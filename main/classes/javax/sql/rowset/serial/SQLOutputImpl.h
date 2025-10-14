#ifndef _javax_sql_rowset_serial_SQLOutputImpl_h_
#define _javax_sql_rowset_serial_SQLOutputImpl_h_
//$ class javax.sql.rowset.serial.SQLOutputImpl
//$ extends java.sql.SQLOutput

#include <java/lang/Array.h>
#include <java/sql/SQLOutput.h>

namespace java {
	namespace io {
		class InputStream;
		class Reader;
	}
}
namespace java {
	namespace math {
		class BigDecimal;
	}
}
namespace java {
	namespace net {
		class URL;
	}
}
namespace java {
	namespace sql {
		class Array;
		class Blob;
		class Clob;
		class Date;
		class NClob;
		class Ref;
		class RowId;
		class SQLData;
		class SQLXML;
		class Struct;
		class Time;
		class Timestamp;
	}
}
namespace java {
	namespace util {
		class Map;
		class Vector;
	}
}

namespace javax {
	namespace sql {
		namespace rowset {
			namespace serial {

class $export SQLOutputImpl : public ::java::sql::SQLOutput {
	$class(SQLOutputImpl, $NO_CLASS_INIT, ::java::sql::SQLOutput)
public:
	SQLOutputImpl();
	void init$(::java::util::Vector* attributes, ::java::util::Map* map);
	virtual void writeArray(::java::sql::Array* x) override;
	virtual void writeAsciiStream(::java::io::InputStream* x) override;
	virtual void writeBigDecimal(::java::math::BigDecimal* x) override;
	virtual void writeBinaryStream(::java::io::InputStream* x) override;
	virtual void writeBlob(::java::sql::Blob* x) override;
	virtual void writeBoolean(bool x) override;
	virtual void writeByte(int8_t x) override;
	virtual void writeBytes($bytes* x) override;
	virtual void writeCharacterStream(::java::io::Reader* x) override;
	virtual void writeClob(::java::sql::Clob* x) override;
	virtual void writeDate(::java::sql::Date* x) override;
	virtual void writeDouble(double x) override;
	virtual void writeFloat(float x) override;
	virtual void writeInt(int32_t x) override;
	virtual void writeLong(int64_t x) override;
	virtual void writeNClob(::java::sql::NClob* x) override;
	virtual void writeNString($String* x) override;
	using ::java::sql::SQLOutput::writeObject;
	virtual void writeObject(::java::sql::SQLData* x) override;
	virtual void writeRef(::java::sql::Ref* x) override;
	virtual void writeRowId(::java::sql::RowId* x) override;
	virtual void writeSQLXML(::java::sql::SQLXML* x) override;
	virtual void writeShort(int16_t x) override;
	virtual void writeString($String* x) override;
	virtual void writeStruct(::java::sql::Struct* x) override;
	virtual void writeTime(::java::sql::Time* x) override;
	virtual void writeTimestamp(::java::sql::Timestamp* x) override;
	virtual void writeURL(::java::net::URL* url) override;
	::java::util::Vector* attribs = nullptr;
	::java::util::Map* map = nullptr;
};

			} // serial
		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_serial_SQLOutputImpl_h_