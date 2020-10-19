.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240118_BCED08
/* BCED08 80240118 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BCED0C 8024011C AFB10014 */  sw        $s1, 0x14($sp)
/* BCED10 80240120 0080882D */  daddu     $s1, $a0, $zero
/* BCED14 80240124 AFBF001C */  sw        $ra, 0x1c($sp)
/* BCED18 80240128 AFB20018 */  sw        $s2, 0x18($sp)
/* BCED1C 8024012C AFB00010 */  sw        $s0, 0x10($sp)
/* BCED20 80240130 8E240084 */  lw        $a0, 0x84($s1)
/* BCED24 80240134 0C04C3D6 */  jal       get_item_entity
/* BCED28 80240138 00A0802D */   daddu    $s0, $a1, $zero
/* BCED2C 8024013C 12000005 */  beqz      $s0, .L80240154
/* BCED30 80240140 0040902D */   daddu    $s2, $v0, $zero
/* BCED34 80240144 C640000C */  lwc1      $f0, 0xc($s2)
/* BCED38 80240148 AE200074 */  sw        $zero, 0x74($s1)
/* BCED3C 8024014C AE20007C */  sw        $zero, 0x7c($s1)
/* BCED40 80240150 E6200078 */  swc1      $f0, 0x78($s1)
.L80240154:
/* BCED44 80240154 8E230074 */  lw        $v1, 0x74($s1)
/* BCED48 80240158 10600005 */  beqz      $v1, .L80240170
/* BCED4C 8024015C 24020001 */   addiu    $v0, $zero, 1
/* BCED50 80240160 10620024 */  beq       $v1, $v0, .L802401F4
/* BCED54 80240164 00000000 */   nop      
/* BCED58 80240168 08090093 */  j         .L8024024C
/* BCED5C 8024016C 00000000 */   nop      
.L80240170:
/* BCED60 80240170 3C013FC9 */  lui       $at, 0x3fc9
/* BCED64 80240174 34210FD8 */  ori       $at, $at, 0xfd8
/* BCED68 80240178 44810000 */  mtc1      $at, $f0
/* BCED6C 8024017C C62C007C */  lwc1      $f12, 0x7c($s1)
/* BCED70 80240180 46806320 */  cvt.s.w   $f12, $f12
/* BCED74 80240184 46006302 */  mul.s     $f12, $f12, $f0
/* BCED78 80240188 00000000 */  nop       
/* BCED7C 8024018C 3C0141F0 */  lui       $at, 0x41f0
/* BCED80 80240190 44810000 */  mtc1      $at, $f0
/* BCED84 80240194 0C00A874 */  jal       cos_rad
/* BCED88 80240198 46006303 */   div.s    $f12, $f12, $f0
/* BCED8C 8024019C 3C013F80 */  lui       $at, 0x3f80
/* BCED90 802401A0 44811000 */  mtc1      $at, $f2
/* BCED94 802401A4 00000000 */  nop       
/* BCED98 802401A8 46001081 */  sub.s     $f2, $f2, $f0
/* BCED9C 802401AC 3C0141A0 */  lui       $at, 0x41a0
/* BCEDA0 802401B0 44810000 */  mtc1      $at, $f0
/* BCEDA4 802401B4 00000000 */  nop       
/* BCEDA8 802401B8 46001082 */  mul.s     $f2, $f2, $f0
/* BCEDAC 802401BC 00000000 */  nop       
/* BCEDB0 802401C0 C6200078 */  lwc1      $f0, 0x78($s1)
/* BCEDB4 802401C4 46020000 */  add.s     $f0, $f0, $f2
/* BCEDB8 802401C8 E640000C */  swc1      $f0, 0xc($s2)
/* BCEDBC 802401CC 8E23007C */  lw        $v1, 0x7c($s1)
/* BCEDC0 802401D0 2402001E */  addiu     $v0, $zero, 0x1e
/* BCEDC4 802401D4 14620005 */  bne       $v1, $v0, .L802401EC
/* BCEDC8 802401D8 24620001 */   addiu    $v0, $v1, 1
/* BCEDCC 802401DC 24020001 */  addiu     $v0, $zero, 1
/* BCEDD0 802401E0 AE220074 */  sw        $v0, 0x74($s1)
/* BCEDD4 802401E4 08090093 */  j         .L8024024C
/* BCEDD8 802401E8 AE20007C */   sw       $zero, 0x7c($s1)
.L802401EC:
/* BCEDDC 802401EC 08090093 */  j         .L8024024C
/* BCEDE0 802401F0 AE22007C */   sw       $v0, 0x7c($s1)
.L802401F4:
/* BCEDE4 802401F4 C62C007C */  lwc1      $f12, 0x7c($s1)
/* BCEDE8 802401F8 0C00A8D4 */  jal       cos_deg
/* BCEDEC 802401FC 46806320 */   cvt.s.w  $f12, $f12
/* BCEDF0 80240200 3C014040 */  lui       $at, 0x4040
/* BCEDF4 80240204 44811000 */  mtc1      $at, $f2
/* BCEDF8 80240208 00000000 */  nop       
/* BCEDFC 8024020C 46020002 */  mul.s     $f0, $f0, $f2
/* BCEE00 80240210 00000000 */  nop       
/* BCEE04 80240214 3C014188 */  lui       $at, 0x4188
/* BCEE08 80240218 44812000 */  mtc1      $at, $f4
/* BCEE0C 8024021C C6220078 */  lwc1      $f2, 0x78($s1)
/* BCEE10 80240220 46041080 */  add.s     $f2, $f2, $f4
/* BCEE14 80240224 46001080 */  add.s     $f2, $f2, $f0
/* BCEE18 80240228 E642000C */  swc1      $f2, 0xc($s2)
/* BCEE1C 8024022C 8E22007C */  lw        $v0, 0x7c($s1)
/* BCEE20 80240230 24420009 */  addiu     $v0, $v0, 9
/* BCEE24 80240234 44826000 */  mtc1      $v0, $f12
/* BCEE28 80240238 00000000 */  nop       
/* BCEE2C 8024023C 0C00A6C9 */  jal       clamp_angle
/* BCEE30 80240240 46806320 */   cvt.s.w  $f12, $f12
/* BCEE34 80240244 4600018D */  trunc.w.s $f6, $f0
/* BCEE38 80240248 E626007C */  swc1      $f6, 0x7c($s1)
.L8024024C:
/* BCEE3C 8024024C 8FBF001C */  lw        $ra, 0x1c($sp)
/* BCEE40 80240250 8FB20018 */  lw        $s2, 0x18($sp)
/* BCEE44 80240254 8FB10014 */  lw        $s1, 0x14($sp)
/* BCEE48 80240258 8FB00010 */  lw        $s0, 0x10($sp)
/* BCEE4C 8024025C 0000102D */  daddu     $v0, $zero, $zero
/* BCEE50 80240260 03E00008 */  jr        $ra
/* BCEE54 80240264 27BD0020 */   addiu    $sp, $sp, 0x20
