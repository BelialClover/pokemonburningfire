EventScript_PkmnCenterNurse:: @ 81A6578
	goto_if_questlog EventScript_ReleaseEnd
	goto EventScript_PkmnCenterNurse_HealPkmn
	end

EventScript_PkmnCenterNurse_HealPkmn:: @ 81A65B8
	incrementgamestat GAME_STAT_USED_POKECENTER
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
	special SetUsedPkmnCenterQuestLogEvent
	goto EventScript_PkmnCenterNurse_CheckTrainerTowerAndUnionRoom
	end

EventScript_PkmnCenterNurse_TakeAndHealPkmn:: @ 81A65CE
	applymovement VAR_LAST_TALKED, Movement_WalkInPlaceFastestLeft
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_LAST_TALKED, Movement_WalkInPlaceFastestDown
	waitmovement 0
	special HealPlayerParty
	applymovement OBJ_EVENT_ID_PLAYER, Movement_FaceDown
	waitmovement 0
	return

EventScript_PkmnCenterNurse_CheckTrainerTowerAndUnionRoom:: @ 81A65EC
	specialvar VAR_RESULT, IsPlayerNotInTrainerTowerLobby
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_PkmnCenterNurse_ReturnPkmn
	specialvar VAR_RESULT, BufferUnionRoomPlayerName
	copyvar VAR_0x8008, VAR_RESULT
	compare VAR_0x8008, 0
	goto_if_eq EventScript_PkmnCenterNurse_ReturnPkmn
	compare VAR_0x8008, 1
	goto_if_eq EventScript_PkmnCenterNurse_PlayerWaitingInUionRoom
	end

EventScript_PkmnCenterNurse_ReturnPkmn:: @ 81A661D
	return

EventScript_PkmnCenterNurse_PlayerWaitingInUionRoom:: @ 81A6636
	goto_if_set FLAG_SYS_INFORMED_OF_LOCAL_WIRELESS_PLAYER, EventScript_PkmnCenterNurse_ReturnPkmn
	msgbox Text_RestoredPkmnToFullHealth
	setflag FLAG_SYS_INFORMED_OF_LOCAL_WIRELESS_PLAYER
	message Text_PlayerIsPlayingRightNowGoForIt
	waitmessage
	return

Movement_Bow:: @ 81A666C
	nurse_joy_bow
	delay_4
	step_end
