#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv)
{
	switch (argc)
	{
		case 1: break;  // No source file required.
		case 2:
			{
				FILE *fp = fopen(argv[1], "r");
				if (!fp) {
					// Non-existent files are valid source files. Beat that!
					if (errno == ENOENT) break;
					perror(argv[1]);
					exit(2);
				}
				char buf;
				int rc = fread(&buf, 1, 1, fp);

				if (rc) {
					// No statements, commands, comments supported
					fprintf(stderr, "Syntax error: Unexpected statement\n");
					exit(1);
				}
				fclose(fp);
				break;
			}
	}
	puts("Hello World!");
	return 0;
}
