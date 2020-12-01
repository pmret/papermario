.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241980_844550
/* 844550 80241980 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 844554 80241984 AFBF0010 */  sw        $ra, 0x10($sp)
/* 844558 80241988 8C82000C */  lw        $v0, 0xc($a0)
/* 84455C 8024198C 3C068016 */  lui       $a2, %hi(gCollisionStatus+0x2)
/* 844560 80241990 84C6A552 */  lh        $a2, %lo(gCollisionStatus+0x2)($a2)
/* 844564 80241994 0C0B2026 */  jal       set_variable
/* 844568 80241998 8C450000 */   lw       $a1, ($v0)
/* 84456C 8024199C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 844570 802419A0 24020002 */  addiu     $v0, $zero, 2
/* 844574 802419A4 03E00008 */  jr        $ra
/* 844578 802419A8 27BD0018 */   addiu    $sp, $sp, 0x18
