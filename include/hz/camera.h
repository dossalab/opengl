#ifndef HZ_CAMERA_H
#define HZ_CAMERA_H

#include <hz/types.h>
#include <GLFW/glfw3.h>

struct hz_camera;

struct hz_camera_proto {
	void (*init)(struct hz_camera *);
	void (*update)(struct hz_camera *, GLFWwindow *, float);
};

struct hz_camera {
	hz_mat4x4 view, projection, vp;
	const struct hz_camera_proto *proto;
};

void hz_camera_update_perspective(struct hz_camera *c, float aspect);
void hz_camera_update(struct hz_camera *c, GLFWwindow *window, float time_spent);
void hz_camera_init(struct hz_camera *c, const struct hz_camera_proto *proto);

#endif
