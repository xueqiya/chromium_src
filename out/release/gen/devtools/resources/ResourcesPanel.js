import{ApplicationPanelSidebar,StorageCategoryView}from'./ApplicationPanelSidebar.js';import{CookieItemsView}from'./CookieItemsView.js';import{DatabaseQueryView}from'./DatabaseQueryView.js';import{DatabaseTableView}from'./DatabaseTableView.js';import{DOMStorageItemsView}from'./DOMStorageItemsView.js';import{DOMStorage}from'./DOMStorageModel.js';import{StorageItemsView}from'./StorageItemsView.js';export class ResourcesPanel extends UI.PanelWithSidebar{constructor(){super('resources');this.registerRequiredCSS('resources/resourcesPanel.css');this._resourcesLastSelectedItemSetting=self.Common.settings.createSetting('resourcesLastSelectedElementPath',[]);this.visibleView=null;this._pendingViewPromise=null;this._categoryView=null;const mainContainer=new UI.VBox();this.storageViews=mainContainer.element.createChild('div','vbox flex-auto');this._storageViewToolbar=new UI.Toolbar('resources-toolbar',mainContainer.element);this.splitWidget().setMainWidget(mainContainer);this._domStorageView=null;this._cookieView=null;this._emptyWidget=null;this._sidebar=new ApplicationPanelSidebar(this);this._sidebar.show(this.panelSidebarElement());}
static _instance(){return(self.runtime.sharedInstance(ResourcesPanel));}
static _shouldCloseOnReset(view){const viewClassesToClose=[SourceFrame.ResourceSourceFrame,SourceFrame.ImageView,SourceFrame.FontView,StorageItemsView,DatabaseQueryView,DatabaseTableView];return viewClassesToClose.some(type=>view instanceof type);}
focus(){this._sidebar.focus();}
lastSelectedItemPath(){return this._resourcesLastSelectedItemSetting.get();}
setLastSelectedItemPath(path){this._resourcesLastSelectedItemSetting.set(path);}
resetView(){if(this.visibleView&&ResourcesPanel._shouldCloseOnReset(this.visibleView)){this.showView(null);}}
showView(view){this._pendingViewPromise=null;if(this.visibleView===view){return;}
if(this.visibleView){this.visibleView.detach();}
if(view){view.show(this.storageViews);}
this.visibleView=view;this._storageViewToolbar.removeToolbarItems();if(view instanceof UI.SimpleView){view.toolbarItems().then(items=>{items.map(item=>this._storageViewToolbar.appendToolbarItem(item));this._storageViewToolbar.element.classList.toggle('hidden',!items.length);});}}
async scheduleShowView(viewPromise){this._pendingViewPromise=viewPromise;const view=await viewPromise;if(this._pendingViewPromise!==viewPromise){return null;}
this.showView(view);return view;}
showCategoryView(categoryName,categoryLink){if(!this._categoryView){this._categoryView=new StorageCategoryView();}
this._categoryView.setText(categoryName);this._categoryView.setLink(categoryLink);this.showView(this._categoryView);}
showDOMStorage(domStorage){if(!domStorage){return;}
if(!this._domStorageView){this._domStorageView=new DOMStorageItemsView(domStorage);}else{this._domStorageView.setStorage(domStorage);}
this.showView(this._domStorageView);}
showCookies(cookieFrameTarget,cookieDomain){const model=cookieFrameTarget.model(SDK.CookieModel);if(!model){return;}
if(!this._cookieView){this._cookieView=new CookieItemsView(model,cookieDomain);}else{this._cookieView.setCookiesDomain(model,cookieDomain);}
this.showView(this._cookieView);}
clearCookies(target,cookieDomain){const model=target.model(SDK.CookieModel);if(!model){return;}
model.clear(cookieDomain,()=>{if(this._cookieView){this._cookieView.refreshItems();}});}}
export class ResourceRevealer{async reveal(resource){if(!(resource instanceof SDK.Resource)){return Promise.reject(new Error('Internal error: not a resource'));}
const sidebar=ResourcesPanel._instance()._sidebar;await self.UI.viewManager.showView('resources');await sidebar.showResource(resource);}}