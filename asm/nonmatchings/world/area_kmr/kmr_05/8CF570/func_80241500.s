.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241500
/* 8CF570 80241500 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 8CF574 80241504 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 8CF578 80241508 4485A000 */  mtc1      $a1, $f20
/* 8CF57C 8024150C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 8CF580 80241510 4486B000 */  mtc1      $a2, $f22
/* 8CF584 80241514 AFB00010 */  sw        $s0, 0x10($sp)
/* 8CF588 80241518 F7B80028 */  sdc1      $f24, 0x28($sp)
/* 8CF58C 8024151C 4487C000 */  mtc1      $a3, $f24
/* 8CF590 80241520 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8CF594 80241524 0C019D28 */  jal       guMtxIdentF
/* 8CF598 80241528 0080802D */   daddu    $s0, $a0, $zero
/* 8CF59C 8024152C 4616A582 */  mul.s     $f22, $f20, $f22
/* 8CF5A0 80241530 00000000 */  nop       
/* 8CF5A4 80241534 4618A502 */  mul.s     $f20, $f20, $f24
/* 8CF5A8 80241538 00000000 */  nop       
/* 8CF5AC 8024153C 3C013F80 */  lui       $at, 0x3f80
/* 8CF5B0 80241540 44810000 */  mtc1      $at, $f0
/* 8CF5B4 80241544 00000000 */  nop       
/* 8CF5B8 80241548 E6000014 */  swc1      $f0, 0x14($s0)
/* 8CF5BC 8024154C E6160010 */  swc1      $f22, 0x10($s0)
/* 8CF5C0 80241550 E6140018 */  swc1      $f20, 0x18($s0)
/* 8CF5C4 80241554 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8CF5C8 80241558 8FB00010 */  lw        $s0, 0x10($sp)
/* 8CF5CC 8024155C D7B80028 */  ldc1      $f24, 0x28($sp)
/* 8CF5D0 80241560 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 8CF5D4 80241564 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 8CF5D8 80241568 03E00008 */  jr        $ra
/* 8CF5DC 8024156C 27BD0030 */   addiu    $sp, $sp, 0x30
