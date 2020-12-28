.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel func_80218000_6DBDA0
/* 6DBDA0 80218000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6DBDA4 80218004 AFBF0018 */  sw        $ra, 0x18($sp)
/* 6DBDA8 80218008 AFB10014 */  sw        $s1, 0x14($sp)
/* 6DBDAC 8021800C AFB00010 */  sw        $s0, 0x10($sp)
/* 6DBDB0 80218010 0C09A75B */  jal       get_actor
/* 6DBDB4 80218014 8C840148 */   lw       $a0, 0x148($a0)
/* 6DBDB8 80218018 3C108022 */  lui       $s0, %hi(D_802187E4)
/* 6DBDBC 8021801C 261087E4 */  addiu     $s0, $s0, %lo(D_802187E4)
/* 6DBDC0 80218020 8E030000 */  lw        $v1, ($s0)
/* 6DBDC4 80218024 0040882D */  daddu     $s1, $v0, $zero
/* 6DBDC8 80218028 24630009 */  addiu     $v1, $v1, 9
/* 6DBDCC 8021802C 44836000 */  mtc1      $v1, $f12
/* 6DBDD0 80218030 00000000 */  nop       
/* 6DBDD4 80218034 46806320 */  cvt.s.w   $f12, $f12
/* 6DBDD8 80218038 0C00A6C9 */  jal       clamp_angle
/* 6DBDDC 8021803C AE030000 */   sw       $v1, ($s0)
/* 6DBDE0 80218040 4600010D */  trunc.w.s $f4, $f0
/* 6DBDE4 80218044 44022000 */  mfc1      $v0, $f4
/* 6DBDE8 80218048 3C0140C9 */  lui       $at, 0x40c9
/* 6DBDEC 8021804C 34210FD0 */  ori       $at, $at, 0xfd0
/* 6DBDF0 80218050 44810000 */  mtc1      $at, $f0
/* 6DBDF4 80218054 44826000 */  mtc1      $v0, $f12
/* 6DBDF8 80218058 00000000 */  nop       
/* 6DBDFC 8021805C 46806320 */  cvt.s.w   $f12, $f12
/* 6DBE00 80218060 46006302 */  mul.s     $f12, $f12, $f0
/* 6DBE04 80218064 00000000 */  nop       
/* 6DBE08 80218068 3C0143B4 */  lui       $at, 0x43b4
/* 6DBE0C 8021806C 44810000 */  mtc1      $at, $f0
/* 6DBE10 80218070 AE020000 */  sw        $v0, ($s0)
/* 6DBE14 80218074 0C00A85B */  jal       sin_rad
/* 6DBE18 80218078 46006303 */   div.s    $f12, $f12, $f0
/* 6DBE1C 8021807C 3C014040 */  lui       $at, 0x4040
/* 6DBE20 80218080 44811000 */  mtc1      $at, $f2
/* 6DBE24 80218084 00000000 */  nop       
/* 6DBE28 80218088 46020002 */  mul.s     $f0, $f0, $f2
/* 6DBE2C 8021808C 00000000 */  nop       
/* 6DBE30 80218090 4600010D */  trunc.w.s $f4, $f0
/* 6DBE34 80218094 44032000 */  mfc1      $v1, $f4
/* 6DBE38 80218098 00000000 */  nop       
/* 6DBE3C 8021809C A223019A */  sb        $v1, 0x19a($s1)
/* 6DBE40 802180A0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 6DBE44 802180A4 8FB10014 */  lw        $s1, 0x14($sp)
/* 6DBE48 802180A8 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DBE4C 802180AC 24020002 */  addiu     $v0, $zero, 2
/* 6DBE50 802180B0 03E00008 */  jr        $ra
/* 6DBE54 802180B4 27BD0020 */   addiu    $sp, $sp, 0x20

glabel func_802180B8_6DBE58
/* 6DBE58 802180B8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 6DBE5C 802180BC AFB10014 */  sw        $s1, 0x14($sp)
/* 6DBE60 802180C0 0080882D */  daddu     $s1, $a0, $zero
/* 6DBE64 802180C4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 6DBE68 802180C8 AFB20018 */  sw        $s2, 0x18($sp)
/* 6DBE6C 802180CC AFB00010 */  sw        $s0, 0x10($sp)
/* 6DBE70 802180D0 F7B80030 */  sdc1      $f24, 0x30($sp)
/* 6DBE74 802180D4 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 6DBE78 802180D8 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 6DBE7C 802180DC 8E30000C */  lw        $s0, 0xc($s1)
/* 6DBE80 802180E0 8E050000 */  lw        $a1, ($s0)
/* 6DBE84 802180E4 0C0B1EAF */  jal       get_variable
/* 6DBE88 802180E8 26100004 */   addiu    $s0, $s0, 4
/* 6DBE8C 802180EC 8E050000 */  lw        $a1, ($s0)
/* 6DBE90 802180F0 26100004 */  addiu     $s0, $s0, 4
/* 6DBE94 802180F4 0220202D */  daddu     $a0, $s1, $zero
/* 6DBE98 802180F8 0C0B1EAF */  jal       get_variable
/* 6DBE9C 802180FC 0040902D */   daddu    $s2, $v0, $zero
/* 6DBEA0 80218100 8E050000 */  lw        $a1, ($s0)
/* 6DBEA4 80218104 26100004 */  addiu     $s0, $s0, 4
/* 6DBEA8 80218108 4482C000 */  mtc1      $v0, $f24
/* 6DBEAC 8021810C 00000000 */  nop       
/* 6DBEB0 80218110 4680C620 */  cvt.s.w   $f24, $f24
/* 6DBEB4 80218114 0C0B1EAF */  jal       get_variable
/* 6DBEB8 80218118 0220202D */   daddu    $a0, $s1, $zero
/* 6DBEBC 8021811C 8E050000 */  lw        $a1, ($s0)
/* 6DBEC0 80218120 4482B000 */  mtc1      $v0, $f22
/* 6DBEC4 80218124 00000000 */  nop       
/* 6DBEC8 80218128 4680B5A0 */  cvt.s.w   $f22, $f22
/* 6DBECC 8021812C 0C0B1EAF */  jal       get_variable
/* 6DBED0 80218130 0220202D */   daddu    $a0, $s1, $zero
/* 6DBED4 80218134 4482A000 */  mtc1      $v0, $f20
/* 6DBED8 80218138 00000000 */  nop       
/* 6DBEDC 8021813C 4680A520 */  cvt.s.w   $f20, $f20
/* 6DBEE0 80218140 0C04417A */  jal       get_entity_by_index
/* 6DBEE4 80218144 0240202D */   daddu    $a0, $s2, $zero
/* 6DBEE8 80218148 0040182D */  daddu     $v1, $v0, $zero
/* 6DBEEC 8021814C E4780048 */  swc1      $f24, 0x48($v1)
/* 6DBEF0 80218150 E476004C */  swc1      $f22, 0x4c($v1)
/* 6DBEF4 80218154 E4740050 */  swc1      $f20, 0x50($v1)
/* 6DBEF8 80218158 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6DBEFC 8021815C 8FB20018 */  lw        $s2, 0x18($sp)
/* 6DBF00 80218160 8FB10014 */  lw        $s1, 0x14($sp)
/* 6DBF04 80218164 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DBF08 80218168 D7B80030 */  ldc1      $f24, 0x30($sp)
/* 6DBF0C 8021816C D7B60028 */  ldc1      $f22, 0x28($sp)
/* 6DBF10 80218170 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 6DBF14 80218174 24020002 */  addiu     $v0, $zero, 2
/* 6DBF18 80218178 03E00008 */  jr        $ra
/* 6DBF1C 8021817C 27BD0038 */   addiu    $sp, $sp, 0x38

glabel func_80218180_6DBF20
/* 6DBF20 80218180 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6DBF24 80218184 AFB20018 */  sw        $s2, 0x18($sp)
/* 6DBF28 80218188 0080902D */  daddu     $s2, $a0, $zero
/* 6DBF2C 8021818C AFBF001C */  sw        $ra, 0x1c($sp)
/* 6DBF30 80218190 AFB10014 */  sw        $s1, 0x14($sp)
/* 6DBF34 80218194 AFB00010 */  sw        $s0, 0x10($sp)
/* 6DBF38 80218198 8E50000C */  lw        $s0, 0xc($s2)
/* 6DBF3C 8021819C 8E050000 */  lw        $a1, ($s0)
/* 6DBF40 802181A0 0C0B1EAF */  jal       get_variable
/* 6DBF44 802181A4 26100004 */   addiu    $s0, $s0, 4
/* 6DBF48 802181A8 0C04417A */  jal       get_entity_by_index
/* 6DBF4C 802181AC 0040202D */   daddu    $a0, $v0, $zero
/* 6DBF50 802181B0 8E050000 */  lw        $a1, ($s0)
/* 6DBF54 802181B4 26100004 */  addiu     $s0, $s0, 4
/* 6DBF58 802181B8 0040882D */  daddu     $s1, $v0, $zero
/* 6DBF5C 802181BC C6200048 */  lwc1      $f0, 0x48($s1)
/* 6DBF60 802181C0 4600008D */  trunc.w.s $f2, $f0
/* 6DBF64 802181C4 44061000 */  mfc1      $a2, $f2
/* 6DBF68 802181C8 0C0B2026 */  jal       set_variable
/* 6DBF6C 802181CC 0240202D */   daddu    $a0, $s2, $zero
/* 6DBF70 802181D0 8E050000 */  lw        $a1, ($s0)
/* 6DBF74 802181D4 26100004 */  addiu     $s0, $s0, 4
/* 6DBF78 802181D8 C620004C */  lwc1      $f0, 0x4c($s1)
/* 6DBF7C 802181DC 4600008D */  trunc.w.s $f2, $f0
/* 6DBF80 802181E0 44061000 */  mfc1      $a2, $f2
/* 6DBF84 802181E4 0C0B2026 */  jal       set_variable
/* 6DBF88 802181E8 0240202D */   daddu    $a0, $s2, $zero
/* 6DBF8C 802181EC C6200050 */  lwc1      $f0, 0x50($s1)
/* 6DBF90 802181F0 8E050000 */  lw        $a1, ($s0)
/* 6DBF94 802181F4 4600008D */  trunc.w.s $f2, $f0
/* 6DBF98 802181F8 44061000 */  mfc1      $a2, $f2
/* 6DBF9C 802181FC 0C0B2026 */  jal       set_variable
/* 6DBFA0 80218200 0240202D */   daddu    $a0, $s2, $zero
/* 6DBFA4 80218204 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6DBFA8 80218208 8FB20018 */  lw        $s2, 0x18($sp)
/* 6DBFAC 8021820C 8FB10014 */  lw        $s1, 0x14($sp)
/* 6DBFB0 80218210 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DBFB4 80218214 24020002 */  addiu     $v0, $zero, 2
/* 6DBFB8 80218218 03E00008 */  jr        $ra
/* 6DBFBC 8021821C 27BD0020 */   addiu    $sp, $sp, 0x20

glabel func_80218220_6DBFC0
/* 6DBFC0 80218220 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6DBFC4 80218224 AFB20018 */  sw        $s2, 0x18($sp)
/* 6DBFC8 80218228 0080902D */  daddu     $s2, $a0, $zero
/* 6DBFCC 8021822C AFBF001C */  sw        $ra, 0x1c($sp)
/* 6DBFD0 80218230 AFB10014 */  sw        $s1, 0x14($sp)
/* 6DBFD4 80218234 AFB00010 */  sw        $s0, 0x10($sp)
/* 6DBFD8 80218238 8E4400A8 */  lw        $a0, 0xa8($s2)
/* 6DBFDC 8021823C 0C04417A */  jal       get_entity_by_index
/* 6DBFE0 80218240 00A0802D */   daddu    $s0, $a1, $zero
/* 6DBFE4 80218244 12000004 */  beqz      $s0, .L80218258
/* 6DBFE8 80218248 0040882D */   daddu    $s1, $v0, $zero
/* 6DBFEC 8021824C 2402003C */  addiu     $v0, $zero, 0x3c
/* 6DBFF0 80218250 AE400070 */  sw        $zero, 0x70($s2)
/* 6DBFF4 80218254 AE420074 */  sw        $v0, 0x74($s2)
.L80218258:
/* 6DBFF8 80218258 2403003C */  addiu     $v1, $zero, 0x3c
/* 6DBFFC 8021825C 8E420074 */  lw        $v0, 0x74($s2)
/* 6DC000 80218260 3C014270 */  lui       $at, 0x4270
/* 6DC004 80218264 44811000 */  mtc1      $at, $f2
/* 6DC008 80218268 00621023 */  subu      $v0, $v1, $v0
/* 6DC00C 8021826C 44820000 */  mtc1      $v0, $f0
/* 6DC010 80218270 00000000 */  nop       
/* 6DC014 80218274 46800020 */  cvt.s.w   $f0, $f0
/* 6DC018 80218278 46020003 */  div.s     $f0, $f0, $f2
/* 6DC01C 8021827C E6200054 */  swc1      $f0, 0x54($s1)
/* 6DC020 80218280 8E420074 */  lw        $v0, 0x74($s2)
/* 6DC024 80218284 3C014049 */  lui       $at, 0x4049
/* 6DC028 80218288 34210FD8 */  ori       $at, $at, 0xfd8
/* 6DC02C 8021828C 44816000 */  mtc1      $at, $f12
/* 6DC030 80218290 00621023 */  subu      $v0, $v1, $v0
/* 6DC034 80218294 44820000 */  mtc1      $v0, $f0
/* 6DC038 80218298 00000000 */  nop       
/* 6DC03C 8021829C 46800020 */  cvt.s.w   $f0, $f0
/* 6DC040 802182A0 46020003 */  div.s     $f0, $f0, $f2
/* 6DC044 802182A4 E6200058 */  swc1      $f0, 0x58($s1)
/* 6DC048 802182A8 8E420074 */  lw        $v0, 0x74($s2)
/* 6DC04C 802182AC 460C0302 */  mul.s     $f12, $f0, $f12
/* 6DC050 802182B0 00000000 */  nop       
/* 6DC054 802182B4 00621823 */  subu      $v1, $v1, $v0
/* 6DC058 802182B8 44830000 */  mtc1      $v1, $f0
/* 6DC05C 802182BC 00000000 */  nop       
/* 6DC060 802182C0 46800020 */  cvt.s.w   $f0, $f0
/* 6DC064 802182C4 46020003 */  div.s     $f0, $f0, $f2
/* 6DC068 802182C8 0C00A874 */  jal       cos_rad
/* 6DC06C 802182CC E620005C */   swc1     $f0, 0x5c($s1)
/* 6DC070 802182D0 3C013F80 */  lui       $at, 0x3f80
/* 6DC074 802182D4 44811000 */  mtc1      $at, $f2
/* 6DC078 802182D8 00000000 */  nop       
/* 6DC07C 802182DC 46001081 */  sub.s     $f2, $f2, $f0
/* 6DC080 802182E0 3C014487 */  lui       $at, 0x4487
/* 6DC084 802182E4 44810000 */  mtc1      $at, $f0
/* 6DC088 802182E8 00000000 */  nop       
/* 6DC08C 802182EC 46001082 */  mul.s     $f2, $f2, $f0
/* 6DC090 802182F0 00000000 */  nop       
/* 6DC094 802182F4 3C013F00 */  lui       $at, 0x3f00
/* 6DC098 802182F8 44810000 */  mtc1      $at, $f0
/* 6DC09C 802182FC 00000000 */  nop       
/* 6DC0A0 80218300 46001082 */  mul.s     $f2, $f2, $f0
/* 6DC0A4 80218304 00000000 */  nop       
/* 6DC0A8 80218308 E6220064 */  swc1      $f2, 0x64($s1)
/* 6DC0AC 8021830C 8E430074 */  lw        $v1, 0x74($s2)
/* 6DC0B0 80218310 2463FFFF */  addiu     $v1, $v1, -1
/* 6DC0B4 80218314 00031027 */  nor       $v0, $zero, $v1
/* 6DC0B8 80218318 2C420001 */  sltiu     $v0, $v0, 1
/* 6DC0BC 8021831C AE430074 */  sw        $v1, 0x74($s2)
/* 6DC0C0 80218320 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6DC0C4 80218324 8FB20018 */  lw        $s2, 0x18($sp)
/* 6DC0C8 80218328 8FB10014 */  lw        $s1, 0x14($sp)
/* 6DC0CC 8021832C 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DC0D0 80218330 00021040 */  sll       $v0, $v0, 1
/* 6DC0D4 80218334 03E00008 */  jr        $ra
/* 6DC0D8 80218338 27BD0020 */   addiu    $sp, $sp, 0x20

