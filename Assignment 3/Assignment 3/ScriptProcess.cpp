#include "ScriptProcess.h"

const char* SCRIPT_PROCESS_NAME = "ScriptProcess";

void ScriptProcess::RegisterScriptClass()
{
	//LuaObject metaTableObj = LuaStateManager::Get()->GetGlobalVars().CreateTable(SCRIPT_PROCESS_NAME);
	//metaTableObj.SetObject("__index",metaTableObj);
	//metaTableObj.SetObject("base", metaTableObj);
	//metaTableObj.SetBoolean("cpp", true);
	//RegisterScriptClassFunctions();
	//metaTableObj.RegisterDirect("Create", &ScriptProcess::CreateFromScript);
}
void ScriptProcess::RegisterScriptClassFunctions()
{
	//LuaObject metaTableObj = LuaStateManager::Get()->GetGlobalVars().CreateTable(SCRIPT_PROCESS_NAME);
	//metaTableObj.RegisterObjectDirect("Succeed",(Process*)0,&Process::Succeed);
	//metaTableObj.RegisterObjectDirect("Fail",(Process*)0,&Process::Fail);
	//metaTableObj.RegisterObjectDirect("Pause",(Process*)0,&Process::Pause);
	//metaTableObj.RegisterObjectDirect("UnPause",(Process*)0,&Process::UnPause);
	
	//metaTableObj.RegisterObjectDirect("IsAlive",(ScriptProcess*)0,&ScriptProcess::ScriptIsAlive);
	//metaTableObj.RegisterObjectDirect("IsDead",(ScriptProcess*)0,&ScriptProcess::ScriptIsDead);
	//metaTableObj.RegisterObjectDirect("IsPaused",(ScriptProcess*)0,&ScriptProcess::ScriptIsPaused);
	//metaTableObj.RegisterObjectDirect("AttachChild",(ScriptProcess*)0,&ScriptProcess::ScriptAttachChild);
}
void ScriptProcess::ScriptAttachChild(LuaObject child)
{
	if (child.IsTable())
	{
		LuaObject obj = child.GetByName("__object");
		if (!obj.IsNil())
		{
			//shared_ptr<Process> pProcess(static_cast<Process*>(obj.GetLightUserData())));
			//assert(pProcess);
			//AttachChild(pProcess);
		}
		else
		{
			//GCC_ERROR("Attempting to attach child with no valid object");
		}
	}
	else
	{
		//GCC_ERROR("Invalid object type passed into \ ScriptProcess::ScriptAttachChild(); type = " + string(child.TypeName));
	}
}
//LuaObject ScriptProcess::CreateFromScript(LuaObject self, LuaObject constructionData, LuaObject originalSubClass)
//{
	//ScriptProcess* pObj = new ScriptProcess();
	//pObj->m_self.AssignNewTable(LuaStateManager::Get()->GetLuaState());
	//if (pObj->VBuildCppDataFromScript(originalSubClass, constructionData))
	//{
		//LuaObject metaTableObj = LuaStateManager::Get()->GetGlobalVars().Lookup(SCRIPT_PROCESS_NAME);
		//assert(!metaTableObj.IsNil());

		//pObj->m_self.SetLightUserData("__object",pObj);
		//pObj->m_self.SetMetaTable(metaTableObj);
	//}
	//else
	//{
		//pObj->m_self.AssignNil(LuaStateManager::Get()->GetLuaState());
		//delete pObj;
	//}
	//return pObj->m_self;
//}
bool ScriptProcess::VBuildCppDataFromScript(LuaObject scriptClass, LuaObject constructionData)
{
	if (scriptClass.IsTable())
	{
		// OnInit()
		LuaObject temp = scriptClass.GetByName("OnInit");
		if (temp.IsFunction())
		{
			m_scriptInitFunction = temp;
		}
		// OnUpdate()
		temp = scriptClass.GetByName("OnUpdate");
		if (temp.IsFunction())
		{
			m_scriptUpdateFunction = temp;
		}

		// OnSuccess()
		temp = scriptClass.GetByName("OnSuccess");
		if (temp.IsFunction())
		{
			m_scriptSuccessFunction = temp;
		}

		// OnFail()
		temp = scriptClass.GetByName("OnFail");
		if (temp.IsFunction())
		{
			m_scriptFailFunction = temp;
		}

		// OnAbort()
		temp = scriptClass.GetByName("OnAbort");
		if (temp.IsFunction())
		{
			m_scriptAbortFunction = temp;
		}
	}
	if (constructionData.IsTable())
	{
		for (LuaTableIterator constructionDataIt(constructionData); constructionDataIt; constructionDataIt.Next())
		{

		}
	}
	return true;
}