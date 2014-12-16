#include "InternalScriptExports.h"

bool InternalScriptExports::LoadAndExecuteScriptResource(const char* scriptResource)
{
	/*
	Resource resource(scriptResource);
	shared_ptr<ResHandle> pResourceHandle = g_pApp-<m_ResCache->GetHandle(&resource);>
	if (!pResourceHandle)
	{
		return true;
	}
	*/
	return false;
}
namespace ScriptExports
{
	void Register();
	void Unregister();
}
void ScriptExports::Register()
{
	//LuaObject globals = LuaStateManager::Get()->GetGlobalVars();

	// Init
	InternalScriptExports::Init();

	// Resource Loading
	//globals.RegisterDirect("LoadAndExecuteResource", InternalScriptExports::LoadAndExecuteScriptResource);
}
void ScriptExports::Unregister()
{
	InternalScriptExports::Destroy();
}