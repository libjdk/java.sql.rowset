#ifndef _javax_sql_rowset_serial_SerialException_h_
#define _javax_sql_rowset_serial_SerialException_h_
//$ class javax.sql.rowset.serial.SerialException
//$ extends java.sql.SQLException

#include <java/sql/SQLException.h>

namespace javax {
	namespace sql {
		namespace rowset {
			namespace serial {

class $export SerialException : public ::java::sql::SQLException {
	$class(SerialException, $NO_CLASS_INIT, ::java::sql::SQLException)
public:
	SerialException();
	void init$();
	void init$($String* msg);
	static const int64_t serialVersionUID = (int64_t)0xF933E670223588CE;
	SerialException(const SerialException& e);
	virtual void throw$() override;
	inline SerialException* operator ->() {
		return (SerialException*)throwing$;
	}
};

			} // serial
		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_serial_SerialException_h_