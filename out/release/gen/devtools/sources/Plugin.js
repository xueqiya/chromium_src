export class Plugin{static accepts(uiSourceCode){return false;}
wasShown(){}
willHide(){}
async rightToolbarItems(){return[];}
leftToolbarItems(){return[];}
populateLineGutterContextMenu(contextMenu,lineNumber){return Promise.resolve();}
populateTextAreaContextMenu(contextMenu,lineNumber,columnNumber){return Promise.resolve();}
dispose(){}}