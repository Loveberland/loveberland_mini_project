#include "convert.hh"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <unistd.h>

static int passed = 0;
static int failed = 0;

static std::string capture_output(void (*func)(ll), ll number)
{
	FILE *tmp = tmpfile();

	if (tmp == NULL)
	{
		perror("tmpfile");
		exit(EXIT_FAILURE);
	}

	int stdout_fd = dup(fileno(stdout));

	if (stdout_fd == -1)
	{
		perror("dup");
		fclose(tmp);
		exit(EXIT_FAILURE);
	}

	fflush(stdout);

	if (dup2(fileno(tmp), fileno(stdout)) == -1)
	{
		perror("dup2");
		close(stdout_fd);
		fclose(tmp);
		exit(EXIT_FAILURE);
	}

	func(number);

	fflush(stdout);

	if (dup2(stdout_fd, fileno(stdout)) == -1)
	{
		perror("dup2");
		close(stdout_fd);
		fclose(tmp);
		exit(EXIT_FAILURE);
	}

	close(stdout_fd);

	rewind(tmp);

	std::string result;
	char buffer[128];

	while (fgets(buffer, sizeof(buffer), tmp) != NULL)
		result += buffer;

	fclose(tmp);

	return result;
}

static void test(
	const char *name,
	void (*func)(ll),
	ll number,
	const char *expected)
{
	std::string actual = capture_output(func, number);

	if (actual == expected)
	{
		printf("[PASS] %s\n", name);
		passed++;
	}
	else
	{
		printf("[FAIL] %s\n", name);
		printf("       expected: %s", expected);
		printf("       actual:   %s", actual.c_str());
		failed++;
	}
}

int main(void)
{
	printf("========================================\n");
	printf("          Converter Test Suite\n");
	printf("========================================\n\n");

	test("binary -> octal", bin_oct, 15, "17\n");
	test("binary -> decimal", bin_dec, 15, "15\n");
	test("binary -> hexadecimal", bin_hex, 15, "f\n");

	test("octal -> binary", oct_bin, 15, "1111\n");
	test("octal -> decimal", oct_dec, 15, "15\n");
	test("octal -> hexadecimal", oct_hex, 15, "f\n");

	test("decimal -> binary", dec_bin, 15, "1111\n");
	test("decimal -> octal", dec_oct, 15, "17\n");
	test("decimal -> hexadecimal", dec_hex, 15, "f\n");

	test("hexadecimal -> binary", hex_bin, 15, "1111\n");
	test("hexadecimal -> octal", hex_oct, 15, "17\n");
	test("hexadecimal -> decimal", hex_dec, 15, "15\n");

	printf("\n========================================\n");
	printf("Passed: %d\n", passed);
	printf("Failed: %d\n", failed);
	printf("========================================\n");

	return failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
