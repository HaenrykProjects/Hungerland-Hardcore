class CraftManager
{

    ref CraftHud        m_CraftHud;
    ref array<EntityAI> m_AllItems;
    HP_Crafter        m_HPC;
    ref map<string,int> m_ExItems;

    void CraftManager()
    {
        m_ExItems = new map<string, int>();
        m_AllItems = new array<EntityAI>();
    }

    void SetHPC(HP_Crafter wb)
    {
        m_HPC = wb;
    }

    HP_Crafter GetWB()
    {
        return m_HPC;
    }

    void OnKeyPress( int key )
    {
        switch (key)
        {
            case KeyCode.KC_ESCAPE:
                CloseCraft();
            break;
        }
    }

    void RequestCraft()
    {
        if (m_CraftHud || GetGame().GetUIManager().GetMenu()) return;

        m_CraftHud = new CraftHud();
        GetGame().GetUIManager().ShowScriptedMenu( m_CraftHud, NULL );
    }

    void CloseCraft()
    {
        if ( GetGame().GetUIManager().GetMenu() && m_CraftHud)
        {
            GetGame().GetUIManager().Back();
            GetWB().RPCSingleParam(HPCc.CLIENT_REQUEST_FREE_WB, new Param1<HP_Crafter>(GetWB()), true, null);
            SetHPC(null);
        }
    }

    void CreateCraftedItem(CraftItem craftItem)
   {
    // Create Object EntityAI
    EntityAI craftedItem = EntityAI.Cast(GetGame().CreateObject(craftItem.Result, GetWB().GetPosition()));

    // Set Stats Changehealth
    for (int i = 0; i < craftItem.CraftComponents.Count(); i++)
    {
        CraftComponent component = craftItem.CraftComponents.Get(i);

    // component Changehealth stats
        craftedItem.SetHealth(craftedItem.GetMaxHealth() * (component.Changehealth / 100.0)); 
    }

    // Set crafted item to m_AllItems
    m_AllItems.Insert(craftedItem);
   }


    static void SelfChatMessage( string message )
	{ 
        GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(0, "", message, "")); 
    }

    void DeleteEntities()
    {
        for (int i = 0; i < m_AllItems.Count(); i++)
        {
            if (m_AllItems.Get(i))
            GetGame().ObjectDeleteOnClient(m_AllItems.Get(i));
        }
        m_AllItems.Clear();
    }

}
ref CraftManager g_CraftManager;