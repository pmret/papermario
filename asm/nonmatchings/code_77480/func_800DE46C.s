.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800DE46C
/* 7791C 800DE46C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 77920 800DE470 AFBF0028 */  sw        $ra, 0x28($sp)
/* 77924 800DE474 C48200A8 */  lwc1      $f2, 0xa8($a0)
/* 77928 800DE478 3C0142B4 */  lui       $at, 0x42b4
/* 7792C 800DE47C 44810000 */  mtc1      $at, $f0
/* 77930 800DE480 44802000 */  mtc1      $zero, $f4
/* 77934 800DE484 4602003E */  c.le.s    $f0, $f2
/* 77938 800DE488 00000000 */  nop
/* 7793C 800DE48C 4500000A */  bc1f      .L800DE4B8
/* 77940 800DE490 00C0402D */   daddu    $t0, $a2, $zero
/* 77944 800DE494 3C014387 */  lui       $at, 0x4387
/* 77948 800DE498 44810000 */  mtc1      $at, $f0
/* 7794C 800DE49C 00000000 */  nop
/* 77950 800DE4A0 4600103C */  c.lt.s    $f2, $f0
/* 77954 800DE4A4 00000000 */  nop
/* 77958 800DE4A8 45000003 */  bc1f      .L800DE4B8
/* 7795C 800DE4AC 00000000 */   nop
/* 77960 800DE4B0 3C014334 */  lui       $at, 0x4334
/* 77964 800DE4B4 44812000 */  mtc1      $at, $f4
.L800DE4B8:
/* 77968 800DE4B8 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 7796C 800DE4BC 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 77970 800DE4C0 3C0142B4 */  lui       $at, 0x42b4
/* 77974 800DE4C4 44816000 */  mtc1      $at, $f12
/* 77978 800DE4C8 00031080 */  sll       $v0, $v1, 2
/* 7797C 800DE4CC 00431021 */  addu      $v0, $v0, $v1
/* 77980 800DE4D0 00021080 */  sll       $v0, $v0, 2
/* 77984 800DE4D4 00431023 */  subu      $v0, $v0, $v1
/* 77988 800DE4D8 000218C0 */  sll       $v1, $v0, 3
/* 7798C 800DE4DC 00431021 */  addu      $v0, $v0, $v1
/* 77990 800DE4E0 000210C0 */  sll       $v0, $v0, 3
/* 77994 800DE4E4 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 77998 800DE4E8 00220821 */  addu      $at, $at, $v0
/* 7799C 800DE4EC C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* 779A0 800DE4F0 848300B2 */  lh        $v1, 0xb2($a0)
/* 779A4 800DE4F4 8FA20040 */  lw        $v0, 0x40($sp)
/* 779A8 800DE4F8 00A0302D */  daddu     $a2, $a1, $zero
/* 779AC 800DE4FC AFA70010 */  sw        $a3, 0x10($sp)
/* 779B0 800DE500 AFA20014 */  sw        $v0, 0x14($sp)
/* 779B4 800DE504 8FA20044 */  lw        $v0, 0x44($sp)
/* 779B8 800DE508 0100382D */  daddu     $a3, $t0, $zero
/* 779BC 800DE50C AFA20018 */  sw        $v0, 0x18($sp)
/* 779C0 800DE510 8FA20048 */  lw        $v0, 0x48($sp)
/* 779C4 800DE514 460C2301 */  sub.s     $f12, $f4, $f12
/* 779C8 800DE518 AFA2001C */  sw        $v0, 0x1c($sp)
/* 779CC 800DE51C 8FA2004C */  lw        $v0, 0x4c($sp)
/* 779D0 800DE520 46006300 */  add.s     $f12, $f12, $f0
/* 779D4 800DE524 AFA20020 */  sw        $v0, 0x20($sp)
/* 779D8 800DE528 8FA20050 */  lw        $v0, 0x50($sp)
/* 779DC 800DE52C 44837000 */  mtc1      $v1, $f14
/* 779E0 800DE530 00000000 */  nop
/* 779E4 800DE534 468073A0 */  cvt.s.w   $f14, $f14
/* 779E8 800DE538 0C0377F4 */  jal       test_below_player
/* 779EC 800DE53C AFA20024 */   sw       $v0, 0x24($sp)
/* 779F0 800DE540 8FBF0028 */  lw        $ra, 0x28($sp)
/* 779F4 800DE544 03E00008 */  jr        $ra
/* 779F8 800DE548 27BD0030 */   addiu    $sp, $sp, 0x30
