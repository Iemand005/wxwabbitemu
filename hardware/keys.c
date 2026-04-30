#include "stdafx.h"
#include "keys.h"
#if WXVER
#include <wx/wx.h>
#endif

keyprog_t defaultkeys[256] = {
#ifdef _WINDOWS
	{ 'A' , 5 , 6 },
	{ 'B' , 4 , 6 },
	{ 'C' , 3 , 6 },
	{ 'D' , 5 , 5 },
	{ 'E' , 4 , 5 },
	{ 'F' , 3 , 5 },
	{ 'G' , 2 , 5 },
	{ 'H' , 1 , 5 },
	{ 'I' , 5 , 4 },
	{ 'J' , 4 , 4 },
	{ 'K' , 3 , 4 },
	{ 'L' , 2 , 4 },
	{ 'M' , 1 , 4 },
	{ 'N' , 5 , 3 },
	{ 'O' , 4 , 3 },
	{ 'P' , 3 , 3 },
	{ 'Q' , 2 , 3 },
	{ 'R' , 1 , 3 },
	{ 'S' , 5 , 2 },
	{ 'T' , 4 , 2 },
	{ 'U' , 3 , 2 },
	{ 'V' , 2 , 2 },
	{ 'W' , 1 , 2 },
	{ 'X' , 5 , 1 },
	{ 'Y' , 4 , 1 },
	{ 'Z' , 3 , 1 },
	{ ' ' , 4 , 0 },
	{ VK_DOWN , 0 , 0 },
	{ VK_LEFT , 0 , 1 },
	{ VK_RIGHT , 0 , 2 },
	{ VK_UP , 0 , 3 },
	{ '0' , 4 , 0 },
	{ '1' , 4 , 1 },
	{ '2' , 3 , 1 },
	{ '3' , 2 , 1 },
	{ '4' , 4 , 2 },
	{ '5' , 3 , 2 },
	{ '6' , 2 , 2 },
	{ '7' , 4 , 3 },
	{ '8' , 3 , 3 },
	{ '9' , 2 , 3 },
	{ VK_RETURN , 1 , 0 },
	{ VKF_PERIOD , 3 , 0 },
	{ VKF_COMMA , 4 , 4 },
	{ VK_ADD , 1 , 1 },
	{ VK_SUBTRACT , 1 , 2 },
	{ VK_MULTIPLY , 1 , 3 },
	{ VK_DIVIDE , 1 , 4 },
	{ VKF_LBRACKET , 3 , 4 },
	{ VKF_RBRACKET , 2 , 4 },
	{ VK_F1 , 6 , 4 },
	{ VK_F2 , 6 , 3 },
	{ VK_F3 , 6 , 2 },
	{ VK_F4 , 6 , 1 },
	{ VK_F5 , 6 , 0 },
	{ VK_ESCAPE , 6 , 6 },
	{ VK_LSHIFT , 6 , 5 },			// l shift
	{ VK_CONTROL, 5 , 7 },			// l control
	{ VK_RSHIFT , 1 , 6 },
	{ VKF_MINUS , 2 , 0 },
	{ VKF_EQUAL , 4 , 7 },
	{ VK_PRIOR , 4 , 6 },
	{ VK_NEXT , 3 , 6 },
	{ VK_INSERT , 2 , 6 },
	{ VK_DELETE , 6 , 7 },
	{ VK_HOME , 5 , 6 },
	{ VK_END , 3 , 7 },
#ifndef _DEBUG
	{ VK_NUMPAD0 , 4 , 0 },
#endif
	{ VK_NUMPAD1 , 4 , 1 },
	{ VK_NUMPAD2 , 3 , 1 },
	{ VK_NUMPAD3 , 2 , 1 },
	{ VK_NUMPAD4 , 4 , 2 },
	{ VK_NUMPAD5 , 3 , 2 },
	{ VK_NUMPAD6 , 2 , 2 },
	{ VK_NUMPAD7 , 4 , 3 },
	{ VK_NUMPAD8 , 3 , 3 },
	{ VK_NUMPAD9 , 2 , 3 },
	{ VK_DECIMAL , 3 , 0 },
	{ VK_OEM_2, 2, 0 },
//so much better than harcoding the changes :P
#ifdef _DEBUG
	{ VK_NUMPAD0, KEYGROUP_ON, KEYBIT_ON},
#else
	{ VK_F12, KEYGROUP_ON, KEYBIT_ON},
#endif
#endif
	{ -1, -1, -1},
};
keyprog_t keysti86[256] = {
#ifdef _WINDOWS
	{ 'A' , 5 , 5 },
	{ 'B' , 4 , 5 },
	{ 'C' , 3 , 5 },
	{ 'D' , 2 , 5 },
	{ 'E' , 1 , 5 },
	{ 'F' , 5 , 4 },
	{ 'G' , 4 , 4 },
	{ 'H' , 3 , 4 },
	{ 'I' , 2 , 4 },
	{ 'J' , 1 , 4 },
	{ 'K' , 5 , 3 },
	{ 'L' , 4 , 3 },
	{ 'M' , 3 , 3 },
	{ 'N' , 2 , 3 },
	{ 'O' , 1 , 3 },
	{ 'P' , 5 , 2 },
	{ 'Q' , 4 , 2 },
	{ 'R' , 3 , 2 },
	{ 'S' , 2 , 2 },
	{ 'T' , 1 , 2 },
	{ 'U' , 4 , 1 },
	{ 'V' , 3 , 1 },
	{ 'W' , 2 , 1 },
	{ 'X' , 1 , 1 },
	{ 'Y' , 4 , 0 },
	{ 'Z' , 3 , 0 },
	{ ' ' , 2 , 0 },
	{ VK_DOWN , 0 , 0 },
	{ VK_LEFT , 0 , 1 },
	{ VK_RIGHT , 0 , 2 },
	{ VK_UP , 0 , 3 },
	{ '0' , 4 , 0 },
	{ '1' , 4 , 1 },
	{ '2' , 3 , 1 },
	{ '3' , 2 , 1 },
	{ '4' , 4 , 2 },
	{ '5' , 3 , 2 },
	{ '6' , 2 , 2 },
	{ '7' , 4 , 3 },
	{ '8' , 3 , 3 },
	{ '9' , 2 , 3 },
	{ VK_RETURN , 1 , 0 },
	{ VKF_PERIOD , 3 , 0 },
	{ VKF_COMMA , 4 , 4 },
	{ VK_ADD , 1 , 1 },
	{ VK_SUBTRACT , 1 , 2 },
	{ VK_MULTIPLY , 1 , 3 },
	{ VK_DIVIDE , 1 , 4 },
	{ VKF_LBRACKET , 3 , 4 },
	{ VKF_RBRACKET , 2 , 4 },
	{ VK_F1 , 6 , 4 },
	{ VK_F2 , 6 , 3 },
	{ VK_F3 , 6 , 2 },
	{ VK_F4 , 6 , 1 },
	{ VK_F5 , 6 , 0 },
	{ VK_ESCAPE , 6 , 6 },
	{ VK_LSHIFT , 6 , 5 },			// l shift
	{ VK_CONTROL, 5 , 7 },			// l control
	{ VK_RSHIFT , 1 , 6 },
	{ VKF_MINUS , 2 , 0 },
	{ VKF_EQUAL , 4 , 7 },
	{ VK_PRIOR , 4 , 6 },
	{ VK_NEXT , 3 , 6 },
	{ VK_INSERT , 2 , 6 },
	{ VK_DELETE , 3 , 7 },
	{ VK_HOME , 5 , 6 },
	{ VK_END , 6 , 7 },
#ifndef _DEBUG
	{ VK_NUMPAD0 , 4 , 0 },
#endif
	{ VK_NUMPAD1 , 4 , 1 },
	{ VK_NUMPAD2 , 3 , 1 },
	{ VK_NUMPAD3 , 2 , 1 },
	{ VK_NUMPAD4 , 4 , 2 },
	{ VK_NUMPAD5 , 3 , 2 },
	{ VK_NUMPAD6 , 2 , 2 },
	{ VK_NUMPAD7 , 4 , 3 },
	{ VK_NUMPAD8 , 3 , 3 },
	{ VK_NUMPAD9 , 2 , 3 },
	{ VK_DECIMAL , 3 , 0 },
	{ VK_OEM_2, 2, 0 },
//so much better than hardcoding the changes :P
#ifdef _DEBUG
	{ VK_NUMPAD0, KEYGROUP_ON, KEYBIT_ON},
#else
	{ VK_F12, KEYGROUP_ON, KEYBIT_ON},
#endif
#endif
	{ -1, -1, -1},
};
keyprog_t keygrps[256] = {
	{ 'A' , 5 , 6 },
	{ 'B' , 4 , 6 },
	{ 'C' , 3 , 6 },
	{ 'D' , 5 , 5 },
	{ 'E' , 4 , 5 },
	{ 'F' , 3 , 5 },
	{ 'G' , 2 , 5 },
	{ 'H' , 1 , 5 },
	{ 'I' , 5 , 4 },
	{ 'J' , 4 , 4 },
	{ 'K' , 3 , 4 },
	{ 'L' , 2 , 4 },
	{ 'M' , 1 , 4 },
	{ 'N' , 5 , 3 },
	{ 'O' , 4 , 3 },
	{ 'P' , 3 , 3 },
	{ 'Q' , 2 , 3 },
	{ 'R' , 1 , 3 },
	{ 'S' , 5 , 2 },
	{ 'T' , 4 , 2 },
	{ 'U' , 3 , 2 },
	{ 'V' , 2 , 2 },
	{ 'W' , 1 , 2 },
	{ 'X' , 5 , 1 },
	{ 'Y' , 4 , 1 },
	{ 'Z' , 3 , 1 },
	{ ' ' , 4 , 0 },
	{ WXK_DOWN , 0 , 0 },
	{ WXK_LEFT , 0 , 1 },
	{ WXK_RIGHT , 0 , 2 },
	{ WXK_UP , 0 , 3 },
	{ '0' , 4 , 0 },
	{ '1' , 4 , 1 },
	{ '2' , 3 , 1 },
	{ '3' , 2 , 1 },
	{ '4' , 4 , 2 },
	{ '5' , 3 , 2 },
	{ '6' , 2 , 2 },
	{ '7' , 4 , 3 },
	{ '8' , 3 , 3 },
	{ '9' , 2 , 3 },
	{ WXK_RETURN , 1 , 0 },
	{ WXK_DECIMAL , 3 , 0 },
	{ ',', 4 , 4 },
	{ WXK_NUMPAD_ADD , 1 , 1 },
	{ WXK_SUBTRACT , 1 , 2 },
	{ WXK_MULTIPLY , 1 , 3 },
	{ WXK_DIVIDE , 1 , 4 },
	{ '[' , 3 , 4 },
	{ ']' , 2 , 4 },
	{ WXK_F1 , 6 , 4 },
	{ WXK_F2 , 6 , 3 },
	{ WXK_F3 , 6 , 2 },
	{ WXK_F4 , 6 , 1 },
	{ WXK_F5 , 6 , 0 },
	{ WXK_ESCAPE , 6 , 6 },
	{ WXK_LSHIFT , 6 , 5 },			// l shift
	{ WXK_CONTROL, 5 , 7 },			// l control
	{ WXK_RSHIFT , 1 , 6 },
	{ '-', 2 , 0 },
	{ WXK_NUMPAD_EQUAL , 4 , 7 },
	//{ VK_PRIOR , 4 , 6 },
	//{ VK_NEXT , 3 , 6 },
	{ WXK_INSERT , 2 , 6 },
	{ WXK_DELETE , 6 , 7 },
	{ WXK_HOME , 5 , 6 },
	{ WXK_END , 3 , 7 },
	{ WXK_NUMPAD0 , 4 , 0 },
	{ WXK_NUMPAD1 , 4 , 1 },
	{ WXK_NUMPAD2 , 3 , 1 },
	{ WXK_NUMPAD3 , 2 , 1 },
	{ WXK_NUMPAD4 , 4 , 2 },
	{ WXK_NUMPAD5 , 3 , 2 },
	{ WXK_NUMPAD6 , 2 , 2 },
	{ WXK_NUMPAD7 , 4 , 3 },
	{ WXK_NUMPAD8 , 3 , 3 },
	{ WXK_NUMPAD9 , 2 , 3 },
	{ WXK_DECIMAL , 3 , 0 },
	//{ VK_OEM_2, 2, 0 },
	{ WXK_F12, KEYGROUP_ON, KEYBIT_ON},
	{ -1, -1, -1},
};
	
