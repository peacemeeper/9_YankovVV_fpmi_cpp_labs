#pragma once
#include <string> 
#include <iostream>

enum class Colour { Black, White };

class ChessPiece {
protected:
    int x;
    int y;
    Colour colour;
public:
    ChessPiece(Colour colour_, int x_, int y_);
    ChessPiece(const ChessPiece& other);
    ChessPiece(ChessPiece&& other) noexcept;
    virtual ~ChessPiece();

    ChessPiece& operator=(const ChessPiece& other);
    ChessPiece& operator=(ChessPiece&& other) noexcept;

    virtual std::string getInfo() const = 0;
    int getX() const { return x; }
    int getY() const { return y; }
    Colour getColour() const { return colour; }
    void Move(int x_, int y_);

    virtual bool CanMove(int x_, int y_) const = 0;
    std::string posToStr() const;
};

class Bishop :virtual public ChessPiece {
public:
    Bishop(Colour colour_, int x_, int y_);
    Bishop(const Bishop& other);
    Bishop(Bishop&& other) noexcept;
    ~Bishop();
    Bishop& operator=(const Bishop& other);
    Bishop& operator=(Bishop&& other) noexcept;
    std::string getInfo() const;
    bool CanMove(int x_, int y_) const;
};

class Rook :virtual public ChessPiece {
public:
    Rook(Colour colour_, int x_, int y_);
    Rook(const Rook& other);
    Rook(Rook&& other) noexcept;
    ~Rook();
    Rook& operator=(const Rook& other);
    Rook& operator=(Rook&& other) noexcept;
    std::string getInfo() const;
    bool CanMove(int x_, int y_) const;
};

class Queen :public Bishop, public Rook {
public:
    Queen(Colour colour_, int x_, int y_);
    Queen(const Queen& other);
    Queen(Queen&& other) noexcept;
    ~Queen();
    Queen& operator=(const Queen& other);
    Queen& operator=(Queen&& other) noexcept;
    std::string getInfo() const;
    bool CanMove(int x_, int y_) const;
};
