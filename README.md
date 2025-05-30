# Numerical Solution of Diode Circuit Using Newton-Raphson Method

```txt
Kelompok 18
- Arsinta Kirana Nisa (2306215980)
- Kharisma Aprilia (2306223244)
- Isyana Trevia Pohaci (2306250592)
- Stevie Nathania Siregar (2306242382)
```

## Deskripsi Program
Program ini adalah implementasi dalam bahasa C untuk menganalisis rangkaian seri sederhana yang terdiri dari sumber tegangan DC (Vs), sebuah resistor (R), dan sebuah dioda (D). Tujuan utama program ini adalah untuk menemukan titik operasi DC (arus dan tegangan) dioda menggunakan metode numerik Newton-Raphson.

Metode Newton-Raphson dipilih karena karakteristik arus-tegangan dioda bersifat non-linear (eksponensial), sehingga penyelesaian analitik langsung untuk tegangan dioda (Vd) dalam rangkaian ini menjadi sulit. Metode ini secara iteratif mencari akar dari fungsi yang merepresentasikan persamaan rangkaian berdasarkan Hukum Arus Kirchhoff (KCL). Berikut rangkaian sederhana yang di analisis:

![diode_circuit_schematic](https://hackmd.io/_uploads/rkDdS4wfle.png)

## Hasil dan Analisis

![output_program](https://hackmd.io/_uploads/HJOmD4Pzgx.png)

![visualisasi iterasi](https://hackmd.io/_uploads/rkcowVwMgl.png)

Berdasarkan hasil iterasi numerik dan visualisasi grafik, metode Newton-Raphson menunjukkan konvergensi yang sangat cepat dalam menemukan titik operasi rangkaian dioda seri. Dimulai dari tebakan awal Vd = 0.6 V, nilai tegangan dioda (Vd) berhasil mendekati solusi stabil hanya dalam 5 iterasi, mencapai nilai akhir Vd ≈ 0.574147 V. Grafik konvergensi menunjukkan kurva Tegangan Dioda (Vd) yang melandai dengan cepat menuju nilai konvergen, sementara kurva Error menurun secara eksponensial mendekati nol pada iterasi ke-5, menunjukkan bahwa perubahan nilai Vd antar iterasi sudah lebih kecil dari toleransi yang ditetapkan (1e-6).

Hasil akhir menunjukkan bahwa pada kondisi rangkaian dengan Vs = 5V dan R = 1 kOhm, titik operasi dioda tercapai pada tegangan Vd ≈ 0.574 V dan arus dioda Id ≈ 4.43 mA (4.425853e-03 A). Kecepatan konvergensi ini membuktikan efektivitas metode Newton-Raphson untuk menyelesaikan persamaan non-linear yang muncul pada analisis rangkaian dioda, meskipun dimulai dari tebakan awal yang cukup dekat namun belum tepat.





