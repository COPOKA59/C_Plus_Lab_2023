#include "A.h"

void A::Draw(System::Drawing::Graphics^ gr, System::Drawing::Pen^ pen, System::Drawing::SolidBrush^ brRed, System::Drawing::SolidBrush^ brWhite)
{
	if (Condition == 1) {
		gr->FillEllipse(brRed, X + 10, Y + 10, W, W);
		gr->DrawEllipse(pen, X + 10, Y + 10, W, W);
	}
	else if (Condition == 0)
	{
		gr->FillEllipse(brWhite, X + 10, Y + 10, W, W);
		gr->DrawEllipse(pen, X + 10, Y + 10, W, W);
	}
}

bool operator<(A b1, A b2)
{
	return (b1.Condition < b2.Condition);
}
bool operator>(A b1, A b2)
{
	return (b1.Condition > b2.Condition);
}
bool operator==(A b1, A b2)
{
	return (b1.Condition == b2.Condition);
}
