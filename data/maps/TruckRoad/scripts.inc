TruckRoad_MapScripts::
	.byte 0

Route102_EventScript_TruckRaid::
	trainerbattle_no_intro TRAINER_ROAD_GRUNT_1, TruckRaid_Text_RickDefeated
	special HealPlayerParty
	trainerbattle_no_intro TRAINER_ROAD_GRUNT_2, TruckRaid_Text_RickDefeated
	special HealPlayerParty
	trainerbattle_no_intro TRAINER_ROAD_GRUNT_3, TruckRaid_Text_RickDefeated
	end

TruckRaid_Text_RickDefeated:
	.string "Ow! Down and out!$"
