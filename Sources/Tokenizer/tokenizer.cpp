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
  auto tok = Token(TokenKind::Eof, "");
  return tok;
}

} // namespace Tokenizer
} // namespace Mirim