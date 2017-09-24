#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node{
	int num;//��������Ϋ�����,����O��0,���O��1
	int num_of_child;
	char w;
	struct node *children[26]; 
}node;
node *give_space(){
	node *root = (node *)malloc(sizeof(node));
	return root; 
}
int traversal(node *root, int level){
	if(root->num_of_child == 0){ //�q��ڶ}�l��
		root->num = (level + 1) % 2;
		printf("%c %d\n", root->w, root->num);
		return (level + 1) % 2; 
	}
	else if(root->num_of_child == 1){//�p�G�u���@�Ӥl�`�I,�h��node��num�ȻP��l�`�I�ۦP
		for(int i = 0; i < 26; i++){
			if(root->children[i] != NULL){
				root->num = traversal(root->children[i], level + 1);
				printf("%c %d\n", root->w, root->num);
				return root->num;
			}
		}
	}
	else{//���즹�I�̥���,�]���U�@�ӤH�i�H��ܦۤv����Ӫ��D��(���D����S���U�ӤH��ӧQ���D��) 
		root->num = (level + 1) % 2;
		int flag = 0;
		for(int i = 0; i < 26; i++){
			if(root->children[i] != NULL){
				int n = traversal(root->children[i], level + 1);
				if(root->num != n){
					flag = 1;
				}
			}
		}
		if(flag == 1){
			root->num = level % 2;
		}
		if(level != 0){
			printf("%c %d\n", root->w, root->num);
		}
		return root->num;
	}
	return 0;
}
int main(){
	node *root = give_space();
	for(int i = 0; i < 26; i++){
		root->children[i] = NULL;
	}
	root->num_of_child = 0;
	root->w = 'R';
	root->num = 0;
	int N;
	char word[100];
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		node *k = root;
		scanf("%s", word);
		int length = strlen(word);
		for(int j = 0; j < length; j++){
			if(k->children[word[j] - 'a'] == NULL){
				k->num_of_child++;
				k->children[word[j] - 'a'] = give_space();
				k->children[word[j] - 'a']->w = word[j];
				k->children[word[j] - 'a']->num = 0;
				k->children[word[j] - 'a']->num_of_child = 0;
				for(int m = 0; m < 26; m++){
					k->children[word[j] - 'a']->children[m] = NULL;
				}
			}
			k = k->children[word[j] - 'a'];
		}
	}
	traversal(root, 0);
	int win = 0;
	for(int i = 0; i < 26; i++){
		if(root->children[i] != NULL){
			win += root->children[i]->num;
		}
	}
	printf("%d\n", win / root->num_of_child);
	return 0;
}
/*
7
tea
teach
to
ted
cat
car
can
*/
