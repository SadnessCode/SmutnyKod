//============================================================================
// Name
// Author      : smutny
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "LogSort.hpp"
#include <stdlib.h>
#include <iostream>
#include<regex.h>
#include<regex>
#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <time.h>
using namespace std;

int main( int argc, char * argv[]) {
	 unsigned long long int Line=0;
         double a;
	
	  clock_t t;
  int f;
  t = clock();
           char  tab[30];
	   LogSort Sorto;
	   Sorto.Log(string(argv[1]));
		string OutString;
		string LineOfFile;

		ofstream newfile ("new.txt");
		fstream  File;
		File.open(argv[1],fstream::in| fstream::out);

        
		if (File.is_open())
		{
                        cout<<"wczytuje"<<endl;
			while( !File.eof() )
			        {
                                      long pos=File.tellp();
			            getline( File, LineOfFile );
                                  
			            Sorto.Preprocess(LineOfFile,pos);
			            Line++;
			        }
			         
		}
		else cout<<"can not open file"<<endl;
t = clock() - t;
  cout<<((float)t/CLOCKS_PER_SEC)<<endl;
			
			File.clear();
			File.seekg(0,File.beg);
			cout<<"sortuje"<<endl;
			
			Sorto.Sort(0,Sorto.LineContainer.size()-1);
t = clock() - t;
  cout<<((float)t/CLOCKS_PER_SEC)<<endl;

	cout<<"Pisze do Pliku"<<endl;
	Sorto.WriteToFile();
		t = clock() - t;
  cout<<((float)t/CLOCKS_PER_SEC)<<endl;
  return 0;
}
