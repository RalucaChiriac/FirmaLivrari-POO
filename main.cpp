#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
ifstream in("tastatura.txt");

class Produs
{
    char *nume;
    float pret;
    int nr_bucati;
public:
    ///constructori initializare
    Produs(char*, float, int);
    Produs();
    Produs(bool);
    ///destructor
    ~Produs()
    {
        delete[] nume;
    }
    ///constructor copiere
    Produs(const Produs&);
    ///get si set
    float get_pret()
    {
        return pret;
    }
    int get_nr_bucati()
    {
        return nr_bucati;
    }
    void set_nr_bucati(int x)
    {
        nr_bucati=x;
    }
    char* get_nume()
    {
        return nume;
    }
    ///operator de copiere
    Produs& operator=(Produs&);
    ///functie afisare
    void afis()
    {
        cout<<nume<<" "<<pret<<" "<<nr_bucati<<endl;
    }
    ///operator de afisare
    friend ostream &operator<<(ostream&, const Produs&);
    ///operator de citire
    friend istream &operator>>(istream &, Produs &);
};
Produs::Produs():nr_bucati(0), pret(0)
{
    nume=new char(50);
}
Produs::Produs(char* prod, float p, int nr)
{
    nume=new char(50);
    strcpy(nume, prod);
    pret=p;
    nr_bucati=nr;
}
Produs::Produs(const Produs& p)
{
    nume=new char(50);
    strcpy(this->nume, p.nume);
    this->pret=p.pret;
    this->nr_bucati=p.nr_bucati;
}
Produs::Produs (bool b)
{
    nume=new char(50);
    if(b==true)
    {
        cin.getline(nume, 50);
        cin>>nr_bucati>>pret;
    }
    else
    {
        in.getline(nume, 50);
        in>>nr_bucati>>pret;
    }
}
Produs& Produs::operator=(Produs& ob)
{
    if(this!=&ob)
    {
        this->nume=new char[strlen(ob.nume)+1];
        strcpy(this->nume, ob.nume);
        this->pret=ob.pret;
        this->nr_bucati=ob.nr_bucati;
    }
    return *this;
}

ostream &operator<<(ostream& out, const Produs &p)
{
    cout<<p.nume<<endl;
    cout<<p.nr_bucati<<" "<<p.pret<<endl;
    return out;
}
istream &operator>>(istream &in, Produs &p)
{
    cin.getline(p.nume, 50);
    cin>>p.nr_bucati>>p.pret;
    return in;
}

class Comanda
{
    int id, nr_prod;
    string magazin, status;
    float suma_plata;
    Produs p[20];
public:
    ///constructori initializare
    Comanda();
    Comanda(int, string);
    ///destructor
    ~Comanda()
    {}
    ///get si set
    string get_status()
    {
        return status;
    }
    void set_status(string s)
    {
        status = s;
    }
    void set_suma_plata()
    {
        suma_plata=0;
    }
    int get_nr_prod()
    {
        return nr_prod;
    }
    Produs get_prod(int i)
    {
        return p[i];
    }
    ///operator afisare
    friend ostream &operator<<(ostream&, const Comanda&);
};

Comanda::Comanda():suma_plata(0), nr_prod(0)
{
    magazin="";
    status="";
    id=rand()%100;
}

Comanda::Comanda(int nr, string m):suma_plata(0), nr_prod(0)
{
    magazin="";
    status="";
    id=nr;
    magazin = m;
    status = "Adauga produse";
}


class Client
{
    char* nume_prenume, *adresa, *tel;
public:
    ///constructori initializare
    Client();
    Client(char*, char*, char*);
    ///destructor
    ~Client(){}
    ///operator afisare
    friend ostream &operator<<(ostream&, const Client&);
    ///operator citire
    friend istream &operator>>(istream &, Client &);

};

Client::Client()
{
    nume_prenume=new char[50];
    adresa=new char[50];
    tel=new char[50];
}
Client::Client(char* np, char* adr, char* t)
{
    nume_prenume=new char[50];
    adresa=new char[50];
    tel=new char[50];
    strcpy(nume_prenume, np);
    strcpy(adresa, adr);
    strcpy(tel, t);
}

int main()
{
    return 0;
}
