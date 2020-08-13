.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel nuScResetClientMesgType
/* 03A338 8005EF38 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 03A33C 8005EF3C AFB10014 */  sw    $s1, 0x14($sp)
/* 03A340 8005EF40 0080882D */  daddu $s1, $a0, $zero
/* 03A344 8005EF44 AFB00010 */  sw    $s0, 0x10($sp)
/* 03A348 8005EF48 00A0802D */  daddu $s0, $a1, $zero
/* 03A34C 8005EF4C AFBF0018 */  sw    $ra, 0x18($sp)
/* 03A350 8005EF50 0C018250 */  jal   osSetIntMask
/* 03A354 8005EF54 24040001 */   addiu $a0, $zero, 1
/* 03A358 8005EF58 0040202D */  daddu $a0, $v0, $zero
/* 03A35C 8005EF5C 0C018250 */  jal   osSetIntMask
/* 03A360 8005EF60 A6300008 */   sh    $s0, 8($s1)
/* 03A364 8005EF64 8FBF0018 */  lw    $ra, 0x18($sp)
/* 03A368 8005EF68 8FB10014 */  lw    $s1, 0x14($sp)
/* 03A36C 8005EF6C 8FB00010 */  lw    $s0, 0x10($sp)
/* 03A370 8005EF70 03E00008 */  jr    $ra
/* 03A374 8005EF74 27BD0020 */   addiu $sp, $sp, 0x20

