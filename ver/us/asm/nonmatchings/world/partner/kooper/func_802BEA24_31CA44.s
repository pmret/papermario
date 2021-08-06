.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BEA24_31CA44
/* 31CA44 802BEA24 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 31CA48 802BEA28 AFB10014 */  sw        $s1, 0x14($sp)
/* 31CA4C 802BEA2C 0080882D */  daddu     $s1, $a0, $zero
/* 31CA50 802BEA30 3C04802C */  lui       $a0, %hi(D_802BEC54)
/* 31CA54 802BEA34 2484EC54 */  addiu     $a0, $a0, %lo(D_802BEC54)
/* 31CA58 802BEA38 AFB20018 */  sw        $s2, 0x18($sp)
/* 31CA5C 802BEA3C 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* 31CA60 802BEA40 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* 31CA64 802BEA44 3C028011 */  lui       $v0, %hi(gPartnerActionStatus)
/* 31CA68 802BEA48 2442EBB0 */  addiu     $v0, $v0, %lo(gPartnerActionStatus)
/* 31CA6C 802BEA4C AFBF0020 */  sw        $ra, 0x20($sp)
/* 31CA70 802BEA50 AFB3001C */  sw        $s3, 0x1c($sp)
/* 31CA74 802BEA54 AFB00010 */  sw        $s0, 0x10($sp)
/* 31CA78 802BEA58 AC800000 */  sw        $zero, ($a0)
/* 31CA7C 802BEA5C 80430000 */  lb        $v1, ($v0)
/* 31CA80 802BEA60 10600024 */  beqz      $v1, .L802BEAF4
/* 31CA84 802BEA64 0040982D */   daddu    $s3, $v0, $zero
/* 31CA88 802BEA68 24020002 */  addiu     $v0, $zero, 2
/* 31CA8C 802BEA6C 14620002 */  bne       $v1, $v0, .L802BEA78
/* 31CA90 802BEA70 24020001 */   addiu    $v0, $zero, 1
/* 31CA94 802BEA74 AC820000 */  sw        $v0, ($a0)
.L802BEA78:
/* 31CA98 802BEA78 3C10802C */  lui       $s0, %hi(D_802BEC64)
/* 31CA9C 802BEA7C 2610EC64 */  addiu     $s0, $s0, %lo(D_802BEC64)
/* 31CAA0 802BEA80 8E020000 */  lw        $v0, ($s0)
/* 31CAA4 802BEA84 50400005 */  beql      $v0, $zero, .L802BEA9C
/* 31CAA8 802BEA88 24040284 */   addiu    $a0, $zero, 0x284
/* 31CAAC 802BEA8C 0C038069 */  jal       enable_player_input
/* 31CAB0 802BEA90 00000000 */   nop
/* 31CAB4 802BEA94 AE000000 */  sw        $zero, ($s0)
/* 31CAB8 802BEA98 24040284 */  addiu     $a0, $zero, 0x284
.L802BEA9C:
/* 31CABC 802BEA9C 8E420000 */  lw        $v0, ($s2)
/* 31CAC0 802BEAA0 2403FFFD */  addiu     $v1, $zero, -3
/* 31CAC4 802BEAA4 3C01802C */  lui       $at, %hi(D_802BEB40_31CB60)
/* 31CAC8 802BEAA8 AC20EB40 */  sw        $zero, %lo(D_802BEB40_31CB60)($at)
/* 31CACC 802BEAAC 00431024 */  and       $v0, $v0, $v1
/* 31CAD0 802BEAB0 AE420000 */  sw        $v0, ($s2)
/* 31CAD4 802BEAB4 8E220000 */  lw        $v0, ($s1)
/* 31CAD8 802BEAB8 2403F7FF */  addiu     $v1, $zero, -0x801
/* 31CADC 802BEABC AE20001C */  sw        $zero, 0x1c($s1)
/* 31CAE0 802BEAC0 00431024 */  and       $v0, $v0, $v1
/* 31CAE4 802BEAC4 2403FFBF */  addiu     $v1, $zero, -0x41
/* 31CAE8 802BEAC8 00431024 */  and       $v0, $v0, $v1
/* 31CAEC 802BEACC 0C05271B */  jal       sfx_stop_sound
/* 31CAF0 802BEAD0 AE220000 */   sw       $v0, ($s1)
/* 31CAF4 802BEAD4 0C039769 */  jal       set_action_state
/* 31CAF8 802BEAD8 0000202D */   daddu    $a0, $zero, $zero
/* 31CAFC 802BEADC 0C03BD17 */  jal       partner_clear_player_tracking
/* 31CB00 802BEAE0 0220202D */   daddu    $a0, $s1, $zero
/* 31CB04 802BEAE4 0C00EB6B */  jal       disable_npc_blur
/* 31CB08 802BEAE8 0220202D */   daddu    $a0, $s1, $zero
/* 31CB0C 802BEAEC A2600003 */  sb        $zero, 3($s3)
/* 31CB10 802BEAF0 A2600000 */  sb        $zero, ($s3)
.L802BEAF4:
/* 31CB14 802BEAF4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 31CB18 802BEAF8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 31CB1C 802BEAFC 8FB20018 */  lw        $s2, 0x18($sp)
/* 31CB20 802BEB00 8FB10014 */  lw        $s1, 0x14($sp)
/* 31CB24 802BEB04 8FB00010 */  lw        $s0, 0x10($sp)
/* 31CB28 802BEB08 03E00008 */  jr        $ra
/* 31CB2C 802BEB0C 27BD0028 */   addiu    $sp, $sp, 0x28
