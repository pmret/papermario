.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00C6768
/* 3CD148 E00C6768 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3CD14C E00C676C 3C02E00C */  lui       $v0, %hi(D_E00C67B0)
/* 3CD150 E00C6770 244267B0 */  addiu     $v0, $v0, %lo(D_E00C67B0)
/* 3CD154 E00C6774 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3CD158 E00C6778 2402000A */  addiu     $v0, $zero, 0xa
/* 3CD15C E00C677C AFA20014 */  sw        $v0, 0x14($sp)
/* 3CD160 E00C6780 2402002D */  addiu     $v0, $zero, 0x2d
/* 3CD164 E00C6784 AFA40018 */  sw        $a0, 0x18($sp)
/* 3CD168 E00C6788 27A40010 */  addiu     $a0, $sp, 0x10
/* 3CD16C E00C678C AFBF0020 */  sw        $ra, 0x20($sp)
/* 3CD170 E00C6790 0C080120 */  jal       func_E0200480
/* 3CD174 E00C6794 AFA20010 */   sw       $v0, 0x10($sp)
/* 3CD178 E00C6798 8C430000 */  lw        $v1, ($v0)
/* 3CD17C E00C679C 34630002 */  ori       $v1, $v1, 2
/* 3CD180 E00C67A0 AC430000 */  sw        $v1, ($v0)
/* 3CD184 E00C67A4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3CD188 E00C67A8 03E00008 */  jr        $ra
/* 3CD18C E00C67AC 27BD0028 */   addiu    $sp, $sp, 0x28
