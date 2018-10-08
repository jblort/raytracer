#pragma once

#include <vector>

namespace rt {
    namespace Solver {
        struct QuadraticSolution : private std::vector<double> {
            int count();
            using std::vector<double>::operator[];
            friend QuadraticSolution solveQuadratic(double a, double b, double c);

        private:
            void addSolution(double value);
        };

        QuadraticSolution solveQuadratic(double a, double b, double c);
    }
}
