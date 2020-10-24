.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240838_DCD508
/* DCD508 80240838 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DCD50C 8024083C AFB10014 */  sw        $s1, 0x14($sp)
/* DCD510 80240840 0080882D */  daddu     $s1, $a0, $zero
/* DCD514 80240844 AFBF001C */  sw        $ra, 0x1c($sp)
/* DCD518 80240848 AFB20018 */  sw        $s2, 0x18($sp)
/* DCD51C 8024084C AFB00010 */  sw        $s0, 0x10($sp)
/* DCD520 80240850 8E240084 */  lw        $a0, 0x84($s1)
/* DCD524 80240854 0C04C3D6 */  jal       get_item_entity
/* DCD528 80240858 00A0802D */   daddu    $s0, $a1, $zero
/* DCD52C 8024085C 12000005 */  beqz      $s0, .L80240874
/* DCD530 80240860 0040902D */   daddu    $s2, $v0, $zero
/* DCD534 80240864 C640000C */  lwc1      $f0, 0xc($s2)
/* DCD538 80240868 AE200074 */  sw        $zero, 0x74($s1)
/* DCD53C 8024086C AE20007C */  sw        $zero, 0x7c($s1)
/* DCD540 80240870 E6200078 */  swc1      $f0, 0x78($s1)
.L80240874:
/* DCD544 80240874 8E230074 */  lw        $v1, 0x74($s1)
/* DCD548 80240878 10600005 */  beqz      $v1, .L80240890
/* DCD54C 8024087C 24020001 */   addiu    $v0, $zero, 1
/* DCD550 80240880 10620024 */  beq       $v1, $v0, .L80240914
/* DCD554 80240884 00000000 */   nop      
/* DCD558 80240888 0809025B */  j         .L8024096C
/* DCD55C 8024088C 00000000 */   nop      
.L80240890:
/* DCD560 80240890 3C013FC9 */  lui       $at, 0x3fc9
/* DCD564 80240894 34210FD8 */  ori       $at, $at, 0xfd8
/* DCD568 80240898 44810000 */  mtc1      $at, $f0
/* DCD56C 8024089C C62C007C */  lwc1      $f12, 0x7c($s1)
/* DCD570 802408A0 46806320 */  cvt.s.w   $f12, $f12
/* DCD574 802408A4 46006302 */  mul.s     $f12, $f12, $f0
/* DCD578 802408A8 00000000 */  nop       
/* DCD57C 802408AC 3C0141F0 */  lui       $at, 0x41f0
/* DCD580 802408B0 44810000 */  mtc1      $at, $f0
/* DCD584 802408B4 0C00A874 */  jal       cos_rad
/* DCD588 802408B8 46006303 */   div.s    $f12, $f12, $f0
/* DCD58C 802408BC 3C013F80 */  lui       $at, 0x3f80
/* DCD590 802408C0 44811000 */  mtc1      $at, $f2
/* DCD594 802408C4 00000000 */  nop       
/* DCD598 802408C8 46001081 */  sub.s     $f2, $f2, $f0
/* DCD59C 802408CC 3C0141A0 */  lui       $at, 0x41a0
/* DCD5A0 802408D0 44810000 */  mtc1      $at, $f0
/* DCD5A4 802408D4 00000000 */  nop       
/* DCD5A8 802408D8 46001082 */  mul.s     $f2, $f2, $f0
/* DCD5AC 802408DC 00000000 */  nop       
/* DCD5B0 802408E0 C6200078 */  lwc1      $f0, 0x78($s1)
/* DCD5B4 802408E4 46020000 */  add.s     $f0, $f0, $f2
/* DCD5B8 802408E8 E640000C */  swc1      $f0, 0xc($s2)
/* DCD5BC 802408EC 8E23007C */  lw        $v1, 0x7c($s1)
/* DCD5C0 802408F0 2402001E */  addiu     $v0, $zero, 0x1e
/* DCD5C4 802408F4 14620005 */  bne       $v1, $v0, .L8024090C
/* DCD5C8 802408F8 24620001 */   addiu    $v0, $v1, 1
/* DCD5CC 802408FC 24020001 */  addiu     $v0, $zero, 1
/* DCD5D0 80240900 AE220074 */  sw        $v0, 0x74($s1)
/* DCD5D4 80240904 0809025B */  j         .L8024096C
/* DCD5D8 80240908 AE20007C */   sw       $zero, 0x7c($s1)
.L8024090C:
/* DCD5DC 8024090C 0809025B */  j         .L8024096C
/* DCD5E0 80240910 AE22007C */   sw       $v0, 0x7c($s1)
.L80240914:
/* DCD5E4 80240914 C62C007C */  lwc1      $f12, 0x7c($s1)
/* DCD5E8 80240918 0C00A8D4 */  jal       cos_deg
/* DCD5EC 8024091C 46806320 */   cvt.s.w  $f12, $f12
/* DCD5F0 80240920 3C014040 */  lui       $at, 0x4040
/* DCD5F4 80240924 44811000 */  mtc1      $at, $f2
/* DCD5F8 80240928 00000000 */  nop       
/* DCD5FC 8024092C 46020002 */  mul.s     $f0, $f0, $f2
/* DCD600 80240930 00000000 */  nop       
/* DCD604 80240934 3C014188 */  lui       $at, 0x4188
/* DCD608 80240938 44812000 */  mtc1      $at, $f4
/* DCD60C 8024093C C6220078 */  lwc1      $f2, 0x78($s1)
/* DCD610 80240940 46041080 */  add.s     $f2, $f2, $f4
/* DCD614 80240944 46001080 */  add.s     $f2, $f2, $f0
/* DCD618 80240948 E642000C */  swc1      $f2, 0xc($s2)
/* DCD61C 8024094C 8E22007C */  lw        $v0, 0x7c($s1)
/* DCD620 80240950 24420009 */  addiu     $v0, $v0, 9
/* DCD624 80240954 44826000 */  mtc1      $v0, $f12
/* DCD628 80240958 00000000 */  nop       
/* DCD62C 8024095C 0C00A6C9 */  jal       clamp_angle
/* DCD630 80240960 46806320 */   cvt.s.w  $f12, $f12
/* DCD634 80240964 4600018D */  trunc.w.s $f6, $f0
/* DCD638 80240968 E626007C */  swc1      $f6, 0x7c($s1)
.L8024096C:
/* DCD63C 8024096C 8FBF001C */  lw        $ra, 0x1c($sp)
/* DCD640 80240970 8FB20018 */  lw        $s2, 0x18($sp)
/* DCD644 80240974 8FB10014 */  lw        $s1, 0x14($sp)
/* DCD648 80240978 8FB00010 */  lw        $s0, 0x10($sp)
/* DCD64C 8024097C 0000102D */  daddu     $v0, $zero, $zero
/* DCD650 80240980 03E00008 */  jr        $ra
/* DCD654 80240984 27BD0020 */   addiu    $sp, $sp, 0x20
