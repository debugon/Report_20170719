#include"Reversi.h"

ReversiEngine::ReversiEngine()
{
	//StoneFlag gameBoard[8][8]
	//全要素をStoneFlag::None(= 0)で初期化
	gameBoard = std::vector<std::vector<StoneFlag>>(NUMBER_OF_SQUARE, std::vector<StoneFlag>(NUMBER_OF_SQUARE, StoneFlag::None));

	//初期配置セット
	gameBoard[3][3] = gameBoard[4][4] = StoneFlag::Black;
	gameBoard[3][4] = gameBoard[4][3] = StoneFlag::White;
}

ReversiEngine::~ReversiEngine()
{

}

void ReversiEngine::PrintGameBoard()
{
	//コンソール画面初期化
	system("cls");

	std::cout << "　│ 0│ 1│ 2│ 3│ 4│ 5│ 6│ 7│" << std::endl;
	for (int i = 0; i < NUMBER_OF_SQUARE; i++) {

		std::cout << "─┼─┼─┼─┼─┼─┼─┼─┼─┤" << std::endl;
		std::cout << " " << i << "│";
		for (int j = 0; j < NUMBER_OF_SQUARE; j++) {
			switch (gameBoard[i][j])
			{
			case StoneFlag::None:
				std::cout << "　";
				break;

			case StoneFlag::Black:
				std::cout << "●";
				break;

			case StoneFlag::White:
				std::cout << "○";
				break;
			}

			std::cout << "│";
		}

		if (i == StoneFlag::Black) std::cout << "●:PLAYER_1";
		if (i == StoneFlag::White) std::cout << "○:PLAYER_2";
		std::cout << std::endl;
	}
	std::cout << "─┴─┴─┴─┴─┴─┴─┴─┴─┘" << std::endl;
}

void ReversiEngine::SetGameBoard(int x, int y, StoneFlag flag)
{
	this->gameBoard[y][x] = flag;
}

bool ReversiEngine::isCheckReverse(int x, int y)
{
	int ORIGIN_X = x;
	int ORIGIN_Y = y;

	for (x; x < NUMBER_OF_SQUARE - 1; x++) {

	}

	return true;
}