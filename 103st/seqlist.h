#ifndef __LIST
#define __LIST

typedef struct{
	void *arr;
	int size;
	int nmemb;
}seqlist_t;

typedef int cmp_t(void *a, void *b);

int seqlist_init(seqlist_t **list, int size);//开辟seqlist_t所占字节的存储空间，list指向空间，arr->size = size; nmemb = 0;

int seqlist_add(seqlist_t *list, void *data);
//arr重新开辟size*（nmemb + 1）个字节存储空间，data指向数据复制到arr偏移size*nmemb个字节;
int seqlist_traval(seqlist_t *list, void （*show）(const void *data));
//i= 0; i < nmemb; i++;调用show函数遍历；
int seqlist_find(seqlist_t *list，void *key, cmp_t cmp);
//遍历顺序表，调用比较函数，找到和key指向数据相等的地址，返回地址
int seqlist_del(seqlist_t *list, void *key, cmp_t cmp);
//调用find，将返回地址后size字节开始复制到地址；
int seqlist_updata(seqlist_t *list, void *key, cmp_t cmp, void *newdata);
//调用find，memcpy newdata到返回地址；


#endif

