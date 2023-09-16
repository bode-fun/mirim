#include "token.hpp"

namespace Mirim {
namespace Lexer {

Token::Token(TokenKind kind, std::string value) : kind(kind), value(value) {}

} // namespace Lexer
} // namespace Mirim