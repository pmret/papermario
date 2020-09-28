.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuScResetClientMesgType
/* 3A338 8005EF38 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3A33C 8005EF3C AFB10014 */  sw        $s1, 0x14($sp)
/* 3A340 8005EF40 0080882D */  daddu     $s1, $a0, $zero
/* 3A344 8005EF44 AFB00010 */  sw        $s0, 0x10($sp)
/* 3A348 8005EF48 00A0802D */  daddu     $s0, $a1, $zero
/* 3A34C 8005EF4C AFBF0018 */  sw        $ra, 0x18($sp)
/* 3A350 8005EF50 0C018250 */  jal       osSetIntMask
/* 3A354 8005EF54 24040001 */   addiu    $a0, $zero, 1
/* 3A358 8005EF58 0040202D */  daddu     $a0, $v0, $zero
/* 3A35C 8005EF5C 0C018250 */  jal       osSetIntMask
/* 3A360 8005EF60 A6300008 */   sh       $s0, 8($s1)
/* 3A364 8005EF64 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3A368 8005EF68 8FB10014 */  lw        $s1, 0x14($sp)
/* 3A36C 8005EF6C 8FB00010 */  lw        $s0, 0x10($sp)
/* 3A370 8005EF70 03E00008 */  jr        $ra
/* 3A374 8005EF74 27BD0020 */   addiu    $sp, $sp, 0x20
