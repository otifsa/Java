import ComplexApp.*;
import java.util.Properties;  
import org.omg.CosNaming.*; // HelloServer will use the naming service. 
import org.omg.CosNaming.NamingContextPackage.*; // ..for exceptions. 
import org.omg.CORBA.*;     // All CORBA applications need these classes. 
import org.omg.PortableServer.*;   
import org.omg.PortableServer.POA;

 public class ComplexServant extends ComplexIntPOA{

	private ORB orb;

    public void setORB(ORB orb_val) {
	orb = orb_val;
    }

	public Complex AddComplex(Complex a,Complex b){

		return new Complex(a.re+b.re,a.im+b.im);
				}

}
