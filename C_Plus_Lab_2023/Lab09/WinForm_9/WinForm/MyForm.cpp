#include "MyForm.h"

// 9 ����


using namespace System; 
using namespace System::Windows::Forms; 
using namespace WinForm; // ��� ������������ ���� �� MyForm.h 

[STAThreadAttribute] void Main(array<String^>^ args) {
	Application::EnableVisualStyles();  
	Application::SetCompatibleTextRenderingDefault(false);  
	Application::Run(gcnew MyForm); // MyForm � ��� ������ ����� 
}