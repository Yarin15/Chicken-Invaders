#pragma once
#include <SFML/Graphics.hpp>

// Game status enum
enum gameStatus { CONTINUE_T, GAME_OVER_T, GAME_SUCCESS_T, PAUSE_T };

// Dynamic objects enum
enum direction { RIGHT_T, DOWN_T, LEFT_T, UP_T, NONE_T, SPACE_T, };

enum GameMenuButtons { PLAY_GAME_T, TOGGLE_SOUND_T, INSTRUCTIONS_T, SCORES_T, EXIT_T };

enum Menus {GAME_MENU_T, PAUSE_MENU_T};

enum PauseMenuButtons {RESUME_T, EXIT_GAME_T};

enum setAttack {DECREASE_T, INCREASE_T};

// These are the chicken sprite sizes
const int CHIC_SPR_X = 80;
const int CHIC_SPR_Y = 98;
const int CHICKEN_SRPITE = 490;

// These are the coin sprite sizes
const int COIN_SPR_X = 25;
const int COIN_SPR_Y = 30;
const int COIN_SPRITE = 210;

// The space ship size
const int SHIP_SIZE = 66;

// These consts are for the user score.
const int SCORE_CHICKEN_KILL = 10;
const int SCORE_CHICKEN_LEG = 30;
const int SCORE_COIN = 60;
const int SCORE_PRIZE = 10;
const int SCORE_EGG = -200;
const int SCORE_CHICKEN_HIT = -600;
const int INCREASE_GOAL = 2500;
