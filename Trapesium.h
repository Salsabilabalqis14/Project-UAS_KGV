#pragma once

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "Shape.h"

class Trapesium : public Shape
{

public:

    static unsigned int vertexArray;
    static unsigned int vertexBuffer;
    static unsigned int indexBuffer;

    Trapesium();

    void draw();

private:

    float vertices[24] = {
        -0.8f, 0.5f, 0.2f, -1.0f,
        -1.0f, -0.5f, 0.0f, -1.0f,
        -0.8f, -0.5f, 0.2f, -1.0f,
        0.8f, -0.5f,  1.8f, -1.0f,
        0.8f, 0.5f, 1.8f, 0.0f,
        1.0f, -0.5f, 2.0f, -1.0f
    };

    unsigned int indexArr[12] = {
        0, 1, 2,
        0, 2, 3,
        0, 3, 4,
        3, 4, 5
    };

};

