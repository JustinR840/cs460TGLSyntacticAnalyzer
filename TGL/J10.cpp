#include "Syn.h"

int Syn::present_person()	// Function 10
{
	int errors = 0;
	if(ct == "steed")
	{
		ct = lex->NextTerminal();;
	}
	else if(ct == "king")
	{
		ct = lex->NextTerminal();
	}
	else if(ct == "first-born")
	{
		ct = lex->NextTerminal();
	}
	else
	{
		errors++;
	}
	return errors;
}
