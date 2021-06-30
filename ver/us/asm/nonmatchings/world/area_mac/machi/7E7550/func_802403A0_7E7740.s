.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403A0_7E7740
/* 7E7740 802403A0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7E7744 802403A4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 7E7748 802403A8 AFB00018 */  sw        $s0, 0x18($sp)
/* 7E774C 802403AC 8C820148 */  lw        $v0, 0x148($a0)
/* 7E7750 802403B0 0C00EABB */  jal       get_npc_unsafe
/* 7E7754 802403B4 84440008 */   lh       $a0, 8($v0)
/* 7E7758 802403B8 0040802D */  daddu     $s0, $v0, $zero
/* 7E775C 802403BC 0200202D */  daddu     $a0, $s0, $zero
/* 7E7760 802403C0 0C00ECF4 */  jal       npc_set_palswap_mode_A
/* 7E7764 802403C4 24050003 */   addiu    $a1, $zero, 3
/* 7E7768 802403C8 0200202D */  daddu     $a0, $s0, $zero
/* 7E776C 802403CC 0000282D */  daddu     $a1, $zero, $zero
/* 7E7770 802403D0 24060001 */  addiu     $a2, $zero, 1
/* 7E7774 802403D4 2407001E */  addiu     $a3, $zero, 0x1e
/* 7E7778 802403D8 2402000A */  addiu     $v0, $zero, 0xa
/* 7E777C 802403DC 0C00ED13 */  jal       npc_set_palswap_1
/* 7E7780 802403E0 AFA20010 */   sw       $v0, 0x10($sp)
/* 7E7784 802403E4 0200202D */  daddu     $a0, $s0, $zero
/* 7E7788 802403E8 2405003C */  addiu     $a1, $zero, 0x3c
/* 7E778C 802403EC 24060014 */  addiu     $a2, $zero, 0x14
/* 7E7790 802403F0 0000382D */  daddu     $a3, $zero, $zero
/* 7E7794 802403F4 0C00ED19 */  jal       npc_set_palswap_2
/* 7E7798 802403F8 AFA00010 */   sw       $zero, 0x10($sp)
/* 7E779C 802403FC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 7E77A0 80240400 8FB00018 */  lw        $s0, 0x18($sp)
/* 7E77A4 80240404 24020002 */  addiu     $v0, $zero, 2
/* 7E77A8 80240408 03E00008 */  jr        $ra
/* 7E77AC 8024040C 27BD0020 */   addiu    $sp, $sp, 0x20
