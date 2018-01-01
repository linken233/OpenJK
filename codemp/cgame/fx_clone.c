/*
===========================================================================
Copyright (C) 2000 - 2013, Raven Software, Inc.
Copyright (C) 2001 - 2013, Activision, Inc.
Copyright (C) 2013 - 2015, OpenJK contributors

This file is part of the OpenJK source code.

OpenJK is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License version 2 as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see <http://www.gnu.org/licenses/>.
===========================================================================
*/

// Clone Weapon

#include "cg_local.h"

/*
-------------------------
FX_CloneProjectileThink
-------------------------
*/

void FX_CloneProjectileThink( centity_t *cent, const struct weaponInfo_s *weapon )
{
	vec3_t forward;

	if ( VectorNormalize2( cent->currentState.pos.trDelta, forward ) == 0.0f )
	{
		forward[2] = 1.0f;
	}

	trap->FX_PlayEffectID( cgs.effects.cloneShotEffect, cent->lerpOrigin, forward, -1, -1, qfalse );
}

/*
-------------------------
FX_CloneAltFireThink
-------------------------
*/
void FX_CloneAltFireThink( centity_t *cent, const struct weaponInfo_s *weapon )
{
	vec3_t forward;

	if ( VectorNormalize2( cent->currentState.pos.trDelta, forward ) == 0.0f )
	{
		forward[2] = 1.0f;
	}

	trap->FX_PlayEffectID( cgs.effects.cloneShotEffect, cent->lerpOrigin, forward, -1, -1, qfalse );
}

/*
-------------------------
FX_CloneWeaponHitWall
-------------------------
*/
void FX_CloneWeaponHitWall( vec3_t origin, vec3_t normal )
{
	trap->FX_PlayEffectID( cgs.effects.cloneWallImpactEffect, origin, normal, -1, -1, qfalse );
}

/*
-------------------------
FX_CloneWeaponHitPlayer
-------------------------
*/
void FX_CloneWeaponHitPlayer( vec3_t origin, vec3_t normal, qboolean humanoid )
{
	if ( humanoid )
	{
		trap->FX_PlayEffectID( cgs.effects.cloneFleshImpactEffect, origin, normal, -1, -1, qfalse );
	}
	else
	{
		trap->FX_PlayEffectID( cgs.effects.cloneFleshImpactEffect, origin, normal, -1, -1, qfalse );
	}
}
