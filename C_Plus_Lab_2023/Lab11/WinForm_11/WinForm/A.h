#pragma once
#include "BigIndicator.h"

class A : public BigIndicator
{
public:
	A() : BigIndicator(20, 20, 0, 0, 0, 0) {}

	void Draw(System::Drawing::Graphics^ gr, System::Drawing::Pen^ pen, System::Drawing::SolidBrush^ brRed, System::Drawing::SolidBrush^ brWhite);

	friend bool operator<(A b1, A b2);
	friend bool operator>(A b1, A b2);
	friend bool operator==(A b1, A b2);
};