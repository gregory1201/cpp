#include <cstdlib>
#include <iostream>
#include <cstdio>

using namespace std;

int tab[270000];
int wiel,ilosc_blokow,wys,szer,wynik;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> ilosc_blokow;
    for(int i=1;i<=ilosc_blokow;++i)
    {
        szer = 0;
        cin >> szer >> wys;
        while ((wiel>0)&&(tab[wiel-1]>wys))
        {
            wiel--;
        }
        if ((wiel==0)||(tab[wiel-1]<wys))
        {
            wynik++; 
            tab[wiel++]=wys;
        }
    }
    cout << wynik << "\n";
    return 0;
    system("pause");
}