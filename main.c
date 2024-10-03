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


// Loading Image 
/*
	stbi_load(char *img_path, int *img_width, int *img_height, int *channels, 0);
	channels: 
		Color channels refer to the components of a pixel [RGB || RGBA]
	0:
		means i want to load just RGB & ignore Alpha Channel
		
*/




// NOTE: gcc main.c -o main -lm
// -lm: -lm links the math library for functions [pow] used for calculations [width, height, ...]






int main(int argc, char **argv) {
	
	int width, height, channels;
	unsigned char *img = stbi_load("images/youtube.png", &width, &height, &channels, 0);
	if (img == NULL) {
		perror("Failed Loading Image"); exit(1);
	}
	printf("Loading Succefflly\n");
	printf("Info: width = %d, height = %d, channels = %d\n", width, height, channels);
	
	
	
	return 0;	
		
}















