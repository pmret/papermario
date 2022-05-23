HudScript HudScript_Item_Present = STANDARD_ITEM_HUD_SCRIPT(key_Gift);

HudScript HudScript_Item_CakeDone = STANDARD_ITEM_HUD_SCRIPT(key_CakeDone);

HudScript HudScript_Item_CakeBaked = STANDARD_ITEM_HUD_SCRIPT(key_CakeBaked);

HudScript HudScript_Item_CakePan = STANDARD_ITEM_HUD_SCRIPT(key_CakePan);

HudScript HudScript_Item_CakeBatter = STANDARD_ITEM_HUD_SCRIPT(key_CakeBatter);

HudScript HudScript_Item_CakeBowl = STANDARD_ITEM_HUD_SCRIPT(key_CakeBowl);

HudScript HudScript_Item_CakeMixed = STANDARD_ITEM_HUD_SCRIPT(key_CakeMix);

HudScript HudScript_Item_CakeIcing = STANDARD_ITEM_HUD_SCRIPT(key_CakeIcing);

HudScript HudScript_Item_CakeBerries = STANDARD_ITEM_HUD_SCRIPT(key_CakeBerries);

HudScript HudScript_Item_Hammer1 = STANDARD_ITEM_HUD_SCRIPT(Hammer1);

HudScript HudScript_Item_Hammer2 = STANDARD_ITEM_HUD_SCRIPT(Hammer2);

HudScript HudScript_Item_Hammer3 = STANDARD_ITEM_HUD_SCRIPT(Hammer3);

HudScript HudScript_Item_Boots1 = STANDARD_ITEM_HUD_SCRIPT(Boots1);

HudScript HudScript_Item_Boots2 = STANDARD_ITEM_HUD_SCRIPT(Boots2);

HudScript HudScript_Item_Boots3 = STANDARD_ITEM_HUD_SCRIPT(Boots3);

HudScript HudScript_Item_Items = STANDARD_ITEM_HUD_SCRIPT(Items);

HudScript HudScript_Item_HeartPiece = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_24x24)
	hs_Loop
		hs_SetIcon(60, anim_heart_piece)
	hs_Restart
	hs_End
};

HudScript HudScript_Item_Heart = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_24x24)
	hs_Loop
		hs_SetIcon(10, anim_heart_0)
		hs_SetIcon(6, anim_heart_1)
	hs_Restart
	hs_End
};

HudScript HudScript_Item_Coin = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_24x24)
	hs_Loop
		hs_op_15(00000000)
		hs_SetIcon(3, anim_coin_0)
		hs_SetIcon(3, anim_coin_1)
		hs_SetIcon(3, anim_coin_4)
		hs_SetIcon(3, anim_coin_5)
		hs_SetIcon(3, anim_coin_6)
		hs_SetIcon(3, anim_coin_7)
		hs_SetIcon(3, anim_coin_8)
		hs_SetIcon(3, anim_coin_9)
		hs_RandomRestart(100, 70)
		hs_op_15(00000001)
		hs_SetIcon(3, anim_coin_0)
		hs_SetIcon(2, anim_coin_1)
		hs_SetIcon(1, anim_coin_2)
		hs_SetIcon(1, anim_coin_3)
		hs_SetIcon(2, anim_coin_4)
		hs_SetIcon(3, anim_coin_5)
		hs_SetIcon(3, anim_coin_6)
		hs_SetIcon(3, anim_coin_7)
		hs_SetIcon(3, anim_coin_8)
		hs_SetIcon(3, anim_coin_9)
	hs_Restart
	hs_End
};

HudScript HudScript_Item_CoinSparkleA = {
	hs_SetTexelOffset(-8, 0)
	hs_SetIcon(1, anim_shimmer_0)
	hs_SetIcon(1, anim_shimmer_1)
	hs_SetIcon(1, anim_shimmer_2)
	hs_SetIcon(2, anim_shimmer_6)
	hs_SetIcon(1, anim_shimmer_2)
	hs_SetIcon(1, anim_shimmer_3)
	hs_SetIcon(1, anim_shimmer_6)
	hs_SetIcon(1, anim_shimmer_4)
	hs_SetIcon(1, anim_shimmer_6)
	hs_SetIcon(1, anim_shimmer_5)
	hs_SetIcon(16, anim_shimmer_6)
	hs_End
};

HudScript HudScript_Item_CoinSparkleB = {
	hs_SetTexelOffset(8, 8)
	hs_SetIcon(1, anim_shimmer_0)
	hs_SetIcon(1, anim_shimmer_1)
	hs_SetIcon(1, anim_shimmer_2)
	hs_SetIcon(2, anim_shimmer_6)
	hs_SetIcon(1, anim_shimmer_2)
	hs_SetIcon(1, anim_shimmer_3)
	hs_SetIcon(1, anim_shimmer_6)
	hs_SetIcon(1, anim_shimmer_4)
	hs_SetIcon(1, anim_shimmer_6)
	hs_SetIcon(1, anim_shimmer_5)
	hs_SetIcon(16, anim_shimmer_6)
	hs_End
};

HudScript HudScript_Item_CoinSparkleC = {
	hs_SetTexelOffset(-4, 8)
	hs_SetIcon(1, anim_shimmer_0)
	hs_SetIcon(1, anim_shimmer_1)
	hs_SetIcon(1, anim_shimmer_2)
	hs_SetIcon(2, anim_shimmer_6)
	hs_SetIcon(1, anim_shimmer_2)
	hs_SetIcon(1, anim_shimmer_3)
	hs_SetIcon(1, anim_shimmer_6)
	hs_SetIcon(1, anim_shimmer_4)
	hs_SetIcon(1, anim_shimmer_6)
	hs_SetIcon(1, anim_shimmer_5)
	hs_SetIcon(16, anim_shimmer_6)
	hs_End
};

HudScript HudScript_Item_CoinSparkleD = {
	hs_SetTexelOffset(6, -6)
	hs_SetIcon(1, anim_shimmer_0)
	hs_SetIcon(1, anim_shimmer_1)
	hs_SetIcon(1, anim_shimmer_2)
	hs_SetIcon(2, anim_shimmer_6)
	hs_SetIcon(1, anim_shimmer_2)
	hs_SetIcon(1, anim_shimmer_3)
	hs_SetIcon(1, anim_shimmer_6)
	hs_SetIcon(1, anim_shimmer_4)
	hs_SetIcon(1, anim_shimmer_6)
	hs_SetIcon(1, anim_shimmer_5)
	hs_SetIcon(16, anim_shimmer_6)
	hs_End
};

HudScript HudScript_Item_CoinSparkleE = {
	hs_SetTexelOffset(1, -8)
	hs_SetIcon(1, anim_shimmer_0)
	hs_SetIcon(1, anim_shimmer_1)
	hs_SetIcon(1, anim_shimmer_2)
	hs_SetIcon(2, anim_shimmer_6)
	hs_SetIcon(1, anim_shimmer_2)
	hs_SetIcon(1, anim_shimmer_3)
	hs_SetIcon(1, anim_shimmer_6)
	hs_SetIcon(1, anim_shimmer_4)
	hs_SetIcon(1, anim_shimmer_6)
	hs_SetIcon(1, anim_shimmer_5)
	hs_SetIcon(16, anim_shimmer_6)
	hs_End
};

HudScript HudScript_Item_CoinSparkleRandom = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_8x8)
	hs_RandomBranch(
		HS_PTR(HudScript_Item_CoinSparkleA),
		HS_PTR(HudScript_Item_CoinSparkleB),
		HS_PTR(HudScript_Item_CoinSparkleC),
		HS_PTR(HudScript_Item_CoinSparkleD),
		HS_PTR(HudScript_Item_CoinSparkleE))
	hs_End
};

HudScript HudScript_Item_StarPoint = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_24x24)
	hs_Loop
		hs_SetIcon(2, anim_sp_0)
		hs_SetIcon(2, anim_sp_1)
		hs_SetIcon(2, anim_sp_2)
		hs_SetIcon(2, anim_sp_3)
		hs_SetIcon(2, anim_sp_4)
		hs_SetIcon(2, anim_sp_5)
		hs_SetIcon(2, anim_sp_6)
		hs_SetIcon(2, anim_sp_7)
	hs_Restart
	hs_End
};

HudScript HudScript_Item_SmallStarPoint = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_8x8)
	hs_Loop
		hs_SetIcon(2, anim_sp_small_0)
		hs_SetIcon(2, anim_sp_small_1)
		hs_SetIcon(2, anim_sp_small_2)
		hs_SetIcon(2, anim_sp_small_3)
		hs_SetIcon(2, anim_sp_small_4)
		hs_SetIcon(2, anim_sp_small_5)
		hs_SetIcon(2, anim_sp_small_6)
		hs_SetIcon(2, anim_sp_small_7)
	hs_Restart
	hs_End
};

HudScript HudScript_Item_HeartPoint = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_32x32)
	hs_Loop
		hs_SetIcon(8, anim_hp_0)
		hs_SetIcon(5, anim_hp_1)
		hs_SetIcon(8, anim_hp_2)
	hs_Restart
	hs_End
};

