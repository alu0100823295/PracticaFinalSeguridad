﻿#pragma once
//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------


namespace Windows {
    namespace UI {
        namespace Xaml {
            namespace Controls {
                ref class Button;
                ref class TextBlock;
                ref class TextBox;
            }
        }
    }
}

namespace PracticaFinalSeguridad
{
    [::Windows::Foundation::Metadata::WebHostHidden]
    partial ref class RSAUserControl : public ::Windows::UI::Xaml::Controls::UserControl, 
        public ::Windows::UI::Xaml::Markup::IComponentConnector,
        public ::Windows::UI::Xaml::Markup::IComponentConnector2
    {
    public:
        void InitializeComponent();
        virtual void Connect(int connectionId, ::Platform::Object^ target);
        virtual ::Windows::UI::Xaml::Markup::IComponentConnector^ GetBindingConnector(int connectionId, ::Platform::Object^ target);
    
    private:
        bool _contentLoaded;
    
        private: ::Windows::UI::Xaml::Controls::Button^ Button;
        private: ::Windows::UI::Xaml::Controls::TextBlock^ output;
        private: ::Windows::UI::Xaml::Controls::TextBox^ Msg;
        private: ::Windows::UI::Xaml::Controls::TextBox^ primoP;
        private: ::Windows::UI::Xaml::Controls::TextBox^ primoQ;
        private: ::Windows::UI::Xaml::Controls::TextBox^ numD;
    };
}

