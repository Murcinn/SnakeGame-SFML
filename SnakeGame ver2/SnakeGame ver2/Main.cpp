#include "GameProcess.h"
#include "GameMenu.h"
int main() {
	//GameProcess firstProcess;
	//firstProcess.RunGame();
	srand(time(NULL));
	GameMenu firstMenu;
	firstMenu.runMenu();

	return 0;
}