import Bank.*;
import java.io.*;
import org.omg.CORBA.ORB;
import org.omg.CosNaming.*;
public class TransactionClient
{ static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
public static void main(String args[])
{
try{ ORB orb = ORB.init(args, null);
org.omg.CORBA.Object objRef =
orb.resolve_initial_references("NameService");
NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);
String name = "TRANSACTION";
Transaction transaction = TransactionHelper.narrow(ncRef.resolve_str(name));
System.out.println("Enter Counter ID:");
String counterId = in.readLine();
System.out.println("Enter the account ID:");
String accountId = in.readLine();
System.out.println("Enter debit amount:");
double debit = Integer.parseInt(in.readLine());
System.out.println("Enter Credit amount");
double credit = Integer.parseInt(in.readLine());
//double credit =125.63;
System.out.println("Enter date of transaction");
String date = in.readLine();
/*String counterId ="10";
String accountId = "15";
double debit = 200.53;
double credit =125.63;
String date = "12/05/2012";*/
String status = transaction.updateDetails(counterId,date,debit,credit,accountId);
System.out.println("Status of operation:" + status); }
catch(Exception e)
{System.out.println(e); } }
}
