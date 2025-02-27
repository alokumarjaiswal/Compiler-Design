#include "intermediate_code.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_SIZE 1000

Instruction code[MAX_CODE_SIZE];
int codeSize = 0;

void addInstruction(OpCode op, char *arg1, char *arg2, char *result) {
  if (codeSize >= MAX_CODE_SIZE) {
    fprintf(stderr, "Error: Intermediate code size exceeded.\n");
    exit(1);
  }
  code[codeSize].op = op;
  code[codeSize].arg1 = arg1 ? strdup(arg1) : NULL;
  code[codeSize].arg2 = arg2 ? strdup(arg2) : NULL;
  code[codeSize].result = result ? strdup(result) : NULL;
  codeSize++;
}

void printIntermediateCode() {
  for (int i = 0; i < codeSize; i++) {
    printf("%d: %d %s %s %s\n", i, code[i].op, code[i].arg1, code[i].arg2,
           code[i].result);
  }
}