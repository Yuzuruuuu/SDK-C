#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct ncsdk_ItemStack {
  int type_id;
  int count;
};

struct ncsdk_ItemStack;

struct ncsdk_ItemStack* ncsdk_ItemStack_New(int type_id, int count);

void ncsdk_ItemStack_Delete(struct ncsdk_ItemStack* self);

int ncsdk_ItemStack_GetCount(const struct ncsdk_ItemStack* self);

int ncsdk_ItemStack_GetTypeId(const struct ncsdk_ItemStack* self);

#ifdef __cplusplus
}
#endif
