#pragma once

#include "../token/token.hpp"

#include <cstdint>
#include <string_view>

namespace mirim {
namespace tokenizer {

/**
 * @brief A cursor based Tokenizer, which extracts tokens from a given source.
 *
 */
class Tokenizer {
public:
  Tokenizer(std::string_view source);

  /**
   * @brief Returns the current token.
   *
   * @return token::Token
   */
  auto next() -> token::Token;

private:
  std::uint64_t index;
  std::string_view source;
};

} // namespace tokenizer
} // namespace mirim