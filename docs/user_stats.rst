###############
ISteamUserStats
###############


List of Functions
-----------------
* :func:`userStats.getStatInt`
* :func:`userStats.getStatFloat`
* :func:`userStats.setStatInt`
* :func:`userStats.setStatFloat`
* :func:`userStats.getAchievement`
* :func:`userStats.setAchievement`
* :func:`userStats.resetAllStats`
* :func:`userStats.storeStats`
* :func:`userStats.requestCurrentStats`
* :func:`userStats.findLeaderboard`
* :func:`userStats.findOrCreateLeaderboard`
* :func:`userStats.getLeaderboardEntryCount`
* :func:`userStats.getLeaderboardName`
* :func:`userStats.getLeaderboardSortMethod`
* :func:`userStats.getLeaderboardDisplayType`
* :func:`userStats.uploadLeaderboardScore`
* :func:`userStats.downloadLeaderboardEntries`

List of Callbacks
-----------------

* :func:`userStats.onUserStatsReceived`

Function Reference
------------------

.. function:: userStats.getStatInt(name)

    :param string name: The 'API Name' of the stat. Must not be longer than 128 bytes.
    :returns: (`boolean`)
        This function returns true upon success if all of the following conditions are met; otherwise, false.

        * :func:`userStats.requestCurrentStats` has completed and successfully returned its callback.

        * The 'API Name' of the specified stat exists in App Admin on the Steamworks website, and the changes are published.
    :returns: (`number?`) If the call is successful, returns a second value, the current value of the stat.
    :SteamWorks: `GetStat <https://partner.steamgames.com/doc/api/ISteamUserStats#GetStat>`_

    Gets the current value of a users stat, it must have been set as an int. For floats see :func:`userStats.getStatFloat`

    The equivalent function for other users is :func:`userStats.getUserStatInt` **(missing)**.

**Example**::

    local success, data = Steam.userStats.getStatInt('stat_name')
    if success then
        print(data)
    end

.. function:: userStats.getStatFloat(name)

  Same as :func:`userStats.getStatInt`, but this function reads stats that are set as floats.

  The equivalent function for other users is :func:`userStats.getUserStatFloat` **(missing)**.

**Example**::

    local success, data = Steam.userStats.getStatFloat('stat_name')
    if success then
        print(data)
    end

.. function:: userStats.setStatInt(stat_name, stat_value)
    
    :param string name: The 'API Name' of the stat whose value to set. Must not be longer than 128 bytes.
    :param int stat_value: The new value of the stat. This must be an absolute value, it will not increment or decrement for you.
    :returns: (`boolean`)
        This function returns true upon success if all of the following conditions are met; otherwise, false.

        * The specified stat 'API Name' exists in App Admin on the Steamworks website, and the changes are published.

        * :func:`userStats.requestCurrentStats` has completed and successfully returned its callback.
    :SteamWorks: `SetStat <https://partner.steamgames.com/doc/api/ISteamUserStats#SetStat>`_

    Sets the value of a stat for the current user.

    You must have called :func:`userStats.requestCurrentStats` and it needs to return successfully via its callback prior to calling this!

    This call only modifies Steam's in-memory state so it is quite cheap. To submit the stats to the server you must call :func:`userStats.storeStats`.

**Example**::

    Steam.userStats.setStatInt('stat_name', 43)
    Steam.userStats.storeStats()

.. function:: userStats.setStatFloat(stat_name, stat_value)

  Same as :func:`userStats.setStatInt`, but this function sets stats as floats.

**Example**::

    Steam.userStats.setStatFloat('stat_name', 43.34)
    Steam.userStats.storeStats()