keypad_t *keypad_init(CPU_t *cpu) {
	keypad_t *keypad;
	
	keypad = (keypad_t *) malloc(sizeof(keypad_t));
	if (!keypad) {
		return NULL;
	}

	memset(keypad->keys, 0, sizeof(keypad->keys));
	keypad->on_pressed = 0;
	keypad->group = 0;
	memset(keypad->last_pressed, 0, sizeof(keypad->last_pressed));
	keypad->on_last_pressed = 0;
	return keypad;
}

void keypad(CPU_t *cpu, device_t *dev) {
	keypad_t *keypad = (keypad_t *) dev->aux;

	if (cpu->input) {
		int i, group, keybit;
		unsigned char result=0;
		unsigned char keymap[8] = {0, 0, 0, 0, 0, 0, 0, 0};
		unsigned char keymapbug[8] = {0, 0, 0, 0, 0, 0, 0, 0};

		for (group = 0; group < 7; group++) {
			for (keybit = 0; keybit < 8; keybit++) {
				if (keypad->keys[group][keybit]) {
					keymap[group] |= (1 << keybit);
				}
			}
		}
		
		for (group = 0; group < 7; group++) {
			for (i = 0; i < 7; i++) {
				if (keymap[group] & keymap[i]) {
					keymapbug[group] |= keymap[group] | keymap[i];
				}
			}
		}
		
		for (group = 0; group < 7; group++) {
			if (keypad->group & (1<<group)) {
				result |= keymapbug[group];
			}
		}
	

		cpu->bus = ~result;
		cpu->input = FALSE;
	} else if (cpu->output) {
		unsigned char group = ~cpu->bus;
		if (group != 0) keypad->group = group;
		else keypad->group = 0;
		cpu->output = FALSE;
	}	
}

