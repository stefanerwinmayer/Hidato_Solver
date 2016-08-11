#ifndef STATE_STRUCT
#define STATE_STRUCT

struct State {
	struct Coordinate *hamiltonian;
	int ham_length;

	int **board;
	int board_rows;
	int board_cols;
};

#endif