#include "plik.hpp"
#include <vector>
#include <string>
#include<iostream>
using namespace std;

//virtual void Base::wypisz () =0;
void Klient::wlaczKlienta()
{
   if (status==0 && statusSerwera ==1)
     {
      status =1;
      Display="wlaczam klienta";
      
     }
     if (status == 0 && statusSerwera ==0)
     {
      statusSledzony=1;
       Display="wlaczam klienta ale serwer wylaczony sledze";
     
     }
}
void Klient::wylaczKlienta ()
{
  if (status==1 && statusSerwera==1)
     {
     statusSledzony=status;  
     status=0;
     Display="wylaczam klienta";
     
     }
}

 void Klient::wypisz ()
{
  if (Display!="")
   {
    cout<<Display<<endl;
   }
 Display="";
}
Serwer::Serwer (Serwer & serw)
{
}
Serwer::Serwer ()
{
}
Serwer::Serwer (Serwer && other)
{
}
void Serwer::ustaw (bool a)
{
 status=a; 
}
void Serwer::dodajKlienta (Klient & client)
{
 cout<<"dodaje Klienta"<<endl;
 client.statusSerwera=status;
 client.statusSledzony=0;
 listaKlientow.push_back(&client);
}
void Serwer::wylaczSerwer ()
{
  if(status==1)
   {
     for (int i=0;i<listaKlientow.size();i++)
     { 
	listaKlientow[i]->wylaczKlienta();
	listaKlientow[i]->statusSerwera=0;
	listaKlientow[i]->statusSledzony=0;
     }
   status=0;
   Display = "Wylaczam serwer :";
   }
}
void Serwer::wlaczSerwer ()
{
   if(status==0)
   {
      Display="wlaczam serwer";
     status=1;
     for (int i=0;i<listaKlientow.size();i++)
     {
       listaKlientow[i]->statusSerwera=1;
       if(listaKlientow[i]->statusSledzony==1)
       { 
	listaKlientow[i]->wlaczKlienta();
       }
     }
   }
}
static Serwer * Serwer::getInstance ()
{
  if (instance==NULL)
   {
    instance = new Serwer; 
   }
   return instance;
}
 void Serwer::wypisz()
{
   if (Display!="")
   {
    cout<<Display<<endl;
   }
  Display="";
 }
Serwer* Serwer::instance =0;
