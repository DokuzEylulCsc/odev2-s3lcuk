#include <stdio.h>
#include <string.h>

void sayi_to_roma(){
    int num, rem;
    printf("\n\nSayi: ");
    scanf("%d", &num);
   while(num >= 4000){
      printf("Sayi 4000'den kucuk olmalidir.");
      printf("\n\nSayi: ");
      scanf("%d", &num);
    }
    printf("\n\nRoma Karsiligi: ");        
    while(num != 0)
    {
        if (num >= 1000)
        {
           printf("M");
           num -= 1000;
        }
        else if (num >= 900)
        {
           printf("CM");
           num -= 900;
        }
        else if (num >= 500)
        {           
           printf("D");
           num -= 500;
        }
 
        else if (num >= 400)
        {
           printf("CD");
           num -= 400;
        }
        else if (num >= 100)
        {
           printf("C");
           num -= 100;                       
        }
        else if (num >= 90)
        {
           printf("XC");
           num -= 90;                                              
        }
        else if (num >= 50)
        {
           printf("L");
           num -= 50;                                                                     
        }
        else if (num >= 40)
        {
           printf("XL");           
           num -= 40;
        }
        else if (num >= 10)
        {
           printf("X");
           num -= 10;           
        }
        else if (num >= 9)
        {
           printf("IX");
           num -= 9;                         
        }
        else if (num >= 5)
        {
           printf("V");
           num -= 5;                                     
        }
        else if (num >= 4)
        {
           printf("IV");
           num -= 4;                                                            
        }
        else if (num >= 1)
        {
           printf("I");
           num -= 1;                                                                                   
        }
    }
}

int roma_show(char ch)
{
   int value = 0;

   switch(ch)
   {
      case 'I': value = 1; break;
      case 'V': value = 5; break;
      case 'X': value = 10; break;
      case 'L': value = 50; break;
      case 'C': value = 100; break;
      case 'D': value = 500; break;
      case 'M': value = 1000; break;
      case '\0': value = 0; break;
      default: value = -1;
   }
   return value;
}

void roma_to_sayi(){ 
   int i = 0, num = 0;
   char romanNumber[100];
   printf("Roma Sayisi: ");
   scanf("%s", romanNumber);

   while(romanNumber[ i ])
   {
      if(roma_show(romanNumber[ i ]) < 0 )
      {
         printf("\n[!] Gecersiz Roma Sayisi.\n");
         roma_to_sayi();
      }
      if((strlen(romanNumber) - i ) > 2)
      {
         if(roma_show(romanNumber[ i ]) < roma_show(romanNumber[i + 2]))
         {
            printf("\n[!] Gecersiz Roma Sayisi.\n");
            roma_to_sayi();
         }
      }
      if(roma_show(romanNumber[ i ]) >= roma_show(romanNumber[i + 1]))
         num = num + roma_show(romanNumber[ i ]);
      else
      {
         num = num + (roma_show(romanNumber[i + 1]) - roma_show(romanNumber[ i ]));
         i++;
      }
      i++;
   }
   printf("\nSayi Karsiligi: %d\n", num);
}

void method(){
    int method_input, sayi;
    printf("\n\nLutfen seciniz:\n\n0) SAYI -> ROMA\n1) ROMA -> SAYI\n\n");
    scanf("%d", &method_input);
    if(method_input==0){
        printf("\n");
        sayi_to_roma();
    } else if(method_input==1){
        printf("\n");
        roma_to_sayi();
    } else{
        printf("\n\n[!] Secim bulunamadi.\n");
        method();
    }
}

int main()
{   
    method();
    return 0;
}

/**
KAYNAK:
https://overiq.com/c-examples/c-program-to-convert-a-decimal-number-to-roman-numerals/
http://www.trytoprogram.com/c-examples/c-program-to-convert-roman-number-into-decimal-number/
**/
