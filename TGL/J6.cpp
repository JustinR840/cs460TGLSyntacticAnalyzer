#include "Syn.h"

int Syn::modified_noun()	// Function 6
{
	int errors = 0;
	if(ct == "hamster" || ct == "coconut" || ct == "duck" ||
			ct == "herring" || ct == "newt" || ct == "peril" ||
			ct == "chicken" || ct == "vole" || ct == "parrot" ||
			ct == "mouse" || ct == "twit")
	{
		errors += noun();
	}
	else if(ct == "silly" || ct == "wicked" || ct == "sordid" ||
			ct == "naughty" || ct == "repulsive" || ct == "malodorous" ||
			ct == "ill-tempered" || ct == "conspicuosly" || ct == "categorically" ||
			ct == "positively" || ct == "cruelly" || ct == "incontrovertibly")
	{
		errors += modifier();
		errors += noun();
	}
	else
	{
		errors++;
	}
	return errors;
}