.. function:: userStats.getAchievement(name)


    :param string name: The 'API Name' of the achievement.
    :returns: (`boolean`)
        This function returns true upon success if all of the following conditions are met; otherwise, false.

        * :func:`userStats.requestCurrentStats` has completed and successfully returned its callback.

        * The 'API Name' of the specified achievement exists in App Admin on the Steamworks website, and the changes are published.
    :returns: (`boolean?`) If the call is successful, returns a second value, the unlock status of the achievement.
    :SteamWorks: `GetAchievement <https://partner.steamgames.com/doc/api/ISteamUserStats#GetAchievement>`_

    Gets the unlock status of the Achievement.

    The equivalent function for other users is :func:`userStats.getUserAchievement` **(missing)**.

**Example**::

    local success, achieved = Steam.userStats.getAchievement('ach_name')
    if success and achieved then
        print('Yep, you have the achievement')
    end

.. function:: userStats.setAchievement(name)
    
    :param string name: The 'API Name' of the Achievement to unlock.
    :returns: (`boolean`)
        This function returns true upon success if all of the following conditions are met; otherwise, false.

        * The specified achievement 'API Name' exists in App Admin on the Steamworks website, and the changes are published.

        * :func:`userStats.requestCurrentStats` has completed and successfully returned its callback.
    :SteamWorks: `SetAchievement <https://partner.steamgames.com/doc/api/ISteamUserStats#SetAchievement>`_

    Unlocks an achievement.

    You must have called :func:`userStats.requestCurrentStats` and it needs to return successfully via its callback prior to calling this!

    You can unlock an achievement multiple times so you don't need to worry about only setting achievements that aren't already set. This call only modifies Steam's in-memory state so it is quite cheap. To send the unlock status to the server and to trigger the Steam overlay notification you must call :func:`userStats.storeStats`.

**Example**::

    if achievementConditionSatisfied() and doesntHaveAchievement() then
        Steam.userStats.setAchievement('ach_name')
        Steam.userStats.storeStats() -- shows overlay notification
    end

.. function:: userStats.resetAllStats(achievementsToo)

    :param boolean achievementsToo: Also reset the user's achievements?
    :returns: (`boolean`) true indicating success if :func:`userStats.requestCurrentStats` has already been called and successfully returned its callback; otherwise false.
    :SteamWorks: `ResetAllStats <https://partner.steamgames.com/doc/api/ISteamUserStats#ResetAllStats>`_

    Resets the current users stats and, optionally achievements.

    This automatically calls :func:`userStats.storeStats` to persist the changes to the server. This should typically only be used for testing purposes during development. Ensure that you sync up your stats with the new default values provided by Steam after calling this by calling :func:`userStats.requestCurrentStats`.

**Example**::

    if dev_mode and keypressed('f10') then
        Steam.userStats.resetAllStats(true)
    end

.. function:: userStats.storeStats()

    :returns: (`boolen`)
        This function returns true upon success if all of the following conditions are met; otherwise, false.

        * :func:`userStats.requestCurrentStats` has completed and successfully returned its callback.

        * The current game has stats associated with it in the Steamworks Partner backend, and those stats are published.
    :SteamWorks: `StoreStats <https://partner.steamgames.com/doc/api/ISteamUserStats#StoreStats>`_

    Send the changed stats and achievements data to the server for permanent storage.

    If this fails then nothing is sent to the server. It's advisable to keep trying until the call is successful.

    This call can be rate limited. Call frequency should be on the order of minutes, rather than seconds. You should only be calling this during major state changes such as the end of a round, the map changing, or the user leaving a server. This call is required to display the achievement unlock notification dialog though, so if you have called :func:`userStats.setAchievement` then it's advisable to call this soon after that.

    If you have stats or achievements that you have saved locally but haven't uploaded with this function when your application process ends then this function will automatically be called.

    You can find additional debug information written to the ``%steam_install%\logs\stats_log.txt`` file.

    If the call is successful you will receive a :func:`userStats.userStatsStored` callback.
    If **result** has a result of **"InvalidParam"**, then one or more stats uploaded has been rejected, either because they broke constraints or were out of date. In this case the server sends back updated values and the stats should be updated locally to keep in sync.

    If one or more achievements has been unlocked then this will also trigger a :func:`userStats.userAchievementStored` callback.

