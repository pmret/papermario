.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243770_95E970
/* 95E970 80243770 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 95E974 80243774 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 95E978 80243778 3C014334 */  lui       $at, 0x4334
/* 95E97C 8024377C 44816000 */  mtc1      $at, $f12
/* 95E980 80243780 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 95E984 80243784 AFBF0014 */  sw        $ra, 0x14($sp)
/* 95E988 80243788 AFB00010 */  sw        $s0, 0x10($sp)
/* 95E98C 8024378C 00031080 */  sll       $v0, $v1, 2
/* 95E990 80243790 00431021 */  addu      $v0, $v0, $v1
/* 95E994 80243794 00021080 */  sll       $v0, $v0, 2
/* 95E998 80243798 00431023 */  subu      $v0, $v0, $v1
/* 95E99C 8024379C 000218C0 */  sll       $v1, $v0, 3
/* 95E9A0 802437A0 00431021 */  addu      $v0, $v0, $v1
/* 95E9A4 802437A4 000210C0 */  sll       $v0, $v0, 3
/* 95E9A8 802437A8 3C01800B */  lui       $at, 0x800b
/* 95E9AC 802437AC 00220821 */  addu      $at, $at, $v0
/* 95E9B0 802437B0 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 95E9B4 802437B4 460C0300 */  add.s     $f12, $f0, $f12
/* 95E9B8 802437B8 0C00A6C9 */  jal       clamp_angle
/* 95E9BC 802437BC 0080802D */   daddu    $s0, $a0, $zero
/* 95E9C0 802437C0 4600008D */  trunc.w.s $f2, $f0
/* 95E9C4 802437C4 E6020084 */  swc1      $f2, 0x84($s0)
/* 95E9C8 802437C8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 95E9CC 802437CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 95E9D0 802437D0 24020002 */  addiu     $v0, $zero, 2
/* 95E9D4 802437D4 03E00008 */  jr        $ra
/* 95E9D8 802437D8 27BD0018 */   addiu    $sp, $sp, 0x18
