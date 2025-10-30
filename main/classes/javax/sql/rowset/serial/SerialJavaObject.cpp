#include <javax/sql/rowset/serial/SerialJavaObject.h>

#include <java/io/IOException.h>
#include <java/io/ObjectInputStream$GetField.h>
#include <java/io/ObjectInputStream.h>
#include <java/io/ObjectOutputStream$PutField.h>
#include <java/io/ObjectOutputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/ClassLoader.h>
#include <java/lang/CloneNotSupportedException.h>
#include <java/lang/InternalError.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/reflect/Field.h>
#include <java/lang/reflect/Modifier.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractList.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Vector.h>
#include <javax/sql/rowset/RowSetWarning.h>
#include <javax/sql/rowset/serial/SerialException.h>
#include <jdk/internal/reflect/Reflection.h>
#include <sun/reflect/misc/ReflectUtil.h>
#include <jcpp.h>

#undef STATIC

using $FieldArray = $Array<::java::lang::reflect::Field>;
using $IOException = ::java::io::IOException;
using $ObjectInputStream = ::java::io::ObjectInputStream;
using $ObjectInputStream$GetField = ::java::io::ObjectInputStream$GetField;
using $ObjectOutputStream = ::java::io::ObjectOutputStream;
using $ObjectOutputStream$PutField = ::java::io::ObjectOutputStream$PutField;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $ClassLoader = ::java::lang::ClassLoader;
using $CloneNotSupportedException = ::java::lang::CloneNotSupportedException;
using $Cloneable = ::java::lang::Cloneable;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $FieldInfo = ::java::lang::FieldInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityManager = ::java::lang::SecurityManager;
using $Field = ::java::lang::reflect::Field;
using $Modifier = ::java::lang::reflect::Modifier;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractList = ::java::util::AbstractList;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Vector = ::java::util::Vector;
using $RowSetWarning = ::javax::sql::rowset::RowSetWarning;
using $SerialException = ::javax::sql::rowset::serial::SerialException;
using $Reflection = ::jdk::internal::reflect::Reflection;
using $ReflectUtil = ::sun::reflect::misc::ReflectUtil;

