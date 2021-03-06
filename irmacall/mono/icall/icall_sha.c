#include "icall.h"

static MonoString* __sha1(MonoArray *content)
{
	worker_t *w = CURRENT;
	app_t *app = (app_t*)w->priv_app;

	int len = mono_array_length(content);
	if (len <= 0)
		return mono_string_new(app->domain, "");

	buf_data_reset(app->buf, len);
	int i = 0;
	unsigned char uc;
	for (; i < len; i++) {
		uc = mono_array_get(content, unsigned char, i);
		buf_append(app->buf, (const char*)&uc, 1);
	}
	char output[41];
	sha1(app->buf->data, app->buf->offset, output);
	//buf_force_reset(app->buf);
	return mono_string_new(app->domain, output);
}

static MonoString* __sha256(MonoArray *content)
{
	worker_t *w = CURRENT;
	app_t *app = (app_t*)w->priv_app;

	int len = mono_array_length(content);
	if (len <= 0)
		return mono_string_new(app->domain, "");

	buf_data_reset(app->buf, len);
	int i = 0;
	unsigned char uc;
	for (; i < len; i++) {
		uc = mono_array_get(content, unsigned char, i);
		buf_append(app->buf, (const char*)&uc, 1);
	}
	char output[65];
	sha256(app->buf->data, app->buf->offset, output);
	//buf_force_reset(app->buf);
	return mono_string_new(app->domain, output);
}

static icall_item_t __items[] = {
	ICALL_ITEM(Sha1, __sha1),
	ICALL_ITEM(Sha256, __sha256),
	ICALL_ITEM_NULL
};

void reg_sha() { regit(__items); }
