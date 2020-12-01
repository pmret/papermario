.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E002E330
/* 341D10 E002E330 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 341D14 E002E334 3C02E003 */  lui       $v0, %hi(D_E002E368)
/* 341D18 E002E338 2442E368 */  addiu     $v0, $v0, %lo(D_E002E368)
/* 341D1C E002E33C AFA2001C */  sw        $v0, 0x1c($sp)
/* 341D20 E002E340 24020028 */  addiu     $v0, $zero, 0x28
/* 341D24 E002E344 AFA40018 */  sw        $a0, 0x18($sp)
/* 341D28 E002E348 27A40010 */  addiu     $a0, $sp, 0x10
/* 341D2C E002E34C AFBF0020 */  sw        $ra, 0x20($sp)
/* 341D30 E002E350 AFA00014 */  sw        $zero, 0x14($sp)
/* 341D34 E002E354 0C080120 */  jal       func_E0200480
/* 341D38 E002E358 AFA20010 */   sw       $v0, 0x10($sp)
/* 341D3C E002E35C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 341D40 E002E360 03E00008 */  jr        $ra
/* 341D44 E002E364 27BD0028 */   addiu    $sp, $sp, 0x28
