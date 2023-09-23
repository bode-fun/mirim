#include "Tokenizer/token.hpp"
#include "Tokenizer/tokenizer.hpp"
#include <string>

#include "catch2/catch_test_macros.hpp"
#include <catch2/catch_all.hpp>

TEST_CASE("Tokenizer skips BOM") {
  auto input = std::string();
  input.push_back(0xEF);
  input.push_back(0xBB);
  input.push_back(0xBF);

  REQUIRE(input.length() == 3);

  auto tokenizer = Mirim::Tokenizer::Tokenizer(input);
  auto tok = tokenizer.next();

  REQUIRE(tok.kind == Mirim::Tokenizer::TokenKind::Eof);
}
