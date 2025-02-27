#include "codegen.h"
#include "intermediate_code.h"
#include <stdio.h>

void generateTargetCode() {
  for (int i = 0; i < codeSize; i++) {
    switch (code[i].op) {
    case ADD:
      printf("ADD %s, %s, %s\n", code[i].result, code[i].arg1, code[i].arg2);
      break;
    case SUB:
      printf("SUB %s, %s, %s\n", code[i].result, code[i].arg1, code[i].arg2);
      break;
    case MUL:
      printf("MUL %s, %s, %s\n", code[i].result, code[i].arg1, code[i].arg2);
      break;
    case DIV:
      printf("DIV %s, %s, %s\n", code[i].result, code[i].arg1, code[i].arg2);
      break;
    case ASSIGN:
      printf("MOV %s, %s\n", code[i].result, code[i].arg1);
      break;
    case PRINT:
      printf("PRINT %s\n", code[i].arg1);
      break;
    default:
      printf("UNKNOWN INSTRUCTION\n");
      break;
    }
  }
}