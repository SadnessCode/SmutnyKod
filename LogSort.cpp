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

void LogSort:: Preprocess (string formula , int LineNumber)
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
		 ptr=new LogSort::Line;
	//	 * LinePtr->a=atoll(wynik.c_str());
	  }
	  if (IFmatch)
	  {
	//	  LinePtr = new Line ;
	//	*LinePtr->a=atoll(wynik.c_str());
	  }
	 // LineContainer.push_back(&LinePtr);
      
	}
void LogSort:: Sort()
{
	/*
for (unsigned int i=0;i<LineContainer.size()-1;i++)
{
	for (unsigned int j=0;j<LineContainer.size()-i-1;j++)
	{
		if (*LineContainer[j].a>*LineContainer[j+1].a)
		{
			long long int * y=LineContainer[j];
			LineContainer[j]=LineContainer[j+1];
			LineContainer[j+1]=y;
			
		}
	}
	*/

}
/*
void LogSort::WriteToFile()
{

	ofstream NewFile ("Sort");
	fstream  File;
	File.open(nameOfFile.c_str(),fstream::in| fstream::out);
	if (File.is_open())
	{
	for (unsigned int i=0;i<container.size();i++)
	{
      NewFile<<GetStringLine(LineContainer[i],File,i,NewFile)<<endl;
	}
	}
	else cout<<"Can not open file"<<endl;
}*/
void LogSort::Swap(vector<long long int *> a,vector<long long int *> b)
{
	

}
/*
string LogSort:: GetStringLine(int LineNumber, fstream & File,int i,ofstream & New)
{
	short int y;

	string b;
    string a;
    for (;currentLine<LineNumber+1;currentLine++)
    {
     getline (File, a);
    }
    while (Line[i]>0)
    {
    	getline(File,b);
        y=a.length();
        a.resize(y+1);
    	a[y]='\n';
        a=a+b;
    	Line[i]--;
    }
    File.clear();
    File.seekg(0,File.beg);
    currentLine=0;
    return a;
}*/
void LogSort::Log(string name)
{
 	   iter=-1;
	p=-1;
    NonLine=0;
	nameOfFile=name;
	currentLine=0;
}
bool LogSort::comp(string & a, string &b)
{
  
  
}