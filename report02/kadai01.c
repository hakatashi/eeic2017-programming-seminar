#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define TOKEN_PLUS ("Plus")
#define TOKEN_TIMES ("Times")
#define TOKEN_SUBTRACT ("Subtract")
#define TOKEN_DIVIDE ("Divide")
#define TOKEN_SIN ("Sin")
#define TOKEN_COS ("Cos")
#define TOKEN_EXP ("Exp")
#define TOKEN_LOG ("Log")
#define TOKEN_POWER ("Power")

#ifndef MIN
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#endif

#ifndef NAN
#define NAN (0.0 / 0.0)
#endif

enum node_type {
	NODE_NUMBER,
	NODE_PLUS,
	NODE_TIMES,
	NODE_SUBTRACT,
	NODE_DIVIDE,
	NODE_SIN,
	NODE_COS,
	NODE_EXP,
	NODE_LOG,
	NODE_POWER
};

struct node {
	enum node_type type;
	double value;
	struct node *left;
	struct node *right;
	int length;
};

double calc_ast(struct node *ast) {
	double left = 0, right = 0;

	if (ast->left != NULL) {
		left = calc_ast(ast->left);
	}

	if (ast->right != NULL) {
		right = calc_ast(ast->right);
	}

	switch (ast->type) {
		case NODE_NUMBER:
			return ast->value;
			break;
		case NODE_PLUS:
			return left + right;
			break;
		case NODE_SUBTRACT:
			return left - right;
			break;
		case NODE_TIMES:
			return left * right;
			break;
		case NODE_DIVIDE:
			return left / right;
			break;
		case NODE_SIN:
			return sin(left);
			break;
		case NODE_COS:
			return cos(left);
			break;
		case NODE_EXP:
			return exp(left);
			break;
		case NODE_LOG:
			return log(left);
			break;
		case NODE_POWER:
			return pow(left, right);
			break;
	}

	return NAN;
}

struct node *parse_ast(char **tokens) {
	struct node *temp_node = (struct node*)malloc(sizeof(struct node));
	char *token = tokens[0];
	int args = 0;

	if (strcmp(token, TOKEN_PLUS) == 0) {
		temp_node->type = NODE_PLUS;
		args = 2;
	} else if (strcmp(token, TOKEN_TIMES) == 0) {
		temp_node->type = NODE_TIMES;
		args = 2;
	} else if (strcmp(token, TOKEN_SUBTRACT) == 0) {
		temp_node->type = NODE_SUBTRACT;
		args = 2;
	} else if (strcmp(token, TOKEN_DIVIDE) == 0) {
		temp_node->type = NODE_DIVIDE;
		args = 2;
	} else if (strcmp(token, TOKEN_SIN) == 0) {
		temp_node->type = NODE_SIN;
		args = 1;
	} else if (strcmp(token, TOKEN_COS) == 0) {
		temp_node->type = NODE_COS;
		args = 1;
	} else if (strcmp(token, TOKEN_EXP) == 0) {
		temp_node->type = NODE_EXP;
		args = 1;
	} else if (strcmp(token, TOKEN_LOG) == 0) {
		temp_node->type = NODE_LOG;
		args = 1;
	} else if (strcmp(token, TOKEN_POWER) == 0) {
		temp_node->type = NODE_POWER;
		args = 2;
	} else {
		temp_node->type = NODE_NUMBER;

		temp_node->value = atof(token);
		temp_node->left = NULL;
		temp_node->right = NULL;
		temp_node->length = 1;

		return temp_node;
	}

	temp_node->value = NAN;

	if (args == 1) {
		temp_node->left = parse_ast(tokens + 1);
		temp_node->right = NULL;
		temp_node->length = 1 + temp_node->left->length;
	} else if (args == 2) {
		temp_node->left = parse_ast(tokens + 1);
		temp_node->right = parse_ast(tokens + temp_node->left->length + 1);
		temp_node->length = 1 + temp_node->left->length + temp_node->right->length;
	}

	return temp_node;
}

char **parse_tokens(const char *string) {
	const int string_length = strlen(string);
	char **tokens = (char**)malloc(sizeof(char*) * string_length);
	memset(tokens, 0, string_length);

	int token_index = 0;
	int token_begin = 0;
	int token_length = 0;

	for (size_t i = 0; i <= string_length; i++) {
		char c = string[i];

		if (c == '[' || c == ']' || c == ',' || c == ' ' || c == '\0') {
			if (token_length != 0) {
				char *token = (char*)malloc(sizeof(char) * (token_length + 1));
				memset(token, '\0', token_length + 1);
				strncpy(token, string + token_begin, token_length);
				tokens[token_index] = token;
				token_index++;
			}

			token_begin = i + 1;
			token_length = 0;
		} else {
			token_length++;
		}
	}

	return tokens;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Usage: %s [equation]", argv[0]);
		return 1;
	}

	char *equation = argv[1];

	char **tokens = parse_tokens(equation);
	struct node *ast = parse_ast(tokens);
	double result = calc_ast(ast);
	printf("%f\n", result);
	return 0;
}
