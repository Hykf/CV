#include <iostream>
#include <vector>
#include <stdio.h>
#include <unistd.h> //you need this for linux!
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <windows.h>

using namespace std;

//STRUCTY ::
struct nazwa{

  std::string ID;
  std::string tekst;

   //std::string wybory ; //tu jeszcze dorobic string z wyborami A,B,C,D

  std::string A;
  std::string konsekwencjeA; //dla B,C,D tez beda

  std::string B;
  std::string konsekwencjeB; //dla B,C,D tez beda

  std::string C;
  std::string konsekwencjeC; //dla B,C,D tez beda

  std::string D;
  std::string konsekwencjeD; //dla B,C,D tez beda

    nazwa(std::string t,std::string id){
      tekst = t;
      ID = id;

  }

  nazwa(std::string t,std::string id,std::string a){
      tekst = t;
      ID = id;
      A = a;
  }

   nazwa(std::string t,std::string id,std::string a,std::string KonA){
      tekst = t;
      ID = id;
      A = a;
      konsekwencjeA = KonA;
  }

   nazwa(std::string t,std::string id,std::string a,std::string KonA,std::string b,std::string KonB){
      tekst = t;
      ID = id;
      A = a;
      konsekwencjeA = KonA;
      B = b;
      konsekwencjeB = KonB;
  }

    nazwa(std::string t,std::string id,std::string a,std::string KonA,std::string b,std::string KonB,std::string c,std::string KonC){
      tekst = t;
      ID = id;
      A = a;
      konsekwencjeA = KonA;
      B = b;
      konsekwencjeB = KonB;
      C = c;
      konsekwencjeC = KonC;
  }

      nazwa(std::string t,std::string id,std::string a,std::string KonA,std::string b,std::string KonB,std::string c,std::string KonC,std::string d,std::string KonD){
      tekst = t;
      ID = id;
      A = a;
      konsekwencjeA = KonA;
      B = b;
      konsekwencjeB = KonB;
      C = c;
      konsekwencjeC = KonC;
      D = d;
      konsekwencjeD = KonD;
  }






      std::string getText(){
      return tekst;
  }

      std::string getA(){
      return A;
  }

      std::string getKonA(){
      return konsekwencjeA;
  }

      std::string getB(){
      return B;
  }

      std::string getKonB(){
      return konsekwencjeB;
  }

      std::string getC(){
      return C;
  }

      std::string getKonC(){
      return konsekwencjeC;
  }

      std::string getD(){
      return D;
  }

      std::string getKonD(){
      return konsekwencjeD;
  }



};

struct Item{
    std::string nazwa;
    float attackBonus;
    double defBonus;


    Item(std::string n, int a){
        nazwa = n;
        attackBonus = a;
    }

    Item(std::string n, double a){
        nazwa = n;
        defBonus = a;
    }


};

struct Potki{
    std::string nazwa;
    float dodajMane;
    float dodajHP;


    Potki(std::string name,float a,float b){
        nazwa = name;
        dodajHP = a;
        dodajMane = b;
    }

};

struct Enemy{
  std::string nazwa;
  float hp;
  int speed;
  float damage;
  int dodgeChance;

  Enemy(std::string n,float a,int b, float c,int d){
   nazwa = n;
   hp = a;
   speed = b;
   damage = c;
   dodgeChance = d;
  }
  Enemy(){
  }


};

struct Hero{

  vector<Potki> pots;
  vector<Item> items;
  int pieniadze;
  float attackBonus;
  float defBonus;

  float hp;
  float maxHP;
  int speed;
  float damage;
  int mana;
  int maxMana;
  int szansaNaUnik;

  int sila; //damage
  int zwinnosc; //speed
  int inteligencja; //magia
  int kondycja; //hp

  Hero(int a,int b, int c, int d,vector<Potki> p,vector<Item> i){

      attackBonus = 0.5;
      defBonus = 1;
      pieniadze = 1000;

      pots = p;
      items = i;
      sila = a;
      zwinnosc = b;
      inteligencja = c;
      kondycja = d;

        switch(sila){
        case 1:
            damage = 10;
            break;
        case 2:
           damage = 20;
            break;
        case 3:
            damage = 30;
            break;
        case 4:
            damage = 40;
            break;
        case 5:
           damage = 50;
            break;
    }
        switch(zwinnosc){
        case 1:
            speed = 1;
            szansaNaUnik = 5;
            break;
        case 2:
            speed = 2;
            szansaNaUnik =10;
            break;
        case 3:
            speed = 3;
            szansaNaUnik = 15;
            break;
        case 4:
            speed = 4;
            szansaNaUnik = 20;
            break;
        case 5:
            speed = 5;
            szansaNaUnik =25;
            break;
    }
        switch(inteligencja){
        case 1:
            mana = 75;
            break;
        case 2:
            mana = 85;
            break;
        case 3:
            mana = 100;
            break;
        case 4:
            mana = 125;
            break;
        case 5:
            mana = 150;
            break;
    }
        switch(kondycja){
        case 1:
            hp = 75;
            break;
        case 2:
            hp = 85;
            break;
        case 3:
            hp = 100;
            break;
        case 4:
            hp = 125;
            break;
        case 5:
            hp = 150;
            break;
    }

    maxHP = hp;
    maxMana = mana;

  }

   Hero(int a,int b, int c, int d){

      attackBonus = 0.9;
      defBonus = 0.9;
      pieniadze = 100;

      sila = a;
      zwinnosc = b;
      inteligencja = c;
      kondycja = d;

        switch(sila){
        case 1:
            damage = 10;
            break;
        case 2:
           damage = 20;
            break;
        case 3:
            damage = 30;
            break;
        case 4:
            damage = 40;
            break;
        case 5:
           damage = 50;
            break;
    }
        switch(zwinnosc){
        case 1:
            speed = 1;
            szansaNaUnik = 5;
            break;
        case 2:
            speed = 2;
            szansaNaUnik =10;
            break;
        case 3:
            speed = 3;
            szansaNaUnik = 15;
            break;
        case 4:
            speed = 4;
            szansaNaUnik = 20;
            break;
        case 5:
            speed = 5;
            szansaNaUnik =25;
            break;
    }
        switch(inteligencja){
        case 1:
            mana = 75;
            break;
        case 2:
            mana = 85;
            break;
        case 3:
            mana = 100;
            break;
        case 4:
            mana = 125;
            break;
        case 5:
            mana = 150;
            break;
    }
        switch(kondycja){
        case 1:
            hp = 75;
            break;
        case 2:
            hp = 85;
            break;
        case 3:
            hp = 100;
            break;
        case 4:
            hp = 125;
            break;
        case 5:
            hp = 150;
            break;
    }
    maxHP = hp;
    maxMana = mana;
  }


  void use(Potki pot){

        static float maxHP = hp;


        if(hp>maxHP){
            hp=maxHP;
        }else{
            hp += pot.dodajHP;
        }



        static int maxMana = mana;


        if(mana>maxMana){
            mana=maxMana;
        }else{
            mana +=pot.dodajMane;
        }

    }

    void modyfikujPieniadze(int a){
        pieniadze -= a;
    }



};


//METODY POMOCNICZE::
void Klimat(std::string s){

string tekst = s;
int x=0;
while ( tekst[x] != '\0')
{
	cout << tekst[x];
	Sleep(5);//PAMIETAJ BY ZMIENIC TU NA 5
	x++;
};

cout<<"\n";

}

