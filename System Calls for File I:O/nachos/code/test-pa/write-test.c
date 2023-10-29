#include "syscall.h"

int
main()
{
  OpenFileId output = ConsoleOutput;

  char* str = "Name: Shu Li Date: 04/24/2023\n";
  
  int i,j;
  for (i = 0; i < 10; i++)
  {
    Write(str, 30, output);
    for (j = 0; j < 10000; j++);
  }

  Exit(0);
}

