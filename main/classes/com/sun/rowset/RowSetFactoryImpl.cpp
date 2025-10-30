#include <com/sun/rowset/RowSetFactoryImpl.h>

#include <com/sun/rowset/CachedRowSetImpl.h>
#include <com/sun/rowset/FilteredRowSetImpl.h>
#include <com/sun/rowset/JdbcRowSetImpl.h>
#include <com/sun/rowset/JoinRowSetImpl.h>
#include <com/sun/rowset/WebRowSetImpl.h>
#include <javax/sql/rowset/CachedRowSet.h>
#include <javax/sql/rowset/FilteredRowSet.h>
#include <javax/sql/rowset/JdbcRowSet.h>
#include <javax/sql/rowset/JoinRowSet.h>
#include <javax/sql/rowset/WebRowSet.h>
#include <jcpp.h>

using $CachedRowSetImpl = ::com::sun::rowset::CachedRowSetImpl;
using $FilteredRowSetImpl = ::com::sun::rowset::FilteredRowSetImpl;
using $JdbcRowSetImpl = ::com::sun::rowset::JdbcRowSetImpl;
using $JoinRowSetImpl = ::com::sun::rowset::JoinRowSetImpl;
using $WebRowSetImpl = ::com::sun::rowset::WebRowSetImpl;
using $ClassInfo = ::java::lang::ClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CachedRowSet = ::javax::sql::rowset::CachedRowSet;
using $FilteredRowSet = ::javax::sql::rowset::FilteredRowSet;
using $JdbcRowSet = ::javax::sql::rowset::JdbcRowSet;
using $JoinRowSet = ::javax::sql::rowset::JoinRowSet;
using $RowSetFactory = ::javax::sql::rowset::RowSetFactory;
using $WebRowSet = ::javax::sql::rowset::WebRowSet;

namespace com {
	namespace sun {
		namespace rowset {

$MethodInfo _RowSetFactoryImpl_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RowSetFactoryImpl::*)()>(&RowSetFactoryImpl::init$))},
	{"createCachedRowSet", "()Ljavax/sql/rowset/CachedRowSet;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"createFilteredRowSet", "()Ljavax/sql/rowset/FilteredRowSet;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"createJdbcRowSet", "()Ljavax/sql/rowset/JdbcRowSet;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"createJoinRowSet", "()Ljavax/sql/rowset/JoinRowSet;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"createWebRowSet", "()Ljavax/sql/rowset/WebRowSet;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{}
};

$ClassInfo _RowSetFactoryImpl_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"com.sun.rowset.RowSetFactoryImpl",
	"java.lang.Object",
	"javax.sql.rowset.RowSetFactory",
	nullptr,
	_RowSetFactoryImpl_MethodInfo_
};

$Object* allocate$RowSetFactoryImpl($Class* clazz) {
	return $of($alloc(RowSetFactoryImpl));
}

void RowSetFactoryImpl::init$() {
}

$CachedRowSet* RowSetFactoryImpl::createCachedRowSet() {
	return $new($CachedRowSetImpl);
}

$FilteredRowSet* RowSetFactoryImpl::createFilteredRowSet() {
	return $new($FilteredRowSetImpl);
}

$JdbcRowSet* RowSetFactoryImpl::createJdbcRowSet() {
	return $new($JdbcRowSetImpl);
}

$JoinRowSet* RowSetFactoryImpl::createJoinRowSet() {
	return $new($JoinRowSetImpl);
}

$WebRowSet* RowSetFactoryImpl::createWebRowSet() {
	return $new($WebRowSetImpl);
}

RowSetFactoryImpl::RowSetFactoryImpl() {
}

$Class* RowSetFactoryImpl::load$($String* name, bool initialize) {
	$loadClass(RowSetFactoryImpl, name, initialize, &_RowSetFactoryImpl_ClassInfo_, allocate$RowSetFactoryImpl);
	return class$;
}

$Class* RowSetFactoryImpl::class$ = nullptr;

		} // rowset
	} // sun
} // com