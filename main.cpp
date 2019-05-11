#include <vector>
#include "kik.hpp"
#include <iostream>

using namespace std;

int main() {


    cout<<endl<<"#Kolko i krzyzyk#"<<endl<<endl;
    Kolkoikrzyzyk kik;
    cout<<"Instruckcja do grania:"<<endl<<"Plansza nizej pokazuje, w ktore miejsce zostanie wpisany znak po podaniu konkretnej cyfry"<<endl;
    kik.rysujPlansze(true);
    kik.graj();

return 0;

}
