#include <iostream>
#include "dinstring.hpp"
#include "list.hpp"
#include "Map.hpp"
#include "Item.hpp"
#include "SummonerSpell.hpp"
#include "Summoner.hpp"
#include "Champion.hpp"
using namespace std;

int main()
{

    ///Summoner Spell
    SummonerSpell sprazan();
    SummonerSpell s("Flash", 'F', 300);
    SummonerSpell skopija(s);

    ///Map
    List<DinString> lanes;
    lanes.add(lanes.size() + 1, "TOP");
    lanes.add(lanes.size() + 1, "JUNGLE");
    lanes.add(lanes.size() + 1, "MID");
    lanes.add(lanes.size() + 1, "BOT");
    Map mprazan();
    Map m("Summoner's Rift", 10, lanes);
    Map mkopija(m);

    ///Item
    Item iprazan();
    Ability Hourglass("Hourglass", 50, 0, '1', ITEM_ABILITY);
    Item i(m, "Zhonya's", AP, true, 3400, Hourglass);
    Item ikopija(i);

    ///Skin
    Skin skinprazan();
    Skin skin("Elementalist", 3250, 4, false);
    Skin skinkopija(skin);

    ///Abilities
    Ability a1("Illumination", 0, 0, 'P', PASSIVE);
    Ability a2("Light Binding", 11, 50, 'Q', CC);
    Ability a3("Prismatic Barrier", 14, 60, 'W', SHIELD);
    Ability a4("Lucent Singularity", 10, 70, 'E', DAMAGE);
    Ability a5("Final Spark", 80, 100, 'R', DAMAGE);
    Ability aprazan();
    Ability akopija(a1);

    ///Role
    Role roleprazan();
    Role role(1, 2);
    Role rolekopija(role);

    ///Champion
    List<Ability> abilities;
    abilities.add(abilities.size() + 1, a1);
    abilities.add(abilities.size() + 1, a2);
    abilities.add(abilities.size() + 1, a3);
    abilities.add(abilities.size() + 1, a4);
    abilities.add(abilities.size() + 1, a5);
    List<Skin> skins;
    skins.add(skins.size() + 1, skin);
    Champion Lux("Lux", 3150, 790, 1, role, abilities, skins, 330, 18, 30, 70, 53, 490, 480, 0, 0, 0.669);
    Champion champprazan();
    Champion champkopija(Lux);
    cout << Lux; ///ISPIS-----------------------------------------------------------------------------------------------------------------------------------------------------------

    ///Friend
    Friend friend1("Doktor Smrda", RANKED_PREMADE, true);
    Friend friend2("NoHaxJustSoflo", ONCE_DAY, true);
    Friend friend3("Lofer", NEVER, false);
    Friend fprazan();
    Friend fkopija(friend1);
    List<Friend> friendList;

    ///Currencies
    Currencies moneyprazan();
    Currencies money(5600, 52320);
    Currencies moneykopija(money);

    ///Crafting
    Crafting lootprazan();
    Crafting loot(3, 0, 5, 1270, 5);
    Crafting lootkopija(loot);

    ///Club
    Club IMT("Immortals", "IMT", 6, OWNER, friendList);
    Club APKAH("Arkanove komete", "APKAH", 5, MEMBER, friendList);
    Club clubprazan();
    Club clubkopija(IMT);

    ///Ranked
    Ranked soloduo(DIAMOND, 3, 56, 3400);
    Ranked flex(BRONZE, 1, 24, 1103);
    flex.promote();
    Ranked rankprazan();
    Ranked rankkopija(flex);

    ///Game Stats
    GameStats avgStatsLux(true, 19, 7, 6, 8.43, 21450);
    GameStats game1(true, 13, 4, 10, 8.97, 19870);
    GameStats game2(true, 10, 9, 8, 7.45, 15168);
    GameStats game3(false, 3, 11, 2, 4.76, 11236);
    GameStats gameprazan();
    GameStats gamekopija(game1);

    ///Mastery
    List<GameStats> games;
    games.add(games.size() + 1, game1);
    games.add(games.size() + 1, game2);
    games.add(games.size() + 1, game3);
    Mastery mLux(Lux, 7, 231987, 56, avgStatsLux, games);
    mLux.avarage();
    Mastery masteryprazan();
    Mastery masterykopija(mLux);

    ///Runes
    Primary primary1(SORCERY, 1, 2, 3, "Arcane Comet");
    Secondary secondary1(PRECISION, 1, 2);
    RunePage page1(primary1, secondary1);
    Primary primary2(DOMINATION, 3, 2, 3, "Electrocute");
    Secondary secondary2(RESOLVE, 3, 1);
    RunePage page2(primary2, secondary2);
    Primary primaryprazan();
    Primary primarykopija(primary1);
    Secondary secondaryprazan();
    Secondary secondarykopija(secondary1);
    RunePage pageprazan();
    RunePage pagekopija(page1);

    ///Summoner
    List<Club> clubs;
    clubs.add(clubs.size() + 1, IMT);
    clubs.add(clubs.size() + 1, APKAH);
    List<Mastery> favChamps;
    favChamps.add(favChamps.size() + 1, mLux);
    friendList.add(friendList.size() + 1, friend1);
    friendList.add(friendList.size() + 1, friend2);
    friendList.add(friendList.size() + 1, friend3);
    List<RunePage> runes;
    runes.add(runes.size() + 1, page1);
    runes.add(runes.size() + 1, page2);
    Summoner summonerprazan();
    Summoner OMGitzApple("apple12345", "kontejneR12", "English", EUNE, "OMGitzApple", 105, 67, 3, role, money, loot, flex, soloduo, clubs, favChamps, friendList, runes);
    cout << endl << endl;
    cout << OMGitzApple; ///ISPIS---------------------------------------------------------------------------------------------------------------------------------------------------

    ///Provera operatora
    cout << endl << endl << "PROVERA OPERATORA" << endl;
    Summoner summonerkopija(OMGitzApple);
    Summoner fakeOMGitzApple = summonerkopija;
    if(summonerkopija == fakeOMGitzApple)
        cout << "* Ova dva summonera su ista!" << endl;
    fakeOMGitzApple.setSummName("fakeOMGitzApple");
    fakeOMGitzApple.setSummLevel(160);
    if(OMGitzApple != fakeOMGitzApple)
        cout << "* Ova dva summonera nisu ista!" << endl;
    if(OMGitzApple < fakeOMGitzApple)
        cout << "* Prvi Summoner je manji level od drugog!" << endl;
    if(fakeOMGitzApple > OMGitzApple)
        cout << "* Prvi Summoner je veci level od drugog!" << endl;
    return 0;
}
