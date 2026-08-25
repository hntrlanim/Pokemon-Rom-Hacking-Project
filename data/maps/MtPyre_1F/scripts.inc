MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "All sorts of beings wander the slopes\n"
	.string "of MT. PYRE…\p"
	.string "There is no telling what may happen.\n"
	.string "Take this. It's for your own good.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Have a POKéMON hold that\n"
	.string "CLEANSE TAG.\p"
	.string "It will help ward off wild POKéMON.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Did you come to pay your respect\n"
	.string "to the spirits of departed POKéMON?\p"
	.string "You must care for your POKéMON a lot.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "This is the final resting place of my\n"
	.string "ZIGZAGOON. I cherished it…$"

MtPyre_1F_EventScript_AquaTag1::
	lockall
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_MALEGRUNT1, Common_Movement_ExclamationMark
	applymovement LOCALID_FEMALEGRUNT1, Common_Movement_ExclamationMark
	waitmovement 0
	delay 60
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox MtPyre_2F_Text_LeahIntro, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox MtPyre_2F_Text_ZanderIntro, MSGBOX_DEFAULT
	multi_2_vs_2 TRAINER_LEAH, MtPyre_2F_Text_LeahDefeat, TRAINER_ZANDER, MtPyre_2F_Text_ZanderDefeat, PARTNER_PHOEBE
	setvar VAR_PYRETAG_1, 1
	releaseall
	end

MtPyre_1F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_1F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

