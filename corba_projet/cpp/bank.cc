/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <bank.h>


using namespace std;

//--------------------------------------------------------
//  Implementation of stubs
//--------------------------------------------------------

/*
 * Base interface for class Transaction
 */

Bank::Transaction::~Transaction()
{
}

void *
Bank::Transaction::_narrow_helper( const char *_repoid )
{
  if( strcmp( _repoid, "IDL:Bank/Transaction:1.0" ) == 0 )
    return (void *)this;
  return NULL;
}

Bank::Transaction_ptr
Bank::Transaction::_narrow( CORBA::Object_ptr _obj )
{
  Bank::Transaction_ptr _o;
  if( !CORBA::is_nil( _obj ) ) {
    void *_p;
    if( (_p = _obj->_narrow_helper( "IDL:Bank/Transaction:1.0" )))
      return _duplicate( (Bank::Transaction_ptr) _p );
    if (!strcmp (_obj->_repoid(), "IDL:Bank/Transaction:1.0") || _obj->_is_a_remote ("IDL:Bank/Transaction:1.0")) {
      _o = new Bank::Transaction_stub;
      _o->CORBA::Object::operator=( *_obj );
      return _o;
    }
  }
  return _nil();
}

Bank::Transaction_ptr
Bank::Transaction::_narrow( CORBA::AbstractBase_ptr _obj )
{
  return _narrow (_obj->_to_object());
}

class _Marshaller_Bank_Transaction : public ::CORBA::StaticTypeInfo {
    typedef Bank::Transaction_ptr _MICO_T;
  public:
    ~_Marshaller_Bank_Transaction();
    StaticValueType create () const;
    void assign (StaticValueType dst, const StaticValueType src) const;
    void free (StaticValueType) const;
    void release (StaticValueType) const;
    ::CORBA::Boolean demarshal (::CORBA::DataDecoder&, StaticValueType) const;
    void marshal (::CORBA::DataEncoder &, StaticValueType) const;
};


_Marshaller_Bank_Transaction::~_Marshaller_Bank_Transaction()
{
}

::CORBA::StaticValueType _Marshaller_Bank_Transaction::create() const
{
  return (StaticValueType) new _MICO_T( 0 );
}

void _Marshaller_Bank_Transaction::assign( StaticValueType d, const StaticValueType s ) const
{
  *(_MICO_T*) d = ::Bank::Transaction::_duplicate( *(_MICO_T*) s );
}

void _Marshaller_Bank_Transaction::free( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
  delete (_MICO_T*) v;
}

void _Marshaller_Bank_Transaction::release( StaticValueType v ) const
{
  ::CORBA::release( *(_MICO_T *) v );
}

::CORBA::Boolean _Marshaller_Bank_Transaction::demarshal( ::CORBA::DataDecoder &dc, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj;
  if (!::CORBA::_stc_Object->demarshal(dc, &obj))
    return FALSE;
  *(_MICO_T *) v = ::Bank::Transaction::_narrow( obj );
  ::CORBA::Boolean ret = ::CORBA::is_nil (obj) || !::CORBA::is_nil (*(_MICO_T *)v);
  ::CORBA::release (obj);
  return ret;
}

void _Marshaller_Bank_Transaction::marshal( ::CORBA::DataEncoder &ec, StaticValueType v ) const
{
  ::CORBA::Object_ptr obj = *(_MICO_T *) v;
  ::CORBA::_stc_Object->marshal( ec, &obj );
}

::CORBA::StaticTypeInfo *_marshaller_Bank_Transaction;


/*
 * Stub interface for class Transaction
 */

Bank::Transaction_stub::~Transaction_stub()
{
}

#ifndef MICO_CONF_NO_POA

void *
POA_Bank::Transaction::_narrow_helper (const char * repoid)
{
  if (strcmp (repoid, "IDL:Bank/Transaction:1.0") == 0) {
    return (void *) this;
  }
  return NULL;
}

POA_Bank::Transaction *
POA_Bank::Transaction::_narrow (PortableServer::Servant serv) 
{
  void * p;
  if ((p = serv->_narrow_helper ("IDL:Bank/Transaction:1.0")) != NULL) {
    serv->_add_ref ();
    return (POA_Bank::Transaction *) p;
  }
  return NULL;
}

Bank::Transaction_stub_clp::Transaction_stub_clp ()
{
}

