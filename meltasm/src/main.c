#include <stdbool.h>
#include <stdio.h>
#include <darray.h>
#include <string.h>

DYNAMIC_ARRAY(strarr, char *);

struct arguments {
	char *output;
	bool assemble;
	bool link;
	strarr inputs;
};

int main(int argc, char *argv[]) {
	struct arguments args = {
		.output = "a.out",
		.assemble = false,
		.link = false,
		.inputs = strarr_init(16),
	};
	int argn = 1;
	for (;;) {
		if (argn >= argc) break;
		if (strcmp(argv[argn], "-o") == 0) {
			argn++;
			if (argn >= argc) {
				fprintf(stderr, "-o <output> - missing output");
				return -1;
			}
			args.output = argv[argn];
			argn++;
			continue;
		}
		if (strcmp(argv[argn], "-a") == 0) {
			args.assemble = true;
			argn++;
			continue;
		}
		if (strcmp(argv[argn], "-l") == 0) {
			args.link = true;
			argn++;
			continue;
		}
		break;
	}
	for (;;) {
		if (argn >= argc) break;
		strarr_insert_after(&args.inputs, -1, argv[argn]);
		argn++;
	}
	printf("arguments {\n  output: %s,\n  assemble: %d,\n  link: %d,\n  inputs: [\n", args.output, args.assemble, args.link);
	char **current;
	for (int i = 0;;i++) {
		current = strarr_at(&args.inputs, i);
		if (current == NULL) break;
		printf("    %s,\n", *current);
	}
	printf("  ]\n}\n");
}
