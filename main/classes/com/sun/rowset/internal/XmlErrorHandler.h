#ifndef _com_sun_rowset_internal_XmlErrorHandler_h_
#define _com_sun_rowset_internal_XmlErrorHandler_h_
//$ class com.sun.rowset.internal.XmlErrorHandler
//$ extends org.xml.sax.helpers.DefaultHandler

#include <org/xml/sax/helpers/DefaultHandler.h>

namespace org {
	namespace xml {
		namespace sax {
			class SAXParseException;
		}
	}
}

namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {

class XmlErrorHandler : public ::org::xml::sax::helpers::DefaultHandler {
	$class(XmlErrorHandler, $NO_CLASS_INIT, ::org::xml::sax::helpers::DefaultHandler)
public:
	XmlErrorHandler();
	void init$();
	virtual void error(::org::xml::sax::SAXParseException* e) override;
	virtual void fatalError(::org::xml::sax::SAXParseException* e) override;
	virtual void warning(::org::xml::sax::SAXParseException* exception) override;
	int32_t errorCounter = 0;
};

			} // internal
		} // rowset
	} // sun
} // com

#endif // _com_sun_rowset_internal_XmlErrorHandler_h_