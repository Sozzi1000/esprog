#include <ctime>
#include <vector>

time_t now;
int d = 0;

int ConvertToSeconds(int days) {
    int seconds;
    seconds = days * 86400;
    return seconds;
}

auto FinalDate(int days) {
    time(&now);
    now += ConvertToSeconds(days);
    return &now;
}

std::string ConvertToString(int month) {
    std::vector<std::string> Mesi{"Gennaio",   "Febbraio", "Marzo",    "Aprile",
                                  "Maggio",    "Giugno",   "Luglio",   "Agosto",
                                  "Settembre", "Ottobre",  "Novembre", "Dicembre"};
    return Mesi[month];
}