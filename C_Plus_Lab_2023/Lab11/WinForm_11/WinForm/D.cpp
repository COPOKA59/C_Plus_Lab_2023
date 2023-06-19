#include "D.h"

void D::Draw(System::Drawing::Graphics^ gr, System::Drawing::Pen^ pen, System::Drawing::SolidBrush^ brRed, System::Drawing::SolidBrush^ brWhite)
{
	FontFamily^ fntFamily = gcnew FontFamily(L"Arial");
	System::Drawing::Font^ fntWrite1 = gcnew System::Drawing::Font(fntFamily, H - H / 2, FontStyle::Regular);
	System::Drawing::Font^ fntWrite2 = gcnew System::Drawing::Font(fntFamily, H - H / 2, FontStyle::Bold);
	
	if (Condition == 1) {
		gr->DrawString("���", fntWrite2, brRed, X + 10, Y + 10);
		gr->DrawString("����", fntWrite1, brRed, X + 10 + H * 2, Y + 10);
	}
	else if (Condition == 0)
	{
		gr->DrawString("����", fntWrite2, brRed, X + 10 + H * 2, Y + 10);
		gr->DrawString("���", fntWrite1, brRed, X + 10, Y + 10);
	}
}
bool operator<(D b1, D b2)
{
	return (b1.Condition < b2.Condition);
}
bool operator>(D b1, D b2)
{
	return (b1.Condition > b2.Condition);
}
bool operator==(D b1, D b2)
{
	return (b1.Condition == b2.Condition);
}