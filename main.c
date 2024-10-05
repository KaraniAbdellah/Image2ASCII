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
			row 1: [R1, G1, B1 | R2, G2, B2 | R3, G3, B3]
			row 2: [R4, G4, B4 | R5, G5, B5 | R6, G6, B6]
	---------------
	Convert to Ascii code:
		- to convert we need to:
			--> Brightness Calculation (average of R, G, B value):
			--> Map to Density:
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
	
	// Loading the image
	int width, height, channels;
	unsigned char *img = stbi_load("images/youtube.png", &width, &height, &channels, 0);
	if (img == NULL) {
		perror("Failed Loading Image"); exit(1);
	}
	printf("Loading Succefflly\n");
	printf("Info: width = %d, height = %d, channels = %d\n", width, height, channels);
	
	
	// Saving the image
	// stbi_write_png("images/youtube.png", width, height, channels, img, width * channels);
	// stbi_write_jpg("images/youtube.jpeg", width, height, channels, img, 100);
	// I do not need to save it, because I am going to save an image with a deffrent name

	// Define Variables	
	const char density[40] = "@#B%=+-. ";
	char **ascii_code = (char **) malloc(sizeof(char *) * height);
	for (int i = 0; i < height; i++) {
		ascii_code[i] = (char *) malloc(sizeof(char) * width);
	}
	
	
	// Loop thought image data
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			
			// get the channels
			int pixel_index = (y * width + x) * channels;
			unsigned int red = img[pixel_index];
			unsigned int green = img[pixel_index + 1];
			unsigned int blue = img[pixel_index + 2];
			
			// brightness calculation
			float brightness = 0.299 * red + 0.587 * green + 0.114 * blue;
			
			// Map to density
			int density_size = sizeof(density) - 1;
			int index = (int)(brightness * (density_size - 1) / 255); 
			char ascii_char = density[index];

			// Replace Channel
			img[pixel_index] = ascii_char;
	        img[pixel_index + 1] = ascii_char;
	        img[pixel_index + 2] = ascii_char;
	        
	        // Store ascci_code
	        ascii_code[y][x] = ascii_char;
	        
		}
	}

	
	// Print the ASCII art to the terminal
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
		    printf("%c", ascii_code[y][x]);
		}
		printf("\n");
	}	
	

	// Saving the new image version
	stbi_write_jpg("images/output.jpg", width, height, channels, img, 100);
	
	
	// Free the memory
	stbi_image_free(img);
	
	
	
	return 0;	
		
}




// understand the parts of [brightness, map density, replace]
// write it
// reduce the output

















