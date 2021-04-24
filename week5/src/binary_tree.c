#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_sort_tree.h"

Status BST_init(BinarySortTreePtr tree)
{
	tree->root = (NodePtr)malloc(sizeof(Node));

	tree->root->left = NULL;
	tree->root->right = NULL;
	return true;
}

Status BST_insert(BinarySortTreePtr tree, ElemType num)
{
	if(tree->root == NULL)   //如果没有数，则在根节点插入
	{
		BST_init(tree);            //没有数则先初始化一个根
		tree->root->value = num;
		return succeed;
	}
	NodePtr faNode = NULL;
	NodePtr childNode = tree->root;
	while(childNode)
	{
		if(num > childNode->value)  //要插入的数比结点的数大则应往后边移动
		{
			faNode = childNode;
			childNode = childNode->right;
		}
		else if(num < childNode->value)
		{
			faNode = childNode;
			childNode = childNode->left;
		}
		else
		{
			return false;
		}

	}
	if(num > faNode->value)
	{
		faNode->right = NewNode(num);
	}
	else
	{
		faNode->left = NewNode(num);
	}
	return true;

}

NodePtr NewNode(ElemType num)
{
	NodePtr newNode = (NodePtr)malloc(sizeof(Node));
	newNode->value = num;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Status BST_delete(BinarySortTreePtr tree,ElemType num)
{
	if(tree->root == NULL)
	{
		printf("-----------------------\n");
		printf("    树为空，无法删除\n");
		printf("-----------------------\n");
		system("pause");
		return false;
	}
	if(num == tree->root->value)   //删除根结点时
	{
		if(tree->root->right == NULL)
		{
			tree->root = tree->root->left;
		}
		else
		{
			tree->root = tree->root->right;
		}
		printf("---------------\n");
		printf("删除成功!!!!!\n");
		printf("---------------\n");
		system("pause");
		return true;
	}

	NodePtr p,endNode;
	NodePtr faNode = NULL;
	NodePtr childNode = tree->root;
	while(childNode)
	{
		if(num > childNode->value)
		{
			faNode = childNode;
			childNode = childNode ->right;
			if(childNode == NULL)       //如果小于后面一个结点，说明不存在此数
			{
				printf("----------------------\n");
				printf("没找到此数，无法删除\n");
				printf("----------------------\n");
				system("pause");
				return true;
			}
		}
		else if(num < childNode->value)
		{
			faNode = childNode;
			childNode = childNode->left;
			if(childNode == NULL )       //如果大于后面一个结点，说明不存在此数
			{
				printf("----------------------\n");
				printf("没找到此数，无法删除\n");
				printf("----------------------\n");
				system("pause");
				return true;
			}
		}
		else     //有此数，能够删除的情况
		{
			if(childNode->right == NULL)    //没有右孩子时
			{
				if(childNode->value < faNode->value)
				{
					faNode->left = childNode->left;
				}
				else
				{
					faNode->right = childNode->left;
				}

			}
			else if(childNode->left == NULL)    //没有左孩子时
			{
				if(childNode ->value > faNode->value)
				{
					faNode->right = childNode->right;
				}
				else
				{
					faNode->left = childNode->right;
				}
			}
			else    //左右孩子都有时
			{
				if(childNode->value > faNode->value)     //删除点在父结点的右边时
				{
					faNode->right = childNode->right;
					p = childNode;
					endNode = childNode->right;
					childNode = childNode->left;
					p->left=NULL;
					p->right=NULL;
					while(endNode->left)
						endNode = endNode->left;      //找到最后一个结点
					endNode->left = childNode;
				}
				else
				{
					faNode->left = childNode->right;
					p=childNode;
					endNode = childNode->right;
					childNode = childNode->left;
					p->left = NULL;
					p->right = NULL;
					while(endNode->left)
						endNode = endNode->left;
					endNode->left=childNode;
				}
			}
			printf("---------------\n");
			printf("删除成功!!!!!\n");
			printf("---------------\n");
			system("pause");
			return true;
		}
	}
	return true;
}

Status BST_search(BinarySortTreePtr tree, ElemType num)
{
	if(tree->root == NULL)
	{
		printf("--------------\n");
		printf("    树为空\n");
		printf("--------------\n");
		system("pause");
		return true;
	}
	NodePtr childNode = tree->root;
	while(childNode)
	{
		if(num > childNode->value)   //大于这个结点则从这个结点右边找
		{
			childNode = childNode->right;
			if(childNode == NULL)       //如果小于后面一个结点，说明不存在此数
			{
				printf("-------------------\n");
				printf("    没找到此数\n");
				printf("-------------------\n");
				system("pause");
				return true;
			}
		}
		else if(num < childNode->value)
		{
			childNode = childNode->left;
			if(childNode == NULL)       //如果大于后面一个结点，说明不存在此数
			{
				printf("-------------------\n");
				printf("    没找到此数\n");
				printf("-------------------\n");
				system("pause");
				return true;
			}
		}
		else
		{
			printf("-------------------\n");
			printf("在数中找到了该数:%d\n",childNode->value);
			printf("-------------------\n");
			system("pause");
			return true;
		}
	}
	return true;
}

Status BST_preorderR(NodePtr node, void (*visit)(NodePtr))
{
	if(node == NULL)
	{
		return true;
	}
	visit(node);
	BST_preorderR(node->left,visit);
	BST_preorderR(node->right,visit);
	return true;
}
Status BST_inorderR(NodePtr node, void (*visit)(NodePtr))
{
	if(node == NULL)
	{
		return true;
	}
	BST_inorderR(node->left,visit);
	visit(node);
	BST_inorderR(node->right,visit);
	return true;
}

Status BST_postorderR(NodePtr node, void (*visit)(NodePtr))
{
	if(node == NULL)
	{
		return true;
	}
	BST_postorderR(node->left,visit);
	BST_postorderR(node->right,visit);
	visit(node);
	return true;
}

void visit(NodePtr s)
{
	printf("%d ",s->value);
}

Status BST_preorderI(BinarySortTreePtr tree, void (*visit)(NodePtr))   //非递归
{
	if(tree->root == NULL)
	{
		printf("--------------\n");
		printf("    树为空\n");
		printf("--------------\n");

		return true;
	}
	LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack));
	initLStack(stack);        //初始化一个栈
	NodePtr tempNode = (NodePtr)malloc(sizeof(Node));
	push(stack,*tree->root);
	while(stack->count)
	{
		tempNode = pop(stack);
		visit(tempNode);

		//将左右孩子都入栈
		if(tempNode->right != NULL)
		{
			push(stack,*(tempNode->right));
		}
		if(tempNode->left != NULL)
		{
			push(stack,*(tempNode->left));
		}

	}
	free(stack);
	free(tempNode);
	return true;
}

