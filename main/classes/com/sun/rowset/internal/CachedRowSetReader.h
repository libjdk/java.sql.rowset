#ifndef _com_sun_rowset_internal_CachedRowSetReader_h_
#define _com_sun_rowset_internal_CachedRowSetReader_h_
//$ class com.sun.rowset.internal.CachedRowSetReader
//$ extends javax.sql.RowSetReader
//$ implements java.io.Serializable

#include <java/io/Serializable.h>
#include <java/lang/Array.h>
#include <javax/sql/RowSetReader.h>

namespace com {
	namespace sun {
		namespace rowset {
			class JdbcRowSetResourceBundle;
		}
	}
}
namespace java {
	namespace io {
		class ObjectInputStream;
	}
}
namespace java {
	namespace sql {
		class Connection;
		class PreparedStatement;
	}
}
namespace javax {
	namespace sql {
		class RowSetInternal;
	}
}

namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {

class CachedRowSetReader : public ::javax::sql::RowSetReader, public ::java::io::Serializable {
	$class(CachedRowSetReader, $NO_CLASS_INIT, ::javax::sql::RowSetReader, ::java::io::Serializable)
public:
	CachedRowSetReader();
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$();
	virtual ::java::sql::Connection* connect(::javax::sql::RowSetInternal* caller);
	void decodeParams($ObjectArray* params, ::java::sql::PreparedStatement* pstmt);
	virtual bool getCloseConnection();
	virtual void readData(::javax::sql::RowSetInternal* caller) override;
	void readObject(::java::io::ObjectInputStream* ois);
	virtual bool reset();
	virtual void setStartPosition(int32_t pos);
	virtual $String* toString() override;
	int32_t writerCalls = 0;
	bool userCon = false;
	int32_t startPosition = 0;
	::com::sun::rowset::JdbcRowSetResourceBundle* resBundle = nullptr;
	static const int64_t serialVersionUID = (int64_t)0x46144620156A7159;
};

			} // internal
		} // rowset
	} // sun
} // com

#endif // _com_sun_rowset_internal_CachedRowSetReader_h_