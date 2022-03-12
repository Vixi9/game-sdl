//
// Created by victor on 11/03/2022.
//

#include "Player.h"

#include <utility>

Player::Player(double x, double y, double z, Vector3d viewportDirection) : x(x), y(y), z(z),
                                                                               viewportDirection(std::move(viewportDirection)) {}

double Player::getX() const {
    return x;
}

void Player::setX(double newX) {
    Player::x = newX;
}

double Player::getY() const {
    return y;
}

void Player::setY(double newY) {
    Player::y = newY;
}

double Player::getZ() const {
    return z;
}

void Player::setZ(double newZ) {
    Player::z = newZ;
}

const Vector3d &Player::getViewportDirection() const {
    return viewportDirection;
}

void Player::setViewportDirection(const Vector3d &viewport) {
    Player::viewportDirection = viewport;
}

void Player::move(double xIncrement, double yIncrement, double zIncrement) {
    Player::x += xIncrement;
    Player::y += yIncrement;
    Player::z += zIncrement;
}

void Player::rotate(double xAngle, double zAngle) {
    double newX = viewportDirection[0] * cos(xAngle) - viewportDirection[1] * sin(xAngle);
    double newY = viewportDirection[0] * sin(xAngle) + viewportDirection[1] * cos(xAngle);
    viewportDirection[0] = newX;
    viewportDirection[1] = newY;
}
