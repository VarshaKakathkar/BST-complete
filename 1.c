/*
	Design a BST class with methods to add element, search element, number of elements and
	delete requested element
	compile : gcc -Wall 1.c lib/bst.c ../Queue/queue.c
*/
#include <stdio.h>
#include <assert.h>
#include "bst.h"

void test_create_bst(){
	BST* bst = create_bst();
	assert(bst->length ==0);
	assert(bst->root == NULL);
	assert(length_bst(bst)==0);
	printf("[+] Success in testing creation\n");
}

void test_add_bst(){

	BST* bst = create_bst();
	OprResult* res = add_bst(bst,10);
	assert(bst->length==1);
	assert(res->status == STATUS_OK);
	assert(((Node*)res->data)->data == 10);
	assert(bst->root->data==10);
	assert(bst->length==1);

	res = add_bst(bst,20);
	assert(res->status == STATUS_OK);
	assert(((Node*)res->data)->data == 20);
	assert(bst->root!=NULL);
	assert(bst->root->right!=NULL);
	assert(bst->root->right->data==20);
	assert(bst->length==2);


	res = add_bst(bst,5);
	assert(res->status == STATUS_OK);
	assert(((Node*)res->data)->data == 5);
	assert(bst->root!=NULL);
	assert(bst->root->data==10);
	assert(bst->root->left!=NULL);
	assert(bst->root->left->data==5);
	assert(bst->length==3);


	res = add_bst(bst,10);
	assert(res->status == STATUS_FAIL);
	assert(res->data == NULL);
	assert(bst->root!=NULL);
	assert(bst->root->data==10);
	assert(bst->length==3);


	res = add_bst(bst,5);
	assert(res->status == STATUS_FAIL);
	assert(res->data == NULL);
	assert(bst->root->data==10);
	assert(bst->root->left->data==5);
	assert(bst->length==3);

	printf("[+] Success in testing addtion\n");

}

void test_search(){

	BST* bst = create_bst();
	OprResult* res = add_bst(bst,10);
	res = add_bst(bst,20);
	res = add_bst(bst,5);

	res = search_ele_bst(bst,10);
	assert(res->status==STATUS_OK);
	assert(((Node*)res->data)->data == 10);


	res = search_ele_bst(bst,20);
	assert(res->status==STATUS_OK);
	assert(((Node*)res->data)->data == 20);


	res = search_ele_bst(bst,5);
	assert(res->status==STATUS_OK);
	assert(((Node*)res->data)->data == 5);

	res = search_ele_bst(bst,15);
	assert(res->status==STATUS_FAIL);
	assert(res->data==NULL);

	printf("[+] Success in testing search\n");
}
void test_delete(){
	BST* bst = create_bst();
	OprResult* res = add_bst(bst,10);
	res = add_bst(bst,20);
	res = add_bst(bst,5);
	res = add_bst(bst,0);
	res = add_bst(bst,15);
	res = add_bst(bst,25);
	int len = bst->length;

	res = delete_bst(bst,0);
	assert(res!=NULL);
	assert(res->status==STATUS_OK);
	assert(((Node*)res->data)->data==0);
	assert(bst->length==len-1);
	assert(bst->root->left!=NULL);
	assert(bst->root->left->left==NULL);;


	len = bst->length;
	res = delete_bst(bst,10);
	assert(res!=NULL);
	assert(res->status==STATUS_OK);
	assert(((Node*)res->data)->data==10);
	assert(bst->length==len-1);
	assert(bst->root->data==15);

	printf("[+] Success in testing delete\n");

}

int main(int v,char** c){
	test_create_bst();
	test_add_bst();
	test_search();
	test_delete();

	printf("[+] All Test Complete\n");

}

