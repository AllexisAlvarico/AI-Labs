#pragma once
#include "MyVector3.h"

struct Steering
{
	MyVector3 m_linear{};
	MyVector3 m_angular{};
	float m_rotation{};
};