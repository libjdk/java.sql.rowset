#ifndef _javax_sql_rowset_serial_SerialJavaObject_h_
#define _javax_sql_rowset_serial_SerialJavaObject_h_
//$ class javax.sql.rowset.serial.SerialJavaObject
//$ extends java.io.Serializable
//$ implements java.lang.Cloneable

#include <java/io/Serializable.h>
#include <java/lang/Array.h>
#include <java/lang/Cloneable.h>

namespace java {
	namespace io {
		class ObjectInputStream;
		class ObjectOutputStream;
	}
}
namespace java {
	namespace lang {
		namespace reflect {
			class Field;
		}
	}
}
namespace java {
	namespace util {
		class Vector;
	}
}
namespace javax {
	namespace sql {
		namespace rowset {
			class RowSetWarning;
		}
	}
}

namespace javax {
	namespace sql {
		namespace rowset {
			namespace serial {

class $import SerialJavaObject : public ::java::io::Serializable, public ::java::lang::Cloneable {
	$class(SerialJavaObject, $NO_CLASS_INIT, ::java::io::Serializable, ::java::lang::Cloneable)
public:
	SerialJavaObject();
	virtual void finalize() override;
	void init$(Object$* obj);
	virtual $Object* clone() override;
	virtual bool equals(Object$* o) override;
	virtual $Array<::java::lang::reflect::Field>* getFields();
	virtual $Object* getObject();
	static bool hasStaticFields($Array<::java::lang::reflect::Field>* fields);
	virtual int32_t hashCode() override;
	void readObject(::java::io::ObjectInputStream* s);
	void setWarning(::javax::sql::rowset::RowSetWarning* e);
	virtual $String* toString() override;
	void writeObject(::java::io::ObjectOutputStream* s);
	$Object* obj = nullptr;
	$Array<::java::lang::reflect::Field>* fields = nullptr;
	static const int64_t serialVersionUID = (int64_t)0xEBA8731650742BD1;
	::java::util::Vector* chain = nullptr;
};

			} // serial
		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_serial_SerialJavaObject_h_