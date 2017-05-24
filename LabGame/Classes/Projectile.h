#pragma once
#include "cocos2d.h"
using namespace cocos2d;
class Projectile
{
private:
	Vec2 m_Position;
	Vec2 m_Direction;
	float m_Speed;

	int m_Damage;
	int m_LifeSpan;

public:
	Projectile();
	~Projectile();
	void update(float dt);

	Vec2 GetDirection() { return m_Direction; };
	void SetDirection(Vec2 Direction) { m_Direction = Direction; };
	void SetDirection(int x, int y) { m_Direction = Vec2(x, y); };
	Vec2 GetPosition() { return m_Position; };
	void SetPosition(Vec2 Pos) { m_Position = Pos; };
	void SetPosition(int x, int y) { m_Position = Vec2(x, y); };
	float GetSpeed() { return m_Speed; };
	void SetSpeed(float speed) { m_Speed = speed; };
	int GetDamage() { return m_Damage; };
	void SetDamage(int dmg) {m_Damage = dmg;};
	int GetLifespan() { return m_LifeSpan; };
	void SetLifespan(int lifespan) { m_LifeSpan = lifespan; };

};