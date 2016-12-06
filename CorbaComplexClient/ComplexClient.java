import ComplexApp.*;          // The package containing our stubs
import org.omg.CosNaming.*; // HelloClient will use the naming service.
import org.omg.CosNaming.NamingContextPackage.*;
import org.omg.CORBA.*;     // All CORBA applications need these classes.

public class ComplexClient
{
    static ComplexInt complex;
    
    public static void main(String args[])
    {
		Complex a,b,c;
	try {
		a=new Complex(1,2);
		b=new Complex(3,4);
	    ORB orb = ORB.init(args, null);
	    org.omg.CORBA.Object objRef = 
                     orb.resolve_initial_references("NameService");
	    NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);

	    String name = "complex";
	    complex = ComplexIntHelper.narrow(ncRef.resolve_str(name));

	    System.out.println("Got a handle on the server object: " + complex);
		c=complex.AddComplex(a,b);
	  System.out.println("re: " +c.re+" im: "+c.im);
 
}
  catch (Exception e){}
}
}
