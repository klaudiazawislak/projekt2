#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <iomanip>
#include <cmath>
#include <conio.h>  //getch
#include<windows.h>
#include <cstdio>
#include <ctime>




using namespace std;

const int N = 100000;

int ile,i ;
clock_t start,stop;
double czas;
int*tab_pom;
int liczby[100];

void scal(int* tab, int from, int sr, int to) {
  for (int i = from; i <= to; i++)
    tab_pom[i] = tab[i];
  int i = from, j = sr + 1;
  for (int k = from; k <= to; k++) {
    if (i <= sr) {
      if (j <= to) {
        tab[k] = (tab_pom[j] < tab_pom[i]) ? tab_pom[j++] : tab_pom[i++];
      } else {
        tab[k] = tab_pom[i++];
      }
    } else {
      tab[k] = tab_pom[j++];
    }
  }
}
void sortowaniescalanie(int* tab, int from, int to) {
  if (to <= from)
    return;
  int sr = (to + from) / 2;
  sortowaniescalanie(tab, from, sr);
  sortowaniescalanie(tab, sr + 1, to);
  scal(tab, from, sr, to);
}





void wstaw(int tab[],int n)  //funkcja zape³niaj¹ca tablicê
{
    for(int i=0; i<n; i++)
        tab[i]=rand()%1000;
}

void drukuj(int tab[],int n)
{
    for(int i =0; i<n; i++)
        cout<<tab[i]<<" ";
    cout<<endl;
} //funkcja do wyœwietlenia tablicy

void zanurzanie(int i, int kolejka[], int rozmiarKolejki)
{
    int l=2*i+1;
    int r=2*i+2;
    int wiekszy = i;
    if(l<rozmiarKolejki&&kolejka[l]>kolejka[wiekszy])//l<N-1
        wiekszy=l;
    if(r<rozmiarKolejki&&kolejka[r]>kolejka[wiekszy])//N-1
        wiekszy=r;
    if(wiekszy!=i)
    {
        swap(kolejka[wiekszy],kolejka[i]);
        zanurzanie(wiekszy,kolejka,rozmiarKolejki);
    }
}

void utworzKopiec(int tab[],int n)
{
    for(int i =n/2; i>=0; i--)
        zanurzanie(i,tab,n);
}
void sortuj(int tab[], int n)
{
    utworzKopiec(tab,n);
     for(int i = n; i>=1; i--)
    {
        swap(tab[0],tab[n-1]);
        --n;
        zanurzanie(0,tab,n);
    }

}



