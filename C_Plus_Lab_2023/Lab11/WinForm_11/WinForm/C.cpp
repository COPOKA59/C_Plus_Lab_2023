#include "C.h"

void C::Draw(System::Drawing::Graphics^ gr, System::Drawing::Pen^ pen, System::Drawing::SolidBrush^ brRed, System::Drawing::SolidBrush^ brWhite)
{
	FontFamily^ fntFamily = gcnew FontFamily(L"Arial");
	System::Drawing::Font^ fntWrite = gcnew System::Drawing::Font(fntFamily, (H-H/2 + W-W/2)/2, FontStyle::Italic);
	gr->DrawRectangle(pen, X + 5, Y + 5, W + W / 2, H + 10);
	if (Condition == 1) {
		gr->DrawString("ON", fntWrite, brRed, X + 5 + W / 4, Y + 5 + H / 4);
	}
	else if (Condition == 0)
	{
		gr->DrawString("OFF", fntWrite, brRed, X + 10, Y + 10);
	}
}
bool operator<(C b1, C b2)
{
	return (b1.Condition < b2.Condition);
}
bool operator>(C b1, C b2)
{
	return (b1.Condition > b2.Condition);
}
bool operator==(C b1, C b2)
{
	return (b1.Condition == b2.Condition);
}