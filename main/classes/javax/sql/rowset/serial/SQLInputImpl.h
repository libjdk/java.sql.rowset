#ifndef _javax_sql_rowset_serial_SQLInputImpl_h_
#define _javax_sql_rowset_serial_SQLInputImpl_h_
//$ class javax.sql.rowset.serial.SQLInputImpl
//$ extends java.sql.SQLInput

#include <java/lang/Array.h>
#include <java/sql/SQLInput.h>

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
		class SQLXML;
		class Time;
		class Timestamp;
	}
}
namespace java {
	namespace util {
		class Map;
	}
}

namespace javax {
	namespace sql {
		namespace rowset {
			namespace serial {

class $export SQLInputImpl : public ::java::sql::SQLInput {
	$class(SQLInputImpl, $NO_CLASS_INIT, ::java::sql::SQLInput)
public:
	SQLInputImpl();
	void init$($ObjectArray* attributes, ::java::util::Map* map);
	$Object* getNextAttribute();
	virtual ::java::sql::Array* readArray() override;
	virtual ::java::io::InputStream* readAsciiStream() override;
	virtual ::java::math::BigDecimal* readBigDecimal() override;
	virtual ::java::io::InputStream* readBinaryStream() override;
	virtual ::java::sql::Blob* readBlob() override;
	virtual bool readBoolean() override;
	virtual int8_t readByte() override;
	virtual $bytes* readBytes() override;
	virtual ::java::io::Reader* readCharacterStream() override;
	virtual ::java::sql::Clob* readClob() override;
	virtual ::java::sql::Date* readDate() override;
	virtual double readDouble() override;
	virtual float readFloat() override;
	virtual int32_t readInt() override;
	virtual int64_t readLong() override;
	virtual ::java::sql::NClob* readNClob() override;
	virtual $String* readNString() override;
	using ::java::sql::SQLInput::readObject;
	virtual $Object* readObject() override;
	virtual ::java::sql::Ref* readRef() override;
	virtual ::java::sql::RowId* readRowId() override;
	virtual ::java::sql::SQLXML* readSQLXML() override;
	virtual int16_t readShort() override;
	virtual $String* readString() override;
	virtual ::java::sql::Time* readTime() override;
	virtual ::java::sql::Timestamp* readTimestamp() override;
	virtual ::java::net::URL* readURL() override;
	virtual bool wasNull() override;
	bool lastValueWasNull = false;
	int32_t idx = 0;
	$ObjectArray* attrib = nullptr;
	::java::util::Map* map = nullptr;
};

			} // serial
		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_serial_SQLInputImpl_h_