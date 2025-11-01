#ifndef _javax_sql_rowset_serial_SerialDatalink_h_
#define _javax_sql_rowset_serial_SerialDatalink_h_
//$ class javax.sql.rowset.serial.SerialDatalink
//$ extends java.io.Serializable
//$ implements java.lang.Cloneable

#include <java/io/Serializable.h>
#include <java/lang/Cloneable.h>

namespace java {
	namespace net {
		class URL;
	}
}

namespace javax {
	namespace sql {
		namespace rowset {
			namespace serial {

class $export SerialDatalink : public ::java::io::Serializable, public ::java::lang::Cloneable {
	$class(SerialDatalink, $NO_CLASS_INIT, ::java::io::Serializable, ::java::lang::Cloneable)
public:
	SerialDatalink();
	virtual void finalize() override;
	void init$(::java::net::URL* url);
	virtual $Object* clone() override;
	virtual bool equals(Object$* obj) override;
	virtual ::java::net::URL* getDatalink();
	virtual int32_t hashCode() override;
	virtual $String* toString() override;
	::java::net::URL* url = nullptr;
	int32_t baseType = 0;
	$String* baseTypeName = nullptr;
	static const int64_t serialVersionUID = (int64_t)0x273B31AFB4DFFABA;
};

			} // serial
		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_serial_SerialDatalink_h_