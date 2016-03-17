#include "Gamepad.h"

CGamepad::CGamepad(int _iIndex) {

	// Subtract 1 because XInput identifies the 
	// gamepads as 0, 1, 2, 3
	m_iGamepadIndex = _iIndex - 1;

	// Iterate through all gamepad buttons
	for (int i = 0; i < ButtonCount; i++)
	{
		bPrev_ButtonStates[i]   = false;
		bButtonStates[i]        = false;
		bGamepad_ButtonsDown[i] = false;
	}

}

// Update gamepad state
void CGamepad::Update() {

	// Obtain current gamepad state
	m_state = GetState(); 

	// Iterate through all gamepad buttons
	for (int i = 0; i < ButtonCount; i++)
	{
		// Set button state for current frame
		bButtonStates[i] = (m_state.Gamepad.wButtons &
			XINPUT_Buttons[i]) == XINPUT_Buttons[i];

		// Set 'DOWN' state for current frame
		bGamepad_ButtonsDown[i] = !bPrev_ButtonStates[i] &&
			bButtonStates[i];
	}

}

// Update button states for next frame
void CGamepad::RefreshState() {

	memcpy(bPrev_ButtonStates, bButtonStates, sizeof(bPrev_ButtonStates));

}

// Get the current state of the gamepad
XINPUT_STATE CGamepad::GetState() {

	// Initialize at null
	ZeroMemory(&m_state, sizeof(XINPUT_STATE));

	XInputGetState(m_iGamepadIndex, &m_state);

	return (m_state);
}

int CGamepad::GetIndex() {
	return (m_iGamepadIndex);
}

// Check whether or not it's connected
bool CGamepad::IsConnected() {

	// Zeroise the state
	ZeroMemory(&m_state, sizeof(XINPUT_STATE));

	// Get the state
	DWORD Result = XInputGetState(m_iGamepadIndex, &m_state);

	if (Result == ERROR_SUCCESS) {
		return true;
	}
	else {
		return false;
	}

}

void CGamepad::SetIsActive(bool _bIsActive) {

	m_bIsActive = _bIsActive;

}

bool CGamepad::IsActive() {

	return (m_bIsActive);

}

// Deadzone check for Left Thumbstick
bool CGamepad::LStick_InDeadzone()
{
	// Obtain the X & Y axes of the stick
	short sX = m_state.Gamepad.sThumbLX;
	short sY = m_state.Gamepad.sThumbLY;

	// X axis is outside of deadzone
	if (sX > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE ||
		sX < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		return false;

	// Y axis is outside of deadzone
	if (sY > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE ||
		sY < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		return false;

	// One (or both axes) axis is inside of deadzone
	return true;
}

// Deadzone check for Right Thumbstick
bool CGamepad::RStick_InDeadzone()
{
	// Obtain the X & Y axes of the stick
	short sX = m_state.Gamepad.sThumbRX;
	short sY = m_state.Gamepad.sThumbRY;

	// X axis is outside of deadzone
	if (sX > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE ||
		sX < -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		return false;

	// Y axis is outside of deadzone
	if (sY > XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE ||
		sY < -XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE)
		return false;

	// One (or both axes) axis is inside of deadzone
	return true;
}

// Return X axis of left stick
float CGamepad::LeftStick_X()
{
	// Obtain X axis of left stick
	short sX = m_state.Gamepad.sThumbLX;

	// Return axis value, converted to a float
	return (static_cast<float>(sX) / 32768.0f);
}

// Return Y axis of left stick
float CGamepad::LeftStick_Y()
{
	// Obtain Y axis of left stick
	short sY = m_state.Gamepad.sThumbLY;

	// Return axis value, converted to a float
	return (static_cast<float>(sY) / 32768.0f);
}

// Return X axis of right stick
float CGamepad::RightStick_X()
{
	// Obtain X axis of right stick
	short sX = m_state.Gamepad.sThumbRX;

	// Return axis value, converted to a float
	return (static_cast<float>(sX) / 32768.0f);
}

// Return Y axis of right stick
float CGamepad::RightStick_Y()
{
	// Obtain the Y axis of the left stick
	short sY = m_state.Gamepad.sThumbRY;

	// Return axis value, converted to a float
	return (static_cast<float>(sY) / 32768.0f);
}

bool CGamepad::IsButtonPressed(int _iButton) {

	if (m_state.Gamepad.wButtons & XINPUT_Buttons[_iButton]) {
		return true; // The button is pressed
	}

	return false; // The button is not pressed
}

bool CGamepad::IsButtonDown(int a_iButton)
{
	return bGamepad_ButtonsDown[a_iButton];
}