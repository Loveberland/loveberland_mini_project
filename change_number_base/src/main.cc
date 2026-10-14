#include "convert.hh"

#include <iostream>
#include <cstring>

#define SIZ 1024

static bool is_valid_format(char *s)
{
	if (s[0] == '2' || s[0] == '8')
	{
		return s[1] == '\0';
	}

	if (s[0] == '1' && (s[1] == '0' || s[1] == '6'))
	{
		return s[2] == '\0';
	}

	return false;
}

int main(int argc, char **argv)
{
	if (argc != 3 || !is_valid_format(argv[1]) || !is_valid_format(argv[2]) || (std::strcmp(argv[1], argv[2]) == 0))
	{
		std::cerr << "invalid format input\n";
		return -1;
	}

	// get input
	ll number;
	if (argv[1][0] == '2')
	{
		char buf[65];
		scanf("%64s", buf);
		number = (ll)strtoll(buf, NULL, 2);
	}
	else if (strcmp(argv[1], "16") == 0)
	{
		char buf[17];
		scanf("%16s", buf);
		number = (ll)strtoll(buf, NULL, 16);
	}
	else
	{
		scanf("%lld", &number);
	}

	// choose format
	if (argv[1][0] == '2' && argv[2][0] == '8')
	{
		bin_oct(number);
	}
	else if (argv[1][0] == '2' && (std::strcmp(argv[2], "10")) == 0)
	{
		bin_dec(number);
	}
	else if (argv[1][0] == '2' && (std::strcmp(argv[2], "16")) == 0)
	{
		bin_hex(number);
	}
	else if (argv[1][0] == '8' && argv[2][0] == '2')
	{
		oct_bin(number);
	}
	else if (argv[1][0] == '8' && (std::strcmp(argv[2], "10")) == 0)
	{
		oct_dec(number);
	}
	else if (argv[1][0] == '8' && (std::strcmp(argv[2], "16")) == 0)
	{
		oct_hex(number);
	}
	else if ((std::strcmp(argv[1], "10")) == 0 && argv[2][0] == '2')
	{
		dec_bin(number);
	}
	else if ((std::strcmp(argv[1], "10")) == 0 && argv[2][0] == '8')
	{
		dec_oct(number);
	}
	else if ((std::strcmp(argv[1], "10")) == 0 && (std::strcmp(argv[2], "16")) == 0)
	{
		dec_hex(number);
	}
	else if ((std::strcmp(argv[1], "16")) == 0 && argv[2][0] == '2')
	{
		hex_bin(number);
	}
	else if ((std::strcmp(argv[1], "16")) == 0 && argv[2][0] == '8')
	{
		hex_oct(number);
	}
	else if ((std::strcmp(argv[1], "16")) == 0 && (std::strcmp(argv[2], "10")) == 0)
	{
		hex_dec(number);
	}

	return 0;
}