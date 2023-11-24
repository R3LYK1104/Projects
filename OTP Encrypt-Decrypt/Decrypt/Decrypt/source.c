#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//takes a file name and translates the file into a readable integer array
int* readFile(char* filename) {
	FILE* file = fopen(filename, "r");
	char line[5];
	int numz[20] = {0};
	int cur = 0;
	while (fgets(line, 5, file) !=0) {
		numz[cur] = atoi(line);
		cur++;
	}
	fclose(file);
	return &numz;
}
//given the decryption file and the properly formatted array of numbers this function creates
//a variable for the decryption key and uses it to return the origonal phrase reversed
char* unxor(char* keyname, int *nums) {
	FILE* keyFl = fopen(keyname, "r");
	int length = sizeof(nums)+1;
	char read[20];
	char key[sizeof(nums)+1][3];
	char output[sizeof(nums)+2];
	int c =  0;
	char line[20];
	while (fgets(line, 20, keyFl)!=0) {
		int a=0;
		char b=' ';
		sscanf(line, "%d,%c", &a, &b);
		key[c][0] = a;
		key[c][1] = b;
		c++;
	}
	for (int n = 0; n < length+1; n++) {	
		if (n == length) {
			output[n] = 0;
		}
		else {
			output[n] = (int)key[n][1];
		}
	}
	return output;
}
//reverses a given string 
char* reverse(char* revphrase) {
	int first = 0;
	int last = strlen(revphrase) - 1;
	while (first < last) {
		char temp = revphrase[first];
		revphrase[first] = revphrase[last];
		revphrase[last] = temp;
		first++;
		last--;
	}
	return revphrase;
}
int main(void) {
	char decF[50];
	printf("Enter your decryption key file: ");
	scanf("%s", decF);
	char filename[50];
	printf("Enter the file you wish to decrypt: ");
	scanf("%s", filename);
	int* nums = {0};
	nums = readFile(filename);
	int c = 0;
	printf("Encrypted input: ");
	while(nums[c] != 0) {
		printf("%d ", nums[c]);
		c++;
	}
	char revphrase[sizeof(nums) + 2];
	strcpy(revphrase, unxor(decF, &nums));
	printf("\nReversed phrase: %s\n", revphrase);
	printf("Decrypted output: %s", reverse(revphrase));
}