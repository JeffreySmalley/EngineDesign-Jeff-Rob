class IGUIElement
{
public:
	virtual void Init(){}
	virtual void Update(float dt)=0;
	virtual void Shutdown(){}
	virtual void Render(){}
};