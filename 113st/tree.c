#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NAMESIZE 32

struct stu_t{
	int id;
	char name[NAMESIZE];
};
struct tree_stu{
	struct stu_t data;
	struct tree_stu *left;
	struct tree_stu *right;
};

int tree_init(struct tree_stu **arr, struct stu_t *newdata)
{	
	struct tree_stu *brr;
	if(*arr == NULL)
	{
		brr = malloc(sizeof(*brr));
		if(brr == NULL)
			return -1;

		memcpy(&brr->data, newdata, sizeof(struct stu_t));
		
		brr->left = brr->right = NULL;
		
	   	*arr = brr;

		return 0;
	}
	if(newdata->id <= (*arr)->data.id)
		return tree_init(&(*arr)->left, newdata);
	else 
		return tree_init(&(*arr)->right, newdata);
}

void tree_midtraval(const struct tree_stu *arr)
{
	if(arr == NULL)
		return;
	tree_midtraval(arr->left);
	printf("%d\n", arr->data.id);
	tree_midtraval(arr->right);
}

void tree_des(struct tree_stu **arr)
{
	if(*arr == NULL)
		return ;
	tree_des(&(*arr)->left);
	tree_des(&(*arr)->right);
	free(*arr);
	arr = NULL;
}
static int tree_sum(const struct tree_stu *arr)
{
	if(arr == NULL)
		return 0;
		
	return 1 + tree_sum(arr->left) + tree_sum(arr->right);
	
}


static void tree_draw(struct tree_stu *arr, int level)
{
	if(arr == NULL)
		return ;
	tree_draw(arr->right, level + 1);
	for(int i = 0; i < level; i++)
		printf("		");
	printf("%d	%s\n", arr->data.id, arr->data.name);
	tree_draw(arr->left, level + 1);
}

/*static void newtree(struct tree_stu **left_tree, struct tree_stu *right_tree)
{
	if(*left_tree == NULL)
	{
		*left_tree = right_tree;
		return;
	}
	newtree(&(*left_tree)->right, right_tree);
}
static struct tree_stu *tree_del(struct tree_stu **arr)
{
	struct tree_stu *newarr;

	newtree(&(*arr)->left, (*arr)->right);

	newarr = (*arr)->left;
	(*arr)->right = (*arr)->left = NULL;
	free(*arr);
	*arr = NULL;

	return newarr;
}
*/
static struct tree_stu **del_find(struct tree_stu **arr, int id)
{
	if((*arr) == NULL)
		return NULL;
	if((*arr)->data.id == id)
		return arr;
}
static struct tree_stu *leftmost(struct tree_stu *arr)
{
	if(arr == NULL)
		return NULL;
	if((arr)->left == NULL)
		return arr;
	return leftmost(arr->left);
}

static struct tree_stu **rightmost(struct tree_stu **arr)
{
	if(*arr == NULL)
		return arr;
	leftmost((*arr)->right);
}
static int tree_del(struct tree_stu **arr, int key)
{
	struct tree_stu **find, **newarr, **left;
//	struct tree_stu **newarr;
	find = del_find(arr, key);

//	struct tree_stu *left, right;
///*
	left = rightmost(&(*arr)->left);
	(*left)->right = (*arr)->right;

/*	newarr = &(*arr)->left;
	(*arr)->left = (*arr)->right = NULL;
	free(*arr);
	arr = newarr;

	*/
}


int main()
{
	struct tree_stu *arr;
	struct stu_t stu;
	arr = NULL;
	int brr[] = {6,2,7,8,4,6,1,9,32,2,2,7,4,5,5,86,3,4,5,7};

	for(int i = 0; i < sizeof(brr)/ sizeof(int); i++)
	{
		stu.id = brr[i];
		snprintf(stu.name, NAMESIZE, "lihua%d", brr[i]);
		tree_init(&arr, &stu);
	}
	tree_midtraval(arr);
	tree_draw(arr, 0);
	int i = tree_sum(arr);
	printf("-----------sum----------------------\n");
	printf("%d\n", i);

	int key = 32;
	tree_del(&arr , key);
	tree_draw(arr, 0);
	tree_des(&arr);
}
