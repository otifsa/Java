import Bank.*;
import java.sql.*;
import java.util.Properties;
import org.omg.CORBA.ORB;
import org.omg.CosNaming.*;
import org.omg.PortableServer.*; 
import org.omg.PortableServer.POA;  

public class TransactionServer extends TransactionPOA
{  static int transactionId = 11;
  private ORB orb;
  String name;
  
 public void setORB(ORB orb_val) {orb = orb_val; }
 public String updateDetails (String counterId, String date, double amountDebit, double amountCredit, String accountId)
  {
try{ transactionId += 1;
      int id_= transactionId;
      Class.forName("com.mysql.jdbc.Driver");
      Connection con = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/corba","oti", "fsa");                   
      PreparedStatement st = con.prepareStatement("insert into c_transaction  values(?,?,?,?,?,?)");
      Statement st1=con.createStatement();  
      ResultSet rs=st1.executeQuery("select max(id) from c_transaction");  
      rs.next();
      int a=rs.getInt(1);
	a++;
      st.setInt(1,a);
      st.setString(2,counterId);
      st.setString(3,date);
      st.setDouble(4,amountDebit);
      st.setDouble(5,amountCredit);
      st.setString(6,accountId);
      st.executeUpdate();   }
      catch(Exception e)
      {System.out.println(e); }   
      return "Operation successful";
  }
   public static void main(String args[])
   {
        Properties properties = System.getProperties();
    	properties.put("org.omg.CORBA.ORBInitialHost", "localhost");
    	properties.put("org.omg.CORBA.ORBInitialPort", "1050");

        try{
        ORB orb = ORB.init(args, null);  // -1-
	    POA rootpoa = POAHelper.narrow(orb.resolve_initial_references("RootPOA"));  
	    rootpoa.the_POAManager().activate(); 

	    TransactionServer transaction = new TransactionServer();
             transaction.setORB(orb);  
             org.omg.CORBA.Object ref = rootpoa.servant_to_reference(transaction);
	    	Transaction href = TransactionHelper.narrow(ref);

	    org.omg.CORBA.Object objRef = orb.resolve_initial_references("NameService");
	    NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);

	    String name = "TRANSACTION";
	    NameComponent path[] = ncRef.to_name(name);
	    ncRef.rebind(path, href);
	    System.out.println("Server Ready ");
	    orb.run();
            
             Object waitForCall = new Object();
             synchronized(waitForCall)
             {waitForCall.wait();      }      }
        catch(Exception e)
        {	System.out.println(e);  }  }}
