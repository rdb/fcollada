/*
	Copyright (C) 2005-2007 Feeling Software Inc.
	Portions of the code are:
	Copyright (C) 2005-2007 Sony Computer Entertainment America

	MIT License: http://www.opensource.org/licenses/mit-license.php
*/

#include "StdAfx.h"
#include "FUParameterizable.h"
#include "FUParameter.h"

extern void TrickLinkerFUParameter()
{
	// Animatables
	extern void TrickLinkerFCDParameterAnimatable();
	TrickLinkerFCDParameterAnimatable();
}
