#include "token.hpp"

namespace mirim {
namespace token {

Token::Token(Kind kind) : kind(kind) {}

auto is_whitespace(char ch) -> bool {
  switch (ch) {
  case ' ':
  case '\n':
  case '\t':
  case '\r':
    return true;
    break;
  default:
    return false;
    break;
  }
}

} // namespace token
} // namespace mirim