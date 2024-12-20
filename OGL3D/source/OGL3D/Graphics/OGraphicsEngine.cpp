#include <OGL3D/Graphics/OGraphicsEngine.h>
#include <OGL3D/Graphics/OVertexArrayObject.h>
#include <glad/glad.h>


OVertexArrayObjectPtr OGraphicsEngine::createVertexArrayObject(const OVertexBufferData& data)
{

	return std::make_shared<OVertexArrayObject>(data);
}


void OGraphicsEngine::clear(const OVec4& color)
{
	glClearColor(color.x, color.y, color.z, color.w);
	glClear(GL_COLOR_BUFFER_BIT);
}

void OGraphicsEngine::setViewport(const ORect& size)
{
	glViewport(size.left, size.top, size.width, size.height);

}

void OGraphicsEngine::setVertexArrayObject(const OVertexArrayObjectPtr& vao)
{
	glBindVertexArray(vao->getId());
}

void OGraphicsEngine::drawTriangles(ui32 vertexCount, ui32 offset)
{
	glDrawArrays(GL_TRIANGLES, offset, vertexCount);
}

