package ComplexApp;


/**
* ComplexApp/Complex.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from ComplexIdl.idl
* Wednesday, November 23, 2016 2:30:27 PM WET
*/

public final class Complex implements org.omg.CORBA.portable.IDLEntity
{
  public double re = (double)0;
  public double im = (double)0;

  public Complex ()
  {
  } // ctor

  public Complex (double _re, double _im)
  {
    re = _re;
    im = _im;
  } // ctor

} // class Complex