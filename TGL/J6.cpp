/********************************************************************************
* File: J6.cpp                                                                  *
* Author: Colin Franceschini, Justin Ramos                                      *
* Date: 4/4/18                                                                  *
* Description: This is the modified noun function that will be used to parse    *
               the taunt generation language                                    *
* Comments:                                                                     *
********************************************************************************/

#include "Syn.h"

int Syn::modified_noun() {   // Function 6
	int errors = 0;
	if (ct == "hamster" || ct == "coconut" || ct == "duck" ||
		ct == "herring" || ct == "newt" || ct == "peril" ||
		ct == "chicken" || ct == "vole" || ct == "parrot" ||
		ct == "mouse" || ct == "twit") {
		errors += noun();
	} else if (ct == "silly" || ct == "wicked" || ct == "sordid" ||
			   ct == "naughty" || ct == "repulsive" || ct == "malodorous" ||
			   ct == "ill-tempered" || ct == "conspicuosly" || ct == "categorically" ||
			   ct == "positively" || ct == "cruelly" || ct == "incontrovertibly") {
		errors += modifier();
		errors += noun();
	} else {
		lex->ReportError("unexpected \'" + ct + "\' found; modified_noun expected");
		ct = lex->NextTerminal();
		errors++;
	}
	return errors;
}
