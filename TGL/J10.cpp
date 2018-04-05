/*******************************************************************************
* File: J10.cpp													               *
* Author: Colin Franceschini, Justin Ramos                                     *
* Date: 4/4/18		                                                           *
* Description: This is the present person function that will be used to parse  *
* 			   the taunt generation language      							   *
* Comments:                                                                    *
*******************************************************************************/


#include "Syn.h"

int Syn::present_person()    // Function 10
{
	int errors = 0;
	if (ct == "steed") {
		ct = lex->NextTerminal();;
	} else if (ct == "king") {
		ct = lex->NextTerminal();
	} else if (ct == "first-born") {
		ct = lex->NextTerminal();
	} else {
		errors++;
	}
	return errors;
}
