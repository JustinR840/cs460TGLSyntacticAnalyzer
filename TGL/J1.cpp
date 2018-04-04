#include "Syn.h"

int Syn::taunt()	// Function 1
{
	int errors = 0;
	if(ct == "your")
	{
		errors += sentence();
		errors += taunt_tail();
	}
	else if(ct == "hamster" || ct == "coconut" || ct == "duck" ||
			ct == "herring" || ct == "newt" || ct == "peril" ||
			ct == "chicken" || ct == "vole" || ct == "parrot" ||
			ct == "mouse" || ct == "twit")
	{
		errors += noun();
		if(ct == "!")
		{
			ct = lex->NextTerminal();
	
		}
		else
		{
			errors++;
		}
		errors += taunt_tail();
		if(ct == "")
		{

		}
		else
		{
			errors++;
		}
	}
	else
	{
		errors++;
	}
	return errors;
}
