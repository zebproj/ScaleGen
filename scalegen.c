typedef struct{
	int *cluster;
	int size;
	int time;
} progression;

typedef struct{
	int *cluster;
	int size;
	int time;
} cluster;

enum scale_types {
	MAJOR,
	MINOR
};

enum keys {
	KEY_C, KEY_Cis, KEY_Ces,
	KEY_D, KEY_Dis, KEY_Des,
	KEY_E, KEY_Eis, KEY_Ees,
	KEY_F, KEY_Fis, KEY_Fes,
	KEY_G, KEY_Gis, KEY_Ges,
	KEY_A, KEY_Ais, KEY_Aes,
	KEY_B, KEY_Bis, KEY_Bes
};

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
