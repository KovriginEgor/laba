#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	FILE *fp, *fo;

	if (argv[1] == NULL) fp = fopen("lab_10_text.txt", "r");
	else fp = fopen(argv[1], "r");
	fo = fopen("output1.txt", "w");
	char str[20];
	char c;
	char t;
	
	while ((t = fgetc(fp)) != EOF) {
		fseek(fp, -1, 1);
		while (((c = fgetc(fp)) != '\n')&&(c != EOF)) {
			fseek(fp, -1, 1);
			fscanf(fp, "%s", &str);
			fprintf(fo,"%8s ", str);
		}
		fprintf(fo,"\n");
	}

	fclose(fp);
	fclose(fo);

	return 0;
}