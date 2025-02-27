#include "codegen.h"
#include "intermediate_code.h"
#include "optimizer.h"
#include <stdio.h>

int main() {
  // Example intermediate code
  addInstruction(ASSIGN, "5", NULL, "a");
  addInstruction(ASSIGN, "10", NULL, "b");
  addInstruction(ADD, "a", "b", "c");
  addInstruction(PRINT, "c", NULL, NULL);

  printf("Intermediate Code:\n");
  printIntermediateCode();

  optimizeCode();

  printf("\nOptimized Intermediate Code:\n");
  printIntermediateCode();

  printf("\nGenerated Target Code:\n");
  generateTargetCode();

  return 0;
}