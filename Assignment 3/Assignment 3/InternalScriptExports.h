#include "LuaStateManager.h"
#include <memory>
#include "LuaPlus\LuaPlus.h"

using namespace LuaPlus;
using namespace std;
class InternalScriptExports
{
public:
	// Initialization
	static bool Init();
	static void Destroy();
	static bool LoadAndExportScriptResource(const char* scriptResource);
};