HudScript HudScript_Item_FlowerPoint = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_32x32)
	hs_Loop
		hs_SetIcon(8, anim_fp_0)
		hs_SetIcon(5, anim_fp_1)
		hs_SetIcon(8, anim_fp_2)
	hs_Restart
	hs_End
};

HudScript HudScript_Item_StarPiece = {
	hs_SetVisible
	hs_SetTileSize(HUD_ELEMENT_SIZE_32x32)
	hs_Loop
		hs_SetIcon(12, anim_star_piece_0)
		hs_SetIcon(4, anim_star_piece_1)
		hs_SetIcon(12, anim_star_piece_2)
		hs_SetIcon(4, anim_star_piece_1)
	hs_Restart
	hs_End
};

HudScript HudScript_Item_GearBoots1 = STANDARD_ITEM_HUD_SCRIPT(key_gear_boots_1);

HudScript HudScript_Item_GearBoots2 = STANDARD_ITEM_HUD_SCRIPT(key_gear_boots_2);

HudScript HudScript_Item_GearBoots3 = STANDARD_ITEM_HUD_SCRIPT(key_gear_boots_3);

HudScript HudScript_Item_GearHammer1 = STANDARD_ITEM_HUD_SCRIPT(key_gear_hammer_1);

HudScript HudScript_Item_GearHammer2 = STANDARD_ITEM_HUD_SCRIPT(key_gear_hammer_2);

HudScript HudScript_Item_GearHammer3 = STANDARD_ITEM_HUD_SCRIPT(key_gear_hammer_3);

HudScript HudScript_Item_LuckyStar = STANDARD_ITEM_HUD_SCRIPT(key_gear_lucky_star);

HudScript HudScript_Item_Map = STANDARD_ITEM_HUD_SCRIPT(key_map);

HudScript HudScript_Item_KoopaFortressKey = STANDARD_ITEM_HUD_SCRIPT(key_key_koopa_fortress);

HudScript HudScript_Item_RuinsKey = STANDARD_ITEM_HUD_SCRIPT(key_key_ruins);

HudScript HudScript_Item_TubbaCastleKey = STANDARD_ITEM_HUD_SCRIPT(key_key_tubba_castle);

HudScript HudScript_Item_IcePalaceKey = STANDARD_ITEM_HUD_SCRIPT(key_key_ice_palace);

HudScript HudScript_Item_BowserCastleKey = STANDARD_ITEM_HUD_SCRIPT(key_key_bowser_castle);

HudScript HudScript_Item_Dolly = STANDARD_ITEM_HUD_SCRIPT(key_dolly);

HudScript HudScript_Item_KooperShell = STANDARD_ITEM_HUD_SCRIPT(key_kooper_shell);

HudScript HudScript_Item_PulseStone = STANDARD_ITEM_HUD_SCRIPT(key_pulse_stone);

HudScript HudScript_Item_Artifact = STANDARD_ITEM_HUD_SCRIPT(key_artifact);

HudScript HudScript_Item_AncientVase = STANDARD_ITEM_HUD_SCRIPT(key_vase);

HudScript HudScript_Item_RuinsStonePyramid = STANDARD_ITEM_HUD_SCRIPT(key_ruins_stone_pyramid);

HudScript HudScript_Item_RuinsStoneStar = STANDARD_ITEM_HUD_SCRIPT(key_ruins_stone_star);

HudScript HudScript_Item_RuinsStoneMoon = STANDARD_ITEM_HUD_SCRIPT(key_ruins_stone_moon);

HudScript HudScript_Item_ForestPass = STANDARD_ITEM_HUD_SCRIPT(key_forest_pass);

HudScript HudScript_Item_BooRecordOutline = STANDARD_ITEM_HUD_SCRIPT(key_boo_record_mask);

HudScript HudScript_Item_BooRecord = STANDARD_ITEM_HUD_SCRIPT(key_boo_record);

HudScript HudScript_Item_BooWeight = STANDARD_ITEM_HUD_SCRIPT(key_boo_weight);

HudScript HudScript_Item_BooPortrait = STANDARD_ITEM_HUD_SCRIPT(key_boo_portrait);

HudScript HudScript_Item_MysticKey = STANDARD_ITEM_HUD_SCRIPT(key_mystic_key);

HudScript HudScript_Item_IronKey = STANDARD_ITEM_HUD_SCRIPT(key_key_storeroom);

HudScript HudScript_Item_ToyboxTrain = STANDARD_ITEM_HUD_SCRIPT(key_toybox_train);

HudScript HudScript_Item_FryingPan = STANDARD_ITEM_HUD_SCRIPT(key_frying_pan);

HudScript HudScript_Item_Dictionary = STANDARD_ITEM_HUD_SCRIPT(key_dictionary);

HudScript HudScript_Item_MysteryNote = STANDARD_ITEM_HUD_SCRIPT(key_mystery_note);

HudScript HudScript_Item_SuspiciousNote = STANDARD_ITEM_HUD_SCRIPT(key_suspicious_note);

HudScript HudScript_Item_MagicalSeed1 = STANDARD_ITEM_HUD_SCRIPT(key_seed_1);

HudScript HudScript_Item_MagicalSeed2 = STANDARD_ITEM_HUD_SCRIPT(key_seed_2);

HudScript HudScript_Item_MagicalSeed3 = STANDARD_ITEM_HUD_SCRIPT(key_seed_3);

HudScript HudScript_Item_MagicalSeed4 = STANDARD_ITEM_HUD_SCRIPT(key_seed_4);

HudScript HudScript_Item_CrystalBerry = STANDARD_ITEM_HUD_SCRIPT(key_crystal_berry);

HudScript HudScript_Item_WaterStone = STANDARD_ITEM_HUD_SCRIPT(key_water_stone);

HudScript HudScript_Item_MagicBean = STANDARD_ITEM_HUD_SCRIPT(key_magic_bean);

HudScript HudScript_Item_FertileSoil = STANDARD_ITEM_HUD_SCRIPT(key_fertile_soil);

HudScript HudScript_Item_MiracleWater = STANDARD_ITEM_HUD_SCRIPT(key_miracle_water);

HudScript HudScript_Item_UltraStone = STANDARD_ITEM_HUD_SCRIPT(key_ultra_stone);

HudScript HudScript_Item_ToadDoll = STANDARD_ITEM_HUD_SCRIPT(key_toad_doll);

HudScript HudScript_Item_Calculator = STANDARD_ITEM_HUD_SCRIPT(key_calculator);

HudScript HudScript_Item_Screwdriver = STANDARD_ITEM_HUD_SCRIPT(key_screwdriver);

HudScript HudScript_Item_CookBook = STANDARD_ITEM_HUD_SCRIPT(key_book_cook);

HudScript HudScript_Item_JadeRaven = STANDARD_ITEM_HUD_SCRIPT(key_jade_raven);

HudScript HudScript_Item_SnowmanBucket = STANDARD_ITEM_HUD_SCRIPT(key_snowman_bucket);

HudScript HudScript_Item_SnowmanScarf = STANDARD_ITEM_HUD_SCRIPT(key_snowman_scarf);

HudScript HudScript_Item_RedKey = STANDARD_ITEM_HUD_SCRIPT(key_key_red);

HudScript HudScript_Item_BlueKey = STANDARD_ITEM_HUD_SCRIPT(key_key_blue);

HudScript HudScript_Item_KootPackage = STANDARD_ITEM_HUD_SCRIPT(key_koot_package);

HudScript HudScript_Item_KootRedJar = STANDARD_ITEM_HUD_SCRIPT(key_koot_red_jar);

HudScript HudScript_Item_Melody = STANDARD_ITEM_HUD_SCRIPT(key_book_melody);

HudScript HudScript_Item_Lyrics = STANDARD_ITEM_HUD_SCRIPT(key_book_lyrics);

HudScript HudScript_Item_Mailbag = STANDARD_ITEM_HUD_SCRIPT(key_mailbag);

HudScript HudScript_Item_StarStone = STANDARD_ITEM_HUD_SCRIPT(key_star_stone);

HudScript HudScript_Item_SneakyParasol = STANDARD_ITEM_HUD_SCRIPT(peach_sneaky_parasol);

HudScript HudScript_Item_PeachKey = STANDARD_ITEM_HUD_SCRIPT(key_key_peach);

HudScript HudScript_Item_UNK_1DC210 = STANDARD_ITEM_HUD_SCRIPT(key_1DC210);

HudScript HudScript_Item_UNK_1DC430 = STANDARD_ITEM_HUD_SCRIPT(key_1DC430);

HudScript HudScript_Item_UNK_1DC650 = STANDARD_ITEM_HUD_SCRIPT(key_1DC650);

HudScript HudScript_Item_UNK_1DC870 = STANDARD_ITEM_HUD_SCRIPT(key_1DC870);

HudScript HudScript_Item_DojoCard1 = STANDARD_ITEM_HUD_SCRIPT(key_dojo_card_1);

HudScript HudScript_Item_DojoCard2 = STANDARD_ITEM_HUD_SCRIPT(key_dojo_card_2);

HudScript HudScript_Item_DojoCard3 = STANDARD_ITEM_HUD_SCRIPT(key_dojo_card_3);

HudScript HudScript_Item_DojoCard4 = STANDARD_ITEM_HUD_SCRIPT(key_dojo_card_4);

