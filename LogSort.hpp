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
public:
    class Line
    		{
    			long long int a;
    		};
private:
	int iter;
	int p;
	int NonLine;
	Line *ptr;
	string nameOfFile;
	int currentLine;
    vector <Line*> LineContainer;
    vector <int> Line;
    vector <string > container;

public:

  bool comp(string & a, string &b);
	void  Log (string name);
    void Sort ();
	void  Preprocess (string formula,int LineNumber );
   // void WriteToFile ();
    void Swap (vector<long long int *> a,vector<long long int *> b);
   // string GetStringLine(int LineNumber,fstream & File,int i,ofstream & NewFile);
};




#endif /* LOGSORT_HPP_ */
