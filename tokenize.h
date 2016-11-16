#ifndef __TOKENIZE_H__
#define __TOKENIZE_H__

#define LITERAL_LENGTH 16

typedef enum {
  EOI, // End of input
  PLUS,
  MINUS,
  MULTIPLICATION,
  DIVISION,
  BRACE_LEFT,
  BRACE_RIGHT,
  LITERAL,
  NAT // Not a token
} token;

/**
 * Initialize the tokenizer.
 */
void tokenize_init(char *expression);

/**
 * Return the current token.
 */
token get(void);

/**
 * Find next token.
 */
void next(void);

/**
 * If we encounter a literal this function returns its value.
 */
double get_literal(void);

#endif // __TOKENIZE_H__