HudScript HudScript_Item_DojoCard5 = STANDARD_ITEM_HUD_SCRIPT(key_dojo_card_5);

HudScript HudScript_Item_CrystalBall = STANDARD_ITEM_HUD_SCRIPT(key_crystal_ball);

HudScript HudScript_Item_GoldCard = STANDARD_ITEM_HUD_SCRIPT(key_card_gold);

HudScript HudScript_Item_SilverCard = STANDARD_ITEM_HUD_SCRIPT(key_card_silver);

HudScript HudScript_Item_KootBook = STANDARD_ITEM_HUD_SCRIPT(key_koot_book);

HudScript HudScript_Item_KootTheTape = STANDARD_ITEM_HUD_SCRIPT(key_koot_the_tape);

HudScript HudScript_Item_KootMerluvleeAutograph = STANDARD_ITEM_HUD_SCRIPT(key_koot_autograph_luigi);

HudScript HudScript_Item_KootEmptyWallet = STANDARD_ITEM_HUD_SCRIPT(key_koot_empty_wallet);

HudScript HudScript_Item_KootLuigiAutograph = STANDARD_ITEM_HUD_SCRIPT(key_koot_autograph_merluvlee);

HudScript HudScript_Item_KootShell = STANDARD_ITEM_HUD_SCRIPT(key_koot_shell);

HudScript HudScript_Item_KootPhoto = STANDARD_ITEM_HUD_SCRIPT(key_koot_photo);

HudScript HudScript_Item_KootGlasses = STANDARD_ITEM_HUD_SCRIPT(key_koot_glasses);

HudScript HudScript_Item_Letter = STANDARD_ITEM_HUD_SCRIPT(key_Letter);
HudScript HudScript_Item_Letter_disabled = STANDARD_ITEM_HUD_SCRIPT(key_Letter_disabled);

HudScript HudScript_Item_Unused_089 = STANDARD_ITEM_HUD_SCRIPT(key_LongLetter);
HudScript HudScript_Item_Unused_089_disabled = STANDARD_ITEM_HUD_SCRIPT(key_LongLetter_disabled);

HudScript HudScript_Item_Unused_08A = STANDARD_ITEM_HUD_SCRIPT(key_TealLetter);
HudScript HudScript_Item_Unused_08A_disabled = STANDARD_ITEM_HUD_SCRIPT(key_TealLetter_disabled);

HudScript HudScript_Item_Unused_08B = STANDARD_ITEM_HUD_SCRIPT(key_Postcard);
HudScript HudScript_Item_Unused_08B_disabled = STANDARD_ITEM_HUD_SCRIPT(key_Postcard_disabled);

HudScript HudScript_Item_Unused_08C = STANDARD_ITEM_HUD_SCRIPT(key_EmptyBook);
HudScript HudScript_Item_Unused_08C_disabled = STANDARD_ITEM_HUD_SCRIPT(key_EmptyBook_disabled);

HudScript HudScript_Item_Unused_08D = STANDARD_ITEM_HUD_SCRIPT(unused_08D);
HudScript HudScript_Item_Unused_08D_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_08D_disabled);

HudScript HudScript_Item_Unused_08E = STANDARD_ITEM_HUD_SCRIPT(unused_08E);
HudScript HudScript_Item_Unused_08E_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_08E_disabled);

HudScript HudScript_Item_Unused_08F = STANDARD_ITEM_HUD_SCRIPT(unused_08F);
HudScript HudScript_Item_Unused_08F_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_08F_disabled);

HudScript HudScript_Item_PleaseComeBack = STANDARD_ITEM_HUD_SCRIPT(battle_PleaseComeBack);
HudScript HudScript_Item_PleaseComeBack_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_PleaseComeBack_disabled);

HudScript HudScript_Item_Unused_139 = STANDARD_ITEM_HUD_SCRIPT(battle_139);
HudScript HudScript_Item_Unused_139_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_139_disabled);

HudScript HudScript_Item_FrightJar = STANDARD_ITEM_HUD_SCRIPT(battle_FrightJar);
HudScript HudScript_Item_FrightJar_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_FrightJar_disabled);

HudScript HudScript_Item_Mystery = STANDARD_ITEM_HUD_SCRIPT(battle_Mystery);
HudScript HudScript_Item_Mystery_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_Mystery_disabled);

HudScript HudScript_Item_RepelGel = STANDARD_ITEM_HUD_SCRIPT(battle_RepelGel);
HudScript HudScript_Item_RepelGel_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_RepelGel_disabled);

HudScript HudScript_Item_InsecticideHerb = STANDARD_ITEM_HUD_SCRIPT(battle_InsecticideHerb);
HudScript HudScript_Item_InsecticideHerb_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_InsecticideHerb_disabled);

HudScript HudScript_Item_Unused_13E = STANDARD_ITEM_HUD_SCRIPT(battle_13E);
HudScript HudScript_Item_Unused_13E_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_13E_disabled);

HudScript HudScript_Item_Unused_13F = STANDARD_ITEM_HUD_SCRIPT(battle_13F);
HudScript HudScript_Item_Unused_13F_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_13F_disabled);

HudScript HudScript_Item_SpicySoup = STANDARD_ITEM_HUD_SCRIPT(food_SpicySoup);
HudScript HudScript_Item_SpicySoup_disabled = STANDARD_ITEM_HUD_SCRIPT(food_SpicySoup_disabled);

HudScript HudScript_Item_ApplePie = STANDARD_ITEM_HUD_SCRIPT(food_ApplePie);
HudScript HudScript_Item_ApplePie_disabled = STANDARD_ITEM_HUD_SCRIPT(food_ApplePie_disabled);

HudScript HudScript_Item_HoneyUltra = STANDARD_ITEM_HUD_SCRIPT(food_HoneyUltra);
HudScript HudScript_Item_HoneyUltra_disabled = STANDARD_ITEM_HUD_SCRIPT(food_HoneyUltra_disabled);

HudScript HudScript_Item_MapleUltra = STANDARD_ITEM_HUD_SCRIPT(food_MapleUltra);
HudScript HudScript_Item_MapleUltra_disabled = STANDARD_ITEM_HUD_SCRIPT(food_MapleUltra_disabled);

HudScript HudScript_Item_JellyUltra = STANDARD_ITEM_HUD_SCRIPT(food_JellyUltra);
HudScript HudScript_Item_JellyUltra_disabled = STANDARD_ITEM_HUD_SCRIPT(food_JellyUltra_disabled);

HudScript HudScript_Item_Koopasta = STANDARD_ITEM_HUD_SCRIPT(food_Koopasta);
HudScript HudScript_Item_Koopasta_disabled = STANDARD_ITEM_HUD_SCRIPT(food_Koopasta_disabled);

HudScript HudScript_Item_FriedShroom = STANDARD_ITEM_HUD_SCRIPT(food_FriedShroom);
HudScript HudScript_Item_FriedShroom_disabled = STANDARD_ITEM_HUD_SCRIPT(food_FriedShroom_disabled);

HudScript HudScript_Item_ShroomCake = STANDARD_ITEM_HUD_SCRIPT(food_ShroomCake);
HudScript HudScript_Item_ShroomCake_disabled = STANDARD_ITEM_HUD_SCRIPT(food_ShroomCake_disabled);

HudScript HudScript_Item_ShroomSteak = STANDARD_ITEM_HUD_SCRIPT(food_ShroomSteak);
HudScript HudScript_Item_ShroomSteak_disabled = STANDARD_ITEM_HUD_SCRIPT(food_ShroomSteak_disabled);

HudScript HudScript_Item_HotShroom = STANDARD_ITEM_HUD_SCRIPT(food_HotShroom);
HudScript HudScript_Item_HotShroom_disabled = STANDARD_ITEM_HUD_SCRIPT(food_HotShroom_disabled);

HudScript HudScript_Item_SweetShroom = STANDARD_ITEM_HUD_SCRIPT(food_SweetShroom);
HudScript HudScript_Item_SweetShroom_disabled = STANDARD_ITEM_HUD_SCRIPT(food_SweetShroom_disabled);

HudScript HudScript_Item_HealthyJuice = STANDARD_ITEM_HUD_SCRIPT(food_HealthyJuice);
HudScript HudScript_Item_HealthyJuice_disabled = STANDARD_ITEM_HUD_SCRIPT(food_HealthyJuice_disabled);

HudScript HudScript_Item_BlandMeal = STANDARD_ITEM_HUD_SCRIPT(food_BlandMeal);
HudScript HudScript_Item_BlandMeal_disabled = STANDARD_ITEM_HUD_SCRIPT(food_BlandMeal_disabled);

HudScript HudScript_Item_YummyMeal = STANDARD_ITEM_HUD_SCRIPT(food_YummyMeal);
HudScript HudScript_Item_YummyMeal_disabled = STANDARD_ITEM_HUD_SCRIPT(food_YummyMeal_disabled);

HudScript HudScript_Item_DeluxeFeast = STANDARD_ITEM_HUD_SCRIPT(food_DeluxeFeast);
HudScript HudScript_Item_DeluxeFeast_disabled = STANDARD_ITEM_HUD_SCRIPT(food_DeluxeFeast_disabled);

