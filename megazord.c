#define frente OnRev
#define tras OnFwd

#define M_E OUT_C
#define M_D OUT_B
#define M_ED OUT_BC

#define M_D OUT_B
#define M_ED OUT_BC

#define S_E IN_4
#define S_D IN_1
#define preto 45
#define S_F IN_2
int con = 0;

inline void andar() {
	while (con < 5) {
		if (Sensor(S_F) > preto) {
			Wait(500);
			con = con + 1;
		}


		if (Sensor(S_E) <= preto && Sensor(S_D) <= preto) {
			frente(M_ED, 70);


		}
		if (Sensor(S_E) >= preto && Sensor(S_D) >= preto) {
			frente(M_ED, 70);

		}
		if (Sensor(S_E) > preto && Sensor(S_D) <= preto) {

			frente(M_D, 64);
			tras(M_E, 00);
		}

		if (Sensor(S_D) > preto && Sensor(S_E) <= preto) {

			frente(M_E, 64);
			tras(M_D, 00);
		}
		while (con >= 5) {
			Off(OUT_BC);
		}
	}

}
task main() {
	SetSensorLight(IN_1);
	SetSensorLight(IN_4);
	SetSensorLight(IN_2);
	while (true) {
		andar();
	}
}