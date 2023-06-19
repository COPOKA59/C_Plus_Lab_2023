#pragma once
#include "BigIndicator.h"

class D : public BigIndicator
{
public:
	D() : BigIndicator(20, 20, 0, 0, 0, 0) {}

	void Draw(System::Drawing::Graphics^ gr, System::Drawing::Pen^ pen, System::Drawing::SolidBrush^ brRed, System::Drawing::SolidBrush^ brWhite);

	friend bool operator<(D b1, D b2);
	friend bool operator>(D b1, D b2);
	friend bool operator==(D b1, D b2);
};