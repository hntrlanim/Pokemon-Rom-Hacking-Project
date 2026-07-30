InsideOfTruck_2_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, InsideOfTruck_2_OnFrame
	.byte 0

InsideOfTruck_2_OnFrame:
	map_script_2 VAR_INSIDE_OF_TRUCK_STATE, 0, InsideOfTruck_2_EventScript_GameStart
	.2byte 0

Speaker_Green:
	.string "Green$"

InsideOfTruck_2_EventScript_GameStart:
	lockall
	applymovement LOCALID_INSIDE_OF_TRUCK_2_GREEN, Common_Movement_WalkInPlaceFasterLeft
	setvar VAR_INSIDE_OF_TRUCK_STATE, 1
	releaseall
	end

InsideOfTruck_2_EventScript_RotomBall::
	lockall
	playmoncry SPECIES_ROTOM, CRY_MODE_NORMAL
	showmonpic SPECIES_ROTOM, 1, 3
	msgbox InsideOfTruck_2_Text_DoYouWantRotom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, InsideOfTruck_2_EventScript_CancelSelection
	goto InsideOfTruck_2_EventScript_RivalEeveeBattle
	end

InsideOfTruck_2_Text_DoYouWantRotom:
	.string "This Pokeball contains a Rotom!\n"
	.string "Would you like to take the Rotom?$"

InsideOfTruck_2_EventScript_RivalEeveeBattle::
	lockall
	removeobject LOCALID_INSIDE_OF_TRUCK_ROTOM_BALL
	setflag FLAG_HIDE_ROTOM_STARTER
	givemon SPECIES_ROTOM, 15
	hidemonpic
	message InsideOfTruck_2_Text_RecievedRotom
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	closemessage
	applymovement LOCALID_PLAYER, InsideOfTruck_2_Movement_ReturnGreenRotom
	waitmovement 0
	applymovement LOCALID_INSIDE_OF_TRUCK_2_GREEN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setspeaker Speaker_Green
	msgbox InsideOfTruck_2_Text_PickedRotom, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_INSIDE_OF_TRUCK_2_GREEN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	setspeaker Speaker_Green
	msgbox InsideOfTruck_2_Text_ShouldPickOne, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_INSIDE_OF_TRUCK_2_GREEN, InsideOfTruck_2_Movement_GreenApproachEevee
	waitmovement 0
	delay 30
	setspeaker Speaker_Green
	msgbox InsideOfTruck_2_Text_PickingEevee, MSGBOX_DEFAULT
	closemessage
	removeobject LOCALID_INSIDE_OF_TRUCK_EEVEE_BALL
	setflag FLAG_HIDE_EEVEE_STARTER
	delay 30
	applymovement LOCALID_INSIDE_OF_TRUCK_2_GREEN, InsideOfTruck_2_Movement_GreenReturnEevee
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	delay 10
	setspeaker Speaker_Green
	msgbox InsideOfTruck_2_Text_WeShouldBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_INSIDE_OF_TRUCK_2_GREEN, InsideOfTruck_2_Movement_GreenExcited
	waitmovement 0
	setspeaker Speaker_Green
	msgbox InsideOfTruck_2_Text_ReadyOrNot, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GREEN_TRUCK_ROTOM, InsideOfTruck_2_Text_GreenDefeated
	special HealPlayerParty
	releaseall
	end

InsideOfTruck_2_Text_RecievedRotom:
	.string "You recieved the Professors Rotom!$"

InsideOfTruck_2_Text_PickedRotom:
	.string "So? Which Pokemon did you end up\n"
	.string "going with?\p"
	.string "...\p"
	.string "Rotom, huh? Cool!$"

InsideOfTruck_2_Text_ShouldPickOne:
	.string "Hmm...\n"
	.string "I think I'll pick one too!$"

InsideOfTruck_2_Text_PickingEevee:
	.string "Oh! This looks like an Eevee!\n"
	.string "I'll go with this one then!$"

InsideOfTruck_2_Text_WeShouldBattle:
	.string "Hey! {PLAYER}!\n"
	.string "Since we both have a new Pokemon...\l"
	.string "We should have a battle!\p"
	.string "Come on! We're both champions!\n"
	.string "It'll be just like old times!\p"
	.string "Ooooh! I'm so excited!$"

