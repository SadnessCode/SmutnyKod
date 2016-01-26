//============================================================================
// Name        : SmutnyProgram.cpp
// Author      : smutny
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "LogAnalysys.hpp"
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
using namespace std;

int main(int argc, char * argv[]) {

  unsigned long long int Line=0;



   LogSort Sorto;
   Sorto.Log(string(argv[1]));
	LogAnalysys Operations (argc,argv);

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

		while( !File.eof() )
		        {

		            getline( File, LineOfFile );

		            Sorto.Preprocess(LineOfFile,Line);
		            Line++;
		        }

		//tutaj juz -1
		File.clear();
		File.seekg(0,File.beg);
		Sorto.Sort();

		/*do{

			getline(File,LineOfFile);
			cout<<LineOfFile<<endl;
			//Sorto.Preprocess(LineOfFile);

			//newfile<<Operations.do_it(LineOfFile)<<endl;

		}while( LineOfFile!="");

	}
	else
	{
		cout<<"can not open file"<<endl;
	}
*/
Sorto.WriteToFile();
	}
	return 0;
}
