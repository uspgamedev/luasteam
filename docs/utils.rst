###########
ISteamUtils
###########

List of Functions
-----------------

* :func:`utils.getAppID`
* :func:`utils.getEnteredGamepadTextInput`
* :func:`utils.getEnteredGamepadTextLength`
* :func:`utils.isSteamInBigPictureMode`
* :func:`utils.isSteamRunningOnSteamDeck`
* :func:`utils.showGamepadTextInput`
* :func:`utils.showFloatingGamepadTextInput`

List of Callbacks
-----------------

* :func:`utils.onGamepadTextInputDismissed`
* :func:`utils.onFloatingGamepadTextInputDismissed`

Function Reference
------------------

.. function:: utils.getAppID()

    :returns: (`number`) The AppID.
    :SteamWorks: `GetAppID <https://partner.steamgames.com/doc/api/ISteamUtils#GetAppID>`_

    Gets the App ID of the current process.

    **Example**::

    print("My app id is " .. Steam.utils.getAppID())

.. function:: utils.getEnteredGamepadTextInput(buffer,length)

    :param number buffer: We use 1024 chars.
    :param number length: Number returned by getEnteredGamepadTextLength().
    :returns: (`string`)
    :SteamWorks: `GetEnteredGamepadTextInput <https://partner.steamgames.com/doc/api/ISteamUtils#GetEnteredGamepadTextInput>`_

    Called within onGamepadTextInputDismissed: see that example.
    Provides the text input as UTF-8.

.. function:: utils.getEnteredGamepadTextLength()

    :returns: (`number`)
    :SteamWorks: `GetEnteredGamepadTextLength <https://partner.steamgames.com/doc/api/ISteamUtils#GetEnteredGamepadTextLength>`_

    Called within onGamepadTextInputDismissed: see that example.

.. function:: utils.isSteamInBigPictureMode()

    :returns: (`boolean`)
    :SteamWorks: `IsSteamInBigPictureMode <https://partner.steamgames.com/doc/api/ISteamUtils#IsSteamInBigPictureMode>`_

.. function:: utils.isSteamRunningOnSteamDeck()

    :returns: (`boolean`)
    :SteamWorks: `IsSteamRunningOnSteamDeck <https://partner.steamgames.com/doc/api/ISteamUtils#IsSteamRunningOnSteamDeck>`_

.. function:: utils.showGamepadTextInput(input_mode,input_line_mode,description,char_max,existing_text)

    :param string input_mode: Valid options are: "Normal", "Password".
    :param string input_line_mode: Valid options are: "SingleLine", "MultipleLines".
    :param string description: Sets the description that should inform the user what the input dialog is for.
    :param string char_max: We use 1024 chars.
    :param string existing_text: Sets the preexisting text which the user can edit.
    :returns: (`boolean`) true if the big picture overlay is running; otherwise, false
    :SteamWorks: `ShowGamepadTextInput <https://partner.steamgames.com/doc/api/ISteamUtils#ShowGamepadTextInput>`_

.. function:: utils.showFloatingGamepadTextInput(floating_input_mode,TextFieldXPosition,TextFieldYPosition,TextFieldWidth,TextFieldHeight)

    :param string floating_input_mode: Valid options are: "SingleLine", "MultipleLines", "Email", "Numeric".
    :param string TextFieldXPosition: X coordinate of text field which shouldn't be obscured by the floating keyboard.
    :param string TextFieldYPosition: Y coordinate of text field which shouldn't be obscured by the floating keyboard.
    :param string TextFieldWidth: Width of text field which shouldn't be obscured by the floating keyboard.
    :param string TextFieldHeight: Height of text field which shouldn't be obscured by the floating keyboard.
    :returns: (`boolean`) true if the floating keyboard was shown, otherwise, false
    :SteamWorks: `ShowFloatingGamepadTextInput <https://partner.steamgames.com/doc/api/ISteamUtils#ShowFloatingGamepadTextInput>`_

Callbacks Reference
-------------------

.. warning::

    Remember callbacks are functions that you should override in order to receive the events, and not call directly.

    Also, you **must** constantly call ``Steam.runCallbacks()`` (preferably in your game loop) in order for your callbacks to be called.

.. function:: utils.OnGamepadTextInputDismissed(data)

    :param table data: A table similar to `GamepadTextInputDismissed_t <https://partner.steamgames.com/doc/api/ISteamUtils#GamepadTextInputDismissed_t>`_

		* **data.submitted** (`boolean`)  -- true if user entered & accepted text (Call utils.getEnteredGamepadTextInput to receive the text), false if input was canceled.
		* **data.submittedText** (`number`)  -- Contains the length in bytes if there was text submitted.
    :returns: nothing
    :SteamWorks: `GamepadTextInputDismissed_t <https://partner.steamgames.com/doc/api/ISteamUtils#GamepadTextInputDismissed_t>`_

    Called when the big picture gamepad text input has been closed.

**Example**::

function Steam.utils.onGamepadTextInputDismissed(data)
    if not data.submitted then return end-- The user canceled
    local length = Steam.utils.getEnteredGamepadTextLength();
    local newstring = Steam.utils.getEnteredGamepadTextInput(1024, length);
    -- Use the newstring made by the user.
end

.. function:: utils.OnFloatingGamepadTextInputDismissed()

    :returns: nothing
    :SteamWorks: `FloatingGamepadTextInputDismissed_t <https://partner.steamgames.com/doc/api/ISteamUtils#FloatingGamepadTextInputDismissed_t>`_

    Called when the floating keyboard invoked from utils.showFloatingGamepadTextInput has been closed.

**Example with notes**::

function Steam.utils.onGamepadTextInputDismissed(data)
    -- x,y,w,h are the ''field which shouldn't be obscured by the floating keyboard''
    -- However, it is finicky around window edges.  Really, you want the keyboard at the top or bottom of the window.
    -- For bottom of window use 0,0,0,0
    -- For top of window use 50, window width-250, window height-100, 200
    Steam.utils.showFloatingGamepadTextInput("SingleLine",x,y,w,h)
end
