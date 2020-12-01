.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E004A748
/* 358C08 E004A748 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 358C0C E004A74C 3C02E005 */  lui       $v0, %hi(D_E004A78C)
/* 358C10 E004A750 2442A78C */  addiu     $v0, $v0, %lo(D_E004A78C)
/* 358C14 E004A754 AFA2001C */  sw        $v0, 0x1c($sp)
/* 358C18 E004A758 24020028 */  addiu     $v0, $zero, 0x28
/* 358C1C E004A75C AFA40018 */  sw        $a0, 0x18($sp)
/* 358C20 E004A760 27A40010 */  addiu     $a0, $sp, 0x10
/* 358C24 E004A764 AFBF0020 */  sw        $ra, 0x20($sp)
/* 358C28 E004A768 AFA00014 */  sw        $zero, 0x14($sp)
/* 358C2C E004A76C 0C080120 */  jal       func_E0200480
/* 358C30 E004A770 AFA20010 */   sw       $v0, 0x10($sp)
/* 358C34 E004A774 8C430000 */  lw        $v1, ($v0)
/* 358C38 E004A778 34630002 */  ori       $v1, $v1, 2
/* 358C3C E004A77C AC430000 */  sw        $v1, ($v0)
/* 358C40 E004A780 8FBF0020 */  lw        $ra, 0x20($sp)
/* 358C44 E004A784 03E00008 */  jr        $ra
/* 358C48 E004A788 27BD0028 */   addiu    $sp, $sp, 0x28
