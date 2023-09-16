#pragma once

#include <string>

namespace Mirim {
namespace Lexer {

enum TokenKind {
  illegal,
  eof,

  identifier,

  keyword,

  lParenthesis,
  rParenthesis,
};

/**
 * A piece of text, which holds a specific meaning for the compilation process.
 */
class Token {
public:
  Token(TokenKind kind, std::string value);

private:
  TokenKind kind;
  std::string value;
};

} // namespace Lexer
} // namespace Mirim