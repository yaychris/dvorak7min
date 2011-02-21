/*
 *  lessons.c - the lessons for Dvorak 7min
 *  Copyright (C) 1998-2001  Ragnar Hojland Espinosa
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */ 

#include "lessons.h"

/* name of the lesson, text of the lesson.. you can embed \n's except on
 * the last line.
 *
 *   lesson name should be shorter than 37
 *   lesson text should 6 lines or less, with an end of page marker (\x01)
 *
 * note that as of version 1.2 using ASCII files is possible too.
 */

char *lessons[] =
{ 
    "UH: home row, index fingers",
"\x2"
"uuuu hhhh uuuu hhhh uuuu hhhh uuuu hhhh uuuu hhhh uuuu hhhh uuuu hhhu\n"
"uuuu hhhh uuuu hhhh uuuu hhhh uuuu hhhh huuu uuuh huhu uuhh hhuu uhuh\n"
"uh uh uh uh hu hu hu hu huh huh huh huh huh huh uh huh uh huh uh huuh\n"
"huh h u uh hu uhh huh uhh h u uh hu uhh huh uhh uhuh huhu huuh hu uhh",

    "ET: home row, second fingers",
"\x2"
"eeee tttt eeee tttt eeee tttt eeee tttt eeee tttt eeee tttt eeee tttt\n"
"eeee tttt eeee tttt eeee tttt eeee tttt eeee tttt eeee tttt eeee tttt\n"
"et et et et et et tee tee tee tee tete tete tete tete eet eet eet eet\n"
"t e et te teet tee teet tete et et e et te teet tee teet tete et etet",
    
    "EHTU: comprehensive",
"eeee hhhh tttt uuuu eeee hhhh tttt uuuu eeee hhhh tttt uuuu eeee hhhh\n" 
"eeee hhhh tttt uuuu eeee hhhh tttt uuuu eeee hhhh tttt uuuu eeee hhhh\n"
"\x2"
"hue hue hue hue tutu tutu tutu tutu the the the the he he he he he he\n"
"teeth teeth teeth teeth hu hut hut hute thee thee thee thee tutu tutu\n"
"eh he hue hut teeth teethe the thee tutu eh he hue hut ethe thee tutu",

    "ON: home row, third fingers",
"\x2"
"oooo nnnn oooo nnnn oooo nnnn oooo nnnn oooo nnnn oooo nnnn oooo nnnn\n"
"oooo nnnn oooo nnnn oooo nnnn oooo nnnn oooo nnnn oooo nnnn oooo nnnn\n"
"oooo nnnn no no no no on on on non non non non non non noon noon noon\n"
"oooo nnnn no no no no on on on non non non non non non noon noon noon\n"
"ono ono ono ono no non noon on noo ono no non noon on noo ono non oono",

    "ON: comprehensive",
"eeee hhhh nnnn oooo tttt uuuu eeee hhhh nnnn oooo tttt uuuu ehnotuehnotu\n"
"\x2"   
"en en en en ho ho ho ho ne ne ne ne nu nu nu nu oh oh oh oh to to to to\n"
"hen hen hen hen hoe hoe hoe hoe hot hot hot hot hun hun hun hun nee nee\n"
"nee nee net net net net not not not not nun nun nun nun nut nut nut nut\n"
"one one one one out out out out ten ten ten ten tnt toe toe toe toe ton\n"
"ton ton ton too too too too tot tot tot tot tun tun tun tun tou tou tou"
"\x1"
"hone hone hone hone hoot hoot hoot hoot hunt hunt hunt hunt hone hoot hunt\n"
"neon neon neon neon none none none none note note note note neon none note\n"
"noun noun noun noun onto onto onto onto Otto Otto Otto Otto noun onto Otto\n"
"teen teen teen teen tent tent tent tent then then then then teen tent then\n"
"thou thou thou thou tone tone tone tone toot toot toot toot thou tone toot\n"
"tote tote tote tote tout tout tout tout tune tune tune tune tote tout tune"
"\x1"
"thou thou thou thou tone tone tone tone toot toot toot toot thou tone toot\n"
"tote tote tote tote tout tout tout tout tune tune tune tune tote tout tune\n"
"tenet tenet tenet tenet tenth tenth tenth tenth tooth tooth tooth tooth"
"\x1"
"Tune the tone\n"
"Note the teen not the tutu\n"
"Ten hot teeth tout the tune\n"
"The one nut to tote out the hen\n"
"None hunt out the tenth one ton nun\n"
"Hunt the neon then toot out the tune onto the tent",
   
    "AS: home row, fourth fingers",
"\x2"
"aaaa ssss aaaa ssss aaaa ssss aaaa ssss aaaa ssss aaaa ssss aaaa ssss\n"
"aaaa ssss aaaa ssss aaaa ssss aaaa ssss aaaa ssss aaaa ssss aaaa ssss\n"
"as as as as sa sa sa sa sas sas sas sas ass ass ass ass ass ass ss aa\n"
"as as as as sa sa sa sa sas sas sas sas ass ass ass ass ass ass ss aa\n"
"sass sass sass sass as a sass ass as a sas as a sass ass as a sas asa",

    "AS: comprehensive",
"aaaa eeee hhhh nnnn oooo ssss tttt uuuu aaaa eeee hhhh nnnn oooo ssss\n"
"\x2"   
"ah ah ah ah an an an an at at at at ha ha ha ha so so so so us us use\n"
"ash ash ash ash San San San San sat sat sat sat sees sea sea sea ease\n"
"ease ease ease east east east east Haas Haas Haas Haas Hans Hans Hans\n"
"Hans hash hash hash hash sane sane sane sane sash sash sash sash Sean\n"
"Sean Sean Sean seat seat seat seat Stan Stan Stan Stan Stan seat seat"
"\x1"
"Sean hates tetanus shots\n"
"Eat the toast at ten to noon\n"
"The Taos sun shone as hot as Santa Anna\n"
"Anthea assesses the estate at South Tahoe\n"
"Hotshot Hanna uses these shoes that Shannon soon sees\n"
"At noon on the teahouse Aunt Tess hushes the nauseous host"
"\x1"
"Annette senses the sensuous sunset onset on the Athens sea\n"
"Tess Sutton notates the tenuous state that southeast Houston has seen\n"
"Ethan Ness attests to these Tennessee Senate OSHA statutes to shun Utah",

    "ID: index fingers stretching home",
"\x2"   
"iiii dddd iiii dddd iiii dddd iiii dddd iiii dddd iiii dddd iiii dddd iiii\n"
"id id id id id id id id did did did did did did did did did did did did id\n"
"Didi did id did i Didi did id did i Didi did id did i Didi did id did i id\n"
"uuuu hhhh iiii dddd uuuu hhhh iiii dddd uuuu hhhh iiii dddd uuuu hhhh iiii\n"
"du du du du hi hi hi hi du du du du hi hi hi hi du du du du hi hi hi hi du\n"
"di dud dud dud dud hid hid hid hid dud dud dud dud hid hid hid hid hud hud",

    "Home row",
"aaaa dddd eeee hhhh iiii nnnn oooo ssss tttt uuuu\n"
"aaaa dddd eeee hhhh iiii nnnn oooo ssss tttt uuuu\n"
"\x2"
"Tina is on hiatus instead\n"
"The statue is sent to Santa Anita\n"
"This session is tedious on the tendons"
"\x1"
"That Thai dish is intense on the sinuses\n"
"Onions stain satin so use this Tide on this\n"
"Dan Addison detonated the thousandth headstone\n"
"Estonian nationhood is a notion hidden in Asia\n"
"The tennis enthusiast hides the dots on his hands\n"
"Otis said that sand is the seed that Isis sent us\n"
"\x1"   
"Ted Austin insinuated that Tunisia is in Indonesia\n"
"The Dissonant in the ninth edition hits on the Saudis\n"
"I insist that Adenine is in DNA and that andesine is not\n"
"Deanna and Eddie suntanned on the Tahitian seaside oasis\n"
"Indiana and Ohio do not need donated tissues and headsets\n"
"The attendant initiated an intense sound that suited Odessa\n"
"\x1"   
"The dodo added nine and nineteen and attained nine thousand\n"
"Duane nodded to his sis as he situated his sedan in the shade\n"
"Dennis Hudson is hidden in a distant Tunisian hashish hideout\n"
"Nina and Dana hit the astonished attendee on the head in unison\n"
"Auntie Edith tends to hint that Edna heeds the ideas due to Satan\n"
"The idea that nineteen studious Dadaists assisted Einstein is asinine"
"\x1"
"Todd hesitated in his Datsun then hit the Honda in the side in an\n"
"instantaneous THUD\n"
"The thesis that Dante dated Death is as inane as the attitude that\n"
"Sade stood on Sadness\n"
"A destitute Sudanese assassin insists that sainthood is indeed a\n"
"handout to heathenish idiots",

    "PG: first fingers up",   
"\x2"
"gggg pppp gggg pppp gggg pppp gggg pppp gggg pppp gggg pppp gggg ppp\n"
"gggg pppp gggg pppp gggg pppp gggg pppp gggg pppp gggg pppp gggg ppp\n"
"pg pg pg pg pg pg pg pg pg pg pg pg pg pg pg pg pg pg pg pg pg pg pg\n"
"gp gp gp gp gp gp gp gp gp gp gp gp gp gp gp gp gp gp gp gp gp gp gp\n"
"gggg hhhh pppp uuuu gggg hhhh pppp uuuu gggg hhhh pppp uuuu\n"
"up up up up hug hug hug hug pug pug pug pug pup pup pup pup\n"
"ugh ugh ugh ugh Hugh Hugh Hugh Hugh Pugh Pugh Pugh Pugh",

    "PG: comprehensive",   
"aaaa dddd eeee gggg hhhh iiii nnnn oooo pppp ssss tttt uuuu\n"
"aaaa dddd eeee gggg hhhh iiii nnnn oooo pppp ssss tttt uuuu\n"
"\x2"   
"The Huntington is in Pasadena\n"
"He has one pip on his insignia\n"
"I did not see Patton Against The Gestapo\n"
"I put the sponge onto the peg on the spigot"
"\x1"
"She did not postpone the hepatitis diagnosis\n"
"The USPS sent postage high on August eighteenth\n"
"Pete stops as he peeps at the Pepsi and doughnuts\n"
"Nothing is as stupendous as an independent opinion\n"
"I did not design this gadget that ignites potatoes\n"
"Neptune is the sea god and is the god Poseidon too"
"\x1"
"Do not dispute that pogo is as ingenious as ping pong\n"
"The suggestion that toothpaste is poisonous is stupid\n"
"I suggest that one not go to Saigon in a ship tonight\n"
"Giuseppe pigged out on antipasto and pungent spaghetti\n"
"The pianist is a passionate sap and sings insipid songs\n"
"Angus thought he needed a tenspot to snap up the headphones"
"\x1"
"Gina Esposito supposed that the signpost in Spain said STOP\n"
"The Spanish poet happened to paint his house indigo and sepia\n"
"Gus is assigned to get genuine snapshots inside the USGS ship\n"
"This pennant said Hastings on it and that one said Penn State\n"
"Gas Seepage in the Peugeot stopped the engine at the guidepost\n"
"Patti Eng has a PhD in the thespian sagas on Oedipus and Antigone"
"\x1"
"Tonight the teenage peasants appease the pagan suntanning goddess\n"
"The penguin gasped as its appendage pushed past the Patagonian ship\n"
"Seeing an aging ape eating pudding in a teaspoon is not too desponding\n"
"In this episode the patient hostages hug and sing despite the gunshots\n"
"Espionage at DuPont and Hughes is upsetting to the GOP and the Pentagon\n"
"Doug pauses as he puts the poinsettias and sagging petunias in the teapot"
"\x1"
"The indignant patient ingested a potent dosage to suspend his indigestion\n"
"Upsetting gossip at the pageant had Stephanie and Gina sidestepping opponents\n"
"\n"
"Pat goes sightseeing at the pagoda\n"
"in Shanghai despite the gunshots at its apogee"
"\x1"
"The passage on Pegasus and the Aegean Sea\n"
"upon page eight is a poignant adaptation\n"
"\n"
"In hindsight Stonehenge suggests the\n"
"indigenous geniuses had to depend on the sun and its phases"
"\x1"
"Daphne Stephenson has gone to Ghana and\n"
"Ethiopia and Uganda to audiotape the distinguished singing\n"
"\n"
"The Pope stood in position atop the\n"
"highest point in Santiago as an aghast Angie Diego ingested peanuts",

    ".C: second fingers up",
"\x2"
"cccc .... cccc .... cccc .... cccc .... cccc .... cccc .... cccc ....\n"
"cccc .... cccc .... cccc .... cccc .... cccc .... cccc .... cccc ....\n"
"eeee cccc tttt .... eeee cccc tttt .... eeee cccc tttt .... eeee cccc\n"
"ec ec ec ec tc tc tc tc ec ec ec ec tc tc tc tc ec tc ec tc ec tc ec\n"
"c. c. c. c. t. t. t. t. e. e. e. e. c. c. c. c. t. t. t. t. e. e. e.\n"
"etc. etc. etc. etc. etc. etc. etc. etc. etc. etc. etc. etc. etc. etc.",

    ".C: comprehensive",
"aaaa cccc dddd eeee gggg hhhh iiii nnnn oooo pppp ssss tttt uuuu ....\n"
"aaaa cccc dddd eeee gggg hhhh iiii nnnn oooo pppp ssss tttt uuuu ....\n"
"\x2"   
"I can accept this pecan pie.\n"
"Each disc costs ten cents each.\n"
"The census counts us each decade.\n"
"Couscous is cheapest in Connecticut."
"\x1"
"Cincinnati and Chicago...each U.S.A. cities.\n"
"The didactic speech on Chopin educated Chad.\n"
"Isaac cannot teach us the Chattanooga Choo Choo.\n"
"Scott Chen teaches in oceanic science at Antioch.\n"
"The cadets deduced that such antics caused chaos.\n"
"His stethoscope suggested that Connie had congestion."
"\x1"   
"I contend that a Hitachi scope can decode this speech.\n"
"The octopus descended to the Titanic deep in the ocean.\n"
"U.N.E.S.C.O. accepted a chance at a conspicuous occupation.\n"
"The stagecoach continued to pass the cacti in scenic Tucson.\n"
"Capt. P. T. Cohen needs access to a tactician in this section.\n"
"Insecticide succeeds in contacting the insect in a picosecond."
"\x1"   
"Cognac and scotch is an inconspicuous choice...thought Candace.\n"
"Topnotch associates to authenticate the ancient Cantonese teacups.\n"
"Coco said coaching is a cinch...catch and toss...catch and toss....\n"
"The catchup accident at the picnic depicted Dutch as an apathetic nuisance.\n"
"It is no coincidence that this idiotic sentence has eight concise Cs in it.\n"
"The enthusiastic duchess noticed the Pontiac coupe...and decided to chase it."
"\1"
"I detect a headache...I hope it is not the\n"
"Schnapps and Cocoa I had as a nightcap.\n"
"\n"
"The accountant...the C.P.A...conceded that\n"
"he had on occasion hidden cocaine in a coconut."
"\x1"
"The cautious Canadian statisticians caught\n"
"inconsistencies in the second spacesuit design.\n"
"\n"
"The Ph.D. conducted the Puccini Toccata...\n"
"an acoustic succession in succinct cacophonic staccato notes.",

    ",R: third fingers up",
"\x2"   
"rrrr ,,,, rrrr ,,,, rrrr ,,,, rrrr ,,,, rrrr ,,,, rrrr ,,,,\n"
"rrrr ,,,, rrrr ,,,, rrrr ,,,, rrrr ,,,, rrrr ,,,, rrrr ,,,,\n"
"nnnn oooo rrrr ,,,, nnnn oooo rrrr ,,,, nnnn oooo rrrr ,,,,\n"
"or, or, or, or, or, ro, ro, ro, ro, ro, nor, nor, nor, norn\n"
"or, or, or, or, or, ro, ro, ro, ro, ro, nor, nor, nor, norn\n"
"Orr, Orr, Orr, Orr, Ron, Ron, Ron, Ron, Orono, Orono, Orono",

    ",R: comprehensive",
"aaaa cccc dddd eeee gggg hhhh iiii nnnn oooo pppp rrrr ssss tttt uuuu ,,,, ..\n"
"aaaa cccc dddd eeee gggg hhhh iiii nnnn oooo pppp rrrr ssss tttt uuuu ,,,, ..\n"
"\x2"   
"Schroeder desires a career as an orchestra conductor.\n"
"A recurring procedure irrigates the orchard and the prairie.\n"
"Harrison, Harriet, Arturo, and Christopher are grandparents.\n"
"Reagan arranged an airdrop, near the northern Pretoria corridor."
"\x1"
"The erratic Richard Rodgers production returned to the Curran Theatre.\n"
"Carrie read the transportation report as Rosie rehearsed her transcript.\n"
"Roger that, in the circuit, the resistors and transistors are corroded.\n"
"The grocer reported that the antiperspirant had deteriorated.\n"
"Pierre Renoir regrets that Gerard Depardieu is not in Chatres, as desired.\n"
"Horns are characteristic to the rhinoceros and the Triceratops, a dinosaur."
"\x1"
"Tia Carrere stars, narrates, and is the director in this torrid adaptation.\n"
"Gertrude, in her aristocratic grandeur, returned the carrots at the restaurant.\n"
"The Enterprise surprised Picard as it crisscrossed the restricted stratosphere.\n"
"\n"
"Ritter, a character actor, returned an\n"
"uproarious retort to the irritating chairperson."
"\x1"
"The rhetoric, the grandeur, and the\n"
"scripture interpretation surprised the churchgoer.\n"
"\n"
"The choreographer restrained his rather\n"
"strong terpsichorean urges, and did not dance."
"\x1"
"The oceanographer reports that the interior pressure is inappropriate and\n"
"erroneous, and orders the radar operator to intercept the pursuer.\n"
"\n"
"Ed Harris stars as an arrogant and treacherous paratrooper, interpreting, in\n"
"error, orders to torture a geriatric instructor. Though his side has\n"
"surrendered, he continues to oppress and interrogate the retired grandparent."
"\x1"   
"The aggressor is arrested, arraigned, tried, and, appropriate to the horrors\n"
"he practiced, prosecuted and incarcerated. The granddaughter, a stenographer,\n"
"nurtures her grandpa, and he recuperates, though his arthritis returns.\n"
"\n"
"In retrospect, that paragraph incorporated a preposterous R proportion.",

    "'L: fourth fingers up",   
"\x2"
"llll '''' llll '''' llll '''' llll '''' llll '''' llll '''' llll ''''\n"
"llll '''' llll '''' llll '''' llll '''' llll '''' llll '''' llll ''''\n"
"LLLL \"\"\"\" LLLL \"\"\"\" LLLL \"\"\"\" LLLL \"\"\"\" LLLL \"\"\"\" LLLL \"\"\"\" LLLL \"\"\"\"\n"
"aaaa llll ssss '''' aaaa llll ssss '''' aaaa llll ssss '''' aaaa llll\n"
"all all all all all all la la la la la la A's A's A's A's A's A's A'S\n"
"ala ala ala ala ala ala l's l's l's l's l's l's s's s's s's s's s's s's\n"
"Sal Sal Sal Sal lass lass lass lass lass Sal's Sal's Sal's Sal's Sal's",

    "'L: comprehensive",   
"aaaa cccc dddd eeee gggg hhhh iiii llll nnnn\n"
"oooo pppp rrrr ssss tttt uuuu '''' ,,,, ....\n"
"\x2"   
"\"Hello,\" Ellen laughed, as she collided into Allen.\n"
"In a nutshell, Clinton still had an electoral landslide.\n"
"The alcoholic general staged a coup d'etat in Tallahassee.\n"
"Lucille and Randall cleaned their plates in the candlelight."
"\x1"   
"Leland alleged that \"Gilligan's Island\" is a little illogical.\n"
"Sinead O'Connor's latest single isn't going to appall Russell.\n"
"Colonial landlords near London once said \"ain't,\" not \"isn't.\"\n"
"Caroline D'Arc is an enrollee at that college in Philadelphia.\n"
"Didn't she hear, Cal used lots o' laterals, in the last seconds.\n"
"Eileen O'Hare and Pat O'Shea still shouldn't tell Leslie O'Neill."
"\x1"
"\"This little oriental elephant is a cultural sellout,\" said Helen.\n"
"The illegal planeload o' pollutants hasn't landed at Chicago's O'Hare.\n"
"She'll call Allison in Honolulu, not a local call, on her cellular phone.\n"
"This'll enthrall the linguists...using the letter \"L,\" one can spell\n"
"\"chocolate.\""
"\x1"
"Allegra, an unparalleled intellectual, calculated the celestial latitudes and\n"
"longitudes in her sleep.",

    "YF: index fingers streching up",
"\x2"   
"ffff yyyy ffff yyyy ffff yyyy ffff yyyy ffff yyyy ffff yyyy ffff yyyy\n"
"ffff yyyy ffff yyyy ffff yyyy ffff yyyy ffff yyyy ffff yyyy ffff yyyy\n"
"fy fy fy fy fy fy fy yf yf yf yf yf yf yf ffff gggg hhhh yyyy pppp uuuu\n"
"guy guy guy guy guy guy guy guy guy gyp gyp gyp gyp gyp gyp gyp gyp gyp\n"
"UHF UHF UHF UHF UHF UHF UHF UHF UHF yuh yuh yuh yuh yuh yuh yuh yuh yuh\n"
"huff huff huff huff huff huff huff puff puff puff puff puff puff puff\n"
"puffy puffy puffy puffy puffy puffy puppy puppy puppy puppy puppy puppy",

    "Upper and home rows",
"aaaa cccc dddd eeee ffff gggg hhhh iiii llll nnnn\n"
"oooo pppp rrrr ssss tttt uuuu yyyy '''' ,,,, ....\n"
"aaaa cccc dddd eeee ffff gggg hhhh iiii llll nnnn\n"
"oooo pppp rrrr ssss tttt uuuu yyyy '''' ,,,, ...."
"\x1"
"\x2"
"In Lafayette, crayfish and coffee intensify the lifestyle.\n"
"\"I defy you,\" cried Finley, \"to find a falcon as feathery as Godfrey.\"\n"
"Granny Fay left Cindy a frilly, yet unfortunately frayed, taffeta dress.\n"
"In days of yesteryear, typography did not signify only fonts and typefaces.\n"
"The youthful fantasy of Goofy and Donald left Francine the fallacy that life is\n"
"often funny."
"\x1"
"\"After the fifteenth forfeiture,\" uttered the referee, \"Stanford is,\n"
"officially, ineffectual.\"\n"
"\n"
"Dreyfuss thought fondly of that hefty eyeful of San Francisco's fog, last\n"
"Friday near the ferry."
"\x1"
"Geoffrey's faculty lecture on crystallography and diffraction patterns is\n"
"usually insufficient and faulty.\n"
"\n"
"If you can differentiate psychotherapy and psychoanalysis, or psychiatry and\n"
"psychology, you yourself are a psychologist."
"\x1"
"Yesterday, as they do each payday, Sydney and Clifford playfully ran off to\n"
"the fishery for frothy glasses of Henry's Draft Ale.",
   
    "KM: index fingers down",
"\x2"   
"kkkk mmmm kkkk mmmm kkkk mmmm kkkk mmmm kkkk mmmm kkkk mmmm\n"
"kkkk mmmm kkkk mmmm kkkk mmmm kkkk mmmm kkkk mmmm kkkk mmmm\n"
"km km km km km km km km km km mk mk mk mk mk mk mk mk mk mk\n"
"hhhh kkkk mmmm uuuu hhhh kkkk mmmm uuuu hhhh kkkk mmmm uuuu\n"
"ku ku ku ku ku ku ku ku ku ku mu mu mu mu mu mu mu mu mu mu\n"
"UK UK UK UK UK UK UK UK UK UK UK UK UK UK UK UK UK UK UK UK\n"
"hum hum hum hum hum mum mum mum mum mum muk muk muk muk muk",

    "KM: comprehensive",
"aaaa cccc dddd eeee ffff gggg hhhh iiii kkkk llll mmmm\n"
"nnnn oooo pppp rrrr ssss tttt uuuu yyyy '''' ,,,, ....\n"
"aaaa cccc dddd eeee ffff gggg hhhh iiii kkkk llll mmmm\n"
"nnnn oooo pppp rrrr ssss tttt uuuu yyyy '''' ,,,, ...."
"\x1"
"\x2"
"Kramer asked for skim milk in a melodramatic manner.\n"
"\"My kingdom for a Macintosh,\" Maurice choked out meekly.\n"
"It's more sportsmanlike to say \"checkmate\" than \"knockout.\"\n"
"Emmet felt homesick until Mom sent him that Hallmark Hanukkah card.\n"
"The makeshift cloakroom is a trademark of McKinley's decisionmaking.\n"
"Kim's nickname is \"Kimono,\" an irksome mockery of her days in Yokohama."
"\x1"
"There's not much homemade pumpkin ice cream and Smucker's hot fudge sauce\n"
"remaining.\n"
"\n"
"The filmmaker, in machinelike precision, caught the magma and smoke from the\n"
"immense Mt. Krakatoa on film."
"\x1"
"Stock in Amtrak skyrocketed after McKeon's remark mocking spokesmen,\n"
"gimmickery, and smokescreens in the marketplace.\n"
"\n"
"From Katmandu to Oklahoma, from Stockholm to Kentucky, from Alaska to the\n"
"Kremlin, Kodak film is found in many, many cameras.",

    "JW: second fingers down",
"\x2"   
"jjjj wwww jjjj wwww jjjj wwww jjjj wwww jjjj wwww jjjj wwww\n"
"jjjj wwww jjjj wwww jjjj wwww jjjj wwww jjjj wwww jjjj wwww\n"
"jw jw jw jw jw jw jw jw jw jw jw wj wj wj wj wj wj wj wj wj\n"
"eeee jjjj tttt wwww eeee jjjj tttt wwww eeee jjjj tttt wwww\n"
"ewe ewe ewe ewe ewe jet jet jet jet jet Jew Jew Jew Jew Jew\n"
"wee wee wee wee wee wee wee wet wet wet wet wet wet wet wet\n"
"wet Jewett Jewett Jewett Jewett Jewett Jewett Jewett Jewett",
   
    "JW: comprehensive",
"aaaa cccc dddd eeee ffff gggg hhhh iiii jjjj kkkk llll mmmm\n"
"nnnn oooo pppp rrrr ssss tttt uuuu wwww yyyy '''' ,,,, ....\n"
"aaaa cccc dddd eeee ffff gggg hhhh iiii jjjj kkkk llll mmmm\n"
"nnnn oooo pppp rrrr ssss tttt uuuu wwww yyyy '''' ,,,, ...."
"\x1"
"\x2"   
"Jamestown, New York, that's my home town.\n"
"The Joshua Tree National Monument is known worldwide.\n"
"Jujitsu makes you use your opponent's weight against himself.\n"
"\"Wow,\" he said as his jaw dropped. \"That's a jewel of a wristwatch.\"\n"
"Wanting the water to flow, Irwin twisted the faucet counterclockwise.\n"
"Woodrow Wilson's popularity went downward after the economic slowdown."
"\x1"   
"The old Jewish widow withdrew further, working with the wooden jigsaw.\n"
"Judy wondered if it was worthwhile to walk downtown to the Jewelry store.\n"
"I wonder if that Newsweek on the windowsill has the lowdown on Woolworths.\n"
"\n"
"With awe, Jeremy awkwardly swallowed a whole slew of raisinettes as the\n"
"John Waters film started."
"\x1"
"Wynonna Judd, after a whirlwind tour of the Midwest, waited at the\n"
"Waldorf Astoria for two weeks.\n"
"\n"
"\"Your Majesty,\" wrote Marjorie, \"Nothing justifies prejudice. I can rejoice\n"
"only when there is justice.\""
"\x1"
"The newsletter whitewashed reports of wiretapping in Congresswoman\n"
"Hollingsworth's jurisdiction.\n"
"\n"
"\"Hallelujah,\" wailed the janitor as he jettisoned the typewriter out the\n"
"window. The projectile majestically landed at the junction of Jefferson and\n"
"Winslow streets, just jolting, not injuring, a jogging tourist.",
   
    "QV: third fingers down",   
"\x2"
"qqqq vvvv qqqq vvvv qqqq vvvv qqqq vvvv qqqq vvvv qqqq vvvv\n"
"qqqq vvvv qqqq vvvv qqqq vvvv qqqq vvvv qqqq vvvv qqqq vvvv\n"
"qv qv qv qv qv qv qv qv qv qv qv qv qv qv qv qv qv qv qv qv\n"
"vq vq vq vq vq vq vq vq vq vq vq vq vq vq vq vq vq vq vq vq\n"
"qvq qvq qvq qvq qvq qvq qvq qvq vqv vqv vqv vqv vqv vqv vqv",

    "QV: comprehensive",
"aaaa cccc dddd eeee ffff gggg hhhh iiii jjjj kkkk llll mmmm nnnn\n"
"oooo pppp qqqq rrrr ssss tttt uuuu vvvv wwww yyyy '''' ,,,, ....\n"
"aaaa cccc dddd eeee ffff gggg hhhh iiii jjjj kkkk llll mmmm nnnn\n"
"oooo pppp qqqq rrrr ssss tttt uuuu vvvv wwww yyyy '''' ,,,, ...."
"\x1"
"\x2"
"Mercury and quicksilver are quite the same.\n"
"An acquisitive mind helped Pavlov evolve his theories.\n"
"QVC's involvement with Paramount may give it new verve.\n"
"Vivian's new Volvo unequivocally vanquished her fears of driving.\n"
"According to Pravda, Vladivostok was a quiet village in its Soviet days.\n"
"This unique, opaque liquor does not quench your thirst, it makes you queasy.\n"
"David's vivid imagination and his inquisitive and inventive mind suggest a high IQ."
"\x1"
"If Iraq was equipped to invade and conquer Tel Aviv, the U.S. may have quashed\n"
"that pervasively.\n"
"\n"
"We've never quantitatively proven that a quaver is equivalent to a quiver, only\n"
"qualitatively."
"\x1"
"This revolutionary cardiovascular technique is representative of the\n"
"productivity here in Charlottesville.\n"
"\n"
"\"I've never had such quality hors d'oeuvres,\" Javier said assertively over the\n"
"tranquil sounds of Vivaldi, as he looked over the picturesque headquarters of\n"
"the Vancouver Civic Center."
"\x1"
"Nirvana's inequivalent sequel to their provocative release, Nevermind, is\n"
"inconclusive.  Nevertheless, this quirky yet vivacious trio has evoked a\n"
"progressive sound that very well may give you a new perspective on irreverence.",

    ";Z: fourth fingers down",
"\x2"   
";;;; zzzz ;;;; zzzz ;;;; zzzz ;;;; zzzz ;;;; zzzz ;;;; zzzz\n"
";;;; zzzz ;;;; zzzz ;;;; zzzz ;;;; zzzz ;;;; zzzz ;;;; zzzz\n"
";z ;z ;z ;z ;z ;z ;z ;z ;z ;z ;z :z :z :z :z :z :z :z :z :z\n"
";z ;z ;z ;z ;z ;z ;z ;z ;z ;z ;z :z :z :z :z :z :z :z :z :z\n"
"Z; Z; Z; Z; Z; Z; Z; Z; Z; Z; Z; Z: Z: Z: Z: Z: Z: Z: Z: Z:",

    ";Z: comprehensive",   
"aaaa cccc dddd eeee ffff gggg hhhh iiii jjjj kkkk llll mmmm nnnn oooo\n"
"pppp qqqq rrrr ssss tttt uuuu vvvv wwww yyyy zzzz '''' ,,,, .... ;;;;\n"
"aaaa cccc dddd eeee ffff gggg hhhh iiii jjjj kkkk llll mmmm nnnn oooo\n"
"pppp qqqq rrrr ssss tttt uuuu vvvv wwww yyyy zzzz '''' ,,,, .... ;;;;"
"\x1"
"\x2"   
"Zachary MacKenzie froze in amazement; on the radio in his Mazda he heard\n"
"pizzicato stanzas of Mozart.\n"
"\n"
"Carmen Rodriguez is a citizen of Venezuela; her former spouse, Inigo Martinez,\n"
"and his new wife, Anna Vasquez, have moved to Swaziland or Tanzania."
"\x1"
"A crazed gazelle was whizzing around the zoo; a quizzical giraffe guzzled down\n"
"pizzas through his muzzle; another one merely grazed and dozed; several\n"
"chimpanzees started zigging and zagging; the reptile zone was oozing with\n"
"activity; several lizards hazarded the freezing waters and capsized the fish\n"
"tanks; a dozen grizzlies were waltzing in the plaza.",

    "XB: index fingers streching down",
"\x2"   
"bbbb xxxx bbbb xxxx bbbb xxxx bbbb xxxx bbbb xxxx bbbb xxxx\n"
"bbbb xxxx bbbb xxxx bbbb xxxx bbbb xxxx bbbb xxxx bbbb xxxx\n"
"bx bx bx bx bx bx bx bx bx bx bx bx bx bx bx bx bx bx bx bx\n"
"xb xb xb xb xb xb xb xb xb xb xb xb xb xb xb xb xb xb xb xb\n"
"bbx xbb bbx xbb bbx xbb bbx xbb bbx xbb bbx xbb bbx xbb bbx\n"
"xbx xbx xbx xbx xbx xbx xbx xbx bxb bxb bxb bxb bxb bxb bxb",

    "All rows",
"\x2"   
"Heathcliff Huxtable was played by the inexorable Bill Cosby.\n"
"An inexhaustible supply of benzedrine merely exacerbated his disturbances.\n"
"Bruce Boxleitner explained to the extraterrestrial why Babylon Five was built.\n"
"\n"
"The ambidextrous exhibitor was exhausted by the time he loaded the boxcar\n"
"with hobbyhorses."
"\x1"
"Drop those xeroxes off in the mailbox; I'll get them in the bibliography in\n"
"five days maximum.\n"
"\n"
"Mr. Balboa is pretty flexible with the textbook; it's probably excusable to\n"
"fall a bit behind."
"\x1"
"Why Mr. Baxter went from Bordeaux to the tableaux exhibit in Luxembourg by\n"
"taxicab is inexplicable.\n"
"\n"
"Becky found the Bronx pretty obnoxious; though there was that Caribbean\n"
"restaurant that truly excelled."
"\x1"
"The executives at NBC, CBS, and ABC all found it inexcusable that the BBC was\n"
"so inflexible and xenophobic.\n"
"\n"
"An exuberant Bill Clinton blew into his saxophone before the ambassadors; it\n"
"was an extraordinary experience that nobody could explain.",
    
   /* end of lessons. do not remove these zeroes */
   0, 0
};

