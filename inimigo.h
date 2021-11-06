//void criaInimigos(void);
//void posicionaInimigo(int ini);
//int ocupado(int mx, int my, int sx, int sy, int inimigo);
void inimigoTurno(void);
//void acaoInimigo(int ini);
//void acaoInimigo2(int ini);


void criaInimigos(void);
struct Slime *criaInimigosLista(void);
void insereInimigoLista(struct Slime *p);
void posicionaInimigo(struct Slime *inimigo);
int ocupado(int mx, int my, int sx, int sy, struct Slime *lista);
void mataInimigos(struct Slime *inimigo);
void acaoInimigo(struct Slime *inimigo);
void acaoInimigo2(struct Slime *inimigo);