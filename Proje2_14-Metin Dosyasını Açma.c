#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char kelime[100];
	char aranan_kelime[100];
	int kelime_sayaci = 0;
	
	FILE *yeni_dosya;
	yeni_dosya = fopen("C:\\Users\\ASUS\\Desktop\\PROJE DOSYASI.txt","r");
	
	printf("ARANACAK KELIMEYI GIRINIZ:");
	scanf("%s",aranan_kelime);
	
	if (yeni_dosya == NULL){
		printf("DOSYAYA YER AYRILMADIGI ICIN DOSYA ACILAMADI!!!");
		return 1;
	}
	
	while(fscanf(yeni_dosya , "%s" , kelime) != EOF){
		if(strcmp(kelime,aranan_kelime) == 0){
			kelime_sayaci++;
		}
	}
	
	printf("%s KELIMESI %d KEZ GECIYOR\n",aranan_kelime,kelime_sayaci);
	
	fclose(yeni_dosya);
}
