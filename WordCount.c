#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//计算文件中的字符数 
int countCharacters(FILE *file) {
	int count = 0;
	char c;
	//逐个读取文件中的字符，直到文件结束 
	while ((c = fgetc(file)) != EOF) {
		count++;
	}
	return count;
}

//计算文件中的单词数 
int countWords(FILE *file) {
	int count = 0;
	char word[100];
	//逐个读取文件中的单词，直到文件结束 
	while (fscanf(file, "%s", word) != EOF) {
		count++;
	}
	return count;
}

int main(int argc, char *argv[]) {
	//检查命令行参数的数量是否正确 
	if (argc != 3) {
	printf("Usage: WordCount [parameter] [input_file_name]\n");
	return 1;
	}
	//从命令行参数中提取参数和文件名 
	char *param = argv[1];
	char *fileName = argv[2];
	//打开输入文件 
	FILE *file = fopen(fileName, "r");
	//检查文件是否成功打开 
	if (file == NULL) {
    	printf("Error opening file\n");
    	return 1;
	}
    //根据提供的参数执行相应的操作 
	if (strcmp(param, "-c") == 0) {
		//如果参数是“-c”，调用 countCharacters函数计算字符数并打印结果 
    	int charCount = countCharacters(file);
    	printf("字符数：%d\n", charCount);
	} else if (strcmp(param, "-w") == 0) {
		//如果参数是“-w",调用 countWords函数计算单词书并打印结果 
    	int wordCount = countWords(file);
    	printf("单词数：%d\n", wordCount);
	} else {
    	printf("Invalid parameter\n");
    	return 1;
	}
	//关闭文件并返回成功 
	fclose(file);
	return 0;

}