Bank::Transaction_stub_clp::Transaction_stub_clp (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
  : CORBA::Object(*obj), PortableServer::StubBase(poa)
{
}

Bank::Transaction_stub_clp::~Transaction_stub_clp ()
{
}

#endif // MICO_CONF_NO_POA

char* Bank::Transaction_stub::updateDetails( const char* _par_counterId, const char* _par_date, CORBA::Double _par_amountDebit, CORBA::Double _par_amountCredit, const char* _par_accountId )
{
  CORBA::StaticAny _sa_counterId( CORBA::_stc_string, &_par_counterId );
  CORBA::StaticAny _sa_date( CORBA::_stc_string, &_par_date );
  CORBA::StaticAny _sa_amountDebit( CORBA::_stc_double, &_par_amountDebit );
  CORBA::StaticAny _sa_amountCredit( CORBA::_stc_double, &_par_amountCredit );
  CORBA::StaticAny _sa_accountId( CORBA::_stc_string, &_par_accountId );
  char* _res = NULL;
  CORBA::StaticAny __res( CORBA::_stc_string, &_res );

  CORBA::StaticRequest __req( this, "updateDetails" );
  __req.add_in_arg( &_sa_counterId );
  __req.add_in_arg( &_sa_date );
  __req.add_in_arg( &_sa_amountDebit );
  __req.add_in_arg( &_sa_amountCredit );
  __req.add_in_arg( &_sa_accountId );
  __req.set_result( &__res );

  __req.invoke();

  mico_sii_throw( &__req, 
    0);
  return _res;
}


#ifndef MICO_CONF_NO_POA

char*
Bank::Transaction_stub_clp::updateDetails( const char* _par_counterId, const char* _par_date, CORBA::Double _par_amountDebit, CORBA::Double _par_amountCredit, const char* _par_accountId )
{
  PortableServer::Servant _serv = _preinvoke ();
  if (_serv) {
    POA_Bank::Transaction * _myserv = POA_Bank::Transaction::_narrow (_serv);
    if (_myserv) {
      char* __res;

      #ifdef HAVE_EXCEPTIONS
      try {
      #endif
        __res = _myserv->updateDetails(_par_counterId, _par_date, _par_amountDebit, _par_amountCredit, _par_accountId);
      #ifdef HAVE_EXCEPTIONS
      }
      catch (...) {
        _myserv->_remove_ref();
        _postinvoke();
        throw;
      }
      #endif

      _myserv->_remove_ref();
      _postinvoke ();
      return __res;
    }
    _postinvoke ();
  }

  return Bank::Transaction_stub::updateDetails(_par_counterId, _par_date, _par_amountDebit, _par_amountCredit, _par_accountId);
}

#endif // MICO_CONF_NO_POA

struct __tc_init_BANK {
  __tc_init_BANK()
  {
    _marshaller_Bank_Transaction = new _Marshaller_Bank_Transaction;
  }

  ~__tc_init_BANK()
  {
    delete static_cast<_Marshaller_Bank_Transaction*>(_marshaller_Bank_Transaction);
  }
};

static __tc_init_BANK __init_BANK;

//--------------------------------------------------------
//  Implementation of skeletons
//--------------------------------------------------------

// PortableServer Skeleton Class for interface Bank::Transaction
POA_Bank::Transaction::~Transaction()
{
}

::Bank::Transaction_ptr
POA_Bank::Transaction::_this ()
{
  CORBA::Object_var obj = PortableServer::ServantBase::_this();
  return ::Bank::Transaction::_narrow (obj);
}

CORBA::Boolean
POA_Bank::Transaction::_is_a (const char * repoid)
{
  if (strcmp (repoid, "IDL:Bank/Transaction:1.0") == 0) {
    return TRUE;
  }
  return FALSE;
}

CORBA::InterfaceDef_ptr
POA_Bank::Transaction::_get_interface ()
{
  CORBA::InterfaceDef_ptr ifd = PortableServer::ServantBase::_get_interface ("IDL:Bank/Transaction:1.0");

  if (CORBA::is_nil (ifd)) {
    mico_throw (CORBA::OBJ_ADAPTER (0, CORBA::COMPLETED_NO));
  }

  return ifd;
}

CORBA::RepositoryId
POA_Bank::Transaction::_primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr)
{
  return CORBA::string_dup ("IDL:Bank/Transaction:1.0");
}

CORBA::Object_ptr
POA_Bank::Transaction::_make_stub (PortableServer::POA_ptr poa, CORBA::Object_ptr obj)
{
  return new ::Bank::Transaction_stub_clp (poa, obj);
}

bool
POA_Bank::Transaction::dispatch (CORBA::StaticServerRequest_ptr __req)
{
  #ifdef HAVE_EXCEPTIONS
  try {
  #endif
    if( strcmp( __req->op_name(), "updateDetails" ) == 0 ) {
      CORBA::String_var _par_counterId;
      CORBA::StaticAny _sa_counterId( CORBA::_stc_string, &_par_counterId._for_demarshal() );
      CORBA::String_var _par_date;
      CORBA::StaticAny _sa_date( CORBA::_stc_string, &_par_date._for_demarshal() );
      CORBA::Double _par_amountDebit;
      CORBA::StaticAny _sa_amountDebit( CORBA::_stc_double, &_par_amountDebit );
      CORBA::Double _par_amountCredit;
      CORBA::StaticAny _sa_amountCredit( CORBA::_stc_double, &_par_amountCredit );
      CORBA::String_var _par_accountId;
      CORBA::StaticAny _sa_accountId( CORBA::_stc_string, &_par_accountId._for_demarshal() );

      char* _res;
      CORBA::StaticAny __res( CORBA::_stc_string, &_res );
      __req->add_in_arg( &_sa_counterId );
      __req->add_in_arg( &_sa_date );
      __req->add_in_arg( &_sa_amountDebit );
      __req->add_in_arg( &_sa_amountCredit );
      __req->add_in_arg( &_sa_accountId );
      __req->set_result( &__res );

      if( !__req->read_args() )
        return true;

      _res = updateDetails( _par_counterId.inout(), _par_date.inout(), _par_amountDebit, _par_amountCredit, _par_accountId.inout() );
      __req->write_results();
      CORBA::string_free( _res );
      return true;
    }
  #ifdef HAVE_EXCEPTIONS
  } catch( CORBA::SystemException_catch &_ex ) {
    __req->set_exception( _ex->_clone() );
    __req->write_results();
    return true;
  } catch( ... ) {
    CORBA::UNKNOWN _ex (CORBA::OMGVMCID | 1, CORBA::COMPLETED_MAYBE);
    __req->set_exception (_ex->_clone());
    __req->write_results ();
    return true;
  }
  #endif

  return false;
}

void
POA_Bank::Transaction::invoke (CORBA::StaticServerRequest_ptr __req)
{
  if (dispatch (__req)) {
      return;
  }

  CORBA::Exception * ex = 
    new CORBA::BAD_OPERATION (0, CORBA::COMPLETED_NO);
  __req->set_exception (ex);
  __req->write_results();
}

