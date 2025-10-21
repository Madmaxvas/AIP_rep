#include <iostream>

void remove(int** m, size_t rows);

int** create(size_t rows, size_t cols){
	int** result = new (std::nothrow) int*[rows];
	if (result == nullptr) {
        return nullptr;
    }
	size_t i = 0;
	for(i = 0; i < rows; ++i){
		result[i] = new (std::nothrow) int[cols];
        if (result[i] == nullptr) {
	        remove(result, i);
            return nullptr;
        }
    }
	return result;
}

void remove(int** m, size_t rows){
    if (m == nullptr) return;
	for(size_t i = 0; i < rows; ++i){
        if (m[i] != nullptr) {
		    delete [] m[i];
        }
    }
	delete [] m;
}

void input(int** m, size_t rows, size_t cols){
	for (size_t i = 0; i < rows && (std::cin); ++i){
        	for(size_t j=0; j < cols && (std::cin); ++j ){
			std::cin >> m[i][j];}}}

void output(const int * const * m, size_t rows, size_t cols){
	std::cout << cols << " " << rows << "\n";
    	for (size_t j = 0; j < cols; ++j) {
        	for (size_t i = 0; i < rows; ++i) {
            		std::cout << m[i][j] << (i == rows - 1 ? "" : " ");
        		}
        	std::cout << "\n";
    		}
}

int main(){

    size_t rows = 0, cols = 0;

    std::cin >> rows >> cols;

    if(!std::cin){
        return 1;
    }

    int **m = nullptr;

    m = create(rows, cols);

    if (m == nullptr) {
        return 2;
    }

    input(m, rows, cols);

    if(!std::cin){
        remove(m, rows);
        return 1;
    }

    output(m, rows, cols);
    remove(m, rows);
    return 0;
}
