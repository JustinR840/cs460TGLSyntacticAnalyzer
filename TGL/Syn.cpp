/*******************************************************************************
* Assignment: Syntactical Analyzer for Taunt Generator Language                *
* Author: Dr. Watts                                                            *
* Date: Spring 2018                                                            *
* File: Syn.cpp                                                                *
*                                                                              *
* Description: This file contains the                                          *
*******************************************************************************/

#include <iostream>
#include "Syn.h"

using namespace std;

/*******************************************************************************
* Function: Syn                                                                *
*                                                                              *
* Description: This function is designed to                                    *
*******************************************************************************/
Syn::Syn(Lex *LA) {
	lex = LA;
}

Syn::~Syn() {
}

int Syn::Start() {
	int errors = 0;
	ct = lex->NextTerminal();
	while (ct != "") {
		cout << ct << endl;
		ct = lex->NextTerminal();
		errors += taunt();
	}
	return errors;
}

int Syn::taunt() {
	int errors = 0;
	return errors;
}
