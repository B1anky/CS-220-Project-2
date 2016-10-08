#include "lnode.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

lnode makeLnode(char *val) {
	lnode node=(lnode)malloc(sizeof(struct lnode_s));
	assert(node); // exit if we can't get space for a node
	node->value=strdup(val);
	node->count=1;
	node->next=NULL;
	return node;
}

void deleteLnode(lnode node) {
	if (node->value) free(node->value);
	free(node);
}

char * getLnodeValue(lnode node) {
	return node->value;
}

int getLnodeCount(lnode node) {
	return node->count;
}

lnode getNextLnode(lnode node) {
	return node->next;
}

/* Function definitions for new lnode methods go here */