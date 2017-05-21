//
// DHUserControl.xaml.cpp
// Implementation of the DHUserControl class
//

#include "pch.h"
#include "DHUserControl.xaml.h"

#include "Practicas\DiffieHellman.h"

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

int To_Int(Platform::String^ platformString)
{
	return _wtoi(platformString->Data());
}


DHUserControl::DHUserControl()
{
	InitializeComponent();
}


void PracticaFinalSeguridad::DHUserControl::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	DiffieHellman DH;

	bool isPrimo = DH.setP(To_Int(primo->Text));
	bool isMinor = DH.setAlpha(To_Int(alpha->Text));

	DH.setXa(To_Int(xa->Text));
	DH.setXb(To_Int(xb->Text));

	int k = DH.generate();

	ya->Text = DH.getYa().ToString();
	yb->Text = DH.getYb().ToString();
	K->Text = k.ToString();
}
