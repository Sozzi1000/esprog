#include <iomanip>
#include <iostream>

#include "Calcoli.hpp"
#include "Date.hpp"

int main() {
  int Pop;
  int Inf;
  int Dead;
  int Heal;
  int Duration;
  int Immunity;
  int VStart;
  int VMax;
  int NewSusc;
  double Beta;
  double Gamma;
  double HIndex;
  double VIndex;
  char Already;

  /*
      std::cout << "Inserire \n";
      int Pop;
      std::cout << "Popolazione totale:\t";
      std::cin >> Pop;
      while ( Pop <= 0 ) {
          std::cout << " Population has to be > than 0.\n ";
          std::cin >> Pop;
      }

      int Inf;
      std::cout << "Popolazione infetta:\t";
      std::cin >> Inf;
      while ( Inf < 0 || Inf > Pop ) {
          std::cout << " Inf's value has to be between 0 and Pop's value.\n ";
          std::cin >> Inf;
      }

      double Beta;
      std::cout << "Indice di contagiosità:\t";
      std::cin >> Beta;
      while ( Beta < 0 || Beta > 1 ) {
          std::cout << " Beta's value has to be between 0 and 1.\n ";
          std::cin >> Beta;
      }

      double Gamma;
      std::cout << "Indice di rimozione:\t";
      std::cin >> Gamma;
      while ( Gamma < 0 || Gamma > 1 ) {
          std::cout << " Gamma's value has to be between 0 and 1.\n ";
          std::cin >> Gamma;
      }

      double HIndex;
      std::cout << "Indice di guarigiosità:\t";
      std::cin >> HIndex;
      while ( HIndex < 0 || HIndex > 1 ) {
          std::cout << " HIndex's value has to be between 0 and 1.\n ";
          std::cin >> HIndex;
      }

      double VIndex;
      std::cout << "Indice di vaccinazione:\t";
      std::cin >> VIndex;
      while ( VIndex < 0 || VIndex > 1 ) {
          std::cout << " VIndex's value has to be between 0 and 1.\n ";
          std::cin >> VIndex;
      }

      int Duration;
      std::cout << "Durata simulazione:\t";
      std::cin >> Duration;
      while ( Duration <= 0 ) {
          std::cout << " Duration has to be > than 0.\n ";
          std::cin >> Duration;
      }

      int Immunity;
      std::cout << "Durata immunità:\t";
      std::cin >> Immunity;
      while ( Immunity <= 0 ) {
          std::cout << " Immunity has to be > than 0.\n ";
          std::cin >> Immunity;
      }

      int VStart;
      std::cout << "Giorno di inizio dei vaccini:\t";
      std::cin >> VStart;
      while ( VStart <= 0 ) {
          std::cout << " VStart has to be > than 0.\n ";
          std::cin >> VStart;
      }

      int VMax;
      std::cout << "Giorni per raggiungere la massima velocità percentuale di
     vaccinazione:\t"; std::cin >> VMax; while ( VMax <= 0 ) { std::cout << "
     VMax has to be > than 0.\n "; std::cin >> VMax;
      }

      char Already;
      std::cout << "La pandemia è già in corso?\t";
      std::cin >> Already;
      while ( Already != 'N' && Already != 'Y' && Already  != 'n' && Already !=
     'y' ) { std::cout << " Already has to be Y/n.\n "; std::cin >> Already;
      }

      int Dead;
      int Heal;
      if ( Already == 'Y' || Already == 'y') {
          std::cout << " Dead = ";
          std::cin >> Dead;
          while ( Dead < 0 || Dead > Pop - Inf) {
              std::cout << " Dead has to be between 0 and Pop - Inf.\n ";
              std::cin >> Dead;
          }
          std::cout << " Heal = ";
          std::cin >> Heal;
          while ( Heal < 0 || Heal > Pop - Inf - Dead) {
              std::cout << " Heal has to be between 0 and Pop - Inf - Dead.\n ";
              std::cin >> Heal;
          }
      } else {
          Dead = 0;
          Heal = 0;
      }

      int NewSusc = 0;
  */
  Pop = 1000000;
  Inf = 100;
  Dead = 0;
  Heal = 0;
  Beta = 0.2;
  Gamma = 0.05;
  HIndex = 0.94;
  Duration = 100;
  Immunity = 250;
  // tempo di guarigione
  VStart = 350;
  // quando iniziano i vaccini
  Already = 'n';
  // pandemia già in corso?
  VIndex = 0.01;
  VMax = 200;
  NewSusc = 0;

  Data initial_state{Pop - Inf - Dead - Heal,
                     Inf,
                     Dead,
                     Heal,
                     Dead + Heal,
                     Immunity,
                     VStart,
                     VMax,
                     NewSusc,
                     Beta,
                     Gamma,
                     HIndex,
                     VIndex,
                     Already};  // aggiungere c
  Contagi covid{initial_state};
  std::vector<Data> data = covid.generate_data(Duration - 1);
  int d = 0;
  std::cout << "---------------------------------------------------------------"
               "-------------------------------------------------------"
               "\n|"
            << std::setw(12) << "Giorno   "
            << "|" << std::setw(12) << "Suscettibili"
            << "|" << std::setw(12) << " Infetti  "
            << "|" << std::setw(12) << "Rimossi   "
            << "|" << std::setw(12) << "Guariti   "
            << "|" << std::setw(12) << "  Morti   "
            << "|" << std::setw(12) << "Guarigios."
            << "|" << std::setw(12) << "Population"
            << "|" << std::setw(12) << "     Rt     "
            << "|\n"
            << "---------------------------------------------------------------"
               "-------------------------------------------------------"
            << '\n';

  char a = ' ';
  if (Duration <= 150) {
    a = 'x';
  } else if (Duration <= 500) {
    a = 'y';
  } else {
    a = 'z';
  }

  std::cout.precision(3);

  double Giuseppe = Beta / Gamma;

  switch (a) {
    case 'x':
      while (d < Duration + 1) {
        control_print(d, data[d].Susc_, data[d].Inf_, data[d].Recov_,
                      data[d].Heal_, data[d].Dead_, data[d].HIndex_, Pop,
                      Giuseppe);
        ++d;
      }
      break;

    case 'y':
      while (d < Duration + 1) {
        control_print(d, data[d].Susc_, data[d].Inf_, data[d].Recov_,
                      data[d].Heal_, data[d].Dead_, data[d].HIndex_, Pop,
                      Giuseppe);
        d += 10;
        if (d > Duration && d != Duration + 10) {
          control_print(Duration, data[Duration].Susc_, data[Duration].Inf_,
                        data[Duration].Recov_, data[Duration].Heal_,
                        data[Duration].Dead_, data[Duration].HIndex_, Pop,
                        Giuseppe);
        }
      }
      break;

    case 'z':
      while (d < Duration + 1) {
        control_print(d, data[d].Susc_, data[d].Inf_, data[d].Recov_,
                      data[d].Heal_, data[d].Dead_, data[d].HIndex_, Pop,
                      Giuseppe);
        d += 20;
        if (d > Duration && d != Duration + 20) {
          control_print(Duration, data[Duration].Susc_, data[Duration].Inf_,
                        data[Duration].Recov_, data[Duration].Heal_,
                        data[Duration].Dead_, data[Duration].HIndex_, Pop,
                        Giuseppe);
        }
      }
      break;
  }

  std::cout << "---------------------------------------------------------------"
               "-------------------------------------------------------\n";

  now = time(0) + ConvertToSeconds(Duration);
  tm *ldt = localtime(&now);
  std::cout << "La simulazione termina il " << ldt->tm_mday << ' '
            << ConvertToString(ldt->tm_mon) << ' ' << 1900 + ldt->tm_year
            << std::endl;
}
