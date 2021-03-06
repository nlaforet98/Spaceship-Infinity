#ifndef SPACESHIP_H
#define SPACESHIP_H

/*
 *        DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *                    Version 2, December 2004
 *
 * Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>
 *
 * Everyone is permitted to copy and distribute verbatim or modified
 * copies of this license document, and changing it is allowed as long
 * as the name is changed.
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 *  0. You just DO WHAT THE FUCK YOU WANT TO.
 */

#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

#include "point.h"
#include "point_list.h"
#include "terrain.h"
#include "options.h"

////////////////////////////////////////////////////////////////////////////////
// types
////////////////////////////////////////////////////////////////////////////////

typedef struct game game;

////////////////////////////////////////////////////////////////////////////////
// init./destroy etc.
////////////////////////////////////////////////////////////////////////////////

game* game_init(spaceship_options o);
void game_destroy(game* j);

////////////////////////////////////////////////////////////////////////////////
// getters
////////////////////////////////////////////////////////////////////////////////

bool game_ship_is_alive(const game* j);
double game_get_delay(const game* j);
double game_get_elapsed_time(const game* j);
double game_get_constant_delay(const game* g);
intmax_t game_get_score(const game* g);
spaceship_options game_get_options(const game* g);
terrain* game_get_map(const game* g);
point game_get_ship_position(const game* g);
size_t game_get_max_ammo(const game* g);
size_t game_get_fired_bullets(const game* g);
intmax_t game_get_lives(const game* g);
void game_set_lives(game* const g, const intmax_t l);
point_list* game_get_bullets(const game* g);
int game_get_last_input(const game* g);
void game_reset_bonus(game* const g);
void game_reset_constant_delay(game* const g);
void game_reset_ship(game* const g);
bool game_get_laser(const game* const g);

////////////////////////////////////////////////////////////////////////////////
// setters / modifiers
////////////////////////////////////////////////////////////////////////////////

void game_pause_process_input(game* j, int key);
void game_process_input(game* j, int key);
void game_set_delay(game* j, double delay);
void game_set_elapsed_time(game* j, double t);
void game_compute_turn(game* j);
bool game_check_hit(const game* g);
void game_was_hit(game* const g);
void game_pause(game* const g, int p);
bool game_is_paused(const game* const g);
int game_pause_menu(const game* const g);
void game_reset(game* const g);
void clear_terrain(game* const g);
void game_reset_ammo(game* const g);
void game_change_friendly(game* const g);
void game_change_tail(game* const g);
void game_set_laser(game* const g, const bool active);

#endif
