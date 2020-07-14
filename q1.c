#include <stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
  char c;
  FILE *inputfile,*outputfile;
  int key = atoi(argv[1]);
  inputfile = fopen(argv[2],"r");
  outputfile = fopen(argv[3],"w");

  while((c = fgetc(inputfile))!=EOF){
  char ch =(char)c;

  if (ch>='A'&&ch<='Z')
  ch+=32;

  if(ch>='a'&& ch<='z')
{
  ch = 97 + (ch + key - 97)%26;
  fprintf(outputfile,"%c",ch);
}
  else
  fprintf(outputfile,"%c",(char)c);
  }
fclose(inputfile);
fclose(outputfile);
return 0;
}

