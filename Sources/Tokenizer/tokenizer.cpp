#include "tokenizer.hpp"
#include "../Token/token.hpp"

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

auto Tokenizer::next() -> Token::Token {
  if (index >= source.length()) {
    return Token::Token(Token::Eof);
  }

  auto ch = source.at(index);

  index += 1;

  // A switch doesn't seem to work.
  if (ch == 0) {
    return Token::Token(Token::Illegal);
  } else if (ch == '+') {
    return Token::Token(Token::Plus);
  } else if (ch == '-') {
    return Token::Token(Token::Minus);
  } else if (ch == '*') {
    return Token::Token(Token::Star);
  } else if (ch == '/') {
    return Token::Token(Token::Slash);
  } else if (ch == '%') {
    return Token::Token(Token::Percent);
  } else if (ch == '=') {
    return Token::Token(Token::Equal);
  } else if (ch == '!') {
    return Token::Token(Token::Bang);
  } else if (ch == '&') {
    return Token::Token(Token::Ampersand);
  } else if (ch == '|') {
    return Token::Token(Token::Pipe);
  } else if (ch == '^') {
    return Token::Token(Token::Caret);
  } else if (ch == '<') {
    return Token::Token(Token::AngleBracketLeft);
  } else if (ch == '>') {
    return Token::Token(Token::AngleBracketRight);
  } else if (ch == ',') {
    return Token::Token(Token::Comma);
  } else if (ch == '.') {
    return Token::Token(Token::Period);
  } else if (ch == ':') {
    return Token::Token(Token::Colon);
  } else if (ch == '#') {
    return Token::Token(Token::Pound);
  } else if (ch == '?') {
    return Token::Token(Token::QuestionMark);
  } else if (ch == '(') {
    return Token::Token(Token::LParen);
  } else if (ch == '[') {
    return Token::Token(Token::LBrack);
  } else if (ch == '{') {
    return Token::Token(Token::LBrace);
  } else if (ch == ')') {
    return Token::Token(Token::RParen);
  } else if (ch == ']') {
    return Token::Token(Token::RBrack);
  } else if (ch == '}') {
    return Token::Token(Token::RBrace);
  } else {
    assert(false && "Token not implemented");
  }
}

} // namespace Tokenizer
} // namespace Mirim