HudScript HudScript_Item_SpecialShake = STANDARD_ITEM_HUD_SCRIPT(food_SpecialShake);
HudScript HudScript_Item_SpecialShake_disabled = STANDARD_ITEM_HUD_SCRIPT(food_SpecialShake_disabled);

HudScript HudScript_Item_BigCookie = STANDARD_ITEM_HUD_SCRIPT(food_BigCookie);
HudScript HudScript_Item_BigCookie_disabled = STANDARD_ITEM_HUD_SCRIPT(food_BigCookie_disabled);

HudScript HudScript_Item_Cake = STANDARD_ITEM_HUD_SCRIPT(food_Cake);
HudScript HudScript_Item_Cake_disabled = STANDARD_ITEM_HUD_SCRIPT(food_Cake_disabled);

HudScript HudScript_Item_Mistake = STANDARD_ITEM_HUD_SCRIPT(food_Mistake);
HudScript HudScript_Item_Mistake_disabled = STANDARD_ITEM_HUD_SCRIPT(food_Mistake_disabled);

HudScript HudScript_Item_KoopaTea = STANDARD_ITEM_HUD_SCRIPT(food_KoopaTea);
HudScript HudScript_Item_KoopaTea_disabled = STANDARD_ITEM_HUD_SCRIPT(food_KoopaTea_disabled);

HudScript HudScript_Item_HoneySuper = STANDARD_ITEM_HUD_SCRIPT(food_HoneySuper);
HudScript HudScript_Item_HoneySuper_disabled = STANDARD_ITEM_HUD_SCRIPT(food_HoneySuper_disabled);

HudScript HudScript_Item_MapleSuper = STANDARD_ITEM_HUD_SCRIPT(food_MapleSuper);
HudScript HudScript_Item_MapleSuper_disabled = STANDARD_ITEM_HUD_SCRIPT(food_MapleSuper_disabled);

HudScript HudScript_Item_JellySuper = STANDARD_ITEM_HUD_SCRIPT(food_JellySuper);
HudScript HudScript_Item_JellySuper_disabled = STANDARD_ITEM_HUD_SCRIPT(food_JellySuper_disabled);

HudScript HudScript_Item_Spaghetti = STANDARD_ITEM_HUD_SCRIPT(food_Spaghetti);
HudScript HudScript_Item_Spaghetti_disabled = STANDARD_ITEM_HUD_SCRIPT(food_Spaghetti_disabled);

HudScript HudScript_Item_EggMissile = STANDARD_ITEM_HUD_SCRIPT(food_EggMissile);
HudScript HudScript_Item_EggMissile_disabled = STANDARD_ITEM_HUD_SCRIPT(food_EggMissile_disabled);

HudScript HudScript_Item_FriedEgg = STANDARD_ITEM_HUD_SCRIPT(food_FriedEgg);
HudScript HudScript_Item_FriedEgg_disabled = STANDARD_ITEM_HUD_SCRIPT(food_FriedEgg_disabled);

HudScript HudScript_Item_HoneyShroom = STANDARD_ITEM_HUD_SCRIPT(food_HoneyShroom);
HudScript HudScript_Item_HoneyShroom_disabled = STANDARD_ITEM_HUD_SCRIPT(food_HoneyShroom_disabled);

HudScript HudScript_Item_HoneyCandy = STANDARD_ITEM_HUD_SCRIPT(food_HoneyCandy);
HudScript HudScript_Item_HoneyCandy_disabled = STANDARD_ITEM_HUD_SCRIPT(food_HoneyCandy_disabled);

HudScript HudScript_Item_ElectroPop = STANDARD_ITEM_HUD_SCRIPT(food_ElectroPop);
HudScript HudScript_Item_ElectroPop_disabled = STANDARD_ITEM_HUD_SCRIPT(food_ElectroPop_disabled);

HudScript HudScript_Item_FirePop = STANDARD_ITEM_HUD_SCRIPT(food_FirePop);
HudScript HudScript_Item_FirePop_disabled = STANDARD_ITEM_HUD_SCRIPT(food_FirePop_disabled);

HudScript HudScript_Item_LimeCandy = STANDARD_ITEM_HUD_SCRIPT(food_LimeCandy);
HudScript HudScript_Item_LimeCandy_disabled = STANDARD_ITEM_HUD_SCRIPT(food_LimeCandy_disabled);

HudScript HudScript_Item_CocoPop = STANDARD_ITEM_HUD_SCRIPT(food_CocoPop);
HudScript HudScript_Item_CocoPop_disabled = STANDARD_ITEM_HUD_SCRIPT(food_CocoPop_disabled);

HudScript HudScript_Item_LemonCandy = STANDARD_ITEM_HUD_SCRIPT(food_LemonCandy);
HudScript HudScript_Item_LemonCandy_disabled = STANDARD_ITEM_HUD_SCRIPT(food_LemonCandy_disabled);

HudScript HudScript_Item_JellyPop = STANDARD_ITEM_HUD_SCRIPT(food_JellyPop);
HudScript HudScript_Item_JellyPop_disabled = STANDARD_ITEM_HUD_SCRIPT(food_JellyPop_disabled);

HudScript HudScript_Item_StrangeCake = STANDARD_ITEM_HUD_SCRIPT(food_StrangeCake);
HudScript HudScript_Item_StrangeCake_disabled = STANDARD_ITEM_HUD_SCRIPT(food_StrangeCake_disabled);

HudScript HudScript_Item_KookyCookie = STANDARD_ITEM_HUD_SCRIPT(food_KookyCookie);
HudScript HudScript_Item_KookyCookie_disabled = STANDARD_ITEM_HUD_SCRIPT(food_KookyCookie_disabled);

HudScript HudScript_Item_FrozenFries = STANDARD_ITEM_HUD_SCRIPT(food_FrozenFries);
HudScript HudScript_Item_FrozenFries_disabled = STANDARD_ITEM_HUD_SCRIPT(food_FrozenFries_disabled);

HudScript HudScript_Item_PotatoSalad = STANDARD_ITEM_HUD_SCRIPT(food_PotatoSalad);
HudScript HudScript_Item_PotatoSalad_disabled = STANDARD_ITEM_HUD_SCRIPT(food_PotatoSalad_disabled);

HudScript HudScript_Item_NuttyCake = STANDARD_ITEM_HUD_SCRIPT(food_NuttyCake);
HudScript HudScript_Item_NuttyCake_disabled = STANDARD_ITEM_HUD_SCRIPT(food_NuttyCake_disabled);

HudScript HudScript_Item_MapleShroom = STANDARD_ITEM_HUD_SCRIPT(food_MapleShroom);
HudScript HudScript_Item_MapleShroom_disabled = STANDARD_ITEM_HUD_SCRIPT(food_MapleShroom_disabled);

HudScript HudScript_Item_BoiledEgg = STANDARD_ITEM_HUD_SCRIPT(food_BoiledEgg);
HudScript HudScript_Item_BoiledEgg_disabled = STANDARD_ITEM_HUD_SCRIPT(food_BoiledEgg_disabled);

HudScript HudScript_Item_YoshiCookie = STANDARD_ITEM_HUD_SCRIPT(food_YoshiCookie);
HudScript HudScript_Item_YoshiCookie_disabled = STANDARD_ITEM_HUD_SCRIPT(food_YoshiCookie_disabled);

HudScript HudScript_Item_JellyShroom = STANDARD_ITEM_HUD_SCRIPT(food_JellyShroom);
HudScript HudScript_Item_JellyShroom_disabled = STANDARD_ITEM_HUD_SCRIPT(food_JellyShroom_disabled);

HudScript HudScript_Item_Unused_02C = STANDARD_ITEM_HUD_SCRIPT(unused_02C);
HudScript HudScript_Item_Unused_02C_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_02C_disabled);

HudScript HudScript_Item_Unused_02D = STANDARD_ITEM_HUD_SCRIPT(unused_02D);
HudScript HudScript_Item_Unused_02D_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_02D_disabled);

HudScript HudScript_Item_Unused_02E = STANDARD_ITEM_HUD_SCRIPT(unused_02E);
HudScript HudScript_Item_Unused_02E_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_02E_disabled);

HudScript HudScript_Item_Unused_02F = STANDARD_ITEM_HUD_SCRIPT(unused_02F);
HudScript HudScript_Item_Unused_02F_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_02F_disabled);

HudScript HudScript_Item_Unused_030 = STANDARD_ITEM_HUD_SCRIPT(unused_030);
HudScript HudScript_Item_Unused_030_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_030_disabled);

HudScript HudScript_Item_SpinSmash = STANDARD_ITEM_HUD_SCRIPT(badge_SpinSmash);
HudScript HudScript_Item_SpinSmash_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_SpinSmash_disabled);

HudScript HudScript_Item_Multibounce = STANDARD_ITEM_HUD_SCRIPT(badge_Multibounce);
HudScript HudScript_Item_Multibounce_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_Multibounce_disabled);

HudScript HudScript_Item_PowerPlus = STANDARD_ITEM_HUD_SCRIPT(badge_PowerPlus);
HudScript HudScript_Item_PowerPlus_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_PowerPlus_disabled);

