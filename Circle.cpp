#include "Circle.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

unsigned int Circle::vertexBuffer = 0;
unsigned int Circle::indexBuffer = 0;
unsigned int Circle::vertexArray = 0;


Circle::Circle()
{
    atribut();
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);

    glGenBuffers(1, &vertexBuffer);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 200, vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &indexBuffer);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 300, indexArr, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, 0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (void*)(2 * sizeof(float)));
}

void Circle::draw()
{
    glBindVertexArray(vertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glDrawElements(GL_TRIANGLES, 300, GL_UNSIGNED_INT, nullptr);
}

void Circle::atribut()
{
    float xp = 0, yp = 0, r = 1, n = 100, a, x, y;
    int b = 0;
    a = 6.28 / n;
    for (int i = 0; i < n; i++) {
        vertices[b] = xp + r * sin(i * a);
        vertices[b + 1] = yp + r * cos(i * a);
        b = b + 2;
    }

    int c = 0;
    for (int i = 0; i < 99; i++)
    {
        indexArr[c] = 0;
        indexArr[c + 1] = i + 1;
        indexArr[c + 2] = i + 2;
        c = c + 3;
    }

}
