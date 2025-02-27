#include "optimizer.h"
#include "intermediate_code.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void constantFolding() {
  for (int i = 0; i < codeSize; i++) {
    if (code[i].op == ADD || code[i].op == SUB || code[i].op == MUL ||
        code[i].op == DIV) {
      if (code[i].arg1 && code[i].arg2 && isdigit(code[i].arg1[0]) &&
          isdigit(code[i].arg2[0])) {
        int val1 = atoi(code[i].arg1);
        int val2 = atoi(code[i].arg2);
        int result;
        switch (code[i].op) {
        case ADD:
          result = val1 + val2;
          break;
        case SUB:
          result = val1 - val2;
          break;
        case MUL:
          result = val1 * val2;
          break;
        case DIV:
          result = val1 / val2;
          break;
        default:
          continue;
        }
        char *resStr = malloc(20);
        sprintf(resStr, "%d", result);
        code[i].op = ASSIGN;
        free(code[i].arg1);
        code[i].arg1 = resStr;
        free(code[i].arg2);
        code[i].arg2 = NULL;
      }
    }
  }
}

static void deadCodeElimination() {
  // Basic implementation to remove dead code (not comprehensive)
  for (int i = 0; i < codeSize - 1; i++) {
    if (code[i].op == ASSIGN && code[i + 1].op == ASSIGN &&
        strcmp(code[i].result, code[i + 1].result) == 0) {
      for (int j = i; j < codeSize - 1; j++) {
        code[j] = code[j + 1];
      }
      codeSize--;
      i--;
    }
  }
}

void optimizeCode() {
  constantFolding();
  deadCodeElimination();
}