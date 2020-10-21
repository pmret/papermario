.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F20_8EDD40
/* 8EDD40 80241F20 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 8EDD44 80241F24 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 8EDD48 80241F28 3C014334 */  lui       $at, 0x4334
/* 8EDD4C 80241F2C 44816000 */  mtc1      $at, $f12
/* 8EDD50 80241F30 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8EDD54 80241F34 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8EDD58 80241F38 AFB00010 */  sw        $s0, 0x10($sp)
/* 8EDD5C 80241F3C 00031080 */  sll       $v0, $v1, 2
/* 8EDD60 80241F40 00431021 */  addu      $v0, $v0, $v1
/* 8EDD64 80241F44 00021080 */  sll       $v0, $v0, 2
/* 8EDD68 80241F48 00431023 */  subu      $v0, $v0, $v1
/* 8EDD6C 80241F4C 000218C0 */  sll       $v1, $v0, 3
/* 8EDD70 80241F50 00431021 */  addu      $v0, $v0, $v1
/* 8EDD74 80241F54 000210C0 */  sll       $v0, $v0, 3
/* 8EDD78 80241F58 3C01800B */  lui       $at, 0x800b
/* 8EDD7C 80241F5C 00220821 */  addu      $at, $at, $v0
/* 8EDD80 80241F60 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 8EDD84 80241F64 460C0300 */  add.s     $f12, $f0, $f12
/* 8EDD88 80241F68 0C00A6C9 */  jal       clamp_angle
/* 8EDD8C 80241F6C 0080802D */   daddu    $s0, $a0, $zero
/* 8EDD90 80241F70 4600008D */  trunc.w.s $f2, $f0
/* 8EDD94 80241F74 E6020084 */  swc1      $f2, 0x84($s0)
/* 8EDD98 80241F78 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8EDD9C 80241F7C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8EDDA0 80241F80 24020002 */  addiu     $v0, $zero, 2
/* 8EDDA4 80241F84 03E00008 */  jr        $ra
/* 8EDDA8 80241F88 27BD0018 */   addiu    $sp, $sp, 0x18
