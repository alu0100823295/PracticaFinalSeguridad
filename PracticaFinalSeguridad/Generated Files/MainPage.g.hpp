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

#include "MainPage.xaml.h"

void ::PracticaFinalSeguridad::MainPage::InitializeComponent()
{
    if (_contentLoaded)
    {
        return;
    }
    _contentLoaded = true;
    ::Windows::Foundation::Uri^ resourceLocator = ref new ::Windows::Foundation::Uri(L"ms-appx:///MainPage.xaml");
    ::Windows::UI::Xaml::Application::LoadComponent(this, resourceLocator, ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);
}

void ::PracticaFinalSeguridad::MainPage::Connect(int __connectionId, ::Platform::Object^ __target)
{
    switch (__connectionId)
    {
        case 1:
            {
                this->rootPivot = safe_cast<::Windows::UI::Xaml::Controls::Pivot^>(__target);
            }
            break;
        case 2:
            {
                this->VigDecMesg = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
            }
            break;
        case 3:
            {
                this->VigEncMesg = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(__target);
            }
            break;
        case 4:
            {
                this->Vig_Enc_Button = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->Vig_Enc_Button))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::PracticaFinalSeguridad::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::Vig_Enc_Button_Click);
            }
            break;
        case 5:
            {
                this->Vig_Dec_Button = safe_cast<::Windows::UI::Xaml::Controls::Button^>(__target);
                (safe_cast<::Windows::UI::Xaml::Controls::Button^>(this->Vig_Dec_Button))->Click += ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::PracticaFinalSeguridad::MainPage::*)
                    (::Platform::Object^, ::Windows::UI::Xaml::RoutedEventArgs^))&MainPage::Vig_Dec_Button_Click);
            }
            break;
        case 6:
            {
                this->VigMsg = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(__target);
            }
            break;
        case 7:
            {
                this->VigKey = safe_cast<::Windows::UI::Xaml::Controls::TextBox^>(__target);
            }
            break;
    }
    _contentLoaded = true;
}

::Windows::UI::Xaml::Markup::IComponentConnector^ ::PracticaFinalSeguridad::MainPage::GetBindingConnector(int __connectionId, ::Platform::Object^ __target)
{
    __connectionId;         // unreferenced
    __target;               // unreferenced
    return nullptr;
}


