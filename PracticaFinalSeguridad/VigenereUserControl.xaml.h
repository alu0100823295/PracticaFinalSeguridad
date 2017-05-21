//
// VigenereUserControl.xaml.h
// Declaration of the VigenereUserControl class
//

#pragma once

#include "VigenereUserControl.g.h"

namespace PracticaFinalSeguridad
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class VigenereUserControl sealed
	{
	public:
		VigenereUserControl();

	private:
		void Enc_Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Dec_Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
