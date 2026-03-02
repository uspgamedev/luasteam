#####
Extra
#####

This module has some extra functions that are not in the SteamWorks API but may be useful to deal with it.

List of Functions
-----------------

* :func:`extra.ParseUint64`

Function Reference
------------------

.. function:: extra.ParseUint64 (str)

    :param str: The value to convert to uint64. Accepts either a string or an integer.
    :type str: string or integer
    :returns: (`uint64`) The parsed number. 0 if the string was invalid.
    :see: :ref:`64-bit-integers`

    Converts a string or integer to a 64-bit integer userdata that can be used with this library.

**Example**::

    local function saveMyId()
        -- This is highly useless since your ID won't change, but you get the point.
        writeFile('my_id.txt', tostring(Steam.user.getSteamID()))
    end

    local function readMyId()
        return Steam.Extra.ParseUint64(readFile('my_id.txt'))
    end