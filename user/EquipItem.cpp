#include "pch-il2cpp.h"
#include "EquipItem.h"

#include "Weapon.h"
#include "Mod.h"

bool EquipItem::Enabled = false;

std::vector<std::pair<int, WEAPON>> selectWeapons = {
    {VK_NUMPAD0, WEAPON::NONE},
    {VK_NUMPAD1, WEAPON::PIZZA},
    {VK_NUMPAD2, WEAPON::MILK},
    {VK_NUMPAD3, WEAPON::BOMB},
    {VK_NUMPAD4, WEAPON::GLOCK},
    {VK_NUMPAD5, WEAPON::KATANA},
    {VK_NUMPAD6, WEAPON::KNIFE},
    {VK_NUMPAD7, WEAPON::PIPE},
    {VK_NUMPAD8, WEAPON::SNOWBALL},
    {VK_NUMPAD9, WEAPON::STICK}
};

bool pressingKey = false;

void EquipItem::Update()
{
    if (!Enabled) return;

    int selectIndex = -1;

    int i = 0;
    for (auto w : selectWeapons)
    {
        int key = w.first;

        if (GetAsyncKeyState(key))
        {
            selectIndex = i;
        }

        i++;
    }

    if (selectIndex == -1)
    {
        pressingKey = false;
    }
    else {
        if (!pressingKey)
        {
            pressingKey = true;
            auto it = selectWeapons[selectIndex];

            Equip(Mod::GetMySteamId(), it.second);
        }
    }
}

void EquipItem::Equip(long long clientId, int weaponId)
{
    auto weapon = GetWeaponById(weaponId);

    int equipId = -1;
    std::string equipName = "HAND";

    if (weapon)
    {
        equipId = weapon->id;
        equipName = weapon->name;
    }

    std::cout << "[EquipItem] " << clientId << " equip " << equipName << " (" << equipId << ")" << std::endl;

    if (clientId == Mod::GetMySteamId())
    {
        Mod::AppendLocalChatMessage(0, "INFO", "Selecting " + equipName);
        ClientSend_SendActiveItem(equipId, NULL);
    }
    else {
        ServerSend_PlayerActiveItem(clientId, weaponId, NULL);
    }
}