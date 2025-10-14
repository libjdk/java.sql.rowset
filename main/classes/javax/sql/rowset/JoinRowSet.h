#ifndef _javax_sql_rowset_JoinRowSet_h_
#define _javax_sql_rowset_JoinRowSet_h_
//$ interface javax.sql.rowset.JoinRowSet
//$ extends javax.sql.rowset.WebRowSet

#include <java/lang/Array.h>
#include <javax/sql/rowset/WebRowSet.h>

#pragma push_macro("CROSS_JOIN")
#undef CROSS_JOIN
#pragma push_macro("FULL_JOIN")
#undef FULL_JOIN
#pragma push_macro("INNER_JOIN")
#undef INNER_JOIN
#pragma push_macro("LEFT_OUTER_JOIN")
#undef LEFT_OUTER_JOIN
#pragma push_macro("RIGHT_OUTER_JOIN")
#undef RIGHT_OUTER_JOIN

namespace java {
	namespace util {
		class Collection;
	}
}
namespace javax {
	namespace sql {
		class RowSet;
	}
}
namespace javax {
	namespace sql {
		namespace rowset {
			class CachedRowSet;
			class Joinable;
		}
	}
}

namespace javax {
	namespace sql {
		namespace rowset {

class $export JoinRowSet : public ::javax::sql::rowset::WebRowSet {
	$interface(JoinRowSet, $NO_CLASS_INIT, ::javax::sql::rowset::WebRowSet)
public:
	virtual void addRowSet(::javax::sql::rowset::Joinable* rowset) {}
	virtual void addRowSet(::javax::sql::RowSet* rowset, int32_t columnIdx) {}
	virtual void addRowSet(::javax::sql::RowSet* rowset, $String* columnName) {}
	virtual void addRowSet($Array<::javax::sql::RowSet>* rowset, $ints* columnIdx) {}
	virtual void addRowSet($Array<::javax::sql::RowSet>* rowset, $StringArray* columnName) {}
	using ::javax::sql::rowset::WebRowSet::execute;
	virtual int32_t getJoinType() {return 0;}
	virtual $StringArray* getRowSetNames() {return nullptr;}
	virtual ::java::util::Collection* getRowSets() {return nullptr;}
	virtual $String* getWhereClause() {return nullptr;}
	virtual void setJoinType(int32_t joinType) {}
	virtual bool supportsCrossJoin() {return false;}
	virtual bool supportsFullJoin() {return false;}
	virtual bool supportsInnerJoin() {return false;}
	virtual bool supportsLeftOuterJoin() {return false;}
	virtual bool supportsRightOuterJoin() {return false;}
	virtual ::javax::sql::rowset::CachedRowSet* toCachedRowSet() {return nullptr;}
	static const int32_t CROSS_JOIN = 0;
	static const int32_t INNER_JOIN = 1;
	static const int32_t LEFT_OUTER_JOIN = 2;
	static const int32_t RIGHT_OUTER_JOIN = 3;
	static const int32_t FULL_JOIN = 4;
};

		} // rowset
	} // sql
} // javax

#pragma pop_macro("CROSS_JOIN")
#pragma pop_macro("FULL_JOIN")
#pragma pop_macro("INNER_JOIN")
#pragma pop_macro("LEFT_OUTER_JOIN")
#pragma pop_macro("RIGHT_OUTER_JOIN")

#endif // _javax_sql_rowset_JoinRowSet_h_