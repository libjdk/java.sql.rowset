#include <com/sun/rowset/internal/CachedRowSetReader.h>

#include <com/sun/rowset/CachedRowSetImpl.h>
#include <com/sun/rowset/JdbcRowSetResourceBundle.h>
#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/Reader.h>
#include <java/sql/Connection.h>
#include <java/sql/Date.h>
#include <java/sql/DriverManager.h>
#include <java/sql/PreparedStatement.h>
#include <java/sql/ResultSet.h>
#include <java/sql/SQLException.h>
#include <java/sql/Time.h>
#include <java/sql/Timestamp.h>
#include <java/util/Calendar.h>
#include <javax/naming/Context.h>
#include <javax/naming/InitialContext.h>
#include <javax/naming/NamingException.h>
#include <javax/sql/DataSource.h>
#include <javax/sql/RowSet.h>
#include <javax/sql/RowSetInternal.h>
#include <javax/sql/RowSetReader.h>
#include <javax/sql/rowset/CachedRowSet.h>
#include <jcpp.h>

#undef ASCII_STREAM_PARAM
#undef BINARY_STREAM_PARAM
#undef CONCUR_UPDATABLE
#undef TYPE_SCROLL_INSENSITIVE
#undef UNICODE_STREAM_PARAM

using $CachedRowSetImpl = ::com::sun::rowset::CachedRowSetImpl;
using $JdbcRowSetResourceBundle = ::com::sun::rowset::JdbcRowSetResourceBundle;
using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $PrintStream = ::java::io::PrintStream;
using $Reader = ::java::io::Reader;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $Connection = ::java::sql::Connection;
using $Date = ::java::sql::Date;
using $DriverManager = ::java::sql::DriverManager;
using $PreparedStatement = ::java::sql::PreparedStatement;
using $ResultSet = ::java::sql::ResultSet;
using $SQLException = ::java::sql::SQLException;
using $Statement = ::java::sql::Statement;
using $Time = ::java::sql::Time;
using $Timestamp = ::java::sql::Timestamp;
using $Calendar = ::java::util::Calendar;
using $Context = ::javax::naming::Context;
using $InitialContext = ::javax::naming::InitialContext;
using $NamingException = ::javax::naming::NamingException;
using $DataSource = ::javax::sql::DataSource;
using $RowSet = ::javax::sql::RowSet;
using $RowSetInternal = ::javax::sql::RowSetInternal;
using $RowSetReader = ::javax::sql::RowSetReader;
using $CachedRowSet = ::javax::sql::rowset::CachedRowSet;

