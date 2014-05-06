CC = g++
obj = valid_sudoku	
all:${obj}
best-time-to-buy-and-sell-stock:best-time-to-buy-and-sell-stock.cpp
	${CC} -g best-time-to-buy-and-sell-stock.cpp -o best-time-to-buy-and-sell-stock
pascals-triangle:pascals-triangle.cpp
	${CC} -g pascals-triangle.cpp -o pascals-triangle
minimum_path_sum:minimum_path_sum.cpp
	${CC} -g minimum_path_sum.cpp -o minimum_path_sum
pascals_triangle_ii:pascals_triangle_ii.cpp
	${CC} -g pascals_triangle_ii.cpp -o pascals_triangle_ii
regular_expression-matching:regular_expression-matching.cpp
	${CC} -g regular_expression-matching.cpp -o regular_expression-matching
wildcard_matching:wildcard_matching.cpp
	${CC} -g wildcard_matching.cpp -o wildcard_matching
validate_bst:validate_bst.cpp
	${CC} -g validate_bst.cpp -o validate_bst -std=c++0x
spiral_matrix_ii:spiral_matrix_ii.cpp
	${CC} -g spiral_matrix_ii.cpp -o spiral_matrix_ii -std=c++0x
valid_sudoku:valid_sudoku.cpp
	${CC} -g valid_sudoku.cpp -o valid_sudoku -std=c++0x
