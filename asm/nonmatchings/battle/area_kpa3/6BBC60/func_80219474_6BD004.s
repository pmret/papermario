.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219474_6BD004
/* 6BD004 80219474 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6BD008 80219478 AFB00010 */  sw        $s0, 0x10($sp)
/* 6BD00C 8021947C 0080802D */  daddu     $s0, $a0, $zero
/* 6BD010 80219480 AFBF0018 */  sw        $ra, 0x18($sp)
/* 6BD014 80219484 AFB10014 */  sw        $s1, 0x14($sp)
/* 6BD018 80219488 8E040148 */  lw        $a0, 0x148($s0)
/* 6BD01C 8021948C 0C09A75B */  jal       get_actor
/* 6BD020 80219490 8E11000C */   lw       $s1, 0xc($s0)
/* 6BD024 80219494 0200202D */  daddu     $a0, $s0, $zero
/* 6BD028 80219498 8E250000 */  lw        $a1, ($s1)
/* 6BD02C 8021949C 0C0B1EAF */  jal       get_variable
/* 6BD030 802194A0 8C500090 */   lw       $s0, 0x90($v0)
/* 6BD034 802194A4 AE02000C */  sw        $v0, 0xc($s0)
/* 6BD038 802194A8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 6BD03C 802194AC 8FB10014 */  lw        $s1, 0x14($sp)
/* 6BD040 802194B0 8FB00010 */  lw        $s0, 0x10($sp)
/* 6BD044 802194B4 24020002 */  addiu     $v0, $zero, 2
/* 6BD048 802194B8 03E00008 */  jr        $ra
/* 6BD04C 802194BC 27BD0020 */   addiu    $sp, $sp, 0x20
