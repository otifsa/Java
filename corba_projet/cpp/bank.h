/*
 *  MICO --- an Open Source CORBA implementation
 *  Copyright (c) 1997-2006 by The Mico Team
 *
 *  This file was automatically generated. DO NOT EDIT!
 */

#include <CORBA.h>
#include <mico/throw.h>

#ifndef __BANK_H__
#define __BANK_H__






namespace Bank
{

class Transaction;
typedef Transaction *Transaction_ptr;
typedef Transaction_ptr TransactionRef;
typedef ObjVar< Transaction > Transaction_var;
typedef ObjOut< Transaction > Transaction_out;

}






namespace Bank
{


/*
 * Base class and common definitions for interface Transaction
 */

class Transaction : 
  virtual public CORBA::Object
{
  public:
    virtual ~Transaction();

    #ifdef HAVE_TYPEDEF_OVERLOAD
    typedef Transaction_ptr _ptr_type;
    typedef Transaction_var _var_type;
    #endif

    static Transaction_ptr _narrow( CORBA::Object_ptr obj );
    static Transaction_ptr _narrow( CORBA::AbstractBase_ptr obj );
    static Transaction_ptr _duplicate( Transaction_ptr _obj )
    {
      CORBA::Object::_duplicate (_obj);
      return _obj;
    }

    static Transaction_ptr _nil()
    {
      return 0;
    }

    virtual void *_narrow_helper( const char *repoid );

    virtual char* updateDetails( const char* counterId, const char* date, CORBA::Double amountDebit, CORBA::Double amountCredit, const char* accountId ) = 0;

  protected:
    Transaction() {};
  private:
    Transaction( const Transaction& );
    void operator=( const Transaction& );
};

// Stub for interface Transaction
class Transaction_stub:
  virtual public Transaction
{
  public:
    virtual ~Transaction_stub();
    char* updateDetails( const char* counterId, const char* date, CORBA::Double amountDebit, CORBA::Double amountCredit, const char* accountId );

  private:
    void operator=( const Transaction_stub& );
};

#ifndef MICO_CONF_NO_POA

class Transaction_stub_clp :
  virtual public Transaction_stub,
  virtual public PortableServer::StubBase
{
  public:
    Transaction_stub_clp (PortableServer::POA_ptr, CORBA::Object_ptr);
    virtual ~Transaction_stub_clp ();
    char* updateDetails( const char* counterId, const char* date, CORBA::Double amountDebit, CORBA::Double amountCredit, const char* accountId );

  protected:
    Transaction_stub_clp ();
  private:
    void operator=( const Transaction_stub_clp & );
};

#endif // MICO_CONF_NO_POA

}


#ifndef MICO_CONF_NO_POA



namespace POA_Bank
{

class Transaction : virtual public PortableServer::StaticImplementation
{
  public:
    virtual ~Transaction ();
    Bank::Transaction_ptr _this ();
    bool dispatch (CORBA::StaticServerRequest_ptr);
    virtual void invoke (CORBA::StaticServerRequest_ptr);
    virtual CORBA::Boolean _is_a (const char *);
    virtual CORBA::InterfaceDef_ptr _get_interface ();
    virtual CORBA::RepositoryId _primary_interface (const PortableServer::ObjectId &, PortableServer::POA_ptr);

    virtual void * _narrow_helper (const char *);
    static Transaction * _narrow (PortableServer::Servant);
    virtual CORBA::Object_ptr _make_stub (PortableServer::POA_ptr, CORBA::Object_ptr);

    virtual char* updateDetails( const char* counterId, const char* date, CORBA::Double amountDebit, CORBA::Double amountCredit, const char* accountId ) = 0;

  protected:
    Transaction () {};

  private:
    Transaction (const Transaction &);
    void operator= (const Transaction &);
};

}


#endif // MICO_CONF_NO_POA

extern CORBA::StaticTypeInfo *_marshaller_Bank_Transaction;

#endif
