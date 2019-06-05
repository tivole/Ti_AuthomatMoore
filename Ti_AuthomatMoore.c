// (c) Tivole

#include <stdio.h>
#include <string.h>

int Find_Alphabet_Letters(char*, char*);
int Compare_String(char*, char*, int, int);

int main(void) {

	char Program_Name[128], File_Name[128], word[128], Word_For_Comparison[128], alphabet[128];
	int i, j, k, Length_Of_Word, Length_Of_WFC, Length_Of_Alphabet, Max_i;


	// Cheking for data
	printf("Enter a word to search for: ");
	scanf("%s", word);
	printf("Enter the file name with the symbols (E.g.: XXX.txt): ");
	scanf("%s", File_Name);
	printf("Enter the file name for the final program (E.g.: XXX.c): ");
	scanf("%s", Program_Name);

	FILE *Program = fopen(Program_Name, "w");

	// Writing a new program
	fprintf(Program, "%s%s", "// (c) Tivole\n\n// ", word);
	fprintf(Program, "%s", "\n\n#include <stdio.h>\n\nint main(void) {\n\n\tchar letter;\n\tint cond = 0, Num_Of_Found_Words = 0;\n\n");
	fprintf(Program, "%s%s%s", "\tFILE *Symbols = fopen(\"", File_Name,"\", \"r\");\n\n\tif(!Symbols) {\n\t\tprintf(\"(!) Error while opening file. Perhaps it does not exist.\\n\");\n\t\treturn 1;\n\t}");
	fprintf(Program, "%s", "\n\n\twhile(fscanf(Symbols, \"%c\", &letter) == 1) {\n");

	// Starting of algorithm
	Length_Of_Word = strlen(word);
	Length_Of_Alphabet = Find_Alphabet_Letters(word, alphabet);

	// Number of conditions is must be equal to Length_Of_Word
	for(i = 0; i < Length_Of_Word; i++) {

		// Copy 'word' to 'Word_For_Comparison'
		for(j = 0; j < Length_Of_Word; j++)
			Word_For_Comparison[j] = word[j];

		// We will compare words only with this length
		Length_Of_WFC = i+1;

		for(j = 0; j < Length_Of_Alphabet; j++) {
			Word_For_Comparison[i] = alphabet[j];
			Max_i = 0;

			for(k = 1; k < Length_Of_WFC; k++) {
				if(Compare_String(word, Word_For_Comparison, Length_Of_WFC-k, k) == 1)
					Max_i = k;
			}

			if(alphabet[j] == word[i]) {
				fprintf(Program, "%s", "\t\t");
				if(i != 0) fprintf(Program, "%s", "else ");
				if(i < Length_Of_Word - 1) {
					fprintf(Program, "%s%d%s%c%s", "if(cond == " , i , " && letter == '" , word[i] , "') cond++; // Simple moment\n");
				}else {
					// The last character
					fprintf(Program, "%s%d%s%c%s%d%s", "if(cond == " , i , " && letter == '", word[i] , "') { cond = ", Max_i , "; Num_Of_Found_Words++; } // Last moment\n" );
				}
			}else {
				if(Max_i != 0) {
					fprintf(Program, "%s", "\t\t");
					if(i != 0) fprintf(Program, "%s", "else ");
					fprintf(Program, "%s%d%s%c%s%d%s", "if(cond == " , i , " && letter == '", alphabet[j] , "') cond = ", Max_i , "; // * Important moment\n");
				}
			}
		}
	}

	if(Length_Of_Word > 1) fprintf(Program, "%s", "\t\telse cond = 0;\n");
	fprintf(Program, "%s", "\t}\n\n\tprintf(\"Num of found words: %d\\n\", Num_Of_Found_Words);\n\n\tfclose(Symbols);\n\n\treturn 0;\n}");
	fclose(Program);
	printf("%s%s%s", "File " , Program_Name , " saved successfully.\n");

	return 0;
}

int Find_Alphabet_Letters(char *word, char *alphabet) {
	int i, j, Length_Of_Alphabet, isRpt;
	Length_Of_Alphabet = 0;
	for(i = 0; word[i]; i++) {
		isRpt = 0;
		for(j = 0; j < i; j++)
			if(word[j] == word[i])
				isRpt = 1;

		if(!isRpt) {
			alphabet[Length_Of_Alphabet] = word[i];
			Length_Of_Alphabet++;
		}
	}
	return Length_Of_Alphabet;
}

int Compare_String(char *word, char *Word_For_Comparison, int left, int n) {
	int i;
	for(i = 0; i < n; i++) {
		if(word[i] != Word_For_Comparison[left+i])
			return 0;
	}
	return 1;
}
