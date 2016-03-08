#ifndef PLIK_HPP_
#define PLIK_HPP_
#include<vector>
#include<string>
class Base 
{
  public:
  std::string Display;
  virtual void wypisz ();
};
class Klient : public Base
{
  public:
  bool status;
  bool statusSledzony;
  bool statusSerwera;
  void wlaczKlienta();
  void wylaczKlienta();
   void wypisz ();
  
  
};
class Serwer : public Base
{
  protected:
  Serwer ();
  Serwer (Serwer & a);
  Serwer (Serwer && other);
  static Serwer * instance;
  public:
  bool status; 
  std::vector <Klient*> listaKlientow;
  void ustaw (bool a);
  void dodajKlienta (Klient &  client);
  void wylaczSerwer ();
  void wlaczSerwer ();
  static Serwer * getInstance ();
  void wypisz ();
  
};









#endif