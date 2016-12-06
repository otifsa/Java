import HelloApp.*;          // The package containing our stubs. 
import java.util.Properties;  
import org.omg.CosNaming.*; // HelloServer will use the naming service. 
import org.omg.CosNaming.NamingContextPackage.*; // ..for exceptions. 
import org.omg.CORBA.*;     // All CORBA applications need these classes. 
import org.omg.PortableServer.*;   
import org.omg.PortableServer.POA;

public class HelloServer 
{
    public static void main(String args[]) 
    {
    	Properties properties = System.getProperties();
    	properties.put("org.omg.CORBA.ORBInitialHost", "localhost");
    	properties.put("org.omg.CORBA.ORBInitialPort", "1050");

	try { 
	    ORB orb = ORB.init(args, null);  // -1-

	    POA rootpoa = POAHelper.narrow(orb.resolve_initial_references("RootPOA"));  
	    rootpoa.the_POAManager().activate(); 

	    HelloServant helloImpl = new HelloServant();
	    helloImpl.setORB(orb);  

	    org.omg.CORBA.Object ref = rootpoa.servant_to_reference(helloImpl);
	    Hello href = HelloHelper.narrow(ref);
	    org.omg.CORBA.Object objRef = 
		           orb.resolve_initial_references("NameService");
	    NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);

	    String name = "Hello";
	    NameComponent path[] = ncRef.to_name(name);
	    ncRef.rebind(path, href);
	    System.out.println("Server Ready ");
	    orb.run();
	}
	    
	catch(Exception e) {
	    System.err.println("ERROR : " + e);
	    e.printStackTrace(System.out);
	}
    }
}
