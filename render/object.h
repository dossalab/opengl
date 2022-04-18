#ifndef RENDER_OBJECT_H
#define RENDER_OBJECT_H

#include <GL/gl.h>
#include <utils/3rdparty/linmath/linmath.h>
#include "scene.h"

struct object;

struct object_proto {
	void (*draw)(struct object *o);
	void (*update_mvp)(struct object *o, mat4x4 vp);
	void (*free)(struct object *o);
	bool (*init)(struct object *o);
};

struct object {
	GLuint vao;
	GLuint program;
	struct list_item scene_node;
	const struct object_proto *proto;
};

void object_draw(struct object *o);
void object_update_mvp(struct object *o, mat4x4 vp);
void object_free(struct object *o);
bool object_init(struct object *o, GLuint program, const struct object_proto *proto);

#endif