glabel func_8021833C_6DC0DC
/* 6DC0DC 8021833C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6DC0E0 80218340 AFB00010 */  sw        $s0, 0x10($sp)
/* 6DC0E4 80218344 0080802D */  daddu     $s0, $a0, $zero
/* 6DC0E8 80218348 10A00010 */  beqz      $a1, .L8021838C
/* 6DC0EC 8021834C AFBF0014 */   sw       $ra, 0x14($sp)
/* 6DC0F0 80218350 24040001 */  addiu     $a0, $zero, 1
/* 6DC0F4 80218354 0000282D */  daddu     $a1, $zero, $zero
/* 6DC0F8 80218358 00A0302D */  daddu     $a2, $a1, $zero
/* 6DC0FC 8021835C 00A0382D */  daddu     $a3, $a1, $zero
/* 6DC100 80218360 24020014 */  addiu     $v0, $zero, 0x14
/* 6DC104 80218364 0C04DF93 */  jal       func_80137E4C
/* 6DC108 80218368 AE020070 */   sw       $v0, 0x70($s0)
/* 6DC10C 8021836C 24040001 */  addiu     $a0, $zero, 1
/* 6DC110 80218370 0080282D */  daddu     $a1, $a0, $zero
/* 6DC114 80218374 24060140 */  addiu     $a2, $zero, 0x140
/* 6DC118 80218378 0C04DF93 */  jal       func_80137E4C
/* 6DC11C 8021837C 240700F0 */   addiu    $a3, $zero, 0xf0
/* 6DC120 80218380 3C054316 */  lui       $a1, 0x4316
/* 6DC124 80218384 0C04DF69 */  jal       func_80137DA4
/* 6DC128 80218388 2404000C */   addiu    $a0, $zero, 0xc
.L8021838C:
/* 6DC12C 8021838C 8E020070 */  lw        $v0, 0x70($s0)
/* 6DC130 80218390 14400010 */  bnez      $v0, .L802183D4
/* 6DC134 80218394 2442FFFF */   addiu    $v0, $v0, -1
/* 6DC138 80218398 24040001 */  addiu     $a0, $zero, 1
/* 6DC13C 8021839C 0000282D */  daddu     $a1, $zero, $zero
/* 6DC140 802183A0 00A0302D */  daddu     $a2, $a1, $zero
/* 6DC144 802183A4 0C04DF93 */  jal       func_80137E4C
/* 6DC148 802183A8 00A0382D */   daddu    $a3, $a1, $zero
/* 6DC14C 802183AC 24040001 */  addiu     $a0, $zero, 1
/* 6DC150 802183B0 0080282D */  daddu     $a1, $a0, $zero
/* 6DC154 802183B4 24060140 */  addiu     $a2, $zero, 0x140
/* 6DC158 802183B8 0C04DF93 */  jal       func_80137E4C
/* 6DC15C 802183BC 240700F0 */   addiu    $a3, $zero, 0xf0
/* 6DC160 802183C0 3C05BF80 */  lui       $a1, 0xbf80
/* 6DC164 802183C4 0C04DF69 */  jal       func_80137DA4
/* 6DC168 802183C8 240400FF */   addiu    $a0, $zero, 0xff
/* 6DC16C 802183CC 080860F7 */  j         .L802183DC
/* 6DC170 802183D0 24020002 */   addiu    $v0, $zero, 2
.L802183D4:
/* 6DC174 802183D4 AE020070 */  sw        $v0, 0x70($s0)
/* 6DC178 802183D8 0000102D */  daddu     $v0, $zero, $zero
.L802183DC:
/* 6DC17C 802183DC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6DC180 802183E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DC184 802183E4 03E00008 */  jr        $ra
/* 6DC188 802183E8 27BD0018 */   addiu    $sp, $sp, 0x18

glabel func_802183EC_6DC18C
/* 6DC18C 802183EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6DC190 802183F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 6DC194 802183F4 0080802D */  daddu     $s0, $a0, $zero
/* 6DC198 802183F8 10A00010 */  beqz      $a1, .L8021843C
/* 6DC19C 802183FC AFBF0014 */   sw       $ra, 0x14($sp)
/* 6DC1A0 80218400 24040001 */  addiu     $a0, $zero, 1
/* 6DC1A4 80218404 0000282D */  daddu     $a1, $zero, $zero
/* 6DC1A8 80218408 00A0302D */  daddu     $a2, $a1, $zero
/* 6DC1AC 8021840C 00A0382D */  daddu     $a3, $a1, $zero
/* 6DC1B0 80218410 2402001E */  addiu     $v0, $zero, 0x1e
/* 6DC1B4 80218414 0C04DF93 */  jal       func_80137E4C
/* 6DC1B8 80218418 AE020070 */   sw       $v0, 0x70($s0)
/* 6DC1BC 8021841C 24040001 */  addiu     $a0, $zero, 1
/* 6DC1C0 80218420 0080282D */  daddu     $a1, $a0, $zero
/* 6DC1C4 80218424 24060140 */  addiu     $a2, $zero, 0x140
/* 6DC1C8 80218428 0C04DF93 */  jal       func_80137E4C
/* 6DC1CC 8021842C 240700F0 */   addiu    $a3, $zero, 0xf0
/* 6DC1D0 80218430 3C054316 */  lui       $a1, 0x4316
/* 6DC1D4 80218434 0C04DF69 */  jal       func_80137DA4
/* 6DC1D8 80218438 2404000C */   addiu    $a0, $zero, 0xc
.L8021843C:
/* 6DC1DC 8021843C 8E020070 */  lw        $v0, 0x70($s0)
/* 6DC1E0 80218440 14400010 */  bnez      $v0, .L80218484
/* 6DC1E4 80218444 2442FFFF */   addiu    $v0, $v0, -1
/* 6DC1E8 80218448 24040001 */  addiu     $a0, $zero, 1
/* 6DC1EC 8021844C 0000282D */  daddu     $a1, $zero, $zero
/* 6DC1F0 80218450 00A0302D */  daddu     $a2, $a1, $zero
/* 6DC1F4 80218454 0C04DF93 */  jal       func_80137E4C
/* 6DC1F8 80218458 00A0382D */   daddu    $a3, $a1, $zero
/* 6DC1FC 8021845C 24040001 */  addiu     $a0, $zero, 1
/* 6DC200 80218460 0080282D */  daddu     $a1, $a0, $zero
/* 6DC204 80218464 24060140 */  addiu     $a2, $zero, 0x140
/* 6DC208 80218468 0C04DF93 */  jal       func_80137E4C
/* 6DC20C 8021846C 240700F0 */   addiu    $a3, $zero, 0xf0
/* 6DC210 80218470 3C05BF80 */  lui       $a1, 0xbf80
/* 6DC214 80218474 0C04DF69 */  jal       func_80137DA4
/* 6DC218 80218478 240400FF */   addiu    $a0, $zero, 0xff
/* 6DC21C 8021847C 08086123 */  j         .L8021848C
/* 6DC220 80218480 24020002 */   addiu    $v0, $zero, 2
.L80218484:
/* 6DC224 80218484 AE020070 */  sw        $v0, 0x70($s0)
/* 6DC228 80218488 0000102D */  daddu     $v0, $zero, $zero
.L8021848C:
/* 6DC22C 8021848C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6DC230 80218490 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DC234 80218494 03E00008 */  jr        $ra
/* 6DC238 80218498 27BD0018 */   addiu    $sp, $sp, 0x18

glabel func_8021849C_6DC23C
/* 6DC23C 8021849C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6DC240 802184A0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 6DC244 802184A4 AFB20018 */  sw        $s2, 0x18($sp)
/* 6DC248 802184A8 AFB10014 */  sw        $s1, 0x14($sp)
/* 6DC24C 802184AC AFB00010 */  sw        $s0, 0x10($sp)
/* 6DC250 802184B0 8C9000A8 */  lw        $s0, 0xa8($a0)
/* 6DC254 802184B4 0C04417A */  jal       get_entity_by_index
/* 6DC258 802184B8 0200202D */   daddu    $a0, $s0, $zero
/* 6DC25C 802184BC 0040882D */  daddu     $s1, $v0, $zero
/* 6DC260 802184C0 3C128016 */  lui       $s2, %hi(gCollisionStatus)
/* 6DC264 802184C4 2652A550 */  addiu     $s2, $s2, %lo(gCollisionStatus)
/* 6DC268 802184C8 36104000 */  ori       $s0, $s0, 0x4000
/* 6DC26C 802184CC 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* 6DC270 802184D0 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* 6DC274 802184D4 A2200007 */  sb        $zero, 7($s1)
/* 6DC278 802184D8 A6500014 */  sh        $s0, 0x14($s2)
/* 6DC27C 802184DC 8C820000 */  lw        $v0, ($a0)
/* 6DC280 802184E0 3C030100 */  lui       $v1, 0x100
/* 6DC284 802184E4 00431025 */  or        $v0, $v0, $v1
/* 6DC288 802184E8 AC820000 */  sw        $v0, ($a0)
/* 6DC28C 802184EC 24020040 */  addiu     $v0, $zero, 0x40
/* 6DC290 802184F0 A2220006 */  sb        $v0, 6($s1)
/* 6DC294 802184F4 24020012 */  addiu     $v0, $zero, 0x12
/* 6DC298 802184F8 A08200B4 */  sb        $v0, 0xb4($a0)
/* 6DC29C 802184FC 8E220038 */  lw        $v0, 0x38($s1)
/* 6DC2A0 80218500 8C420014 */  lw        $v0, 0x14($v0)
/* 6DC2A4 80218504 0040F809 */  jalr      $v0
/* 6DC2A8 80218508 0220202D */   daddu    $a0, $s1, $zero
/* 6DC2AC 8021850C 2403000A */  addiu     $v1, $zero, 0xa
/* 6DC2B0 80218510 A2230007 */  sb        $v1, 7($s1)
/* 6DC2B4 80218514 8E230000 */  lw        $v1, ($s1)
/* 6DC2B8 80218518 3C040001 */  lui       $a0, 1
/* 6DC2BC 8021851C 00641825 */  or        $v1, $v1, $a0
/* 6DC2C0 80218520 AE230000 */  sw        $v1, ($s1)
/* 6DC2C4 80218524 2403FFFF */  addiu     $v1, $zero, -1
/* 6DC2C8 80218528 A6430014 */  sh        $v1, 0x14($s2)
/* 6DC2CC 8021852C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6DC2D0 80218530 8FB20018 */  lw        $s2, 0x18($sp)
/* 6DC2D4 80218534 8FB10014 */  lw        $s1, 0x14($sp)
/* 6DC2D8 80218538 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DC2DC 8021853C 24020002 */  addiu     $v0, $zero, 2
/* 6DC2E0 80218540 03E00008 */  jr        $ra
/* 6DC2E4 80218544 27BD0020 */   addiu    $sp, $sp, 0x20
/* 6DC2E8 80218548 00000000 */  nop       
/* 6DC2EC 8021854C 00000000 */  nop       

glabel func_80218550_6DC2F0
/* 6DC2F0 80218550 8C8400C0 */  lw        $a0, 0xc0($a0)
/* 6DC2F4 80218554 8C83000C */  lw        $v1, 0xc($a0)
/* 6DC2F8 80218558 24020055 */  addiu     $v0, $zero, 0x55
/* 6DC2FC 8021855C AC620030 */  sw        $v0, 0x30($v1)
/* 6DC300 80218560 8C83000C */  lw        $v1, 0xc($a0)
/* 6DC304 80218564 2402002A */  addiu     $v0, $zero, 0x2a
/* 6DC308 80218568 AC620034 */  sw        $v0, 0x34($v1)
/* 6DC30C 8021856C 8C82000C */  lw        $v0, 0xc($a0)
/* 6DC310 80218570 240300FF */  addiu     $v1, $zero, 0xff
/* 6DC314 80218574 AC430038 */  sw        $v1, 0x38($v0)
/* 6DC318 80218578 8C82000C */  lw        $v0, 0xc($a0)
/* 6DC31C 8021857C AC430040 */  sw        $v1, 0x40($v0)
/* 6DC320 80218580 8C83000C */  lw        $v1, 0xc($a0)
/* 6DC324 80218584 240200AF */  addiu     $v0, $zero, 0xaf
/* 6DC328 80218588 AC620044 */  sw        $v0, 0x44($v1)
/* 6DC32C 8021858C 8C83000C */  lw        $v1, 0xc($a0)
/* 6DC330 80218590 240200EF */  addiu     $v0, $zero, 0xef
/* 6DC334 80218594 AC620048 */  sw        $v0, 0x48($v1)
/* 6DC338 80218598 03E00008 */  jr        $ra
/* 6DC33C 8021859C 24020002 */   addiu    $v0, $zero, 2

glabel func_802185A0_6DC340
/* 6DC340 802185A0 80218718 */  lb        $at, -0x78e8($at)
/* 6DC344 802185A4 00000006 */  srlv      $zero, $zero, $zero
/* 6DC348 802185A8 0000000A */  movz      $zero, $zero, $zero
/* 6DC34C 802185AC 00000000 */  nop       
/* 6DC350 802185B0 00000000 */  nop       
/* 6DC354 802185B4 00000000 */  nop       
/* 6DC358 802185B8 00000000 */  nop       
/* 6DC35C 802185BC 80219FC0 */  lb        $at, -0x6040($at)
/* 6DC360 802185C0 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC364 802185C4 802185A0 */  lb        $at, -0x7a60($at)
/* 6DC368 802185C8 80219F98 */  lb        $at, -0x6068($at)
/* 6DC36C 802185CC 00000000 */  nop       
/* 6DC370 802185D0 00000000 */  nop       
/* 6DC374 802185D4 00000000 */  nop       
/* 6DC378 802185D8 00000000 */  nop       
/* 6DC37C 802185DC 00000000 */  nop       
/* 6DC380 802185E0 00000000 */  nop       
/* 6DC384 802185E4 80219FE8 */  lb        $at, -0x6018($at)
/* 6DC388 802185E8 80219F98 */  lb        $at, -0x6068($at)
/* 6DC38C 802185EC 00000000 */  nop       
/* 6DC390 802185F0 00000000 */  nop       
/* 6DC394 802185F4 00000000 */  nop       
/* 6DC398 802185F8 00000000 */  nop       
/* 6DC39C 802185FC 00000000 */  nop       
/* 6DC3A0 80218600 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC3A4 80218604 00610005 */  lsa       $zero, $v1, $at, 1
/* 6DC3A8 80218608 00000000 */  nop       
/* 6DC3AC 8021860C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC3B0 80218610 0061000C */  syscall   0x18400
/* 6DC3B4 80218614 00000000 */  nop       
/* 6DC3B8 80218618 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC3BC 8021861C 00000000 */  nop       
/* 6DC3C0 80218620 00000000 */  nop       
/* 6DC3C4 80218624 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC3C8 80218628 00000000 */  nop       
/* 6DC3CC 8021862C 00000002 */  srl       $zero, $zero, 0
/* 6DC3D0 80218630 00000000 */  nop       
/* 6DC3D4 80218634 00000006 */  srlv      $zero, $zero, $zero
/* 6DC3D8 80218638 00000000 */  nop       
/* 6DC3DC 8021863C 00000009 */  jr        $zero
/* 6DC3E0 80218640 00000000 */   nop      

glabel func_80218644_6DC3E4
/* 6DC3E4 80218644 00000007 */  srav      $zero, $zero, $zero
/* 6DC3E8 80218648 00000000 */  nop       
/* 6DC3EC 8021864C 00000004 */  sllv      $zero, $zero, $zero
/* 6DC3F0 80218650 00000000 */  nop       
/* 6DC3F4 80218654 00000003 */  sra       $zero, $zero, 0
/* 6DC3F8 80218658 00000000 */  nop       
/* 6DC3FC 8021865C 0000000B */  movn      $zero, $zero, $zero
/* 6DC400 80218660 00000000 */  nop       
/* 6DC404 80218664 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DC408 80218668 00000000 */  nop       
/* 6DC40C 8021866C 0000000A */  movz      $zero, $zero, $zero
/* 6DC410 80218670 00000000 */  nop       
/* 6DC414 80218674 00000008 */  jr        $zero
/* 6DC418 80218678 00000000 */   nop      

