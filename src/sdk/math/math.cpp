#include <cmath>
#include "math.h"

Vector3::Vector3() { x = 0.0f; y = 0.0f; z = 0.0f; }
Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float Vector3::Distance(const Vector3& other) const {
    float dx = x - other.x;
    float dy = y - other.y;
    float dz = z - other.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

Vector2::Vector2() { x = 0.0f; y = 0.0f; }
Vector2::Vector2(float x, float y) {
    this->x = x;
    this->y = y;
}

float Vector2::vievAng(const Vector2& other) const {
    float dx = other.x - x;
    float dy = other.y - y;

    return std::atan2(dy, dx);
}
