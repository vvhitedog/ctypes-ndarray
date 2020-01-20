#include "NdArray.h"

//////////////////////////////////////////////////////////////////////////////////////////////
//
//            Common Ctypes NdArray Functionality
//
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

void inline ndarray_set_size(NdArray* arr, uint64_t dim0, uint64_t dim1) {
	arr->m_ndim = 2;
	arr->m_shape[0] = dim0;
	arr->m_shape[1] = dim1;
}

void inline ndarray_set_size(NdArray* arr, uint64_t dim0, uint64_t dim1, uint64_t dim2) {
	arr->m_ndim = 3;
	arr->m_shape[0] = dim0;
	arr->m_shape[1] = dim1;
	arr->m_shape[2] = dim2;
}

void inline ndarray_set_size(NdArray* arr, int ndim, uint64_t* dims) {
	arr->m_ndim = ndim;
	for ( int idim = 0; idim < ndim; ++idim ) {
		uint64_t dim = dims[idim];
		arr->m_shape[idim] = dim;
	}
}


void inline ndarray_alloc(NdArray* arr) {
	size_t nelem = 1;
	for (int i = 0; i < arr->m_ndim; ++i) {
		nelem *= arr->m_shape[i];
	}
	arr->m_data = arr->m_alloc(arr->m_sizeofdtype * nelem);
}

//////////////////////////////////////////////////////////////////////////////////////////////
