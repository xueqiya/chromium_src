import{Plugin}from'./Plugin.js';export class GutterDiffPlugin extends Plugin{constructor(textEditor,uiSourceCode){super();this._textEditor=textEditor;this._uiSourceCode=uiSourceCode;this._decorations=[];this._textEditor.installGutter(DiffGutterType,true);this._workspaceDiff=WorkspaceDiff.workspaceDiff();this._workspaceDiff.subscribeToDiffChange(this._uiSourceCode,this._update,this);this._update();}
static accepts(uiSourceCode){return uiSourceCode.project().type()===Workspace.projectTypes.Network;}
_updateDecorations(removed,added){this._textEditor.operation(operation);function operation(){for(const decoration of removed){decoration.remove();}
for(const decoration of added){decoration.install();}}}
_update(){if(this._uiSourceCode){this._workspaceDiff.requestDiff(this._uiSourceCode).then(this._innerUpdate.bind(this));}else{this._innerUpdate(null);}}
_innerUpdate(lineDiff){if(!lineDiff){this._updateDecorations(this._decorations,[]);this._decorations=[];return;}
const oldDecorations=new Map();for(let i=0;i<this._decorations.length;++i){const decoration=this._decorations[i];const lineNumber=decoration.lineNumber();if(lineNumber===-1){continue;}
oldDecorations.set(lineNumber,decoration);}
const diff=SourceFrame.SourceCodeDiff.computeDiff(lineDiff);const newDecorations=new Map();for(let i=0;i<diff.length;++i){const diffEntry=diff[i];for(let lineNumber=diffEntry.from;lineNumber<diffEntry.to;++lineNumber){newDecorations.set(lineNumber,{lineNumber:lineNumber,type:diffEntry.type});}}
const decorationDiff=oldDecorations.diff(newDecorations,(e1,e2)=>e1.type===e2.type);const addedDecorations=decorationDiff.added.map(entry=>new GutterDecoration(this._textEditor,entry.lineNumber,entry.type));this._decorations=decorationDiff.equal.concat(addedDecorations);this._updateDecorations(decorationDiff.removed,addedDecorations);this._decorationsSetForTest(newDecorations);}
_decorationsSetForTest(decorations){}
async populateLineGutterContextMenu(contextMenu,lineNumber){GutterDiffPlugin._appendRevealDiffContextMenu(contextMenu,this._uiSourceCode);}
async populateTextAreaContextMenu(contextMenu,lineNumber,columnNumber){GutterDiffPlugin._appendRevealDiffContextMenu(contextMenu,this._uiSourceCode);}
static _appendRevealDiffContextMenu(contextMenu,uiSourceCode){if(!WorkspaceDiff.workspaceDiff().isUISourceCodeModified(uiSourceCode)){return;}
contextMenu.revealSection().appendItem(ls`Local Modifications...`,()=>{Common.Revealer.reveal(new WorkspaceDiff.DiffUILocation(uiSourceCode));});}
dispose(){for(const decoration of this._decorations){decoration.remove();}
WorkspaceDiff.workspaceDiff().unsubscribeFromDiffChange(this._uiSourceCode,this._update,this);}}
export class GutterDecoration{constructor(textEditor,lineNumber,type){this._textEditor=textEditor;this._position=this._textEditor.textEditorPositionHandle(lineNumber,0);this._className='';if(type===SourceFrame.SourceCodeDiff.EditType.Insert){this._className='diff-entry-insert';}else if(type===SourceFrame.SourceCodeDiff.EditType.Delete){this._className='diff-entry-delete';}else if(type===SourceFrame.SourceCodeDiff.EditType.Modify){this._className='diff-entry-modify';}
this.type=type;}
lineNumber(){const location=this._position.resolve();if(!location){return-1;}
return location.lineNumber;}
install(){const location=this._position.resolve();if(!location){return;}
const element=createElementWithClass('div','diff-marker');element.textContent='\xA0';this._textEditor.setGutterDecoration(location.lineNumber,DiffGutterType,element);this._textEditor.toggleLineClass(location.lineNumber,this._className,true);}
remove(){const location=this._position.resolve();if(!location){return;}
this._textEditor.setGutterDecoration(location.lineNumber,DiffGutterType,null);this._textEditor.toggleLineClass(location.lineNumber,this._className,false);}}
export const DiffGutterType='CodeMirror-gutter-diff';export class ContextMenuProvider{appendApplicableItems(event,contextMenu,target){let uiSourceCode=(target);const binding=self.Persistence.persistence.binding(uiSourceCode);if(binding){uiSourceCode=binding.network;}
GutterDiffPlugin._appendRevealDiffContextMenu(contextMenu,uiSourceCode);}}