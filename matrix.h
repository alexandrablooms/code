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
                vector<T *> current_row(columns_);
                for (size_t j = 0; j < columns_; ++j) {
                    current_row[j] = &(data_[i * columns_ + j]);
                }
                representation_.push_back(move(current_row));
            }
        }

        Matrix(initializer_list<T> i_list, size_t rows, size_t columns) : rows_(rows), columns_(columns) {
            if (i_list.size() == rows_ * columns_) {
                data_.resize(rows_ * columns_);
                move(i_list.begin(), i_list.end(), data_.data());
                for (size_t i = 0; i < rows_; ++i) {
                    vector<T *> current_row(columns_);
                    for (size_t j = 0; j < columns_; ++j) {
                        current_row[j] = &(data_[i * columns_ + j]);
                    }
                    representation_.push_back(move(current_row));
                }
            } else {
                throw out_of_range(
                        "Current matrix position is wrong (" + to_string(rows) + ", " + to_string(columns) + ") != " + to_string(i_list.size()));
            }
        }