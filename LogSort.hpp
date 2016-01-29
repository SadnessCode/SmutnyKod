/*
 * LogSort.hpp
 *
 *  Created on: Jan 20, 2016
 *      Author: p637
 */
#include <vector>
#include <time.h>
#include <string>
#ifndef LOGSORT_HPP_
#define LOGSORT_HPP_

using namespace std;
class LogSort
{
  int iter;
	int p;
	int NonLine;
	vector< int>::iterator it;
	string nameOfFile;
	int currentLine;
    vector <int> LineContainer;
    vector <int> Line;
    vector <unsigned long long int  > container;

public:

	void  Log (string name);
    void Sort ();
	void  Preprocess (string formula,int LineNumber );
    void WriteToFile ();
    void Swap (vector <unsigned long long int  >& container,vector <int> &LineContainer, int i,vector <int>& Line);
    string GetStringLine(int LineNumber,fstream & File,int i,ofstream & NewFile);
};




#endif /* LOGSORT_HPP_ */
