/******************************************************************************
* Assignment: Syntactical Analyzer for Taunt Generator Language               *
* Author: Dr. Watts                                                           *
* Date: Spring 2018                                                           *
* File: Syn.h                                                                 *
*                                                                             *
* Description: This file contains the                                         *
******************************************************************************/

#ifndef SYN_H
#define SYN_H

#include "Lex.h"

using namespace std;

/******************************************************************************
* Class: Syn                                                                  *
*                                                                             *
* Description: This class is designed to                                      *
******************************************************************************/
class Syn 
{
   public:
	Syn (Lex * LA);
	~Syn ();
	int Start ();
   private:
	Lex * lex;
	string ct; 		// current terminal
	int taunt ();		// Function 1
	int taunt_tail ();	// Function 2
	int sentence ();	// Function 3
	int relation ();	// Function 4
	int noun_phrase();	// Function 5
	int modified_noun();	// Function 6
	int modifier();		// Function 7
	int present_rel();	// Function 8
	int past_rel();		// Function 9
	int present_person();	// Function 10
	int past_person();	// Function 11
	int noun();		// Function 12
	int article();		// Function 13
	int present_verb();	// Function 14
	int past_verb();	// Function 15
	int adjective();	// Function 16
	int adverb();		// Function 17
};
	
#endif
