#include "header.hpp"
#include <iostream>

Enemy::Enemy(std::string name, int health, int damage) {

	if ((health < 0) || (damage < 0))
		throw std::invalid_argument("Neispravan argument!(manji od nula)");

	this->name = name;
	this->health = health;
	this->damage = damage;
}

void Enemy::attack() {
	std::cout << "The enemy attacked" << std::endl;
}

void Enemy::displayInfo() {
	std::cout << this->get_name() << std::endl;
	std::cout << this->get_health() << std::endl;
	std::cout << this->get_damage() << std::endl;

}

std::string Enemy::get_name() {
	return this->name;
}
int Enemy::get_health() {
	return this->health;
}
int Enemy::get_damage() {
	return this->damage;
}

// BOSS -- BOSS -- BOSS -- BOSS 

Boss::Boss(std::string name, int health, int damage, std::string additional_weapon) {
	if ((health < 0) || (damage < 0)) {
		throw std::invalid_argument("health ili dmg su manji od 0");

		if (additional_weapon.empty())
			throw std::invalid_argument("additional weapon string je prazan");
	}
	
	this->name = name;
	this->health = health;
	this->damage = damage;
	this->additional_weapon = additional_weapon;
}

std::string Boss::get_name() {
	return this->name;
}

int Boss::get_health() {
	return this->health;
}

int Boss::get_damage() {
	return this->damage;
}

std::string Boss::get_additional_weapon() {
	return this->additional_weapon;
}

void Boss::attack() {
	std::cout << this->get_name() << " boss attacked!" << std::endl;
}

void Boss::displayInfo() {
	std::cout << "Name: " << this->get_name() << std::endl;
	std::cout << "Health: " << this->get_health() << std::endl;
	std::cout << "Damage: " << this->get_damage() << std::endl;
	std::cout << "Additional weapon: " << this->get_additional_weapon() << std::endl;
}

// MONSTER -- MONSTER -- MONSTER -- MONSTER

Monster::Monster(std::string name, int health, int damage, std::string special_skill) {
	if ((health < 0) || (damage < 0)) {
		throw std::invalid_argument("health ili dmg su manji od 0");

		if (special_skill.empty())
			throw std::invalid_argument("special skill string je prazan");
	}

	this->name = name;
	this->health = health;
	this->damage = damage;
	this->special_skill = special_skill;
}

std::string Monster::get_name() {
	return this->name;
}

int Monster::get_health() {
	return this->health;
}

int Monster::get_damage() {
	return this->damage;
}

std::string Monster::get_special_skill() {
	return this->special_skill;
}

void Monster::attack() {
	std::cout << this->get_name() << " monster attacked!" << std::endl;
}

void Monster::displayInfo() {
	std::cout << "Name: " << this->get_name() << std::endl;
	std::cout << "Health: " << this->get_health() << std::endl;
	std::cout << "Damage: " << this->get_damage() << std::endl;
	std::cout << "Special skill: " << this->get_special_skill() << std::endl;

}