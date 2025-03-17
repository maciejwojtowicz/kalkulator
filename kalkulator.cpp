#include <iostream>

void start(int& n) {
    std::cout << "podaj numer operacji:\n0. stop\n1. dodawanie\n2. odejmowanie\n3. mnozenie\n4. dzielenie\n5. modulo\n6. dodaj do pamieci\n7. odejmij od pamieci\n8. wyczysc pamiec" << std::endl;
    std::cin >> n;
}

void podaj_liczby(double& a, double& b) {
    std::cout << "podaj dwie liczby";
    std::cin >> a >> b;
}

void dodawanie(double& a, double& b,double& wynik) {
    podaj_liczby(a,b);
    wynik = a + b;
    std::cout << wynik;
}

void odejmowanie(double& a, double& b, double& wynik) {
    podaj_liczby(a,b);
    wynik = a - b;
    std::cout << wynik;

}

void mnozenie(double& a, double& b, double& wynik) {
    podaj_liczby(a,b);
    wynik = a * b;
    std::cout << wynik;

}

void dzielenie(double& a, double& b, double& wynik) {
    podaj_liczby(a,b);
    if (b == 0) std::cout << "BŁĄD!";
    wynik = a / b;
    std::cout << wynik;

}

void modulo(double& a, double& b, double& wynik) {
    podaj_liczby(a,b);
    if (static_cast<int>(b) == 0) std::cout << "BŁĄD!";
    wynik = static_cast<int>(a) % static_cast<int>(b);
    std::cout << wynik;

}

void mem_add(double& wynik, double& mem) {
    mem += wynik;
}

void mem_sub(double& wynik, double& mem) {
    mem -= wynik;
}

void mem_clr(double& wynik, double& mem) {
    mem = 0;
}

void dzialanie(double& a, double& b, int& n, double& wynik, double& mem,int& x) {
    switch (n) {
        case 0:
            x = 0;

        case 1:
            dodawanie(a, b, wynik);

        case 2:
            odejmowanie(a, b, wynik);
        
        case 3:
            mnozenie(a, b, wynik);
      
        case 4:
            dzielenie(a, b, wynik);

        case 5:
            modulo(a, b, wynik);

        case 6:
            mem_add(wynik, mem);

        case 7:
            mem_sub(wynik, mem);

        case 8:
            mem_clr(wynik, mem);
    }
}

int main()
{   
    double mem = 0;
    double a;
    double b;
    int n;
    int x = 1;
    double wynik = 0;
    while (x != 0) {
        start(n);
        podaj_liczby(a, b);
        dzialanie(a, b, n, wynik, mem, x);
        std::cout << "wynik: " << wynik;
    }
    return wynik;
}
