class OneRecipe
{
    private Widget                  item;
    private ImageWidget             m_OneItemImage; 
    private MultilineTextWidget     m_OneItem;
    private ButtonWidget            m_OneItemButtonWidget;
    private EditBoxWidget           m_OneItemStorage;

    const string    repairpicPath = "HP_Crafter/scripts/4_World/layout/repairpic.edds";
    const string    paintpicPath = "HP_Crafter/scripts/4_World/layout/paintpic.edds";
	const string    ammopicPath = "HP_Crafter/scripts/4_World/layout/ammopic.edds";
	const string    weaponpicPath = "HP_Crafter/scripts/4_World/layout/weaponpic.edds";
	const string    toolspicPath = "HP_Crafter/scripts/4_World/layout/toolspic.edds";
    const string    craftpicPath = "HP_Crafter/scripts/4_World/layout/craftpic.edds";
	const string    sewingkitpicPath = "HP_Crafter/scripts/4_World/layout/sewingkitpic.edds";
	const string    buildingpicPath = "HP_Crafter/scripts/4_World/layout/buildingpic.edds";
	const string    carpicPath = "HP_Crafter/scripts/4_World/layout/carpic.edds";
	const string    furniturepicPath = "HP_Crafter/scripts/4_World/layout/furniturepic.edds";
	const string    medicpicPath = "HP_Crafter/scripts/4_World/layout/medicpic.edds";
	const string    bookpicPath = "HP_Crafter/scripts/4_World/layout/bookpic.edds";
	const string    housepicPath = "HP_Crafter/scripts/4_World/layout/housepic.edds";
	const string    donatepicPath = "HP_Crafter/scripts/4_World/layout/donatepic.edds";
	const string    voltagepicPath = "HP_Crafter/scripts/4_World/layout/voltagepic.edds";

    PlayerBase player;

    ref CraftItem m_CraftItem;
    int m_Test;
    
    void OneRecipe()
    {
        player = PlayerBase.Cast(GetGame().GetPlayer());
    }

    Widget Init( Widget parent, string name, string type)
    {
        item = GetGame().GetWorkspace().CreateWidgets("HP_Crafter/scripts/4_World/layout/OneItemRecipe.layout", parent);
        m_OneItemImage = ImageWidget.Cast(item.FindAnyWidget("OneItemImage"));
        m_OneItem = MultilineTextWidget.Cast(item.FindAnyWidget("OneItem"));
        m_OneItemButtonWidget = ButtonWidget.Cast(item.FindAnyWidget("OneItemButtonWidget"));
        m_OneItemStorage = EditBoxWidget.Cast(item.FindAnyWidget("OneItemStorage"));

        m_OneItem.SetText(name);
        SetImage(type);
        return item;
    }

    void SetImage(string type)
    {
        if ( !m_OneItemImage.LoadImageFile(0, GetTypePath(type)) )
        {
            m_OneItemImage.LoadImageFile(0, GetVanilaTypePath(type));
        }
    }

    string GetVanilaTypePath(string val)
    {
        switch (val)
        {
            case "repairpic":
                return repairpicPath;
            break;
			 case "paintpic":
                return paintpicPath;
            break;
			 case "ammopic":
                return ammopicPath;
            break;
			 case "weaponpic":
                return weaponpicPath;
            break;
			 case "toolspic":
                return toolspicPath;
            break;
			 case "craftpic":
                return craftpicPath;
            break;
            case "sewingkitpic":
                return sewingkitpicPath;
            break;
			 case "buildingpic":
                return buildingpicPath;
            break;
			 case "carpic":
                return carpicPath;
            break;
			 case "furniturepic":
                return furniturepicPath;
            break;
            case "medicpic":
                return medicpicPath;
            break;
			case "bookpic":
                return bookpicPath;
            break;
			 case "housepic":
                return housepicPath;
            break;
			 case "donatepic":
                return donatepicPath;
            break;
            case "voltagepic":
                return voltagepicPath;
            break;
        }
        return craftpicPath;
    }
	

    string GetTypePath(string val)
    {
        switch (val)
        {
            case "repairpic":
                return player.m_CraftClasses.m_CustomizationSetting.PathTorepairpicImg;
            break;
			 case "paintpic":
                return player.m_CraftClasses.m_CustomizationSetting.PathTopaintpicImg;
            break;
			 case "ammopic":
                return player.m_CraftClasses.m_CustomizationSetting.PathToammopicImg;
            break;
			 case "weaponpic":
                return player.m_CraftClasses.m_CustomizationSetting.PathToweaponpicImg;
            break;
			 case "toolspic":
                return player.m_CraftClasses.m_CustomizationSetting.PathTotoolspicImg;
            break;
			 case "craftpic":
                return player.m_CraftClasses.m_CustomizationSetting.PathTocraftpicImg;
            break;
            case "sewingkitpic":
                return player.m_CraftClasses.m_CustomizationSetting.PathTosewingkitpicImg;
            break;
			 case "buildingpic":
                return player.m_CraftClasses.m_CustomizationSetting.PathTobuildingpicImg;
            break;
			 case "carpic":
                return player.m_CraftClasses.m_CustomizationSetting.PathTocarpicImg;
            break;
			 case "furniturepic":
                return player.m_CraftClasses.m_CustomizationSetting.PathTofurniturepicImg;
            break;
            case "medicpic":
                return player.m_CraftClasses.m_CustomizationSetting.PathTomedicpicImg;
            break;
			 case "bookpic":
                return player.m_CraftClasses.m_CustomizationSetting.PathTobookpicImg;
            break;
			 case "housepic":
                return player.m_CraftClasses.m_CustomizationSetting.PathTohousepicImg;
            break;
			 case "donatepic":
                return player.m_CraftClasses.m_CustomizationSetting.PathTodonatepicImg;
            break;
            case "voltagepic":
                return player.m_CraftClasses.m_CustomizationSetting.PathTovoltagepicImg;
            break;			
        }
        return craftpicPath;
    }

    void SetData(CraftItem itm)
    {
        m_CraftItem = itm;
    }

    void SetDataTEST(int val)
    {
        m_Test = val;
    }
}