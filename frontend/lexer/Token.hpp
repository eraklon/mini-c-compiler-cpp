#ifndef TOKEN_H
#define TOKEN_H

#include <cassert>
#include <string>
#include <unordered_map>

class Token {
public:
  enum TokenKind {
    EndOfFile,
    Invalid,

    Identifier,

    // Numbers
    Integer,
    Real,

    // Operators
    Dot,
    Comma,
    Plus,
    Minus,
    Astrix,
    ForwardSlash,
    Percent,
    Equal,
    LessThan,
    GreaterThan,
    Bang,
    And,
    QuestionMark,

    // Multichar operators
    PlusPlus,
    MinusMinus,
    PlusEqual,
    MinusEqual,
    AstrixEqual,
    ForwardSlashEqual,
    BangEqual,
    GreaterEqual,
    LessEqual,
    DoubleAnd,
    DoubleEqual,
    MinusGreaterThan,
    LessThanLessThan,
    GreaterThanGreaterThan,

    // Symbols
    Colon,
    SemiColon,
    LeftParen,
    RightParen,
    LeftBracet,
    RightBracet,
    LeftCurly,
    RightCurly,

    // Comment
    DoubleForwardSlash,
  
    // Keywords
    For,
    While,
    If,
    Switch,
    Case,
    Default,
    Break,
    Continue,
    Else,
    Return,
    Const,
    Char,
    Int,
    Long,
    Double,
    Unsigned,
    Void,
    Struct,
    Enum,
    Typedef,
  };

  Token() : Kind(Invalid) {}

  Token(TokenKind tk) : Kind(tk) {}

  Token(TokenKind tk, std::string_view sv, unsigned l, unsigned c)
      : Kind(tk), StringValue(sv), LineNumber(l), ColumnNumber(c) {}

  std::string GetString() const { return std::string(StringValue); }
  TokenKind GetKind() const { return Kind; }

  unsigned GetLineNum() const { return LineNumber; }
  unsigned GetColNum() const { return ColumnNumber; }

  std::string ToString() const {
    std::string Result("");
    Result += "\"" + std::string(StringValue) + "\", ";
    Result += "Line: " + std::to_string(LineNumber + 1) + ", ";
    Result += "Col: " + std::to_string(ColumnNumber + 1);
    return Result;
  }

  static std::string ToString(TokenKind tk) {
    switch (tk) {
    case EndOfFile:
      return "End of file";
    case Invalid:
      return "Invalid";
    case Identifier:
      return "Identifier";
    case Integer:
      return "Integer";
    case Real:
      return "Float";
    case Dot:
      return ".";
    case Comma:
      return ",";
    case Plus:
      return "+";
    case Minus:
      return "-";
    case Astrix:
      return "*";
    case ForwardSlash:
      return "/";
    case Percent:
      return "%";
    case Equal:
      return "=";
    case LessThan:
      return "<";
    case GreaterThan:
      return ">";
    case Bang:
      return "!";
    case QuestionMark:
      return "?";
    case PlusPlus:
      return "++";
    case MinusMinus:
      return "--";
    case PlusEqual:
      return "+=";
    case MinusEqual:
      return "-=";
    case AstrixEqual:
      return "*=";
    case ForwardSlashEqual:
      return "/=";
    case BangEqual:
      return "!=";
    case GreaterEqual:
      return ">=";
    case LessEqual:
      return "<=";
    case And:
      return "&";
    case DoubleAnd:
      return "&&";
    case DoubleEqual:
      return "==";
    case MinusGreaterThan:
      return "->";
    case LessThanLessThan:
      return "<<";
    case GreaterThanGreaterThan:
      return ">>";
    case Colon:
      return ":";
    case SemiColon:
      return ";";
    case LeftParen:
      return "(";
    case RightParen:
      return ")";
    case LeftBracet:
      return "[";
    case RightBracet:
      return "]";
    case LeftCurly:
      return "{";
    case RightCurly:
      return "}";
    case DoubleForwardSlash:
      return "//";
    case For:
      return "for";
    case While:
      return "while";
    case If:
      return "if";
    case Switch:
      return "switch";
    case Case:
      return "case";
    case Default:
      return "default";
    case Break:
      return "break";
    case Continue:
      return "continue";
    case Else:
      return "else";
    case Return:
      return "return";
    case Const:
      return "const";
    case Char:
      return "char";
    case Int:
      return "int";
    case Long:
      return "long";
    case Double:
      return "double";
    case Void:
      return "void";
    case Unsigned:
      return "unsigned";
    case Struct:
      return "struct";
    case Enum:
      return "enum";
    case Typedef:
      return "typedef";
    default:
      assert(false && "Unhandled token type.");
      break;
    }
  }

private:
  TokenKind Kind;
  std::string_view StringValue;
  unsigned LineNumber;
  unsigned ColumnNumber;
};

#endif