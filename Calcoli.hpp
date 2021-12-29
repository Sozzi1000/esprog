#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <iomanip>

struct Data {                      
    int Susc_;
    int Inf_;
    int Dead_;
    int Heal_;
    int Recov_;
    int Immunity_;
    int VStart_;
    int VMax_;
    int NewSusc_;  
    double Beta_
    double Gamma_;
    double HIndex_;
    double VIndex_;          
    char Already_;                         // è se la pandemia è già in corso o se è all'inizio.
};

void control_print ( int day, int susc, int inf, int recov, int heal, int dead, double hindex, int pop ) {
    assert ( susc >= 0 && susc <= pop );
    assert ( inf >= 0 && inf <= pop );
    assert ( recov >= 0 && recov <= pop );
    assert ( heal >= 0 && heal <= recov );
    assert ( dead >= 0 && dead <= recov );
    assert ( hindex >= 0 && hindex <= 1 );
    assert ( pop == susc + inf + recov );
    assert ( recov == heal + dead);  
    assert ( day >= 0 );

    std::cout << std::setw(12) << day << "|" << std::setw(12) << susc << "|" << std::setw(12) << inf << "|" 
              << std::setw(12) << recov << "|" << std::setw(12) << heal << "|" << std::setw(12) << dead << "|"
              << std::setw(12) << hindex << "|" << std::setw(12) << pop <<"|\n";
}

class Contagi {
   private:
    Data states;

   public:
    Contagi(Data& initial_state) : states{initial_state} {}

    std::vector<Data> generate_data(int Duration_) {
        int Const = std::round(25 * tan(M_PI * (states.HIndex_ - 0.5)));
        std::vector<Data> result{states};
        Data state = result.back();

        for (int i = 0; i <= Duration_; ++i) {
            int Pop_ = states.Susc_ + states.Inf_ + states.Dead_ + states.Heal_;
            int NoInf_ = std::round(states.Gamma_ * state.Inf_);
            int NewInf_ = std::round(states.Beta_ / Pop_ * state.Susc_ * state.Inf_);
            int NewHeal_ = std::round(NoInf_ * states.HIndex_);  // l è la gente che guarisce.

            if ( states.Already_ == 's' ) {           // se la pandemia è già in corso
                if (i > (50 * pow(M_E, -2 * states.Beta_) + 30)) {  // si può modificare. Forse mettere fuori come int
                    // deve essere inv prop a beta
                    state.HIndex_ = ((atan((i + Const) / 50)) / M_PI) + 0.5;
                } else {
                    state.HIndex_ = states.HIndex_;
                }
            } else {
                state.HIndex_ = ((atan((i + Const) / 50)) / M_PI) + 0.5;
            };

            // da inizializzare fuori per farlo inserire all'utente
            if (i > states.Immunity_) {  
                int j = i - states.Immunity_;
                states.NewSusc_ = result[j].Heal_ - result[j - 1].Heal_ + result[j].NewSusc_;  
            }

            int NewVac_ = 0;
            if (state.Inf_ > Pop_ * 0.001) {
                if (states.VStart_ <= i && states.VStart_ + states.VMax_ > i) {
                    NewVac_ = (state.Susc_ + states.NewSusc_ - NewInf_) * states.VIndex_ * ((i - states.VStart_ + 1) / states.VMax_);
                } else if (states.VStart_ + states.VMax_ <= i) {
                    NewVac_ = (state.Susc_ + states.NewSusc_ - NewVac_) * states.VIndex_;
                }
            } else {
                NewVac_ = 0;
            }

            state.Susc_ += states.NewSusc_ - NewInf_ - NewVac_;
            state.Inf_ += NewInf_ - NoInf_;
            state.Recov_ += NoInf_ - states.NewSusc_ + NewVac_; 
            state.Dead_ += NoInf_ - NewHeal_;         // l è una frazione di k, quindi sempre minore. Io (Stefanoo) so cosa intendo.
            state.Heal_ += NewHeal_ - states.NewSusc_ + NewVac_;
            state.NewSusc_ = states.NewSusc_;

            result.push_back(state);
        }
        return result;
    }
};