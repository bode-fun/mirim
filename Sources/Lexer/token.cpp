#include <string>

enum TokenKind {
  illegal,
  eof,

  identifier,

  keyword,

  lParenthesis,
  rParenthesis,
};

class Token {
public:
  TokenKind kind;
  std::string value;

  Token(TokenKind kind, std::string value) : kind(kind), value(value) {}
};