glabel func_8021867C_6DC41C
/* 6DC41C 8021867C 0000001F */  ddivu     $zero, $zero, $zero
/* 6DC420 80218680 00000000 */  nop       
/* 6DC424 80218684 00000020 */  add       $zero, $zero, $zero
/* 6DC428 80218688 00000000 */  nop       
/* 6DC42C 8021868C 00000025 */  or        $zero, $zero, $zero
/* 6DC430 80218690 00000000 */  nop       
/* 6DC434 80218694 00000022 */  neg       $zero, $zero
/* 6DC438 80218698 00000000 */  nop       
/* 6DC43C 8021869C 00000024 */  and       $zero, $zero, $zero
/* 6DC440 802186A0 00000000 */  nop       
/* 6DC444 802186A4 00000023 */  negu      $zero, $zero
/* 6DC448 802186A8 00000000 */  nop       
/* 6DC44C 802186AC 00000021 */  addu      $zero, $zero, $zero
/* 6DC450 802186B0 00000000 */  nop       
/* 6DC454 802186B4 00000026 */  xor       $zero, $zero, $zero
/* 6DC458 802186B8 00000000 */  nop       
/* 6DC45C 802186BC 00000027 */  not       $zero, $zero
/* 6DC460 802186C0 00000000 */  nop       
/* 6DC464 802186C4 00000029 */  .byte     0x00, 0x00, 0x00, 0x29
/* 6DC468 802186C8 00000000 */  nop       
/* 6DC46C 802186CC 00000000 */  nop       
/* 6DC470 802186D0 00800000 */  .byte     0x00, 0x80, 0x00, 0x00
/* 6DC474 802186D4 01000000 */  .byte     0x01, 0x00, 0x00, 0x00
/* 6DC478 802186D8 F62300FF */  sdc1      $f3, 0xff($s1)
/* 6DC47C 802186DC 80218600 */  lb        $at, -0x7a00($at)
/* 6DC480 802186E0 80218618 */  lb        $at, -0x79e8($at)
/* 6DC484 802186E4 00000000 */  nop       
/* 6DC488 802186E8 00000000 */  nop       
/* 6DC48C 802186EC 00F80000 */  .byte     0x00, 0xf8, 0x00, 0x00
/* 6DC490 802186F0 00000000 */  nop       
/* 6DC494 802186F4 00120001 */  .byte     0x00, 0x12, 0x00, 0x01
/* 6DC498 802186F8 02000000 */  .byte     0x02, 0x00, 0x00, 0x00
/* 6DC49C 802186FC 000000FF */  dsra32    $zero, $zero, 3
/* 6DC4A0 80218700 8021860C */  lb        $at, -0x79f4($at)
/* 6DC4A4 80218704 80218618 */  lb        $at, -0x79e8($at)
/* 6DC4A8 80218708 00000000 */  nop       
/* 6DC4AC 8021870C 00000000 */  nop       
/* 6DC4B0 80218710 00000000 */  nop       
/* 6DC4B4 80218714 00000000 */  nop       
/* 6DC4B8 80218718 00000200 */  sll       $zero, $zero, 8
/* 6DC4BC 8021871C 0087630A */  .byte     0x00, 0x87, 0x63, 0x0a
/* 6DC4C0 80218720 00020000 */  sll       $zero, $v0, 0
/* 6DC4C4 80218724 802186D0 */  lb        $at, -0x7930($at)
/* 6DC4C8 80218728 80218740 */  lb        $at, -0x78c0($at)
/* 6DC4CC 8021872C 80218624 */  lb        $at, -0x79dc($at)
/* 6DC4D0 80218730 00000000 */  nop       
/* 6DC4D4 80218734 00045000 */  sll       $t2, $a0, 0
/* 6DC4D8 80218738 18200000 */  blez      $at, .L8021873C
.L8021873C:
/* 6DC4DC 8021873C F6140A14 */   sdc1     $f20, 0xa14($s0)
/* 6DC4E0 80218740 00000043 */  sra       $zero, $zero, 1
/* 6DC4E4 80218744 00000003 */  sra       $zero, $zero, 0
/* 6DC4E8 80218748 80278930 */  lb        $a3, -0x76d0($at)
/* 6DC4EC 8021874C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DC4F0 80218750 802189A0 */  lb        $at, -0x7660($at)
/* 6DC4F4 80218754 00000043 */  sra       $zero, $zero, 1
/* 6DC4F8 80218758 00000003 */  sra       $zero, $zero, 0
/* 6DC4FC 8021875C 80278A94 */  lb        $a3, -0x756c($at)
/* 6DC500 80218760 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DC504 80218764 802187E8 */  lb        $at, -0x7818($at)
/* 6DC508 80218768 00000043 */  sra       $zero, $zero, 1
/* 6DC50C 8021876C 00000003 */  sra       $zero, $zero, 0
/* 6DC510 80218770 80278C20 */  lb        $a3, -0x73e0($at)
/* 6DC514 80218774 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DC518 80218778 80218824 */  lb        $at, -0x77dc($at)
/* 6DC51C 8021877C 00000043 */  sra       $zero, $zero, 1
/* 6DC520 80218780 00000003 */  sra       $zero, $zero, 0
/* 6DC524 80218784 80278C94 */  lb        $a3, -0x736c($at)
/* 6DC528 80218788 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DC52C 8021878C 80219334 */  lb        $at, -0x6ccc($at)
/* 6DC530 80218790 00000043 */  sra       $zero, $zero, 1
/* 6DC534 80218794 00000003 */  sra       $zero, $zero, 0
/* 6DC538 80218798 8026CDCC */  lb        $a2, -0x3234($at)
/* 6DC53C 8021879C 02000000 */  .byte     0x02, 0x00, 0x00, 0x00
/* 6DC540 802187A0 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC544 802187A4 00000043 */  sra       $zero, $zero, 1
/* 6DC548 802187A8 00000004 */  sllv      $zero, $zero, $zero
/* 6DC54C 802187AC 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6DC550 802187B0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DC554 802187B4 00000000 */  nop       
/* 6DC558 802187B8 00000000 */  nop       
/* 6DC55C 802187BC 00000043 */  sra       $zero, $zero, 1
/* 6DC560 802187C0 00000004 */  sllv      $zero, $zero, $zero
/* 6DC564 802187C4 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6DC568 802187C8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DC56C 802187CC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC570 802187D0 00000000 */  nop       
/* 6DC574 802187D4 00000002 */  srl       $zero, $zero, 0
/* 6DC578 802187D8 00000000 */  nop       
/* 6DC57C 802187DC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC580 802187E0 00000000 */  nop       
/* 6DC584 802187E4 00000000 */  nop       
/* 6DC588 802187E8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DC58C 802187EC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC590 802187F0 00000000 */  nop       
/* 6DC594 802187F4 00000043 */  sra       $zero, $zero, 1
/* 6DC598 802187F8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC59C 802187FC 80218000 */  lb        $at, -0x8000($at)
/* 6DC5A0 80218800 00000008 */  jr        $zero
/* 6DC5A4 80218804 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218808_6DC5A8
/* 6DC5A8 80218808 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC5AC 8021880C 00000006 */  srlv      $zero, $zero, $zero
/* 6DC5B0 80218810 00000000 */  nop       
/* 6DC5B4 80218814 00000002 */  srl       $zero, $zero, 0
/* 6DC5B8 80218818 00000000 */  nop       
/* 6DC5BC 8021881C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC5C0 80218820 00000000 */  nop       
/* 6DC5C4 80218824 00000043 */  sra       $zero, $zero, 1
/* 6DC5C8 80218828 00000003 */  sra       $zero, $zero, 0
/* 6DC5CC 8021882C 8026F0EC */  lb        $a2, -0xf14($at)
/* 6DC5D0 80218830 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DC5D4 80218834 00000000 */  nop       
/* 6DC5D8 80218838 00000043 */  sra       $zero, $zero, 1
/* 6DC5DC 8021883C 00000003 */  sra       $zero, $zero, 0
/* 6DC5E0 80218840 8027C4E0 */  lb        $a3, -0x3b20($at)
/* 6DC5E4 80218844 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DC5E8 80218848 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DC5EC 8021884C 00000014 */  dsllv     $zero, $zero, $zero
/* 6DC5F0 80218850 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC5F4 80218854 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DC5F8 80218858 00000016 */  dsrlv     $zero, $zero, $zero
/* 6DC5FC 8021885C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC600 80218860 00000038 */  dsll      $zero, $zero, 0
/* 6DC604 80218864 0000001D */  dmultu    $zero, $zero
/* 6DC608 80218868 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC60C 8021886C 00000009 */  jr        $zero
/* 6DC610 80218870 0000001D */   dmultu   $zero, $zero

glabel func_80218874_6DC614
/* 6DC614 80218874 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC618 80218878 0000000A */  movz      $zero, $zero, $zero
/* 6DC61C 8021887C 00000025 */  or        $zero, $zero, $zero
/* 6DC620 80218880 00000002 */  srl       $zero, $zero, 0
/* 6DC624 80218884 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DC628 80218888 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC62C 8021888C 00000025 */  or        $zero, $zero, $zero
/* 6DC630 80218890 00000002 */  srl       $zero, $zero, 0
/* 6DC634 80218894 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DC638 80218898 0061000D */  break     0x61
/* 6DC63C 8021889C 00000046 */   rotrv    $zero, $zero, $zero
/* 6DC640 802188A0 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC644 802188A4 80299044 */  lb        $t1, -0x6fbc($at)
/* 6DC648 802188A8 00000046 */  rotrv     $zero, $zero, $zero
/* 6DC64C 802188AC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC650 802188B0 802195B8 */  lb        $at, -0x6a48($at)
/* 6DC654 802188B4 00000020 */  add       $zero, $zero, $zero
/* 6DC658 802188B8 00000000 */  nop       
/* 6DC65C 802188BC 0000001D */  dmultu    $zero, $zero
/* 6DC660 802188C0 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC664 802188C4 00000017 */  dsrav     $zero, $zero, $zero
/* 6DC668 802188C8 0000001D */  dmultu    $zero, $zero
/* 6DC66C 802188CC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC670 802188D0 00000019 */  multu     $zero, $zero
/* 6DC674 802188D4 00000025 */  or        $zero, $zero, $zero
/* 6DC678 802188D8 00000002 */  srl       $zero, $zero, 0
/* 6DC67C 802188DC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DC680 802188E0 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC684 802188E4 00000025 */  or        $zero, $zero, $zero
/* 6DC688 802188E8 00000002 */  srl       $zero, $zero, 0
/* 6DC68C 802188EC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DC690 802188F0 00610005 */  lsa       $zero, $v1, $at, 1
/* 6DC694 802188F4 00000046 */  rotrv     $zero, $zero, $zero
/* 6DC698 802188F8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC69C 802188FC 8029AC70 */  lb        $t1, -0x5390($at)
/* 6DC6A0 80218900 00000046 */  rotrv     $zero, $zero, $zero
/* 6DC6A4 80218904 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC6A8 80218908 802195B8 */  lb        $at, -0x6a48($at)
/* 6DC6AC 8021890C 00000020 */  add       $zero, $zero, $zero
/* 6DC6B0 80218910 00000000 */  nop       
/* 6DC6B4 80218914 00000016 */  dsrlv     $zero, $zero, $zero
/* 6DC6B8 80218918 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC6BC 8021891C 00000020 */  add       $zero, $zero, $zero
/* 6DC6C0 80218920 00000025 */  or        $zero, $zero, $zero
/* 6DC6C4 80218924 00000002 */  srl       $zero, $zero, 0
/* 6DC6C8 80218928 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DC6CC 8021892C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC6D0 80218930 00000025 */  or        $zero, $zero, $zero
/* 6DC6D4 80218934 00000002 */  srl       $zero, $zero, 0
/* 6DC6D8 80218938 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DC6DC 8021893C 0061000D */  break     0x61
/* 6DC6E0 80218940 00000046 */   rotrv    $zero, $zero, $zero
/* 6DC6E4 80218944 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC6E8 80218948 80299044 */  lb        $t1, -0x6fbc($at)
/* 6DC6EC 8021894C 00000008 */  jr        $zero
/* 6DC6F0 80218950 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218954_6DC6F4
/* 6DC6F4 80218954 0000000A */  movz      $zero, $zero, $zero
/* 6DC6F8 80218958 00000046 */  rotrv     $zero, $zero, $zero
/* 6DC6FC 8021895C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC700 80218960 80219980 */  lb        $at, -0x6680($at)
/* 6DC704 80218964 00000002 */  srl       $zero, $zero, 0
/* 6DC708 80218968 00000000 */  nop       
/* 6DC70C 8021896C 0000001C */  dmult     $zero, $zero
/* 6DC710 80218970 00000000 */  nop       
/* 6DC714 80218974 00000023 */  negu      $zero, $zero
/* 6DC718 80218978 00000000 */  nop       
/* 6DC71C 8021897C 00000043 */  sra       $zero, $zero, 1
/* 6DC720 80218980 00000003 */  sra       $zero, $zero, 0
/* 6DC724 80218984 8026F0EC */  lb        $a2, -0xf14($at)
/* 6DC728 80218988 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DC72C 8021898C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC730 80218990 00000002 */  srl       $zero, $zero, 0
/* 6DC734 80218994 00000000 */  nop       
/* 6DC738 80218998 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC73C 8021899C 00000000 */  nop       
/* 6DC740 802189A0 00000043 */  sra       $zero, $zero, 1
/* 6DC744 802189A4 00000003 */  sra       $zero, $zero, 0
/* 6DC748 802189A8 8026F0EC */  lb        $a2, -0xf14($at)
/* 6DC74C 802189AC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DC750 802189B0 00000000 */  nop       
/* 6DC754 802189B4 00000043 */  sra       $zero, $zero, 1
/* 6DC758 802189B8 00000003 */  sra       $zero, $zero, 0
/* 6DC75C 802189BC 8027C548 */  lb        $a3, -0x3ab8($at)
/* 6DC760 802189C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DC764 802189C4 00000100 */  sll       $zero, $zero, 4
/* 6DC768 802189C8 00000043 */  sra       $zero, $zero, 1
/* 6DC76C 802189CC 00000002 */  srl       $zero, $zero, 0
/* 6DC770 802189D0 8024E61C */  lb        $a0, -0x19e4($at)
/* 6DC774 802189D4 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6DC778 802189D8 00000043 */  sra       $zero, $zero, 1
/* 6DC77C 802189DC 00000002 */  srl       $zero, $zero, 0
/* 6DC780 802189E0 8024EB24 */  lb        $a0, -0x14dc($at)
/* 6DC784 802189E4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DC788 802189E8 00000008 */  jr        $zero
/* 6DC78C 802189EC 00000001 */   movf     $zero, $zero, $fcc0

