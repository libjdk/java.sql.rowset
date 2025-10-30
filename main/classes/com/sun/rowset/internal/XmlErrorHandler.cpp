#include <com/sun/rowset/internal/XmlErrorHandler.h>

#include <org/xml/sax/SAXParseException.h>
#include <org/xml/sax/helpers/DefaultHandler.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SAXParseException = ::org::xml::sax::SAXParseException;
using $DefaultHandler = ::org::xml::sax::helpers::DefaultHandler;

namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {

$FieldInfo _XmlErrorHandler_FieldInfo_[] = {
	{"errorCounter", "I", nullptr, $PUBLIC, $field(XmlErrorHandler, errorCounter)},
	{}
};

$MethodInfo _XmlErrorHandler_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(XmlErrorHandler::*)()>(&XmlErrorHandler::init$))},
	{"error", "(Lorg/xml/sax/SAXParseException;)V", nullptr, $PUBLIC, nullptr, "org.xml.sax.SAXException"},
	{"fatalError", "(Lorg/xml/sax/SAXParseException;)V", nullptr, $PUBLIC, nullptr, "org.xml.sax.SAXException"},
	{"warning", "(Lorg/xml/sax/SAXParseException;)V", nullptr, $PUBLIC, nullptr, "org.xml.sax.SAXException"},
	{}
};

$ClassInfo _XmlErrorHandler_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"com.sun.rowset.internal.XmlErrorHandler",
	"org.xml.sax.helpers.DefaultHandler",
	nullptr,
	_XmlErrorHandler_FieldInfo_,
	_XmlErrorHandler_MethodInfo_
};

$Object* allocate$XmlErrorHandler($Class* clazz) {
	return $of($alloc(XmlErrorHandler));
}

void XmlErrorHandler::init$() {
	$DefaultHandler::init$();
	this->errorCounter = 0;
}

void XmlErrorHandler::error($SAXParseException* e) {
	++this->errorCounter;
}

void XmlErrorHandler::fatalError($SAXParseException* e) {
	++this->errorCounter;
}

void XmlErrorHandler::warning($SAXParseException* exception) {
}

XmlErrorHandler::XmlErrorHandler() {
}

$Class* XmlErrorHandler::load$($String* name, bool initialize) {
	$loadClass(XmlErrorHandler, name, initialize, &_XmlErrorHandler_ClassInfo_, allocate$XmlErrorHandler);
	return class$;
}

$Class* XmlErrorHandler::class$ = nullptr;

			} // internal
		} // rowset
	} // sun
} // com