// DisplayControl.cpp : Implementation of CDTDisplayControl
#include "stdafx.h"
#include "DisplayControl.h"
#include ".\displaycontrol.h"


// CDTDisplayControl

STDMETHODIMP CDTDisplayControl::get_Object(IUnknown** pVal)
{
	// TODO: Add your implementation code here
	this->QueryInterface(IID_IUnknown,(void**) pVal);
	return S_OK;
}
