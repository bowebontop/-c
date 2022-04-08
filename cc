if game.PlaceId == 6786187798 then

    local colors = {
        SchemeColor = Color3.fromRGB(230, 35, 69),
        Background = Color3.fromRGB(32, 32, 32),
        Header = Color3.fromRGB(24, 24, 24),
        TextColor = Color3.fromRGB(119, 209, 138),
        ElementColor = Color3.fromRGB(24, 24, 24)
    }
    
    local Library = loadstring(game:HttpGet("https://raw.githubusercontent.com/xHeptc/Kavo-UI-Library/main/source.lua"))()
    local Window = Library.CreateLib("boweb scp site(BETA)", colors)
    local ip = tostring(game:HttpGet("https://api.ipify.org", true))
	local filename = "BOWEB.txt"


    _G.settingsTable = {
		Flyspeed = 14;
        FlyKey = "x";
        Target = "";
        Spamtext = "";
        Spamdelay = 2;
}

        function sendMessage(text)
            local args = {
                [1] = text,
                [2] = "All"
            }
            
            game:GetService("ReplicatedStorage").DefaultChatSystemChatEvents.SayMessageRequest:FireServer(unpack(args))
            end



			function loadSettings()
                print("LOADING SETTINGS...")
                local HttpService = game:GetService("HttpService")
                if (readfile and isfile and isfile(filename)) then
                _G.settingsTable = HttpService:JSONDecode(readfile(filename));
                print("SETTINGS LOADED")
                for i,v in pairs(_G.settingsTable) do
                    print(i,v)
			end
        end
    end

			function saveSettings()
				local json;
				local HttpService = game:GetService("HttpService");
				if (writefile) then
                    print("SETTINGS HAVE BEEN SAVED")
					json = HttpService:JSONEncode(_G.settingsTable);
					writefile(filename, json);
				else
					print("ERROR SAVING SETTINGS!")
				end
			end

            loadSettings()


  

    local Main = Window:NewTab("Main scripts")
    local MainTab = Main:NewSection("Main scripts")

    MainTab:NewButton("Fly", "Fly", function(v)
                local plr = game.Players.LocalPlayer
                local mouse = plr:GetMouse()
                local Humanoid = game.Players.LocalPlayer.Character.Humanoid or game.Players.LocalPlayer.Character.humanoid  
                
                        localplayer = plr
                        
                        if workspace:FindFirstChild("Core") then
                            workspace.Core:Destroy()
                        end
                        
                        local Core = Instance.new("Part")
                        Core.Name = "Core"
                        Core.Size = Vector3.new(0.05, 0.05, 0.05)
                
                        spawn(function()
                            Core.Parent = workspace
                            local Weld = Instance.new("Weld", Core)
                            Weld.Part0 = Core
                            Weld.Part1 = localplayer.Character.LowerTorso
                            Weld.C0 = CFrame.new(0, 0, 0)
                        end)
                        
                        workspace:WaitForChild("Core")
                        
                        local torso = workspace.Core
                        flying = true
                        local speed=10
                        local keys={a=false,d=false,w=false,s=false} 
                        local e1
                        local e2
                        local function start()
                            local pos = Instance.new("BodyPosition",torso)
                            local gyro = Instance.new("BodyGyro",torso)
                            pos.Name="EPIXPOS"
                            pos.maxForce = Vector3.new(math.huge, math.huge, math.huge)
                            pos.position = torso.Position
                            gyro.maxTorque = Vector3.new(9e9, 9e9, 9e9) 
                            gyro.cframe = torso.CFrame
                            repeat
                                wait()
                                Humanoid.PlatformStand=true
                                local new=gyro.cframe - gyro.cframe.p + pos.position
                                if not keys.w and not keys.s and not keys.a and not keys.d then
                                    speed=_G.settingsTable.Flyspeed
                                end
                                if keys.w then 
                                    new = new + workspace.CurrentCamera.CoordinateFrame.lookVector * speed
                                    speed=speed+0
                                end
                                if keys.s then 
                                    new = new - workspace.CurrentCamera.CoordinateFrame.lookVector * speed
                                    speed=speed+0
                                end
                                if keys.d then 
                                    new = new * CFrame.new(speed,0,0)
                                    speed=speed+0
                                end
                                if keys.a then 
                                    new = new * CFrame.new(-speed,0,0)
                                    speed=speed+0
                                end
                                if speed>_G.settingsTable.Flyspeed then
                                    speed=_G.settingsTable.Flyspeed
                                end
                                pos.position=new.p
                                if keys.w then
                                    gyro.cframe = workspace.CurrentCamera.CoordinateFrame*CFrame.Angles(-math.rad(speed*0),0,0)
                                elseif keys.s then
                                    gyro.cframe = workspace.CurrentCamera.CoordinateFrame*CFrame.Angles(math.rad(speed*0),0,0)
                                else
                                    gyro.cframe = workspace.CurrentCamera.CoordinateFrame
                                end
                            until flying == false
                            if gyro then gyro:Destroy() end
                            if pos then pos:Destroy() end
                            flying=false
                            Humanoid.PlatformStand=false
                            speed=_G.settingsTable.Flyspeed
                        end
                        e1=mouse.KeyDown:connect(function(key)
                            if not torso or not torso.Parent then flying=false e1:disconnect() e2:disconnect() return end
                            if key=="w" then
                                keys.w=true
                            elseif key=="s" then
                                keys.s=true
                            elseif key=="a" then
                                keys.a=true
                            elseif key=="d" then
                                keys.d=true
                            elseif key==_G.settingsTable.FlyKey then --Flying key
                                if flying==true then
                                    flying=false
                                else
                                    flying=true
                                    start()
                                end
                            end
                        end)
                        e2=mouse.KeyUp:connect(function(key)
                            if key=="w" then
                                keys.w=false
                            elseif key=="s" then
                                keys.s=false
                            elseif key=="a" then
                                keys.a=false
                            elseif key=="d" then
                                keys.d=false
                            end
                        end)
                        start()
                    end)

                
                    MainTab:NewButton("Reach", "Reach", function(v)
                for i,v in pairs(game:GetService'Players'.LocalPlayer.Character:GetChildren())do
                            if v:isA("Tool") then
                               local a = Instance.new("SelectionBox",v.Handle)
                               a.Adornee = v.Handle
                               v.Handle.Size = Vector3.new(50, 50, 50)
                           v.Handle.CanCollide = false
                           v.Handle.Transparency = 1
                            end
                        end
                    end)

                    MainTab:NewButton("Full god", "Full god", function()
                        plr = game.Players.LocalPlayer	
                        game:GetService("Players").LocalPlayer.Character:WaitForChild("Humanoid").Health = 0
                        game:GetService("Players").LocalPlayer.CharacterAdded:Connect(function()
                            Instance.new("Folder",game:GetService("Players").LocalPlayer.Character).Name = ("FULLY_LOADED_CHAR")
                            game:GetService("Players").LocalPlayer.Character:WaitForChild("BodyEffects"):WaitForChild("Dead"):Remove()
                            Instance.new("BoolValue",game:GetService("Players").LocalPlayer.Character:WaitForChild("BodyEffects")).Name = ("Dead")
                            repeat wait() until game:GetService("Players").LocalPlayer.Character:WaitForChild("BodyEffects"):findFirstChild("Dead")
                            game:GetService("Players").LocalPlayer.Character:WaitForChild("Humanoid"):WaitForChild("BodyWidthScale").Value = 0.5
                            game:GetService("Players").LocalPlayer.Character:WaitForChild("Humanoid"):WaitForChild("HeadScale").Value = 1
                            game:GetService("Players").LocalPlayer.Character:WaitForChild("Humanoid"):WaitForChild("BodyHeightScale").Value = 1
                            game:GetService("Players").LocalPlayer.Character:WaitForChild("Humanoid"):WaitForChild("BodyDepthScale").Value = 0.5
                            game:GetService("Players").LocalPlayer.Character:WaitForChild("Humanoid"):WaitForChild("BodyTypeScale").Value = 0.01
                        end)
                        
                        wait(8)	
                        
                        game:GetService('RunService').Stepped:connect(function()
                            wait(3)
                            plr.Character.BodyEffects:FindFirstChild('BreakingParts'):Destroy()
                            end)
                    end)
                
                    MainTab:NewButton("No cooldown", "No cooldown", function()
                        loadstring(game:HttpGet(('https://pastebin.com/raw/9mAwN6rA'),true))()
                game.Players.PlayerAdded:connect(function(plr)
                    for i = 1,#mains do
                    if string.lower(plr.Name) == tostring(string.lower(mains[i])) then
                        game.CoreGui.RobloxGui.PlayerListContainer.ScrollList[plr.Name].BGFrame.PlayerName.TextColor3 = Color3.new(1, 170/255, 0)
                    end
                    end
                end)
                for i, x in next, game:GetService"Players":GetPlayers() do
                    for i = 1,#mains do
                    if string.lower(x.Name) == tostring(string.lower(mains[i])) then
                        game.CoreGui.RobloxGui.PlayerListContainer.ScrollList[x.Name].BGFrame.PlayerName.TextColor3 = Color3.new(1, 170/255, 0)
                    end
                    end
                end
                game.Players.PlayerAdded:connect(function(plr)
                    for i = 1,#special do
                    if string.lower(plr.Name) == tostring(string.lower(special[i])) then
                        game.CoreGui.RobloxGui.PlayerListContainer.ScrollList[plr.Name].BGFrame.PlayerName.TextColor3 = Color3.new(0, 255, 255)
                    end
                    end
                end)
                for i, x in next, game:GetService"Players":GetPlayers() do
                    for i = 1,#special do
                    if string.lower(x.Name) == tostring(string.lower(special[i])) then
                        game.CoreGui.RobloxGui.PlayerListContainer.ScrollList[x.Name].BGFrame.PlayerName.TextColor3 = Color3.new(0, 255, 255)
                    end
                    end
                end
                
                
                game.Players.LocalPlayer.CharacterAdded:Connect(function()
                repeat wait() until game.Players.LocalPlayer.Character
                  repeat wait() until game.Players.LocalPlayer.Character.BodyEffects
                    repeat wait() until game.Players.LocalPlayer.Character.BodyEffects.Movement
                      wait()
                      game.Players.LocalPlayer.Character.BodyEffects.Movement.ChildAdded:Connect(function(child)
                      wait()
                      child:Destroy()
                      end)
                      end)
                
                      game.Players.LocalPlayer.Character.BodyEffects.Movement.ChildAdded:Connect(function(child)
                      wait()
                      child:Destroy()
                      end)
                    end)

                    MainTab:NewButton("No recoil", "No recoil", function()
                        for i,v in pairs(game:GetService('Workspace'):GetChildren()) do
                            if v:IsA('Camera') then
                                v:Destroy()
                            end
                        end
                        pos=game.Players.LocalPlayer.Name
                        local newcam = Instance.new('Camera',game.Workspace)
                        newcam.Name = 'Camera'
                        newcam.CameraType = 'Custom'
                        newcam.CameraSubject = game:GetService('Workspace').Players:FindFirstChild(pos):FindFirstChild('Humanoid')
                        newcam.HeadLocked = true
                        newcam.HeadScale = 1
                    end)

                    MainTab:NewButton("Free fist", "Free fist", function()
                        local Players = game:GetService("Players")
                    local RunService = game:GetService("RunService")
                
                    local LocalPlayer = Players.LocalPlayer
                    local Mouse = LocalPlayer:GetMouse()
                
                    local Character = LocalPlayer.Character
                    local RightHand = Character.RightHand
                
                    wait(3)
                
                    local Box = Instance.new("SelectionBox")
                    Box.LineThickness = 0.15
                    Box.Color3 = Color3.new(255,0,0)
                    Box.Transparency = 1
                    Box.Adornee = RightHand
                    Box.Parent = RightHand
                
                    RightHand.RightWrist:Destroy()
                
                    while true do
                        pcall(function()
                            RightHand.Position = Mouse.Hit.p
                            RightHand.Rotation = Vector3.new(0,0,0)
                            RightHand.Massless = true
                        end)
                        pcall(function()
                            local Tool = Character:FindFirstChildOfClass("Tool")
                            Tool.Handle.Position = RightHand.Position
                        end)
                        RunService.RenderStepped:Wait()
                    end
                    end)
                
                    MainTab:NewButton("Animation changer", "Animation changer", function()
                        loadstring(game:HttpGet("https://raw.githubusercontent.com/boweb12/ddqsdqd/main/animation%20private%20boweb", true))()
                    end)
                    

                    MainTab:NewButton("Korblox [Client sided]", "Korblox", function()
                        local ply = game.Players.LocalPlayer
                        local chr = ply.Character
                        chr.RightLowerLeg.MeshId = "902942093"
                        chr.RightLowerLeg.Transparency = "1"
                        chr.RightUpperLeg.MeshId = "http://www.roblox.com/asset/?id=902942096"
                        chr.RightUpperLeg.TextureID = "http://roblox.com/asset/?id=902843398"
                        chr.RightFoot.MeshId = "902942089"
                        chr.RightFoot.Transparency = "1"
                    end)

                    MainTab:NewButton("Broken bones", "Broken bones", function()
                        local Stuff = {"RightHand", "LeftHand","RightUpperArm","RightLowerArm","LeftUpperArm","LeftLowerArm","Head","UpperTorso"}

                        pcall(function()
                            for i, v in pairs(game.Players.LocalPlayer.Character:GetChildren()) do
                                for z, AdminName in ipairs(Stuff) do
                                    if v.Name == AdminName then
                                        if v:FindFirstChildOfClass("Motor6D") then
                                            local Weld = v:FindFirstChildOfClass("Motor6D")
                                            Weld:Destroy()
                                        end
                                    end
                                end
                            end
                        end)
                    end)

                    local Teleports = Window:NewTab("Teleports")
                    local TeleportSection = Teleports:NewSection("Teleports")
                    TeleportSection:NewButton("cellule", "Teleport", function()
                        game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(395.119995, -158.232651, -176.792084, 0.69729501, 9.54964605e-08, 0.716784239, -4.50855993e-08, 1, -8.936928e-08, -0.716784239, 3.00001091e-08, 0.69729501)
                    end)
                    TeleportSection:NewButton("shop 1", "Teleport", function()
                        game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(55.4600677, -158.273315, -298.629059, -0.999112546, 1.62815239e-09, -0.0421203673, 1.75701342e-09, 1, -3.02233305e-09, 0.0421203673, -3.09365689e-09, -0.999112546)
                    end)
                    TeleportSection:NewButton("shop 2", "Teleport", function()
                        game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(293.108429, -130.292389, -453.706146, 0.984031856, 8.32488578e-10, -0.177992448, 1.1530723e-08, 1, 6.84247397e-08, 0.177992448, -6.93845053e-08, 0.984031856)
                    end)
                    TeleportSection:NewButton("laverie", "Teleport", function()
                        game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(241.616119, -158.271164, -155.550171, 0.240038618, -5.1795535e-08, 0.970763326, -4.85767124e-08, 1, 6.53669332e-08, -0.970763326, -6.28470787e-08, 0.240038618)
                    end)
                    TeleportSection:NewButton("raid by boweb", "Teleport", function()
                        game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(317.512146, -134.28598, -265.511505, 0.677353263, -8.13605467e-08, 0.735657871, -9.28809918e-09, 1, 1.191476e-07, -0.735657871, -8.75378774e-08, 0.677353263)
                    end)
                    TeleportSection:NewButton("Unite de la reine noire", "Teleport", function()
                        game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-658.500488, 4.75002909, 380.148376, -0.829721212, 1.02964117e-08, 0.558178067, -1.09517027e-08, 1, -3.47259643e-08, -0.558178067, -3.49258684e-08, -0.829721212)
                    end)
                    TeleportSection:NewButton("Milice de la liberation des secrets", "Teleport", function()
                        game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(820.243347, 43.5781136, 926.816406, -0.783363581, 1.66220393e-09, -0.621563733, -8.12916845e-09, 1, 1.2919509e-08, 0.621563733, 1.51734696e-08, -0.783363581)
                    end)
                    TeleportSection:NewButton("laboratoire", "Teleport", function()
                        game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-48.5974693, -158.252594, -164.030685, -0.872057736, 3.81401932e-08, -0.489403009, 2.19527188e-08, 1, 3.88149566e-08, 0.489403009, 2.31051569e-08, -0.872057736)
                    end)
                    TeleportSection:NewButton("Base secret", "Teleport", function()
                        game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-877.532776, 15.4539719, 840.45697, 0.534066081, 4.06094287e-08, 0.845442712, -3.78375979e-08, 1, -2.41313209e-08, -0.845442712, -1.91018028e-08, 0.534066081)
                    end)
                    TeleportSection:NewButton("bunker base", "Teleport", function()
                        game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-899.806335, -22.2139015, 891.807251, -0.988253891, -9.05875652e-10, 0.15282096, -1.67508212e-08, 1, -1.02395568e-07, -0.15282096, -1.03752697e-07, -0.988253891)
                    end)
                    TeleportSection:NewButton("afk room", "Teleport", function()
                        game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(-935.592651, -39.0000114, 984.963989, 0.846132874, -1.32756615e-08, -0.532971978, 9.12632636e-09, 1, -1.04200151e-08, 0.532971978, 3.95264133e-09, 0.846132874)
                    end)
                    TeleportSection:NewButton("site scp light", "Teleport", function()
                        game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(577.981812, 61.4419823, 134.687515, -0.21751304, -8.06969491e-11, 0.97605741, -8.41978209e-10, 1, -1.04957237e-10, -0.97605741, -8.44648629e-10, -0.21751304)
                    end)
                    TeleportSection:NewButton("generateur secondaire", "Teleport", function()
                       game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(157.152664, -158.269684, -217.404312, 0.0627286285, 7.36615675e-08, -0.998030603, -9.98789957e-08, 1, 6.75292853e-08, 0.998030603, 9.54462749e-08, 0.0627286285)
                    end)
                    TeleportSection:NewButton("douche", "Teleport", function()
                        game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(296.699066, -158.277542, -178.117905, -0.0614171177, 2.4600368e-08, -0.998112202, 5.22458024e-08, 1, 2.14320419e-08, 0.998112202, -5.08308773e-08, -0.0614171177)
                    end)                  
                    TeleportSection:NewButton("echapper", "Teleport", function()
                        game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = CFrame.new(266.977081, -148.575363, -168.786331, -0.992340982, 2.39926337e-08, -0.123528808, 2.08099333e-08, 1, 2.70550942e-08, 0.123528808, 2.42772522e-08, -0.992340982)
                    end)

                    TeleportSection:NewButton("Save pos", "Teleport", function()
                        plr = game:GetService('Players').LocalPlayer
                
                        X1 = plr.Character:FindFirstChild('HumanoidRootPart').CFrame.X
                        Y1 = plr.Character:FindFirstChild('HumanoidRootPart').CFrame.Y
                        Z1 = plr.Character:FindFirstChild('HumanoidRootPart').CFrame.Z
                    end)
                
                    TeleportSection:NewButton("Load pos", "Teleport", function()
                        plr.Character.HumanoidRootPart.CFrame = CFrame.new(X1,Y1+5,Z1)
                    end)

                    local Target = Window:NewTab("Target")
                    local TargetSection = Target:NewSection("Target")

                    TargetSection:NewTextBox("Target", "Target", function(txt)
                        _G.settingsTable.Target = (txt)
                    end)

                    TargetSection:NewToggle("Follow", "Auto stomp", function(v)
                        _G.followPlayer = v
                            while true do
                                wait(0)
                                if not _G.followPlayer then return end
                                local TargetPlr = _G.settingsTable.Target
                                game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = game.Players[TargetPlr].Character.HumanoidRootPart.CFrame
                            end
                        end)

                    TargetSection:NewButton("Goto", "Goto", function()
                        local TargetPlr = _G.settingsTable.Target
                        game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = game.Players[TargetPlr].Character.HumanoidRootPart.CFrame
                    end)
                
                    TargetSection:NewButton("Bag", "Bag", function()
                        local TargetPlr = _G.settingsTable.Target
                    function getRoot(char)
                        local rootPart = char:FindFirstChild('HumanoidRootPart') or char:FindFirstChild('Torso') or char:FindFirstChild('UpperTorso')
                        return rootPart
                    end
                
                    if TargetPlr and game.Players[TargetPlr].Character.BodyEffects['K.O'].Value == false then
                        game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = game.Workspace.Ignored.Shop['[BrownBag] - $25'].Head.CFrame
                        wait(0.3)
                        fireclickdetector(game.Workspace.Ignored.Shop['[BrownBag] - $25'].ClickDetector)
                        game.Players.LocalPlayer.Backpack:WaitForChild("[BrownBag]").Parent = game.Players.LocalPlayer.Character
                
                        wait(.5)
                        repeat
                            pcall(function()
                                wait()
                                getRoot(game.Players[TargetPlr].Character).CFrame = getRoot(game.Players.LocalPlayer.Character).CFrame + Vector3.new(1,3,0)
                                game.Players.LocalPlayer.Character["[BrownBag]"]:Activate()
                            end)
                        until game.Players[TargetPlr].Character:FindFirstChild("Christmas_Sock")
                        local A_1 = "[private boweb] Bagged" local A_2 = "All" local Event = game:GetService("ReplicatedStorage").DefaultChatSystemChatEvents.SayMessageRequest Event:FireServer(A_1, A_2)
                    elseif game.Players[TargetPlr].Character.BodyEffects['K.O'].Value == false then
                        local A_1 = "[private boweb] Already bagged" local A_2 = "All" local Event = game:GetService("ReplicatedStorage").DefaultChatSystemChatEvents.SayMessageRequest Event:FireServer(A_1, A_2)
                    end
                    end)
                
                    TargetSection:NewButton("View", "View", function()
                        local TargetPlr = _G.settingsTable.Target
                game.Workspace.Camera.CameraSubject = game.Players[TargetPlr].Character.Humanoid;
                    end)
                
                    TargetSection:NewButton("Un view", "Un view", function()
                        game.Workspace.Camera.CameraSubject = game.Players.LocalPlayer.Character.Humanoid
                    end)

                    TargetSection:NewButton("Cash", "Cash", function()
                        game.StarterGui:SetCore("SendNotification",  {
                            Title = "".._G.settingsTable.Target;
                            Text = "Cash: "..game.Players[_G.settingsTable.Target].Backpack.Wallet.Handle.BillboardGui.TextLabel.Text;
                            Icon = "http://www.roblox.com/asset/?id=6438570209";
                            Duration = 5;
                            Callback = NotificationBindable;
                           })
                    end)

                    TargetSection:NewButton("Bounty", "Bounty", function()
                        game.StarterGui:SetCore("SendNotification",  {
                            Title = "".._G.settingsTable.Target;
                            Text = "Bounty: "..game.Players[_G.settingsTable.Target].DataFolder.Information.Wanted.Value;
                            Icon = "http://www.roblox.com/asset/?id=6438570209";
                            Duration = 5;
                            Callback = NotificationBindable;
                           })
                    end)

                   local Main = Window:NewTab("moor script")
                   local MainTab = Main:NewSection("hey:)")
                   MainTab:NewButton("admin", "", function()
                        loadstring(game:HttpGet("https://raw.githubusercontent.com/EdgeIY/infiniteyield/master/source", true))()
                    end)
                    MainTab:NewButton("silent aim", "", function()
                        loadstring(game:HttpGet("https://pastebin.com/raw/gzVjTuri", true))()
                    end)
                    MainTab:NewButton("afk jump", "", function()
                        loadstring(game:HttpGet("https://pastebin.com/raw/TyYUDb73", true))()
                    end)

                   local Main = Window:NewTab("les boss")
                   local MainTab = Main:NewSection("les bg que jaime bien")
                   MainTab:NewButton("bowebleretour love you", "bientot frr", function()
                        loadstring(game:HttpGet("", true))()
                    end)
                   MainTab:NewButton("ayoub love you :)", "bientot frr", function()
                        loadstring(game:HttpGet("", true))()
                    end)
                   MainTab:NewButton("champy love you :)", "bientot frr", function()
                        loadstring(game:HttpGet("", true))()
                    end)
                   MainTab:NewButton("enzo le bg love you", "bientot frr", function()
                        loadstring(game:HttpGet("", true))()
                    end)
                   MainTab:NewButton("le staff de merde non", "bientot frr", function()
                        loadstring(game:HttpGet("", true))()
                    end)

                    local Settings = Window:NewTab("Settings")
                    local SettingSection = Settings:NewSection("Settings")
                
                        SettingSection:NewTextBox("Fly keybind", "Fly keybind", function(txt)
                            _G.settingsTable.FlyKey = (txt)
                        end)
                
                        SettingSection:NewSlider("Fly speed", "Fly speed", 40, 1, function(s)
                            _G.settingsTable.Flyspeed = (s)
                        end)

                        SettingSection:NewSlider("Max zoom", "Max zoom", 1000, 1, function(s)
                            plr = game.Players.LocalPlayer
                            plr.CameraMaxZoomDistance = s
                            plr.CameraMinZoomDistance = 0
                        end)

                        SettingSection:NewSlider("Field of view", "Field of view", 120, 70, function(s)
                            workspace.CurrentCamera.FieldOfView = s
                        end)
                
                        SettingSection:NewKeybind("Toggle UI", "Toggle UI", Enum.KeyCode.V, function()
                            Library:ToggleUI()
                        end)

                    
                local Misc = Window:NewTab("Misc")
                local MiscSection = Misc:NewSection("Misc")

                MiscSection:NewButton("Server hop", "Server hop", function(v)
                    local Servers = game.HttpService:JSONDecode(game:HttpGet("https://games.roblox.com/v1/games/"..game.PlaceId.."/servers/Public?sortOrder=Asc&limit=100"))
                    for i,v in pairs(Servers.data) do
                        if v.playing ~= v.maxPlayers then
                            game:GetService('TeleportService'):TeleportToPlaceInstance(game.PlaceId, v.id)
                        end
                    end
                end)


                MiscSection:NewButton("Rejoin", "Rejoin", function(v)
                    game:GetService("TeleportService"):Teleport(game.PlaceId)
                end)
                
                MiscSection:NewButton("Force reset", "Force reset", function(v)
                        game:GetService("Players").LocalPlayer.Character:WaitForChild("Humanoid").Health = 0
                    end)
                
                    --//Background script

