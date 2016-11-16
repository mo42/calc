#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "tokenize.h"

char *position = NULL;
token next_token;
double literal;

void tokenize_init(char *expression) { position = expression; }

token get(void) { return next_token; }

void next(void) {
  char l[LITERAL_LENGTH];

  if (!*position) {
    next_token = EOI;
  } else {
    while (*position == ' ')
      ++position;
    // Check for the real tokens
    switch (*position) {
    case '\0':
      next_token = EOI;
      break;
    case '+':
      ++position;
      next_token = PLUS;
      break;
    case '-':
      ++position;
      next_token = MINUS;
      break;
    case '*':
      ++position;
      next_token = MULTIPLICATION;
      break;
    case '/':
      ++position;
      next_token = DIVISION;
      break;
    case '(':
      ++position;
      next_token = BRACE_LEFT;
      break;
    case ')':
      ++position;
      next_token = BRACE_RIGHT;
      break;
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '.':
      memset(l, '\0', LITERAL_LENGTH);
      unsigned int i = 0;
      while (*position && (isdigit(*position) || *position == '.') &&
             i < LITERAL_LENGTH) {
        l[i++] = *position++;
      }
      literal = atof(l);
      next_token = LITERAL;
      break;
    default:
      next_token = NAT;
      break;
    }
  }
}

double get_literal(void) { return literal; }
