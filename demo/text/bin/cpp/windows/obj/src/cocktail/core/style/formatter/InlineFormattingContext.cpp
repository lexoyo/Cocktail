#include <hxcpp.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Element
#include <cocktail/core/dom/Element.h>
#endif
#ifndef INCLUDED_cocktail_core_dom_Node
#include <cocktail/core/dom/Node.h>
#endif
#ifndef INCLUDED_cocktail_core_event_IEventTarget
#include <cocktail/core/event/IEventTarget.h>
#endif
#ifndef INCLUDED_cocktail_core_html_HTMLElement
#include <cocktail/core/html/HTMLElement.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BlockBoxRenderer
#include <cocktail/core/renderer/BlockBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_BoxRenderer
#include <cocktail/core/renderer/BoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_ElementRenderer
#include <cocktail/core/renderer/ElementRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_FlowBoxRenderer
#include <cocktail/core/renderer/FlowBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_InlineBoxRenderer
#include <cocktail/core/renderer/InlineBoxRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_renderer_LayerRenderer
#include <cocktail/core/renderer/LayerRenderer.h>
#endif
#ifndef INCLUDED_cocktail_core_style_CoreStyle
#include <cocktail/core/style/CoreStyle.h>
#endif
#ifndef INCLUDED_cocktail_core_style_TextAlign
#include <cocktail/core/style/TextAlign.h>
#endif
#ifndef INCLUDED_cocktail_core_style_VerticalAlign
#include <cocktail/core/style/VerticalAlign.h>
#endif
#ifndef INCLUDED_cocktail_core_style_WhiteSpace
#include <cocktail/core/style/WhiteSpace.h>
#endif
#ifndef INCLUDED_cocktail_core_style_floats_FloatsManager
#include <cocktail/core/style/floats/FloatsManager.h>
#endif
#ifndef INCLUDED_cocktail_core_style_formatter_FormattingContext
#include <cocktail/core/style/formatter/FormattingContext.h>
#endif
#ifndef INCLUDED_cocktail_core_style_formatter_InlineFormattingContext
#include <cocktail/core/style/formatter/InlineFormattingContext.h>
#endif
namespace cocktail{
namespace core{
namespace style{
namespace formatter{

Void InlineFormattingContext_obj::__construct(::cocktail::core::renderer::BlockBoxRenderer formattingContextRoot)
{
{
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",77)
	this->_elementsInLineBox = Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new();
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",78)
	this->_unbreakableLineBoxElements = Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new();
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",79)
	this->_unbreakableWidth = (int)0;
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",80)
	this->_currentInlineBoxesData = Dynamic( Array_obj<Dynamic>::__new() );
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",82)
	super::__construct(formattingContextRoot);
}
;
	return null();
}

InlineFormattingContext_obj::~InlineFormattingContext_obj() { }

Dynamic InlineFormattingContext_obj::__CreateEmpty() { return  new InlineFormattingContext_obj; }
hx::ObjectPtr< InlineFormattingContext_obj > InlineFormattingContext_obj::__new(::cocktail::core::renderer::BlockBoxRenderer formattingContextRoot)
{  hx::ObjectPtr< InlineFormattingContext_obj > result = new InlineFormattingContext_obj();
	result->__construct(formattingContextRoot);
	return result;}

Dynamic InlineFormattingContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< InlineFormattingContext_obj > result = new InlineFormattingContext_obj();
	result->__construct(inArgs[0]);
	return result;}

Void InlineFormattingContext_obj::dispose( ){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::dispose")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",91)
		this->super::dispose();
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",92)
		this->_unbreakableLineBoxElements = null();
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",93)
		this->_elementsInLineBox = null();
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",94)
		this->_currentInlineBoxesData = null();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InlineFormattingContext_obj,dispose,(void))

Void InlineFormattingContext_obj::doFormat( Array< ::cocktail::core::renderer::ElementRenderer > elementsInFormattingContext){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::doFormat")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",99)
		this->_elementsInLineBox = Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new();
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",100)
		this->_unbreakableLineBoxElements = Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new();
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",101)
		this->_unbreakableWidth = (int)0;
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",103)
		this->_formattingContextRoot->removeLineBoxes();
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",105)
		this->_currentInlineBoxesData = Dynamic( Array_obj<Dynamic>::__new() );
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",108)
		this->super::doFormat(elementsInFormattingContext);
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",110)
		this->insertBreakOpportunity(true,true);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,doFormat,(void))

int InlineFormattingContext_obj::getRemainingLineWidth( ){
	HX_SOURCE_PUSH("InlineFormattingContext_obj::getRemainingLineWidth")
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",119)
	return ((this->_formattingContextRoot->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("width")) - this->_formattingContextData->__Field(HX_CSTRING("x"))) - this->_floatsManager->getRightFloatOffset(this->_formattingContextData->__Field(HX_CSTRING("y")),this->_formattingContextRoot->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("width"))));
}


