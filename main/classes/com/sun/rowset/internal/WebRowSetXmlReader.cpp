#include <com/sun/rowset/internal/WebRowSetXmlReader.h>

#include <com/sun/rowset/JdbcRowSetResourceBundle.h>
#include <com/sun/rowset/internal/XmlErrorHandler.h>
#include <com/sun/rowset/internal/XmlReaderContentHandler.h>
#include <com/sun/rowset/internal/XmlResolver.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/Reader.h>
#include <java/lang/ArrayIndexOutOfBoundsException.h>
#include <java/sql/SQLException.h>
#include <java/text/MessageFormat.h>
#include <javax/sql/RowSet.h>
#include <javax/sql/RowSetInternal.h>
#include <javax/sql/rowset/CachedRowSet.h>
#include <javax/sql/rowset/WebRowSet.h>
#include <javax/sql/rowset/spi/XmlReader.h>
#include <javax/xml/parsers/SAXParser.h>
#include <javax/xml/parsers/SAXParserFactory.h>
#include <org/xml/sax/ContentHandler.h>
#include <org/xml/sax/EntityResolver.h>
#include <org/xml/sax/ErrorHandler.h>
#include <org/xml/sax/InputSource.h>
#include <org/xml/sax/SAXException.h>
#include <org/xml/sax/SAXParseException.h>
#include <org/xml/sax/XMLReader.h>
#include <org/xml/sax/helpers/DefaultHandler.h>
#include <jcpp.h>

using $JdbcRowSetResourceBundle = ::com::sun::rowset::JdbcRowSetResourceBundle;
using $XmlErrorHandler = ::com::sun::rowset::internal::XmlErrorHandler;
using $XmlReaderContentHandler = ::com::sun::rowset::internal::XmlReaderContentHandler;
using $XmlResolver = ::com::sun::rowset::internal::XmlResolver;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $PrintStream = ::java::io::PrintStream;
using $Reader = ::java::io::Reader;
using $Serializable = ::java::io::Serializable;
using $ArrayIndexOutOfBoundsException = ::java::lang::ArrayIndexOutOfBoundsException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $SQLException = ::java::sql::SQLException;
using $MessageFormat = ::java::text::MessageFormat;
using $RowSet = ::javax::sql::RowSet;
using $RowSetInternal = ::javax::sql::RowSetInternal;
using $CachedRowSet = ::javax::sql::rowset::CachedRowSet;
using $WebRowSet = ::javax::sql::rowset::WebRowSet;
using $XmlReader = ::javax::sql::rowset::spi::XmlReader;
using $SAXParser = ::javax::xml::parsers::SAXParser;
using $SAXParserFactory = ::javax::xml::parsers::SAXParserFactory;
using $ContentHandler = ::org::xml::sax::ContentHandler;
using $EntityResolver = ::org::xml::sax::EntityResolver;
using $ErrorHandler = ::org::xml::sax::ErrorHandler;
using $InputSource = ::org::xml::sax::InputSource;
using $SAXException = ::org::xml::sax::SAXException;
using $SAXParseException = ::org::xml::sax::SAXParseException;
using $XMLReader = ::org::xml::sax::XMLReader;
using $DefaultHandler = ::org::xml::sax::helpers::DefaultHandler;

namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {

$FieldInfo _WebRowSetXmlReader_FieldInfo_[] = {
	{"resBundle", "Lcom/sun/rowset/JdbcRowSetResourceBundle;", nullptr, $PRIVATE, $field(WebRowSetXmlReader, resBundle)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(WebRowSetXmlReader, serialVersionUID)},
	{}
};

$MethodInfo _WebRowSetXmlReader_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(WebRowSetXmlReader::*)()>(&WebRowSetXmlReader::init$))},
	{"readData", "(Ljavax/sql/RowSetInternal;)V", nullptr, $PUBLIC},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(WebRowSetXmlReader::*)($ObjectInputStream*)>(&WebRowSetXmlReader::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"readXML", "(Ljavax/sql/rowset/WebRowSet;Ljava/io/Reader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readXML", "(Ljavax/sql/rowset/WebRowSet;Ljava/io/InputStream;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _WebRowSetXmlReader_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"com.sun.rowset.internal.WebRowSetXmlReader",
	"java.lang.Object",
	"javax.sql.rowset.spi.XmlReader,java.io.Serializable",
	_WebRowSetXmlReader_FieldInfo_,
	_WebRowSetXmlReader_MethodInfo_
};

$Object* allocate$WebRowSetXmlReader($Class* clazz) {
	return $of($alloc(WebRowSetXmlReader));
}

int32_t WebRowSetXmlReader::hashCode() {
	 return this->$XmlReader::hashCode();
}

bool WebRowSetXmlReader::equals(Object$* arg0) {
	 return this->$XmlReader::equals(arg0);
}

$Object* WebRowSetXmlReader::clone() {
	 return this->$XmlReader::clone();
}

$String* WebRowSetXmlReader::toString() {
	 return this->$XmlReader::toString();
}

void WebRowSetXmlReader::finalize() {
	this->$XmlReader::finalize();
}

