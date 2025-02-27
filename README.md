# Compiler Phases

A compiler typically goes through the following six phases to translate source code into target code:

1. **Lexical Analysis**:
    - Tokenizes the input source code into a sequence of tokens.
    - Removes whitespace and comments.
    - Identifies keywords, identifiers, literals, and operators.

2. **Syntax Analysis**:
    - Parses the sequence of tokens to generate a parse tree (syntax tree).
    - Ensures the source code follows the correct grammatical structure.
    - Detects syntax errors.

3. **Semantic Analysis**:
    - Checks for semantic errors in the parse tree.
    - Ensures variables are declared before use and type compatibility.
    - Performs type checking and scope resolution.

4. **Intermediate Code Generation**:
    - Translates the syntax tree into an intermediate representation (IR).
    - Simplifies the translation process and makes optimization easier.
    - Common IR forms include three-address code and abstract syntax trees.

5. **Code Optimization**:
    - Improves the intermediate code to make it more efficient.
    - Applies techniques like constant folding, dead code elimination, and loop optimization.
    - Aims to reduce execution time and memory usage.

6. **Code Generation**:
    - Translates the optimized intermediate code into target assembly or machine code.
    - Allocates registers and generates machine-level instructions.
    - Produces the final executable code.

These phases work together to ensure that the source code is correctly and efficiently translated into executable code.

NOTE: Visuals of each phase is provided in the above folders respectively. Technologies used are yacc/bison, flex, and C. So you will need to install and configure them accordingly. Each folder has a Readme file to help run and compile that phase only.