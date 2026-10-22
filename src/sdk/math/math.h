#pragma once
struct Vector3
{
	float x, y, z;
	Vector3();
	Vector3(float x, float y, float z);
	float Distance(const Vector3& other) const;
};
struct Vector2
{	
	float x, y;
	Vector2();
	Vector2(float x, float y);
	float vievAng(const Vector2& other) const;
};
