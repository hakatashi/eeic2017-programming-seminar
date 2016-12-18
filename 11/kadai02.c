#include <stdio.h>
#include <stdlib.h>

struct node {
	char value;
	struct node *left;
	struct node *right;
	int size;
};

double calc(struct node *n) {
	double left = 0, right = 0;

	if (n->left != NULL) {
		left = calc(n->left);
	}

	if (n->right != NULL) {
		right = calc(n->right);
	}

	if (n->value == '+') {
		return left + right;
	}

	if (n->value == '-') {
		return left - right;
	}

	if (n->value == '*') {
		return left * right;
	}

	if (n->value == '/') {
		return left / right;
	}

	return n->value - '0';
}

struct node *create_node(char *s) {
	struct node *temp_node = (struct node*)malloc(sizeof(struct node));

	temp_node->value = s[0];

	if ('0' <= s[0] && s[0] <= '9') {
		temp_node->left = NULL;
		temp_node->right = NULL;
		temp_node->size = 1;
	} else {
		temp_node->left = create_node(s + 1);
		temp_node->right = create_node(s + temp_node->left->size + 1);
		temp_node->size = 1 + temp_node->left->size + temp_node->right->size;
	}

	return temp_node;
}

int main() {
	char *str = "+/9*84-*84+73";
	struct node *root = create_node(str);
	double result = calc(root);
	printf("%f\n", result);
	return 0;
}
