// Kelompok 18 Komputasi Numerik 01
// Tugas Pemrograman B

#include <stdio.h>
#include <math.h>

// Definisi konstanta 
#define MAX_ITER 100
#define TOLERANCE 1e-6
#define Is 1e-12
#define n 1.0
#define Vt 0.02585
#define R 1000
#define Vs 5.0

// Fungsi Karakteristik Dioda 
double diode_current(double Vd) {
    return Is * (exp(Vd / (n * Vt)) - 1);
}

// Fungsi Persamaan Rangkaian (f(Vd) = 0)
// Berdasarkan KCL: (Vs - Vd)/R - Id(Vd) = 0
double f(double Vd) {
    return (Vs - Vd)/R - diode_current(Vd);
}

// Fungsi Turunan (f'(Vd))
// Turunan dari f(Vd) terhadap Vd
double df(double Vd) {
    return -1/R - (Is/(n*Vt)) * exp(Vd/(n*Vt));
}

// Implementasi Metode Newton-Raphson
void newtonRaphson(double initial_guess) {
    int iter = 0;
    double Vd = initial_guess;
    double error;

    printf("Iter\t Vd (V)\t\t Error\n");
    printf("==============================\n");

    // Loop iterasi utama
    do {
        double f_val = f(Vd);   // Hitung f(Vd)
        double df_val = df(Vd); // Hitung f'(Vd)

        if (fabs(df_val) < 1e-10) { // Cek pembagian dengan nol
            printf("Turunan terlalu kecil. Metode gagal.\n");
            return;
        }

        // Hitung koreksi dan perbarui Vd
        double delta = f_val / df_val; // delta = f(Vd) / f'(Vd)
        Vd = Vd - delta;             // Vd_baru = Vd_lama - delta
        error = fabs(delta);         // Hitung error
        iter++;

        printf("%d\t %.6f\t %.6f\n", iter, Vd, error);

    // Ulangi jika error > toleransi dan iter < maks
    } while (error > TOLERANCE && iter < MAX_ITER);

    printf("\nSolusi konvergen:\n");
    printf("Tegangan dioda (Vd) = %.6f V\n", Vd);
    printf("Arus dioda (Id) = %.6e A\n", diode_current(Vd));
}

// Main
int main() {
    printf("Analisis Rangkaian Doda dengan Metode Newton-Raphson\n");
    printf("===================================================\n");
    printf("Parameter rangkaian: Vs=%.1fV, R=%dOhm\n", Vs, R);
    printf("Parameter dioda: Is=%.1eA, n=%.1f, Vt=%.5fV\n\n", Is, n, Vt);

    double initial_guess = 0.6; // Tebakan awal Vd = 0.6 V
    printf("Tebakan awal Vd = %.1f V\n\n", initial_guess);

    newtonRaphson(initial_guess); // Jalankan metode Newton-Raphson

    return 0;
}

