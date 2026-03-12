local Steam = require 'luasteam'

local connections = {}
local server = nil

print("Initializing server...")
Steam.Init()

local auth = Steam.NetworkingSockets.InitAuthentication()

function Steam.NetworkingSockets.OnSteamNetConnectionStatusChangedCallback(data)
    if data.m_info.m_eState == Steam.k_ESteamNetworkingConnectionState_Connecting then
        print("Accepting connection from " .. data.m_hConn)
        Steam.NetworkingSockets.AcceptConnection(data.m_hConn)
    end
    if  data.m_info.m_eState == Steam.k_ESteamNetworkingConnectionState_Connected then
        print("Connected to", data.m_hConn)
        connections[data.m_hConn] = true
        local message = "Hello client! This is the server! Welcome!"
        Steam.NetworkingSockets.SendMessageToConnection(data.m_hConn, message, #message, Steam.k_nSteamNetworkingSend_Reliable)
    end
    if data.m_info.m_eState == Steam.k_ESteamNetworkingConnectionState_ClosedByPeer or data.m_info.m_eState == Steam.k_ESteamNetworkingConnectionState_ProblemDetectedLocally then
        print("Connection closed: " .. data.m_hConn)
        Steam.NetworkingSockets.CloseConnection(data.m_hConn, 0, "", false)
        connections[data.m_hConn] = nil
    end
end

function Steam.NetworkingSockets.OnSteamNetAuthenticationStatus(data)
    print('Auth status', data.m_eAvail, data.m_debugMsg)
    if data.m_eAvail == 100 and not connection then
        local addr = Steam.newSteamNetworkingIPAddr {}
        addr:ParseString("127.0.0.1:55556")
        server = Steam.NetworkingSockets.CreateListenSocketIP(addr, 0, nil)
        print("Listening on port 55556")
    end
end

local run = true

while run do
    Steam.RunCallbacks()

    for conn,_ in pairs(connections) do
        local n, messages = Steam.NetworkingSockets.ReceiveMessagesOnConnection(conn, 32)
        if n > 0 then
            for j,m in ipairs(messages) do
                print("Received message from connection " .. conn .. ": " .. m:GetData())
                run = false
                m:Release()
            end
        end
    end
end

print("Closing connections...")
for conn,_ in pairs(connections) do
    Steam.NetworkingSockets.FlushMessagesOnConnection(conn)
    Steam.NetworkingSockets.CloseConnection(conn, 0, "", false)
end
print("Closing server...")
Steam.NetworkingSockets.CloseListenSocket(server)
Steam.Shutdown()