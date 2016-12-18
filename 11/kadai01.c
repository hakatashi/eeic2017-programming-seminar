#include <stdio.h>
#include <stdlib.h>

struct node {
	char value;
	struct node *left;
	struct node *right;
	int size;
};

void traverse(struct node *n) {
	printf("%c", n->value);

	if (n->left != NULL) {
		traverse(n->left);
	}

	if (n->right != NULL) {
		traverse(n->right);
	}
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
	traverse(root);
	return 0;
}
