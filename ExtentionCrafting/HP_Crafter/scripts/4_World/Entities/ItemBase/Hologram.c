modded class Hologram
{
	override string ProjectionBasedOnParent()
	{
		HP_Crafter_Kit kit = HP_Crafter_Kit.Cast(m_Parent);

		if (kit)
			return kit.GetDeployedClassname();

		return super.ProjectionBasedOnParent();
	}

	override string GetProjectionName(ItemBase item)
	{
		HP_Crafter_Kit kit = HP_Crafter_Kit.Cast(m_Parent);

		if (kit)
			return kit.GetDeployedClassname();

		return super.GetProjectionName(item);
	}

	override EntityAI PlaceEntity(EntityAI entity_for_placing)
	{
		HP_Crafter_Kit kit = HP_Crafter_Kit.Cast(m_Parent);

		if (kit)
			return entity_for_placing;

		return super.PlaceEntity(entity_for_placing);
	}

	override void EvaluateCollision(ItemBase action_item = null)
	{
		if (m_Parent.IsInherited(HP_Crafter_Kit))
		{
			SetIsColliding(false);
			return;
		}

		super.EvaluateCollision(action_item);
	}

	override vector GetDefaultOrientation()
	{
		HP_Crafter_Kit kit = HP_Crafter_Kit.Cast(m_Parent);

		if (kit)
			return super.GetDefaultOrientation() + kit.GetDeployOrientationOffset();

		return super.GetDefaultOrientation();
	}

	override void SetProjectionPosition(vector position)
	{
		HP_Crafter_Kit kit = HP_Crafter_Kit.Cast(m_Parent);

		if (kit)
		{
			m_Projection.SetPosition(position + kit.GetDeployPositionOffset());

			if (IsFloating())
				m_Projection.SetPosition(SetOnGround(position + kit.GetDeployPositionOffset()));

			return;
		}

		super.SetProjectionPosition(position);
	}
};