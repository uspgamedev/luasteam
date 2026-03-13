package.cpath = package.cpath .. ";./?.dll;./?.so"

local Steam = require("luasteam")

local started = os.clock()
local passed, failed = 0, 0
local current_appid = nil
local stats_callback_fired = false
local request_user_stats_callback_fired = false
local leaderboard_find_callback_fired = false
local leaderboard_download_callback_fired = false

local function mark(name, ok, extra)
    if ok then
        passed = passed + 1
        print("[PASS] " .. name .. (extra and (" -> " .. extra) or ""))
    else
        failed = failed + 1
        print("[FAIL] " .. name .. (extra and (" -> " .. extra) or ""))
    end
end

local function run(name, fn)
    local ok, a, b, c = pcall(fn)
    if ok then
        mark(name, true, a and tostring(a) or nil)
        return true, a, b, c
    end
    mark(name, false, a)
    return false
end

local function expect_type(v, t)
    assert(type(v) == t, "expected " .. t .. ", got " .. type(v))
end

local function to_integer_like(v)
    local tv = type(v)
    if tv == "number" then
        return v
    end
    if tv == "userdata" and v.tonumber then
        return v:tonumber()
    end
    error("expected number or uint64 userdata, got " .. tv)
end

run("Steam.Init", function()
    local ok = Steam.Init()
    assert(ok, "Steam.Init returned false")
    return "initialized"
end)

run("Steam.Utils.GetAppID", function()
    current_appid = Steam.Utils.GetAppID()
    expect_type(current_appid, "number")
    local expected_appid = tonumber(io.open("steam_appid.txt"):read("*a"))
    assert(current_appid == expected_appid, "invalid AppID (expected " .. expected_appid .. ", got " .. current_appid .. ")")
    return current_appid
end)

local mySteamID
run("Steam.User.GetSteamID", function()
    mySteamID = Steam.User.GetSteamID()
    assert(mySteamID ~= nil, "steam id is nil")
    return tostring(mySteamID)
end)

run("Steam.User.BLoggedOn", function()
    local logged = Steam.User.BLoggedOn()
    expect_type(logged, "boolean")
    return logged
end)

run("Steam.User.GetHSteamUser", function()
    local h = Steam.User.GetHSteamUser()
    expect_type(h, "number")
    return h
end)

run("Steam.Apps.BIsSubscribed", function()
    local v = Steam.Apps.BIsSubscribed()
    expect_type(v, "boolean")
    return v
end)

run("Steam.Apps.GetCurrentGameLanguage", function()
    local lang = Steam.Apps.GetCurrentGameLanguage()
    expect_type(lang, "string")
    return lang
end)

run("Steam.Apps.GetAvailableGameLanguages", function()
    local langs = Steam.Apps.GetAvailableGameLanguages()
    expect_type(langs, "string")
    return langs
end)

run("Steam.Friends.GetPersonaName", function()
    local name = Steam.Friends.GetPersonaName()
    expect_type(name, "string")
    return name
end)

run("Steam.Friends.GetPersonaState", function()
    local state = Steam.Friends.GetPersonaState()
    expect_type(state, "number")
    return state
end)

local friend_ids = {}
run("Steam.Friends.GetFriendCount + list friend names", function()
    local count = Steam.Friends.GetFriendCount(Steam.k_EFriendFlagImmediate)
    expect_type(count, "number")
    print("Friends (" .. count .. "):")
    for i = 0, count - 1 do
        local friend_steam_id = Steam.Friends.GetFriendByIndex(i, Steam.k_EFriendFlagImmediate)
        table.insert(friend_ids, friend_steam_id)
        local friend_name = Steam.Friends.GetFriendPersonaName(friend_steam_id)
        print(string.format("  %d) %s (%s)", i + 1, friend_name, tostring(friend_steam_id)))
    end
    return count
end)

if mySteamID ~= nil then
    run("Steam.Friends.GetFriendPersonaName(self)", function()
        local name = Steam.Friends.GetFriendPersonaName(mySteamID)
        expect_type(name, "string")
        return name
    end)

    run("Steam.Friends.GetFriendRelationship(self)", function()
        local rel = Steam.Friends.GetFriendRelationship(mySteamID)
        expect_type(rel, "number")
        return rel
    end)
end

run("Steam.Utils.GetConnectedUniverse", function()
    local universe = Steam.Utils.GetConnectedUniverse()
    expect_type(universe, "number")
    return universe
end)

