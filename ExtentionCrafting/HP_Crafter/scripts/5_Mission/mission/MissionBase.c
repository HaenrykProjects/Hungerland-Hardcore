modded class MissionBase
{
    override void OnInit()
    {
        super.OnInit();

        if ( GetGame().IsServer() || !GetGame().IsMultiplayer() )
        {
            g_CraftServerManager = new CraftServerManager();
            g_CraftServerManager = CraftServerManager.LoadData();
        }
    }
}