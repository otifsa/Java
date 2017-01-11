package oti.fsa.ma.Actions;

import java.util.Properties;

import org.omg.CORBA.ORB;
import org.omg.CosNaming.NamingContextExt;
import org.omg.CosNaming.NamingContextExtHelper;

import com.opensymphony.xwork2.ActionSupport;

import Bank.Transaction;
import Bank.TransactionHelper;

public class TransactionAction extends ActionSupport{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private String counterId,accountId,date;
	private double debit,credit;
	private String result;
	
	public String execute (){
		String args[]=null;
		Properties props = new Properties();
    	props.put("org.omg.CORBA.ORBInitialHost","127.0.0.1");
    	props.put("org.omg.CORBA.ORBInitialPort","1050");
	    ORB orb; 

       try{ orb = ORB.init(args, props);
	    org.omg.CORBA.Object objRef = 
            orb.resolve_initial_references("NameService");
	    NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);

	    String name = "TRANSACTION";
	    Transaction transaction = TransactionHelper.narrow(ncRef.resolve_str(name));
	    String status = transaction.updateDetails(counterId,date,debit,credit,accountId);
        System.out.println("Status of operation:" + status);       }
    catch(Exception e)
    {System.out.println(e);   }   
		
		return "ok";
       
	}


	public String getCounterId() {
		return counterId;
	}

	public void setCounterId(String counterId) {
		this.counterId = counterId;
	}

	public String getAccountId() {
		return accountId;
	}

	public void setAccountId(String accountId) {
		this.accountId = accountId;
	}

	public String getDate() {
		return date;
	}

	public void setDate(String date) {
		this.date = date;
	}

	public double getDebit() {
		return debit;
	}

	public void setDebit(double debit) {
		this.debit = debit;
	}

	public double getCredit() {
		return credit;
	}

	public void setCredit(double credit) {
		this.credit = credit;
	}

	public String getResult() {
		return result;
	}

	public void setResult(String result) {
		this.result = result;
	}
	
	

	
}
