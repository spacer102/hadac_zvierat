#include <iostream>
#include "strom.h"
#include <limits>
#include <string>
#include <cstddef>

using namespace std;

strom::strom()
{
    koren = new uzol("rohy",true,nullptr,nullptr);
    koren->ma=new uzol("vol",false,nullptr,nullptr);
    koren->nema=new uzol("zaba",false,nullptr,nullptr);
}

strom::~strom()
{
    vyprazdni(koren);
}

void strom::vyprazdni(uzol *p)
{
    if(koren==nullptr) return;
    vyprazdni(koren->ma);
    vyprazdni(koren->nema);
    delete koren;
}

void strom::vyprazdni()
{
    vyprazdni(koren);
    koren=nullptr;
}

string strom::najdi()
{
    aktualny=koren;
    while(aktualny->otazka )
    {
        cout<<"Ma to zviera "<<aktualny->znak<<" ?"<<endl;
        string odpoved;
        cin>>odpoved;
        aktualny = odpoved[0] == 'a' ?  aktualny->ma: aktualny->nema;
        if(aktualny==nullptr) {cout<<"nothing here"<<endl;return "nothing here";}
    }
    return aktualny->znak;
}

void strom::pridaj()
{
    cin.ignore();
    cout<<"A co to potom je? ";
    string zviera;
    getline(cin, zviera);
    cout<<"cim sa odlisuje? "<<zviera<<endl;
    string rozdiel;
    getline(cin, rozdiel);
    cout<<zviera<<" ma "<< rozdiel<<" ? ";
    string odpoved;
    cin>>odpoved;
    cin.ignore();

    if(aktualny!=nullptr) {
    if(odpoved[0]=='a') {
        aktualny->nema= new uzol(*aktualny);
        aktualny->ma=new uzol(zviera,false,nullptr,nullptr);
    }
    else {
        aktualny->ma=new uzol(*aktualny);
        aktualny->nema= new uzol(zviera,false,nullptr,nullptr);
    }
    aktualny->otazka=true;
    aktualny->znak=rozdiel;}

}
    void strom::vyhladaj()
    {
        aktualny=koren;
        cout<<"Zadaj nazov veci ku ktorej chces pristupovat: "<<endl;
        string zmen;
        cin>>zmen;
        vyhladaj_prvok(aktualny,zmen);
    }

    void strom::zrus(uzol *p) {
        if(p==nullptr) {return;}
        if(p->ma != nullptr) {zrus(p->ma);}
        if(p->nema != nullptr) {zrus(p->nema);}

        delete p;
    }

    int strom::vymaz(uzol *p, uzol *k) {
        //cout<<k->znak<<endl<<p->znak<<endl;
        if(k->znak==p->znak) {cout<<"tusom a vymazujem"<<endl;cout<<"ideme zmazat: "<<k->znak<<endl;zrus(k); k=nullptr; cout<<"hotovo"<<endl;return 3;cout<<"koniec"<<endl;}
        if(k->ma!=nullptr) {cout<<"tu"<<endl;vymaz(p,k->ma);}
        if(k->nema!=nullptr) {cout<<"vymazujem"<<endl;vymaz(p,k->nema);}
    }

    void strom::vyhladaj_prvok(uzol *v, string z) {
       /* if(v->znak!=z) {
            aktualny=v;
        }*/
        if(v!=nullptr) {
        cout<<v->znak<<" =>"<<v->otazka<<endl;

        if(z==v->znak) {
            cout<<"Co chces urobit?\n1.vymazat\n2.upravit\n3.zpet "<<endl;
            int a;
            cin>>a;

            switch(a) {
            case 1:
                cout<<vymaz(v, koren)<<endl;
                return;
            case 2:
                cout<<"Zadaj novy znak alebo nazov zvierata: "<<endl;
                string b;
                cin>>b;
                v->znak=b;
                return;
            }
            return;
        }

        if(v->ma!=nullptr) {vyhladaj_prvok(v->ma,z);}
        if(v->nema!=nullptr) {vyhladaj_prvok(v->nema,z);}
        }
    }
