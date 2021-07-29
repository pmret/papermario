.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00A82D4
/* 3A73C4 E00A82D4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3A73C8 E00A82D8 3C02E00B */  lui       $v0, %hi(func_E00A8320)
/* 3A73CC E00A82DC 24428320 */  addiu     $v0, $v0, %lo(func_E00A8320)
/* 3A73D0 E00A82E0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3A73D4 E00A82E4 2402002D */  addiu     $v0, $zero, 0x2d
/* 3A73D8 E00A82E8 AFA40018 */  sw        $a0, 0x18($sp)
/* 3A73DC E00A82EC 27A40010 */  addiu     $a0, $sp, 0x10
/* 3A73E0 E00A82F0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3A73E4 E00A82F4 AFA00014 */  sw        $zero, 0x14($sp)
/* 3A73E8 E00A82F8 0C080120 */  jal       func_E0200480
/* 3A73EC E00A82FC AFA20010 */   sw       $v0, 0x10($sp)
/* 3A73F0 E00A8300 8C430000 */  lw        $v1, ($v0)
/* 3A73F4 E00A8304 34630002 */  ori       $v1, $v1, 2
/* 3A73F8 E00A8308 AC430000 */  sw        $v1, ($v0)
/* 3A73FC E00A830C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3A7400 E00A8310 03E00008 */  jr        $ra
/* 3A7404 E00A8314 27BD0028 */   addiu    $sp, $sp, 0x28
