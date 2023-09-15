#include <cstdint>
#include <string>
#include <string_view>

class Lexer {
private:
  std::uint64_t position = 0;
  std::string_view input;

public:
  Lexer(std::string_view input) : input(input) {}
};