HudScript HudScript_Item_DodgeMaster = STANDARD_ITEM_HUD_SCRIPT(badge_DodgeMaster);
HudScript HudScript_Item_DodgeMaster_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_DodgeMaster_disabled);

HudScript HudScript_Item_PowerBounce = STANDARD_ITEM_HUD_SCRIPT(badge_PowerBounce);
HudScript HudScript_Item_PowerBounce_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_PowerBounce_disabled);

HudScript HudScript_Item_SpikeShield = STANDARD_ITEM_HUD_SCRIPT(badge_SpikeShield);
HudScript HudScript_Item_SpikeShield_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_SpikeShield_disabled);

HudScript HudScript_Item_FirstAttack = STANDARD_ITEM_HUD_SCRIPT(badge_FirstAttack);
HudScript HudScript_Item_FirstAttack_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_FirstAttack_disabled);

HudScript HudScript_Item_HPPlus = STANDARD_ITEM_HUD_SCRIPT(badge_HPPlus);
HudScript HudScript_Item_HPPlus_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_HPPlus_disabled);

HudScript HudScript_Item_QuakeHammer = STANDARD_ITEM_HUD_SCRIPT(badge_QuakeHammer);
HudScript HudScript_Item_QuakeHammer_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_QuakeHammer_disabled);

HudScript HudScript_Item_DoubleDip = STANDARD_ITEM_HUD_SCRIPT(badge_DoubleDip);
HudScript HudScript_Item_DoubleDip_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_DoubleDip_disabled);

HudScript HudScript_Item_PowerQuake = STANDARD_ITEM_HUD_SCRIPT(badge_PowerQuake);
HudScript HudScript_Item_PowerQuake_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_PowerQuake_disabled);

HudScript HudScript_Item_MegaQuake = STANDARD_ITEM_HUD_SCRIPT(badge_MegaQuake);
HudScript HudScript_Item_MegaQuake_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_MegaQuake_disabled);

HudScript HudScript_Item_SleepStomp = STANDARD_ITEM_HUD_SCRIPT(badge_SleepStomp);
HudScript HudScript_Item_SleepStomp_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_SleepStomp_disabled);

HudScript HudScript_Item_SmashCharge = STANDARD_ITEM_HUD_SCRIPT(badge_SmashCharge);
HudScript HudScript_Item_SmashCharge_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_SmashCharge_disabled);

HudScript HudScript_Item_SSmashChg = STANDARD_ITEM_HUD_SCRIPT(badge_SSmashChg);
HudScript HudScript_Item_SSmashChg_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_SSmashChg_disabled);

HudScript HudScript_Item_AutoSmash = STANDARD_ITEM_HUD_SCRIPT(badge_AutoSmash);
HudScript HudScript_Item_AutoSmash_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_AutoSmash_disabled);

HudScript HudScript_Item_FireShield = STANDARD_ITEM_HUD_SCRIPT(badge_FireShield);
HudScript HudScript_Item_FireShield_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_FireShield_disabled);

HudScript HudScript_Item_JumpCharge = STANDARD_ITEM_HUD_SCRIPT(badge_JumpCharge);
HudScript HudScript_Item_JumpCharge_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_JumpCharge_disabled);

HudScript HudScript_Item_SJumpChg = STANDARD_ITEM_HUD_SCRIPT(badge_SJumpChg);
HudScript HudScript_Item_SJumpChg_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_SJumpChg_disabled);

HudScript HudScript_Item_AutoJump = STANDARD_ITEM_HUD_SCRIPT(badge_AutoJump);
HudScript HudScript_Item_AutoJump_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_AutoJump_disabled);

HudScript HudScript_Item_DDownPound = STANDARD_ITEM_HUD_SCRIPT(badge_DDownPound);
HudScript HudScript_Item_DDownPound_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_DDownPound_disabled);

HudScript HudScript_Item_AutoMultibounce = STANDARD_ITEM_HUD_SCRIPT(badge_AutoMultibounce);
HudScript HudScript_Item_AutoMultibounce_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_AutoMultibounce_disabled);

HudScript HudScript_Item_DizzyStomp = STANDARD_ITEM_HUD_SCRIPT(badge_DizzyStomp);
HudScript HudScript_Item_DizzyStomp_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_DizzyStomp_disabled);

HudScript HudScript_Item_HammerThrow = STANDARD_ITEM_HUD_SCRIPT(badge_HammerThrow);
HudScript HudScript_Item_HammerThrow_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_HammerThrow_disabled);

HudScript HudScript_Item_SmashCharge0 = STANDARD_ITEM_HUD_SCRIPT(badge_SmashCharge0);
HudScript HudScript_Item_SmashCharge0_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_SmashCharge0_disabled);

HudScript HudScript_Item_PrettyLucky = STANDARD_ITEM_HUD_SCRIPT(badge_PrettyLucky);
HudScript HudScript_Item_PrettyLucky_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_PrettyLucky_disabled);

HudScript HudScript_Item_FeelingFine = STANDARD_ITEM_HUD_SCRIPT(badge_FeelingFine);
HudScript HudScript_Item_FeelingFine_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_FeelingFine_disabled);

HudScript HudScript_Item_AttackFXA = STANDARD_ITEM_HUD_SCRIPT(badge_AttackFXA);
HudScript HudScript_Item_AttackFXA_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_AttackFXA_disabled);

HudScript HudScript_Item_AllorNothing = STANDARD_ITEM_HUD_SCRIPT(badge_AllorNothing);
HudScript HudScript_Item_AllorNothing_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_AllorNothing_disabled);

HudScript HudScript_Item_HPDrain = STANDARD_ITEM_HUD_SCRIPT(badge_HPDrain);
HudScript HudScript_Item_HPDrain_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_HPDrain_disabled);

HudScript HudScript_Item_JumpCharge0 = STANDARD_ITEM_HUD_SCRIPT(badge_JumpCharge0);
HudScript HudScript_Item_JumpCharge0_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_JumpCharge0_disabled);

HudScript HudScript_Item_SlowGo = STANDARD_ITEM_HUD_SCRIPT(badge_SlowGo);
HudScript HudScript_Item_SlowGo_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_SlowGo_disabled);

HudScript HudScript_Item_FPPlus = STANDARD_ITEM_HUD_SCRIPT(badge_FPPlus);
HudScript HudScript_Item_FPPlus_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_FPPlus_disabled);

HudScript HudScript_Item_MegaRush = STANDARD_ITEM_HUD_SCRIPT(badge_MegaRush);
HudScript HudScript_Item_MegaRush_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_MegaRush_disabled);

HudScript HudScript_Item_IcePower = STANDARD_ITEM_HUD_SCRIPT(badge_IcePower);
HudScript HudScript_Item_IcePower_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_IcePower_disabled);

HudScript HudScript_Item_DefendPlus = STANDARD_ITEM_HUD_SCRIPT(badge_DefendPlus);
HudScript HudScript_Item_DefendPlus_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_DefendPlus_disabled);

HudScript HudScript_Item_PayOff = STANDARD_ITEM_HUD_SCRIPT(badge_PayOff);
HudScript HudScript_Item_PayOff_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_PayOff_disabled);

HudScript HudScript_Item_MoneyMoney = STANDARD_ITEM_HUD_SCRIPT(badge_MoneyMoney);
HudScript HudScript_Item_MoneyMoney_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_MoneyMoney_disabled);

HudScript HudScript_Item_ChillOut = STANDARD_ITEM_HUD_SCRIPT(badge_ChillOut);
HudScript HudScript_Item_ChillOut_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_ChillOut_disabled);

HudScript HudScript_Item_HappyHeart = STANDARD_ITEM_HUD_SCRIPT(badge_HappyHeart);
HudScript HudScript_Item_HappyHeart_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_HappyHeart_disabled);

HudScript HudScript_Item_ZapTap = STANDARD_ITEM_HUD_SCRIPT(badge_ZapTap);
HudScript HudScript_Item_ZapTap_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_ZapTap_disabled);

HudScript HudScript_Item_Berserker = STANDARD_ITEM_HUD_SCRIPT(badge_Berserker);
HudScript HudScript_Item_Berserker_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_Berserker_disabled);

HudScript HudScript_Item_RightOn = STANDARD_ITEM_HUD_SCRIPT(badge_RightOn);
HudScript HudScript_Item_RightOn_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_RightOn_disabled);

HudScript HudScript_Item_RunawayPay = STANDARD_ITEM_HUD_SCRIPT(badge_RunawayPay);
HudScript HudScript_Item_RunawayPay_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_RunawayPay_disabled);

HudScript HudScript_Item_Refund = STANDARD_ITEM_HUD_SCRIPT(badge_Refund);
HudScript HudScript_Item_Refund_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_Refund_disabled);

HudScript HudScript_Item_FlowerSaver = STANDARD_ITEM_HUD_SCRIPT(badge_FlowerSaver);
HudScript HudScript_Item_FlowerSaver_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_FlowerSaver_disabled);

HudScript HudScript_Item_TripleDip = STANDARD_ITEM_HUD_SCRIPT(badge_TripleDip);
HudScript HudScript_Item_TripleDip_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_TripleDip_disabled);

HudScript HudScript_Item_FlowerFanatic = STANDARD_ITEM_HUD_SCRIPT(badge_FlowerFanatic);
HudScript HudScript_Item_FlowerFanatic_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_FlowerFanatic_disabled);

