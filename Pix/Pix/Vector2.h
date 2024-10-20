#pragma once

struct Vector2
{
    float x, y;

    Vector2() : x{ 0.0f }, y{ 0.0f } {}
    Vector2(float s) : x{ s }, y{ s } {}
    Vector2(float _x, float _y) : x{ _x }, y{ _y } {}
    Vector2(const Vector2& v) : x{ v.x }, y{ v.y } {}

    Vector2 operator-() const { return{ -x, -y }; }
    Vector2 operator+(const Vector2& rhs) const { return { x + rhs.x, y + rhs.y }; }
    Vector2 operator-(const Vector2& rhs) const { return { x - rhs.x, y - rhs.y }; }
    Vector2 operator*(float s) const { return { x * s, y * s }; }
    Vector2 operator/(float s) const { return { x / s, y / s }; }

    Vector2 operator+=(const Vector2& rhs) { x += rhs.x, y += rhs.y; return *this; }
    Vector2 operator-=(const Vector2& rhs) { x -= rhs.x, y -= rhs.y; return *this; }
    Vector2 operator=(float s) { x *= s, y *= s; return *this; }
    Vector2 operator/=(float s) { x /= s, y /= s; return *this; }
};