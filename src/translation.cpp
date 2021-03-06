// Copyright (c) 2018-2019 Emil Engler et al.
// Distributed under the GNU GENERAL PUBLIC LICENSE Version 3, see the accompanying
// file LICENSE.txt or <https://www.gnu.org/licenses/gpl-3.0.html>.
#include "translation.hpp"

std::string sysget::JsonSTR(nlohmann::json j)
{
    return j.get<std::string>();
}

nlohmann::json sysget::language(std::string lang)
{
    // Get country code of the $LANG envrionment variable
    std::string LangCC;
    try {
        LangCC = lang.substr(0, 2);
    }
    catch(int e) {
        LangCC = "en";
    }
    // To format and unformat the JSON please use https://jsonformatter.curiousconcept.com/
    nlohmann::json english = "{\"help\":\"Help of sysget\\nsysget [OPTION] [PACKAGE(S)]\\n\\nsearch [QUERY]\\t\\t\\tsearch for a package in the resporitories\\ninstall [PACKAGE] [PACKAGE]\\tinstall a package from the repos\\nremove [PACKAGE] [PACKAGE]\\tremoves a package\\nautoremove\\t\\t\\tremoves not needed packages (orphans)\\nupdate\\t\\t\\t\\tupdate the database\\nupgrade\\t\\t\\t\\tdo a system upgrade\\nupgrade [PACKAGE] [PACKAGE]\\tupgrade a specific package\\nclean\\t\\t\\t\\tclean the download cache\\nset [NEW MANAGER]\\t\\tset a new package manager\\nhelp\\t\\t\\t\\topen this help page\\nabout\\t\\t\\t\\tview legal informations\",\"choose\":\"Please choose a package manager: \",\"nonum\":\"You need to enter a number\",\"invalidinputrange\":\"Input is out of range\",\"brokenconf\":\"Your config is broken please restart the program to create a new one\",\"errordelconf\":\"Error while deleting broken config file, are you root?\",\"nooperation\":\"Error you need an operation.\\nTry sysget help\",\"noquery\":\"Error, no search query provided\",\"noinstallpkg\":\"Error, no package for the installation provided\",\"noremovepkg\":\"Error, no package for the removal provided\",\"nonewpkgmanager\":\"Error, no new package manager provided\",\"changepkgmanager\":\"Package manager changed to \",\"unknownop\":\"Unknown operation\\nTry sysget help\",\"openconferr\":\"Unable to open config file\",\"assignpkgmanager\":\"Unable to assign package manager, are you root?\",\"invalidsysget_args\":\"Invalid sysget_args file\"}"_json;
    nlohmann::json german = "{\"help\":\"Hilfe von sysget\\nsysget [OPTION] [PAKETE]\\n\\nsearch [BEGRIFF]\\t\\t\\tSucht nach einem Paket in den Repositories\\ninstall [PAKET] [PAKET]\\tInstalliert ein Paket von den Repositories\\nremove [PAKET] [PAKET]\\tentfernt ein Paket\\nautoremove\\t\\t\\tentfernt unnötige Abhängigkeiten\\nupdate\\t\\t\\t\\tAktualisiert die Datenbank\\nupgrade\\t\\t\\t\\tFührt ein Upgrade der installierten Pakete aus\\nupgrade [PAKET] [PAKET]\\tAktualisiere ein spezifisches Paket\\nclean\\t\\t\\t\\tLeere den Cache\\nset [NEUER PACKET MANAGER]\\t\\tÄndert den Paketmanager\\nhelp\\t\\t\\t\\tÖffnet diese Hilfe\\nabout\\t\\t\\t\\tZeigt Legale Informationen\",\"choose\":\"Bitte wähle einen Paketmanager: \",\"nonum\":\"Du musst eine Nummer eingegeben\",\"invalidinputrange\":\"Eingabe is außer Reichweite\",\"brokenconf\":\"Deine Konfiguration ist ungültig, möchtest du eine neue erstellen?\",\"errordelconf\":\"Fehler beim Löschen der Konfigurationsdatei, bist du root?\",\"nooperation\":\"Fehler, keine Operation angegeben.\\nProbiere sysget help\",\"noquery\":\"Fehler, kein Suchbegriff angegeben\",\"noinstallpkg\":\"Fehler, kein Paket für die Installation angegeben\",\"noremovepkg\":\"Fehler, kein Paket für die Entfernung angegeben\",\"nonewpkgmanager\":\"Fehler, kein Paket für die Entfernung angegeben\",\"changepkgmanager\":\"Paket-Manager gewechselt zu: \",\"unknownop\":\"Unbekannte Operating\\nProbiere sysget help\",\"openconferr\":\"Fehler beim öffnen der Konfigurationsdatei\",\"assignpkgmanager\":\"Fehler bei der Zuweisung des Paket-Managers\",\"invalidsysget_args\":\"Fehler in der sysget_args file\"}"_json;
    if(LangCC == "en") {
        return english;
    }
    else if(LangCC == "de") {
        return german;
    }
    // Return english if no other language is available
    return english;
}