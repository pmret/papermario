.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240118_AFDC58
/* AFDC58 80240118 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AFDC5C 8024011C AFB10014 */  sw        $s1, 0x14($sp)
/* AFDC60 80240120 0080882D */  daddu     $s1, $a0, $zero
/* AFDC64 80240124 AFBF001C */  sw        $ra, 0x1c($sp)
/* AFDC68 80240128 AFB20018 */  sw        $s2, 0x18($sp)
/* AFDC6C 8024012C AFB00010 */  sw        $s0, 0x10($sp)
/* AFDC70 80240130 8E240084 */  lw        $a0, 0x84($s1)
/* AFDC74 80240134 0C04C3D6 */  jal       get_item_entity
/* AFDC78 80240138 00A0802D */   daddu    $s0, $a1, $zero
/* AFDC7C 8024013C 12000005 */  beqz      $s0, .L80240154
/* AFDC80 80240140 0040902D */   daddu    $s2, $v0, $zero
/* AFDC84 80240144 C640000C */  lwc1      $f0, 0xc($s2)
/* AFDC88 80240148 AE200074 */  sw        $zero, 0x74($s1)
/* AFDC8C 8024014C AE20007C */  sw        $zero, 0x7c($s1)
/* AFDC90 80240150 E6200078 */  swc1      $f0, 0x78($s1)
.L80240154:
/* AFDC94 80240154 8E230074 */  lw        $v1, 0x74($s1)
/* AFDC98 80240158 10600005 */  beqz      $v1, .L80240170
/* AFDC9C 8024015C 24020001 */   addiu    $v0, $zero, 1
/* AFDCA0 80240160 10620024 */  beq       $v1, $v0, .L802401F4
/* AFDCA4 80240164 00000000 */   nop      
/* AFDCA8 80240168 08090093 */  j         .L8024024C
/* AFDCAC 8024016C 00000000 */   nop      
.L80240170:
/* AFDCB0 80240170 3C013FC9 */  lui       $at, 0x3fc9
/* AFDCB4 80240174 34210FD8 */  ori       $at, $at, 0xfd8
/* AFDCB8 80240178 44810000 */  mtc1      $at, $f0
/* AFDCBC 8024017C C62C007C */  lwc1      $f12, 0x7c($s1)
/* AFDCC0 80240180 46806320 */  cvt.s.w   $f12, $f12
/* AFDCC4 80240184 46006302 */  mul.s     $f12, $f12, $f0
/* AFDCC8 80240188 00000000 */  nop       
/* AFDCCC 8024018C 3C0141F0 */  lui       $at, 0x41f0
/* AFDCD0 80240190 44810000 */  mtc1      $at, $f0
/* AFDCD4 80240194 0C00A874 */  jal       cos_rad
/* AFDCD8 80240198 46006303 */   div.s    $f12, $f12, $f0
/* AFDCDC 8024019C 3C013F80 */  lui       $at, 0x3f80
/* AFDCE0 802401A0 44811000 */  mtc1      $at, $f2
/* AFDCE4 802401A4 00000000 */  nop       
/* AFDCE8 802401A8 46001081 */  sub.s     $f2, $f2, $f0
/* AFDCEC 802401AC 3C0141A0 */  lui       $at, 0x41a0
/* AFDCF0 802401B0 44810000 */  mtc1      $at, $f0
/* AFDCF4 802401B4 00000000 */  nop       
/* AFDCF8 802401B8 46001082 */  mul.s     $f2, $f2, $f0
/* AFDCFC 802401BC 00000000 */  nop       
/* AFDD00 802401C0 C6200078 */  lwc1      $f0, 0x78($s1)
/* AFDD04 802401C4 46020000 */  add.s     $f0, $f0, $f2
/* AFDD08 802401C8 E640000C */  swc1      $f0, 0xc($s2)
/* AFDD0C 802401CC 8E23007C */  lw        $v1, 0x7c($s1)
/* AFDD10 802401D0 2402001E */  addiu     $v0, $zero, 0x1e
/* AFDD14 802401D4 14620005 */  bne       $v1, $v0, .L802401EC
/* AFDD18 802401D8 24620001 */   addiu    $v0, $v1, 1
/* AFDD1C 802401DC 24020001 */  addiu     $v0, $zero, 1
/* AFDD20 802401E0 AE220074 */  sw        $v0, 0x74($s1)
/* AFDD24 802401E4 08090093 */  j         .L8024024C
/* AFDD28 802401E8 AE20007C */   sw       $zero, 0x7c($s1)
.L802401EC:
/* AFDD2C 802401EC 08090093 */  j         .L8024024C
/* AFDD30 802401F0 AE22007C */   sw       $v0, 0x7c($s1)
.L802401F4:
/* AFDD34 802401F4 C62C007C */  lwc1      $f12, 0x7c($s1)
/* AFDD38 802401F8 0C00A8D4 */  jal       cos_deg
/* AFDD3C 802401FC 46806320 */   cvt.s.w  $f12, $f12
/* AFDD40 80240200 3C014040 */  lui       $at, 0x4040
/* AFDD44 80240204 44811000 */  mtc1      $at, $f2
/* AFDD48 80240208 00000000 */  nop       
/* AFDD4C 8024020C 46020002 */  mul.s     $f0, $f0, $f2
/* AFDD50 80240210 00000000 */  nop       
/* AFDD54 80240214 3C014188 */  lui       $at, 0x4188
/* AFDD58 80240218 44812000 */  mtc1      $at, $f4
/* AFDD5C 8024021C C6220078 */  lwc1      $f2, 0x78($s1)
/* AFDD60 80240220 46041080 */  add.s     $f2, $f2, $f4
/* AFDD64 80240224 46001080 */  add.s     $f2, $f2, $f0
/* AFDD68 80240228 E642000C */  swc1      $f2, 0xc($s2)
/* AFDD6C 8024022C 8E22007C */  lw        $v0, 0x7c($s1)
/* AFDD70 80240230 24420009 */  addiu     $v0, $v0, 9
/* AFDD74 80240234 44826000 */  mtc1      $v0, $f12
/* AFDD78 80240238 00000000 */  nop       
/* AFDD7C 8024023C 0C00A6C9 */  jal       clamp_angle
/* AFDD80 80240240 46806320 */   cvt.s.w  $f12, $f12
/* AFDD84 80240244 4600018D */  trunc.w.s $f6, $f0
/* AFDD88 80240248 E626007C */  swc1      $f6, 0x7c($s1)
.L8024024C:
/* AFDD8C 8024024C 8FBF001C */  lw        $ra, 0x1c($sp)
/* AFDD90 80240250 8FB20018 */  lw        $s2, 0x18($sp)
/* AFDD94 80240254 8FB10014 */  lw        $s1, 0x14($sp)
/* AFDD98 80240258 8FB00010 */  lw        $s0, 0x10($sp)
/* AFDD9C 8024025C 0000102D */  daddu     $v0, $zero, $zero
/* AFDDA0 80240260 03E00008 */  jr        $ra
/* AFDDA4 80240264 27BD0020 */   addiu    $sp, $sp, 0x20
