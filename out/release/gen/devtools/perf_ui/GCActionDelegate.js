export class GCActionDelegate{handleAction(context,actionId){for(const heapProfilerModel of self.SDK.targetManager.models(SDK.HeapProfilerModel)){heapProfilerModel.collectGarbage();}
return true;}}