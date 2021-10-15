#ifndef GL_MESH_H
#define GL_MESH_H

#include <GL/gl.h>
#include <utils/linmath.h>
#include <utils/defines.h>
#include <stddef.h>
#include <stdbool.h>

struct mesh {
	unsigned int vao, vbo, nbo, tbo;

	/* variables from shaders */
	GLint mvp_handle, model_handle, time_handle;
	bool model_presented, time_presented;

	mat4x4 model;
	mat4x4 mvp;
	int program;
	unsigned int texture;
	size_t vertex_count;
};

int mesh_load(struct mesh *m, char *path, GLuint shader_program);
void mesh_update_mvp(struct mesh *m, mat4x4 pv);
void mesh_redraw(struct mesh *m);
void mesh_free(struct mesh *m);

#endif

