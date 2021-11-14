void inimigoTurno(void);
void criaInimigos(void);
struct Slime *criaInimigosLista(void);
void insereInimigoLista(struct Slime *p);
void posicionaInimigo(struct Slime *inimigo);
int ocupado(int mx, int my, int sx, int sy, struct Slime *lista);
void mataInimigos(struct Slime *inimigo);
void acaoInimigo(struct Slime *inimigo);
void acaoInimigo2(struct Slime *inimigo);