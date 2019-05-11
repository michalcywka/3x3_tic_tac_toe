#include "kik.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <array>
using namespace std;

Kolkoikrzyzyk::Kolkoikrzyzyk()
{
    rozmiarPlanszy=9;

    for(int i = 0; i < rozmiarPlanszy; i++)
    {
        plansza.push_back(0);
    }

}


void Kolkoikrzyzyk::rysujPlansze(bool instrukcja)
{
    int wysokosc=sqrt(rozmiarPlanszy);
    string podzialka;
    podzialka+='\n';
    for(int i=1;i<=wysokosc*3+wysokosc-1;i++)
    {
        if(i%4==0)
        {
            podzialka+='+';
        }
        else
        {
        podzialka+='-';
        }
    }
    podzialka+='\n';
    for(int i = 0; i < rozmiarPlanszy; i++)
    {
        char znak=' ';
        switch (plansza[i])
        {
        case 0:
        znak=' ';
        break;

        case 1:
        znak='x';
        break;

        case 2:
        znak='o';
        break;
        }


        if(i%wysokosc==0 && i>0)
            cout<<podzialka;
        if(!instrukcja) cout<<" "<<znak<<" ";
        else cout <<" "<<i+1<<" ";
        if(i%wysokosc!=wysokosc-1)
            cout <<"|";



    }

}

bool Kolkoikrzyzyk::czyRemis()
{


    for(int i = 0; i < rozmiarPlanszy; i++)
    {

        if(plansza[i]==0)
            return false;

    }

    return true;

}


bool Kolkoikrzyzyk::czyWygrana(int gracz)
{

    for(int i = 0; i <= 7; i += 3)
    {


        if((plansza[i]==gracz) && (plansza[i+1]==gracz) && (plansza[i+2]==gracz))
        {

            return true;

        }

    }


    for(int i = 0; i <= 3; i++)
    {
        if((plansza[i]==gracz) && (plansza[i+3]==gracz) && (plansza[i+6]==gracz))
        {

            return true;

        }

    }


    if((plansza[0]==gracz) && (plansza[4]==gracz) && (plansza[8]==gracz))
    {

        return true;

    }


    if((plansza[2]==gracz) && (plansza[4]==gracz) && (plansza[6]==gracz))
    {

        return true;

    }

    return false;

}


int Kolkoikrzyzyk::minMax(int gracz)
{

    int m, mmx;

    if(czyWygrana(gracz))
    {

        if(gracz==1)
            return 1;
        else
            return -1;
    }

    if(czyRemis())
    {

        return 0;

    }


    if(gracz==1)
        gracz = 2;
    else
        gracz = 1;


    if(gracz==2)
        mmx = 10;
    else
        mmx = -10;

    for(int i = 0; i < rozmiarPlanszy; i++)
    {

        if(plansza[i] == 0)
        {

            plansza[i] = gracz;

            m = minMax(gracz);

            plansza[i] = 0;

            if(((gracz == 2) && (m < mmx)) || ((gracz == 1) && (m > mmx)))
                mmx = m;
        }

    }

    return mmx;

}

int Kolkoikrzyzyk::ruchKomputera()
{

    int ruch=0, m, mmx;

    mmx = -10;

    for(int i = 0; i < rozmiarPlanszy; i++)
    {

        if(plansza[i]==0)
        {

            plansza[i] = 1;

            m = minMax(1);

            plansza[i] = 0;

            if(m > mmx)
            {

                mmx = m;
                ruch = i;

            }

        }
    }

    return ruch;

}


void Kolkoikrzyzyk::ruch(int gracz)
{

    int r;

        if(gracz==2)
    {

        cout<<endl;
        cout<<"Ruch gracza: ";

        do

        {
            cin>>r;
            r--;
            if(plansza[r]!=0 && r>=0) cout<<"Pole "<<r+1<<" zajete. Podaj inne, wolne."<<endl;
            if(r>rozmiarPlanszy || r<0) cout<<"Pole o takim numerze nie istnieje"<<endl;
        }
        while(plansza[r]!=0 || r>rozmiarPlanszy || r<0);
        plansza[r]=2;

    }
    else
    {

        r=ruchKomputera();
        cout<<endl;
        cout<<"Tura komputera"<<endl;
        plansza[r]=1;

    }


}

void Kolkoikrzyzyk::graj()
{
    int gracz;


    cout<<endl<<endl<<"Kto zaczyna? (1-komputer, 2-gracz)"<<endl;

    cin>>gracz;




    while(!czyWygrana(1) && !czyWygrana(2) && !czyRemis())
    {

        ruch(gracz);

    if(gracz==2)
    {
       gracz = 1;
    }
    else
    {
        gracz = 2;
    }
    rysujPlansze(false);
    }

    if(czyWygrana(1))
       {
            cout<<endl;

            cout<<endl<<"Wygrywa komputer!"<<endl;
       }
    else if(czyWygrana(2))
    {
        cout<<endl;

        cout<<endl<<"Wygrywa czlowiek!"<<endl<<endl;
    }

    else if(czyRemis())
    {
        cout<<endl;

        cout<<endl<<"Remis!"<<endl;
    }



}
