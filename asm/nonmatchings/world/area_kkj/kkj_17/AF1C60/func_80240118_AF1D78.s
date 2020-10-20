.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240118_AF1D78
/* AF1D78 80240118 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AF1D7C 8024011C AFB10014 */  sw        $s1, 0x14($sp)
/* AF1D80 80240120 0080882D */  daddu     $s1, $a0, $zero
/* AF1D84 80240124 AFBF001C */  sw        $ra, 0x1c($sp)
/* AF1D88 80240128 AFB20018 */  sw        $s2, 0x18($sp)
/* AF1D8C 8024012C AFB00010 */  sw        $s0, 0x10($sp)
/* AF1D90 80240130 8E240084 */  lw        $a0, 0x84($s1)
/* AF1D94 80240134 0C04C3D6 */  jal       get_item_entity
/* AF1D98 80240138 00A0802D */   daddu    $s0, $a1, $zero
/* AF1D9C 8024013C 12000005 */  beqz      $s0, .L80240154
/* AF1DA0 80240140 0040902D */   daddu    $s2, $v0, $zero
/* AF1DA4 80240144 C640000C */  lwc1      $f0, 0xc($s2)
/* AF1DA8 80240148 AE200074 */  sw        $zero, 0x74($s1)
/* AF1DAC 8024014C AE20007C */  sw        $zero, 0x7c($s1)
/* AF1DB0 80240150 E6200078 */  swc1      $f0, 0x78($s1)
.L80240154:
/* AF1DB4 80240154 8E230074 */  lw        $v1, 0x74($s1)
/* AF1DB8 80240158 10600005 */  beqz      $v1, .L80240170
/* AF1DBC 8024015C 24020001 */   addiu    $v0, $zero, 1
/* AF1DC0 80240160 10620024 */  beq       $v1, $v0, .L802401F4
/* AF1DC4 80240164 00000000 */   nop      
/* AF1DC8 80240168 08090093 */  j         .L8024024C
/* AF1DCC 8024016C 00000000 */   nop      
.L80240170:
/* AF1DD0 80240170 3C013FC9 */  lui       $at, 0x3fc9
/* AF1DD4 80240174 34210FD8 */  ori       $at, $at, 0xfd8
/* AF1DD8 80240178 44810000 */  mtc1      $at, $f0
/* AF1DDC 8024017C C62C007C */  lwc1      $f12, 0x7c($s1)
/* AF1DE0 80240180 46806320 */  cvt.s.w   $f12, $f12
/* AF1DE4 80240184 46006302 */  mul.s     $f12, $f12, $f0
/* AF1DE8 80240188 00000000 */  nop       
/* AF1DEC 8024018C 3C0141F0 */  lui       $at, 0x41f0
/* AF1DF0 80240190 44810000 */  mtc1      $at, $f0
/* AF1DF4 80240194 0C00A874 */  jal       cos_rad
/* AF1DF8 80240198 46006303 */   div.s    $f12, $f12, $f0
/* AF1DFC 8024019C 3C013F80 */  lui       $at, 0x3f80
/* AF1E00 802401A0 44811000 */  mtc1      $at, $f2
/* AF1E04 802401A4 00000000 */  nop       
/* AF1E08 802401A8 46001081 */  sub.s     $f2, $f2, $f0
/* AF1E0C 802401AC 3C0141A0 */  lui       $at, 0x41a0
/* AF1E10 802401B0 44810000 */  mtc1      $at, $f0
/* AF1E14 802401B4 00000000 */  nop       
/* AF1E18 802401B8 46001082 */  mul.s     $f2, $f2, $f0
/* AF1E1C 802401BC 00000000 */  nop       
/* AF1E20 802401C0 C6200078 */  lwc1      $f0, 0x78($s1)
/* AF1E24 802401C4 46020000 */  add.s     $f0, $f0, $f2
/* AF1E28 802401C8 E640000C */  swc1      $f0, 0xc($s2)
/* AF1E2C 802401CC 8E23007C */  lw        $v1, 0x7c($s1)
/* AF1E30 802401D0 2402001E */  addiu     $v0, $zero, 0x1e
/* AF1E34 802401D4 14620005 */  bne       $v1, $v0, .L802401EC
/* AF1E38 802401D8 24620001 */   addiu    $v0, $v1, 1
/* AF1E3C 802401DC 24020001 */  addiu     $v0, $zero, 1
/* AF1E40 802401E0 AE220074 */  sw        $v0, 0x74($s1)
/* AF1E44 802401E4 08090093 */  j         .L8024024C
/* AF1E48 802401E8 AE20007C */   sw       $zero, 0x7c($s1)
.L802401EC:
/* AF1E4C 802401EC 08090093 */  j         .L8024024C
/* AF1E50 802401F0 AE22007C */   sw       $v0, 0x7c($s1)
.L802401F4:
/* AF1E54 802401F4 C62C007C */  lwc1      $f12, 0x7c($s1)
/* AF1E58 802401F8 0C00A8D4 */  jal       cos_deg
/* AF1E5C 802401FC 46806320 */   cvt.s.w  $f12, $f12
/* AF1E60 80240200 3C014040 */  lui       $at, 0x4040
/* AF1E64 80240204 44811000 */  mtc1      $at, $f2
/* AF1E68 80240208 00000000 */  nop       
/* AF1E6C 8024020C 46020002 */  mul.s     $f0, $f0, $f2
/* AF1E70 80240210 00000000 */  nop       
/* AF1E74 80240214 3C014188 */  lui       $at, 0x4188
/* AF1E78 80240218 44812000 */  mtc1      $at, $f4
/* AF1E7C 8024021C C6220078 */  lwc1      $f2, 0x78($s1)
/* AF1E80 80240220 46041080 */  add.s     $f2, $f2, $f4
/* AF1E84 80240224 46001080 */  add.s     $f2, $f2, $f0
/* AF1E88 80240228 E642000C */  swc1      $f2, 0xc($s2)
/* AF1E8C 8024022C 8E22007C */  lw        $v0, 0x7c($s1)
/* AF1E90 80240230 24420009 */  addiu     $v0, $v0, 9
/* AF1E94 80240234 44826000 */  mtc1      $v0, $f12
/* AF1E98 80240238 00000000 */  nop       
/* AF1E9C 8024023C 0C00A6C9 */  jal       clamp_angle
/* AF1EA0 80240240 46806320 */   cvt.s.w  $f12, $f12
/* AF1EA4 80240244 4600018D */  trunc.w.s $f6, $f0
/* AF1EA8 80240248 E626007C */  swc1      $f6, 0x7c($s1)
.L8024024C:
/* AF1EAC 8024024C 8FBF001C */  lw        $ra, 0x1c($sp)
/* AF1EB0 80240250 8FB20018 */  lw        $s2, 0x18($sp)
/* AF1EB4 80240254 8FB10014 */  lw        $s1, 0x14($sp)
/* AF1EB8 80240258 8FB00010 */  lw        $s0, 0x10($sp)
/* AF1EBC 8024025C 0000102D */  daddu     $v0, $zero, $zero
/* AF1EC0 80240260 03E00008 */  jr        $ra
/* AF1EC4 80240264 27BD0020 */   addiu    $sp, $sp, 0x20
