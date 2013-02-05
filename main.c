#include <stdio.h>
#include <stdlib.h>
#include "scalegen.h"
/*
scalegen: a simple scale generator library.
This is a WIP library for generating many types of scales for use in algorithmic
composition in C. 

At the moment, the make_scale() function can only write 7-note scales to 
arrays of ints as MIDI note numbers.

In the future, I hope to make this function write to a more flexible struct called
"cluster," that will allow for scales with more or less notes in it.
*/
int main(){
	cluster chords[4];

	int scale1[7];
	int scale2[7];
	int scale3[7];
	int scale4[7];

	make_scale(scale1, KEY_C, MAJOR, 4);
	chords[0].cluster = scale1;
	chords[0].time = 2;
	make_scale(scale2, KEY_Des, MAJOR, -1);
	chords[1].cluster = scale2;
	chords[1].time = 1;
	make_scale(scale3, KEY_B, MAJOR, 5) ;
	chords[2].cluster = scale3;
	chords[2].time = 2;
	make_scale(scale4, KEY_E, MINOR, 3);
	chords[3].cluster = scale4;
	chords[3].time = 1;
	int i, j;
	char *note = midi_to_string(66, FLAT);

	printf("\033[1mScales with Flats:\033[0m \n");
	for (j = 0; j < 2; j++){
		printf("Scale %i\n", (j+1));
		for (i = 0; i < 7; i++){
			printf("%s\n",
					midi_to_string(*(chords[j].cluster + i), FLAT));
		}
		printf("\n");
	}
	
	printf("\033[1mScales with Sharps: \033[0m\n");
	for (j = 2; j < 4; j++){
		printf("Scale %i\n", (j+1));
		for (i = 0; i < 7; i++){
			printf("%s\n",
					midi_to_string(*(chords[j].cluster + i), SHARP));
		}
		printf("\n");
	}

	return 0;
}
