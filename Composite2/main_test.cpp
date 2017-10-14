/// <summary>
/// �V�[���O���t�e�X�g
/// </summary>

#include <iostream>
#include <cstdio>
#include "SceneGraph/SceneGraph.h"//�V�[���O���t
using namespace std;
using namespace SceneGraph;//�V�[���O���t�p���O��ԑS�Ă��ȗ��\

int main()
{
	//NodeABC�I�u�W�F�N�g����
	GameObj CharacterA = make_shared<CharactorA>("1", 1);
	GameObjNode NodeA = make_shared<GameObjectNode>(move(CharacterA));
		
	GameObj CharacterB = make_shared<CharactorB>("1", 2);
	GameObjNode NodeB = make_shared<GameObjectNode>(move(CharacterB));

	GameObj CharacterC = make_shared<CharactorC>("1", 3);
	GameObjNode NodeC = make_shared<GameObjectNode>(move(CharacterC));

	//�e�X�g
	cout << "NodeB��NodeA�̎q�Ɏw��" << endl;
	NodeA->AddChild(NodeB);

	cout << "NodeC��NodeB�̎q�Ɏw��" << endl;
	NodeB->AddChild(NodeC);

	cout << "NodeA��\��" << endl;
	NodeA->Render();

	cout << "NodeA����NodeB��؂藣��" << endl;
	NodeA->RemoveChild(NodeB);

	cout << "NodeA��\��" << endl;
	NodeA->Render();
	
	cout << "NodeB��\��" << endl;
	NodeB->Render();

	cout << "NodeB��NodeA�̎q�Ɏw��" << endl;
	NodeA->AddChild(NodeB);

	cout << "NodeA��\��" << endl;
	NodeA->Render();

	cout << NodeB.use_count() << endl;

	cout << "NodeB��e����؂藣�����㎩�g���폜(�Q�ƃJ�E���^���f�N�������g)" << endl;
	NodeB->RemoveFromParent();
	NodeB.reset();
	cout << NodeB.use_count() << endl;

	if (NodeB)
	{
		NodeB->Render();
	}
	else
	{
		cout << "NodeB�͍폜�ς�" << endl;
	}


	cout << "NodeA��\��" << endl;
	NodeA->Render();

	cout << "NodeB�̎q�ł���NodeC�́H" << endl;
	NodeC->Render();

	//NodeB���Ăѐ���
	CharacterB = make_shared<CharactorB>("2", 2);
	NodeB = make_shared<GameObjectNode>(move(CharacterB));
	cout << "NodeB��NodeA�̎q�Ɏw��" << endl;
	NodeA->AddChild(NodeB);
	cout << "NodeC��NodeB�̎q�Ɏw��" << endl;
	NodeB->AddChild(NodeC);
	cout << "NodeA�ɂ����̃m�[�h�����邩" << endl;
	cout << NodeA->GetSize() << endl;
	getchar();

	cout << "�m�[�h�𕡐�����" << endl;

	shared_ptr<NodeAbstract> NodeAClone = NodeA->Clone();
	cout << NodeAClone->GetSize() << endl;
	NodeAClone->Render();


	getchar();
	return 0;

}