HudScript HudScript_Item_PowerJump = STANDARD_ITEM_HUD_SCRIPT(badge_PowerJump);
HudScript HudScript_Item_PowerJump_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_PowerJump_disabled);

HudScript HudScript_Item_SuperJump = STANDARD_ITEM_HUD_SCRIPT(badge_SuperJump);
HudScript HudScript_Item_SuperJump_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_SuperJump_disabled);

HudScript HudScript_Item_MegaJump = STANDARD_ITEM_HUD_SCRIPT(badge_MegaJump);
HudScript HudScript_Item_MegaJump_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_MegaJump_disabled);

HudScript HudScript_Item_PowerSmash1 = STANDARD_ITEM_HUD_SCRIPT(badge_PowerSmash);
HudScript HudScript_Item_PowerSmash1_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_PowerSmash_disabled);

HudScript HudScript_Item_SuperSmash = STANDARD_ITEM_HUD_SCRIPT(badge_SuperSmash);
HudScript HudScript_Item_SuperSmash_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_SuperSmash_disabled);

HudScript HudScript_Item_MegaSmash = STANDARD_ITEM_HUD_SCRIPT(badge_MegaSmash);
HudScript HudScript_Item_MegaSmash_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_MegaSmash_disabled);

HudScript HudScript_Item_LuckyDay = STANDARD_ITEM_HUD_SCRIPT(badge_LuckyDay);
HudScript HudScript_Item_LuckyDay_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_LuckyDay_disabled);

HudScript HudScript_Item_MegaHPDrain = STANDARD_ITEM_HUD_SCRIPT(badge_MegaHPDrain);
HudScript HudScript_Item_MegaHPDrain_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_MegaHPDrain_disabled);

HudScript HudScript_Item_BumpAttack = STANDARD_ITEM_HUD_SCRIPT(badge_BumpAttack);
HudScript HudScript_Item_BumpAttack_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_BumpAttack_disabled);

HudScript HudScript_Item_PUpDDown = STANDARD_ITEM_HUD_SCRIPT(badge_PUpDDown);
HudScript HudScript_Item_PUpDDown_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_PUpDDown_disabled);

HudScript HudScript_Item_PDownDUp = STANDARD_ITEM_HUD_SCRIPT(badge_PDownDUp);
HudScript HudScript_Item_PDownDUp_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_PDownDUp_disabled);

HudScript HudScript_Item_HeartFinder = STANDARD_ITEM_HUD_SCRIPT(badge_HeartFinder);
HudScript HudScript_Item_HeartFinder_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_HeartFinder_disabled);

HudScript HudScript_Item_FlowerFinder = STANDARD_ITEM_HUD_SCRIPT(badge_FlowerFinder);
HudScript HudScript_Item_FlowerFinder_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_FlowerFinder_disabled);

HudScript HudScript_Item_DizzyAttack = STANDARD_ITEM_HUD_SCRIPT(badge_DizzyAttack);
HudScript HudScript_Item_DizzyAttack_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_DizzyAttack_disabled);

HudScript HudScript_Item_SpeedySpin = STANDARD_ITEM_HUD_SCRIPT(badge_SpeedySpin);
HudScript HudScript_Item_SpeedySpin_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_SpeedySpin_disabled);

HudScript HudScript_Item_SpinAttack = STANDARD_ITEM_HUD_SCRIPT(badge_SpinAttack);
HudScript HudScript_Item_SpinAttack_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_SpinAttack_disabled);

HudScript HudScript_Item_ISpy = STANDARD_ITEM_HUD_SCRIPT(badge_ISpy);
HudScript HudScript_Item_ISpy_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_ISpy_disabled);

HudScript HudScript_Item_PowerRush = STANDARD_ITEM_HUD_SCRIPT(badge_PowerRush);
HudScript HudScript_Item_PowerRush_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_PowerRush_disabled);

HudScript HudScript_Item_LastStand = STANDARD_ITEM_HUD_SCRIPT(badge_LastStand);
HudScript HudScript_Item_LastStand_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_LastStand_disabled);

HudScript HudScript_Item_CloseCall = STANDARD_ITEM_HUD_SCRIPT(badge_CloseCall);
HudScript HudScript_Item_CloseCall_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_CloseCall_disabled);

HudScript HudScript_Item_CrazyHeart = STANDARD_ITEM_HUD_SCRIPT(badge_CrazyHeart);
HudScript HudScript_Item_CrazyHeart_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_CrazyHeart_disabled);

HudScript HudScript_Item_Unused_0D5 = STANDARD_ITEM_HUD_SCRIPT(unused_0D5);
HudScript HudScript_Item_Unused_0D5_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_0D5_disabled);

HudScript HudScript_Item_Unused_0D6 = STANDARD_ITEM_HUD_SCRIPT(unused_0D6);
HudScript HudScript_Item_Unused_0D6_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_0D6_disabled);

HudScript HudScript_Item_Unused_0D7 = STANDARD_ITEM_HUD_SCRIPT(unused_0D7);
HudScript HudScript_Item_Unused_0D7_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_0D7_disabled);

HudScript HudScript_Item_ShrinkSmash = STANDARD_ITEM_HUD_SCRIPT(badge_ShrinkSmash);
HudScript HudScript_Item_ShrinkSmash_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_ShrinkSmash_disabled);

HudScript HudScript_Item_ShrinkStomp = STANDARD_ITEM_HUD_SCRIPT(badge_ShrinkStomp);
HudScript HudScript_Item_ShrinkStomp_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_ShrinkStomp_disabled);

HudScript HudScript_Item_DDownJump = STANDARD_ITEM_HUD_SCRIPT(badge_DDownJump);
HudScript HudScript_Item_DDownJump_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_DDownJump_disabled);

HudScript HudScript_Item_DamageDodge = STANDARD_ITEM_HUD_SCRIPT(badge_DamageDodge);
HudScript HudScript_Item_DamageDodge_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_DamageDodge_disabled);

HudScript HudScript_Item_EarthquakeJump = STANDARD_ITEM_HUD_SCRIPT(badge_EarthquakeJump);
HudScript HudScript_Item_EarthquakeJump_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_EarthquakeJump_disabled);

HudScript HudScript_Item_HappyFlower = STANDARD_ITEM_HUD_SCRIPT(badge_HappyFlower);
HudScript HudScript_Item_HappyFlower_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_HappyFlower_disabled);

HudScript HudScript_Item_Unused_0DE = STANDARD_ITEM_HUD_SCRIPT(badge_HappyCoin);
HudScript HudScript_Item_Unused_0DE_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_HappyCoin_disabled);

HudScript HudScript_Item_Unused_0DF = STANDARD_ITEM_HUD_SCRIPT(unused_0DF);
HudScript HudScript_Item_Unused_0DF_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_0DF_disabled);

HudScript HudScript_Item_DeepFocus = STANDARD_ITEM_HUD_SCRIPT(badge_DeepFocus);
HudScript HudScript_Item_DeepFocus_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_DeepFocus_disabled);

HudScript HudScript_Item_SuperFocus = STANDARD_ITEM_HUD_SCRIPT(badge_SuperFocus);
HudScript HudScript_Item_SuperFocus_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_SuperFocus_disabled);

HudScript HudScript_Item_Kaiden = STANDARD_ITEM_HUD_SCRIPT(badge_Kaiden);
HudScript HudScript_Item_Kaiden_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_Kaiden_disabled);

HudScript HudScript_Item_QuickChange = STANDARD_ITEM_HUD_SCRIPT(badge_QuickChange);
HudScript HudScript_Item_QuickChange_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_QuickChange_disabled);

HudScript HudScript_Item_Unused_0E4 = STANDARD_ITEM_HUD_SCRIPT(unused_0E4);
HudScript HudScript_Item_Unused_0E4_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_0E4_disabled);

HudScript HudScript_Item_Unused_0E5 = STANDARD_ITEM_HUD_SCRIPT(unused_0E5);
HudScript HudScript_Item_Unused_0E5_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_0E5_disabled);

HudScript HudScript_Item_Unused_0E6 = STANDARD_ITEM_HUD_SCRIPT(unused_0E6);
HudScript HudScript_Item_Unused_0E6_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_0E6_disabled);

HudScript HudScript_Item_Unused_0E7 = STANDARD_ITEM_HUD_SCRIPT(unused_0E7);
HudScript HudScript_Item_Unused_0E7_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_0E7_disabled);

HudScript HudScript_Item_Peekaboo = STANDARD_ITEM_HUD_SCRIPT(badge_Peekaboo);
HudScript HudScript_Item_Peekaboo_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_Peekaboo_disabled);

HudScript HudScript_Item_GroupFocus = STANDARD_ITEM_HUD_SCRIPT(badge_GroupFocus);
HudScript HudScript_Item_GroupFocus_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_GroupFocus_disabled);

HudScript HudScript_Item_AttackFXD = STANDARD_ITEM_HUD_SCRIPT(badge_AttackFXD);
HudScript HudScript_Item_AttackFXD_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_AttackFXD_disabled);