std::string wydarzenieWalka(std::string wrog,std::string nas){
        cout<<"zaczynasz walke z: "<<wrog<<endl;
        return nas;
    }

void GameOver(){
    Klimat("Tu konczy sie twoja przygoda");
    int i;
    cin>>i;
    exit(0);
}

void drop(Hero gracz){


    srand (time(NULL));
  int iSecret = rand() % 10 + 1;
  int randKasa = rand() % 550+ 1;
  if(iSecret==1){
      if(gracz.defBonus>0.8){
        cout<<"wrog mial przy sobie cos co poprawi twoj pancerz"<<endl;
        gracz.defBonus=0.8;
      }else{
           cout<<"wrog mial przy sobie przedmiot ktory jest gorszy od tego ktory obecnie posiadasz"<<endl;
      }
  }else if(iSecret==2){
      if(gracz.attackBonus<1.2){
        cout<<"wrog mial przy sobie miecz lepszy od twojego obecnego"<<endl;
        gracz.attackBonus=1.2;
      }else{
           cout<<"wrog mial przy sobie przedmiot ktory jest gorszy od tego ktory obecnie posiadasz"<<endl;
      }
  }else if(iSecret>2 && iSecret<6){
      cout<<"wrog mial przy sobie " <<randKasa<<" zlota ktore teraz nalezy do ciebie."<<endl;

  }else{
      cout<<"wrog nie mial nic przy sobie"<<endl;
  }

}

Hero Character(){

    int kondycjaTemp;
    int silaTemp;
    int zwinnoscTemp;
    int inteligencjaTemp;
    int sumaKontrolna ;
    int wybor;
    bool ok = false;
    bool okW = false;
    Klimat("To jest kreator postac\nNalezy rozdysponowac 12 punktow pomiedzy 4 statystyki(kondycje sile zwinnosc inteligencje)\nMaksymalnie mozna przydzielic 5 punktow.\n");
    while(ok!=true){

        while(okW!=true){

           Klimat("Ile punktow chcesz przeznaczyc na Kondycje?");
            cout<<"Kondycja: ";
            cin>>wybor;
            if(wybor==1){
                kondycjaTemp = 1;
                okW = true;
            }else if(wybor==2){
                kondycjaTemp = 2;
                okW = true;
            }else if(wybor==3){
                kondycjaTemp = 3;
                okW = true;
            }else if(wybor==4){
                kondycjaTemp = 4;
                okW = true;
            }else if(wybor==5){
                kondycjaTemp = 5;
                okW = true;
            }else{
            Klimat("Nieprawidlowa wartsoc\n");
            }
        }//Kondycja
        okW = false;

        while(okW!=true){

            Klimat("Ile punktow chcesz przeznaczyc na SILE?");
            cout<<"Sila: ";
            cin>>wybor;
            if(wybor==1){
                silaTemp = 1;
                okW = true;
            }else if(wybor==2){
                silaTemp = 2;
                okW = true;
            }else if(wybor==3){
                silaTemp = 3;
                okW = true;
            }else if(wybor==4){
                silaTemp = 4;
                okW = true;
            }else if(wybor==5){
                silaTemp = 5;
                okW = true;
            }else{
           Klimat("Nieprawidlowa wartsoc\n");
            }
        }//SILA
        okW = false;

        while(okW!=true){

            Klimat("Ile punktow chcesz przeznaczyc na Zwinnosc?");
            cout<<"Zwinnosc: ";
            cin>>wybor;
            if(wybor==1){
                zwinnoscTemp = 1;
                okW = true;
            }else if(wybor==2){
                zwinnoscTemp = 2;
                okW = true;
            }else if(wybor==3){
                zwinnoscTemp = 3;
                okW = true;
            }else if(wybor==4){
                zwinnoscTemp = 4;
                okW = true;
            }else if(wybor==5){
                zwinnoscTemp = 5;
                okW = true;
            }else{
            Klimat("Nieprawidlowa wartsoc\n");
            }
        }//ZWINNOSC
        okW = false;


        while(okW!=true){

            Klimat("Ile punktow chcesz przeznaczyc na Inteligencje?");
            cout<<"Inteligencja: ";
            cin>>wybor;
            if(wybor==1){
                inteligencjaTemp = 1;
                okW = true;
            }else if(wybor==2){
                inteligencjaTemp = 2;
                okW = true;
            }else if(wybor==3){
                inteligencjaTemp = 3;
                okW = true;
            }else if(wybor==4){
                inteligencjaTemp = 4;
                okW = true;
            }else if(wybor==5){
                inteligencjaTemp = 5;
                okW = true;
            }else{
            Klimat("Nieprawidlowa wartsoc\n");
            }
        }//INT
        okW = false;

        int sumaKontrolna = kondycjaTemp + silaTemp + zwinnoscTemp + inteligencjaTemp;

        cout<<"\nKondycja: "<<kondycjaTemp<<endl;
        cout<<"Sila: "<<silaTemp<<endl;
        cout<<"Zwinnosc: "<<zwinnoscTemp<<endl;
        cout<<"Inteligencja: "<<inteligencjaTemp<<endl;


        if(sumaKontrolna!=12){
            cout<<"\nNieprawidlowo rozdane statystyki:\n";
        }else{
            cout<<"Zakonczono robienie Postaci\n\nTwoja podroz sie rozpoczyna";
            Klimat("\n\n\n\n\n\n");
            ok = true;
            break;
        }



    }


     return Hero(silaTemp,zwinnoscTemp,inteligencjaTemp,kondycjaTemp);

}

int nagroda(Hero gracz){

    Klimat("Jako nagrode mozesz wybrac 1 z 3 mikstur");

    int i;
    bool wybor = false;
    Potki MiksturkaOdWrozki("Miksturka od wrozki",50,50);
    while(wybor==false){

        Klimat("1.Mikstura zdrowia\n2.Mikstura many\n3.Tajemnicza mikstura");
        cin>>i;
        cout<<("Wybieram: ")<<endl;

        if(i==1){
            Potki MiksturaZdrowia("Mikstura zdrowia",50,0);
            gracz.pots.push_back(MiksturaZdrowia);
            Klimat("Wybrales "+ MiksturaZdrowia.nazwa);
            wybor = true;

        }else if(i==2){
            Potki MiksturaMany("Mikstura many",0,50);
            gracz.pots.push_back(MiksturaMany);
            Klimat("Wybrales "+ MiksturaMany.nazwa);
            wybor = true;

        }else if(i==3){
            Potki TajPotek("Tajemnicza mikstura",-50,75);
            gracz.pots.push_back(TajPotek);
            Klimat("Wybrales "+ TajPotek.nazwa);
            wybor = true;

        }else{
            Klimat("Nieprawidlowy wybor");
            continue;
        }
    break;
    }

    return i;

}


int zakupyUAlchemiczki(Hero gracz){

    Klimat("Pieniadze: "+to_string(gracz.pieniadze));

    int i;
    bool wybor = false;
    while(wybor!=true){
        Klimat("1.Zestaw malych mikstur (100) \n2.Zestaw srednich mikstur (150) \n3.Zestaw duzych mikstur (250) \n4.Rozmyslilem sie");
        cin>>i;
        Klimat("Kupuje: ");
        if(i==1){
            if(gracz.pieniadze>=100){
            }else{
                Klimat("Nie stac mnie na to");
                continue;
            }
            wybor = true;
            break;
        }else if(i==2){
            if(gracz.pieniadze>=150){
            }else{
                Klimat("Nie stac mnie na to");
                continue;
            }
            wybor = true;
            break;
        }else if(i==3){
            if(gracz.pieniadze>=250){
            }else{
                Klimat("Nie stac mnie na to");
                continue;
            }
            wybor = true;
            break;
        }else if(i==4){
            wybor = true;
            Klimat("Nic");
            break;
        }else{
            Klimat("Nieprawidlowy wybor");
            continue;
        }

    }
    return i;
}