**Example**::

    function onMatchEnd()
        Steam.userStats.storeStats()
    end

.. function:: userStats.requestCurrentStats()

    :returns: (`boolean`)
        Only returns false if there is no user logged in; otherwise, true.
    :SteamWorks: `RequestCurrentStats <https://partner.steamgames.com/doc/api/ISteamUserStats#RequestCurrentStats>`_

    Asynchronously request the user's current stats and achievements from the server.

    You must **always call this first** to get the initial status of stats and achievements.
    Only after the resulting callback comes back can you start calling the rest of the stats and achievement functions for the current user.

    The equivalent function for other users is :func:`userStats.requestUserStats` **(missing)**.

    Triggers a :func:`userStats.onUserStatsReceived` callback.

**Example**::

    -- before any achievement/stats stuff
    Steam.userStats.requestCurrentStats()

    function Steam.userStats.onUserStatsReceived()
        can_do_stats_stuff = true
    end


.. function:: userStats.findLeaderboard(name, callback)

    :param string name: The name of the leaderboard to find. Must not be longer than 128 bytes.
    :param function callback: Called asynchronously when this function returns. See below.
    :returns: nothing
    :SteamWorks: `FindLeaderboard <https://partner.steamgames.com/doc/api/ISteamUserStats#FindLeaderboard>`_

    Gets a leaderboard by name.

    You must call either this or :func:`userStats.findOrCreateLeaderboard` to obtain the leaderboard handle which is valid for the game session for each leaderboard you wish to access prior to calling any other Leaderboard functions.

    **callback(data, err)** receives two arguments:

    * **data** (`table`) -- Similar to `LeaderboardFindResult_t <https://partner.steamgames.com/doc/api/ISteamUserStats#LeaderboardFindResult_t>`_, or **nil** if **err** is **true**.

        * **data.steamLeaderboard** (`uint64`) -- Handle to the leaderboard that was searched for. A special value is returned if no leaderboard was found.

        * **data.leaderboardFound** (`boolean`) -- Was the leaderboard found? **true** if it was, **false** if it wasn't.


    * **err** (`boolean`): **true** if there was any IO error with the request.

**Example**::

    Steam.userStats.findLeaderboard('l_name', function(data, err)
        if err or not data.leaderboardFound then
            print('Something happened')
        elseif 
            uploadScoresHelper(data.steamLeaderboard)
        end
    end)

.. function:: userStats.findOrCreateLeaderboard(name, sortMethod, displayType, callback)

    :param string name: The name of the leaderboard to find or create. Must not be larger than 128 bytes.
    :param string sortMethod: The sort order of the new leaderboard if it's created. Must be 'Ascending' or 'Descending' (see `ELeaderboardSortMethod <https://partner.steamgames.com/doc/api/ISteamUserStats#ELeaderboardSortMethod>`_).
    :param string displayType: The display type (used by the Steam Community web site) of the new leaderboard if it's created. Must be one of: 'Numeric', 'TimeSeconds' or 'TimeMilliSeconds' (see `ELeaderboardDisplayType <https://partner.steamgames.com/doc/api/ISteamUserStats#ELeaderboardDisplayType>`_).
    :param function callback: Called asynchronously when this function returns. It must be of the same type as the callback in :func:`userStats.findLeaderboard`.
    :returns: nothing
    :SteamWorks: `FindOrCreateLeaderboard <https://partner.steamgames.com/doc/api/ISteamUserStats#FindOrCreateLeaderboard>`_

    Gets a leaderboard by name, it will create it if it's not yet created.

    You must call either this or :func:`userStats.findLeaderboard` to obtain the leaderboard handle which is valid for the game session for each leaderboard you wish to access prior to calling any other Leaderboard functions.

    Leaderboards created with this function will not automatically show up in the Steam Community. You must manually set the Community Name field in the App Admin panel of the Steamworks website. As such it's generally recommended to prefer creating the leaderboards in the App Admin panel on the Steamworks website and using :func:`userStats.findLeaderboard` unless you're expected to have a large amount of dynamically created leaderboards.

