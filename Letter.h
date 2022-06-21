#pragma once

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "Shape.h"

class Letter : public Shape
{

public:

    static unsigned int vertexArray;
    static unsigned int vertexBuffer;
    static unsigned int indexBuffer;

    Letter();

    void draw();

private:

    float vertices[48] = {
        -1.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, 1.0f, 0.5f, 0.0f,
        -1.0f, -1.0f, 0.0f, -2.0f,
        -0.5f, -1.0f,  0.5f, -2.0f,
        -0.5f, 0.2f, 0.5f, 0.8f,
        -0.5f, -0.2f, 0.5f, -1.2f,
        0.5f, 0.2f, 1.5f, 0.8f,
        0.5f, -0.2f, 1.5f, -1.2f,
        0.5f, 1.0f, 1.5f, 0.0f,
        1.0f, 1.0f, 2.0f, 0.0f,
        0.5f, -1.0f, 1.5f, -2.0f,
        1.0f, -1.0f, 2.0f, -2.0f
    };

    unsigned int indexArr[18] = {
        0, 1, 2,
        1, 2, 3,
        4, 5, 7,
        4, 6, 7,
        8, 9, 10,
        9, 10, 11
    };

};

