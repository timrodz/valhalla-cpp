#ifndef __GAMEPAD_H__
#define __GAMEPAD_H__

// Windows header and XInput header
#include <Windows.h>
#include <XInput.h>

// XInput library
#pragma comment(lib, "XInput.lib")

#define DISCONNECTED XINPUT_STATE 

// Buttons
static const WORD XINPUT_Buttons[] = {
	XINPUT_GAMEPAD_A,
	XINPUT_GAMEPAD_B,
	XINPUT_GAMEPAD_X,
	XINPUT_GAMEPAD_Y,
	XINPUT_GAMEPAD_DPAD_UP,
	XINPUT_GAMEPAD_DPAD_DOWN,
	XINPUT_GAMEPAD_DPAD_LEFT,
	XINPUT_GAMEPAD_DPAD_RIGHT,
	XINPUT_GAMEPAD_LEFT_SHOULDER,
	XINPUT_GAMEPAD_RIGHT_SHOULDER,
	XINPUT_GAMEPAD_LEFT_THUMB,
	XINPUT_GAMEPAD_RIGHT_THUMB,
	XINPUT_GAMEPAD_START,
	XINPUT_GAMEPAD_BACK
};

// XInput Button IDs
struct XButtonIDs
{
	// Function prototypes
	//---------------------//

	// 'XButtonIDs' - Default constructor
	XButtonIDs::XButtonIDs() {
		// These values are used to index the XINPUT_Buttons array,
		// accessing the matching XINPUT button value

		A = 0;
		B = 1;
		X = 2;
		Y = 3;

		DPad_Up = 4;
		DPad_Down = 5;
		DPad_Left = 6;
		DPad_Right = 7;

		L_Shoulder = 8;
		R_Shoulder = 9;

		L_Thumbstick = 10;
		R_Thumbstick = 11;

		Start = 12;
		Back = 13;
	};

	// Member variables
	//---------------------//

	int A, B, X, Y; // 'Action' buttons

	// Directional Pad (D-Pad)
	int DPad_Up, DPad_Down, DPad_Left, DPad_Right;

	// Shoulder ('Bumper') buttons
	int L_Shoulder, R_Shoulder;

	// Thumbstick buttons
	int L_Thumbstick, R_Thumbstick;

	int Start; // 'START' button
	int Back;  // 'BACK' button

};

class CGamepad {

public:
	CGamepad(int _iIndex);
	//XButtonIDs XButtons;

	// Determine the state of the gamepad
	XINPUT_STATE GetState();
	// Get the index of the gamepad
	int GetIndex();
	// Check whether or not it's connected
	bool IsConnected();
	// Check whether or not it's being used
	void SetIsActive(bool _bIsBeingUsed);
	bool IsActive();

	// Thumbstick functions
	// - Return true if stick is inside deadzone, false if outside
	bool LStick_InDeadzone();
	bool RStick_InDeadzone();

	float LeftStick_X();  // Return X axis of left stick
	float LeftStick_Y();  // Return Y axis of left stick
	float RightStick_X(); // Return X axis of right stick
	float RightStick_Y(); // Return Y axis of right stick

	// Determine whether or not a certain button is pressed
	bool IsDown(int _iButton);

private:
	XINPUT_STATE m_state; // Current gamepad state
	int m_iGamepadIndex;  // Gamepad index (1 - 4)
	bool m_bIsActive;

};

#endif //__GAMEPAD_H__
