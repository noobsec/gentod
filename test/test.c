#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *gentod_cipher(char string[])
{
	char alpha_lower[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};
	char alpha_upper[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
	char sym_one[] = {64, 59, 39, 36, 51, 95, 38, 45, 56, 40, 41, 47, 63, 33, 57, 48, 49, 52, 35, 53, 55, 58, 50, 34, 54, 42};
	wchar_t sym_two[] = {163, 10003, 174, 8364, 124, 165, 94, 176, 215, 123, 125, 92, 93, 91, 182, 8710, 126, 8226, 162, 8730, 247, 8482, 96, 169, 960, 37};
	int c = 0;

	while(string[c]) {
		for (int i = 0; i < 26; ++i) {
			if (string[c] == alpha_lower[i])
				string[c] = (char) sym_one[i];
			else if (string[c] == alpha_upper[i])
				string[c] = (char) sym_two[i];
			else if (string[c] == sym_one[i])
				string[c] = (char) alpha_lower[i];
			else if (string[c] == sym_two[i])
				string[c] = (char) alpha_upper[i];
			else
				string[c] = string[c];
		}
		c++;
	}

	return string;
}

int main()
{
	char plaintext[] = "hello, world!";
	printf("Plaintext: %s\n", plaintext);
	printf("Gentod cipher: %s\n", gentod_cipher(plaintext));
	return 0;
}