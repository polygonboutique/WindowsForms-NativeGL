#include "stdafx.h"
#include "LibWrapper.h"

namespace TheWrapper
{
	LibWrapper::LibWrapper()
	{
		this->instance = new LibClass();
	}

	LibWrapper::~LibWrapper()
	{
		delete this->instance;
		this->instance = nullptr;
	}

	void LibWrapper::SetHWND(void* hwnd)
	{
		this->instance->SetHWND(static_cast<HWND>(hwnd));
	}

	void LibWrapper::Init()
	{
		this->instance->Init();
	}

	void LibWrapper::Update()
	{
		this->instance->Update();
	}
};