#include <javax/sql/rowset/spi/XmlWriter.h>

#include <java/io/Writer.h>
#include <javax/sql/rowset/WebRowSet.h>
#include <jcpp.h>

using $Writer = ::java::io::Writer;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $RowSetWriter = ::javax::sql::RowSetWriter;
using $WebRowSet = ::javax::sql::rowset::WebRowSet;

namespace javax {
	namespace sql {
		namespace rowset {
			namespace spi {

$MethodInfo _XmlWriter_MethodInfo_[] = {
	{"writeXML", "(Ljavax/sql/rowset/WebRowSet;Ljava/io/Writer;)V", nullptr, $PUBLIC | $ABSTRACT, nullptr, "java.sql.SQLException"},
	{}
};

$ClassInfo _XmlWriter_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"javax.sql.rowset.spi.XmlWriter",
	nullptr,
	"javax.sql.RowSetWriter",
	nullptr,
	_XmlWriter_MethodInfo_
};

$Object* allocate$XmlWriter($Class* clazz) {
	return $of($alloc(XmlWriter));
}

$Class* XmlWriter::load$($String* name, bool initialize) {
	$loadClass(XmlWriter, name, initialize, &_XmlWriter_ClassInfo_, allocate$XmlWriter);
	return class$;
}

$Class* XmlWriter::class$ = nullptr;

			} // spi
		} // rowset
	} // sql
} // javax