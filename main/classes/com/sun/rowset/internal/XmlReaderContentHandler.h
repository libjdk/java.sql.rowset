#ifndef _com_sun_rowset_internal_XmlReaderContentHandler_h_
#define _com_sun_rowset_internal_XmlReaderContentHandler_h_
//$ class com.sun.rowset.internal.XmlReaderContentHandler
//$ extends org.xml.sax.helpers.DefaultHandler

#include <java/lang/Array.h>
#include <org/xml/sax/helpers/DefaultHandler.h>

#pragma push_macro("DATA")
#undef DATA
#pragma push_macro("INITIAL")
#undef INITIAL
#pragma push_macro("METADATA")
#undef METADATA
#pragma push_macro("PROPERTIES")
#undef PROPERTIES

namespace com {
	namespace sun {
		namespace rowset {
			class JdbcRowSetResourceBundle;
			class WebRowSetImpl;
		}
	}
}
namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {
				class Row;
			}
		}
	}
}
namespace java {
	namespace math {
		class BigDecimal;
	}
}
namespace java {
	namespace sql {
		class Date;
		class Time;
		class Timestamp;
	}
}
namespace java {
	namespace util {
		class HashMap;
		class Vector;
	}
}
namespace javax {
	namespace sql {
		class RowSet;
		class RowSetMetaData;
	}
}
namespace org {
	namespace xml {
		namespace sax {
			class Attributes;
			class SAXParseException;
		}
	}
}

namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {

class XmlReaderContentHandler : public ::org::xml::sax::helpers::DefaultHandler {
	$class(XmlReaderContentHandler, $NO_CLASS_INIT, ::org::xml::sax::helpers::DefaultHandler)
public:
	XmlReaderContentHandler();
	void init$(::javax::sql::RowSet* r);
	void applyUpdates();
	virtual void characters($chars* ch, int32_t start, int32_t length) override;
	virtual void endDocument() override;
	virtual void endElement($String* uri, $String* lName, $String* qName) override;
	virtual void error(::org::xml::sax::SAXParseException* e) override;
	::java::math::BigDecimal* getBigDecimalValue($String* s);
	$bytes* getBinaryValue($String* s);
	bool getBooleanValue($String* s);
	int8_t getByteValue($String* s);
	::java::sql::Date* getDateValue($String* s);
	double getDoubleValue($String* s);
	bool getEmptyStringValue();
	float getFloatValue($String* s);
	int32_t getIntegerValue($String* s);
	int64_t getLongValue($String* s);
	bool getNullValue();
	::com::sun::rowset::internal::Row* getPresentRow(::com::sun::rowset::WebRowSetImpl* rs);
	int16_t getShortValue($String* s);
	int32_t getState();
	$String* getStringValue($String* s);
	int32_t getTag();
	::java::sql::Time* getTimeValue($String* s);
	::java::sql::Timestamp* getTimestampValue($String* s);
	void initMaps();
	void insertValue($String* s);
	virtual void notationDecl($String* name, $String* publicId, $String* systemId) override;
	void setDataValue($chars* ch, int32_t start, int32_t len);
	void setEmptyStringValue(bool e);
	void setMetaDataValue($String* s);
	void setNullValue(bool n);
	void setPropertyValue($String* s);
	void setState($String* s);
	void setTag(int32_t t);
	virtual void startDocument() override;
	virtual void startElement($String* uri, $String* lName, $String* qName, ::org::xml::sax::Attributes* attributes) override;
	virtual void unparsedEntityDecl($String* name, $String* publicId, $String* systemId, $String* notationName) override;
	virtual void warning(::org::xml::sax::SAXParseException* err) override;
	::java::util::HashMap* propMap = nullptr;
	::java::util::HashMap* colDefMap = nullptr;
	::java::util::HashMap* dataMap = nullptr;
	::java::util::HashMap* typeMap = nullptr;
	::java::util::Vector* updates = nullptr;
	::java::util::Vector* keyCols = nullptr;
	$String* columnValue = nullptr;
	$String* propertyValue = nullptr;
	$String* metaDataValue = nullptr;
	int32_t tag = 0;
	int32_t state = 0;
	::com::sun::rowset::WebRowSetImpl* rs = nullptr;
	bool nullVal = false;
	bool emptyStringVal = false;
	::javax::sql::RowSetMetaData* md = nullptr;
	int32_t idx = 0;
	$String* lastval = nullptr;
	$String* Key_map = nullptr;
	$String* Value_map = nullptr;
	$String* tempStr = nullptr;
	$String* tempUpdate = nullptr;
	$String* tempCommand = nullptr;
	$ObjectArray* upd = nullptr;
	$StringArray* properties = nullptr;
	static const int32_t CommandTag = 0;
	static const int32_t ConcurrencyTag = 1;
	static const int32_t DatasourceTag = 2;
	static const int32_t EscapeProcessingTag = 3;
	static const int32_t FetchDirectionTag = 4;
	static const int32_t FetchSizeTag = 5;
	static const int32_t IsolationLevelTag = 6;
	static const int32_t KeycolsTag = 7;
	static const int32_t MapTag = 8;
	static const int32_t MaxFieldSizeTag = 9;
	static const int32_t MaxRowsTag = 10;
	static const int32_t QueryTimeoutTag = 11;
	static const int32_t ReadOnlyTag = 12;
	static const int32_t RowsetTypeTag = 13;
	static const int32_t ShowDeletedTag = 14;
	static const int32_t TableNameTag = 15;
	static const int32_t UrlTag = 16;
	static const int32_t PropNullTag = 17;
	static const int32_t PropColumnTag = 18;
	static const int32_t PropTypeTag = 19;
	static const int32_t PropClassTag = 20;
	static const int32_t SyncProviderTag = 21;
	static const int32_t SyncProviderNameTag = 22;
	static const int32_t SyncProviderVendorTag = 23;
	static const int32_t SyncProviderVersionTag = 24;
	static const int32_t SyncProviderGradeTag = 25;
	static const int32_t DataSourceLock = 26;
	$StringArray* colDef = nullptr;
	static const int32_t ColumnCountTag = 0;
	static const int32_t ColumnDefinitionTag = 1;
	static const int32_t ColumnIndexTag = 2;
	static const int32_t AutoIncrementTag = 3;
	static const int32_t CaseSensitiveTag = 4;
	static const int32_t CurrencyTag = 5;
	static const int32_t NullableTag = 6;
	static const int32_t SignedTag = 7;
	static const int32_t SearchableTag = 8;
	static const int32_t ColumnDisplaySizeTag = 9;
	static const int32_t ColumnLabelTag = 10;
	static const int32_t ColumnNameTag = 11;
	static const int32_t SchemaNameTag = 12;
	static const int32_t ColumnPrecisionTag = 13;
	static const int32_t ColumnScaleTag = 14;
	static const int32_t MetaTableNameTag = 15;
	static const int32_t CatalogNameTag = 16;
	static const int32_t ColumnTypeTag = 17;
	static const int32_t ColumnTypeNameTag = 18;
	static const int32_t MetaNullTag = 19;
	$StringArray* data = nullptr;
	static const int32_t RowTag = 0;
	static const int32_t ColTag = 1;
	static const int32_t InsTag = 2;
	static const int32_t DelTag = 3;
	static const int32_t InsDelTag = 4;
	static const int32_t UpdTag = 5;
	static const int32_t NullTag = 6;
	static const int32_t EmptyStringTag = 7;
	static const int32_t INITIAL = 0;
	static const int32_t PROPERTIES = 1;
	static const int32_t METADATA = 2;
	static const int32_t DATA = 3;
	::com::sun::rowset::JdbcRowSetResourceBundle* resBundle = nullptr;
};

			} // internal
		} // rowset
	} // sun
} // com

#pragma pop_macro("DATA")
#pragma pop_macro("INITIAL")
#pragma pop_macro("METADATA")
#pragma pop_macro("PROPERTIES")

#endif // _com_sun_rowset_internal_XmlReaderContentHandler_h_