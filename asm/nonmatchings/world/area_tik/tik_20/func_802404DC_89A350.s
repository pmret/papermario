.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404DC_89A82C
/* 89A82C 802404DC 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 89A830 802404E0 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 89A834 802404E4 3C014334 */  lui       $at, 0x4334
/* 89A838 802404E8 44816000 */  mtc1      $at, $f12
/* 89A83C 802404EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 89A840 802404F0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 89A844 802404F4 AFB00010 */  sw        $s0, 0x10($sp)
/* 89A848 802404F8 00031080 */  sll       $v0, $v1, 2
/* 89A84C 802404FC 00431021 */  addu      $v0, $v0, $v1
/* 89A850 80240500 00021080 */  sll       $v0, $v0, 2
/* 89A854 80240504 00431023 */  subu      $v0, $v0, $v1
/* 89A858 80240508 000218C0 */  sll       $v1, $v0, 3
/* 89A85C 8024050C 00431021 */  addu      $v0, $v0, $v1
/* 89A860 80240510 000210C0 */  sll       $v0, $v0, 3
/* 89A864 80240514 3C01800B */  lui       $at, 0x800b
/* 89A868 80240518 00220821 */  addu      $at, $at, $v0
/* 89A86C 8024051C C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 89A870 80240520 460C0300 */  add.s     $f12, $f0, $f12
/* 89A874 80240524 0C00A6C9 */  jal       clamp_angle
/* 89A878 80240528 0080802D */   daddu    $s0, $a0, $zero
/* 89A87C 8024052C 4600008D */  trunc.w.s $f2, $f0
/* 89A880 80240530 E6020084 */  swc1      $f2, 0x84($s0)
/* 89A884 80240534 8FBF0014 */  lw        $ra, 0x14($sp)
/* 89A888 80240538 8FB00010 */  lw        $s0, 0x10($sp)
/* 89A88C 8024053C 24020002 */  addiu     $v0, $zero, 2
/* 89A890 80240540 03E00008 */  jr        $ra
/* 89A894 80240544 27BD0018 */   addiu    $sp, $sp, 0x18
