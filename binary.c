#include <stdio.h>

#define BUF_LEN 8

int main(int argc, char *argv[]) {
	char *bin_list[] = {
		"0000", "0001", "0010", "0011",
		"0100", "0101", "0110", "0111",
		"1000", "1001", "1010", "1011",
		"1100", "1101", "1110", "1111"
	};
	char *path;
	FILE *file;
	unsigned char buffer[BUF_LEN];
	unsigned char a, b;
	int i, j;

	if (!argv[1])
		path = argv[0];
	else
		path = argv[1];
	
	if (file = fopen(path, "rb")) {
		printf("Path: %s\n", path);
		while (i = fread(buffer, 1, BUF_LEN, file)) {
			for (j = 0; j < i; j++) {
				a = buffer[j] >> 4;
				b = buffer[j] << 4;
				b = b >> 4;
				printf("%s%s ", bin_list[a], bin_list[b]);
			}
				
		}
		fclose(file);
		printf("\n");
		system("pause");
		return 0;
	}
	return 0;
}