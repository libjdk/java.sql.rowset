#ifndef _com_sun_rowset_internal_XmlResolver_h_
#define _com_sun_rowset_internal_XmlResolver_h_
//$ class com.sun.rowset.internal.XmlResolver
//$ extends org.xml.sax.EntityResolver

#include <org/xml/sax/EntityResolver.h>

namespace org {
	namespace xml {
		namespace sax {
			class InputSource;
		}
	}
}

namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {

class XmlResolver : public ::org::xml::sax::EntityResolver {
	$class(XmlResolver, $NO_CLASS_INIT, ::org::xml::sax::EntityResolver)
public:
	XmlResolver();
	void init$();
	virtual ::org::xml::sax::InputSource* resolveEntity($String* publicId, $String* systemId) override;
};

			} // internal
		} // rowset
	} // sun
} // com

#endif // _com_sun_rowset_internal_XmlResolver_h_