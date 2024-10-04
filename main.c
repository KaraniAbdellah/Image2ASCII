#include <stdio.h>
#include <stdlib.h>



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
		stbi_load(char *path, int *width, int *height, int *channels, 0);
			- channels: refer to the pixels [RGB || RGBA]
			- 0: oding just RGB & ignore Alpha Channel
	
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
		stbi_write_png(char *path, width, height, channels, img, width * channels);
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
			row 1: [R1, G1, B1 | R2, G2, B2 | R3, G3, B3]
			row 2: [R4, G4, B4 | R5, G5, B5 | R6, G6, B6]
			
*/







int main(int argc, char **argv) {
	
	// Loading the image
	int width, height, channels;
	unsigned char *img = stbi_load("images/youtube.png", &width, &height, &channels, 0);
	if (img == NULL) {
		perror("Failed Loading Image"); exit(1);
	}
	printf("Loading Succefflly\n");
	printf("Info: width = %d, height = %d, channels = %d\n", width, height, channels);
	
	// Saving the image
	stbi_write_png("images/youtube.png", width, height, channels, img, width * channels);
	stbi_write_jpg("images/youtube.jpeg", width, height, channels, img, 100);
	
	// Loop thought image data
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int index = (y * width + x) * channels; // calculate pixel index
			unsigned int r = img[index]; // red value
			unsigned int g = img[index + 1]; // green value
			unsigned int b = img[index + 2]; // blue value
			
			printf("(%d,%d,%d)|", r, g, b);
			// printf("pixel (%d, %d): R--> %d, G--> %d, B--> %d\n", x, y, r, g, b);
		}
		printf("\n");
	}
	
	// Free the memory
	stbi_image_free(img);
	
	
	
	return 0;	
		
}





// the documentation show how you can convert image to grayscale images
// grayscale black & white image
// the goal is to prrint the data image


















