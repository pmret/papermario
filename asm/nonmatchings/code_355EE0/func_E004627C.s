.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E004627C
/* 35615C E004627C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 356160 E0046280 3C02E004 */  lui       $v0, 0xe004
/* 356164 E0046284 244262C0 */  addiu     $v0, $v0, 0x62c0
/* 356168 E0046288 AFA2001C */  sw        $v0, 0x1c($sp)
/* 35616C E004628C 2402002D */  addiu     $v0, $zero, 0x2d
/* 356170 E0046290 AFA40018 */  sw        $a0, 0x18($sp)
/* 356174 E0046294 27A40010 */  addiu     $a0, $sp, 0x10
/* 356178 E0046298 AFBF0020 */  sw        $ra, 0x20($sp)
/* 35617C E004629C AFA00014 */  sw        $zero, 0x14($sp)
/* 356180 E00462A0 0C080120 */  jal       func_E0200480
/* 356184 E00462A4 AFA20010 */   sw       $v0, 0x10($sp)
/* 356188 E00462A8 8C430000 */  lw        $v1, ($v0)
/* 35618C E00462AC 34630002 */  ori       $v1, $v1, 2
/* 356190 E00462B0 AC430000 */  sw        $v1, ($v0)
/* 356194 E00462B4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 356198 E00462B8 03E00008 */  jr        $ra
/* 35619C E00462BC 27BD0028 */   addiu    $sp, $sp, 0x28