run("Steam.Utils.GetIPCountry", function()
    local country = Steam.Utils.GetIPCountry()
    expect_type(country, "string")
    return country
end)

run("Steam.Utils.GetServerRealTime", function()
    local t = Steam.Utils.GetServerRealTime()
    expect_type(t, "number")
    return t
end)

run("Steam.Utils.GetSteamUILanguage", function()
    local lang = Steam.Utils.GetSteamUILanguage()
    expect_type(lang, "string")
    return lang
end)

run("Steam.Utils.GetIPCCallCount", function()
    local count = Steam.Utils.GetIPCCallCount()
    expect_type(count, "number")
    return count
end)

run("Steam.Utils.IsSteamInBigPictureMode", function()
    local in_bp = Steam.Utils.IsSteamInBigPictureMode()
    expect_type(in_bp, "boolean")
    return in_bp
end)

run("Steam.Utils.IsOverlayEnabled", function()
    local enabled = Steam.Utils.IsOverlayEnabled()
    expect_type(enabled, "boolean")
    return enabled
end)

run("Steam.Utils.GetSecondsSinceAppActive", function()
    local secs = Steam.Utils.GetSecondsSinceAppActive()
    expect_type(secs, "number")
    return secs
end)

run("Steam.Utils.GetSecondsSinceComputerActive", function()
    local secs = Steam.Utils.GetSecondsSinceComputerActive()
    expect_type(secs, "number")
    return secs
end)

run("Steam.NetworkingUtils.InitRelayNetworkAccess", function()
    Steam.NetworkingUtils.InitRelayNetworkAccess()
    return "ok"
end)

run("Steam.NetworkingUtils.GetRelayNetworkStatus", function()
    local avail, details = Steam.NetworkingUtils.GetRelayNetworkStatus()
    expect_type(avail, "number")
    if details ~= nil then
        assert(details.m_eAvail ~= nil, "missing m_eAvail in relay status struct")
    end
    return avail
end)

run("Steam.NetworkingSockets.InitAuthentication", function()
    local res = Steam.NetworkingSockets.InitAuthentication()
    expect_type(res, "number")
    return res
end)

run("Steam.NetworkingSockets.GetAuthenticationStatus", function()
    local avail, details = Steam.NetworkingSockets.GetAuthenticationStatus()
    expect_type(avail, "number")
    if details ~= nil then
        assert(details.m_eAvail ~= nil, "missing m_eAvail in auth status struct")
    end
    return avail
end)

run("Steam.NetworkingSockets.GetIdentity", function()
    local ok, identity = Steam.NetworkingSockets.GetIdentity()
    expect_type(ok, "boolean")
    if ok then
        assert(identity ~= nil, "identity struct is nil")
    end
    return ok
end)

run("Steam.RemoteStorage.GetFileCount", function()
    local count = Steam.RemoteStorage.GetFileCount()
    expect_type(count, "number")
    return count
end)

run("Steam.RemoteStorage.GetQuota", function()
    local ok, total, available = Steam.RemoteStorage.GetQuota()
    expect_type(ok, "boolean")
    total = to_integer_like(total)
    available = to_integer_like(available)
    return tostring(ok) .. ", total=" .. tostring(total) .. ", available=" .. tostring(available)
end)

run("Steam.RemoteStorage.IsCloudEnabledForAccount", function()
    local enabled = Steam.RemoteStorage.IsCloudEnabledForAccount()
    expect_type(enabled, "boolean")
    return enabled
end)

run("Steam.RemoteStorage.IsCloudEnabledForApp", function()
    local enabled = Steam.RemoteStorage.IsCloudEnabledForApp()
    expect_type(enabled, "boolean")
    return enabled
end)

run("Steam.RemoteStorage.GetFileNameAndSize (all files)", function()
    local count = Steam.RemoteStorage.GetFileCount()
    for i = 0, count - 1 do
        local name, size = Steam.RemoteStorage.GetFileNameAndSize(i)
        expect_type(name, "string")
        expect_type(size, "number")
        print(string.format("  cloud file %d: %s (%d bytes)", i + 1, name, size))
    end
    return count
end)

run("Steam.Matchmaking.GetFavoriteGameCount", function()
    local count = Steam.Matchmaking.GetFavoriteGameCount()
    expect_type(count, "number")
    return count
end)

