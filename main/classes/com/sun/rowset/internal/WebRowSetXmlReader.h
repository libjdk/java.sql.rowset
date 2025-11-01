#ifndef _com_sun_rowset_internal_WebRowSetXmlReader_h_
#define _com_sun_rowset_internal_WebRowSetXmlReader_h_
//$ class com.sun.rowset.internal.WebRowSetXmlReader
//$ extends javax.sql.rowset.spi.XmlReader
//$ implements java.io.Serializable

#include <java/io/Serializable.h>
#include <javax/sql/rowset/spi/XmlReader.h>

namespace com {
	namespace sun {
		namespace rowset {
			class JdbcRowSetResourceBundle;
		}
	}
}
namespace java {
	namespace io {
		class InputStream;
		class ObjectInputStream;
		class Reader;
	}
}
namespace javax {
	namespace sql {
		class RowSetInternal;
	}
}
namespace javax {
	namespace sql {
		namespace rowset {
			class WebRowSet;
		}
	}
}

namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {

class WebRowSetXmlReader : public ::javax::sql::rowset::spi::XmlReader, public ::java::io::Serializable {
	$class(WebRowSetXmlReader, $NO_CLASS_INIT, ::javax::sql::rowset::spi::XmlReader, ::java::io::Serializable)
public:
	WebRowSetXmlReader();
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$();
	virtual void readData(::javax::sql::RowSetInternal* caller) override;
	void readObject(::java::io::ObjectInputStream* ois);
	virtual void readXML(::javax::sql::rowset::WebRowSet* caller, ::java::io::Reader* reader) override;
	virtual void readXML(::javax::sql::rowset::WebRowSet* caller, ::java::io::InputStream* iStream);
	virtual $String* toString() override;
	::com::sun::rowset::JdbcRowSetResourceBundle* resBundle = nullptr;
	static const int64_t serialVersionUID = (int64_t)0x81562CBFBBC67DF2;
};

			} // internal
		} // rowset
	} // sun
} // com

#endif // _com_sun_rowset_internal_WebRowSetXmlReader_h_