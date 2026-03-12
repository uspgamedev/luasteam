local Steam = require 'luasteam'

local connections = {}
local server = nil

Steam.Init()

Steam.NetworkingSockets.InitAuthentication()

function Steam.NetworkingSockets.OnSteamNetConnectionStatusChangedCallback(data)
    print ('Connection changed', data.m_hConn, data.m_info.m_eState)
    if data.m_info.m_eState == "Connecting" then
        Steam.NetworkingSockets.AcceptConnection(data.m_hConn)
    end
    if  data.m_info.m_eState == "Connected" then
        connections[data.m_hConn] = true
        local data = "Hello client! This is the server! Welcome!"
        Steam.NetworkingSockets.SendMessageToConnection(data.m_hConn, data, #data, Steam.k_nSteamNetworkingSend_Reliable)
    end
    if data.m_info.m_eState == "ClosedByPeer" or data.m_info.m_eState == "ProblemDetectedLocally" then
        print(data.m_hConn, data.m_info.m_eState)
        Steam.NetworkingSockets.CloseConnection(data.m_hConn, 0, "", false)
        connections[data.m_hConn] = nil
    end
end

function Steam.NetworkingSockets.OnAuthenticationStatus(data)
    if data.m_eAvail == 100 and not connection then
        local addr = Steam.newSteamNetworkingIPAddr {}
        addr:ParseString("127.0.0.1:55556")
        server = Steam.NetPworkingSockets.CreateListenSocketIP(addr, 0, nil)
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
                print("received message", j, m, "from connection", conn, type(j))
                run = false
            end
        end
    end
end

for conn,_ in pairs(connections) do
    Steam.NetworkingSockets.CloseConnection(conn, 0, "", false)
end
Steam.Shutdown()