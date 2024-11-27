#include <iostream>
#include <vector>
using namespace std;

// 定義 Polynomial 類別
class Polynomial {
private:
    vector<int> coefficients; // 儲存係數
    vector<int> exponents;    // 儲存指數

    // 合併同類項
    void simplify() {
        for (size_t i = 0; i < exponents.size(); ++i) {
            for (size_t j = i + 1; j < exponents.size(); ++j) {
                if (exponents[i] == exponents[j]) {
                    coefficients[i] += coefficients[j];
                    coefficients.erase(coefficients.begin() + j);
                    exponents.erase(exponents.begin() + j);
                    --j;
                }
            }
        }
    }

public:
    Polynomial() {}

    // 添加新項目
    void addTerm(int coeff, int exp) {
        coefficients.push_back(coeff);
        exponents.push_back(exp);
    }

    // 重載輸入運算符 >>
    friend istream& operator>>(istream& in, Polynomial& poly) {
        int coeff, exp;
        cout << "輸入多項式項目（係數 指數），輸入 -1 -1 結束：" << endl;
        while (true) {
            in >> coeff >> exp;
            if (coeff == -1 && exp == -1) break;
            poly.addTerm(coeff, exp);
        }
        poly.simplify(); // 自動合併同類項
        return in;
    }

    // 重載輸出運算符 <<
    friend ostream& operator<<(ostream& out, const Polynomial& poly) {
        for (size_t i = 0; i < poly.coefficients.size(); ++i) {
            if (poly.coefficients[i] != 0) {
                out << poly.coefficients[i] << "x^" << poly.exponents[i];
                if (i < poly.coefficients.size() - 1) out << " + ";
            }
        }
        return out;
    }

    // 多項式加法
    Polynomial operator+(const Polynomial& other) const {
        Polynomial result = *this;
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            result.addTerm(other.coefficients[i], other.exponents[i]);
        }
        result.simplify(); // 合併同類項
        return result;
    }

    // 多項式減法
    Polynomial operator-(const Polynomial& other) const {
        Polynomial result = *this;
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            result.addTerm(-other.coefficients[i], other.exponents[i]);
        }
        result.simplify(); // 合併同類項
        return result;
    }

    // 多項式乘法
    Polynomial operator*(const Polynomial& other) const {
        Polynomial result;
        for (size_t i = 0; i < coefficients.size(); ++i) {
            for (size_t j = 0; j < other.coefficients.size(); ++j) {
                int newCoeff = coefficients[i] * other.coefficients[j];
                int newExp = exponents[i] + other.exponents[j];
                result.addTerm(newCoeff, newExp);
            }
        }
        result.simplify(); // 合併同類項
        return result;
    }
};

int main() {
    Polynomial p1, p2;

    // 輸入第一個多項式
    cout << "輸入第一個多項式：" << endl;
    cin >> p1;

    // 輸入第二個多項式
    cout << "輸入第二個多項式：" << endl;
    cin >> p2;

    // 輸出兩個多項式
    cout << "第一個多項式：" << p1 << endl;
    cout << "第二個多項式：" << p2 << endl;

    // 加法運算
    Polynomial sum = p1 + p2;
    cout << "加法結果：" << sum << endl;

    // 減法運算
    Polynomial diff = p1 - p2;
    cout << "減法結果：" << diff << endl;

    // 乘法運算
    Polynomial prod = p1 * p2;
    cout << "乘法結果：" << prod << endl;

    return 0;
}
