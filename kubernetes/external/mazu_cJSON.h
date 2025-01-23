/*
  Copyright (c) 2009-2017 Dave Gamble and mazu_cJSON contributors

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#ifndef mazu_cJSON__h
#define mazu_cJSON__h

#ifdef __cplusplus
extern "C"
{
#endif

/* project version */
#define CJSON_VERSION_MAJOR 1
#define CJSON_VERSION_MINOR 7
#define CJSON_VERSION_PATCH 7

#include <stddef.h>

/* mazu_cJSON Types: */
#define mazu_cJSON_Invalid (0)
#define mazu_cJSON_False  (1 << 0)
#define mazu_cJSON_True   (1 << 1)
#define mazu_cJSON_NULL   (1 << 2)
#define mazu_cJSON_Number (1 << 3)
#define mazu_cJSON_String (1 << 4)
#define mazu_cJSON_Array  (1 << 5)
#define mazu_cJSON_Object (1 << 6)
#define mazu_cJSON_Raw    (1 << 7) /* raw json */

#define mazu_cJSON_IsReference 256
#define mazu_cJSON_StringIsConst 512

/* The mazu_cJSON structure: */
typedef struct mazu_cJSON
{
    /* next/prev allow you to walk array/object chains. Alternatively, use GetArraySize/GetArrayItem/GetObjectItem */
    struct mazu_cJSON *next;
    struct mazu_cJSON *prev;
    /* An array or object item will have a child pointer pointing to a chain of the items in the array/object. */
    struct mazu_cJSON *child;

    /* The type of the item, as above. */
    int type;

    /* The item's string, if type==mazu_cJSON_String  and type == mazu_cJSON_Raw */
    char *valuestring;
    /* writing to valueint is DEPRECATED, use mazu_cJSON_SetNumberValue instead */
    int valueint;
    /* The item's number, if type==mazu_cJSON_Number */
    double valuedouble;

    /* The item's name string, if this item is the child of, or is in the list of subitems of an object. */
    char *string;
} mazu_cJSON;

typedef struct mazu_cJSON_Hooks
{
      void *(*malloc_fn)(size_t sz);
      void (*free_fn)(void *ptr);
} mazu_cJSON_Hooks;

typedef int mazu_cJSON_bool;

#if !defined(__WINDOWS__) && (defined(WIN32) || defined(WIN64) || defined(_MSC_VER) || defined(_WIN32))
#define __WINDOWS__
#endif
#ifdef __WINDOWS__

/* When compiling for windows, we specify a specific calling convention to avoid issues where we are being called from a project with a different default calling convention.  For windows you have 2 define options:

CJSON_HIDE_SYMBOLS - Define this in the case where you don't want to ever dllexport symbols
CJSON_EXPORT_SYMBOLS - Define this on library build when you want to dllexport symbols (default)
CJSON_IMPORT_SYMBOLS - Define this if you want to dllimport symbol

For *nix builds that support visibility attribute, you can define similar behavior by

setting default visibility to hidden by adding
-fvisibility=hidden (for gcc)
or
-xldscope=hidden (for sun cc)
to CFLAGS

then using the CJSON_API_VISIBILITY flag to "export" the same symbols the way CJSON_EXPORT_SYMBOLS does

*/

/* export symbols by default, this is necessary for copy pasting the C and header file */
#if !defined(CJSON_HIDE_SYMBOLS) && !defined(CJSON_IMPORT_SYMBOLS) && !defined(CJSON_EXPORT_SYMBOLS)
#define CJSON_EXPORT_SYMBOLS
#endif

#if defined(CJSON_HIDE_SYMBOLS)
#define CJSON_PUBLIC(type)   type __stdcall
#elif defined(CJSON_EXPORT_SYMBOLS)
#define CJSON_PUBLIC(type)   __declspec(dllexport) type __stdcall
#elif defined(CJSON_IMPORT_SYMBOLS)
#define CJSON_PUBLIC(type)   __declspec(dllimport) type __stdcall
#endif
#else /* !WIN32 */
#if (defined(__GNUC__) || defined(__SUNPRO_CC) || defined (__SUNPRO_C)) && defined(CJSON_API_VISIBILITY)
#define CJSON_PUBLIC(type)   __attribute__((visibility("default"))) type
#else
#define CJSON_PUBLIC(type) type
#endif
#endif

