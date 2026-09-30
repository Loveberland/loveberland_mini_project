#include <unistd.h>
#include <string.h>

int main(void) {
	void *memory = sbrk(10);
	memory = sbrk(10);
	memory = sbrk(10);
	return 0;
}
