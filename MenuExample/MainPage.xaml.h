//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace MenuExample
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		void AddItemsToMenu();
		MainPage();
		property Windows::Foundation::Collections::IObservableVector<Microsoft::UI::Xaml::Controls::NavigationViewItem^>^ MenuCollection
		{
			Windows::Foundation::Collections::IObservableVector<Microsoft::UI::Xaml::Controls::NavigationViewItem^>^ get()
			{
				return m_menuCollection;
			}
		}
	private:
		Platform::Collections::Vector<Microsoft::UI::Xaml::Controls::NavigationViewItem^>^ m_menuCollection = nullptr;

		template<typename Func>
		Windows::Foundation::IAsyncAction^ CallOnUIThread(Func fn);

	};
}
