class Compte{
public int nbComptes=0;
private float solde;
private int code;
public Compte(){
nbComptes++;
code=nbComptes;
solde=0;}
public int getCode(){return code;}
public float getSolde(){return
solde; }
public void retirer(float mt){solde-=mt;}
public void verser(float mt)
{solde+=mt;}
}
