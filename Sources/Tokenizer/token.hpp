#pragma once

#include <cstdint>
#include <string>

namespace Mirim {
namespace Tokenizer {

enum TokenKind : int8_t {
  // Special Tokens
  Illegal,
  Eof,
  Lf,
  Whitespace,
  Comment,
  // End Special Tokens

  // Literals
  Ident,  // main
  Int,    // 1234
  Float,  // 12.34
  Char,   // 'a'
  String, // "abc"
          // TODO: MultilineString // """abc"""
          // TODO: FormatString // `abc ${indent}`
  // End Literals

  // Operators and Delimiters
  Plus,      // +
  PlusEqual, // +=

  Minus,      // -
  MinusEqual, // -=

  Star,      // *
  StarEqual, // *=

  Slash,      // /
  SlashEqual, // /=

  Percent,      // %
  PercentEqual, // %=

  Equal,      // =
  EqualEqual, // ==

  Bang,      // !
  BangEqual, // !=

  Ampersand,          // &
  AmpersandEqual,     // &=
  AmpersandAmpersand, // &&

  Pipe,      // |
  PipeEqual, // |=
  PipePipe,  // ||

  Caret,      // ^
  CaretEqual, // ^=

  AngleBracketLeft,                  // <
  AngleBracketAngleBracketLeft,      // <<
  AngleBracketLeftEqual,             // <=
  AngleBracketAngleBracketLeftEqual, // <<=

  AngleBracketRight,                  // >
  AngleBracketAngleBracketRight,      // >>
  AngleBracketRightEqual,             // >=
  AngleBracketAngleBracketRightEqual, // >>=

  Ellipsis,     // ...
  Comma,        // ,
  Period,       // .
  Colon,        // :
  Pound,        // #
  QuestionMark, // ?

  LParen, // (
  LBrack, // [
  LBrace, // {

  RParen, // )
  RBrack, // ]
  RBrace, // }
  // End Operators and Delimiters

  // Keywords
  Alias, // alias
  Await, // await
  Async, // async
  Break, // break

  Case,     // case
  Catch,    // catch
  Continue, // continue
  Default,  // default
  Defer,    // defer

  Else, // else
  Enum, // enum
  For,  // for
  Fun,  // fun

  If,        // if
  Import,    // import
  Interface, // interface
  Let,       // let

  Of,     // of
  Pub,    // pub
  Return, // return

  Struct, // struct
  Switch, // switch
  Throws, // throws
  Try,    // try

  Var, // var
  // End Keywords
};

/**
 * A piece of text, which holds a specific meaning for the compilation process.
 */
class Token {
public:
  Token(TokenKind kind, std::string value);

private:
  TokenKind kind;
  std::string value;
};

} // namespace Tokenizer
} // namespace Mirim