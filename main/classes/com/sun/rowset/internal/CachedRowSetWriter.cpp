#include <com/sun/rowset/internal/CachedRowSetWriter.h>

#include <com/sun/rowset/CachedRowSetImpl.h>
#include <com/sun/rowset/JdbcRowSetResourceBundle.h>
#include <com/sun/rowset/internal/CachedRowSetReader.h>
#include <com/sun/rowset/internal/SyncResolverImpl.h>
#include <java/io/IOException.h>
#include <java/io/ObjectInputStream.h>
#include <java/sql/Array.h>
#include <java/sql/Blob.h>
#include <java/sql/Clob.h>
#include <java/sql/Connection.h>
#include <java/sql/DatabaseMetaData.h>
#include <java/sql/PreparedStatement.h>
#include <java/sql/ResultSet.h>
#include <java/sql/ResultSetMetaData.h>
#include <java/sql/SQLData.h>
#include <java/sql/SQLException.h>
#include <java/sql/SQLInput.h>
#include <java/sql/Savepoint.h>
#include <java/sql/Struct.h>
#include <java/sql/Types.h>
#include <java/util/ArrayList.h>
#include <java/util/Map.h>
#include <java/util/Vector.h>
#include <javax/sql/RowSet.h>
#include <javax/sql/RowSetInternal.h>
#include <javax/sql/RowSetMetaData.h>
#include <javax/sql/rowset/CachedRowSet.h>
#include <javax/sql/rowset/RowSetMetaDataImpl.h>
#include <javax/sql/rowset/serial/SQLInputImpl.h>
#include <javax/sql/rowset/serial/SerialArray.h>
#include <javax/sql/rowset/serial/SerialBlob.h>
#include <javax/sql/rowset/serial/SerialClob.h>
#include <javax/sql/rowset/serial/SerialStruct.h>
#include <javax/sql/rowset/spi/SyncProviderException.h>
#include <javax/sql/rowset/spi/SyncResolver.h>
#include <javax/sql/rowset/spi/TransactionalWriter.h>
#include <sun/reflect/misc/ReflectUtil.h>
#include <jcpp.h>

#undef ARRAY
#undef BLOB
#undef CLOB
#undef CONCUR_READ_ONLY
#undef DELETE_ROW_CONFLICT
#undef INSERT_ROW_CONFLICT
#undef NO_ROW_CONFLICT
#undef OTHER
#undef SQLXML
#undef STRUCT
#undef TYPE_SCROLL_SENSITIVE
#undef UPDATE_ROW_CONFLICT

using $CachedRowSetImpl = ::com::sun::rowset::CachedRowSetImpl;
using $JdbcRowSetResourceBundle = ::com::sun::rowset::JdbcRowSetResourceBundle;
using $CachedRowSetReader = ::com::sun::rowset::internal::CachedRowSetReader;
using $SyncResolverImpl = ::com::sun::rowset::internal::SyncResolverImpl;
using $IOException = ::java::io::IOException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $1Array = ::java::sql::Array;
using $Blob = ::java::sql::Blob;
using $Clob = ::java::sql::Clob;
using $Connection = ::java::sql::Connection;
using $DatabaseMetaData = ::java::sql::DatabaseMetaData;
using $PreparedStatement = ::java::sql::PreparedStatement;
using $ResultSet = ::java::sql::ResultSet;
using $ResultSetMetaData = ::java::sql::ResultSetMetaData;
using $SQLData = ::java::sql::SQLData;
using $SQLException = ::java::sql::SQLException;
using $SQLInput = ::java::sql::SQLInput;
using $Savepoint = ::java::sql::Savepoint;
using $Statement = ::java::sql::Statement;
using $Struct = ::java::sql::Struct;
using $Types = ::java::sql::Types;
using $ArrayList = ::java::util::ArrayList;
using $Map = ::java::util::Map;
using $Vector = ::java::util::Vector;
using $RowSet = ::javax::sql::RowSet;
using $RowSetInternal = ::javax::sql::RowSetInternal;
using $RowSetMetaData = ::javax::sql::RowSetMetaData;
using $BaseRowSet = ::javax::sql::rowset::BaseRowSet;
using $CachedRowSet = ::javax::sql::rowset::CachedRowSet;
using $RowSetMetaDataImpl = ::javax::sql::rowset::RowSetMetaDataImpl;
using $SQLInputImpl = ::javax::sql::rowset::serial::SQLInputImpl;
using $SerialArray = ::javax::sql::rowset::serial::SerialArray;
using $SerialBlob = ::javax::sql::rowset::serial::SerialBlob;
using $SerialClob = ::javax::sql::rowset::serial::SerialClob;
using $SerialStruct = ::javax::sql::rowset::serial::SerialStruct;
using $SyncProviderException = ::javax::sql::rowset::spi::SyncProviderException;
using $SyncResolver = ::javax::sql::rowset::spi::SyncResolver;
using $TransactionalWriter = ::javax::sql::rowset::spi::TransactionalWriter;
using $ReflectUtil = ::sun::reflect::misc::ReflectUtil;

namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {

$FieldInfo _CachedRowSetWriter_FieldInfo_[] = {
	{"con", "Ljava/sql/Connection;", nullptr, $PRIVATE | $TRANSIENT, $field(CachedRowSetWriter, con)},
	{"selectCmd", "Ljava/lang/String;", nullptr, $PRIVATE, $field(CachedRowSetWriter, selectCmd)},
	{"updateCmd", "Ljava/lang/String;", nullptr, $PRIVATE, $field(CachedRowSetWriter, updateCmd)},
	{"updateWhere", "Ljava/lang/String;", nullptr, $PRIVATE, $field(CachedRowSetWriter, updateWhere)},
	{"deleteCmd", "Ljava/lang/String;", nullptr, $PRIVATE, $field(CachedRowSetWriter, deleteCmd)},
	{"deleteWhere", "Ljava/lang/String;", nullptr, $PRIVATE, $field(CachedRowSetWriter, deleteWhere)},
	{"insertCmd", "Ljava/lang/String;", nullptr, $PRIVATE, $field(CachedRowSetWriter, insertCmd)},
	{"keyCols", "[I", nullptr, $PRIVATE, $field(CachedRowSetWriter, keyCols)},
	{"params", "[Ljava/lang/Object;", nullptr, $PRIVATE, $field(CachedRowSetWriter, params)},
	{"reader", "Lcom/sun/rowset/internal/CachedRowSetReader;", nullptr, $PRIVATE, $field(CachedRowSetWriter, reader)},
	{"callerMd", "Ljava/sql/ResultSetMetaData;", nullptr, $PRIVATE, $field(CachedRowSetWriter, callerMd)},
	{"callerColumnCount", "I", nullptr, $PRIVATE, $field(CachedRowSetWriter, callerColumnCount)},
	{"crsResolve", "Lcom/sun/rowset/CachedRowSetImpl;", nullptr, $PRIVATE, $field(CachedRowSetWriter, crsResolve)},
	{"status", "Ljava/util/ArrayList;", "Ljava/util/ArrayList<Ljava/lang/Integer;>;", $PRIVATE, $field(CachedRowSetWriter, status)},
	{"iChangedValsInDbAndCRS", "I", nullptr, $PRIVATE, $field(CachedRowSetWriter, iChangedValsInDbAndCRS)},
	{"iChangedValsinDbOnly", "I", nullptr, $PRIVATE, $field(CachedRowSetWriter, iChangedValsinDbOnly)},
	{"resBundle", "Lcom/sun/rowset/JdbcRowSetResourceBundle;", nullptr, $PRIVATE, $field(CachedRowSetWriter, resBundle)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(CachedRowSetWriter, serialVersionUID)},
	{}
};

$MethodInfo _CachedRowSetWriter_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(CachedRowSetWriter::*)()>(&CachedRowSetWriter::init$))},
	{"buildKeyDesc", "(Ljavax/sql/rowset/CachedRowSet;)V", nullptr, $PRIVATE, $method(static_cast<void(CachedRowSetWriter::*)($CachedRowSet*)>(&CachedRowSetWriter::buildKeyDesc)), "java.sql.SQLException"},
	{"buildTableName", "(Ljava/sql/DatabaseMetaData;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(CachedRowSetWriter::*)($DatabaseMetaData*,$String*,$String*,$String*)>(&CachedRowSetWriter::buildTableName)), "java.sql.SQLException"},
	{"buildWhereClause", "(Ljava/lang/String;Ljava/sql/ResultSet;)Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(CachedRowSetWriter::*)($String*,$ResultSet*)>(&CachedRowSetWriter::buildWhereClause)), "java.sql.SQLException"},
	{"commit", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"commit", "(Lcom/sun/rowset/CachedRowSetImpl;Z)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"deleteOriginalRow", "(Ljavax/sql/rowset/CachedRowSet;Lcom/sun/rowset/CachedRowSetImpl;)Z", nullptr, $PRIVATE, $method(static_cast<bool(CachedRowSetWriter::*)($CachedRowSet*,$CachedRowSetImpl*)>(&CachedRowSetWriter::deleteOriginalRow)), "java.sql.SQLException"},
	{"getReader", "()Lcom/sun/rowset/internal/CachedRowSetReader;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"initSQLStatements", "(Ljavax/sql/rowset/CachedRowSet;)V", nullptr, $PRIVATE, $method(static_cast<void(CachedRowSetWriter::*)($CachedRowSet*)>(&CachedRowSetWriter::initSQLStatements)), "java.sql.SQLException"},
	{"insertNewRow", "(Ljavax/sql/rowset/CachedRowSet;Ljava/sql/PreparedStatement;Lcom/sun/rowset/CachedRowSetImpl;)Z", nullptr, $PRIVATE, $method(static_cast<bool(CachedRowSetWriter::*)($CachedRowSet*,$PreparedStatement*,$CachedRowSetImpl*)>(&CachedRowSetWriter::insertNewRow)), "java.sql.SQLException"},
	{"isPKNameValid", "(Ljava/lang/String;Ljava/sql/ResultSetMetaData;)Z", nullptr, $PRIVATE, $method(static_cast<bool(CachedRowSetWriter::*)($String*,$ResultSetMetaData*)>(&CachedRowSetWriter::isPKNameValid)), "java.sql.SQLException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(CachedRowSetWriter::*)($ObjectInputStream*)>(&CachedRowSetWriter::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"rollback", "()V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"rollback", "(Ljava/sql/Savepoint;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setReader", "(Lcom/sun/rowset/internal/CachedRowSetReader;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"updateOriginalRow", "(Ljavax/sql/rowset/CachedRowSet;)Z", nullptr, $PRIVATE, $method(static_cast<bool(CachedRowSetWriter::*)($CachedRowSet*)>(&CachedRowSetWriter::updateOriginalRow)), "java.sql.SQLException"},
	{"updateResolvedConflictToDB", "(Ljavax/sql/rowset/CachedRowSet;Ljava/sql/Connection;)V", nullptr, 0, nullptr, "java.sql.SQLException"},
	{"writeData", "(Ljavax/sql/RowSetInternal;)Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{}
};

$ClassInfo _CachedRowSetWriter_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"com.sun.rowset.internal.CachedRowSetWriter",
	"java.lang.Object",
	"javax.sql.rowset.spi.TransactionalWriter,java.io.Serializable",
	_CachedRowSetWriter_FieldInfo_,
	_CachedRowSetWriter_MethodInfo_
};

$Object* allocate$CachedRowSetWriter($Class* clazz) {
	return $of($alloc(CachedRowSetWriter));
}

int32_t CachedRowSetWriter::hashCode() {
	 return this->$TransactionalWriter::hashCode();
}

bool CachedRowSetWriter::equals(Object$* arg0) {
	 return this->$TransactionalWriter::equals(arg0);
}

$Object* CachedRowSetWriter::clone() {
	 return this->$TransactionalWriter::clone();
}

$String* CachedRowSetWriter::toString() {
	 return this->$TransactionalWriter::toString();
}

void CachedRowSetWriter::finalize() {
	this->$TransactionalWriter::finalize();
}

void CachedRowSetWriter::init$() {
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
}

bool CachedRowSetWriter::writeData($RowSetInternal* caller) {
	$useLocalCurrentObjectStackCache();
	int64_t conflicts = 0;
	bool showDel = false;
	$var($PreparedStatement, pstmtIns, nullptr);
	this->iChangedValsInDbAndCRS = 0;
	this->iChangedValsinDbOnly = 0;
	$var($CachedRowSetImpl, crs, $cast($CachedRowSetImpl, caller));
	$set(this, crsResolve, $new($CachedRowSetImpl));
	$set(this, con, $nc(this->reader)->connect(caller));
	if (this->con == nullptr) {
		$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("crswriter.connect"_s))))->toString()));
	}
	initSQLStatements(crs);
	int32_t iColCount = 0;
	$var($RowSetMetaDataImpl, rsmdWrite, $cast($RowSetMetaDataImpl, $nc(crs)->getMetaData()));
	$var($RowSetMetaDataImpl, rsmdResolv, $new($RowSetMetaDataImpl));
	iColCount = $nc(rsmdWrite)->getColumnCount();
	int32_t sz = crs->size() + 1;
	$set(this, status, $new($ArrayList, sz));
	$nc(this->status)->add(0, nullptr);
	rsmdResolv->setColumnCount(iColCount);
	for (int32_t i = 1; i <= iColCount; ++i) {
		rsmdResolv->setColumnType(i, rsmdWrite->getColumnType(i));
		rsmdResolv->setColumnName(i, $(rsmdWrite->getColumnName(i)));
		rsmdResolv->setNullable(i, $ResultSetMetaData::columnNullableUnknown);
	}
	$nc(this->crsResolve)->setMetaData(rsmdResolv);
	if (this->callerColumnCount < 1) {
		if ($nc(this->reader)->getCloseConnection() == true) {
			$nc(this->con)->close();
		}
		return true;
	}
	showDel = crs->getShowDeleted();
	crs->setShowDeleted(true);
	crs->beforeFirst();
	int32_t rows = 1;
	while (crs->next()) {
		if (crs->rowDeleted()) {
			if (deleteOriginalRow(crs, this->crsResolve)) {
				$nc(this->status)->add(rows, $($Integer::valueOf($SyncResolver::DELETE_ROW_CONFLICT)));
				++conflicts;
			} else {
				$nc(this->status)->add(rows, $($Integer::valueOf($SyncResolver::NO_ROW_CONFLICT)));
			}
		} else if (crs->rowInserted()) {
			$assign(pstmtIns, $nc(this->con)->prepareStatement(this->insertCmd));
			if (insertNewRow(crs, pstmtIns, this->crsResolve)) {
				$nc(this->status)->add(rows, $($Integer::valueOf($SyncResolver::INSERT_ROW_CONFLICT)));
				++conflicts;
			} else {
				$nc(this->status)->add(rows, $($Integer::valueOf($SyncResolver::NO_ROW_CONFLICT)));
			}
		} else if (crs->rowUpdated()) {
			if (updateOriginalRow(crs)) {
				$nc(this->status)->add(rows, $($Integer::valueOf($SyncResolver::UPDATE_ROW_CONFLICT)));
				++conflicts;
			} else {
				$nc(this->status)->add(rows, $($Integer::valueOf($SyncResolver::NO_ROW_CONFLICT)));
			}
		} else {
			int32_t icolCount = $nc($(crs->getMetaData()))->getColumnCount();
			$nc(this->status)->add(rows, $($Integer::valueOf($SyncResolver::NO_ROW_CONFLICT)));
			$nc(this->crsResolve)->moveToInsertRow();
			for (int32_t cols = 0; cols < iColCount; ++cols) {
				$nc(this->crsResolve)->updateNull(cols + 1);
			}
			$nc(this->crsResolve)->insertRow();
			$nc(this->crsResolve)->moveToCurrentRow();
		}
		++rows;
	}
	if (pstmtIns != nullptr) {
		pstmtIns->close();
	}
	crs->setShowDeleted(showDel);
	crs->beforeFirst();
	$nc(this->crsResolve)->beforeFirst();
	if (conflicts != 0) {
		$var($SyncProviderException, spe, $new($SyncProviderException, $$str({$$str(conflicts), " "_s, $($nc($of($($nc(this->resBundle)->handleGetObject("crswriter.conflictsno"_s))))->toString())})));
		$var($SyncResolverImpl, syncResImpl, $cast($SyncResolverImpl, spe->getSyncResolver()));
		$nc(syncResImpl)->setCachedRowSet(crs);
		syncResImpl->setCachedRowSetResolver(this->crsResolve);
		syncResImpl->setStatus(this->status);
		syncResImpl->setCachedRowSetWriter(this);
		$throw(spe);
	} else {
		return true;
	}
}

