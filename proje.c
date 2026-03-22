#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1000
#define MAX_SATIR 1000

// Küçük harfe çevirme fonksiyonu
void toLowerCase(char *str) {
    int i;
    for (i = 0; str[i]; i++) {
        str[i] = (char)tolower((unsigned char)str[i]);
    }
}

int main() {
	
	system("COLOR D");
    
    char dosyaAdi[100];
    char arananKelime[100];
    char satir[MAX_LINE];
    char geciciSatir[MAX_LINE];

    int satirNo = 1;
    int toplamTekrar = 0;
    int bulunanSatirlar[MAX_SATIR];
    int bulunanSatirSayisi = 0;
    int i;

    FILE *dosya;

    printf("Dosya adini giriniz: ");
    if (fgets(dosyaAdi, sizeof(dosyaAdi), stdin) != NULL) {
        dosyaAdi[strcspn(dosyaAdi, "\n")] = 0;
    }

    dosya = fopen(dosyaAdi, "r");
    if (dosya == NULL) {
        printf("HATA: Dosya acilamadi! Dosyanin .c dosyasiyla ayni klasorde oldugundan emin olun.\n");
        return 1;
    }

    printf("Aranacak kelimeyi giriniz: ");
    scanf("%s", arananKelime);

    toLowerCase(arananKelime);

    // Ana döngü: Dosyayý satýr satýr oku
    while (fgets(satir, MAX_LINE, dosya) != NULL) {
        strcpy(geciciSatir, satir);
        toLowerCase(geciciSatir);

        char *ptr = geciciSatir;
        int buSatirdaKacDefa = 0;

        // Kelimeyi satýr içinde ara
        while ((ptr = strstr(ptr, arananKelime)) != NULL) {
            toplamTekrar++;
            buSatirdaKacDefa++;
            ptr += strlen(arananKelime);
        }

        // Eðer kelime bu satýrda geçtiyse yazdýr
        if (buSatirdaKacDefa > 0) {
            if (bulunanSatirSayisi < MAX_SATIR) {
                bulunanSatirlar[bulunanSatirSayisi++] = satirNo;
            }
            printf("%d. satirda '%s' kelimesi %d kez gecti.\n", satirNo, arananKelime, buSatirdaKacDefa);
        }

        satirNo++;
    }

    fclose(dosya);

    // -------- RAPOR --------
    printf("\n========== RAPOR ==========\n");
    printf("Aranan kelime: %s\n", arananKelime);
    printf("Toplam tekrar sayisi: %d\n", toplamTekrar);
    printf("Gectigi farkli satir sayisi: %d\n", bulunanSatirSayisi);

    printf("Gectigi satir numaralari: ");
    for (i = 0; i < bulunanSatirSayisi; i++) {
        printf("%d ", bulunanSatirlar[i]);
    }
    printf("\n===========================\n");

    return 0;
}
