import Banque.*;
import org.omg.CosNaming.*; // HelloClient will use the naming service.
import org.omg.CosNaming.NamingContextPackage.*;
import org.omg.CORBA.*;     // All CORBA applications need these classes.

public class CompteClient
{
    static CompteInt compte;
    
    public static void main(String args[])
    {
		
	try {
		
	    ORB orb = ORB.init(args, null);
	    org.omg.CORBA.Object objRef = 
                     orb.resolve_initial_references("NameService");
	    NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);

	    String name = "compte";
	    compte = CompteIntHelper.narrow(ncRef.resolve_str(name));

	    //System.out.println("Got a handle on the server object: " + compte);
		compte.verser(1000);
	    System.out.println("le code "+compte.getCode());
	    System.out.println("le solde "+compte.getSolde());
 
}
  catch (Exception e){}
}
}
