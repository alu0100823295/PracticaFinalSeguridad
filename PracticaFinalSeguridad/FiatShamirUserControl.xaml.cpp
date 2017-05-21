//
// FiatShamirUserControl.xaml.cpp
// Implementation of the FiatShamirUserControl class
//

#include "pch.h"
#include "FiatShamirUserControl.xaml.h"

#include "Practicas\FiatShamir.h"

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


long To_Long1(Platform::String^ platformString)
{
	return _wtol(platformString->Data());
}

FiatShamirUserControl::FiatShamirUserControl()
{
	InitializeComponent();
}

void PracticaFinalSeguridad::FiatShamirUserControl::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{	
	FiatShamir FS;
	FS.setP(To_Long1(primoP->Text));
	FS.setQ(To_Long1(primoQ->Text));

	FS.setN();

	FS.setS(To_Long1(numS->Text));


	bool nice = FS.exchange();

	N->Text = FS.getN().ToString();
	V->Text = FS.getV().ToString();

	if (nice)	ExitText->Text = "Todo Correcto";
	else	ExitText->Text = "Fallo en alguna iteración";

}
