#include <iostream>

#define print(X,Y)    std::cout << "wynik: " << wynik <<std::endl<< "pamiec: " << mem << std::endl;
#define abwm() double& a, double& b,double& wynik,double& mem
#define memref() double& wynik, double& mem
#define inp_numbers() double& a, double& b, int& n, int& n_old, double& wynik
#define switch_nums() double& a,double&b, int& n, int& n_old, double& wynik, double& mem

void start(int& n) {
    std::cout << "\npodaj numer operacji:\n0. stop\n1. dodawanie\n2. odejmowanie\n3. mnozenie\n4. dzielenie\n5. modulo\n6. dodaj do pamieci\n7. odejmij od pamieci\n8. wyczysc pamiec\njezeli wybierzesz dwa razy z rzedu ta sama opcje - za drugim razem a bedzie rowne wynikowi poprzedniej operacji" << std::endl;
    std::cin >> n;
}

void podaj_liczby(inp_numbers()) {
    std::cout << "podaj dwie liczby";
    if (n_old == n) {
        a = wynik;
        std::cout<<"\na: " << wynik << "\npodaj b: ";
        std::cin>>b;
    }
    else {
        std::cout<<"\npodaj a: ";
        std::cin>>a;
        std::cout<<"\npodaj b: ";
        std::cin>>b;
    }
}

void dodawanie(abwm()) {
    wynik = a + b;
    print(wynik,pamiec)
}

void odejmowanie(abwm()) {
    wynik = a - b;
    print(wynik,pamiec)
}

void mnozenie(abwm()) {
    wynik = a * b;
    print(wynik,pamiec)
}

void dzielenie(abwm()) {
    if (b == 0) std::cout << "BŁĄD!";
    wynik = a / b;
    if (b != 0) print(wynik,pamiec)
}

void modulo(abwm()) {
    if (static_cast<int>(b) == 0) std::cout << "BLAD!";
    wynik = static_cast<int>(a) % static_cast<int>(b);
    if (b != 0) print(wynik,pamiec)
}

void mem_add(memref()) {
    mem += wynik;
    print(wynik,pamiec)
}

void mem_sub(memref()) {
    mem -= wynik;
    print(wynik,pamiec)
}

void mem_clr(memref()) {
    mem = 0;
    print(wynik,pamiec)
}

void dzialanie(switch_nums()) {
    switch (n) {
        case 0:
            break;

        case 1:
            podaj_liczby(a,b,n,n_old,wynik);
            dodawanie(a, b, wynik,mem);
            break;

        case 2:
            podaj_liczby(a,b,n,n_old,wynik);
            odejmowanie(a, b, wynik,mem);
            break;
        
        case 3:
            podaj_liczby(a,b,n,n_old,wynik);
            mnozenie(a, b, wynik,mem);
            break;
      
        case 4:
            podaj_liczby(a,b,n,n_old,wynik);
            dzielenie(a, b, wynik,mem);
            break;

        case 5:
            podaj_liczby(a,b,n,n_old,wynik);
            modulo(a, b, wynik,mem);
            break;

        case 6:
            mem_add(wynik, mem);
            break;

        case 7:
            mem_sub(wynik, mem);
            break;

        case 8:
            mem_clr(wynik, mem);
            break;

        default:
            break;
    }
    n_old = n;
}

int main() {
    double mem = 0;
    double a;
    double b;
    int n = 1;
    int n_old;
    double wynik = 0;
    while (n) {
        start(n);
        dzialanie(a, b, n, n_old, wynik, mem);
    }
    print(wynik,pamiec)
}