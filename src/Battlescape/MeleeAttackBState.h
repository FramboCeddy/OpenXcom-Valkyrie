#pragma once
/*
 * Copyright 2010-2016 OpenXcom Developers.
 *
 * This file is part of OpenXcom.
 *
 * OpenXcom is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenXcom is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenXcom.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "BattleState.h"
#include "Position.h"
#include "TileEngine.h"

namespace OpenXcom
{

class BattlescapeGame;
class BattleUnit;
class BattleItem;
class Tile;

/**
 * A Melee Attack state.
 */
class MeleeAttackBState : public BattleState
{
private:
	BattleUnit *_unit = nullptr, *_target = nullptr;
	BattleItem *_weapon = nullptr, *_ammo = nullptr;
	Position _voxel = TileEngine::invalid;
	int _hitNumber = -1;
	bool _initialized = false;
	bool _reaction = false;
public:
	/// Creates a new MeleeAttackBState class
	MeleeAttackBState(BattlescapeGame *parent, BattleAction action);
	MeleeAttackBState(BattlescapeGame *parent, BattleAction action, int hitNumber);
	/// Cleans up the MeleeAttackBState.
	~MeleeAttackBState();
	/// Initializes the state.
	void init() override;
	/// Runs state functionality every cycle.
	void think() override;
	/// Performs a melee attack
	void performMeleeAttack(int terrainMeleeTilePart = 0);

};

}