/* Limits how deeply nested arrays/objects can be before mazu_cJSON rejects to parse them.
 * This is to prevent stack overflows. */
#ifndef CJSON_NESTING_LIMIT
#define CJSON_NESTING_LIMIT 1000
#endif

/* returns the version of mazu_cJSON as a string */
CJSON_PUBLIC(const char*) mazu_cJSON_Version(void);

/* Supply malloc, realloc and free functions to mazu_cJSON */
CJSON_PUBLIC(void) mazu_cJSON_InitHooks(mazu_cJSON_Hooks* hooks);

/* Memory Management: the caller is always responsible to free the results from all variants of mazu_cJSON_Parse (with mazu_cJSON_Delete) and mazu_cJSON_Print (with stdlib free, mazu_cJSON_Hooks.free_fn, or mazu_cJSON_free as appropriate). The exception is mazu_cJSON_PrintPreallocated, where the caller has full responsibility of the buffer. */
/* Supply a block of JSON, and this returns a mazu_cJSON object you can interrogate. */
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_Parse(const char *value);
/* ParseWithOpts allows you to require (and check) that the JSON is null terminated, and to retrieve the pointer to the final byte parsed. */
/* If you supply a ptr in return_parse_end and parsing fails, then return_parse_end will contain a pointer to the error so will match mazu_cJSON_GetErrorPtr(). */
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_ParseWithOpts(const char *value, const char **return_parse_end, mazu_cJSON_bool require_null_terminated);

/* Render a mazu_cJSON entity to text for transfer/storage. */
CJSON_PUBLIC(char *) mazu_cJSON_Print(const mazu_cJSON *item);
/* Render a mazu_cJSON entity to text for transfer/storage without any formatting. */
CJSON_PUBLIC(char *) mazu_cJSON_PrintUnformatted(const mazu_cJSON *item);
/* Render a mazu_cJSON entity to text using a buffered strategy. prebuffer is a guess at the final size. guessing well reduces reallocation. fmt=0 gives unformatted, =1 gives formatted */
CJSON_PUBLIC(char *) mazu_cJSON_PrintBuffered(const mazu_cJSON *item, int prebuffer, mazu_cJSON_bool fmt);
/* Render a mazu_cJSON entity to text using a buffer already allocated in memory with given length. Returns 1 on success and 0 on failure. */
/* NOTE: mazu_cJSON is not always 100% accurate in estimating how much memory it will use, so to be safe allocate 5 bytes more than you actually need */
CJSON_PUBLIC(mazu_cJSON_bool) mazu_cJSON_PrintPreallocated(mazu_cJSON *item, char *buffer, const int length, const mazu_cJSON_bool format);
/* Delete a mazu_cJSON entity and all subentities. */
CJSON_PUBLIC(void) mazu_cJSON_Delete(mazu_cJSON *c);

/* Returns the number of items in an array (or object). */
CJSON_PUBLIC(int) mazu_cJSON_GetArraySize(const mazu_cJSON *array);
/* Retrieve item number "index" from array "array". Returns NULL if unsuccessful. */
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_GetArrayItem(const mazu_cJSON *array, int index);
/* Get item "string" from object. Case insensitive. */
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_GetObjectItem(const mazu_cJSON * const object, const char * const string);
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_GetObjectItemCaseSensitive(const mazu_cJSON * const object, const char * const string);
CJSON_PUBLIC(mazu_cJSON_bool) mazu_cJSON_HasObjectItem(const mazu_cJSON *object, const char *string);
/* For analysing failed parses. This returns a pointer to the parse error. You'll probably need to look a few chars back to make sense of it. Defined when mazu_cJSON_Parse() returns 0. 0 when mazu_cJSON_Parse() succeeds. */
CJSON_PUBLIC(const char *) mazu_cJSON_GetErrorPtr(void);

/* Check if the item is a string and return its valuestring */
CJSON_PUBLIC(char *) mazu_cJSON_GetStringValue(mazu_cJSON *item);

