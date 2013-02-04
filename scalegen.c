#include "scalegen.h"
#include <stdio.h>
#include <stdlib.h>
char* midi_to_string(int n, int accidental){
	int note = n % 12;
	int octave = (n / 12) - 1;
	int i;
	char *msg;
	msg = malloc(4);
	if(note == 0){
		sprintf(msg, "C-%i", octave);
	}else
	if(note == 2){
		sprintf(msg, "D-%i", octave);
	}else
	if(note == 4){
		sprintf(msg, "E-%i", octave);
	}else
	if(note == 5){
		sprintf(msg, "F-%i", octave);
	}else
	if(note == 7){
		sprintf(msg, "G-%i", octave);
	}else
	if(note == 9){
		sprintf(msg, "A-%i", octave);
	}else
	if(note == 11){
		sprintf(msg, "B-%i", octave);
	}else
	if(note == 1 && accidental==SHARP){
		sprintf(msg, "C#%i", octave);
	}else
	if(note == 3 && accidental==SHARP){
		sprintf(msg, "D#%i", octave);
	}else
	if(note == 5 && accidental==SHARP){
		sprintf(msg, "E#%i", octave);
	}else
	if(note == 6 && accidental==SHARP){
		sprintf(msg, "F#%i", octave);
	}else
	if(note == 8 && accidental==SHARP){
		sprintf(msg, "G#%i", octave);
	}else
	if(note == 10 && accidental==SHARP){
		sprintf(msg, "A#%i", octave);
	}else
	if(note == 1 && accidental==FLAT){
		sprintf(msg, "Db%i", octave);
	}else
	if(note == 3 && accidental==FLAT){
		sprintf(msg, "Eb%i", octave);
	}else
	if(note == 4 && accidental==FLAT){
		sprintf(msg, "Fb%i", octave);
	}else
	if(note == 6 && accidental==FLAT){
		sprintf(msg, "Gb%i", octave);
	}else
	if(note == 8 && accidental==FLAT){
		sprintf(msg, "Ab%i", octave);
	}else
	if(note == 10 && accidental==FLAT){
		sprintf(msg, "Bb%i", octave);
	}else{
		sprintf(msg, "000", octave);
	}
	
	//msg = "hi there!";
	return msg;
}

int pick_a_note(int *scale){
	int n = 0;
	int note = 0;
	/*Get size of array */
	while(*(scale + n) != '\0'){ 
		n ++;
	}
    
	n = n/sizeof(n) + 1;

	//printf("%i\n", n);
	note = *(scale + (rand() % n));
	return note;
}

void bias_scale(int **scale, int notes, int bias){
	int i;

	for(i = 0; i < notes; i++){
		*(*scale + i) = *(*scale + i) + bias;
	}
}

void make_scale(int *scale, int key, int type){

	int i = 0;
	int *base_scale;

	if(type == MAJOR){
	int major_scale[] = {0, 2, 4, 5, 7, 9, 11};
	base_scale = major_scale;
	}else if(type == MINOR){
	int minor_scale[] = {0, 2, 3, 5, 7, 8, 10};
	base_scale = minor_scale;
	}
	
	for(i = 0; i < 7; i++){
		*(scale + i) = *(base_scale + i);
	}

	if(
		key == KEY_C ||
		key == KEY_Bis
	)
		bias_scale(&scale, i, 60);	
	else if(
		key == KEY_Cis ||
		key == KEY_Des
	)
		bias_scale(&scale, i, 61);
	else if(
		key == KEY_D 
	)
		bias_scale(&scale, i, 62);
	else if(
		key == KEY_Ees ||
		key == KEY_Dis
	)
		bias_scale(&scale, i, 63);
	else if(
		key == KEY_E
	)
		bias_scale(&scale, i, 64);
	else if(
		key == KEY_F ||
		key == KEY_Eis
	)
		bias_scale(&scale, i, 65);
	else if(
		key == KEY_Fis ||
		key == KEY_Ges
	)
		bias_scale(&scale, i, 66);
	else if(
		key == KEY_G 
	)
		bias_scale(&scale, i, 67);
	else if(
		key == KEY_Gis  ||
		key == KEY_Aes
	)
		bias_scale(&scale, i, 68);
	else if(
		key == KEY_A 
	)
		bias_scale(&scale, i, 69);
	else if(
		key == KEY_Ais ||
		key == KEY_Bes
	)
		bias_scale(&scale, i, 70);
	else if(
		key == KEY_B
	)
		bias_scale(&scale, i, 71);
}
