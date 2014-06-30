/*
===========================================================================
Daemon BSD Source Code
Copyright (c) 2013-2014, Daemon Developers
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
* Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
* Neither the name of the <organization> nor the
names of its contributors may be used to endorse or promote products
derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
===========================================================================
*/

#ifndef PHYSICS_PHYSICS_H_
#define PHYSICS_PHYSICS_H_

#include "cm_public.h"

namespace Physics {

	void Init();
	void Shutdown();
	void Load(const void* bspBuffer);

	struct TraceResults {
		float fraction;
		vec3_t endpos;
		vec3_t normal;
		vec3_t debug1;
		vec3_t debug2;
		vec3_t debug3;
		vec3_t debug4;
	};

	//float Trace(const vec3_t from, const vec3_t to);
	void BoxTrace(const vec3_t from, const vec3_t to, const vec3_t mins, const vec3_t maxs, int brushMask, TraceResults& results);
	void TempBox(const vec3_t mins, const vec3_t maxs);

	enum COLLISIONFLAGS {
		COLLISION_SOLID = 0x1,
		COLLISION_BODY = 0x2,
	};
}

#endif //PHYSICS_PHYSICS_H_

