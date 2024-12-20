#pragma once

#ifdef JELLY_GLFW

	#define JELLY_KEY_SPACE              32
	#define JELLY_KEY_APOSTROPHE         39  /* ' */
	#define JELLY_KEY_COMMA              44  /* , */
	#define JELLY_KEY_MINUS              45  /* - */
	#define JELLY_KEY_PERIOD             46  /* . */
	#define JELLY_KEY_SLASH              47  /* / */
	#define JELLY_KEY_0                  48
	#define JELLY_KEY_1                  49
	#define JELLY_KEY_2                  50
	#define JELLY_KEY_3                  51
	#define JELLY_KEY_4                  52
	#define JELLY_KEY_5                  53
	#define JELLY_KEY_6                  54
	#define JELLY_KEY_7                  55
	#define JELLY_KEY_8                  56
	#define JELLY_KEY_9                  57
	#define JELLY_KEY_SEMICOLON          59  /* ; */
	#define JELLY_KEY_EQUAL              61  /* = */
	#define JELLY_KEY_A                  65
	#define JELLY_KEY_B                  66
	#define JELLY_KEY_C                  67
	#define JELLY_KEY_D                  68
	#define JELLY_KEY_E                  69
	#define JELLY_KEY_F                  70
	#define JELLY_KEY_G                  71
	#define JELLY_KEY_H                  72
	#define JELLY_KEY_I                  73
	#define JELLY_KEY_J                  74
	#define JELLY_KEY_K                  75
	#define JELLY_KEY_L                  76
	#define JELLY_KEY_M                  77
	#define JELLY_KEY_N                  78
	#define JELLY_KEY_O                  79
	#define JELLY_KEY_P                  80
	#define JELLY_KEY_Q                  81
	#define JELLY_KEY_R                  82
	#define JELLY_KEY_S                  83
	#define JELLY_KEY_T                  84
	#define JELLY_KEY_U                  85
	#define JELLY_KEY_V                  86
	#define JELLY_KEY_W                  87
	#define JELLY_KEY_X                  88
	#define JELLY_KEY_Y                  89
	#define JELLY_KEY_Z                  90
	#define JELLY_KEY_LEFT_BRACKET       91  /* [ */
	#define JELLY_KEY_BACKSLASH          92  /* \ */
	#define JELLY_KEY_RIGHT_BRACKET      93  /* ] */
	#define JELLY_KEY_GRAVE_ACCENT       96  /* ` */
	#define JELLY_KEY_WORLD_1            161 /* non-US #1 */
	#define JELLY_KEY_WORLD_2            162 /* non-US #2 */

	/* Function keys */
	#define JELLY_KEY_ESCAPE             256
	#define JELLY_KEY_ENTER              257
	#define JELLY_KEY_TAB                258
	#define JELLY_KEY_BACKSPACE          259
	#define JELLY_KEY_INSERT             260
	#define JELLY_KEY_DELETE             261
	#define JELLY_KEY_RIGHT              262
	#define JELLY_KEY_LEFT               263
	#define JELLY_KEY_DOWN               264
	#define JELLY_KEY_UP                 265
	#define JELLY_KEY_PAGE_UP            266
	#define JELLY_KEY_PAGE_DOWN          267
	#define JELLY_KEY_HOME               268
	#define JELLY_KEY_END                269
	#define JELLY_KEY_CAPS_LOCK          280
	#define JELLY_KEY_SCROLL_LOCK        281
	#define JELLY_KEY_NUM_LOCK           282
	#define JELLY_KEY_PRINT_SCREEN       283
	#define JELLY_KEY_PAUSE              284
	#define JELLY_KEY_F1                 290
	#define JELLY_KEY_F2                 291
	#define JELLY_KEY_F3                 292
	#define JELLY_KEY_F4                 293
	#define JELLY_KEY_F5                 294
	#define JELLY_KEY_F6                 295
	#define JELLY_KEY_F7                 296
	#define JELLY_KEY_F8                 297
	#define JELLY_KEY_F9                 298
	#define JELLY_KEY_F10                299
	#define JELLY_KEY_F11                300
	#define JELLY_KEY_F12                301
	#define JELLY_KEY_F13                302
	#define JELLY_KEY_F14                303
	#define JELLY_KEY_F15                304
	#define JELLY_KEY_F16                305
	#define JELLY_KEY_F17                306
	#define JELLY_KEY_F18                307
	#define JELLY_KEY_F19                308
	#define JELLY_KEY_F20                309
	#define JELLY_KEY_F21                310
	#define JELLY_KEY_F22                311
	#define JELLY_KEY_F23                312
	#define JELLY_KEY_F24                313
	#define JELLY_KEY_F25                314
	#define JELLY_KEY_KP_0               320
	#define JELLY_KEY_KP_1               321
	#define JELLY_KEY_KP_2               322
	#define JELLY_KEY_KP_3               323
	#define JELLY_KEY_KP_4               324
	#define JELLY_KEY_KP_5               325
	#define JELLY_KEY_KP_6               326
	#define JELLY_KEY_KP_7               327
	#define JELLY_KEY_KP_8               328
	#define JELLY_KEY_KP_9               329
	#define JELLY_KEY_KP_DECIMAL         330
	#define JELLY_KEY_KP_DIVIDE          331
	#define JELLY_KEY_KP_MULTIPLY        332
	#define JELLY_KEY_KP_SUBTRACT        333
	#define JELLY_KEY_KP_ADD             334
	#define JELLY_KEY_KP_ENTER           335
	#define JELLY_KEY_KP_EQUAL           336
	#define JELLY_KEY_LEFT_SHIFT         340
	#define JELLY_KEY_LEFT_CONTROL       341
	#define JELLY_KEY_LEFT_ALT           342
	#define JELLY_KEY_LEFT_SUPER         343
	#define JELLY_KEY_RIGHT_SHIFT        344
	#define JELLY_KEY_RIGHT_CONTROL      345
	#define JELLY_KEY_RIGHT_ALT          346
	#define JELLY_KEY_RIGHT_SUPER        347
	#define JELLY_KEY_MENU               348

#else
	#only_GLFW_is_supported_for_now
#endif