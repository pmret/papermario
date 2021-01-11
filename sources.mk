OBJECTS := $(foreach OBJECT, $(shell $(PYTHON) tools/n64splat/list_objects.py $(SPLAT_YAML)), $(BUILD_DIR)/$(OBJECT))

DSL_C_FILES := $(shell grep -lrF "SCRIPT" src)

MAPS := \
	dro_01 dro_02 \
	hos_00 hos_01 hos_02 hos_03 hos_04 hos_05 hos_06 hos_10 hos_20 \
	isk_01 isk_02 isk_03 isk_04 isk_05 isk_06 isk_07 isk_08 isk_09 isk_10 isk_11 isk_12 isk_13 isk_14 isk_16 isk_18 isk_19 \
	iwa_00 iwa_01 iwa_02 iwa_03 iwa_04 iwa_10 iwa_11 \
	osr_00 osr_01 osr_02 osr_03 kkj_00 kkj_01 kkj_02 kkj_03 kkj_10 kkj_11 kkj_12 kkj_13 kkj_14 kkj_15 kkj_16 kkj_17 kkj_18 kkj_19 kkj_20 kkj_21 kkj_22 kkj_23 kkj_24 kkj_25 kkj_26 kkj_27 kkj_28 kkj_29 \
	kmr_00 kmr_02 kmr_03 kmr_04 kmr_05 kmr_06 kmr_07 kmr_09 kmr_10 kmr_11 kmr_12 kmr_20 kmr_30 \
	kpa_01 kpa_03 kpa_04 kpa_08 kpa_09 kpa_10 kpa_11 kpa_12 kpa_13 kpa_14 kpa_15 kpa_16 kpa_17 kpa_32 kpa_33 kpa_40 kpa_41 kpa_50 kpa_52 kpa_60 kpa_61 kpa_62 kpa_63 kpa_70 kpa_80 kpa_90 kpa_91 kpa_94 kpa_95 kpa_96 kpa_102 kpa_111 kpa_112 kpa_113 kpa_115 kpa_116 kpa_117 kpa_118 kpa_119 kpa_121 kpa_130 kpa_133 kpa_134 \
	machi mac_00 mac_01 mac_02 mac_03 mac_04 mac_05 mac_06 \
	tik_01 tik_02 tik_03 tik_04 tik_05 tik_06 tik_07 tik_08 tik_09 tik_10 tik_12 tik_14 tik_15 tik_17 tik_18 tik_19 tik_20 tik_21 tik_22 tik_23 tik_25 \
	kgr_01 kgr_02 \
	nok_01 nok_02 nok_03 nok_04 nok_11 nok_12 nok_13 nok_14 nok_15 \
	sbk_00 sbk_01 sbk_02 sbk_03 sbk_04 sbk_05 sbk_06 sbk_10 sbk_11 sbk_12 sbk_13 sbk_14 sbk_15 sbk_16 sbk_20 sbk_21 sbk_22 sbk_23 sbk_24 sbk_25 sbk_26 sbk_30 sbk_31 sbk_32 sbk_33 sbk_34 sbk_35 sbk_36 sbk_40 sbk_41 sbk_42 sbk_43 sbk_44 sbk_45 sbk_46 sbk_50 sbk_51 sbk_52 sbk_53 sbk_54 sbk_55 sbk_56 sbk_60 sbk_61 sbk_62 sbk_63 sbk_64 sbk_65 sbk_66 sbk_99 \
	trd_00 trd_01 trd_02 trd_03 trd_04 trd_05 trd_06 trd_07 trd_08 trd_09 trd_10 \
	tst_01 tst_02 tst_03 tst_04 tst_10 tst_11 tst_12 tst_13 tst_20 \
	jan_00 jan_01 jan_02 jan_03 jan_04 jan_05 jan_06 jan_07 jan_08 jan_09 jan_10 jan_11 jan_12 jan_13 jan_14 jan_15 jan_16 jan_17 jan_18 jan_19 jan_22 jan_23 \
	mim_01 mim_02 mim_03 mim_04 mim_05 mim_06 mim_07 mim_08 mim_09 mim_10 mim_11 mim_12 \
	obk_01 obk_02 obk_03 obk_04 obk_05 obk_06 obk_07 obk_08 obk_09 \
	arn_02 arn_03 arn_04 arn_05 arn_07 arn_08 arn_09 arn_10 arn_11 arn_12 arn_13 arn_20 \
	dgb_01 dgb_02 dgb_03 dgb_04 dgb_05 dgb_06 dgb_07 dgb_08 dgb_09 dgb_10 dgb_11 dgb_12 dgb_13 dgb_14 dgb_15 dgb_16 dgb_17 dgb_18 \
	kzn_01 kzn_02 kzn_03 kzn_04 kzn_05 kzn_06 kzn_07 kzn_08 kzn_09 kzn_10 kzn_11 kzn_17 kzn_18 kzn_19 kzn_20 kzn_22 kzn_23 \
	flo_00 flo_03 flo_07 flo_08 flo_09 flo_10 flo_11 flo_12 flo_13 flo_14 flo_15 flo_16 flo_17 flo_18 flo_19 flo_21 flo_22 flo_23 flo_24 flo_25 \
	sam_01 sam_02 sam_03 sam_04 sam_05 sam_06 sam_07 sam_08 sam_09 sam_10 sam_11 sam_12 \
	pra_01 pra_02 pra_03 pra_04 pra_05 pra_09 pra_10 pra_11 pra_13 pra_14 pra_15 pra_16 pra_18 pra_19 pra_20 pra_21 pra_22 pra_29 pra_31 pra_32 pra_33 pra_34 pra_35 pra_40 \
	omo_01 omo_02 omo_03 omo_04 omo_05 omo_06 omo_07 omo_08 omo_09 omo_10 omo_11 omo_12 omo_13 omo_14 omo_15 omo_16 omo_17 \
	end_00 end_01 \
	mgm_00 mgm_01 mgm_02 mgm_03 \
	gv_01 \
	kmr_bt03 kmr_bt04 kmr_bt05 kmr_bt06 \
	nok_bt01 nok_bt02 nok_bt03 nok_bt04 \
	trd_bt00 trd_bt01 trd_bt02 trd_bt03 trd_bt04 trd_bt05 \
	iwa_bt01 iwa_bt02 \
	sbk_bt02 \
	isk_bt01 isk_bt02 isk_bt03 isk_bt04 isk_bt05 isk_bt06 isk_bt07 isk_bt08 \
	arn_bt01 arn_bt02 arn_bt03 arn_bt04 arn_bt05 arn_bt06 \
	dgb_bt01 dgb_bt02 dgb_bt03 dgb_bt04 dgb_bt05 \
	mim_bt01 \
	omo_bt01 omo_bt02 omo_bt03 omo_bt04 omo_bt05 omo_bt06 omo_bt07 \
	kgr_bt01 flo_bt01 flo_bt02 flo_bt03 flo_bt04 flo_bt05 flo_bt06 \
	jan_bt00 jan_bt01 jan_bt02 jan_bt03 jan_bt04 \
	kzn_bt01 kzn_bt02 kzn_bt04 kzn_bt05 sam_bt01 sam_bt02 sam_bt03 sam_bt04 \
	tik_bt01 tik_bt02 tik_bt03 tik_bt04 tik_bt05 \
	pra_bt01 pra_bt02 pra_bt03 pra_bt04 mac_bt01 mac_bt02 \
	kpa_bt01 kpa_bt02 kpa_bt03 kpa_bt04 kpa_bt05 kpa_bt07 kpa_bt08 kpa_bt09 kpa_bt11 kpa_bt13 kpa_bt14 \
	hos_bt01 hos_bt02 \
	kkj_bt01 kkj_bt02

