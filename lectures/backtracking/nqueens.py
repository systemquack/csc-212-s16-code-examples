import sys

# checks if a queen can be placed at board[row][col]
# this is only called when queens are placed in previous columns
def is_safe(board, row, col, n):
	# check row attacks
	for i in range(col):
		if board[row][i] == 1:
			return False
	# check for upper diagonal
	a, b = row, col
	while a >= 0 and b >= 0:
		if board[a][b] == 1:
			return False
		a, b = a-1, b-1
	# check for lower diagonal
	a, b = row, col
	while a < n and b >= 0:
		if board[a][b] == 1:
			return False
		a, b = a+1, b-1		

	return True

# recursive function to solve N Queen
def nqueens(board, col, n):
	# base case -- all queens are placed
	if col >= n:
		return True
	
	# try placing queen in all rows
	for i in range(n):
		# check if queen can be placed
		if is_safe(board, i, col, n):
			# place the queen
			board[i][col] = 1
			# recursively place all other queens
			if nqueens(board, col+1, n):
				# solution found
				return True
			else:
				# need to backtrack -- remove queen
				board[i][col] = 0
	# if queen cannot be placed in any row in this column ...
	return False


def print_board(board):
	for row in board:
		line = ''
		for val in row:
			if val == 1:
				line += "Q "
			else:
				line += ". " 
		print line

###########################################
### Main PROGRAM
###########################################
nq = int(sys.argv[1])
board = []
for i in range(nq):
	board.append([0] * nq)
nqueens(board, 0, nq)
print_board(board)
