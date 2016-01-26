/*
 * LogAnalysys.hpp
 *
 *  Created on: Jan 15, 2016
 *      Author: p637
 */
#include <string>
#ifndef LOGANALYSYS_HPP_
#define LOGANALYSYS_HPP_
using namespace std;
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
	LogAnalysys (int Number,char ** a);
	string  do_it (string & LineOfFile);
	void set_word (word * name,int number,string & re);
	void set_reg (word * name,int number,char**argc);
	void if_match (word * name , int number,string & word);

};


#endif /* LOGANALYSYS_HPP_ */
