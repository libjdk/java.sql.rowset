#ifndef _com_sun_rowset_internal_WebRowSetXmlWriter_h_
#define _com_sun_rowset_internal_WebRowSetXmlWriter_h_
//$ class com.sun.rowset.internal.WebRowSetXmlWriter
//$ extends javax.sql.rowset.spi.XmlWriter
//$ implements java.io.Serializable

#include <java/io/Serializable.h>
#include <javax/sql/rowset/spi/XmlWriter.h>

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
		class OutputStream;
		class Writer;
	}
}
namespace java {
	namespace math {
		class BigDecimal;
	}
}
namespace java {
	namespace util {
		class Stack;
	}
}
namespace javax {
	namespace sql {
		class RowSet;
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

class WebRowSetXmlWriter : public ::javax::sql::rowset::spi::XmlWriter, public ::java::io::Serializable {
	$class(WebRowSetXmlWriter, $NO_CLASS_INIT, ::javax::sql::rowset::spi::XmlWriter, ::java::io::Serializable)
public:
	WebRowSetXmlWriter();
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$();
	void beginSection($String* tag);
	void beginTag($String* tag);
	void emptyTag($String* tag);
	void endHeader();
	void endSection($String* tag);
	void endSection();
	void endTag($String* tag);
	$String* getTag();
	$String* processSpecialCharacters($String* s);
	void propBoolean($String* tag, bool b);
	void propInteger($String* tag, int32_t i);
	void propString($String* tag, $String* s);
	void readObject(::java::io::ObjectInputStream* ois);
	void setTag($String* tag);
	void startHeader();
	virtual $String* toString() override;
	void writeBigDecimal(::java::math::BigDecimal* bd);
	void writeBoolean(bool b);
	void writeData(::javax::sql::rowset::WebRowSet* caller);
	virtual bool writeData(::javax::sql::RowSetInternal* caller) override;
	void writeDouble(double d);
	void writeEmptyString();
	void writeFloat(float f);
	void writeIndent(int32_t tabs);
	void writeInteger(int32_t i);
	void writeLong(int64_t l);
	void writeMetaData(::javax::sql::rowset::WebRowSet* caller);
	void writeNull();
	void writeProperties(::javax::sql::rowset::WebRowSet* caller);
	void writeRowSet(::javax::sql::rowset::WebRowSet* caller);
	void writeShort(int16_t s);
	void writeString($String* s);
	void writeStringData($String* s);
	void writeValue(int32_t idx, ::javax::sql::RowSet* caller);
	virtual void writeXML(::javax::sql::rowset::WebRowSet* caller, ::java::io::Writer* wrt) override;
	virtual void writeXML(::javax::sql::rowset::WebRowSet* caller, ::java::io::OutputStream* oStream);
	::java::io::Writer* writer = nullptr;
	::java::util::Stack* stack = nullptr;
	::com::sun::rowset::JdbcRowSetResourceBundle* resBundle = nullptr;
	static const int64_t serialVersionUID = (int64_t)0x636891516A022449;
};

			} // internal
		} // rowset
	} // sun
} // com

#endif // _com_sun_rowset_internal_WebRowSetXmlWriter_h_