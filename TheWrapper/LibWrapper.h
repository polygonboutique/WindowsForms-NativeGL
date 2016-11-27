#pragma once
#include <LibClass.h>

namespace TheWrapper
{
	public ref class LibWrapper
	{
	private:
		LibClass* instance;
	public:
		LibWrapper();
		~LibWrapper();
		void SetHWND(void* hwnd);
		void Init();
		void Update();
	};
}