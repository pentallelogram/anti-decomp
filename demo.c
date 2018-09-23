#include <stdio.h>
#include "anti-decomp.h"

void evil()
{
	puts("can't see me in decomp");
}

void *gadgets[] = {gadget, evil};

void protected()
{
	positive_sp_predicate;
	puts("can't decompile");
}


void main()
{
	protected();
	ret_hijack(gadgets);
}
