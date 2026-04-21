LilycoveCity_DepartmentStoreRooftop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_DepartmentStoreRooftop_OnTransition
	.byte 0

LilycoveCity_DepartmentStoreRooftop_OnTransition:
	getpokenewsactive POKENEWS_LILYCOVE
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_DepartmentStoreRooftop_EventScript_ShowSaleWoman
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_HideSaleWoman
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ShowSaleWoman::
	clearflag FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_HideSaleWoman::
	setflag FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale:
	.2byte DECOR_MUD_BALL
	.2byte DECOR_FENCE_LENGTH
	.2byte DECOR_FENCE_WIDTH
	.2byte DECOR_TIRE
	.2byte DECOR_BREAKABLE_DOOR
	.2byte DECOR_SOLID_BOARD
	.2byte DECOR_SAND_ORNAMENT
	.2byte DECOR_STAND
	.2byte DECOR_SLIDE
	.2byte DECOR_TV
	.2byte DECOR_ROUND_TV
	.2byte DECOR_CUTE_TV
	.2byte DECOR_WAILMER_DOLL
	.2byte DECOR_RHYDON_DOLL
	.2byte 0
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_Man::
	lock
	faceplayer
	getpokenewsactive POKENEWS_LILYCOVE
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_DepartmentStoreRooftop_EventScript_ManClearOutSale
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_SetDatesForClearOutSales, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ManClearOutSale::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_BeenWaitingForClearOutSale, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyMan::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_BoneDryThirsty, MSGBOX_NPC
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_VendingMachine::
	lockall
	message LilycoveCity_DepartmentStoreRooftop_Text_WhichItemWouldYouLike
	waitmessage
	showmoneybox 0, 0
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseItem
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseItem::
	multichoice 16, 0, MULTI_VENDING_MACHINE, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LilycoveCity_DepartmentStoreRooftop_EventScript_FreshWater
	case 1, LilycoveCity_DepartmentStoreRooftop_EventScript_SodaPop
	case 2, LilycoveCity_DepartmentStoreRooftop_EventScript_Lemonade
	case 3, LilycoveCity_DepartmentStoreRooftop_EventScript_GreenTea
	case 4, LilycoveCity_DepartmentStoreRooftop_EventScript_Apple
	case 5, LilycoveCity_DepartmentStoreRooftop_EventScript_AdzukiMochi
	case 6, LilycoveCity_DepartmentStoreRooftop_EventScript_MatchaMochi
	case 7, LilycoveCity_DepartmentStoreRooftop_EventScript_MysteryMochi
	case 8, LilycoveCity_DepartmentStoreRooftop_EventScript_Muffin
	case 9, LilycoveCity_DepartmentStoreRooftop_EventScript_Pastry
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_DecidedAgainstBuyingItem, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_GreenTea::
	setvar VAR_TEMP_0, ITEM_GREEN_TEA
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyItem
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_FreshWater::
	setvar VAR_TEMP_0, ITEM_FRESH_WATER
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyItem
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SodaPop::
	setvar VAR_TEMP_0, ITEM_SODA_POP
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyItem
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_Lemonade::
	setvar VAR_TEMP_0, ITEM_LEMONADE
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyItem
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_Apple::
	setvar VAR_TEMP_0, ITEM_APPLE
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyItem
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_AdzukiMochi::
	setvar VAR_TEMP_0, ITEM_ADZUKI_MOCHI
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyItem
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_MatchaMochi::
	setvar VAR_TEMP_0, ITEM_MATCHA_MOCHI
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyItem
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_MysteryMochi::
	setvar VAR_TEMP_0, ITEM_MYSTERY_MOCHI
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyItem
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_Muffin::
	setvar VAR_TEMP_0, ITEM_MUFFIN
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyItem
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_Pastry::
	setvar VAR_TEMP_0, ITEM_PASTRY
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyItem
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyGreenTea::
	checkmoney 100
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyFreshWater::
	checkmoney 200
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneySodaPop::
	checkmoney 300
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyLemonade::
	checkmoney 350
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyApple::
	checkmoney 50
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyAdzukiMochi::
	checkmoney 100
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyMatchaMochi::
	checkmoney 300
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyMysteryMochi::
	checkmoney 600
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyMuffin::
	checkmoney 600
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyPastry::
	checkmoney 1200
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyGreenTea::
	removemoney 100
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyFreshWater::
	removemoney 200
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneySodaPop::
	removemoney 300
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyLemonade::
	removemoney 350
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyApple::
	removemoney 50
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyAdzukiMochi::
	removemoney 100
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyMatchaMochi::
	removemoney 300
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyMysteryMochi::
	removemoney 600
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyMuffin::
	removemoney 600
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyPastry::
	removemoney 1200
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyItem::
	call_if_eq VAR_TEMP_1, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyGreenTea
	call_if_eq VAR_TEMP_1, 1, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyFreshWater
	call_if_eq VAR_TEMP_1, 2, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneySodaPop
	call_if_eq VAR_TEMP_1, 3, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyLemonade
	call_if_eq VAR_TEMP_1, 4, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyApple
	call_if_eq VAR_TEMP_1, 5, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyAdzukiMochi
	call_if_eq VAR_TEMP_1, 6, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyMatchaMochi
	call_if_eq VAR_TEMP_1, 7, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyMysteryMochi
	call_if_eq VAR_TEMP_1, 8, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyMuffin
	call_if_eq VAR_TEMP_1, 9, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyPastry
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_NotEnoughMoneyForItem
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForItem
	call_if_eq VAR_TEMP_1, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyGreenTea
	call_if_eq VAR_TEMP_1, 1, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyFreshWater
	call_if_eq VAR_TEMP_1, 2, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneySodaPop
	call_if_eq VAR_TEMP_1, 3, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyLemonade
	call_if_eq VAR_TEMP_1, 4, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyApple
	call_if_eq VAR_TEMP_1, 5, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyAdzukiMochi
	call_if_eq VAR_TEMP_1, 6, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyMatchaMochi
	call_if_eq VAR_TEMP_1, 7, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyMysteryMochi
	call_if_eq VAR_TEMP_1, 8, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyMuffin
	call_if_eq VAR_TEMP_1, 9, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyPastry
	updatemoneybox
	bufferitemname STR_VAR_1, VAR_TEMP_0
	playse SE_VEND
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_ItemOfItemDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 chance of an additional Item dropping
	goto_if_ne VAR_RESULT, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewItem
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForItem
	playse SE_VEND
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_ExtraItemOfItemDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 * the prev 1/64 chance of a third additional Item dropping, ~ 0.02% chance
	goto_if_ne VAR_RESULT, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewItem
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForItem
	playse SE_VEND
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_ExtraItemOfItemDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewItem
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewItem::
	message LilycoveCity_DepartmentStoreRooftop_Text_WhichItemWouldYouLike
	waitmessage
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseItem
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_NotEnoughMoneyForItem::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine::
	hidemoneybox
	releaseall
	end

