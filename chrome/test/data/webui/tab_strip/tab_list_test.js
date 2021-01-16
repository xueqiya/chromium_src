// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {webUIListenerCallback} from 'chrome://resources/js/cr.m.js';
import {FocusOutlineManager} from 'chrome://resources/js/cr/ui/focus_outline_manager.m.js';
import {loadTimeData} from 'chrome://resources/js/load_time_data.m.js';
import {setScrollAnimationEnabledForTesting} from 'chrome://tab-strip/tab_list.js';
import {TabStripEmbedderProxy} from 'chrome://tab-strip/tab_strip_embedder_proxy.js';
import {TabsApiProxy} from 'chrome://tab-strip/tabs_api_proxy.js';

import {TestTabStripEmbedderProxy} from './test_tab_strip_embedder_proxy.js';
import {TestTabsApiProxy} from './test_tabs_api_proxy.js';

class MockDataTransfer extends DataTransfer {
  constructor() {
    super();

    this.dragImageData = {
      image: undefined,
      offsetX: undefined,
      offsetY: undefined,
    };

    this.dropEffect_ = 'none';
    this.effectAllowed_ = 'none';
  }

  get dropEffect() {
    return this.dropEffect_;
  }

  set dropEffect(effect) {
    this.dropEffect_ = effect;
  }

  get effectAllowed() {
    return this.effectAllowed_;
  }

  set effectAllowed(effect) {
    this.effectAllowed_ = effect;
  }

  setDragImage(image, offsetX, offsetY) {
    this.dragImageData.image = image;
    this.dragImageData.offsetX = offsetX;
    this.dragImageData.offsetY = offsetY;
  }
}