ASSETS := \
	$(foreach map, $(MAPS), $(map)_shape $(map)_hit) \
	mac_tex tik_tex kgr_tex kmr_tex iwa_tex sbk_tex dro_tex isk_tex trd_tex nok_tex hos_tex kpa_tex osr_tex kkj_tex tst_tex jan_tex mim_tex obk_tex arn_tex dgb_tex kzn_tex flo_tex sam_tex pra_tex omo_tex end_tex mgm_tex gv__tex \
	kmr_bg nok_bg sbk_bg sbk3_bg iwa_bg hos_bg arn_bg obk_bg omo_bg yos_bg jan_bg fla_bg flb_bg sra_bg yki_bg sam_bg kpa_bg title_bg \
	title_data \
	party_kurio party_kameki party_pinki party_pareta party_resa party_akari party_opuku party_pokopi

MESSAGES := $(shell find msg -type f -name "*.msg" 2> /dev/null)

NPC_SPRITES := world_goombario world_kooper world_bombette world_parakarry world_bow world_watt world_sushie world_lakilester battle_goombario battle_kooper battle_bombette battle_parakarry battle_bow battle_watt battle_sushie battle_lakilester kooper_without_shell world_eldstar world_mamar world_skolar world_muskular world_misstar world_klevar world_kalmar battle_eldstar battle_mamar battle_skolar battle_muskular battle_misstar battle_klevar battle_kalmar twink jr_troopa spiked_jr_troopa spiked_para_jr_troopa mage_jr_troopa para_jr_troopa goomba spiked_goomba paragoomba koopa_troopa para_troopa fuzzy bob_omb bullet_bill bill_blaster monty_mole cleft pokey battle_bandit buzzy_beetle swooper stone_chomp putrid_piranha piranha_plant sentinel world_clubba battle_clubba shy_guy groove_guy sky_guy pyro_guy spy_guy medi_guy fuzzipede jungle_guy heart_plant hurt_plant m_bush bubble kent_c_koopa dayzee lakitu spiny bzzap ruff_puff spike_top duplighost albino_dino blooper baby_blooper gulpit dry_bones thrown_bone bony_beetle magikoopa flying_magikoopa world_koopatrol koopatrol hammer_bros bush_basic bush_blocky bush_dry bush_leafy bush_matted world_kammy battle_kammy goomba_bros goomba_king spiky_goomnut dark_toad koopa_bros buzzar tutankoopa chain_chomp world_tubba battle_tubba tubbas_heart big_lantern_ghost shy_squad_guy marshal_guy stilt_guy stilt_guy_unfold shy_stack_guy shy_stack_unfold shy_stack_damage shy_stack_rock general_guy general_guy_bomb tank_guy lava_piranha_head petit_piranha lava_bud huff_n_puff tuff_puff monstar crystal_king world_bowser battle_bowser luigi toad three_sisters vanna_t toad_kid toad_guard harry_t toad_minister postmaster conductor_toad train_station_toad fishmael artist_toad koopa koopa_without_shell world_bob_omb whacka dryite mouser boo yoshi yoshi_kid raven bubulb penguin shiver_toad world_bandit goompa goombaria gooma goompapa goomama the_master chan lee merlon chet_rippo rowf minh_t russ_t tayce_t fice_t bartender chanterelle rip_cheato chuck_quizmo merluvlee merlar merlow star_kid kolorado_wife koopa_koot kolorado battle_kolorado archeologist nomadimouse world_merlee battle_merlee disguised_moustafa moustafa oaklie bootler yakkey gourmet_guy village_leader leaders_friend rafael_raven tolielup gate_flower petunia posie lily rosie sun lakilulu ninji mayor_penguin mayor_penguin_wife penguin_patrol herringway merle star_rod fire coin parade_peach parade_koopas parade_burnt_bowser parade_luigi parade_partners parade_yoshis parade_kolorados parade_chicks parade_ice_show parade_toads parade_batons parade_drums parade_flags parade_horns parade_tubba_balloon parade_wizards parade_mario parade_shy_guys parade_twink leaf

# Image settings
$(BUILD_DIR)/img/battle/text_action_command_ratings.ia4.png: IMG_FLAGS = --flip-y