HX_DEFINE_DYNAMIC_FUNC0(InlineFormattingContext_obj,getRemainingLineWidth,return )

Void InlineFormattingContext_obj::insertEmbeddedElement( ::cocktail::core::renderer::ElementRenderer element){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::insertEmbeddedElement")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",143)
		this->insertBreakOpportunity(false,null());
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",145)
		this->_unbreakableLineBoxElements->push(element);
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",146)
		this->_lastInsertedElement = element;
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",148)
		this->addWidth(::Math_obj::round(element->getBounds()->__Field(HX_CSTRING("width"))));
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",150)
		this->insertBreakOpportunity(false,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,insertEmbeddedElement,(void))

Void InlineFormattingContext_obj::insertFormattingContextRootElement( ::cocktail::core::renderer::ElementRenderer element){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::insertFormattingContextRootElement")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",159)
		Dynamic computedStyle = element->getCoreStyle()->getComputedStyle();
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",162)
		element->getBounds()->__FieldRef(HX_CSTRING("width")) = ((computedStyle->__Field(HX_CSTRING("width")) + computedStyle->__Field(HX_CSTRING("paddingLeft"))) + computedStyle->__Field(HX_CSTRING("paddingRight")));
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",163)
		element->getBounds()->__FieldRef(HX_CSTRING("height")) = ((computedStyle->__Field(HX_CSTRING("height")) + computedStyle->__Field(HX_CSTRING("paddingTop"))) + computedStyle->__Field(HX_CSTRING("paddingBottom")));
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",165)
		this->insertBreakOpportunity(false,null());
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",167)
		this->_unbreakableLineBoxElements->push(element);
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",168)
		this->_lastInsertedElement = element;
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",170)
		this->addWidth(::Math_obj::round(element->getBounds()->__Field(HX_CSTRING("width"))));
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",172)
		this->insertBreakOpportunity(false,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,insertFormattingContextRootElement,(void))

Void InlineFormattingContext_obj::insertContainerElement( ::cocktail::core::renderer::ElementRenderer element){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::insertContainerElement")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",177)
		this->_unbreakableLineBoxElements->push(element);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,insertContainerElement,(void))

