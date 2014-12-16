#include "LuaStateManager.h"
#include <memory>
#include <LuaPlus.h>

using namespace LuaPlus;
using namespace std;
class InternalScriptExports
{
public:
	// Initialization
	static bool Init(){return true;}
	static void Destroy(){}
	static bool LoadAndExecuteScriptResource(const char* scriptResource);
};