#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countCharacters(FILE *file) {
int count = 0;
char c;
while ((c = fgetc(file)) != EOF) {
count++;
}
return count;
}

int countWords(FILE *file) {
int count = 0;
char word[100];
while (fscanf(file, "%s", word) != EOF) {
count++;
}
return count;
}

int main(int argc, char *argv[]) {
if (argc != 3) {
printf("Usage: WordCount [parameter] [input_file_name]\n");
return 1;
}
char *param = argv[1];
char *fileName = argv[2];

FILE *file = fopen(fileName, "r");
if (file == NULL) {
    printf("Error opening file\n");
    return 1;
}

if (strcmp(param, "-c") == 0) {
    int charCount = countCharacters(file);
    printf("×Ö·ûÊý£º%d\n", charCount);
} else if (strcmp(param, "-w") == 0) {
    int wordCount = countWords(file);
    printf("µ¥´ÊÊý£º%d\n", wordCount);
} else {
    printf("Invalid parameter\n");
    return 1;
}

fclose(file);
return 0;

}
