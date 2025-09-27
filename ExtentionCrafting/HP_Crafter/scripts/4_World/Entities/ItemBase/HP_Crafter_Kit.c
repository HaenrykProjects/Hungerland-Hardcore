class HP_Crafter_Kit : DeployableContainer_Base
{
	string GetDeployedClassname()
	{
		return "HP_Crafter";
	}

	vector GetDeployPositionOffset()
	{
		return "0 0 0";
	}

	vector GetDeployOrientationOffset()
	{
		return "180 0 0";
	}

	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);

		if (!GetGame().IsDedicatedServer())
			return;

		PlayerBase pb = PlayerBase.Cast(player);

		if (!pb)
			return;
		
		HP_Crafter bench = HP_Crafter.Cast(GetGame().CreateObject(GetDeployedClassname(), pb.GetLocalProjectionPosition(), false));

		if (!bench)
			return;

		SetIsDeploySound(true);
		bench.SetPosition(position);
		bench.SetOrientation(orientation);
		this.DeleteSafe();
	}

	override bool IsBasebuildingKit()
	{
		return true;
	}

	override bool IsDeployable()
	{
		return true;
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
};