run("Steam.Apps.GetAppBuildId", function()
    local build = Steam.Apps.GetAppBuildId()
    expect_type(build, "number")
    return build
end)

run("Steam.Apps.BIsSubscribedFromFamilySharing", function()
    local v = Steam.Apps.BIsSubscribedFromFamilySharing()
    expect_type(v, "boolean")
    return v
end)

run("Steam.Apps.BIsTimedTrial", function()
    local active, allowed, played = Steam.Apps.BIsTimedTrial()
    expect_type(active, "boolean")
    expect_type(allowed, "number")
    expect_type(played, "number")
    return tostring(active) .. ", allowed=" .. tostring(allowed) .. ", played=" .. tostring(played)
end)

run("Steam.UserStats.GetNumAchievements + list names", function()
    local count = Steam.UserStats.GetNumAchievements()
    expect_type(count, "number")
    print("Achievements (" .. count .. "):")
    for i = 0, count - 1 do
        local ach_name = Steam.UserStats.GetAchievementName(i)
        expect_type(ach_name, "string")
        local _, achieved, unlock_time = Steam.UserStats.GetAchievementAndUnlockTime(ach_name)
        local title = Steam.UserStats.GetAchievementDisplayAttribute(ach_name, "name")
        local desc = Steam.UserStats.GetAchievementDisplayAttribute(ach_name, "desc")
        local hidden = Steam.UserStats.GetAchievementDisplayAttribute(ach_name, "hidden")
        expect_type(achieved, "boolean")
        expect_type(unlock_time, "number")
        expect_type(title, "string")
        expect_type(desc, "string")
        expect_type(hidden, "string")
        print(string.format(
            "  %d) %s | title=%s | hidden=%s | achieved=%s | unlock_time=%d",
            i + 1,
            ach_name,
            title,
            hidden,
            tostring(achieved),
            unlock_time
        ))
    end
    return count
end)

run("Steam.UGC.GetNumSubscribedItems", function()
    local count = Steam.UGC.GetNumSubscribedItems(false)
    expect_type(count, "number")
    return count
end)

run("Steam.UGC.GetSubscribedItems", function()
    local count = Steam.UGC.GetNumSubscribedItems(false)
    local n, ids = Steam.UGC.GetSubscribedItems(count, false)
    expect_type(n, "number")
    if n > 0 then
        assert(type(ids) == "table", "expected ids table when subscribed items exist")
        for i, published_file_id in ipairs(ids) do
            local state = Steam.UGC.GetItemState(published_file_id)
            local installed, size_on_disk, folder, timestamp = Steam.UGC.GetItemInstallInfo(published_file_id, 1024)
            local has_download_info, downloaded, total = Steam.UGC.GetItemDownloadInfo(published_file_id)
            local dl_a = has_download_info and tostring(to_integer_like(downloaded)) or "n/a"
            local dl_b = has_download_info and tostring(to_integer_like(total)) or "n/a"
            print(string.format(
                "  UGC item %d: id=%s state=%s installed=%s size=%s folder=%s ts=%s downloaded=%s/%s",
                i,
                tostring(published_file_id),
                tostring(state),
                tostring(installed),
                tostring(installed and to_integer_like(size_on_disk) or 0),
                tostring(folder),
                tostring(timestamp),
                dl_a,
                dl_b
            ))
        end
    end
    return n
end)

