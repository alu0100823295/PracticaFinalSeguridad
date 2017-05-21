//
// VigenereUserControl.xaml.cpp
// Implementation of the VigenereUserControl class
//

#include "pch.h"
#include "VigenereUserControl.xaml.h"

#include "Practicas\Vigenere.h"

using namespace PracticaFinalSeguridad;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236

VigenereUserControl::VigenereUserControl()
{
	InitializeComponent();
}

void PracticaFinalSeguridad::VigenereUserControl::Enc_Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Vigenere vig;

	std::wstring m(Msg->Text->Data());
	std::wstring k(Key->Text->Data());

	std::wstring enc = vig.encrypt(m, k);

	EncMesg->Text = ref new String(enc.c_str());
}


void PracticaFinalSeguridad::VigenereUserControl::Dec_Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Vigenere vig;

	std::wstring m(Msg->Text->Data());
	std::wstring k(Key->Text->Data());

	std::wstring enc = vig.decrypt(m, k);

	DecMesg->Text = ref new String(enc.c_str());
}