HudScript HudScript_Item_AttackFXB = STANDARD_ITEM_HUD_SCRIPT(badge_AttackFXB);
HudScript HudScript_Item_AttackFXB_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_AttackFXB_disabled);

HudScript HudScript_Item_AttackFXE = STANDARD_ITEM_HUD_SCRIPT(badge_AttackFXE);
HudScript HudScript_Item_AttackFXE_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_AttackFXE_disabled);

HudScript HudScript_Item_AttackFXC = STANDARD_ITEM_HUD_SCRIPT(badge_AttackFXC);
HudScript HudScript_Item_AttackFXC_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_AttackFXC_disabled);

HudScript HudScript_Item_AttackFXF = STANDARD_ITEM_HUD_SCRIPT(badge_AttackFXF);
HudScript HudScript_Item_AttackFXF_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_AttackFXF_disabled);

HudScript HudScript_Item_Unused_0EF = STANDARD_ITEM_HUD_SCRIPT(unused_0EF);
HudScript HudScript_Item_Unused_0EF_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_0EF_disabled);

HudScript HudScript_Item_HealthyHealthy = STANDARD_ITEM_HUD_SCRIPT(badge_HealthyHealthy);
HudScript HudScript_Item_HealthyHealthy_disabled = STANDARD_ITEM_HUD_SCRIPT(badge_HealthyHealthy_disabled);

HudScript HudScript_Item_Unused_0F1 = STANDARD_ITEM_HUD_SCRIPT(unused_0F1);
HudScript HudScript_Item_Unused_0F1_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_0F1_disabled);

HudScript HudScript_Item_Unused_0F2 = STANDARD_ITEM_HUD_SCRIPT(unused_0F2);
HudScript HudScript_Item_Unused_0F2_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_0F2_disabled);

HudScript HudScript_Item_Unused_0F3 = STANDARD_ITEM_HUD_SCRIPT(unused_0F3);
HudScript HudScript_Item_Unused_0F3_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_0F3_disabled);

HudScript HudScript_Item_Unused_0F4 = STANDARD_ITEM_HUD_SCRIPT(unused_0F4);
HudScript HudScript_Item_Unused_0F4_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_0F4_disabled);

HudScript HudScript_Item_Unused_0F5 = STANDARD_ITEM_HUD_SCRIPT(unused_0F5);
HudScript HudScript_Item_Unused_0F5_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_0F5_disabled);

HudScript HudScript_Item_Unused_0F6 = STANDARD_ITEM_HUD_SCRIPT(unused_0F6);
HudScript HudScript_Item_Unused_0F6_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_0F6_disabled);

HudScript HudScript_Item_Unused_0F7 = STANDARD_ITEM_HUD_SCRIPT(unused_0F7);
HudScript HudScript_Item_Unused_0F7_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_0F7_disabled);

HudScript HudScript_Item_FireFlower = STANDARD_ITEM_HUD_SCRIPT(battle_FireFlower);
HudScript HudScript_Item_FireFlower_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_FireFlower_disabled);

HudScript HudScript_Item_SnowmanDoll = STANDARD_ITEM_HUD_SCRIPT(battle_SnowmanDoll);
HudScript HudScript_Item_SnowmanDoll_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_SnowmanDoll_disabled);

HudScript HudScript_Item_ThunderRage = STANDARD_ITEM_HUD_SCRIPT(battle_ThunderRage);
HudScript HudScript_Item_ThunderRage_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_ThunderRage_disabled);

HudScript HudScript_Item_ThunderBolt = STANDARD_ITEM_HUD_SCRIPT(battle_ThunderBolt);
HudScript HudScript_Item_ThunderBolt_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_ThunderBolt_disabled);

HudScript HudScript_Item_ShootingStar = STANDARD_ITEM_HUD_SCRIPT(battle_ShootingStar);
HudScript HudScript_Item_ShootingStar_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_ShootingStar_disabled);

HudScript HudScript_Item_DustyHammer = STANDARD_ITEM_HUD_SCRIPT(battle_DustyHammer);
HudScript HudScript_Item_DustyHammer_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_DustyHammer_disabled);

HudScript HudScript_Item_Pebble = STANDARD_ITEM_HUD_SCRIPT(battle_Pebble);
HudScript HudScript_Item_Pebble_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_Pebble_disabled);

HudScript HudScript_Item_Unused_127 = STANDARD_ITEM_HUD_SCRIPT(unused_127);
HudScript HudScript_Item_Unused_127_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_127_disabled);

HudScript HudScript_Item_StoneCap = STANDARD_ITEM_HUD_SCRIPT(battle_StoneCap);
HudScript HudScript_Item_StoneCap_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_StoneCap_disabled);

HudScript HudScript_Item_VoltShroom = STANDARD_ITEM_HUD_SCRIPT(battle_VoltShroom);
HudScript HudScript_Item_VoltShroom_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_VoltShroom_disabled);

HudScript HudScript_Item_PowerStar = STANDARD_ITEM_HUD_SCRIPT(battle_PowerStar);
HudScript HudScript_Item_PowerStar_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_PowerStar_disabled);

HudScript HudScript_Item_Parasol = STANDARD_ITEM_HUD_SCRIPT(battle_Parasol);
HudScript HudScript_Item_Parasol_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_Parasol_disabled);

HudScript HudScript_Item_MagicMirror = STANDARD_ITEM_HUD_SCRIPT(battle_MagicMirror);
HudScript HudScript_Item_MagicMirror_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_MagicMirror_disabled);

HudScript HudScript_Item_Unused_12D = STANDARD_ITEM_HUD_SCRIPT(unused_12D);
HudScript HudScript_Item_Unused_12D_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_12D_disabled);

HudScript HudScript_Item_Unused_12E = STANDARD_ITEM_HUD_SCRIPT(unused_12E);
HudScript HudScript_Item_Unused_12E_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_12E_disabled);

HudScript HudScript_Item_Unused_12F = STANDARD_ITEM_HUD_SCRIPT(unused_12F);
HudScript HudScript_Item_Unused_12F_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_12F_disabled);

HudScript HudScript_Item_Mushroom = STANDARD_ITEM_HUD_SCRIPT(food_Mushroom);
HudScript HudScript_Item_Mushroom_disabled = STANDARD_ITEM_HUD_SCRIPT(food_Mushroom_disabled);

HudScript HudScript_Item_SuperShroom = STANDARD_ITEM_HUD_SCRIPT(food_SuperShroom);
HudScript HudScript_Item_SuperShroom_disabled = STANDARD_ITEM_HUD_SCRIPT(food_SuperShroom_disabled);

HudScript HudScript_Item_UltraShroom = STANDARD_ITEM_HUD_SCRIPT(food_UltraShroom);
HudScript HudScript_Item_UltraShroom_disabled = STANDARD_ITEM_HUD_SCRIPT(food_UltraShroom_disabled);

HudScript HudScript_Item_LifeShroom = STANDARD_ITEM_HUD_SCRIPT(food_LifeShroom);
HudScript HudScript_Item_LifeShroom_disabled = STANDARD_ITEM_HUD_SCRIPT(food_LifeShroom_disabled);

HudScript HudScript_Item_DriedShroom = STANDARD_ITEM_HUD_SCRIPT(food_DriedShroom);
HudScript HudScript_Item_DriedShroom_disabled = STANDARD_ITEM_HUD_SCRIPT(food_DriedShroom_disabled);

HudScript HudScript_Item_TastyTonic = STANDARD_ITEM_HUD_SCRIPT(food_TastyTonic);
HudScript HudScript_Item_TastyTonic_disabled = STANDARD_ITEM_HUD_SCRIPT(food_TastyTonic_disabled);

HudScript HudScript_Item_SuperSoda = STANDARD_ITEM_HUD_SCRIPT(food_SuperSoda);
HudScript HudScript_Item_SuperSoda_disabled = STANDARD_ITEM_HUD_SCRIPT(food_SuperSoda_disabled);

HudScript HudScript_Item_BlueBerry = STANDARD_ITEM_HUD_SCRIPT(food_BlueBerry);
HudScript HudScript_Item_BlueBerry_disabled = STANDARD_ITEM_HUD_SCRIPT(food_BlueBerry_disabled);

HudScript HudScript_Item_RedBerry = STANDARD_ITEM_HUD_SCRIPT(food_RedBerry);
HudScript HudScript_Item_RedBerry_disabled = STANDARD_ITEM_HUD_SCRIPT(food_RedBerry_disabled);

HudScript HudScript_Item_YellowBerry = STANDARD_ITEM_HUD_SCRIPT(food_YellowBerry);
HudScript HudScript_Item_YellowBerry_disabled = STANDARD_ITEM_HUD_SCRIPT(food_YellowBerry_disabled);

HudScript HudScript_Item_BubbleBerry = STANDARD_ITEM_HUD_SCRIPT(food_BubbleBerry);
HudScript HudScript_Item_BubbleBerry_disabled = STANDARD_ITEM_HUD_SCRIPT(food_BubbleBerry_disabled);

HudScript HudScript_Item_Goomnut = STANDARD_ITEM_HUD_SCRIPT(food_Goomnut);
HudScript HudScript_Item_Goomnut_disabled = STANDARD_ITEM_HUD_SCRIPT(food_Goomnut_disabled);

