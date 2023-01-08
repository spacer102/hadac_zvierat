#include <iostream>
#include <cctype>
#include "strom.h"

using namespace std;

bool mam_pokracovat(string txt) {
    char odpoved;
    string ano_nie;

    do
    {
        cin.ignore();
        cout<<txt<<endl;
        cin>>ano_nie;
        odpoved=tolower(ano_nie[0]);
        cout<<odpoved<<endl;
    }while((odpoved!='a') && (odpoved!='n'));
    return odpoved=='a';
}

int main()
{
    strom str;
cout<<"Vitaj!\nBudem hadat zvierata a ty odpovedaj na otazky"<<endl;

do
{
    string answer;
    string zviera=str.najdi();

    if(zviera!="nothing here") {
    cout<<"Je to "<<zviera<<" ?"<<endl;
    cin>>answer;
    }
    else {
        answer='n';
    }


    if(answer[0] != 'a') { str.pridaj();  }
    str.vyhladaj();

}while(mam_pokracovat("Mam hadat dalsie zviera? (ano/nie)"));
}