int zakupyUKowala(Hero gracz){

    Klimat("Pieniadze: "+to_string(gracz.pieniadze));

    int i;
    bool wybor = false;
    while(wybor!=true){
        Klimat("1.Miecz jednoreczny (300) \n2.Miecz poltora-reczny (450) \n3.Wielki miecz dwureczny (650) \n4.Rozmyslilem sie");
        cin>>i;
        Klimat("Kupuje: ");
        if(i==1){
            if(gracz.pieniadze>=300){
            }else{
                Klimat("Nie stac mnie na to");
                continue;
            }
            wybor = true;
            break;
        }else if(i==2){
            if(gracz.pieniadze>=450){
            }else{
                Klimat("Nie stac mnie na to");
                continue;
            }
            wybor = true;
            break;
        }else if(i==3){
            if(gracz.pieniadze>=650){
            }else{
                Klimat("Nie stac mnie na to");
                continue;
            }
            wybor = true;
            break;
        }else if(i==4){
            wybor = true;
            Klimat("Nic");
            break;
        }else{
            Klimat("Nieprawidlowy wybor");
            continue;
        }

    }
    return i;
}

int zakupyUPlatnerza(Hero gracz){

    Klimat("Pieniadze: "+to_string(gracz.pieniadze));

    int i;
    bool wybor = false;
    while(wybor!=true){
        Klimat("1.Lekka zbroja (200) \n2.Srednia zbroja (350) \n3.Ciezka zbroja (500) \n4.Rozmyslilem sie");
        cin>>i;
        Klimat("Kupuje: ");
        if(i==1){
            if(gracz.pieniadze>=200){
            }else{
                Klimat("Nie stac mnie na to");
                continue;
            }
            wybor = true;
            break;
        }else if(i==2){
            if(gracz.pieniadze>=350){
            }else{
                Klimat("Nie stac mnie na to");
                continue;
            }
            wybor = true;
            break;
        }else if(i==3){
            if(gracz.pieniadze>=500){
            }else{
                Klimat("Nie stac mnie na to");
                continue;
            }
            wybor = true;
            break;
        }else if(i==4){
            wybor = true;
            Klimat("Nic");
            break;
        }else{
            Klimat("Nieprawidlowy wybor");
            continue;
        }

    }
    return i;
}

int zakupyUPodroznika(Hero gracz){

Klimat("Pieniadze: "+to_string(gracz.pieniadze));

    int i;
    bool wybor = false;
    while(wybor!=true){
        Klimat("1.Zestaw malych mikstur (100) \n2.Zestaw srednich mikstur (150) \n3.Zestaw duzych mikstur (250) \n4.Rozmyslilem sie");
        cin>>i;
        Klimat("Kupuje: ");
        if(i==1){
            if(gracz.pieniadze>=100){
            }else{
                Klimat("Nie stac mnie na to");
                continue;
            }
            wybor = true;
            break;
        }else if(i==2){
            if(gracz.pieniadze>=150){
            }else{
                Klimat("Nie stac mnie na to");
                continue;
            }
            wybor = true;
            break;
        }else if(i==3){
            if(gracz.pieniadze>=250){
            }else{
                Klimat("Nie stac mnie na to");
                continue;
            }
            wybor = true;
            break;
        }else if(i==4){
            wybor = true;
            Klimat("Nic");
            break;
        }else{
            Klimat("Nieprawidlowy wybor");
            continue;
        }

    }
    return i;
}


//METODY GLOWNE::


