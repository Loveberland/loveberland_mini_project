#include <iostream>
#include <cstring>

bool is_valid_format(char *s) {
	if (s[0] == '2' || s[0] == '8') {
		return s[1] == '\0';
	}

	if (s[0] == '1' && (s[1] == '0' || s[1] == '6')) {
		return s[2] == '\0';
	}

	return false;
}

int main(int argc, char **argv) {
	if (argc != 3 || !is_valid_format(argv[1]) || !is_valid_format(argv[2]) || (std::strcmp(argv[1], argv[2]) == 0)) {
		std::cerr << "invalid format input\n";
		return -1;
	}

	return 0;
}