HudScript HudScript_Item_KoopaLeaf = STANDARD_ITEM_HUD_SCRIPT(food_KoopaLeaf);
HudScript HudScript_Item_KoopaLeaf_disabled = STANDARD_ITEM_HUD_SCRIPT(food_KoopaLeaf_disabled);

HudScript HudScript_Item_DriedPasta = STANDARD_ITEM_HUD_SCRIPT(food_DriedPasta);
HudScript HudScript_Item_DriedPasta_disabled = STANDARD_ITEM_HUD_SCRIPT(food_DriedPasta_disabled);

HudScript HudScript_Item_Lime = STANDARD_ITEM_HUD_SCRIPT(food_Lime);
HudScript HudScript_Item_Lime_disabled = STANDARD_ITEM_HUD_SCRIPT(food_Lime_disabled);

HudScript HudScript_Item_Lemon = STANDARD_ITEM_HUD_SCRIPT(food_Lemon);
HudScript HudScript_Item_Lemon_disabled = STANDARD_ITEM_HUD_SCRIPT(food_Lemon_disabled);

HudScript HudScript_Item_DriedFruit = STANDARD_ITEM_HUD_SCRIPT(food_DriedFruit);
HudScript HudScript_Item_DriedFruit_disabled = STANDARD_ITEM_HUD_SCRIPT(food_DriedFruit_disabled);

HudScript HudScript_Item_StrangeLeaf = STANDARD_ITEM_HUD_SCRIPT(food_StrangeLeaf);
HudScript HudScript_Item_StrangeLeaf_disabled = STANDARD_ITEM_HUD_SCRIPT(food_StrangeLeaf_disabled);

HudScript HudScript_Item_CakeMix = STANDARD_ITEM_HUD_SCRIPT(food_CakeMix);
HudScript HudScript_Item_CakeMix_disabled = STANDARD_ITEM_HUD_SCRIPT(food_CakeMix_disabled);

HudScript HudScript_Item_Egg = STANDARD_ITEM_HUD_SCRIPT(food_Egg);
HudScript HudScript_Item_Egg_disabled = STANDARD_ITEM_HUD_SCRIPT(food_Egg_disabled);

HudScript HudScript_Item_Coconut = STANDARD_ITEM_HUD_SCRIPT(food_Coconut);
HudScript HudScript_Item_Coconut_disabled = STANDARD_ITEM_HUD_SCRIPT(food_Coconut_disabled);

HudScript HudScript_Item_Melon = STANDARD_ITEM_HUD_SCRIPT(food_Melon);
HudScript HudScript_Item_Melon_disabled = STANDARD_ITEM_HUD_SCRIPT(food_Melon_disabled);

HudScript HudScript_Item_StinkyHerb = STANDARD_ITEM_HUD_SCRIPT(food_StinkyHerb);
HudScript HudScript_Item_StinkyHerb_disabled = STANDARD_ITEM_HUD_SCRIPT(food_StinkyHerb_disabled);

HudScript HudScript_Item_IcedPotato = STANDARD_ITEM_HUD_SCRIPT(food_IcedPotato);
HudScript HudScript_Item_IcedPotato_disabled = STANDARD_ITEM_HUD_SCRIPT(food_IcedPotato_disabled);

HudScript HudScript_Item_HoneySyrup = STANDARD_ITEM_HUD_SCRIPT(food_HoneySyrup);
HudScript HudScript_Item_HoneySyrup_disabled = STANDARD_ITEM_HUD_SCRIPT(food_HoneySyrup_disabled);

HudScript HudScript_Item_MapleSyrup = STANDARD_ITEM_HUD_SCRIPT(food_MapleSyrup);
HudScript HudScript_Item_MapleSyrup_disabled = STANDARD_ITEM_HUD_SCRIPT(food_MapleSyrup_disabled);

HudScript HudScript_Item_JamminJelly = STANDARD_ITEM_HUD_SCRIPT(food_JamminJelly);
HudScript HudScript_Item_JamminJelly_disabled = STANDARD_ITEM_HUD_SCRIPT(food_JamminJelly_disabled);

HudScript HudScript_Item_WhackasBump = STANDARD_ITEM_HUD_SCRIPT(food_WhackasBump);
HudScript HudScript_Item_WhackasBump_disabled = STANDARD_ITEM_HUD_SCRIPT(food_WhackasBump_disabled);

HudScript HudScript_Item_Apple = STANDARD_ITEM_HUD_SCRIPT(food_Apple);
HudScript HudScript_Item_Apple_disabled = STANDARD_ITEM_HUD_SCRIPT(food_Apple_disabled);

HudScript HudScript_Item_BakingSalt = STANDARD_ITEM_HUD_SCRIPT(peach_BakingSalt);
HudScript HudScript_Item_BakingSalt_disabled = STANDARD_ITEM_HUD_SCRIPT(peach_BakingSalt_disabled);

HudScript HudScript_Item_BakingSugar = STANDARD_ITEM_HUD_SCRIPT(peach_BakingSugar);
HudScript HudScript_Item_BakingSugar_disabled = STANDARD_ITEM_HUD_SCRIPT(peach_BakingSugar_disabled);

HudScript HudScript_Item_BakingEgg = STANDARD_ITEM_HUD_SCRIPT(peach_BakingEgg);
HudScript HudScript_Item_BakingEgg_disabled = STANDARD_ITEM_HUD_SCRIPT(peach_BakingEgg_disabled);

HudScript HudScript_Item_BakingCream = STANDARD_ITEM_HUD_SCRIPT(peach_BakingCream);
HudScript HudScript_Item_BakingCream_disabled = STANDARD_ITEM_HUD_SCRIPT(peach_BakingCream_disabled);

HudScript HudScript_Item_BakingStrawberry = STANDARD_ITEM_HUD_SCRIPT(peach_BakingStrawberry);
HudScript HudScript_Item_BakingStrawberry_disabled = STANDARD_ITEM_HUD_SCRIPT(peach_BakingStrawberry_disabled);

HudScript HudScript_Item_BakingButter = STANDARD_ITEM_HUD_SCRIPT(peach_BakingButter);
HudScript HudScript_Item_BakingButter_disabled = STANDARD_ITEM_HUD_SCRIPT(peach_BakingButter_disabled);

HudScript HudScript_Item_BakingCleanser = STANDARD_ITEM_HUD_SCRIPT(peach_BakingCleanser);
HudScript HudScript_Item_BakingCleanser_disabled = STANDARD_ITEM_HUD_SCRIPT(peach_BakingCleanser_disabled);

HudScript HudScript_Item_BakingWater = STANDARD_ITEM_HUD_SCRIPT(peach_BakingWater);
HudScript HudScript_Item_BakingWater_disabled = STANDARD_ITEM_HUD_SCRIPT(peach_BakingWater_disabled);

HudScript HudScript_Item_BakingFlour = STANDARD_ITEM_HUD_SCRIPT(peach_BakingFlour);
HudScript HudScript_Item_BakingFlour_disabled = STANDARD_ITEM_HUD_SCRIPT(peach_BakingFlour_disabled);

HudScript HudScript_Item_BakingMilk = STANDARD_ITEM_HUD_SCRIPT(peach_BakingMilk);
HudScript HudScript_Item_BakingMilk_disabled = STANDARD_ITEM_HUD_SCRIPT(peach_BakingMilk_disabled);

HudScript HudScript_Item_Unused_11F = STANDARD_ITEM_HUD_SCRIPT(unused_11F);
HudScript HudScript_Item_Unused_11F_disabled = STANDARD_ITEM_HUD_SCRIPT(unused_11F_disabled);

HudScript HudScript_Item_SleepySheep = STANDARD_ITEM_HUD_SCRIPT(battle_SleepySheep);
HudScript HudScript_Item_SleepySheep_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_SleepySheep_disabled);

HudScript HudScript_Item_XBandage = STANDARD_ITEM_HUD_SCRIPT(battle_XBandage);
HudScript HudScript_Item_XBandage_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_XBandage_disabled);

HudScript HudScript_Item_POWBlock = STANDARD_ITEM_HUD_SCRIPT(battle_POWBlock);
HudScript HudScript_Item_POWBlock_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_POWBlock_disabled);

HudScript HudScript_Item_HustleDrink = STANDARD_ITEM_HUD_SCRIPT(battle_HustleDrink);
HudScript HudScript_Item_HustleDrink_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_HustleDrink_disabled);

HudScript HudScript_Item_StopWatch = STANDARD_ITEM_HUD_SCRIPT(battle_StopWatch);
HudScript HudScript_Item_StopWatch_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_StopWatch_disabled);

HudScript HudScript_Item_DizzyDial = STANDARD_ITEM_HUD_SCRIPT(battle_DizzyDial);
HudScript HudScript_Item_DizzyDial_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_DizzyDial_disabled);

HudScript HudScript_Item_Unused_136 = STANDARD_ITEM_HUD_SCRIPT(battle_136);
HudScript HudScript_Item_Unused_136_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_136_disabled);

HudScript HudScript_Item_Unused_137 = STANDARD_ITEM_HUD_SCRIPT(battle_137);
HudScript HudScript_Item_Unused_137_disabled = STANDARD_ITEM_HUD_SCRIPT(battle_137_disabled);
