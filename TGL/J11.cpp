#include "Syn.h"

int Syn::past_verb()	// Function 14
{
	int errors = 0;
	if(ct == "is")
	{
		ct = lex->NextTerminal();;
	}
	else if(ct == "masquerades-as")
	{
		ct = lex->NextTerminal();
	}
	else
	{
		errors++;
	}
	return errors;
}
