package Bank;

/**
* Bank/TransactionHolder.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from bank.idl
* Thursday, November 24, 2016 11:42:16 AM WET
*/

public final class TransactionHolder implements org.omg.CORBA.portable.Streamable
{
  public Bank.Transaction value = null;

  public TransactionHolder ()
  {
  }

  public TransactionHolder (Bank.Transaction initialValue)
  {
    value = initialValue;
  }

  public void _read (org.omg.CORBA.portable.InputStream i)
  {
    value = Bank.TransactionHelper.read (i);
  }

  public void _write (org.omg.CORBA.portable.OutputStream o)
  {
    Bank.TransactionHelper.write (o, value);
  }

  public org.omg.CORBA.TypeCode _type ()
  {
    return Bank.TransactionHelper.type ();
  }

}
