# Monty - The Monty language

Monty 0.98 is a scripting language that compiles into Monty byte codes (similar to Python). It relies on a unique stack with specific instructions for manipulation. The goal of this project is to create an interpreter for Monty ByteCodes files.

---

## Requirements:

   - Allowed editors: vi, vim, emacs
   - Compilation on Ubuntu 20.04 LTS using gcc with options -Wall -Werror -Wextra -pedantic
   - All files should end with a new line
   - A mandatory README.md file at the root of the project folder
   - Code should follow the Betty style, checked using betty-style.pl and betty-doc.pl
   - Allowed to use a maximum of one global variable
   - No more than 5 functions per file
   - Allowed to use the C standard library
   - Prototypes of functions should be included in the header file called monty.h
   - Don't forget to push your header file
   - All header files should be include guarded
   - Tasks are expected to be completed in the order shown in the project

---

## Data Structures:

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

---

## Compilation & Output:

$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty

---

## Task:

## 0. push, pall

  Implement the push and pall opcodes.
The push opcode

   -  Usage: push <int>
    <int> is an integer
    If <int> is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE

The pall opcode

    Usage: pall
    Format: see example
    If the stack is empty, don't print anything

### Example:
$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
$ ./monty bytecodes/00.m
3
2
1

---
## 1.pint

Implement the pint opcode.

   -  Usage: pint
   -  If the stack is empty, print the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE

### Example:
$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
$ ./monty bytecodes/06.m 
1
2
3

---
## 2. pop

Implement the pop opcode.

   - Usage: pop
   - If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE

### Example:
$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
$ ./monty bytecodes/07.m 
3
2
1
2
1
1

---
## 3.swap

Implement the swap opcode.

   - Usage: swap
   - If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE

### Example:
$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
$ ./monty bytecodes/09.m 
3
2
1
2
3
1

---
## 4. add

Implement the add opcode.

   -  Usage: add
   - If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
   - The result is stored in the second top element of the stack, and the top element is removed

### Example:
$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall
$ ./monty bytecodes/12.m 
3
2
1
5
1

---
### 5.nop

Implement the nop opcode.

   - Usage: nop
   - Doesn't do anything

---

## Collaborators:

    Angelo Garcia
    Yahsai Santana


