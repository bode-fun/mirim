#include "tokenizer.hpp"
#include "../token/token.hpp"

#include <cassert>
#include <string_view>

namespace mirim {
namespace tokenizer {

Tokenizer::Tokenizer(std::string_view input) : source(input) {
  // Skip UTF-8 BOM if present
  if (this->source.length() >= 3 && this->source.at(0) == (char)0xEF &&
      this->source.at(1) == (char)0xBB && this->source.at(2) == (char)0xBF) {
    this->index = 3;
  } else {
    this->index = 0;
  }
}

auto Tokenizer::next() -> token::Token {
  if (index >= source.length()) {
    return token::Token(token::Eof);
  }

  auto ch = source.at(index);

  index += 1;

  // A switch doesn't seem to work.
  if (ch == 0) {
    return token::Token(token::Illegal);
  } else if (ch == '+') {
    return token::Token(token::Plus);
  } else if (ch == '-') {
    return token::Token(token::Minus);
  } else if (ch == '*') {
    return token::Token(token::Star);
  } else if (ch == '/') {
    return token::Token(token::Slash);
  } else if (ch == '%') {
    return token::Token(token::Percent);
  } else if (ch == '=') {
    return token::Token(token::Equal);
  } else if (ch == '!') {
    return token::Token(token::Bang);
  } else if (ch == '&') {
    return token::Token(token::Ampersand);
  } else if (ch == '|') {
    return token::Token(token::Pipe);
  } else if (ch == '^') {
    return token::Token(token::Caret);
  } else if (ch == '<') {
    return token::Token(token::AngleBracketLeft);
  } else if (ch == '>') {
    return token::Token(token::AngleBracketRight);
  } else if (ch == ',') {
    return token::Token(token::Comma);
  } else if (ch == '.') {
    return token::Token(token::Period);
  } else if (ch == ':') {
    return token::Token(token::Colon);
  } else if (ch == '#') {
    return token::Token(token::Pound);
  } else if (ch == '?') {
    return token::Token(token::QuestionMark);
  } else if (ch == '(') {
    return token::Token(token::LParen);
  } else if (ch == '[') {
    return token::Token(token::LBrack);
  } else if (ch == '{') {
    return token::Token(token::LBrace);
  } else if (ch == ')') {
    return token::Token(token::RParen);
  } else if (ch == ']') {
    return token::Token(token::RBrack);
  } else if (ch == '}') {
    return token::Token(token::RBrace);
  } else {
    assert(false && "Token not implemented");
  }
}

} // namespace tokenizer
} // namespace mirim