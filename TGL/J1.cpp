/********************************************************************************
* File: J1.cpp                                                                  *
* Author: Colin Franceschini, Justin Ramos                                      *
* Date: 4/4/18                                                                  *
* Description: This is taunt function that will be used to parse the            *
               taunt generation language                                        *
* Comments:                                                                     *
********************************************************************************/

#include "Syn.h"

int Syn::taunt() {    // Function 1
	int errors = 0;
	if (ct == "your") {
		errors += sentence();
		errors += taunt_tail();
	} else if (ct == "hamster" || ct == "coconut" || ct == "duck" ||
			   ct == "herring" || ct == "newt" || ct == "peril" ||
			   ct == "chicken" || ct == "vole" || ct == "parrot" ||
			   ct == "mouse" || ct == "twit") {
		errors += noun();
		if (ct != "!") {
			lex->ReportError("unexpected \'" + ct + "\' found; ! expected");
			ct = lex->NextTerminal();
			errors++;
		}
		// need to get a new token after seeing '!'
		ct = lex->NextTerminal();
		errors+= taunt_tail();
	} else {
		lex->ReportError("unexpected \'" + ct + "\' found; taunt expected");
		ct = lex->NextTerminal();
		errors++;
	}
	return errors;
}