void WebRowSetXmlReader::init$() {
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
}

void WebRowSetXmlReader::readXML($WebRowSet* caller, $Reader* reader) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($InputSource, is, $new($InputSource, reader));
		$var($DefaultHandler, dh, $new($XmlErrorHandler));
		$var($XmlReaderContentHandler, hndr, $new($XmlReaderContentHandler, static_cast<$RowSet*>(caller)));
		$var($SAXParserFactory, factory, $SAXParserFactory::newInstance());
		$nc(factory)->setNamespaceAware(true);
		factory->setValidating(true);
		$var($SAXParser, parser, factory->newSAXParser());
		$nc(parser)->setProperty("http://java.sun.com/xml/jaxp/properties/schemaLanguage"_s, "http://www.w3.org/2001/XMLSchema"_s);
		$var($XMLReader, reader1, parser->getXMLReader());
		$nc(reader1)->setEntityResolver($$new($XmlResolver));
		reader1->setContentHandler(hndr);
		reader1->setErrorHandler(dh);
		reader1->parse(is);
	} catch ($SAXParseException& err) {
		$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("wrsxmlreader.parseerr"_s))))->toString());
		$nc($System::out)->println($($MessageFormat::format(var$0, $$new($ObjectArray, {
			$($of(err->getMessage())),
			$($of($Integer::valueOf(err->getLineNumber()))),
			$($of(err->getSystemId()))
		}))));
		err->printStackTrace();
		$throwNew($SQLException, $(err->getMessage()));
	} catch ($SAXException& e) {
		$var($Exception, x, e);
		if (e->getException() != nullptr) {
			$assign(x, e->getException());
		}
		x->printStackTrace();
		$throwNew($SQLException, $(x->getMessage()));
	} catch ($ArrayIndexOutOfBoundsException& aie) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("wrsxmlreader.invalidcp"_s))))->toString()));
	} catch ($Throwable& e) {
		$var($String, var$1, $nc($of($($nc(this->resBundle)->handleGetObject("wrsxmlreader.readxml"_s))))->toString());
		$throwNew($SQLException, $($MessageFormat::format(var$1, $$new($ObjectArray, {$($of(e->getMessage()))}))));
	}
}

void WebRowSetXmlReader::readXML($WebRowSet* caller, $InputStream* iStream) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($InputSource, is, $new($InputSource, iStream));
		$var($DefaultHandler, dh, $new($XmlErrorHandler));
		$var($XmlReaderContentHandler, hndr, $new($XmlReaderContentHandler, static_cast<$RowSet*>(caller)));
		$var($SAXParserFactory, factory, $SAXParserFactory::newInstance());
		$nc(factory)->setNamespaceAware(true);
		factory->setValidating(true);
		$var($SAXParser, parser, factory->newSAXParser());
		$nc(parser)->setProperty("http://java.sun.com/xml/jaxp/properties/schemaLanguage"_s, "http://www.w3.org/2001/XMLSchema"_s);
		$var($XMLReader, reader1, parser->getXMLReader());
		$nc(reader1)->setEntityResolver($$new($XmlResolver));
		reader1->setContentHandler(hndr);
		reader1->setErrorHandler(dh);
		reader1->parse(is);
	} catch ($SAXParseException& err) {
		$var($String, var$0, $nc($of($($nc(this->resBundle)->handleGetObject("wrsxmlreader.parseerr"_s))))->toString());
		$nc($System::out)->println($($MessageFormat::format(var$0, $$new($ObjectArray, {
			$($of($Integer::valueOf(err->getLineNumber()))),
			$($of(err->getSystemId()))
		}))));
		$nc($System::out)->println($$str({"   "_s, $(err->getMessage())}));
		err->printStackTrace();
		$throwNew($SQLException, $(err->getMessage()));
	} catch ($SAXException& e) {
		$var($Exception, x, e);
		if (e->getException() != nullptr) {
			$assign(x, e->getException());
		}
		x->printStackTrace();
		$throwNew($SQLException, $(x->getMessage()));
	} catch ($ArrayIndexOutOfBoundsException& aie) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("wrsxmlreader.invalidcp"_s))))->toString()));
	} catch ($Throwable& e) {
		$var($String, var$1, $nc($of($($nc(this->resBundle)->handleGetObject("wrsxmlreader.readxml"_s))))->toString());
		$throwNew($SQLException, $($MessageFormat::format(var$1, $$new($ObjectArray, {$($of(e->getMessage()))}))));
	}
}

void WebRowSetXmlReader::readData($RowSetInternal* caller) {
}

void WebRowSetXmlReader::readObject($ObjectInputStream* ois) {
	$nc(ois)->defaultReadObject();
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
}

WebRowSetXmlReader::WebRowSetXmlReader() {
}

$Class* WebRowSetXmlReader::load$($String* name, bool initialize) {
	$loadClass(WebRowSetXmlReader, name, initialize, &_WebRowSetXmlReader_ClassInfo_, allocate$WebRowSetXmlReader);
	return class$;
}

$Class* WebRowSetXmlReader::class$ = nullptr;

			} // internal
		} // rowset
	} // sun
} // com