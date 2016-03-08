#include "plik.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int  main ()
{
  
  Serwer * ws;
  Serwer::getInstance()->status=0;
  Klient * wskKlient;
  Base * wsk ;
  int ktorego;
  int coWykonac;
  cout<<"serwer jest wylaczony  "<<endl;
  while (1)
  {
   cout<<"wcisnij 0 by wylaczyc serwer"<<endl;
   cout<<"wcisni 1 by wlaczyc serwer "<<endl;
    cout<<"wcisnij 2 by wylaczyc klienta"<<endl;
   cout<<"wcisni 3 by wlaczyc klienta "<<endl;
   cout<<"wcisnij 4 by dodac klienta"<<endl;
   cin >>coWykonac;
   switch(coWykonac)
   {
       case 0:
        wsk = Serwer::getInstance();
        Serwer::getInstance()->wylaczSerwer();
        wsk->wypisz();
	for (int i=0;i<Serwer::getInstance()->listaKlientow.size();i++)
	{
	 wsk=Serwer::getInstance()->listaKlientow[i];
	 wsk->wypisz();
	}
       break;
       case 1:
	wsk = Serwer::getInstance();
        Serwer::getInstance()->wlaczSerwer();
        wsk->wypisz();
	for (int i=0;i<Serwer::getInstance()->listaKlientow.size();i++)
	{
	 wsk=Serwer::getInstance()->listaKlientow[i];
	 wsk->wypisz();
	}
       break;
       case 2:
	cout<<"ktorego ?"<<endl;
        cin>>ktorego;
	wsk= Serwer::getInstance()->listaKlientow[ktorego];
	Serwer::getInstance()->listaKlientow[ktorego]->wylaczKlienta();
	wsk->wypisz();
       break;
       case 3:
	cout<<"ktorego ?"<<endl;
        cin>>ktorego;
	wsk= Serwer::getInstance()->listaKlientow[ktorego];
	Serwer::getInstance()->listaKlientow[ktorego]->wlaczKlienta();
	wsk->wypisz();
       break;
       case 4:
	 wskKlient = new Klient;
	 wskKlient->statusSledzony=0;
	 Serwer::getInstance()->dodajKlienta(*wskKlient);
	 break;
       default:
	 cout<<"cos nietak"<<endl;
	 break;
   }
    
  }
  
  
}