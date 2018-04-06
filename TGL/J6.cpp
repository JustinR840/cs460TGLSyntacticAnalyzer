/********************************************************************************
* File: J6.cpp                                                                  *
* Author: Colin Franceschini, Justin Ramos                                      *
* Date: 4/4/18                                                                  *
* Description: This is the modified noun function that will be used to parse    *
               the taunt generation language                                    *
* Comments:                                                                     *
********************************************************************************/

#include <set>
#include "Syn.h"

int Syn::modified_noun() {   // Function 6
	static set<string> firsts = {"hamster", "coconut", "duck", "herring", "newt", "peril",
		"chicken", "vole", "parrot", "mouse", "twit", "silly", "wicked", "sordid", "naughty",
		"repulsive", "malodorous", "ill-tempered", "conspicuously", "categorically", "positively",
		"cruely", "incontrovertibly"};
	static set<string> follows = {"hamster", "coconut", "duck", "herring", "newt", "peril",
		"chicken", "vole", "parrot", "mouse", "twit"};
	int errors = 0;

	while(!firsts.count(ct) && !follows.count(ct))
	{
		lex->ReportError("unexpected '" + ct + "' found at beginning of <modified_noun>.");
		errors++;
		ct = lex->NextTerminal();
	}

	// First if block checks for nouns because they could be first.
	if (ct == "hamster" || ct == "coconut" || ct == "duck" ||
		ct == "herring" || ct == "newt" || ct == "peril" ||
		ct == "chicken" || ct == "vole" || ct == "parrot" ||
		ct == "mouse" || ct == "twit") {
		errors += noun();
	// If we get here, then it didn't start with a noun. The only other
	// option is that it starts with a modifier.
	} else if (ct == "silly" || ct == "wicked" || ct == "sordid" ||
			   ct == "naughty" || ct == "repulsive" || ct == "malodorous" ||
			   ct == "ill-tempered" || ct == "conspicuosly" || ct == "categorically" ||
			   ct == "positively" || ct == "cruelly" || ct == "incontrovertibly") {
		errors += modifier();
		errors += noun();
	} else {
		lex->ReportError("unexpected \'" + ct + "\' found; <noun> or <modifier> expected.");
		ct = lex->NextTerminal();
		errors++;
	}
	return errors;
}
