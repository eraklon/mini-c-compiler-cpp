#ifndef PPTOKEN_H
#define PPTOKEN_H

#include <cassert>
#include <string>
#include <unordered_map>

class PPToken {
public:
  enum PPTokenKind {
    EndOfFile,
    Invalid,

    Identifier,
    
    // Symbols
    Dot,
    Colon,
    Hashtag,
    LeftParen,
    RightParen,
    DoubleQuote,
    
    // Keywords
    Define,
    Include,
  };

  PPToken() : Kind(Invalid) {}

  PPToken(PPTokenKind tk) : Kind(tk) {}

  PPToken(PPTokenKind tk, std::string_view sv) : Kind(tk), StringValue(sv) {}

  std::string GetString() const { return std::string(StringValue); }
  PPTokenKind GetKind() const { return Kind; }

  std::string ToString() const {
    std::string Result("");
    Result += "\"" + std::string(StringValue) + "\", ";
    return Result;
  }

  static std::string ToString(PPTokenKind tk) {
    switch (tk) {
    case EndOfFile:
      return "End of file";
    case Invalid:
      return "Invalid";
    case Identifier:
      return "Identifier";
    case Dot:
      return ".";
    case Colon:
      return ",";
    case Hashtag:
      return "#";
    case LeftParen:
      return "(";
    case RightParen:
      return ")";
    case DoubleQuote:
      return "\"";
    case Define:
      return "define";
    case Include:
      return "include";

    default:
      assert(false && "Unhandled token type.");
      break;
    }
  }

  bool IsKeyword() const { return Kind >= Define; }

private:
  PPTokenKind Kind;
  std::string_view StringValue;
};

#endif