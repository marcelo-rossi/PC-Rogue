#define PAREDE 0
#define CHAO 1
#define PORTA 2
#define ESCADA 3


struct salas{
    char tiles [10][10];
};

void criaMapa(void);
void desenhaMapa(struct salas local);