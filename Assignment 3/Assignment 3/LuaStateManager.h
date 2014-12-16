#include <LuaPlus.h>
#include "IScriptManager.h"
#include <iostream>

using namespace LuaPlus;
using namespace std;

class LuaStateManager : public IScriptManager
{
	static LuaStateManager* s_pSingleton;
	LuaState* m_pLuaState;
	string m_lastError;
public:
	static bool Create();
	static bool Destroy();
	static LuaStateManager* Get(){assert(s_pSingleton); return s_pSingleton;}
	
	virtual bool VInit() override;
	virtual void VExecuteFile(const char* resource) override;
	virtual void VExecuteString(const char* str) override;

	//LuaObject GetGlobalVars(){};
	LuaState* GetLuaState() const;

	LuaObject CreatePath(const char* pathString, bool toIgnoreLastElement = false);
	//void ConvertVec3ToTable(const Vec3& vec, LuaObject& outLuaTable) const;
	//void ConvertTableToVec3(const LuaObject& luaTable, Vec3& outVec3) const;

private:
	void SetError(int errorNum);
	void ClearStack();

	explicit LuaStateManager();
	virtual ~LuaStateManager();
};