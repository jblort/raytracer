#include "math/QuadraticSolver.h"

#include "math/FloatingComp.h"

#include <cmath>

using namespace rt;

int Solver::QuadraticSolution::count() {
    return std::vector<double>::size();
}

void Solver::QuadraticSolution::addSolution(double value) {
    std::vector<double>::push_back(value);
}

Solver::QuadraticSolution Solver::solveQuadratic(double a, double b, double c) {
    auto solution = QuadraticSolution{};

    auto delta = b * b - 4 * a * c;
    if (delta < 0) {
        return solution;
    }

    if (isEqual(delta, 0.0)) {
        auto value = -0.5 * b / a;
        solution.addSolution(value);
        return solution;
    }

    auto deltaSquareRoot = std::sqrt(delta);
    auto posSolution = -0.5 * (b + deltaSquareRoot) / a;
    auto negSolution = -0.5 * (b - deltaSquareRoot) / a;
    solution.addSolution(posSolution);
    solution.addSolution(negSolution);

    return solution;
}