Void InlineFormattingContext_obj::insertText( ::cocktail::core::renderer::ElementRenderer element){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::insertText")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",186)
		this->_unbreakableLineBoxElements->push(element);
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",187)
		this->_lastInsertedElement = element;
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",189)
		this->addWidth(::Math_obj::round(element->getBounds()->__Field(HX_CSTRING("width"))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,insertText,(void))

Void InlineFormattingContext_obj::insertSpace( ::cocktail::core::renderer::ElementRenderer element,bool isNextElementALineFeed){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::insertSpace")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",204)
		this->_unbreakableLineBoxElements->push(element);
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",206)
		this->_lastInsertedElement = element;
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",208)
		this->addWidth(::Math_obj::round(element->getBounds()->__Field(HX_CSTRING("width"))));
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",210)
		this->insertBreakOpportunity(false,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InlineFormattingContext_obj,insertSpace,(void))

Void InlineFormattingContext_obj::insertHorizontalOffset( ::cocktail::core::renderer::ElementRenderer element){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::insertHorizontalOffset")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,insertHorizontalOffset,(void))

Void InlineFormattingContext_obj::insertTab( ::cocktail::core::renderer::ElementRenderer element,bool isNextElementALineFeed){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::insertTab")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InlineFormattingContext_obj,insertTab,(void))

Void InlineFormattingContext_obj::insertLineFeed( ::cocktail::core::renderer::ElementRenderer element){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::insertLineFeed")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,insertLineFeed,(void))

Void InlineFormattingContext_obj::insertBreakOpportunity( bool forced,Dynamic __o_isLastLine){
bool isLastLine = __o_isLastLine.Default(false);
	HX_SOURCE_PUSH("InlineFormattingContext_obj::insertBreakOpportunity");
{
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",305)
		int remainingLineWidth = this->getRemainingLineWidth();
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",309)
		if (((isLastLine == true))){
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",310)
			this->insertBreakOpportunity(false,false);
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",317)
		if (((bool(((remainingLineWidth - this->_unbreakableWidth) < (int)0)) || bool((forced == true))))){
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",318)
			this->startNewLine(this->_unbreakableWidth,isLastLine);
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",325)
		{
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",325)
			int _g1 = (int)0;
			int _g = this->_unbreakableLineBoxElements->length;
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",325)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",325)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",327)
				this->_elementsInLineBox->push(this->_unbreakableLineBoxElements->__get(i));
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",330)
		this->_unbreakableLineBoxElements = Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new();
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",331)
		hx::AddEq(this->_formattingContextData->__FieldRef(HX_CSTRING("x")),this->_unbreakableWidth);
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",333)
		this->_unbreakableWidth = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InlineFormattingContext_obj,insertBreakOpportunity,(void))

Void InlineFormattingContext_obj::addWidth( int width){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::addWidth")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",340)
		hx::AddEq(this->_unbreakableWidth,width);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,addWidth,(void))

bool InlineFormattingContext_obj::shouldTabBeConvertedToSpace( ::cocktail::core::style::WhiteSpace whiteSpace){
	HX_SOURCE_PUSH("InlineFormattingContext_obj::shouldTabBeConvertedToSpace")
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",350)
	bool shouldTabBeConvertedToSpace;
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",352)
	{
::cocktail::core::style::WhiteSpace _switch_1 = (whiteSpace);
		switch((_switch_1)->GetIndex()){
			case 0: case 2: case 4: {
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",354)
				shouldTabBeConvertedToSpace = true;
			}
			;break;
			case 1: case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",359)
				shouldTabBeConvertedToSpace = false;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",364)
	return shouldTabBeConvertedToSpace;
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,shouldTabBeConvertedToSpace,return )

bool InlineFormattingContext_obj::isLineFeedAllowed( ::cocktail::core::style::WhiteSpace whiteSpace){
	HX_SOURCE_PUSH("InlineFormattingContext_obj::isLineFeedAllowed")
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",373)
	bool lineFeedAllowed;
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",375)
	{
::cocktail::core::style::WhiteSpace _switch_2 = (whiteSpace);
		switch((_switch_2)->GetIndex()){
			case 0: case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",377)
				lineFeedAllowed = false;
			}
			;break;
			case 1: case 3: case 4: {
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",381)
				lineFeedAllowed = true;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",387)
	return lineFeedAllowed;
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,isLineFeedAllowed,return )

bool InlineFormattingContext_obj::shouldInsertSpace( ::cocktail::core::style::WhiteSpace whiteSpace,bool isNexElementALineFeed){
	HX_SOURCE_PUSH("InlineFormattingContext_obj::shouldInsertSpace")
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",395)
	bool shouldInsertSpace;
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",397)
	{
::cocktail::core::style::WhiteSpace _switch_3 = (whiteSpace);
		switch((_switch_3)->GetIndex()){
			case 0: case 2: case 4: {
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",399)
				shouldInsertSpace = (isNexElementALineFeed == false);
			}
			;break;
			case 3: case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",404)
				shouldInsertSpace = true;
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",409)
	if (((shouldInsertSpace == true))){
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",410)
		(shouldInsertSpace != this->isCollapsed(this->_lastInsertedElement,whiteSpace));
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",415)
	return shouldInsertSpace;
}


HX_DEFINE_DYNAMIC_FUNC2(InlineFormattingContext_obj,shouldInsertSpace,return )

bool InlineFormattingContext_obj::isCollapsed( ::cocktail::core::renderer::ElementRenderer lastInsertedElement,::cocktail::core::style::WhiteSpace whiteSpace){
	HX_SOURCE_PUSH("InlineFormattingContext_obj::isCollapsed")
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",423)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC2(InlineFormattingContext_obj,isCollapsed,return )

Dynamic InlineFormattingContext_obj::getParentInlineBoxesData( ::cocktail::core::renderer::InlineBoxRenderer parent){
	HX_SOURCE_PUSH("InlineFormattingContext_obj::getParentInlineBoxesData")
	struct _Function_1_1{
		inline static Dynamic Block( ::cocktail::core::renderer::InlineBoxRenderer &parent){
			hx::Anon __result = hx::Anon_obj::Create();
			__result->Add(HX_CSTRING("element") , parent,false);
			__result->Add(HX_CSTRING("children") , Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new(),false);
			return __result;
		}
	};
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",473)
	Dynamic inlineBoxData = _Function_1_1::Block(parent);
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",478)
	bool flagFound = false;
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",479)
	{
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",479)
		int _g1 = (int)0;
		int _g = this->_currentInlineBoxesData->__Field(HX_CSTRING("length"));
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",479)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",479)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",481)
			if (((this->_currentInlineBoxesData->__GetItem(i)->__Field(HX_CSTRING("element")) == parent))){
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",483)
				inlineBoxData = this->_currentInlineBoxesData->__GetItem(i);
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",484)
				flagFound = true;
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",488)
	if (((flagFound == false))){
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",489)
		this->_currentInlineBoxesData->__Field(HX_CSTRING("push"))(inlineBoxData);
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",493)
	return inlineBoxData;
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,getParentInlineBoxesData,return )

Void InlineFormattingContext_obj::startNewLine( int elementWidth,bool isLastLine){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::startNewLine")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",497)
		if (((this->_elementsInLineBox->length > (int)0))){
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",500)
			this->removeSpaces();
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",501)
			int lineBoxHeight = this->computeLineBoxHeight();
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",503)
			int lineWidth = this->alignLineBox(isLastLine);
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",505)
			if (((lineWidth > this->_formattingContextData->__Field(HX_CSTRING("maxWidth"))))){
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",506)
				this->_formattingContextData->__FieldRef(HX_CSTRING("maxWidth")) = lineWidth;
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",510)
			Array< ::cocktail::core::renderer::ElementRenderer > lineBoxElements = Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new();
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",512)
			this->_formattingContextRoot->addLineBox(lineBoxElements);
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",514)
			{
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",514)
				int _g1 = (int)0;
				int _g = this->_elementsInLineBox->length;
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",514)
				while(((_g1 < _g))){
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",514)
					int i = (_g1)++;
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",516)
					if (((this->_elementsInLineBox->__get(i)->get_parentNode() != this->_formattingContextRoot->getCoreStyle()->getElementRenderer()))){
						HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",517)
						this->getParentInlineBoxesData(this->_elementsInLineBox->__get(i)->get_parentNode())->__Field(HX_CSTRING("children"))->__Field(HX_CSTRING("push"))(this->_elementsInLineBox->__get(i));
					}
					else{
						HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",522)
						lineBoxElements->push(this->_elementsInLineBox->__get(i));
					}
				}
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",527)
			{
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",527)
				int _g1 = (int)0;
				int _g = this->_currentInlineBoxesData->__Field(HX_CSTRING("length"));
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",527)
				while(((_g1 < _g))){
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",527)
					int i = (_g1)++;
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",529)
					{
						HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",529)
						int _g3 = (int)0;
						int _g2 = this->_currentInlineBoxesData->__GetItem(i)->__Field(HX_CSTRING("children"))->__Field(HX_CSTRING("length"));
						HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",529)
						while(((_g3 < _g2))){
							HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",529)
							int j = (_g3)++;
							HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",532)
							lineBoxElements->push(this->_currentInlineBoxesData->__GetItem(i)->__Field(HX_CSTRING("children"))->__GetItem(j));
						}
					}
				}
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",538)
			Array< ::cocktail::core::renderer::InlineBoxRenderer > inlineBoxes = Array_obj< ::cocktail::core::renderer::InlineBoxRenderer >::__new();
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",540)
			{
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",540)
				int _g1 = (int)0;
				int _g = this->_currentInlineBoxesData->__Field(HX_CSTRING("length"));
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",540)
				while(((_g1 < _g))){
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",540)
					int i = (_g1)++;
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",543)
					::cocktail::core::renderer::InlineBoxRenderer inlineBoxRenderer = ::cocktail::core::renderer::InlineBoxRenderer_obj::__new(this->_currentInlineBoxesData->__GetItem(i)->__Field(HX_CSTRING("element"))->__Field(HX_CSTRING("getCoreStyle"))());
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",544)
					inlineBoxRenderer->setLayerRenderer(this->_currentInlineBoxesData->__GetItem(i)->__Field(HX_CSTRING("element"))->__Field(HX_CSTRING("getLayerRenderer"))());
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",545)
					inlineBoxRenderer->setBounds(this->getBounds(this->_currentInlineBoxesData->__GetItem(i)->__Field(HX_CSTRING("children"))));
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",546)
					inlineBoxes->push(inlineBoxRenderer);
				}
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",552)
			inlineBoxes->reverse();
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",554)
			{
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",554)
				int _g1 = (int)0;
				int _g = inlineBoxes->length;
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",554)
				while(((_g1 < _g))){
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",554)
					int i = (_g1)++;
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",556)
					lineBoxElements->push(inlineBoxes->__get(i));
				}
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",561)
			this->_currentInlineBoxesData = Dynamic( Array_obj<Dynamic>::__new() );
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",562)
			this->_elementsInLineBox = Array_obj< ::cocktail::core::renderer::ElementRenderer >::__new();
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",565)
			if (((isLastLine == false))){
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",567)
				hx::AddEq(this->_formattingContextData->__FieldRef(HX_CSTRING("y")),lineBoxHeight);
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",569)
				this->_formattingContextData->__FieldRef(HX_CSTRING("y")) = this->_floatsManager->getFirstAvailableY(this->_formattingContextData,elementWidth,this->_formattingContextRoot->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("width")));
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",571)
				if ((((this->_formattingContextData->__Field(HX_CSTRING("y")) + lineBoxHeight) > this->_formattingContextData->__Field(HX_CSTRING("maxHeight"))))){
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",572)
					this->_formattingContextData->__FieldRef(HX_CSTRING("maxHeight")) = (this->_formattingContextData->__Field(HX_CSTRING("y")) + lineBoxHeight);
				}
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",577)
				this->_formattingContextData->__FieldRef(HX_CSTRING("x")) = this->_floatsManager->getLeftFloatOffset(this->_formattingContextData->__Field(HX_CSTRING("y")));
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",580)
				if (((this->_layOutLastLine == true))){
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",582)
					hx::AddEq(this->_formattingContextData->__FieldRef(HX_CSTRING("y")),lineBoxHeight);
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",584)
					this->_formattingContextData->__FieldRef(HX_CSTRING("y")) = this->_floatsManager->getFirstAvailableY(this->_formattingContextData,elementWidth,this->_formattingContextRoot->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("width")));
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",587)
					if (((this->_formattingContextData->__Field(HX_CSTRING("y")) > this->_formattingContextData->__Field(HX_CSTRING("maxHeight"))))){
						HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",588)
						this->_formattingContextData->__FieldRef(HX_CSTRING("maxHeight")) = this->_formattingContextData->__Field(HX_CSTRING("y"));
					}
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",592)
					this->_formattingContextData->__FieldRef(HX_CSTRING("x")) = this->_floatsManager->getLeftFloatOffset(this->_formattingContextData->__Field(HX_CSTRING("y")));
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InlineFormattingContext_obj,startNewLine,(void))

Void InlineFormattingContext_obj::removeSpaces( ){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::removeSpaces")
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(InlineFormattingContext_obj,removeSpaces,(void))

int InlineFormattingContext_obj::alignLineBox( bool isLastLine){
	HX_SOURCE_PUSH("InlineFormattingContext_obj::alignLineBox")
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",668)
	int concatenatedLength = (int)0;
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",669)
	{
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",669)
		int _g1 = (int)0;
		int _g = this->_elementsInLineBox->length;
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",669)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",669)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",671)
			hx::AddEq(concatenatedLength,::Math_obj::round(this->_elementsInLineBox->__get(i)->getBounds()->__Field(HX_CSTRING("width"))));
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",679)
	int remainingSpace;
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",680)
	int flowX;
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",682)
	remainingSpace = (((this->_formattingContextRoot->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("width")) - concatenatedLength) - this->_floatsManager->getLeftFloatOffset(this->_formattingContextData->__Field(HX_CSTRING("y")))) - this->_floatsManager->getRightFloatOffset(this->_formattingContextData->__Field(HX_CSTRING("y")),this->_formattingContextRoot->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("width"))));
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",684)
	flowX = this->_formattingContextRoot->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingLeft"));
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",687)
	hx::AddEq(flowX,this->_floatsManager->getLeftFloatOffset(this->_formattingContextData->__Field(HX_CSTRING("y"))));
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",691)
	{
::cocktail::core::style::TextAlign _switch_4 = (this->_formattingContextRoot->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("textAlign")));
		switch((_switch_4)->GetIndex()){
			case 0: {
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",693)
				this->alignLeft(flowX);
			}
			;break;
			case 1: {
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",696)
				this->alignRight(flowX,remainingSpace);
			}
			;break;
			case 2: {
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",699)
				this->alignCenter(flowX,remainingSpace);
			}
			;break;
			case 3: {
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",702)
				if (((isLastLine == true))){
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",707)
					this->alignLeft(flowX);
				}
				else{
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",714)
					concatenatedLength = this->_formattingContextRoot->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("width"));
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",716)
					this->alignJustify(flowX,remainingSpace);
				}
			}
			;break;
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",720)
	return concatenatedLength;
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,alignLineBox,return )

Void InlineFormattingContext_obj::alignLeft( int flowX){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::alignLeft")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",729)
		int _g1 = (int)0;
		int _g = this->_elementsInLineBox->length;
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",729)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",729)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",731)
			this->_elementsInLineBox->__get(i)->getBounds()->__FieldRef(HX_CSTRING("x")) = flowX;
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",732)
			hx::AddEq(flowX,::Math_obj::round(this->_elementsInLineBox->__get(i)->getBounds()->__Field(HX_CSTRING("width"))));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(InlineFormattingContext_obj,alignLeft,(void))

Void InlineFormattingContext_obj::alignCenter( int flowX,int remainingSpace){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::alignCenter")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",745)
		int _g1 = (int)0;
		int _g = this->_elementsInLineBox->length;
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",745)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",745)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",747)
			this->_elementsInLineBox->__get(i)->getBounds()->__FieldRef(HX_CSTRING("x")) = (::Math_obj::round((double(remainingSpace) / double((int)2))) + flowX);
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",748)
			hx::AddEq(flowX,::Math_obj::round(this->_elementsInLineBox->__get(i)->getBounds()->__Field(HX_CSTRING("width"))));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InlineFormattingContext_obj,alignCenter,(void))

Void InlineFormattingContext_obj::alignRight( int flowX,int remainingSpace){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::alignRight")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",761)
		int _g1 = (int)0;
		int _g = this->_elementsInLineBox->length;
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",761)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",761)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",763)
			this->_elementsInLineBox->__get(i)->getBounds()->__FieldRef(HX_CSTRING("x")) = (flowX + remainingSpace);
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",764)
			hx::AddEq(flowX,::Math_obj::round(this->_elementsInLineBox->__get(i)->getBounds()->__Field(HX_CSTRING("width"))));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InlineFormattingContext_obj,alignRight,(void))

Void InlineFormattingContext_obj::alignJustify( int flowX,int remainingSpace){
{
		HX_SOURCE_PUSH("InlineFormattingContext_obj::alignJustify")
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",778)
		int spacesNumber = (int)0;
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",779)
		{
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",779)
			int _g1 = (int)0;
			int _g = this->_elementsInLineBox->length;
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",779)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",779)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",781)
				if (((this->_elementsInLineBox->__get(i)->isSpace() == true))){
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",782)
					(spacesNumber)++;
				}
			}
		}
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",788)
		{
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",788)
			int _g1 = (int)0;
			int _g = this->_elementsInLineBox->length;
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",788)
			while(((_g1 < _g))){
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",788)
				int i = (_g1)++;
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",790)
				if (((this->_elementsInLineBox->__get(i)->isSpace() == true))){
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",792)
					int spaceWidth = ::Math_obj::round((double(remainingSpace) / double(spacesNumber)));
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",793)
					(spacesNumber)--;
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",794)
					hx::SubEq(remainingSpace,spaceWidth);
					HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",795)
					hx::AddEq(flowX,spaceWidth);
				}
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",798)
				this->_elementsInLineBox->__get(i)->getBounds()->__FieldRef(HX_CSTRING("x")) = flowX;
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",799)
				hx::AddEq(flowX,::Math_obj::round(this->_elementsInLineBox->__get(i)->getBounds()->__Field(HX_CSTRING("width"))));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(InlineFormattingContext_obj,alignJustify,(void))

int InlineFormattingContext_obj::computeLineBoxHeight( ){
	HX_SOURCE_PUSH("InlineFormattingContext_obj::computeLineBoxHeight")
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",823)
	double lineBoxAscent = (int)0;
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",824)
	double lineBoxDescent = (int)0;
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",828)
	{
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",828)
		int _g1 = (int)0;
		int _g = this->_elementsInLineBox->length;
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",828)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",828)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",831)
			::cocktail::core::html::HTMLElement htmlElement = this->_elementsInLineBox->__get(i)->getCoreStyle()->get_htmlElement();
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",833)
			int htmlElementAscent;
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",834)
			int htmlElementDescent;
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",838)
			double htmlElementVerticalAlign = htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("verticalAlign"));
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",842)
			if (((bool((bool((this->_elementsInLineBox->__get(i)->isEmbedded() == true)) && bool((this->_elementsInLineBox->__get(i)->isText() == false)))) || bool((this->_elementsInLineBox->__get(i)->establishesNewFormattingContext() == true))))){
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",845)
				htmlElementAscent = ((((htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("height")) + htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingTop"))) + htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingBottom"))) + this->_elementsInLineBox->__get(i)->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("marginTop"))) + this->_elementsInLineBox->__get(i)->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("marginBottom")));
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",848)
				htmlElementDescent = (int)0;
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",850)
				{
::cocktail::core::style::VerticalAlign _switch_5 = (htmlElement->get_coreStyle()->getVerticalAlign());
					switch((_switch_5)->GetIndex()){
						case 3: {
							HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",853)
							htmlElementAscent = ::Math_obj::round(lineBoxAscent);
							HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",854)
							htmlElementDescent = ::Math_obj::round((((htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("height")) + htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingTop"))) + htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingBottom"))) - lineBoxAscent));
						}
						;break;
						default: {
						}
					}
				}
			}
			else{
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",864)
				htmlElementAscent = htmlElement->get_coreStyle()->getFontMetricsData()->__Field(HX_CSTRING("ascent"));
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",865)
				htmlElementDescent = htmlElement->get_coreStyle()->getFontMetricsData()->__Field(HX_CSTRING("descent"));
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",869)
				double leading = (htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("lineHeight")) - ((htmlElementAscent + htmlElementDescent)));
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",872)
				htmlElementAscent = ::Math_obj::round((htmlElementAscent + (double(leading) / double((int)2))));
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",873)
				htmlElementDescent = ::Math_obj::round((htmlElementDescent + (double(leading) / double((int)2))));
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",878)
			if ((((htmlElementAscent - htmlElementVerticalAlign) > lineBoxAscent))){
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",879)
				lineBoxAscent = (htmlElementAscent - htmlElementVerticalAlign);
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",883)
			if ((((htmlElementDescent + htmlElementVerticalAlign) > lineBoxDescent))){
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",884)
				lineBoxDescent = (htmlElementDescent + htmlElementVerticalAlign);
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",891)
	double lineBoxHeight = (lineBoxAscent + lineBoxDescent);
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",894)
	{
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",894)
		int _g1 = (int)0;
		int _g = this->_elementsInLineBox->length;
		HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",894)
		while(((_g1 < _g))){
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",894)
			int i = (_g1)++;
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",897)
			::cocktail::core::html::HTMLElement htmlElement = this->_elementsInLineBox->__get(i)->getCoreStyle()->get_htmlElement();
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",899)
			double verticalAlign;
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",900)
			{
::cocktail::core::style::VerticalAlign _switch_6 = (htmlElement->get_coreStyle()->getVerticalAlign());
				switch((_switch_6)->GetIndex()){
					case 3: {
						HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",902)
						verticalAlign = (int)0;
					}
					;break;
					case 6: {
						HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",906)
						verticalAlign = (int)0;
					}
					;break;
					default: {
						HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",909)
						verticalAlign = htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("verticalAlign"));
					}
				}
			}
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",913)
			this->_elementsInLineBox->__get(i)->getBounds()->__FieldRef(HX_CSTRING("y")) = (((::Math_obj::round(lineBoxAscent) + ::Math_obj::round(verticalAlign)) + this->_formattingContextData->__Field(HX_CSTRING("y"))) + this->_formattingContextRoot->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingTop")));
			HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",921)
			if (((bool((bool((this->_elementsInLineBox->__get(i)->isEmbedded() == true)) && bool((this->_elementsInLineBox->__get(i)->isText() == false)))) || bool((this->_elementsInLineBox->__get(i)->establishesNewFormattingContext() == true))))){
				HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",923)
				{
::cocktail::core::style::VerticalAlign _switch_7 = (htmlElement->get_coreStyle()->getVerticalAlign());
					switch((_switch_7)->GetIndex()){
						case 3: {
							HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",927)
							this->_elementsInLineBox->__get(i)->getBounds()->__FieldRef(HX_CSTRING("y")) = this->_formattingContextData->__Field(HX_CSTRING("y"));
						}
						;break;
						default: {
							HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",930)
							hx::SubEq(this->_elementsInLineBox->__get(i)->getBounds()->__FieldRef(HX_CSTRING("y")),((((htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("height")) + htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingTop"))) + htmlElement->get_coreStyle()->getComputedStyle()->__Field(HX_CSTRING("paddingBottom"))) + this->_elementsInLineBox->__get(i)->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("marginTop"))) + this->_elementsInLineBox->__get(i)->getCoreStyle()->getComputedStyle()->__Field(HX_CSTRING("marginBottom"))));
						}
					}
				}
			}
		}
	}
	HX_SOURCE_POS("../../src/cocktail/core/style/formatter/InlineFormattingContext.hx",940)
	return ::Math_obj::round(lineBoxHeight);
}


HX_DEFINE_DYNAMIC_FUNC0(InlineFormattingContext_obj,computeLineBoxHeight,return )


InlineFormattingContext_obj::InlineFormattingContext_obj()
{
}

void InlineFormattingContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(InlineFormattingContext);
	HX_MARK_MEMBER_NAME(_elementsInLineBox,"_elementsInLineBox");
	HX_MARK_MEMBER_NAME(_unbreakableLineBoxElements,"_unbreakableLineBoxElements");
	HX_MARK_MEMBER_NAME(_unbreakableWidth,"_unbreakableWidth");
	HX_MARK_MEMBER_NAME(_currentInlineBoxesData,"_currentInlineBoxesData");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

Dynamic InlineFormattingContext_obj::__Field(const ::String &inName)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"doFormat") ) { return doFormat_dyn(); }
		if (HX_FIELD_EQ(inName,"addWidth") ) { return addWidth_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"insertTab") ) { return insertTab_dyn(); }
		if (HX_FIELD_EQ(inName,"alignLeft") ) { return alignLeft_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"insertText") ) { return insertText_dyn(); }
		if (HX_FIELD_EQ(inName,"alignRight") ) { return alignRight_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"insertSpace") ) { return insertSpace_dyn(); }
		if (HX_FIELD_EQ(inName,"isCollapsed") ) { return isCollapsed_dyn(); }
		if (HX_FIELD_EQ(inName,"alignCenter") ) { return alignCenter_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"startNewLine") ) { return startNewLine_dyn(); }
		if (HX_FIELD_EQ(inName,"removeSpaces") ) { return removeSpaces_dyn(); }
		if (HX_FIELD_EQ(inName,"alignLineBox") ) { return alignLineBox_dyn(); }
		if (HX_FIELD_EQ(inName,"alignJustify") ) { return alignJustify_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"insertLineFeed") ) { return insertLineFeed_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"_unbreakableWidth") ) { return _unbreakableWidth; }
		if (HX_FIELD_EQ(inName,"isLineFeedAllowed") ) { return isLineFeedAllowed_dyn(); }
		if (HX_FIELD_EQ(inName,"shouldInsertSpace") ) { return shouldInsertSpace_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_elementsInLineBox") ) { return _elementsInLineBox; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"computeLineBoxHeight") ) { return computeLineBoxHeight_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getRemainingLineWidth") ) { return getRemainingLineWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"insertEmbeddedElement") ) { return insertEmbeddedElement_dyn(); }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"insertContainerElement") ) { return insertContainerElement_dyn(); }
		if (HX_FIELD_EQ(inName,"insertHorizontalOffset") ) { return insertHorizontalOffset_dyn(); }
		if (HX_FIELD_EQ(inName,"insertBreakOpportunity") ) { return insertBreakOpportunity_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_currentInlineBoxesData") ) { return _currentInlineBoxesData; }
		break;
	case 24:
		if (HX_FIELD_EQ(inName,"getParentInlineBoxesData") ) { return getParentInlineBoxesData_dyn(); }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"_unbreakableLineBoxElements") ) { return _unbreakableLineBoxElements; }
		if (HX_FIELD_EQ(inName,"shouldTabBeConvertedToSpace") ) { return shouldTabBeConvertedToSpace_dyn(); }
		break;
	case 34:
		if (HX_FIELD_EQ(inName,"insertFormattingContextRootElement") ) { return insertFormattingContextRootElement_dyn(); }
	}
	return super::__Field(inName);
}

Dynamic InlineFormattingContext_obj::__SetField(const ::String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 17:
		if (HX_FIELD_EQ(inName,"_unbreakableWidth") ) { _unbreakableWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"_elementsInLineBox") ) { _elementsInLineBox=inValue.Cast< Array< ::cocktail::core::renderer::ElementRenderer > >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"_currentInlineBoxesData") ) { _currentInlineBoxesData=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"_unbreakableLineBoxElements") ) { _unbreakableLineBoxElements=inValue.Cast< Array< ::cocktail::core::renderer::ElementRenderer > >(); return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void InlineFormattingContext_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_elementsInLineBox"));
	outFields->push(HX_CSTRING("_unbreakableLineBoxElements"));
	outFields->push(HX_CSTRING("_unbreakableWidth"));
	outFields->push(HX_CSTRING("_currentInlineBoxesData"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("_elementsInLineBox"),
	HX_CSTRING("_unbreakableLineBoxElements"),
	HX_CSTRING("_unbreakableWidth"),
	HX_CSTRING("_currentInlineBoxesData"),
	HX_CSTRING("dispose"),
	HX_CSTRING("doFormat"),
	HX_CSTRING("getRemainingLineWidth"),
	HX_CSTRING("insertEmbeddedElement"),
	HX_CSTRING("insertFormattingContextRootElement"),
	HX_CSTRING("insertContainerElement"),
	HX_CSTRING("insertText"),
	HX_CSTRING("insertSpace"),
	HX_CSTRING("insertHorizontalOffset"),
	HX_CSTRING("insertTab"),
	HX_CSTRING("insertLineFeed"),
	HX_CSTRING("insertBreakOpportunity"),
	HX_CSTRING("addWidth"),
	HX_CSTRING("shouldTabBeConvertedToSpace"),
	HX_CSTRING("isLineFeedAllowed"),
	HX_CSTRING("shouldInsertSpace"),
	HX_CSTRING("isCollapsed"),
	HX_CSTRING("getParentInlineBoxesData"),
	HX_CSTRING("startNewLine"),
	HX_CSTRING("removeSpaces"),
	HX_CSTRING("alignLineBox"),
	HX_CSTRING("alignLeft"),
	HX_CSTRING("alignCenter"),
	HX_CSTRING("alignRight"),
	HX_CSTRING("alignJustify"),
	HX_CSTRING("computeLineBoxHeight"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

Class InlineFormattingContext_obj::__mClass;

void InlineFormattingContext_obj::__register()
{
	Static(__mClass) = hx::RegisterClass(HX_CSTRING("cocktail.core.style.formatter.InlineFormattingContext"), hx::TCanCast< InlineFormattingContext_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void InlineFormattingContext_obj::__boot()
{
}

} // end namespace cocktail
} // end namespace core
} // end namespace style
} // end namespace formatter
