/*******************************************************************************
* Assignment: Lexical Analyzer for Taunt Generator Language                    *
* Author: Dr. Watts                                                            *
* Date: Spring 2018                                                            *
* File: Lex.h                                                                  *
*                                                                              *
* Description: This file contains the                                          *
*******************************************************************************/

#ifndef LEX_H
#define LEX_H

#include <fstream>

using namespace std;

/*******************************************************************************
* Class: Lex                                                                   *
*                                                                              *
* Description: This class is designed to                                       *
*******************************************************************************/

class Lex 
{
    public:
	Lex (char * filename);
	~Lex ();
	bool NextLine ();
	string NextTerminal ();
	void ReportError (const string & msg);
    private:
	ifstream input;
	int linenumber;
	string line;
	int pos;
	string terminal;
	int errors;
};
	
#endif
