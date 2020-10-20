.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241950_8ED770
/* 8ED770 80241950 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 8ED774 80241954 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 8ED778 80241958 3C014334 */  lui       $at, 0x4334
/* 8ED77C 8024195C 44816000 */  mtc1      $at, $f12
/* 8ED780 80241960 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8ED784 80241964 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8ED788 80241968 AFB00010 */  sw        $s0, 0x10($sp)
/* 8ED78C 8024196C 00031080 */  sll       $v0, $v1, 2
/* 8ED790 80241970 00431021 */  addu      $v0, $v0, $v1
/* 8ED794 80241974 00021080 */  sll       $v0, $v0, 2
/* 8ED798 80241978 00431023 */  subu      $v0, $v0, $v1
/* 8ED79C 8024197C 000218C0 */  sll       $v1, $v0, 3
/* 8ED7A0 80241980 00431021 */  addu      $v0, $v0, $v1
/* 8ED7A4 80241984 000210C0 */  sll       $v0, $v0, 3
/* 8ED7A8 80241988 3C01800B */  lui       $at, 0x800b
/* 8ED7AC 8024198C 00220821 */  addu      $at, $at, $v0
/* 8ED7B0 80241990 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 8ED7B4 80241994 460C0300 */  add.s     $f12, $f0, $f12
/* 8ED7B8 80241998 0C00A6C9 */  jal       clamp_angle
/* 8ED7BC 8024199C 0080802D */   daddu    $s0, $a0, $zero
/* 8ED7C0 802419A0 4600008D */  trunc.w.s $f2, $f0
/* 8ED7C4 802419A4 E6020084 */  swc1      $f2, 0x84($s0)
/* 8ED7C8 802419A8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8ED7CC 802419AC 8FB00010 */  lw        $s0, 0x10($sp)
/* 8ED7D0 802419B0 24020002 */  addiu     $v0, $zero, 2
/* 8ED7D4 802419B4 03E00008 */  jr        $ra
/* 8ED7D8 802419B8 27BD0018 */   addiu    $sp, $sp, 0x18
