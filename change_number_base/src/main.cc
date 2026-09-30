#include <iostream>
#include <cstring>

#define SIZ 1024

static bool is_valid_format(char *s) {
	if (s[0] == '2' || s[0] == '8') {
		return s[1] == '\0';
	}

	if (s[0] == '1' && (s[1] == '0' || s[1] == '6')) {
		return s[2] == '\0';
	}

	return false;
}

static int get_src(char *src, int base) {
	std::cout << "enter number: ";
	if (!fgets(src, SIZ, stdin)) {
		return -1;
	}
	
	src[strcspn(src, "\n")] = '\0';
	if (src[0] == '\0') {
		return -1;
	}

	for (char *c = &src[0]; *c != '\0'; ++c) {
		if (base == 2) {
			if (*c < '0' || *c > '1') {
				std::cerr << "found: " << *c << '\n';
				return -1;
			}
		} else if (base == 8) {
			if (*c < '0' || *c > '7') {
				std::cerr << "found: " << *c << '\n';
				return -1;
			}
		} else if (base == 10) {
			if (*c < '0' || *c > '9') {
				std::cerr << "found: " << *c << '\n';
				return -1;
			}
		} else if (base == 16) {
			if (!((*c >= 0 && *c <= '9') || (*c >= 'A' && *c <= 'F'))) {
				std::cerr << "found: " << *c << '\n';
				return -1;
			}
		}
	}

	return 0;
}

int main(int argc, char **argv) {
	if (argc != 3 || !is_valid_format(argv[1]) || !is_valid_format(argv[2]) || (std::strcmp(argv[1], argv[2]) == 0)) {
		std::cerr << "invalid format input\n";
		return -1;
	}

	char *src = (char *)malloc(sizeof(char) * SIZ);
	char *dest = (char *)malloc(sizeof(char) * SIZ);
	if (!src || !dest) {
		std::cout << "memory allocation failed\n";
		free(src);
		free(dest);
		return -1;
	}

	while (get_src(src, atoi(argv[1])));

	// choose convert algorithms

	free(src);
	free(dest);

	return 0;
}