glabel func_802189F0_6DC790
/* 6DC790 802189F0 0000001E */  ddiv      $zero, $zero, $zero
/* 6DC794 802189F4 00000043 */  sra       $zero, $zero, 1
/* 6DC798 802189F8 00000004 */  sllv      $zero, $zero, $zero
/* 6DC79C 802189FC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6DC7A0 80218A00 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DC7A4 80218A04 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC7A8 80218A08 00610007 */  srav      $zero, $at, $v1
/* 6DC7AC 80218A0C 00000008 */  jr        $zero
/* 6DC7B0 80218A10 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218A14_6DC7B4
/* 6DC7B4 80218A14 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DC7B8 80218A18 00000043 */  sra       $zero, $zero, 1
/* 6DC7BC 80218A1C 00000003 */  sra       $zero, $zero, 0
/* 6DC7C0 80218A20 8025385C */  lb        $a1, 0x385c($at)
/* 6DC7C4 80218A24 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DC7C8 80218A28 0000207A */  dsrl      $a0, $zero, 1
/* 6DC7CC 80218A2C 00000043 */  sra       $zero, $zero, 1
/* 6DC7D0 80218A30 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DC7D4 80218A34 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6DC7D8 80218A38 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DC7DC 80218A3C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DC7E0 80218A40 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DC7E4 80218A44 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DC7E8 80218A48 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6DC7EC 80218A4C 00000002 */  srl       $zero, $zero, 0
/* 6DC7F0 80218A50 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DC7F4 80218A54 00000019 */  multu     $zero, $zero
/* 6DC7F8 80218A58 00000027 */  not       $zero, $zero
/* 6DC7FC 80218A5C 00000002 */  srl       $zero, $zero, 0
/* 6DC800 80218A60 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DC804 80218A64 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6DC808 80218A68 00000043 */  sra       $zero, $zero, 1
/* 6DC80C 80218A6C 0000000F */  sync      
/* 6DC810 80218A70 802D829C */  lb        $t5, -0x7d64($at)
/* 6DC814 80218A74 00000013 */  mtlo      $zero
/* 6DC818 80218A78 00000000 */  nop       
/* 6DC81C 80218A7C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DC820 80218A80 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DC824 80218A84 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DC828 80218A88 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC82C 80218A8C 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6DC830 80218A90 00000000 */  nop       
/* 6DC834 80218A94 00000000 */  nop       
/* 6DC838 80218A98 00000000 */  nop       
/* 6DC83C 80218A9C 00000000 */  nop       
/* 6DC840 80218AA0 00000000 */  nop       
/* 6DC844 80218AA4 00000000 */  nop       
/* 6DC848 80218AA8 00000000 */  nop       
/* 6DC84C 80218AAC 00000008 */  jr        $zero
/* 6DC850 80218AB0 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218AB4_6DC854
/* 6DC854 80218AB4 00000014 */  dsllv     $zero, $zero, $zero
/* 6DC858 80218AB8 00000043 */  sra       $zero, $zero, 1
/* 6DC85C 80218ABC 00000002 */  srl       $zero, $zero, 0
/* 6DC860 80218AC0 8024E61C */  lb        $a0, -0x19e4($at)
/* 6DC864 80218AC4 00000013 */  mtlo      $zero
/* 6DC868 80218AC8 00000043 */  sra       $zero, $zero, 1
/* 6DC86C 80218ACC 00000004 */  sllv      $zero, $zero, $zero
/* 6DC870 80218AD0 8024E90C */  lb        $a0, -0x16f4($at)
/* 6DC874 80218AD4 00000050 */  .byte     0x00, 0x00, 0x00, 0x50
/* 6DC878 80218AD8 0000005F */  .byte     0x00, 0x00, 0x00, 0x5f
/* 6DC87C 80218ADC 0000000F */  sync      
/* 6DC880 80218AE0 00000043 */  sra       $zero, $zero, 1
/* 6DC884 80218AE4 00000002 */  srl       $zero, $zero, 0
/* 6DC888 80218AE8 8024EC6C */  lb        $a0, -0x1394($at)
/* 6DC88C 80218AEC 00000154 */  .byte     0x00, 0x00, 0x01, 0x54
/* 6DC890 80218AF0 00000043 */  sra       $zero, $zero, 1
/* 6DC894 80218AF4 00000002 */  srl       $zero, $zero, 0
/* 6DC898 80218AF8 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6DC89C 80218AFC 0000003C */  dsll32    $zero, $zero, 0
/* 6DC8A0 80218B00 00000043 */  sra       $zero, $zero, 1
/* 6DC8A4 80218B04 00000003 */  sra       $zero, $zero, 0
/* 6DC8A8 80218B08 8025385C */  lb        $a1, 0x385c($at)
/* 6DC8AC 80218B0C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DC8B0 80218B10 0000207B */  dsra      $a0, $zero, 1
/* 6DC8B4 80218B14 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6DC8B8 80218B18 00000002 */  srl       $zero, $zero, 0
/* 6DC8BC 80218B1C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DC8C0 80218B20 0000000F */  sync      
/* 6DC8C4 80218B24 00000027 */  not       $zero, $zero
/* 6DC8C8 80218B28 00000002 */  srl       $zero, $zero, 0
/* 6DC8CC 80218B2C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DC8D0 80218B30 0000001E */  ddiv      $zero, $zero, $zero
/* 6DC8D4 80218B34 00000024 */  and       $zero, $zero, $zero
/* 6DC8D8 80218B38 00000002 */  srl       $zero, $zero, 0
/* 6DC8DC 80218B3C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DC8E0 80218B40 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DC8E4 80218B44 00000027 */  not       $zero, $zero
/* 6DC8E8 80218B48 00000002 */  srl       $zero, $zero, 0
/* 6DC8EC 80218B4C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DC8F0 80218B50 00000014 */  dsllv     $zero, $zero, $zero
/* 6DC8F4 80218B54 00000043 */  sra       $zero, $zero, 1
/* 6DC8F8 80218B58 0000000F */  sync      
/* 6DC8FC 80218B5C 802D829C */  lb        $t5, -0x7d64($at)
/* 6DC900 80218B60 00000013 */  mtlo      $zero
/* 6DC904 80218B64 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC908 80218B68 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DC90C 80218B6C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DC910 80218B70 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DC914 80218B74 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 6DC918 80218B78 0000003C */  dsll32    $zero, $zero, 0
/* 6DC91C 80218B7C 00000000 */  nop       
/* 6DC920 80218B80 00000000 */  nop       
/* 6DC924 80218B84 00000000 */  nop       
/* 6DC928 80218B88 00000000 */  nop       
/* 6DC92C 80218B8C 00000000 */  nop       
/* 6DC930 80218B90 00000000 */  nop       
/* 6DC934 80218B94 00000000 */  nop       
/* 6DC938 80218B98 00000008 */  jr        $zero
/* 6DC93C 80218B9C 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218BA0_6DC940
/* 6DC940 80218BA0 00000014 */  dsllv     $zero, $zero, $zero
/* 6DC944 80218BA4 00000043 */  sra       $zero, $zero, 1
/* 6DC948 80218BA8 0000000F */  sync      
/* 6DC94C 80218BAC 802D829C */  lb        $t5, -0x7d64($at)
/* 6DC950 80218BB0 00000013 */  mtlo      $zero
/* 6DC954 80218BB4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC958 80218BB8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DC95C 80218BBC FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DC960 80218BC0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DC964 80218BC4 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 6DC968 80218BC8 0000003C */  dsll32    $zero, $zero, 0
/* 6DC96C 80218BCC 00000000 */  nop       
/* 6DC970 80218BD0 00000000 */  nop       
/* 6DC974 80218BD4 00000000 */  nop       
/* 6DC978 80218BD8 00000000 */  nop       
/* 6DC97C 80218BDC 00000000 */  nop       
/* 6DC980 80218BE0 00000000 */  nop       
/* 6DC984 80218BE4 00000000 */  nop       
/* 6DC988 80218BE8 00000008 */  jr        $zero
/* 6DC98C 80218BEC 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218BF0_6DC990
/* 6DC990 80218BF0 0000000A */  movz      $zero, $zero, $zero
/* 6DC994 80218BF4 00000043 */  sra       $zero, $zero, 1
/* 6DC998 80218BF8 0000000F */  sync      
/* 6DC99C 80218BFC 802D829C */  lb        $t5, -0x7d64($at)
/* 6DC9A0 80218C00 00000013 */  mtlo      $zero
/* 6DC9A4 80218C04 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC9A8 80218C08 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DC9AC 80218C0C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DC9B0 80218C10 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DC9B4 80218C14 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 6DC9B8 80218C18 0000003C */  dsll32    $zero, $zero, 0
/* 6DC9BC 80218C1C 00000000 */  nop       
/* 6DC9C0 80218C20 00000000 */  nop       
/* 6DC9C4 80218C24 00000000 */  nop       
/* 6DC9C8 80218C28 00000000 */  nop       
/* 6DC9CC 80218C2C 00000000 */  nop       
/* 6DC9D0 80218C30 00000000 */  nop       
/* 6DC9D4 80218C34 00000000 */  nop       
/* 6DC9D8 80218C38 00000008 */  jr        $zero
/* 6DC9DC 80218C3C 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218C40_6DC9E0
/* 6DC9E0 80218C40 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DC9E4 80218C44 00000043 */  sra       $zero, $zero, 1
/* 6DC9E8 80218C48 0000000F */  sync      
/* 6DC9EC 80218C4C 802D829C */  lb        $t5, -0x7d64($at)
/* 6DC9F0 80218C50 00000013 */  mtlo      $zero
/* 6DC9F4 80218C54 00000001 */  movf      $zero, $zero, $fcc0
/* 6DC9F8 80218C58 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DC9FC 80218C5C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DCA00 80218C60 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DCA04 80218C64 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 6DCA08 80218C68 0000003C */  dsll32    $zero, $zero, 0
/* 6DCA0C 80218C6C 00000000 */  nop       
/* 6DCA10 80218C70 00000000 */  nop       
/* 6DCA14 80218C74 00000000 */  nop       
/* 6DCA18 80218C78 00000000 */  nop       
/* 6DCA1C 80218C7C 00000000 */  nop       
/* 6DCA20 80218C80 00000000 */  nop       
/* 6DCA24 80218C84 00000000 */  nop       
/* 6DCA28 80218C88 00000008 */  jr        $zero
/* 6DCA2C 80218C8C 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218C90_6DCA30
/* 6DCA30 80218C90 00000003 */  sra       $zero, $zero, 0
/* 6DCA34 80218C94 00000043 */  sra       $zero, $zero, 1
/* 6DCA38 80218C98 0000000F */  sync      
/* 6DCA3C 80218C9C 802D829C */  lb        $t5, -0x7d64($at)
/* 6DCA40 80218CA0 00000013 */  mtlo      $zero
/* 6DCA44 80218CA4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCA48 80218CA8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DCA4C 80218CAC FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DCA50 80218CB0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DCA54 80218CB4 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 6DCA58 80218CB8 0000003C */  dsll32    $zero, $zero, 0
/* 6DCA5C 80218CBC 00000000 */  nop       
/* 6DCA60 80218CC0 00000000 */  nop       
/* 6DCA64 80218CC4 00000000 */  nop       
/* 6DCA68 80218CC8 00000000 */  nop       
/* 6DCA6C 80218CCC 00000000 */  nop       
/* 6DCA70 80218CD0 00000000 */  nop       
/* 6DCA74 80218CD4 00000000 */  nop       
/* 6DCA78 80218CD8 00000043 */  sra       $zero, $zero, 1
/* 6DCA7C 80218CDC 00000007 */  srav      $zero, $zero, $zero
/* 6DCA80 80218CE0 80111D38 */  lb        $s1, 0x1d38($zero)
/* 6DCA84 80218CE4 802EA10C */  lb        $t6, -0x5ef4($at)
/* 6DCA88 80218CE8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DCA8C 80218CEC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DCA90 80218CF0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DCA94 80218CF4 00000000 */  nop       
/* 6DCA98 80218CF8 80000000 */  lb        $zero, ($zero)
/* 6DCA9C 80218CFC 00000024 */  and       $zero, $zero, $zero
/* 6DCAA0 80218D00 00000002 */  srl       $zero, $zero, 0
/* 6DCAA4 80218D04 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6DCAA8 80218D08 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DCAAC 80218D0C 00000043 */  sra       $zero, $zero, 1
/* 6DCAB0 80218D10 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCAB4 80218D14 80218220 */  lb        $at, -0x7de0($at)
/* 6DCAB8 80218D18 00000056 */  drotrv    $zero, $zero, $zero
/* 6DCABC 80218D1C 00000000 */  nop       
/* 6DCAC0 80218D20 00000043 */  sra       $zero, $zero, 1
/* 6DCAC4 80218D24 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCAC8 80218D28 8021833C */  lb        $at, -0x7cc4($at)
/* 6DCACC 80218D2C 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6DCAD0 80218D30 00000000 */  nop       
/* 6DCAD4 80218D34 00000043 */  sra       $zero, $zero, 1
/* 6DCAD8 80218D38 00000003 */  sra       $zero, $zero, 0
/* 6DCADC 80218D3C 8025385C */  lb        $a1, 0x385c($at)
/* 6DCAE0 80218D40 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DCAE4 80218D44 0000207C */  dsll32    $a0, $zero, 1
/* 6DCAE8 80218D48 00000043 */  sra       $zero, $zero, 1
/* 6DCAEC 80218D4C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCAF0 80218D50 80218180 */  lb        $at, -0x7e80($at)
/* 6DCAF4 80218D54 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6DCAF8 80218D58 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DCAFC 80218D5C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DCB00 80218D60 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6DCB04 80218D64 00000043 */  sra       $zero, $zero, 1
/* 6DCB08 80218D68 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCB0C 80218D6C 802D45B0 */  lb        $t5, 0x45b0($at)
/* 6DCB10 80218D70 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DCB14 80218D74 0000012C */  .byte     0x00, 0x00, 0x01, 0x2c
/* 6DCB18 80218D78 00000014 */  dsllv     $zero, $zero, $zero
/* 6DCB1C 80218D7C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCB20 80218D80 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCB24 80218D84 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCB28 80218D88 00000000 */  nop       
/* 6DCB2C 80218D8C 00000043 */  sra       $zero, $zero, 1
/* 6DCB30 80218D90 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCB34 80218D94 802D462C */  lb        $t5, 0x462c($at)
/* 6DCB38 80218D98 00000043 */  sra       $zero, $zero, 1
/* 6DCB3C 80218D9C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCB40 80218DA0 802180B8 */  lb        $at, -0x7f48($at)
/* 6DCB44 80218DA4 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6DCB48 80218DA8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DCB4C 80218DAC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DCB50 80218DB0 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6DCB54 80218DB4 00000008 */  jr        $zero
/* 6DCB58 80218DB8 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218DBC_6DCB5C
/* 6DCB5C 80218DBC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCB60 80218DC0 0000000B */  movn      $zero, $zero, $zero
/* 6DCB64 80218DC4 00000002 */  srl       $zero, $zero, 0
/* 6DCB68 80218DC8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DCB6C 80218DCC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCB70 80218DD0 00000007 */  srav      $zero, $zero, $zero
/* 6DCB74 80218DD4 00000000 */  nop       
/* 6DCB78 80218DD8 00000013 */  mtlo      $zero
/* 6DCB7C 80218DDC 00000000 */  nop       
/* 6DCB80 80218DE0 00000006 */  srlv      $zero, $zero, $zero
/* 6DCB84 80218DE4 00000000 */  nop       
/* 6DCB88 80218DE8 00000008 */  jr        $zero
/* 6DCB8C 80218DEC 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218DF0_6DCB90
/* 6DCB90 80218DF0 00000014 */  dsllv     $zero, $zero, $zero
/* 6DCB94 80218DF4 00000043 */  sra       $zero, $zero, 1
/* 6DCB98 80218DF8 00000004 */  sllv      $zero, $zero, $zero
/* 6DCB9C 80218DFC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6DCBA0 80218E00 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DCBA4 80218E04 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCBA8 80218E08 00610008 */  .byte     0x00, 0x61, 0x00, 0x08
/* 6DCBAC 80218E0C 00000008 */  jr        $zero
/* 6DCBB0 80218E10 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218E14_6DCBB4
/* 6DCBB4 80218E14 0000000A */  movz      $zero, $zero, $zero
/* 6DCBB8 80218E18 00000043 */  sra       $zero, $zero, 1
/* 6DCBBC 80218E1C 00000002 */  srl       $zero, $zero, 0
/* 6DCBC0 80218E20 8024E61C */  lb        $a0, -0x19e4($at)
/* 6DCBC4 80218E24 00000013 */  mtlo      $zero
/* 6DCBC8 80218E28 00000043 */  sra       $zero, $zero, 1
/* 6DCBCC 80218E2C 00000004 */  sllv      $zero, $zero, $zero
/* 6DCBD0 80218E30 8024E90C */  lb        $a0, -0x16f4($at)
/* 6DCBD4 80218E34 FFFFFFB0 */  sd        $ra, -0x50($ra)
/* 6DCBD8 80218E38 00000025 */  or        $zero, $zero, $zero
/* 6DCBDC 80218E3C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCBE0 80218E40 00000043 */  sra       $zero, $zero, 1
/* 6DCBE4 80218E44 00000002 */  srl       $zero, $zero, 0
/* 6DCBE8 80218E48 8024EC6C */  lb        $a0, -0x1394($at)
/* 6DCBEC 80218E4C 00000100 */  sll       $zero, $zero, 4
/* 6DCBF0 80218E50 00000043 */  sra       $zero, $zero, 1
/* 6DCBF4 80218E54 00000002 */  srl       $zero, $zero, 0
/* 6DCBF8 80218E58 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6DCBFC 80218E5C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCC00 80218E60 00000043 */  sra       $zero, $zero, 1
/* 6DCC04 80218E64 00000002 */  srl       $zero, $zero, 0
/* 6DCC08 80218E68 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 6DCC0C 80218E6C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DCC10 80218E70 00000043 */  sra       $zero, $zero, 1
/* 6DCC14 80218E74 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCC18 80218E78 8026A820 */  lb        $a2, -0x57e0($at)
/* 6DCC1C 80218E7C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DCC20 80218E80 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DCC24 80218E84 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DCC28 80218E88 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DCC2C 80218E8C 00000058 */  .byte     0x00, 0x00, 0x00, 0x58
/* 6DCC30 80218E90 00000000 */  nop       
/* 6DCC34 80218E94 00000008 */  jr        $zero
/* 6DCC38 80218E98 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218E9C_6DCC3C
/* 6DCC3C 80218E9C 0000000A */  movz      $zero, $zero, $zero
/* 6DCC40 80218EA0 00000043 */  sra       $zero, $zero, 1
/* 6DCC44 80218EA4 00000002 */  srl       $zero, $zero, 0
/* 6DCC48 80218EA8 8024ECAC */  lb        $a0, -0x1354($at)
/* 6DCC4C 80218EAC 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6DCC50 80218EB0 00000043 */  sra       $zero, $zero, 1
/* 6DCC54 80218EB4 00000002 */  srl       $zero, $zero, 0
/* 6DCC58 80218EB8 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6DCC5C 80218EBC 0000000A */  movz      $zero, $zero, $zero
/* 6DCC60 80218EC0 00000008 */  jr        $zero
/* 6DCC64 80218EC4 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218EC8_6DCC68
/* 6DCC68 80218EC8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCC6C 80218ECC 00000043 */  sra       $zero, $zero, 1
/* 6DCC70 80218ED0 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCC74 80218ED4 802183EC */  lb        $at, -0x7c14($at)
/* 6DCC78 80218ED8 00000059 */  .byte     0x00, 0x00, 0x00, 0x59
/* 6DCC7C 80218EDC 00000000 */  nop       
/* 6DCC80 80218EE0 00000043 */  sra       $zero, $zero, 1
/* 6DCC84 80218EE4 00000003 */  sra       $zero, $zero, 0
/* 6DCC88 80218EE8 8025385C */  lb        $a1, 0x385c($at)
/* 6DCC8C 80218EEC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DCC90 80218EF0 0000207D */  .byte     0x00, 0x00, 0x20, 0x7d
/* 6DCC94 80218EF4 00000024 */  and       $zero, $zero, $zero
/* 6DCC98 80218EF8 00000002 */  srl       $zero, $zero, 0
/* 6DCC9C 80218EFC FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6DCCA0 80218F00 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DCCA4 80218F04 00000027 */  not       $zero, $zero
/* 6DCCA8 80218F08 00000002 */  srl       $zero, $zero, 0
/* 6DCCAC 80218F0C FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6DCCB0 80218F10 000000C8 */  .byte     0x00, 0x00, 0x00, 0xc8
/* 6DCCB4 80218F14 00000043 */  sra       $zero, $zero, 1
/* 6DCCB8 80218F18 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCCBC 80218F1C 802180B8 */  lb        $at, -0x7f48($at)
/* 6DCCC0 80218F20 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6DCCC4 80218F24 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DCCC8 80218F28 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6DCCCC 80218F2C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DCCD0 80218F30 00000043 */  sra       $zero, $zero, 1
/* 6DCCD4 80218F34 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCCD8 80218F38 80218180 */  lb        $at, -0x7e80($at)
/* 6DCCDC 80218F3C FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6DCCE0 80218F40 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DCCE4 80218F44 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DCCE8 80218F48 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6DCCEC 80218F4C 00000043 */  sra       $zero, $zero, 1
/* 6DCCF0 80218F50 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCCF4 80218F54 802D45B0 */  lb        $t5, 0x45b0($at)
/* 6DCCF8 80218F58 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6DCCFC 80218F5C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DCD00 80218F60 00000014 */  dsllv     $zero, $zero, $zero
/* 6DCD04 80218F64 00000002 */  srl       $zero, $zero, 0
/* 6DCD08 80218F68 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCD0C 80218F6C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCD10 80218F70 00000000 */  nop       
/* 6DCD14 80218F74 00000043 */  sra       $zero, $zero, 1
/* 6DCD18 80218F78 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCD1C 80218F7C 802D462C */  lb        $t5, 0x462c($at)
/* 6DCD20 80218F80 00000043 */  sra       $zero, $zero, 1
/* 6DCD24 80218F84 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCD28 80218F88 802180B8 */  lb        $at, -0x7f48($at)
/* 6DCD2C 80218F8C FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6DCD30 80218F90 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DCD34 80218F94 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DCD38 80218F98 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6DCD3C 80218F9C 00000008 */  jr        $zero
/* 6DCD40 80218FA0 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218FA4_6DCD44
/* 6DCD44 80218FA4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCD48 80218FA8 0000000B */  movn      $zero, $zero, $zero
/* 6DCD4C 80218FAC 00000002 */  srl       $zero, $zero, 0
/* 6DCD50 80218FB0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DCD54 80218FB4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCD58 80218FB8 00000007 */  srav      $zero, $zero, $zero
/* 6DCD5C 80218FBC 00000000 */  nop       
/* 6DCD60 80218FC0 00000013 */  mtlo      $zero
/* 6DCD64 80218FC4 00000000 */  nop       
/* 6DCD68 80218FC8 00000006 */  srlv      $zero, $zero, $zero
/* 6DCD6C 80218FCC 00000000 */  nop       
/* 6DCD70 80218FD0 00000043 */  sra       $zero, $zero, 1
/* 6DCD74 80218FD4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCD78 80218FD8 8021849C */  lb        $at, -0x7b64($at)
/* 6DCD7C 80218FDC 00000058 */  .byte     0x00, 0x00, 0x00, 0x58
/* 6DCD80 80218FE0 00000000 */  nop       
/* 6DCD84 80218FE4 00000043 */  sra       $zero, $zero, 1
/* 6DCD88 80218FE8 00000002 */  srl       $zero, $zero, 0
/* 6DCD8C 80218FEC 80254218 */  lb        $a1, 0x4218($at)
/* 6DCD90 80218FF0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCD94 80218FF4 00000043 */  sra       $zero, $zero, 1
/* 6DCD98 80218FF8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCD9C 80218FFC 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 6DCDA0 80219000 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCDA4 80219004 00000000 */  nop       
/* 6DCDA8 80219008 00000002 */  srl       $zero, $zero, 0
/* 6DCDAC 8021900C F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 6DCDB0 80219010 00000043 */  sra       $zero, $zero, 1
/* 6DCDB4 80219014 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCDB8 80219018 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 6DCDBC 8021901C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCDC0 80219020 00000000 */  nop       
/* 6DCDC4 80219024 00000002 */  srl       $zero, $zero, 0
/* 6DCDC8 80219028 F24A8680 */  scd       $t2, -0x7980($s2)
/* 6DCDCC 8021902C 00000043 */  sra       $zero, $zero, 1
/* 6DCDD0 80219030 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCDD4 80219034 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 6DCDD8 80219038 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCDDC 8021903C 00000000 */  nop       
/* 6DCDE0 80219040 00000002 */  srl       $zero, $zero, 0
/* 6DCDE4 80219044 F24A9280 */  scd       $t2, -0x6d80($s2)
/* 6DCDE8 80219048 00000043 */  sra       $zero, $zero, 1
/* 6DCDEC 8021904C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCDF0 80219050 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 6DCDF4 80219054 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCDF8 80219058 00000000 */  nop       
/* 6DCDFC 8021905C 00000002 */  srl       $zero, $zero, 0
/* 6DCE00 80219060 F24A8E80 */  scd       $t2, -0x7180($s2)
/* 6DCE04 80219064 00000043 */  sra       $zero, $zero, 1
/* 6DCE08 80219068 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCE0C 8021906C 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 6DCE10 80219070 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCE14 80219074 00000000 */  nop       
/* 6DCE18 80219078 00000002 */  srl       $zero, $zero, 0
/* 6DCE1C 8021907C F24A8A80 */  scd       $t2, -0x7580($s2)
/* 6DCE20 80219080 00000043 */  sra       $zero, $zero, 1
/* 6DCE24 80219084 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCE28 80219088 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 6DCE2C 8021908C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCE30 80219090 00000000 */  nop       
/* 6DCE34 80219094 00000002 */  srl       $zero, $zero, 0
/* 6DCE38 80219098 F24A8680 */  scd       $t2, -0x7980($s2)
/* 6DCE3C 8021909C 00000043 */  sra       $zero, $zero, 1
/* 6DCE40 802190A0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCE44 802190A4 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 6DCE48 802190A8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCE4C 802190AC 00000000 */  nop       
/* 6DCE50 802190B0 00000002 */  srl       $zero, $zero, 0
/* 6DCE54 802190B4 F24A8280 */  scd       $t2, -0x7d80($s2)
/* 6DCE58 802190B8 00000043 */  sra       $zero, $zero, 1
/* 6DCE5C 802190BC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCE60 802190C0 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 6DCE64 802190C4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCE68 802190C8 00000000 */  nop       
/* 6DCE6C 802190CC 00000002 */  srl       $zero, $zero, 0
/* 6DCE70 802190D0 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 6DCE74 802190D4 00000043 */  sra       $zero, $zero, 1
/* 6DCE78 802190D8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCE7C 802190DC 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 6DCE80 802190E0 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCE84 802190E4 00000000 */  nop       
/* 6DCE88 802190E8 00000002 */  srl       $zero, $zero, 0
/* 6DCE8C 802190EC F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 6DCE90 802190F0 00000043 */  sra       $zero, $zero, 1
/* 6DCE94 802190F4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DCE98 802190F8 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 6DCE9C 802190FC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCEA0 80219100 00000000 */  nop       
/* 6DCEA4 80219104 00000002 */  srl       $zero, $zero, 0
/* 6DCEA8 80219108 F24A7B4D */  scd       $t2, 0x7b4d($s2)
/* 6DCEAC 8021910C 00000059 */  .byte     0x00, 0x00, 0x00, 0x59
/* 6DCEB0 80219110 00000000 */  nop       
/* 6DCEB4 80219114 00000043 */  sra       $zero, $zero, 1
/* 6DCEB8 80219118 00000004 */  sllv      $zero, $zero, $zero
/* 6DCEBC 8021911C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6DCEC0 80219120 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DCEC4 80219124 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCEC8 80219128 00610005 */  lsa       $zero, $v1, $at, 1
/* 6DCECC 8021912C 00000008 */  jr        $zero
/* 6DCED0 80219130 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80219134_6DCED4
/* 6DCED4 80219134 00000002 */  srl       $zero, $zero, 0
/* 6DCED8 80219138 00000043 */  sra       $zero, $zero, 1
/* 6DCEDC 8021913C 00000008 */  jr        $zero
/* 6DCEE0 80219140 8027CCB4 */   lb       $a3, -0x334c($at)

