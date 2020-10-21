#include "vec3.h"
#include <cmath>
#include <iostream>

vec3 operator+(const vec3& l, const vec3& r) {
	return vec3(l.x + r.x, l.y + r.y, l.z + r.z);
}

vec3 operator-(const vec3& l, const vec3& r) {
	return vec3(l.x - r.x, l.y - r.y, l.z - r.z);
}

vec3 operator*(const vec3& v, float f) {
	return vec3(v.x * f, v.y * f, v.z * f);
}

vec3 operator*(const vec3& l, const vec3& r) {
	return vec3(l.x * r.x, l.y * r.y, l.z * r.z);
}

float dot(const vec3& l, const vec3& r) {
	return l.x * r.x + l.y * r.y + l.z * r.z;
}

float lenSq(const vec3& v) {
	return v.x * v.x + v.y * v.y + v.z * v.z;
}

float len(const vec3& v) {
	float lenSq = v.x * v.x + v.y * v.y + v.z * v.z;
	if (lenSq < VEC3_EPSILON) {
		return 0.0f;
	}
	return sqrtf(lenSq);
}

void normalize(vec3& v) {
	float lenSq = v.x * v.x + v.y * v.y + v.z * v.z;
	if (lenSq < VEC3_EPSILON) { return; }
	float invLen = 1.0f / sqrtf(lenSq);
	v.x *= invLen;
	v.y *= invLen;
	v.z *= invLen;
}

vec3 normalized(const vec3& v) {
	float lenSq = v.x * v.x + v.y * v.y + v.z * v.z;
	if (lenSq < VEC3_EPSILON) { return v; }
	float invLen = 1.0f / sqrtf(lenSq);
	return vec3(
		v.x * invLen,
		v.y * invLen,
		v.z * invLen
	);
}

float angle(const vec3& l, const vec3& r) {
	float sqMagL = l.x * l.x + l.y * l.y + l.z * l.z;
	float sqMagR = r.x * r.x + r.y * r.y + r.z * r.z;

	if (sqMagL < VEC3_EPSILON || sqMagR < VEC3_EPSILON) { 
		return 0.0f; 
	}

	float dot = l.x * r.x + l.y * r.y + l.z * r.z;
	float len = sqrtf(sqMagL) * sqrtf(sqMagR);
	return acosf(dot / len);
}