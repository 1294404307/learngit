#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h"

int main()
{
	int input,add,deletenum;
	BinarySortTreePtr Tree;
	Tree=(BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	Tree->root = NULL;
	while(1)
	{
		system("cls");
		menu();
		input = get_input();
		if(input > 10 || input < 0)
		{
			printf("-----------------------\n");
			printf("输入错误请重新输入\n");
			printf("-----------------------\n");
			system("pause");
			continue;
		}
		system("cls");
		switch(input)
		{
		case 0:
			printf("---------------\n");
			printf("     已退出\n");
			printf("---------------\n");
			system("pause");
			return 0;
		case 1:
			printf("-------------------------\n");
			printf("     请输入要插入的数:\n");
			printf("-------------------------\n");
			add = get_input();
			if(add == -1073741510)
			{
				printf("-------------------\n");
				printf("      输入错误\n");
				printf("-------------------\n");
				system("pause");
				break;
			}
			if(BST_insert(Tree, add) == 1 )
			{
				printf("-------------------\n");
				printf("    插入成功!!!!\n");
				printf("-------------------\n");
			}
			else
			{
				printf("------------------------------\n");
				printf("该数已经存在，不能重复插入\n");
				printf("------------------------------\n");
			}
			system("pause");
			break;
		case 2:
			printf("-------------------------\n");
			printf("     请输入要删除的数:\n");
			printf("-------------------------\n");
			deletenum = get_input();
			if(deletenum == -1073741510)
			{
				printf("-------------------\n");
				printf("      输入错误\n");
				printf("-------------------\n");
				system("pause");
				break;
			}
			BST_delete(Tree, deletenum);
			break;
		case 3:
			printf("---------------------\n");
			printf("    你想找什么数\n");
			printf("---------------------\n");
			add = get_input();
			if(add == -1073741510)
			{
				printf("-------------------\n");
				printf("      输入错误\n");
				printf("-------------------\n");
				system("pause");
				break;
			}
			BST_search(Tree, add);
			break;
		case 4:
			BST_levelOrder(Tree,visit);
			printf("\n\n");
			system("pause");
			break;
		case 5:
			if(Tree->root == NULL)
			{
				printf("--------------\n");
				printf("   树为空\n");
				printf("--------------\n");
				system("pause");
				break;
			}
			BST_preorderR(Tree->root, visit);
			printf("\n\n");
			system("pause");
			break;
		case 6:
			if(Tree->root == NULL)
			{
				printf("--------------\n");
				printf("   树为空\n");
				printf("--------------\n");
				system("pause");
				break;
			}
			BST_inorderR(Tree->root, visit);
			printf("\n\n");
			system("pause");
			break;
		case 7:
			if(Tree->root == NULL)
			{
				printf("--------------\n");
				printf("   树为空\n");
				printf("--------------\n");
				system("pause");
				break;
			}
			BST_postorderR(Tree->root, visit);
			printf("\n\n");
			system("pause");
			break;
		case 8:
			BST_preorderI(Tree, visit);
			printf("\n\n");
			system("pause");
			break;
		case 9:
			BST_inorderI(Tree, visit);
			printf("\n\n");
			system("pause");
			break;
		case 10:
			BST_postorderI(Tree, visit);
			printf("\n\n");
			system("pause");
			break;
		}
	}
	return 0;
}
