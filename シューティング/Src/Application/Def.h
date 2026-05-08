#pragma once

//スクリーン関連//
#define SCREEN_SIZE_X 1280
#define SCREEN_SIZE_Y 720
#define SCREEN_MAX_X 640
#define SCREEN_MIN_X -640
#define SCREEN_MAX_Y 360
#define SCREEN_MIN_Y -360

//キーチェック関連//
#define key GetAsyncKeyState
#define UP key(VK_UP) & 0x8000
#define DOWN key(VK_DOWN) & 0x8000
#define LEFT key(VK_LEFT) & 0x8000
#define RIGHT key(VK_RIGHT) & 0x8000
#define ENTER key(VK_RETURN) & 0x8000
#define SPACE key(VK_SPACE) & 0x8000
#define SHIFT key(VK_SHIFT) & 0x8000
#define CONTROL key(VK_CONTROL) & 0x8000