#pragma once

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "Shape.h"
#include <math.h>

class Circle : public Shape
{

public:

    static unsigned int vertexArray;
    static unsigned int vertexBuffer;
    static unsigned int indexBuffer;

    Circle();

    void draw();

private:
    float vertices[200];
    unsigned int indexArr[300];
    void atribut();
};

