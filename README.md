# LoRa_Flowerpot
 
Repozitář na semestrální práci do předmětu Sběr a přenos dat.

Návod ke zprovoznění prvního pokusu a připojení k TTN:

- Nainstaluj stm32cubeide
- Stáhni I-CUBE-LRWAN, rozbal.
- Naklonuj tento repozitář do \STM32CubeExpansion_LRWAN_V2.1.0\Projects\B-L072Z-LRWAN1\Applications\LoRaWAN\LoRa_Flowerpot.
- v stm32cubeide dej file - open project from file system - najdi složku LoRa_Flowerpot. stm32Cubeide by mělo automaticky najít i stm32cubeide projekt vnořenej uvnitř.
- zkompiluj a spusť projekt. Nejspíš bude potřeba v cubeide otevřít vnořenou složku stm32cubeide, v ní pravým na projekt (cmwx1zzabz_0xx) a run as.
- připoj se přes sériovku (baud 115200) k desce. Zresetuj pomocí tlačítka. Deska by měla vypsat nějaké údaje o sobě a pak periodicky informovat o neúspěšných pokusech o připojení.
- z údajů si poznamenej device EUI.

Dále na The things stacku: (thethingsnetwork.org -> start building)

- vytvoř novou aplikaci
- add end device -> manually
- nastav:
- 
Freq. plan: 863-870 (SF9 for RX2)

LoRaWAN ver. 1.0.1

Activation mode - OTAA

Additional LoRaWAN capabilities - None

Network Defaults - zaškrtnout Use network's default mac settings

Cluster settings - nezaškrtávat extended backend servers

DevEUI - sem doplň device eui opsané ze sériovky

AppEUI - 0101010101010101

AppKey - 2B7E151628AED2A6ABF7158809CF4F3C (pozn.: TOTO NENÍ BEZPEČNÉ, nechávám ho tu zveřejněné jen pro potřeby prvního příkladu... bude nutno eventuálně nahradit něčím jiným. Tohle je defaultní app key který mají uvedený v tom examplu od STM32)


Teď by mělo být zařízení zaregistrované u TTN a za předpokladu že jsi v dosahu sítě, mělo by se mu podařit (možná až po resetu) připojit. Možno monitorovat po sériovce.

V záložce Live Data by měly začít přibývat zprávy od zařízení. V demu posílá string, postupně inkrementované číslo a pak nějaká defaultní data z examplu (teplotu...). Logika odesílání je v LoRaWAN/App/lora_app.c ve funkci SendTxData. (řádky 427 a dál jsem přidal, nebo viz diffy commitů).

Do the things stack možno přidat parsování stringu a čísla zprávy. Postup:
- otevři payload formatters
- uplink
- vyber custom javascript formatter
- do okna zkopíruj obsah souboru ttstack_demo_formatter.js v kořeni repa
Pak by se měly zobrazované zprávy v live data rovnou parsovat a zobrazovat string.



