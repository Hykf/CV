
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


};

struct Hero{

  vector<Potki> pots;
  vector<Item> items;
  int pieniadze;
  float attackBonus;
  float defBonus;

  float hp;
  int speed;
  float damage;
  int mana;
  int szansaNaUnik;

  int sila; //damage
  int zwinnosc; //speed
  int inteligencja; //magia
  int kondycja; //hp

  Hero(int a,int b, int c, int d,vector<Potki> p,vector<Item> i){

      attackBonus = 0.9;
      defBonus = 0.9;
      pieniadze = 100;

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



};


//METODY POMOCNICZE::
void Klimat(std::string s){

string tekst = s;
int x=0;
while ( tekst[x] != '\0')
{
	cout << tekst[x];
	Sleep(50);
	x++;
};

cout<<"\n";

}

std::string wydarzenieWalka(std::string wrog,std::string nas){
        cout<<"zaczynasz walke z: "<<wrog<<endl;
        return nas;
    }

void GameOver(){
    cout<<"KONIEC";
    system("pause");
}

void drop(Hero gracz){


    srand (time(NULL));
  int iSecret = rand() % 10 + 1;
  int randKasa = rand() % 150+ 1;
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

           Klimat("ile Punktow chcesz dac w Kondycje?");
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

            Klimat("Ile Punktow chcesz dac w SILE?");
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

            Klimat("Ile Punktow chcesz dac w Zwinnosc?");
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

            Klimat("Ile Punktow chcesz dac w Inteligencje?");
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
            cout<<"Zakonczono robienie Postaci\n\n";
            ok = true;
            break;
        }



    }


     return Hero(silaTemp,zwinnoscTemp,inteligencjaTemp,kondycjaTemp);

}

string zakupyUKowala(Hero gracz,std::string s){
    Klimat("Pieniadze:" + gracz.pieniadze);
    return s;
}

//METODY GLOWNE::

void Rozgrywka(vector<nazwa> karty){
    std::string next = "LOCH1";

    int wybor;
    int karta;

    while(1){

       for( int i = 0; i<karty.size(); i++){
          if(karty[i].ID==next){
              karta = i;
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

std::string walka(Hero gracz,Enemy wrog,std::string tekst){

    HANDLE hc = GetStdHandle(STD_OUTPUT_HANDLE);

     srand (time(NULL));
     cout<<"\n";
     cout<<"########################################"<<endl;
     Klimat("Zaczynasz walke z:");
     SetConsoleTextAttribute(hc,014);
     cout<<wrog.nazwa;
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
                if(szansaNaTrafienie>wrog.dodgeChance+10){
                    wrog.hp-=(gracz.damage*1.2*gracz.attackBonus);
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
                        gracz.hp +=5*gracz.inteligencja;
                        Klimat("Leczenie za:" + to_string(5*gracz.inteligencja));
                        if(gracz.hp>maxHp){
                            gracz.hp = maxHp;
                        }
                        cout<<"HP:"<<gracz.hp<<endl;
                        gracz.mana-=20;
                        mojaTura = false;
                        break;
                    }
                }else if(wyborZaklecia==2){

                    if(gracz.mana<25){
                        Klimat("Nie masz wystarczajacej ilosci many na zadne zaklecie");
                        continue;
                    }else{
                        wrog.hp -=5*gracz.inteligencja;
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
                        wrog.hp -=8*gracz.inteligencja;
                            if(wrog.hp<=0){
                            Klimat(wrog.nazwa+" pokonany!");
                            //drop(gracz);
                            mojaTura = false;
                            break;
                          }else{
                             Klimat(wrog.nazwa+" otrzymal: "+ to_string(8*gracz.inteligencja));
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




int main()
{
    // OSOBNY PLIK - poczatek
    nazwa Las1("Wchodzisz do mrocznego lasu","LAS1","LAS4");
    nazwa Las2("Przechodzisz do las2\n","LAS2","LAS3","spadasz w przepasc \n");
    nazwa Las3("Las3-text","LAS3","LAS4");
    nazwa Las4("Las4-text","LAS4","LAS2","dostajesz jablko \n");
    //nazwa nazwaOB(TEXT ID A KonA B KonB C KonC D KonD)
    nazwa Loch1("Jestes w lochu","LOCH1","1.Poloz sie i placz","LOCH1","2.Wal w sciane","LAS1","3.XXXX","LAS2","4.YYYY","LAS3");
    nazwa Loch2("Chcesz uciec","LOCH2","LOCH3");
    nazwa Loch3("Ale nie mozesz uciec","LOCH3","LOCH1");
    nazwa Loch5("Jestes w lochu","LOCH1","1.Poloz sie i placz","LOCH1","2.Wal w sciane","LAS1","3.XXXX","LAS2");

    std::vector<nazwa> zbior;
    zbior.push_back(Las1);
    zbior.push_back(Las2);
    zbior.push_back(Las3);
    zbior.push_back(Las4);
    zbior.push_back(Loch1);
    zbior.push_back(Loch2);
    zbior.push_back(Loch3);
    zbior.push_back(Loch5);
    // OSOBNY  PLIK - koniec

    vector<Potki> flaszki;
    vector<Item> eq;


    Enemy zombie("Zombie",1,111,35,1);

     Potki potek("Hp Potek",20,0);
     Potki manaPotek("Mana Potek",0,20);
     Potki GreaterHpPotek("GreaterHpPotek",50,0);
     Potki LesserHpPotek("LesserHpPotek",10,0);


   // flaszki.push_back(potek);
  //  flaszki.push_back(manaPotek);
    flaszki.push_back(GreaterHpPotek);
  //  flaszki.push_back(LesserHpPotek);

    Hero ja = Character();
    ja.items = eq;
    ja.pots = flaszki;

   // Hero ja(4,2,5,2,flaszki,eq);
    walka(ja,zombie,"LAS3");
   // Rozgrywka(zbior);



    return 0;
}
