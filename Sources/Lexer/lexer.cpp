#include "token.hpp"

#include <cstdint>
#include <string>
#include <string_view>

/**
 * A cursor based lexer, which extracts tokens from a given input.
 */
class Lexer {
private:
  std::uint64_t cursor = 0;
  std::string_view input;

  /**
   * Returns the current character and bumps the cursor.
   * If there is no character left, it returns '\0' as EOF.
   */
  char bump() {
    if (this->cursor < this->input.length()) {
      char current_char = this->input.at(this->cursor);
      this->cursor += 1;
      return current_char;
    }

    return '\0';
  }

  /**
   * Returns the next character from the input without incrementing the cursor.
   */
  char peek() {
    if (this->cursor < this->input.length() - 1) {
      char current_char = this->input.at(this->cursor + 1);
      return current_char;
    }

    return '\0';
  }

  /**
   * Moves the lexer's cursor until a character is reached.
   */
  void eat_whitespace() {
    while (this->is_whitespace(this->peek())) {
      this->bump();
    }
  }

  /**
   * Determins if the given character is whitespace.
   */
  static bool is_whitespace(char input) {
    switch (input) {
    case ' ':
    case '\n':
      return true;
    default:
      return false;
    }
  }

public:
  Lexer(std::string_view input) : input(input) {}
};