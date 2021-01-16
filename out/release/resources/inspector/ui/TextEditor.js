import*as Common from'../common/common.js';import{Widget}from'./Widget.js';export class TextEditorFactory{createEditor(options){}}
export class TextEditor extends Common.EventTarget.EventTarget{widget(){}
fullRange(){}
selection(){}
setSelection(selection){}
text(textRange){}
textWithCurrentSuggestion(){}
setText(text){}
line(lineNumber){}
newlineAndIndent(){}
addKeyDownHandler(handler){}
configureAutocomplete(config){}
clearAutocomplete(){}
visualCoordinates(lineNumber,columnNumber){}
tokenAtTextPosition(lineNumber,columnNumber){}
setPlaceholder(placeholder){}}
export const Events={CursorChanged:Symbol('CursorChanged'),TextChanged:Symbol('TextChanged'),SuggestionChanged:Symbol('SuggestionChanged')};