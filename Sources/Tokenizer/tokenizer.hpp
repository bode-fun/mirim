#pragma once

#include "../Token/token.hpp"

#include <string_view>

namespace Mirim {
namespace Tokenizer {

/**
 * A cursor based Tokenizer, which extracts tokens from a given source.
 */
class Tokenizer {
public:
  Tokenizer(std::string_view source);

  /**
   *  Returns the current token.
   */
  auto next() -> Token::Token;

private:
  std::uint64_t index;
  std::string_view source;
};

} // namespace Tokenizer
} // namespace Mirim