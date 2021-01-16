import{TimelineUIUtils}from'./TimelineUIUtils.js';export class IsLong extends TimelineModel.TimelineModelFilter{constructor(){super();this._minimumRecordDuration=0;}
setMinimumRecordDuration(value){this._minimumRecordDuration=value;}
accept(event){const duration=event.endTime?event.endTime-event.startTime:0;return duration>=this._minimumRecordDuration;}}
export class Category extends TimelineModel.TimelineModelFilter{constructor(){super();}
accept(event){return!TimelineUIUtils.eventStyle(event).category.hidden;}}
export class TimelineRegExp extends TimelineModel.TimelineModelFilter{constructor(regExp){super();this._regExp;this.setRegExp(regExp||null);}
setRegExp(regExp){this._regExp=regExp;}
regExp(){return this._regExp;}
accept(event){return!this._regExp||TimelineUIUtils.testContentMatching(event,this._regExp);}}