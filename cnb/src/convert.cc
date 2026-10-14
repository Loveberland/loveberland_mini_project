#include "convert.hh"

#include <cstdio>

// bin zone
void bin_oct(ll number)
{
	fprintf(stdout, "%llo\n", number);
}

void bin_dec(ll number)
{
	fprintf(stdout, "%lld\n", number);
}
void bin_hex(ll number)
{
	fprintf(stdout, "%llx\n", number);
}

// oct zone
void oct_bin(ll number)
{
	fprintf(stdout, "%llb\n", number);
}
void oct_dec(ll number)
{
	fprintf(stdout, "%lld\n", number);
}
void oct_hex(ll number)
{
	fprintf(stdout, "%llx\n", number);
}

// dec zone
void dec_bin(ll number)
{
	fprintf(stdout, "%llb\n", number);
}
void dec_oct(ll number)
{
	fprintf(stdout, "%llo\n", number);
}
void dec_hex(ll number)
{
	fprintf(stdout, "%llx\n", number);
}

// hex zone
void hex_bin(ll number)
{
	fprintf(stdout, "%llb\n", number);
}
void hex_oct(ll number)
{
	fprintf(stdout, "%llo\n", number);
}
void hex_dec(ll number)
{
	fprintf(stdout, "%lld\n", number);
}
