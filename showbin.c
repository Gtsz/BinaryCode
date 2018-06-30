#include <stdio.h>

#define BUF_LEN 4

int main(int argc, char *argv[]) {
	char *bin_list[] = {
		"0000", "0001", "0010", "0011",
		"0100", "0101", "0110", "0111",
		"1000", "1001", "1010", "1011",
		"1100", "1101", "1110", "1111"
	};
	FILE *file;
	unsigned char buffer[BUF_LEN];
	unsigned char a, b;
	int i, j;
	long long int count = 0;
	
	if (file = fopen(argv[1], "rb")) {
		printf("Path: %s\n", argv[1]);
		while (i = fread(buffer, 1, BUF_LEN, file)) {
			for (j = 0; j < i; j++) {
				a = buffer[j] >> 4;
				b = buffer[j] << 4;
				b = b >> 4;
				printf("%s%s ", bin_list[a], bin_list[b]);
				count++;
			}
			//sleep(1);
		}
		fclose(file);
		printf("\nFile size: %lld bytes\n", count);
		system("pause");
	}
	
	return 0;
}