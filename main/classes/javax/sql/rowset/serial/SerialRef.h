#ifndef _javax_sql_rowset_serial_SerialRef_h_
#define _javax_sql_rowset_serial_SerialRef_h_
//$ class javax.sql.rowset.serial.SerialRef
//$ extends java.sql.Ref
//$ implements java.io.Serializable,java.lang.Cloneable

#include <java/io/Serializable.h>
#include <java/lang/Cloneable.h>
#include <java/sql/Ref.h>

namespace java {
	namespace io {
		class ObjectInputStream;
		class ObjectOutputStream;
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

class $export SerialRef : public ::java::sql::Ref, public ::java::io::Serializable, public ::java::lang::Cloneable {
	$class(SerialRef, $NO_CLASS_INIT, ::java::sql::Ref, ::java::io::Serializable, ::java::lang::Cloneable)
public:
	SerialRef();
	virtual void finalize() override;
	void init$(::java::sql::Ref* ref);
	virtual $Object* clone() override;
	virtual bool equals(Object$* obj) override;
	virtual $String* getBaseTypeName() override;
	virtual $Object* getObject(::java::util::Map* map) override;
	virtual $Object* getObject() override;
	virtual int32_t hashCode() override;
	void readObject(::java::io::ObjectInputStream* s);
	virtual void setObject(Object$* obj) override;
	virtual $String* toString() override;
	void writeObject(::java::io::ObjectOutputStream* s);
	$String* baseTypeName = nullptr;
	$Object* object = nullptr;
	::java::sql::Ref* reference = nullptr;
	static const int64_t serialVersionUID = (int64_t)0xBE65E238B8C292BE;
};

			} // serial
		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_serial_SerialRef_h_