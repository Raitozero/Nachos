#include "syscall.h"

int
main()
{
  OpenFileId output = ConsoleOutput;

  char* str = "Hello from exit0\n";
  
  Write(str, 18, output);

  Exit(0);
}
