//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace MenuExample;

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

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

void MainPage::AddItemsToMenu()
{
    auto fi = ref new FontIcon();

    auto txtContent = ref new TextBlock();
    txtContent->TextWrapping = TextWrapping::WrapWholeWords;
    txtContent->Text = L"Home";

    auto nvi = ref new Microsoft::UI::Xaml::Controls::NavigationViewItem();
    nvi->Content = txtContent;
    nvi->Icon = fi;
    nvi->IsSelected = true;

    this->MenuCollection->Append(nvi);
    this->navView->SelectedItem = nvi;
}

template <typename Func>
Windows::Foundation::IAsyncAction^ MainPage::CallOnUIThread(Func fn)
{
    return this->Dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal,
        ref new Windows::UI::Core::DispatchedHandler([this, fn]() {
        fn();
    }));
}

MainPage::MainPage()
{
	InitializeComponent();
	m_menuCollection = ref new Platform::Collections::Vector<Microsoft::UI::Xaml::Controls::NavigationViewItem^>();
    auto waitTask = concurrency::create_task([](){
        return concurrency::create_async([]() {
            Sleep(1000);
        });
    });
    //1. This works 100% of the times
    this->AddItemsToMenu();

    //2. This will work sometimes!
    //CallOnUIThread([this]() {
    //    this->AddItemsToMenu();
    //});

    //3. This never shows the selected item in the nav menu
    //waitTask.then([this]()
    //{        
    //    this->AddItemsToMenu();
    //});
}
