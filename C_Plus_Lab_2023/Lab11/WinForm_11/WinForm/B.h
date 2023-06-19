#pragma once
#include "BigIndicator.h"

class B : public BigIndicator
{
public:
	B() : BigIndicator(20, 20, 0, 0, 0, 0) {}

	void Draw(System::Drawing::Graphics^ gr, System::Drawing::Pen^ pen, System::Drawing::SolidBrush^ brRed, System::Drawing::SolidBrush^ brWhite);

	friend bool operator<(B b1, B b2);
	friend bool operator>(B b1, B b2);
	friend bool operator==(B b1, B b2);
};