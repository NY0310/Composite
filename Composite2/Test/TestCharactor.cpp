/// <summary>
/// テスト用キャラクタークラス
/// Yusuke Nakata 
/// 2017/10/13
/// </summary>

#include "TestCharactor.h"
using namespace std;
using namespace gameobject;

/// <summary>
/// 出力
/// </summary>
void CharactorAbstract::Render()
{
	cout << name  << Hp << endl;
	getchar();


}
