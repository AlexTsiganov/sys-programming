#include "lab5static.h"
#include "stdio.h"

int main() 
{
	char* filePath = "/home/alex/Documents/Labs/Lab1/out.txt";
	int size = fileSize(filePath);
	printf("Hello Alex\n");
	printf("%s fileSize: %d bytes\n", filePath, size);
	printMemoryInfo();
	return 0;
}