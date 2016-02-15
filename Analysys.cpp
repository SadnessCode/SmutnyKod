 #include "LogAnalysys.hpp"
 #include <stdlib.h>
#include <iostream>
#include <regex.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char * argv[]) {


	LogAnalysys Operations (argc,argv);

	string OutString;
	string LineOfFile;

	if ((argc)%2 != 0)// Odd number of arguments is necessary
	{
		cout<<"Odd number of arguments "<<endl;
		exit(-1);
	}
	ofstream newfile ("AnalysysOut.txt");
	fstream  File;
	File.open(argv[1],fstream::in| fstream::out);
	if (File.is_open()) // Open the file
	{
		do{
			getline(File,LineOfFile);

			newfile<<Operations.do_it(LineOfFile)<<endl;
		}while( LineOfFile!="");

	}
	else
	{
		cout<<"can not open file"<<endl;
	}
	return 0;
}