Status BST_inorderI(BinarySortTreePtr tree, void (*visit)(NodePtr))
{

	if(tree->root == NULL)
	{
		printf("--------------\n");
		printf("   树为空\n");
		printf("--------------\n");

		return true;
	}
	LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack));
	initLStack(stack);     //初始化一个栈
	NodePtr tempNode = (NodePtr)malloc(sizeof(Node));
	NodePtr temp = tree->root;
	while(1)
	{
		while(temp)
		{
			push(stack,*temp);
			temp = temp->left;
		}
		if(stack->count == 0)
			return true;
		tempNode = pop(stack);
		visit(tempNode);
		if(tempNode->right != NULL)   //此结点有右孩子时，找到右孩子的最左的结点
		{
			temp = tempNode->right;
			continue;
		}

		//当没有右孩子时，继续出栈，直到找到有右孩子的结点
		while(tempNode->right == NULL && stack->count != 0)
		{
			tempNode = pop(stack);
			visit(tempNode);
		}
		temp = tempNode->right;
	}
	return true;
}

Status BST_postorderI(BinarySortTreePtr tree, void (*visit)(NodePtr))
{
	if(tree->root == NULL)
	{
		printf("--------------\n");
		printf("    树为空\n");
		printf("--------------\n");

		return true;
	}
	LinkStack *stack1 = (LinkStack *)malloc(sizeof(LinkStack));       //两个栈，与前序遍历类比，前序遍历是将每个结点出栈再打印，
	LinkStack *stack2 = (LinkStack *)malloc(sizeof(LinkStack));	  //后序遍历可看做前序遍历的类似逆操作，将结点出栈后入另一个栈，使其后打印
	initLStack(stack1);     //初始化一个栈
	initLStack(stack2);

	NodePtr tempNode = (NodePtr)malloc(sizeof(Node));
	push(stack1,*tree->root);

	while(stack1->count)
	{
		tempNode = pop(stack1);
		push(stack2,*tempNode);
		if(tempNode->left != NULL)
		{
			push(stack1,*(tempNode->left));
		}
		if(tempNode->right != NULL)
		{
			push(stack1,*(tempNode->right));
		}
	}

	while(stack2->count)//将第二个栈中储存的数据打印出来，即为后序遍历的结果
	{
		tempNode = pop(stack2);
		visit(tempNode);
	}
	free(tempNode);
	free(stack1);
	free(stack2);
	return true;
}

Status BST_levelOrder(BinarySortTreePtr tree, void (*visit)(NodePtr))
{
	if(tree->root == NULL)
	{
		printf("--------------\n");
		printf("    树为空\n");
		printf("--------------\n");

		return true;
	}

	Queuehead *quehead = (Queuehead *)malloc(sizeof(Queue));
	initqueue(quehead);
	NodePtr tempNode = (NodePtr)malloc(sizeof(Node));
	inqueue(quehead,*tree->root);

	while(quehead->count)
	{
		tempNode = outqueue(quehead);
		visit(tempNode);

		//将左右孩子入队列
		if(tempNode->left != NULL)
		{
			inqueue(quehead,*tempNode->left);
		}
		if(tempNode->right != NULL)
		{
			inqueue(quehead,*tempNode->right);
		}
	}
	free(quehead);
	free(tempNode);
	return true;
}

void menu()
{
	printf("---------------------------------\n");
	printf("           二叉排序树\n");
	printf("1、插入数字           2、删除数字\n");
	printf("3、查找数字           4、层序遍历\n");
	printf("5、递归前序遍历       6、递归中序遍历\n");
	printf("7、递归后序遍历       8、迭代前序遍历\n");
	printf("9、迭代中序遍历       10、迭代后序遍历\n");
	printf("	   0、退出程序\n");
	printf("---------------------------------\n");

}
