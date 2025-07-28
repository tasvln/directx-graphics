#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>

// From DXSampleHelper.h 
// Source: https://github.com/Microsoft/DirectX-Graphics-Samples
inline void throwFailed(HRESULT hr)
{
    if (FAILED(hr))
    {
        throw std::exception();
    }
}