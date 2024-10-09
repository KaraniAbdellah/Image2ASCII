#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



// tells the compiler to include the code for loading images from stb_image.h.
#define STB_IMAGE_IMPLEMENTATION
// provides functions to load images.
#include "stb_image/stb_image.h"

// tells the compiler to include the code for saving images from stb_image_write.h.
#define STB_IMAGE_WRITE_IMPLEMENTATION
// provides functions to write or save images.
#include "stb_image/stb_image_write.h"



///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////



int main(int argc, char **argv) {
	
	// Define the variables
	int width, height, channels;
	char density[20] = " .:ioVM@";
	int density_size = strlen(density);
	
	// Load image
	if (argv[1] == NULL) {
		printf("invalid number of argument\n");
	}
	unsigned char *img = stbi_load(argv[1], &width, &height, &channels, 0);
	if (img == NULL) {
		printf("can not load this image\n"); exit(1);
	}
	
	
	// Looping thought image data
	/*
		height: number of lines
		width: number of columns
	*/
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			// Calculation of image pixel's
			int index_pixel = ((i * width) + j) * channels;
			// [R1, G1, B1, R2, G2, B2, R3, G3, B3, ...] --> 0 3 5 ...
			
			// Get channels
			int red = img[index_pixel];
			int green = img[index_pixel + 1];
			int blue = img[index_pixel + 2];

			// Convert to ASCII code
			/*
				256: The highest brightness level
				(k + 1): Checks the next level of brightness
				/ density_size: Divides brightness into equal parts based on how many characters you have.
			*/
			int brightness = (red + green + blue) / 3;
			for (int k = 0; k < density_size; k++) {
				if (brightness < (256 * (k + 1) / density_size)) {
					char asciiChar = density[k];
					printf("%c", asciiChar); usleep(1000);
					break;
				}
			}
		}
		printf("\n");
	}
	
	return 0;	
		
}
















