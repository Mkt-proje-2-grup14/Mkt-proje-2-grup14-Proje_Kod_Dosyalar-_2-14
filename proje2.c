#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1. soru değişken tanımlama
int main(){

    char arananKelime[50];
    char *dosyaYolu = "metin.txt";
    char satir[256];
    char kelime[100];

    int satirSayaci = 0;
    int toplamTekrar = 0;    
    int kelimeSayaci =0;
//2. soru dosya açma
   
    FILE *yeni_dosya;
	yeni_dosya = fopen("C:\\Users\\ASUS\\Desktop\\PROJE DOSYASI.txt","r");
	
	printf("ARANACAK KELIMEYI GIRINIZ:");
	scanf("%s",arananKelime);
	
	if (yeni_dosya == NULL){
		printf("DOSYAYA YER AYRILMADIGI ICIN DOSYA ACILAMADI!!!");
		return 1;
	}
	
	while(fscanf(yeni_dosya , "%s" , kelime) != EOF){
		if(strcmp(kelime,arananKelime) == 0){
			kelimeSayaci++;
		}
	}
	
	printf("%s KELIMESI %d KEZ GECIYOR\n",arananKelime,kelimeSayaci);
	
	rewind(yeni_dosya);


    //3. soru dosyayı satır satır okuma
    
    while(fgets(satir, sizeof(satir), yeni_dosya) != NULL){
        satirSayaci++;
        printf("%d. Satir: %s", satirSayaci, satir);                                
    }

    fclose(yeni_dosya);
    return 0;

}
