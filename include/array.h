/// @file array.h
/// @brief Array interfaces

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

struct ncsdk_Array;
typedef struct ncsdk_Array ncsdk_Array;

/// @brief Creates a new array.
/// @param capacity The initial capacity of the array
/// @return The new array
#define ncsdk_Array_New(type, capacity) ncsdk_Array_NewWithElementSize(sizeof(type), capacity)

/// @brief Creates a new array with specified element size.
/// @param element_size The size of each element in the array
/// @param capacity The initial capacity of the array
/// @return The new array
ncsdk_Array* ncsdk_Array_NewWithElementSize(size_t element_size, size_t capacity);

/// @brief Destroys an array.
/// @param self The array
void ncsdk_Array_Delete(ncsdk_Array* self);

/// @brief Accesses specified element with bounds checking.
/// @param self The array
/// @param index The index of the element to access
/// @return The element at specified position. If index is out of range, the
/// value is NULL.
void* ncsdk_Array_At(ncsdk_Array* self, size_t index);

/// @brief Fills the array with the specified value.
/// @param self The array
/// @param value The value to fill the array with
void ncsdk_Array_Fill(ncsdk_Array* self, void* value);

/// @brief Returns the number of elements in the array.
/// @param self The array
/// @return The number of elements in the array
size_t ncsdk_Array_Size(ncsdk_Array* self);

#ifdef __cplusplus
}
#endif