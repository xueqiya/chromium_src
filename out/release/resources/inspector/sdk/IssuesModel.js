import{CookieModel}from'./CookieModel.js';import{Events,NetworkManager}from'./NetworkManager.js';import{NetworkRequest,setCookieBlockedReasonToAttribute,setCookieBlockedReasonToUiString,}from'./NetworkRequest.js';import{Capability,SDKModel,Target}from'./SDKModel.js';class Issue{constructor(category,name,data){this._category=category;this._name=name;this._data=data;}}
Issue.Categories={SameSite:Symbol('SameSite'),};const connectedIssuesSymbol=Symbol('issues');export class IssuesModel extends SDKModel{constructor(target){super(target);const networkManager=target.model(NetworkManager);if(networkManager){networkManager.addEventListener(Events.RequestFinished,this._handleRequestFinished,this);}
this._cookiesModel=target.model(CookieModel);this._issues=[];}
static connectWithIssue(obj,issue){if(!obj){return;}
if(!obj[connectedIssuesSymbol]){obj[connectedIssuesSymbol]=[];}
obj[connectedIssuesSymbol].push(issue);}
static hasIssues(obj){if(!obj){return false;}
return obj[connectedIssuesSymbol]&&obj[connectedIssuesSymbol].length;}
_handleRequestFinished(event){const request=(event.data);const blockedResponseCookies=request.blockedResponseCookies();for(const blockedCookie of blockedResponseCookies){const cookie=blockedCookie.cookie;if(!cookie){continue;}
const reason=blockedCookie.blockedReasons[0];const issue=new Issue(Issue.Categories.SameSite,reason,{request,cookie});IssuesModel.connectWithIssue(request,issue);IssuesModel.connectWithIssue(cookie,issue);this._cookiesModel.addBlockedCookie(cookie,blockedCookie.blockedReasons.map(blockedReason=>({attribute:setCookieBlockedReasonToAttribute(blockedReason),uiString:setCookieBlockedReasonToUiString(blockedReason)})));}}}
SDKModel.register(IssuesModel,Capability.None,true);