.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241610_CF9180
/* CF9180 80241610 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CF9184 80241614 AFB10014 */  sw        $s1, 0x14($sp)
/* CF9188 80241618 0080882D */  daddu     $s1, $a0, $zero
/* CF918C 8024161C AFB00010 */  sw        $s0, 0x10($sp)
/* CF9190 80241620 00A0802D */  daddu     $s0, $a1, $zero
/* CF9194 80241624 AFBF001C */  sw        $ra, 0x1c($sp)
/* CF9198 80241628 AFB20018 */  sw        $s2, 0x18($sp)
/* CF919C 8024162C F7B40020 */  sdc1      $f20, 0x20($sp)
/* CF91A0 80241630 0C00EABB */  jal       get_npc_unsafe
/* CF91A4 80241634 2404FFFC */   addiu    $a0, $zero, -4
/* CF91A8 80241638 12000017 */  beqz      $s0, .L80241698
/* CF91AC 8024163C 0040902D */   daddu    $s2, $v0, $zero
/* CF91B0 80241640 0220202D */  daddu     $a0, $s1, $zero
/* CF91B4 80241644 3C05FE36 */  lui       $a1, 0xfe36
/* CF91B8 80241648 0C0B210B */  jal       get_float_variable
/* CF91BC 8024164C 34A53C80 */   ori      $a1, $a1, 0x3c80
/* CF91C0 80241650 0220202D */  daddu     $a0, $s1, $zero
/* CF91C4 80241654 3C05FE36 */  lui       $a1, 0xfe36
/* CF91C8 80241658 3C014270 */  lui       $at, 0x4270
/* CF91CC 8024165C 4481A000 */  mtc1      $at, $f20
/* CF91D0 80241660 34A53C85 */  ori       $a1, $a1, 0x3c85
/* CF91D4 80241664 46140003 */  div.s     $f0, $f0, $f20
/* CF91D8 80241668 0C0B210B */  jal       get_float_variable
/* CF91DC 8024166C E6200074 */   swc1     $f0, 0x74($s1)
/* CF91E0 80241670 0220202D */  daddu     $a0, $s1, $zero
/* CF91E4 80241674 3C05FE36 */  lui       $a1, 0xfe36
/* CF91E8 80241678 34A53C81 */  ori       $a1, $a1, 0x3c81
/* CF91EC 8024167C 46140003 */  div.s     $f0, $f0, $f20
/* CF91F0 80241680 0C0B210B */  jal       get_float_variable
/* CF91F4 80241684 E6200078 */   swc1     $f0, 0x78($s1)
/* CF91F8 80241688 46140003 */  div.s     $f0, $f0, $f20
/* CF91FC 8024168C 2402003C */  addiu     $v0, $zero, 0x3c
/* CF9200 80241690 E620007C */  swc1      $f0, 0x7c($s1)
/* CF9204 80241694 AE220070 */  sw        $v0, 0x70($s1)
.L80241698:
/* CF9208 80241698 C6400038 */  lwc1      $f0, 0x38($s2)
/* CF920C 8024169C C6220074 */  lwc1      $f2, 0x74($s1)
/* CF9210 802416A0 46020000 */  add.s     $f0, $f0, $f2
/* CF9214 802416A4 E6400038 */  swc1      $f0, 0x38($s2)
/* CF9218 802416A8 C640003C */  lwc1      $f0, 0x3c($s2)
/* CF921C 802416AC C6220078 */  lwc1      $f2, 0x78($s1)
/* CF9220 802416B0 46020000 */  add.s     $f0, $f0, $f2
/* CF9224 802416B4 E640003C */  swc1      $f0, 0x3c($s2)
/* CF9228 802416B8 C6400040 */  lwc1      $f0, 0x40($s2)
/* CF922C 802416BC C622007C */  lwc1      $f2, 0x7c($s1)
/* CF9230 802416C0 46020000 */  add.s     $f0, $f0, $f2
/* CF9234 802416C4 E6400040 */  swc1      $f0, 0x40($s2)
/* CF9238 802416C8 8E230070 */  lw        $v1, 0x70($s1)
/* CF923C 802416CC 2463FFFF */  addiu     $v1, $v1, -1
/* CF9240 802416D0 2C620001 */  sltiu     $v0, $v1, 1
/* CF9244 802416D4 AE230070 */  sw        $v1, 0x70($s1)
/* CF9248 802416D8 8FBF001C */  lw        $ra, 0x1c($sp)
/* CF924C 802416DC 8FB20018 */  lw        $s2, 0x18($sp)
/* CF9250 802416E0 8FB10014 */  lw        $s1, 0x14($sp)
/* CF9254 802416E4 8FB00010 */  lw        $s0, 0x10($sp)
/* CF9258 802416E8 D7B40020 */  ldc1      $f20, 0x20($sp)
/* CF925C 802416EC 00021040 */  sll       $v0, $v0, 1
/* CF9260 802416F0 03E00008 */  jr        $ra
/* CF9264 802416F4 27BD0028 */   addiu    $sp, $sp, 0x28
