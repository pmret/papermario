.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A2910
/* 4176A0 802A2910 3C02802B */  lui       $v0, %hi(battle_menu_moveOptionCount)
/* 4176A4 802A2914 8C42D4A4 */  lw        $v0, %lo(battle_menu_moveOptionCount)($v0)
/* 4176A8 802A2918 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4176AC 802A291C AFB00010 */  sw        $s0, 0x10($sp)
/* 4176B0 802A2920 0000802D */  daddu     $s0, $zero, $zero
/* 4176B4 802A2924 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4176B8 802A2928 1840000F */  blez      $v0, .L802A2968
/* 4176BC 802A292C AFB10014 */   sw       $s1, 0x14($sp)
/* 4176C0 802A2930 3C11802B */  lui       $s1, %hi(battle_menu_moveOptionIconIDs)
/* 4176C4 802A2934 2631D128 */  addiu     $s1, $s1, %lo(battle_menu_moveOptionIconIDs)
/* 4176C8 802A2938 240500FF */  addiu     $a1, $zero, 0xff
.L802A293C:
/* 4176CC 802A293C 00A0302D */  daddu     $a2, $a1, $zero
/* 4176D0 802A2940 00A0382D */  daddu     $a3, $a1, $zero
/* 4176D4 802A2944 8E240000 */  lw        $a0, ($s1)
/* 4176D8 802A2948 0C0513BF */  jal       icon_set_tint
/* 4176DC 802A294C 26310004 */   addiu    $s1, $s1, 4
/* 4176E0 802A2950 3C02802B */  lui       $v0, %hi(battle_menu_moveOptionCount)
/* 4176E4 802A2954 8C42D4A4 */  lw        $v0, %lo(battle_menu_moveOptionCount)($v0)
/* 4176E8 802A2958 26100001 */  addiu     $s0, $s0, 1
/* 4176EC 802A295C 0202102A */  slt       $v0, $s0, $v0
/* 4176F0 802A2960 1440FFF6 */  bnez      $v0, .L802A293C
/* 4176F4 802A2964 240500FF */   addiu    $a1, $zero, 0xff
.L802A2968:
/* 4176F8 802A2968 240500FF */  addiu     $a1, $zero, 0xff
/* 4176FC 802A296C 00A0302D */  daddu     $a2, $a1, $zero
/* 417700 802A2970 3C04802B */  lui       $a0, %hi(battle_menu_moveCursorIcon)
/* 417704 802A2974 8C84D118 */  lw        $a0, %lo(battle_menu_moveCursorIcon)($a0)
/* 417708 802A2978 0C0513BF */  jal       icon_set_tint
/* 41770C 802A297C 00A0382D */   daddu    $a3, $a1, $zero
/* 417710 802A2980 240500FF */  addiu     $a1, $zero, 0xff
/* 417714 802A2984 00A0302D */  daddu     $a2, $a1, $zero
/* 417718 802A2988 3C04802B */  lui       $a0, %hi(battle_menu_moveUpArrowIcon)
/* 41771C 802A298C 8C84D11C */  lw        $a0, %lo(battle_menu_moveUpArrowIcon)($a0)
/* 417720 802A2990 0C0513BF */  jal       icon_set_tint
/* 417724 802A2994 00A0382D */   daddu    $a3, $a1, $zero
/* 417728 802A2998 240500FF */  addiu     $a1, $zero, 0xff
/* 41772C 802A299C 00A0302D */  daddu     $a2, $a1, $zero
/* 417730 802A29A0 3C04802B */  lui       $a0, %hi(battle_menu_moveDownArrowIcon)
/* 417734 802A29A4 8C84D120 */  lw        $a0, %lo(battle_menu_moveDownArrowIcon)($a0)
/* 417738 802A29A8 0C0513BF */  jal       icon_set_tint
/* 41773C 802A29AC 00A0382D */   daddu    $a3, $a1, $zero
/* 417740 802A29B0 240500FF */  addiu     $a1, $zero, 0xff
/* 417744 802A29B4 00A0302D */  daddu     $a2, $a1, $zero
/* 417748 802A29B8 3C04802B */  lui       $a0, %hi(battle_menu_moveTitleIcon)
/* 41774C 802A29BC 8C84D188 */  lw        $a0, %lo(battle_menu_moveTitleIcon)($a0)
/* 417750 802A29C0 0C0513BF */  jal       icon_set_tint
/* 417754 802A29C4 00A0382D */   daddu    $a3, $a1, $zero
/* 417758 802A29C8 3C02802B */  lui       $v0, %hi(battle_menu_moveOptionCount)
/* 41775C 802A29CC 8C42D4A4 */  lw        $v0, %lo(battle_menu_moveOptionCount)($v0)
/* 417760 802A29D0 1840000F */  blez      $v0, .L802A2A10
/* 417764 802A29D4 0000802D */   daddu    $s0, $zero, $zero
/* 417768 802A29D8 3C11802B */  lui       $s1, %hi(battle_menu_moveOptionCostUnitIconIDs)
/* 41776C 802A29DC 2631D190 */  addiu     $s1, $s1, %lo(battle_menu_moveOptionCostUnitIconIDs)
/* 417770 802A29E0 240500FF */  addiu     $a1, $zero, 0xff
.L802A29E4:
/* 417774 802A29E4 00A0302D */  daddu     $a2, $a1, $zero
/* 417778 802A29E8 00A0382D */  daddu     $a3, $a1, $zero
/* 41777C 802A29EC 8E240000 */  lw        $a0, ($s1)
/* 417780 802A29F0 0C0513BF */  jal       icon_set_tint
/* 417784 802A29F4 26310004 */   addiu    $s1, $s1, 4
/* 417788 802A29F8 3C02802B */  lui       $v0, %hi(battle_menu_moveOptionCount)
/* 41778C 802A29FC 8C42D4A4 */  lw        $v0, %lo(battle_menu_moveOptionCount)($v0)
/* 417790 802A2A00 26100001 */  addiu     $s0, $s0, 1
/* 417794 802A2A04 0202102A */  slt       $v0, $s0, $v0
/* 417798 802A2A08 5440FFF6 */  bnel      $v0, $zero, .L802A29E4
/* 41779C 802A2A0C 240500FF */   addiu    $a1, $zero, 0xff
.L802A2A10:
/* 4177A0 802A2A10 3C04802B */  lui       $a0, %hi(battle_menu_moveCursorIcon)
/* 4177A4 802A2A14 8C84D118 */  lw        $a0, %lo(battle_menu_moveCursorIcon)($a0)
/* 4177A8 802A2A18 3C058010 */  lui       $a1, %hi(D_80104A28)
/* 4177AC 802A2A1C 24A54A28 */  addiu     $a1, $a1, %lo(D_80104A28)
/* 4177B0 802A2A20 0C0511FF */  jal       set_menu_icon_script
/* 4177B4 802A2A24 00000000 */   nop
/* 4177B8 802A2A28 24040001 */  addiu     $a0, $zero, 1
/* 4177BC 802A2A2C 0C051F9F */  jal       set_window_update
/* 4177C0 802A2A30 24050005 */   addiu    $a1, $zero, 5
/* 4177C4 802A2A34 3C02802B */  lui       $v0, %hi(battle_menu_hasSpiritsMenu)
/* 4177C8 802A2A38 8C42D4A0 */  lw        $v0, %lo(battle_menu_hasSpiritsMenu)($v0)
/* 4177CC 802A2A3C 54400006 */  bnel      $v0, $zero, .L802A2A58
/* 4177D0 802A2A40 24040004 */   addiu    $a0, $zero, 4
/* 4177D4 802A2A44 24040002 */  addiu     $a0, $zero, 2
/* 4177D8 802A2A48 0C051F9F */  jal       set_window_update
/* 4177DC 802A2A4C 24050005 */   addiu    $a1, $zero, 5
/* 4177E0 802A2A50 080A8A99 */  j         .L802A2A64
/* 4177E4 802A2A54 24040003 */   addiu    $a0, $zero, 3
.L802A2A58:
/* 4177E8 802A2A58 0C051F9F */  jal       set_window_update
/* 4177EC 802A2A5C 24050005 */   addiu    $a1, $zero, 5
/* 4177F0 802A2A60 24040005 */  addiu     $a0, $zero, 5
.L802A2A64:
/* 4177F4 802A2A64 0C051F9F */  jal       set_window_update
/* 4177F8 802A2A68 24050005 */   addiu    $a1, $zero, 5
/* 4177FC 802A2A6C 24040008 */  addiu     $a0, $zero, 8
/* 417800 802A2A70 0C051F9F */  jal       set_window_update
/* 417804 802A2A74 24050001 */   addiu    $a1, $zero, 1
/* 417808 802A2A78 2402000A */  addiu     $v0, $zero, 0xa
/* 41780C 802A2A7C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 417810 802A2A80 8FB10014 */  lw        $s1, 0x14($sp)
/* 417814 802A2A84 8FB00010 */  lw        $s0, 0x10($sp)
/* 417818 802A2A88 24030001 */  addiu     $v1, $zero, 1
/* 41781C 802A2A8C 3C01802B */  lui       $at, %hi(battle_menu_moveTextColor)
/* 417820 802A2A90 A422D114 */  sh        $v0, %lo(battle_menu_moveTextColor)($at)
/* 417824 802A2A94 240200FF */  addiu     $v0, $zero, 0xff
/* 417828 802A2A98 3C01802B */  lui       $at, %hi(D_802AD10F)
/* 41782C 802A2A9C A023D10F */  sb        $v1, %lo(D_802AD10F)($at)
/* 417830 802A2AA0 3C01802B */  lui       $at, %hi(battle_menu_moveTextOpacity)
/* 417834 802A2AA4 A422D116 */  sh        $v0, %lo(battle_menu_moveTextOpacity)($at)
/* 417838 802A2AA8 3C01802B */  lui       $at, %hi(battle_menu_moveState)
/* 41783C 802A2AAC A023D108 */  sb        $v1, %lo(battle_menu_moveState)($at)
/* 417840 802A2AB0 03E00008 */  jr        $ra
/* 417844 802A2AB4 27BD0020 */   addiu    $sp, $sp, 0x20