int main()
{
    fstream plik, wyniki;
    plik.open("tablica.txt",ios::in); // Otwarcie/utworzenie pliku, z którego pobierana bedzie tablica
    wyniki.open("wyniki.txt",ios::out); // Otwarcie/utworzenie pliku, do którego zapisywany bêdzie wynik

 cout<<"Program sortujacy przez scalanie oraz kopcowo, porownujacy dzialanie obu metod"<<endl;
 int x;
    cout<<"Jesli chcesz porownac czas dzialania obu metod wpisz 9 "<<endl;
    cout<<"Jesli chcesz posortowac dowolna tablice obiema metodami wpisz 6"<<endl;
    cout<<"Jesli chcesz odczytac tablice z pliku wpisz 3"<<endl;
    cin >> x;

    while((x!=9)&&(x!=6)&&(x!=3))//jezeli x nie jest rowny p,d lub o postepuj zgodnie z petla
    {
        cout<<"Wprowadz litere : 9, 6 lub 3! " <<endl;
        cin>>x;
    }

    if(x==9)
    {


     cout << "Porownanie czasow sortowania v.1" << endl;

    cout<<"Ile losowych liczb w tablicy: ";
    cin>>ile;

    //dynamiczna alokacja tablicy
    int *tablica;
    tablica=new int [ile];

	tab_pom = new int[ile];
  int* tab_pom = new int[ile];

     int *tablica2;
    tablica2=new int [ile];

    //inicjowanie generatora
    srand(time(NULL));

    //wczytywanie losowych liczb do tablicy
    for(int i=0; i<ile; i++)
    {
        tablica[i] = rand()%1000+1;
    }
 //przepisanie tablicy do tablicy2
    for(int i=0; i<ile; i++)
    {
       tablica2[i]=tablica[i];
    }
     for(int i=0; i<ile; i++)
    {
       tab_pom[i]=tablica[i];
    }



        cout<<"Przed posortowaniem: "<<endl;
        for(int i=0; i<ile; i++)
        {
            cout<<tablica[i]<<" ";
        }


 cout<<"Sortuje teraz przez scalanie. Prosze czekac!"<<endl;
    start = clock();
      sortowaniescalanie(tablica, 0, ile - 1);
    stop = clock();
    czas = (double)(stop-start) / CLOCKS_PER_SEC;
    cout<<endl<<"Czas sortowania przez scalanie: "<<czas<<" s"<<endl;

 cout<<"Po posortowaniu: "<<endl;
        for(int i=0; i<ile; i++)
        {
            cout<<tablica[i]<<" ";
        }


    cout<<endl<<"Sortuje teraz kopcowo. Prosze czekac!"<<endl;
    start = clock();
    drukuj(tablica, 0);
    stop = clock();
    czas = (double)(stop-start) / CLOCKS_PER_SEC;
    cout<<endl<<"Czas sortowania kopcowego: "<<czas<<" s"<<endl;

cout<<"Po posortowaniu: "<<endl;
        for(int i=0; i<ile; i++)
        {
            cout<<tablica[i]<<" ";
        }


    delete [] tablica;
    delete [] tablica2;
    delete[] tab_pom;

    }


        if(x==6)
     {
        cout << "Program sortujacy przez scalanie i kopcowo" << endl<<endl;

        cout<<"Ile losowych liczb w tablicy: ";
        cin>>ile;

        int *tablica; //dynamiczna alokacja tablicy
        tablica=new int [ile];

        int *tablica2;
        tablica2=new int [ile];

        srand(time(NULL));    //inicjowanie generatora

        for(int i=0; i<ile; i++)     //wczytywanie losowych liczb do tablicy
        {
            tablica[i] = rand()%100000+1;
        }
        for(int i=0; i<ile; i++) //przepisanie tablicy do tablicy2
        {
            tablica2[i]=tablica[i];
        }

        cout<<"Przed posortowaniem: "<<endl;
        wyniki<<"Przed posortowaniem: "<<endl;
        for(int i=0; i<ile; i++)
        {
            cout<<tablica[i]<<" ";
            wyniki<<tablica[i]<<" ";
        }

        cout<<endl<<endl<<"Sortuje przez scalanie."<<endl;

        sortowaniescalanie(tablica, 0, ile - 1);

        cout<<"Po posortowaniu przez scalanie: "<<endl;
        wyniki <<"\n"<< "Po posortowaniu przez scalanie: "<<endl; //wczytywanie tablicy do pliku
        for(int i=0; i<ile; i++)
        {
            cout<<tablica[i]<<" ";
            wyniki<< tablica[i] <<" "; //wczytywanie tablicy do pliku
        }

        cout<<endl<<endl<<"Sortuje kopcowe."<<endl;
        sortuj(tablica2,ile);

        cout<<"Po posortowaniu kopcowym: "<<endl;
        wyniki <<"\n"<< "Po posortowaniu kopcowym: "<<endl;
        for(int i=0; i<ile; i++)
        {
            cout<<tablica[i]<<" ";
            wyniki<< tablica[i] <<" ";
        }

        cout<<endl;
        delete [] tablica;
        delete [] tablica2;
    }

if(x==3)
    {
        int ile=100;  //liczba elementow w pliku  //funkcja do wczytywania tablic do testow
    int tablica[ile];  //zadeklarowanie dwoch tablic
    int tablica2[ile];

    for(int i=0; i<ile; i++) //petla wpisujaca elementy z pliku do tablicy
    {
        plik>>tablica[i];
    }
        cout<<"Przed posortowaniem: "<<endl;
        wyniki<<"Przed posortowaniem: "<<endl;
        for (int i=0; i < ile; i++)
        {
            cout << tablica[i] << " ";
            wyniki<<tablica[i]<<" ";
        }

        cout<<endl<<endl<<"Sortuje przez scalanie."<<endl;
        sortowaniescalanie(tablica, 0, ile - 1);

        cout<<endl<<endl<<"Sortuje kopcowe."<<endl;
        sortuj(tablica2,ile);
        cout<<endl;

        //zapisanie do pliku
        cout<<"Po posortowaniu: "<<endl;
        wyniki<<"\n"<<"Po posortowaniu: "<<endl;
        for (int i=0; i < ile; i++)
        {
            cout<<tablica[i]<<" ";
            wyniki<< tablica[i] << " ";
        }
        plik.close();
        wyniki.close();
    }
    return 0;
}
