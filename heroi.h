struct coordenada{
    int x;
    int y;
};


struct Heroi{
    int HP;
    int dano;
    int level;
    char vivo;
    struct coordenada sala;
    struct coordenada atual;
    struct coordenada mapa;
};

struct Slime{
    int HP;
    int dano;
    char display;
    char vivo;
    struct coordenada sala;
    struct coordenada atual;
    struct coordenada mapa;
    struct Slime *prox;
};

void acaoHeroi(void);
void parede(void);
void moveHeroi(void);
void heroiAtaca(void);
void entraPorta(void);
void sobeEscada(void);
void mataTodos(struct Slime *inimigo);