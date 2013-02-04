#include <stdio.h>
#include <stdlib.h>
#include "scalegen.h"

int main(){
	srand(time(NULL));
	progression chords[4];

	int scale1[7];
	int scale2[7];
	int scale3[7];
	int scale4[7];

	make_scale(scale1, KEY_Ees, MAJOR);
	chords[0].cluster = scale1;
	chords[0].time = 2;
	make_scale(scale2, KEY_E, MAJOR);
	chords[1].cluster = scale2;
	chords[1].time = 1;
	make_scale(scale3, KEY_F, MAJOR);
	chords[2].cluster = scale3;
	chords[2].time = 2;
	make_scale(scale4, KEY_Fis, MAJOR);
	chords[3].cluster = scale4;
	chords[3].time = 1;
	int i, j;
	for (j = 0; j < 4; j++){
		for (i = 0; i < 7; i++){printf("%i\n",*(chords[j].cluster + i));}
	printf("\n");
	}
	int vals[] = {1, 2, 3, 4, 5};
	int numchords = 4;
	int crnt_chrd = 0;
	double dur = 0.25;
	double score_time = 0;
	double counter = 0;
	/*
	while(score_time < 24.0){
		if(counter >= chords[crnt_chrd].time){
			crnt_chrd = (crnt_chrd + 1) % numchords;
			counter = 0;
		}
		printf("i1\t%g\t%g\t%i\t\n",
				score_time,
				dur,
				pick_a_note(chords[crnt_chrd].cluster)
				);
		score_time += dur;
		counter += dur;
	}	
	*/
	return 0;
}
