/***********************************************************************
*  This code is part of ...
*
*  Copyright (C) 2017 Heinrich Schuchardt (xypron.glpk@gmx.de)
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
***********************************************************************/

/**
 * @file ncpu.c
 * @brief Gets number of cpus.
 *
 */

#include "thread.h"

/**
 * @brief Gets number of cpus.
 */
#ifdef __WOE__

#include <windows.h>
#pragma comment(lib, "user32.lib")

int ncpu() {
	SYSTEM_INFO info;

	GetSystemInfo(&info);
	return info.dwNumberOfProcessors
}
#else

#include <unistd.h>

int ncpu() {
  return sysconf(_SC_NPROCESSORS_ONLN);
}
#endif
