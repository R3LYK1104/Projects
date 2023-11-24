#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
//uses ascii values to convert any lowercase letters to uppercase
char cap(char letter) {
	if (letter >= 'a' && letter <= 'z') {
		return (char)(letter - 32);
	}
	return letter;
}
//capetalizes all characters in a given string usinng cap function
char *capall(char *string) {
	for (int i = 0; i < strlen(string); i++) {
		string[i] = cap(string[i]);
	}
	return string;
}
//reverses and capitalizes the given string using capall
char *revCap(char *string) {
	int first = 0;
	int last = strlen(string)-1;
	while (first < last) {
		char temp = string[first];
		string[first] = string[last];
		string[last] = temp;
		first++;
		last--;
	}
	return capall(string);
}
//given a phrase and key array the function will create a copy of the phrase, apply encryption based on the key file, then return the encryped result
char *keyphrz(char *revphrase, char key[26][2]) {
	char phrase[50];
	strcpy(phrase, revphrase);
	char cur;
	int length = strlen(phrase);
	for (int i = 0; i < length; i++) {
		for(int k=0; k<=26; k++) {
			cur = phrase[i];
			if (cur ==  key[k][0]) {
				phrase[i] = cur ^ key[k][1];
			}
		}
		printf("%d, %c\n", phrase[i], revphrase[i]);
	}
	return phrase;
}
//opens a file given an inputted file name using fopen, from there the file is iterated throughout
//using fgets to translate the file to a double array and returns it
char** processFile() {
	char filename[50];
	printf("please enter the name of your key file: ");
	fflush(stdin);
	scanf("%s", filename);
	fflush(stdin);

	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("Failed");
		return 0;
	}
	char keyfile[26][2];

	char line[5];
	int c = 0;

	while (fgets(line, 5, file)) {
		if (line != "\n" && line != 10 && line != NULL) {
			keyfile[c][0] = (char)line[0];
			keyfile[c][1] = (char)line[2];
			c++;
		}
	}
	fclose(file);
	return keyfile;
}
// writes the output of the encrypted text to a given text file, then a decryption key was created to be used with the decryption program
void write(char *file, char *out, char* revCapPrz) {
	FILE* outFl = fopen(file, "w");
	if (outFl == NULL) {
		printf("error opening the file");
		return 0;
	}
	for (int i = 0; i < strlen(out); i++) fprintf(outFl, "%d\n", out[i]);
	fclose(outFl);
	FILE* dec = fopen("decryption.txt", "w");
	for (int i = 0; i < strlen(out); i++) fprintf(dec, "%d,%c\n", out[i], revCapPrz[i]);
	fclose(dec);
}
int main(void) {
	
	char keyarr[26][2];
	strcpy(keyarr, processFile());
	char phrase[50];
	printf("Please enter your phrase: ");
	scanf("%s", phrase);

	char revCapPrz[50];
	strcpy(revCapPrz, revCap(phrase));
	printf("reversed and capitalized phrase: %s\n", revCapPrz);

	char out[50];
	strcpy(out, keyphrz(revCapPrz, keyarr));
	printf("Encyrypted text: ");
	for (int i = 0; i < strlen(out); i++) printf("%d", out[i]);

	char outFile[50];
	printf("\nWhere would you like to print your output: ");
	scanf("%s", outFile);
	write(outFile, out, revCapPrz);
}