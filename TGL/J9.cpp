/********************************************************************************
* File: J9.cpp                                                                  *
* Author: Colin Franceschini, Justin Ramos                                      *
* Date: 4/4/18                                                                  *
* Description: This is the past rel function that will be used to parse         *
               the taunt generation language                                    *
* Comments:                                                                     *
********************************************************************************/

#include <set>
#include "Syn.h"

int Syn::past_rel() {   // Function 9
	static set<string> firsts = {"mother", "father", "grandmother", "grandfather", "godfather"};
	static set<string> follows = {"was", "personified-a"};
	
	int errors = 0;

	while(!firsts.count(ct) && !follows.count(ct))
	{
		lex->ReportError("unexpected '" + ct + "' found at beginning of <past_rel>.");
		errors++;
		ct = lex->NextTerminal();
	}

	// We expect a terminal state of past person here.
	if (ct == "mother" || ct == "father" || ct == "grandmother" ||
		ct == "grandfather" || ct == "godfather") {
		errors += past_person();
		errors += past_verb();
	} else {
		lex->ReportError("unexpected \'" + ct + "\' found; <past_person> expected.");
		ct = lex->NextTerminal();
		errors++;
	}
	return errors;
}
