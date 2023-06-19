#include "B.h"

void B::Draw(System::Drawing::Graphics^ gr, System::Drawing::Pen^ pen, System::Drawing::SolidBrush^ brRed, System::Drawing::SolidBrush^ brWhite)
{
	gr->DrawRectangle(pen, X+5, Y+5, W + 10, H + 10);
	if (Condition == 1) {
		gr->FillEllipse(brWhite, X + 10, Y + 10, H, H);
		gr->DrawEllipse(pen, X + 10, Y + 10, H, H);
		gr->FillEllipse(brRed, X + 15 + H, Y + 10, H, H);
		gr->DrawEllipse(pen, X + 15 + H, Y + 10, H, H);
	}
	else if (Condition == 0)
	{
		gr->FillEllipse(brRed, X + 10, Y + 10, H, H);
		gr->DrawEllipse(pen, X + 10, Y + 10, H, H);
		gr->FillEllipse(brWhite, X + 15 + H, Y + 10, H, H);
		gr->DrawEllipse(pen, X + 15 + H, Y + 10, H, H);
	}
}
bool operator<(B b1, B b2)
{
	return (b1.Condition < b2.Condition);
}
bool operator>(B b1, B b2)
{
	return (b1.Condition > b2.Condition);
}
bool operator==(B b1, B b2)
{
	return (b1.Condition == b2.Condition);
}