void keypad_press(CPU_t *cpu, int group, int bit)
{
	if (group == KEYGROUP_ON && bit == KEYBIT_ON)
	{
		cpu->pio.keypad->on_pressed |= KEY_KEYBOARDPRESS;
	}
	else
	{
		cpu->pio.keypad->keys[group][bit] |= KEY_KEYBOARDPRESS;
	}
}

keyprog_t *keypad_key_press(CPU_t *cpu, unsigned int vk, bool *changed)
{
	int i;
	keypad_t *keypad = cpu->pio.keypad;

	if (keypad == NULL) {
		return NULL;
	}
	for(i = 0; i < NumElm(keygrps); i++)
	{
		if (keygrps[i].vk == vk)
		{
			int orig, group = keygrps[i].group, bit = keygrps[i].bit;
			if (group == KEYGROUP_ON && bit == KEYBIT_ON) {
				orig = keypad->on_pressed;
			} else {
				orig = keypad->keys[group][bit];
			}
			keypad_press(cpu, group, bit);
			if (changed) {
				if (group == KEYGROUP_ON && bit == KEYBIT_ON) {
					*changed = orig != keypad->on_pressed;
				} else {
					*changed = orig != keypad->keys[group][bit];
				}
			}
			return &keygrps[i];
		}
	}	
	return NULL;
}

