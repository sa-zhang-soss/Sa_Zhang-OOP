Space Invaders ASCI remake - Sa Zhang

UPUTE ZA INSTALACIJU I POKRETANJE:

- Preduvjet je da imate već instaliran "Visual Studio 2019" ili novije, radnim okruženjem za razvoj u C++.
- Preuzmite datoteke sa GitHubu.
- Pokrenite "Visual Studio"
- Napravite novi project za C++
- U Source Files dodajte sve .cpp datoteke
- U Header Files dodajte sve .hpp i .inl datoteke
- Pokrenite igru sa Ctrl + F5 (build i run)


KONTROLE:

- a: pomicanje ulijevo
- d: pomicanje udesno
- Space: pucanje
- Esc: izlaz iz igre


OPIS:

Ovaj projekt je ASCII remake igre Space Invaders, implementiran u C++. 
Igra se prikazuje kroz konzolu oslanjajući se na funkcije iz Windows.h i conio.h biblioteke.
Projekt je podijeljen u .hpp datoteke i njihove .cpp datoteke u kojoj je implementacija, 
podijeljene je tu radi preglednosti. Koristi se također jedan .inl file u kojoj je implementacija template funkcije, u ovom slučaju se koristi opet radi preglednosti.
U kodu se koristi bazna klasa "Entity", od kojeg su nastale sve ostale klase: "Player","Enemy","Bullet","House".
Loop igre je vrlo jednostavan, enenmies su postavljeni u formaciji i pomiču se lijevo i desno spustajući se za jedan razmak kad dotaknu "border" igre. S vremenom se ubrzavaju (svakih 5s) i imaju 1% šanse da pucaju za svaki "refresh" igre. Player se može pomicati također udesno i ulijevo, puca na enemies sa "Space" i sakuplja bodove s tim da što su udaljeniji enemies vrijede više bodova. Između playera i enemies su kućice koje se unište nakon 3 udarca od enemies. Igra završava: pritiskom na tipku "Esc", time da player izgubi sva 3 života, da player ubije sve enemies prije nego što dođu do njega, i kada enemies dođu do playera. 


PROBLEMI TIJEKOM IZRADE:

- Razvijanje plana strukture klasa
- Sinkronizacija enemies i playera da se kreću propocionalno brzini igre
- Problemi kolizije između enemy, playera i kućica
- Upoznavanje sa Windows.h i conio.h bibliotekama
- Općeniti problemi oko implementacije logike igre


MOGUĆA POBOLJŠANJA:

- Dodavanja više levela (trenutno je samo jedan)
- Različiti enemies s drugčijim ponašanjima
- Power ups
- Vizualna poboljšanja
