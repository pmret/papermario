.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E002A380
/* 33EC40 E002A380 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 33EC44 E002A384 3C02E003 */  lui       $v0, 0xe003
/* 33EC48 E002A388 2442A3C4 */  addiu     $v0, $v0, -0x5c3c
/* 33EC4C E002A38C AFA2001C */  sw        $v0, 0x1c($sp)
/* 33EC50 E002A390 24020011 */  addiu     $v0, $zero, 0x11
/* 33EC54 E002A394 AFA40018 */  sw        $a0, 0x18($sp)
/* 33EC58 E002A398 27A40010 */  addiu     $a0, $sp, 0x10
/* 33EC5C E002A39C AFBF0020 */  sw        $ra, 0x20($sp)
/* 33EC60 E002A3A0 AFA00014 */  sw        $zero, 0x14($sp)
/* 33EC64 E002A3A4 0C080120 */  jal       func_E0200480
/* 33EC68 E002A3A8 AFA20010 */   sw       $v0, 0x10($sp)
/* 33EC6C E002A3AC 8C430000 */  lw        $v1, ($v0)
/* 33EC70 E002A3B0 34630002 */  ori       $v1, $v1, 2
/* 33EC74 E002A3B4 AC430000 */  sw        $v1, ($v0)
/* 33EC78 E002A3B8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 33EC7C E002A3BC 03E00008 */  jr        $ra
/* 33EC80 E002A3C0 27BD0028 */   addiu    $sp, $sp, 0x28
