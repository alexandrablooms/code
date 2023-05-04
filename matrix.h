#pragma once
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

namespace bmstu {
    template<typename T>
    class Matrix {
    public:
        Matrix() : data_(1), rows_(1), columns_(1) {
            representation_ = {{&data_[0]}};
        }

        Matrix(size_t rows, size_t columns) : data_(rows * columns), rows_(rows), columns_(columns) {
            for (size_t i = 0; i < rows_; ++i) {
                std::vector<T *> current_row(columns_);
                for (size_t j = 0; j < columns_; ++j) {
                    current_row[j] = &(data_[i * columns_ + j]);
                }
                representation_.push_back(std::move(current_row));
            }
        }
