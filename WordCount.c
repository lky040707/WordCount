#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�����ļ��е��ַ��� 
int countCharacters(FILE *file) {
	int count = 0;
	char c;
	//�����ȡ�ļ��е��ַ���ֱ���ļ����� 
	while ((c = fgetc(file)) != EOF) {
		count++;
	}
	return count;
}

//�����ļ��еĵ����� 
int countWords(FILE *file) {
	int count = 0;
	char word[100];
	//�����ȡ�ļ��еĵ��ʣ�ֱ���ļ����� 
	while (fscanf(file, "%s", word) != EOF) {
		count++;
	}
	return count;
}

int main(int argc, char *argv[]) {
	//��������в����������Ƿ���ȷ 
	if (argc != 3) {
	printf("Usage: WordCount [parameter] [input_file_name]\n");
	return 1;
	}
	//�������в�������ȡ�������ļ��� 
	char *param = argv[1];
	char *fileName = argv[2];
	//�������ļ� 
	FILE *file = fopen(fileName, "r");
	//����ļ��Ƿ�ɹ��� 
	if (file == NULL) {
    	printf("Error opening file\n");
    	return 1;
	}
    //�����ṩ�Ĳ���ִ����Ӧ�Ĳ��� 
	if (strcmp(param, "-c") == 0) {
		//��������ǡ�-c�������� countCharacters���������ַ�������ӡ��� 
    	int charCount = countCharacters(file);
    	printf("�ַ�����%d\n", charCount);
	} else if (strcmp(param, "-w") == 0) {
		//��������ǡ�-w",���� countWords�������㵥���鲢��ӡ��� 
    	int wordCount = countWords(file);
    	printf("��������%d\n", wordCount);
	} else {
    	printf("Invalid parameter\n");
    	return 1;
	}
	//�ر��ļ������سɹ� 
	fclose(file);
	return 0;

}