namespace javax {
	namespace sql {
		namespace rowset {
			namespace serial {

$CompoundAttribute _SerialJavaObject_MethodAnnotations_getFields3[] = {
	{"Ljdk/internal/reflect/CallerSensitive;", nullptr},
	{}
};

$FieldInfo _SerialJavaObject_FieldInfo_[] = {
	{"obj", "Ljava/lang/Object;", nullptr, $PRIVATE, $field(SerialJavaObject, obj)},
	{"fields", "[Ljava/lang/reflect/Field;", nullptr, $PRIVATE | $TRANSIENT, $field(SerialJavaObject, fields)},
	{"serialVersionUID", "J", nullptr, $STATIC | $FINAL, $constField(SerialJavaObject, serialVersionUID)},
	{"chain", "Ljava/util/Vector;", "Ljava/util/Vector<Ljavax/sql/rowset/RowSetWarning;>;", 0, $field(SerialJavaObject, chain)},
	{}
};

$MethodInfo _SerialJavaObject_MethodInfo_[] = {
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"<init>", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $method(static_cast<void(SerialJavaObject::*)(Object$*)>(&SerialJavaObject::init$)), "javax.sql.rowset.serial.SerialException"},
	{"clone", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"getFields", "()[Ljava/lang/reflect/Field;", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException", nullptr, _SerialJavaObject_MethodAnnotations_getFields3},
	{"getObject", "()Ljava/lang/Object;", nullptr, $PUBLIC, nullptr, "javax.sql.rowset.serial.SerialException"},
	{"hasStaticFields", "([Ljava/lang/reflect/Field;)Z", nullptr, $PRIVATE | $STATIC, $method(static_cast<bool(*)($FieldArray*)>(&SerialJavaObject::hasStaticFields))},
	{"hashCode", "()I", nullptr, $PUBLIC},
	{"readObject", "(Ljava/io/ObjectInputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(SerialJavaObject::*)($ObjectInputStream*)>(&SerialJavaObject::readObject)), "java.io.IOException,java.lang.ClassNotFoundException"},
	{"setWarning", "(Ljavax/sql/rowset/RowSetWarning;)V", nullptr, $PRIVATE, $method(static_cast<void(SerialJavaObject::*)($RowSetWarning*)>(&SerialJavaObject::setWarning))},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"writeObject", "(Ljava/io/ObjectOutputStream;)V", nullptr, $PRIVATE, $method(static_cast<void(SerialJavaObject::*)($ObjectOutputStream*)>(&SerialJavaObject::writeObject)), "java.io.IOException"},
	{}
};

$ClassInfo _SerialJavaObject_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"javax.sql.rowset.serial.SerialJavaObject",
	"java.lang.Object",
	"java.io.Serializable,java.lang.Cloneable",
	_SerialJavaObject_FieldInfo_,
	_SerialJavaObject_MethodInfo_
};

$Object* allocate$SerialJavaObject($Class* clazz) {
	return $of($alloc(SerialJavaObject));
}

$String* SerialJavaObject::toString() {
	 return this->$Serializable::toString();
}

void SerialJavaObject::finalize() {
	this->$Serializable::finalize();
}

void SerialJavaObject::init$(Object$* obj) {
	$beforeCallerSensitive();
	$Class* c = $nc($of(obj))->getClass();
	if (!($instanceOf($Serializable, obj))) {
		setWarning($$new($RowSetWarning, "Warning, the object passed to the constructor does not implement Serializable"_s));
	}
	$set(this, fields, $nc(c)->getFields());
	if (hasStaticFields(this->fields)) {
		$throwNew($SerialException, "Located static fields in object instance. Cannot serialize"_s);
	}
	$set(this, obj, obj);
}

$Object* SerialJavaObject::getObject() {
	return $of(this->obj);
}

$FieldArray* SerialJavaObject::getFields() {
	$useLocalCurrentObjectStackCache();
	if (this->fields != nullptr) {
		$Class* c = $nc($of(this->obj))->getClass();
		$var($SecurityManager, sm, $System::getSecurityManager());
		if (sm != nullptr) {
			$Class* caller = $Reflection::getCallerClass();
			$var($ClassLoader, var$0, $nc(caller)->getClassLoader());
			if ($ReflectUtil::needsPackageAccessCheck(var$0, $($nc(c)->getClassLoader()))) {
				$ReflectUtil::checkPackageAccess(c);
			}
		}
		return $nc(c)->getFields();
	} else {
		$throwNew($SerialException, "SerialJavaObject does not contain a serialized object instance"_s);
	}
}

bool SerialJavaObject::equals(Object$* o) {
	if ($equals(this, o)) {
		return true;
	}
	if ($instanceOf(SerialJavaObject, o)) {
		$var(SerialJavaObject, sjo, $cast(SerialJavaObject, o));
		return $nc($of(this->obj))->equals($nc(sjo)->obj);
	}
	return false;
}

int32_t SerialJavaObject::hashCode() {
	return 31 + $nc($of(this->obj))->hashCode();
}

$Object* SerialJavaObject::clone() {
	try {
		$var(SerialJavaObject, sjo, $cast(SerialJavaObject, $Serializable::clone()));
		$set($nc(sjo), fields, $fcast($FieldArray, $Arrays::copyOf(this->fields, $nc(this->fields)->length)));
		if (this->chain != nullptr) {
			$set(sjo, chain, $new($Vector, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>(this->chain)))));
		}
		return $of(sjo);
	} catch ($CloneNotSupportedException& ex) {
		$throwNew($InternalError);
	}
	$shouldNotReachHere();
}

void SerialJavaObject::setWarning($RowSetWarning* e) {
	if (this->chain == nullptr) {
		$set(this, chain, $new($Vector));
	}
	$nc(this->chain)->add(e);
}

void SerialJavaObject::readObject($ObjectInputStream* s) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($ObjectInputStream$GetField, fields1, $nc(s)->readFields());
	$var($Vector, tmp, $cast($Vector, $nc(fields1)->get("chain"_s, ($Object*)nullptr)));
	if (tmp != nullptr) {
		$set(this, chain, $new($Vector, static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>(tmp)))));
	}
	$set(this, obj, fields1->get("obj"_s, ($Object*)nullptr));
	if (this->obj != nullptr) {
		$set(this, fields, $nc($of(this->obj))->getClass()->getFields());
		if (hasStaticFields(this->fields)) {
			$throwNew($IOException, "Located static fields in object instance. Cannot serialize"_s);
		}
	} else {
		$throwNew($IOException, "Object cannot be null!"_s);
	}
}

void SerialJavaObject::writeObject($ObjectOutputStream* s) {
	$var($ObjectOutputStream$PutField, fields, $nc(s)->putFields());
	$nc(fields)->put("obj"_s, this->obj);
	fields->put("chain"_s, $of(this->chain));
	s->writeFields();
}

bool SerialJavaObject::hasStaticFields($FieldArray* fields) {
	$init(SerialJavaObject);
	$useLocalCurrentObjectStackCache();
	{
		$var($FieldArray, arr$, fields);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Field, field, arr$->get(i$));
			{
				if ($nc(field)->getModifiers() == $Modifier::STATIC) {
					return true;
				}
			}
		}
	}
	return false;
}

SerialJavaObject::SerialJavaObject() {
}

$Class* SerialJavaObject::load$($String* name, bool initialize) {
	$loadClass(SerialJavaObject, name, initialize, &_SerialJavaObject_ClassInfo_, allocate$SerialJavaObject);
	return class$;
}

$Class* SerialJavaObject::class$ = nullptr;

			} // serial
		} // rowset
	} // sql
} // javax