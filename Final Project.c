#include <stdio.h>
#include <string.h>
#include <ctype.h>

//fungsi untuk menyimpan struk atau nota belanja user
void cetakNota(char nama[], float totalHarga, float biayaAdmin, int ongkir, float potonganHarga, float totalBayar) {
	
    printf("========= NOTA BELANJA =========\n\n");
    printf("Nama Pembeli\t: %s\n", nama);
    printf("Ongkos Kirim\t: Rp %d,00\n", ongkir);
    printf("Total Harga\t: Rp %.0f,00\n", totalHarga);
    printf("Diskon\t\t: Rp %.0f,00\n", potonganHarga);
    printf("Biaya Admin\t: Rp %.0f,00\n", biayaAdmin);
    printf("Total Bayar\t: Rp %.0f,00\n\n", totalBayar);
    printf("================================\n");
}

//fungsi utama 
int main() {
	//deklarasi variabel untuk fungsi struct untuk katalog barang
	struct Barang {
    char kode[10];
    char nama[50];
    int harga;
	}; 

	//menampilkan katalog barang
    struct Barang barang[10];
    strcpy(barang[0].kode, "B001");
    strcpy(barang[0].nama, "Compact Powder - Wardah");
    barang[0].harga = 82000;

    strcpy(barang[1].kode, "B002");
    strcpy(barang[1].nama, "Compact Powder - YOU");
    barang[1].harga = 45000;

    strcpy(barang[2].kode, "B003");
    strcpy(barang[2].nama, "Cushion - Somethinc");
    barang[2].harga = 150000;
    
 	strcpy(barang[3].kode, "B004");
    strcpy(barang[3].nama, "Cushion - Skintific");
    barang[3].harga = 181000;
    
    strcpy(barang[4].kode, "B005");
    strcpy(barang[4].nama, "Eyeshadow - Pink Flash");
    barang[4].harga = 71000;
    
    strcpy(barang[5].kode, "B006");
    strcpy(barang[5].nama, "Eyeshadow - Make Over");
    barang[5].harga = 85000;
 
    strcpy(barang[6].kode, "B007");
    strcpy(barang[6].nama, "Liptint - Barenbliss");
    barang[6].harga = 67000; 

    strcpy(barang[7].kode, "B008");
    strcpy(barang[7].nama, "Liptint - Implora");
    barang[7].harga = 26000;

    strcpy(barang[8].kode, "B009");
    strcpy(barang[8].nama, "Mascara - Maybeline");
    barang[8].harga = 55000;

    strcpy(barang[9].kode, "B010");
    strcpy(barang[9].nama, "Mascara - Pink Flash");
    barang[9].harga = 28000;
    
    //deklarasi variabel untuk inputan user
    char nama[50];
    char alamat[100];
    int totalBarang;
    float totalHarga;
    int dom;
	int ongkir;
	
	//memulai inputan user
    printf("=== SELAMAT DATANG DI COSMETIC SHOP ===\n\n");
    printf("Silakan masukkan nama Anda: ");
    gets(nama);
    printf("[1. Surabaya]\n[2. Luar Surabaya]\n");
    printf("Pilih domisili Anda : ");
    int cekDomValid = 0; // Boolean untuk mengecek apakah input domisili valid atau tidak
    while (!cekDomValid) {
        scanf("%d", &dom);

        if (dom == 1) {
            ongkir = 0;
            cekDomValid = 1; // Domisili input valid, keluar dari loop
        } else if (dom == 2) {
            ongkir = 15000;
            cekDomValid = 1; // Domisili input  valid, kelir dari loop
        } else {
            printf("Input yang Anda masukkan salah. Silakan coba lagi.\n");
            printf("Pilih domisili Anda: ");
        }
    }
		
    printf("Silakan masukkan alamat lengkap Anda: ");
    getchar(); //membersihkan riwayat inputan dan memberikan inputan baru tanpa menghilangkan hasil dari inputan yang lama
    gets(alamat);
    printf("\n");

	//melakukan perulangan untuk menampilkan katalog barang.
    int i;
    for (i = 0; i < 10; i++) {
        printf("Katalog Barang:\n");
        printf("Kode Barang: %s\n", barang[i].kode);
        printf("Nama Barang: %s\n", barang[i].nama);
        printf("Harga Barang: Rp %d\n", barang[i].harga);
        printf("========================\n");
    }

    printf("Masukkan jumlah barang yang akan dibeli: ");
    scanf("%d", &totalBarang);
    printf("\n");


    char kodeBarang[10];
	
	//perulangan untuk memasukkan kode barang sesuai inputan user	
    for (i = 0; i < totalBarang; i++) { 
	    int kodeValid = 1; // Variabel untuk menandakan apakah kode barang valid
	    while (kodeValid) {
	        printf("Masukkan kode barang ke-%d: ", i + 1); 
	        scanf("%s", &kodeBarang);
	        printf("\n");
	
			//membuat inputan kode user menjadi kapital (kode akan terbaca walau user menginput huruf kecil atau huruf kapital)
	        int k;
	        for (k = 0; k < 10; k++) {
	            kodeBarang[k] = toupper(kodeBarang[k]);
	        }
				
				//menjumlahkan harga semua barang sesuai inoutan user
		        int j;
		        for (j = 0; j < 10; j++) {
		            if (strcmp(kodeBarang, barang[j].kode) == 0) {
		                totalHarga += barang[j].harga;
		                kodeValid = 0; // Kode barang valid, keluar dari loop
		                break;
		            }
	        }
			
			//pengecekan valid kode barang dengan boolean
	        if (kodeValid) {
	            printf("Kode barang tidak valid. Silakan coba lagi.\n");
	        }
    	}
	}

    //deklarasi variabel untuk diskon
	float potonganHarga;
    float diskon;
    if (totalHarga > 250000) {
        diskon = 0.3;
    } 
	else {
        diskon = 0;
    }
    
    //assignment untuk menghitung diskon
    potonganHarga = totalHarga*diskon;

	//deklarasi variabel untuk metode pembayaran
    float biayaAdmin;
    printf("Pilih jenis pembayaran:\n");
    printf("1. COD (Cash On Delivery)\n");
    printf("2. Transfer Bank\n");
    printf("Pilihan anda : ");
    int pilihan;
    scanf("%d", &pilihan);
    printf("\n");
    
	if (pilihan == 1){
		biayaAdmin = 2500;
	}
    else if (pilihan == 2) {
    	biayaAdmin = 0;
        printf("Pilih bank untuk transfer:\n");
        printf("1. Bank BCA\n");
        printf("2. Bank BRI\n");
        printf("3. Bank BNI\n");
        printf("Pilihan Anda : ");
        int bank;
        scanf("%d", &bank);
        printf("\n");
        
// cek valid input
	while(bank!=1 && bank!=2 && bank!=3) {
		printf("Input tidak valid, silahkan pilih kembali!");
		
		printf("Pilih bank untuk transfer:\n");
        printf("1. Bank BCA\n");
        printf("2. Bank BRI\n");
        printf("3. Bank BNI\n");
        printf("Pilihan anda : ");
		scanf("%d", &bank);
        printf("\n");
	}
        switch (bank) {
            case 1:
                biayaAdmin = 5000;
                break;
            case 2:
                biayaAdmin = 7000;
                break;
            case 3:
                biayaAdmin = 10000;
                break;
            default:
                printf("Pilihan bank tidak valid.\n");
                return 0;
        }
    } else if (pilihan != 1) {
        printf("Pilihan pembayaran tidak valid.\n");
        printf("Pilihan anda : ");
        return 0;
    }
    
    //assignment untuk menghitung total harga
	float totalBayar = totalHarga - (totalHarga * diskon) + biayaAdmin + ongkir;
	
	//untuk mengeluarkan nota dalam fungsi void
    cetakNota(nama, totalHarga, biayaAdmin, ongkir, potonganHarga, totalBayar);
    
    return 0;
}

