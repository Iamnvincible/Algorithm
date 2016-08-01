#include<stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct treenode {
	ElementType data;
	struct treenode* left;
	struct treenode* right;
}TreeNode;
TreeNode* Create(TreeNode * T) {
	int c;
	printf("please input node value\n");
	scanf("%d", &c);
	if (c != 0) {
		T = (TreeNode *)malloc(sizeof(TreeNode));
		T->data = c;
		T->left=Create(T->left);
		T->right=Create(T->right);
		return T;
	}
	else
	{
		return NULL;
	}
}
void PreOrder(TreeNode *T) {
	if (T != NULL) {
		printf("%d", T->data);
		PreOrder(T->left);
		PreOrder(T->right);
	}
}
void InOrder(TreeNode *T) {
	if (T != NULL) {
		PreOrder(T->left);
		printf("%d", T->data);
		PreOrder(T->right);
	}
}
void PostOrder(TreeNode *T) {
	if (T != NULL) {
		PreOrder(T->left);
		PreOrder(T->right);
		printf("%d", T->data);
	}
}
int main() {
	TreeNode *t=NULL;
	t=Create(t);
	PreOrder(t);
	InOrder(t);
	PostOrder(t);
	return 0;
}