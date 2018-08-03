#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#include <conio.h>
#include <Windows.h>
#include <Windowsx.h>
#include <Shlwapi.h>
#include <winapifamily.h>
#if WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP
#include <delayimp.h>
#include <comdef.h>
#include <Shellapi.h>
#include <Commdlg.h>
#include <CommCtrl.h>
#include <Shlobj.h>
#include <commoncontrols.h>
#include <Psapi.h>
#endif
#include <excpt.h>
#include <winapifamily.h>
#pragma warning(disable: 4996)
#include <direct.h>
#include <Strsafe.h>
#if WINAPI_FAMILY == WINAPI_FAMILY_DESKTOP_APP
#include <d3d9.h>
#include <dxgi.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <DXGI1_2.h>
#else
#include <d3d11_2.h>
#include <d3dcompiler.h>
#include <DXGI1_2.h>
#include <DirectXColors.h>
#include <DirectXMath.h>
#endif
#include <GL/glew.h>
#endif

#ifdef _OS_OSX_
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>
#include <dispatch/dispatch.h>
#endif

#include <egl.h>
#include <gles2.h>

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_STROKER_H

#include <setjmp.h>

#include <png.h>
#define STDC_HEADERS 1
#include <jpeglib.h>
#include <gif_lib.h>

#ifdef _OS_ANDROID_
#include <android/log.h>
#include <jni.h>
#define KTX_OPENGL_ES2 1
#include <ktx.h>
#endif

#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <ffi.h>

#if defined(__GNUC__)
#include <dlfcn.h>
#include <setjmp.h>
#include <sys/cdefs.h>
#endif

#include <signal.h>
#include <pthread.h>

#ifdef _WIN32
#include <direct.h>
#include <io.h>
#define mkdir(path,mode) _mkdir(path)
#define strtok_r strtok_s
#include <sys/stat.h>
#else
#include <utime.h>
#include <sys/time.h>
#include <sys/select.h>
#include <sys/stat.h>
#endif

#include <zlib.h>
#include <zip.h>
#include <unzip.h>
#include <sqlite3.h>

#define CASESENSITIVITY 0
#define WRITEBUFFERSIZE 8192
#define MAXFILENAME 256

#ifdef _WIN32
#define USEWIN32IOAPI
#include <iowin32.h>
#endif

#ifndef _WIN32
#include <fts.h>
#include <err.h>
#endif

#ifdef __APPLE__
#include <AvailabilityMacros.h>
#endif

#ifdef _WIN32
#undef near
#undef far
#undef random
#undef GetClassName
#undef DrawText
#undef CreateDirectory
#undef CreateFile
#undef CopyFile
#undef DeleteFile
#undef GetObject
#undef CreateWindow
#undef GetMessage
#endif

#define _USE_MATH_DEFINES
#include <math.h>
#include <assert.h>
#include <limits.h>
#include <locale.h>
