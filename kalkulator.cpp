#include <iostream>

void start(int& n) {
    std::cout << "\npodaj numer operacji:\n0. stop\n1. dodawanie\n2. odejmowanie\n3. mnozenie\n4. dzielenie\n5. modulo\n6. dodaj do pamieci\n7. odejmij od pamieci\n8. wyczysc pamiec" << std::endl;
    std::cin >> n;
}

void podaj_liczby(double& a, double& b) {
    std::cout << "podaj dwie liczby";
    std::cin >> a >> b;
}

void dodawanie(double& a, double& b,double& wynik,double& mem) {
    podaj_liczby(a,b);
    wynik = a + b;
    std::cout << "wynik: " << wynik <<std::endl<< "pamiec: " << mem << std::endl;

}

void odejmowanie(double& a, double& b, double& wynik, double& mem) {
    podaj_liczby(a,b);
    wynik = a - b;
    std::cout << "wynik: " << wynik <<std::endl<< "pamiec: " << mem << std::endl;


}

void mnozenie(double& a, double& b, double& wynik, double& mem) {
    podaj_liczby(a,b);
    wynik = a * b;
    std::cout << "wynik: " << wynik <<std::endl<< "pamiec: " << mem << std::endl;


}

void dzielenie(double& a, double& b, double& wynik, double& mem) {
    podaj_liczby(a,b);
    if (b == 0) std::cout << "BŁĄD!";
    wynik = a / b;
    if (b != 0) std::cout << "wynik: " << wynik <<std::endl<< "pamiec: " << mem << std::endl;

}

void modulo(double& a, double& b, double& wynik, double& mem) {
    podaj_liczby(a,b);
    if (static_cast<int>(b) == 0) std::cout << "BLAD!";
    wynik = static_cast<int>(a) % static_cast<int>(b);
    if (b != 0) std::cout << "wynik: " << wynik <<std::endl<< "pamiec: " << mem << std::endl;


}

void mem_add(double& wynik, double& mem) {
    mem += wynik;
    std::cout << "wynik: " << wynik <<std::endl<< "pamiec: " << mem << std::endl;

}

void mem_sub(double& wynik, double& mem) {
    mem -= wynik;
    std::cout << "wynik: " << wynik <<std::endl<< "pamiec: " << mem << std::endl;

}

void mem_clr(double& wynik, double& mem) {
    mem = 0;
    std::cout << "wynik: " << wynik <<std::endl<< "pamiec: " << mem << std::endl;

}

void dzialanie(double& a,double&b, int& n, double& wynik, double& mem) {
    switch (n) {
        case 0:
            break;

        case 1:
            dodawanie(a, b, wynik,mem);
            break;

        case 2:
            odejmowanie(a, b, wynik,mem);
            break;
        
        case 3:
            mnozenie(a, b, wynik,mem);
            break;
      
        case 4:
            dzielenie(a, b, wynik,mem);
            break;

        case 5:
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
    
}

int main()
{   
    double mem = 0;
    double a;
    double b;
    int n = 1;
    double wynik = 0;
    while (n) {
        start(n);
        dzialanie(a, b, n, wynik, mem);
    }
    std::cout << "wynik: " << wynik << "pamiec: " << mem << std::endl;

}
