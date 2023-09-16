#pragma once

#include <string_view>

namespace Mirim {
namespace Lexer {

/**
 * A cursor based lexer, which extracts tokens from a given input.
 */
class Lexer {
public:
  Lexer(std::string_view input);

private:
  std::uint64_t cursor;
  std::string_view input;

  /**
   * Returns the current character and bumps the cursor.
   * If there is no character left, it returns '\0' as EOF.
   */
  auto bump() -> char;

  /**
   * Returns the next character from the input without incrementing the cursor.
   */
  auto peek() const -> char;

  /**
   * Moves the lexer's cursor until a character is reached.
   */
  auto eat_whitespace() -> void;

  /**
   * Determins if the given character is whitespace.
   */
  auto is_whitespace(char input) const -> bool;
};

} // namespace Lexer
} // namespace Mirim