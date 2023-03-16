/// @file list.h
/// @brief List interfaces

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

struct ncsdk_List;
typedef struct ncsdk_List ncsdk_List;

/// @brief Creates a new list.
/// @param type The type of the elements in the list
/// @return The new list
#define ncsdk_List_New(type) ncsdk_List_NewWithElementSize(sizeof(type))

/// @brief Creates a new list with specified element size.
/// @param element_size The size of each element in the list
/// @return The new list
ncsdk_List* ncsdk_List_NewWithElementSize(size_t element_size);

/// @brief Destroys an list.
/// @param self A pointer to the list
void ncsdk_List_Delete(ncsdk_List** self);

/// @brief Accesses specified element with bounds checking.
/// @param type The type of the elements in the list
/// @param self The list
/// @param index The index of the element to access
/// @return The element at specified position. If index is out of range, the
/// value is NULL.
#define ncsdk_List_At(type) (type*)ncsdk_List_AtWithoutType

void* ncsdk_List_AtWithoutType(ncsdk_List* self, size_t index);

/// @brief Clears the list.
/// @param self The list
void ncsdk_List_Clear(ncsdk_List* self);

#define ncsdk_List_PushBack(type) 

void ncsdk_List_PushBackWithoutType(ncsdk_List* self, const void* element, size_t element_size);

/// @brief Returns the number of elements in the list.
/// @param self The list
/// @return The number of elements in the list
size_t ncsdk_List_Size(ncsdk_List* self);

#ifdef __cplusplus
}
#endif