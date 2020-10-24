.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404DC_86998C
/* 86998C 802404DC 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 869990 802404E0 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 869994 802404E4 3C014334 */  lui       $at, 0x4334
/* 869998 802404E8 44816000 */  mtc1      $at, $f12
/* 86999C 802404EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8699A0 802404F0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8699A4 802404F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 8699A8 802404F8 00031080 */  sll       $v0, $v1, 2
/* 8699AC 802404FC 00431021 */  addu      $v0, $v0, $v1
/* 8699B0 80240500 00021080 */  sll       $v0, $v0, 2
/* 8699B4 80240504 00431023 */  subu      $v0, $v0, $v1
/* 8699B8 80240508 000218C0 */  sll       $v1, $v0, 3
/* 8699BC 8024050C 00431021 */  addu      $v0, $v0, $v1
/* 8699C0 80240510 000210C0 */  sll       $v0, $v0, 3
/* 8699C4 80240514 3C01800B */  lui       $at, 0x800b
/* 8699C8 80240518 00220821 */  addu      $at, $at, $v0
/* 8699CC 8024051C C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 8699D0 80240520 460C0300 */  add.s     $f12, $f0, $f12
/* 8699D4 80240524 0C00A6C9 */  jal       clamp_angle
/* 8699D8 80240528 0080802D */   daddu    $s0, $a0, $zero
/* 8699DC 8024052C 4600008D */  trunc.w.s $f2, $f0
/* 8699E0 80240530 E6020084 */  swc1      $f2, 0x84($s0)
/* 8699E4 80240534 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8699E8 80240538 8FB00010 */  lw        $s0, 0x10($sp)
/* 8699EC 8024053C 24020002 */  addiu     $v0, $zero, 2
/* 8699F0 80240540 03E00008 */  jr        $ra
/* 8699F4 80240544 27BD0018 */   addiu    $sp, $sp, 0x18
