.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005A370
/* 35770 8005A370 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 35774 8005A374 3C04007F */  lui       $a0, 0x7f
/* 35778 8005A378 24848810 */  addiu     $a0, $a0, -0x77f0
/* 3577C 8005A37C 3C05007F */  lui       $a1, 0x7f
/* 35780 8005A380 24A5ECD0 */  addiu     $a1, $a1, -0x1330
/* 35784 8005A384 3C068028 */  lui       $a2, %hi(D_80280000)
/* 35788 8005A388 24C60000 */  addiu     $a2, $a2, %lo(D_80280000)
/* 3578C 8005A38C AFBF0010 */  sw        $ra, 0x10($sp)
/* 35790 8005A390 0C00A5BF */  jal       func_800296FC
/* 35794 8005A394 00000000 */   nop
/* 35798 8005A398 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3579C 8005A39C 03E00008 */  jr        $ra
/* 357A0 8005A3A0 27BD0018 */   addiu    $sp, $sp, 0x18
