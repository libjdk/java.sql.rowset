#ifndef _javax_sql_rowset_serial_SerialClob_h_
#define _javax_sql_rowset_serial_SerialClob_h_
//$ class javax.sql.rowset.serial.SerialClob
//$ extends java.sql.Clob
//$ implements java.io.Serializable,java.lang.Cloneable

#include <java/io/Serializable.h>
#include <java/lang/Array.h>
#include <java/lang/Cloneable.h>
#include <java/sql/Clob.h>

namespace java {
	namespace io {
		class InputStream;
		class ObjectInputStream;
		class ObjectOutputStream;
		class OutputStream;
		class Reader;
		class Writer;
	}
}

namespace javax {
	namespace sql {
		namespace rowset {
			namespace serial {

class $import SerialClob : public ::java::sql::Clob, public ::java::io::Serializable, public ::java::lang::Cloneable {
	$class(SerialClob, $NO_CLASS_INIT, ::java::sql::Clob, ::java::io::Serializable, ::java::lang::Cloneable)
public:
	SerialClob();
	virtual void finalize() override;
	void init$($chars* ch);
	void init$(::java::sql::Clob* clob);
	virtual $Object* clone() override;
	virtual bool equals(Object$* obj) override;
	virtual void free() override;
	virtual ::java::io::InputStream* getAsciiStream() override;
	virtual ::java::io::Reader* getCharacterStream() override;
	virtual ::java::io::Reader* getCharacterStream(int64_t pos, int64_t length) override;
	virtual $String* getSubString(int64_t pos, int32_t length) override;
	virtual int32_t hashCode() override;
	void isValid();
	virtual int64_t length() override;
	virtual int64_t position($String* searchStr, int64_t start) override;
	virtual int64_t position(::java::sql::Clob* searchStr, int64_t start) override;
	void readObject(::java::io::ObjectInputStream* s);
	virtual ::java::io::OutputStream* setAsciiStream(int64_t pos) override;
	virtual ::java::io::Writer* setCharacterStream(int64_t pos) override;
	virtual int32_t setString(int64_t pos, $String* str) override;
	virtual int32_t setString(int64_t pos, $String* str, int32_t offset, int32_t length) override;
	virtual $String* toString() override;
	virtual void truncate(int64_t length) override;
	void writeObject(::java::io::ObjectOutputStream* s);
	$chars* buf = nullptr;
	::java::sql::Clob* clob = nullptr;
	int64_t len = 0;
	int64_t origLen = 0;
	static const int64_t serialVersionUID = (int64_t)0xE8ED8B26783FDE2F;
};

			} // serial
		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_serial_SerialClob_h_