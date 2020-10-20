.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F40
/* 893960 80240F40 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 893964 80240F44 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 893968 80240F48 3C014334 */  lui       $at, 0x4334
/* 89396C 80240F4C 44816000 */  mtc1      $at, $f12
/* 893970 80240F50 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 893974 80240F54 AFBF0014 */  sw        $ra, 0x14($sp)
/* 893978 80240F58 AFB00010 */  sw        $s0, 0x10($sp)
/* 89397C 80240F5C 00031080 */  sll       $v0, $v1, 2
/* 893980 80240F60 00431021 */  addu      $v0, $v0, $v1
/* 893984 80240F64 00021080 */  sll       $v0, $v0, 2
/* 893988 80240F68 00431023 */  subu      $v0, $v0, $v1
/* 89398C 80240F6C 000218C0 */  sll       $v1, $v0, 3
/* 893990 80240F70 00431021 */  addu      $v0, $v0, $v1
/* 893994 80240F74 000210C0 */  sll       $v0, $v0, 3
/* 893998 80240F78 3C01800B */  lui       $at, 0x800b
/* 89399C 80240F7C 00220821 */  addu      $at, $at, $v0
/* 8939A0 80240F80 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* 8939A4 80240F84 460C0300 */  add.s     $f12, $f0, $f12
/* 8939A8 80240F88 0C00A6C9 */  jal       clamp_angle
/* 8939AC 80240F8C 0080802D */   daddu    $s0, $a0, $zero
/* 8939B0 80240F90 4600008D */  trunc.w.s $f2, $f0
/* 8939B4 80240F94 E6020084 */  swc1      $f2, 0x84($s0)
/* 8939B8 80240F98 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8939BC 80240F9C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8939C0 80240FA0 24020002 */  addiu     $v0, $zero, 2
/* 8939C4 80240FA4 03E00008 */  jr        $ra
/* 8939C8 80240FA8 27BD0018 */   addiu    $sp, $sp, 0x18
