#include <iostream>

class IntNumber {
private:
    int value;

public:
    IntNumber(int val = 0) : value(val) {
        if (val < -128 || val > 128) {
            std::cerr << "Eroare: Valoarea trebuie să fie în diapazonul -128 până la 128.\n";
            exit(EXIT_FAILURE);
        }
    }

    IntNumber& operator++() {
        if (++value > 128) {
            std::cerr << "Eroare: Incrementarea depășește limita superioară.\n";
            exit(EXIT_FAILURE);
        }
        return *this;
    }

    IntNumber operator+(const IntNumber& other) const {
        int result = value + other.value;
        if (result < -128 || result > 128) {
            std::cerr << "Eroare: Adunarea depășește limitele.\n";
            exit(EXIT_FAILURE);
        }
        return IntNumber(result);
    }

    friend std::ostream& operator<<(std::ostream& os, const IntNumber& num);
    friend std::istream& operator>>(std::istream& is, IntNumber& num);
};

std::ostream& operator<<(std::ostream& os, const IntNumber& num) {
    os << num.value;
    return os;
}

std::istream& operator>>(std::istream& is, IntNumber& num) {
    is >> num.value;
    if (num.value < -128 || num.value > 128) {
        std::cerr << "Eroare: Valoarea trebuie să fie în diapazonul -128 până la 128.\n";
        exit(EXIT_FAILURE);
    }
    return is;
}

int main() {
    IntNumber num1, num2;

    std::cout << "Introduceti primul numar: ";
    std::cin >> num1;

    std::cout << "Introduceti al doilea numar: ";
    std::cin >> num2;

    std::cout << "Numarul 1: " << num1 << "\n";
    std::cout << "Numarul 2: " << num2 << "\n";

    IntNumber sum = num1 + num2;
    std::cout << "Suma: " << sum << "\n";

    ++num1;
    std::cout << "Numarul 1 dupa incrementare: " << num1 << "\n";

    return 0;
}