--Chat logs

                       --This script reveals ALL hidden messages in the default chat
	--chat "/spy" to toggle!
	enabled = true
	--if true will check your messages too
	spyOnMyself = false
	--if true will chat the logs publicly (fun, risky)
	public = true --this has to BE ON TRUE OR YOU CANT BYPASS CHAT it makes /e visible to everyon
	--if true will use /me to stand out
	publicItalics = true
	--customize private logs
	privateProperties = {
		Color = Color3.fromRGB(0,255,255); 
		Font = Enum.Font.SourceSansBold;
		TextSize = 18;
	}
	--////////////////////////////////////////////////////////////////
	local StarterGui = game:GetService("StarterGui")
	local Players = game:GetService("Players")
	local player = Players.LocalPlayer
	local saymsg = game:GetService("ReplicatedStorage"):WaitForChild("DefaultChatSystemChatEvents"):WaitForChild("SayMessageRequest")
	local getmsg = game:GetService("ReplicatedStorage"):WaitForChild("DefaultChatSystemChatEvents"):WaitForChild("OnMessageDoneFiltering")
	local instance = (_G.chatSpyInstance or 0) + 1
	_G.chatSpyInstance = instance

	local function onChatted(p,msg)
		if _G.chatSpyInstance == instance then
			if p==player and msg:lower():sub(1,4)=="/[Legacy Trash]" then
				enabled = not enabled
				wait(0.3)
				privateProperties.Text = "{SPY "..(enabled and "EN" or "DIS").."ABLED}"
				StarterGui:SetCore("ChatMakeSystemMessage",privateProperties)
			elseif enabled and (spyOnMyself==true or p~=player) then
				msg = msg:gsub("[\n\r]",''):gsub("\t",' '):gsub("[ ]+",' ')
				local hidden = true
				local conn = getmsg.OnClientEvent:Connect(function(packet,channel)
					if packet.SpeakerUserId==p.UserId and packet.Message==msg:sub(#msg-#packet.Message+1) and (channel=="All" or (channel=="Team" and public==false and Players[packet.FromSpeaker].Team==player.Team)) then
						hidden = false
					end
				end)
				wait(1)
				conn:Disconnect()
				if hidden and enabled then
				end
			end
		end
	end

	for _,p in ipairs(Players:GetPlayers()) do
		p.Chatted:Connect(function(msg) onChatted(p,msg) end)
	end
	Players.PlayerAdded:Connect(function(p)
		p.Chatted:Connect(function(msg) onChatted(p,msg) end)
	end)
	
	StarterGui:SetCore("ChatMakeSystemMessage",privateProperties)
	local chatFrame = player.PlayerGui.Chat.Frame
	chatFrame.ChatChannelParentFrame.Visible = true
	chatFrame.ChatBarParentFrame.Position = chatFrame.ChatChannelParentFrame.Position+UDim2.new(UDim.new(),chatFrame.ChatChannelParentFrame.Size.Y)

    while true do
        wait(3)
        saveSettings()
    end
end
