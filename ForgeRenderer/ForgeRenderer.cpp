// ForgeRender.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "ForgeRenderer.h"
#include "AppFramework.h"

using namespace Forge;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	DeviceType type = DT_Soft;
	std::wstring device_type(lpCmdLine);
	if (device_type == L"soft")
		type = DT_Soft;
	else if (device_type == L"d3d11")
		type = DT_D3D11;

	AppFrameworkPtr app = std::make_shared<AppFramework>();
	if (!app->Initialize(hInstance, 800, 600, L"һ���򵥵Ĺ�դ����Ⱦ��ʵ��"))
		return 1;
	app->Run();
	app->ShutDown();
	return 0;
}