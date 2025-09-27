class CraftClasses
{
    ref CustomizationSetting m_CustomizationSetting = new CustomizationSetting();
    ref array<string> HPCClassnames = new array<string>();
    ref array<ref CraftCategory> CraftCategories = new array<ref CraftCategory>;
}

class CraftCategory
{
    string CategoryName;
    ref array<ref CraftItem> CraftItems = new array<ref CraftItem>();
}

class CraftItem
{
    string Result;
    int    ResultCount;
    int ComponentsDontAffectHealth;
    string CraftType;
    string RecipeName;
    ref array<ref CraftComponent> CraftComponents = new array <ref CraftComponent>();
    ref array <string> AttachmentsNeed = new array<string>();
}

class CraftComponent
{
    string Classname;
    int    Amount;
    bool   Destroy;
    float  Changehealth;
}

class CustomizationSetting
{
    string PathToMainBackgroundImg;
    string PathTorepairpicImg;
    string PathTopaintpicImg;
	string PathToammopicImg;
	string PathToweaponpicImg;
	string PathTotoolspicImg;
    string PathTocraftpicImg;
	string PathTosewingkitpicImg;
	string PathTobuildingpicImg;
	string PathTocarpicImg;
	string PathTofurniturepicImg;
	string PathTomedicpicImg;
	string PathTobookpicImg;
	string PathTohousepicImg;
	string PathTodonatepicImg;
	string PathTovoltagepicImg;
}
