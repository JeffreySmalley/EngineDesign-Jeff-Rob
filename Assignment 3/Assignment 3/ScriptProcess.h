#include <LuaPlus.h>
#include "LuaStateManager.h"
#include <memory>

using namespace LuaPlus;

class ScriptProcess
{
	unsigned long m_frequency, m_time;
	LuaObject m_scriptInitFunction, m_scriptUpdateFunction;
	LuaObject m_scriptSuccessFunction, m_scriptFailFunction;
	LuaObject m_scriptAbortFunction;
	LuaObject m_self;

public:
	static void RegisterScriptClass();
protected:
	//Process interface

	virtual void VOnInit();
	virtual void VOnUpdate();
	virtual void VOnSuccess();
	virtual void VOnFail();
	virtual void VOnAbort();
private:
	// private helpers
	static void RegisterScriptClassFunctions();
	//static LuaObject CreateFromScript(LuaObject self,LuaObject constructionData,LuaObject originalSubClass);
	virtual bool VBuildCppDataFromScript(LuaObject scriptClass,LuaObject constructionData);

	//bool ScriptIsAlive(){return IsAlive();}
	//bool ScriptIsDead(){return IsDead();}
	//bool ScriptIsPaused(){return IsPaused();}

	// This wrapper function is needed so we can translate a Lua script object to something C++ can use
	void ScriptAttachChild(LuaObject child);

	// Don't allow construction outside of this class
	explicit ScriptProcess();

	// Static create function so lua can instantiate it; only used internally
	static ScriptProcess* Create(const char* scriptName = NULL);
	static void Destroy(ScriptProcess* pObj);
};