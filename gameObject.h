#pragma once

class GameObject {
protected:
	char symbol;

public:
	void setSymbol(char s_) {
		symbol = s_;
	}
	char getSymbol() {
		return symbol;
	}
};

class UserPlayer : public GameObject {
private:
	// default values to start 
	int x = 0;
	int y = 0;

public:
	int health;
	using GameObject::GameObject;

	void setLocation(int x_, int y_) {
		x = x_;
		y = y_;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};