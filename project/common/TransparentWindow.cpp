#ifndef STATIC_LINK
#define IMPLEMENT_API
#endif

#if defined(HX_WINDOWS) || defined(HX_MACOS) || defined(HX_LINUX)
#define NEKO_COMPATIBLE
#endif

#if defined(HX_WINDOWS)
#include <Windows.h>
#include <dwmapi.h>
#include <wingdi.h>

#pragma comment(lib, "Dwmapi")
#pragma comment(lib, "Gdi32.lib")
#endif

#include <hx/CFFI.h>
#include <hx/CFFIPrime.h>

#if defined(HX_WINDOWS)

static value win32_enable_window_transparent( ) {
	DWM_BLURBEHIND blurBehind = {0};
	blurBehind.dwFlags = DWM_BB_ENABLE | DWM_BB_BLURREGION;
	blurBehind.fEnable = TRUE;
	blurBehind.hRgnBlur = CreateRectRgn(-1, -1, 0, 0);

	return alloc_bool(DwmEnableBlurBehindWindow(GetActiveWindow(), &blurBehind) == S_OK);
}

static value win32_disable_window_transparent( ) {
    DWM_BLURBEHIND blurBehind = {0};
    blurBehind.dwFlags = DWM_BB_ENABLE;
    blurBehind.fEnable = FALSE;

    return alloc_bool(DwmEnableBlurBehindWindow(GetActiveWindow(), &blurBehind) == S_OK);
}

DEFINE_PRIME0 (win32_enable_window_transparent);
DEFINE_PRIME0 (win32_disable_window_transparent);

#else

static value win32_window_transparent( ) {
	return alloc_bool(false);
}
DEFINE_PRIME0 (win32_window_transparent);

#endif

extern "C" void transparent_main () {
	val_int(0); // Fix Neko init
}
DEFINE_ENTRY_POINT (transparent_main);

extern "C" int transparent_register_prims () { return 0; }