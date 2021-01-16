export class StorageItemsView extends UI.VBox{constructor(title,filterName){super(false);this._filterRegex=null;this._refreshButton=this._addButton(Common.UIString('Refresh'),'largeicon-refresh',this.refreshItems);this._mainToolbar=new UI.Toolbar('top-resources-toolbar',this.element);this._filterItem=new UI.ToolbarInput(Common.UIString('Filter'),'',0.4);this._filterItem.addEventListener(UI.ToolbarInput.Event.TextChanged,this._filterChanged,this);const toolbarSeparator=new UI.ToolbarSeparator();this._deleteAllButton=this._addButton(Common.UIString('Clear All'),'largeicon-clear',this.deleteAllItems);this._deleteSelectedButton=this._addButton(Common.UIString('Delete Selected'),'largeicon-delete',this.deleteSelectedItem);const toolbarItems=[this._refreshButton,this._filterItem,toolbarSeparator,this._deleteAllButton,this._deleteSelectedButton];for(const item of toolbarItems){this._mainToolbar.appendToolbarItem(item);}}
appendToolbarItem(item){this._mainToolbar.appendToolbarItem(item);}
_addButton(label,glyph,callback){const button=new UI.ToolbarButton(label,glyph);button.addEventListener(UI.ToolbarButton.Events.Click,callback,this);return button;}
_filterChanged(event){const text=(event.data);this._filterRegex=text?new RegExp(text.escapeForRegExp(),'i'):null;this.refreshItems();}
filter(items,keyFunction){if(!this._filterRegex){return items;}
return items.filter(item=>this._filterRegex.test(keyFunction(item)));}
wasShown(){this.refreshItems();}
setCanDeleteAll(enabled){this._deleteAllButton.setEnabled(enabled);}
setCanDeleteSelected(enabled){this._deleteSelectedButton.setEnabled(enabled);}
setCanRefresh(enabled){this._refreshButton.setEnabled(enabled);}
setCanFilter(enabled){this._filterItem.setEnabled(enabled);}
deleteAllItems(){}
deleteSelectedItem(){}
refreshItems(){}}