glabel func_80219144_6DCEE4
/* 6DCEE4 80219144 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DCEE8 80219148 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DCEEC 8021914C 10000010 */  b         .L80219190
/* 6DCEF0 80219150 00000000 */   nop      
/* 6DCEF4 80219154 00000000 */  nop       
/* 6DCEF8 80219158 00000004 */  sllv      $zero, $zero, $zero
/* 6DCEFC 8021915C 00000020 */  add       $zero, $zero, $zero
/* 6DCF00 80219160 00000024 */  and       $zero, $zero, $zero
/* 6DCF04 80219164 00000002 */  srl       $zero, $zero, 0
/* 6DCF08 80219168 FE363C8F */  sd        $s6, 0x3c8f($s1)
/* 6DCF0C 8021916C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DCF10 80219170 00000014 */  dsllv     $zero, $zero, $zero
/* 6DCF14 80219174 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCF18 80219178 FE363C8F */  sd        $s6, 0x3c8f($s1)
/* 6DCF1C 8021917C 0000001D */  dmultu    $zero, $zero
/* 6DCF20 80219180 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCF24 80219184 00000000 */  nop       
/* 6DCF28 80219188 0000001D */  dmultu    $zero, $zero
/* 6DCF2C 8021918C 00000001 */  movf      $zero, $zero, $fcc0
.L80219190:
/* 6DCF30 80219190 00000002 */  srl       $zero, $zero, 0
/* 6DCF34 80219194 00000008 */  jr        $zero
/* 6DCF38 80219198 00000001 */   movf     $zero, $zero, $fcc0

glabel func_8021919C_6DCF3C
/* 6DCF3C 8021919C 00000013 */  mtlo      $zero
/* 6DCF40 802191A0 00000043 */  sra       $zero, $zero, 1
/* 6DCF44 802191A4 00000002 */  srl       $zero, $zero, 0
/* 6DCF48 802191A8 8024E61C */  lb        $a0, -0x19e4($at)
/* 6DCF4C 802191AC 00000002 */  srl       $zero, $zero, 0
/* 6DCF50 802191B0 00000020 */  add       $zero, $zero, $zero
/* 6DCF54 802191B4 00000000 */  nop       
/* 6DCF58 802191B8 00000023 */  negu      $zero, $zero
/* 6DCF5C 802191BC 00000000 */  nop       
/* 6DCF60 802191C0 00000043 */  sra       $zero, $zero, 1
/* 6DCF64 802191C4 00000003 */  sra       $zero, $zero, 0
/* 6DCF68 802191C8 8027DB3C */  lb        $a3, -0x24c4($at)
/* 6DCF6C 802191CC 00000100 */  sll       $zero, $zero, 4
/* 6DCF70 802191D0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DCF74 802191D4 0000000A */  movz      $zero, $zero, $zero
/* 6DCF78 802191D8 00000002 */  srl       $zero, $zero, 0
/* 6DCF7C 802191DC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DCF80 802191E0 00000000 */  nop       
/* 6DCF84 802191E4 00000043 */  sra       $zero, $zero, 1
/* 6DCF88 802191E8 00000002 */  srl       $zero, $zero, 0
/* 6DCF8C 802191EC 8024E61C */  lb        $a0, -0x19e4($at)
/* 6DCF90 802191F0 00000013 */  mtlo      $zero
/* 6DCF94 802191F4 00000043 */  sra       $zero, $zero, 1
/* 6DCF98 802191F8 00000004 */  sllv      $zero, $zero, $zero
/* 6DCF9C 802191FC 8024E90C */  lb        $a0, -0x16f4($at)
/* 6DCFA0 80219200 00000045 */  lsa       $zero, $zero, $zero, 2
/* 6DCFA4 80219204 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6DCFA8 80219208 FFFFFFEE */  sd        $ra, -0x12($ra)
/* 6DCFAC 8021920C 00000043 */  sra       $zero, $zero, 1
/* 6DCFB0 80219210 00000002 */  srl       $zero, $zero, 0
/* 6DCFB4 80219214 8024EC6C */  lb        $a0, -0x1394($at)
/* 6DCFB8 80219218 00000154 */  .byte     0x00, 0x00, 0x01, 0x54
/* 6DCFBC 8021921C 00000043 */  sra       $zero, $zero, 1
/* 6DCFC0 80219220 00000002 */  srl       $zero, $zero, 0
/* 6DCFC4 80219224 8024EA58 */  lb        $a0, -0x15a8($at)
/* 6DCFC8 80219228 0000003E */  dsrl32    $zero, $zero, 0
/* 6DCFCC 8021922C 00000043 */  sra       $zero, $zero, 1
/* 6DCFD0 80219230 00000002 */  srl       $zero, $zero, 0
/* 6DCFD4 80219234 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6DCFD8 80219238 00000014 */  dsllv     $zero, $zero, $zero
/* 6DCFDC 8021923C 00000043 */  sra       $zero, $zero, 1
/* 6DCFE0 80219240 00000002 */  srl       $zero, $zero, 0
/* 6DCFE4 80219244 8024ED78 */  lb        $a0, -0x1288($at)
/* 6DCFE8 80219248 00000001 */  movf      $zero, $zero, $fcc0
/* 6DCFEC 8021924C 00000008 */  jr        $zero
/* 6DCFF0 80219250 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80219254_6DCFF4
/* 6DCFF4 80219254 00000014 */  dsllv     $zero, $zero, $zero
/* 6DCFF8 80219258 00000056 */  drotrv    $zero, $zero, $zero
/* 6DCFFC 8021925C 00000000 */  nop       
/* 6DD000 80219260 00000043 */  sra       $zero, $zero, 1
/* 6DD004 80219264 00000002 */  srl       $zero, $zero, 0
/* 6DD008 80219268 80269EC4 */  lb        $a2, -0x613c($at)
/* 6DD00C 8021926C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD010 80219270 00000043 */  sra       $zero, $zero, 1
/* 6DD014 80219274 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DD018 80219278 8026A748 */  lb        $a2, -0x58b8($at)
/* 6DD01C 8021927C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD020 80219280 0000000A */  movz      $zero, $zero, $zero
/* 6DD024 80219284 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DD028 80219288 00000000 */  nop       
/* 6DD02C 8021928C 00000043 */  sra       $zero, $zero, 1
/* 6DD030 80219290 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DD034 80219294 8027B624 */  lb        $a3, -0x49dc($at)
/* 6DD038 80219298 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD03C 8021929C 00000006 */  srlv      $zero, $zero, $zero
/* 6DD040 802192A0 00000000 */  nop       
/* 6DD044 802192A4 00000000 */  nop       
/* 6DD048 802192A8 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6DD04C 802192AC 00000000 */  nop       
/* 6DD050 802192B0 00000043 */  sra       $zero, $zero, 1
/* 6DD054 802192B4 00000006 */  srlv      $zero, $zero, $zero
/* 6DD058 802192B8 80252F30 */  lb        $a1, 0x2f30($at)
/* 6DD05C 802192BC 0013009A */  .byte     0x00, 0x13, 0x00, 0x9a
/* 6DD060 802192C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD064 802192C4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD068 802192C8 00610006 */  srlv      $zero, $at, $v1
/* 6DD06C 802192CC 00610005 */  lsa       $zero, $v1, $at, 1
/* 6DD070 802192D0 00000008 */  jr        $zero
/* 6DD074 802192D4 00000001 */   movf     $zero, $zero, $fcc0

glabel func_802192D8_6DD078
/* 6DD078 802192D8 0000000A */  movz      $zero, $zero, $zero
/* 6DD07C 802192DC 00000043 */  sra       $zero, $zero, 1
/* 6DD080 802192E0 00000002 */  srl       $zero, $zero, 0
/* 6DD084 802192E4 8024ED78 */  lb        $a0, -0x1288($at)
/* 6DD088 802192E8 00000000 */  nop       
/* 6DD08C 802192EC 00000043 */  sra       $zero, $zero, 1
/* 6DD090 802192F0 00000002 */  srl       $zero, $zero, 0
/* 6DD094 802192F4 8024E61C */  lb        $a0, -0x19e4($at)
/* 6DD098 802192F8 00000002 */  srl       $zero, $zero, 0
/* 6DD09C 802192FC 00000013 */  mtlo      $zero
/* 6DD0A0 80219300 00000000 */  nop       
/* 6DD0A4 80219304 00000008 */  jr        $zero
/* 6DD0A8 80219308 00000001 */   movf     $zero, $zero, $fcc0

glabel func_8021930C_6DD0AC
/* 6DD0AC 8021930C 0000000A */  movz      $zero, $zero, $zero
/* 6DD0B0 80219310 00000043 */  sra       $zero, $zero, 1
/* 6DD0B4 80219314 00000003 */  sra       $zero, $zero, 0
/* 6DD0B8 80219318 8026F0EC */  lb        $a2, -0xf14($at)
/* 6DD0BC 8021931C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD0C0 80219320 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD0C4 80219324 00000002 */  srl       $zero, $zero, 0
/* 6DD0C8 80219328 00000000 */  nop       
/* 6DD0CC 8021932C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD0D0 80219330 00000000 */  nop       
/* 6DD0D4 80219334 00000043 */  sra       $zero, $zero, 1
/* 6DD0D8 80219338 00000003 */  sra       $zero, $zero, 0
/* 6DD0DC 8021933C 8026F0EC */  lb        $a2, -0xf14($at)
/* 6DD0E0 80219340 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD0E4 80219344 00000000 */  nop       
/* 6DD0E8 80219348 00000043 */  sra       $zero, $zero, 1
/* 6DD0EC 8021934C 00000002 */  srl       $zero, $zero, 0
/* 6DD0F0 80219350 80269E28 */  lb        $a2, -0x61d8($at)
/* 6DD0F4 80219354 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DD0F8 80219358 00000014 */  dsllv     $zero, $zero, $zero
/* 6DD0FC 8021935C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD100 80219360 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DD104 80219364 00000016 */  dsrlv     $zero, $zero, $zero
/* 6DD108 80219368 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD10C 8021936C 0000000A */  movz      $zero, $zero, $zero
/* 6DD110 80219370 00000043 */  sra       $zero, $zero, 1
/* 6DD114 80219374 00000004 */  sllv      $zero, $zero, $zero
/* 6DD118 80219378 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6DD11C 8021937C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD120 80219380 00000000 */  nop       
/* 6DD124 80219384 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DD128 80219388 00000014 */  dsllv     $zero, $zero, $zero
/* 6DD12C 8021938C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD130 80219390 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DD134 80219394 00000016 */  dsrlv     $zero, $zero, $zero
/* 6DD138 80219398 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD13C 8021939C 00000000 */  nop       
/* 6DD140 802193A0 00000043 */  sra       $zero, $zero, 1
/* 6DD144 802193A4 00000002 */  srl       $zero, $zero, 0
/* 6DD148 802193A8 8024E61C */  lb        $a0, -0x19e4($at)
/* 6DD14C 802193AC 00000013 */  mtlo      $zero
/* 6DD150 802193B0 00000043 */  sra       $zero, $zero, 1
/* 6DD154 802193B4 00000004 */  sllv      $zero, $zero, $zero
/* 6DD158 802193B8 8024E90C */  lb        $a0, -0x16f4($at)
/* 6DD15C 802193BC 00000045 */  lsa       $zero, $zero, $zero, 2
/* 6DD160 802193C0 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6DD164 802193C4 FFFFFFEE */  sd        $ra, -0x12($ra)
/* 6DD168 802193C8 00000043 */  sra       $zero, $zero, 1
/* 6DD16C 802193CC 00000002 */  srl       $zero, $zero, 0
/* 6DD170 802193D0 8024EC6C */  lb        $a0, -0x1394($at)
/* 6DD174 802193D4 00000154 */  .byte     0x00, 0x00, 0x01, 0x54
/* 6DD178 802193D8 00000043 */  sra       $zero, $zero, 1
/* 6DD17C 802193DC 00000002 */  srl       $zero, $zero, 0
/* 6DD180 802193E0 8024EA58 */  lb        $a0, -0x15a8($at)
/* 6DD184 802193E4 0000003E */  dsrl32    $zero, $zero, 0
/* 6DD188 802193E8 00000043 */  sra       $zero, $zero, 1
/* 6DD18C 802193EC 00000002 */  srl       $zero, $zero, 0
/* 6DD190 802193F0 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6DD194 802193F4 00000014 */  dsllv     $zero, $zero, $zero
/* 6DD198 802193F8 00000008 */  jr        $zero
/* 6DD19C 802193FC 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80219400_6DD1A0
/* 6DD1A0 80219400 00000014 */  dsllv     $zero, $zero, $zero
/* 6DD1A4 80219404 00000043 */  sra       $zero, $zero, 1
/* 6DD1A8 80219408 00000006 */  srlv      $zero, $zero, $zero
/* 6DD1AC 8021940C 80252F30 */  lb        $a1, 0x2f30($at)
/* 6DD1B0 80219410 00130093 */  .byte     0x00, 0x13, 0x00, 0x93
/* 6DD1B4 80219414 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD1B8 80219418 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD1BC 8021941C 00610006 */  srlv      $zero, $at, $v1
/* 6DD1C0 80219420 00610005 */  lsa       $zero, $v1, $at, 1
/* 6DD1C4 80219424 00000008 */  jr        $zero
/* 6DD1C8 80219428 00000001 */   movf     $zero, $zero, $fcc0