suite('TabList', () => {
  let callbackRouter;
  let optionsCalled;
  let tabList;
  let testTabStripEmbedderProxy;
  let testTabsApiProxy;

  const tabs = [
    {
      active: true,
      alertStates: [],
      id: 0,
      index: 0,
      pinned: false,
      title: 'Tab 1',
    },
    {
      active: false,
      alertStates: [],
      id: 1,
      index: 1,
      pinned: false,
      title: 'Tab 2',
    },
    {
      active: false,
      alertStates: [],
      id: 2,
      index: 2,
      pinned: false,
      title: 'Tab 3',
    },
  ];
  const currentWindowId = 1000;

  const strings = {
    tabIdDataType: 'application/tab-id',
  };

  function pinTabAt(tab, index) {
    const changeInfo = {index: index, pinned: true};
    const updatedTab = Object.assign({}, tab, changeInfo);
    webUIListenerCallback('tab-updated', updatedTab);
  }

  function unpinTabAt(tab, index) {
    const changeInfo = {index: index, pinned: false};
    const updatedTab = Object.assign({}, tab, changeInfo);
    webUIListenerCallback('tab-updated', updatedTab);
  }

  function getUnpinnedTabs() {
    return tabList.shadowRoot.querySelectorAll('#unpinnedTabs tabstrip-tab');
  }

  function getPinnedTabs() {
    return tabList.shadowRoot.querySelectorAll('#pinnedTabs tabstrip-tab');
  }

  function getTabGroups() {
    return tabList.shadowRoot.querySelectorAll('tabstrip-tab-group');
  }

  setup(() => {
    loadTimeData.overrideValues(strings);
    document.body.innerHTML = '';
    document.body.style.margin = 0;

    testTabsApiProxy = new TestTabsApiProxy();
    testTabsApiProxy.setTabs(tabs);
    TabsApiProxy.instance_ = testTabsApiProxy;
    callbackRouter = testTabsApiProxy.callbackRouter;

    testTabStripEmbedderProxy = new TestTabStripEmbedderProxy();
    testTabStripEmbedderProxy.setWindowId(currentWindowId);
    testTabStripEmbedderProxy.setColors({
      '--background-color': 'white',
      '--foreground-color': 'black',
    });
    testTabStripEmbedderProxy.setLayout({
      '--height': '100px',
      '--width': '150px',
    });
    testTabStripEmbedderProxy.setVisible(true);
    TabStripEmbedderProxy.instance_ = testTabStripEmbedderProxy;

    setScrollAnimationEnabledForTesting(false);

    tabList = document.createElement('tabstrip-tab-list');
    document.body.appendChild(tabList);

    return Promise.all([
      testTabsApiProxy.whenCalled('getTabs'),
      testTabStripEmbedderProxy.whenCalled('getWindowId'),
    ]);
  });

  teardown(() => {
    testTabsApiProxy.reset();
    testTabStripEmbedderProxy.reset();
  });

  test('sets theme colors on init', async () => {
    await testTabStripEmbedderProxy.whenCalled('getColors');
    assertEquals(tabList.style.getPropertyValue('--background-color'), 'white');
    assertEquals(tabList.style.getPropertyValue('--foreground-color'), 'black');
  });

  test('updates theme colors when theme changes', async () => {
    testTabStripEmbedderProxy.setColors({
      '--background-color': 'pink',
      '--foreground-color': 'blue',
    });
    webUIListenerCallback('theme-changed');
    await testTabStripEmbedderProxy.whenCalled('getColors');
    assertEquals(tabList.style.getPropertyValue('--background-color'), 'pink');
    assertEquals(tabList.style.getPropertyValue('--foreground-color'), 'blue');
  });

  test('sets layout variables on init', async () => {
    await testTabStripEmbedderProxy.whenCalled('getLayout');
    assertEquals(tabList.style.getPropertyValue('--height'), '100px');
    assertEquals(tabList.style.getPropertyValue('--width'), '150px');
  });

  test('updates layout variables when layout changes', async () => {
    webUIListenerCallback('layout-changed', {
      '--height': '10000px',
      '--width': '10px',
    });
    await testTabStripEmbedderProxy.whenCalled('getLayout');
    assertEquals(tabList.style.getPropertyValue('--height'), '10000px');
    assertEquals(tabList.style.getPropertyValue('--width'), '10px');
  });

  test('GroupVisualDataOnInit', async () => {
    testTabsApiProxy.reset();
    testTabsApiProxy.setTabs([{
      active: true,
      alertStates: [],
      groupId: 'group0',
      id: 0,
      index: 0,
      title: 'New tab',
    }]);
    testTabsApiProxy.setGroupVisualData({
      group0: {
        title: 'My group',
        color: 'rgba(255, 0, 0, 1)',
      },
    });
    // Remove and reinsert into DOM to retrigger connectedCallback();
    tabList.remove();
    document.body.appendChild(tabList);
    await testTabsApiProxy.whenCalled('getGroupVisualData');
  });

  test('GroupVisualDataOnThemeChange', async () => {
    testTabsApiProxy.reset();
    testTabsApiProxy.setGroupVisualData({
      group0: {
        title: 'My group',
        color: 'rgba(255, 0, 0, 1)',
      },
    });
    webUIListenerCallback('theme-changed');
    await testTabsApiProxy.whenCalled('getGroupVisualData');
  });

  test('calculates the correct unpinned tab width and height', async () => {
    webUIListenerCallback('layout-changed', {
      '--tabstrip-tab-thumbnail-height': '132px',
      '--tabstrip-tab-thumbnail-width': '200px',
      '--tabstrip-tab-title-height': '15px',
    });
    await testTabStripEmbedderProxy.whenCalled('getLayout');

    const tabListStyle = window.getComputedStyle(tabList);
    assertEquals(
        tabListStyle.getPropertyValue('--tabstrip-tab-height').trim(),
        'calc(15px + 132px)');
    assertEquals(
        tabListStyle.getPropertyValue('--tabstrip-tab-width').trim(), '200px');
  });

  test('creates a tab element for each tab', () => {
    const tabElements = getUnpinnedTabs();
    assertEquals(tabs.length, tabElements.length);
    tabs.forEach((tab, index) => {
      assertEquals(tabElements[index].tab, tab);
    });
  });

  test('adds a new tab element when a tab is added in same window', () => {
    const appendedTab = {
      active: false,
      alertStates: [],
      id: 3,
      index: 3,
      title: 'New tab',
    };
    webUIListenerCallback('tab-created', appendedTab);
    let tabElements = getUnpinnedTabs();
    assertEquals(tabs.length + 1, tabElements.length);
    assertEquals(tabElements[tabs.length].tab, appendedTab);

    const prependedTab = {
      active: false,
      alertStates: [],
      id: 4,
      index: 0,
      title: 'New tab',
    };
    webUIListenerCallback('tab-created', prependedTab);
    tabElements = getUnpinnedTabs();
    assertEquals(tabs.length + 2, tabElements.length);
    assertEquals(tabElements[0].tab, prependedTab);
  });

  test('AddNewTabGroup', () => {
    const appendedTab = {
      active: false,
      alertStates: [],
      groupId: 'group0',
      id: 3,
      index: 3,
      title: 'New tab in group',
    };
    webUIListenerCallback('tab-created', appendedTab);
    let tabElements = getUnpinnedTabs();
    assertEquals(tabs.length + 1, tabElements.length);
    assertEquals(getTabGroups().length, 1);
    assertEquals(
        'TABSTRIP-TAB-GROUP',
        tabElements[appendedTab.index].parentElement.tagName);

    const prependedTab = {
      active: false,
      alertStates: [],
      groupId: 'group1',
      id: 4,
      index: 0,
      title: 'New tab',
    };
    webUIListenerCallback('tab-created', prependedTab);
    tabElements = getUnpinnedTabs();
    assertEquals(tabs.length + 2, tabElements.length);
    assertEquals(getTabGroups().length, 2);
    assertEquals(
        'TABSTRIP-TAB-GROUP',
        tabElements[prependedTab.index].parentElement.tagName);
  });

  test('AddTabToExistingGroup', () => {
    const appendedTab = {
      active: false,
      alertStates: [],
      groupId: 'group0',
      id: 3,
      index: 3,
      title: 'New tab in group',
    };
    webUIListenerCallback('tab-created', appendedTab);
    const appendedTabInSameGroup = {
      active: false,
      alertStates: [],
      groupId: 'group0',
      id: 4,
      index: 4,
      title: 'New tab in same group',
    };
    webUIListenerCallback('tab-created', appendedTabInSameGroup);
    const tabGroups = getTabGroups();
    assertEquals(tabGroups.length, 1);
    assertEquals(tabGroups[0].children.item(0).tab.id, appendedTab.id);
    assertEquals(
        tabGroups[0].children.item(1).tab.id, appendedTabInSameGroup.id);
  });

  // Test that the TabList does not add a non-grouped tab to a tab group at the
  // same index.
  test('HandleSingleTabBeforeGroup', () => {
    const tabInGroup = {
      active: false,
      alertStates: [],
      groupId: 'group0',
      id: 3,
      index: 3,
      title: 'New tab in group',
    };
    webUIListenerCallback('tab-created', tabInGroup);
    const tabNotInGroup = {
      active: false,
      alertStates: [],
      id: 4,
      index: 3,
      title: 'New tab not in group',
    };
    webUIListenerCallback('tab-created', tabNotInGroup);
    const tabsContainerChildren =
        tabList.shadowRoot.querySelector('#unpinnedTabs').children;
    assertEquals(tabsContainerChildren.item(3).tagName, 'TABSTRIP-TAB');
    assertEquals(tabsContainerChildren.item(3).tab, tabNotInGroup);
    assertEquals(tabsContainerChildren.item(4).tagName, 'TABSTRIP-TAB-GROUP');
  });

  test('HandleGroupedTabBeforeDifferentGroup', () => {
    const tabInOriginalGroup = tabs[1];
    webUIListenerCallback(
        'tab-group-state-changed', tabInOriginalGroup.id,
        tabInOriginalGroup.index, 'originalGroup');

    // Create another group from the tab before group A.
    const tabInPrecedingGroup = tabs[0];
    webUIListenerCallback(
        'tab-group-state-changed', tabInPrecedingGroup.id,
        tabInPrecedingGroup.index, 'precedingGroup');
    const tabsContainerChildren =
        tabList.shadowRoot.querySelector('#unpinnedTabs').children;

    const precedingGroup = tabsContainerChildren[0];
    assertEquals(precedingGroup.tagName, 'TABSTRIP-TAB-GROUP');
    assertEquals(precedingGroup.dataset.groupId, 'precedingGroup');
    assertEquals(precedingGroup.children.length, 1);
    assertEquals(precedingGroup.children[0].tab.id, tabInPrecedingGroup.id);

    const originalGroup = tabsContainerChildren[1];
    assertEquals(originalGroup.tagName, 'TABSTRIP-TAB-GROUP');
    assertEquals(originalGroup.dataset.groupId, 'originalGroup');
    assertEquals(originalGroup.children.length, 1);
    assertEquals(originalGroup.children[0].tab.id, tabInOriginalGroup.id);
  });

  test('HandleGroupedTabBeforeSameGroup', () => {
    const originalTabInGroup = tabs[1];
    webUIListenerCallback(
        'tab-group-state-changed', originalTabInGroup.id,
        originalTabInGroup.index, 'sameGroup');

    // Create another group from the tab before group A.
    const precedingTabInGroup = tabs[0];
    webUIListenerCallback(
        'tab-group-state-changed', precedingTabInGroup.id,
        precedingTabInGroup.index, 'sameGroup');

    const tabGroups = getTabGroups();
    const tabGroup = tabGroups[0];
    assertEquals(tabGroups.length, 1);
    assertEquals(tabGroup.dataset.groupId, 'sameGroup');
    assertEquals(tabGroup.children.length, 2);
    assertEquals(tabGroup.children[0].tab.id, precedingTabInGroup.id);
    assertEquals(tabGroup.children[1].tab.id, originalTabInGroup.id);
  });

  test('removes a tab when tab is removed from current window', async () => {
    const tabToRemove = tabs[0];
    webUIListenerCallback('tab-removed', tabToRemove.id);
    await tabList.animationPromises;
    assertEquals(tabs.length - 1, getUnpinnedTabs().length);
  });

  test('updates a tab with new tab data when a tab is updated', () => {
    const tabToUpdate = tabs[0];
    const changeInfo = {title: 'A new title'};
    const updatedTab = Object.assign({}, tabToUpdate, changeInfo);
    webUIListenerCallback('tab-updated', updatedTab);
    const tabElements = getUnpinnedTabs();
    assertEquals(tabElements[0].tab, updatedTab);
  });

  test('updates tabs when a new tab is activated', () => {
    const tabElements = getUnpinnedTabs();

    // Mock activating the 2nd tab
    webUIListenerCallback('tab-active-changed', tabs[1].id);
    assertFalse(tabElements[0].tab.active);
    assertTrue(tabElements[1].tab.active);
    assertFalse(tabElements[2].tab.active);
  });

  test('adds a pinned tab to its designated container', () => {
    webUIListenerCallback('tab-created', {
      active: false,
      alertStates: [],
      index: 0,
      title: 'New pinned tab',
      pinned: true,
    });
    const pinnedTabElements = getPinnedTabs();
    assertEquals(pinnedTabElements.length, 1);
    assertTrue(pinnedTabElements[0].tab.pinned);
  });

  test('moves pinned tabs to designated containers', () => {
    const tabToPin = tabs[1];
    const changeInfo = {index: 0, pinned: true};
    let updatedTab = Object.assign({}, tabToPin, changeInfo);
    webUIListenerCallback('tab-updated', updatedTab);

    let pinnedTabElements = getPinnedTabs();
    assertEquals(pinnedTabElements.length, 1);
    assertTrue(pinnedTabElements[0].tab.pinned);
    assertEquals(pinnedTabElements[0].tab.id, tabToPin.id);
    assertEquals(getUnpinnedTabs().length, 2);

    // Unpin the tab so that it's now at index 0
    changeInfo.index = 0;
    changeInfo.pinned = false;
    updatedTab = Object.assign({}, updatedTab, changeInfo);
    webUIListenerCallback('tab-updated', updatedTab);

    const unpinnedTabElements = getUnpinnedTabs();
    assertEquals(getPinnedTabs().length, 0);
    assertEquals(unpinnedTabElements.length, 3);
    assertEquals(unpinnedTabElements[0].tab.id, tabToPin.id);
  });

  test('moves tab elements when tabs move', () => {
    const tabElementsBeforeMove = getUnpinnedTabs();
    const tabToMove = tabs[0];
    webUIListenerCallback('tab-moved', tabToMove.id, 2);

    const tabElementsAfterMove = getUnpinnedTabs();
    assertEquals(tabElementsBeforeMove[0], tabElementsAfterMove[2]);
    assertEquals(tabElementsBeforeMove[1], tabElementsAfterMove[0]);
    assertEquals(tabElementsBeforeMove[2], tabElementsAfterMove[1]);
  });

  test('MoveExistingTabToGroup', () => {
    const tabToGroup = tabs[1];
    webUIListenerCallback(
        'tab-group-state-changed', tabToGroup.id, tabToGroup.index, 'group0');
    let tabElements = getUnpinnedTabs();
    assertEquals(tabElements.length, tabs.length);
    assertEquals(
        tabElements[tabToGroup.index].parentElement.tagName,
        'TABSTRIP-TAB-GROUP');

    const anotherTabToGroup = tabs[2];
    webUIListenerCallback(
        'tab-group-state-changed', anotherTabToGroup.id,
        anotherTabToGroup.index, 'group0');
    tabElements = getUnpinnedTabs();
    assertEquals(tabElements.length, tabs.length);
    assertEquals(
        tabElements[tabToGroup.index].parentElement,
        tabElements[anotherTabToGroup.index].parentElement);
  });

  test('MoveTabGroup', () => {
    const tabToGroup = tabs[1];
    webUIListenerCallback(
        'tab-group-state-changed', tabToGroup.id, tabToGroup.index, 'group0');
    webUIListenerCallback('tab-group-moved', 'group0', 0);

    const tabAtIndex0 = getUnpinnedTabs()[0];
    assertEquals(tabAtIndex0.parentElement.tagName, 'TABSTRIP-TAB-GROUP');
    assertEquals(tabAtIndex0.tab.id, tabToGroup.id);
  });

  test('dragstart sets a drag image offset by the event coordinates', () => {
    // Drag and drop only works for pinned tabs
    tabs.forEach(pinTabAt);

    const draggedTab = getPinnedTabs()[0];
    const mockDataTransfer = new MockDataTransfer();
    const dragStartEvent = new DragEvent('dragstart', {
      bubbles: true,
      composed: true,
      clientX: 100,
      clientY: 150,
      dataTransfer: mockDataTransfer,
    });
    draggedTab.dispatchEvent(dragStartEvent);
    assertEquals(dragStartEvent.dataTransfer.effectAllowed, 'move');
    assertEquals(
        mockDataTransfer.dragImageData.image, draggedTab.getDragImage());
    assertEquals(
        mockDataTransfer.dragImageData.offsetX, 100 - draggedTab.offsetLeft);
    assertEquals(
        mockDataTransfer.dragImageData.offsetY, 150 - draggedTab.offsetTop);
  });

  test('dragover moves tabs', async () => {
    // Drag and drop only works for pinned tabs
    tabs.forEach(pinTabAt);

    const draggedIndex = 0;
    const dragOverIndex = 1;
    const draggedTab = getPinnedTabs()[draggedIndex];
    const dragOverTab = getPinnedTabs()[dragOverIndex];
    const mockDataTransfer = new MockDataTransfer();

    // Dispatch a dragstart event to start the drag process
    const dragStartEvent = new DragEvent('dragstart', {
      bubbles: true,
      composed: true,
      clientX: 100,
      clientY: 150,
      dataTransfer: mockDataTransfer,
    });
    draggedTab.dispatchEvent(dragStartEvent);

    // Move the draggedTab over the 2nd tab
    const dragOverEvent = new DragEvent('dragover', {
      bubbles: true,
      composed: true,
      dataTransfer: mockDataTransfer,
    });
    dragOverTab.dispatchEvent(dragOverEvent);
    assertEquals(dragOverEvent.dataTransfer.dropEffect, 'move');
    const [tabId, windowId, newIndex] =
        await testTabsApiProxy.whenCalled('moveTab');
    assertEquals(tabId, tabs[draggedIndex].id);
    assertEquals(currentWindowId, windowId);
    assertEquals(newIndex, dragOverIndex);
  });

  test('DragTabOverTabGroup', async () => {
    const tabElements = getUnpinnedTabs();

    // Group the first tab.
    webUIListenerCallback(
        'tab-group-state-changed', tabElements[0].tab.id, 0, 'group0');

    // Start dragging the second tab.
    const draggedTab = tabElements[1];
    const mockDataTransfer = new MockDataTransfer();
    const dragStartEvent = new DragEvent('dragstart', {
      bubbles: true,
      composed: true,
      clientX: 100,
      clientY: 150,
      dataTransfer: mockDataTransfer,
    });
    draggedTab.dispatchEvent(dragStartEvent);

    // Drag the second tab over the newly created tab group.
    const dragOverTabGroup = getTabGroups()[0];
    const dragOverEvent = new DragEvent('dragover', {
      bubbles: true,
      composed: true,
      dataTransfer: mockDataTransfer,
    });
    dragOverTabGroup.dispatchEvent(dragOverEvent);
    const [tabId, groupId] = await testTabsApiProxy.whenCalled('groupTab');
    assertEquals(draggedTab.tab.id, tabId);
    assertEquals('group0', groupId);
  });

  test('DragTabOutOfTabGroup', async () => {
    const tabElements = getUnpinnedTabs();

    // Group the first tab.
    webUIListenerCallback(
        'tab-group-state-changed', tabElements[0].tab.id, 0, 'group0');

    // Start dragging the first tab.
    const draggedTab = tabElements[0];
    const mockDataTransfer = new MockDataTransfer();
    const dragStartEvent = new DragEvent('dragstart', {
      bubbles: true,
      composed: true,
      clientX: 100,
      clientY: 150,
      dataTransfer: mockDataTransfer,
    });
    draggedTab.dispatchEvent(dragStartEvent);

    // Drag the first tab out.
    const dragOverEvent = new DragEvent('dragover', {
      bubbles: true,
      composed: true,
      dataTransfer: mockDataTransfer,
    });
    tabList.dispatchEvent(dragOverEvent);
    const [tabId] = await testTabsApiProxy.whenCalled('ungroupTab');
    assertEquals(draggedTab.tab.id, tabId);
  });

  test('DragGroupOverTab', async () => {
    const tabElements = getUnpinnedTabs();

    // Group the first tab.
    webUIListenerCallback(
        'tab-group-state-changed', tabElements[0].tab.id, 0, 'group0');

    // Start dragging the group.
    const draggedGroup = getTabGroups()[0];
    const mockDataTransfer = new MockDataTransfer();
    const dragStartEvent = new DragEvent('dragstart', {
      bubbles: true,
      composed: true,
      clientX: 100,
      clientY: 150,
      dataTransfer: mockDataTransfer,
    });
    draggedGroup.dispatchEvent(dragStartEvent);

    // Drag the group over the second tab.
    const dragOverTab = tabElements[1];
    const dragOverEvent = new DragEvent('dragover', {
      bubbles: true,
      composed: true,
      dataTransfer: mockDataTransfer,
    });
    dragOverTab.dispatchEvent(dragOverEvent);
    const [groupId, index] = await testTabsApiProxy.whenCalled('moveGroup');
    assertEquals('group0', groupId);
    assertEquals(1, index);
  });

  test('DragGroupOverGroup', async () => {
    const tabElements = getUnpinnedTabs();

    // Group the first tab and second tab separately.
    webUIListenerCallback(
        'tab-group-state-changed', tabElements[0].tab.id, 0, 'group0');
    webUIListenerCallback(
        'tab-group-state-changed', tabElements[1].tab.id, 1, 'group1');

    // Start dragging the first group.
    const draggedGroup = getTabGroups()[0];
    const mockDataTransfer = new MockDataTransfer();
    const dragStartEvent = new DragEvent('dragstart', {
      bubbles: true,
      composed: true,
      clientX: 100,
      clientY: 150,
      dataTransfer: mockDataTransfer,
    });
    draggedGroup.dispatchEvent(dragStartEvent);

    // Drag the group over the second tab.
    const dragOverGroup = getTabGroups()[1];
    const dragOverEvent = new DragEvent('dragover', {
      bubbles: true,
      composed: true,
      dataTransfer: mockDataTransfer,
    });
    dragOverGroup.dispatchEvent(dragOverEvent);
    const [groupId, index] = await testTabsApiProxy.whenCalled('moveGroup');
    assertEquals('group0', groupId);
    assertEquals(1, index);
  });

  test('DragTabIntoListFromOutside', () => {
    const mockDataTransfer = new MockDataTransfer();
    mockDataTransfer.setData(strings.tabIdDataType, '1000');
    const dragOverEvent = new DragEvent('dragover', {
      bubbles: true,
      composed: true,
      dataTransfer: mockDataTransfer,
    });
    tabList.dispatchEvent(dragOverEvent);
    assertTrue(
        tabList.$('#unpinnedTabs').lastElementChild.id === 'dropPlaceholder');

    tabList.dispatchEvent(new DragEvent('drop', dragOverEvent));
    assertEquals(null, tabList.$('dropPlaceholder'));
  });

  test('DropTabIntoList', async () => {
    const droppedTabId = 9000;
    const mockDataTransfer = new MockDataTransfer();
    mockDataTransfer.setData(strings.tabIdDataType, droppedTabId);
    const dropEvent = new DragEvent('drop', {
      bubbles: true,
      composed: true,
      clientX: 100,
      clientY: 150,
      dataTransfer: mockDataTransfer,
    });
    tabList.dispatchEvent(dropEvent);

    const [tabId, windowId, index] =
        await testTabsApiProxy.whenCalled('moveTab');
    assertEquals(droppedTabId, tabId);
    assertEquals(currentWindowId, windowId);
    assertEquals(-1, index);
  });

  test('tracks and untracks thumbnails based on viewport', async () => {
    // Wait for slideIn animations to complete updating widths and reset
    // resolvers to track new calls.
    await tabList.animationPromises;
    await testTabsApiProxy.whenCalled('setThumbnailTracked');
    testTabsApiProxy.reset();
    const tabElements = getUnpinnedTabs();

    // Update width such that at most one tab can fit in the viewport at once.
    tabList.style.setProperty('--tabstrip-tab-width', `${window.innerWidth}px`);

    // At this point, the only visible tab should be the first tab. The second
    // tab should fit within the rootMargin of the IntersectionObserver. The
    // third tab should not be intersecting.
    let [tabId, thumbnailTracked] =
        await testTabsApiProxy.whenCalled('setThumbnailTracked');
    assertEquals(tabId, tabElements[2].tab.id);
    assertEquals(thumbnailTracked, false);
    assertEquals(testTabsApiProxy.getCallCount('setThumbnailTracked'), 1);
    testTabsApiProxy.reset();

    // Scroll such that the second tab is now the only visible tab. At this
    // point, all 3 tabs should fit within the root and rootMargin of the
    // IntersectionObserver. Since the 3rd tab was not being tracked before,
    // it should be the only tab to become tracked.
    tabList.scrollLeft = tabElements[1].offsetLeft;
    [tabId, thumbnailTracked] =
        await testTabsApiProxy.whenCalled('setThumbnailTracked');
    assertEquals(tabId, tabElements[2].tab.id);
    assertEquals(thumbnailTracked, true);
    assertEquals(testTabsApiProxy.getCallCount('setThumbnailTracked'), 1);
    testTabsApiProxy.reset();

    // Scroll such that the third tab is now the only visible tab. At this
    // point, the first tab should be outside of the rootMargin of the
    // IntersectionObserver.
    tabList.scrollLeft = tabElements[2].offsetLeft;
    [tabId, thumbnailTracked] =
        await testTabsApiProxy.whenCalled('setThumbnailTracked');
    assertEquals(tabId, tabElements[0].tab.id);
    assertEquals(thumbnailTracked, false);
    assertEquals(testTabsApiProxy.getCallCount('setThumbnailTracked'), 1);
  });

  test('tracks and untracks thumbnails based on pinned state', async () => {
    await tabList.animationPromises;
    await testTabsApiProxy.whenCalled('setThumbnailTracked');
    testTabsApiProxy.reset();

    // Update width such that at all tabs can fit and do not fire the
    // IntersectionObserver based on intersection alone.
    tabList.style.setProperty(
        '--tabstrip-tab-width', `${window.innerWidth / tabs.length}px`);

    // Pinning the third tab should untrack thumbnails for the tab
    pinTabAt(tabs[2], 0);
    let [tabId, thumbnailTracked] =
        await testTabsApiProxy.whenCalled('setThumbnailTracked');
    assertEquals(tabId, tabs[2].id);
    assertEquals(thumbnailTracked, false);
    testTabsApiProxy.reset();

    // Unpinning the tab should re-track the thumbnails
    unpinTabAt(tabs[2], 0);
    [tabId, thumbnailTracked] =
        await testTabsApiProxy.whenCalled('setThumbnailTracked');

    assertEquals(tabId, tabs[2].id);
    assertEquals(thumbnailTracked, true);
  });

  test('should update thumbnail track status on visibilitychange', async () => {
    await tabList.animationPromises;
    await testTabsApiProxy.whenCalled('setThumbnailTracked');
    testTabsApiProxy.reset();

    testTabStripEmbedderProxy.setVisible(false);
    document.dispatchEvent(new Event('visibilitychange'));

    // The tab strip should force untrack thumbnails for all tabs.
    await testTabsApiProxy.whenCalled('setThumbnailTracked');
    assertEquals(
        testTabsApiProxy.getCallCount('setThumbnailTracked'), tabs.length);
    testTabsApiProxy.reset();

    // Update width such that at all tabs can fit
    tabList.style.setProperty(
        '--tabstrip-tab-width', `${window.innerWidth / tabs.length}px`);

    testTabStripEmbedderProxy.setVisible(true);
    document.dispatchEvent(new Event('visibilitychange'));

    await testTabsApiProxy.whenCalled('setThumbnailTracked');
    assertEquals(
        testTabsApiProxy.getCallCount('setThumbnailTracked'), tabs.length);
  });

  test(
      'focusing on tab strip with the keyboard adds a class and focuses ' +
          'the first tab',
      () => {
        webUIListenerCallback('received-keyboard-focus');
        assertEquals(document.activeElement, tabList);
        assertEquals(tabList.shadowRoot.activeElement, getUnpinnedTabs()[0]);
        assertTrue(FocusOutlineManager.forDocument(document).visible);
      });

  test('blurring the tab strip blurs the active element', () => {
    // First, make sure tab strip has keyboard focus.
    webUIListenerCallback('received-keyboard-focus');

    window.dispatchEvent(new Event('blur'));
    assertEquals(tabList.shadowRoot.activeElement, null);
  });

  test('should update the ID when a tab is replaced', () => {
    assertEquals(getUnpinnedTabs()[0].tab.id, 0);
    webUIListenerCallback('tab-replaced', tabs[0].id, 1000);
    assertEquals(getUnpinnedTabs()[0].tab.id, 1000);
  });

  test('has custom context menu', async () => {
    let event = new Event('contextmenu');
    event.clientX = 1;
    event.clientY = 2;
    document.dispatchEvent(event);

    const contextMenuArgs =
        await testTabStripEmbedderProxy.whenCalled('showBackgroundContextMenu');
    assertEquals(contextMenuArgs[0], 1);
    assertEquals(contextMenuArgs[1], 2);
  });

  test('scrolls to active tabs', async () => {
    await tabList.animationPromises;

    const newTabButtonMargin = 15;
    const newTabButtonWidth = 50;
    const scrollPadding = 32;
    const tabWidth = 200;
    const viewportWidth = 300;

    // Mock the width of each tab element.
    tabList.style.setProperty(
        '--tabstrip-new-tab-button-margin', `${newTabButtonMargin}px`);
    tabList.style.setProperty(
        '--tabstrip-new-tab-button-width', `${newTabButtonWidth}px`);
    tabList.style.setProperty(
        '--tabstrip-tab-thumbnail-width', `${tabWidth}px`);
    tabList.style.setProperty('--tabstrip-tab-spacing', '0px');
    const tabElements = getUnpinnedTabs();
    tabElements.forEach(tabElement => {
      tabElement.style.width = `${tabWidth}px`;
    });

    // Mock the scroller size such that it cannot fit only 1 tab at a time.
    tabList.style.setProperty(
        '--tabstrip-viewport-width', `${viewportWidth}px`);
    tabList.style.width = `${viewportWidth}px`;

    // Verify the scrollLeft is currently at its default state of 0, and then
    // send a visibilitychange event to cause a scroll.
    assertEquals(tabList.scrollLeft, 0);
    webUIListenerCallback('tab-active-changed', tabs[1].id);
    testTabStripEmbedderProxy.setVisible(false);
    document.dispatchEvent(new Event('visibilitychange'));

    // The 2nd tab should be off-screen to the right, so activating it should
    // scroll so that the element's right edge is aligned with the screen's
    // right edge.
    let activeTab = getUnpinnedTabs()[1];
    assertEquals(
        tabList.scrollLeft + tabList.offsetWidth,
        activeTab.offsetLeft + activeTab.offsetWidth + scrollPadding +
            newTabButtonMargin + newTabButtonWidth);

    // The 1st tab should be now off-screen to the left, so activating it should
    // scroll so that the element's left edge is aligned with the screen's
    // left edge.
    webUIListenerCallback('tab-active-changed', tabs[0].id);
    activeTab = getUnpinnedTabs()[0];
    assertEquals(tabList.scrollLeft, 0);
  });

  test('clicking on new tab button opens a new tab', () => {
    tabList.shadowRoot.querySelector('#newTabButton').click();
    return testTabsApiProxy.whenCalled('createNewTab');
  });
});
