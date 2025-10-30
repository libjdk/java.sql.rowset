#include <com/sun/rowset/internal/XmlResolver.h>

#include <java/io/InputStream.h>
#include <org/xml/sax/InputSource.h>
#include <jcpp.h>

using $InputStream = ::java::io::InputStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $EntityResolver = ::org::xml::sax::EntityResolver;
using $InputSource = ::org::xml::sax::InputSource;

namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {

$MethodInfo _XmlResolver_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(XmlResolver::*)()>(&XmlResolver::init$))},
	{"resolveEntity", "(Ljava/lang/String;Ljava/lang/String;)Lorg/xml/sax/InputSource;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _XmlResolver_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"com.sun.rowset.internal.XmlResolver",
	"java.lang.Object",
	"org.xml.sax.EntityResolver",
	nullptr,
	_XmlResolver_MethodInfo_
};

$Object* allocate$XmlResolver($Class* clazz) {
	return $of($alloc(XmlResolver));
}

void XmlResolver::init$() {
}

$InputSource* XmlResolver::resolveEntity($String* publicId, $String* systemId) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($String, schemaName, $nc(systemId)->substring(systemId->lastIndexOf((int32_t)u'/')));
	if (systemId->startsWith("http://java.sun.com/xml/ns/jdbc"_s)) {
		return $new($InputSource, $($of(this)->getClass()->getResourceAsStream(schemaName)));
	} else {
		return nullptr;
	}
}

XmlResolver::XmlResolver() {
}

$Class* XmlResolver::load$($String* name, bool initialize) {
	$loadClass(XmlResolver, name, initialize, &_XmlResolver_ClassInfo_, allocate$XmlResolver);
	return class$;
}

$Class* XmlResolver::class$ = nullptr;

			} // internal
		} // rowset
	} // sun
} // com