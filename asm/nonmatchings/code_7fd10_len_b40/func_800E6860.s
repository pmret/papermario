.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800E6860
/* 07FD10 800E6860 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 07FD14 800E6864 3C038011 */  lui   $v1, 0x8011
/* 07FD18 800E6868 2463EBB0 */  addiu $v1, $v1, -0x1450
/* 07FD1C 800E686C AFBF0028 */  sw    $ra, 0x28($sp)
/* 07FD20 800E6870 AFB10024 */  sw    $s1, 0x24($sp)
/* 07FD24 800E6874 AFB00020 */  sw    $s0, 0x20($sp)
/* 07FD28 800E6878 80620000 */  lb    $v0, ($v1)
/* 07FD2C 800E687C 3C118011 */  lui   $s1, 0x8011
/* 07FD30 800E6880 2631EFC8 */  addiu $s1, $s1, -0x1038
/* 07FD34 800E6884 1040001A */  beqz  $v0, .L800E68F0
/* 07FD38 800E6888 24020009 */   addiu $v0, $zero, 9
/* 07FD3C 800E688C 80630003 */  lb    $v1, 3($v1)
/* 07FD40 800E6890 14620017 */  bne   $v1, $v0, .L800E68F0
/* 07FD44 800E6894 00000000 */   nop   
/* 07FD48 800E6898 0C00EABB */  jal   get_npc_unsafe
/* 07FD4C 800E689C 2404FFFC */   addiu $a0, $zero, -4
/* 07FD50 800E68A0 0000202D */  daddu $a0, $zero, $zero
/* 07FD54 800E68A4 2405FFFF */  addiu $a1, $zero, -1
/* 07FD58 800E68A8 24060007 */  addiu $a2, $zero, 7
/* 07FD5C 800E68AC 0080382D */  daddu $a3, $a0, $zero
/* 07FD60 800E68B0 9223000E */  lbu   $v1, 0xe($s1)
/* 07FD64 800E68B4 0040802D */  daddu $s0, $v0, $zero
/* 07FD68 800E68B8 AFA00010 */  sw    $zero, 0x10($sp)
/* 07FD6C 800E68BC AFA00014 */  sw    $zero, 0x14($sp)
/* 07FD70 800E68C0 AFA0001C */  sw    $zero, 0x1c($sp)
/* 07FD74 800E68C4 0C0B77B9 */  jal   func_802DDEE4
/* 07FD78 800E68C8 AFA30018 */   sw    $v1, 0x18($sp)
/* 07FD7C 800E68CC 0200202D */  daddu $a0, $s0, $zero
/* 07FD80 800E68D0 24050007 */  addiu $a1, $zero, 7
/* 07FD84 800E68D4 9226000E */  lbu   $a2, 0xe($s1)
/* 07FD88 800E68D8 0000382D */  daddu $a3, $zero, $zero
/* 07FD8C 800E68DC AFA00010 */  sw    $zero, 0x10($sp)
/* 07FD90 800E68E0 AFA00014 */  sw    $zero, 0x14($sp)
/* 07FD94 800E68E4 0C00F589 */  jal   func_8003D624
/* 07FD98 800E68E8 AFA00018 */   sw    $zero, 0x18($sp)
/* 07FD9C 800E68EC A220000F */  sb    $zero, 0xf($s1)
.L800E68F0:
/* 07FDA0 800E68F0 8FBF0028 */  lw    $ra, 0x28($sp)
/* 07FDA4 800E68F4 8FB10024 */  lw    $s1, 0x24($sp)
/* 07FDA8 800E68F8 8FB00020 */  lw    $s0, 0x20($sp)
/* 07FDAC 800E68FC 03E00008 */  jr    $ra
/* 07FDB0 800E6900 27BD0030 */   addiu $sp, $sp, 0x30

