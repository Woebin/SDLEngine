Johan Sällström, 9307112814
Theo Walther, 8608220151

Nuvarande implementationsprogram förväntar sig bilder i en mapp som heter \img och ligger under huvudmappen för programmet, men en implementationsprogrammerare kan skriva in absoluta adresser om så önskas och ha bilderna var som helst.
Det enda som händer vid kollision just nu är att fiendeobjektet spelar sin dödsanimation tills spelet slutar.
Spelkontrollerna är för närvarande hårdkodade till att gå i alla riktningar, en implementationsprogrammerare kan sätta xSpeed till 0 för att hindra rörelse i sidled eller ySpeed 0 för att hindra rörelse upp / ner.
Nuvarande implementationsprogram går endast vänster / höger. Animationer spelas bara om relevant hastighet är över noll.
Klassen GameObject representerar det som i instruktionerna refereras till som Sprite, detta för att en sprite enbart är en bild och ett GameObject är mer än så.
