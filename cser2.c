#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
   char c;
   char ceaser2[52];
   FILE *fp;
   int character[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
   int key;
   char calc[9999];
   int index = 0;

  printf("enter the file's name \n");
  memset(ceaser2,0,sizeof(ceaser2));
  fgets(ceaser2,sizeof(ceaser2),stdin); 
  fp = fopen(ceaser2, "r");
 if(fp == NULL){
    error("error in file");
    return(-1);
}
   printf("read file:", ceaser2);
  while((c = fgetc(fp))!= EOF){
  calc[index] = c ;
  index++;
}
  fclose(fp);


  int length = sizeof(calc);
  int i;
  for(i=0; i <length; i++){
   int a = calc[i] -97 ;
   character[a] += 1;
}
  int j, maxIndex1, maxIndex2 , max1 = 0 , max2= 0;
   for( j = 0 ;j < 26;j++){
     if (character[j] > max1) {
        max1 = character[j];
        maxIndex1 = j;
     }
     else if(character[j]<max1 &&character[j]>max2){
         max2 = character[j];
         maxIndex2 = j ;
     }
    }
    key = maxIndex1 -4;
    if (key <0) {
    key +=26;
   }
   printf("key: %d\n", key);
   
   int k;
  for(k=0 ; k<length;k++){
  if((calc[k] >='a'&& calc[k] <='z') || (calc[k]>='A' &&calc[k]<='B')){
    if(calc[k] -key >=97){
       calc[k] -= key;
  }
    else {
      calc[k] = calc[k] +26 -key;
      }
    }
   }
   printf("%s",calc);
   return 0;
}
 
