export class HARWriter{static async write(stream,requests,progress){const compositeProgress=new Common.CompositeProgress(progress);const content=await HARWriter._harStringForRequests(requests,compositeProgress);if(progress.isCanceled()){return Promise.resolve();}
return HARWriter._writeToStream(stream,compositeProgress,content);}
static async _harStringForRequests(requests,compositeProgress){const progress=compositeProgress.createSubProgress();progress.setTitle(Common.UIString('Collecting content\u2026'));progress.setTotalWork(requests.length);const harLog=await SDK.HARLog.build(requests);const promises=[];for(let i=0;i<requests.length;i++){const promise=requests[i].contentData();promises.push(promise.then(contentLoaded.bind(null,harLog.entries[i])));}
await Promise.all(promises);progress.done();if(progress.isCanceled()){return'';}
return JSON.stringify({log:harLog},null,_jsonIndent);function isValidCharacter(code_point){return code_point<0xD800||(code_point>=0xE000&&code_point<0xFDD0)||(code_point>0xFDEF&&code_point<=0x10FFFF&&(code_point&0xFFFE)!==0xFFFE);}
function needsEncoding(content){for(let i=0;i<content.length;i++){if(!isValidCharacter(content.charCodeAt(i))){return true;}}
return false;}
function contentLoaded(entry,contentData){progress.worked();let encoded=contentData.encoded;if(contentData.content!==null){let content=contentData.content;if(content&&!encoded&&needsEncoding(content)){content=content.toBase64();encoded=true;}
entry.response.content.text=content;}
if(encoded){entry.response.content.encoding='base64';}}}
static async _writeToStream(stream,compositeProgress,fileContent){const progress=compositeProgress.createSubProgress();progress.setTitle(Common.UIString('Writing file\u2026'));progress.setTotalWork(fileContent.length);for(let i=0;i<fileContent.length&&!progress.isCanceled();i+=_chunkSize){const chunk=fileContent.substr(i,_chunkSize);await stream.write(chunk);progress.worked(chunk.length);}
progress.done();}}
export const _jsonIndent=2;export const _chunkSize=100000;