void keypad_release(CPU_t *cpu, int group, int bit)
{
	if (group == KEYGROUP_ON && bit == KEYBIT_ON)
	{
		cpu->pio.keypad->on_pressed &= ~KEY_KEYBOARDPRESS;
	}
	else
	{
		cpu->pio.keypad->keys[group][bit] &= ~KEY_KEYBOARDPRESS;
	}
}

keyprog_t *keypad_key_release(CPU_t *cpu, unsigned int vk) {
	keypad_t *keypad = cpu->pio.keypad;
	
	if (keypad == NULL)
	{
		return NULL;
	}

	for (int i = 0; i < NumElm(keygrps); i++)
	{
		if (keygrps[i].vk == vk)
		{	
			keypad_release(cpu, keygrps[i].group, keygrps[i].bit);
			return &keygrps[i];
		}
	}
	return NULL;
}

#ifdef WINVER
void keypad_vk_release(HWND hwnd, int group, int bit) {
	for (int i = 0; i < ARRAYSIZE(defaultkeys); i++) {
		if (keygrps[i].group == group && keygrps[i].bit == bit) {	
			//TODO: fix lparam
			//this is sent as a message and not HandleKeyUp because
			//i can't get an LPCALC in here. It would be nice
			//to somehow separate the skin logic from that but
			//still update the skin somehow
			SendMessage(hwnd, WM_KEYUP, keygrps[i].vk, 0);
		}
	}
}
#endif
