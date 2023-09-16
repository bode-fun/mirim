#include "lexer.hpp"

namespace Mirim {
namespace Lexer {

Lexer::Lexer(std::string_view input) : cursor(0), input(input) {}

auto Lexer::bump() -> char {
  if (this->cursor < this->input.length()) {
    auto current_char = this->input.at(this->cursor);
    this->cursor += 1;
    return current_char;
  }

  return '\0';
}

auto Lexer::peek() const -> char {
  if (this->cursor < this->input.length() - 1) {
    auto next_char = this->input.at(this->cursor + 1);
    return next_char;
  }

  return '\0';
}

auto Lexer::eat_whitespace() -> void {
  while (this->is_whitespace(this->peek())) {
    this->bump();
  }
}

auto Lexer::is_whitespace(char input) const -> bool {
  switch (input) {
  case ' ':
  case '\n':
    return true;
  default:
    return false;
  }
}

} // namespace Lexer
} // namespace Mirim