#include "main.h"
#include "fose\GameAPI.h"
#include "fose\PluginAPI.h"
#include "fose\Hooks_DirectInput8Create.h"
#include "fose\Hooks_SaveLoad.h"
#include "fose_common\SafeWrite.h"
#include <dinput.h>
#include <steam/include/steam_api.h>
#include <steam/include/isteamfriends.h>
#include <steam/include/isteamutils.h>

/*
struct SteamOverlayCallback {
	SteamOverlayCallback();
	STEAM_CALLBACK(SteamOverlayCallback, OnGameOverlayActivated, GameOverlayActivated_t, m_GameOverlayActivated);
};
*/

extern "C" {
	BOOL WINAPI DllMain(HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved) {
		return TRUE;
	}

	bool FOSEPlugin_Query(const FOSEInterface* fose, PluginInfo* info) {
		// fill out the info structure
		info->infoVersion = PluginInfo::kInfoVersion;
		info->name = PLUGIN_NAME;
		info->version = PLUGIN_VERSION;

		return !(fose->isEditor || fose->foseVersion < FOSE_VERSION_INTEGER);
	}

	bool FOSEPlugin_Load(const FOSEInterface* fose) {
		// don't do anything if steam isn't running
		if (!SteamAPI_IsSteamRunning())
			return true;

		// fail if init failed
		if (!SteamAPI_Init())
			return false;

		// load function
		//HMODULE ce = GetModuleHandleA("CommandExtender.dll");
		//MainLoopAddCallbackEx = (MainLoopAddCallbackExProc)GetProcAddress(ce, "MainLoopAddCallbackEx");
		//MainLoopAddCallbackEx(SteamAPI_RunCallbacks, nullptr, 0, 100);

		return true;
	}
};

/*
SteamOverlayCallback::SteamOverlayCallback()
	: m_GameOverlayActivated(this, &SteamOverlayCallback::OnGameOverlayActivated) {}

void SteamOverlayCallback::OnGameOverlayActivated(GameOverlayActivated_t* pParam) {
	if (pParam->m_bActive) {
		// pause game when overlay activates
		DI_data.TapKey(DIK_ESCAPE);
		Console_Print("hello");
		// FreezeTime 0/1
	}
	Console_Print("damn");
}
*/