bool CachedRowSetWriter::updateOriginalRow($CachedRowSet* crs) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($PreparedStatement, pstmt, nullptr);
	int32_t i = 0;
	int32_t idx = 0;
	$var($ResultSet, origVals, $nc(crs)->getOriginalRow());
	$nc(origVals)->next();
	try {
		$set(this, updateWhere, buildWhereClause(this->updateWhere, origVals));
		$var($String, tempselectCmd, $nc(this->selectCmd)->toLowerCase());
		int32_t idxWhere = tempselectCmd->indexOf("where"_s);
		if (idxWhere != -1) {
			$var($String, tempSelect, $nc(this->selectCmd)->substring(0, idxWhere));
			$set(this, selectCmd, tempSelect);
		}
		$assign(pstmt, $nc(this->con)->prepareStatement($$str({this->selectCmd, this->updateWhere}), $ResultSet::TYPE_SCROLL_SENSITIVE, $ResultSet::CONCUR_READ_ONLY));
		for (i = 0; i < $nc(this->keyCols)->length; ++i) {
			if ($nc(this->params)->get(i) != nullptr) {
				$nc(pstmt)->setObject(++idx, $nc(this->params)->get(i));
			} else {
				continue;
			}
		}
		try {
			$nc(pstmt)->setMaxRows(crs->getMaxRows());
			pstmt->setMaxFieldSize(crs->getMaxFieldSize());
			pstmt->setEscapeProcessing(crs->getEscapeProcessing());
			pstmt->setQueryTimeout(crs->getQueryTimeout());
		} catch ($Exception& ex) {
		}
		$var($ResultSet, rs, nullptr);
		$assign(rs, $nc(pstmt)->executeQuery());
		$var($ResultSetMetaData, rsmd, $nc(rs)->getMetaData());
		if (rs->next()) {
			if (rs->next()) {
				return true;
			}
			rs->first();
			int32_t colsNotChanged = 0;
			$var($Vector, cols, $new($Vector));
			$var($String, updateExec, this->updateCmd);
			$var($Object, orig, nullptr);
			$var($Object, curr, nullptr);
			$var($Object, rsval, nullptr);
			bool boolNull = true;
			$var($Object, objVal, nullptr);
			bool first = true;
			bool flag = true;
			$nc(this->crsResolve)->moveToInsertRow();
			for (i = 1; i <= this->callerColumnCount; ++i) {
				$assign(orig, origVals->getObject(i));
				$assign(curr, crs->getObject(i));
				$assign(rsval, rs->getObject(i));
				$var($Map, map, (crs->getTypeMap() == nullptr) ? $nc(this->con)->getTypeMap() : crs->getTypeMap());
				if ($instanceOf($Struct, rsval)) {
					$var($Struct, s, $cast($Struct, rsval));
					$Class* c = nullptr;
					c = $cast($Class, $nc(map)->get($($nc(s)->getSQLTypeName())));
					if (c != nullptr) {
						$var($SQLData, obj, nullptr);
						try {
							$ReflectUtil::checkPackageAccess(c);
							$var($Object, tmp, c->newInstance());
							$assign(obj, $cast($SQLData, tmp));
						} catch ($Exception& ex) {
							$throwNew($SQLException, "Unable to Instantiate: "_s, static_cast<$Throwable*>(ex));
						}
						$var($ObjectArray, attribs, $nc(s)->getAttributes(map));
						$var($SQLInputImpl, sqlInput, $new($SQLInputImpl, attribs, map));
						$nc(obj)->readSQL(sqlInput, $(s->getSQLTypeName()));
						$assign(rsval, obj);
					}
				} else if ($instanceOf($SQLData, rsval)) {
					$assign(rsval, $new($SerialStruct, $cast($SQLData, rsval), map));
				} else if ($instanceOf($Blob, rsval)) {
					$assign(rsval, $new($SerialBlob, $cast($Blob, rsval)));
				} else if ($instanceOf($Clob, rsval)) {
					$assign(rsval, $new($SerialClob, $cast($Clob, rsval)));
				} else if ($instanceOf($1Array, rsval)) {
					$assign(rsval, $new($SerialArray, $cast($1Array, rsval), map));
				}
				boolNull = true;
				if (rsval == nullptr && orig != nullptr) {
					++this->iChangedValsinDbOnly;
					boolNull = false;
					$assign(objVal, rsval);
				} else if (rsval != nullptr && (!$of(rsval)->equals(orig))) {
					++this->iChangedValsinDbOnly;
					boolNull = false;
					$assign(objVal, rsval);
				} else if (orig == nullptr || curr == nullptr) {
					if (first == false || flag == false) {
						$plusAssign(updateExec, ", "_s);
					}
					$plusAssign(updateExec, $($nc($(crs->getMetaData()))->getColumnName(i)));
					cols->add($($Integer::valueOf(i)));
					$plusAssign(updateExec, " = ? "_s);
					first = false;
				} else if ($of(orig)->equals(curr)) {
					++colsNotChanged;
				} else if ($of(orig)->equals(curr) == false) {
					if (crs->columnUpdated(i)) {
						if ($of(rsval)->equals(orig)) {
							if (flag == false || first == false) {
								$plusAssign(updateExec, ", "_s);
							}
							$plusAssign(updateExec, $($nc($(crs->getMetaData()))->getColumnName(i)));
							cols->add($($Integer::valueOf(i)));
							$plusAssign(updateExec, " = ? "_s);
							flag = false;
						} else {
							boolNull = false;
							$assign(objVal, rsval);
							++this->iChangedValsInDbAndCRS;
						}
					}
				}
				if (!boolNull) {
					$nc(this->crsResolve)->updateObject(i, objVal);
				} else {
					$nc(this->crsResolve)->updateNull(i);
				}
			}
			rs->close();
			pstmt->close();
			$nc(this->crsResolve)->insertRow();
			$nc(this->crsResolve)->moveToCurrentRow();
			if ((first == false && cols->size() == 0) || colsNotChanged == this->callerColumnCount) {
				return false;
			}
			if (this->iChangedValsInDbAndCRS != 0 || this->iChangedValsinDbOnly != 0) {
				return true;
			}
			$plusAssign(updateExec, this->updateWhere);
			$assign(pstmt, $nc(this->con)->prepareStatement(updateExec));
			for (i = 0; i < cols->size(); ++i) {
				$var($Object, obj, crs->getObject($nc(($cast($Integer, $(cols->get(i)))))->intValue()));
				if (obj != nullptr) {
					$nc(pstmt)->setObject(i + 1, obj);
				} else {
					$nc(pstmt)->setNull(i + 1, $nc($(crs->getMetaData()))->getColumnType(i + 1));
				}
			}
			idx = i;
			for (i = 0; i < $nc(this->keyCols)->length; ++i) {
				if ($nc(this->params)->get(i) != nullptr) {
					$nc(pstmt)->setObject(++idx, $nc(this->params)->get(i));
				} else {
					continue;
				}
			}
			i = $nc(pstmt)->executeUpdate();
			return false;
		} else {
			return true;
		}
	} catch ($SQLException& ex) {
		ex->printStackTrace();
		$nc(this->crsResolve)->moveToInsertRow();
		for (i = 1; i <= this->callerColumnCount; ++i) {
			$nc(this->crsResolve)->updateNull(i);
		}
		$nc(this->crsResolve)->insertRow();
		$nc(this->crsResolve)->moveToCurrentRow();
		return true;
	}
	$shouldNotReachHere();
}

