export class ExecutionContextSelector{constructor(targetManager,context){context.addFlavorChangeListener(SDK.ExecutionContext,this._executionContextChanged,this);context.addFlavorChangeListener(SDK.Target,this._targetChanged,this);targetManager.addModelListener(SDK.RuntimeModel,SDK.RuntimeModel.Events.ExecutionContextCreated,this._onExecutionContextCreated,this);targetManager.addModelListener(SDK.RuntimeModel,SDK.RuntimeModel.Events.ExecutionContextDestroyed,this._onExecutionContextDestroyed,this);targetManager.addModelListener(SDK.RuntimeModel,SDK.RuntimeModel.Events.ExecutionContextOrderChanged,this._onExecutionContextOrderChanged,this);this._targetManager=targetManager;this._context=context;targetManager.observeModels(SDK.RuntimeModel,this);}
modelAdded(runtimeModel){setImmediate(deferred.bind(this));function deferred(){if(!this._context.flavor(SDK.Target)){this._context.setFlavor(SDK.Target,runtimeModel.target());}}}
modelRemoved(runtimeModel){const currentExecutionContext=this._context.flavor(SDK.ExecutionContext);if(currentExecutionContext&&currentExecutionContext.runtimeModel===runtimeModel){this._currentExecutionContextGone();}
const models=this._targetManager.models(SDK.RuntimeModel);if(this._context.flavor(SDK.Target)===runtimeModel.target()&&models.length){this._context.setFlavor(SDK.Target,models[0].target());}}
_executionContextChanged(event){const newContext=(event.data);if(newContext){this._context.setFlavor(SDK.Target,newContext.target());if(!this._ignoreContextChanged){this._lastSelectedContextId=this._contextPersistentId(newContext);}}}
_contextPersistentId(executionContext){return executionContext.isDefault?executionContext.target().name()+':'+executionContext.frameId:'';}
_targetChanged(event){const newTarget=(event.data);const currentContext=this._context.flavor(SDK.ExecutionContext);if(!newTarget||(currentContext&&currentContext.target()===newTarget)){return;}
const runtimeModel=newTarget.model(SDK.RuntimeModel);const executionContexts=runtimeModel?runtimeModel.executionContexts():[];if(!executionContexts.length){return;}
let newContext=null;for(let i=0;i<executionContexts.length&&!newContext;++i){if(this._shouldSwitchToContext(executionContexts[i])){newContext=executionContexts[i];}}
for(let i=0;i<executionContexts.length&&!newContext;++i){if(this._isDefaultContext(executionContexts[i])){newContext=executionContexts[i];}}
this._ignoreContextChanged=true;this._context.setFlavor(SDK.ExecutionContext,newContext||executionContexts[0]);this._ignoreContextChanged=false;}
_shouldSwitchToContext(executionContext){if(this._lastSelectedContextId&&this._lastSelectedContextId===this._contextPersistentId(executionContext)){return true;}
if(!this._lastSelectedContextId&&this._isDefaultContext(executionContext)){return true;}
return false;}
_isDefaultContext(executionContext){if(!executionContext.isDefault||!executionContext.frameId){return false;}
if(executionContext.target().parentTarget()){return false;}
const resourceTreeModel=executionContext.target().model(SDK.ResourceTreeModel);const frame=resourceTreeModel&&resourceTreeModel.frameForId(executionContext.frameId);if(frame&&frame.isTopFrame()){return true;}
return false;}
_onExecutionContextCreated(event){this._switchContextIfNecessary((event.data));}
_onExecutionContextDestroyed(event){const executionContext=(event.data);if(this._context.flavor(SDK.ExecutionContext)===executionContext){this._currentExecutionContextGone();}}
_onExecutionContextOrderChanged(event){const runtimeModel=(event.data);const executionContexts=runtimeModel.executionContexts();for(let i=0;i<executionContexts.length;i++){if(this._switchContextIfNecessary(executionContexts[i])){break;}}}
_switchContextIfNecessary(executionContext){if(!this._context.flavor(SDK.ExecutionContext)||this._shouldSwitchToContext(executionContext)){this._ignoreContextChanged=true;this._context.setFlavor(SDK.ExecutionContext,executionContext);this._ignoreContextChanged=false;return true;}
return false;}
_currentExecutionContextGone(){const runtimeModels=this._targetManager.models(SDK.RuntimeModel);let newContext=null;for(let i=0;i<runtimeModels.length&&!newContext;++i){const executionContexts=runtimeModels[i].executionContexts();for(const executionContext of executionContexts){if(this._isDefaultContext(executionContext)){newContext=executionContext;break;}}}
if(!newContext){for(let i=0;i<runtimeModels.length&&!newContext;++i){const executionContexts=runtimeModels[i].executionContexts();if(executionContexts.length){newContext=executionContexts[0];break;}}}
this._ignoreContextChanged=true;this._context.setFlavor(SDK.ExecutionContext,newContext);this._ignoreContextChanged=false;}}