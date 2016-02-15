import sys
import numpy as np

#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
def print_board(board):
	print()
	for r in range(board.shape[0]):
		line = ''
		for c in range(board.shape[1]):
			if board[r][c] == 0:
				number = '-'
			else:
				number = str(int(board[r][c]))
			line += (number + ' ')
			if (c+1) % 3 == 0:
				line += '  '
		print(line)
		if (r+1) % 3 == 0:
			print()
	
#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
def read_board(fname):
	return np.loadtxt(fname, delimiter=',')


#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
def find_empty_cell(board):
	for i in range(board.shape[0]):
		for j in range(board.shape[1]):
			if board[i][j] == 0:
				return i, j
	return None, None


#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
def is_safe(board, row, col, number):
	# check for this row
	for i in range(board.shape[1]):
		if board[row][i] == number:
			return False
	# check for this col
	for i in range(board.shape[0]):
		if board[i][col] == number:
			return False
	# get index of the square where row,col is
	sqr, sqc = row // 3, col // 3
	# check all elements in this square
	for i in range(3):
		for j in range(3):
			if board[i+3*sqr][j+3*sqc] == number:
				return False
	# none has found ... position is safe
	return True

#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
def solve_sudoku(board):
	# find the position of the first empty cell
	row, col = find_empty_cell(board)
	# if no empty position is left ... then we are done
	if row == None:
		return True
	# check all digits from 1 to 9
	for i in range(1, 10):
		# try to place a number on the first empty location
		if is_safe(board, row, col, i):
			# assign the number
			board[row][col] = i
			# call recursevely to find a solution
			if solve_sudoku(board):
				# if successful then ... no more to do
				return True
			else:
				# otherwise, undo and try again
				board[row][col] = 0
	# if all numbers have been tried and no success then trigger backtraking
	return False

#------------------------------------------------------------------------------
#------------------------------------------------------------------------------
# main program
#------------------------------------------------------------------------------
board = read_board(sys.argv[1])
print_board(board)
solve_sudoku(board)
print_board(board)