std::string walka(Hero gracz,Enemy wrog,std::string tekst){



    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);

     srand (time(NULL));
     cout<<"\n";
     cout<<"########################################"<<endl;
     Klimat("Zaczynasz walke z:");
     SetConsoleTextAttribute(hc,014);
     cout<<wrog.nazwa;
     cout<<"\n";
     SetConsoleTextAttribute(hc,02);
    bool mojaTura = true;
    if(wrog.speed>gracz.speed){
         mojaTura = false;
    }

    int ruch = 0;
    while(wrog.hp>=0||gracz.hp>=0){

        float maxHp = gracz.hp;
while(1){
        while(mojaTura==true){
            int szansaNaTrafienie = rand() % 100 + 1;
            SetConsoleTextAttribute(hc,017);
            cout<<"########################################"<<endl;
            SetConsoleTextAttribute(hc,02);
            Klimat("TWOJA TURA!\n");
            SetConsoleTextAttribute(hc,014);
            std::cout<<"HP "<<wrog.nazwa<<":"<<wrog.hp<<"\n"<<endl;
            SetConsoleTextAttribute(hc,012);
            std::cout<<"HP:"<< gracz.hp<<"    ";
            SetConsoleTextAttribute(hc,013);
            cout<<"MANA:"<<  gracz.mana<<"\n"<<endl;
            SetConsoleTextAttribute(hc,017);

            std::cout << "1.Lekki cios\n2.Silny cios\n";

            cout<<"3.Magia\n";

            cout<<"4.Przedmioty\n" << std::endl;
            std::cin >> ruch;
            if(ruch==1){

               if(szansaNaTrafienie>wrog.dodgeChance){
                    wrog.hp-=(gracz.damage*0.75*gracz.attackBonus);
                      if(wrog.hp<=0){
                        Klimat(wrog.nazwa+" pokonany!");
                        //drop(gracz);
                        mojaTura = false;

                      }else{
                         cout<<wrog.nazwa<<" otrzymal: "<<gracz.damage*0.75*gracz.attackBonus<<endl;
                         mojaTura = false;
                      }
                      }else{
                        Klimat("Wrog zrobil unik");
                        mojaTura = false;
                      }

            }else if(ruch==2){
                if(szansaNaTrafienie>wrog.dodgeChance+25){
                    wrog.hp-=(gracz.damage*1.3*gracz.attackBonus);
                      if(wrog.hp<=0){
                        Klimat(wrog.nazwa+" pokonany!");
                        //drop(gracz);
                        mojaTura = false;
                        break;
                      }else{
                         Klimat(wrog.nazwa+" otrzymal: "+to_string(gracz.damage*1.2*gracz.attackBonus));
                         mojaTura = false;
                    }
                }else{
                        Klimat("Wrog zrobil unik");
                        mojaTura = false;
                }



        }else if(ruch==3){

            int wyborZaklecia;
            while(1){
                cout<<"1.Heal (20)\n2.Fireball (25)\n3.Ice Ray (45)\n\n\n0.Nic nie rob (pass)\n\n"<<endl;
                cin>>wyborZaklecia;

                if(wyborZaklecia==1){

                    if(gracz.mana<20){
                        Klimat("Nie masz wystarczajacej ilosci many na zadne zaklecie");
                        continue;
                    }else{
                        gracz.hp +=8*gracz.inteligencja;
                        Klimat("Leczenie za:" + to_string(5*gracz.inteligencja));
                        if(gracz.hp>maxHp){
                            gracz.hp = maxHp;
                        }
                        SetConsoleTextAttribute(hc,012);
                        cout<<"HP:"<<gracz.hp<<endl;
                        SetConsoleTextAttribute(hc,017);
                        gracz.mana-=20;
                        mojaTura = false;
                        break;
                    }
                }else if(wyborZaklecia==2){

                    if(gracz.mana<25){
                        Klimat("Nie masz wystarczajacej ilosci many na zadne zaklecie");
                        continue;
                    }else{
                        wrog.hp -=8*gracz.inteligencja;
                            if(wrog.hp<=0){
                            Klimat(wrog.nazwa+" pokonany!");
                            drop(gracz);
                            mojaTura = false;
                            break;
                          }else{
                             Klimat(wrog.nazwa+" otrzymal: "+ to_string(5*gracz.inteligencja));
                             gracz.mana-=20;
                             mojaTura = false;
                              break;
                          }

                    }
                }else if(wyborZaklecia==3){

                    if(gracz.mana<45){
                        Klimat("Nie masz wystarczajacej ilosci many na zadne zaklecie");
                        continue;
                    }else{
                        wrog.hp -=12*gracz.inteligencja;
                            if(wrog.hp<=0){
                            Klimat(wrog.nazwa+" pokonany!");
                            //drop(gracz);
                            mojaTura = false;
                            break;
                          }else{
                             Klimat(wrog.nazwa+" otrzymal: "+ to_string(12*gracz.inteligencja));
                             gracz.mana-=45;
                             mojaTura = false;
                              break;
                          }

                    }

                }else if(wyborZaklecia==0){
                    break;
                }



            }//while zaklecia

        //UZYCIE MAGI - Koniec
        }else if(ruch==4){


        int wyborPrzedmiotu;
        std::string wyborText;

            while(1){

                if(gracz.pots.size()!=0){

                for(int i=0;i<gracz.pots.size();i++){
                    wyborText += to_string(i+1);
                    wyborText += ".";
                    wyborText += gracz.pots[i].nazwa;
                    wyborText += "\n";
                }
                cout<< wyborText;
                cout<< "\n\n\n\n0.pass\n";
                cin>>wyborPrzedmiotu;
                if(wyborPrzedmiotu==0){
                    break;
                }


                gracz.use(gracz.pots[wyborPrzedmiotu-1]);
                gracz.pots.erase(gracz.pots.begin()+wyborPrzedmiotu-1);
                Klimat("Uzyles przedmiotu: "+ gracz.pots[wyborPrzedmiotu-1].nazwa);
                mojaTura = false;
                break;
            }else{
                Klimat("Nie masz zadnych mikstur");
                break;
            }


            }//while UZYCIE PRZEDMIOTU-Koniec
            mojaTura = false;

        }//Koniec ruchow gracza






      sleep(1);

    }

         if(wrog.hp>0){

        cout<<"\n\n";
        SetConsoleTextAttribute(hc,04);
        cout<<"*********************************************"<<endl;

        Klimat("WROGA TURA!");
        sleep(2);

        while(mojaTura==false){
            int wrogSzansaNaTrafienie = rand() % 100 + 1;
            SetConsoleTextAttribute(hc,014);
            if(wrogSzansaNaTrafienie>gracz.szansaNaUnik){
                Klimat( wrog.nazwa +" uderza za: "+to_string(wrog.damage*gracz.defBonus));
                gracz.hp-=wrog.damage*gracz.defBonus;
                mojaTura = true;
            }else{
            Klimat( wrog.nazwa+" atakuje ale udalo ci sie zrobic unik!");
            mojaTura = true;
            }
        }

        if(gracz.hp<=0){
            cout<<"PADLES!"<<endl;
            GameOver();

        }

        }

        if(wrog.hp<=0){

            break;
        }

    }



    drop(gracz);
    break;

  }//while (1)

  //cout<<"Zmienic typ na STRING i TU BEDZIE ID KTORE ZWRACA";
  return tekst;


}//funkcja

