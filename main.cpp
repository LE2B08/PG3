#include <stdio.h>
#include "Enemy.h"

int main()
{
	Enemy enemy;

	// 状態遷移を行う
	for (int i = 0; i < 3; i++)
	{
		enemy.UpdateState();
	}

	return 0;
}