/* These functions check the type of an item */
CJSON_PUBLIC(mazu_cJSON_bool) mazu_cJSON_IsInvalid(const mazu_cJSON * const item);
CJSON_PUBLIC(mazu_cJSON_bool) mazu_cJSON_IsFalse(const mazu_cJSON * const item);
CJSON_PUBLIC(mazu_cJSON_bool) mazu_cJSON_IsTrue(const mazu_cJSON * const item);
CJSON_PUBLIC(mazu_cJSON_bool) mazu_cJSON_IsBool(const mazu_cJSON * const item);
CJSON_PUBLIC(mazu_cJSON_bool) mazu_cJSON_IsNull(const mazu_cJSON * const item);
CJSON_PUBLIC(mazu_cJSON_bool) mazu_cJSON_IsNumber(const mazu_cJSON * const item);
CJSON_PUBLIC(mazu_cJSON_bool) mazu_cJSON_IsString(const mazu_cJSON * const item);
CJSON_PUBLIC(mazu_cJSON_bool) mazu_cJSON_IsArray(const mazu_cJSON * const item);
CJSON_PUBLIC(mazu_cJSON_bool) mazu_cJSON_IsObject(const mazu_cJSON * const item);
CJSON_PUBLIC(mazu_cJSON_bool) mazu_cJSON_IsRaw(const mazu_cJSON * const item);

/* These calls create a mazu_cJSON item of the appropriate type. */
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_CreateNull(void);
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_CreateTrue(void);
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_CreateFalse(void);
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_CreateBool(mazu_cJSON_bool boolean);
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_CreateNumber(double num);
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_CreateString(const char *string);
/* raw json */
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_CreateRaw(const char *raw);
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_CreateArray(void);
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_CreateObject(void);

/* Create a string where valuestring references a string so
 * it will not be freed by mazu_cJSON_Delete */
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_CreateStringReference(const char *string);
/* Create an object/array that only references it's elements so
 * they will not be freed by mazu_cJSON_Delete */
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_CreateObjectReference(const mazu_cJSON *child);
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_CreateArrayReference(const mazu_cJSON *child);

/* These utilities create an Array of count items. */
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_CreateIntArray(const int *numbers, int count);
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_CreateFloatArray(const float *numbers, int count);
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_CreateDoubleArray(const double *numbers, int count);
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_CreateStringArray(const char **strings, int count);

/* Append item to the specified array/object. */
CJSON_PUBLIC(void) mazu_cJSON_AddItemToArray(mazu_cJSON *array, mazu_cJSON *item);
CJSON_PUBLIC(void) mazu_cJSON_AddItemToObject(mazu_cJSON *object, const char *string, mazu_cJSON *item);
/* Use this when string is definitely const (i.e. a literal, or as good as), and will definitely survive the mazu_cJSON object.
 * WARNING: When this function was used, make sure to always check that (item->type & mazu_cJSON_StringIsConst) is zero before
 * writing to `item->string` */
CJSON_PUBLIC(void) mazu_cJSON_AddItemToObjectCS(mazu_cJSON *object, const char *string, mazu_cJSON *item);
/* Append reference to item to the specified array/object. Use this when you want to add an existing mazu_cJSON to a new mazu_cJSON, but don't want to corrupt your existing mazu_cJSON. */
CJSON_PUBLIC(void) mazu_cJSON_AddItemReferenceToArray(mazu_cJSON *array, mazu_cJSON *item);
CJSON_PUBLIC(void) mazu_cJSON_AddItemReferenceToObject(mazu_cJSON *object, const char *string, mazu_cJSON *item);

/* Remove/Detach items from Arrays/Objects. */
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_DetachItemViaPointer(mazu_cJSON *parent, mazu_cJSON * const item);
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_DetachItemFromArray(mazu_cJSON *array, int which);
CJSON_PUBLIC(void) mazu_cJSON_DeleteItemFromArray(mazu_cJSON *array, int which);
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_DetachItemFromObject(mazu_cJSON *object, const char *string);
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_DetachItemFromObjectCaseSensitive(mazu_cJSON *object, const char *string);
CJSON_PUBLIC(void) mazu_cJSON_DeleteItemFromObject(mazu_cJSON *object, const char *string);
CJSON_PUBLIC(void) mazu_cJSON_DeleteItemFromObjectCaseSensitive(mazu_cJSON *object, const char *string);

