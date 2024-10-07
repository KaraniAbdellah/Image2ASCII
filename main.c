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


// Loading image 
/*

	Goal:
		is to get the image's pixels.
		loading image means copy of image go to memory
	---------------
	How:
		stbi_load(char *img_path, int *width, int *height, int *channels, 0);
			- channels: refer to the pixels [RGB || RGBA]
			- 0: Loding just RGB & ignore Alpha Channel
	
*/

// Compiling: gcc main.c -o main -lm
// -lm: link math.h library 



// Saving image
/*
	
	Goal: 
		after any editing we need to save the new version at disk.
		image save with PNG or JPEG format.
	---------------
	How:
		stbi_write_png(char *path_to_save, width, height, channels, img, width * channels);
			- width: gives the total number of values in one row of the image.
			- channels: each pixles how many valus has [3 || 4]
			- height: number rows in image
			- width * channels: number of values 
		
		stbi_write_jpg("sky2.jpg", width, height, channels, img, 100); 
			- 100: image quality, it arrange from (11 to 100)
		
		stbi_info(char *path, int *width, int *height, int *channels);
			- get just image info
		

*/

// NOTE1: you can load any image format, but you can save it as [PNG || JPEG]
// NOTE2: saving just for keeping the original image before editing.



// Looping thought image data

/*
	Goal:
		is to print each pixel in image
	---------------
	How:
	 	// calculate pixel index
		index = (y * width + x) * channels;
			y * width: get the total number of pixels in all rows
			+ x: add current pixel position in rows
			* channels: find the exact byte position
	---------------
	Visual:
		- we have image with [width: 3 pixels, height: 2 rows, channels: 3(rgb)]
		- real representation:
			row 1: [R1, G1, B1 | R2, G2, B2 | R3, G3, B3] || [0, 1, 2] | [3, 4, 5] | [6, 7, 8]
			row 2: [R4, G4, B4 | R5, G5, B5 | R6, G6, B6]
	---------------
	Convert to Ascii code:
		- to convert we need to:
			--> Brightness Calculation:
				- Brightness is about how light or dark a color looks.
				- To calculate brightness: (red + green + blue) / 3
				- Goal: measure how light or dark each part of image,
					this help to image in ascii code.
			--> Map to Density:
				- Goal: take the brightness value and match
					it into a specific character.
				
			--> Replace Channel: 
				
*/


// Resume
/*
	- Load image
	- Save a copy [PNG || JPEG] 
		[make sure to use a deffrent extention(png --> jpeg || jpeg --> png)]
	- Modify
	- Save a new version 
		[make sure to use the same image name]
*/






int main(int argc, char **argv) {
	
	// Define the variables
	int width, height, channels;
	char density[200] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
	int density_size = strlen(density);
	
	// Load image
	unsigned char *img = stbi_load("images/jerry.png", &width, &height, &channels, 0);
	if (img == NULL) {
		printf("can not load this image\n"); exit(1);
	}
	
	printf("Width = %d, Height = %d, Channels = %d \n", width, height, channels);
	
	// Looping thought image data
	/*
		height: number of lines
		width: number of columns
	*/
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			// Calculation of image pixel's
			int index_pixel = ((i * width) + j) * channels;
			
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


















