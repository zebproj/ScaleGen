typedef struct {
	int *cluster;
	int size;
	int time;
} cluster;

enum scale_types {
	MAJOR,
	MINOR,
	HARMONIC_MINOR,
	MELODIC_MINOR,
	DORIAN,
	PHRYGIAN,
	LYDIAN,
	MIXOLYDIAN,
	MIXOLYDIANb9,
	MIXOLYDIANb9b13,
	MIXOLYDIANb13,
	LOCRIAN,
	/* These scales not yet implemented yet */
	PENTATONIC,
	MINOR_PENTATONIC,
	BLUES,
	WHOLE_TONE,
	CHROMATIC,
	WHOLE_HALF,
	HALF_WHOLE
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

enum accidentals{
	FLAT, SHARP, EN_FLAT, EN_SHARP
};

int pick_a_note(int *scale);

void bias_scale(int **scale, int notes, int bias);

void make_scale(int *scale, int key, int type, int octave);

char* midi_to_string(int n, int accidental);

