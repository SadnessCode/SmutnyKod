/*
 * LogAsnalysys.cpp
 *
 *  Created on: Jan 15, 2016
 *      Author: p637
 */
#include "LogAnalysys.hpp"
#include <stdlib.h>
#include <iostream>
#include <regex.h>
#include <stdio.h>
#include <string.h>
#include <string>
LogAnalysys::LogAnalysys (int Number,char ** a): NumberOfArguments(Number),HandleToArguments(a){}
string LogAnalysys::do_it (string & LineOfFile) // do all of operations
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
void LogAnalysys::set_word (word * name,int number,string & re) 
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
void LogAnalysys::set_reg (word * name,int number,char**argc) 
{


	for (int i=0;i<number;i++)
	{

		name[i].flag=0;
		name[i].word_char=string( argc[(i*2+2)]);
		name[i].reg=string( argc[(i*2)+3]);
	}
}
void LogAnalysys::if_match (word * name , int number,string & word) 
{
	regmatch_t cos [5];
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
		reti = regexec(&regex, word.c_str(), 5, cos, 0);
		if (!reti) {
			name[i].flag=1;
		}

	}
}



