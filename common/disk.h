#ifndef DISK_H
#define DISK_H

#include <cstdlib>
#include <cstdio>

FILE *disk_file_in;
FILE *disk_file_out;

void disk_open()
{
	disk_file_in = fopen("/file1/useless", "r");
	disk_file_out = tmpfile();
}

void disk_close()
{
	fclose(disk_file_in);
	fclose(disk_file_out);
}

void disk_do()
{
	int t;
	int pos = rand() & 0x3FFFFFFF;
	fseek(disk_file_in, pos, 0);
	fread(&t, sizeof(int), 1, disk_file_in);
	fwrite(&t, sizeof(int), 1, disk_file_out);
}

#endif

