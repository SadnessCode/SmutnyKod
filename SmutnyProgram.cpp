//============================================================================
// Name        : SmutnyProgram.cpp
// Author      : smutny
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "LogAnalysys.hpp"
#include <stdlib.h>
#include <iostream>
#include <regex.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;
/*
class LogAnalysys
{

	struct word
	{
		bool flag;
		string  word_char;
		string  reg;
	};

	int NumberOfArguments;
	char ** HandleToArguments;
	string OutString;
	string retu;
	public:
	LogAnalysys (int Number,char ** a): NumberOfArguments(Number),HandleToArguments(a)
	{
	}
	string  do_it (string & LineOfFile)
	{
		word *Flags;
		Flags= new word [(NumberOfArguments/2)-1];
		set_reg(Flags,(NumberOfArguments/2)-1, HandleToArguments);
		if_match(Flags,(NumberOfArguments/2)-1,LineOfFile);
		set_word(Flags,(NumberOfArguments/2)+1,OutString);
		OutString+=LineOfFile;
		retu=OutString;

		delete [] Flags;
		OutString="";
		return retu;


	}
	void set_word (word * name,int number,string & re)
	{
		re=re+'[';
		for (int i=1;i<number-1;i++)
		{

			if(name[i-1].flag)
			{
				re=re+ name[i-1].word_char;
			}
			if(!name[i-1].flag)
			{
				re=re+'.';
			}
		}
		re=re+']';
	}
	void set_reg (word * name,int number,char**argc)
	{


		for (int i=0;i<number;i++)
		{

			name[i].flag=0;
			name[i].word_char=string( argc[(i*2+2)]);
			name[i].reg=string( argc[(i*2)+3]);
		}
	}
	void if_match (word * name , int number,string & word)
	{
		regex_t regex;
		int reti;
		for (int i=0;i<number;i++)
		{
			reti = regcomp(&regex, name[i].reg.c_str(), 0);
			if (reti)
			{
				fprintf(stderr, "Could not compile regex\n");
				exit(1);
			}
			reti = regexec(&regex, word.c_str(), 0, NULL, 0);
			if (!reti) {
				name[i].flag=1;
			}
		}
	}
}; */
int main(int argc, char * argv[]) {


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
