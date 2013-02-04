typedef struct{
	int *cluster;
	int size;
	int time;
} progression;

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

int pick_a_note(int *scale);

void bias_scale(int **scale, int notes, int bias);

void make_scale(int *scale, int key, int type);
