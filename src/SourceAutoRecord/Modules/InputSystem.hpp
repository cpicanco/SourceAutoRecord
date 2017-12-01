#pragma once
#include "../Offsets.hpp"
#include "../Utils.hpp"

// ButtonCode_t
#define BUTTON_CODE_INVALID -1
#define KEY_ESCAPE 70

// CInputSystem::StringToButtonCode
using _StringToButtonCode = int(__stdcall*)(const char* pString);
// Key_SetBinding
using _KeySetBinding = void(__cdecl*)(int keynum, const char* pBinding);

namespace InputSystem
{
	void* Ptr;
	_StringToButtonCode StringToButtonCode;
	_KeySetBinding KeySetBinding;

	void Set(uintptr_t inputSystemPtr, uintptr_t keySetBindingAddr)
	{
		Ptr = **(void***)(inputSystemPtr);
		StringToButtonCode = (_StringToButtonCode)GetVirtualFunctionByIndex(Ptr, Offsets::StringToButtonCode);
		KeySetBinding = (_KeySetBinding)(keySetBindingAddr);
	}
}