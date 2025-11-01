#ifndef _javax_sql_rowset_serial_SerialArray_h_
#define _javax_sql_rowset_serial_SerialArray_h_
//$ class javax.sql.rowset.serial.SerialArray
//$ extends java.sql.Array
//$ implements java.io.Serializable,java.lang.Cloneable

#include <java/io/Serializable.h>
#include <java/lang/Array.h>
#include <java/lang/Cloneable.h>
#include <java/sql/Array.h>

namespace java {
	namespace io {
		class ObjectInputStream;
		class ObjectOutputStream;
	}
}
namespace java {
	namespace sql {
		class ResultSet;
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

class $export SerialArray : public ::java::sql::Array, public ::java::io::Serializable, public ::java::lang::Cloneable {
	$class(SerialArray, $NO_CLASS_INIT, ::java::sql::Array, ::java::io::Serializable, ::java::lang::Cloneable)
public:
	SerialArray();
	virtual void finalize() override;
	void init$(::java::sql::Array* array, ::java::util::Map* map);
	void init$(::java::sql::Array* array);
	virtual $Object* clone() override;
	virtual bool equals(Object$* obj) override;
	virtual void free() override;
	virtual $Object* getArray() override;
	virtual $Object* getArray(::java::util::Map* map) override;
	virtual $Object* getArray(int64_t index, int32_t count) override;
	virtual $Object* getArray(int64_t index, int32_t count, ::java::util::Map* map) override;
	virtual int32_t getBaseType() override;
	virtual $String* getBaseTypeName() override;
	virtual ::java::sql::ResultSet* getResultSet(int64_t index, int32_t count) override;
	virtual ::java::sql::ResultSet* getResultSet(::java::util::Map* map) override;
	virtual ::java::sql::ResultSet* getResultSet() override;
	virtual ::java::sql::ResultSet* getResultSet(int64_t index, int32_t count, ::java::util::Map* map) override;
	virtual int32_t hashCode() override;
	void isValid();
	void readObject(::java::io::ObjectInputStream* s);
	virtual $String* toString() override;
	void writeObject(::java::io::ObjectOutputStream* s);
	$ObjectArray* elements = nullptr;
	int32_t baseType = 0;
	$String* baseTypeName = nullptr;
	int32_t len = 0;
	static const int64_t serialVersionUID = (int64_t)0x8A821B5514A364F8;
};

			} // serial
		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_serial_SerialArray_h_