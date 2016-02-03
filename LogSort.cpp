/*
 * LogSort.cpp
 *
 *  Created on: Jan 20, 2016
 *      Author: p637
 */
#include "LogSort.hpp"
#include <regex.h>
#include <vector>
#include <time.h>
#include<sys/time.h>
#include <string>
#include<iostream>
#include <stdlib.h>
#include<stdio.h>
#include <string.h>
#include <string>
#include <sys/types.h>
#include<fstream>


using namespace std;

void LogSort:: Preprocess (string formula , long LineNumber)
	{

	
	
	  long long int * IntWynik=0;
	  bool IFmatch=0;
	  string wynik;
	  wynik.resize(17);
	  int com=6;
	 
	  if (formula[com]=='[' && formula[com+24] == ']')
	  {
	    wynik[0]=formula[com+1];
	    wynik[1]=formula[com+2];
	     wynik[2]=formula[com+3];
	    wynik[3]=formula[com+4];
	    
	    wynik[4]=formula[com+6];
	    wynik[5]=formula[com+7];
	    
	    wynik[6]=formula[com+9];
	    wynik[7]=formula[com+10];
	    
	    wynik[8]=formula[com+12];
	    wynik[9]=formula[com+13];
	    
	    wynik[10]=formula[com+15];
	    wynik[11]=formula[com+16];
	    
	     wynik[12]=formula[com+18];
	    wynik[13]=formula[com+19];
	    
	    wynik[14]=formula[com+21];
	    wynik[15]=formula[com+22];
	    wynik[16]=formula[com+23];
	    IFmatch=1;
	    
	  }
	 else {
	    com++;
	    while(com+24<formula.length())
	    {
	    if (formula[com]=='[' && formula[com+24] == ']')
	    {
	          wynik[0]=formula[com+1];
	    wynik[1]=formula[com+2];
	     wynik[2]=formula[com+3];
	    wynik[3]=formula[com+4];
	    
	    wynik[4]=formula[com+6];
	    wynik[5]=formula[com+7];
	    
	    wynik[6]=formula[com+9];
	    wynik[7]=formula[com+10];
	    
	    wynik[8]=formula[com+12];
	    wynik[9]=formula[com+13];
	    
	    wynik[10]=formula[com+15];
	    wynik[11]=formula[com+16];
	    
	     wynik[12]=formula[com+18];
	    wynik[13]=formula[com+19];
	    
	    wynik[14]=formula[com+21];
	    wynik[15]=formula[com+22];
	    wynik[16]=formula[com+23];
	    IFmatch=1;
	 
	    }
	    com++;
	    }    
	  }
	  if (!IFmatch)
	  {
		container[iter]++;
		
	  }
	  if (IFmatch)
	  {
		  ptr=new IntStruct;
		ptr->a=atoll(wynik.c_str());
		ptr->line=LineNumber;
		LineContainer.push_back(ptr);
		container.push_back(0);
		iter++;
	  }
	
	 
	  
      
	}
void LogSort:: Sort( int lewy, int prawy)
{

 long long int v=LineContainer[(lewy+prawy)/2]->a;
 
int i;
int j;
int x;

i=lewy;
j=prawy;
do
{
while
 (LineContainer[i]->a<v) 
 {  
   i++;
 }
while
 (LineContainer[j]->a>v) 
 {
   j--;
 }
 if (i<=j)
 { 
   long long int p= LineContainer[i]->a;
     long long int e= LineContainer[i]->line;
     short int g=container[i];
			LineContainer[i]->a=LineContainer[j]->a;
			LineContainer[j]->a=p;
			
			container[i]=container[j];
			container[j]=g;
			
			LineContainer[i]->line=LineContainer[j]->line;
			LineContainer[j]->line=e;
			j--;
			i++;			
 }
}while(i<=j);
if (j>lewy) Sort (lewy,j);
  if (i<prawy) Sort (i,prawy);

}

void LogSort::WriteToFile()
{

	ofstream NewFile ("Sort");
	fstream  File;
	File.open(nameOfFile.c_str(),fstream::in| fstream::out);
	if (File.is_open())
	{
	for (unsigned int i=0;i<container.size();i++)
	{
	  
      NewFile<<GetStringLine(LineContainer[i]->line,File,i,NewFile)<<endl;
	}
	}
	else cout<<"Can not open file"<<endl;
}
string LogSort:: GetStringLine(int LineNumber, fstream & File,int i,ofstream & New)
{
	short int y;

	string b;
    string a;
 
   File.seekp(LineNumber);
   getline (File, a);
    
    while (container[i]>0)
    {
    	getline(File,b);
        y=a.length();
        a.resize(y+1);
    	a[y]='\n';
        a=a+b;
    	container[i]--;
    }
    File.clear();
    File.seekg(0,File.beg);
    currentLine=0;
    return a;
}
void LogSort::Log(string name)
{

 	   iter=-1;
	p=-1;
    NonLine=0;
	nameOfFile=name;
	currentLine=0;
}

