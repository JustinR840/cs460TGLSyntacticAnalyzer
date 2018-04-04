
/*******************************************************************************
* Assignment: Lexical Analyzer for Taunt Generator Language                    *
* Author: Dr. Watts                                                            *
* Date: Spring 2018                                                            *
* File: Lex.cpp                                                                *
*                                                                              *
* Description: This file contains the                                          *
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Lex.h"

using namespace std;

/*******************************************************************************
* Function: Lex                                                                *
*                                                                              *
* Description: This function is designed to                                    *
*******************************************************************************/
Lex::Lex (char * filename)
{
	input.open (filename);
	if (input.fail ())
	{
		cout << "Error: " << filename << " not found.\n";	
		exit (1);
	}
	linenumber = 0;
}

Lex::~Lex ()
{
	input.close ();
}

bool Lex::NextLine ()
{
	if (getline (input, line))
	{
		cout << ++linenumber << ": " << line << endl;
		line += " ";
		pos = 0;
		return true;
	}
	return false;
}

string Lex::NextTerminal ()
{
	terminal = "";
	if (pos >= line.length())
		return terminal;
	while (isspace (line[pos]))
	{
		pos++;
		if (pos >= line.length())
			return terminal;
	}
	if (!isalpha (line[pos]))
	{
		terminal = line[pos];
		pos++;
		return terminal;
	}
	while (line[pos] == '-' || isalpha (line[pos]))
	{
		terminal += tolower (line[pos]);
		pos++;
	}
	return terminal;
}

void Lex::ReportError (const string & msg)
{
	cout << "Error: " << msg << endl;
}
