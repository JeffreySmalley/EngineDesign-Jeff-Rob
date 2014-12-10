#include "LuaPlus\LuaPlus.h"
#include "IScriptManager.h"

using namespace LuaPlus;

class LuaStateManager : public IScriptManager
{
public:
	static bool Create();
	static bool Destroy();
	//static LuaStateManager* Get(){GCC_ASSERT(s_pSingleton); return s_pSingleton;}
	
	virtual bool VInit() override;
	virtual void VExecuteFile(const char* resource) override;
	virtual void VExecuteString(const char* str) override;

	LuaObject GetGlobalVars();
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