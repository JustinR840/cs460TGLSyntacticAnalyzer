#include "Syn.h"

int Syn::past_rel()	// Function 9
{
	int errors = 0;
	if(ct == "mother" || ct == "father" || ct == "grandmother" ||
			ct == "grandfather" || ct == "godfather")
	{
		errors += past_person();
		errors += past_verb();
	}
	else
	{
		errors++;
	}
	return errors;
}
