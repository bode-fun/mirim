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
  auto result = token::Token(token::Eof);

  if (index >= source.length()) {
    return result;
  }

  auto ch = source.at(index);

  index += 1;

  // A switch doesn't seem to work.
  if (ch == 0) {
    result.kind = token::Illegal;
  } else if (token::is_whitespace(ch)) {
    result = this->next();
  } else if (ch == '+') {
    result.kind = token::Plus;
  } else if (ch == '-') {
    result.kind = token::Minus;
  } else if (ch == '*') {
    result.kind = token::Star;
  } else if (ch == '/') {
    result.kind = token::Slash;
  } else if (ch == '%') {
    result.kind = token::Percent;
  } else if (ch == '=') {
    result.kind = token::Equal;
  } else if (ch == '!') {
    result.kind = token::Bang;
  } else if (ch == '&') {
    result.kind = token::Ampersand;
  } else if (ch == '|') {
    result.kind = token::Pipe;
  } else if (ch == '^') {
    result.kind = token::Caret;
  } else if (ch == '<') {
    result.kind = token::AngleBracketLeft;
  } else if (ch == '>') {
    result.kind = token::AngleBracketRight;
  } else if (ch == ',') {
    result.kind = token::Comma;
  } else if (ch == '.') {
    result.kind = token::Period;
  } else if (ch == ':') {
    result.kind = token::Colon;
  } else if (ch == '#') {
    result.kind = token::Pound;
  } else if (ch == '?') {
    result.kind = token::QuestionMark;
  } else if (ch == '(') {
    result.kind = token::LParen;
  } else if (ch == '[') {
    result.kind = token::LBrack;
  } else if (ch == '{') {
    result.kind = token::LBrace;
  } else if (ch == ')') {
    result.kind = token::RParen;
  } else if (ch == ']') {
    result.kind = token::RBrack;
  } else if (ch == '}') {
    result.kind = token::RBrace;
  } else {
    assert(false && "Token not implemented");
  }

  return result;
}

} // namespace tokenizer
} // namespace mirim