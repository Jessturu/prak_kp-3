#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function untuk menjalankan permainan secara rekursif
int permainanTebakAngka (int jawaban, int minimum, int maksimum, int *percobaan) {
    int tebakan;

    printf("Masukkin Tebakan Lu (%d - %d): ", minimum, maksimum);
    scanf("%d", &tebakan);

    (*percobaan)++;

    if (tebakan < jawaban) {
        printf("Masih Kekecilan Woi! coba lagi deh.\n");

        // Rekursi: function memanggil dirinya sendiri
        return permainanTebakAngka(
           jawaban,
           minimum,
           maksimum,
           percobaan
    );
    } else if (tebakan > jawaban) {
        printf("Kebesaran Loh Yah! coba lagi deh.\n");

        // Rekursi: function memanggil dirinya sendiri
        return permainanTebakAngka(
            jawaban,
            minimum,
            maksimum,
            percobaan
        );
    } else {
        printf(
            "Yey Benar Juga Lu angkanya %d dalam %d percobaan.\n",
            jawaban,
            *percobaan
        );

        return tebakan;
    }
}

// Function untuk memeberikan penilaian berdasarkan jumlah percobaaan
void tampilkanHasil(int percobaan) {
    if (percobaan <= 5) {
        printf("Keren bos! jago juga lu cepet banget tebakannya!\n");
    } else if (percobaan <= 10) {
        printf("yah boleh lah lumayan skill elu.\n");
    } else {
        printf("cupu banget sih latihan lagi sana cik.\n");
    }
}

// Function untuk menjalankan permainan
void jalankanpermainan() {
    int minimum = 1;
    int maksimum = 100;
    int percobaan = 0;

    // Membuat angka acak antara minimum dan maksimum
    int jawaban = (rand() % (maksimum - minimum + 1)) + minimum;

    printf("======================================================\n");
    printf("                     TEBAK ANGKA WOILAH\n");
    printf("======================================================\n");
    printf("selamat datang ye di permainan gwe\n");
    printf("gua milih angka antara %d dan %d.\n",
        minimum, maksimum);
    // Memanggil function rekursif
    permainanTebakAngka(
        jawaban,
        minimum,
        maksimum,
        &percobaan
    );

    // Memanggil hasilpermainan
    tampilkanHasil(percobaan);

    printf("Nih yang bener tuh: %d\n,", jawaban);
    printf("Lu dah coba segini nih: %d\n", percobaan);
}

//Function utama
int main() {
    // inisialisasi pembangkit angka acak
    srand(time(NULL));

    // Menjalankan permainan
    jalankanpermainan();

    return 0;
}