glabel func_8021942C_6DD1CC
/* 6DD1CC 8021942C 0000000A */  movz      $zero, $zero, $zero
/* 6DD1D0 80219430 00000043 */  sra       $zero, $zero, 1
/* 6DD1D4 80219434 00000002 */  srl       $zero, $zero, 0
/* 6DD1D8 80219438 8024E61C */  lb        $a0, -0x19e4($at)
/* 6DD1DC 8021943C 00000013 */  mtlo      $zero
/* 6DD1E0 80219440 00000043 */  sra       $zero, $zero, 1
/* 6DD1E4 80219444 00000004 */  sllv      $zero, $zero, $zero
/* 6DD1E8 80219448 8024E90C */  lb        $a0, -0x16f4($at)
/* 6DD1EC 8021944C FFFFFFC8 */  sd        $ra, -0x38($ra)
/* 6DD1F0 80219450 FFFFFFF7 */  sd        $ra, -9($ra)
/* 6DD1F4 80219454 FFFFFFEE */  sd        $ra, -0x12($ra)
/* 6DD1F8 80219458 00000043 */  sra       $zero, $zero, 1
/* 6DD1FC 8021945C 00000002 */  srl       $zero, $zero, 0
/* 6DD200 80219460 8024EC6C */  lb        $a0, -0x1394($at)
/* 6DD204 80219464 00000154 */  .byte     0x00, 0x00, 0x01, 0x54
/* 6DD208 80219468 00000043 */  sra       $zero, $zero, 1
/* 6DD20C 8021946C 00000002 */  srl       $zero, $zero, 0
/* 6DD210 80219470 8024EA58 */  lb        $a0, -0x15a8($at)
/* 6DD214 80219474 0000003E */  dsrl32    $zero, $zero, 0
/* 6DD218 80219478 00000043 */  sra       $zero, $zero, 1
/* 6DD21C 8021947C 00000002 */  srl       $zero, $zero, 0
/* 6DD220 80219480 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6DD224 80219484 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD228 80219488 00000008 */  jr        $zero
/* 6DD22C 8021948C 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80219490_6DD230
/* 6DD230 80219490 0000000A */  movz      $zero, $zero, $zero
/* 6DD234 80219494 00000043 */  sra       $zero, $zero, 1
/* 6DD238 80219498 00000006 */  srlv      $zero, $zero, $zero
/* 6DD23C 8021949C 80252F30 */  lb        $a1, 0x2f30($at)
/* 6DD240 802194A0 00130094 */  .byte     0x00, 0x13, 0x00, 0x94
/* 6DD244 802194A4 00000100 */  sll       $zero, $zero, 4
/* 6DD248 802194A8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD24C 802194AC 0020000D */  break     0x20
/* 6DD250 802194B0 00200008 */   jr       $at
/* 6DD254 802194B4 00000008 */   jr       $zero
/* 6DD258 802194B8 00000001 */   movf     $zero, $zero, $fcc0

glabel func_802194BC_6DD25C
/* 6DD25C 802194BC 0000000A */  movz      $zero, $zero, $zero
/* 6DD260 802194C0 00000043 */  sra       $zero, $zero, 1
/* 6DD264 802194C4 00000002 */  srl       $zero, $zero, 0
/* 6DD268 802194C8 8024E61C */  lb        $a0, -0x19e4($at)
/* 6DD26C 802194CC 00000013 */  mtlo      $zero
/* 6DD270 802194D0 00000043 */  sra       $zero, $zero, 1
/* 6DD274 802194D4 00000004 */  sllv      $zero, $zero, $zero
/* 6DD278 802194D8 8024E90C */  lb        $a0, -0x16f4($at)
/* 6DD27C 802194DC FFFFFFBE */  sd        $ra, -0x42($ra)
/* 6DD280 802194E0 FFFFFFF7 */  sd        $ra, -9($ra)
/* 6DD284 802194E4 FFFFFFEE */  sd        $ra, -0x12($ra)
/* 6DD288 802194E8 00000043 */  sra       $zero, $zero, 1
/* 6DD28C 802194EC 00000002 */  srl       $zero, $zero, 0
/* 6DD290 802194F0 8024EC6C */  lb        $a0, -0x1394($at)
/* 6DD294 802194F4 00000154 */  .byte     0x00, 0x00, 0x01, 0x54
/* 6DD298 802194F8 00000043 */  sra       $zero, $zero, 1
/* 6DD29C 802194FC 00000002 */  srl       $zero, $zero, 0
/* 6DD2A0 80219500 8024EA58 */  lb        $a0, -0x15a8($at)
/* 6DD2A4 80219504 0000003E */  dsrl32    $zero, $zero, 0
/* 6DD2A8 80219508 00000043 */  sra       $zero, $zero, 1
/* 6DD2AC 8021950C 00000002 */  srl       $zero, $zero, 0
/* 6DD2B0 80219510 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6DD2B4 80219514 0000000A */  movz      $zero, $zero, $zero
/* 6DD2B8 80219518 00000008 */  jr        $zero
/* 6DD2BC 8021951C 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80219520_6DD2C0
/* 6DD2C0 80219520 0000000A */  movz      $zero, $zero, $zero
/* 6DD2C4 80219524 00000043 */  sra       $zero, $zero, 1
/* 6DD2C8 80219528 00000006 */  srlv      $zero, $zero, $zero
/* 6DD2CC 8021952C 80252F30 */  lb        $a1, 0x2f30($at)
/* 6DD2D0 80219530 00130095 */  dlsa      $zero, $zero, $s3, 3
/* 6DD2D4 80219534 00000000 */  nop       
/* 6DD2D8 80219538 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD2DC 8021953C 000C0007 */  srav      $zero, $t4, $zero
/* 6DD2E0 80219540 000C0008 */  .byte     0x00, 0x0c, 0x00, 0x08
/* 6DD2E4 80219544 00000008 */  jr        $zero
/* 6DD2E8 80219548 00000001 */   movf     $zero, $zero, $fcc0

glabel func_8021954C_6DD2EC
/* 6DD2EC 8021954C 0000000A */  movz      $zero, $zero, $zero
/* 6DD2F0 80219550 00000043 */  sra       $zero, $zero, 1
/* 6DD2F4 80219554 00000002 */  srl       $zero, $zero, 0
/* 6DD2F8 80219558 8024E61C */  lb        $a0, -0x19e4($at)
/* 6DD2FC 8021955C 00000002 */  srl       $zero, $zero, 0
/* 6DD300 80219560 00000043 */  sra       $zero, $zero, 1
/* 6DD304 80219564 00000004 */  sllv      $zero, $zero, $zero
/* 6DD308 80219568 8026C0D4 */  lb        $a2, -0x3f2c($at)
/* 6DD30C 8021956C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD310 80219570 00000000 */  nop       
/* 6DD314 80219574 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD318 80219578 00000023 */  negu      $zero, $zero
/* 6DD31C 8021957C 00000000 */  nop       
/* 6DD320 80219580 00000016 */  dsrlv     $zero, $zero, $zero
/* 6DD324 80219584 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD328 80219588 0000000C */  syscall   
/* 6DD32C 8021958C 00000023 */  negu      $zero, $zero
/* 6DD330 80219590 00000000 */  nop       
/* 6DD334 80219594 00000043 */  sra       $zero, $zero, 1
/* 6DD338 80219598 00000003 */  sra       $zero, $zero, 0
/* 6DD33C 8021959C 8026F0EC */  lb        $a2, -0xf14($at)
/* 6DD340 802195A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD344 802195A4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD348 802195A8 00000002 */  srl       $zero, $zero, 0
/* 6DD34C 802195AC 00000000 */  nop       
/* 6DD350 802195B0 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD354 802195B4 00000000 */  nop       
/* 6DD358 802195B8 00000043 */  sra       $zero, $zero, 1
/* 6DD35C 802195BC 00000002 */  srl       $zero, $zero, 0
/* 6DD360 802195C0 8026BF48 */  lb        $a2, -0x40b8($at)
/* 6DD364 802195C4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD368 802195C8 00000043 */  sra       $zero, $zero, 1
/* 6DD36C 802195CC 00000003 */  sra       $zero, $zero, 0
/* 6DD370 802195D0 8026F0EC */  lb        $a2, -0xf14($at)
/* 6DD374 802195D4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD378 802195D8 00000000 */  nop       
/* 6DD37C 802195DC 00000043 */  sra       $zero, $zero, 1
/* 6DD380 802195E0 00000004 */  sllv      $zero, $zero, $zero
/* 6DD384 802195E4 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6DD388 802195E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD38C 802195EC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD390 802195F0 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD394 802195F4 00000043 */  sra       $zero, $zero, 1
/* 6DD398 802195F8 00000003 */  sra       $zero, $zero, 0
/* 6DD39C 802195FC 8027C6A0 */  lb        $a3, -0x3960($at)
/* 6DD3A0 80219600 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD3A4 80219604 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DD3A8 80219608 00000014 */  dsllv     $zero, $zero, $zero
/* 6DD3AC 8021960C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD3B0 80219610 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DD3B4 80219614 00000016 */  dsrlv     $zero, $zero, $zero
/* 6DD3B8 80219618 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD3BC 8021961C 0000000A */  movz      $zero, $zero, $zero
/* 6DD3C0 80219620 00000043 */  sra       $zero, $zero, 1
/* 6DD3C4 80219624 00000002 */  srl       $zero, $zero, 0
/* 6DD3C8 80219628 8024E61C */  lb        $a0, -0x19e4($at)
/* 6DD3CC 8021962C 00000013 */  mtlo      $zero
/* 6DD3D0 80219630 00000043 */  sra       $zero, $zero, 1
/* 6DD3D4 80219634 00000004 */  sllv      $zero, $zero, $zero
/* 6DD3D8 80219638 8024E90C */  lb        $a0, -0x16f4($at)
/* 6DD3DC 8021963C 00000045 */  lsa       $zero, $zero, $zero, 2
/* 6DD3E0 80219640 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6DD3E4 80219644 FFFFFFEE */  sd        $ra, -0x12($ra)
/* 6DD3E8 80219648 00000043 */  sra       $zero, $zero, 1
/* 6DD3EC 8021964C 00000002 */  srl       $zero, $zero, 0
/* 6DD3F0 80219650 8024EC6C */  lb        $a0, -0x1394($at)
/* 6DD3F4 80219654 00000154 */  .byte     0x00, 0x00, 0x01, 0x54
/* 6DD3F8 80219658 00000043 */  sra       $zero, $zero, 1
/* 6DD3FC 8021965C 00000002 */  srl       $zero, $zero, 0
/* 6DD400 80219660 8024EA58 */  lb        $a0, -0x15a8($at)
/* 6DD404 80219664 0000003E */  dsrl32    $zero, $zero, 0
/* 6DD408 80219668 00000043 */  sra       $zero, $zero, 1
/* 6DD40C 8021966C 00000002 */  srl       $zero, $zero, 0
/* 6DD410 80219670 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6DD414 80219674 00000014 */  dsllv     $zero, $zero, $zero
/* 6DD418 80219678 00000043 */  sra       $zero, $zero, 1
/* 6DD41C 8021967C 00000002 */  srl       $zero, $zero, 0
/* 6DD420 80219680 8024ED78 */  lb        $a0, -0x1288($at)
/* 6DD424 80219684 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD428 80219688 00000008 */  jr        $zero
/* 6DD42C 8021968C 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80219690_6DD430
/* 6DD430 80219690 00000014 */  dsllv     $zero, $zero, $zero
/* 6DD434 80219694 00000043 */  sra       $zero, $zero, 1
/* 6DD438 80219698 00000006 */  srlv      $zero, $zero, $zero
/* 6DD43C 8021969C 80252F30 */  lb        $a1, 0x2f30($at)
/* 6DD440 802196A0 00130097 */  .byte     0x00, 0x13, 0x00, 0x97
/* 6DD444 802196A4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD448 802196A8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD44C 802196AC 00610009 */  .byte     0x00, 0x61, 0x00, 0x09
/* 6DD450 802196B0 00610005 */  lsa       $zero, $v1, $at, 1
/* 6DD454 802196B4 00000008 */  jr        $zero
/* 6DD458 802196B8 00000001 */   movf     $zero, $zero, $fcc0

glabel func_802196BC_6DD45C
/* 6DD45C 802196BC 0000000A */  movz      $zero, $zero, $zero
/* 6DD460 802196C0 00000043 */  sra       $zero, $zero, 1
/* 6DD464 802196C4 00000002 */  srl       $zero, $zero, 0
/* 6DD468 802196C8 8024ED78 */  lb        $a0, -0x1288($at)
/* 6DD46C 802196CC 00000000 */  nop       
/* 6DD470 802196D0 00000043 */  sra       $zero, $zero, 1
/* 6DD474 802196D4 00000002 */  srl       $zero, $zero, 0
/* 6DD478 802196D8 8024E61C */  lb        $a0, -0x19e4($at)
/* 6DD47C 802196DC 00000002 */  srl       $zero, $zero, 0
/* 6DD480 802196E0 0000001D */  dmultu    $zero, $zero
/* 6DD484 802196E4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD488 802196E8 00000009 */  jr        $zero
/* 6DD48C 802196EC 0000001D */   dmultu   $zero, $zero

glabel func_802196F0_6DD490
/* 6DD490 802196F0 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD494 802196F4 00000008 */  jr        $zero
/* 6DD498 802196F8 00000043 */   sra      $zero, $zero, 1

