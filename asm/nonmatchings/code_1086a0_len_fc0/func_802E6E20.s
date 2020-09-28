.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E6E20
/* 1086A0 802E6E20 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1086A4 802E6E24 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 1086A8 802E6E28 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 1086AC 802E6E2C AFBF0010 */  sw        $ra, 0x10($sp)
/* 1086B0 802E6E30 84430086 */  lh        $v1, 0x86($v0)
/* 1086B4 802E6E34 2402000B */  addiu     $v0, $zero, 0xb
/* 1086B8 802E6E38 14620004 */  bne       $v1, $v0, .L802E6E4C
/* 1086BC 802E6E3C 0000202D */   daddu    $a0, $zero, $zero
/* 1086C0 802E6E40 3C04802F */  lui       $a0, 0x802f
/* 1086C4 802E6E44 080B9B9D */  j         .L802E6E74
/* 1086C8 802E6E48 2484AB30 */   addiu    $a0, $a0, -0x54d0
.L802E6E4C:
/* 1086CC 802E6E4C 24020002 */  addiu     $v0, $zero, 2
/* 1086D0 802E6E50 14620004 */  bne       $v1, $v0, .L802E6E64
/* 1086D4 802E6E54 24020012 */   addiu    $v0, $zero, 0x12
/* 1086D8 802E6E58 3C04802F */  lui       $a0, 0x802f
/* 1086DC 802E6E5C 080B9B9D */  j         .L802E6E74
/* 1086E0 802E6E60 2484AC40 */   addiu    $a0, $a0, -0x53c0
.L802E6E64:
/* 1086E4 802E6E64 14620003 */  bne       $v1, $v0, .L802E6E74
/* 1086E8 802E6E68 00000000 */   nop      
/* 1086EC 802E6E6C 3C04802F */  lui       $a0, 0x802f
/* 1086F0 802E6E70 2484AC84 */  addiu     $a0, $a0, -0x537c
.L802E6E74:
/* 1086F4 802E6E74 10800003 */  beqz      $a0, .L802E6E84
/* 1086F8 802E6E78 2405000A */   addiu    $a1, $zero, 0xa
/* 1086FC 802E6E7C 0C0B0CF8 */  jal       start_script
/* 108700 802E6E80 24060020 */   addiu    $a2, $zero, 0x20
.L802E6E84:
/* 108704 802E6E84 8FBF0010 */  lw        $ra, 0x10($sp)
/* 108708 802E6E88 03E00008 */  jr        $ra
/* 10870C 802E6E8C 27BD0018 */   addiu    $sp, $sp, 0x18
