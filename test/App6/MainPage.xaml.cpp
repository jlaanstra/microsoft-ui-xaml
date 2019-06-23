//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace App6;

using namespace Platform;
using namespace Platform::Collections;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

using namespace Microsoft::UI::Xaml::Controls;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
    InitializeComponent();

    m_items = ref new Vector<Item^>();
    Repeater->ItemsSource = m_items;
}

void MainPage::OnAppendClick(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    auto item = ref new Item();
    item->Background = ref new SolidColorBrush(Colors::Red);
    std::wstringstream str;
    str << L"http://loremflickr.com/400/200/?";
    str << m_count++;
    str << L"\r\n";
    item->Text = ref new String(str.str().c_str());
    m_items->Append(item);
}

void MainPage::OnSetClick(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    auto item = ref new Item();
    item->Background = ref new SolidColorBrush(Colors::Red);
    std::wstringstream str;
    str << L"http://loremflickr.com/400/200/?";
    str << m_count++;
    str << L"\r\n";
    item->Text = ref new String(str.str().c_str());

    int index = _wtoi(IndexTextBox->Text->Data());

    if (m_items->Size > index)
    {
        m_items->SetAt(index, item);
    }
}

void MainPage::OnRemoveClick(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    int index = _wtoi(IndexTextBox->Text->Data());

    if (m_items->Size > index)
    {
        m_items->RemoveAt(index);
    }
}

void MainPage::OnRemoveAppendClick(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    if (m_items->Size > 0)
    {
        m_items->RemoveAt(0);
    }
    auto item = ref new Item();
    item->Background = ref new SolidColorBrush(Colors::Red);
    std::wstringstream str;
    str << L"http://loremflickr.com/400/200/?";
    str << m_count++;
    str << L"\r\n";
    item->Text = ref new String(str.str().c_str());
    m_items->Append(item);
}
