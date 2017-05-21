//
// DHUserControl.xaml.h
// Declaration of the DHUserControl class
//

#pragma once

#include "DHUserControl.g.h"

namespace PracticaFinalSeguridad
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class DHUserControl sealed
	{
	public:
		DHUserControl();
	private:
		void Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
