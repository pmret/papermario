.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00242E0
/* 339530 E00242E0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 339534 E00242E4 3C02E002 */  lui       $v0, %hi(func_E0024454)
/* 339538 E00242E8 24424454 */  addiu     $v0, $v0, %lo(func_E0024454)
/* 33953C E00242EC AFA2001C */  sw        $v0, 0x1c($sp)
/* 339540 E00242F0 2402002D */  addiu     $v0, $zero, 0x2d
/* 339544 E00242F4 AFA40018 */  sw        $a0, 0x18($sp)
/* 339548 E00242F8 27A40010 */  addiu     $a0, $sp, 0x10
/* 33954C E00242FC AFBF0020 */  sw        $ra, 0x20($sp)
/* 339550 E0024300 AFA00014 */  sw        $zero, 0x14($sp)
/* 339554 E0024304 0C080120 */  jal       func_E0200480
/* 339558 E0024308 AFA20010 */   sw       $v0, 0x10($sp)
/* 33955C E002430C 8C430000 */  lw        $v1, ($v0)
/* 339560 E0024310 34630002 */  ori       $v1, $v1, 2
/* 339564 E0024314 AC430000 */  sw        $v1, ($v0)
/* 339568 E0024318 8FBF0020 */  lw        $ra, 0x20($sp)
/* 33956C E002431C 03E00008 */  jr        $ra
/* 339570 E0024320 27BD0028 */   addiu    $sp, $sp, 0x28
