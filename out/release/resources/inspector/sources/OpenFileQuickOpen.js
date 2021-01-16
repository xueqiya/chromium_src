import{FilteredUISourceCodeListProvider}from'./FilteredUISourceCodeListProvider.js';import{SourcesView}from'./SourcesView.js';export class OpenFileQuickOpen extends FilteredUISourceCodeListProvider{attach(){this.setDefaultScores(SourcesView.defaultUISourceCodeScores());super.attach();}
uiSourceCodeSelected(uiSourceCode,lineNumber,columnNumber){Host.userMetrics.actionTaken(Host.UserMetrics.Action.SelectFileFromFilePicker);if(!uiSourceCode){return;}
if(typeof lineNumber==='number'){Common.Revealer.reveal(uiSourceCode.uiLocation(lineNumber,columnNumber));}else{Common.Revealer.reveal(uiSourceCode);}}
filterProject(project){return!project.isServiceProject();}
renderAsTwoRows(){return true;}}