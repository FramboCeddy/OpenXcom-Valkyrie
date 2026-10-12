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
#include "../Engine/InteractiveSurface.h"
#include "Position.h"

namespace OpenXcom
{

class Game;
class Camera;
class SavedBattleGame;
class SurfaceSet;

/**
 * MiniMapView is the class used to display the map in the MiniMapState.
 */
class MiniMapView : public InteractiveSurface
{
	Game * _game;
	Camera * _camera;
	SavedBattleGame * _battleGame;
	int _maxShade;
	int _frame = 0;
	SurfaceSet * _set;
	int _emptySpaceIndex;
	// these two are required for right-button scrolling on the minimap
	bool _isMouseScrolling = false;
	bool _isMouseScrolled = false;
	int _xBeforeMouseScrolling = 0;
	int _yBeforeMouseScrolling = 0;
	int _mouseScrollX = 0;
	int _mouseScrollY = 0;
	Position _posBeforeMouseScrolling, _cursorPosition;
	Uint32 _mouseScrollingStartTime = 0;
	int _totalMouseMoveX = 0;
	int _totalMouseMoveY = 0;
	bool _mouseMovedOverThreshold = false;
	/// Handles pressing on the MiniMap.
	void mousePress(Action *action, State *state) override;
	/// Handles clicking on the MiniMap.
	void mouseClick(Action *action, State *state) override;
	/// Handles moving mouse over the MiniMap.
	void mouseOver(Action *action, State *state) override;
	/// Handles moving the mouse into the MiniMap surface.
	void mouseIn(Action *action, State *state) override;
public:
	/// Creates the MiniMapView.
	MiniMapView(int w, int h, int x, int y, Game * game, Camera * camera, SavedBattleGame * battleGame, int maxShade);
	/// Draws the minimap.
	void draw() override;
	/// Changes the displayed minimap level.
	int up();
	/// Changes the displayed minimap level.
	int down();
	/// Updates the minimap animation.
	void animate();
	void stopScrolling(Action *action);
};

}
