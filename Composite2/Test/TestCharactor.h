/// <summary>
/// テスト用キャラクタークラス
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
		//初期化
		void Initialize() {}
		//更新
		void Update() {}
		//描画
		void Render();
		//終了
		void Finalize() {}

		//体力設定
		inline void SetHp(const int& hp) { Hp = hp; }
		//体力取得
		inline int GetHp() { return Hp; }

		//名前取得
		inline std::string GetName() { return name; }
	private:
		//体力
		int Hp;
		//名前
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