LittlerootTown_MusicStore_MapScripts::
	.byte 0

@ TODO : display an image of the singers when interacted with

.macro choose_starter text:req, flag:req species:req
	msgbox \text, MSGBOX_SIGN

	goto_if_set FLAG_RECEIVED_STARTER, LittlerootTown_MusicStore_EventScript_End

	setflag \flag
	setflag FLAG_RECEIVED_STARTER
	removeobject VAR_LAST_TALKED
	givemon \species 5
	setflag FLAG_SYS_POKEMON_GET

	goto LittlerootTown_MusicStore_EventScript_StarterCutscene
.endm

LittlerootTown_MusicStore_EventScript_End::
	end

@ TODO add the starter pokémon

LittlerootTown_MusicStore_EventScript_StarterLeft::
	choose_starter LittlerootTown_MusicStore_Text_StarterLeft, FLAG_CHOSE_MAI, SPECIES_BULBASAUR

LittlerootTown_MusicStore_EventScript_StarterCenter::
	choose_starter LittlerootTown_MusicStore_Text_StarterCenter, FLAG_CHOSE_UTA_UTANE, SPECIES_CHARMANDER

LittlerootTown_MusicStore_EventScript_StarterRight::
	choose_starter LittlerootTown_MusicStore_Text_StarterRight, FLAG_CHOSE_CHIS_A, SPECIES_SQUIRTLE

LittlerootTown_MusicStore_EventScript_StarterCutscene::
	@ The clerk's id is 4
	applymovement 4, LittlerootTown_MusicStore_EventScript_ClerkMovement
	waitmovement 0
	@ TODO : notify that starter has been recieved
	msgbox LittlerootTown_MusicStore_Text_ClerkExplain, MSGBOX_NPC
	end

LittlerootTown_MusicStore_EventScript_ClerkMovement::
	jump_2_down
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_MusicStore_EventScript_Clerk::
	goto_if_set FLAG_RECEIVED_STARTER, LittlerootTown_MusicStore_EventScript_ClerkPostStarter
	msgbox LittlerootTown_MusicStore_Text_ClerkOffer, MSGBOX_NPC
	end
LittlerootTown_MusicStore_EventScript_ClerkPostStarter::
	msgbox LittlerootTown_MusicStore_Text_Clerk, MSGBOX_NPC
	end


LittlerootTown_MusicStore_EventScript_Shelf::
	msgbox LittlerootTown_MusicStore_Text_Shelf, MSGBOX_SIGN
	end

LittlerootTown_MusicStore_Text_StarterLeft::
	.string "It's “Mai”.\n"
	.string "The Synthesizer V singer.$"

LittlerootTown_MusicStore_Text_StarterCenter::
	.string "It's “Utane Uta”.\n"
	.string "The UTAU singer.$"

LittlerootTown_MusicStore_Text_StarterRight::
	.string "It's “Chis-A”.\n"
	.string "The CeVIO singer.$"

LittlerootTown_MusicStore_Text_Shelf::
	.string "You don't see anything of intrest.$"

LittlerootTown_MusicStore_Text_ClerkOffer::
	.string "Welcome!\p"
	.string "We currently have a selection of free\n"
	.string "voice banks for new producers.\p"
	.string "You can see the options in the top right\n"
	.string "of the store.\p"
	.string "Feel free to pick one.$"

LittlerootTown_MusicStore_Text_ClerkExplain::
	.string "Oh right sorry,\n"
	.string "Forgot to mention.\p"
	.string "The selction only includes older\n"
	.string "versions…\p"
	.string "But once you've used it enough it will get\n"
	.string "an upgrade!\p"

LittlerootTown_MusicStore_Text_Clerk::
	.string "Feel free to look around the store for\n"
	.string "anything else that you want.$"