LilycoveCity_DepartmentStoreRooftop_Text_SetDatesForClearOutSales:
	.string "Don't they have set dates for their\n"
	.string "clear-out sales?\p"
	.string "I watch TV, but they never show any\n"
	.string "commercials.$"

LilycoveCity_DepartmentStoreRooftop_Text_BeenWaitingForClearOutSale:
	.string "Yes! I've been waiting a long time for\n"
	.string "this clear-out sale.\p"
	.string "They have items that you can only get\n"
	.string "here. I'm going to load up, that I am!$"

LilycoveCity_DepartmentStoreRooftop_Text_BoneDryThirsty:
	.string "Ohh… I'm bone-dry thirsty!$"

LilycoveCity_DepartmentStoreRooftop_Text_WhichItemWouldYouLike:
	.string "It's a VENDING MACHINE.\n"
	.string "Which item would you like?$"

LilycoveCity_DepartmentStoreRooftop_Text_ItemOfItemDroppedDown:
	.string "Clang!\p"
	.string "{STR_VAR_1} dropped down.$"

LilycoveCity_DepartmentStoreRooftop_Text_ExtraItemOfItemDroppedDown:
	.string "Clang!\p"
	.string "Score! An extra {STR_VAR_1}\n"
	.string "dropped down!$"

LilycoveCity_DepartmentStoreRooftop_Text_NotEnoughMoney:
	.string "Not enough money…$"

LilycoveCity_DepartmentStoreRooftop_Text_DecidedAgainstBuyingItem:
	.string "Decided against buying an item.$"
