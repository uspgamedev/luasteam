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

    :param number length: Usually the number returned by `utils.getEnteredGamepadTextLength()`
    :returns: (`string`) The gamepad text
    :SteamWorks: `GetEnteredGamepadTextInput <https://partner.steamgames.com/doc/api/ISteamUtils#GetEnteredGamepadTextInput>`_
    
    Gets the gamepad text input from the Big Picture overlay.

    This must be called within the :func:`utils.onGamepadTextInputDismissed` callback, and only if `submitted` is ``true``. See that example.

.. function:: utils.getEnteredGamepadTextLength()

    :returns: (`number`) Length of the gamepad text
    :SteamWorks: `GetEnteredGamepadTextLength <https://partner.steamgames.com/doc/api/ISteamUtils#GetEnteredGamepadTextLength>`_
    
    Gets the length of the gamepad text input from the Big Picture overlay.

    This must be called within the :func:`utils.onGamepadTextInputDismissed` callback, and only if `submitted` is ``true``. See that example.
    
.. function:: utils.isSteamInBigPictureMode()

    :returns: (`boolean`) ``true`` if the Big Picture overlay is available; otherwise, ``false``. This will always return ``false`` if your app is not the 'game' `application type <https://partner.steamgames.com/doc/store/application#types_of_applications>`_.
    :SteamWorks: `IsSteamInBigPictureMode <https://partner.steamgames.com/doc/api/ISteamUtils#IsSteamInBigPictureMode>`_
    
    Checks if Steam & the Steam Overlay are running in Big Picture mode.
    
    Games must be launched through the Steam client to enable the Big Picture overlay.
During development, a game can be added as a non-steam game to the developer's library to test this feature.

.. function:: utils.isSteamRunningOnSteamDeck ()

    :returns: (`boolean`) ``true`` if Steam itself is running on a Steam Deck device; otherwise, ``false``.
    :SteamWorks: `IsSteamRunningOnSteamDeck <https://partner.steamgames.com/doc/api/ISteamUtils#IsSteamRunningInVR>`_

	Checks if Steam is running on a Steam Deck, or any other SteamOS device.

**Example**::

    if Steam.utils.isSteamRunningOnSteamDeck() then
        -- some special logic
    end

.. function:: utils.showGamepadTextInput(input_mode, input_line_mode, description, char_max, existing_text)

    :param string input_mode: Selects the input mode to use. Valid options are: "Normal", "Password".
    :param string input_line_mode: Controls whether to use single or multi line input. Valid options are: "SingleLine", "MultipleLines".
    :param string description: Sets the description that should inform the user what the input dialog is for.
    :param number char_max: The maximum number of characters that the user can input.
    :param string existing_text: Sets the preexisting text which the user can edit.
    :returns: (`boolean`) ``true`` if the big picture overlay is running; otherwise, ``false``.
    :SteamWorks: `ShowGamepadTextInput <https://partner.steamgames.com/doc/api/ISteamUtils#ShowGamepadTextInput>`_

    Activates the Big Picture text input dialog which only supports gamepad input.

    Note: Steam must be in Big Picture Mode. Non-Steam games ran through Steam will not overlay properly; however, you can minimize Steam Big Picture mode to test.

**Example**::

    Steam.utils.showGamepadTextInput("Normal","SingleLine",description,1024,existing_text)

.. function:: utils.showFloatingGamepadTextInput(floating_input_mode, textFieldXPosition, textFieldYPosition, textFieldWidth, textFieldHeight)

    :param string floating_input_mode: Selects the keyboard type to use. Valid options are: "SingleLine", "MultipleLines", "Email", "Numeric".
    :param number textFieldXPosition: X coordinate of text field which shouldn't be obscured by the floating keyboard.
    :param number textFieldYPosition: Y coordinate of text field which shouldn't be obscured by the floating keyboard.
    :param number textFieldWidth: Width of text field which shouldn't be obscured by the floating keyboard.
    :param number textFieldHeight: Height of text field which shouldn't be obscured by the floating keyboard.
    :returns: (`boolean`) ``true`` if the floating keyboard was shown, otherwise, ``false``.
    :SteamWorks: `ShowFloatingGamepadTextInput <https://partner.steamgames.com/doc/api/ISteamUtils#ShowFloatingGamepadTextInput>`_

    Opens a floating keyboard over the game content and sends OS keyboard keys directly to the game.
    The text field position is specified in pixels relative the origin of the game window and is used to position the floating keyboard in a way that doesn't cover the text field.

    Note: Steam must be in Big Picture Mode. Non-Steam games ran through Steam will not overlay properly; however, you can minimize Steam Big Picture mode to test.

**Example**::

    -- For bottom of window use 0,0,0,0
    -- For top of window use 0,window height/2,window width,window height/2
    Steam.utils.showFloatingGamepadTextInput("SingleLine", x, y, w, h)

Callbacks Reference
-------------------

.. warning::

    Remember callbacks are functions that you should override in order to receive the events, and not call directly.

    Also, you **must** constantly call ``Steam.runCallbacks()`` (preferably in your game loop) in order for your callbacks to be called.

.. function:: utils.onGamepadTextInputDismissed(data)

    :param table data: A table similar to `GamepadTextInputDismissed_t <https://partner.steamgames.com/doc/api/ISteamUtils#GamepadTextInputDismissed_t>`_

		* **data.submitted** (`boolean`)  -- ``true`` if user entered & accepted text (Call :func:`utils.getEnteredGamepadTextInput` to receive the text), ``false`` if input was canceled.
		* **data.submittedText** (`number`)  -- Contains the length in bytes if there was text submitted.
    :returns: nothing
    :SteamWorks: `GamepadTextInputDismissed_t <https://partner.steamgames.com/doc/api/ISteamUtils#GamepadTextInputDismissed_t>`_

    Called when the big picture gamepad text input has been closed.

**Example**::

    function Steam.utils.onGamepadTextInputDismissed(data)
       if not data.submitted then return end -- The user canceled
       local length = Steam.utils.getEnteredGamepadTextLength();
       local newstring = Steam.utils.getEnteredGamepadTextInput(length);
       -- Use the newstring made by the user.
    end

.. function:: utils.onFloatingGamepadTextInputDismissed()

    :returns: nothing
    :SteamWorks: `FloatingGamepadTextInputDismissed_t <https://partner.steamgames.com/doc/api/ISteamUtils#FloatingGamepadTextInputDismissed_t>`_

    Called when the floating keyboard invoked from :func:`utils.showFloatingGamepadTextInput` has been closed.
