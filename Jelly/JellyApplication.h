#pragma once
namespace Jelly
{
	class JellyApplication
	{
	public:
		void Run();
		virtual void Initialize();
		virtual void Update();
		virtual void Shutdown();

	private:
		bool ShouldContinue{ true };

	};
}