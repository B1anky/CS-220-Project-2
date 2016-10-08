#include "lnode.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int normalize(char *w);
int isGreater(char * s1, char *s2);
lnode auxInsertWord(char * word, lnode head, lnode par, lnode cur);
lnode insertWord(char * word, lnode head);

int main(int argc, char **argv) {
	lnode head=NULL;
	char word[1024];
	while(!feof(stdin)) {
		if (scanf("%s",word)) { // If we can read another white space terminated string
			if (normalize(word)) { // And if that string is non-empty after normalization...
				head=insertWord(word,head);
			}
		}
	}

	lnode node;
	int i=1;
	for(node=head; node; node=getNextLnode(node)) {
		printf("%3d. - %3d - %s\n",i++,getLnodeCount(node),getLnodeValue(node));
	}

	lnode next;
	for(node=head; node; node=next) {
		next=getNextLnode(node);
		deleteLnode(node);
	}
	return 0;
}

int normalize(char *r) {
	int ret=0;
	char *w=r;
	while(*r) {
		if (!isalpha((int)*r)) { r++; continue; }
		(*w++)=tolower((int)*r++);
		ret=1;
	}
	(*w)=0;
	return ret;
}

//For any proceeding cases and the edge cases
lnode auxInsertWord(char * word, lnode head, lnode par, lnode cur){
	if(cur == NULL){
		par->next = makeLnode(word);
		return head;
	}else{
		int cmp = isGreater(word, cur->value);
		if(!cmp){
			cur->count++;
			return head;
		}else if(cmp == -1){
			lnode tmp = makeLnode(word);
			tmp->next = cur;
			par->next = tmp;
			return head;
		}
		return auxInsertWord(word, head, cur, cur->next);
	}
}

//For first case
lnode insertWord(char * word, lnode head) {
	if(head == NULL){
		head = makeLnode(word);
		return head;
	}
	int cmp = isGreater(word, head->value);
	if(!cmp){
		head->count++;
		return head;
	}else if(cmp == -1){
		lnode tmp = makeLnode(word);
		tmp->next = head;
		head = tmp;
		return head;
	}
	return auxInsertWord(word, head, head, head->next);
}

int isGreater(char *s1,char *s2) {
	while(*s1) {
		if ((*s1)>(*s2)) return 1;
		if ((*s1)<(*s2)) return -1;
		s1++; s2++;
	}
	if ((*s2)==0) return 0;
	return -1;
}