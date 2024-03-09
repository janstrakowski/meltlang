#include <stdbool.h>

struct arguments {
	char *output;
	bool assemble;
	bool link;
	char **inputs;
};

int main(int argc, char *argv[]) {
	struct arguments args = {
		.output = "a.out",
		.assemble = true,
		.link = true,
		.inputs = NULL,
	int argn = 0;
	for (;;) {
		if (argn >= argc) break;
	}
}
