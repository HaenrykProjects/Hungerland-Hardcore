modded class ModItemRegisterCallbacks
{
	  override void RegisterOneHanded( DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior )
    {
		super.RegisterOneHanded( pType, pBehavior );
		
		pType.AddItemInHandsProfileIK("HP_napilnik", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,"dz/anims/anm/player/ik/gear/wrench.anm");
	    pType.AddItemInHandsProfileIK("HP_Oiler", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,"dz/anims/anm/player/ik/weapons/Deagle.anm");
        pType.AddItemInHandsProfileIK("HP_Payalnik", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,"dz/anims/anm/player/ik/weapons/Deagle.anm");
        pType.AddItemInHandsProfileIK("HP_Plata", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,"dz/anims/anm/player/ik/gear/compass.anm");
        pType.AddItemInHandsProfileIK("HP_Battery", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,"dz/anims/anm/player/ik/gear/9v_battery.anm");
        pType.AddItemInHandsProfileIK("HP_Tester", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,"dz/anims/anm/player/ik/gear/cleaning_kit_wood.anm");
        pType.AddItemInHandsProfileIK("HP_Pipe", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,"dz/anims/anm/player/ik/gear/soda_can.anm");
	};  
	
    override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterTwoHanded(pType, pBehavior);

   		pType.AddItemInHandsProfileIK("HP_Anvil", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/BatteryCar.anm");
        pType.AddItemInHandsProfileIK("HP_Drill", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/BatteryCar.anm");
		pType.AddItemInHandsProfileIK("HP_Grinde", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/BatteryCar.anm");
		pType.AddItemInHandsProfileIK("HP_Vise", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/BatteryCar.anm");
		
    }

    override void RegisterHeavy(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterHeavy(pType, pBehavior);
        pType.AddItemInHandsProfileIK("HP_Crafter_Kit", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior, "dz/anims/anm/player/ik/heavy/sea_chest.anm");
    }
}

modded class PlayerBase
{
    ref CraftClasses m_CraftClasses;
    ref array<EntityAI> CargoItems;
    ref map<string, int> DeletItems;
    ItemBase m_PCHP;
    int NumberOfItemsInvolved;
    float RewardHealth;

    bool        CanCraft;

    void PlayerBase()
    {
        CargoItems = new array<EntityAI>();
        DeletItems = new map<string, int>();

        CanCraft = true;
    }

    bool CanCraft()
    {
        return CanCraft;
    }

    void SetCraftDelay()
    {
        CanCraft = false;
        GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( AllowCraft, 2000, false);
    }

    void AllowCraft()
    {
        CanCraft = true;
    }

    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
        if (GetGame().IsClient() || !GetGame().IsMultiplayer())
        {
            if (rpc_type == HPCc.SERVER_SEND_MAIN_DATA)
            {ApplyServerData(ctx);}
            else if (rpc_type == HPCc.SERVER_SEND_CLOSE_MENU)
            {g_CraftManager.CloseCraft();}
        }
        if (GetGame().IsServer() || !GetGame().IsMultiplayer())
        {
            if (rpc_type == HPCc.CLIENT_REQUEST_CRAFT_ITEMS)
            CraftItems(ctx);
        }
    }

    void ApplyServerData(ParamsReadContext ctx)
    {
        Param1<ref CraftClasses> rpb;
        if (!ctx.Read(rpb)) return;

        m_CraftClasses = rpb.param1;
    }

    void CraftItems(ParamsReadContext ctx)
    {
        RewardHealth = 0.0;
        NumberOfItemsInvolved = 0;
        Param2<CraftItem, ItemBase> rpb;
        if (!ctx.Read(rpb)) return;
        m_PCHP = rpb.param2;
        if ( !GetGame().IsMultiplayer() )
        {
            m_PCHP = g_CraftManager.GetWB();
        }
        Print(m_PCHP);
        if (!ScanItems(rpb.param1)) return;
        DeleteIngredients(rpb.param1, rpb.param2);
    }

    void DeleteIngredients(CraftItem arr, ItemBase work)
    {
        CraftItem crtItems = arr;
        ItemBase PCHP = work;
        ItemBase cargoItemIB;
        CargoBase cargoBase;
        int cargoCount;

        cargoBase = PCHP.GetInventory().GetCargo();
        cargoCount = cargoBase.GetItemCount();

        for (int k = 0; k < cargoCount; k++)
        {
            EntityAI crgEnt = cargoBase.GetItem(k);
            if (crgEnt && (!crgEnt.IsRuined() || crgEnt.IsWeapon()))
            {
                CargoItems.Insert(crgEnt);
            }
        }

        for (int i = 0; i < crtItems.CraftComponents.Count(); i++)
        {
            CraftComponent cc = crtItems.CraftComponents.Get(i);
            cargoItemIB = ItemBase.Cast(GetGame().CreateObject(cc.Classname, vector.Zero, false));
            if (cargoItemIB)
            {
                if ((QuantityConversions.HasItemQuantity(cargoItemIB) == 0) || cargoItemIB.IsInherited(Magazine))
                {
                    ItemWithoutQuantity(cc);
                }
                else
                {
                    ItemWithCount(cc, PCHP);
                }

                GetGame().ObjectDelete(cargoItemIB);
            }
        }
        CargoItems.Clear();
        DeletItems.Clear();

        GiveResults(arr);
    }

    void GiveResults(CraftItem itemData)
    {
        CraftItem cragtItem = itemData;
        ItemBase itemReward;
        ItemBase tempIB;
        Magazine pileReward;
        string resultType;
        float needQuantity;
        float q_cur, q_min, q_max;

        resultType = cragtItem.Result;
        needQuantity = cragtItem.ResultCount;

        tempIB = ItemBase.Cast(GetGame().CreateObject(resultType, vector.Zero, false));
        if (!tempIB)
            return;

        QuantityConversions.GetItemQuantity(tempIB, q_cur, q_min, q_max);
        tempIB.Delete();

		if (!q_max) q_max = 1;

        while (needQuantity)
        {
            if (q_max < needQuantity)
            {
                itemReward = ItemBase.Cast(GetGame().CreateObject(resultType, this.GetPosition(), false));
                needQuantity -= q_max;
            }
            else
            {
                itemReward = ItemBase.Cast(GetGame().CreateObject(resultType, this.GetPosition(), false));
                if (Class.CastTo(pileReward, itemReward))
                {
                    pileReward.ServerSetAmmoCount(needQuantity);
                }
                else
                {
                    itemReward.SetQuantity(needQuantity);
                }
                needQuantity = 0;
            }
        }

        if (itemData.ComponentsDontAffectHealth == 0 && NumberOfItemsInvolved > 0)
        {
            RewardHealth = RewardHealth / NumberOfItemsInvolved;
            //itemReward.SetHealth01("","",RewardHealth);
        }
    }

    void ItemWithoutQuantity(CraftComponent cc)
    {
        int amount = cc.Amount;
        string name = cc.Classname;
        int count = CargoItems.Count();
        for (int i = 0; i < count; i++)
        {
            EntityAI ent = CargoItems.Get(i);
            if (ent && (ent.GetType() == name))
            {
                ItemBase item = ItemBase.Cast(ent);
                if (item)
                {
                    RewardHealth = RewardHealth + item.GetHealth01();
                    NumberOfItemsInvolved = NumberOfItemsInvolved + 1;
                    if (cc.Destroy)
                    GetGame().ObjectDelete(item);    
                    else
                    item.AddHealth(cc.Changehealth);

                    amount--;
                    if (!amount) break;
                }
            }
        }
    }


    void ItemWithCount(CraftComponent cc, ItemBase PCHP)
    {
        int amount = cc.Amount;
        string name = cc.Classname;
        int count = CargoItems.Count();
        for (int i = 0; i < count; i++)
        {
            EntityAI ent = CargoItems.Get(i);
            if (ent && (ent.GetType() == name))
            {
                ItemBase item = ItemBase.Cast(ent);
                if (item)
                {
                    RewardHealth = RewardHealth + item.GetHealth01();
                    NumberOfItemsInvolved = NumberOfItemsInvolved + 1;

                    if (cc.Destroy)
                    {
                        if (item.GetQuantity() > amount)
                        {
                            item.AddQuantity(-amount);
                            break;
                        }
                        else
                        {
                            amount -= item.GetQuantity();
                            GetGame().ObjectDelete(item); 
                        }
                    }
                    else
                    {
                        if (item.GetQuantity() > amount)
                        {
                            item.AddQuantity(-amount);
                            ItemBase tempItm = ItemBase.Cast(PCHP.GetInventory().CreateInInventory(item.GetType()));
                            if (!tempItm)
                            tempItm = ItemBase.Cast(GetGame().CreateObject(item.GetType(), PCHP.GetPosition(), false));
                            tempItm.SetQuantity(amount);
                            tempItm.AddHealth(cc.Changehealth);
                            break;
                        }
                        else
                        {
                            amount -= item.GetQuantity();
                            item.AddHealth(cc.Changehealth); 
                        }
                    }
                }
            }
        }
    }

    bool ScanItems(CraftItem arr)
    {
        if (!m_PCHP)
        {
            return false;
        }

        if (!m_PCHP.HasAnyCargo())
        {
            return false;
        }

        CargoBase cargoBase;
        int cargoCount;
        int quant;
        
        cargoBase = m_PCHP.GetInventory().GetCargo();
        cargoCount = cargoBase.GetItemCount();
        for (int c = 0; c < cargoCount; c++)
        {
            ItemBase cargoItemIB;
			if ( Class.CastTo(cargoItemIB, cargoBase.GetItem(c)) && cargoItemIB.IsItemBase() )
            {
                if (cargoItemIB.IsRuined()) continue;
                
                if (cargoItemIB.HasQuantity())
                {
                    quant = cargoItemIB.GetQuantity();
                }
                else
                {
                    quant = 1;
                }

                if (!DeletItems.Contains(cargoItemIB.GetType()))
                {
                    DeletItems.Insert(cargoItemIB.GetType(), quant);
                }
                else
                {
                    int nowQuant = DeletItems.Get(cargoItemIB.GetType());
                    DeletItems.Set(cargoItemIB.GetType(), (nowQuant + quant));
                }
            }
        }

        for (int i = 0; i < arr.CraftComponents.Count(); i++)
        {
            CraftComponent cc = arr.CraftComponents.Get(i);
            int count = DeletItems.Get(cc.Classname);
            if ( count < cc.Amount )
            {return false;}
        }
        DeletItems.Clear();
        return true;
    }

    override void Init()
    {
        if ( !GetGame().IsServer() ||!GetGame().IsMultiplayer() )
        {
            if ( g_CraftServerManager && g_CraftServerManager.m_CraftClasses )
            {
                m_CraftClasses = g_CraftServerManager.m_CraftClasses;
            }
        }
        
        super.Init();
    }
}
