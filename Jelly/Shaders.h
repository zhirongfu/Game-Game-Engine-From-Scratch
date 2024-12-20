#pragma once

#include "pch.h"
#include "JellyUtilities.h"
#include "ShadersImpl.h"

namespace Jelly
{
	class  JELLY_API Shaders
	{
	public:
		Shaders();
		Shaders(const std::string& vertexSFile, const std::string& fragmentSFile);
		void LoadShaders(const std::string& vertexSFile, const std::string& fragmentSFile);

		void Bind();
		void SetIntUniform(const std::string& uniformName, const std::vector<int>& values);
		void SetIntUniform(const std::string& uniformName, int value);

	private:
		std::unique_ptr<ShadersImpl> implementation;

	};

}
