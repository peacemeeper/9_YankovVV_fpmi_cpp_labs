#include "Header1.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

ChessPiece::ChessPiece(Colour colour_ , int x_ , int y_) : colour(colour_) , x(x_) , y(y_) {}

ChessPiece::ChessPiece(const ChessPiece& other) : colour(other.colour) , x(other.x) , y(other.y) {}

ChessPiece::~ChessPiece() {}

ChessPiece::ChessPiece(ChessPiece&& other) noexcept : colour(other.colour), x(other.x), y(other.y) {};

ChessPiece& ChessPiece::operator= (const ChessPiece& other) {
	if (this != &other) {
		colour = other.colour;
		x = other.x;
		y = other.y;
	}
	return *this;
}

ChessPiece& ChessPiece::operator=(ChessPiece&& other) noexcept {
	if (this != &other) {
		colour = other.colour;
		x = other.x;
		y = other.y;
	}
	return *this;
}

void ChessPiece::Move(int x_, int y_) {
	if (!CanMove(x_, y_)) {
		throw std::invalid_argument("Can't move like that");
	}
	x = x_;
	y = y_;
}

std::string ChessPiece::posToStr() const {
	std::string str;
	str+= char('a' + (x - 1));
	str+= std::to_string(y);
	return str;
}

Bishop::Bishop(Colour colour_ , int x_ , int y_) : ChessPiece(colour_ , x_ , y_) {}
Bishop::Bishop(const Bishop& other) : ChessPiece(other) {}
Bishop::Bishop(Bishop&& other) noexcept : ChessPiece(std::move(other)) {}
Bishop::~Bishop() {}
Bishop& Bishop::operator=(const Bishop& other) {
	ChessPiece::operator=(other);
	return *this;
}
Bishop& Bishop::operator =(Bishop && other) noexcept{
	ChessPiece::operator = (other);
	return *this;
}

Rook::Rook(Colour colour_, int x_, int y_) : ChessPiece(colour_, x_, y_) {}
Rook::Rook(const Rook& other) : ChessPiece(other) {}
Rook::Rook(Rook&& other) noexcept : ChessPiece(std::move(other)) {}
Rook::~Rook() {}
Rook& Rook::operator=(const Rook& other) {
	ChessPiece::operator=(other);
	return *this;
}
Rook& Rook::operator=(Rook&& other) noexcept {
	ChessPiece::operator= (other);
	return *this;
}

Queen::	Queen(Colour colour_, int x_, int y_) : ChessPiece(colour_, x_, y_) , Bishop::Bishop(colour_,x_, y_) , Rook::Rook(colour_ , x_ , y_) {}
Queen::Queen(const Queen& other) : ChessPiece(other) , Bishop(other), Rook(other) {}
Queen::Queen( Queen&& other) : ChessPiece(std::move(other)), Bishop(std::move(other)), Rook(std::move(other)) {}
Queen::~Queen() {}
Queen& Queen::operator=(const Queen& other) {
	ChessPiece::operator=(other);
	return *this;
}
Queen& Queen::operator =(Queen&& other) noexcept {
	ChessPiece::operator = (other);
	return *this;
}



std::string Bishop::getInfo() const {
	return 'B' + posToStr();
}

std::string Rook::getInfo() const {
	return 'R' + posToStr();
}

std::string Queen::getInfo() const {
	return 'Q' + posToStr();
}

bool Bishop::CanMove(int x_, int y_) const {
	if (x_ == x && y_ == y) {
		return false;
	}
	return abs( x_ - x) == abs(y_ - y);
}

bool Rook::CanMove(int x_, int y_) const {
	if (x_ == x && y_ == y) {
		return false;
	}
	return (x_ == x) || (y_ == y);
}

bool Queen::CanMove(int x_, int y_) const {
	if (x_ == x && y_ == y) {
		return false;
	}
	return Bishop::CanMove(x_, y_) || Rook::CanMove(x_, y_);
}


