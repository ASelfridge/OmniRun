#pragma once

#define LEVEL_WIDTH 1280
#define LEVEL_HEIGHT 720
#define NUM_LEVELS 1
#define LEVEL_TIME 180
#define GRAVITY 9.8
#define MAX_DAMAGE 5
#define MAX_DISTANCE 30
#define MAX_SPEED 6
#define RUNNER_FRAMES 25
#define NUM_ANIM 4
#define MAX_AP 5
#define TIME_ADJUST 600
#define NUM_BUTTONS 2

#include "stdio.h"
#include "iostream"
using namespace std;

#include "ofMain.h"
#include "GameObject.h"
#include "Runner.h"
#include "Fireball.h"
#include "AbilityButton.h"
#include "UI.h"
#include "Enemy.h"
#include "Omnipotent.h"
#include "Physics.h"
#include "ofApp.h"
