#pragma once
#include "BigIndicator.h"
using namespace System;
class C : public BigIndicator
{
public:
	C() : BigIndicator(20, 20, 0, 0, 0, 0) {}

	void Draw(System::Drawing::Graphics^ gr, System::Drawing::Pen^ pen, System::Drawing::SolidBrush^ brRed, System::Drawing::SolidBrush^ brWhite);

	friend bool operator<(C b1, C b2);
	friend bool operator>(C b1, C b2);
	friend bool operator==(C b1, C b2);
};