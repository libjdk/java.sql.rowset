#ifndef _javax_sql_rowset_WebRowSet_h_
#define _javax_sql_rowset_WebRowSet_h_
//$ interface javax.sql.rowset.WebRowSet
//$ extends javax.sql.rowset.CachedRowSet

#include <javax/sql/rowset/CachedRowSet.h>

#pragma push_macro("PUBLIC_XML_SCHEMA")
#undef PUBLIC_XML_SCHEMA
#pragma push_macro("SCHEMA_SYSTEM_ID")
#undef SCHEMA_SYSTEM_ID

namespace java {
	namespace io {
		class InputStream;
		class OutputStream;
		class Reader;
		class Writer;
	}
}
namespace java {
	namespace sql {
		class ResultSet;
	}
}

namespace javax {
	namespace sql {
		namespace rowset {

class $export WebRowSet : public ::javax::sql::rowset::CachedRowSet {
	$interface(WebRowSet, 0, ::javax::sql::rowset::CachedRowSet)
public:
	using ::javax::sql::rowset::CachedRowSet::execute;
	virtual void readXml(::java::io::Reader* reader) {}
	virtual void readXml(::java::io::InputStream* iStream) {}
	virtual void writeXml(::java::sql::ResultSet* rs, ::java::io::Writer* writer) {}
	virtual void writeXml(::java::sql::ResultSet* rs, ::java::io::OutputStream* oStream) {}
	virtual void writeXml(::java::io::Writer* writer) {}
	virtual void writeXml(::java::io::OutputStream* oStream) {}
	static $String* PUBLIC_XML_SCHEMA;
	static $String* SCHEMA_SYSTEM_ID;
};

		} // rowset
	} // sql
} // javax

#pragma pop_macro("PUBLIC_XML_SCHEMA")
#pragma pop_macro("SCHEMA_SYSTEM_ID")

#endif // _javax_sql_rowset_WebRowSet_h_