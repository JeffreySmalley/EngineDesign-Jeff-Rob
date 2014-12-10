#include "InternalScriptExports.h"

bool InternalScriptExports::LoadAndExportScriptResource(const char* scriptResource)
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
	//LuaObject globals = LuaStateManager 
}