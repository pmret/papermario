.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802ACBE0
.word 0x802AA090, 0x802AA090, 0x802AA090, 0x802AA090, 0x802AA090, 0x802AA098, 0x802AA098, 0x802AA098, 0x802AA098, 0x00000000

.section .text

glabel btl_state_draw_peach_menu
/* 41EDEC 802AA05C 3C02800E */  lui       $v0, %hi(gBattleState2)
/* 41EDF0 802AA060 8C42C4DC */  lw        $v0, %lo(gBattleState2)($v0)
/* 41EDF4 802AA064 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 41EDF8 802AA068 2443FFFF */  addiu     $v1, $v0, -1
/* 41EDFC 802AA06C 2C620009 */  sltiu     $v0, $v1, 9
/* 41EE00 802AA070 10400009 */  beqz      $v0, .L802AA098
/* 41EE04 802AA074 AFBF0010 */   sw       $ra, 0x10($sp)
/* 41EE08 802AA078 00031080 */  sll       $v0, $v1, 2
/* 41EE0C 802AA07C 3C01802B */  lui       $at, %hi(D_802ACBE0)
/* 41EE10 802AA080 00220821 */  addu      $at, $at, $v0
/* 41EE14 802AA084 8C22CBE0 */  lw        $v0, %lo(D_802ACBE0)($at)
/* 41EE18 802AA088 00400008 */  jr        $v0
/* 41EE1C 802AA08C 00000000 */   nop
/* 41EE20 802AA090 0C0A8715 */  jal       btl_draw_menu_wheel
/* 41EE24 802AA094 00000000 */   nop
.L802AA098:
/* 41EE28 802AA098 8FBF0010 */  lw        $ra, 0x10($sp)
/* 41EE2C 802AA09C 03E00008 */  jr        $ra
/* 41EE30 802AA0A0 27BD0018 */   addiu    $sp, $sp, 0x18
