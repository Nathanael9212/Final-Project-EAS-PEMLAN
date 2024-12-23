#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_HP 50

// Struktur untuk menyimpan data HP
typedef struct {
    char nama[50];
    int harga;
    int ram;
    int memori;
    char jaringan[10];
} HP;

// Fungsi untuk menampilkan detail HP
void tampilkanHP(HP hp) {
    printf("Nama: %s\n", hp.nama);
    printf("Harga: Rp%d\n", hp.harga);
    printf("RAM: %d GB\n", hp.ram);
    printf("Memori: %d GB\n", hp.memori);
    printf("Jaringan: %s\n", hp.jaringan);
    printf("-------------------------\n");
}

// Fungsi untuk mengurutkan data berdasarkan harga (ascending)
void urutkanHP(HP arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].harga > arr[j + 1].harga) {
                HP temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fungsi pencarian dengan jump search
void cariHP(HP arr[], int n, int hargaMin, int hargaMax, int ram, int memori, char* jaringan) {
    int step = (int)sqrt(n); // Langkah melompat
    int prev = 0;
    int ditemukan = 0;

    // Menemukan blok yang sesuai untuk hargaMin
    while (arr[(step < n ? step : n) - 1].harga < hargaMin) {
        prev = step;
        step += (int)sqrt(n);
        if (prev >= n) return;
    }

    // Pencarian linear dalam blok yang relevan
    for (int i = prev; i < (step < n ? step : n); i++) {
        if (arr[i].harga >= hargaMin && arr[i].harga <= hargaMax &&
            arr[i].ram >= ram && arr[i].memori >= memori &&
            strcmp(arr[i].jaringan, jaringan) == 0) {
            tampilkanHP(arr[i]);
            ditemukan = 1;
        }
    }

    if (!ditemukan) {
        printf("Tidak ada HP yang sesuai dengan kriteria tersebut.\n");
    }
}

int main() {
    HP daftarHP[MAX_HP] = {
        {"Samsung Galaxy S24 Ultra", 21999000, 12, 256, "5G"},
        {"Samsung Galaxy S24+", 16999000, 12, 256, "5G"},
        {"Samsung Galaxy S24", 13999000, 8, 256, "5G"},
        {"Samsung Galaxy Z Fold6", 26499000, 12, 256, "5G"},
        {"Samsung Galaxy Z Flip6", 17499000, 8, 256, "5G"},
        {"Samsung Galaxy A15 5G", 3399000, 4, 128, "5G"},
        {"Samsung Galaxy M34 5G", 3999000, 6, 128, "5G"},
        {"Samsung Galaxy M54 5G", 6499000, 8, 256, "5G"},
        {"Samsung Galaxy M33 5G", 3699000, 6, 128, "5G"},
        {"Samsung Galaxy M23 5G", 3499000, 4, 128, "5G"},
        {"iPhone 15 Pro Max", 23249000, 8, 256, "5G"},
        {"iPhone 15 Pro", 19249000, 8, 256, "5G"},
        {"iPhone 15 Plus", 16249000, 6, 128, "5G"},
        {"iPhone 15", 14249000, 6, 128, "5G"},
        {"Xiaomi 14", 11999000, 12, 256, "5G"},
        {"Xiaomi 14 Pro", 14999000, 12, 512, "5G"},
        {"Oppo Find N3", 26999000, 16, 512, "5G"},
        {"Vivo X Fold3 Pro", 26999000, 12, 512, "5G"},
        {"Samsung Galaxy A25 5G", 4099000, 6, 128, "5G"},
        {"Samsung Galaxy A15", 2999000, 4, 64, "4G"},
        {"Samsung Galaxy A06", 1699000, 3, 32, "4G"},
        {"Samsung Galaxy Z Fold5", 21999000, 12, 256, "5G"},
        {"Samsung Galaxy Z Flip5", 13999000, 8, 256, "5G"},
        {"Samsung Galaxy S23 Ultra", 19999000, 12, 512, "5G"},
        {"Samsung Galaxy S23+", 15999000, 8, 512, "5G"},
        {"Samsung Galaxy M15 5G", 2699000, 4, 64, "5G"},
        {"Samsung Galaxy M15", 2499000, 4, 64, "4G"},
        {"Samsung Galaxy A14 5G", 2999000, 4, 128, "5G"},
        {"Samsung Galaxy A13", 2499000, 4, 64, "4G"},
        {"Samsung Galaxy A12", 2199000, 4, 64, "4G"},
        {"Samsung Galaxy A11", 1999000, 3, 32, "4G"},
        {"Samsung Galaxy A10", 1799000, 2, 32, "4G"},
        {"Samsung Galaxy M14 5G", 3199000, 4, 128, "5G"},
        {"Samsung Galaxy M13", 2899000, 4, 64, "4G"},
        {"Samsung Galaxy M12", 2599000, 4, 64, "4G"},
        {"Samsung Galaxy M11", 2299000, 3, 32, "4G"},
        {"Samsung Galaxy M10", 1999000, 2, 32, "4G"},
        {"iPhone 14 Pro Max", 20999000, 6, 256, "5G"},
        {"iPhone 14 Pro", 18999000, 6, 256, "5G"},
        {"iPhone 14 Plus", 15999000, 6, 128, "5G"},
        {"iPhone 14", 13999000, 6, 128, "5G"},
        {"Xiaomi 13", 10999000, 12, 256, "5G"},
        {"Xiaomi 13 Pro", 13999000, 12, 512, "5G"},
        {"Oppo Find N2", 24999000, 16, 512, "5G"},
        {"Vivo X Fold2 Pro", 24999000, 12, 512, "5G"},
        {"Samsung Galaxy A24 5G", 3899000, 6, 128, "5G"},
        {"Samsung Galaxy A14", 2799000, 4, 64, "4G"},
        {"Samsung Galaxy A04s", 1999000, 3, 32, "4G"},
        {"Samsung Galaxy A04", 1799000, 3, 32, "4G"}
    };

    int hargaMin, hargaMax, ram, memori;
    char jaringan[10];

    // Mengurutkan data berdasarkan harga
    urutkanHP(daftarHP, MAX_HP);

    printf("Masukkan rentang harga (min max): ");
    scanf("%d %d", &hargaMin, &hargaMax);

    printf("Masukkan minimal RAM (GB): ");
    scanf("%d", &ram);

    printf("Masukkan minimal memori (GB): ");
    scanf("%d", &memori);

    printf("Masukkan jenis jaringan (4G/5G): ");
    scanf("%s", jaringan);

    printf("\nHP yang sesuai dengan kriteria:\n");
    cariHP(daftarHP, MAX_HP, hargaMin, hargaMax, ram, memori, jaringan);

    return 0;
}
