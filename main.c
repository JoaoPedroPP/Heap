#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int x; //Armazena dado
	int i; //Index para saber se  é direita ou esquerda
	struct node *d; //Ponteiro para o nó da direita
	struct node *e; //Ponteiro para o nó da esquerda
} node;

node *min = NULL;

//Declaração da função para evitar conflito
node *percorre_no(node*);
void mostra_no(node*);
void perc_e(node*);
void perc_d(node*);

//Rotina que percorre os nós da esquerda
node* percorre_no_esquerda(node *pointer_E){
	if(pointer_E->e == NULL) return pointer_E; //Retorna o endereço da folha
	/*return*/ percorre_no(pointer_E->e);
}

//Rotina que percorre os nós da direita
node* percorre_no_direita(node *pointer_D){
	if(pointer_D->d == NULL) return pointer_D; //Retorna o endereço da folha
	/*return*/ percorre_no(pointer_D->d);
}

//Rotina que percorre os nós
node* percorre_no(node *pointer){
	node *pe = percorre_no_esquerda(pointer);
	node *pd = percorre_no_direita(pointer);
//	printf("pe->i: %d\n", pe->i);
//	printf("pd->i: %d\n", pd->i);
//	node* n = pe->i > pd->i ? pe->i: pd->i;
//	min = min->i > n->i ? n:min;
//	printf("min: %d\n", min->i);
	return  pe->i > pd->i ? pd: pe;
//	printf("%d\n", pointer->x); //WORKS !!!!!!
}

//Rotina de criação de nós
node* cria_no(node *p){
	min = p;
	node *no_cria = percorre_no(p);
	printf("no_cria->i: %d\n", no_cria->i);
//	printf("p->d: %d\n", p->d);
	if(p->i%2 != 0){
		no_cria->e = (node*)malloc(sizeof(node));
		printf("passou e\n");
		min = NULL;
		return no_cria->e;
	}
	if(p->i%2 == 0){
		no_cria->d = (node*)malloc(sizeof(node));
		printf("passou d\n");
		min = NULL;
		return no_cria->d;
	}
	else{
		no_cria->e = (node*)malloc(sizeof(node));
		return no_cria->e;
	}
}

int main(int argc, char** argv){
	int i = 0;
	node *root = (node*)malloc(sizeof(node));
//	root->e = (node*)malloc(sizeof(node));
//	root->d = (node*)malloc(sizeof(node));
	root->i = ++i;
	while(i<9){
		node *x = cria_no(root);
		printf("Insira um número inteiro para a Heap: \n");
		scanf("%d", &x->x);
		x->i = ++i;
		printf("x->i: %d\n", x->i);
		printf("%d\n", x->x);
//		break;
	}
	i = 0;
	while(i<9){
		mostra_no(root);
		i++;
	}




	free(root);
//	scanf("%d", &root->x);
//	printf("%d\n", root->x);
	return 0;
}

//Area para mostrar nos
void mostra_no(node *pointer){
	perc_e(pointer);
	perc_d(pointer);
}
void perc_e(node *pe){
	if(pe->e == NULL){
		printf("Folha esquerda encontrada: ");
		printf("%d\n", pe->x);
		return;
	}
	printf("%d\n", pe->x);
	return mostra_no(pe->e);
}
void perc_d(node *pd){
	if(pd->d == NULL){
		printf("Folha direita encontrada: ");
		printf("%d\n", pd->x);
		return;
	}
	printf("%d\n", pd->x);
	return mostra_no(pd->d);
}
