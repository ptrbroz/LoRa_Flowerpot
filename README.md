# LoRa_Flowerpot
 
Repozitář na semestrální práci do předmětu Sběr a přenos dat.

Návod ke zprovoznění prvního pokusu a připojení k TTN (arduino verze)

- nainstaluj arduino IDE
- soubor -> vlastnosti -> do kolonky Správce dalších desek url přidat: https://grumpyoldpizza.github.io/ArduinoCore-stm32l0/package_stm32l0_boards_index.json
- nástroje -> vývojová deska -> manažér desek - najdi a nainstaluj Tlera Corp STM32L0 Boards
- nástroje -> vývojová deska -> vyber B-L072Z-LRWAN1
- nástroje -> knihovny -> nainstaluj cayenneLPP a beelan lorawan

Teď by melo jit kompilovat arduino sketch.

Pozor, následující taky změněno proti stm32 projektu!
Dále na The things stacku: (thethingsnetwork.org -> start building)

- vytvoř novou aplikaci
- add end device -> manually
- nastav:

Freq. plan: 863-870 (SF9 for RX2)

LoRaWAN ver. 1.0.0

Activation mode - Activation by personalization ABP

Additional LoRaWAN capabilities - None

DevEUI - sem doplň device eui opsané ze sériovky (z projektu STM32... nejspíš to nějak půjde vytáhnout i z arduina, ale ještě jsem nekoukal jak, tak je asi nejsnažší si to opsat z té předchozí aplikace na TTNstacku)

AppEUI - n/a (asi se na to nebude ani ptát)

AppKey - 2B7E151628AED2A6ABF7158809CF4F3C (pozn.: TOTO NENÍ BEZPEČNÉ, nechávám ho tu zveřejněné jen pro potřeby prvního příkladu... bude nutno eventuálně nahradit něčím jiným. Tohle je defaultní app key který mají uvedený v tom examplu od STM32)

AppKey se nastavuje přímo v tom arduino sketchi na začátku

NWksec key, Appskey, device address - pokud se na to bude ptát - tak taky opsat z arduino sketche

Teď by mělo být zařízení zaregistrované u TTN a za předpokladu že jsi v dosahu sítě, mělo by se mu podařit (možná až po resetu) připojit.





