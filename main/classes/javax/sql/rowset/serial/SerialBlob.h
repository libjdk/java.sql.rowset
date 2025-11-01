#ifndef _javax_sql_rowset_serial_SerialBlob_h_
#define _javax_sql_rowset_serial_SerialBlob_h_
//$ class javax.sql.rowset.serial.SerialBlob
//$ extends java.sql.Blob
//$ implements java.io.Serializable,java.lang.Cloneable

#include <java/io/Serializable.h>
#include <java/lang/Array.h>
#include <java/lang/Cloneable.h>
#include <java/sql/Blob.h>

namespace java {
	namespace io {
		class InputStream;
		class ObjectInputStream;
		class ObjectOutputStream;
		class OutputStream;
	}
}

namespace javax {
	namespace sql {
		namespace rowset {
			namespace serial {

class $export SerialBlob : public ::java::sql::Blob, public ::java::io::Serializable, public ::java::lang::Cloneable {
	$class(SerialBlob, $NO_CLASS_INIT, ::java::sql::Blob, ::java::io::Serializable, ::java::lang::Cloneable)
public:
	SerialBlob();
	virtual void finalize() override;
	void init$($bytes* b);
	void init$(::java::sql::Blob* blob);
	virtual $Object* clone() override;
	virtual bool equals(Object$* obj) override;
	virtual void free() override;
	virtual ::java::io::InputStream* getBinaryStream() override;
	virtual ::java::io::InputStream* getBinaryStream(int64_t pos, int64_t length) override;
	virtual $bytes* getBytes(int64_t pos, int32_t length) override;
	virtual int32_t hashCode() override;
	void isValid();
	virtual int64_t length() override;
	virtual int64_t position($bytes* pattern, int64_t start) override;
	virtual int64_t position(::java::sql::Blob* pattern, int64_t start) override;
	void readObject(::java::io::ObjectInputStream* s);
	virtual ::java::io::OutputStream* setBinaryStream(int64_t pos) override;
	virtual int32_t setBytes(int64_t pos, $bytes* bytes) override;
	virtual int32_t setBytes(int64_t pos, $bytes* bytes, int32_t offset, int32_t length) override;
	virtual $String* toString() override;
	virtual void truncate(int64_t length) override;
	void writeObject(::java::io::ObjectOutputStream* s);
	$bytes* buf = nullptr;
	::java::sql::Blob* blob = nullptr;
	int64_t len = 0;
	int64_t origLen = 0;
	static const int64_t serialVersionUID = (int64_t)0x8EF86B518C1492E7;
};

			} // serial
		} // rowset
	} // sql
} // javax

#endif // _javax_sql_rowset_serial_SerialBlob_h_