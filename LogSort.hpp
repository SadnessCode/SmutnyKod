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
	struct IntStruct
	   {
			
              long long int a;
	      long  line;
	   };
   private:
	int iter;
	int p;
	int NonLine;
	short int LineWithoutTime;
	string nameOfFile;
	int currentLine;  
        vector < int > container;

   public:
       vector <IntStruct*> LineContainer;
       IntStruct *ptr;
       void  Log (string name);
       void  Sort (long int lewy, long int prawy);
       void  Preprocess (string formula,long LineNumber );
       void WriteToFile ();
       string GetStringLine(int LineNumber,fstream & File,int i,ofstream & NewFile);
};




#endif /* LOGSORT_HPP_ */