bool CachedRowSetWriter::insertNewRow($CachedRowSet* crs, $PreparedStatement* pstmt, $CachedRowSetImpl* crsRes) {
	$useLocalCurrentObjectStackCache();
	bool returnVal = false;
	{
		$var($PreparedStatement, pstmtSel, $nc(this->con)->prepareStatement(this->selectCmd, $ResultSet::TYPE_SCROLL_SENSITIVE, $ResultSet::CONCUR_READ_ONLY));
		{
			$var($Throwable, var$0, nullptr);
			bool var$2 = false;
			bool return$1 = false;
			try {
				try {
					$var($ResultSet, rs, $nc(pstmtSel)->executeQuery());
					{
						$var($Throwable, var$3, nullptr);
						bool var$5 = false;
						bool return$4 = false;
						try {
							try {
								$var($ResultSet, rs2, $nc($($nc(this->con)->getMetaData()))->getPrimaryKeys(nullptr, nullptr, $($nc(crs)->getTableName())));
								{
									$var($Throwable, var$6, nullptr);
									bool var$8 = false;
									bool return$7 = false;
									try {
										try {
											$var($ResultSetMetaData, rsmd, $nc(crs)->getMetaData());
											int32_t icolCount = $nc(rsmd)->getColumnCount();
											$var($StringArray, primaryKeys, $new($StringArray, icolCount));
											int32_t k = 0;
											while ($nc(rs2)->next()) {
												primaryKeys->set(k, $(rs2->getString("COLUMN_NAME"_s)));
												++k;
											}
											if ($nc(rs)->next()) {
												{
													$var($StringArray, arr$, primaryKeys);
													int32_t len$ = arr$->length;
													int32_t i$ = 0;
													for (; i$ < len$; ++i$) {
														$var($String, pkName, arr$->get(i$));
														{
															if (!isPKNameValid(pkName, rsmd)) {
																continue;
															}
															$var($Object, crsPK, crs->getObject(pkName));
															if (crsPK == nullptr) {
																break;
															}
															$var($String, rsPK, $nc($of($(rs->getObject(pkName))))->toString());
															if ($nc($($nc($of(crsPK))->toString()))->equals(rsPK)) {
																returnVal = true;
																$nc(this->crsResolve)->moveToInsertRow();
																for (int32_t i = 1; i <= icolCount; ++i) {
																	$var($String, colname, $nc(($(rs->getMetaData())))->getColumnName(i));
																	if ($nc(colname)->equals(pkName)) {
																		$nc(this->crsResolve)->updateObject(i, $of(rsPK));
																	} else {
																		$nc(this->crsResolve)->updateNull(i);
																	}
																}
																$nc(this->crsResolve)->insertRow();
																$nc(this->crsResolve)->moveToCurrentRow();
															}
														}
													}
												}
											}
											if (returnVal) {
												var$8 = returnVal;
												return$7 = true;
												goto $finally2;
											}
											try {
												for (int32_t i = 1; i <= icolCount; ++i) {
													$var($Object, obj, crs->getObject(i));
													if (obj != nullptr) {
														$nc(pstmt)->setObject(i, obj);
													} else {
														$nc(pstmt)->setNull(i, $nc($(crs->getMetaData()))->getColumnType(i));
													}
												}
												$nc(pstmt)->executeUpdate();
												return false;
											} catch ($SQLException& ex) {
												$nc(this->crsResolve)->moveToInsertRow();
												for (int32_t i = 1; i <= icolCount; ++i) {
													$nc(this->crsResolve)->updateNull(i);
												}
												$nc(this->crsResolve)->insertRow();
												$nc(this->crsResolve)->moveToCurrentRow();
												return true;
											}
										} catch ($Throwable& t$) {
											if (rs2 != nullptr) {
												try {
													rs2->close();
												} catch ($Throwable& x2) {
													t$->addSuppressed(x2);
												}
											}
											$throw(t$);
										}
									} catch ($Throwable& var$9) {
										$assign(var$6, var$9);
									} $finally2: {
										if (rs2 != nullptr) {
											rs2->close();
										}
									}
									if (var$6 != nullptr) {
										$throw(var$6);
									}
									if (return$7) {
										var$5 = var$8;
										return$4 = true;
										goto $finally1;
									}
								}
							} catch ($Throwable& t$) {
								if (rs != nullptr) {
									try {
										rs->close();
									} catch ($Throwable& x2) {
										t$->addSuppressed(x2);
									}
								}
								$throw(t$);
							}
						} catch ($Throwable& var$10) {
							$assign(var$3, var$10);
						} $finally1: {
							if (rs != nullptr) {
								rs->close();
							}
						}
						if (var$3 != nullptr) {
							$throw(var$3);
						}
						if (return$4) {
							var$2 = var$5;
							return$1 = true;
							goto $finally;
						}
					}
				} catch ($Throwable& t$) {
					if (pstmtSel != nullptr) {
						try {
							pstmtSel->close();
						} catch ($Throwable& x2) {
							t$->addSuppressed(x2);
						}
					}
					$throw(t$);
				}
			} catch ($Throwable& var$11) {
				$assign(var$0, var$11);
			} $finally: {
				if (pstmtSel != nullptr) {
					pstmtSel->close();
				}
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
			if (return$1) {
				return var$2;
			}
		}
	}
	$shouldNotReachHere();
}

bool CachedRowSetWriter::deleteOriginalRow($CachedRowSet* crs, $CachedRowSetImpl* crsRes) {
	$useLocalCurrentObjectStackCache();
	$var($PreparedStatement, pstmt, nullptr);
	int32_t i = 0;
	int32_t idx = 0;
	$var($String, strSelect, nullptr);
	$var($ResultSet, origVals, $nc(crs)->getOriginalRow());
	$nc(origVals)->next();
	$set(this, deleteWhere, buildWhereClause(this->deleteWhere, origVals));
	$assign(pstmt, $nc(this->con)->prepareStatement($$str({this->selectCmd, this->deleteWhere}), $ResultSet::TYPE_SCROLL_SENSITIVE, $ResultSet::CONCUR_READ_ONLY));
	for (i = 0; i < $nc(this->keyCols)->length; ++i) {
		if ($nc(this->params)->get(i) != nullptr) {
			$nc(pstmt)->setObject(++idx, $nc(this->params)->get(i));
		} else {
			continue;
		}
	}
	try {
		$nc(pstmt)->setMaxRows(crs->getMaxRows());
		pstmt->setMaxFieldSize(crs->getMaxFieldSize());
		pstmt->setEscapeProcessing(crs->getEscapeProcessing());
		pstmt->setQueryTimeout(crs->getQueryTimeout());
	} catch ($Exception& ex) {
	}
	$var($ResultSet, rs, $nc(pstmt)->executeQuery());
	if ($nc(rs)->next() == true) {
		if (rs->next()) {
			return true;
		}
		rs->first();
		bool boolChanged = false;
		$nc(crsRes)->moveToInsertRow();
		for (i = 1; i <= $nc($(crs->getMetaData()))->getColumnCount(); ++i) {
			$var($Object, original, origVals->getObject(i));
			$var($Object, changed, rs->getObject(i));
			if (original != nullptr && changed != nullptr) {
				if (!$nc(($($of(original)->toString())))->equals($($of(changed)->toString()))) {
					boolChanged = true;
					crsRes->updateObject(i, $(origVals->getObject(i)));
				}
			} else {
				crsRes->updateNull(i);
			}
		}
		crsRes->insertRow();
		crsRes->moveToCurrentRow();
		if (boolChanged) {
			return true;
		} else {
		}
		$var($String, cmd, $str({this->deleteCmd, this->deleteWhere}));
		$assign(pstmt, $nc(this->con)->prepareStatement(cmd));
		idx = 0;
		for (i = 0; i < $nc(this->keyCols)->length; ++i) {
			if ($nc(this->params)->get(i) != nullptr) {
				$nc(pstmt)->setObject(++idx, $nc(this->params)->get(i));
			} else {
				continue;
			}
		}
		if ($nc(pstmt)->executeUpdate() != 1) {
			return true;
		}
		$nc(pstmt)->close();
	} else {
		return true;
	}
	return false;
}

void CachedRowSetWriter::setReader($CachedRowSetReader* reader) {
	$set(this, reader, reader);
}

$CachedRowSetReader* CachedRowSetWriter::getReader() {
	return this->reader;
}

void CachedRowSetWriter::initSQLStatements($CachedRowSet* caller) {
	$useLocalCurrentObjectStackCache();
	int32_t i = 0;
	$set(this, callerMd, $nc(caller)->getMetaData());
	this->callerColumnCount = $nc(this->callerMd)->getColumnCount();
	if (this->callerColumnCount < 1) {
		return;
	}
	$var($String, table, caller->getTableName());
	if (table == nullptr) {
		$assign(table, $nc(this->callerMd)->getTableName(1));
		if (table == nullptr || $nc(table)->length() == 0) {
			$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("crswriter.tname"_s))))->toString()));
		}
	}
	$var($String, catalog, $nc(this->callerMd)->getCatalogName(1));
	$var($String, schema, $nc(this->callerMd)->getSchemaName(1));
	$var($DatabaseMetaData, dbmd, $nc(this->con)->getMetaData());
	$set(this, selectCmd, "SELECT "_s);
	for (i = 1; i <= this->callerColumnCount; ++i) {
		$plusAssignField(this, selectCmd, $($nc(this->callerMd)->getColumnName(i)));
		if (i < $nc(this->callerMd)->getColumnCount()) {
			$plusAssignField(this, selectCmd, ", "_s);
		} else {
			$plusAssignField(this, selectCmd, " "_s);
		}
	}
	$plusAssignField(this, selectCmd, $$str({"FROM "_s, $(buildTableName(dbmd, catalog, schema, table))}));
	$set(this, updateCmd, $str({"UPDATE "_s, $(buildTableName(dbmd, catalog, schema, table))}));
	$var($String, tempupdCmd, $nc(this->updateCmd)->toLowerCase());
	int32_t idxupWhere = tempupdCmd->indexOf("where"_s);
	if (idxupWhere != -1) {
		$set(this, updateCmd, $nc(this->updateCmd)->substring(0, idxupWhere));
	}
	$plusAssignField(this, updateCmd, "SET "_s);
	$set(this, insertCmd, $str({"INSERT INTO "_s, $(buildTableName(dbmd, catalog, schema, table))}));
	$plusAssignField(this, insertCmd, "("_s);
	for (i = 1; i <= this->callerColumnCount; ++i) {
		$plusAssignField(this, insertCmd, $($nc(this->callerMd)->getColumnName(i)));
		if (i < $nc(this->callerMd)->getColumnCount()) {
			$plusAssignField(this, insertCmd, ", "_s);
		} else {
			$plusAssignField(this, insertCmd, ") VALUES ("_s);
		}
	}
	for (i = 1; i <= this->callerColumnCount; ++i) {
		$plusAssignField(this, insertCmd, "?"_s);
		if (i < this->callerColumnCount) {
			$plusAssignField(this, insertCmd, ", "_s);
		} else {
			$plusAssignField(this, insertCmd, ")"_s);
		}
	}
	$set(this, deleteCmd, $str({"DELETE FROM "_s, $(buildTableName(dbmd, catalog, schema, table))}));
	buildKeyDesc(caller);
}

