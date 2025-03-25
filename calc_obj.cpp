#include<iostream>

class Calculator {
    double a = 0;
    double b = 0;
    int n = -1;
    int n_old = -1;
    double wynik = 0;
    double mem = 0;

    public:
    void set_n_old() {
        n_old = n;
    }

    int* get_n() {
        return &n;
    }

    double* get_result() {
        return& wynik;
    }

    double* get_mem() {
        return& mem;
    }

    void input_num() {
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

    void add() {
        wynik = a + b;
    }

    void sub() {
        wynik = a - b;
    }

    void mult() {
        wynik =  a * b;
    }

    void div() {
        if (b == 0) {
            std::cout << "BŁĄD!";
        }
        wynik =  a / b;
    }

    void mod() {
        if (static_cast<int>(b) == 0) std::cout << "BLAD!";
        if (b != 0) wynik =  static_cast<int>(a) % static_cast<int>(b);
    }

    void mem_add() {
        mem += wynik;
    }

    void mem_sub() {
        mem -= wynik;
    }

    void mem_clr() {
        mem = 0;
    }
};

void start(int& n) {
    std::cout << "\npodaj numer operacji:\n0. stop\n1. dodawanie\n2. odejmowanie\n3. mnozenie\n4. dzielenie\n5. modulo\n6. dodaj do pamieci\n7. odejmij od pamieci\n8. wyczysc pamiec\njezeli wybierzesz dwa razy z rzedu ta sama opcje - za drugim razem a bedzie rowne wynikowi poprzedniej operacji" << std::endl;
    std::cin >> n;
}

int main() {
    Calculator c1;
    int* n = c1.get_n();
    while (*n) {
        start(*n);
        switch (*n) {
            case 0:
                break;

            case 1:
                c1.input_num();
                c1.add();
                std::cout <<"wynik: " << *c1.get_result()<<std::endl;
                std::cout <<"pamiec: " << *c1.get_mem();
                break;

            case 2:
                c1.input_num();
                c1.sub();
                std::cout <<"wynik: " << *c1.get_result()<<std::endl;
                std::cout <<"pamiec: " << *c1.get_mem();
                break;

            case 3:
                c1.input_num();
                c1.mult();
                std::cout <<"wynik: " << *c1.get_result()<<std::endl;
                std::cout <<"pamiec: " << *c1.get_mem();
                break;

            case 4:
                c1.input_num();
                c1.div();
                std::cout <<"wynik: " << *c1.get_result()<<std::endl;
                std::cout <<"pamiec: " << *c1.get_mem();
                break;

            case 5:
                c1.input_num();
                c1.mod();
                std::cout <<"wynik: " << *c1.get_result()<<std::endl;
                std::cout <<"pamiec: " << *c1.get_mem();

            break;

            case 6:
                c1.mem_add();
                std::cout <<"pamiec: " << *c1.get_mem();
            break;

            case 7:
                c1.mem_sub();
                std::cout <<"pamiec: " << *c1.get_mem();
            break;

            case 8:
                c1.mem_clr();
                std::cout <<"pamiec: " << *c1.get_mem();
            break;

            default:
                break;
        }
        c1.set_n_old();
    }
}