#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ogrenci {
    int numara;
    char isim[50];
    int yas;
    struct Ogrenci *sonraki;
};

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

void sirala_ve_ekle() {
    int liste[100];
    int i = 0;

    printf("Sayilari girin (-1 girerek bitirin):\n");

    while (1) {
        int sayi;
        scanf("%d", &sayi);

        if (sayi == -1) {
            break;
        }

        liste[i++] = sayi;
    }

    int boyut = i;

    // Tek ve çift sayilari ayirmak için iki ayri liste olusturduk
    int tek_sayilar[boyut];
    int cift_sayilar[boyut];
    int index_tek = 0, index_cift = 0;

    for (i = 0; i < boyut; i++) {
        if (liste[i] % 2 == 1) {
            tek_sayilar[index_tek++] = liste[i];
        } else {
            cift_sayilar[index_cift++] = liste[i];
        }
    }

    // Tek ve çift sayýlarý ayrý ayrý ekrana yazdýrdýk
    printf("Tek Sayilar: ");
    for (i = 0; i < index_tek; i++) {
        printf("%d ", tek_sayilar[i]);
    }
    printf("\n");

    printf("Cift Sayilar: ");
    for (i = 0; i < index_cift; i++) {
        printf("%d ", cift_sayilar[i]);
    }
    printf("\n");
}

void rastgele_siralama() {
    int liste[100];
    int i; 

    
    for (i = 0; i < 100; i++) {
        liste[i] = rand() % 1000; // Rastgele 100 sayý ekledik
    }

    qsort(liste, 100, sizeof(int), compare);

    // Rastgele sýralanmýþ listeyi ekrana yazdýrdýk
    printf("Rastgele Siralanmis Liste: ");
    for (i = 0; i < 100; i++) {
        printf("%d", liste[i]);
        if (i < 99) {
            printf("->");
        }
    }
    printf("\n");
}

void ogrenci_bilgilerini_yazdir(struct Ogrenci ogrenci_listesi[], int boyut) {
    int i; 

    printf("Ogrenci Bilgileri:\n");
    for (i = 0; i < boyut; i++) {
        printf("%d- %s %d\n", ogrenci_listesi[i].numara, ogrenci_listesi[i].isim, ogrenci_listesi[i].yas);
    }
}

struct Ogrenci ogrenci_ara(struct Ogrenci ogrenci_listesi[], int boyut, const char aranan_ad[]) {
    int i; 

    for (i = 0; i < boyut; i++) {
        if (strcmp(ogrenci_listesi[i].isim, aranan_ad) == 0) {
            return ogrenci_listesi[i];
        }
    }

    // Bulunamadý ise boþ bir öðrenci döndürdük
    struct Ogrenci bos_ogrenci = {0, "", 0};
    return bos_ogrenci;
}

void ogrenci_sil(struct Ogrenci ogrenci_listesi[], int *boyut, const char aranan_ad[]) {
    int i, j; 

    for (i = 0; i < *boyut; i++) {
        if (strcmp(ogrenci_listesi[i].isim, aranan_ad) == 0) {
            for (j = i; j < *boyut - 1; j++) {
                ogrenci_listesi[j] = ogrenci_listesi[j + 1];
            }
            (*boyut)--;
            break;
        }
    }
}

void en_uzun_ismi_bul(struct Ogrenci ogrenci_listesi[], int boyut) {
    int i; 
    int max_uzunluk = 0;
    char en_uzun_isim[50];

    for (i = 0; i < boyut; i++) {
        if (strlen(ogrenci_listesi[i].isim) > max_uzunluk) {
            max_uzunluk = strlen(ogrenci_listesi[i].isim);
            strcpy(en_uzun_isim, ogrenci_listesi[i].isim);
        }
    }

    printf("Listedeki en uzun isim: %s\nUzunluk: %d\n", en_uzun_isim, max_uzunluk);
}

int main() {
    int secim;
    int ogrenci_sayisi = 3; 
    struct Ogrenci ogrenci_listesi[] = {
        {1, "Ahmet", 23},
        {2, "Ali", 19},
        {3, "Veli", 22},
    
    };

    printf("Yapmak istediginiz islemi secin:\n");
    printf("1. Tek ve Cift Sayilari Ayirma\n");
    printf("2. Rastgele Sayilari Siralama\n");
    printf("3. Ogrenci Bilgilerini Yazdirma\n");
    printf("4. Ogrenci Ara\n");
    printf("5. Ogrenci Sil\n");
    printf("6. En Uzun Ismi Bulma\n");
    printf("Secim: ");
    scanf("%d", &secim);

    switch (secim) {
        case 1:
            // 1. Soru - Tek ve Cift Sayilari Ayirma
            sirala_ve_ekle();
            break;
        case 2:
            // 2. Soru - Rastgele Sayilari Siralama
            rastgele_siralama();
            break;
        case 3:
            // 3. Soru - Ogrenci Bilgilerini Yazdirma
            ogrenci_bilgilerini_yazdir(ogrenci_listesi, ogrenci_sayisi);
            break;
        case 4:
            // 4. Soru - Ogrenci Ara
            {
                char aranan_isim[50];
                printf("Aranan ogrenci ismini girin: ");
                scanf("%s", aranan_isim);
                struct Ogrenci aranan_ogrenci = ogrenci_ara(ogrenci_listesi, ogrenci_sayisi, aranan_isim);
                if (aranan_ogrenci.numara != 0) {
                    printf("Bulunan ogrenci: %d- %s %d\n", aranan_ogrenci.numara, aranan_ogrenci.isim, aranan_ogrenci.yas);
                } else {
                    printf("Ogrenci bulunamadi.\n");
                }
            }
            break;
        case 5:
            // 5. Soru - Ogrenci Silme
            {
                char silinecek_isim[50];
                printf("Silinecek ogrenci ismini girin: ");
                scanf("%s", silinecek_isim);
                ogrenci_sil(ogrenci_listesi, &ogrenci_sayisi, silinecek_isim);
                printf("Ogrenci silindi.\n");
            }
            break;
        case 6:
            // 6. Soru - En Uzun Ismi Bulma
            en_uzun_ismi_bul(ogrenci_listesi, ogrenci_sayisi);
            break;
        default:
            printf("Gecersiz secim.\n");
            break;
    }

    return 0;
}

