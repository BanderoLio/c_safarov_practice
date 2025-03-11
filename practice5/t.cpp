#include <bits/stdc++.h>


template <typename T>
T power_modulo(T base, size_t exponent, size_t mod, T initial) {
    T res = std::move(initial);
    while (exponent) {
        if (exponent & 1) {
            --exponent;
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exponent >>= 1;
    }
    return res;
}


template <typename T>
class Matrix {
public:
    Matrix(const std::vector<std::vector<T>>& m) : m_matrix{m} {}

    const auto& matrix() const {
        return m_matrix;
    }


    Matrix<T> operator%(T m) {
        auto res = m_matrix;
        for (size_t i=0; i < res.size(); ++i) {
            for (size_t j=0; j < res[i].size(); ++j) {
                res[i][j] %= m;
            }
        }
        return Matrix<T>(res);
    }
    friend Matrix<T> operator*(const Matrix<T>& m1, const Matrix<T>& m2) {
        if (m1.m_matrix.front().size() != m2.m_matrix.size())
            throw std::runtime_error("Wrong matrix sizes: Unable to multiply");
        Matrix<T> res(std::vector<std::vector<T>>(m1.m_matrix.size(), std::vector<T>(m2.m_matrix.front().size(), T{})));
        for (size_t i=0; i < m1.m_matrix.size(); ++i) {
            for (size_t j=0; j < m2.m_matrix.front().size(); ++j) {
                for (size_t k=0; k < m1.m_matrix[i].size(); ++k) {
                    res.m_matrix[i][j] += m1.m_matrix[i][k] * m2.m_matrix[k][j];                  
                }
            }
        }
        return res;
    }
    friend auto& operator<<(std::ostream& out, const Matrix<T>& m) {
            for (size_t i=0; i < m.m_matrix.size(); ++i) {
                for (size_t j=0; j < m.m_matrix[i].size(); ++j) {
                    out << m.m_matrix[i][j] << ' ';
                }
                if (i != m.m_matrix.size() - 1) out << '\n';
            }
            return out;
    }
private:
    std::vector<std::vector<T>> m_matrix;    
};



int main() {
    size_t n;
    std::cin >> n;
    if (!n) {
        std::cout << 0 << '\n';
        return 0;
    }
    --n;
    // std::cout << power_modulo(2, 10e18, 1'000'000'7, 1) << '\n';
    std::vector<std::vector<size_t>> m = {{1,1}, {1, 0}};
    auto mat = power_modulo(Matrix<size_t>(m), n, 1'000'000'007, Matrix<size_t>({{1,0}, {0, 1}}));
    std::cout << (mat.matrix())[0][0]  << '\n';
}
//     std::thread t1([] {
//         std::lock_guard lg{m1};
//         std::cout << "ALEX\n";
//     });
//     std::thread t2([] {
//         std::lock_guard lg{m1};
//         std::cout << "BEBR\n";
//     });
//     std::cout << "main\n";
//     t1.join();
//     t2.join();
// }

