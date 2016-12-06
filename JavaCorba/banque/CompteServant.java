import Banque.*;
import java.util.Properties;  
import org.omg.CosNaming.*; // HelloServer will use the naming service. 
import org.omg.CosNaming.NamingContextPackage.*; // ..for exceptions. 
import org.omg.CORBA.*;     // All CORBA applications need these classes. 
import org.omg.PortableServer.*;   
import org.omg.PortableServer.POA;

 public class CompteServant extends CompteIntPOA{

	private ORB orb;
	private Compte c=new Compte();

    public void setORB(ORB orb_val) {orb = orb_val;}

	public int getCode(){return c.getCode();}
	public float getSolde(){return c.getSolde();}
	public void retirer(float mt){c.retirer(mt);}
	public void verser(float mt){c.verser(mt);}

}
