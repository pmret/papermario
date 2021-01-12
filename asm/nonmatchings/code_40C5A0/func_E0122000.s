.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0122000
/* 40C5A0 E0122000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 40C5A4 E0122004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 40C5A8 E0122008 4485A000 */  mtc1      $a1, $f20
/* 40C5AC E012200C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 40C5B0 E0122010 4486B000 */  mtc1      $a2, $f22
/* 40C5B4 E0122014 AFB00028 */  sw        $s0, 0x28($sp)
/* 40C5B8 E0122018 0080802D */  daddu     $s0, $a0, $zero
/* 40C5BC E012201C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 40C5C0 E0122020 4487C000 */  mtc1      $a3, $f24
/* 40C5C4 E0122024 27A40010 */  addiu     $a0, $sp, 0x10
/* 40C5C8 E0122028 AFB20030 */  sw        $s2, 0x30($sp)
/* 40C5CC E012202C 8FB20064 */  lw        $s2, 0x64($sp)
/* 40C5D0 E0122030 3C02E012 */  lui       $v0, %hi(func_E0122174)
/* 40C5D4 E0122034 24422174 */  addiu     $v0, $v0, %lo(func_E0122174)
/* 40C5D8 E0122038 AFA20018 */  sw        $v0, 0x18($sp)
/* 40C5DC E012203C 3C02E012 */  lui       $v0, %hi(func_E012217C)
/* 40C5E0 E0122040 2442217C */  addiu     $v0, $v0, %lo(func_E012217C)
/* 40C5E4 E0122044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 40C5E8 E0122048 3C02E012 */  lui       $v0, %hi(func_E01226C4)
/* 40C5EC E012204C 244226C4 */  addiu     $v0, $v0, %lo(func_E01226C4)
/* 40C5F0 E0122050 AFA20020 */  sw        $v0, 0x20($sp)
/* 40C5F4 E0122054 24020083 */  addiu     $v0, $zero, 0x83
/* 40C5F8 E0122058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 40C5FC E012205C AFB1002C */  sw        $s1, 0x2c($sp)
/* 40C600 E0122060 AFA00010 */  sw        $zero, 0x10($sp)
/* 40C604 E0122064 AFA00024 */  sw        $zero, 0x24($sp)
/* 40C608 E0122068 0C080124 */  jal       func_E0200490
/* 40C60C E012206C AFA20014 */   sw       $v0, 0x14($sp)
/* 40C610 E0122070 24040078 */  addiu     $a0, $zero, 0x78
/* 40C614 E0122074 24030001 */  addiu     $v1, $zero, 1
/* 40C618 E0122078 0040882D */  daddu     $s1, $v0, $zero
/* 40C61C E012207C 0C08012C */  jal       func_E02004B0
/* 40C620 E0122080 AE230008 */   sw       $v1, 8($s1)
/* 40C624 E0122084 0040182D */  daddu     $v1, $v0, $zero
/* 40C628 E0122088 14600003 */  bnez      $v1, .LE0122098
/* 40C62C E012208C AE22000C */   sw       $v0, 0xc($s1)
.LE0122090:
/* 40C630 E0122090 08048824 */  j         .LE0122090
/* 40C634 E0122094 00000000 */   nop
.LE0122098:
/* 40C638 E0122098 3202FF00 */  andi      $v0, $s0, 0xff00
/* 40C63C E012209C 321000FF */  andi      $s0, $s0, 0xff
/* 40C640 E01220A0 AC620000 */  sw        $v0, ($v1)
/* 40C644 E01220A4 AC700004 */  sw        $s0, 4($v1)
/* 40C648 E01220A8 1E400004 */  bgtz      $s2, .LE01220BC
/* 40C64C E01220AC AC600018 */   sw       $zero, 0x18($v1)
/* 40C650 E01220B0 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 40C654 E01220B4 08048830 */  j         .LE01220C0
/* 40C658 E01220B8 AC620014 */   sw       $v0, 0x14($v1)
.LE01220BC:
/* 40C65C E01220BC AC720014 */  sw        $s2, 0x14($v1)
.LE01220C0:
/* 40C660 E01220C0 3C013F80 */  lui       $at, 0x3f80
/* 40C664 E01220C4 44811000 */  mtc1      $at, $f2
/* 40C668 E01220C8 240200FF */  addiu     $v0, $zero, 0xff
/* 40C66C E01220CC AC620028 */  sw        $v0, 0x28($v1)
/* 40C670 E01220D0 E4740008 */  swc1      $f20, 8($v1)
/* 40C674 E01220D4 E476000C */  swc1      $f22, 0xc($v1)
/* 40C678 E01220D8 E4780010 */  swc1      $f24, 0x10($v1)
/* 40C67C E01220DC C7A00060 */  lwc1      $f0, 0x60($sp)
/* 40C680 E01220E0 AC62001C */  sw        $v0, 0x1c($v1)
/* 40C684 E01220E4 AC620020 */  sw        $v0, 0x20($v1)
/* 40C688 E01220E8 AC620024 */  sw        $v0, 0x24($v1)
/* 40C68C E01220EC AC62002C */  sw        $v0, 0x2c($v1)
/* 40C690 E01220F0 AC620030 */  sw        $v0, 0x30($v1)
/* 40C694 E01220F4 AC620034 */  sw        $v0, 0x34($v1)
/* 40C698 E01220F8 AC620038 */  sw        $v0, 0x38($v1)
/* 40C69C E01220FC AC620050 */  sw        $v0, 0x50($v1)
/* 40C6A0 E0122100 24020003 */  addiu     $v0, $zero, 3
/* 40C6A4 E0122104 AC600060 */  sw        $zero, 0x60($v1)
/* 40C6A8 E0122108 AC600064 */  sw        $zero, 0x64($v1)
/* 40C6AC E012210C AC600068 */  sw        $zero, 0x68($v1)
/* 40C6B0 E0122110 AC60006C */  sw        $zero, 0x6c($v1)
/* 40C6B4 E0122114 AC600044 */  sw        $zero, 0x44($v1)
/* 40C6B8 E0122118 AC600048 */  sw        $zero, 0x48($v1)
/* 40C6BC E012211C AC60004C */  sw        $zero, 0x4c($v1)
/* 40C6C0 E0122120 AC600054 */  sw        $zero, 0x54($v1)
/* 40C6C4 E0122124 AC600058 */  sw        $zero, 0x58($v1)
/* 40C6C8 E0122128 AC60005C */  sw        $zero, 0x5c($v1)
/* 40C6CC E012212C E460003C */  swc1      $f0, 0x3c($v1)
/* 40C6D0 E0122130 16020004 */  bne       $s0, $v0, .LE0122144
/* 40C6D4 E0122134 E4620040 */   swc1     $f2, 0x40($v1)
/* 40C6D8 E0122138 24020001 */  addiu     $v0, $zero, 1
/* 40C6DC E012213C 08048852 */  j         .LE0122148
/* 40C6E0 E0122140 AC620070 */   sw       $v0, 0x70($v1)
.LE0122144:
/* 40C6E4 E0122144 AC600070 */  sw        $zero, 0x70($v1)
.LE0122148:
/* 40C6E8 E0122148 0220102D */  daddu     $v0, $s1, $zero
/* 40C6EC E012214C AC600074 */  sw        $zero, 0x74($v1)
/* 40C6F0 E0122150 8FBF0034 */  lw        $ra, 0x34($sp)
/* 40C6F4 E0122154 8FB20030 */  lw        $s2, 0x30($sp)
/* 40C6F8 E0122158 8FB1002C */  lw        $s1, 0x2c($sp)
/* 40C6FC E012215C 8FB00028 */  lw        $s0, 0x28($sp)
/* 40C700 E0122160 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 40C704 E0122164 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 40C708 E0122168 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 40C70C E012216C 03E00008 */  jr        $ra
/* 40C710 E0122170 27BD0050 */   addiu    $sp, $sp, 0x50