namespace com {
	namespace sun {
		namespace rowset {
			namespace internal {

$FieldInfo _CachedRowSetReader_FieldInfo_[] = {
	{"writerCalls", "I", nullptr, $PRIVATE, $field(CachedRowSetReader, writerCalls)},
	{"userCon", "Z", nullptr, $PRIVATE, $field(CachedRowSetReader, userCon)},
	{"startPosition", "I", nullptr, $PRIVATE, $field(CachedRowSetReader, startPosition)},
	{"resBundle", "Lcom/sun/rowset/JdbcRowSetResourceBundle;", nullptr, $PRIVATE, $field(CachedRowSetReader, resBundle)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(CachedRowSetReader, serialVersionUID)},
	{}
};

$MethodInfo _CachedRowSetReader_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(CachedRowSetReader::*)()>(&CachedRowSetReader::init$))},
	{"connect", "(Ljavax/sql/RowSetInternal;)Ljava/sql/Connection;", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"decodeParams", "([Ljava/lang/Object;Ljava/sql/PreparedStatement;)V", nullptr, $PRIVATE, $method(static_cast<void(CachedRowSetReader::*)($ObjectArray*,$PreparedStatement*)>(&CachedRowSetReader::decodeParams)), "java.sql.SQLException"},
	{"getCloseConnection", "()Z", nullptr, $PROTECTED},
	{"readData", "(Ljavax/sql/RowSetInternal;)V", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(CachedRowSetReader::*)($ObjectInputStream*)>(&CachedRowSetReader::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"reset", "()Z", nullptr, $PUBLIC, nullptr, "java.sql.SQLException"},
	{"setStartPosition", "(I)V", nullptr, $PUBLIC},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _CachedRowSetReader_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"com.sun.rowset.internal.CachedRowSetReader",
	"java.lang.Object",
	"javax.sql.RowSetReader,java.io.Serializable",
	_CachedRowSetReader_FieldInfo_,
	_CachedRowSetReader_MethodInfo_
};

$Object* allocate$CachedRowSetReader($Class* clazz) {
	return $of($alloc(CachedRowSetReader));
}

int32_t CachedRowSetReader::hashCode() {
	 return this->$RowSetReader::hashCode();
}

bool CachedRowSetReader::equals(Object$* arg0) {
	 return this->$RowSetReader::equals(arg0);
}

$Object* CachedRowSetReader::clone() {
	 return this->$RowSetReader::clone();
}

$String* CachedRowSetReader::toString() {
	 return this->$RowSetReader::toString();
}

void CachedRowSetReader::finalize() {
	this->$RowSetReader::finalize();
}

void CachedRowSetReader::init$() {
	this->writerCalls = 0;
	this->userCon = false;
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
}

void CachedRowSetReader::readData($RowSetInternal* caller) {
	$useLocalCurrentObjectStackCache();
	$var($Connection, con, nullptr);
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				$var($CachedRowSet, crs, $cast($CachedRowSet, caller));
				bool var$1 = $nc(crs)->getPageSize() == 0;
				if (var$1 && crs->size() > 0) {
					crs->close();
				}
				this->writerCalls = 0;
				this->userCon = false;
				$assign(con, this->connect(caller));
				if (con == nullptr || $nc(crs)->getCommand() == nullptr) {
					$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("crsreader.connecterr"_s))))->toString()));
				}
				try {
					$nc(con)->setTransactionIsolation($nc(crs)->getTransactionIsolation());
				} catch ($Exception& ex) {
				}
				$var($PreparedStatement, pstmt, $nc(con)->prepareStatement($($nc(crs)->getCommand())));
				decodeParams($($nc(caller)->getParams()), pstmt);
				try {
					$nc(pstmt)->setMaxRows($nc(crs)->getMaxRows());
					pstmt->setMaxFieldSize($nc(crs)->getMaxFieldSize());
					pstmt->setEscapeProcessing($nc(crs)->getEscapeProcessing());
					pstmt->setQueryTimeout($nc(crs)->getQueryTimeout());
				} catch ($Exception& ex) {
					$throwNew($SQLException, $(ex->getMessage()));
				}
				if ($($nc($($nc(crs)->getCommand()))->toLowerCase())->indexOf("select"_s) != -1) {
					$var($ResultSet, rs, $nc(pstmt)->executeQuery());
					if (crs->getPageSize() == 0) {
						crs->populate(rs);
					} else {
						$assign(pstmt, con->prepareStatement($(crs->getCommand()), $ResultSet::TYPE_SCROLL_INSENSITIVE, $ResultSet::CONCUR_UPDATABLE));
						decodeParams($($nc(caller)->getParams()), pstmt);
						try {
							$nc(pstmt)->setMaxRows(crs->getMaxRows());
							pstmt->setMaxFieldSize(crs->getMaxFieldSize());
							pstmt->setEscapeProcessing(crs->getEscapeProcessing());
							pstmt->setQueryTimeout(crs->getQueryTimeout());
						} catch ($Exception& ex) {
							$throwNew($SQLException, $(ex->getMessage()));
						}
						$assign(rs, $nc(pstmt)->executeQuery());
						crs->populate(rs, this->startPosition);
					}
					$nc(rs)->close();
				} else {
					$nc(pstmt)->executeUpdate();
				}
				$nc(pstmt)->close();
				try {
					con->commit();
				} catch ($SQLException& ex) {
				}
				if (getCloseConnection() == true) {
					con->close();
				}
			} catch ($SQLException& ex) {
				$throw(ex);
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} /*finally*/ {
			try {
				if (con != nullptr && getCloseConnection() == true) {
					try {
						if (!con->getAutoCommit()) {
							con->rollback();
						}
					} catch ($Exception& dummy) {
					}
					con->close();
					$assign(con, nullptr);
				}
			} catch ($SQLException& e) {
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

bool CachedRowSetReader::reset() {
	++this->writerCalls;
	return this->writerCalls == 1;
}

$Connection* CachedRowSetReader::connect($RowSetInternal* caller) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if ($nc(caller)->getConnection() != nullptr) {
		this->userCon = true;
		return caller->getConnection();
	} else if ($nc(($cast($RowSet, caller)))->getDataSourceName() != nullptr) {
		try {
			$var($Context, ctx, $new($InitialContext));
			$var($DataSource, ds, $cast($DataSource, ctx->lookup($(($cast($RowSet, caller))->getDataSourceName()))));
			if (($cast($RowSet, caller))->getUsername() != nullptr) {
				$var($String, var$0, ($cast($RowSet, caller))->getUsername());
				return $nc(ds)->getConnection(var$0, $(($cast($RowSet, caller))->getPassword()));
			} else {
				return $nc(ds)->getConnection();
			}
		} catch ($NamingException& ex) {
			$var($SQLException, sqlEx, $new($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("crsreader.connect"_s))))->toString())));
			sqlEx->initCause(ex);
			$throw(sqlEx);
		}
	} else if (($cast($RowSet, caller))->getUrl() != nullptr) {
		$var($String, var$1, ($cast($RowSet, caller))->getUrl());
		$var($String, var$2, ($cast($RowSet, caller))->getUsername());
		return $DriverManager::getConnection(var$1, var$2, $(($cast($RowSet, caller))->getPassword()));
	} else {
		return nullptr;
	}
}

