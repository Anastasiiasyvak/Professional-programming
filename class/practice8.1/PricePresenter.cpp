#include <concepts>
#include <print>

template<typename T>
concept Priceable = requires(T obj) {
    { obj.getCoefficient() } -> std::same_as<double>;
    { obj.getBasePrice() } -> std::same_as<double>;
};

template<size_t PRIORITY>
class PricePresenter {
public:
    template<Priceable T1, Priceable T2>
    void printTotalPrice(const T1& obj1, const T2& obj2) {
        double totalPrice = PRIORITY * obj1.getCoefficient() * obj1.getBasePrice() + obj2.getCoefficient() * obj2.getBasePrice();
        std::println("Total price: {}", totalPrice);
    }
};

class Milk {
public:
    double getCoefficient() const {
        return 1.1;
    }
    double getBasePrice() const {
        return 2.0;
    }
};

class Cookies {
public:
    double getCoefficient() const {
        return 1.5;
    }
    double getBasePrice() const {
        return 3.0;
    }
};

class Pineapple {
public:
    double getCoefficient() const {
        return 1.3;
    }
    double getBasePrice() const {
        return 4.0;
    }
};

int main() {
    Milk milk;
    Cookies cookies;
    Pineapple pineapple;

    PricePresenter<2> presenter;
    presenter.printTotalPrice(milk, cookies); 
    presenter.printTotalPrice(cookies, pineapple); 
    presenter.printTotalPrice(pineapple, milk);

    return 0;
}
