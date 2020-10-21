.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240200_8EC020
/* 8EC020 80240200 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 8EC024 80240204 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 8EC028 80240208 3C014334 */  lui       $at, 0x4334
/* 8EC02C 8024020C 44816000 */  mtc1      $at, $f12
/* 8EC030 80240210 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8EC034 80240214 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8EC038 80240218 AFB00010 */  sw        $s0, 0x10($sp)
/* 8EC03C 8024021C 00031080 */  sll       $v0, $v1, 2
/* 8EC040 80240220 00431021 */  addu      $v0, $v0, $v1
/* 8EC044 80240224 00021080 */  sll       $v0, $v0, 2
/* 8EC048 80240228 00431023 */  subu      $v0, $v0, $v1
/* 8EC04C 8024022C 000218C0 */  sll       $v1, $v0, 3
/* 8EC050 80240230 00431021 */  addu      $v0, $v0, $v1
/* 8EC054 80240234 000210C0 */  sll       $v0, $v0, 3
/* 8EC058 80240238 3C01800B */  lui       $at, 0x800b
/* 8EC05C 8024023C 00220821 */  addu      $at, $at, $v0
/* 8EC060 80240240 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 8EC064 80240244 460C0300 */  add.s     $f12, $f0, $f12
/* 8EC068 80240248 0C00A6C9 */  jal       clamp_angle
/* 8EC06C 8024024C 0080802D */   daddu    $s0, $a0, $zero
/* 8EC070 80240250 4600008D */  trunc.w.s $f2, $f0
/* 8EC074 80240254 E6020084 */  swc1      $f2, 0x84($s0)
/* 8EC078 80240258 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8EC07C 8024025C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8EC080 80240260 24020002 */  addiu     $v0, $zero, 2
/* 8EC084 80240264 03E00008 */  jr        $ra
/* 8EC088 80240268 27BD0018 */   addiu    $sp, $sp, 0x18
