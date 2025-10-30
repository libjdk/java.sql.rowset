#include <javax/sql/rowset/WebRowSet.h>

#include <java/io/InputStream.h>
#include <java/io/OutputStream.h>
#include <java/io/Reader.h>
#include <java/io/Writer.h>
#include <java/sql/ResultSet.h>
#include <jcpp.h>

#undef PUBLIC_XML_SCHEMA
#undef SCHEMA_SYSTEM_ID

using $InputStream = ::java::io::InputStream;
using $OutputStream = ::java::io::OutputStream;
using $Reader = ::java::io::Reader;
using $Writer = ::java::io::Writer;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ResultSet = ::java::sql::ResultSet;
using $CachedRowSet = ::javax::sql::rowset::CachedRowSet;

namespace javax {
	namespace sql {
		namespace rowset {

$FieldInfo _WebRowSet_FieldInfo_[] = {
	{"PUBLIC_XML_SCHEMA", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(WebRowSet, PUBLIC_XML_SCHEMA)},
	{"SCHEMA_SYSTEM_ID", "Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(WebRowSet, SCHEMA_SYSTEM_ID)},
	{}
};

$MethodInfo _WebRowSet_MethodInfo_[] = {
	{"readXml", "(Ljava/io/Reader;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"readXml", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException,java.io.IOException"},
	{"writeXml", "(Ljava/sql/ResultSet;Ljava/io/Writer;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"writeXml", "(Ljava/sql/ResultSet;Ljava/io/OutputStream;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException,java.io.IOException"},
	{"writeXml", "(Ljava/io/Writer;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{"writeXml", "(Ljava/io/OutputStream;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException,java.io.IOException"},
	{}
};

$ClassInfo _WebRowSet_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"javax.sql.rowset.WebRowSet",
	nullptr,
	"javax.sql.rowset.CachedRowSet",
	_WebRowSet_FieldInfo_,
	_WebRowSet_MethodInfo_
};

$Object* allocate$WebRowSet($Class* clazz) {
	return $of($alloc(WebRowSet));
}

$String* WebRowSet::PUBLIC_XML_SCHEMA = nullptr;
$String* WebRowSet::SCHEMA_SYSTEM_ID = nullptr;

void clinit$WebRowSet($Class* class$) {
	$assignStatic(WebRowSet::PUBLIC_XML_SCHEMA, "--//Oracle Corporation//XSD Schema//EN"_s);
	$assignStatic(WebRowSet::SCHEMA_SYSTEM_ID, "http://java.sun.com/xml/ns/jdbc/webrowset.xsd"_s);
}

$Class* WebRowSet::load$($String* name, bool initialize) {
	$loadClass(WebRowSet, name, initialize, &_WebRowSet_ClassInfo_, clinit$WebRowSet, allocate$WebRowSet);
	return class$;
}

$Class* WebRowSet::class$ = nullptr;

		} // rowset
	} // sql
} // javax