﻿//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------
#include "pch.h"

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BINDING_DEBUG_OUTPUT
extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent();
#endif

#include "VigenereUserControl.xaml.h"

void ::PracticaFinalSeguridad::VigenereUserControl::InitializeComponent()
{
    if (_contentLoaded)
    {
        return;
    }
    _contentLoaded = true;
    ::Windows::Foundation::Uri^ resourceLocator = ref new ::Windows::Foundation::Uri(L"ms-appx:///VigenereUserControl.xaml");
    ::Windows::UI::Xaml::Application::LoadComponent(this, resourceLocator, ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);
}

void ::PracticaFinalSeguridad::VigenereUserControl::Connect(int __connectionId, ::Platform::Object^ __target)
{
    switch (__connectionId)
    {
        case 1:
            {
                this->DecMesg = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
            }
            break;
        case 2:
            {
                this->EncMesg = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
            }
            break;
        case 3:
            {
                this->Enc_Button = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->Enc_Button))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::PracticaFinalSeguridad::VigenereUserControl::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&VigenereUserControl::Enc_Button_Click);
            }
            break;
        case 4:
            {
                this->Dec_Button = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->Dec_Button))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::PracticaFinalSeguridad::VigenereUserControl::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&VigenereUserControl::Dec_Button_Click);
            }
            break;
        case 5:
            {
                this->Msg = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(__target);
            }
            break;
        case 6:
            {
                this->Key = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(__target);
            }
            break;
    }
    _contentLoaded = true;
}

::Windows::UI::Xaml::Markup::IComponentConnector^ ::PracticaFinalSeguridad::VigenereUserControl::GetBindingConnector(int __connectionId, ::Platform::Object^ __target)
{
    __connectionId;         // unreferenced
    __target;               // unreferenced
    return nullptr;
}

