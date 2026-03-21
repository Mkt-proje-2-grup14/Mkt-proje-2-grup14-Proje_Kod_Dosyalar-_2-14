#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_SATIR 1000

// Küçük harfe çevirme
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char dosyaAdi[100];
    char arananKelime[100];
    char satir[MAX_LINE];
    char geciciSatir[MAX_LINE];

    int satirNo = 1;
    int toplamTekrar = 0;
    int bulunanSatirlar[MAX_SATIR];
    int bulunanSatirSayisi = 0;

    FILE *dosya;

  	printf("Dosya adini giriniz: ");
	fgets(dosyaAdi, sizeof(dosyaAdi), stdin);
	dosyaAdi[strcspn(dosyaAdi, "\n")] = 0;

    if (dosya == NULL) {
       printf("HATA: Dosya acilamadi!\n");
        return 1;
    }

    printf("Aranacak kelimeyi giriniz: ");
    scanf("%s", arananKelime);

    toLowerCase(arananKelime);

    dosya = fopen(dosyaAdi, "r");

    printf("\n--- DOSYA ICERIGI ---\n");

    while (fgets(satir, MAX_LINE, dosya) != NULL) {
        printf("%d. satir: %s", satirNo, satir);

        strcpy(geciciSatir, satir);
        toLowerCase(geciciSatir);

        char *ptr = geciciSatir;
        int buSatirdaVar = 0;

        while ((ptr = strstr(ptr, arananKelime)) != NULL) {
            toplamTekrar++;
            buSatirdaVar = 1;
            ptr += strlen(arananKelime);
        }

        // Eğer bu satırda bulunduysa kaydet
        if (buSatirdaVar) {
            bulunanSatirlar[bulunanSatirSayisi++] = satirNo;
            printf("  -> Bu satirda kelime bulundu!\n");
        }

        satirNo++;
    }

    fclose(dosya);

    // -------- RAPOR --------
    printf("\n========== RAPOR ==========\n");
    printf("Aranan kelime: %s\n", arananKelime);
    printf("Toplam tekrar sayisi: %d\n", toplamTekrar);
    printf("Kelimenin gectigi farkli satir sayisi: %d\n", bulunanSatirSayisi);

    printf("Gectigi satir numaralari: ");
    for (int i = 0; i < bulunanSatirSayisi; i++) {
        printf("%d ", bulunanSatirlar[i]);
    }

    printf("\n===========================\n");

    // -------- BONUS: RAPORU DOSYAYA YAZ --------
    FILE *rapor = fopen("rapor.txt", "w");

    if (rapor != NULL) {
        fprintf(rapor, "========== RAPOR ==========\n");
        fprintf(rapor, "Aranan kelime: %s\n", arananKelime);
        fprintf(rapor, "Toplam tekrar sayisi: %d\n", toplamTekrar);
        fprintf(rapor, "Farkli satir sayisi: %d\n", bulunanSatirSayisi);

        fprintf(rapor, "Satirlar: ");
        for (int i = 0; i < bulunanSatirSayisi; i++) {
            fprintf(rapor, "%d ", bulunanSatirlar[i]);
        }

        fprintf(rapor, "\n===========================\n");
        fclose(rapor);

        printf("\nRapor 'rapor.txt' dosyasina yazildi.\n");
    } else {
        printf("\nRapor dosyasi olusturulamadi.\n");
    }

    return 0;
}
