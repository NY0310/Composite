/// <summary>
/// シーングラフテスト
/// </summary>

#include <iostream>
#include <cstdio>
#include "SceneGraph/SceneGraph.h"//シーングラフ
using namespace std;
using namespace SceneGraph;//シーングラフ用名前空間全てを省略可能

int main()
{
	//NodeABCオブジェクト生成
	GameObj CharacterA = make_shared<CharactorA>("1", 1);
	GameObjNode NodeA = make_shared<GameObjectNode>(move(CharacterA));
		
	GameObj CharacterB = make_shared<CharactorB>("1", 2);
	GameObjNode NodeB = make_shared<GameObjectNode>(move(CharacterB));

	GameObj CharacterC = make_shared<CharactorC>("1", 3);
	GameObjNode NodeC = make_shared<GameObjectNode>(move(CharacterC));

	//テスト
	cout << "NodeBをNodeAの子に指定" << endl;
	NodeA->AddChild(NodeB);

	cout << "NodeCをNodeBの子に指定" << endl;
	NodeB->AddChild(NodeC);

	cout << "NodeAを表示" << endl;
	NodeA->Render();

	cout << "NodeAからNodeBを切り離す" << endl;
	NodeA->RemoveChild(NodeB);

	cout << "NodeAを表示" << endl;
	NodeA->Render();
	
	cout << "NodeBを表示" << endl;
	NodeB->Render();

	cout << "NodeBをNodeAの子に指定" << endl;
	NodeA->AddChild(NodeB);

	cout << "NodeAを表示" << endl;
	NodeA->Render();

	cout << NodeB.use_count() << endl;

	cout << "NodeBを親から切り離した後自身を削除(参照カウンタをデクリメント)" << endl;
	NodeB->RemoveFromParent();
	NodeB.reset();
	cout << NodeB.use_count() << endl;

	if (NodeB)
	{
		NodeB->Render();
	}
	else
	{
		cout << "NodeBは削除済み" << endl;
	}


	cout << "NodeAを表示" << endl;
	NodeA->Render();

	cout << "NodeBの子であるNodeCは？" << endl;
	NodeC->Render();

	//NodeBを再び生成
	CharacterB = make_shared<CharactorB>("2", 2);
	NodeB = make_shared<GameObjectNode>(move(CharacterB));
	cout << "NodeBをNodeAの子に指定" << endl;
	NodeA->AddChild(NodeB);
	cout << "NodeCをNodeBの子に指定" << endl;
	NodeB->AddChild(NodeC);
	cout << "NodeAにいくつのノードがあるか" << endl;
	cout << NodeA->GetSize() << endl;
	getchar();

	cout << "ノードを複製する" << endl;

	shared_ptr<NodeAbstract> NodeAClone = NodeA->Clone();
	cout << NodeAClone->GetSize() << endl;
	NodeAClone->Render();


	getchar();
	return 0;

}