void CachedRowSetReader::decodeParams($ObjectArray* params, $PreparedStatement* pstmt) {
	$useLocalCurrentObjectStackCache();
	int32_t arraySize = 0;
	$var($ObjectArray, param, nullptr);
	for (int32_t i = 0; i < $nc(params)->length; ++i) {
		if ($instanceOf($ObjectArray, params->get(i))) {
			$assign(param, $cast($ObjectArray, params->get(i)));
			if ($nc(param)->length == 2) {
				if (param->get(0) == nullptr) {
					$nc(pstmt)->setNull(i + 1, $nc(($cast($Integer, param->get(1))))->intValue());
					continue;
				}
				if ($instanceOf($Date, param->get(0)) || $instanceOf($Time, param->get(0)) || $instanceOf($Timestamp, param->get(0))) {
					$nc($System::err)->println($($nc($of($($nc(this->resBundle)->handleGetObject("crsreader.datedetected"_s))))->toString()));
					if ($instanceOf($Calendar, param->get(1))) {
						$nc($System::err)->println($($nc($of($($nc(this->resBundle)->handleGetObject("crsreader.caldetected"_s))))->toString()));
						$nc(pstmt)->setDate(i + 1, $cast($Date, param->get(0)), $cast($Calendar, param->get(1)));
						continue;
					} else {
						$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("crsreader.paramtype"_s))))->toString()));
					}
				}
				if ($instanceOf($Reader, param->get(0))) {
					$nc(pstmt)->setCharacterStream(i + 1, $cast($Reader, param->get(0)), $nc(($cast($Integer, param->get(1))))->intValue());
					continue;
				}
				if ($instanceOf($Integer, param->get(1))) {
					$nc(pstmt)->setObject(i + 1, param->get(0), $nc(($cast($Integer, param->get(1))))->intValue());
					continue;
				}
			} else if (param->length == 3) {
				if (param->get(0) == nullptr) {
					$nc(pstmt)->setNull(i + 1, $nc(($cast($Integer, param->get(1))))->intValue(), $cast($String, param->get(2)));
					continue;
				}
				if ($instanceOf($InputStream, param->get(0))) {
					switch ($nc(($cast($Integer, param->get(2))))->intValue()) {
					case $CachedRowSetImpl::UNICODE_STREAM_PARAM:
						{
							$nc(pstmt)->setUnicodeStream(i + 1, $cast($InputStream, param->get(0)), $nc(($cast($Integer, param->get(1))))->intValue());
							break;
						}
					case $CachedRowSetImpl::BINARY_STREAM_PARAM:
						{
							$nc(pstmt)->setBinaryStream(i + 1, $cast($InputStream, param->get(0)), $nc(($cast($Integer, param->get(1))))->intValue());
							break;
						}
					case $CachedRowSetImpl::ASCII_STREAM_PARAM:
						{
							$nc(pstmt)->setAsciiStream(i + 1, $cast($InputStream, param->get(0)), $nc(($cast($Integer, param->get(1))))->intValue());
							break;
						}
					default:
						{
							$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("crsreader.paramtype"_s))))->toString()));
						}
					}
				}
				if ($instanceOf($Integer, param->get(1)) && $instanceOf($Integer, param->get(2))) {
					int32_t var$0 = i + 1;
					$var($Object, var$1, param->get(0));
					int32_t var$2 = $nc(($cast($Integer, param->get(1))))->intValue();
					$nc(pstmt)->setObject(var$0, var$1, var$2, $nc(($cast($Integer, param->get(2))))->intValue());
					continue;
				}
				$throwNew($SQLException, $($nc($of($($nc(this->resBundle)->handleGetObject("crsreader.paramtype"_s))))->toString()));
			} else {
				$nc(pstmt)->setObject(i + 1, params->get(i));
				continue;
			}
		} else {
			$nc(pstmt)->setObject(i + 1, params->get(i));
		}
	}
}

bool CachedRowSetReader::getCloseConnection() {
	if (this->userCon == true) {
		return false;
	}
	return true;
}

void CachedRowSetReader::setStartPosition(int32_t pos) {
	this->startPosition = pos;
}

void CachedRowSetReader::readObject($ObjectInputStream* ois) {
	$nc(ois)->defaultReadObject();
	try {
		$set(this, resBundle, $JdbcRowSetResourceBundle::getJdbcRowSetResourceBundle());
	} catch ($IOException& ioe) {
		$throwNew($RuntimeException, static_cast<$Throwable*>(ioe));
	}
}

CachedRowSetReader::CachedRowSetReader() {
}

$Class* CachedRowSetReader::load$($String* name, bool initialize) {
	$loadClass(CachedRowSetReader, name, initialize, &_CachedRowSetReader_ClassInfo_, allocate$CachedRowSetReader);
	return class$;
}

$Class* CachedRowSetReader::class$ = nullptr;

			} // internal
		} // rowset
	} // sun
} // com