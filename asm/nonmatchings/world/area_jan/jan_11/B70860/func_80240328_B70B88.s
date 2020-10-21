.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240328_B70B88
/* B70B88 80240328 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* B70B8C 8024032C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* B70B90 80240330 3C014334 */  lui       $at, 0x4334
/* B70B94 80240334 44816000 */  mtc1      $at, $f12
/* B70B98 80240338 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B70B9C 8024033C AFBF0014 */  sw        $ra, 0x14($sp)
/* B70BA0 80240340 AFB00010 */  sw        $s0, 0x10($sp)
/* B70BA4 80240344 00031080 */  sll       $v0, $v1, 2
/* B70BA8 80240348 00431021 */  addu      $v0, $v0, $v1
/* B70BAC 8024034C 00021080 */  sll       $v0, $v0, 2
/* B70BB0 80240350 00431023 */  subu      $v0, $v0, $v1
/* B70BB4 80240354 000218C0 */  sll       $v1, $v0, 3
/* B70BB8 80240358 00431021 */  addu      $v0, $v0, $v1
/* B70BBC 8024035C 000210C0 */  sll       $v0, $v0, 3
/* B70BC0 80240360 3C01800B */  lui       $at, 0x800b
/* B70BC4 80240364 00220821 */  addu      $at, $at, $v0
/* B70BC8 80240368 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* B70BCC 8024036C 460C0300 */  add.s     $f12, $f0, $f12
/* B70BD0 80240370 0C00A6C9 */  jal       clamp_angle
/* B70BD4 80240374 0080802D */   daddu    $s0, $a0, $zero
/* B70BD8 80240378 4600008D */  trunc.w.s $f2, $f0
/* B70BDC 8024037C E6020084 */  swc1      $f2, 0x84($s0)
/* B70BE0 80240380 8FBF0014 */  lw        $ra, 0x14($sp)
/* B70BE4 80240384 8FB00010 */  lw        $s0, 0x10($sp)
/* B70BE8 80240388 24020002 */  addiu     $v0, $zero, 2
/* B70BEC 8024038C 03E00008 */  jr        $ra
/* B70BF0 80240390 27BD0018 */   addiu    $sp, $sp, 0x18
