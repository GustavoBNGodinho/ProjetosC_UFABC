typedef struct pilha Pilha; 
Pilha* pilhaCria(void );
void pilhaPush (Pilha* p, int v);
int pilhaPop (Pilha* p); 
int pilhaVazia (Pilha* p); 
void pilhaLibera (Pilha* p);
int topo(Pilha* p);
void concatenaPilha(Pilha* p1, Pilha* p2);
void printaPilha(Pilha* p);
Pilha* copiaPilha(Pilha* p);