$String* CachedRowSetWriter::buildTableName($DatabaseMetaData* dbmd, $String* catalog$renamed, $String* schema$renamed, $String* table$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($String, schema, schema$renamed);
	$var($String, catalog, catalog$renamed);
	$var($String, table, table$renamed);
	$var($String, cmd, ""_s);
	$assign(catalog, $nc(catalog)->trim());
	$assign(schema, $nc(schema)->trim());
	$assign(table, $nc(table)->trim());
	if ($nc(dbmd)->isCatalogAtStart() == true) {
		if (catalog != nullptr && catalog->length() > 0) {
			$plusAssign(cmd, $$str({catalog, $(dbmd->getCatalogSeparator())}));
		}
		if (schema != nullptr && schema->length() > 0) {
			$plusAssign(cmd, $$str({schema, "."_s}));
		}
		$plusAssign(cmd, table);
	} else {
		if (schema != nullptr && schema->length() > 0) {
			$plusAssign(cmd, $$str({schema, "."_s}));
		}
		$plusAssign(cmd, table);
		if (catalog != nullptr && catalog->length() > 0) {
			$plusAssign(cmd, $$str({$(dbmd->getCatalogSeparator()), catalog}));
		}
	}
	$plusAssign(cmd, " "_s);
	return cmd;
}