glabel func_802196FC_6DD49C
/* 6DD49C 802196FC 00000002 */  srl       $zero, $zero, 0
/* 6DD4A0 80219700 8024E61C */  lb        $a0, -0x19e4($at)
/* 6DD4A4 80219704 00000013 */  mtlo      $zero
/* 6DD4A8 80219708 00000043 */  sra       $zero, $zero, 1
/* 6DD4AC 8021970C 00000004 */  sllv      $zero, $zero, $zero
/* 6DD4B0 80219710 8024E90C */  lb        $a0, -0x16f4($at)
/* 6DD4B4 80219714 00000045 */  lsa       $zero, $zero, $zero, 2
/* 6DD4B8 80219718 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6DD4BC 8021971C FFFFFFEE */  sd        $ra, -0x12($ra)
/* 6DD4C0 80219720 00000043 */  sra       $zero, $zero, 1
/* 6DD4C4 80219724 00000002 */  srl       $zero, $zero, 0
/* 6DD4C8 80219728 8024EC6C */  lb        $a0, -0x1394($at)
/* 6DD4CC 8021972C 00000154 */  .byte     0x00, 0x00, 0x01, 0x54
/* 6DD4D0 80219730 00000043 */  sra       $zero, $zero, 1
/* 6DD4D4 80219734 00000002 */  srl       $zero, $zero, 0
/* 6DD4D8 80219738 8024EA58 */  lb        $a0, -0x15a8($at)
/* 6DD4DC 8021973C 0000003E */  dsrl32    $zero, $zero, 0
/* 6DD4E0 80219740 00000043 */  sra       $zero, $zero, 1
/* 6DD4E4 80219744 00000002 */  srl       $zero, $zero, 0
/* 6DD4E8 80219748 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6DD4EC 8021974C 00000014 */  dsllv     $zero, $zero, $zero
/* 6DD4F0 80219750 00000043 */  sra       $zero, $zero, 1
/* 6DD4F4 80219754 00000002 */  srl       $zero, $zero, 0
/* 6DD4F8 80219758 8024ED78 */  lb        $a0, -0x1288($at)
/* 6DD4FC 8021975C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD500 80219760 00000008 */  jr        $zero
/* 6DD504 80219764 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80219768_6DD508
/* 6DD508 80219768 00000014 */  dsllv     $zero, $zero, $zero
/* 6DD50C 8021976C 00000043 */  sra       $zero, $zero, 1
/* 6DD510 80219770 00000006 */  srlv      $zero, $zero, $zero
/* 6DD514 80219774 80252F30 */  lb        $a1, 0x2f30($at)
/* 6DD518 80219778 00130098 */  .byte     0x00, 0x13, 0x00, 0x98
/* 6DD51C 8021977C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD520 80219780 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD524 80219784 0061000A */  movz      $zero, $v1, $at
/* 6DD528 80219788 00610005 */  lsa       $zero, $v1, $at, 1
/* 6DD52C 8021978C 00000008 */  jr        $zero
/* 6DD530 80219790 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80219794_6DD534
/* 6DD534 80219794 0000000A */  movz      $zero, $zero, $zero
/* 6DD538 80219798 00000043 */  sra       $zero, $zero, 1
/* 6DD53C 8021979C 00000002 */  srl       $zero, $zero, 0
/* 6DD540 802197A0 8024ED78 */  lb        $a0, -0x1288($at)
/* 6DD544 802197A4 00000000 */  nop       
/* 6DD548 802197A8 00000043 */  sra       $zero, $zero, 1
/* 6DD54C 802197AC 00000002 */  srl       $zero, $zero, 0
/* 6DD550 802197B0 8024E61C */  lb        $a0, -0x19e4($at)
/* 6DD554 802197B4 00000002 */  srl       $zero, $zero, 0
/* 6DD558 802197B8 00000020 */  add       $zero, $zero, $zero
/* 6DD55C 802197BC 00000000 */  nop       
/* 6DD560 802197C0 0000001D */  dmultu    $zero, $zero
/* 6DD564 802197C4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD568 802197C8 00000007 */  srav      $zero, $zero, $zero
/* 6DD56C 802197CC 0000001D */  dmultu    $zero, $zero
/* 6DD570 802197D0 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD574 802197D4 00000006 */  srlv      $zero, $zero, $zero
/* 6DD578 802197D8 0000001D */  dmultu    $zero, $zero
/* 6DD57C 802197DC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD580 802197E0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DD584 802197E4 0000001D */  dmultu    $zero, $zero
/* 6DD588 802197E8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD58C 802197EC 00000004 */  sllv      $zero, $zero, $zero
/* 6DD590 802197F0 0000001D */  dmultu    $zero, $zero
/* 6DD594 802197F4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD598 802197F8 00000003 */  sra       $zero, $zero, 0
/* 6DD59C 802197FC 0000001D */  dmultu    $zero, $zero
/* 6DD5A0 80219800 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD5A4 80219804 00000002 */  srl       $zero, $zero, 0
/* 6DD5A8 80219808 0000001D */  dmultu    $zero, $zero
/* 6DD5AC 8021980C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD5B0 80219810 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD5B4 80219814 00000043 */  sra       $zero, $zero, 1
/* 6DD5B8 80219818 00000004 */  sllv      $zero, $zero, $zero
/* 6DD5BC 8021981C 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6DD5C0 80219820 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD5C4 80219824 00000000 */  nop       
/* 6DD5C8 80219828 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DD5CC 8021982C 0000000A */  movz      $zero, $zero, $zero
/* 6DD5D0 80219830 00000002 */  srl       $zero, $zero, 0
/* 6DD5D4 80219834 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DD5D8 80219838 00000002 */  srl       $zero, $zero, 0
/* 6DD5DC 8021983C 00000022 */  neg       $zero, $zero
/* 6DD5E0 80219840 00000000 */  nop       
/* 6DD5E4 80219844 00000013 */  mtlo      $zero
/* 6DD5E8 80219848 00000000 */  nop       
/* 6DD5EC 8021984C 00000043 */  sra       $zero, $zero, 1
/* 6DD5F0 80219850 00000002 */  srl       $zero, $zero, 0
/* 6DD5F4 80219854 8024E61C */  lb        $a0, -0x19e4($at)
/* 6DD5F8 80219858 00000013 */  mtlo      $zero
/* 6DD5FC 8021985C 00000043 */  sra       $zero, $zero, 1
/* 6DD600 80219860 00000004 */  sllv      $zero, $zero, $zero
/* 6DD604 80219864 8024E90C */  lb        $a0, -0x16f4($at)
/* 6DD608 80219868 00000045 */  lsa       $zero, $zero, $zero, 2
/* 6DD60C 8021986C 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6DD610 80219870 FFFFFFEE */  sd        $ra, -0x12($ra)
/* 6DD614 80219874 00000043 */  sra       $zero, $zero, 1
/* 6DD618 80219878 00000002 */  srl       $zero, $zero, 0
/* 6DD61C 8021987C 8024EC6C */  lb        $a0, -0x1394($at)
/* 6DD620 80219880 00000154 */  .byte     0x00, 0x00, 0x01, 0x54
/* 6DD624 80219884 00000043 */  sra       $zero, $zero, 1
/* 6DD628 80219888 00000002 */  srl       $zero, $zero, 0
/* 6DD62C 8021988C 8024EA58 */  lb        $a0, -0x15a8($at)
/* 6DD630 80219890 0000003E */  dsrl32    $zero, $zero, 0
/* 6DD634 80219894 00000043 */  sra       $zero, $zero, 1
/* 6DD638 80219898 00000002 */  srl       $zero, $zero, 0
/* 6DD63C 8021989C 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6DD640 802198A0 00000014 */  dsllv     $zero, $zero, $zero
/* 6DD644 802198A4 00000043 */  sra       $zero, $zero, 1
/* 6DD648 802198A8 00000002 */  srl       $zero, $zero, 0
/* 6DD64C 802198AC 8024ED78 */  lb        $a0, -0x1288($at)
/* 6DD650 802198B0 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD654 802198B4 00000008 */  jr        $zero
/* 6DD658 802198B8 00000001 */   movf     $zero, $zero, $fcc0

glabel func_802198BC_6DD65C
/* 6DD65C 802198BC 00000014 */  dsllv     $zero, $zero, $zero
/* 6DD660 802198C0 00000043 */  sra       $zero, $zero, 1
/* 6DD664 802198C4 00000006 */  srlv      $zero, $zero, $zero
/* 6DD668 802198C8 80252F30 */  lb        $a1, 0x2f30($at)
/* 6DD66C 802198CC 00130099 */  .byte     0x00, 0x13, 0x00, 0x99
/* 6DD670 802198D0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD674 802198D4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD678 802198D8 00610006 */  srlv      $zero, $at, $v1
/* 6DD67C 802198DC 00610005 */  lsa       $zero, $v1, $at, 1
/* 6DD680 802198E0 00000008 */  jr        $zero
/* 6DD684 802198E4 00000001 */   movf     $zero, $zero, $fcc0

glabel func_802198E8_6DD688
/* 6DD688 802198E8 0000000A */  movz      $zero, $zero, $zero
/* 6DD68C 802198EC 00000043 */  sra       $zero, $zero, 1
/* 6DD690 802198F0 00000002 */  srl       $zero, $zero, 0
/* 6DD694 802198F4 8024ED78 */  lb        $a0, -0x1288($at)
/* 6DD698 802198F8 00000000 */  nop       
/* 6DD69C 802198FC 00000043 */  sra       $zero, $zero, 1
/* 6DD6A0 80219900 00000002 */  srl       $zero, $zero, 0
/* 6DD6A4 80219904 8024E61C */  lb        $a0, -0x19e4($at)
/* 6DD6A8 80219908 00000002 */  srl       $zero, $zero, 0
/* 6DD6AC 8021990C 00000043 */  sra       $zero, $zero, 1
/* 6DD6B0 80219910 00000004 */  sllv      $zero, $zero, $zero
/* 6DD6B4 80219914 8026C0D4 */  lb        $a2, -0x3f2c($at)
/* 6DD6B8 80219918 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD6BC 8021991C 00000000 */  nop       
/* 6DD6C0 80219920 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD6C4 80219924 00000020 */  add       $zero, $zero, $zero
/* 6DD6C8 80219928 00000000 */  nop       
/* 6DD6CC 8021992C 00000023 */  negu      $zero, $zero
/* 6DD6D0 80219930 00000000 */  nop       
/* 6DD6D4 80219934 00000043 */  sra       $zero, $zero, 1
/* 6DD6D8 80219938 00000004 */  sllv      $zero, $zero, $zero
/* 6DD6DC 8021993C 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6DD6E0 80219940 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD6E4 80219944 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD6E8 80219948 00000000 */  nop       
/* 6DD6EC 8021994C 00000043 */  sra       $zero, $zero, 1
/* 6DD6F0 80219950 00000003 */  sra       $zero, $zero, 0
/* 6DD6F4 80219954 8026F0EC */  lb        $a2, -0xf14($at)
/* 6DD6F8 80219958 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD6FC 8021995C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD700 80219960 00000043 */  sra       $zero, $zero, 1
/* 6DD704 80219964 00000002 */  srl       $zero, $zero, 0
/* 6DD708 80219968 8026BF48 */  lb        $a2, -0x40b8($at)
/* 6DD70C 8021996C 00000000 */  nop       
/* 6DD710 80219970 00000002 */  srl       $zero, $zero, 0
/* 6DD714 80219974 00000000 */  nop       
/* 6DD718 80219978 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD71C 8021997C 00000000 */  nop       
/* 6DD720 80219980 00000043 */  sra       $zero, $zero, 1
/* 6DD724 80219984 00000003 */  sra       $zero, $zero, 0
/* 6DD728 80219988 80278B4C */  lb        $a3, -0x74b4($at)
/* 6DD72C 8021998C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD730 80219990 00000000 */  nop       
/* 6DD734 80219994 00000043 */  sra       $zero, $zero, 1
/* 6DD738 80219998 00000002 */  srl       $zero, $zero, 0
/* 6DD73C 8021999C 8027D32C */  lb        $a3, -0x2cd4($at)
/* 6DD740 802199A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD744 802199A4 00000043 */  sra       $zero, $zero, 1
/* 6DD748 802199A8 00000002 */  srl       $zero, $zero, 0
/* 6DD74C 802199AC 8024E61C */  lb        $a0, -0x19e4($at)
/* 6DD750 802199B0 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6DD754 802199B4 00000043 */  sra       $zero, $zero, 1
/* 6DD758 802199B8 00000002 */  srl       $zero, $zero, 0
/* 6DD75C 802199BC 8024EB24 */  lb        $a0, -0x14dc($at)
/* 6DD760 802199C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD764 802199C4 00000043 */  sra       $zero, $zero, 1
/* 6DD768 802199C8 00000002 */  srl       $zero, $zero, 0
/* 6DD76C 802199CC 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6DD770 802199D0 0000003C */  dsll32    $zero, $zero, 0
/* 6DD774 802199D4 00000008 */  jr        $zero
/* 6DD778 802199D8 00000001 */   movf     $zero, $zero, $fcc0

glabel func_802199DC_6DD77C
/* 6DD77C 802199DC 0000000A */  movz      $zero, $zero, $zero
/* 6DD780 802199E0 00000043 */  sra       $zero, $zero, 1
/* 6DD784 802199E4 00000004 */  sllv      $zero, $zero, $zero
/* 6DD788 802199E8 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6DD78C 802199EC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD790 802199F0 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD794 802199F4 00610002 */  .byte     0x00, 0x61, 0x00, 0x02
/* 6DD798 802199F8 00000043 */  sra       $zero, $zero, 1
/* 6DD79C 802199FC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DD7A0 80219A00 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6DD7A4 80219A04 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD7A8 80219A08 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DD7AC 80219A0C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DD7B0 80219A10 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DD7B4 80219A14 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6DD7B8 80219A18 00000002 */  srl       $zero, $zero, 0
/* 6DD7BC 80219A1C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DD7C0 80219A20 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD7C4 80219A24 00000043 */  sra       $zero, $zero, 1
/* 6DD7C8 80219A28 00000006 */  srlv      $zero, $zero, $zero
/* 6DD7CC 80219A2C 8026AF18 */  lb        $a2, -0x50e8($at)
/* 6DD7D0 80219A30 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD7D4 80219A34 00000002 */  srl       $zero, $zero, 0
/* 6DD7D8 80219A38 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DD7DC 80219A3C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DD7E0 80219A40 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DD7E4 80219A44 00000043 */  sra       $zero, $zero, 1
/* 6DD7E8 80219A48 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DD7EC 80219A4C 8026D010 */  lb        $a2, -0x2ff0($at)
/* 6DD7F0 80219A50 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD7F4 80219A54 00000002 */  srl       $zero, $zero, 0
/* 6DD7F8 80219A58 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD7FC 80219A5C 00000000 */  nop       
/* 6DD800 80219A60 00000043 */  sra       $zero, $zero, 1
/* 6DD804 80219A64 00000003 */  sra       $zero, $zero, 0
/* 6DD808 80219A68 8025385C */  lb        $a1, 0x385c($at)
/* 6DD80C 80219A6C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD810 80219A70 00000301 */  .byte     0x00, 0x00, 0x03, 0x01
/* 6DD814 80219A74 00000043 */  sra       $zero, $zero, 1
/* 6DD818 80219A78 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DD81C 80219A7C 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6DD820 80219A80 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD824 80219A84 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DD828 80219A88 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DD82C 80219A8C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DD830 80219A90 00000024 */  and       $zero, $zero, $zero
/* 6DD834 80219A94 00000002 */  srl       $zero, $zero, 0
/* 6DD838 80219A98 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DD83C 80219A9C 00000000 */  nop       
/* 6DD840 80219AA0 00000043 */  sra       $zero, $zero, 1
/* 6DD844 80219AA4 00000003 */  sra       $zero, $zero, 0
/* 6DD848 80219AA8 8026B55C */  lb        $a2, -0x4aa4($at)
/* 6DD84C 80219AAC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD850 80219AB0 F24A7DB4 */  scd       $t2, 0x7db4($s2)
/* 6DD854 80219AB4 00000043 */  sra       $zero, $zero, 1
/* 6DD858 80219AB8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DD85C 80219ABC 8026A510 */  lb        $a2, -0x5af0($at)
/* 6DD860 80219AC0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD864 80219AC4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DD868 80219AC8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DD86C 80219ACC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DD870 80219AD0 00000043 */  sra       $zero, $zero, 1
/* 6DD874 80219AD4 00000006 */  srlv      $zero, $zero, $zero
/* 6DD878 80219AD8 80278D08 */  lb        $a3, -0x72f8($at)
/* 6DD87C 80219ADC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD880 80219AE0 0000000F */  sync      
/* 6DD884 80219AE4 00000000 */  nop       
/* 6DD888 80219AE8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD88C 80219AEC 00000000 */  nop       
/* 6DD890 80219AF0 00000043 */  sra       $zero, $zero, 1
/* 6DD894 80219AF4 00000003 */  sra       $zero, $zero, 0
/* 6DD898 80219AF8 8025385C */  lb        $a1, 0x385c($at)
/* 6DD89C 80219AFC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD8A0 80219B00 000020E4 */  .byte     0x00, 0x00, 0x20, 0xe4
/* 6DD8A4 80219B04 00000043 */  sra       $zero, $zero, 1
/* 6DD8A8 80219B08 00000002 */  srl       $zero, $zero, 0
/* 6DD8AC 80219B0C 8024E61C */  lb        $a0, -0x19e4($at)
/* 6DD8B0 80219B10 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD8B4 80219B14 00000043 */  sra       $zero, $zero, 1
/* 6DD8B8 80219B18 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DD8BC 80219B1C 8026A510 */  lb        $a2, -0x5af0($at)
/* 6DD8C0 80219B20 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD8C4 80219B24 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DD8C8 80219B28 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DD8CC 80219B2C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DD8D0 80219B30 00000043 */  sra       $zero, $zero, 1
/* 6DD8D4 80219B34 00000006 */  srlv      $zero, $zero, $zero
/* 6DD8D8 80219B38 80278D08 */  lb        $a3, -0x72f8($at)
/* 6DD8DC 80219B3C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD8E0 80219B40 0000000A */  movz      $zero, $zero, $zero
/* 6DD8E4 80219B44 00000000 */  nop       
/* 6DD8E8 80219B48 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD8EC 80219B4C 00000000 */  nop       
/* 6DD8F0 80219B50 00000043 */  sra       $zero, $zero, 1
/* 6DD8F4 80219B54 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DD8F8 80219B58 8026A510 */  lb        $a2, -0x5af0($at)
/* 6DD8FC 80219B5C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD900 80219B60 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DD904 80219B64 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DD908 80219B68 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DD90C 80219B6C 00000043 */  sra       $zero, $zero, 1
/* 6DD910 80219B70 00000006 */  srlv      $zero, $zero, $zero
/* 6DD914 80219B74 80278D08 */  lb        $a3, -0x72f8($at)
/* 6DD918 80219B78 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD91C 80219B7C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DD920 80219B80 00000000 */  nop       
/* 6DD924 80219B84 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD928 80219B88 00000000 */  nop       
/* 6DD92C 80219B8C 00000043 */  sra       $zero, $zero, 1
/* 6DD930 80219B90 00000003 */  sra       $zero, $zero, 0
/* 6DD934 80219B94 8025385C */  lb        $a1, 0x385c($at)
/* 6DD938 80219B98 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD93C 80219B9C 000020E5 */  .byte     0x00, 0x00, 0x20, 0xe5
/* 6DD940 80219BA0 00000043 */  sra       $zero, $zero, 1
/* 6DD944 80219BA4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DD948 80219BA8 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6DD94C 80219BAC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD950 80219BB0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DD954 80219BB4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DD958 80219BB8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DD95C 80219BBC 00000043 */  sra       $zero, $zero, 1
/* 6DD960 80219BC0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DD964 80219BC4 8026A1EC */  lb        $a2, -0x5e14($at)
/* 6DD968 80219BC8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD96C 80219BCC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DD970 80219BD0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DD974 80219BD4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DD978 80219BD8 00000043 */  sra       $zero, $zero, 1
/* 6DD97C 80219BDC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DD980 80219BE0 8026EE88 */  lb        $a2, -0x1178($at)
/* 6DD984 80219BE4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD988 80219BE8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD98C 80219BEC 00000000 */  nop       
/* 6DD990 80219BF0 00000003 */  sra       $zero, $zero, 0
/* 6DD994 80219BF4 00000043 */  sra       $zero, $zero, 1
/* 6DD998 80219BF8 00000004 */  sllv      $zero, $zero, $zero
/* 6DD99C 80219BFC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6DD9A0 80219C00 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD9A4 80219C04 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD9A8 80219C08 00610003 */  .byte     0x00, 0x61, 0x00, 0x03
/* 6DD9AC 80219C0C 00000008 */  jr        $zero
/* 6DD9B0 80219C10 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80219C14_6DD9B4
/* 6DD9B4 80219C14 00000032 */  tlt       $zero, $zero
/* 6DD9B8 80219C18 00000043 */  sra       $zero, $zero, 1
/* 6DD9BC 80219C1C 00000003 */  sra       $zero, $zero, 0
/* 6DD9C0 80219C20 8026CD3C */  lb        $a2, -0x32c4($at)
/* 6DD9C4 80219C24 00060000 */  sll       $zero, $a2, 0
/* 6DD9C8 80219C28 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD9CC 80219C2C 00000043 */  sra       $zero, $zero, 1
/* 6DD9D0 80219C30 00000004 */  sllv      $zero, $zero, $zero
/* 6DD9D4 80219C34 8026CE8C */  lb        $a2, -0x3174($at)
/* 6DD9D8 80219C38 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD9DC 80219C3C 00400000 */  .byte     0x00, 0x40, 0x00, 0x00
/* 6DD9E0 80219C40 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD9E4 80219C44 00000043 */  sra       $zero, $zero, 1
/* 6DD9E8 80219C48 00000006 */  srlv      $zero, $zero, $zero
/* 6DD9EC 80219C4C 80252F30 */  lb        $a1, 0x2f30($at)
/* 6DD9F0 80219C50 0013009B */  .byte     0x00, 0x13, 0x00, 0x9b
/* 6DD9F4 80219C54 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6DD9F8 80219C58 00000001 */  movf      $zero, $zero, $fcc0
/* 6DD9FC 80219C5C 00610003 */  .byte     0x00, 0x61, 0x00, 0x03
/* 6DDA00 80219C60 00610003 */  .byte     0x00, 0x61, 0x00, 0x03
/* 6DDA04 80219C64 00000008 */  jr        $zero
/* 6DDA08 80219C68 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80219C6C_6DDA0C
/* 6DDA0C 80219C6C 0000000A */  movz      $zero, $zero, $zero
/* 6DDA10 80219C70 00000043 */  sra       $zero, $zero, 1
/* 6DDA14 80219C74 00000002 */  srl       $zero, $zero, 0
/* 6DDA18 80219C78 8024E61C */  lb        $a0, -0x19e4($at)
/* 6DDA1C 80219C7C 00000002 */  srl       $zero, $zero, 0
/* 6DDA20 80219C80 00000043 */  sra       $zero, $zero, 1
/* 6DDA24 80219C84 00000002 */  srl       $zero, $zero, 0
/* 6DDA28 80219C88 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6DDA2C 80219C8C 0000003C */  dsll32    $zero, $zero, 0
/* 6DDA30 80219C90 00000008 */  jr        $zero
/* 6DDA34 80219C94 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80219C98_6DDA38
/* 6DDA38 80219C98 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6DDA3C 80219C9C 00000043 */  sra       $zero, $zero, 1
/* 6DDA40 80219CA0 00000003 */  sra       $zero, $zero, 0
/* 6DDA44 80219CA4 8026CD3C */  lb        $a2, -0x32c4($at)
/* 6DDA48 80219CA8 00100000 */  sll       $zero, $s0, 0
/* 6DDA4C 80219CAC 00000000 */  nop       
/* 6DDA50 80219CB0 00000002 */  srl       $zero, $zero, 0
/* 6DDA54 80219CB4 00000000 */  nop       
/* 6DDA58 80219CB8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDA5C 80219CBC 00000000 */  nop       
/* 6DDA60 80219CC0 FFFFFFEA */  sd        $ra, -0x16($ra)
/* 6DDA64 80219CC4 000000BE */  dsrl32    $zero, $zero, 2
/* 6DDA68 80219CC8 FFFFFFA5 */  sd        $ra, -0x5b($ra)
/* 6DDA6C 80219CCC FFFFFFA8 */  sd        $ra, -0x58($ra)
/* 6DDA70 80219CD0 00000015 */  dlsa      $zero, $zero, $zero, 1
/* 6DDA74 80219CD4 FFFFFFA5 */  sd        $ra, -0x5b($ra)
/* 6DDA78 80219CD8 0000003C */  dsll32    $zero, $zero, 0
/* 6DDA7C 80219CDC FFFFFFFF */  sd        $ra, -1($ra)
/* 6DDA80 80219CE0 000000BE */  dsrl32    $zero, $zero, 2
/* 6DDA84 80219CE4 FFFFFFA5 */  sd        $ra, -0x5b($ra)
/* 6DDA88 80219CE8 00000058 */  .byte     0x00, 0x00, 0x00, 0x58
/* 6DDA8C 80219CEC 00000018 */  mult      $zero, $zero
/* 6DDA90 80219CF0 FFFFFFA5 */  sd        $ra, -0x5b($ra)
/* 6DDA94 80219CF4 0000000A */  movz      $zero, $zero, $zero
/* 6DDA98 80219CF8 FFFFFFBD */  sd        $ra, -0x43($ra)
/* 6DDA9C 80219CFC 000000BE */  dsrl32    $zero, $zero, 2
/* 6DDAA0 80219D00 FFFFFFA5 */  sd        $ra, -0x5b($ra)
/* 6DDAA4 80219D04 FFFFFF86 */  sd        $ra, -0x7a($ra)
/* 6DDAA8 80219D08 0000000A */  movz      $zero, $zero, $zero
/* 6DDAAC 80219D0C FFFFFFA5 */  sd        $ra, -0x5b($ra)
/* 6DDAB0 80219D10 0000005A */  .byte     0x00, 0x00, 0x00, 0x5a
/* 6DDAB4 80219D14 00000039 */  .byte     0x00, 0x00, 0x00, 0x39
/* 6DDAB8 80219D18 000000BE */  dsrl32    $zero, $zero, 2
/* 6DDABC 80219D1C FFFFFFA5 */  sd        $ra, -0x5b($ra)
/* 6DDAC0 80219D20 FFFFFFFC */  sd        $ra, -4($ra)
/* 6DDAC4 80219D24 00000011 */  mthi      $zero
/* 6DDAC8 80219D28 FFFFFFA5 */  sd        $ra, -0x5b($ra)
/* 6DDACC 80219D2C 0000003C */  dsll32    $zero, $zero, 0
/* 6DDAD0 80219D30 00000003 */  sra       $zero, $zero, 0
/* 6DDAD4 80219D34 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDAD8 80219D38 00000000 */  nop       
/* 6DDADC 80219D3C 00000030 */  tge       $zero, $zero
/* 6DDAE0 80219D40 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDAE4 80219D44 80219CC0 */  lb        $at, -0x6340($at)
/* 6DDAE8 80219D48 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DDAEC 80219D4C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDAF0 80219D50 00000004 */  sllv      $zero, $zero, $zero
/* 6DDAF4 80219D54 00000033 */  tltu      $zero, $zero
/* 6DDAF8 80219D58 00000003 */  sra       $zero, $zero, 0
/* 6DDAFC 80219D5C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DDB00 80219D60 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DDB04 80219D64 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DDB08 80219D68 00000033 */  tltu      $zero, $zero
/* 6DDB0C 80219D6C 00000003 */  sra       $zero, $zero, 0
/* 6DDB10 80219D70 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DDB14 80219D74 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6DDB18 80219D78 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6DDB1C 80219D7C 00000043 */  sra       $zero, $zero, 1
/* 6DDB20 80219D80 0000000F */  sync      
/* 6DDB24 80219D84 802D829C */  lb        $t5, -0x7d64($at)
/* 6DDB28 80219D88 0000005E */  .byte     0x00, 0x00, 0x00, 0x5e
/* 6DDB2C 80219D8C 00000000 */  nop       
/* 6DDB30 80219D90 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DDB34 80219D94 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DDB38 80219D98 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DDB3C 80219D9C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DDB40 80219DA0 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6DDB44 80219DA4 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6DDB48 80219DA8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDB4C 80219DAC 00000008 */  jr        $zero
/* 6DDB50 80219DB0 00000000 */   nop      
/* 6DDB54 80219DB4 00000000 */  nop       
/* 6DDB58 80219DB8 00000000 */  nop       
/* 6DDB5C 80219DBC 00000000 */  nop       

