#include <iostream>
#include <vector>
using namespace std;

// �w�q Polynomial ���O
class Polynomial {
private:
    vector<int> coefficients; // �x�s�Y��
    vector<int> exponents;    // �x�s����

    // �X�֦P����
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

    // �K�[�s����
    void addTerm(int coeff, int exp) {
        coefficients.push_back(coeff);
        exponents.push_back(exp);
    }

    // ������J�B��� >>
    friend istream& operator>>(istream& in, Polynomial& poly) {
        int coeff, exp;
        cout << "��J�h�������ء]�Y�� ���ơ^�A��J -1 -1 �����G" << endl;
        while (true) {
            in >> coeff >> exp;
            if (coeff == -1 && exp == -1) break;
            poly.addTerm(coeff, exp);
        }
        poly.simplify(); // �۰ʦX�֦P����
        return in;
    }

    // ������X�B��� <<
    friend ostream& operator<<(ostream& out, const Polynomial& poly) {
        for (size_t i = 0; i < poly.coefficients.size(); ++i) {
            if (poly.coefficients[i] != 0) {
                out << poly.coefficients[i] << "x^" << poly.exponents[i];
                if (i < poly.coefficients.size() - 1) out << " + ";
            }
        }
        return out;
    }

    // �h�����[�k
    Polynomial operator+(const Polynomial& other) const {
        Polynomial result = *this;
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            result.addTerm(other.coefficients[i], other.exponents[i]);
        }
        result.simplify(); // �X�֦P����
        return result;
    }

    // �h������k
    Polynomial operator-(const Polynomial& other) const {
        Polynomial result = *this;
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            result.addTerm(-other.coefficients[i], other.exponents[i]);
        }
        result.simplify(); // �X�֦P����
        return result;
    }

    // �h�������k
    Polynomial operator*(const Polynomial& other) const {
        Polynomial result;
        for (size_t i = 0; i < coefficients.size(); ++i) {
            for (size_t j = 0; j < other.coefficients.size(); ++j) {
                int newCoeff = coefficients[i] * other.coefficients[j];
                int newExp = exponents[i] + other.exponents[j];
                result.addTerm(newCoeff, newExp);
            }
        }
        result.simplify(); // �X�֦P����
        return result;
    }
};

int main() {
    Polynomial p1, p2;

    // ��J�Ĥ@�Ӧh����
    cout << "��J�Ĥ@�Ӧh�����G" << endl;
    cin >> p1;

    // ��J�ĤG�Ӧh����
    cout << "��J�ĤG�Ӧh�����G" << endl;
    cin >> p2;

    // ��X��Ӧh����
    cout << "�Ĥ@�Ӧh�����G" << p1 << endl;
    cout << "�ĤG�Ӧh�����G" << p2 << endl;

    // �[�k�B��
    Polynomial sum = p1 + p2;
    cout << "�[�k���G�G" << sum << endl;

    // ��k�B��
    Polynomial diff = p1 - p2;
    cout << "��k���G�G" << diff << endl;

    // ���k�B��
    Polynomial prod = p1 * p2;
    cout << "���k���G�G" << prod << endl;

    return 0;
}
