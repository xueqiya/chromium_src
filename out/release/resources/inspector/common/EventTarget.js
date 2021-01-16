export let EventDescriptor;export function removeEventListeners(eventList){for(const eventInfo of eventList){eventInfo.eventTarget.removeEventListener(eventInfo.eventType,eventInfo.listener,eventInfo.thisObject);}
eventList.splice(0);}
export class EventTarget{addEventListener(eventType,listener,thisObject){}
once(eventType){}
removeEventListener(eventType,listener,thisObject){}
hasEventListeners(eventType){}
dispatchEventToListeners(eventType,eventData){}}
EventTarget.removeEventListeners=removeEventListeners;