glabel func_80219DC0_6DDB60
/* 6DDB60 80219DC0 00000043 */  sra       $zero, $zero, 1
/* 6DDB64 80219DC4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDB68 80219DC8 80218550 */  lb        $at, -0x7ab0($at)
/* 6DDB6C 80219DCC 00000031 */  tgeu      $zero, $zero
/* 6DDB70 80219DD0 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDB74 80219DD4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DDB78 80219DD8 00000008 */  jr        $zero
/* 6DDB7C 80219DDC 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80219DE0_6DDB80
/* 6DDB80 80219DE0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DDB84 80219DE4 00000006 */  srlv      $zero, $zero, $zero
/* 6DDB88 80219DE8 00000000 */  nop       
/* 6DDB8C 80219DEC 00000004 */  sllv      $zero, $zero, $zero
/* 6DDB90 80219DF0 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDB94 80219DF4 00000000 */  nop       
/* 6DDB98 80219DF8 00000002 */  srl       $zero, $zero, 0
/* 6DDB9C 80219DFC 00000000 */  nop       
/* 6DDBA0 80219E00 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDBA4 80219E04 00000000 */  nop       
/* 6DDBA8 80219E08 FFFFFF87 */  sd        $ra, -0x79($ra)
/* 6DDBAC 80219E0C 00000021 */  addu      $zero, $zero, $zero
/* 6DDBB0 80219E10 FFFFFF98 */  sd        $ra, -0x68($ra)
/* 6DDBB4 80219E14 FFFFFFE8 */  sd        $ra, -0x18($ra)
/* 6DDBB8 80219E18 00000029 */  .byte     0x00, 0x00, 0x00, 0x29
/* 6DDBBC 80219E1C FFFFFF98 */  sd        $ra, -0x68($ra)
/* 6DDBC0 80219E20 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DDBC4 80219E24 00000024 */  and       $zero, $zero, $zero
/* 6DDBC8 80219E28 00000029 */  .byte     0x00, 0x00, 0x00, 0x29
/* 6DDBCC 80219E2C FFFFFF98 */  sd        $ra, -0x68($ra)
/* 6DDBD0 80219E30 00000080 */  sll       $zero, $zero, 2
/* 6DDBD4 80219E34 00000022 */  neg       $zero, $zero
/* 6DDBD8 80219E38 FFFFFF98 */  sd        $ra, -0x68($ra)
/* 6DDBDC 80219E3C 0000001E */  ddiv      $zero, $zero, $zero
/* 6DDBE0 80219E40 00000092 */  .byte     0x00, 0x00, 0x00, 0x92
/* 6DDBE4 80219E44 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDBE8 80219E48 00000071 */  tgeu      $zero, $zero, 1
/* 6DDBEC 80219E4C 00000026 */  xor       $zero, $zero, $zero
/* 6DDBF0 80219E50 FFFFFFF1 */  sd        $ra, -0xf($ra)
/* 6DDBF4 80219E54 00000079 */  .byte     0x00, 0x00, 0x00, 0x79
/* 6DDBF8 80219E58 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DDBFC 80219E5C FFFFFFBE */  sd        $ra, -0x42($ra)
/* 6DDC00 80219E60 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 6DDC04 80219E64 00000073 */  tltu      $zero, $zero, 1
/* 6DDC08 80219E68 FFFFFF65 */  sd        $ra, -0x9b($ra)
/* 6DDC0C 80219E6C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDC10 80219E70 00000061 */  .byte     0x00, 0x00, 0x00, 0x61
/* 6DDC14 80219E74 0000005A */  .byte     0x00, 0x00, 0x00, 0x5a
/* 6DDC18 80219E78 00000003 */  sra       $zero, $zero, 0
/* 6DDC1C 80219E7C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDC20 80219E80 00000000 */  nop       
/* 6DDC24 80219E84 00000030 */  tge       $zero, $zero
/* 6DDC28 80219E88 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDC2C 80219E8C 80219E08 */  lb        $at, -0x61f8($at)
/* 6DDC30 80219E90 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DDC34 80219E94 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDC38 80219E98 00000004 */  sllv      $zero, $zero, $zero
/* 6DDC3C 80219E9C 00000033 */  tltu      $zero, $zero
/* 6DDC40 80219EA0 00000003 */  sra       $zero, $zero, 0
/* 6DDC44 80219EA4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DDC48 80219EA8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DDC4C 80219EAC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DDC50 80219EB0 00000033 */  tltu      $zero, $zero
/* 6DDC54 80219EB4 00000003 */  sra       $zero, $zero, 0
/* 6DDC58 80219EB8 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DDC5C 80219EBC FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6DDC60 80219EC0 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6DDC64 80219EC4 00000043 */  sra       $zero, $zero, 1
/* 6DDC68 80219EC8 0000000F */  sync      
/* 6DDC6C 80219ECC 802D829C */  lb        $t5, -0x7d64($at)
/* 6DDC70 80219ED0 0000005E */  .byte     0x00, 0x00, 0x00, 0x5e
/* 6DDC74 80219ED4 00000000 */  nop       
/* 6DDC78 80219ED8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DDC7C 80219EDC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DDC80 80219EE0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DDC84 80219EE4 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DDC88 80219EE8 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6DDC8C 80219EEC FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6DDC90 80219EF0 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDC94 80219EF4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DDC98 80219EF8 00000000 */  nop       
/* 6DDC9C 80219EFC 00000000 */  nop       
/* 6DDCA0 80219F00 00000000 */  nop       
/* 6DDCA4 80219F04 00000000 */  nop       
/* 6DDCA8 80219F08 00000043 */  sra       $zero, $zero, 1
/* 6DDCAC 80219F0C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDCB0 80219F10 80218550 */  lb        $at, -0x7ab0($at)
/* 6DDCB4 80219F14 00000031 */  tgeu      $zero, $zero
/* 6DDCB8 80219F18 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDCBC 80219F1C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DDCC0 80219F20 00000008 */  jr        $zero
/* 6DDCC4 80219F24 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80219F28_6DDCC8
/* 6DDCC8 80219F28 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DDCCC 80219F2C 00000006 */  srlv      $zero, $zero, $zero
/* 6DDCD0 80219F30 00000000 */  nop       
/* 6DDCD4 80219F34 00000004 */  sllv      $zero, $zero, $zero
/* 6DDCD8 80219F38 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDCDC 80219F3C 00000000 */  nop       
/* 6DDCE0 80219F40 00000002 */  srl       $zero, $zero, 0
/* 6DDCE4 80219F44 00000000 */  nop       
/* 6DDCE8 80219F48 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDCEC 80219F4C 00000000 */  nop       
/* 6DDCF0 80219F50 00000043 */  sra       $zero, $zero, 1
/* 6DDCF4 80219F54 00000002 */  srl       $zero, $zero, 0
/* 6DDCF8 80219F58 802D9700 */  lb        $t5, -0x6900($at)
/* 6DDCFC 80219F5C FFFFFFFF */  sd        $ra, -1($ra)
/* 6DDD00 80219F60 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DDD04 80219F64 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDD08 80219F68 80219D30 */  lb        $at, -0x62d0($at)
/* 6DDD0C 80219F6C 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DDD10 80219F70 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDD14 80219F74 80219E78 */  lb        $at, -0x6188($at)
/* 6DDD18 80219F78 00000002 */  srl       $zero, $zero, 0
/* 6DDD1C 80219F7C 00000000 */  nop       
/* 6DDD20 80219F80 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDD24 80219F84 00000000 */  nop       
/* 6DDD28 80219F88 00000002 */  srl       $zero, $zero, 0
/* 6DDD2C 80219F8C 00000000 */  nop       
/* 6DDD30 80219F90 00000001 */  movf      $zero, $zero, $fcc0
/* 6DDD34 80219F94 00000000 */  nop       
/* 6DDD38 80219F98 8021A018 */  lb        $at, -0x5fe8($at)
/* 6DDD3C 80219F9C 8021A008 */  lb        $at, -0x5ff8($at)
/* 6DDD40 80219FA0 80219FF8 */  lb        $at, -0x6008($at)
/* 6DDD44 80219FA4 80219F50 */  lb        $at, -0x60b0($at)
/* 6DDD48 80219FA8 80219F88 */  lb        $at, -0x6078($at)
/* 6DDD4C 80219FAC 80219FF0 */  lb        $at, -0x6010($at)
/* 6DDD50 80219FB0 00000000 */  nop       
/* 6DDD54 80219FB4 00000000 */  nop       
/* 6DDD58 80219FB8 00000000 */  nop       
/* 6DDD5C 80219FBC 00000000 */  nop       
/* 6DDD60 80219FC0 834A8381 */  lb        $t2, -0x7c7f($k0)
/* 6DDD64 80219FC4 8362834E */  lb        $v0, -0x7cb2($k1)
/* 6DDD68 80219FC8 82CE82CE */  lb        $t6, -0x7d32($s6)
/* 6DDD6C 80219FCC 81698373 */  lb        $t1, -0x7c8d($t3)
/* 6DDD70 80219FD0 815B8360 */  lb        $k1, -0x7ca0($t2)
/* 6DDD74 80219FD4 81418365 */  lb        $at, -0x7c9b($t2)
/* 6DDD78 80219FD8 83428393 */  lb        $v0, -0x7c6d($k0)
/* 6DDD7C 80219FDC 834E82B9 */  lb        $t6, -0x7d47($k0)
/* 6DDD80 80219FE0 82F1816A */  lb        $s1, -0x7e96($s7)
/* 6DDD84 80219FE4 00000000 */  nop       
/* 6DDD88 80219FE8 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DDD8C 80219FEC 30350000 */  andi      $s5, $at, 0
/* 6DDD90 80219FF0 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DDD94 80219FF4 62670000 */  daddi     $a3, $s3, 0
/* 6DDD98 80219FF8 6B6B6A5F */  ldl       $t3, 0x6a5f($k1)
/* 6DDD9C 80219FFC 62743032 */  daddi     $s4, $s3, 0x3032
/* 6DDDA0 8021A000 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 6DDDA4 8021A004 00000000 */  nop       
/* 6DDDA8 8021A008 6B6B6A5F */  ldl       $t3, 0x6a5f($k1)
/* 6DDDAC 8021A00C 62743032 */  daddi     $s4, $s3, 0x3032
/* 6DDDB0 8021A010 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 6DDDB4 8021A014 70650000 */  madd      $v1, $a1
/* 6DDDB8 8021A018 6B6B6A5F */  ldl       $t3, 0x6a5f($k1)
/* 6DDDBC 8021A01C 74657800 */  jalx      0x8195e000
