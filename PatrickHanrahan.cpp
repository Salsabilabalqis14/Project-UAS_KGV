// MyProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Util.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "Square.h"
#include "Trapesium.h"
#include "Circle.h"
#include "Letter.h"
#include <vector>

float currentTime = 0.0f;
GLint uColor;
GLint uMat4x4;

int a = 0, b = 0, c = 0;
float color1[] = { 1.0f, 0.0f, 0.0f, 1.0f };
float color2[] = { 1.0f, 0.0f, 0.0f, 1.0f };

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_UP && action == GLFW_PRESS)
    {
        a = 1;

        for (int i = 0; i < 4; i++)
        {
            color1[i] = (rand() * 1.0f) / RAND_MAX;
        }
    }

    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
    {
        b = 1;

        for (int i = 0; i < 4; i++)
        {
            color2[i] = (rand() * 1.0f) / RAND_MAX;
        }
    }

    if (key == GLFW_KEY_A && action == GLFW_PRESS)
    {
        c = 1;
    }
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 640, "Patrick Hanrahan-A", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, keyCallback);

    GLenum err = glewInit();

    //badan putih kamera
    Square s1;
    s1.setTranslation(0.0f, -0.2f, 0.0f);
    s1.setScale(0.8f, 0.5f, 1.0f);
    s1.setColor(glm::vec4(0.84f, 0.85f, 0.96f, 1.0f));

    //badan hitam kamera
    Square s2;
    s2.setTranslation(0.0f, -0.2f, 0.0f);
    s2.setScale(0.8f, 0.3f, 1.0f);
    s2.setColor(glm::vec4(0.25f, 0.33f, 0.36f, 1.0f));

    //lampu merah kamera
    Square s3;
    s3.setTranslation(-0.6f, 0.2f, 0.0f);
    s3.setScale(0.1f, 0.05f, 1.0f);
    s3.setColor(glm::vec4(0.94f, 0.34f, 0.36f, 1.0f));

    //tombol shutter
    Square s4;
    s4.setTranslation(-0.55f, 0.35f, 0.0f);
    s4.setScale(0.15f, 0.07f, 1.0f);
    s4.setColor(glm::vec4(0.25f, 0.33f, 0.36f, 1.0f));

    //persegi panjang atas kamera
    Square s5;
    s5.setTranslation(0.3f, 0.4f, 0.0f);
    s5.setScale(0.18f, 0.04f, 1.0f);
    s5.setColor(glm::vec4(0.84f, 0.85f, 0.96f, 1.0f));

    //persegi logo merek kamera
    Square s6;
    s6.setTranslation(-0.5f, -0.6f, 0.0f);
    s6.setScale(0.08f, 0.04f, 1.0f);
    s6.setColor(glm::vec4(0.02f, 0.22f, 0.43f, 1.0f));

    // persegi di atas program
    Square s7;
    s7.setTranslation(0.0f, 0.8f, 0.0f);
    s7.setScale(0.4f, 0.1f, 1.0f);
    s7.setColor(glm::vec4(0.25f, 0.33f, 0.36f, 1.0f));

    //trapesium atas kamera
    Trapesium tr1;
    tr1.setTranslation(0.3f, 0.4f, 0.0f);
    tr1.setScale(0.35f, 0.2f, 1.0f);
    tr1.setColor(glm::vec4(0.25f, 0.33f, 0.36f, 1.0f));

    //lingkaran kecil kiri pada atas kamera
    Circle c1;
    c1.setTranslation(0.12f, 0.4f, 0.0f);
    c1.setScale(0.04f, 0.04f, 1.0f);
    c1.setColor(glm::vec4(0.84f, 0.85f, 0.96f, 1.0f));

    //lingkaran kecil kanan pada atas kamera
    Circle c2;
    c2.setTranslation(0.48f, 0.4f, 0.0f);
    c2.setScale(0.04f, 0.04f, 1.0f);
    c2.setColor(glm::vec4(0.84f, 0.85f, 0.96f, 1.0f));

    //lensa terluar kamera
    Circle c3;
    c3.setTranslation(0.2f, -0.2f, 0.0f);
    c3.setScale(0.4f, 0.4f, 1.0f);
    c3.setColor(glm::vec4(0.27f, 0.35f, 0.4f, 1.0f));

    //lensa terluar kedua kamera
    Circle c4;
    c4.setTranslation(0.2f, -0.2f, 0.0f);
    c4.setScale(0.3f, 0.3f, 1.0f);
    c4.setColor(glm::vec4(0.22f, 0.29f, 0.33f, 1.0f));

    //lensa hitam
    Circle c5;
    c5.setTranslation(0.2f, -0.2f, 0.0f);
    c5.setScale(0.15f, 0.15f, 1.0f);
    c5.setColor(glm::vec4(0.f, 0.0f, 0.0f, 1.0f));

    //lingkaran putih kecil
    Circle c6;
    c6.setTranslation(0.15f, -0.15f, 0.0f);
    c6.setScale(0.03f, 0.03f, 1.0f);
    c6.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    //lingkaran putih besar
    Circle c7;
    c7.setTranslation(0.11f, -0.08f, 0.0f);
    c7.setScale(0.04f, 0.04f, 1.0f);
    c7.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

    //lingkaran logo merek kamera warna biru
    Circle c8;
    c8.setTranslation(-0.5f, -0.6f, 0.0f);
    c8.setScale(0.05f, 0.05f, 1.0f);
    c8.setColor(glm::vec4(0.02f, 0.22f, 0.43f, 1.0f));

    //lensa logo merek kamera
    Circle c9;
    c9.setTranslation(-0.5f, -0.6f, 0.0f);
    c9.setScale(0.03f, 0.03f, 1.0f);
    c9.setColor(glm::vec4(0.84f, 0.85f, 0.96f, 1.0f));

    //lingkaran kecil kanan di atas program
    Circle c10;
    c10.setTranslation(0.4f, 0.8f, 0.0f);
    c10.setScale(0.1f, 0.1f, 1.0f);
    c10.setColor(glm::vec4(0.84f, 0.85f, 0.96f, 1.0f));

    //lingkaran kecil kiri di atas progam
    Circle c11;
    c11.setTranslation(-0.4f, 0.8f, 0.0f);
    c11.setScale(0.1f, 0.1f, 1.0f);
    c11.setColor(glm::vec4(0.84f, 0.85f, 0.96f, 1.0f));

    //huruf h untuk merek
    Letter h1;
    h1.setTranslation(-0.66f, -0.6f, 0.0f);
    h1.setScale(0.05f, 0.05f, 1.0f);
    h1.setColor(glm::vec4(0.0f, 0.22f, 0.43f, 1.0f));

    //huruf h di atas program
    Letter h2;
    h2.setTranslation(0.0f, 0.8f, 0.0f);
    h2.setScale(0.05f, 0.05f, 1.0f);
    h2.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));


    vector<Shape*> shapes;
    shapes.push_back(&s4);
    shapes.push_back(&s1);
    shapes.push_back(&s2);
    shapes.push_back(&s3);
    shapes.push_back(&tr1);
    shapes.push_back(&s5);
    shapes.push_back(&c1);
    shapes.push_back(&c2);
    shapes.push_back(&c3);
    shapes.push_back(&c4);
    shapes.push_back(&c5);
    shapes.push_back(&c6);
    shapes.push_back(&c7);
    shapes.push_back(&c8);
    shapes.push_back(&s6);
    shapes.push_back(&c9);
    shapes.push_back(&h1);


    vector<Shape*> shapes1;
    shapes1.push_back(&s7);
    shapes1.push_back(&h2);
    shapes1.push_back(&c10);
    shapes1.push_back(&c11);

    string vertexString = readFile("vertex.vert");
    string fragmentString = readFile("fragment.frag");

    const char* vertexChar = vertexString.c_str();
    const char* fragmentChar = fragmentString.c_str();

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertexShader, 1, &vertexChar, NULL);
    glShaderSource(fragmentShader, 1, &fragmentChar, NULL);

    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    unsigned int program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    uColor = glGetUniformLocation(program, "uColor");
    uMat4x4 = glGetUniformLocation(program, "transformationMat4x4");

    Shape* shape;
    Shape* shape1;

    glfwSetTime(0);
    int d = 1;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {

        currentTime = glfwGetTime();
        if (floor(currentTime) == d)
        {
            d = d + 1;

            for (int i = 0; i < 4; i++)
            {
                color1[i] = (rand() * 1.0f) / RAND_MAX;
                color2[i] = (rand() * 1.0f) / RAND_MAX;
            }
        }

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1, 1, 1, 1);

        glUseProgram(program);

        for (int i = 0; i < shapes.size(); i++)
        {
            shape = shapes.at(i);
            glUniform4fv(uColor, 1, &(shape->getColor()[0]));
            glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &(shape->getTransformationMat4x4()[0][0]));
            shapes.at(i)->draw();
        }


        if (a == 1)
        {
            s2.setColor(glm::vec4(color1[0], color1[1], color1[2], color1[3]));
            s4.setColor(glm::vec4(color1[0], color1[1], color1[2], color1[3]));
            tr1.setColor(glm::vec4(color1[0], color1[1], color1[2], color1[3]));
        }

        if (b == 1)
        {
            s1.setColor(glm::vec4(color2[0], color2[1], color2[2], color2[3]));
            s5.setColor(glm::vec4(color2[0], color2[1], color2[2], color2[3]));
            c1.setColor(glm::vec4(color2[0], color2[1], color2[2], color2[3]));
            c2.setColor(glm::vec4(color2[0], color2[1], color2[2], color2[3]));
            c9.setColor(glm::vec4(color2[0], color2[1], color2[2], color2[3]));
            c10.setColor(glm::vec4(color2[0], color2[1], color2[2], color2[3]));
            c11.setColor(glm::vec4(color2[0], color2[1], color2[2], color2[3]));
        }

        if (c == 1)
        {
            for (int i = 0; i < shapes1.size(); i++)
            {
                shape1 = shapes1.at(i);
                glUniform4fv(uColor, 1, &(shape1->getColor()[0]));
                glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &(shape1->getTransformationMat4x4()[0][0]));
                shapes1.at(i)->draw();
            }
        }


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}