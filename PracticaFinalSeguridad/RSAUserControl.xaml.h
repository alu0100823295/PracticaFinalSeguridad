//
// RSAUserControl.xaml.h
// Declaration of the RSAUserControl class
//

#pragma once

#include "RSAUserControl.g.h"

namespace PracticaFinalSeguridad
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class RSAUserControl sealed
	{
	public:
		RSAUserControl();
	private:
		void Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
