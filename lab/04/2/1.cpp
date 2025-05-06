// https://github.com/uLcdia/DSA/tree/main/lab/04/2

#include <iostream>
#include <string>
#include <vector>

struct Book {
    std::string isbn{};
    std::string name{};
    double price{};
};

void printBookArray(const std::vector<Book> &arr) {
    for (const auto &i : arr) {
        printf("%s %s %.2f\n", i.isbn.c_str(), i.name.c_str(), i.price);
    }
    std::cout << std::endl;
}

void printBookArray(const std::vector<Book> &arr,
                    const std::vector<size_t> &indices) {
    for (const auto &i : indices) {
        printf("%s %s %.2f\n", arr[i].isbn.c_str(), arr[i].name.c_str(),
               arr[i].price);
    }
    std::cout << std::endl;
}

std::vector<size_t> getMostExpensiveIndices(const std::vector<Book> &arr) {
    std::vector<size_t> indices{0};
    double highestPrice{arr[0].price};
    for (size_t i{1}; i < arr.size(); ++i) {
        auto currentPrice{arr[i].price};
        if (currentPrice >= highestPrice) {
            if (currentPrice != highestPrice) {
                highestPrice = currentPrice;
                indices.clear();
            }
            indices.emplace_back(i);
        }
    }
    return indices;
}

std::vector<Book> getArrayFromInput(int n) {
    std::vector<Book> array{};
    for (int i{0}; i < n; ++i) {
        Book newBook{};
        std::cin >> newBook.isbn;
        std::cin >> newBook.name;
        std::cin >> newBook.price;
        array.emplace_back(newBook);
    }
    return array;
}

int main() {
    int n{};
    std::cin >> n;

    auto books{getArrayFromInput(n)};
    auto indices{getMostExpensiveIndices(books)};

    std::cout << indices.size() << '\n';
    printBookArray(books, indices);

    return 0;
}