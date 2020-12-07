#pragma once
#include <glad/glad.h>
#include <vector>
#include "buffer.h"

namespace algo { namespace graphics {

	class VertexArray
	{
	private:
		GLuint mArrayID;
		std::vector<Buffer*> mBuffers;
	public:
		VertexArray();
		~VertexArray();

		void addBuffer(Buffer* buffer, int index, int count, int offset);
		void bind() const;
		void unbind() const;
	};
} }