**Example**::

    Steam.userStats.findOrCreateLeaderboard('l_name', 'Ascending', 'Numeric', function(data, err)
        if err or not data.leaderboardFound then
            print('Something happened')
        elseif 
            uploadScoresHelper(data.steamLeaderboard)
        end
    end)

.. function:: userStats.getLeaderboardName(steamLeaderboard)

    :param uint64 steamLeaderboard: A leaderboard handle obtained from :func:`userStats.findLeaderboard` or :func:`userStats.findOrCreateLeaderboard`.
    :returns: (`string`) The name of the leaderboard. Returns an empty string if the leaderboard handle is invalid.
    :SteamWorks: `GetLeaderboardName <https://partner.steamgames.com/doc/api/ISteamUserStats#GetLeaderboardName>`_

    Returns the name of a leaderboard handle.

**Example**::

    function printLeaderboardInfo(handle)
        print('Leaderboard name: ' .. Steam.userStats.getLeaderboardName(handle))
        print('Entries: ' .. Steam.userStats.getLeaderboardEntryCount(handle))
        print('Sort Method: ' .. Steam.userStats.getLeaderboardSortMethod(handle))
        print('Display Type: ' .. Steam.userStats.getLeaderboardDisplayType(handle))
    end

.. function:: userStats.getLeaderboardEntryCount(steamLeaderboard)

    :param uint64 steamLeaderboard: A leaderboard handle obtained from :func:`userStats.findLeaderboard` or :func:`userStats.findOrCreateLeaderboard`.
    :returns: (`number`) The number of entries in the leaderboard. Returns 0 if the leaderboard handle is invalid.
    :SteamWorks: `GetLeaderboardEntryCount <https://partner.steamgames.com/doc/api/ISteamUserStats#GetLeaderboardEntryCount>`_

    Returns the total number of entries in a leaderboard.

    This is cached on a per leaderboard basis upon the first call to :func:`userStats.findLeaderboard` or :func:`userStats.findOrCreateLeaderboard` and is refreshed on each successful call to :func:`userStats.downloadLeaderboardEntries`, :func:`userStats.downloadLeaderboardEntriesForUsers` **(missing)**, and :func:`userStats.uploadLeaderboardScore`.

**Example**: See :func:`userStats.getLeaderboardName`'s example.

.. function:: userStats.getLeaderboardSortMethod(steamLeaderboard)

    :param uint64 steamLeaderboard: A leaderboard handle obtained from :func:`userStats.findLeaderboard` or :func:`userStats.findOrCreateLeaderboard`.
    :returns: (`string?`) The sort method of the leaderboard, either "Ascending" or "Descending". Returns **nil** if the leaderboard handle is invalid.
    :SteamWorks: `GetLeaderboardSortMethod <https://partner.steamgames.com/doc/api/ISteamUserStats#GetLeaderboardSortMethod>`_

    Returns the sort order of a leaderboard handle.

**Example**: See :func:`userStats.getLeaderboardName`'s example.

.. function:: userStats.getLeaderboardDisplayType(steamLeaderboard)

    :param uint64 steamLeaderboard: A leaderboard handle obtained from :func:`userStats.findLeaderboard` or :func:`userStats.findOrCreateLeaderboard`.
    :returns: (`string?`) The display type of the leaderboard, one of "Numeric", "TimeSeconds" or "TimeMilliSeconds". Returns **nil** if the leaderboard handle is invalid.
    :SteamWorks: `GetLeaderboardDisplayType <https://partner.steamgames.com/doc/api/ISteamUserStats#GetLeaderboardDisplayType>`_

    Returns the display type of a leaderboard handle.

**Example**: See :func:`userStats.getLeaderboardName`'s example.

