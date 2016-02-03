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
		//LogAnalysys Operations (argc,argv);

		string OutString;
		string LineOfFile;
		if ((argc)%2 != 0)
		{
			cout<<"Odd number of arguments "<<endl;
			exit(-1);
		}

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
t = clock() - t;
  cout<<((float)t/CLOCKS_PER_SEC)<<endl;
			//tutaj juz -1

			File.clear();
			File.seekg(0,File.beg);
			cout<<"sortuje"<<endl;
			
			Sorto.Sort(0,Sorto.LineContainer.size()-1);
t = clock() - t;
  cout<<((float)t/CLOCKS_PER_SEC)<<endl;
  /*
			do{
				getline(File,LineOfFile);
				cout<<LineOfFile<<endl;
				//Sorto.Preprocess(LineOfFile);
				//newfile<<Operations.do_it(LineOfFile)<<endl;
			}while( LineOfFile!="");
		}
		}
		else
		{
			cout<<"can not open file"<<endl;
		}
		*/
	cout<<"Pisze do Pliku"<<endl;
	Sorto.WriteToFile();
		t = clock() - t;
  cout<<((float)t/CLOCKS_PER_SEC)<<endl;
  return 0;
}
