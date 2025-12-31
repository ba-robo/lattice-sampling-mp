 //
// Created by itai on 7/15/24.
//

#pragma once

#include <string>
#include <vector>
#include <tuple>
#include <random>
#include <thread>
#include <float.h>
#include <map>
#include <Eigen/Dense>


namespace Lattices {
    enum LatticeType {
        Zn,
        DnStar,
        AnStar,
        File
    };

    class Lattice {
    public:
        Lattice(int dim, double delta, double epsilon, LatticeType type);

        void setBounds(std::vector<double> *bounds);

        std::vector<double> sample();

        class TVectorEquals {
        public:
            bool operator()(const Eigen::VectorXd &v1, const Eigen::VectorXd &v2) const {
                bool res = true;
                for (int i = 0; i < v1.size(); ++i) {
                    res = res && std::fabs(v1[i] - v2[i]) < 0.0001;
                }
                return res;
            }
        };

        // Hash function for Eigen matrix and vector.
        // The code is from `hash_combine` function of the Boost library. See
        // http://www.boost.org/doc/libs/1_55_0/doc/html/hash/reference.html#boost.hash_combine .
        template<typename T>
        struct matrix_hash : std::unary_function<T, size_t> { // moo!!
            std::size_t operator()(T const &matrix) const {
                // Note that it is oblivious to the storage order of Eigen matrix (column- or
                // row-major). It will give you the same hash value for two different matrices if they
                // are the transpose of each other in different storage order.
                size_t seed = 0;
                for (size_t i = 0; i < matrix.size(); ++i) {
                    // auto elem = *(matrix.data() + i);
                    // auto roundElem = roundf(*(matrix.data() + i) * 10000) / 10000;
                    int roundElem = round(*(matrix.data() + i) * 10000);
                    // int elem = (int)(10000 * roundElem);
                    // std::cout << "elem:" << elem << ",";
                    seed ^= std::hash<typename T::Scalar>()(roundElem) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
                }
                // std::cout << ",  ~~~seed=" << seed << std::endl;
                return seed;
            }
        };

        static double distEuclid(const Eigen::VectorXd &v1, const Eigen::VectorXd &v2, int d_) {
            double res = 0;
            for (int w = 0; w < d_; ++w) {
                res += std::pow(v1[w] - v2[w], 2);
            }
            return std::sqrt(res);
        }

        static bool compareDoubles(double a, double b) {
            return fabs(a - b) < DBL_EPSILON;
        }

        std::tuple<long, double> getSampleCountInBallNew();

    protected:
        int d_;
        double r_;
        double rescale_;
        double max_ind_;  // max_ind_ 是晶格采样的最大索引范围，用于定义采样空间的边界
        LatticeType type_;
        Eigen::MatrixXd T_;
        std::random_device seed_;
        std::mt19937 gen_;
        std::uniform_int_distribution<> dist_;
        std::vector<double>* bounds_;
    };



}



// #endif //LATTICES_H
