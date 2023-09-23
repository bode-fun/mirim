#include "tokenizer.hpp"
#include "token.hpp"

#include <cassert>
#include <string_view>

namespace Mirim {
namespace Tokenizer {

Tokenizer::Tokenizer(std::string_view input) : source(input) {
  // Skip UTF-8 BOM if present
  if (this->source.length() >= 3 && this->source.at(0) == (char)0xEF &&
      this->source.at(1) == (char)0xBB && this->source.at(2) == (char)0xBF) {
    this->index = 3;
  } else {
    this->index = 0;
  }
}

auto Tokenizer::next() -> Token {
  if (index >= source.length()) {
    return Token(TokenKind::Eof);
  }

  auto ch = source.at(index);

  index += 1;

  // A switch doesn't seem to work.
  if (ch == 0) {
    return Token(TokenKind::Illegal);
  } else if (ch == '+') {
    return Token(TokenKind::Plus);
  } else if (ch == '-') {
    return Token(TokenKind::Minus);
  } else if (ch == '*') {
    return Token(TokenKind::Star);
  } else if (ch == '/') {
    return Token(TokenKind::Slash);
  } else if (ch == '%') {
    return Token(TokenKind::Percent);
  } else if (ch == '=') {
    return Token(TokenKind::Equal);
  } else if (ch == '!') {
    return Token(TokenKind::Bang);
  } else if (ch == '&') {
    return Token(TokenKind::Ampersand);
  } else if (ch == '|') {
    return Token(TokenKind::Pipe);
  } else if (ch == '^') {
    return Token(TokenKind::Caret);
  } else if (ch == '<') {
    return Token(TokenKind::AngleBracketLeft);
  } else if (ch == '>') {
    return Token(TokenKind::AngleBracketRight);
  } else if (ch == ',') {
    return Token(TokenKind::Comma);
  } else if (ch == '.') {
    return Token(TokenKind::Period);
  } else if (ch == ':') {
    return Token(TokenKind::Colon);
  } else if (ch == '#') {
    return Token(TokenKind::Pound);
  } else if (ch == '?') {
    return Token(TokenKind::QuestionMark);
  } else if (ch == '(') {
    return Token(TokenKind::LParen);
  } else if (ch == '[') {
    return Token(TokenKind::LBrack);
  } else if (ch == '{') {
    return Token(TokenKind::LBrace);
  } else if (ch == ')') {
    return Token(TokenKind::RParen);
  } else if (ch == ']') {
    return Token(TokenKind::RBrack);
  } else if (ch == '}') {
    return Token(TokenKind::RBrace);
  } else {
    assert(false && "Token not implemented");
  }
}

} // namespace Tokenizer
} // namespace Mirim