#pragma once

#include "../token/token.hpp"

#include <string_view>

namespace mirim {
namespace tokenizer {

/**
 * A cursor based Tokenizer, which extracts tokens from a given source.
 */
class Tokenizer {
public:
  Tokenizer(std::string_view source);

  /**
   *  Returns the current token.
   */
  auto next() -> token::Token;

private:
  std::uint64_t index;
  std::string_view source;
};

} // namespace tokenizer
} // namespace mirim