.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024BD10
/* 13F050 8024BD10 0C0511F8 */  jal   func_801447E0
/* 13F054 8024BD14 00000000 */   nop   
.L8024BD18:
/* 13F058 8024BD18 8FBF002C */  lw    $ra, 0x2c($sp)
/* 13F05C 8024BD1C 8FB40028 */  lw    $s4, 0x28($sp)
/* 13F060 8024BD20 8FB30024 */  lw    $s3, 0x24($sp)
/* 13F064 8024BD24 8FB20020 */  lw    $s2, 0x20($sp)
/* 13F068 8024BD28 8FB1001C */  lw    $s1, 0x1c($sp)
/* 13F06C 8024BD2C 8FB00018 */  lw    $s0, 0x18($sp)
/* 13F070 8024BD30 03E00008 */  jr    $ra
/* 13F074 8024BD34 27BD0030 */   addiu $sp, $sp, 0x30

/* 13F078 8024BD38 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 13F07C 8024BD3C AFBE0048 */  sw    $fp, 0x48($sp)
/* 13F080 8024BD40 00C0F02D */  daddu $fp, $a2, $zero
/* 13F084 8024BD44 AFBF004C */  sw    $ra, 0x4c($sp)
/* 13F088 8024BD48 AFB70044 */  sw    $s7, 0x44($sp)
/* 13F08C 8024BD4C AFB60040 */  sw    $s6, 0x40($sp)
/* 13F090 8024BD50 AFB5003C */  sw    $s5, 0x3c($sp)
/* 13F094 8024BD54 AFB40038 */  sw    $s4, 0x38($sp)
/* 13F098 8024BD58 AFB30034 */  sw    $s3, 0x34($sp)
/* 13F09C 8024BD5C AFB20030 */  sw    $s2, 0x30($sp)
/* 13F0A0 8024BD60 AFB1002C */  sw    $s1, 0x2c($sp)
/* 13F0A4 8024BD64 AFB00028 */  sw    $s0, 0x28($sp)
/* 13F0A8 8024BD68 0C039D59 */  jal   get_player_data
/* 13F0AC 8024BD6C AFA50054 */   sw    $a1, 0x54($sp)
/* 13F0B0 8024BD70 3C038027 */  lui   $v1, 0x8027
/* 13F0B4 8024BD74 8C6306A0 */  lw    $v1, 0x6a0($v1)
