#include <iostream>
#include <cstdlib>
#include "Lex.h"
#include "Syn.h"

int main (int argc, char * argv [])
{
	if (argc < 2)
	{
		cout << "Error: filename required.\n";
		exit (1);
	}

	Lex * lex = new Lex (argv[1]);
	Syn * syn = new Syn (lex);
	while (lex->NextLine())
	{
		int e = syn->Start ();
		cout << e << " errors found in this taunt!" << endl;
	}
	return 0;
}
