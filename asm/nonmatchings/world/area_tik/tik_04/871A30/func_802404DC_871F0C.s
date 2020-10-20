.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404DC_871F0C
/* 871F0C 802404DC 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 871F10 802404E0 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 871F14 802404E4 3C014334 */  lui       $at, 0x4334
/* 871F18 802404E8 44816000 */  mtc1      $at, $f12
/* 871F1C 802404EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 871F20 802404F0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 871F24 802404F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 871F28 802404F8 00031080 */  sll       $v0, $v1, 2
/* 871F2C 802404FC 00431021 */  addu      $v0, $v0, $v1
/* 871F30 80240500 00021080 */  sll       $v0, $v0, 2
/* 871F34 80240504 00431023 */  subu      $v0, $v0, $v1
/* 871F38 80240508 000218C0 */  sll       $v1, $v0, 3
/* 871F3C 8024050C 00431021 */  addu      $v0, $v0, $v1
/* 871F40 80240510 000210C0 */  sll       $v0, $v0, 3
/* 871F44 80240514 3C01800B */  lui       $at, 0x800b
/* 871F48 80240518 00220821 */  addu      $at, $at, $v0
/* 871F4C 8024051C C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 871F50 80240520 460C0300 */  add.s     $f12, $f0, $f12
/* 871F54 80240524 0C00A6C9 */  jal       clamp_angle
/* 871F58 80240528 0080802D */   daddu    $s0, $a0, $zero
/* 871F5C 8024052C 4600008D */  trunc.w.s $f2, $f0
/* 871F60 80240530 E6020084 */  swc1      $f2, 0x84($s0)
/* 871F64 80240534 8FBF0014 */  lw        $ra, 0x14($sp)
/* 871F68 80240538 8FB00010 */  lw        $s0, 0x10($sp)
/* 871F6C 8024053C 24020002 */  addiu     $v0, $zero, 2
/* 871F70 80240540 03E00008 */  jr        $ra
/* 871F74 80240544 27BD0018 */   addiu    $sp, $sp, 0x18
