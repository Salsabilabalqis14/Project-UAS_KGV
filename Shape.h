#pragma once

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

class Shape
{

public:

    void setColor(glm::vec4 newColor);
    glm::vec4 getColor();
    glm::mat4x4 getTransformationMat4x4();
    void setTranslation(glm::vec3 newTranslation);
    void setTranslation(float transX, float transY, float transZ);

    void setRotation(float angle, glm::vec3 axis);
    void setScale(glm::vec3 newScale);
    void setScale(float scaleX, float scaleY, float scaleZ);

    virtual void draw() = 0;

    glm::vec4 color = glm::vec4(1.0, 1.0, 1.0, 1.0);

    glm::mat4x4 transformationMat4x4 = glm::mat4x4(1.0f);

private:

};

