/********************************************************************************
* File: J10.cpp                                                                 *
* Author: Colin Franceschini, Justin Ramos                                      *
* Date: 4/4/18                                                                  *
* Description: This is the present person function that will be used to parse   *
               the taunt generation language                                    *
* Comments:                                                                     *
********************************************************************************/

#include <set>
#include "Syn.h"

int Syn::present_person(){    // Function 10
	static set<string> firsts = {"steed", "king", "first-born"};
	static set<string> follows = {"is", "masquerades-as"};

	int errors = 0;

	while(!firsts.count(ct) && !follows.count(ct))
	{
		lex->ReportError("unexpected '" + ct + "' found at beginning of <present_person>.");
		errors++;
		ct = lex->NextTerminal();
	}

	// We expect a terminal state of present person to be here.
	if (ct == "steed" || ct == "king" || ct == "first-born") {
		ct = lex->NextTerminal();
	}else {
		errors++;
		lex->ReportError("unexpected \'" + ct + "\' found; <present_person> expected.");
		ct = lex->NextTerminal();
	}
	return errors;
}
