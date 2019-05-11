#ifndef kik_hpp
#define kik_hpp
#include <vector>

class Kolkoikrzyzyk {

std::vector<int> plansza;

int rozmiarPlanszy;
public:
Kolkoikrzyzyk();

void graj();
void rysujPlansze(bool instrukcja);
void ruch(int gracz);

bool czyRemis();
bool czyWygrana(int  gracz);

int minMax(int gracz);
int ruchKomputera();



};

#endif