/* Update array items. */
CJSON_PUBLIC(void) mazu_cJSON_InsertItemInArray(mazu_cJSON *array, int which, mazu_cJSON *newitem); /* Shifts pre-existing items to the right. */
CJSON_PUBLIC(mazu_cJSON_bool) mazu_cJSON_ReplaceItemViaPointer(mazu_cJSON * const parent, mazu_cJSON * const item, mazu_cJSON * replacement);
CJSON_PUBLIC(void) mazu_cJSON_ReplaceItemInArray(mazu_cJSON *array, int which, mazu_cJSON *newitem);
CJSON_PUBLIC(void) mazu_cJSON_ReplaceItemInObject(mazu_cJSON *object,const char *string,mazu_cJSON *newitem);
CJSON_PUBLIC(void) mazu_cJSON_ReplaceItemInObjectCaseSensitive(mazu_cJSON *object,const char *string,mazu_cJSON *newitem);

/* Duplicate a mazu_cJSON item */
CJSON_PUBLIC(mazu_cJSON *) mazu_cJSON_Duplicate(const mazu_cJSON *item, mazu_cJSON_bool recurse);
/* Duplicate will create a new, identical mazu_cJSON item to the one you pass, in new memory that will
need to be released. With recurse!=0, it will duplicate any children connected to the item.
The item->next and ->prev pointers are always zero on return from Duplicate. */
/* Recursively compare two mazu_cJSON items for equality. If either a or b is NULL or invalid, they will be considered unequal.
 * case_sensitive determines if object keys are treated case sensitive (1) or case insensitive (0) */
CJSON_PUBLIC(mazu_cJSON_bool) mazu_cJSON_Compare(const mazu_cJSON * const a, const mazu_cJSON * const b, const mazu_cJSON_bool case_sensitive);


CJSON_PUBLIC(void) mazu_cJSON_Minify(char *json);

/* Helper functions for creating and adding items to an object at the same time.
 * They return the added item or NULL on failure. */
CJSON_PUBLIC(mazu_cJSON*) mazu_cJSON_AddNullToObject(mazu_cJSON * const object, const char * const name);
CJSON_PUBLIC(mazu_cJSON*) mazu_cJSON_AddTrueToObject(mazu_cJSON * const object, const char * const name);
CJSON_PUBLIC(mazu_cJSON*) mazu_cJSON_AddFalseToObject(mazu_cJSON * const object, const char * const name);
CJSON_PUBLIC(mazu_cJSON*) mazu_cJSON_AddBoolToObject(mazu_cJSON * const object, const char * const name, const mazu_cJSON_bool boolean);
CJSON_PUBLIC(mazu_cJSON*) mazu_cJSON_AddNumberToObject(mazu_cJSON * const object, const char * const name, const double number);
CJSON_PUBLIC(mazu_cJSON*) mazu_cJSON_AddStringToObject(mazu_cJSON * const object, const char * const name, const char * const string);
CJSON_PUBLIC(mazu_cJSON*) mazu_cJSON_AddRawToObject(mazu_cJSON * const object, const char * const name, const char * const raw);
CJSON_PUBLIC(mazu_cJSON*) mazu_cJSON_AddObjectToObject(mazu_cJSON * const object, const char * const name);
CJSON_PUBLIC(mazu_cJSON*) mazu_cJSON_AddArrayToObject(mazu_cJSON * const object, const char * const name);

/* When assigning an integer value, it needs to be propagated to valuedouble too. */
#define mazu_cJSON_SetIntValue(object, number) ((object) ? (object)->valueint = (object)->valuedouble = (number) : (number))
/* helper for the mazu_cJSON_SetNumberValue macro */
CJSON_PUBLIC(double) mazu_cJSON_SetNumberHelper(mazu_cJSON *object, double number);
#define mazu_cJSON_SetNumberValue(object, number) ((object != NULL) ? mazu_cJSON_SetNumberHelper(object, (double)number) : (number))

/* Macro for iterating over an array or object */
#define mazu_cJSON_ArrayForEach(element, array) for(element = (array != NULL) ? (array)->child : NULL; element != NULL; element = element->next)

/* malloc/free objects using the malloc/free functions that have been set with mazu_cJSON_InitHooks */
CJSON_PUBLIC(void *) mazu_cJSON_malloc(size_t size);
CJSON_PUBLIC(void) mazu_cJSON_free(void *object);

#ifdef __cplusplus
}
#endif

#endif