.. function:: userStats.uploadLeaderboardScore(steamLeaderboard, uploadScoreMethod, score, details, callback)

    :param uint64 steamLeaderboard: A leaderboard handle obtained from :func:`userStats.findLeaderboard` or :func:`userStats.findOrCreateLeaderboard`.
    :param string uploadScoreMethod: Do you want to force the score to change, or keep the previous score if it was better? Either "KeepBest" or "ForceUpdate".
    :param number score: The score to upload. Must be a 32-bit integer.
    :param string? details: Optional string with details surrounding the unlocking of this score. Size must be a multiple of four, and at most 256 bytes. Will be converted to an array of 32-bit integers.
    :param function callback: Called asynchronously when this function returns. See below.
    :returns: nothing
    :SteamWorks: `UploadLeaderboardScore <https://partner.steamgames.com/doc/api/ISteamUserStats#UploadLeaderboardScore>`_

    Uploads a user score to a specified leaderboard.

    Details are optional game-defined information which outlines how the user got that score. For example if it's a racing style time based leaderboard you could store the timestamps when the player hits each checkpoint. If you have collectibles along the way you could use bit fields as booleans to store the items the player picked up in the playthrough.

    Uploading scores to Steam is rate limited to 10 uploads per 10 minutes and you may only have one outstanding call to this function at a time.

    **callback(data, err)** receives two arguments:

    * **data** (`table`) -- Similar to `LeaderboardScoreUploaded_t <https://partner.steamgames.com/doc/api/ISteamUserStats#LeaderboardScoreUploaded_t>`_, or **nil** if there was **err** is **true**.

        * **data.success** (`boolean`) -- Was the call successful? Returns **true** if the call was successful, **false** on failure, for example:

            * The amount of details sent exceeds 256 bytes.

            * The leaderboard is set to "Trusted" in App Admin on Steamworks website, and will only accept scores sent from the Steam Web API.
        
        * **data.steamLeaderboard** (`uint64`) -- Handle to the leaderboard that was searched for. A special value is returned if no leaderboard was found.

        * **data.score** (`number`) -- The score that was attempted to set.

        * **data.scoreChanged** (`boolean`) -- **true** if the score on the leaderboard changed otherwise **false** if the existing score was better.

        * **data.globalRankNew** (`number`) -- The new global rank of the user on this leaderboard.

        * **data.globalRankPrevious** (`number`) -- The previous global rank of the user on this leaderboard; 0 if the user had no existing entry in the leaderboard.

    * **err** (`boolean`): **true** if there was any IO error with the request.

**Example**::

    function uploadScoresHelper(handle)
        local score = getScore()
        Steam.userStats.uploadLeaderboardScore(handle, "KeepBest", score, nil, function(data, err)
            if err or not data.success then
                print('Upload score failed')
            else
                print('Upload score success. New rank is: ' .. data.globalRankNew)
            end
        end)
    end

