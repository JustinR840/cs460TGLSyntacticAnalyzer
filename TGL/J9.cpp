/********************************************************************************
* File: J9.cpp                                                                  *
* Author: Colin Franceschini, Justin Ramos                                      *
* Date: 4/4/18                                                                  *
* Description: This is the past rel function that will be used to parse         *
               the taunt generation language                                    *
* Comments:                                                                     *
********************************************************************************/

#include "Syn.h"

int Syn::past_rel() {   // Function 9
	int errors = 0;
	if (ct == "mother" || ct == "father" || ct == "grandmother" ||
		ct == "grandfather" || ct == "godfather") {
		errors += past_person();
		errors += past_verb();
	} else {
		lex->ReportError("unexpected \'" + ct + "\' found; past_rel expected");
		ct = lex->NextTerminal();
		errors++;
	}
	return errors;
}
