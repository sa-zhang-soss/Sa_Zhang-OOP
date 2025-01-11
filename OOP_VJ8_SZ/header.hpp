#pragma once
#include <iostream>
#include <string>

class Enemy {
protected:
	std::string name;
	int health;
	int damage;

public:
	Enemy(){};
	Enemy(std::string name, int health, int damage);

	virtual void attack()=0;
	virtual void displayInfo()=0;

	std::string get_name();
	int get_health();
	int get_damage();
};

class Boss : public Enemy {
protected:
	std::string additional_weapon;
public:
	Boss(std::string name, int health, int damage, std::string additional_weapon);

	std::string get_name();
	int get_health();
	int get_damage();
	std::string get_additional_weapon();

	void attack();
	void displayInfo();
};

class Monster : public Enemy {
protected:
	std::string special_skill;
public:
	Monster(std::string name, int health, int damage, std::string special_skill);

	std::string get_name();
	int get_health();
	int get_damage();
	std::string get_special_skill();

	void attack();
	void displayInfo();
};