run("Steam.UserStats.FindLeaderboard + getters + entries", function()
    local candidate_names
    if current_appid == 1636730 then
        candidate_names = { "level_push", "level_val", "level_preorder" }
    elseif current_appid == 480 then
        candidate_names = { "global", "Global", "leaderboard", "Leaderboard", "score", "Score" }
    else
        candidate_names = { "global", "Global", "leaderboard", "Leaderboard" }
    end
    print("Leaderboard candidates for appid " .. tostring(current_appid) .. ": " .. table.concat(candidate_names, ", "))
    local requested = 0
    for _, name in ipairs(candidate_names) do
        local handle = Steam.UserStats.FindLeaderboard(name, function(data, io_fail)
            leaderboard_find_callback_fired = true
            local found = data and (data.m_bLeaderboardFound ~= 0)
            print(string.format("[CALLRESULT] FindLeaderboard name=%s io_fail=%s found=%s", name, tostring(io_fail), tostring(found)))
            if not io_fail and found then
                local lb = data.m_hSteamLeaderboard
                local lb_name = Steam.UserStats.GetLeaderboardName(lb)
                local lb_entries = Steam.UserStats.GetLeaderboardEntryCount(lb)
                local lb_sort = Steam.UserStats.GetLeaderboardSortMethod(lb)
                local lb_display = Steam.UserStats.GetLeaderboardDisplayType(lb)
                print(string.format("  leaderboard: name=%s entries=%d sort=%d display=%d", tostring(lb_name), lb_entries, lb_sort, lb_display))

                local max_entries = math.min(lb_entries, 10)
                local dl_handle = Steam.UserStats.DownloadLeaderboardEntries(
                    lb,
                    Steam.k_ELeaderboardDataRequestGlobal,
                    1,
                    max_entries,
                    function(dl_data, dl_io_fail)
                        leaderboard_download_callback_fired = true
                        if dl_io_fail or not dl_data then
                            print("[CALLRESULT] DownloadLeaderboardEntries failed")
                            return
                        end
                        print(string.format("  downloaded %d leaderboard entries", dl_data.m_cEntryCount))
                        for i = 0, dl_data.m_cEntryCount - 1 do
                            local ok, entry = Steam.UserStats.GetDownloadedLeaderboardEntry(
                                dl_data.m_hSteamLeaderboardEntries,
                                i,
                                0
                            )
                            if ok then
                                print(string.format(
                                    "    #%d user=%s rank=%d score=%d",
                                    i + 1,
                                    tostring(entry.m_steamIDUser),
                                    entry.m_nGlobalRank,
                                    entry.m_nScore
                                ))
                            end
                        end
                    end
                )
                print("  DownloadLeaderboardEntries handle:", tostring(dl_handle))
            end
        end)
        if handle ~= nil then
            requested = requested + 1
        end
    end
    assert(requested > 0, "no leaderboard request was queued")
    return "requested " .. tostring(requested)
end)

Steam.UserStats.OnUserStatsReceived = function(data)
    stats_callback_fired = true
    print("[CALLBACK] UserStatsReceived result=" .. tostring(data.m_eResult))
end

run("Steam.UserStats.GetNumberOfCurrentPlayers", function()
    local handle = Steam.UserStats.GetNumberOfCurrentPlayers(function(data, io_fail)
        print("[CALLRESULT] NumberOfCurrentPlayers io_fail=" .. tostring(io_fail) .. " result=" .. tostring(data.m_cPlayers))
        assert(data.m_bSuccess)
        expect_type(data.m_cPlayers, "number")
    end)
    assert(handle ~= nil, "expected SteamAPICall_t handle")
    return tostring(handle)
end)

run("Steam.UserStats.RequestUserStats(first friend)", function()
    if #friend_ids == 0 then
        return "skipped (no friends)"
    end
    local first_friend = friend_ids[1]
    local handle = Steam.UserStats.RequestUserStats(first_friend, function(data, io_fail)
        request_user_stats_callback_fired = true
        print("[CALLRESULT] RequestUserStats io_fail=" .. tostring(io_fail) .. " result=" .. tostring(data and data.m_eResult))
    end)
    assert(handle ~= nil, "expected SteamAPICall_t handle")
    return tostring(first_friend)
end)

local wait_until = os.clock() + 3.0
while os.clock() < wait_until do
    Steam.RunCallbacks()
end
mark("Steam.RunCallbacks + OnUserStatsReceived callback", stats_callback_fired, stats_callback_fired and "received" or "not received within timeout")
if #friend_ids > 0 then
    mark("Steam.RunCallbacks + RequestUserStats callback", request_user_stats_callback_fired, request_user_stats_callback_fired and "received" or "not received within timeout")
end
mark("Steam.RunCallbacks + FindLeaderboard callback", leaderboard_find_callback_fired, leaderboard_find_callback_fired and "received" or "not received within timeout")
if leaderboard_find_callback_fired then
    mark("Steam.RunCallbacks + DownloadLeaderboardEntries callback", leaderboard_download_callback_fired, leaderboard_download_callback_fired and "received" or "not received (maybe leaderboard missing/empty)")
end

print(string.format("\nFinished in %.2fs: %d passed, %d failed", os.clock() - started, passed, failed))

Steam.Shutdown()

if failed > 0 then
    error("sdk_readonly_smoke example failed")
end
