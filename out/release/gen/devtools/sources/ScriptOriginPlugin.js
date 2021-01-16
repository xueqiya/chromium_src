import{Plugin}from'./Plugin.js';export class ScriptOriginPlugin extends Plugin{constructor(textEditor,uiSourceCode){super();this._textEditor=textEditor;this._uiSourceCode=uiSourceCode;}
static accepts(uiSourceCode){return uiSourceCode.contentType().hasScripts()||!!ScriptOriginPlugin._script(uiSourceCode);}
async rightToolbarItems(){const originURL=Bindings.CompilerScriptMapping.uiSourceCodeOrigin(this._uiSourceCode);if(originURL){const item=UI.formatLocalized('(source mapped from %s)',[Components.Linkifier.linkifyURL(originURL)]);return[new UI.ToolbarItem(item)];}
const script=await ScriptOriginPlugin._script(this._uiSourceCode);if(!script||!script.originStackTrace){return[];}
const link=linkifier.linkifyStackTraceTopFrame(script.debuggerModel.target(),script.originStackTrace);return[new UI.ToolbarItem(link)];}
static async _script(uiSourceCode){const locations=await self.Bindings.debuggerWorkspaceBinding.uiLocationToRawLocations(uiSourceCode,0,0);for(const location of locations){const script=location.script();if(script&&script.originStackTrace){return script;}}
return null;}}
export const linkifier=new Components.Linkifier();