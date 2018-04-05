/********************************************************************************
* File: J11.cpp                                                                 *
* Author: Colin Franceschini, Justin Ramos                                      *
* Date: 4/4/18                                                                  *
* Description: This is the present verb function that will be used to parse     *
               the taunt generation language                                    *
* Comments:                                                                     *
********************************************************************************/

#include "Syn.h"

int Syn::present_verb() {  // Function 14
	int errors = 0;
	// We expect a terminal state of present verb to be here.
	if (ct == "is" || ct == "masquerades-as") {
		ct = lex->NextTerminal();
	} else {
		lex->ReportError("unexpected \'" + ct + "\' found; <present_verb> expected.");
		ct = lex->NextTerminal();
		errors++;
	}
	return errors;
}
