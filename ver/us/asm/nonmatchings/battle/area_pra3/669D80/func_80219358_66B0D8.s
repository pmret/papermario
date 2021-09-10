.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219358_66B0D8
/* 66B0D8 80219358 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 66B0DC 8021935C AFB00010 */  sw        $s0, 0x10($sp)
/* 66B0E0 80219360 0080802D */  daddu     $s0, $a0, $zero
/* 66B0E4 80219364 AFBF0018 */  sw        $ra, 0x18($sp)
/* 66B0E8 80219368 AFB10014 */  sw        $s1, 0x14($sp)
/* 66B0EC 8021936C 8E040148 */  lw        $a0, 0x148($s0)
/* 66B0F0 80219370 0C09A75B */  jal       get_actor
/* 66B0F4 80219374 8E11000C */   lw       $s1, 0xc($s0)
/* 66B0F8 80219378 0200202D */  daddu     $a0, $s0, $zero
/* 66B0FC 8021937C 8E250000 */  lw        $a1, ($s1)
/* 66B100 80219380 0C0B1EAF */  jal       evt_get_variable
/* 66B104 80219384 8C500090 */   lw       $s0, 0x90($v0)
/* 66B108 80219388 AE020004 */  sw        $v0, 4($s0)
/* 66B10C 8021938C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 66B110 80219390 8FB10014 */  lw        $s1, 0x14($sp)
/* 66B114 80219394 8FB00010 */  lw        $s0, 0x10($sp)
/* 66B118 80219398 24020002 */  addiu     $v0, $zero, 2
/* 66B11C 8021939C 03E00008 */  jr        $ra
/* 66B120 802193A0 27BD0020 */   addiu    $sp, $sp, 0x20
