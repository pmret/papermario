.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006C930
/* 47D30 8006C930 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 47D34 8006C934 AFB00010 */  sw        $s0, 0x10($sp)
/* 47D38 8006C938 00808021 */  addu      $s0, $a0, $zero
/* 47D3C 8006C93C AFBF0018 */  sw        $ra, 0x18($sp)
/* 47D40 8006C940 0C01ACD0 */  jal       func_8006B340
/* 47D44 8006C944 AFB10014 */   sw       $s1, 0x14($sp)
/* 47D48 8006C948 16000004 */  bnez      $s0, .L8006C95C
/* 47D4C 8006C94C 00408821 */   addu     $s1, $v0, $zero
/* 47D50 8006C950 3C108009 */  lui       $s0, %hi(D_80094640)
/* 47D54 8006C954 0801B25E */  j         .L8006C978
/* 47D58 8006C958 8E104640 */   lw       $s0, %lo(D_80094640)($s0)
.L8006C95C:
/* 47D5C 8006C95C 96030010 */  lhu       $v1, 0x10($s0)
/* 47D60 8006C960 24020001 */  addiu     $v0, $zero, 1
/* 47D64 8006C964 10620004 */  beq       $v1, $v0, .L8006C978
/* 47D68 8006C968 00000000 */   nop
/* 47D6C 8006C96C 8E040008 */  lw        $a0, 8($s0)
/* 47D70 8006C970 0C019874 */  jal       func_800661D0
/* 47D74 8006C974 02002821 */   addu     $a1, $s0, $zero
.L8006C978:
/* 47D78 8006C978 3C028009 */  lui       $v0, %hi(D_8009463C)
/* 47D7C 8006C97C 8C42463C */  lw        $v0, %lo(D_8009463C)($v0)
/* 47D80 8006C980 14500008 */  bne       $v0, $s0, .L8006C9A4
/* 47D84 8006C984 00402021 */   addu     $a0, $v0, $zero
/* 47D88 8006C988 8E02000C */  lw        $v0, 0xc($s0)
/* 47D8C 8006C98C 3C018009 */  lui       $at, %hi(D_8009463C)
/* 47D90 8006C990 0801B275 */  j         .L8006C9D4
/* 47D94 8006C994 AC22463C */   sw       $v0, %lo(D_8009463C)($at)
.L8006C998:
/* 47D98 8006C998 8E02000C */  lw        $v0, 0xc($s0)
/* 47D9C 8006C99C 0801B275 */  j         .L8006C9D4
/* 47DA0 8006C9A0 AC82000C */   sw       $v0, 0xc($a0)
.L8006C9A4:
/* 47DA4 8006C9A4 8C830004 */  lw        $v1, 4($a0)
/* 47DA8 8006C9A8 2402FFFF */  addiu     $v0, $zero, -1
/* 47DAC 8006C9AC 10620009 */  beq       $v1, $v0, .L8006C9D4
/* 47DB0 8006C9B0 00000000 */   nop
/* 47DB4 8006C9B4 2403FFFF */  addiu     $v1, $zero, -1
.L8006C9B8:
/* 47DB8 8006C9B8 8C82000C */  lw        $v0, 0xc($a0)
/* 47DBC 8006C9BC 1050FFF6 */  beq       $v0, $s0, .L8006C998
/* 47DC0 8006C9C0 00000000 */   nop
/* 47DC4 8006C9C4 00402021 */  addu      $a0, $v0, $zero
/* 47DC8 8006C9C8 8C820004 */  lw        $v0, 4($a0)
/* 47DCC 8006C9CC 1443FFFA */  bne       $v0, $v1, .L8006C9B8
/* 47DD0 8006C9D0 00000000 */   nop
.L8006C9D4:
/* 47DD4 8006C9D4 3C028009 */  lui       $v0, %hi(D_80094640)
/* 47DD8 8006C9D8 8C424640 */  lw        $v0, %lo(D_80094640)($v0)
/* 47DDC 8006C9DC 16020003 */  bne       $s0, $v0, .L8006C9EC
/* 47DE0 8006C9E0 00000000 */   nop
/* 47DE4 8006C9E4 0C01AC6D */  jal       func_8006B1B4
/* 47DE8 8006C9E8 00000000 */   nop
.L8006C9EC:
/* 47DEC 8006C9EC 0C01ACEC */  jal       func_8006B3B0
/* 47DF0 8006C9F0 02202021 */   addu     $a0, $s1, $zero
/* 47DF4 8006C9F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 47DF8 8006C9F8 8FB10014 */  lw        $s1, 0x14($sp)
/* 47DFC 8006C9FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 47E00 8006CA00 03E00008 */  jr        $ra
/* 47E04 8006CA04 27BD0020 */   addiu    $sp, $sp, 0x20
/* 47E08 8006CA08 00000000 */  nop
/* 47E0C 8006CA0C 00000000 */  nop
