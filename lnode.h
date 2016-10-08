#ifndef LNODE_H
#define LNODE_H

struct lnode_s {
	char *value;
	int count;
	struct lnode_s *next;
};

typedef struct lnode_s * lnode;

lnode makeLnode(char *val);
void deleteLnode(lnode node);

char * getLnodeValue(lnode node);
int getLnodeCount(lnode node);
lnode getNextLnode(lnode node);

#endif