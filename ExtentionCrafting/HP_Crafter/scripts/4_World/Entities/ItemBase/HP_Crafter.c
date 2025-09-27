class HP_Crafter : ItemBase
{
    void HP_Crafter()
    {
        SetAllowDamage( false );
    }

    override void EEOnAfterLoad()
    {
        super.EEOnAfterLoad();

        SetLifetime( GetEconomyProfile().GetLifetime() );
    }

    void SetActions()
	{
		super.SetActions();

        AddAction(ActionInteractWithTable);
	}

    override bool CanPutInCargo (EntityAI parent)
	{
		return false;
	}

    override bool CanPutIntoHands (EntityAI parent)
	{	
		return false;
	}

    override bool CanReleaseAttachment (EntityAI attachment)
    {
        ItemBase item = ItemBase.Cast( attachment );

        if ( item && ( item.IsKindOf( "HP_Crafter" ) || item.IsKindOf( "HP_Anvil" ) || item.IsKindOf( "HP_Drill" ) || item.IsKindOf( "HP_Grinde" ) || item.IsKindOf( "HP_napilnik" ) || item.IsKindOf( "HP_Payalnik" ) || item.IsKindOf( "HP_Oiler" ) || item.IsKindOf( "HP_Vise" ) ) )
        {
            return true;
        }

        return true;
    }
    
    override bool CanRemoveFromCargo (EntityAI parent)
    {
        return CanReleaseAttachment(parent);
    }
    
    override bool CanReleaseCargo (EntityAI cargo)
    {
        return CanReleaseAttachment(cargo);
    }
}
