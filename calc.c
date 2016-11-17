#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "tokenize.h"

double expression1(void);
double expression2(void);
double expression3(void);

void die(const char *s) {
  fprintf(stderr, "%s", s);
  exit(1);
}

void consume(token t) {
  if (t == get())
    next();
  else
    die("Syntax error: TODO\n");
}

double expression() {
  double d = expression1();
  while (true) {
    token t = get();
    switch (t) {
    case PLUS:
      next();
      d += expression1();
      break;
    case MINUS:
      next();
      d -= expression1();
      break;
    default:
      return d;
    }
  }
}

double expression1() {
  double d = expression2();
  while (true) {
    token t = get();
    switch (t) {
    case MULTIPLICATION:
      next();
      d *= expression2();
      break;
    case DIVISION:
      next();
      d /= expression2();
      break;
    default:
      return d;
    }
  }
}

double expression2() {
  token t = get();
  switch (t) {
  case MINUS:
    next();
    return -expression2();
  default:
    return expression3();
  }
}

double expression3() {
  double d;
  token t = get();
  switch (t) {
  case BRACE_LEFT:
    next();
    d = expression();
    consume(BRACE_RIGHT);
    break;
  case LITERAL:
    d = get_literal();
    next();
    break;
  default:
    die("Syntax error: expected '(' or a number\n");
    d = 0.0;
    break;
  }
  return d;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return EXIT_FAILURE;
  } else {
    tokenize_init(argv[1]);
    next();
    printf("%f\n", expression());
    return EXIT_SUCCESS;
  }
}

