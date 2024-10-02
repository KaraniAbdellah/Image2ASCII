#include <stdio.h>


int main(int argc, char **argv) {
	
	if (argc < 2) printf("problem in number of argument\n");
	else {
		printf("The Image is %s\n", argv[1]);
		
		FILE *p_image = fopen(argv[1], "r");
		
		if (p_image == NULL) printf("problem in image\n");
		else {
			printf("We Are Open The Image\n");

			char c;
			int count = 0;
			while ((c = fgetc(p_image)) && c != EOF) {
				printf("%c", c);
				count++;
			}
			printf("Number Of Char That We Read Is %d\n", count);
			
		}
		
		fclose(p_image);
		
	}
	
	
}






