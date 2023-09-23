#include "Tokenizer/token.hpp"
#include "Tokenizer/tokenizer.hpp"

#include "catch2/catch_test_macros.hpp"

#include <cstdint>
#include <string>
#include <vector>

TEST_CASE("Tokenizer skips BOM at the beginning") {
  auto input = std::string();
  input.push_back(0xEF);
  input.push_back(0xBB);
  input.push_back(0xBF);

  REQUIRE(input.length() == 3);

  auto tokenizer = Mirim::Tokenizer::Tokenizer(input);
  auto tok = tokenizer.next();

  REQUIRE(tok.kind == Mirim::Tokenizer::TokenKind::Eof);
}

TEST_CASE("Tokenizer sees 0 byte as an illegal token") {
  auto input = std::string();
  input.push_back(0);

  auto tokenizer = Mirim::Tokenizer::Tokenizer(input);
  auto tok = tokenizer.next();

  REQUIRE(tok.kind == Mirim::Tokenizer::TokenKind::Illegal);
}

TEST_CASE("Tokenizer tokenizes single char operators correctly") {
  std::string input = "+-*/%=!&|^<>,.:#?([{)]}";

  auto tokenizer = Mirim::Tokenizer::Tokenizer(input);

  std::vector<Mirim::Tokenizer::Token> expected_tokens = {
      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::Plus),
      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::Minus),
      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::Star),
      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::Slash),

      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::Percent),
      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::Equal),
      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::Bang),
      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::Ampersand),

      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::Pipe),
      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::Caret),
      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::AngleBracketLeft),
      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::AngleBracketRight),

      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::Comma),
      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::Period),
      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::Colon),
      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::Pound),
      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::QuestionMark),

      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::LParen),
      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::LBrack),
      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::LBrace),

      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::RParen),
      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::RBrack),
      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::RBrace),

      Mirim::Tokenizer::Token(Mirim::Tokenizer::TokenKind::Eof),
  };

  for (uint32_t i = 0; i <= input.length(); i++) {
    auto provided = tokenizer.next();
    auto expected = expected_tokens.at(i).kind;
    REQUIRE(provided.kind == expected);
  }
}
