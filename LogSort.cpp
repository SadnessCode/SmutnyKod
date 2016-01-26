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
	  unsigned  long long int g;
       string  Time;
	   int res;
	   int len;
	   char result[BUFSIZ];
	   char err_buf[BUFSIZ];
	   const  char* pattern =  "([0-9]{4})-([0-9]{2})-([0-9]{2}) ([0-9]{2}):([0-9]{2}):([0-9]{2}).([0-9]{3})";
	   regex_t preg;
	   regmatch_t pmatch[40];

	   if( (res = regcomp(&preg, pattern, REG_EXTENDED)) != 0)
	   {
	      regerror(res, &preg, err_buf, BUFSIZ);
	      printf("regcomp: %s\n", err_buf);
	      exit(res);
	   }
	   res = regexec(&preg, formula.c_str(), 40, pmatch, 0);
	   if(res == REG_NOMATCH)
	   {
		   if (container.empty())
		   {
		   }
		   else
		   {
			   NonLine++;
              Line[p]=NonLine;
		   }
	   }

	   else
	   {
p++;
cout<<p<<endl;
cout<<NonLine<<endl;
		Line.push_back(NonLine);
		NonLine=0;
	   for (int i = 1; pmatch[i].rm_so != -1; i++)
	   {
	      len = pmatch[i].rm_eo - pmatch[i].rm_so;
	      memcpy(result, formula.c_str() + pmatch[i].rm_so, len);
	      result[len] = 0;
		  Time = Time +string (result);
	   }
	   g=atoll(Time.c_str());
        container.push_back(g);
        LineContainer.push_back(LineNumber);
	   }
	   regfree(&preg);
	}
void LogSort:: Sort()
{
for (unsigned int i=0;i<container.size()-1;i++)
{
	for (unsigned int j=0;j<container.size()-1;j++)
	{
		if (container[j]>container[j+1])
		{
        Swap(container,LineContainer,j,Line);
		}
	}
}
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
      NewFile<<GetStringLine(LineContainer[i],File,i,NewFile)<<endl;
	}
	}
	else cout<<"Can not open file"<<endl;
}
void LogSort::Swap(vector <unsigned long long int> &container,vector <int> & LineContainer ,int i,vector <int>& Line)
{
	int overWriteIL=Line[i];
	int overWriteI=LineContainer[i];
	unsigned long long int overWriteIll=container[i];
	LineContainer[i]=LineContainer[i+1];
	container[i]=container[i+1];
	LineContainer[i+1]=overWriteI;
	container[i+1]=overWriteIll;
	Line[i]=Line[i+1];
	Line[i+1]=overWriteIL;

}
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
}
void LogSort::Log(string name)
{
	p=-1;
NonLine=0;
	nameOfFile=name;
	currentLine=0;
}

