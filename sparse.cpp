#include <iostream>
#include <vector>

class SparseMatrix {
public:
    SparseMatrix(int rows, int cols) : rows(rows), cols(cols) {}

    void addElement(int row, int col, int value) {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            std::cerr << "Invalid row or column index." << std::endl;
            return;
        }

        if (value != 0) {
            values.push_back(value);
            column_indices.push_back(col);
            row_pointers.push_back(values.size());
        }
    }

    int getElement(int row, int col) const {
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            std::cerr << "Invalid row or column index." << std::endl;
            return 0; // Assuming 0 for out-of-range elements.
        }

        for (int i = row_pointers[row]; i < row_pointers[row + 1]; ++i) {
            if (column_indices[i] == col) {
                return values[i];
            }
        }

        return 0; // Element is zero.
    }

    void printMatrix() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << getElement(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    int rows;
    int cols;
    std::vector<int> values;
    std::vector<int> column_indices;
    std::vector<int> row_pointers;
};

int main() {
    int rows = 4;
    int cols = 4;

    SparseMatrix sparse(rows, cols);

    sparse.addElement(0, 0, 1);
    sparse.addElement(0, 3, 2);
    sparse.addElement(1, 1, 3);
    sparse.addElement(2, 2, 4);
    sparse.addElement(3, 0, 5);

    sparse.printMatrix();

    return 0;
}
