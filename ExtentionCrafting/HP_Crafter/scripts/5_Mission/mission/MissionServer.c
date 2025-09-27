modded class MissionServer
{
    void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
        super.InvokeOnConnect(player, identity);
        g_CraftServerManager.SendTraderData(player);
    }
}