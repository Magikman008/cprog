import ctypes

arr_lib = ctypes.CDLL('out/libfuncs.so')
_fill_arr = arr_lib.fill_arr
_fill_arr.argtypes = (ctypes.POINTER(ctypes.c_ulonglong), ctypes.c_int)
_copy_elems = arr_lib.copy_elems
_copy_elems.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_copy_elems.restype = ctypes.POINTER(ctypes.c_int)

def fillarray(size):
    arr = (ctypes.c_ulonglong * size)()
    _fill_arr(arr, size)
    return list(arr)

def copy_elems(arr):
    src_len = ctypes.c_int(len(arr))
    src = (ctypes.c_int * src_len.value)(*arr)
    dst_len = ctypes.c_int(0)

    dst = _copy_elems(None, dst_len, src, src_len)
    temp = []
    for i in range(dst_len.value): temp.append(dst[i])
    return temp
