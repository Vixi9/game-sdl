//
// Created by victor on 11/03/2022.
//

#ifndef SDL_PLAYER_H
#define SDL_PLAYER_H

#include <eigen3/Eigen/Dense>
#include <SDL2/SDL.h>
#include <cmath>

#define PLAYER_MOVE_SPEED 0.1
#define MOUSE_X_SENSIBILITY M_PI / 5000

using namespace Eigen;
using namespace std;

class Player {
    double x;
    double y;
    double z;
    Vector3d viewportDirection;

public:
    Player(double x, double y, double z, Vector3d viewportDirection);

    [[nodiscard]] double getX() const;

    void setX(double newX);

    [[nodiscard]] double getY() const;

    void setY(double newY);

    [[nodiscard]] double getZ() const;

    void setZ(double newZ);

    [[nodiscard]] const Vector3d &getViewportDirection() const;

    void setViewportDirection(const Vector3d &viewport);

    void move(double xIncrement, double yIncrement, double zIncrement);

    void rotate(double xAngle, double zAngle);
};


#endif //SDL_PLAYER_H
