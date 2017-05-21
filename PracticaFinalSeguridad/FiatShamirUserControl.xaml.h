//
// FiatShamirUserControl.xaml.h
// Declaration of the FiatShamirUserControl class
//

#pragma once

#include "FiatShamirUserControl.g.h"


namespace PracticaFinalSeguridad
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class FiatShamirUserControl sealed
	{
	public:
		FiatShamirUserControl();

	private:
		void Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
