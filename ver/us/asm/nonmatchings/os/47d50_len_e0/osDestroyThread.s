.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osDestroyThread
/* 47D50 8006C950 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 47D54 8006C954 AFB00010 */  sw        $s0, 0x10($sp)
/* 47D58 8006C958 00808021 */  addu      $s0, $a0, $zero
/* 47D5C 8006C95C AFBF0018 */  sw        $ra, 0x18($sp)
/* 47D60 8006C960 0C01ACD8 */  jal       __osDisableInt
/* 47D64 8006C964 AFB10014 */   sw       $s1, 0x14($sp)
/* 47D68 8006C968 16000004 */  bnez      $s0, .L8006C97C
/* 47D6C 8006C96C 00408821 */   addu     $s1, $v0, $zero
/* 47D70 8006C970 3C108009 */  lui       $s0, %hi(__osRunningThread)
/* 47D74 8006C974 0801B266 */  j         .L8006C998
/* 47D78 8006C978 8E104660 */   lw       $s0, %lo(__osRunningThread)($s0)
.L8006C97C:
/* 47D7C 8006C97C 96030010 */  lhu       $v1, 0x10($s0)
/* 47D80 8006C980 24020001 */  addiu     $v0, $zero, 1
/* 47D84 8006C984 10620004 */  beq       $v1, $v0, .L8006C998
/* 47D88 8006C988 00000000 */   nop
/* 47D8C 8006C98C 8E040008 */  lw        $a0, 8($s0)
/* 47D90 8006C990 0C019880 */  jal       osDequeueThread
/* 47D94 8006C994 02002821 */   addu     $a1, $s0, $zero
.L8006C998:
/* 47D98 8006C998 3C028009 */  lui       $v0, %hi(__osActiveQueue)
/* 47D9C 8006C99C 8C42465C */  lw        $v0, %lo(__osActiveQueue)($v0)
/* 47DA0 8006C9A0 14500008 */  bne       $v0, $s0, .L8006C9C4
/* 47DA4 8006C9A4 00402021 */   addu     $a0, $v0, $zero
/* 47DA8 8006C9A8 8E02000C */  lw        $v0, 0xc($s0)
/* 47DAC 8006C9AC 3C018009 */  lui       $at, %hi(__osActiveQueue)
/* 47DB0 8006C9B0 0801B27D */  j         .L8006C9F4
/* 47DB4 8006C9B4 AC22465C */   sw       $v0, %lo(__osActiveQueue)($at)
.L8006C9B8:
/* 47DB8 8006C9B8 8E02000C */  lw        $v0, 0xc($s0)
/* 47DBC 8006C9BC 0801B27D */  j         .L8006C9F4
/* 47DC0 8006C9C0 AC82000C */   sw       $v0, 0xc($a0)
.L8006C9C4:
/* 47DC4 8006C9C4 8C830004 */  lw        $v1, 4($a0)
/* 47DC8 8006C9C8 2402FFFF */  addiu     $v0, $zero, -1
/* 47DCC 8006C9CC 10620009 */  beq       $v1, $v0, .L8006C9F4
/* 47DD0 8006C9D0 00000000 */   nop
/* 47DD4 8006C9D4 2403FFFF */  addiu     $v1, $zero, -1
.L8006C9D8:
/* 47DD8 8006C9D8 8C82000C */  lw        $v0, 0xc($a0)
/* 47DDC 8006C9DC 1050FFF6 */  beq       $v0, $s0, .L8006C9B8
/* 47DE0 8006C9E0 00000000 */   nop
/* 47DE4 8006C9E4 00402021 */  addu      $a0, $v0, $zero
/* 47DE8 8006C9E8 8C820004 */  lw        $v0, 4($a0)
/* 47DEC 8006C9EC 1443FFFA */  bne       $v0, $v1, .L8006C9D8
/* 47DF0 8006C9F0 00000000 */   nop
.L8006C9F4:
/* 47DF4 8006C9F4 3C028009 */  lui       $v0, %hi(__osRunningThread)
/* 47DF8 8006C9F8 8C424660 */  lw        $v0, %lo(__osRunningThread)($v0)
/* 47DFC 8006C9FC 16020003 */  bne       $s0, $v0, .L8006CA0C
/* 47E00 8006CA00 00000000 */   nop
/* 47E04 8006CA04 0C01AC75 */  jal       osDispatchThread
/* 47E08 8006CA08 00000000 */   nop
.L8006CA0C:
/* 47E0C 8006CA0C 0C01ACF4 */  jal       __osRestoreInt
/* 47E10 8006CA10 02202021 */   addu     $a0, $s1, $zero
/* 47E14 8006CA14 8FBF0018 */  lw        $ra, 0x18($sp)
/* 47E18 8006CA18 8FB10014 */  lw        $s1, 0x14($sp)
/* 47E1C 8006CA1C 8FB00010 */  lw        $s0, 0x10($sp)
/* 47E20 8006CA20 03E00008 */  jr        $ra
/* 47E24 8006CA24 27BD0020 */   addiu    $sp, $sp, 0x20
/* 47E28 8006CA28 00000000 */  nop
/* 47E2C 8006CA2C 00000000 */  nop
