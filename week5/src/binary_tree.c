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
	if(tree->root == NULL)   //���û���������ڸ��ڵ����
	{
		BST_init(tree);            //û�������ȳ�ʼ��һ����
		tree->root->value = num;
		return succeed;
	}
	NodePtr faNode = NULL;
	NodePtr childNode = tree->root;
	while(childNode)
	{
		if(num > childNode->value)  //Ҫ��������Ƚ���������Ӧ������ƶ�
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
		printf("    ��Ϊ�գ��޷�ɾ��\n");
		printf("-----------------------\n");
		system("pause");
		return false;
	}
	if(num == tree->root->value)   //ɾ�������ʱ
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
		printf("ɾ���ɹ�!!!!!\n");
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
			if(childNode == NULL)       //���С�ں���һ����㣬˵�������ڴ���
			{
				printf("----------------------\n");
				printf("û�ҵ��������޷�ɾ��\n");
				printf("----------------------\n");
				system("pause");
				return true;
			}
		}
		else if(num < childNode->value)
		{
			faNode = childNode;
			childNode = childNode->left;
			if(childNode == NULL )       //������ں���һ����㣬˵�������ڴ���
			{
				printf("----------------------\n");
				printf("û�ҵ��������޷�ɾ��\n");
				printf("----------------------\n");
				system("pause");
				return true;
			}
		}
		else     //�д������ܹ�ɾ�������
		{
			if(childNode->right == NULL)    //û���Һ���ʱ
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
			else if(childNode->left == NULL)    //û������ʱ
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
			else    //���Һ��Ӷ���ʱ
			{
				if(childNode->value > faNode->value)     //ɾ�����ڸ������ұ�ʱ
				{
					faNode->right = childNode->right;
					p = childNode;
					endNode = childNode->right;
					childNode = childNode->left;
					p->left=NULL;
					p->right=NULL;
					while(endNode->left)
						endNode = endNode->left;      //�ҵ����һ�����
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
			printf("ɾ���ɹ�!!!!!\n");
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
		printf("    ��Ϊ��\n");
		printf("--------------\n");
		system("pause");
		return true;
	}
	NodePtr childNode = tree->root;
	while(childNode)
	{
		if(num > childNode->value)   //��������������������ұ���
		{
			childNode = childNode->right;
			if(childNode == NULL)       //���С�ں���һ����㣬˵�������ڴ���
			{
				printf("-------------------\n");
				printf("    û�ҵ�����\n");
				printf("-------------------\n");
				system("pause");
				return true;
			}
		}
		else if(num < childNode->value)
		{
			childNode = childNode->left;
			if(childNode == NULL)       //������ں���һ����㣬˵�������ڴ���
			{
				printf("-------------------\n");
				printf("    û�ҵ�����\n");
				printf("-------------------\n");
				system("pause");
				return true;
			}
		}
		else
		{
			printf("-------------------\n");
			printf("�������ҵ��˸���:%d\n",childNode->value);
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

Status BST_preorderI(BinarySortTreePtr tree, void (*visit)(NodePtr))   //�ǵݹ�
{
	if(tree->root == NULL)
	{
		printf("--------------\n");
		printf("    ��Ϊ��\n");
		printf("--------------\n");

		return true;
	}
	LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack));
	initLStack(stack);        //��ʼ��һ��ջ
	NodePtr tempNode = (NodePtr)malloc(sizeof(Node));
	push(stack,*tree->root);
	while(stack->count)
	{
		tempNode = pop(stack);
		visit(tempNode);

		//�����Һ��Ӷ���ջ
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
		printf("   ��Ϊ��\n");
		printf("--------------\n");

		return true;
	}
	LinkStack *stack = (LinkStack *)malloc(sizeof(LinkStack));
	initLStack(stack);     //��ʼ��һ��ջ
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
		if(tempNode->right != NULL)   //�˽�����Һ���ʱ���ҵ��Һ��ӵ�����Ľ��
		{
			temp = tempNode->right;
			continue;
		}

		//��û���Һ���ʱ��������ջ��ֱ���ҵ����Һ��ӵĽ��
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
		printf("    ��Ϊ��\n");
		printf("--------------\n");

		return true;
	}
	LinkStack *stack1 = (LinkStack *)malloc(sizeof(LinkStack));       //����ջ����ǰ�������ȣ�ǰ������ǽ�ÿ������ջ�ٴ�ӡ��
	LinkStack *stack2 = (LinkStack *)malloc(sizeof(LinkStack));	  //��������ɿ���ǰ������������������������ջ������һ��ջ��ʹ����ӡ
	initLStack(stack1);     //��ʼ��һ��ջ
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

	while(stack2->count)//���ڶ���ջ�д�������ݴ�ӡ��������Ϊ��������Ľ��
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
		printf("    ��Ϊ��\n");
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

		//�����Һ��������
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
	printf("           ����������\n");
	printf("1����������           2��ɾ������\n");
	printf("3����������           4���������\n");
	printf("5���ݹ�ǰ�����       6���ݹ��������\n");
	printf("7���ݹ�������       8������ǰ�����\n");
	printf("9�������������       10�������������\n");
	printf("	   0���˳�����\n");
	printf("---------------------------------\n");

}