InsideOfTruck_2_Text_ReadyOrNot:
	.string "Ready or not...\n"
	.string "Here I come!$"

InsideOfTruck_2_Movement_ReturnGreenRotom:
	walk_down
	walk_right
	walk_right
	walk_in_place_up
	step_end

InsideOfTruck_2_Movement_GreenApproachEevee:
	walk_left
	walk_left
	step_end

InsideOfTruck_2_Movement_GreenReturnEevee:
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

InsideOfTruck_2_Movement_GreenExcited:
	walk_in_place_faster_down
	walk_in_place_faster_down
	walk_in_place_faster_down
	walk_in_place_faster_down
	walk_in_place_faster_down
	walk_in_place_faster_down
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

InsideOfTruck_2_EventScript_EeveeBall::
	lockall
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	showmonpic SPECIES_EEVEE, 1, 3
	msgbox InsideOfTruck_2_Text_DoYouWantEevee, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, InsideOfTruck_2_EventScript_CancelSelection
	goto InsideOfTruck_2_EventScript_RivalCastformBattle
	end

InsideOfTruck_2_Text_DoYouWantEevee:
	.string "This Pokeball contains an Eevee!\n"
	.string "Would you like to take the Eevee?$"

InsideOfTruck_2_EventScript_RivalCastformBattle::
	lockall
	removeobject LOCALID_INSIDE_OF_TRUCK_EEVEE_BALL
	setflag FLAG_HIDE_EEVEE_STARTER
	givemon SPECIES_EEVEE, 15
	hidemonpic
	message InsideOfTruck_2_Text_RecievedEevee
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	closemessage
	trainerbattle_no_intro TRAINER_GREEN_TRUCK_EEVEE, InsideOfTruck_2_Text_GreenDefeated
	special HealPlayerParty
	releaseall
	end

InsideOfTruck_2_Text_RecievedEevee:
	.string "You recieved the Professors Eevee!$"

InsideOfTruck_2_EventScript_CastformBall::
	lockall
	playmoncry SPECIES_CASTFORM, CRY_MODE_NORMAL
	showmonpic SPECIES_CASTFORM, 1, 3
	msgbox InsideOfTruck_2_Text_DoYouWantCastform, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, InsideOfTruck_2_EventScript_CancelSelection
	goto InsideOfTruck_2_EventScript_RivalRotomBattle
	end

InsideOfTruck_2_Text_DoYouWantCastform:
	.string "This Pokeball contains a Castform!\n"
	.string "Would you like to take the Castform?$"

InsideOfTruck_2_EventScript_RivalRotomBattle::
	lockall
	removeobject LOCALID_INSIDE_OF_TRUCK_CASTFORM_BALL
	setflag FLAG_HIDE_CASTFORM_STARTER
	givemon SPECIES_CASTFORM, 15
	hidemonpic
	message InsideOfTruck_2_Text_RecievedCastform
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	closemessage
	trainerbattle_no_intro TRAINER_GREEN_TRUCK_CASTFORM, InsideOfTruck_2_Text_GreenDefeated
	special HealPlayerParty
	releaseall
	end

InsideOfTruck_2_Text_RecievedCastform:
	.string "You recieved the Professors Castform!$"

InsideOfTruck_2_Text_GreenDefeated:
	.string "Still as strong as always!$"

InsideOfTruck_2_EventScript_CancelSelection::
	lockall
	closemessage
	hidemonpic
	releaseall
	end

@@@@@@@@@@@@ ALL PREVIOUS CODE @@@@@@@@@@@@

InsideOfTruck_2_EventScript_SetIntroFlags::
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, InsideOfTruck_2_EventScript_SetIntroFlagsMale
	goto_if_eq VAR_RESULT, FEMALE, InsideOfTruck_2_EventScript_SetIntroFlagsFemale
	end

InsideOfTruck_2_EventScript_SetIntroFlagsMale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 3, 10
	releaseall
	end

InsideOfTruck_2_EventScript_SetIntroFlagsFemale::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 12, 10
	releaseall
	end

InsideOfTruck_2_Text_BoxPrintedWithMonLogo:
	.string "The box is printed with a POKéMON logo.\p"
	.string "It's a POKéMON brand moving and\n"
	.string "delivery service.$"
