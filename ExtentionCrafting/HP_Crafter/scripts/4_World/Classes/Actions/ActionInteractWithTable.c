class ActionInteractWithTable : ActionInteractBase
{
	void ActionInteractWithTable()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_HUDCursorIcon = CursorIcons.CloseHood;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	

	override string GetText()
	{
		return "Start";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (GetGame().IsClient())
		{
			HP_Crafter ntarget = HP_Crafter.Cast(  target.GetObject() );
			if(  ntarget )
			{
				return true;
			}
			return false;
		}
		return true;
	}
	
	override void OnExecute( ActionData action_data )
	{
        super.OnExecute( action_data );

        if ( GetGame().IsClient() || !GetGame().IsMultiplayer() )
        {
            HP_Crafter ntarget = HP_Crafter.Cast( action_data.m_Target.GetObject() );
            string message;
            if ( ntarget)
            {
                g_CraftManager.SetHPC(ntarget);
                g_CraftManager.RequestCraft();
            }
        }
	}
}