#include "pch_script.h"

#include "MainMenu.h"
#include "UIGameCustom.h"
#include "UI/UIScriptWnd.h"
#include "UI/UIButton.h"
#include "UI/UIProgressBar.h"
#include "UI/UIEditBox.h"
#include "UI/UIMessageBox.h"
#include "UI/UIPropertiesBox.h"
#include "UI/UITabControl.h"
#include "UI/UIComboBox.h"
#include "ui/UIOptionsManagerScript.h"
#include "ui/UIMapInfo.h"
#include "ScriptXmlInit.h"
#include "login_manager.h"
#include "account_manager.h"
#include "profile_store.h"
#include "xrScriptEngine/ScriptExporter.hpp"

using namespace luabind;

CMainMenu* MainMenu();

SCRIPT_EXPORT(UIRegistrator, (), {
    module(luaState)[class_<CGameFont>("CGameFont")
                         .enum_("EAligment")[value("alLeft", int(CGameFont::alLeft)),
                             value("alRight", int(CGameFont::alRight)), value("alCenter", int(CGameFont::alCenter))],

        class_<Patch_Dawnload_Progress>("Patch_Dawnload_Progress")
            .def("GetInProgress", &Patch_Dawnload_Progress::GetInProgress)
            .def("GetStatus", &Patch_Dawnload_Progress::GetStatus)
            .def("GetFlieName", &Patch_Dawnload_Progress::GetFlieName)
            .def("GetProgress", &Patch_Dawnload_Progress::GetProgress),

        class_<CMainMenu>("CMainMenu")
            .def("GetPatchProgress", &CMainMenu::GetPatchProgress)
            .def("CancelDownload", &CMainMenu::CancelDownload)
            .def("ValidateCDKey", &CMainMenu::ValidateCDKey)
            .def("GetGSVer", &CMainMenu::GetGSVer)
            .def("GetCDKey", &CMainMenu::GetCDKeyFromRegistry)
            .def("GetPlayerName", &CMainMenu::GetPlayerName)
            .def("GetDemoInfo", &CMainMenu::GetDemoInfo)
            .def("GetLoginMngr", &CMainMenu::GetLoginMngr)
            .def("GetAccountMngr", &CMainMenu::GetAccountMngr)
            .def("GetProfileStore", &CMainMenu::GetProfileStore)];

    module(luaState, "main_menu")[def("get_main_menu", &MainMenu)];
});
