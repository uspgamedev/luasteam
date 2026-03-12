local Steam = require 'luasteam'

local connection = nil

print("Initializing client...")
local ok = Steam.Init()
local auth = Steam.NetworkingSockets.InitAuthentication()

function Steam.NetworkingSockets.OnSteamNetAuthenticationStatus(data)
    print('Auth status', data.m_eAvail, data.m_debugMsg)
    if data.m_eAvail == 100 and not connection then
        print("Connecting...")
        local addr = Steam.newSteamNetworkingIPAddr {}
        addr:ParseString("127.0.0.1:55556")
        connection = Steam.NetworkingSockets.ConnectByIPAddress(addr, 0, nil)
    end
end

local run = true
function Steam.NetworkingSockets.OnSteamNetConnectionStatusChangedCallback(data)
    if data.m_info.m_eState == Steam.k_ESteamNetworkingConnectionState_ClosedByPeer and data.m_hConn == connection then
        print("Server closed connection.")
        Steam.NetworkingSockets.CloseConnection(connection, 0, "", false)
        run = false
    end
end

local counter = 0
while run do
    Steam.RunCallbacks()

    if connection then
        local n, messages = Steam.NetworkingSockets.ReceiveMessagesOnConnection(connection, 32)

        if n > 0 then
            for j, m in ipairs(messages) do
                print("Received message from connection " .. connection .. ": " .. m:GetData())
                m:Release()
                print("Sending message back...")
                local data = "Hello server! This is the client! Thank you!"
                Steam.NetworkingSockets.SendMessageToConnection(connection, data, #data, Steam.k_nSteamNetworkingSend_Reliable)
            end
        end
    end
end

print("Shutting down...")
Steam.Shutdown()

