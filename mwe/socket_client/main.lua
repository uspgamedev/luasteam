local Steam = require 'luasteam'

local connection = nil

local ok = Steam.Init()
print("Steam init", ok)
local auth = Steam.NetworkingSockets.InitAuthentication()
print("Auth init", auth)

function Steam.NetworkingSockets.onConnectionChanged(data)
    print ('Connection changed', data)
end

function Steam.NetworkingSockets.OnSteamNetAuthenticationStatus(data)
    if data.m_eAvail == 100 and not connection then
        local addr = Steam.newSteamNetworkingIPAddr {}
        addr:ParseString("127.0.0.1:55556")
        connection = Steam.NetworkingSockets.ConnectByIPAddress(addr, 0, nil)
    end
end

local run = true
local counter = 0
local msg_time = nil
while run do
    Steam.RunCallbacks()

    if connection then
        local n, messages = Steam.NetworkingSockets.ReceiveMessagesOnConnection(connection, 32)

        if n > 0 then
            for j, m in ipairs(messages) do
                print("received message", j, m, "from connection", connection)
                local data = "Hello server! This is the client! Thank you!"
                Steam.NetworkingSockets.SendMessageToConnection(connection, data, #data, Steam.k_nSteamNetworkingSend_Reliable)
                m:Release()
                msg_time = os.time()
            end
        end
    end

    if msg_time ~= nil and os.time() > msg_time + 3 then
        run = false
    end
end

Steam.NetworkingSockets.CloseConnection(connection, 0, "", false)
Steam.Shutdown()

