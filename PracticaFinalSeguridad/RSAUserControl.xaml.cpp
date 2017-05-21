//
// RSAUserControl.xaml.cpp
// Implementation of the RSAUserControl class
//

#include "pch.h"
#include "RSAUserControl.xaml.h"

#include "Practicas\RSA.h"

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

long To_Long2(Platform::String^ platformString)
{
	return _wtol(platformString->Data());
}

std::string make_string1(const std::wstring& wstring)
{
	auto wideData = wstring.c_str();
	int bufferSize = WideCharToMultiByte(CP_UTF8, 0, wideData, -1, nullptr, 0, NULL, NULL);
	auto utf8 = std::make_unique<char[]>(bufferSize);
	if (0 == WideCharToMultiByte(CP_UTF8, 0, wideData, -1, utf8.get(), bufferSize, NULL, NULL))
		throw std::exception("Can't convert string to UTF8");

	return std::string(utf8.get());
}

RSAUserControl::RSAUserControl()
{
	InitializeComponent();
}


void PracticaFinalSeguridad::RSAUserControl::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	RSA rsa;
	rsa.setP(To_Long2(primoP->Text));
	rsa.setQ(To_Long2(primoQ->Text));
	rsa.setD(To_Long2(numD->Text));
	
	if (rsa.getData()) {
		output->Text = rsa.encrypt(make_string1(Msg->Text->Data()));
	}
}
