#include "includes/lexer_tokens_grammar.h"
#include <iostream>

lexer_tokens_grammar::lexer_tokens_grammar
(std::string&& text_code)
{
    text_code_ = std::move(text_code);
    size_text_ = text_code_.size();
}

lexer_tokens_grammar::~lexer_tokens_grammar(){}



token* lexer_tokens_grammar::tokenize_number()
{
    bool float_f = false;
    std::string buffer;

	while ( isdigit( get(0) ) )
	{
		buffer += get(0);
		next(1);	
		if (get(0) == '.')
		{
            std::cout << "float type\n";
            if ( isdigit(get(1)) && !float_f )
            {
                float_f = true;
                buffer += get(0);
                next(1);
            }
            else
            {
                throw "unidefien token .\n"; 
            }
            
        }
	}

    if (float_f)
    {
        return create_token(
            std::move(buffer), TokenType::FLOAT
            );
    }
    return create_token(
        std::move(buffer), TokenType::INT
        );
}


token* lexer_tokens_grammar::tokenize_string()
{
    next(1);
	std::string buffer;
	while (get(0) != '\"')
	{
		buffer += get(0);
		next(1);
	}
	next(1);
	return create_token(std::move(buffer), TokenType::STRING);
}

token* lexer_tokens_grammar::tokenize_char()
{
    next(1);
    std::string buffer;
    buffer += get(0);
    next(1);
    if (get(0) == '\'')
    {
        next(1);
        return create_token(std::move(buffer), TokenType::CHAR);
    }
    else
    {
        return nullptr;
    } 
}

token* lexer_tokens_grammar::tokenize_word()
{
    std::string buffer;
    while (is_word( get(0) ))
    {
        buffer += get(0);
        next(1);
    }
    if (buffer == "def")
    {
        return create_token("def", TokenType::DEF);
    }
    else if (buffer == "while")
    {
        return create_token("while", TokenType::WHILE);
    }
    else if (buffer == "if")
    {
        return create_token("if", TokenType::IF);
    }
     else if (buffer == "else")
    {
        return create_token("else", TokenType::ELSE);
    }
     else if (buffer == "return")
    {
        return create_token("return", TokenType::RET);
    }
     else if (buffer == "break")
    {
        return create_token("break", TokenType::BREAK);
    }
     else if (buffer == "continue")
    {
        return create_token("contine", TokenType::CONTINUE);
    }
    else
    {
        return create_token(std::move(buffer), TokenType::WORD);
    }
    return nullptr;
}

token* lexer_tokens_grammar::tokenzie_operator()
{
    auto firstSimbol = get(0);
    auto secondSimbol = get(1);
    next(1);

    if (is_double_oprt(firstSimbol) && is_oprt(secondSimbol))
    {
        return double_oprt(firstSimbol);
    }
    else
    {
        return once_oprt(firstSimbol);
    }
    return nullptr;
}

token* lexer_tokens_grammar::double_oprt(const char simbol)
{
std::string buffer;
    buffer += simbol;
    buffer += get(0);
    next(1);

    if (buffer == "==")
    {
        return create_token("==", TokenType::ASSIGN);
    }
    else if (buffer == "!=")
    {
        return create_token("!=", TokenType::NO_EQ);
    }
    else if (buffer == ">=")
    {
        return create_token(">=", TokenType::MORE_EQ);
    }
    else if (buffer == "<=")
    {
        return create_token("<=", TokenType::LESS_EQ);
    }
    else if (buffer == "&&")
    {
        return create_token("&&", TokenType::AND);
    }
    else if (buffer == "||")
    {
        return create_token("||", TokenType::OR);
    }
    return nullptr;
}

token* lexer_tokens_grammar::once_oprt(const char simbol)
{
  switch (simbol)
    {
        case '=' : return create_token("=", TokenType::EQ);
        case '>' : return create_token(">", TokenType::MORE);
        case '<' : return create_token("<", TokenType::LESS);
        case '+' : return create_token("+", TokenType::PLUS);
        case '-' : return create_token("-", TokenType::MINUS);
        case '*' : return create_token("*", TokenType::MULT);
        case '/' : return create_token("/", TokenType::DIV);
        case '(' : return create_token("(", TokenType::LQ);
        case ')' : return create_token(")", TokenType::RQ);
        case '{' : return create_token("{", TokenType::SHAPE_LQ);
        case '}' : return create_token("}", TokenType::SHAPE_RQ);
        case '[' : return create_token("[", TokenType::L_SQUARE);
        case ']' : return create_token("]", TokenType::R_SQUARE);
        case ',' : return create_token(",", TokenType::COMMA);
        default: 
            return nullptr;
    }
    return nullptr;
}

void lexer_tokens_grammar::tokenize_comment()
{
    
    while (get(0) != '\n')
	{
		next(1);
	}
	next(1);
}

char lexer_tokens_grammar::get(const size_t rel_position)
{
     auto position = pos_ + rel_position;
    if (position < 0 || position > size_text_)
    {
        return 0;
    }
    return text_code_[position];
}

void lexer_tokens_grammar::next(const size_t offset)
{
    pos_ += offset;
}

bool lexer_tokens_grammar::is_word(char simbol) const
{
    if (isalpha(simbol))
    {
        return true;
    }
    else if (isdigit(simbol))
    {
        return true;
    }
    else if (simbol == '_')
    {
        return true;
    }
	return false;
}

token* lexer_tokens_grammar::
create_token(std::string&& value, TokenType&& type)
{
    return new token(std::move(value), std::move(type));
}


bool lexer_tokens_grammar::is_double_oprt(char simbol) const
{
switch (simbol)
    {
        case '=' : return true;
        case '!' : return true;
        case '&' : return true;
        case '|' : return true;
        case '>' : return true;
        case '<' : return true;
        default :
            return false;
    }
    return false;
}

bool lexer_tokens_grammar::is_oprt(char simbol) const
{
 switch (simbol)
    {
        case '-' : return true;
        case '+' : return true;
        case '/' : return true;
        case '*' : return true;
        case '=' : return true;
        case '>' : return true;
        case '<' : return true;
        case '!' : return true;
        case '&' : return true;
        case '|' : return true;
        case '[' : return true;
        case ']' : return true;
        case '{' : return true;
        case '}' : return true;
        case '(' : return true;
        case ')' : return true;
        case ',' : return true;
        default : 
            return false;

    }
	return false;
}


bool lexer_tokens_grammar::is_number(char s) const 
{
    return isdigit(s);
}

bool lexer_tokens_grammar::is_string(char s) const 
{
    return s == '\"';
}

bool lexer_tokens_grammar::is_char(char s) const 
{
    return s == '\'';
}

bool lexer_tokens_grammar::is_end(char s) const
{
    return s == '\0';
}

bool lexer_tokens_grammar::is_null_space(char s) const
{
    return isspace(s);
}

bool lexer_tokens_grammar::is_comment(char s) const
{
    return s == '#';
}

bool lexer_tokens_grammar::is_letter(char s) const
{
    return isalpha(s);
}