void Rozgrywka(vector<nazwa> karty,Hero gracz,vector<Enemy> wrogowie){
    std::string next = "INDEXSTART";

    int wybor;
    int karta;
    Enemy wrog;
    Potki potek("Mikstura zdrowia",20,0);

    while(1){

       for( int i = 0; i<karty.size(); i++){
          if(karty[i].ID==next){
              karta = i;
          }

            if(next=="LAS5_WALKA"){

                for(int j=0;j<wrogowie.size();j++){
                    if(wrogowie[j].nazwa=="Dzik"){
                         wrog = wrogowie[j];
                    }
                }
            next = walka(gracz,wrog,"LAS6");
          }

            if(next=="LAS10_WALKA"){


                for(int j=0;j<wrogowie.size();j++){
                    if(wrogowie[j].nazwa=="Klusownik"){
                         wrog = wrogowie[j];
                    }
                }
            next = walka(gracz,wrog,"LAS11");
          }
            if(next=="BAGNO5_WALKA"){

                for(int j=0;j<wrogowie.size();j++){
                    if(wrogowie[j].nazwa=="Waz"){
                         wrog = wrogowie[j];
                    }
                }
            next = walka(gracz,wrog,"BAGNO6");
          }

            if(next=="BAGNO10_WALKA"){

                for(int j=0;j<wrogowie.size();j++){
                    if(wrogowie[j].nazwa=="Krokodyl"){
                         wrog = wrogowie[j];
                    }
                }
            next = walka(gracz,wrog,"BAGNO11");
          }

            if(next=="JEZIORO8"){

                for(int j=0;j<wrogowie.size();j++){
                    if(wrogowie[j].nazwa=="$%!#&"){
                         wrog = wrogowie[j];
                    }
                }
            next = walka(gracz,wrog,"JEZIORO10");
          }



//ZAKUPY
          if(next=="PLATNERZZAKUPY"){

            int price = zakupyUPlatnerza(gracz);

        if(price==1){
            gracz.defBonus = 0.9;
            gracz.pieniadze -= 200;
            Klimat("Kupiles: Lekka zbroja");
        }else if(price==2){
            gracz.defBonus = 0.8;
            gracz.pieniadze -= 350;
            Klimat("Kupiles: Srednia zbroje");
        }else if(price==3){
            gracz.defBonus = 0.6;
            gracz.pieniadze -= 500;
            Klimat("Kupiles: Ciezka zbroje");
        }else{
        }

            next="MIASTO11";
          }

          if(next=="ALCHEMICZKAZAKUPY"){

            int price = zakupyUAlchemiczki(gracz); // zmienic

        if(price==1){
            Potki Mana("Mala mikstura many",0,20);
            Potki HP("Mala mikstura zdrowia",25,0);
            gracz.pots.push_back(Mana);
            gracz.pots.push_back(HP);
            gracz.pieniadze -= 100;
            Klimat("Kupiles: Zestaw mniejszych mikstur");
        }else if(price==2){
            Potki Mana("Mikstura many",0,50);
            Potki HP("Mikstura zdrowia",50,0);
            gracz.pots.push_back(Mana);
            gracz.pots.push_back(HP);
            gracz.pieniadze -= 150;
            Klimat("Kupiles: Zestaw mniejszych mikstur");
        }else if(price==3){
            Potki Mana("duza mikstura many",0,100);
            Potki HP("Duza mikstura zdrowia",100,0);
            gracz.pots.push_back(Mana);
            gracz.pots.push_back(HP);
            gracz.pieniadze -= 250;
            Klimat("Kupiles: Zestaw wiekszych mikstur");
        }else{
        }

            next="MIASTO11";
          }

          if(next=="KOWALZAKUPY"){

            int price = zakupyUKowala(gracz); // zmienic

        if(price==1){
            gracz.attackBonus = 1.1;
            gracz.pieniadze -= 300;
            Klimat("Kupiles: Miecz jednoreczny");
        }else if(price==2){
            gracz.attackBonus = 1.2;
            gracz.pieniadze -= 450;
            Klimat("Kupiles: Miecz poltora-reczny");
        }else if(price==3){
            gracz.attackBonus = 1.3;
            gracz.pieniadze -= 650;
            Klimat("Kupiles: Wielki dwureczny miecz");
        }else{
        }

            next="MIASTO11";
          }

          if(next=="KUPIECZAKUPY"){

            int price = zakupyUPodroznika(gracz); // zmienic

        if(price==1){
            Potki Mana("Mala mikstura many",0,20);
            Potki HP("Mala mikstura zdrowia",25,0);
            gracz.pots.push_back(Mana);
            gracz.pots.push_back(HP);
            gracz.pieniadze -= 100;
            Klimat("Kupiles: Zestaw mniejszych mikstur");
        }else if(price==2){
            Potki Mana("Mikstura many",0,50);
            Potki HP("Mikstura zdrowia",50,0);
            gracz.pots.push_back(Mana);
            gracz.pots.push_back(HP);
            gracz.pieniadze -= 150;
            Klimat("Kupiles: Zestaw mniejszych mikstur");
        }else if(price==3){
            Potki Mana("duza mikstura many",0,100);
            Potki HP("Duza mikstura zdrowia",100,0);
            gracz.pots.push_back(Mana);
            gracz.pots.push_back(HP);
            gracz.pieniadze -= 250;
            Klimat("Kupiles: Zestaw wiekszych mikstur");
        }else{
        }

            next="POLANA4";
          }







//ZAKUPY

          if(next=="BAGNO8"){
            Klimat("Po wzieciu lyka z kotla. Twoje powieki staja sie coraz ciezsze.\nZasypiasz\nI juz sie wiecej nie budzisz");
            GameOver();
          }

          if(next=="JEZIORO_SMIERC"){
            Klimat("Powoli zaczynasz tracic kontakt ze swiatem, by po chwili stracic go calkowicie");
            GameOver();
          }

          if(next=="BAGNO9"){

            int price = nagroda(gracz);
                bool wybrane = true;

        if(price==1 && wybrane==true){
            Potki MiksturaZdrowia("Mikstura zdrowia",50,0);
            gracz.pots.push_back(MiksturaZdrowia);
            Klimat("Wybrales "+ MiksturaZdrowia.nazwa);
            wybrane = false;

        }else if(price==2 &&wybrane ==true){
            Potki MiksturaMany("Mikstura many",0,50);
            gracz.pots.push_back(MiksturaMany);
            Klimat("Wybrales "+ MiksturaMany.nazwa);
            wybrane = false;

        }else if(price==3 && wybrane==true){
            Potki TajPotek("Tajemnicza mikstura",-50,75);
            gracz.pots.push_back(TajPotek);
            Klimat("Wybrales "+ TajPotek.nazwa);
            wybrane = false;

        }


            next="POLANA1";
          }

          if(next=="GORA5"){
            Klimat("Twoje powieki staja sie coraz ciezsze.\nZasypiasz\nI juz sie wiecej nie budzisz");
            GameOver();
          }

         if(next=="POLANA3"){
            gracz.hp+=50;

            bool daj = true;
            if(daj==true){
            Potki MiksturkaOdWrozki("Miksturka od wrozki",50,50);
            gracz.pots.push_back(MiksturkaOdWrozki);
            daj = false;

            }

            if(gracz.hp>gracz.maxHP){
                gracz.hp = gracz.maxHP;
            }
               gracz.mana+=50;
            if(gracz.mana>gracz.maxMana){
                gracz.mana = gracz.maxMana;
            }
          }

         if(next=="LAS12"){
            gracz.hp+=50;
            if(gracz.hp>gracz.maxHP){
                gracz.hp = gracz.maxHP;
            }
               gracz.mana+=50;
            if(gracz.mana>gracz.maxMana){
                gracz.mana = gracz.maxMana;
            }

          }


       }

            system("Color 0F");
            Klimat(karty[karta].getText());
            Klimat(karty[karta].getA());
            Klimat( karty[karta].getB() );
            Klimat(karty[karta].getC());
            Klimat(karty[karta].getD());
            bool nowyWybor = false;
            while(nowyWybor==false){
                cout<<"Co chcesz zrobic ? "<<endl;
                std::cin >> wybor;
                if(wybor==1){
                    karty[karta].getKonA();
                   next = karty[karta].getKonA();
                    break;
                }else if(wybor==2){
                    next = karty[karta].getKonB();
                    break;
                }else if(wybor==3){
                   next = karty[karta].getKonC();
                    break;
                }else if(wybor==4){
                   next = karty[karta].getKonD();
                    break;
                }else{

                }

                if(next==""){
                     nowyWybor = false;
                }else{
                    nowyWybor = true;
                }

            }
    }
}