void CachedRowSetWriter::buildKeyDesc($CachedRowSet* crs) {
	$useLocalCurrentObjectStackCache();
	$set(this, keyCols, $nc(crs)->getKeyColumns());
	$var($ResultSetMetaData, resultsetmd, crs->getMetaData());
	if (this->keyCols == nullptr || $nc(this->keyCols)->length == 0) {
		$var($ArrayList, listKeys, $new($ArrayList));
		for (int32_t i = 0; i < this->callerColumnCount; ++i) {
			bool var$4 = $nc(resultsetmd)->getColumnType(i + 1) != $Types::CLOB;
			bool var$3 = var$4 && resultsetmd->getColumnType(i + 1) != $Types::STRUCT;
			bool var$2 = var$3 && resultsetmd->getColumnType(i + 1) != $Types::SQLXML;
			bool var$1 = var$2 && resultsetmd->getColumnType(i + 1) != $Types::BLOB;
			bool var$0 = var$1 && resultsetmd->getColumnType(i + 1) != $Types::ARRAY;
			if (var$0 && resultsetmd->getColumnType(i + 1) != $Types::OTHER) {
				listKeys->add($($Integer::valueOf(i + 1)));
			}
		}
		$set(this, keyCols, $new($ints, listKeys->size()));
		for (int32_t i = 0; i < listKeys->size(); ++i) {
			$nc(this->keyCols)->set(i, $nc(($cast($Integer, $(listKeys->get(i)))))->intValue());
		}
	}
	$set(this, params, $new($ObjectArray, $nc(this->keyCols)->length));
}

