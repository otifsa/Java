#include <CORBA.h>
#include <coss/CosNaming.h>
#include <bank.h>
#include<string.h>
using namespace std;
int
main (int argc, char *argv[])
{
  // ORB initialization
  CORBA::ORB_var orb = CORBA::ORB_init (argc, argv);

  /*
   * In demo/poa/hello-1, the object reference comes from a file via
   * the "file://" object URL. Here, we retrieve the reference from the
   * Naming Service
   */
  
  /*
   * Acquire a reference to the Naming Service
   */

    CORBA::Object_var nsobj =orb->resolve_initial_references ("NameService");

    CosNaming::NamingContext_var nc = CosNaming::NamingContext::_narrow (nsobj);

  if (CORBA::is_nil (nc)) {
    cerr << "oops, I cannot access the Naming Service!" << endl;
    exit (1);
  }

  /*
   * Construct Naming Service name for our Bank
   */

  CosNaming::Name name;
  name.length (1);
  name[0].id = CORBA::string_dup ("TRANSACTION");
  name[0].kind = CORBA::string_dup ("");
  
  /*
   * try to find that node in the Naming Service tree
   */

  CORBA::Object_var obj;

  cout << "Looking up Hello ... " << flush;

#ifdef HAVE_EXCEPTIONS
  try {
    obj = nc->resolve (name);
  }
  catch (CosNaming::NamingContext::NotFound &exc) {
    cout << "NotFound exception." << endl;
    exit (1);
  }
  catch (CosNaming::NamingContext::CannotProceed &exc) {
    cout << "CannotProceed exception." << endl;
    exit (1);
  }
  catch (CosNaming::NamingContext::InvalidName &exc) {
    cout << "InvalidName exception." << endl;
    exit (1);
  }
#else
  obj = nc->resolve (name);
#endif

  cout << "done." << endl;

  /*
   * The Naming Service returns a generic reference as a CORBA::Object
   * We need to narrow this to the desired type
   */
Bank::Transaction_var client= Bank::Transaction::_narrow (obj);

  if (CORBA::is_nil (client)) {
    printf ("oops: Transaction is nil\n");
    exit (1);
  }
	
	char counterId[20],accountId[20],date[20];
	double debit,credit;
	cout<<"Enter Counter ID:"<<endl;
	cin>>counterId;
	cout<<"Enter the account ID:"<<endl;
	cin>>accountId;
	cout<<"Enter debit amount:"<<endl;
	cin>>debit;
	cout<<"Enter Credit amount:"<<endl;
	cin>>credit;
	cout<<"Enter date of transaction:"<<endl;
	cin>>date;
	
        string status=client->updateDetails(counterId,date,debit,credit,accountId);
 	      cout<<status<<endl;
  

  return 0;
}
