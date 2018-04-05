/********************************************************************************
* File: J10.cpp                                                                 *
* Author: Colin Franceschini, Justin Ramos                                      *
* Date: 4/4/18                                                                  *
* Description: This is the present person function that will be used to parse   *
               the taunt generation language                                    *
* Comments:                                                                     *
********************************************************************************/


#include "Syn.h"

int Syn::present_person(){    // Function 10
	int errors = 0;
	if (ct == "steed" || ct == "king" || ct == "first-born") {
		ct = lex->NextTerminal();;
	}else {
		errors++;
		lex->ReportError("unexpected \'" + ct + "\' found; <present_verb> expected  --> Function 14");
		ct = lex->NextTerminal();
	}
	return errors;
}
