#include <Token/token.hpp>
#include <Tokenizer/tokenizer.hpp>

#include <catch2/catch_test_macros.hpp>

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

  REQUIRE(tok.kind == Mirim::Token::Eof);
}

TEST_CASE("Tokenizer sees 0 byte as an illegal token") {
  auto input = std::string();
  input.push_back(0);

  auto tokenizer = Mirim::Tokenizer::Tokenizer(input);
  auto tok = tokenizer.next();

  REQUIRE(tok.kind == Mirim::Token::Illegal);
}

TEST_CASE("Tokenizer tokenizes single char operators correctly") {
  std::string input = "+-*/%=!&|^<>,.:#?([{)]}";

  auto tokenizer = Mirim::Tokenizer::Tokenizer(input);

  std::vector<Mirim::Token::Token> expected_tokens = {
      Mirim::Token::Token(Mirim::Token::Plus),
      Mirim::Token::Token(Mirim::Token::Minus),
      Mirim::Token::Token(Mirim::Token::Star),
      Mirim::Token::Token(Mirim::Token::Slash),

      Mirim::Token::Token(Mirim::Token::Percent),
      Mirim::Token::Token(Mirim::Token::Equal),
      Mirim::Token::Token(Mirim::Token::Bang),
      Mirim::Token::Token(Mirim::Token::Ampersand),

      Mirim::Token::Token(Mirim::Token::Pipe),
      Mirim::Token::Token(Mirim::Token::Caret),
      Mirim::Token::Token(Mirim::Token::AngleBracketLeft),
      Mirim::Token::Token(Mirim::Token::AngleBracketRight),

      Mirim::Token::Token(Mirim::Token::Comma),
      Mirim::Token::Token(Mirim::Token::Period),
      Mirim::Token::Token(Mirim::Token::Colon),
      Mirim::Token::Token(Mirim::Token::Pound),
      Mirim::Token::Token(Mirim::Token::QuestionMark),

      Mirim::Token::Token(Mirim::Token::LParen),
      Mirim::Token::Token(Mirim::Token::LBrack),
      Mirim::Token::Token(Mirim::Token::LBrace),

      Mirim::Token::Token(Mirim::Token::RParen),
      Mirim::Token::Token(Mirim::Token::RBrack),
      Mirim::Token::Token(Mirim::Token::RBrace),

      Mirim::Token::Token(Mirim::Token::Eof),
  };

  for (uint32_t i = 0; i <= input.length(); i++) {
    auto provided = tokenizer.next();
    auto expected = expected_tokens.at(i).kind;
    REQUIRE(provided.kind == expected);
  }
}
