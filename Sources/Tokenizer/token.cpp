#include "token.hpp"

namespace Mirim {
namespace Tokenizer {

Token::Token(TokenKind::TokenKind kind, std::string value)
    : kind(kind), value(value) {}

} // namespace Tokenizer
} // namespace Mirim