#ifndef _TOKEN_TYPE_H_
#define _TOKEN_TYPE_H_


enum class TokenType 
{
    INT,
    FLOAT,
    STRING,
	CHAR,
	
	/* key words */
	WORD, //word name
	DEF,

	WHILE,
	IF,
	ELSE,
	RET,
	BREAK,
	CONTINUE,

	

    /* operators */
	PLUS,		// +
	MINUS,		// -
	MULT,		// *
	DIV,		// /
	
	LQ,			// (
	RQ,			// )
	SHAPE_LQ,	// {
	SHAPE_RQ,	// }
	L_SQUARE,	// [
	R_SQUARE,	// ]

	POINT,		// .
	COMMA,		// ,

	/* logical operators*/
	EQ,			// =
	MORE,		// >
	LESS,		// <
	MORE_EQ,	// >=
	LESS_EQ,	// <=
	ASSIGN,		// ==
	BUT,		// !
	NO_EQ,		// !=
	AND,		// &&
	OR,			// ||

	NULL_TOKEN,
	END_OF_FILE
};


#endif // !_TOKEN_TYPE_H_