int main()
{
    //TOWRZENIE POSTACI
    vector<Potki> flaszki;
    vector<Item> eq;


    Hero ja = Character();
    //Hero ja(3,3,3,3);
    ja.items = eq;
    ja.pots = flaszki;
    ja.attackBonus = 0.9;
    ja.defBonus = 1;
    ja.pieniadze = 1000;
    //


     Potki potek("Mikstura zdrowia",20,0);
     Potki manaPotek("Mikstura many",0,20);
     Potki GreaterHpPotek("GreaterHpPotek",50,0);
     Potki MiksturkaOdWrozki("Miksturka od wrozki",50,50);


   // flaszki.push_back(potek);
   // flaszki.push_back(manaPotek);
   // flaszki.push_back(GreaterHpPotek);
  //  flaszki.push_back(LesserHpPotek);


    //HP,speed,dmg,dodge
    Enemy chimera("$%!#&",200,2,55,10);
    Enemy dzik("Dzik",140,5,40,20);
    Enemy czlowiek("Klusownik",110,3,35,45);
    Enemy waz("Waz",80,4,35,30);
    Enemy krokodyl("Krokodyl",110,2,45,30);

    vector<Enemy> przeciwnicy;
    przeciwnicy.push_back(chimera);
    przeciwnicy.push_back(dzik);
    przeciwnicy.push_back(czlowiek);
    przeciwnicy.push_back(waz);
    przeciwnicy.push_back(krokodyl);


    nazwa IndexStart("Jestes zwyklym poszukiwaczem przygod ktoremu sie nie przelewa,wlasnie wychodzisz z karczmy z nowym zleceniem ktorego kwota opiewa 10 000 sztuk zlota. Wiesz ze zadanie za taka ilosc pieniedzy nie moze byc latwe. ","INDEXSTART","1.Idz do zleceniodawcy","MIASTO1");
    nazwa Miasto0("Gdzie teraz powinienem sie udac ?","MIASTO0","1.)Idz do zleceniodawcy","MIASTO1");
    nazwa Miasto1("Podchodzisz pod adres wskazany na ogloszeniu. [PUKASZ] .Slyszysz dobiegajace ze srodka *WEJSC*. Gdy wchodzisz widzisz zasypany zwoijami pokoj. Procz tego zauwazasz ze w pokoju na przy kazdej scianie stoi regal z ksiazkami, a posrod nich niski mezczyzna watlej postury.Z siwa broda siegajaca do kolan. Po chwili przegladania zwoju odwraca sie do ciebie i mowi:\n-Witaj podrozniku, widze ze masz ze soba zlecenie ktore wystawilem w karczmie.Wiec zgaduje ze jestes zainteresowany.Opowien ci na czym twoje zadanie bedzie polegac:Udasz sie na polnoc za gory. Za gorami po mniej wiecej dniu drogi, trafisz na ogromne jezioro. Na jego dnie znajduja sie starozytne elfickie ruiny.","MIASTO1","1)Skoro juz to wszystko mi powiedziales to co stoi na drodze bym sie udal tam na wlasna reke ?","MIASTO5","2).Czego potrzebujesz z tych ruin ?","MIASTO6");
    nazwa Miasto2("Wchodzac do kuzni widzisz krasnoluda wykuwajacego wlasnie miecz.Po chwili podchodzi do ciebie i pyta sie :* \nW czym moge pomoc ?*\n ","MIASTO2","1) Rozmowa","MKOWAL1","2)[ZAKUPY]","KOWALZAKUPY","3)Powrot","MIASTO11");
    nazwa M_KOWAL_A("[...] Kraza pogloski ze w pobliskich gorach znajduje sie zawalona krasnoludzka kopalnia. HAHAHA uwierzlbys w takie brednie ? ","MKOWAL1","1)Powrot","MIASTO11");
    nazwa Miasto3("Wchodzac do sklepu  widzisz na koncu pomieszczenia wysoka chuda elfke w bialej masce ktora przykrywa gorna polowe twarzy , ukladajaca mikstury na polkach.\nPo chwili podchodzi do ciebie i pyta sie:\n*W czym moge pomoc ?*","MIASTO3","1) Rozmowa","M_ALCHEMIK_A","2)[ZAKUPY]","ALCHEMICZKAZAKUPY","3)Powrot","MIASTO11");
    nazwa M_ALCHEMIK_A("[...] Jesli bedzie pan przechodzil przez pobliski LAS prosze uwazac na klusownikow.Poluja na wrozki by miec z nich magiczny pylek.Traktuja go jak narkotyk.","M_ALCHEMIK_A","1) Bede uwazac","MIASTO11");
    nazwa Miasto4("Wchodzac do warsztatu platnerza widzisz Poteznie zbudowanego mezczyzne operujacego miechem.\nPo chwili podchodzi do ciebie i pyta sie : *W czym moge pomoc *\n","MIASTO4","1)Rozmowa","M_PLATNERZ_A","2)[ZAKUPY]","PLATNERZZAKUPY","3)Powrot","MIASTO11");
    nazwa M_PLATNERZ_A("[...] Zauwazyl pan  ? Ostatnimi czasy nikt nie zapuszcza sie na bagna. W gospodzie mowili ze Tam zamieszkala wiedzma. Porywa i zjada wszystkich ktorch zlapie.Ja osobiescie w to nie wierze ale lepiej dmuchac na zimne.","M_PLATNERZ_A","1)Powrot","MIASTO11");
    nazwa Miasto5("Jasne mozesz sie tam udac.Ale nie uda ci sie wejsc.Aby sie dostac do ruin potrzebny jest ametystowy kamien z wyrytymi runami. A ow kamien posiadam tylko ja.\nJesli juz rozwialem twoje watpliwosci to mozemy przejsc dalej ? ","MIASTO5","1).OK","MIASTO11");
    nazwa Miasto6("W ruinach powinny byc notatki elfiego uczonego Yesanith'a.\nJesli juz rozwialem twoje watpliwosci to mozemy przejsc dalej ? ","MIASTO6","1).OK","MIASTO7");
    nazwa Miasto7("Porozmawiajmy o twoim wynagrodzeniu. Czy odpowiada ci ilosc monet jaka dostaniesz za przyniesienie mi tych notatek? Oczywiscie wszystko co znajdziesz w ruinach procz notatek rzecz jasne tez bedzie nalezec do ciebie.","MIASTO7","1) Taka suma mi odpowiada.","MIASTO9","2) Jest stanowczo za niska","MIASTO8");
    nazwa Miasto8("Hmm... nie moge ponad to za duzo dolozyc, ale mozemy umowic sie tak ze jesli sprawnie uwiniesz sie z zadaniem to dorzuce spora premie.","MIASTO8","1).OK","MIASTO9");
    nazwa Miasto9("Dobrze. Skoro kwestie finansowe mamy dogadane. Nie pozostaje mi nic innego jak zyczyc ci powodzenia. I czekac na twoj mam nadzieje rychly powrot.","MIASTO9","1).Bywaj","MIASTO10");
    nazwa Miasto10("POWINIENEM SIE PRZYGOTOWAC DO WYPRAWY","MIASTO10","1)Udaj sie do kowala ","MIASTO2","2)Udaj sie do alchemiczki ","MIASTO3","3)Udaj sie do platnerza ","MIASTO4");
    nazwa Miasto11("MOGE RUSZAC","MIASTO11","1)Udaj sie do kowala ","MIASTO2","2)Udaj sie do alchemiczki ","MIASTO3","3)Udaj sie do platnerza ","MIASTO4","4)Wyruszam","ROZDROZA1");

    nazwa Rozdroza1("Docierasz na rozdroza.Mozesz wybrac droge przez Las lub droge przez Bagna","ROZDROZA1","1)Ide przez las","LAS1","2)Ide przez bagno","BAGNO1");

    nazwa Bagno1("Wchodzisz na teren bagna.","BAGNO1","1)Idz dalej","BAGNO2");
    nazwa Bagno2("Podroz jest trudna.\nPo kolejnej godzinie marszu zauwazasz w oddali mala chatke.","BAGNO2","1)Idz w strone domku","BAGNO3","2)Zignoruj dom i kieruj sie na polnoc","BAGNO10");
    nazwa Bagno3("Podchodzisz do drzwi","BAGNO3","1)Zapukaj","BAGNO4","2)Nie pukaj i odejdz","BAGNO10");
    nazwa Bagno4("Pukasz do drzwi i otwiera ci staruszka.Po krotkiej rozmowie prosi cie o pomoc.\n{Zbierz kilka sztuk pobliskich roslin i przynies woreczek jadowy weza","BAGNO4","1)Pomoge","BAGNO5","2)Nie pomoge","BAGNO10");
    nazwa Bagno5("Zebranie ziol z okolicy nie bylo problemem.Podchodzisz pod miejsce o ktorym mowila staruszka i dostrzegasz gigantycznego weza","BAGNO5","1)Zaatakuj","BAGNO5_WALKA","2)Uciekaj","BAGNO10");
    nazwa Bagno6("Po pokonaniu weza,wydobywasz z niego woreczek jadowy","BAGNO6","1)Wroc do staruszki","BAGNO7","2)Nie wracaj do staruszki","BAGNO10");
    nazwa Bagno7("Wracasz do staruszki.Wpuszcza cie do srodka.Oddajesz jej woreczek.Widzisz jak rozcina woreczek a zawartosc wpada do wielkiego kotla wiszacego nad ogniem.Mikstura w srodku nie wyglada za dobrze.Staruszka pyta sie czy chcesz sprobowac?\nMasz co do tego zle przeczucia","BAGNO7","1)Sproboj","BAGNO8","2)Nie proboj","BAGNO9");
    nazwa Bagno8("Po odmowieniu skosztowania napoju.Staruszka by nie zostawic cie z pustymi rekami.Mowi ci jak bezpiecznie opuscic bagno","BAGNO9","1)Podziekuj","POLANA1");
    nazwa Bagno10("Idac dalej grunt staje sie coraz bardziej grzaski.Po chwili brodzisz juz po kolana w wodzie.Po chwili takiego marszu atakuje cie krokodyl","BAGNO10","1)Walcz","BAGNO10_WALKA");
    nazwa Bagno11("Po walce idziesz jeszcze chwile po czym czujesz ze grunt staje sie coraz bardziej solidny.Kolejna godzina marszu skutkuje opuszczeniem bagien","BAGNO11","1)Idz dalej","POLANA1");

    nazwa Las1("Po krotkim spacerze na scieszcze zauwazasz swierze ludzkie slady ktore prowadza w glab lasu.\nKtoredy idziesz?","LAS1","1)Ide dalej sciezka","LAS2","2)Zbaczam z sciezki","LAS3");
    nazwa Las2("Idac sciezka podziwiasz piekno przyrody.\nGdy w oddali dostrzegasz dzika.\nCo robisz?","LAS2","1)Proboje ukryc sie w krzakach","LAS4","2)Atakuje","LAS5_WALKA");
    nazwa Las3("Idac po sladach po chwili slyszysz w oddali dzwieki dzwoneczkow","LAS3","1)Ide w strone dzwiekow","LAS8","2)Ignoruje dzwieki","LAS7");
    nazwa Las4("Chowasz sie w krzakach.\nMasz szczescie dzik cie nie zobaczyl.","LAS4","1)Podazaj dalej sciezka","LAS7");
    nazwa Las6("Dzik juz nie bedzie problemem a ty wedrujesz dalej sciezka","LAS6","1)Dalej podziwiaj piekno przyrody","LAS7","2)Uczic minuta ciszy poleglych","LAS7");
    nazwa Las7("Po kolejnej chwili spaceru docierasz do wyjscia z lasu","LAS7","1)Wyjdz z lasu","POLANA1");
    nazwa Las8("Gdy idziesz za dzwiekiem dzwoneczkow,w oddali dostrzegasz czlowieka ktory biegnie za wrozka","LAS8","1)Zignoruj","LAS7","2)Podbiegnij","LAS9");
    nazwa Las9("Podbiegasz do mezczyzny.Gdy cie zauwaza krzyczy do ciebie bys sie wynosil","LAS9","1)Ucieknij","LAS10","2)Zaatakuj","LAS10_WALKA");
    nazwa Las10("Uciekles przed mezczyzna.","LAS10","1)Wroc na sciezke","LAS7");
    nazwa Las11("Pokonales klusownika i uwolniles wrozke ktora w ramach podziekowania oferuje ci uleczenie ran.","LAS11","1)Skorzystaj z pomocy","LAS12","2)Odmow i udaj sie w strone sciezki","LAS7");
    nazwa Las12("Wrozka prowadzi ci do driady.Podlatuje do niej i szepcze jej cos do ucha.\nPo chwili widzisz jak wokol ciebie tworzy sie wir z lisci, a ty czujesz jak twoje rany sie zablizniaja.\nWrozka podlatuje do ciebie z mala fiolka i daje ci ja","LAS12","1)Podziekuj i odejdz w strone sciezki","LAS7");

    nazwa Polana1("Wkraczasz na rowniny.Powoli robi sie ciemno","POLANA1","1)Idz dalej","POLANA2","2)Rozbij obuz","POLANA3");
    nazwa Polana2("Czujesz sie zmeczony","POLANA2","1)Rozbij oboz","POLANA3");
    nazwa Polana3("Rozbijasz oboz i spisz do wschodu slonca","POLANA3","1)Pospij jeszcze chwile","POLANA5","2)Wstan i rusz w dalsza podroz","POLANA5");
    nazwa Polana5("Okolo poludnia dostrzegasz w oddali wedrownego kupca","POLANA5","1)Zignoruj","POLANA4","2)[ZAKUPY]","KUPIECZAKUPY");
    nazwa Polana4("Twoja podroz zajmuje kilka kolejnych dni w ciagu ktorych albo podrozojesz albo polujesz na zwierzeta by miec jedzenie.\nW oddali majacza ci juz gorskie szczyty","POLANA4","1)Idz","GORY1");

    nazwa Gory1("Zblizasz sie do gor.By przedostac sie na druga strone","GORY1","1)Przejde przez jaskinie","JASKINIA1","2)Przejde szczytami","GORA2");
    nazwa Gory2("Idac w gore czujesz jak obniza sie temperatura.Twoje ciuchy sa nieodpowiednie do pogody","GORA2","1)Idz dalej","GORA3","2)Zawroc","GORY1");
    nazwa Gory3("Idac w gore czujesz jak wzmaga sie wiatra.Robi sie niebezpiecznie","GORA3","1)Idz dalej","GORA4","2)Zawroc","GORY1");
    nazwa Gory4("Temperatura jest juz na tyle niska ze czujesz sie tak jakby kazdy kolejny krok mial byc tym ostatnim","GORA4","1)Idz dalej","GORA5","2)Zawroc","GORY1");

    nazwa Jaskinia1("Wchodzisz w glab jaskini.Jej wnetrze przypomina labirynt","JASKINIA1","1)Idz dalej","LAB1");
    nazwa Jaskinia2("Dochodzisz do kolejnego rozwidlenia","LAB1","1)Idz w lewo","ZAULEK","2)Idz w prawo","LAB2");
    nazwa Jaskinia3("Dotarles do slepego zaulka","ZAULEK","1)Wroc sie na poczatek","LAB1");
    nazwa Jaskinia4("Dochodzisz do kolejnego rozwidlenia","LAB2","1)Idz w lewo","LAB3","2)Idz w prawo","LAB4");
    nazwa Jaskinia5("Dochodzisz do kolejnego rozwidlenia","LAB3","1)Idz w lewo","ZAULEK","2)Idz w prawo","LAB5");
    nazwa Jaskinia6("Dochodzisz do kolejnego rozwidlenia","LAB4","1)Idz w lewo","LAB5","2)Idz w prawo","ZAULEK");
    nazwa Jaskinia7("Dochodzisz do kolejnego rozwidlenia","LAB5","1)Idz w lewo","LAB6","2)Idz w prawo","ZAULEK");
    nazwa Jaskinia8("Czujesz powiew swierzego powietrza","LAB6","1)Idz dalej","JASKINIA2");
    nazwa Jaskinia9("Udalo ci sie przejsc przez gore","JASKINIA2","1)Idz dalej","DROGA1");

    nazwa Droga1("Podrozuj przez kolejny dzien.Po czym dochodzisz do ogromnego jeziora","DROGA1","1)Nurkuj","JEZIORO1","2)Obejrzyj jezioro","DROGA2");
    nazwa Droga2("Podziwiasz jezioro w ktorym odbija sie swiatlo ksiezyca.Po chwili zadumy przypominasz sobie ze masz tu cos do zrobienia","DROGA2","1)Nurkuj","JEZIORO1");

    nazwa Jezioro1("Bierzesz gleboki oddech i nurkujesz w glebinach.Swiatlo ksiezyca wyglada tak jakby wskazywalo ci droge.","JEZIORO1","1)Plyn do miejsca ktore wskazuje ksiezyc","JEZIORO2","2)Wynurz sie i wez oddech","JEZIORO3");
    nazwa Jezioro2("Doplywasz do czegos co przypomina kamienne wrota z wyrytymi na nich runami","JEZIORO2","1)Otworz sila","JEZIORO4","2)Uzyj krysztalu od starca","JEZIORO5");
    nazwa Jezioro3("Wynurzasz sie","JEZIORO3","1)Zanurkuj","JEZIORO1");
    nazwa Jezioro4("Proba otwarcia drzwi sila zakonczyla sie niepowodzenie.Powoli zaczyna brakowac ci tlenu","JEZIORO4","1)Wynurz sie","JEZIORO3","2)Proboj dalej","JEZIORO_SMIERC");
    nazwa Jezioro5("Gdy przykladasz krysztal do run.Dzwi i krysztal zaczynaja swiecic fioletowym blaskiem.Po chwili blask jest tak mocny ze juz nic nie widzisz.Gdy odzyskujesz wzrok widzisz ze jestes w dlugim korytarzu na ktorego koncu jest dwojka drzwi.A za twoimi plecami stoi kamienna tabliczka z runami.","JEZIORO5","1)Zbadaj pomieszczenie po lewo.","JEZIORO6","2)Zbadaj pomieszczenie po prawo","JEZIORO7");
    nazwa Jezioro7("Otwierasz stare spruchniale drzwi, i twoim oczom ukazuje sie pomieszczenie w ktorym procz lozka i wiadra nie ma nic.Gdy tak o tym myslisz to to pomieszczenie przypomina cele.","JEZIORO7","1)Sprawdz drugie dzrzwi","JEZIORO12");
    nazwa Jezioro6("Gdy wchodzisz do pomiesczenia widzisz ze pomieszczenie wypelnione jest roznej masci przyrzadami alchemicznymi.Gdy rozgladasz sie po pomieszczeniu zauwazasz na drugim koncu pomieszczenia zmasakrowane zwloki, przypominajace elfie.A niedaleko nich stoich ponad dwu-metrowe monstrum przypominajace polaczenie czlowieka,wilka i niedzwiedzia.Ponad to zauwazasz polke z zwojami.Na twoje nieszczescie stoi ona niedaleko potwora.","JEZIORO6","1)Atakuj","JEZIORO8","2)Uciekaj [PORZUC MISJE]","JEZIORO9");
    //JEZIORO 8 to walka
    nazwa Jezioro9("Stwierdziles ze twoje zycie jest warte wiecej niz 10 000 monet.I postanowiles uciec.Nigdy wiecej nie pokazales sie miescie.","JEZIORO9");
    nazwa Jezioro10("Po pokonaniu tej potwornosci.Podchodzisz do szfki z notatkami,gdy czytasz zaczynaja trzasc ci sie rece.Z tresci notatek mozna dowiedziec sie jak polaczyl humanoida i zwierze w jeden organizm.Zabierasz notatki.Pochodzisz do kamiennej tabliczki i przykladasz do niej krysztal.Doplywasz do brzegu.","JEZIORO10","1)Oddam notatki","KONIEC1","2)Nikt nie powinien nigdy zobaczyc tych notatek.Zniszcze je!","KONIEC2");
    nazwa Koniec1("Po paru dniach podrozy w koncu docierasz do kresu swojej przygody.Oddajesz notaki starcowi.Gdy je przeglda az blyszcza mu sie oczy.Dostajesz swoja zaplate.Za taka sume mozesz zyc jak krol przez nastepne pare miesiecy.\n[KONIEC]","KONIEC1");
    nazwa Koniec2("Rozpalasz ogien.Czy napewno chce je zniszczyc?","KONIEC2","1)TAK","KONIEC3","2)NIE","KONIEC1");
    nazwa Koniec3("Wrzucasz notatki do ognia.Po chwili nie ma juz po nich nawet sladu.Nie udalo ci sie wykonac misji ale przynajmniej masz czyste sumienie.A to jest bezcenne.Prawda?\n[KONIEC]","KONIEC3");
    nazwa Jezioro12("Podchodzisz do drzwi i slyszysz z za nich nieludzkie odglosy.","JEZIORO12","1)Wchodze","JEZIORO6","2)Najpierw sprawdzam drugie drzwi","JEZIORO7");


    std::vector<nazwa> zbior;


        zbior.push_back(IndexStart);
        zbior.push_back(Miasto0);
        zbior.push_back(Miasto1);
        zbior.push_back(Miasto2);
        zbior.push_back(Miasto3);
        zbior.push_back(Miasto4);
        zbior.push_back(Miasto5);
        zbior.push_back(Miasto6);
        zbior.push_back(Miasto7);
        zbior.push_back(Miasto8);
        zbior.push_back(Miasto10);
        zbior.push_back(Miasto9);
        zbior.push_back(M_KOWAL_A);
        zbior.push_back(M_ALCHEMIK_A);
        zbior.push_back(M_PLATNERZ_A);
        zbior.push_back(Miasto11);
        zbior.push_back(Rozdroza1);
        zbior.push_back(Las1);
        zbior.push_back(Las2);
        zbior.push_back(Las3);
        zbior.push_back(Las4);
        zbior.push_back(Las6);
        zbior.push_back(Las7);
        zbior.push_back(Las8);
        zbior.push_back(Las9);
        zbior.push_back(Las10);
        zbior.push_back(Las11);
        zbior.push_back(Las12);
        zbior.push_back(Bagno1);
        zbior.push_back(Bagno2);
        zbior.push_back(Bagno3);
        zbior.push_back(Bagno4);
        zbior.push_back(Bagno5);
        zbior.push_back(Bagno6);
        zbior.push_back(Bagno7);
        zbior.push_back(Bagno8);
        zbior.push_back(Bagno10);
        zbior.push_back(Bagno11);
        zbior.push_back(Polana1);
        zbior.push_back(Polana2);
        zbior.push_back(Polana3);
        zbior.push_back(Polana4);
        zbior.push_back(Polana5);
        zbior.push_back(Gory1);
        zbior.push_back(Gory2);
        zbior.push_back(Gory3);
        zbior.push_back(Gory4);
        zbior.push_back(Jaskinia1);
        zbior.push_back(Jaskinia2);
        zbior.push_back(Jaskinia3);
        zbior.push_back(Jaskinia4);
        zbior.push_back(Jaskinia5);
        zbior.push_back(Jaskinia6);
        zbior.push_back(Jaskinia7);
        zbior.push_back(Jaskinia8);
        zbior.push_back(Jaskinia9);
        zbior.push_back(Droga1);
        zbior.push_back(Droga2);
        zbior.push_back(Jezioro1);
        zbior.push_back(Jezioro2);
        zbior.push_back(Jezioro3);
        zbior.push_back(Jezioro4);
        zbior.push_back(Jezioro5);
        zbior.push_back(Jezioro6);
        zbior.push_back(Jezioro7);
        zbior.push_back(Jezioro9);
        zbior.push_back(Jezioro10);
        zbior.push_back(Jezioro12);
        zbior.push_back(Koniec1);
        zbior.push_back(Koniec2);
        zbior.push_back(Koniec3);


        //zbior.push_back(Miasto);

    // OSOBNY  PLIK - koniec


   // walka(ja,zombie,"LAS3");
    Rozgrywka(zbior,ja,przeciwnicy);



    return 0;
}
