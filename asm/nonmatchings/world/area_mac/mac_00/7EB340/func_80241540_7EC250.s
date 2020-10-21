.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241540_7EC250
/* 7EC250 80241540 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 7EC254 80241544 AFB10014 */  sw        $s1, 0x14($sp)
/* 7EC258 80241548 0080882D */  daddu     $s1, $a0, $zero
/* 7EC25C 8024154C AFB00010 */  sw        $s0, 0x10($sp)
/* 7EC260 80241550 00A0802D */  daddu     $s0, $a1, $zero
/* 7EC264 80241554 AFBF001C */  sw        $ra, 0x1c($sp)
/* 7EC268 80241558 AFB20018 */  sw        $s2, 0x18($sp)
/* 7EC26C 8024155C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 7EC270 80241560 0C00EABB */  jal       get_npc_unsafe
/* 7EC274 80241564 2404FFFC */   addiu    $a0, $zero, -4
/* 7EC278 80241568 12000017 */  beqz      $s0, .L802415C8
/* 7EC27C 8024156C 0040902D */   daddu    $s2, $v0, $zero
/* 7EC280 80241570 0220202D */  daddu     $a0, $s1, $zero
/* 7EC284 80241574 3C05FE36 */  lui       $a1, 0xfe36
/* 7EC288 80241578 0C0B210B */  jal       get_float_variable
/* 7EC28C 8024157C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 7EC290 80241580 0220202D */  daddu     $a0, $s1, $zero
/* 7EC294 80241584 3C05FE36 */  lui       $a1, 0xfe36
/* 7EC298 80241588 3C014270 */  lui       $at, 0x4270
/* 7EC29C 8024158C 4481A000 */  mtc1      $at, $f20
/* 7EC2A0 80241590 34A53C85 */  ori       $a1, $a1, 0x3c85
/* 7EC2A4 80241594 46140003 */  div.s     $f0, $f0, $f20
/* 7EC2A8 80241598 0C0B210B */  jal       get_float_variable
/* 7EC2AC 8024159C E6200074 */   swc1     $f0, 0x74($s1)
/* 7EC2B0 802415A0 0220202D */  daddu     $a0, $s1, $zero
/* 7EC2B4 802415A4 3C05FE36 */  lui       $a1, 0xfe36
/* 7EC2B8 802415A8 34A53C81 */  ori       $a1, $a1, 0x3c81
/* 7EC2BC 802415AC 46140003 */  div.s     $f0, $f0, $f20
/* 7EC2C0 802415B0 0C0B210B */  jal       get_float_variable
/* 7EC2C4 802415B4 E6200078 */   swc1     $f0, 0x78($s1)
/* 7EC2C8 802415B8 46140003 */  div.s     $f0, $f0, $f20
/* 7EC2CC 802415BC 2402003C */  addiu     $v0, $zero, 0x3c
/* 7EC2D0 802415C0 E620007C */  swc1      $f0, 0x7c($s1)
/* 7EC2D4 802415C4 AE220070 */  sw        $v0, 0x70($s1)
.L802415C8:
/* 7EC2D8 802415C8 C6400038 */  lwc1      $f0, 0x38($s2)
/* 7EC2DC 802415CC C6220074 */  lwc1      $f2, 0x74($s1)
/* 7EC2E0 802415D0 46020000 */  add.s     $f0, $f0, $f2
/* 7EC2E4 802415D4 E6400038 */  swc1      $f0, 0x38($s2)
/* 7EC2E8 802415D8 C640003C */  lwc1      $f0, 0x3c($s2)
/* 7EC2EC 802415DC C6220078 */  lwc1      $f2, 0x78($s1)
/* 7EC2F0 802415E0 46020000 */  add.s     $f0, $f0, $f2
/* 7EC2F4 802415E4 E640003C */  swc1      $f0, 0x3c($s2)
/* 7EC2F8 802415E8 C6400040 */  lwc1      $f0, 0x40($s2)
/* 7EC2FC 802415EC C622007C */  lwc1      $f2, 0x7c($s1)
/* 7EC300 802415F0 46020000 */  add.s     $f0, $f0, $f2
/* 7EC304 802415F4 E6400040 */  swc1      $f0, 0x40($s2)
/* 7EC308 802415F8 8E230070 */  lw        $v1, 0x70($s1)
/* 7EC30C 802415FC 2463FFFF */  addiu     $v1, $v1, -1
/* 7EC310 80241600 2C620001 */  sltiu     $v0, $v1, 1
/* 7EC314 80241604 AE230070 */  sw        $v1, 0x70($s1)
/* 7EC318 80241608 8FBF001C */  lw        $ra, 0x1c($sp)
/* 7EC31C 8024160C 8FB20018 */  lw        $s2, 0x18($sp)
/* 7EC320 80241610 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EC324 80241614 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EC328 80241618 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 7EC32C 8024161C 00021040 */  sll       $v0, $v0, 1
/* 7EC330 80241620 03E00008 */  jr        $ra
/* 7EC334 80241624 27BD0028 */   addiu    $sp, $sp, 0x28
