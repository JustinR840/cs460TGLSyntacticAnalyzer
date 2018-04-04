#include "Syn.h"

int Syn::article()	// Function 13
{
	int errors = 0;
	if (ct == "a")
		ct = lex->NextTerminal();
	else
	{
		lex->ReportError ("Error: unexpected " + ct + "found; 'a' expected");
		errors++;
	}
	return errors;
}
