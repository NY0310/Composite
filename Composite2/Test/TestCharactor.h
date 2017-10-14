/// <summary>
/// �e�X�g�p�L�����N�^�[�N���X
/// Yusuke Nakata
/// 2017/10/1
/// </summary>
#pragma once
#include <string>
#include <iostream>
#include "../GameObject/GameObjectInterface.h"

namespace gameobject
{
	class CharactorAbstract : public GameObjectInterface
	{
	public:
		CharactorAbstract() = delete;
		inline CharactorAbstract(std::string name,int hp) :name(name),Hp(hp) {}
		virtual ~CharactorAbstract() = default;
		//������
		void Initialize() {}
		//�X�V
		void Update() {}
		//�`��
		void Render();
		//�I��
		void Finalize() {}

		//�̗͐ݒ�
		inline void SetHp(const int& hp) { Hp = hp; }
		//�̗͎擾
		inline int GetHp() { return Hp; }

		//���O�擾
		inline std::string GetName() { return name; }
	private:
		//�̗�
		int Hp;
		//���O
		std::string name;
	};

	class CharactorA : public CharactorAbstract
	{
	public:
		CharactorA(std::string&& name, int&& hp) : CharactorAbstract(name + "CharactorA", hp) {}
		~CharactorA() = default;
		CharactorA(const CharactorA&) = delete;
		CharactorA& operator  = (const CharactorA&) = delete;
	private:
		std::string Aname = "CharactorA";
	};

	class CharactorB : public CharactorAbstract
	{
	public:
		CharactorB(std::string&& name, int&& hp) : CharactorAbstract(name + "CharactorB", hp) {}
		~CharactorB() = default;
		CharactorB(const CharactorB&) = delete;
		CharactorB& operator  = (const CharactorB&) = delete;
	private:
	};

	class CharactorC : public CharactorAbstract
	{
	public:
		CharactorC(std::string&& name, int&& hp) : CharactorAbstract(name + "CharactorC", hp) {}
		~CharactorC() = default;
		CharactorC(const CharactorC&) = delete;
		CharactorC& operator  = (const CharactorC&) = delete;
	private:
	};

}