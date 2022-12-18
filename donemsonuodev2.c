#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>

void SoruSec(int sayi)
{

    char soruSayisi[21];
    snprintf(soruSayisi, 21, "soru_%d.txt", sayi);

    FILE *dosya = fopen(soruSayisi, "r");

    while (!feof(dosya))
    {
        putchar(fgetc(dosya));
    }

    fclose(dosya);
}

int Rand()
{

    int sayi;

    srand(time(NULL));

    sayi = rand() %21;

    return sayi;
}

char Cevap(int sayi)
{

    char cevaplar[] = {'C', 'D', 'B', 'D', 'B', 'D', 'D', 'A','B','B','C','D','D','C','B','C','D','A','B','A'};

    return cevaplar[sayi - 1];
}

int kontrolDizi[21];

bool kontrol(int sayi, int cikacakSoru)
{

    for (int i = 0; i < 21; i++)
    {
        if (kontrolDizi[i] == sayi)
        {
            return false;
        }
    }
    kontrolDizi[cikacakSoru] = sayi;

    return true;
}

int main()
{
    int paraodulu = 0;
    int cikacakSoru = 0;
    char cevap;
    char kullaniciCevap;
    int soruSayi;

    printf("*******Kim Milyoner Olmak Ister'e hos geldiniz.*******\n");
    Sleep(2000);
    printf("Yarismamiz 20 sorudan olusmaktadir.\n");
    Sleep(2000);
    printf("Ilk soru baraj sorusudur daha sonraki sorularda q yazarak ayrilma hakkiniz bulunmaktadir.\n");
    printf("Dogru bildiginiz her soru sonunda 5000TL para odulu birikecektir \n\n");
    Sleep(2000);
    printf("*******1. SORU*******\n");
    Sleep(2000);

    soruSayi = Rand();
    kontrol(soruSayi, cikacakSoru);
    SoruSec(soruSayi);
    cevap = Cevap(soruSayi);

    do
    {
        printf("\n");
        Sleep(2000);
        printf("Cevabiniz: ");
        scanf("%s", &kullaniciCevap);

        cikacakSoru += 1;
        if (cevap == toupper(kullaniciCevap))
        {
            Sleep(2000);
            printf("Tebrikler! Dogru cevap \n");
            printf("kazandiginiz toplam para:%d", ((cikacakSoru-1)*5000));
            Sleep(2000);
            system("cls");

            if (cikacakSoru == 20)
            {
                printf("Son soruya ulastiniz\n");
                Sleep(2000);
            }

            soruSayi = Rand();
            if (cikacakSoru != 20)
            {
                printf("*******%d. SORU*******\n", cikacakSoru + 1);
                Sleep(2000);
            }
            while (!kontrol(soruSayi, cikacakSoru))
            {
                soruSayi = Rand();
            }
            SoruSec(soruSayi);
            cevap = Cevap(soruSayi);
        }
        else if (kullaniciCevap == 'q' || kullaniciCevap == 'Q')
        {
            Sleep(2000);
            printf("Yarismadan cekildiniz.\n");
            printf("kazandiginiz toplam para: %d", ((cikacakSoru-1)*5000));
            break;
        }
       else 
        {
            if(toupper(kullaniciCevap)!='A' && toupper(kullaniciCevap)!= 'B' && toupper(kullaniciCevap)!='C' && toupper(kullaniciCevap)!='D')
            {
            printf("lutfen gecerli bir cevap sikki deneyin");
                cikacakSoru -=1;
                continue;
         }
            
        
            else{
            Sleep(2000);
            printf("Yanlis cevap ! Elendiniz.Dogru cevap: %c \n", cevap);
            printf("kazandiginiz toplam para: %d", ((cikacakSoru-1)*5000));
            
            break;
            }
        }

    } while (cikacakSoru < 8);  

    return 0;
}