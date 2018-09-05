#include "stdafx.h"
#include "ootzVector3.hpp"

#include <cassert>

#include "ootzType.hpp"
#include "ootzVector3Int.hpp"

namespace ootz
{

Vector3 Vector3::Zero()
{
    return Vector3(0.0f, 0.0f, 0.0f);
}

Vector3 Vector3::One()
{
    return Vector3(1.0f, 1.0f, 1.0f);
}

Vector3s Vector3::EightDirections()
{
    return Vector3s
    {
        Vector3(0.0f, 0.0f, 1.0f),
        Vector3(1.0f, 0.0f, 1.0f),
        Vector3(1.0f, 0.0f, 0.0f),
        Vector3(1.0f, 0.0f, -1.0f),
        Vector3(0.0f, 0.0f, -1.0f),
        Vector3(-1.0f, 0.0f, -1.0f),
        Vector3(-1.0f, 0.0f, 0.0f),
        Vector3(-1.0f, 0.0f, 1.0f)
    };
}

Vector3::Vector3()
    : x(0.0f)
    , y(0.0f)
    , z(0.0f)
{
}

Vector3::Vector3(const float x, const float y, const float z)
    : x(x)
    , y(y)
    , z(z)
{
}

Vector3 Vector3::Round() const
{
    return Vector3(
        std::round(x),
        std::round(y),
        std::round(z));
}

Vector3Int Vector3::ToVector3Int() const
{
    return Vector3Int(
        static_cast<Int>(x),
        static_cast<Int>(y),
        static_cast<Int>(z));
}

Vector3& Vector3::operator+=(const Vector3& other)
{
    x += other.x;
    y += other.y;
    z += other.z;

    return *this;
}

Vector3& Vector3::operator-=(const Vector3& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;

    return *this;
}

Vector3& Vector3::operator*=(const float other)
{
    x *= other;
    y *= other;
    z *= other;

    return *this;
}

Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
{
    return Vector3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

Vector3 operator-(const Vector3& lhs, const Vector3& rhs)
{
    return Vector3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

Vector3 operator*(const Vector3& lhs, const float rhs)
{
    return Vector3(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

Vector3 operator*(const float lhs, const Vector3& rhs)
{
    return rhs * lhs;
}

Vector3 operator/(const Vector3& lhs, const float rhs)
{
    assert(rhs != 0.0f && "divided by zero");

    return Vector3(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
}

} // namespace ootz