$String* CachedRowSetWriter::buildWhereClause($String* whereClause$renamed, $ResultSet* rs) {
	$useLocalCurrentObjectStackCache();
	$var($String, whereClause, whereClause$renamed);
	$assign(whereClause, "WHERE "_s);
	for (int32_t i = 0; i < $nc(this->keyCols)->length; ++i) {
		if (i > 0) {
			$plusAssign(whereClause, "AND "_s);
		}
		$plusAssign(whereClause, $($nc(this->callerMd)->getColumnName($nc(this->keyCols)->get(i))));
		$nc(this->params)->set(i, $($nc(rs)->getObject($nc(this->keyCols)->get(i))));
		if (rs->wasNull() == true) {
			$plusAssign(whereClause, " IS NULL "_s);
		} else {
			$plusAssign(whereClause, " = ? "_s);
		}
	}
	return whereClause;
}

void CachedRowSetWriter::updateResolvedConflictToDB($CachedRowSet* crs, $Connection* con) {
	$useLocalCurrentObjectStackCache();
	$var($PreparedStatement, pStmt, nullptr);
	$var($String, strWhere, "WHERE "_s);
	$var($String, strExec, " "_s);
	$var($String, strUpdate, "UPDATE "_s);
	int32_t icolCount = $nc($($nc(crs)->getMetaData()))->getColumnCount();
	$var($ints, keyColumns, crs->getKeyColumns());
	$var($ObjectArray, param, nullptr);
	$var($String, strSet, ""_s);
	$assign(strWhere, buildWhereClause(strWhere, crs));
	if (keyColumns == nullptr || $nc(keyColumns)->length == 0) {
		$assign(keyColumns, $new($ints, icolCount));
		for (int32_t i = 0; i < keyColumns->length;) {
			int32_t var$0 = i;
			keyColumns->set(var$0, ++i);
		}
	}
	$assign(param, $new($ObjectArray, $nc(keyColumns)->length));
	$var($String, var$1, "UPDATE "_s);
	$var($DatabaseMetaData, var$2, $nc(con)->getMetaData());
	$var($String, var$3, $nc($(crs->getMetaData()))->getCatalogName(1));
	$var($String, var$4, $nc($(crs->getMetaData()))->getSchemaName(1));
	$assign(strUpdate, $concat(var$1, $(buildTableName(var$2, var$3, var$4, $(crs->getTableName())))));
	$plusAssign(strUpdate, "SET "_s);
	bool first = true;
	for (int32_t i = 1; i <= icolCount; ++i) {
		if (crs->columnUpdated(i)) {
			if (first == false) {
				$plusAssign(strSet, ", "_s);
			}
			$plusAssign(strSet, $($nc($(crs->getMetaData()))->getColumnName(i)));
			$plusAssign(strSet, " = ? "_s);
			first = false;
		}
	}
	$plusAssign(strUpdate, strSet);
	$assign(strWhere, "WHERE "_s);
	for (int32_t i = 0; i < keyColumns->length; ++i) {
		if (i > 0) {
			$plusAssign(strWhere, "AND "_s);
		}
		$plusAssign(strWhere, $($nc($(crs->getMetaData()))->getColumnName(keyColumns->get(i))));
		param->set(i, $(crs->getObject(keyColumns->get(i))));
		if (crs->wasNull() == true) {
			$plusAssign(strWhere, " IS NULL "_s);
		} else {
			$plusAssign(strWhere, " = ? "_s);
		}
	}
	$plusAssign(strUpdate, strWhere);
	$assign(pStmt, $nc(con)->prepareStatement(strUpdate));
	int32_t idx = 0;
	for (int32_t i = 0; i < icolCount; ++i) {
		if (crs->columnUpdated(i + 1)) {
			$var($Object, obj, crs->getObject(i + 1));
			if (obj != nullptr) {
				$nc(pStmt)->setObject(++idx, obj);
			} else {
				$nc(pStmt)->setNull(i + 1, $nc($(crs->getMetaData()))->getColumnType(i + 1));
			}
		}
	}
	for (int32_t i = 0; i < keyColumns->length; ++i) {
		if (param->get(i) != nullptr) {
			$nc(pStmt)->setObject(++idx, param->get(i));
		}
	}
	int32_t id = $nc(pStmt)->executeUpdate();
}

