#ifndef STROM_H_INCLUDED
#define STROM_H_INCLUDED

#include <string>
using namespace std;

class uzol
{
public:
    string znak;
    uzol *ma, *nema;
    bool otazka;

    uzol(string _znak, bool _otazka, uzol *_ma, uzol *_nema)
    {
        znak=_znak;
        otazka=_otazka;
        ma=_ma;
        nema=_nema;
    }
};

class strom
{
public:
    strom();
    ~strom();
    string najdi();
    void vyprazdni();
    void pridaj();
    void vyhladaj_prvok(uzol *prvok, string znak);
    void vyhladaj();
    void zrus(uzol *p);
    int vymaz(uzol *p, uzol *k);

private:
    uzol *koren, *aktualny;
    void vyprazdni(uzol *koren);
};

#endif // STROM_H_INCLUDED
