.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005F93C
/* 3AD3C 8005F93C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3AD40 8005F940 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3AD44 8005F944 0000202D */  daddu     $a0, $zero, $zero
/* 3AD48 8005F948 24050002 */  addiu     $a1, $zero, 2
/* 3AD4C 8005F94C 0080182D */  daddu     $v1, $a0, $zero
.L8005F950:
/* 3AD50 8005F950 3C01800B */  lui       $at, %hi(D_800B1D26)
/* 3AD54 8005F954 00230821 */  addu      $at, $at, $v1
/* 3AD58 8005F958 A0251D26 */  sb        $a1, %lo(D_800B1D26)($at)
/* 3AD5C 8005F95C 3C01800B */  lui       $at, %hi(D_800B1D27)
/* 3AD60 8005F960 00230821 */  addu      $at, $at, $v1
/* 3AD64 8005F964 A0201D27 */  sb        $zero, %lo(D_800B1D27)($at)
/* 3AD68 8005F968 3C01800B */  lui       $at, %hi(D_800B1D24)
/* 3AD6C 8005F96C 00230821 */  addu      $at, $at, $v1
/* 3AD70 8005F970 A4241D24 */  sh        $a0, %lo(D_800B1D24)($at)
/* 3AD74 8005F974 24840001 */  addiu     $a0, $a0, 1
/* 3AD78 8005F978 2C820004 */  sltiu     $v0, $a0, 4
/* 3AD7C 8005F97C 1440FFF4 */  bnez      $v0, .L8005F950
/* 3AD80 8005F980 2463000A */   addiu    $v1, $v1, 0xa
/* 3AD84 8005F984 3C048009 */  lui       $a0, %hi(D_80093CD0)
/* 3AD88 8005F988 0C0180F0 */  jal       func_800603C0
/* 3AD8C 8005F98C 24843CD0 */   addiu    $a0, $a0, %lo(D_80093CD0)
/* 3AD90 8005F990 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3AD94 8005F994 03E00008 */  jr        $ra
/* 3AD98 8005F998 27BD0018 */   addiu    $sp, $sp, 0x18
