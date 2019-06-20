//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace App6
{
    public ref class Item sealed
    {
    public:
        property Windows::UI::Xaml::Media::SolidColorBrush^ Background;
        property Platform::String^ Text;

        Windows::UI::Xaml::Media::SolidColorBrush^ Trace(Windows::UI::Xaml::Media::SolidColorBrush^ b)
        {
            OutputDebugString(Text->Data());
            return b;
        }
    };

	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

    private:
        void OnAppendClick(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void OnSetClick(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void OnRemoveClick(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
        void OnRemoveAppendClick(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);

        Platform::Collections::Vector<Item^>^ m_items;
        uint32_t m_count;
    };
}
