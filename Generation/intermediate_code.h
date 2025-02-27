#ifndef INTERMEDIATE_CODE_H
#define INTERMEDIATE_CODE_H

typedef enum { ADD, SUB, MUL, DIV, ASSIGN, GOTO, IF, LABEL, PRINT } OpCode;

typedef struct {
  OpCode op;
  char *arg1;
  char *arg2;
  char *result;
} Instruction;

extern Instruction code[];
extern int codeSize;

void addInstruction(OpCode op, char *arg1, char *arg2, char *result);
void printIntermediateCode();

#endif // INTERMEDIATE_CODE_H