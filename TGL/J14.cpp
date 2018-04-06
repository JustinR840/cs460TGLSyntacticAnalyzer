/********************************************************************************
* File: J14.cpp                                                                 *
* Author: Colin Franceschini, Justin Ramos                                      *
* Date: 4/4/18                                                                  *
* Description: This is the present verb function that will be used to parse     *
               the taunt generation language                                    *
* Comments:                                                                     *
********************************************************************************/

#include <set>
#include "Syn.h"

int Syn::present_verb() {  // Function 14
	static set<string> firsts = {"is", "masquerades-as"};
	static set<string> follows = {"a"};
	
	int errors = 0;

	while(!firsts.count(ct) && !follows.count(ct))
	{
		lex->ReportError("unexpected '" + ct + "' found at beginning of <present_verb>.");
		errors++;
		ct = lex->NextTerminal();
	}

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
