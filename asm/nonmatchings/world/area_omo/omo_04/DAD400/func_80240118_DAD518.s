.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240118_DAD518
/* DAD518 80240118 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DAD51C 8024011C AFB10014 */  sw        $s1, 0x14($sp)
/* DAD520 80240120 0080882D */  daddu     $s1, $a0, $zero
/* DAD524 80240124 AFBF001C */  sw        $ra, 0x1c($sp)
/* DAD528 80240128 AFB20018 */  sw        $s2, 0x18($sp)
/* DAD52C 8024012C AFB00010 */  sw        $s0, 0x10($sp)
/* DAD530 80240130 8E240084 */  lw        $a0, 0x84($s1)
/* DAD534 80240134 0C04C3D6 */  jal       get_item_entity
/* DAD538 80240138 00A0802D */   daddu    $s0, $a1, $zero
/* DAD53C 8024013C 12000005 */  beqz      $s0, .L80240154
/* DAD540 80240140 0040902D */   daddu    $s2, $v0, $zero
/* DAD544 80240144 C640000C */  lwc1      $f0, 0xc($s2)
/* DAD548 80240148 AE200074 */  sw        $zero, 0x74($s1)
/* DAD54C 8024014C AE20007C */  sw        $zero, 0x7c($s1)
/* DAD550 80240150 E6200078 */  swc1      $f0, 0x78($s1)
.L80240154:
/* DAD554 80240154 8E230074 */  lw        $v1, 0x74($s1)
/* DAD558 80240158 10600005 */  beqz      $v1, .L80240170
/* DAD55C 8024015C 24020001 */   addiu    $v0, $zero, 1
/* DAD560 80240160 10620024 */  beq       $v1, $v0, .L802401F4
/* DAD564 80240164 00000000 */   nop      
/* DAD568 80240168 08090093 */  j         .L8024024C
/* DAD56C 8024016C 00000000 */   nop      
.L80240170:
/* DAD570 80240170 3C013FC9 */  lui       $at, 0x3fc9
/* DAD574 80240174 34210FD8 */  ori       $at, $at, 0xfd8
/* DAD578 80240178 44810000 */  mtc1      $at, $f0
/* DAD57C 8024017C C62C007C */  lwc1      $f12, 0x7c($s1)
/* DAD580 80240180 46806320 */  cvt.s.w   $f12, $f12
/* DAD584 80240184 46006302 */  mul.s     $f12, $f12, $f0
/* DAD588 80240188 00000000 */  nop       
/* DAD58C 8024018C 3C0141F0 */  lui       $at, 0x41f0
/* DAD590 80240190 44810000 */  mtc1      $at, $f0
/* DAD594 80240194 0C00A874 */  jal       cos_rad
/* DAD598 80240198 46006303 */   div.s    $f12, $f12, $f0
/* DAD59C 8024019C 3C013F80 */  lui       $at, 0x3f80
/* DAD5A0 802401A0 44811000 */  mtc1      $at, $f2
/* DAD5A4 802401A4 00000000 */  nop       
/* DAD5A8 802401A8 46001081 */  sub.s     $f2, $f2, $f0
/* DAD5AC 802401AC 3C0141A0 */  lui       $at, 0x41a0
/* DAD5B0 802401B0 44810000 */  mtc1      $at, $f0
/* DAD5B4 802401B4 00000000 */  nop       
/* DAD5B8 802401B8 46001082 */  mul.s     $f2, $f2, $f0
/* DAD5BC 802401BC 00000000 */  nop       
/* DAD5C0 802401C0 C6200078 */  lwc1      $f0, 0x78($s1)
/* DAD5C4 802401C4 46020000 */  add.s     $f0, $f0, $f2
/* DAD5C8 802401C8 E640000C */  swc1      $f0, 0xc($s2)
/* DAD5CC 802401CC 8E23007C */  lw        $v1, 0x7c($s1)
/* DAD5D0 802401D0 2402001E */  addiu     $v0, $zero, 0x1e
/* DAD5D4 802401D4 14620005 */  bne       $v1, $v0, .L802401EC
/* DAD5D8 802401D8 24620001 */   addiu    $v0, $v1, 1
/* DAD5DC 802401DC 24020001 */  addiu     $v0, $zero, 1
/* DAD5E0 802401E0 AE220074 */  sw        $v0, 0x74($s1)
/* DAD5E4 802401E4 08090093 */  j         .L8024024C
/* DAD5E8 802401E8 AE20007C */   sw       $zero, 0x7c($s1)
.L802401EC:
/* DAD5EC 802401EC 08090093 */  j         .L8024024C
/* DAD5F0 802401F0 AE22007C */   sw       $v0, 0x7c($s1)
.L802401F4:
/* DAD5F4 802401F4 C62C007C */  lwc1      $f12, 0x7c($s1)
/* DAD5F8 802401F8 0C00A8D4 */  jal       cos_deg
/* DAD5FC 802401FC 46806320 */   cvt.s.w  $f12, $f12
/* DAD600 80240200 3C014040 */  lui       $at, 0x4040
/* DAD604 80240204 44811000 */  mtc1      $at, $f2
/* DAD608 80240208 00000000 */  nop       
/* DAD60C 8024020C 46020002 */  mul.s     $f0, $f0, $f2
/* DAD610 80240210 00000000 */  nop       
/* DAD614 80240214 3C014188 */  lui       $at, 0x4188
/* DAD618 80240218 44812000 */  mtc1      $at, $f4
/* DAD61C 8024021C C6220078 */  lwc1      $f2, 0x78($s1)
/* DAD620 80240220 46041080 */  add.s     $f2, $f2, $f4
/* DAD624 80240224 46001080 */  add.s     $f2, $f2, $f0
/* DAD628 80240228 E642000C */  swc1      $f2, 0xc($s2)
/* DAD62C 8024022C 8E22007C */  lw        $v0, 0x7c($s1)
/* DAD630 80240230 24420009 */  addiu     $v0, $v0, 9
/* DAD634 80240234 44826000 */  mtc1      $v0, $f12
/* DAD638 80240238 00000000 */  nop       
/* DAD63C 8024023C 0C00A6C9 */  jal       clamp_angle
/* DAD640 80240240 46806320 */   cvt.s.w  $f12, $f12
/* DAD644 80240244 4600018D */  trunc.w.s $f6, $f0
/* DAD648 80240248 E626007C */  swc1      $f6, 0x7c($s1)
.L8024024C:
/* DAD64C 8024024C 8FBF001C */  lw        $ra, 0x1c($sp)
/* DAD650 80240250 8FB20018 */  lw        $s2, 0x18($sp)
/* DAD654 80240254 8FB10014 */  lw        $s1, 0x14($sp)
/* DAD658 80240258 8FB00010 */  lw        $s0, 0x10($sp)
/* DAD65C 8024025C 0000102D */  daddu     $v0, $zero, $zero
/* DAD660 80240260 03E00008 */  jr        $ra
/* DAD664 80240264 27BD0020 */   addiu    $sp, $sp, 0x20
