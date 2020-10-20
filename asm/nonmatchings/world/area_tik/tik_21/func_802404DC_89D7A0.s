.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404DC_89DC7C
/* 89DC7C 802404DC 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 89DC80 802404E0 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 89DC84 802404E4 3C014334 */  lui       $at, 0x4334
/* 89DC88 802404E8 44816000 */  mtc1      $at, $f12
/* 89DC8C 802404EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 89DC90 802404F0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 89DC94 802404F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 89DC98 802404F8 00031080 */  sll       $v0, $v1, 2
/* 89DC9C 802404FC 00431021 */  addu      $v0, $v0, $v1
/* 89DCA0 80240500 00021080 */  sll       $v0, $v0, 2
/* 89DCA4 80240504 00431023 */  subu      $v0, $v0, $v1
/* 89DCA8 80240508 000218C0 */  sll       $v1, $v0, 3
/* 89DCAC 8024050C 00431021 */  addu      $v0, $v0, $v1
/* 89DCB0 80240510 000210C0 */  sll       $v0, $v0, 3
/* 89DCB4 80240514 3C01800B */  lui       $at, 0x800b
/* 89DCB8 80240518 00220821 */  addu      $at, $at, $v0
/* 89DCBC 8024051C C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 89DCC0 80240520 460C0300 */  add.s     $f12, $f0, $f12
/* 89DCC4 80240524 0C00A6C9 */  jal       clamp_angle
/* 89DCC8 80240528 0080802D */   daddu    $s0, $a0, $zero
/* 89DCCC 8024052C 4600008D */  trunc.w.s $f2, $f0
/* 89DCD0 80240530 E6020084 */  swc1      $f2, 0x84($s0)
/* 89DCD4 80240534 8FBF0014 */  lw        $ra, 0x14($sp)
/* 89DCD8 80240538 8FB00010 */  lw        $s0, 0x10($sp)
/* 89DCDC 8024053C 24020002 */  addiu     $v0, $zero, 2
/* 89DCE0 80240540 03E00008 */  jr        $ra
/* 89DCE4 80240544 27BD0018 */   addiu    $sp, $sp, 0x18
