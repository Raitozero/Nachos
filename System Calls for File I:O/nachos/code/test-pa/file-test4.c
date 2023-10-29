#include "syscall.h"

int tostring(char str[], int num) {
    int i = 0, j = 0, len;
    int isNegative = 0;
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }
    while(num){
        str[i++] = num % 10 + '0';
        num /= 10;
    }
    if (isNegative) {
        str[i++] = '-';
    }
    str[i] = '\0';
    len = i;
    for (; j < i / 2; j++) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
    return len;
}
int
main()
{
  OpenFileId outfile0; 
 char buffer[100];
 char* str = "Hello from file-test4\n";
 int i,j;
 int numRead = 0, numRead1 = 0, numClose = 0, numClose1 = 0;
 int length = 0;
 if (Create("file-test4.txt") == -1) {
     Exit(1);
  }
  outfile0 = Open("file-test4.txt");
  Write(str, 22, outfile0);
  Close(outfile0);
  outfile0 = Open("file-test4.txt");
  //Case1: Read() Correctly && Close() Correctly
  numRead = Read(&buffer, 22, outfile0);
  if(numRead >=0){
	   char num2stringBuffer[100];
	   char num2stringBuffer1[100]; 
	   Write("Read(): Successful: read ", 25, ConsoleOutput);
	   length = tostring(&num2stringBuffer, numRead);
	   Write(&num2stringBuffer, length, ConsoleOutput);
	   Write("\n", 1, ConsoleOutput);
	   if((numClose = Close(outfile0)) == 1){
		   Write("Close(): Successful: returned ", 30, ConsoleOutput);
		   length = tostring(&num2stringBuffer1, numClose);
		   Write(&num2stringBuffer1, length, ConsoleOutput);
		   Write("\n", 1, ConsoleOutput);
	   }
	   else{
                   Write("Close(): Failed: returned ", 26, ConsoleOutput);
                   length = tostring(&num2stringBuffer1, numClose);
		   Write(&num2stringBuffer1, length, ConsoleOutput);
		   Write("\n", 1, ConsoleOutput);
	   }
  }
  //Case2: Read() Error && Close() Error
  numRead = Read(&buffer, 22, outfile0);
  if(numRead == -1){
          char num2stringBuffer[100];
	  char num2stringBuffer1[100];
	  Write("Read(): Failed: returned ", 25, ConsoleOutput);
	  length = tostring(&num2stringBuffer, numRead);
  	  Write(&num2stringBuffer, length, ConsoleOutput);
  	  Write("\n", 1, ConsoleOutput);
	  if((numClose = Close(outfile0)) == 1){
                   Write("Close(): Successful: returned ", 30, ConsoleOutput);
                   length = tostring(&num2stringBuffer1, numClose);
                   Write(&num2stringBuffer1, length, ConsoleOutput);
                   Write("\n", 1, ConsoleOutput);
           }
           else{
                   Write("Close(): Failed: returned ", 26, ConsoleOutput);
                   length = tostring(&num2stringBuffer1, numClose);
                   Write(&num2stringBuffer1, length, ConsoleOutput);
                   Write("\n", 1, ConsoleOutput);
           }
  }
  Exit(0);
}


