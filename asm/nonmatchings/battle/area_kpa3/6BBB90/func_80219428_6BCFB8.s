.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219428_6BCFB8
/* 6BCFB8 80219428 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6BCFBC 8021942C AFB00010 */  sw        $s0, 0x10($sp)
/* 6BCFC0 80219430 0080802D */  daddu     $s0, $a0, $zero
/* 6BCFC4 80219434 AFBF0018 */  sw        $ra, 0x18($sp)
/* 6BCFC8 80219438 AFB10014 */  sw        $s1, 0x14($sp)
/* 6BCFCC 8021943C 8E040148 */  lw        $a0, 0x148($s0)
/* 6BCFD0 80219440 0C09A75B */  jal       get_actor
/* 6BCFD4 80219444 8E11000C */   lw       $s1, 0xc($s0)
/* 6BCFD8 80219448 0200202D */  daddu     $a0, $s0, $zero
/* 6BCFDC 8021944C 8E250000 */  lw        $a1, ($s1)
/* 6BCFE0 80219450 0C0B1EAF */  jal       get_variable
/* 6BCFE4 80219454 8C500090 */   lw       $s0, 0x90($v0)
/* 6BCFE8 80219458 AE020004 */  sw        $v0, 4($s0)
/* 6BCFEC 8021945C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 6BCFF0 80219460 8FB10014 */  lw        $s1, 0x14($sp)
/* 6BCFF4 80219464 8FB00010 */  lw        $s0, 0x10($sp)
/* 6BCFF8 80219468 24020002 */  addiu     $v0, $zero, 2
/* 6BCFFC 8021946C 03E00008 */  jr        $ra
/* 6BD000 80219470 27BD0020 */   addiu    $sp, $sp, 0x20
