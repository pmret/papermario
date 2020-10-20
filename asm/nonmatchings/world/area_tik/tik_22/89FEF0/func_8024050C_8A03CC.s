.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024050C_8A03CC
/* 8A03CC 8024050C 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 8A03D0 80240510 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 8A03D4 80240514 3C014334 */  lui       $at, 0x4334
/* 8A03D8 80240518 44816000 */  mtc1      $at, $f12
/* 8A03DC 8024051C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8A03E0 80240520 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8A03E4 80240524 AFB00010 */  sw        $s0, 0x10($sp)
/* 8A03E8 80240528 00031080 */  sll       $v0, $v1, 2
/* 8A03EC 8024052C 00431021 */  addu      $v0, $v0, $v1
/* 8A03F0 80240530 00021080 */  sll       $v0, $v0, 2
/* 8A03F4 80240534 00431023 */  subu      $v0, $v0, $v1
/* 8A03F8 80240538 000218C0 */  sll       $v1, $v0, 3
/* 8A03FC 8024053C 00431021 */  addu      $v0, $v0, $v1
/* 8A0400 80240540 000210C0 */  sll       $v0, $v0, 3
/* 8A0404 80240544 3C01800B */  lui       $at, 0x800b
/* 8A0408 80240548 00220821 */  addu      $at, $at, $v0
/* 8A040C 8024054C C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 8A0410 80240550 460C0300 */  add.s     $f12, $f0, $f12
/* 8A0414 80240554 0C00A6C9 */  jal       clamp_angle
/* 8A0418 80240558 0080802D */   daddu    $s0, $a0, $zero
/* 8A041C 8024055C 4600008D */  trunc.w.s $f2, $f0
/* 8A0420 80240560 E6020084 */  swc1      $f2, 0x84($s0)
/* 8A0424 80240564 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8A0428 80240568 8FB00010 */  lw        $s0, 0x10($sp)
/* 8A042C 8024056C 24020002 */  addiu     $v0, $zero, 2
/* 8A0430 80240570 03E00008 */  jr        $ra
/* 8A0434 80240574 27BD0018 */   addiu    $sp, $sp, 0x18