void CachedRowSetWriter::commit() {
	$nc(this->con)->commit();
	if ($nc(this->reader)->getCloseConnection() == true) {
		$nc(this->con)->close();
	}
}

void CachedRowSetWriter::commit($CachedRowSetImpl* crs, bool updateRowset) {
	$nc(this->con)->commit();
	if (updateRowset) {
		if ($nc(crs)->getCommand() != nullptr) {
			crs->execute(this->con);
		}
	}
	if ($nc(this->reader)->getCloseConnection() == true) {
		$nc(this->con)->close();
	}
}

void CachedRowSetWriter::rollback() {
	$nc(this->con)->rollback();
	if ($nc(this->reader)->getCloseConnection() == true) {
		$nc(this->con)->close();
	}
}

void CachedRowSetWriter::rollback($Savepoint* s) {
	$nc(this->con)->rollback(s);
	if ($nc(this->reader)->getCloseConnection() == true) {
		$nc(this->con)->close();
	}
}

void CachedRowSetWriter::readObject($ObjectInputStream* ois) {
	$nc(ois)->defaultReadObject();
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
}

bool CachedRowSetWriter::isPKNameValid($String* pk, $ResultSetMetaData* rsmd) {
	$useLocalCurrentObjectStackCache();
	bool isValid = false;
	int32_t cols = $nc(rsmd)->getColumnCount();
	for (int32_t i = 1; i <= cols; ++i) {
		$var($String, colName, rsmd->getColumnClassName(i));
		if ($nc(colName)->equalsIgnoreCase(pk)) {
			isValid = true;
			break;
		}
	}
	return isValid;
}

CachedRowSetWriter::CachedRowSetWriter() {
}

$Class* CachedRowSetWriter::load$($String* name, bool initialize) {
	$loadClass(CachedRowSetWriter, name, initialize, &_CachedRowSetWriter_ClassInfo_, allocate$CachedRowSetWriter);
	return class$;
}

$Class* CachedRowSetWriter::class$ = nullptr;

			} // internal
		} // rowset
	} // sun
} // com