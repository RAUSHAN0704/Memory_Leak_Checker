#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <graphics.h>

#define  OUTPUT_FILE			   "leak_info.txt"

using namespace std;

int main( )
{
	initwindow( 1024 , 728 , "Memory leak checker" );
	setfillstyle(SOLID_FILL, 15);
	setcolor(10);
	settextstyle( TRIPLEX_FONT, HORIZ_DIR, 4 );  
	outtextxy( 180 ,0 , "Welcome to memory leak checker" );
    settextstyle( DEFAULT_FONT, HORIZ_DIR, 2 );
	outstreamxy( 0 , 15 ); 
	char info[100],infile[30];
	char fname1[30],fname2[30];
	int i=0;
	FILE* fp1, *fp2;
	int ch;
	printf("ENTER THE FILE NAME TO BE READ\n");
	gets(infile);
	fp1=fopen(infile,"r");
	if (fp1 == NULL)
       {
      printf("Error while opening the file.\n");
      perror ("Died Here");
      printf("Press any key to exit .....\n");
      getche();
      exit(0);
      }
     strcpy(fname1,infile);
   	 while(fname1[i] != '.')
	           {
                      fname2[i]=fname1[i];
                      i++;
               }
     fname2[i++]='.';
     fname2[i++]='e';
     fname2[i++]='x';
     fname2[i++]='e';
     fname2[i]='\0';
     int j=80,k=0;
      
      setcolor(COLOR(255,100,0));
      outtextxy(0,50,"The Input File/Program is :\n"); 
      for(int m=0;m<100;m++){info[m]='\0';}
      setcolor(15);
      while( ( ch = fgetc(fp1) ) != EOF )
             {
                 info[k++]=ch;
                 if(ch==10)
                            {
                                 outtextxy(0,j,info);
                                 j+=20;
                                 k=0;
                                 for(int m=0;m<100;m++){info[m]='\0';}
                            }     
             }
      settextstyle( TRIPLEX_FONT, HORIZ_DIR, 3 ); 
      setcolor(10);
      outtextxy(0,(j+20),"Output about memory leakage has been stored in leak_info.txt");
      system(fname2);
      fp2=fopen(OUTPUT_FILE,"r");
      printf("The contents of file are :\n");
      while( ( ch = fgetc(fp2) ) != EOF )
             printf("%c",ch);
      printf("Press any key to exit .....\n");
      getche();   
	  return 0;
}
