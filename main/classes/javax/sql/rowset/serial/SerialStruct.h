#ifndef _javax_sql_rowset_serial_SerialStruct_h_
#define _javax_sql_rowset_serial_SerialStruct_h_
//$ class javax.sql.rowset.serial.SerialStruct
//$ extends java.sql.Struct
//$ implements java.io.Serializable,java.lang.Cloneable

#include <java/io/Serializable.h>
#include <java/lang/Array.h>
#include <java/lang/Cloneable.h>
#include <java/sql/Struct.h>

namespace java {
	namespace io {
		class ObjectInputStream;
		class ObjectOutputStream;
	}
}
namespace java {
	namespace sql {
		class SQLData;
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

class $export SerialStruct : public ::java::sql::Struct, public ::java::io::Serializable, public ::java::lang::Cloneable {
	$class(SerialStruct, $NO_CLASS_INIT, ::java::sql::Struct, ::java::io::Serializable, ::java::lang::Cloneable)
public:
	SerialStruct();
	virtual void finalize() override;
	void init$(::java::sql::Struct* in, ::java::util::Map* map);
	void init$(::java::sql::SQLData* in, ::java::util::Map* map);
	virtual $Object* clone() override;
	virtual bool equals(Object$* obj) override;
	virtual $ObjectArray* getAttributes() override;
	virtual $ObjectArray* getAttributes(::java::util::Map* map) override;
	virtual $String* getSQLTypeName() override;
	virtual int32_t hashCode() override;
	void mapToSerial(::java::util::Map* map);
	void readObject(::java::io::ObjectInputStream* s);
	virtual $String* toString() override;
	void writeObject(::java::io::ObjectOutputStream* s);
	$String* SQLTypeName = nullptr;
	$ObjectArray* attribs = nullptr;
	static const int64_t serialVersionUID = (int64_t)0x8C80BBE885E52314;
};

			} // serial
		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_serial_SerialStruct_h_