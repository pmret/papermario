.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00022BC
/* 327BAC E00022BC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 327BB0 E00022C0 3C02E000 */  lui       $v0, %hi(func_E0002300)
/* 327BB4 E00022C4 24422300 */  addiu     $v0, $v0, %lo(func_E0002300)
/* 327BB8 E00022C8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 327BBC E00022CC 2402002D */  addiu     $v0, $zero, 0x2d
/* 327BC0 E00022D0 AFA40018 */  sw        $a0, 0x18($sp)
/* 327BC4 E00022D4 27A40010 */  addiu     $a0, $sp, 0x10
/* 327BC8 E00022D8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 327BCC E00022DC AFA00014 */  sw        $zero, 0x14($sp)
/* 327BD0 E00022E0 0C080120 */  jal       func_E0200480
/* 327BD4 E00022E4 AFA20010 */   sw       $v0, 0x10($sp)
/* 327BD8 E00022E8 8C430000 */  lw        $v1, ($v0)
/* 327BDC E00022EC 34630002 */  ori       $v1, $v1, 2
/* 327BE0 E00022F0 AC430000 */  sw        $v1, ($v0)
/* 327BE4 E00022F4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 327BE8 E00022F8 03E00008 */  jr        $ra
/* 327BEC E00022FC 27BD0028 */   addiu    $sp, $sp, 0x28
