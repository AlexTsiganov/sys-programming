#include "sys/statfs.h"
#include "sys/stat.h"
#include "stdio.h"

#define GB (1024 * 1024 * 1024)

int fileSize(char* path)
{
	int result = 0;
	struct stat st;
	stat(path, &st);
	result = st.st_size;
	return result;
}

void printMemoryInfo()
{
	struct statfs info;
	if (statfs("/", &info) == -1)
		printf("error");
	else {
		double total = (double)(info.f_bsize*info.f_blocks) / GB;
		double available = (double)(info.f_bsize*info.f_bfree) / GB;
		double used = total - available;
		double usedPercentage = (used / total) * 100;
		printf("Total : %.2f Gb; ", total);
		printf("available : %.2f Gb; ", available);
		printf("used : %.2f Gb (%.2f%%)\n", used, usedPercentage);
	}
}