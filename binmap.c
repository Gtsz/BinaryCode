#include <stdio.h>

int main(int argc, char *argv[]) {
	char *bin_list[] = {
		"    ", "   #", "  # ", "  ##",
		" #  ", " # #", " ## ", " ###",
		"#   ", "#  #", "# # ", "# ##",
		"##  ", "## #", "### ", "####"
	};
	FILE *file;
	unsigned char buffer[1];
	unsigned char a, b;
	long long int count = 0;
	
	if (file = fopen(argv[1], "rb")) {
		printf("Path: %s\n", argv[1]);
		while (fread(buffer, 1, 1, file)) {
			a = buffer[0] >> 4;
			b = buffer[0] << 4;
			b = b >> 4;
			printf("%s%s", bin_list[a], bin_list[b]);
			count++;
			sleep(1);
		}
		fclose(file);
		printf("\nFile size: %lld bytes\n", count);
		system("pause");
	}
	
	return 0;
}