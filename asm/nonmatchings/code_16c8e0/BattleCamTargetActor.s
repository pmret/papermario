.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel BattleCamTargetActor
/* 17D404 8024EB24 3C028028 */  lui   $v0, 0x8028
/* 17D408 8024EB28 80420CE0 */  lb    $v0, 0xce0($v0)
/* 17D40C 8024EB2C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 17D410 8024EB30 AFB00010 */  sw    $s0, 0x10($sp)
/* 17D414 8024EB34 0080802D */  daddu $s0, $a0, $zero
/* 17D418 8024EB38 AFBF0014 */  sw    $ra, 0x14($sp)
/* 17D41C 8024EB3C 8E05000C */  lw    $a1, 0xc($s0)
/* 17D420 8024EB40 1440000C */  bnez  $v0, .L8024EB74
/* 17D424 8024EB44 24020002 */   addiu $v0, $zero, 2
/* 17D428 8024EB48 8CA50000 */  lw    $a1, ($a1)
/* 17D42C 8024EB4C 0C0B1EAF */  jal   get_variable
/* 17D430 8024EB50 0200202D */   daddu $a0, $s0, $zero
/* 17D434 8024EB54 0040202D */  daddu $a0, $v0, $zero
/* 17D438 8024EB58 2402FF81 */  addiu $v0, $zero, -0x7f
/* 17D43C 8024EB5C 14820002 */  bne   $a0, $v0, .L8024EB68
/* 17D440 8024EB60 00000000 */   nop   
/* 17D444 8024EB64 8E040148 */  lw    $a0, 0x148($s0)
.L8024EB68:
/* 17D448 8024EB68 0C09390F */  jal   cam_target_actor
/* 17D44C 8024EB6C 00000000 */   nop   
/* 17D450 8024EB70 24020002 */  addiu $v0, $zero, 2
.L8024EB74:
/* 17D454 8024EB74 8FBF0014 */  lw    $ra, 0x14($sp)
/* 17D458 8024EB78 8FB00010 */  lw    $s0, 0x10($sp)
/* 17D45C 8024EB7C 03E00008 */  jr    $ra
/* 17D460 8024EB80 27BD0018 */   addiu $sp, $sp, 0x18

/* 17D464 8024EB84 3C028028 */  lui   $v0, 0x8028
/* 17D468 8024EB88 80420CE0 */  lb    $v0, 0xce0($v0)
/* 17D46C 8024EB8C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 17D470 8024EB90 AFB20018 */  sw    $s2, 0x18($sp)
/* 17D474 8024EB94 0080902D */  daddu $s2, $a0, $zero
/* 17D478 8024EB98 AFBF001C */  sw    $ra, 0x1c($sp)
/* 17D47C 8024EB9C AFB10014 */  sw    $s1, 0x14($sp)
/* 17D480 8024EBA0 AFB00010 */  sw    $s0, 0x10($sp)
/* 17D484 8024EBA4 8E51000C */  lw    $s1, 0xc($s2)
/* 17D488 8024EBA8 14400011 */  bnez  $v0, .L8024EBF0
/* 17D48C 8024EBAC 24020002 */   addiu $v0, $zero, 2
/* 17D490 8024EBB0 8E250000 */  lw    $a1, ($s1)
/* 17D494 8024EBB4 26310004 */  addiu $s1, $s1, 4
/* 17D498 8024EBB8 0C0B1EAF */  jal   get_variable
/* 17D49C 8024EBBC 0240202D */   daddu $a0, $s2, $zero
/* 17D4A0 8024EBC0 0040802D */  daddu $s0, $v0, $zero
/* 17D4A4 8024EBC4 2402FF81 */  addiu $v0, $zero, -0x7f
/* 17D4A8 8024EBC8 16020002 */  bne   $s0, $v0, .L8024EBD4
/* 17D4AC 8024EBCC 00000000 */   nop   
/* 17D4B0 8024EBD0 8E500148 */  lw    $s0, 0x148($s2)
.L8024EBD4:
/* 17D4B4 8024EBD4 8E250000 */  lw    $a1, ($s1)
/* 17D4B8 8024EBD8 0C0B1EAF */  jal   get_variable
/* 17D4BC 8024EBDC 0240202D */   daddu $a0, $s2, $zero
/* 17D4C0 8024EBE0 0200202D */  daddu $a0, $s0, $zero
/* 17D4C4 8024EBE4 0C093917 */  jal   func_8024E45C
/* 17D4C8 8024EBE8 0040282D */   daddu $a1, $v0, $zero
/* 17D4CC 8024EBEC 24020002 */  addiu $v0, $zero, 2
.L8024EBF0:
/* 17D4D0 8024EBF0 8FBF001C */  lw    $ra, 0x1c($sp)
/* 17D4D4 8024EBF4 8FB20018 */  lw    $s2, 0x18($sp)
/* 17D4D8 8024EBF8 8FB10014 */  lw    $s1, 0x14($sp)
/* 17D4DC 8024EBFC 8FB00010 */  lw    $s0, 0x10($sp)
/* 17D4E0 8024EC00 03E00008 */  jr    $ra
/* 17D4E4 8024EC04 27BD0020 */   addiu $sp, $sp, 0x20

