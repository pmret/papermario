.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401D0_86ECD0
/* 86ECD0 802401D0 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 86ECD4 802401D4 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 86ECD8 802401D8 3C014334 */  lui       $at, 0x4334
/* 86ECDC 802401DC 44816000 */  mtc1      $at, $f12
/* 86ECE0 802401E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 86ECE4 802401E4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 86ECE8 802401E8 AFB00010 */  sw        $s0, 0x10($sp)
/* 86ECEC 802401EC 00031080 */  sll       $v0, $v1, 2
/* 86ECF0 802401F0 00431021 */  addu      $v0, $v0, $v1
/* 86ECF4 802401F4 00021080 */  sll       $v0, $v0, 2
/* 86ECF8 802401F8 00431023 */  subu      $v0, $v0, $v1
/* 86ECFC 802401FC 000218C0 */  sll       $v1, $v0, 3
/* 86ED00 80240200 00431021 */  addu      $v0, $v0, $v1
/* 86ED04 80240204 000210C0 */  sll       $v0, $v0, 3
/* 86ED08 80240208 3C01800B */  lui       $at, 0x800b
/* 86ED0C 8024020C 00220821 */  addu      $at, $at, $v0
/* 86ED10 80240210 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 86ED14 80240214 460C0300 */  add.s     $f12, $f0, $f12
/* 86ED18 80240218 0C00A6C9 */  jal       clamp_angle
/* 86ED1C 8024021C 0080802D */   daddu    $s0, $a0, $zero
/* 86ED20 80240220 4600008D */  trunc.w.s $f2, $f0
/* 86ED24 80240224 E6020084 */  swc1      $f2, 0x84($s0)
/* 86ED28 80240228 8FBF0014 */  lw        $ra, 0x14($sp)
/* 86ED2C 8024022C 8FB00010 */  lw        $s0, 0x10($sp)
/* 86ED30 80240230 24020002 */  addiu     $v0, $zero, 2
/* 86ED34 80240234 03E00008 */  jr        $ra
/* 86ED38 80240238 27BD0018 */   addiu    $sp, $sp, 0x18