.. function:: userStats.downloadLeaderboardEntries(steamLeaderboard, dataRequest, rangeStart, rangeEnd, callback)
              userStats.downloadLeaderboardEntries(steamLeaderboard, dataRequest, callback)

    :param uint64 steamLeaderboard: A leaderboard handle obtained from :func:`userStats.findLeaderboard` or :func:`userStats.findOrCreateLeaderboard`.
    :param string dataRequest: The type of data request to make. Must be one of "Global", "GlobalAroundUser" or "Friends" (see `ELeaderboardDataRequest <https://partner.steamgames.com/doc/api/ISteamUserStats#ELeaderboardDataRequest>`_).
    :param number rangeStart: The index to start downloading entries relative to **dataRequest**. Must **not** be supplied if **dataRequest** is "Friends".
    :param number rangeEnd: The last index to retrieve entries relative to **dataRequest**. Must **not** be supplied if **dataRequest** is "Friends".
    :param function callback: Called asynchronously when this function returns. See below.
    :returns: nothing
    :SteamWorks: `DownloadLeaderboardEntries <https://partner.steamgames.com/doc/api/ISteamUserStats#DownloadLeaderboardEntries>`_

    Fetches a series of leaderboard entries for a specified leaderboard.

    You can ask for more entries than exist, then this will return as many as do exist.

    If you want to download entries for an arbitrary set of users, such as all of the users on a server then you can use :func:`userStats.downloadLeaderboardEntriesForUsers` **(missing)** which takes an array of Steam IDs.

    **callback(data, err)** receives two arguments:

    * **data** (`table`) -- An array of tables similar to `LeaderboardEntry_t <https://partner.steamgames.com/doc/api/ISteamUserStats#LeaderboardEntry_t>`_, or **nil** if there was **err** is **true**.

        * **data[i].steamIDUser** (`uint64`) -- User who this entry belongs to. You can use :func:`friends.getFriendPersonaName` and :func:`friends.getSmallFriendAvatar` **(missing)** to get more info.

        * **data[i].globalRank** (`number`) -- The global rank of this entry ranging from [1..N], where N is the number of users with an entry in the leaderboard.

        * **data[i].score** (`number`) -- The raw score as set in the leaderboard.

        * **data[i].details** (`string`) -- Details of the entry. String is used as a byte array, so may contain a ``'\0'`` in the middle.

        * **data[i].UGC** (`uint64`) -- Handle for the UGC attached to the entry. A special value if there is none.

    * **err** (`boolean`): **true** if there was any IO error with the request.

.. warning::

    This function has two major differences from the SteamWorks API.
    
    * If the data request is "Friends", you **must not** use the **rangeStart** and **rangeEnd** parameters (see the second example).

    * The callback is not called with a table similar to `LeaderboardScoresDownloaded_t <https://partner.steamgames.com/doc/api/ISteamUserStats#LeaderboardScoresDownloaded_t>`_, and there is no need to use the function `GetDownloadedLeaderboardEntry <https://partner.steamgames.com/doc/api/ISteamUserStats#GetDownloadedLeaderboardEntry>`_, since this is already done for you. The callback already receives a list of objects like `LeaderboardEntry_t <https://partner.steamgames.com/doc/api/ISteamUserStats#LeaderboardEntry_t>`_.

**Examples**::

    function showGlobalEntries(handle)
        Steam.userStats.downloadLeaderboardEntries(handle, 'Global', 1, 1000, function(data, err)
            if err then
                print('Error happened')
            else
                for _, user in ipairs(data) do
                    print('Rank #' .. user.globalRank .. ': ' .. user.score)
                end
            end
        end
    end

::

    function showFriendsEntries(handle)
        Steam.userStats.downloadLeaderboardEntries(handle, 'Friends', function(data, err)
            if err then
                print('Error happened')
            else
                for _, user in ipairs(data) do
                    local name = Steam.friends.getFriendPersonaName(user.steamIDUser)
                    print('Friend ' .. name .. ': ' .. user.score)
                end
            end
        end
    end

Callbacks Reference
-------------------

.. warning::

    Remember callbacks are functions that you should override in order to receive the events, and not call directly.

    Also, you **must** constantly call ``Steam.runCallbacks()`` (preferably in your game loop) in order for your callbacks to be called.


.. function:: userStats.onUserStatsReceived(data)

    :param table data: A table similar to `UserStatsReceived_t <https://partner.steamgames.com/doc/api/ISteamUserStats#UserStatsReceived_t>`_

        * **data.gameID** (`uint64`) -- Game ID that these stats are for.

        * **data.result** (`int`) -- Returns whether the call was successful or not. If the user has no stats, this will be set to 2.

        * **data.steamIDUser** (`uint64`) -- The user whose stats were retrieved.
    :returns: nothing
    :SteamWorks: `UserStatsReceived_t <https://partner.steamgames.com/doc/api/ISteamUserStats#UserStatsReceived_t>`_

    Called when the latest stats and achievements for a specific user (including the local user) have been received from the server.

**Example**::

    function Steam.userStats.onUserStatsReceived(data)
        print('Result: ' .. data.result)
    end
