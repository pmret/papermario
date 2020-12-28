.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel func_80218000_6CC070
/* 6CC070 80218000 3C028022 */  lui       $v0, %hi(D_80218DF4)
/* 6CC074 80218004 24428DF4 */  addiu     $v0, $v0, %lo(D_80218DF4)
/* 6CC078 80218008 24030001 */  addiu     $v1, $zero, 1
/* 6CC07C 8021800C AC43000C */  sw        $v1, 0xc($v0)
/* 6CC080 80218010 8C830148 */  lw        $v1, 0x148($a0)
/* 6CC084 80218014 AC430010 */  sw        $v1, 0x10($v0)
/* 6CC088 80218018 03E00008 */  jr        $ra
/* 6CC08C 8021801C 24020002 */   addiu    $v0, $zero, 2
/* 6CC090 80218020 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 6CC094 80218024 AFB10014 */  sw        $s1, 0x14($sp)
/* 6CC098 80218028 0080882D */  daddu     $s1, $a0, $zero
/* 6CC09C 8021802C AFBF0020 */  sw        $ra, 0x20($sp)
/* 6CC0A0 80218030 AFB3001C */  sw        $s3, 0x1c($sp)
/* 6CC0A4 80218034 AFB20018 */  sw        $s2, 0x18($sp)
/* 6CC0A8 80218038 AFB00010 */  sw        $s0, 0x10($sp)
/* 6CC0AC 8021803C 8E30000C */  lw        $s0, 0xc($s1)
/* 6CC0B0 80218040 8E050000 */  lw        $a1, ($s0)
/* 6CC0B4 80218044 0C0B1EAF */  jal       get_variable
/* 6CC0B8 80218048 26100004 */   addiu    $s0, $s0, 4
/* 6CC0BC 8021804C 8E050000 */  lw        $a1, ($s0)
/* 6CC0C0 80218050 26100004 */  addiu     $s0, $s0, 4
/* 6CC0C4 80218054 0220202D */  daddu     $a0, $s1, $zero
/* 6CC0C8 80218058 0C0B1EAF */  jal       get_variable
/* 6CC0CC 8021805C 0040982D */   daddu    $s3, $v0, $zero
/* 6CC0D0 80218060 8E050000 */  lw        $a1, ($s0)
/* 6CC0D4 80218064 26100004 */  addiu     $s0, $s0, 4
/* 6CC0D8 80218068 0220202D */  daddu     $a0, $s1, $zero
/* 6CC0DC 8021806C 0C0B1EAF */  jal       get_variable
/* 6CC0E0 80218070 0040902D */   daddu    $s2, $v0, $zero
/* 6CC0E4 80218074 0220202D */  daddu     $a0, $s1, $zero
/* 6CC0E8 80218078 8E050000 */  lw        $a1, ($s0)
/* 6CC0EC 8021807C 0C0B1EAF */  jal       get_variable
/* 6CC0F0 80218080 0040802D */   daddu    $s0, $v0, $zero
/* 6CC0F4 80218084 8E240148 */  lw        $a0, 0x148($s1)
/* 6CC0F8 80218088 0C09A75B */  jal       get_actor
/* 6CC0FC 8021808C 0040882D */   daddu    $s1, $v0, $zero
/* 6CC100 80218090 0040182D */  daddu     $v1, $v0, $zero
/* 6CC104 80218094 8C620008 */  lw        $v0, 8($v1)
/* 6CC108 80218098 90420024 */  lbu       $v0, 0x24($v0)
/* 6CC10C 8021809C 8C640008 */  lw        $a0, 8($v1)
/* 6CC110 802180A0 02629823 */  subu      $s3, $s3, $v0
/* 6CC114 802180A4 A0730194 */  sb        $s3, 0x194($v1)
/* 6CC118 802180A8 90820025 */  lbu       $v0, 0x25($a0)
/* 6CC11C 802180AC 02429023 */  subu      $s2, $s2, $v0
/* 6CC120 802180B0 A0720195 */  sb        $s2, 0x195($v1)
/* 6CC124 802180B4 90820026 */  lbu       $v0, 0x26($a0)
/* 6CC128 802180B8 02028023 */  subu      $s0, $s0, $v0
/* 6CC12C 802180BC A0700196 */  sb        $s0, 0x196($v1)
/* 6CC130 802180C0 90840027 */  lbu       $a0, 0x27($a0)
/* 6CC134 802180C4 02248823 */  subu      $s1, $s1, $a0
/* 6CC138 802180C8 A0710197 */  sb        $s1, 0x197($v1)
/* 6CC13C 802180CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 6CC140 802180D0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 6CC144 802180D4 8FB20018 */  lw        $s2, 0x18($sp)
/* 6CC148 802180D8 8FB10014 */  lw        $s1, 0x14($sp)
/* 6CC14C 802180DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 6CC150 802180E0 24020002 */  addiu     $v0, $zero, 2
/* 6CC154 802180E4 03E00008 */  jr        $ra
/* 6CC158 802180E8 27BD0028 */   addiu    $sp, $sp, 0x28
/* 6CC15C 802180EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6CC160 802180F0 AFB10014 */  sw        $s1, 0x14($sp)
/* 6CC164 802180F4 0080882D */  daddu     $s1, $a0, $zero
/* 6CC168 802180F8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 6CC16C 802180FC AFB00010 */  sw        $s0, 0x10($sp)
/* 6CC170 80218100 8E30000C */  lw        $s0, 0xc($s1)
/* 6CC174 80218104 8E050000 */  lw        $a1, ($s0)
/* 6CC178 80218108 0C0B1EAF */  jal       get_variable
/* 6CC17C 8021810C 26100004 */   addiu    $s0, $s0, 4
/* 6CC180 80218110 0220202D */  daddu     $a0, $s1, $zero
/* 6CC184 80218114 8E050000 */  lw        $a1, ($s0)
/* 6CC188 80218118 0C0B1EAF */  jal       get_variable
/* 6CC18C 8021811C 0040802D */   daddu    $s0, $v0, $zero
/* 6CC190 80218120 0200202D */  daddu     $a0, $s0, $zero
/* 6CC194 80218124 0C00A3C2 */  jal       start_rumble
/* 6CC198 80218128 0040282D */   daddu    $a1, $v0, $zero
/* 6CC19C 8021812C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 6CC1A0 80218130 8FB10014 */  lw        $s1, 0x14($sp)
/* 6CC1A4 80218134 8FB00010 */  lw        $s0, 0x10($sp)
/* 6CC1A8 80218138 24020002 */  addiu     $v0, $zero, 2
/* 6CC1AC 8021813C 03E00008 */  jr        $ra
/* 6CC1B0 80218140 27BD0020 */   addiu    $sp, $sp, 0x20
/* 6CC1B4 80218144 00000000 */  nop       
/* 6CC1B8 80218148 00000000 */  nop       
/* 6CC1BC 8021814C 00000000 */  nop       
/* 6CC1C0 80218150 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 6CC1C4 80218154 AFB10024 */  sw        $s1, 0x24($sp)
/* 6CC1C8 80218158 0080882D */  daddu     $s1, $a0, $zero
/* 6CC1CC 8021815C AFBF0028 */  sw        $ra, 0x28($sp)
/* 6CC1D0 80218160 AFB00020 */  sw        $s0, 0x20($sp)
/* 6CC1D4 80218164 F7BE0058 */  sdc1      $f30, 0x58($sp)
/* 6CC1D8 80218168 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 6CC1DC 8021816C F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 6CC1E0 80218170 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 6CC1E4 80218174 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 6CC1E8 80218178 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 6CC1EC 8021817C 8E30000C */  lw        $s0, 0xc($s1)
/* 6CC1F0 80218180 8E050000 */  lw        $a1, ($s0)
/* 6CC1F4 80218184 0C0B210B */  jal       get_float_variable
/* 6CC1F8 80218188 26100004 */   addiu    $s0, $s0, 4
/* 6CC1FC 8021818C 8E050000 */  lw        $a1, ($s0)
/* 6CC200 80218190 26100004 */  addiu     $s0, $s0, 4
/* 6CC204 80218194 0220202D */  daddu     $a0, $s1, $zero
/* 6CC208 80218198 0C0B210B */  jal       get_float_variable
/* 6CC20C 8021819C 46000786 */   mov.s    $f30, $f0
/* 6CC210 802181A0 8E050000 */  lw        $a1, ($s0)
/* 6CC214 802181A4 26100004 */  addiu     $s0, $s0, 4
/* 6CC218 802181A8 0220202D */  daddu     $a0, $s1, $zero
/* 6CC21C 802181AC 0C0B210B */  jal       get_float_variable
/* 6CC220 802181B0 46000506 */   mov.s    $f20, $f0
/* 6CC224 802181B4 8E050000 */  lw        $a1, ($s0)
/* 6CC228 802181B8 26100004 */  addiu     $s0, $s0, 4
/* 6CC22C 802181BC 0220202D */  daddu     $a0, $s1, $zero
/* 6CC230 802181C0 0C0B210B */  jal       get_float_variable
/* 6CC234 802181C4 46000706 */   mov.s    $f28, $f0
/* 6CC238 802181C8 8E050000 */  lw        $a1, ($s0)
/* 6CC23C 802181CC 26100004 */  addiu     $s0, $s0, 4
/* 6CC240 802181D0 0220202D */  daddu     $a0, $s1, $zero
/* 6CC244 802181D4 0C0B210B */  jal       get_float_variable
/* 6CC248 802181D8 46000686 */   mov.s    $f26, $f0
/* 6CC24C 802181DC 8E050000 */  lw        $a1, ($s0)
/* 6CC250 802181E0 26100004 */  addiu     $s0, $s0, 4
/* 6CC254 802181E4 0220202D */  daddu     $a0, $s1, $zero
/* 6CC258 802181E8 0C0B210B */  jal       get_float_variable
/* 6CC25C 802181EC 46000606 */   mov.s    $f24, $f0
/* 6CC260 802181F0 0220202D */  daddu     $a0, $s1, $zero
/* 6CC264 802181F4 8E050000 */  lw        $a1, ($s0)
/* 6CC268 802181F8 0C0B1EAF */  jal       get_variable
/* 6CC26C 802181FC 46000586 */   mov.s    $f22, $f0
/* 6CC270 80218200 8E240148 */  lw        $a0, 0x148($s1)
/* 6CC274 80218204 0C09A75B */  jal       get_actor
/* 6CC278 80218208 0040802D */   daddu    $s0, $v0, $zero
/* 6CC27C 8021820C 4600A521 */  cvt.d.s   $f20, $f20
/* 6CC280 80218210 4405F000 */  mfc1      $a1, $f30
/* 6CC284 80218214 3C014014 */  lui       $at, 0x4014
/* 6CC288 80218218 44810800 */  mtc1      $at, $f1
/* 6CC28C 8021821C 44800000 */  mtc1      $zero, $f0
/* 6CC290 80218220 4407E000 */  mfc1      $a3, $f28
/* 6CC294 80218224 4620A500 */  add.d     $f20, $f20, $f0
/* 6CC298 80218228 0000202D */  daddu     $a0, $zero, $zero
/* 6CC29C 8021822C AFB0001C */  sw        $s0, 0x1c($sp)
/* 6CC2A0 80218230 4620A520 */  cvt.s.d   $f20, $f20
/* 6CC2A4 80218234 4406A000 */  mfc1      $a2, $f20
/* 6CC2A8 80218238 0040802D */  daddu     $s0, $v0, $zero
/* 6CC2AC 8021823C E7BA0010 */  swc1      $f26, 0x10($sp)
/* 6CC2B0 80218240 E7B80014 */  swc1      $f24, 0x14($sp)
/* 6CC2B4 80218244 0C01BFD4 */  jal       func_8006FF50
/* 6CC2B8 80218248 E7B60018 */   swc1     $f22, 0x18($sp)
/* 6CC2BC 8021824C 0040202D */  daddu     $a0, $v0, $zero
/* 6CC2C0 80218250 82030210 */  lb        $v1, 0x210($s0)
/* 6CC2C4 80218254 2402000A */  addiu     $v0, $zero, 0xa
/* 6CC2C8 80218258 14620007 */  bne       $v1, $v0, .L80218278
/* 6CC2CC 8021825C 00000000 */   nop      
/* 6CC2D0 80218260 8C82000C */  lw        $v0, 0xc($a0)
/* 6CC2D4 80218264 3C013ECC */  lui       $at, 0x3ecc
/* 6CC2D8 80218268 3421CCCD */  ori       $at, $at, 0xcccd
/* 6CC2DC 8021826C 44810000 */  mtc1      $at, $f0
/* 6CC2E0 80218270 00000000 */  nop       
/* 6CC2E4 80218274 E4400028 */  swc1      $f0, 0x28($v0)
.L80218278:
/* 6CC2E8 80218278 8FBF0028 */  lw        $ra, 0x28($sp)
/* 6CC2EC 8021827C 8FB10024 */  lw        $s1, 0x24($sp)
/* 6CC2F0 80218280 8FB00020 */  lw        $s0, 0x20($sp)
/* 6CC2F4 80218284 D7BE0058 */  ldc1      $f30, 0x58($sp)
/* 6CC2F8 80218288 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 6CC2FC 8021828C D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 6CC300 80218290 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 6CC304 80218294 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 6CC308 80218298 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 6CC30C 8021829C 24020002 */  addiu     $v0, $zero, 2
/* 6CC310 802182A0 03E00008 */  jr        $ra
/* 6CC314 802182A4 27BD0060 */   addiu    $sp, $sp, 0x60
/* 6CC318 802182A8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 6CC31C 802182AC AFB20018 */  sw        $s2, 0x18($sp)
/* 6CC320 802182B0 0080902D */  daddu     $s2, $a0, $zero
/* 6CC324 802182B4 AFBF0028 */  sw        $ra, 0x28($sp)
/* 6CC328 802182B8 AFB50024 */  sw        $s5, 0x24($sp)
/* 6CC32C 802182BC AFB40020 */  sw        $s4, 0x20($sp)
/* 6CC330 802182C0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 6CC334 802182C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 6CC338 802182C8 AFB00010 */  sw        $s0, 0x10($sp)
/* 6CC33C 802182CC F7B80040 */  sdc1      $f24, 0x40($sp)
/* 6CC340 802182D0 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 6CC344 802182D4 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 6CC348 802182D8 8E50000C */  lw        $s0, 0xc($s2)
/* 6CC34C 802182DC 8E140000 */  lw        $s4, ($s0)
/* 6CC350 802182E0 26100004 */  addiu     $s0, $s0, 4
/* 6CC354 802182E4 0C0B1EAF */  jal       get_variable
/* 6CC358 802182E8 0280282D */   daddu    $a1, $s4, $zero
/* 6CC35C 802182EC 0040982D */  daddu     $s3, $v0, $zero
/* 6CC360 802182F0 8E150000 */  lw        $s5, ($s0)
/* 6CC364 802182F4 26100004 */  addiu     $s0, $s0, 4
/* 6CC368 802182F8 8E050000 */  lw        $a1, ($s0)
/* 6CC36C 802182FC 26100004 */  addiu     $s0, $s0, 4
/* 6CC370 80218300 0C0B210B */  jal       get_float_variable
/* 6CC374 80218304 0240202D */   daddu    $a0, $s2, $zero
/* 6CC378 80218308 8E050000 */  lw        $a1, ($s0)
/* 6CC37C 8021830C 26100004 */  addiu     $s0, $s0, 4
/* 6CC380 80218310 0240202D */  daddu     $a0, $s2, $zero
/* 6CC384 80218314 0C0B210B */  jal       get_float_variable
/* 6CC388 80218318 46000606 */   mov.s    $f24, $f0
/* 6CC38C 8021831C 8E050000 */  lw        $a1, ($s0)
/* 6CC390 80218320 26100004 */  addiu     $s0, $s0, 4
/* 6CC394 80218324 0240202D */  daddu     $a0, $s2, $zero
/* 6CC398 80218328 0C0B1EAF */  jal       get_variable
/* 6CC39C 8021832C 46000506 */   mov.s    $f20, $f0
/* 6CC3A0 80218330 8E050000 */  lw        $a1, ($s0)
/* 6CC3A4 80218334 26100004 */  addiu     $s0, $s0, 4
/* 6CC3A8 80218338 0240202D */  daddu     $a0, $s2, $zero
/* 6CC3AC 8021833C 0C0B1EAF */  jal       get_variable
/* 6CC3B0 80218340 0040882D */   daddu    $s1, $v0, $zero
/* 6CC3B4 80218344 0240202D */  daddu     $a0, $s2, $zero
/* 6CC3B8 80218348 8E050000 */  lw        $a1, ($s0)
/* 6CC3BC 8021834C 0C0B210B */  jal       get_float_variable
/* 6CC3C0 80218350 0040802D */   daddu    $s0, $v0, $zero
/* 6CC3C4 80218354 3C014334 */  lui       $at, 0x4334
/* 6CC3C8 80218358 44811000 */  mtc1      $at, $f2
/* 6CC3CC 8021835C 3C014049 */  lui       $at, 0x4049
/* 6CC3D0 80218360 34210FD8 */  ori       $at, $at, 0xfd8
/* 6CC3D4 80218364 44812000 */  mtc1      $at, $f4
/* 6CC3D8 80218368 46020003 */  div.s     $f0, $f0, $f2
/* 6CC3DC 8021836C 46040582 */  mul.s     $f22, $f0, $f4
/* 6CC3E0 80218370 00000000 */  nop       
/* 6CC3E4 80218374 4618A501 */  sub.s     $f20, $f20, $f24
/* 6CC3E8 80218378 3C013F00 */  lui       $at, 0x3f00
/* 6CC3EC 8021837C 44810000 */  mtc1      $at, $f0
/* 6CC3F0 80218380 00000000 */  nop       
/* 6CC3F4 80218384 4600A502 */  mul.s     $f20, $f20, $f0
/* 6CC3F8 80218388 00000000 */  nop       
/* 6CC3FC 8021838C 12000007 */  beqz      $s0, .L802183AC
/* 6CC400 80218390 0233102A */   slt      $v0, $s1, $s3
/* 6CC404 80218394 10400005 */  beqz      $v0, .L802183AC
/* 6CC408 80218398 0240202D */   daddu    $a0, $s2, $zero
/* 6CC40C 8021839C 0220982D */  daddu     $s3, $s1, $zero
/* 6CC410 802183A0 0280282D */  daddu     $a1, $s4, $zero
/* 6CC414 802183A4 0C0B2026 */  jal       set_variable
/* 6CC418 802183A8 0220302D */   daddu    $a2, $s1, $zero
.L802183AC:
/* 6CC41C 802183AC 3C014049 */  lui       $at, 0x4049
/* 6CC420 802183B0 34210FD8 */  ori       $at, $at, 0xfd8
/* 6CC424 802183B4 44810000 */  mtc1      $at, $f0
/* 6CC428 802183B8 44936000 */  mtc1      $s3, $f12
/* 6CC42C 802183BC 00000000 */  nop       
/* 6CC430 802183C0 46806320 */  cvt.s.w   $f12, $f12
/* 6CC434 802183C4 46006302 */  mul.s     $f12, $f12, $f0
/* 6CC438 802183C8 00000000 */  nop       
/* 6CC43C 802183CC 44910000 */  mtc1      $s1, $f0
/* 6CC440 802183D0 00000000 */  nop       
/* 6CC444 802183D4 46800020 */  cvt.s.w   $f0, $f0
/* 6CC448 802183D8 46006303 */  div.s     $f12, $f12, $f0
/* 6CC44C 802183DC 0C00A874 */  jal       cos_rad
/* 6CC450 802183E0 46166300 */   add.s    $f12, $f12, $f22
/* 6CC454 802183E4 4600A002 */  mul.s     $f0, $f20, $f0
/* 6CC458 802183E8 00000000 */  nop       
/* 6CC45C 802183EC 4614C080 */  add.s     $f2, $f24, $f20
/* 6CC460 802183F0 46001081 */  sub.s     $f2, $f2, $f0
/* 6CC464 802183F4 0240202D */  daddu     $a0, $s2, $zero
/* 6CC468 802183F8 44061000 */  mfc1      $a2, $f2
/* 6CC46C 802183FC 0C0B2190 */  jal       set_float_variable
/* 6CC470 80218400 02A0282D */   daddu    $a1, $s5, $zero
/* 6CC474 80218404 8FBF0028 */  lw        $ra, 0x28($sp)
/* 6CC478 80218408 8FB50024 */  lw        $s5, 0x24($sp)
/* 6CC47C 8021840C 8FB40020 */  lw        $s4, 0x20($sp)
/* 6CC480 80218410 8FB3001C */  lw        $s3, 0x1c($sp)
/* 6CC484 80218414 8FB20018 */  lw        $s2, 0x18($sp)
/* 6CC488 80218418 8FB10014 */  lw        $s1, 0x14($sp)
/* 6CC48C 8021841C 8FB00010 */  lw        $s0, 0x10($sp)
/* 6CC490 80218420 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 6CC494 80218424 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 6CC498 80218428 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 6CC49C 8021842C 24020002 */  addiu     $v0, $zero, 2
/* 6CC4A0 80218430 03E00008 */  jr        $ra
/* 6CC4A4 80218434 27BD0048 */   addiu    $sp, $sp, 0x48
/* 6CC4A8 80218438 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6CC4AC 8021843C AFBF0010 */  sw        $ra, 0x10($sp)
/* 6CC4B0 80218440 8C82000C */  lw        $v0, 0xc($a0)
/* 6CC4B4 80218444 3C06800E */  lui       $a2, %hi(gBattleStatus+0x17C)
/* 6CC4B8 80218448 84C6C1EC */  lh        $a2, %lo(gBattleStatus+0x17C)($a2)
/* 6CC4BC 8021844C 0C0B2026 */  jal       set_variable
/* 6CC4C0 80218450 8C450000 */   lw       $a1, ($v0)
/* 6CC4C4 80218454 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6CC4C8 80218458 24020002 */  addiu     $v0, $zero, 2
/* 6CC4CC 8021845C 03E00008 */  jr        $ra
/* 6CC4D0 80218460 27BD0018 */   addiu    $sp, $sp, 0x18
/* 6CC4D4 80218464 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 6CC4D8 80218468 AFB10014 */  sw        $s1, 0x14($sp)
/* 6CC4DC 8021846C 0080882D */  daddu     $s1, $a0, $zero
/* 6CC4E0 80218470 AFBF0020 */  sw        $ra, 0x20($sp)
/* 6CC4E4 80218474 AFB3001C */  sw        $s3, 0x1c($sp)
/* 6CC4E8 80218478 AFB20018 */  sw        $s2, 0x18($sp)
/* 6CC4EC 8021847C AFB00010 */  sw        $s0, 0x10($sp)
/* 6CC4F0 80218480 8E30000C */  lw        $s0, 0xc($s1)
/* 6CC4F4 80218484 8E050000 */  lw        $a1, ($s0)
/* 6CC4F8 80218488 0C0B1EAF */  jal       get_variable
/* 6CC4FC 8021848C 26100004 */   addiu    $s0, $s0, 4
/* 6CC500 80218490 8E050000 */  lw        $a1, ($s0)
/* 6CC504 80218494 26100004 */  addiu     $s0, $s0, 4
/* 6CC508 80218498 0220202D */  daddu     $a0, $s1, $zero
/* 6CC50C 8021849C 0C0B1EAF */  jal       get_variable
/* 6CC510 802184A0 0040982D */   daddu    $s3, $v0, $zero
/* 6CC514 802184A4 8E050000 */  lw        $a1, ($s0)
/* 6CC518 802184A8 26100004 */  addiu     $s0, $s0, 4
/* 6CC51C 802184AC 0220202D */  daddu     $a0, $s1, $zero
/* 6CC520 802184B0 0C0B1EAF */  jal       get_variable
/* 6CC524 802184B4 0040902D */   daddu    $s2, $v0, $zero
/* 6CC528 802184B8 0220202D */  daddu     $a0, $s1, $zero
/* 6CC52C 802184BC 8E050000 */  lw        $a1, ($s0)
/* 6CC530 802184C0 0C0B1EAF */  jal       get_variable
/* 6CC534 802184C4 0040802D */   daddu    $s0, $v0, $zero
/* 6CC538 802184C8 8E240148 */  lw        $a0, 0x148($s1)
/* 6CC53C 802184CC 0C09A75B */  jal       get_actor
/* 6CC540 802184D0 0040882D */   daddu    $s1, $v0, $zero
/* 6CC544 802184D4 0040182D */  daddu     $v1, $v0, $zero
/* 6CC548 802184D8 8C620008 */  lw        $v0, 8($v1)
/* 6CC54C 802184DC 90420024 */  lbu       $v0, 0x24($v0)
/* 6CC550 802184E0 8C640008 */  lw        $a0, 8($v1)
/* 6CC554 802184E4 02629823 */  subu      $s3, $s3, $v0
/* 6CC558 802184E8 A0730194 */  sb        $s3, 0x194($v1)
/* 6CC55C 802184EC 90820025 */  lbu       $v0, 0x25($a0)
/* 6CC560 802184F0 02429023 */  subu      $s2, $s2, $v0
/* 6CC564 802184F4 A0720195 */  sb        $s2, 0x195($v1)
/* 6CC568 802184F8 90820026 */  lbu       $v0, 0x26($a0)
/* 6CC56C 802184FC 02028023 */  subu      $s0, $s0, $v0
/* 6CC570 80218500 A0700196 */  sb        $s0, 0x196($v1)
/* 6CC574 80218504 90840027 */  lbu       $a0, 0x27($a0)
/* 6CC578 80218508 02248823 */  subu      $s1, $s1, $a0
/* 6CC57C 8021850C A0710197 */  sb        $s1, 0x197($v1)
/* 6CC580 80218510 8FBF0020 */  lw        $ra, 0x20($sp)
/* 6CC584 80218514 8FB3001C */  lw        $s3, 0x1c($sp)
/* 6CC588 80218518 8FB20018 */  lw        $s2, 0x18($sp)
/* 6CC58C 8021851C 8FB10014 */  lw        $s1, 0x14($sp)
/* 6CC590 80218520 8FB00010 */  lw        $s0, 0x10($sp)
/* 6CC594 80218524 24020002 */  addiu     $v0, $zero, 2
/* 6CC598 80218528 03E00008 */  jr        $ra
/* 6CC59C 8021852C 27BD0028 */   addiu    $sp, $sp, 0x28
/* 6CC5A0 80218530 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6CC5A4 80218534 AFB10014 */  sw        $s1, 0x14($sp)
/* 6CC5A8 80218538 0080882D */  daddu     $s1, $a0, $zero
/* 6CC5AC 8021853C AFBF0018 */  sw        $ra, 0x18($sp)
/* 6CC5B0 80218540 AFB00010 */  sw        $s0, 0x10($sp)
/* 6CC5B4 80218544 8E30000C */  lw        $s0, 0xc($s1)
/* 6CC5B8 80218548 8E050000 */  lw        $a1, ($s0)
/* 6CC5BC 8021854C 0C0B1EAF */  jal       get_variable
/* 6CC5C0 80218550 26100004 */   addiu    $s0, $s0, 4
/* 6CC5C4 80218554 0220202D */  daddu     $a0, $s1, $zero
/* 6CC5C8 80218558 8E050000 */  lw        $a1, ($s0)
/* 6CC5CC 8021855C 0C0B1EAF */  jal       get_variable
/* 6CC5D0 80218560 0040802D */   daddu    $s0, $v0, $zero
/* 6CC5D4 80218564 0200202D */  daddu     $a0, $s0, $zero
/* 6CC5D8 80218568 0C00A3C2 */  jal       start_rumble
/* 6CC5DC 8021856C 0040282D */   daddu    $a1, $v0, $zero
/* 6CC5E0 80218570 8FBF0018 */  lw        $ra, 0x18($sp)
/* 6CC5E4 80218574 8FB10014 */  lw        $s1, 0x14($sp)
/* 6CC5E8 80218578 8FB00010 */  lw        $s0, 0x10($sp)
/* 6CC5EC 8021857C 24020002 */  addiu     $v0, $zero, 2
/* 6CC5F0 80218580 03E00008 */  jr        $ra
/* 6CC5F4 80218584 27BD0020 */   addiu    $sp, $sp, 0x20
/* 6CC5F8 80218588 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6CC5FC 8021858C AFB10014 */  sw        $s1, 0x14($sp)
/* 6CC600 80218590 0080882D */  daddu     $s1, $a0, $zero
/* 6CC604 80218594 AFBF0018 */  sw        $ra, 0x18($sp)
/* 6CC608 80218598 AFB00010 */  sw        $s0, 0x10($sp)
/* 6CC60C 8021859C 8E30000C */  lw        $s0, 0xc($s1)
/* 6CC610 802185A0 8E050000 */  lw        $a1, ($s0)
/* 6CC614 802185A4 0C0B1EAF */  jal       get_variable
/* 6CC618 802185A8 26100004 */   addiu    $s0, $s0, 4
/* 6CC61C 802185AC 0040202D */  daddu     $a0, $v0, $zero
/* 6CC620 802185B0 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 6CC624 802185B4 14820002 */  bne       $a0, $v0, .L802185C0
/* 6CC628 802185B8 00000000 */   nop      
/* 6CC62C 802185BC 8E240148 */  lw        $a0, 0x148($s1)
.L802185C0:
/* 6CC630 802185C0 0C09A75B */  jal       get_actor
/* 6CC634 802185C4 00000000 */   nop      
/* 6CC638 802185C8 0040202D */  daddu     $a0, $v0, $zero
/* 6CC63C 802185CC 90830136 */  lbu       $v1, 0x136($a0)
/* 6CC640 802185D0 24020047 */  addiu     $v0, $zero, 0x47
/* 6CC644 802185D4 1062000B */  beq       $v1, $v0, .L80218604
/* 6CC648 802185D8 0062102A */   slt      $v0, $v1, $v0
/* 6CC64C 802185DC 54400011 */  bnel      $v0, $zero, .L80218624
/* 6CC650 802185E0 0220202D */   daddu    $a0, $s1, $zero
/* 6CC654 802185E4 28620065 */  slti      $v0, $v1, 0x65
/* 6CC658 802185E8 1040000D */  beqz      $v0, .L80218620
/* 6CC65C 802185EC 2862004D */   slti     $v0, $v1, 0x4d
/* 6CC660 802185F0 1440000C */  bnez      $v0, .L80218624
/* 6CC664 802185F4 0220202D */   daddu    $a0, $s1, $zero
/* 6CC668 802185F8 8E050000 */  lw        $a1, ($s0)
/* 6CC66C 802185FC 0808618B */  j         .L8021862C
/* 6CC670 80218600 2406FFFF */   addiu    $a2, $zero, -1
.L80218604:
/* 6CC674 80218604 8C8300A8 */  lw        $v1, 0xa8($a0)
/* 6CC678 80218608 24020001 */  addiu     $v0, $zero, 1
/* 6CC67C 8021860C 14620005 */  bne       $v1, $v0, .L80218624
/* 6CC680 80218610 0220202D */   daddu    $a0, $s1, $zero
/* 6CC684 80218614 8E050000 */  lw        $a1, ($s0)
/* 6CC688 80218618 0808618B */  j         .L8021862C
/* 6CC68C 8021861C 2406FFFF */   addiu    $a2, $zero, -1
.L80218620:
/* 6CC690 80218620 0220202D */  daddu     $a0, $s1, $zero
.L80218624:
/* 6CC694 80218624 8E050000 */  lw        $a1, ($s0)
/* 6CC698 80218628 0000302D */  daddu     $a2, $zero, $zero
.L8021862C:
/* 6CC69C 8021862C 0C0B2026 */  jal       set_variable
/* 6CC6A0 80218630 00000000 */   nop      
/* 6CC6A4 80218634 8FBF0018 */  lw        $ra, 0x18($sp)
/* 6CC6A8 80218638 8FB10014 */  lw        $s1, 0x14($sp)
/* 6CC6AC 8021863C 8FB00010 */  lw        $s0, 0x10($sp)
/* 6CC6B0 80218640 24020002 */  addiu     $v0, $zero, 2
/* 6CC6B4 80218644 03E00008 */  jr        $ra
/* 6CC6B8 80218648 27BD0020 */   addiu    $sp, $sp, 0x20
/* 6CC6BC 8021864C 00000000 */  nop       
/* 6CC6C0 80218650 00000001 */  movf      $zero, $zero, $fcc0
/* 6CC6C4 80218654 00000004 */  sllv      $zero, $zero, $zero
/* 6CC6C8 80218658 00000000 */  nop       
/* 6CC6CC 8021865C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CC6D0 80218660 00000000 */  nop       
/* 6CC6D4 80218664 00000002 */  srl       $zero, $zero, 0
/* 6CC6D8 80218668 00000000 */  nop       
/* 6CC6DC 8021866C 00000006 */  srlv      $zero, $zero, $zero
/* 6CC6E0 80218670 00000000 */  nop       
/* 6CC6E4 80218674 00000009 */  jr        $zero
/* 6CC6E8 80218678 00000000 */   nop      
/* 6CC6EC 8021867C 00000007 */  srav      $zero, $zero, $zero
/* 6CC6F0 80218680 00000000 */  nop       
/* 6CC6F4 80218684 00000004 */  sllv      $zero, $zero, $zero
/* 6CC6F8 80218688 00000000 */  nop       
/* 6CC6FC 8021868C 00000003 */  sra       $zero, $zero, 0
/* 6CC700 80218690 00000000 */  nop       
/* 6CC704 80218694 0000000B */  movn      $zero, $zero, $zero
/* 6CC708 80218698 00000000 */  nop       
/* 6CC70C 8021869C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CC710 802186A0 00000000 */  nop       
/* 6CC714 802186A4 0000000A */  movz      $zero, $zero, $zero
/* 6CC718 802186A8 00000032 */  tlt       $zero, $zero
/* 6CC71C 802186AC 00000008 */  jr        $zero
/* 6CC720 802186B0 00000000 */   nop      
/* 6CC724 802186B4 0000001F */  ddivu     $zero, $zero, $zero
/* 6CC728 802186B8 00000000 */  nop       
/* 6CC72C 802186BC 00000020 */  add       $zero, $zero, $zero
/* 6CC730 802186C0 00000000 */  nop       
/* 6CC734 802186C4 00000025 */  or        $zero, $zero, $zero
/* 6CC738 802186C8 00000000 */  nop       
/* 6CC73C 802186CC 00000022 */  neg       $zero, $zero
/* 6CC740 802186D0 00000000 */  nop       
/* 6CC744 802186D4 00000024 */  and       $zero, $zero, $zero
/* 6CC748 802186D8 00000000 */  nop       
/* 6CC74C 802186DC 00000023 */  negu      $zero, $zero
/* 6CC750 802186E0 00000000 */  nop       
/* 6CC754 802186E4 00000021 */  addu      $zero, $zero, $zero
/* 6CC758 802186E8 00000000 */  nop       
/* 6CC75C 802186EC 00000026 */  xor       $zero, $zero, $zero
/* 6CC760 802186F0 00000000 */  nop       
/* 6CC764 802186F4 00000027 */  not       $zero, $zero
/* 6CC768 802186F8 00000000 */  nop       
/* 6CC76C 802186FC 00000029 */  .byte     0x00, 0x00, 0x00, 0x29
/* 6CC770 80218700 FFFFFFFF */  sd        $ra, -1($ra)
/* 6CC774 80218704 00000000 */  nop       
/* 6CC778 80218708 00800000 */  .byte     0x00, 0x80, 0x00, 0x00
/* 6CC77C 8021870C 01000000 */  .byte     0x01, 0x00, 0x00, 0x00
/* 6CC780 80218710 FA1D00FF */  bbit132   $s0, 0x1d, .L80218B10
/* 6CC784 80218714 80218754 */   lb       $at, -0x78ac($at)
/* 6CC788 80218718 80218650 */  lb        $at, -0x79b0($at)
/* 6CC78C 8021871C 00000000 */  nop       
/* 6CC790 80218720 00000000 */  nop       
/* 6CC794 80218724 00F70000 */  .byte     0x00, 0xf7, 0x00, 0x00
/* 6CC798 80218728 00000000 */  nop       
/* 6CC79C 8021872C 00000000 */  nop       
/* 6CC7A0 80218730 00491B0A */  .byte     0x00, 0x49, 0x1b, 0x0a
/* 6CC7A4 80218734 00010000 */  sll       $zero, $at, 0
/* 6CC7A8 80218738 80218708 */  lb        $at, -0x78f8($at)
/* 6CC7AC 8021873C 80218778 */  lb        $at, -0x7888($at)
/* 6CC7B0 80218740 8021865C */  lb        $at, -0x79a4($at)
/* 6CC7B4 80218744 000F0A00 */  sll       $at, $t7, 8
/* 6CC7B8 80218748 5F046402 */  .byte     0x5f, 0x04, 0x64, 0x02
/* 6CC7BC 8021874C 37200000 */  ori       $zero, $t9, 0
/* 6CC7C0 80218750 E8140519 */  bbit1     $zero, 0x14, .L80219BB8
/* 6CC7C4 80218754 00000001 */   movf     $zero, $zero, $fcc0
/* 6CC7C8 80218758 002E0101 */  .byte     0x00, 0x2e, 0x01, 0x01
/* 6CC7CC 8021875C 0000000C */  syscall   
/* 6CC7D0 80218760 002E0100 */  .byte     0x00, 0x2e, 0x01, 0x00
/* 6CC7D4 80218764 00000008 */  jr        $zero
/* 6CC7D8 80218768 002E0100 */   .byte    0x00, 0x2e, 0x01, 0x00
/* 6CC7DC 8021876C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CC7E0 80218770 002E0100 */  .byte     0x00, 0x2e, 0x01, 0x00
/* 6CC7E4 80218774 00000000 */  nop       
/* 6CC7E8 80218778 00000043 */  sra       $zero, $zero, 1
/* 6CC7EC 8021877C 00000003 */  sra       $zero, $zero, 0
/* 6CC7F0 80218780 80278930 */  lb        $a3, -0x76d0($at)
/* 6CC7F4 80218784 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CC7F8 80218788 80218B0C */  lb        $at, -0x74f4($at)
/* 6CC7FC 8021878C 00000043 */  sra       $zero, $zero, 1
/* 6CC800 80218790 00000003 */  sra       $zero, $zero, 0
/* 6CC804 80218794 80278A94 */  lb        $a3, -0x756c($at)
/* 6CC808 80218798 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CC80C 8021879C 802187DC */  lb        $at, -0x7824($at)
/* 6CC810 802187A0 00000043 */  sra       $zero, $zero, 1
/* 6CC814 802187A4 00000003 */  sra       $zero, $zero, 0
/* 6CC818 802187A8 80278C20 */  lb        $a3, -0x73e0($at)
/* 6CC81C 802187AC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CC820 802187B0 802187EC */  lb        $at, -0x7814($at)
/* 6CC824 802187B4 00000043 */  sra       $zero, $zero, 1
/* 6CC828 802187B8 00000004 */  sllv      $zero, $zero, $zero
/* 6CC82C 802187BC 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6CC830 802187C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CC834 802187C4 00000008 */  jr        $zero
/* 6CC838 802187C8 00000000 */   nop      
/* 6CC83C 802187CC 00000002 */  srl       $zero, $zero, 0
/* 6CC840 802187D0 00000000 */  nop       
/* 6CC844 802187D4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CC848 802187D8 00000000 */  nop       
/* 6CC84C 802187DC 00000002 */  srl       $zero, $zero, 0
/* 6CC850 802187E0 00000000 */  nop       
/* 6CC854 802187E4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CC858 802187E8 00000000 */  nop       
/* 6CC85C 802187EC 00000043 */  sra       $zero, $zero, 1
/* 6CC860 802187F0 00000003 */  sra       $zero, $zero, 0
/* 6CC864 802187F4 8026F0EC */  lb        $a2, -0xf14($at)
/* 6CC868 802187F8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CC86C 802187FC 00000000 */  nop       
/* 6CC870 80218800 00000043 */  sra       $zero, $zero, 1
/* 6CC874 80218804 00000003 */  sra       $zero, $zero, 0
/* 6CC878 80218808 80278B4C */  lb        $a3, -0x74b4($at)
/* 6CC87C 8021880C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CC880 80218810 00000000 */  nop       
/* 6CC884 80218814 00000043 */  sra       $zero, $zero, 1
/* 6CC888 80218818 00000003 */  sra       $zero, $zero, 0
/* 6CC88C 8021881C 8027C4E0 */  lb        $a3, -0x3b20($at)
/* 6CC890 80218820 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CC894 80218824 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CC898 80218828 00000014 */  dsllv     $zero, $zero, $zero
/* 6CC89C 8021882C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CC8A0 80218830 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CC8A4 80218834 0000001D */  dmultu    $zero, $zero
/* 6CC8A8 80218838 00000001 */  movf      $zero, $zero, $fcc0
/* 6CC8AC 8021883C 00000009 */  jr        $zero
/* 6CC8B0 80218840 0000001D */   dmultu   $zero, $zero
/* 6CC8B4 80218844 00000001 */  movf      $zero, $zero, $fcc0
/* 6CC8B8 80218848 0000000A */  movz      $zero, $zero, $zero
/* 6CC8BC 8021884C 00000025 */  or        $zero, $zero, $zero
/* 6CC8C0 80218850 00000002 */  srl       $zero, $zero, 0
/* 6CC8C4 80218854 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CC8C8 80218858 00000001 */  movf      $zero, $zero, $fcc0
/* 6CC8CC 8021885C 00000025 */  or        $zero, $zero, $zero
/* 6CC8D0 80218860 00000002 */  srl       $zero, $zero, 0
/* 6CC8D4 80218864 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CC8D8 80218868 002E0103 */  .byte     0x00, 0x2e, 0x01, 0x03
/* 6CC8DC 8021886C 00000046 */  rotrv     $zero, $zero, $zero
/* 6CC8E0 80218870 00000001 */  movf      $zero, $zero, $fcc0
/* 6CC8E4 80218874 80299044 */  lb        $t1, -0x6fbc($at)
/* 6CC8E8 80218878 00000020 */  add       $zero, $zero, $zero
/* 6CC8EC 8021887C 00000000 */  nop       
/* 6CC8F0 80218880 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CC8F4 80218884 00000001 */  movf      $zero, $zero, $fcc0
/* 6CC8F8 80218888 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6CC8FC 8021888C 00000025 */  or        $zero, $zero, $zero
/* 6CC900 80218890 00000002 */  srl       $zero, $zero, 0
/* 6CC904 80218894 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CC908 80218898 00000001 */  movf      $zero, $zero, $fcc0
/* 6CC90C 8021889C 00000025 */  or        $zero, $zero, $zero
/* 6CC910 802188A0 00000002 */  srl       $zero, $zero, 0
/* 6CC914 802188A4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CC918 802188A8 002E0103 */  .byte     0x00, 0x2e, 0x01, 0x03
/* 6CC91C 802188AC 00000025 */  or        $zero, $zero, $zero
/* 6CC920 802188B0 00000002 */  srl       $zero, $zero, 0
/* 6CC924 802188B4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CC928 802188B8 FFFFFFFF */  sd        $ra, -1($ra)
/* 6CC92C 802188BC 00000046 */  rotrv     $zero, $zero, $zero
/* 6CC930 802188C0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CC934 802188C4 8029A0D0 */  lb        $t1, -0x5f30($at)
/* 6CC938 802188C8 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CC93C 802188CC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CC940 802188D0 00000024 */  and       $zero, $zero, $zero
/* 6CC944 802188D4 00000025 */  or        $zero, $zero, $zero
/* 6CC948 802188D8 00000002 */  srl       $zero, $zero, 0
/* 6CC94C 802188DC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CC950 802188E0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CC954 802188E4 00000025 */  or        $zero, $zero, $zero
/* 6CC958 802188E8 00000002 */  srl       $zero, $zero, 0
/* 6CC95C 802188EC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CC960 802188F0 002E0103 */  .byte     0x00, 0x2e, 0x01, 0x03
/* 6CC964 802188F4 00000025 */  or        $zero, $zero, $zero
/* 6CC968 802188F8 00000002 */  srl       $zero, $zero, 0
/* 6CC96C 802188FC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CC970 80218900 FFFFFFFF */  sd        $ra, -1($ra)
/* 6CC974 80218904 00000046 */  rotrv     $zero, $zero, $zero
/* 6CC978 80218908 00000001 */  movf      $zero, $zero, $fcc0
/* 6CC97C 8021890C 8029A0D0 */  lb        $t1, -0x5f30($at)
/* 6CC980 80218910 00000025 */  or        $zero, $zero, $zero
/* 6CC984 80218914 00000002 */  srl       $zero, $zero, 0
/* 6CC988 80218918 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CC98C 8021891C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CC990 80218920 00000025 */  or        $zero, $zero, $zero
/* 6CC994 80218924 00000002 */  srl       $zero, $zero, 0
/* 6CC998 80218928 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CC99C 8021892C 002E0103 */  .byte     0x00, 0x2e, 0x01, 0x03
/* 6CC9A0 80218930 00000046 */  rotrv     $zero, $zero, $zero
/* 6CC9A4 80218934 00000001 */  movf      $zero, $zero, $fcc0
/* 6CC9A8 80218938 8029AEC0 */  lb        $t1, -0x5140($at)
/* 6CC9AC 8021893C 00000002 */  srl       $zero, $zero, 0
/* 6CC9B0 80218940 00000000 */  nop       
/* 6CC9B4 80218944 0000001D */  dmultu    $zero, $zero
/* 6CC9B8 80218948 00000001 */  movf      $zero, $zero, $fcc0
/* 6CC9BC 8021894C 00000017 */  dsrav     $zero, $zero, $zero
/* 6CC9C0 80218950 0000001D */  dmultu    $zero, $zero
/* 6CC9C4 80218954 00000001 */  movf      $zero, $zero, $fcc0
/* 6CC9C8 80218958 00000019 */  multu     $zero, $zero
/* 6CC9CC 8021895C 0000001D */  dmultu    $zero, $zero
/* 6CC9D0 80218960 00000001 */  movf      $zero, $zero, $fcc0
/* 6CC9D4 80218964 0000001F */  ddivu     $zero, $zero, $zero
/* 6CC9D8 80218968 00000025 */  or        $zero, $zero, $zero
/* 6CC9DC 8021896C 00000002 */  srl       $zero, $zero, 0
/* 6CC9E0 80218970 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CC9E4 80218974 00000001 */  movf      $zero, $zero, $fcc0
/* 6CC9E8 80218978 00000025 */  or        $zero, $zero, $zero
/* 6CC9EC 8021897C 00000002 */  srl       $zero, $zero, 0
/* 6CC9F0 80218980 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CC9F4 80218984 002E0101 */  .byte     0x00, 0x2e, 0x01, 0x01
/* 6CC9F8 80218988 00000046 */  rotrv     $zero, $zero, $zero
/* 6CC9FC 8021898C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCA00 80218990 8029AC70 */  lb        $t1, -0x5390($at)
/* 6CCA04 80218994 00000020 */  add       $zero, $zero, $zero
/* 6CCA08 80218998 00000000 */  nop       
/* 6CCA0C 8021899C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CCA10 802189A0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCA14 802189A4 00000020 */  add       $zero, $zero, $zero
/* 6CCA18 802189A8 00000025 */  or        $zero, $zero, $zero
/* 6CCA1C 802189AC 00000002 */  srl       $zero, $zero, 0
/* 6CCA20 802189B0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CCA24 802189B4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCA28 802189B8 00000025 */  or        $zero, $zero, $zero
/* 6CCA2C 802189BC 00000002 */  srl       $zero, $zero, 0
/* 6CCA30 802189C0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CCA34 802189C4 002E0103 */  .byte     0x00, 0x2e, 0x01, 0x03
/* 6CCA38 802189C8 00000046 */  rotrv     $zero, $zero, $zero
/* 6CCA3C 802189CC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCA40 802189D0 80299044 */  lb        $t1, -0x6fbc($at)
/* 6CCA44 802189D4 00000008 */  jr        $zero
/* 6CCA48 802189D8 00000001 */   movf     $zero, $zero, $fcc0
/* 6CCA4C 802189DC 0000000A */  movz      $zero, $zero, $zero
/* 6CCA50 802189E0 00000025 */  or        $zero, $zero, $zero
/* 6CCA54 802189E4 00000002 */  srl       $zero, $zero, 0
/* 6CCA58 802189E8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CCA5C 802189EC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCA60 802189F0 00000025 */  or        $zero, $zero, $zero
/* 6CCA64 802189F4 00000002 */  srl       $zero, $zero, 0
/* 6CCA68 802189F8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CCA6C 802189FC 002E0103 */  .byte     0x00, 0x2e, 0x01, 0x03
/* 6CCA70 80218A00 00000046 */  rotrv     $zero, $zero, $zero
/* 6CCA74 80218A04 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCA78 80218A08 8029AEC0 */  lb        $t1, -0x5140($at)
/* 6CCA7C 80218A0C 00000002 */  srl       $zero, $zero, 0
/* 6CCA80 80218A10 00000000 */  nop       
/* 6CCA84 80218A14 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CCA88 80218A18 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCA8C 80218A1C 00000031 */  tgeu      $zero, $zero
/* 6CCA90 80218A20 00000025 */  or        $zero, $zero, $zero
/* 6CCA94 80218A24 00000002 */  srl       $zero, $zero, 0
/* 6CCA98 80218A28 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CCA9C 80218A2C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCAA0 80218A30 00000025 */  or        $zero, $zero, $zero
/* 6CCAA4 80218A34 00000002 */  srl       $zero, $zero, 0
/* 6CCAA8 80218A38 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CCAAC 80218A3C 002E0101 */  .byte     0x00, 0x2e, 0x01, 0x01
/* 6CCAB0 80218A40 00000046 */  rotrv     $zero, $zero, $zero
/* 6CCAB4 80218A44 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCAB8 80218A48 8029BFA0 */  lb        $t1, -0x4060($at)
/* 6CCABC 80218A4C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CCAC0 80218A50 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCAC4 80218A54 0000003A */  dsrl      $zero, $zero, 0
/* 6CCAC8 80218A58 00000025 */  or        $zero, $zero, $zero
/* 6CCACC 80218A5C 00000002 */  srl       $zero, $zero, 0
/* 6CCAD0 80218A60 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CCAD4 80218A64 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCAD8 80218A68 00000025 */  or        $zero, $zero, $zero
/* 6CCADC 80218A6C 00000002 */  srl       $zero, $zero, 0
/* 6CCAE0 80218A70 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CCAE4 80218A74 002E0103 */  .byte     0x00, 0x2e, 0x01, 0x03
/* 6CCAE8 80218A78 00000046 */  rotrv     $zero, $zero, $zero
/* 6CCAEC 80218A7C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCAF0 80218A80 8029C37C */  lb        $t1, -0x3c84($at)
/* 6CCAF4 80218A84 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CCAF8 80218A88 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCAFC 80218A8C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CCB00 80218A90 00000025 */  or        $zero, $zero, $zero
/* 6CCB04 80218A94 00000002 */  srl       $zero, $zero, 0
/* 6CCB08 80218A98 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CCB0C 80218A9C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCB10 80218AA0 00000025 */  or        $zero, $zero, $zero
/* 6CCB14 80218AA4 00000002 */  srl       $zero, $zero, 0
/* 6CCB18 80218AA8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CCB1C 80218AAC 002E0103 */  .byte     0x00, 0x2e, 0x01, 0x03
/* 6CCB20 80218AB0 00000046 */  rotrv     $zero, $zero, $zero
/* 6CCB24 80218AB4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCB28 80218AB8 8029C4A8 */  lb        $t1, -0x3b58($at)
/* 6CCB2C 80218ABC 00000002 */  srl       $zero, $zero, 0
/* 6CCB30 80218AC0 00000000 */  nop       
/* 6CCB34 80218AC4 0000001C */  dmult     $zero, $zero
/* 6CCB38 80218AC8 00000000 */  nop       
/* 6CCB3C 80218ACC 00000023 */  negu      $zero, $zero
/* 6CCB40 80218AD0 00000000 */  nop       
/* 6CCB44 80218AD4 00000043 */  sra       $zero, $zero, 1
/* 6CCB48 80218AD8 00000003 */  sra       $zero, $zero, 0
/* 6CCB4C 80218ADC 80278B4C */  lb        $a3, -0x74b4($at)
/* 6CCB50 80218AE0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CCB54 80218AE4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCB58 80218AE8 00000043 */  sra       $zero, $zero, 1
/* 6CCB5C 80218AEC 00000003 */  sra       $zero, $zero, 0
/* 6CCB60 80218AF0 8026F0EC */  lb        $a2, -0xf14($at)
/* 6CCB64 80218AF4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CCB68 80218AF8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCB6C 80218AFC 00000002 */  srl       $zero, $zero, 0
/* 6CCB70 80218B00 00000000 */  nop       
/* 6CCB74 80218B04 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCB78 80218B08 00000000 */  nop       
/* 6CCB7C 80218B0C 00000043 */  sra       $zero, $zero, 1
.L80218B10:
/* 6CCB80 80218B10 00000003 */  sra       $zero, $zero, 0
/* 6CCB84 80218B14 8026F0EC */  lb        $a2, -0xf14($at)
/* 6CCB88 80218B18 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CCB8C 80218B1C 00000000 */  nop       
/* 6CCB90 80218B20 00000043 */  sra       $zero, $zero, 1
/* 6CCB94 80218B24 00000003 */  sra       $zero, $zero, 0
/* 6CCB98 80218B28 80278B4C */  lb        $a3, -0x74b4($at)
/* 6CCB9C 80218B2C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CCBA0 80218B30 00000000 */  nop       
/* 6CCBA4 80218B34 00000043 */  sra       $zero, $zero, 1
/* 6CCBA8 80218B38 00000004 */  sllv      $zero, $zero, $zero
/* 6CCBAC 80218B3C 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CCBB0 80218B40 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CCBB4 80218B44 00000008 */  jr        $zero
/* 6CCBB8 80218B48 FE363C80 */   sd       $s6, 0x3c80($s1)
/* 6CCBBC 80218B4C 00000014 */  dsllv     $zero, $zero, $zero
/* 6CCBC0 80218B50 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCBC4 80218B54 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CCBC8 80218B58 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CCBCC 80218B5C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCBD0 80218B60 00000000 */  nop       
/* 6CCBD4 80218B64 00000046 */  rotrv     $zero, $zero, $zero
/* 6CCBD8 80218B68 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCBDC 80218B6C 80218BC8 */  lb        $at, -0x7438($at)
/* 6CCBE0 80218B70 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CCBE4 80218B74 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCBE8 80218B78 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCBEC 80218B7C 00000046 */  rotrv     $zero, $zero, $zero
/* 6CCBF0 80218B80 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCBF4 80218B84 80218D7C */  lb        $at, -0x7284($at)
/* 6CCBF8 80218B88 00000023 */  negu      $zero, $zero
/* 6CCBFC 80218B8C 00000000 */  nop       
/* 6CCC00 80218B90 00000043 */  sra       $zero, $zero, 1
/* 6CCC04 80218B94 00000003 */  sra       $zero, $zero, 0
/* 6CCC08 80218B98 80278B4C */  lb        $a3, -0x74b4($at)
/* 6CCC0C 80218B9C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CCC10 80218BA0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCC14 80218BA4 00000043 */  sra       $zero, $zero, 1
/* 6CCC18 80218BA8 00000003 */  sra       $zero, $zero, 0
/* 6CCC1C 80218BAC 8026F0EC */  lb        $a2, -0xf14($at)
/* 6CCC20 80218BB0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CCC24 80218BB4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCC28 80218BB8 00000002 */  srl       $zero, $zero, 0
/* 6CCC2C 80218BBC 00000000 */  nop       
/* 6CCC30 80218BC0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCC34 80218BC4 00000000 */  nop       
/* 6CCC38 80218BC8 00000043 */  sra       $zero, $zero, 1
/* 6CCC3C 80218BCC 00000004 */  sllv      $zero, $zero, $zero
/* 6CCC40 80218BD0 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6CCC44 80218BD4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CCC48 80218BD8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCC4C 80218BDC 002E0102 */  rotr      $zero, $t6, 4
/* 6CCC50 80218BE0 00000008 */  jr        $zero
/* 6CCC54 80218BE4 00000001 */   movf     $zero, $zero, $fcc0
/* 6CCC58 80218BE8 0000000D */  break     
/* 6CCC5C 80218BEC 00000056 */   drotrv   $zero, $zero, $zero
/* 6CCC60 80218BF0 00000000 */  nop       
/* 6CCC64 80218BF4 00000043 */  sra       $zero, $zero, 1
/* 6CCC68 80218BF8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CCC6C 80218BFC 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 6CCC70 80218C00 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCC74 80218C04 00000000 */  nop       
/* 6CCC78 80218C08 0000000A */  movz      $zero, $zero, $zero
/* 6CCC7C 80218C0C F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 6CCC80 80218C10 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6CCC84 80218C14 00000000 */  nop       
/* 6CCC88 80218C18 00000043 */  sra       $zero, $zero, 1
/* 6CCC8C 80218C1C 00000002 */  srl       $zero, $zero, 0
/* 6CCC90 80218C20 80254218 */  lb        $a1, 0x4218($at)
/* 6CCC94 80218C24 00000009 */  jr        $zero
/* 6CCC98 80218C28 00000043 */   sra      $zero, $zero, 1
/* 6CCC9C 80218C2C 00000003 */  sra       $zero, $zero, 0
/* 6CCCA0 80218C30 8025385C */  lb        $a1, 0x385c($at)
/* 6CCCA4 80218C34 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CCCA8 80218C38 000002C8 */  .byte     0x00, 0x00, 0x02, 0xc8
/* 6CCCAC 80218C3C 00000043 */  sra       $zero, $zero, 1
/* 6CCCB0 80218C40 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CCCB4 80218C44 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6CCCB8 80218C48 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CCCBC 80218C4C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CCCC0 80218C50 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CCCC4 80218C54 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CCCC8 80218C58 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6CCCCC 80218C5C 00000002 */  srl       $zero, $zero, 0
/* 6CCCD0 80218C60 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CCCD4 80218C64 00000021 */  addu      $zero, $zero, $zero
/* 6CCCD8 80218C68 00000027 */  not       $zero, $zero
/* 6CCCDC 80218C6C 00000002 */  srl       $zero, $zero, 0
/* 6CCCE0 80218C70 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CCCE4 80218C74 00000013 */  mtlo      $zero
/* 6CCCE8 80218C78 00000027 */  not       $zero, $zero
/* 6CCCEC 80218C7C 00000002 */  srl       $zero, $zero, 0
/* 6CCCF0 80218C80 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CCCF4 80218C84 00000003 */  sra       $zero, $zero, 0
/* 6CCCF8 80218C88 00000043 */  sra       $zero, $zero, 1
/* 6CCCFC 80218C8C 0000000F */  sync      
/* 6CCD00 80218C90 802D829C */  lb        $t5, -0x7d64($at)
/* 6CCD04 80218C94 00000000 */  nop       
/* 6CCD08 80218C98 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CCD0C 80218C9C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CCD10 80218CA0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CCD14 80218CA4 00000002 */  srl       $zero, $zero, 0
/* 6CCD18 80218CA8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CCD1C 80218CAC 00000000 */  nop       
/* 6CCD20 80218CB0 00000002 */  srl       $zero, $zero, 0
/* 6CCD24 80218CB4 00000000 */  nop       
/* 6CCD28 80218CB8 00000000 */  nop       
/* 6CCD2C 80218CBC 00000000 */  nop       
/* 6CCD30 80218CC0 00000000 */  nop       
/* 6CCD34 80218CC4 00000000 */  nop       
/* 6CCD38 80218CC8 00000000 */  nop       
/* 6CCD3C 80218CCC 00000043 */  sra       $zero, $zero, 1
/* 6CCD40 80218CD0 0000000F */  sync      
/* 6CCD44 80218CD4 802D829C */  lb        $t5, -0x7d64($at)
/* 6CCD48 80218CD8 00000000 */  nop       
/* 6CCD4C 80218CDC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CCD50 80218CE0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CCD54 80218CE4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CCD58 80218CE8 00000002 */  srl       $zero, $zero, 0
/* 6CCD5C 80218CEC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CCD60 80218CF0 00000002 */  srl       $zero, $zero, 0
/* 6CCD64 80218CF4 00000002 */  srl       $zero, $zero, 0
/* 6CCD68 80218CF8 00000000 */  nop       
/* 6CCD6C 80218CFC 00000000 */  nop       
/* 6CCD70 80218D00 00000000 */  nop       
/* 6CCD74 80218D04 00000000 */  nop       
/* 6CCD78 80218D08 00000000 */  nop       
/* 6CCD7C 80218D0C 00000000 */  nop       
/* 6CCD80 80218D10 00000008 */  jr        $zero
/* 6CCD84 80218D14 00000001 */   movf     $zero, $zero, $fcc0
/* 6CCD88 80218D18 00000002 */  srl       $zero, $zero, 0
/* 6CCD8C 80218D1C 00000043 */  sra       $zero, $zero, 1
/* 6CCD90 80218D20 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCD94 80218D24 80218000 */  lb        $at, -0x8000($at)
/* 6CCD98 80218D28 00000043 */  sra       $zero, $zero, 1
/* 6CCD9C 80218D2C 00000003 */  sra       $zero, $zero, 0
/* 6CCDA0 80218D30 8026DB64 */  lb        $a2, -0x249c($at)
/* 6CCDA4 80218D34 80218DF4 */  lb        $at, -0x720c($at)
/* 6CCDA8 80218D38 00000000 */  nop       
/* 6CCDAC 80218D3C 00000043 */  sra       $zero, $zero, 1
/* 6CCDB0 80218D40 00000004 */  sllv      $zero, $zero, $zero
/* 6CCDB4 80218D44 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6CCDB8 80218D48 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CCDBC 80218D4C 00000000 */  nop       
/* 6CCDC0 80218D50 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CCDC4 80218D54 00000043 */  sra       $zero, $zero, 1
/* 6CCDC8 80218D58 00000004 */  sllv      $zero, $zero, $zero
/* 6CCDCC 80218D5C 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6CCDD0 80218D60 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CCDD4 80218D64 00000008 */  jr        $zero
/* 6CCDD8 80218D68 00000001 */   movf     $zero, $zero, $fcc0
/* 6CCDDC 80218D6C 00000002 */  srl       $zero, $zero, 0
/* 6CCDE0 80218D70 00000000 */  nop       
/* 6CCDE4 80218D74 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCDE8 80218D78 00000000 */  nop       
/* 6CCDEC 80218D7C 00000043 */  sra       $zero, $zero, 1
/* 6CCDF0 80218D80 00000004 */  sllv      $zero, $zero, $zero
/* 6CCDF4 80218D84 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CCDF8 80218D88 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CCDFC 80218D8C 00000000 */  nop       
/* 6CCE00 80218D90 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CCE04 80218D94 00000043 */  sra       $zero, $zero, 1
/* 6CCE08 80218D98 00000003 */  sra       $zero, $zero, 0
/* 6CCE0C 80218D9C 8026DE5C */  lb        $a2, -0x21a4($at)
/* 6CCE10 80218DA0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CCE14 80218DA4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CCE18 80218DA8 0000000A */  movz      $zero, $zero, $zero
/* 6CCE1C 80218DAC 00000002 */  srl       $zero, $zero, 0
/* 6CCE20 80218DB0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CCE24 80218DB4 00000000 */  nop       
/* 6CCE28 80218DB8 00000043 */  sra       $zero, $zero, 1
/* 6CCE2C 80218DBC 00000004 */  sllv      $zero, $zero, $zero
/* 6CCE30 80218DC0 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6CCE34 80218DC4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CCE38 80218DC8 00000008 */  jr        $zero
/* 6CCE3C 80218DCC 00000000 */   nop      
/* 6CCE40 80218DD0 00000013 */  mtlo      $zero
/* 6CCE44 80218DD4 00000000 */  nop       
/* 6CCE48 80218DD8 00000002 */  srl       $zero, $zero, 0
/* 6CCE4C 80218DDC 00000000 */  nop       
/* 6CCE50 80218DE0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCE54 80218DE4 00000000 */  nop       
/* 6CCE58 80218DE8 00000000 */  nop       
/* 6CCE5C 80218DEC FFFFFC18 */  sd        $ra, -0x3e8($ra)
/* 6CCE60 80218DF0 00000000 */  nop       
/* 6CCE64 80218DF4 80218EEC */  lb        $at, -0x7114($at)
/* 6CCE68 80218DF8 80218DE8 */  lb        $at, -0x7218($at)
/* 6CCE6C 80218DFC 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6CCE70 80218E00 00000000 */  nop       
/* 6CCE74 80218E04 00000000 */  nop       
/* 6CCE78 80218E08 00000000 */  nop       
/* 6CCE7C 80218E0C 00000000 */  nop       
/* 6CCE80 80218E10 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCE84 80218E14 00000000 */  nop       
/* 6CCE88 80218E18 00000000 */  nop       
/* 6CCE8C 80218E1C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCE90 80218E20 00000000 */  nop       
/* 6CCE94 80218E24 00000002 */  srl       $zero, $zero, 0
/* 6CCE98 80218E28 00000000 */  nop       
/* 6CCE9C 80218E2C 00000006 */  srlv      $zero, $zero, $zero
/* 6CCEA0 80218E30 00000000 */  nop       
/* 6CCEA4 80218E34 00000009 */  jr        $zero
/* 6CCEA8 80218E38 00000000 */   nop      
/* 6CCEAC 80218E3C 00000007 */  srav      $zero, $zero, $zero
/* 6CCEB0 80218E40 00000000 */  nop       
/* 6CCEB4 80218E44 00000004 */  sllv      $zero, $zero, $zero
/* 6CCEB8 80218E48 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6CCEBC 80218E4C 00000003 */  sra       $zero, $zero, 0
/* 6CCEC0 80218E50 00000000 */  nop       
/* 6CCEC4 80218E54 0000000B */  movn      $zero, $zero, $zero
/* 6CCEC8 80218E58 00000000 */  nop       
/* 6CCECC 80218E5C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CCED0 80218E60 00000000 */  nop       
/* 6CCED4 80218E64 0000000A */  movz      $zero, $zero, $zero
/* 6CCED8 80218E68 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6CCEDC 80218E6C 00000008 */  jr        $zero
/* 6CCEE0 80218E70 00000000 */   nop      
/* 6CCEE4 80218E74 0000001F */  ddivu     $zero, $zero, $zero
/* 6CCEE8 80218E78 00000000 */  nop       
/* 6CCEEC 80218E7C 00000020 */  add       $zero, $zero, $zero
/* 6CCEF0 80218E80 FFFFFFFF */  sd        $ra, -1($ra)
/* 6CCEF4 80218E84 00000025 */  or        $zero, $zero, $zero
/* 6CCEF8 80218E88 00000000 */  nop       
/* 6CCEFC 80218E8C 00000022 */  neg       $zero, $zero
/* 6CCF00 80218E90 00000000 */  nop       
/* 6CCF04 80218E94 00000024 */  and       $zero, $zero, $zero
/* 6CCF08 80218E98 00000000 */  nop       
/* 6CCF0C 80218E9C 00000023 */  negu      $zero, $zero
/* 6CCF10 80218EA0 00000000 */  nop       
/* 6CCF14 80218EA4 00000021 */  addu      $zero, $zero, $zero
/* 6CCF18 80218EA8 00000000 */  nop       
/* 6CCF1C 80218EAC 00000026 */  xor       $zero, $zero, $zero
/* 6CCF20 80218EB0 FFFFFFFF */  sd        $ra, -1($ra)
/* 6CCF24 80218EB4 00000027 */  not       $zero, $zero
/* 6CCF28 80218EB8 00000000 */  nop       
/* 6CCF2C 80218EBC 00000029 */  .byte     0x00, 0x00, 0x00, 0x29
/* 6CCF30 80218EC0 FFFFFFFE */  sd        $ra, -2($ra)
/* 6CCF34 80218EC4 00000000 */  nop       
/* 6CCF38 80218EC8 00800000 */  .byte     0x00, 0x80, 0x00, 0x00
/* 6CCF3C 80218ECC 01000000 */  .byte     0x01, 0x00, 0x00, 0x00
/* 6CCF40 80218ED0 001000FF */  dsra32    $zero, $s0, 3
/* 6CCF44 80218ED4 80218F14 */  lb        $at, -0x70ec($at)
/* 6CCF48 80218ED8 80218E10 */  lb        $at, -0x71f0($at)
/* 6CCF4C 80218EDC 00000400 */  sll       $zero, $zero, 0x10
/* 6CCF50 80218EE0 00000000 */  nop       
/* 6CCF54 80218EE4 00FA0000 */  .byte     0x00, 0xfa, 0x00, 0x00
/* 6CCF58 80218EE8 00000000 */  nop       
/* 6CCF5C 80218EEC 00000200 */  sll       $zero, $zero, 8
/* 6CCF60 80218EF0 004A1803 */  .byte     0x00, 0x4a, 0x18, 0x03
/* 6CCF64 80218EF4 00010000 */  sll       $zero, $at, 0
/* 6CCF68 80218EF8 80218EC8 */  lb        $at, -0x7138($at)
/* 6CCF6C 80218EFC 80218F38 */  lb        $at, -0x70c8($at)
/* 6CCF70 80218F00 80218E1C */  lb        $at, -0x71e4($at)
/* 6CCF74 80218F04 28645F00 */  slti      $a0, $v1, 0x5f00
/* 6CCF78 80218F08 5F005000 */  bgtzl     $t8, .L8022CF0C
/* 6CCF7C 80218F0C 1C160000 */   .byte    0x1c, 0x16, 0x00, 0x00
/* 6CCF80 80218F10 F6140A14 */  sdc1      $f20, 0xa14($s0)
/* 6CCF84 80218F14 00000001 */  movf      $zero, $zero, $fcc0
/* 6CCF88 80218F18 002D0101 */  .byte     0x00, 0x2d, 0x01, 0x01
/* 6CCF8C 80218F1C 0000000C */  syscall   
/* 6CCF90 80218F20 002D0100 */  .byte     0x00, 0x2d, 0x01, 0x00
/* 6CCF94 80218F24 00000008 */  jr        $zero
/* 6CCF98 80218F28 002D0100 */   .byte    0x00, 0x2d, 0x01, 0x00
/* 6CCF9C 80218F2C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CCFA0 80218F30 002D0100 */  .byte     0x00, 0x2d, 0x01, 0x00
/* 6CCFA4 80218F34 00000000 */  nop       
/* 6CCFA8 80218F38 00000043 */  sra       $zero, $zero, 1
/* 6CCFAC 80218F3C 00000003 */  sra       $zero, $zero, 0
/* 6CCFB0 80218F40 80278930 */  lb        $a3, -0x76d0($at)
/* 6CCFB4 80218F44 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CCFB8 80218F48 80219670 */  lb        $at, -0x6990($at)
/* 6CCFBC 80218F4C 00000043 */  sra       $zero, $zero, 1
/* 6CCFC0 80218F50 00000003 */  sra       $zero, $zero, 0
/* 6CCFC4 80218F54 80278A94 */  lb        $a3, -0x756c($at)
/* 6CCFC8 80218F58 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CCFCC 80218F5C 80219230 */  lb        $at, -0x6dd0($at)
/* 6CCFD0 80218F60 00000043 */  sra       $zero, $zero, 1
/* 6CCFD4 80218F64 00000003 */  sra       $zero, $zero, 0
/* 6CCFD8 80218F68 80278C20 */  lb        $a3, -0x73e0($at)
/* 6CCFDC 80218F6C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CCFE0 80218F70 80219298 */  lb        $at, -0x6d68($at)
/* 6CCFE4 80218F74 00000043 */  sra       $zero, $zero, 1
/* 6CCFE8 80218F78 00000004 */  sllv      $zero, $zero, $zero
/* 6CCFEC 80218F7C 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CCFF0 80218F80 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CCFF4 80218F84 00000000 */  nop       
/* 6CCFF8 80218F88 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CCFFC 80218F8C 0000000A */  movz      $zero, $zero, $zero
/* 6CD000 80218F90 00000002 */  srl       $zero, $zero, 0
/* 6CD004 80218F94 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD008 80218F98 00000000 */  nop       
/* 6CD00C 80218F9C 00000043 */  sra       $zero, $zero, 1
/* 6CD010 80218FA0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CD014 80218FA4 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6CD018 80218FA8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD01C 80218FAC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD020 80218FB0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD024 80218FB4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CD028 80218FB8 00000027 */  not       $zero, $zero
/* 6CD02C 80218FBC 00000002 */  srl       $zero, $zero, 0
/* 6CD030 80218FC0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD034 80218FC4 00000010 */  mfhi      $zero
/* 6CD038 80218FC8 00000043 */  sra       $zero, $zero, 1
/* 6CD03C 80218FCC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CD040 80218FD0 8026AE40 */  lb        $a2, -0x51c0($at)
/* 6CD044 80218FD4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD048 80218FD8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD04C 80218FDC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD050 80218FE0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CD054 80218FE4 00000043 */  sra       $zero, $zero, 1
/* 6CD058 80218FE8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CD05C 80218FEC 8026A1EC */  lb        $a2, -0x5e14($at)
/* 6CD060 80218FF0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD064 80218FF4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD068 80218FF8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD06C 80218FFC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CD070 80219000 00000043 */  sra       $zero, $zero, 1
/* 6CD074 80219004 00000002 */  srl       $zero, $zero, 0
/* 6CD078 80219008 8026D664 */  lb        $a2, -0x299c($at)
/* 6CD07C 8021900C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD080 80219010 00000012 */  mflo      $zero
/* 6CD084 80219014 00000000 */  nop       
/* 6CD088 80219018 00000043 */  sra       $zero, $zero, 1
/* 6CD08C 8021901C 00000004 */  sllv      $zero, $zero, $zero
/* 6CD090 80219020 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CD094 80219024 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD098 80219028 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD09C 8021902C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD0A0 80219030 00000043 */  sra       $zero, $zero, 1
/* 6CD0A4 80219034 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CD0A8 80219038 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6CD0AC 8021903C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD0B0 80219040 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD0B4 80219044 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CD0B8 80219048 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6CD0BC 8021904C 00000043 */  sra       $zero, $zero, 1
/* 6CD0C0 80219050 00000003 */  sra       $zero, $zero, 0
/* 6CD0C4 80219054 8026F230 */  lb        $a2, -0xdd0($at)
/* 6CD0C8 80219058 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD0CC 8021905C FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6CD0D0 80219060 00000010 */  mfhi      $zero
/* 6CD0D4 80219064 00000002 */  srl       $zero, $zero, 0
/* 6CD0D8 80219068 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6CD0DC 8021906C 00080000 */  sll       $zero, $t0, 0
/* 6CD0E0 80219070 00000024 */  and       $zero, $zero, $zero
/* 6CD0E4 80219074 00000002 */  srl       $zero, $zero, 0
/* 6CD0E8 80219078 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6CD0EC 8021907C FFFFFFF3 */  sd        $ra, -0xd($ra)
/* 6CD0F0 80219080 00000024 */  and       $zero, $zero, $zero
/* 6CD0F4 80219084 00000002 */  srl       $zero, $zero, 0
/* 6CD0F8 80219088 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 6CD0FC 8021908C 00000004 */  sllv      $zero, $zero, $zero
/* 6CD100 80219090 00000012 */  mflo      $zero
/* 6CD104 80219094 00000000 */  nop       
/* 6CD108 80219098 00000024 */  and       $zero, $zero, $zero
/* 6CD10C 8021909C 00000002 */  srl       $zero, $zero, 0
/* 6CD110 802190A0 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6CD114 802190A4 FFFFFFDF */  sd        $ra, -0x21($ra)
/* 6CD118 802190A8 00000024 */  and       $zero, $zero, $zero
/* 6CD11C 802190AC 00000002 */  srl       $zero, $zero, 0
/* 6CD120 802190B0 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 6CD124 802190B4 0000000B */  movn      $zero, $zero, $zero
/* 6CD128 802190B8 00000013 */  mtlo      $zero
/* 6CD12C 802190BC 00000000 */  nop       
/* 6CD130 802190C0 00000027 */  not       $zero, $zero
/* 6CD134 802190C4 00000002 */  srl       $zero, $zero, 0
/* 6CD138 802190C8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD13C 802190CC FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6CD140 802190D0 00000027 */  not       $zero, $zero
/* 6CD144 802190D4 00000002 */  srl       $zero, $zero, 0
/* 6CD148 802190D8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CD14C 802190DC FE363C86 */  sd        $s6, 0x3c86($s1)
/* 6CD150 802190E0 00000043 */  sra       $zero, $zero, 1
/* 6CD154 802190E4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CD158 802190E8 8026AE40 */  lb        $a2, -0x51c0($at)
/* 6CD15C 802190EC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD160 802190F0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD164 802190F4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CD168 802190F8 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6CD16C 802190FC 00000043 */  sra       $zero, $zero, 1
/* 6CD170 80219100 00000003 */  sra       $zero, $zero, 0
/* 6CD174 80219104 8027DCBC */  lb        $a3, -0x2344($at)
/* 6CD178 80219108 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD17C 8021910C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD180 80219110 00000043 */  sra       $zero, $zero, 1
/* 6CD184 80219114 00000003 */  sra       $zero, $zero, 0
/* 6CD188 80219118 80271160 */  lb        $a3, 0x1160($at)
/* 6CD18C 8021911C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD190 80219120 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD194 80219124 00000043 */  sra       $zero, $zero, 1
/* 6CD198 80219128 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CD19C 8021912C 8026F740 */  lb        $a2, -0x8c0($at)
/* 6CD1A0 80219130 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD1A4 80219134 00000002 */  srl       $zero, $zero, 0
/* 6CD1A8 80219138 00000000 */  nop       
/* 6CD1AC 8021913C 00000000 */  nop       
/* 6CD1B0 80219140 00000043 */  sra       $zero, $zero, 1
/* 6CD1B4 80219144 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CD1B8 80219148 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6CD1BC 8021914C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD1C0 80219150 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD1C4 80219154 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6CD1C8 80219158 FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 6CD1CC 8021915C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6CD1D0 80219160 00000002 */  srl       $zero, $zero, 0
/* 6CD1D4 80219164 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD1D8 80219168 0000005A */  .byte     0x00, 0x00, 0x00, 0x5a
/* 6CD1DC 8021916C 00000043 */  sra       $zero, $zero, 1
/* 6CD1E0 80219170 00000003 */  sra       $zero, $zero, 0
/* 6CD1E4 80219174 8026B55C */  lb        $a2, -0x4aa4($at)
/* 6CD1E8 80219178 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD1EC 8021917C F24A7A8B */  scd       $t2, 0x7a8b($s2)
/* 6CD1F0 80219180 00000043 */  sra       $zero, $zero, 1
/* 6CD1F4 80219184 00000004 */  sllv      $zero, $zero, $zero
/* 6CD1F8 80219188 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6CD1FC 8021918C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD200 80219190 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD204 80219194 002D0103 */  .byte     0x00, 0x2d, 0x01, 0x03
/* 6CD208 80219198 00000043 */  sra       $zero, $zero, 1
/* 6CD20C 8021919C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CD210 802191A0 8026A510 */  lb        $a2, -0x5af0($at)
/* 6CD214 802191A4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD218 802191A8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD21C 802191AC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CD220 802191B0 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6CD224 802191B4 00000043 */  sra       $zero, $zero, 1
/* 6CD228 802191B8 00000006 */  srlv      $zero, $zero, $zero
/* 6CD22C 802191BC 80278D08 */  lb        $a3, -0x72f8($at)
/* 6CD230 802191C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD234 802191C4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CD238 802191C8 00000000 */  nop       
/* 6CD23C 802191CC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD240 802191D0 00000000 */  nop       
/* 6CD244 802191D4 00000043 */  sra       $zero, $zero, 1
/* 6CD248 802191D8 00000004 */  sllv      $zero, $zero, $zero
/* 6CD24C 802191DC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6CD250 802191E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD254 802191E4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD258 802191E8 002D0101 */  .byte     0x00, 0x2d, 0x01, 0x01
/* 6CD25C 802191EC 00000043 */  sra       $zero, $zero, 1
/* 6CD260 802191F0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CD264 802191F4 8026A1EC */  lb        $a2, -0x5e14($at)
/* 6CD268 802191F8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD26C 802191FC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD270 80219200 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CD274 80219204 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6CD278 80219208 00000043 */  sra       $zero, $zero, 1
/* 6CD27C 8021920C 00000002 */  srl       $zero, $zero, 0
/* 6CD280 80219210 8026D664 */  lb        $a2, -0x299c($at)
/* 6CD284 80219214 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD288 80219218 00000013 */  mtlo      $zero
/* 6CD28C 8021921C 00000000 */  nop       
/* 6CD290 80219220 00000002 */  srl       $zero, $zero, 0
/* 6CD294 80219224 00000000 */  nop       
/* 6CD298 80219228 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD29C 8021922C 00000000 */  nop       
/* 6CD2A0 80219230 00000002 */  srl       $zero, $zero, 0
/* 6CD2A4 80219234 00000000 */  nop       
/* 6CD2A8 80219238 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD2AC 8021923C 00000000 */  nop       
/* 6CD2B0 80219240 00000046 */  rotrv     $zero, $zero, $zero
/* 6CD2B4 80219244 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD2B8 80219248 80219A90 */  lb        $at, -0x6570($at)
/* 6CD2BC 8021924C 00000025 */  or        $zero, $zero, $zero
/* 6CD2C0 80219250 00000002 */  srl       $zero, $zero, 0
/* 6CD2C4 80219254 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD2C8 80219258 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD2CC 8021925C 00000025 */  or        $zero, $zero, $zero
/* 6CD2D0 80219260 00000002 */  srl       $zero, $zero, 0
/* 6CD2D4 80219264 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD2D8 80219268 002D0107 */  .byte     0x00, 0x2d, 0x01, 0x07
/* 6CD2DC 8021926C 00000024 */  and       $zero, $zero, $zero
/* 6CD2E0 80219270 00000002 */  srl       $zero, $zero, 0
/* 6CD2E4 80219274 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CD2E8 80219278 FFFFCFC7 */  sd        $ra, -0x3039($ra)
/* 6CD2EC 8021927C 00000046 */  rotrv     $zero, $zero, $zero
/* 6CD2F0 80219280 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD2F4 80219284 8029AEC0 */  lb        $t1, -0x5140($at)
/* 6CD2F8 80219288 00000002 */  srl       $zero, $zero, 0
/* 6CD2FC 8021928C 00000000 */  nop       
/* 6CD300 80219290 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD304 80219294 00000000 */  nop       
/* 6CD308 80219298 00000043 */  sra       $zero, $zero, 1
/* 6CD30C 8021929C 00000003 */  sra       $zero, $zero, 0
/* 6CD310 802192A0 8026F0EC */  lb        $a2, -0xf14($at)
/* 6CD314 802192A4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD318 802192A8 00000000 */  nop       
/* 6CD31C 802192AC 00000043 */  sra       $zero, $zero, 1
/* 6CD320 802192B0 00000003 */  sra       $zero, $zero, 0
/* 6CD324 802192B4 80278B4C */  lb        $a3, -0x74b4($at)
/* 6CD328 802192B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD32C 802192BC 00000000 */  nop       
/* 6CD330 802192C0 00000043 */  sra       $zero, $zero, 1
/* 6CD334 802192C4 00000003 */  sra       $zero, $zero, 0
/* 6CD338 802192C8 8027C4E0 */  lb        $a3, -0x3b20($at)
/* 6CD33C 802192CC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD340 802192D0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD344 802192D4 00000014 */  dsllv     $zero, $zero, $zero
/* 6CD348 802192D8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD34C 802192DC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD350 802192E0 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CD354 802192E4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD358 802192E8 00000009 */  jr        $zero
/* 6CD35C 802192EC 00000025 */   or       $zero, $zero, $zero
/* 6CD360 802192F0 00000002 */  srl       $zero, $zero, 0
/* 6CD364 802192F4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD368 802192F8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD36C 802192FC 00000025 */  or        $zero, $zero, $zero
/* 6CD370 80219300 00000002 */  srl       $zero, $zero, 0
/* 6CD374 80219304 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD378 80219308 002D0105 */  .byte     0x00, 0x2d, 0x01, 0x05
/* 6CD37C 8021930C 00000046 */  rotrv     $zero, $zero, $zero
/* 6CD380 80219310 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD384 80219314 80299044 */  lb        $t1, -0x6fbc($at)
/* 6CD388 80219318 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CD38C 8021931C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD390 80219320 0000000A */  movz      $zero, $zero, $zero
/* 6CD394 80219324 00000025 */  or        $zero, $zero, $zero
/* 6CD398 80219328 00000002 */  srl       $zero, $zero, 0
/* 6CD39C 8021932C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD3A0 80219330 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD3A4 80219334 00000025 */  or        $zero, $zero, $zero
/* 6CD3A8 80219338 00000002 */  srl       $zero, $zero, 0
/* 6CD3AC 8021933C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD3B0 80219340 002D0105 */  .byte     0x00, 0x2d, 0x01, 0x05
/* 6CD3B4 80219344 00000046 */  rotrv     $zero, $zero, $zero
/* 6CD3B8 80219348 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD3BC 8021934C 80299044 */  lb        $t1, -0x6fbc($at)
/* 6CD3C0 80219350 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CD3C4 80219354 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD3C8 80219358 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6CD3CC 8021935C 00000046 */  rotrv     $zero, $zero, $zero
/* 6CD3D0 80219360 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD3D4 80219364 80219240 */  lb        $at, -0x6dc0($at)
/* 6CD3D8 80219368 00000002 */  srl       $zero, $zero, 0
/* 6CD3DC 8021936C 00000000 */  nop       
/* 6CD3E0 80219370 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CD3E4 80219374 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD3E8 80219378 00000024 */  and       $zero, $zero, $zero
/* 6CD3EC 8021937C 00000046 */  rotrv     $zero, $zero, $zero
/* 6CD3F0 80219380 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD3F4 80219384 80219240 */  lb        $at, -0x6dc0($at)
/* 6CD3F8 80219388 00000002 */  srl       $zero, $zero, 0
/* 6CD3FC 8021938C 00000000 */  nop       
/* 6CD400 80219390 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CD404 80219394 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD408 80219398 0000000B */  movn      $zero, $zero, $zero
/* 6CD40C 8021939C 00000046 */  rotrv     $zero, $zero, $zero
/* 6CD410 802193A0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD414 802193A4 80219240 */  lb        $at, -0x6dc0($at)
/* 6CD418 802193A8 00000002 */  srl       $zero, $zero, 0
/* 6CD41C 802193AC 00000000 */  nop       
/* 6CD420 802193B0 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CD424 802193B4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD428 802193B8 00000021 */  addu      $zero, $zero, $zero
/* 6CD42C 802193BC 00000046 */  rotrv     $zero, $zero, $zero
/* 6CD430 802193C0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD434 802193C4 80219240 */  lb        $at, -0x6dc0($at)
/* 6CD438 802193C8 00000002 */  srl       $zero, $zero, 0
/* 6CD43C 802193CC 00000000 */  nop       
/* 6CD440 802193D0 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CD444 802193D4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD448 802193D8 0000002F */  dsubu     $zero, $zero, $zero
/* 6CD44C 802193DC 00000025 */  or        $zero, $zero, $zero
/* 6CD450 802193E0 00000002 */  srl       $zero, $zero, 0
/* 6CD454 802193E4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD458 802193E8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD45C 802193EC 00000025 */  or        $zero, $zero, $zero
/* 6CD460 802193F0 00000002 */  srl       $zero, $zero, 0
/* 6CD464 802193F4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD468 802193F8 002D0105 */  .byte     0x00, 0x2d, 0x01, 0x05
/* 6CD46C 802193FC 00000046 */  rotrv     $zero, $zero, $zero
/* 6CD470 80219400 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD474 80219404 8029A6FC */  lb        $t1, -0x5904($at)
/* 6CD478 80219408 00000046 */  rotrv     $zero, $zero, $zero
/* 6CD47C 8021940C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD480 80219410 80219240 */  lb        $at, -0x6dc0($at)
/* 6CD484 80219414 00000002 */  srl       $zero, $zero, 0
/* 6CD488 80219418 00000000 */  nop       
/* 6CD48C 8021941C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CD490 80219420 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD494 80219424 00000026 */  xor       $zero, $zero, $zero
/* 6CD498 80219428 00000025 */  or        $zero, $zero, $zero
/* 6CD49C 8021942C 00000002 */  srl       $zero, $zero, 0
/* 6CD4A0 80219430 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD4A4 80219434 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD4A8 80219438 00000025 */  or        $zero, $zero, $zero
/* 6CD4AC 8021943C 00000002 */  srl       $zero, $zero, 0
/* 6CD4B0 80219440 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD4B4 80219444 002D0105 */  .byte     0x00, 0x2d, 0x01, 0x05
/* 6CD4B8 80219448 00000046 */  rotrv     $zero, $zero, $zero
/* 6CD4BC 8021944C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD4C0 80219450 8029A6FC */  lb        $t1, -0x5904($at)
/* 6CD4C4 80219454 00000046 */  rotrv     $zero, $zero, $zero
/* 6CD4C8 80219458 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD4CC 8021945C 80219240 */  lb        $at, -0x6dc0($at)
/* 6CD4D0 80219460 00000002 */  srl       $zero, $zero, 0
/* 6CD4D4 80219464 00000000 */  nop       
/* 6CD4D8 80219468 0000001D */  dmultu    $zero, $zero
/* 6CD4DC 8021946C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD4E0 80219470 00000017 */  dsrav     $zero, $zero, $zero
/* 6CD4E4 80219474 0000001D */  dmultu    $zero, $zero
/* 6CD4E8 80219478 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD4EC 8021947C 00000019 */  multu     $zero, $zero
/* 6CD4F0 80219480 0000001D */  dmultu    $zero, $zero
/* 6CD4F4 80219484 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD4F8 80219488 0000001F */  ddivu     $zero, $zero, $zero
/* 6CD4FC 8021948C 00000025 */  or        $zero, $zero, $zero
/* 6CD500 80219490 00000002 */  srl       $zero, $zero, 0
/* 6CD504 80219494 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD508 80219498 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD50C 8021949C 00000025 */  or        $zero, $zero, $zero
/* 6CD510 802194A0 00000002 */  srl       $zero, $zero, 0
/* 6CD514 802194A4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD518 802194A8 002D0101 */  .byte     0x00, 0x2d, 0x01, 0x01
/* 6CD51C 802194AC 00000046 */  rotrv     $zero, $zero, $zero
/* 6CD520 802194B0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD524 802194B4 8029AC70 */  lb        $t1, -0x5390($at)
/* 6CD528 802194B8 00000020 */  add       $zero, $zero, $zero
/* 6CD52C 802194BC 00000000 */  nop       
/* 6CD530 802194C0 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CD534 802194C4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD538 802194C8 00000020 */  add       $zero, $zero, $zero
/* 6CD53C 802194CC 00000025 */  or        $zero, $zero, $zero
/* 6CD540 802194D0 00000002 */  srl       $zero, $zero, 0
/* 6CD544 802194D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD548 802194D8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD54C 802194DC 00000025 */  or        $zero, $zero, $zero
/* 6CD550 802194E0 00000002 */  srl       $zero, $zero, 0
/* 6CD554 802194E4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD558 802194E8 002D0105 */  .byte     0x00, 0x2d, 0x01, 0x05
/* 6CD55C 802194EC 00000046 */  rotrv     $zero, $zero, $zero
/* 6CD560 802194F0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD564 802194F4 80299044 */  lb        $t1, -0x6fbc($at)
/* 6CD568 802194F8 00000046 */  rotrv     $zero, $zero, $zero
/* 6CD56C 802194FC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD570 80219500 80219240 */  lb        $at, -0x6dc0($at)
/* 6CD574 80219504 00000002 */  srl       $zero, $zero, 0
/* 6CD578 80219508 00000000 */  nop       
/* 6CD57C 8021950C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CD580 80219510 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD584 80219514 00000022 */  neg       $zero, $zero
/* 6CD588 80219518 00000046 */  rotrv     $zero, $zero, $zero
/* 6CD58C 8021951C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD590 80219520 80219240 */  lb        $at, -0x6dc0($at)
/* 6CD594 80219524 00000002 */  srl       $zero, $zero, 0
/* 6CD598 80219528 00000000 */  nop       
/* 6CD59C 8021952C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CD5A0 80219530 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD5A4 80219534 00000031 */  tgeu      $zero, $zero
/* 6CD5A8 80219538 00000025 */  or        $zero, $zero, $zero
/* 6CD5AC 8021953C 00000002 */  srl       $zero, $zero, 0
/* 6CD5B0 80219540 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD5B4 80219544 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD5B8 80219548 00000025 */  or        $zero, $zero, $zero
/* 6CD5BC 8021954C 00000002 */  srl       $zero, $zero, 0
/* 6CD5C0 80219550 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD5C4 80219554 002D0101 */  .byte     0x00, 0x2d, 0x01, 0x01
/* 6CD5C8 80219558 00000046 */  rotrv     $zero, $zero, $zero
/* 6CD5CC 8021955C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD5D0 80219560 8029BFA0 */  lb        $t1, -0x4060($at)
/* 6CD5D4 80219564 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CD5D8 80219568 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD5DC 8021956C 00000039 */  .byte     0x00, 0x00, 0x00, 0x39
/* 6CD5E0 80219570 00000025 */  or        $zero, $zero, $zero
/* 6CD5E4 80219574 00000002 */  srl       $zero, $zero, 0
/* 6CD5E8 80219578 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD5EC 8021957C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD5F0 80219580 00000025 */  or        $zero, $zero, $zero
/* 6CD5F4 80219584 00000002 */  srl       $zero, $zero, 0
/* 6CD5F8 80219588 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD5FC 8021958C 002D0105 */  .byte     0x00, 0x2d, 0x01, 0x05
/* 6CD600 80219590 00000046 */  rotrv     $zero, $zero, $zero
/* 6CD604 80219594 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD608 80219598 80299044 */  lb        $t1, -0x6fbc($at)
/* 6CD60C 8021959C 00000046 */  rotrv     $zero, $zero, $zero
/* 6CD610 802195A0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD614 802195A4 80219240 */  lb        $at, -0x6dc0($at)
/* 6CD618 802195A8 00000002 */  srl       $zero, $zero, 0
/* 6CD61C 802195AC 00000000 */  nop       
/* 6CD620 802195B0 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CD624 802195B4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD628 802195B8 0000003A */  dsrl      $zero, $zero, 0
/* 6CD62C 802195BC 00000025 */  or        $zero, $zero, $zero
/* 6CD630 802195C0 00000002 */  srl       $zero, $zero, 0
/* 6CD634 802195C4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD638 802195C8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD63C 802195CC 00000025 */  or        $zero, $zero, $zero
/* 6CD640 802195D0 00000002 */  srl       $zero, $zero, 0
/* 6CD644 802195D4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD648 802195D8 002D0103 */  .byte     0x00, 0x2d, 0x01, 0x03
/* 6CD64C 802195DC 00000046 */  rotrv     $zero, $zero, $zero
/* 6CD650 802195E0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD654 802195E4 8029C37C */  lb        $t1, -0x3c84($at)
/* 6CD658 802195E8 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CD65C 802195EC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD660 802195F0 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CD664 802195F4 00000025 */  or        $zero, $zero, $zero
/* 6CD668 802195F8 00000002 */  srl       $zero, $zero, 0
/* 6CD66C 802195FC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD670 80219600 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD674 80219604 00000025 */  or        $zero, $zero, $zero
/* 6CD678 80219608 00000002 */  srl       $zero, $zero, 0
/* 6CD67C 8021960C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD680 80219610 002D0103 */  .byte     0x00, 0x2d, 0x01, 0x03
/* 6CD684 80219614 00000046 */  rotrv     $zero, $zero, $zero
/* 6CD688 80219618 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD68C 8021961C 8029C4A8 */  lb        $t1, -0x3b58($at)
/* 6CD690 80219620 00000002 */  srl       $zero, $zero, 0
/* 6CD694 80219624 00000000 */  nop       
/* 6CD698 80219628 0000001C */  dmult     $zero, $zero
/* 6CD69C 8021962C 00000000 */  nop       
/* 6CD6A0 80219630 00000023 */  negu      $zero, $zero
/* 6CD6A4 80219634 00000000 */  nop       
/* 6CD6A8 80219638 00000043 */  sra       $zero, $zero, 1
/* 6CD6AC 8021963C 00000003 */  sra       $zero, $zero, 0
/* 6CD6B0 80219640 80278B4C */  lb        $a3, -0x74b4($at)
/* 6CD6B4 80219644 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD6B8 80219648 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD6BC 8021964C 00000043 */  sra       $zero, $zero, 1
/* 6CD6C0 80219650 00000003 */  sra       $zero, $zero, 0
/* 6CD6C4 80219654 8026F0EC */  lb        $a2, -0xf14($at)
/* 6CD6C8 80219658 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD6CC 8021965C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD6D0 80219660 00000002 */  srl       $zero, $zero, 0
/* 6CD6D4 80219664 00000000 */  nop       
/* 6CD6D8 80219668 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD6DC 8021966C 00000000 */  nop       
/* 6CD6E0 80219670 00000043 */  sra       $zero, $zero, 1
/* 6CD6E4 80219674 00000003 */  sra       $zero, $zero, 0
/* 6CD6E8 80219678 8026F0EC */  lb        $a2, -0xf14($at)
/* 6CD6EC 8021967C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD6F0 80219680 00000000 */  nop       
/* 6CD6F4 80219684 00000043 */  sra       $zero, $zero, 1
/* 6CD6F8 80219688 00000003 */  sra       $zero, $zero, 0
/* 6CD6FC 8021968C 80278B4C */  lb        $a3, -0x74b4($at)
/* 6CD700 80219690 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD704 80219694 00000000 */  nop       
/* 6CD708 80219698 00000043 */  sra       $zero, $zero, 1
/* 6CD70C 8021969C 00000003 */  sra       $zero, $zero, 0
/* 6CD710 802196A0 8027C548 */  lb        $a3, -0x3ab8($at)
/* 6CD714 802196A4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD718 802196A8 00000000 */  nop       
/* 6CD71C 802196AC 00000043 */  sra       $zero, $zero, 1
/* 6CD720 802196B0 00000002 */  srl       $zero, $zero, 0
/* 6CD724 802196B4 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 6CD728 802196B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD72C 802196BC 00000043 */  sra       $zero, $zero, 1
/* 6CD730 802196C0 00000002 */  srl       $zero, $zero, 0
/* 6CD734 802196C4 8024E61C */  lb        $a0, -0x19e4($at)
/* 6CD738 802196C8 0000003F */  dsra32    $zero, $zero, 0
/* 6CD73C 802196CC 00000043 */  sra       $zero, $zero, 1
/* 6CD740 802196D0 00000002 */  srl       $zero, $zero, 0
/* 6CD744 802196D4 8024EB24 */  lb        $a0, -0x14dc($at)
/* 6CD748 802196D8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD74C 802196DC 00000043 */  sra       $zero, $zero, 1
/* 6CD750 802196E0 00000004 */  sllv      $zero, $zero, $zero
/* 6CD754 802196E4 8024ECF8 */  lb        $a0, -0x1308($at)
/* 6CD758 802196E8 FFFFFFFF */  sd        $ra, -1($ra)
/* 6CD75C 802196EC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD760 802196F0 00000000 */  nop       
/* 6CD764 802196F4 00000043 */  sra       $zero, $zero, 1
/* 6CD768 802196F8 00000004 */  sllv      $zero, $zero, $zero
/* 6CD76C 802196FC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6CD770 80219700 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD774 80219704 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD778 80219708 002D0104 */  .byte     0x00, 0x2d, 0x01, 0x04
/* 6CD77C 8021970C 00000043 */  sra       $zero, $zero, 1
/* 6CD780 80219710 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CD784 80219714 8026BA04 */  lb        $a2, -0x45fc($at)
/* 6CD788 80219718 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD78C 8021971C 00000000 */  nop       
/* 6CD790 80219720 FFFFFFFF */  sd        $ra, -1($ra)
/* 6CD794 80219724 00000000 */  nop       
/* 6CD798 80219728 00000008 */  jr        $zero
/* 6CD79C 8021972C 00000001 */   movf     $zero, $zero, $fcc0
/* 6CD7A0 80219730 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD7A4 80219734 00000043 */  sra       $zero, $zero, 1
/* 6CD7A8 80219738 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CD7AC 8021973C 8026BA04 */  lb        $a2, -0x45fc($at)
/* 6CD7B0 80219740 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD7B4 80219744 00000000 */  nop       
/* 6CD7B8 80219748 FFFFFFFE */  sd        $ra, -2($ra)
/* 6CD7BC 8021974C 00000000 */  nop       
/* 6CD7C0 80219750 00000008 */  jr        $zero
/* 6CD7C4 80219754 00000001 */   movf     $zero, $zero, $fcc0
/* 6CD7C8 80219758 0000000F */  sync      
/* 6CD7CC 8021975C 00000043 */  sra       $zero, $zero, 1
/* 6CD7D0 80219760 00000002 */  srl       $zero, $zero, 0
/* 6CD7D4 80219764 8024E664 */  lb        $a0, -0x199c($at)
/* 6CD7D8 80219768 00000013 */  mtlo      $zero
/* 6CD7DC 8021976C 00000043 */  sra       $zero, $zero, 1
/* 6CD7E0 80219770 00000007 */  srav      $zero, $zero, $zero
/* 6CD7E4 80219774 8027CFB8 */  lb        $a3, -0x3048($at)
/* 6CD7E8 80219778 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD7EC 8021977C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD7F0 80219780 00000000 */  nop       
/* 6CD7F4 80219784 00000000 */  nop       
/* 6CD7F8 80219788 00000006 */  srlv      $zero, $zero, $zero
/* 6CD7FC 8021978C 00000010 */  mfhi      $zero
/* 6CD800 80219790 00000014 */  dsllv     $zero, $zero, $zero
/* 6CD804 80219794 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD808 80219798 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD80C 8021979C 0000001D */  dmultu    $zero, $zero
/* 6CD810 802197A0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD814 802197A4 00000006 */  srlv      $zero, $zero, $zero
/* 6CD818 802197A8 0000001D */  dmultu    $zero, $zero
/* 6CD81C 802197AC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD820 802197B0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CD824 802197B4 00000024 */  and       $zero, $zero, $zero
/* 6CD828 802197B8 00000002 */  srl       $zero, $zero, 0
/* 6CD82C 802197BC FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6CD830 802197C0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD834 802197C4 00000043 */  sra       $zero, $zero, 1
/* 6CD838 802197C8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CD83C 802197CC 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6CD840 802197D0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD844 802197D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD848 802197D8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD84C 802197DC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CD850 802197E0 00000024 */  and       $zero, $zero, $zero
/* 6CD854 802197E4 00000002 */  srl       $zero, $zero, 0
/* 6CD858 802197E8 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6CD85C 802197EC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD860 802197F0 00000043 */  sra       $zero, $zero, 1
/* 6CD864 802197F4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CD868 802197F8 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6CD86C 802197FC 00000000 */  nop       
/* 6CD870 80219800 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD874 80219804 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD878 80219808 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CD87C 8021980C 00000024 */  and       $zero, $zero, $zero
/* 6CD880 80219810 00000002 */  srl       $zero, $zero, 0
/* 6CD884 80219814 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD888 80219818 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6CD88C 8021981C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6CD890 80219820 00000002 */  srl       $zero, $zero, 0
/* 6CD894 80219824 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD898 80219828 0000005A */  .byte     0x00, 0x00, 0x00, 0x5a
/* 6CD89C 8021982C 00000043 */  sra       $zero, $zero, 1
/* 6CD8A0 80219830 00000003 */  sra       $zero, $zero, 0
/* 6CD8A4 80219834 8026B55C */  lb        $a2, -0x4aa4($at)
/* 6CD8A8 80219838 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD8AC 8021983C F24A7A8B */  scd       $t2, 0x7a8b($s2)
/* 6CD8B0 80219840 00000043 */  sra       $zero, $zero, 1
/* 6CD8B4 80219844 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CD8B8 80219848 8026A510 */  lb        $a2, -0x5af0($at)
/* 6CD8BC 8021984C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD8C0 80219850 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD8C4 80219854 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD8C8 80219858 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CD8CC 8021985C 00000043 */  sra       $zero, $zero, 1
/* 6CD8D0 80219860 00000006 */  srlv      $zero, $zero, $zero
/* 6CD8D4 80219864 80278D08 */  lb        $a3, -0x72f8($at)
/* 6CD8D8 80219868 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD8DC 8021986C 00000012 */  mflo      $zero
/* 6CD8E0 80219870 00000000 */  nop       
/* 6CD8E4 80219874 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD8E8 80219878 00000000 */  nop       
/* 6CD8EC 8021987C 0000000A */  movz      $zero, $zero, $zero
/* 6CD8F0 80219880 00000002 */  srl       $zero, $zero, 0
/* 6CD8F4 80219884 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6CD8F8 80219888 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CD8FC 8021988C 00000043 */  sra       $zero, $zero, 1
/* 6CD900 80219890 00000007 */  srav      $zero, $zero, $zero
/* 6CD904 80219894 8027CFB8 */  lb        $a3, -0x3048($at)
/* 6CD908 80219898 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD90C 8021989C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD910 802198A0 80000000 */  lb        $zero, ($zero)
/* 6CD914 802198A4 00000000 */  nop       
/* 6CD918 802198A8 00000000 */  nop       
/* 6CD91C 802198AC 00000000 */  nop       
/* 6CD920 802198B0 00000013 */  mtlo      $zero
/* 6CD924 802198B4 00000000 */  nop       
/* 6CD928 802198B8 00000043 */  sra       $zero, $zero, 1
/* 6CD92C 802198BC 00000002 */  srl       $zero, $zero, 0
/* 6CD930 802198C0 8024E61C */  lb        $a0, -0x19e4($at)
/* 6CD934 802198C4 00000002 */  srl       $zero, $zero, 0
/* 6CD938 802198C8 00000043 */  sra       $zero, $zero, 1
/* 6CD93C 802198CC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CD940 802198D0 8027D7F0 */  lb        $a3, -0x2810($at)
/* 6CD944 802198D4 00000043 */  sra       $zero, $zero, 1
/* 6CD948 802198D8 00000002 */  srl       $zero, $zero, 0
/* 6CD94C 802198DC 8027D32C */  lb        $a3, -0x2cd4($at)
/* 6CD950 802198E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD954 802198E4 00000043 */  sra       $zero, $zero, 1
/* 6CD958 802198E8 00000003 */  sra       $zero, $zero, 0
/* 6CD95C 802198EC 8026F0EC */  lb        $a2, -0xf14($at)
/* 6CD960 802198F0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD964 802198F4 00000000 */  nop       
/* 6CD968 802198F8 00000043 */  sra       $zero, $zero, 1
/* 6CD96C 802198FC 00000002 */  srl       $zero, $zero, 0
/* 6CD970 80219900 8027C7B0 */  lb        $a3, -0x3850($at)
/* 6CD974 80219904 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD978 80219908 00000002 */  srl       $zero, $zero, 0
/* 6CD97C 8021990C 00000000 */  nop       
/* 6CD980 80219910 00000020 */  add       $zero, $zero, $zero
/* 6CD984 80219914 00000000 */  nop       
/* 6CD988 80219918 00000023 */  negu      $zero, $zero
/* 6CD98C 8021991C 00000000 */  nop       
/* 6CD990 80219920 00000043 */  sra       $zero, $zero, 1
/* 6CD994 80219924 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CD998 80219928 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6CD99C 8021992C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CD9A0 80219930 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD9A4 80219934 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD9A8 80219938 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CD9AC 8021993C 00000024 */  and       $zero, $zero, $zero
/* 6CD9B0 80219940 00000002 */  srl       $zero, $zero, 0
/* 6CD9B4 80219944 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6CD9B8 80219948 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD9BC 8021994C 00000043 */  sra       $zero, $zero, 1
/* 6CD9C0 80219950 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CD9C4 80219954 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6CD9C8 80219958 00000000 */  nop       
/* 6CD9CC 8021995C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD9D0 80219960 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD9D4 80219964 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CD9D8 80219968 00000024 */  and       $zero, $zero, $zero
/* 6CD9DC 8021996C 00000002 */  srl       $zero, $zero, 0
/* 6CD9E0 80219970 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CD9E4 80219974 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6CD9E8 80219978 00000027 */  not       $zero, $zero
/* 6CD9EC 8021997C 00000002 */  srl       $zero, $zero, 0
/* 6CD9F0 80219980 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CD9F4 80219984 0000000A */  movz      $zero, $zero, $zero
/* 6CD9F8 80219988 00000043 */  sra       $zero, $zero, 1
/* 6CD9FC 8021998C 00000003 */  sra       $zero, $zero, 0
/* 6CDA00 80219990 8026B55C */  lb        $a2, -0x4aa4($at)
/* 6CDA04 80219994 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CDA08 80219998 F24A7A8B */  scd       $t2, 0x7a8b($s2)
/* 6CDA0C 8021999C 00000043 */  sra       $zero, $zero, 1
/* 6CDA10 802199A0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CDA14 802199A4 8026A510 */  lb        $a2, -0x5af0($at)
/* 6CDA18 802199A8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CDA1C 802199AC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CDA20 802199B0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CDA24 802199B4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CDA28 802199B8 00000043 */  sra       $zero, $zero, 1
/* 6CDA2C 802199BC 00000006 */  srlv      $zero, $zero, $zero
/* 6CDA30 802199C0 80278D08 */  lb        $a3, -0x72f8($at)
/* 6CDA34 802199C4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CDA38 802199C8 0000000C */  syscall   
/* 6CDA3C 802199CC 00000000 */  nop       
/* 6CDA40 802199D0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CDA44 802199D4 00000000 */  nop       
/* 6CDA48 802199D8 00000046 */  rotrv     $zero, $zero, $zero
/* 6CDA4C 802199DC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CDA50 802199E0 80219A90 */  lb        $at, -0x6570($at)
/* 6CDA54 802199E4 00000043 */  sra       $zero, $zero, 1
/* 6CDA58 802199E8 00000002 */  srl       $zero, $zero, 0
/* 6CDA5C 802199EC 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 6CDA60 802199F0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CDA64 802199F4 00000008 */  jr        $zero
/* 6CDA68 802199F8 00000001 */   movf     $zero, $zero, $fcc0
/* 6CDA6C 802199FC 00000002 */  srl       $zero, $zero, 0
/* 6CDA70 80219A00 00000043 */  sra       $zero, $zero, 1
/* 6CDA74 80219A04 00000008 */  jr        $zero
/* 6CDA78 80219A08 8027CCB4 */   lb       $a3, -0x334c($at)
/* 6CDA7C 80219A0C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CDA80 80219A10 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CDA84 80219A14 08000000 */  j         .L80000000
/* 6CDA88 80219A18 00000000 */   nop      
/* 6CDA8C 80219A1C 00000000 */  nop       
/* 6CDA90 80219A20 00000006 */  srlv      $zero, $zero, $zero
/* 6CDA94 80219A24 00000020 */  add       $zero, $zero, $zero
/* 6CDA98 80219A28 00000043 */  sra       $zero, $zero, 1
/* 6CDA9C 80219A2C 00000002 */  srl       $zero, $zero, 0
/* 6CDAA0 80219A30 8024E61C */  lb        $a0, -0x19e4($at)
/* 6CDAA4 80219A34 00000002 */  srl       $zero, $zero, 0
/* 6CDAA8 80219A38 00000043 */  sra       $zero, $zero, 1
/* 6CDAAC 80219A3C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CDAB0 80219A40 8027D7F0 */  lb        $a3, -0x2810($at)
/* 6CDAB4 80219A44 00000025 */  or        $zero, $zero, $zero
/* 6CDAB8 80219A48 00000002 */  srl       $zero, $zero, 0
/* 6CDABC 80219A4C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CDAC0 80219A50 00000001 */  movf      $zero, $zero, $fcc0
/* 6CDAC4 80219A54 00000025 */  or        $zero, $zero, $zero
/* 6CDAC8 80219A58 00000002 */  srl       $zero, $zero, 0
/* 6CDACC 80219A5C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CDAD0 80219A60 002D0107 */  .byte     0x00, 0x2d, 0x01, 0x07
/* 6CDAD4 80219A64 00000024 */  and       $zero, $zero, $zero
/* 6CDAD8 80219A68 00000002 */  srl       $zero, $zero, 0
/* 6CDADC 80219A6C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CDAE0 80219A70 FFFFCFC7 */  sd        $ra, -0x3039($ra)
/* 6CDAE4 80219A74 00000046 */  rotrv     $zero, $zero, $zero
/* 6CDAE8 80219A78 00000001 */  movf      $zero, $zero, $fcc0
/* 6CDAEC 80219A7C 8029AEC0 */  lb        $t1, -0x5140($at)
/* 6CDAF0 80219A80 00000002 */  srl       $zero, $zero, 0
/* 6CDAF4 80219A84 00000000 */  nop       
/* 6CDAF8 80219A88 00000001 */  movf      $zero, $zero, $fcc0
/* 6CDAFC 80219A8C 00000000 */  nop       
/* 6CDB00 80219A90 00000043 */  sra       $zero, $zero, 1
/* 6CDB04 80219A94 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CDB08 80219A98 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6CDB0C 80219A9C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CDB10 80219AA0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CDB14 80219AA4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CDB18 80219AA8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CDB1C 80219AAC 00000027 */  not       $zero, $zero
/* 6CDB20 80219AB0 00000002 */  srl       $zero, $zero, 0
/* 6CDB24 80219AB4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CDB28 80219AB8 00000002 */  srl       $zero, $zero, 0
/* 6CDB2C 80219ABC 00000043 */  sra       $zero, $zero, 1
/* 6CDB30 80219AC0 0000000F */  sync      
/* 6CDB34 80219AC4 802D829C */  lb        $t5, -0x7d64($at)
/* 6CDB38 80219AC8 00000017 */  dsrav     $zero, $zero, $zero
/* 6CDB3C 80219ACC 00000000 */  nop       
/* 6CDB40 80219AD0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CDB44 80219AD4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CDB48 80219AD8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CDB4C 80219ADC 00000000 */  nop       
/* 6CDB50 80219AE0 00000000 */  nop       
/* 6CDB54 80219AE4 00000000 */  nop       
/* 6CDB58 80219AE8 00000000 */  nop       
/* 6CDB5C 80219AEC 00000000 */  nop       
/* 6CDB60 80219AF0 00000000 */  nop       
/* 6CDB64 80219AF4 00000000 */  nop       
/* 6CDB68 80219AF8 00000000 */  nop       
/* 6CDB6C 80219AFC 00000000 */  nop       
/* 6CDB70 80219B00 00000027 */  not       $zero, $zero
/* 6CDB74 80219B04 00000002 */  srl       $zero, $zero, 0
/* 6CDB78 80219B08 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CDB7C 80219B0C 00000010 */  mfhi      $zero
/* 6CDB80 80219B10 00000027 */  not       $zero, $zero
/* 6CDB84 80219B14 00000002 */  srl       $zero, $zero, 0
/* 6CDB88 80219B18 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CDB8C 80219B1C 00000002 */  srl       $zero, $zero, 0
/* 6CDB90 80219B20 00000043 */  sra       $zero, $zero, 1
/* 6CDB94 80219B24 0000000F */  sync      
/* 6CDB98 80219B28 802D829C */  lb        $t5, -0x7d64($at)
/* 6CDB9C 80219B2C 0000003E */  dsrl32    $zero, $zero, 0
/* 6CDBA0 80219B30 00000000 */  nop       
/* 6CDBA4 80219B34 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CDBA8 80219B38 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CDBAC 80219B3C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CDBB0 80219B40 F24A8680 */  scd       $t2, -0x7980($s2)
/* 6CDBB4 80219B44 0000001E */  ddiv      $zero, $zero, $zero
/* 6CDBB8 80219B48 00000000 */  nop       
/* 6CDBBC 80219B4C 00000000 */  nop       
/* 6CDBC0 80219B50 00000000 */  nop       
/* 6CDBC4 80219B54 00000000 */  nop       
/* 6CDBC8 80219B58 00000000 */  nop       
/* 6CDBCC 80219B5C 00000000 */  nop       
/* 6CDBD0 80219B60 00000000 */  nop       
/* 6CDBD4 80219B64 00000043 */  sra       $zero, $zero, 1
/* 6CDBD8 80219B68 00000003 */  sra       $zero, $zero, 0
/* 6CDBDC 80219B6C 8025385C */  lb        $a1, 0x385c($at)
/* 6CDBE0 80219B70 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CDBE4 80219B74 00002078 */  dsll      $a0, $zero, 1
/* 6CDBE8 80219B78 00000043 */  sra       $zero, $zero, 1
/* 6CDBEC 80219B7C 00000002 */  srl       $zero, $zero, 0
/* 6CDBF0 80219B80 80254218 */  lb        $a1, 0x4218($at)
/* 6CDBF4 80219B84 0000000B */  movn      $zero, $zero, $zero
/* 6CDBF8 80219B88 00000056 */  drotrv    $zero, $zero, $zero
/* 6CDBFC 80219B8C 00000000 */  nop       
/* 6CDC00 80219B90 00000043 */  sra       $zero, $zero, 1
/* 6CDC04 80219B94 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CDC08 80219B98 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 6CDC0C 80219B9C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CDC10 80219BA0 00000000 */  nop       
/* 6CDC14 80219BA4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CDC18 80219BA8 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 6CDC1C 80219BAC 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6CDC20 80219BB0 00000000 */  nop       
/* 6CDC24 80219BB4 00000002 */  srl       $zero, $zero, 0
.L80219BB8:
/* 6CDC28 80219BB8 00000000 */  nop       
/* 6CDC2C 80219BBC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CDC30 80219BC0 00000000 */  nop       
/* 6CDC34 80219BC4 00000000 */  nop       
/* 6CDC38 80219BC8 00000000 */  nop       
/* 6CDC3C 80219BCC 00000000 */  nop       
/* 6CDC40 80219BD0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CDC44 80219BD4 00590001 */  movt      $zero, $v0, $fcc6
/* 6CDC48 80219BD8 0000000C */  syscall   
/* 6CDC4C 80219BDC 00590000 */  .byte     0x00, 0x59, 0x00, 0x00
/* 6CDC50 80219BE0 00000006 */  srlv      $zero, $zero, $zero
/* 6CDC54 80219BE4 00590011 */  .byte     0x00, 0x59, 0x00, 0x11
/* 6CDC58 80219BE8 00000009 */  jr        $zero
/* 6CDC5C 80219BEC 00590001 */   movt     $zero, $v0, $fcc6
/* 6CDC60 80219BF0 00000008 */  jr        $zero
/* 6CDC64 80219BF4 00590000 */   .byte    0x00, 0x59, 0x00, 0x00
/* 6CDC68 80219BF8 0000000B */  movn      $zero, $zero, $zero
/* 6CDC6C 80219BFC 00590001 */  movt      $zero, $v0, $fcc6
/* 6CDC70 80219C00 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CDC74 80219C04 00590000 */  .byte     0x00, 0x59, 0x00, 0x00
/* 6CDC78 80219C08 00000004 */  sllv      $zero, $zero, $zero
/* 6CDC7C 80219C0C 00590013 */  .byte     0x00, 0x59, 0x00, 0x13
/* 6CDC80 80219C10 00000003 */  sra       $zero, $zero, 0
/* 6CDC84 80219C14 00590013 */  .byte     0x00, 0x59, 0x00, 0x13
/* 6CDC88 80219C18 00000000 */  nop       
/* 6CDC8C 80219C1C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CDC90 80219C20 00590003 */  .byte     0x00, 0x59, 0x00, 0x03
/* 6CDC94 80219C24 0000000C */  syscall   
/* 6CDC98 80219C28 00590000 */  .byte     0x00, 0x59, 0x00, 0x00
/* 6CDC9C 80219C2C 00000006 */  srlv      $zero, $zero, $zero
/* 6CDCA0 80219C30 00590011 */  .byte     0x00, 0x59, 0x00, 0x11
/* 6CDCA4 80219C34 00000009 */  jr        $zero
/* 6CDCA8 80219C38 00590003 */   .byte    0x00, 0x59, 0x00, 0x03
/* 6CDCAC 80219C3C 00000008 */  jr        $zero
/* 6CDCB0 80219C40 00590000 */   .byte    0x00, 0x59, 0x00, 0x00
/* 6CDCB4 80219C44 0000000B */  movn      $zero, $zero, $zero
/* 6CDCB8 80219C48 00590003 */  .byte     0x00, 0x59, 0x00, 0x03
/* 6CDCBC 80219C4C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CDCC0 80219C50 00590000 */  .byte     0x00, 0x59, 0x00, 0x00
/* 6CDCC4 80219C54 00000004 */  sllv      $zero, $zero, $zero
/* 6CDCC8 80219C58 00590013 */  .byte     0x00, 0x59, 0x00, 0x13
/* 6CDCCC 80219C5C 00000003 */  sra       $zero, $zero, 0
/* 6CDCD0 80219C60 00590013 */  .byte     0x00, 0x59, 0x00, 0x13
/* 6CDCD4 80219C64 00000000 */  nop       
/* 6CDCD8 80219C68 00000001 */  movf      $zero, $zero, $fcc0
/* 6CDCDC 80219C6C 0059000F */  sync      
/* 6CDCE0 80219C70 0000000C */  syscall   
/* 6CDCE4 80219C74 00590010 */  .byte     0x00, 0x59, 0x00, 0x10
/* 6CDCE8 80219C78 00000006 */  srlv      $zero, $zero, $zero
/* 6CDCEC 80219C7C 00590012 */  .byte     0x00, 0x59, 0x00, 0x12
/* 6CDCF0 80219C80 00000009 */  jr        $zero
/* 6CDCF4 80219C84 0059000F */   sync     
/* 6CDCF8 80219C88 00000008 */  jr        $zero
/* 6CDCFC 80219C8C 00590010 */   .byte    0x00, 0x59, 0x00, 0x10
/* 6CDD00 80219C90 0000000B */  movn      $zero, $zero, $zero
/* 6CDD04 80219C94 0059000F */  sync      
/* 6CDD08 80219C98 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CDD0C 80219C9C 00590010 */  .byte     0x00, 0x59, 0x00, 0x10
/* 6CDD10 80219CA0 00000004 */  sllv      $zero, $zero, $zero
/* 6CDD14 80219CA4 00590014 */  dsllv     $zero, $t9, $v0
/* 6CDD18 80219CA8 00000003 */  sra       $zero, $zero, 0
/* 6CDD1C 80219CAC 00590014 */  dsllv     $zero, $t9, $v0
/* 6CDD20 80219CB0 00000000 */  nop       
/* 6CDD24 80219CB4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CDD28 80219CB8 00590006 */  srlv      $zero, $t9, $v0
/* 6CDD2C 80219CBC 0000000C */  syscall   
/* 6CDD30 80219CC0 00590006 */  srlv      $zero, $t9, $v0
/* 6CDD34 80219CC4 00000006 */  srlv      $zero, $zero, $zero
/* 6CDD38 80219CC8 00590006 */  srlv      $zero, $t9, $v0
/* 6CDD3C 80219CCC 00000009 */  jr        $zero
/* 6CDD40 80219CD0 00590006 */   srlv     $zero, $t9, $v0
/* 6CDD44 80219CD4 00000008 */  jr        $zero
/* 6CDD48 80219CD8 00590006 */   srlv     $zero, $t9, $v0
/* 6CDD4C 80219CDC 0000000B */  movn      $zero, $zero, $zero
/* 6CDD50 80219CE0 00590006 */  srlv      $zero, $t9, $v0
/* 6CDD54 80219CE4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CDD58 80219CE8 00590006 */  srlv      $zero, $t9, $v0
/* 6CDD5C 80219CEC 00000004 */  sllv      $zero, $zero, $zero
/* 6CDD60 80219CF0 00590006 */  srlv      $zero, $t9, $v0
/* 6CDD64 80219CF4 00000003 */  sra       $zero, $zero, 0
/* 6CDD68 80219CF8 00590006 */  srlv      $zero, $t9, $v0
/* 6CDD6C 80219CFC 00000000 */  nop       
/* 6CDD70 80219D00 00000001 */  movf      $zero, $zero, $fcc0
/* 6CDD74 80219D04 00000003 */  sra       $zero, $zero, 0
/* 6CDD78 80219D08 0000000C */  syscall   
/* 6CDD7C 80219D0C 00000003 */  sra       $zero, $zero, 0
/* 6CDD80 80219D10 00000000 */  nop       
/* 6CDD84 80219D14 00000001 */  movf      $zero, $zero, $fcc0
/* 6CDD88 80219D18 00000000 */  nop       
/* 6CDD8C 80219D1C 00000000 */  nop       
/* 6CDD90 80219D20 00000001 */  movf      $zero, $zero, $fcc0
/* 6CDD94 80219D24 00000003 */  sra       $zero, $zero, 0
/* 6CDD98 80219D28 00000002 */  srl       $zero, $zero, 0
/* 6CDD9C 80219D2C 00000003 */  sra       $zero, $zero, 0
/* 6CDDA0 80219D30 00000000 */  nop       
/* 6CDDA4 80219D34 00000001 */  movf      $zero, $zero, $fcc0
/* 6CDDA8 80219D38 00000000 */  nop       
/* 6CDDAC 80219D3C 00000002 */  srl       $zero, $zero, 0
/* 6CDDB0 80219D40 00000000 */  nop       
/* 6CDDB4 80219D44 00000006 */  srlv      $zero, $zero, $zero
/* 6CDDB8 80219D48 00000032 */  tlt       $zero, $zero
/* 6CDDBC 80219D4C 00000009 */  jr        $zero
/* 6CDDC0 80219D50 0000003C */   dsll32   $zero, $zero, 0
/* 6CDDC4 80219D54 00000007 */  srav      $zero, $zero, $zero
/* 6CDDC8 80219D58 00000000 */  nop       
/* 6CDDCC 80219D5C 00000004 */  sllv      $zero, $zero, $zero
/* 6CDDD0 80219D60 0000004B */  .byte     0x00, 0x00, 0x00, 0x4b
/* 6CDDD4 80219D64 00000003 */  sra       $zero, $zero, 0
/* 6CDDD8 80219D68 00000000 */  nop       
/* 6CDDDC 80219D6C 0000000B */  movn      $zero, $zero, $zero
/* 6CDDE0 80219D70 00000050 */  .byte     0x00, 0x00, 0x00, 0x50
/* 6CDDE4 80219D74 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CDDE8 80219D78 0000004B */  .byte     0x00, 0x00, 0x00, 0x4b
/* 6CDDEC 80219D7C 0000000A */  movz      $zero, $zero, $zero
/* 6CDDF0 80219D80 00000046 */  rotrv     $zero, $zero, $zero
/* 6CDDF4 80219D84 00000008 */  jr        $zero
/* 6CDDF8 80219D88 00000050 */   .byte    0x00, 0x00, 0x00, 0x50
/* 6CDDFC 80219D8C 0000001F */  ddivu     $zero, $zero, $zero
/* 6CDE00 80219D90 00000000 */  nop       
/* 6CDE04 80219D94 00000020 */  add       $zero, $zero, $zero
/* 6CDE08 80219D98 FFFFFFFF */  sd        $ra, -1($ra)
/* 6CDE0C 80219D9C 00000025 */  or        $zero, $zero, $zero
/* 6CDE10 80219DA0 00000000 */  nop       
/* 6CDE14 80219DA4 00000022 */  neg       $zero, $zero
/* 6CDE18 80219DA8 00000000 */  nop       
/* 6CDE1C 80219DAC 00000024 */  and       $zero, $zero, $zero
/* 6CDE20 80219DB0 00000000 */  nop       
/* 6CDE24 80219DB4 00000023 */  negu      $zero, $zero
/* 6CDE28 80219DB8 00000000 */  nop       
/* 6CDE2C 80219DBC 00000021 */  addu      $zero, $zero, $zero
/* 6CDE30 80219DC0 00000000 */  nop       
/* 6CDE34 80219DC4 00000026 */  xor       $zero, $zero, $zero
/* 6CDE38 80219DC8 00000000 */  nop       
/* 6CDE3C 80219DCC 00000027 */  not       $zero, $zero
/* 6CDE40 80219DD0 00000000 */  nop       
/* 6CDE44 80219DD4 00000029 */  .byte     0x00, 0x00, 0x00, 0x29
/* 6CDE48 80219DD8 FFFFFFFF */  sd        $ra, -1($ra)
/* 6CDE4C 80219DDC 00000000 */  nop       
/* 6CDE50 80219DE0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CDE54 80219DE4 00000000 */  nop       
/* 6CDE58 80219DE8 00000002 */  srl       $zero, $zero, 0
/* 6CDE5C 80219DEC 00000000 */  nop       
/* 6CDE60 80219DF0 00000006 */  srlv      $zero, $zero, $zero
/* 6CDE64 80219DF4 00000000 */  nop       
/* 6CDE68 80219DF8 00000009 */  jr        $zero
/* 6CDE6C 80219DFC 00000000 */   nop      
/* 6CDE70 80219E00 00000004 */  sllv      $zero, $zero, $zero
/* 6CDE74 80219E04 00000000 */  nop       
/* 6CDE78 80219E08 00000003 */  sra       $zero, $zero, 0
/* 6CDE7C 80219E0C 00000000 */  nop       
/* 6CDE80 80219E10 0000000B */  movn      $zero, $zero, $zero
/* 6CDE84 80219E14 00000000 */  nop       
/* 6CDE88 80219E18 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CDE8C 80219E1C 00000000 */  nop       
/* 6CDE90 80219E20 0000000A */  movz      $zero, $zero, $zero
/* 6CDE94 80219E24 00000000 */  nop       
/* 6CDE98 80219E28 00000008 */  jr        $zero
/* 6CDE9C 80219E2C 00000000 */   nop      
/* 6CDEA0 80219E30 0000001F */  ddivu     $zero, $zero, $zero
/* 6CDEA4 80219E34 00000000 */  nop       
/* 6CDEA8 80219E38 00000020 */  add       $zero, $zero, $zero
/* 6CDEAC 80219E3C 00000000 */  nop       
/* 6CDEB0 80219E40 00000025 */  or        $zero, $zero, $zero
/* 6CDEB4 80219E44 00000000 */  nop       
/* 6CDEB8 80219E48 00000024 */  and       $zero, $zero, $zero
/* 6CDEBC 80219E4C 00000000 */  nop       
/* 6CDEC0 80219E50 00000023 */  negu      $zero, $zero
/* 6CDEC4 80219E54 00000000 */  nop       
/* 6CDEC8 80219E58 00000021 */  addu      $zero, $zero, $zero
/* 6CDECC 80219E5C 00000000 */  nop       
/* 6CDED0 80219E60 00000026 */  xor       $zero, $zero, $zero
/* 6CDED4 80219E64 00000000 */  nop       
/* 6CDED8 80219E68 00000027 */  not       $zero, $zero
/* 6CDEDC 80219E6C 00000000 */  nop       
/* 6CDEE0 80219E70 00000029 */  .byte     0x00, 0x00, 0x00, 0x29
/* 6CDEE4 80219E74 00000000 */  nop       
/* 6CDEE8 80219E78 00000000 */  nop       
/* 6CDEEC 80219E7C 00800000 */  .byte     0x00, 0x80, 0x00, 0x00
/* 6CDEF0 80219E80 01000000 */  .byte     0x01, 0x00, 0x00, 0x00
/* 6CDEF4 80219E84 002000FF */  .byte     0x00, 0x20, 0x00, 0xff
/* 6CDEF8 80219E88 80219BD0 */  lb        $at, -0x6430($at)
/* 6CDEFC 80219E8C 80219D00 */  lb        $at, -0x6300($at)
/* 6CDF00 80219E90 00001010 */  mfhi      $v0
/* 6CDF04 80219E94 00000000 */  nop       
/* 6CDF08 80219E98 00F40000 */  .byte     0x00, 0xf4, 0x00, 0x00
/* 6CDF0C 80219E9C 00000000 */  nop       
/* 6CDF10 80219EA0 00000000 */  nop       
/* 6CDF14 80219EA4 004C1908 */  .byte     0x00, 0x4c, 0x19, 0x08
/* 6CDF18 80219EA8 00010000 */  sll       $zero, $at, 0
/* 6CDF1C 80219EAC 80219E7C */  lb        $at, -0x6184($at)
/* 6CDF20 80219EB0 80219EC8 */  lb        $at, -0x6138($at)
/* 6CDF24 80219EB4 80219D34 */  lb        $at, -0x62cc($at)
/* 6CDF28 80219EB8 324B413C */  andi      $t3, $s2, 0x413c
/* 6CDF2C 80219EBC 5F005502 */  bgtzl     $t8, .L8022F2C8
/* 6CDF30 80219EC0 202A0000 */   addi     $t2, $at, 0
/* 6CDF34 80219EC4 F1200520 */  scd       $zero, 0x520($t1)
/* 6CDF38 80219EC8 00000043 */  sra       $zero, $zero, 1
/* 6CDF3C 80219ECC 00000003 */  sra       $zero, $zero, 0
/* 6CDF40 80219ED0 80278930 */  lb        $a3, -0x76d0($at)
/* 6CDF44 80219ED4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CDF48 80219ED8 8021DF34 */  lb        $at, -0x20cc($at)
/* 6CDF4C 80219EDC 00000043 */  sra       $zero, $zero, 1
/* 6CDF50 80219EE0 00000003 */  sra       $zero, $zero, 0
/* 6CDF54 80219EE4 80278A94 */  lb        $a3, -0x756c($at)
/* 6CDF58 80219EE8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CDF5C 80219EEC 8021A23C */  lb        $at, -0x5dc4($at)
/* 6CDF60 80219EF0 00000043 */  sra       $zero, $zero, 1
/* 6CDF64 80219EF4 00000003 */  sra       $zero, $zero, 0
/* 6CDF68 80219EF8 80278C20 */  lb        $a3, -0x73e0($at)
/* 6CDF6C 80219EFC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CDF70 80219F00 8021A724 */  lb        $at, -0x58dc($at)
/* 6CDF74 80219F04 00000043 */  sra       $zero, $zero, 1
/* 6CDF78 80219F08 00000003 */  sra       $zero, $zero, 0
/* 6CDF7C 80219F0C 80278C94 */  lb        $a3, -0x736c($at)
/* 6CDF80 80219F10 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CDF84 80219F14 8021A018 */  lb        $at, -0x5fe8($at)
/* 6CDF88 80219F18 00000043 */  sra       $zero, $zero, 1
/* 6CDF8C 80219F1C 00000004 */  sllv      $zero, $zero, $zero
/* 6CDF90 80219F20 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6CDF94 80219F24 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CDF98 80219F28 00000000 */  nop       
/* 6CDF9C 80219F2C 00000000 */  nop       
/* 6CDFA0 80219F30 00000043 */  sra       $zero, $zero, 1
/* 6CDFA4 80219F34 00000004 */  sllv      $zero, $zero, $zero
/* 6CDFA8 80219F38 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6CDFAC 80219F3C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CDFB0 80219F40 00000001 */  movf      $zero, $zero, $fcc0
/* 6CDFB4 80219F44 00000000 */  nop       
/* 6CDFB8 80219F48 00000043 */  sra       $zero, $zero, 1
/* 6CDFBC 80219F4C 00000003 */  sra       $zero, $zero, 0
/* 6CDFC0 80219F50 8026A0D4 */  lb        $a2, -0x5f2c($at)
/* 6CDFC4 80219F54 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CDFC8 80219F58 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CDFCC 80219F5C 00000043 */  sra       $zero, $zero, 1
/* 6CDFD0 80219F60 00000004 */  sllv      $zero, $zero, $zero
/* 6CDFD4 80219F64 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6CDFD8 80219F68 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CDFDC 80219F6C 00000002 */  srl       $zero, $zero, 0
/* 6CDFE0 80219F70 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CDFE4 80219F74 00000014 */  dsllv     $zero, $zero, $zero
/* 6CDFE8 80219F78 00000001 */  movf      $zero, $zero, $fcc0
/* 6CDFEC 80219F7C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CDFF0 80219F80 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CDFF4 80219F84 00000001 */  movf      $zero, $zero, $fcc0
/* 6CDFF8 80219F88 00000000 */  nop       
/* 6CDFFC 80219F8C 00000043 */  sra       $zero, $zero, 1
/* 6CE000 80219F90 00000003 */  sra       $zero, $zero, 0
.L80219F94:
/* 6CE004 80219F94 8026F638 */  lb        $a2, -0x9c8($at)
/* 6CE008 80219F98 00000004 */  sllv      $zero, $zero, $zero
/* 6CE00C 80219F9C 00000000 */  nop       
/* 6CE010 80219FA0 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CE014 80219FA4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE018 80219FA8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE01C 80219FAC 00000043 */  sra       $zero, $zero, 1
/* 6CE020 80219FB0 00000003 */  sra       $zero, $zero, 0
/* 6CE024 80219FB4 8026F638 */  lb        $a2, -0x9c8($at)
/* 6CE028 80219FB8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE02C 80219FBC 00000000 */  nop       
/* 6CE030 80219FC0 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CE034 80219FC4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE038 80219FC8 00000002 */  srl       $zero, $zero, 0
/* 6CE03C 80219FCC 00000043 */  sra       $zero, $zero, 1
/* 6CE040 80219FD0 00000003 */  sra       $zero, $zero, 0
/* 6CE044 80219FD4 8026F638 */  lb        $a2, -0x9c8($at)
/* 6CE048 80219FD8 00000006 */  srlv      $zero, $zero, $zero
/* 6CE04C 80219FDC 00000000 */  nop       
/* 6CE050 80219FE0 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CE054 80219FE4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE058 80219FE8 00000003 */  sra       $zero, $zero, 0
/* 6CE05C 80219FEC 00000043 */  sra       $zero, $zero, 1
/* 6CE060 80219FF0 00000003 */  sra       $zero, $zero, 0
/* 6CE064 80219FF4 8026F638 */  lb        $a2, -0x9c8($at)
/* 6CE068 80219FF8 00000007 */  srav      $zero, $zero, $zero
/* 6CE06C 80219FFC 00000000 */  nop       
/* 6CE070 8021A000 00000023 */  negu      $zero, $zero
.L8021A004:
/* 6CE074 8021A004 00000000 */  nop       
/* 6CE078 8021A008 00000002 */  srl       $zero, $zero, 0
/* 6CE07C 8021A00C 00000000 */  nop       
/* 6CE080 8021A010 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE084 8021A014 00000000 */  nop       
/* 6CE088 8021A018 00000043 */  sra       $zero, $zero, 1
/* 6CE08C 8021A01C 00000002 */  srl       $zero, $zero, 0
/* 6CE090 8021A020 80269E28 */  lb        $a2, -0x61d8($at)
.L8021A024:
/* 6CE094 8021A024 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE098 8021A028 00000014 */  dsllv     $zero, $zero, $zero
/* 6CE09C 8021A02C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE0A0 8021A030 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE0A4 8021A034 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CE0A8 8021A038 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE0AC 8021A03C 0000000A */  movz      $zero, $zero, $zero
/* 6CE0B0 8021A040 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CE0B4 8021A044 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE0B8 8021A048 0000000C */  syscall   
/* 6CE0BC 8021A04C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CE0C0 8021A050 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE0C4 8021A054 0000000B */  movn      $zero, $zero, $zero
/* 6CE0C8 8021A058 00000043 */  sra       $zero, $zero, 1
/* 6CE0CC 8021A05C 00000003 */  sra       $zero, $zero, 0
/* 6CE0D0 8021A060 8026F638 */  lb        $a2, -0x9c8($at)
/* 6CE0D4 8021A064 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE0D8 8021A068 00000000 */  nop       
/* 6CE0DC 8021A06C 00000023 */  negu      $zero, $zero
/* 6CE0E0 8021A070 00000000 */  nop       
/* 6CE0E4 8021A074 00000002 */  srl       $zero, $zero, 0
/* 6CE0E8 8021A078 00000000 */  nop       
/* 6CE0EC 8021A07C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE0F0 8021A080 00000000 */  nop       
/* 6CE0F4 8021A084 00000014 */  dsllv     $zero, $zero, $zero
/* 6CE0F8 8021A088 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE0FC 8021A08C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE100 8021A090 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CE104 8021A094 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE108 8021A098 00000000 */  nop       
/* 6CE10C 8021A09C 00000010 */  mfhi      $zero
/* 6CE110 8021A0A0 00000002 */  srl       $zero, $zero, 0
/* 6CE114 8021A0A4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CE118 8021A0A8 00041000 */  sll       $v0, $a0, 0
/* 6CE11C 8021A0AC 00000043 */  sra       $zero, $zero, 1
/* 6CE120 8021A0B0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE124 8021A0B4 8027D380 */  lb        $a3, -0x2c80($at)
/* 6CE128 8021A0B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE12C 8021A0BC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE130 8021A0C0 FFFFFFFB */  sd        $ra, -5($ra)
/* 6CE134 8021A0C4 0000000F */  sync      
/* 6CE138 8021A0C8 00000043 */  sra       $zero, $zero, 1
/* 6CE13C 8021A0CC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE140 8021A0D0 8027D4C8 */  lb        $a3, -0x2b38($at)
/* 6CE144 8021A0D4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE148 8021A0D8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE14C 8021A0DC 00000000 */  nop       
/* 6CE150 8021A0E0 00000000 */  nop       
/* 6CE154 8021A0E4 00000043 */  sra       $zero, $zero, 1
/* 6CE158 8021A0E8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE15C 8021A0EC 80218020 */  lb        $at, -0x7fe0($at)
/* 6CE160 8021A0F0 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 6CE164 8021A0F4 00000014 */  dsllv     $zero, $zero, $zero
/* 6CE168 8021A0F8 0000000A */  movz      $zero, $zero, $zero
/* 6CE16C 8021A0FC 00000014 */  dsllv     $zero, $zero, $zero
/* 6CE170 8021A100 00000012 */  mflo      $zero
/* 6CE174 8021A104 00000000 */  nop       
/* 6CE178 8021A108 00000043 */  sra       $zero, $zero, 1
/* 6CE17C 8021A10C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE180 8021A110 8027D380 */  lb        $a3, -0x2c80($at)
/* 6CE184 8021A114 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE188 8021A118 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE18C 8021A11C FFFFFFFC */  sd        $ra, -4($ra)
/* 6CE190 8021A120 00000020 */  add       $zero, $zero, $zero
/* 6CE194 8021A124 00000043 */  sra       $zero, $zero, 1
/* 6CE198 8021A128 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE19C 8021A12C 8027D4C8 */  lb        $a3, -0x2b38($at)
/* 6CE1A0 8021A130 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE1A4 8021A134 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE1A8 8021A138 FFFFFFFF */  sd        $ra, -1($ra)
/* 6CE1AC 8021A13C FFFFFFFC */  sd        $ra, -4($ra)
/* 6CE1B0 8021A140 00000043 */  sra       $zero, $zero, 1
/* 6CE1B4 8021A144 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE1B8 8021A148 80218020 */  lb        $at, -0x7fe0($at)
/* 6CE1BC 8021A14C FFFFFFF1 */  sd        $ra, -0xf($ra)
/* 6CE1C0 8021A150 00000020 */  add       $zero, $zero, $zero
/* 6CE1C4 8021A154 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE1C8 8021A158 00000020 */  add       $zero, $zero, $zero
/* 6CE1CC 8021A15C 00000013 */  mtlo      $zero
/* 6CE1D0 8021A160 00000000 */  nop       
/* 6CE1D4 8021A164 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CE1D8 8021A168 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE1DC 8021A16C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE1E0 8021A170 00000043 */  sra       $zero, $zero, 1
/* 6CE1E4 8021A174 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE1E8 8021A178 8027D380 */  lb        $a3, -0x2c80($at)
/* 6CE1EC 8021A17C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE1F0 8021A180 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE1F4 8021A184 FFFFFFFB */  sd        $ra, -5($ra)
/* 6CE1F8 8021A188 0000000F */  sync      
/* 6CE1FC 8021A18C 00000043 */  sra       $zero, $zero, 1
/* 6CE200 8021A190 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE204 8021A194 8027D4C8 */  lb        $a3, -0x2b38($at)
/* 6CE208 8021A198 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE20C 8021A19C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE210 8021A1A0 00000000 */  nop       
/* 6CE214 8021A1A4 00000000 */  nop       
/* 6CE218 8021A1A8 00000043 */  sra       $zero, $zero, 1
/* 6CE21C 8021A1AC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE220 8021A1B0 80218020 */  lb        $at, -0x7fe0($at)
/* 6CE224 8021A1B4 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 6CE228 8021A1B8 00000014 */  dsllv     $zero, $zero, $zero
/* 6CE22C 8021A1BC 0000000A */  movz      $zero, $zero, $zero
.L8021A1C0:
/* 6CE230 8021A1C0 00000014 */  dsllv     $zero, $zero, $zero
/* 6CE234 8021A1C4 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CE238 8021A1C8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE23C 8021A1CC 00000002 */  srl       $zero, $zero, 0
/* 6CE240 8021A1D0 00000043 */  sra       $zero, $zero, 1
.L8021A1D4:
/* 6CE244 8021A1D4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE248 8021A1D8 8027D380 */  lb        $a3, -0x2c80($at)
/* 6CE24C 8021A1DC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE250 8021A1E0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE254 8021A1E4 FFFFFFFC */  sd        $ra, -4($ra)
/* 6CE258 8021A1E8 00000014 */  dsllv     $zero, $zero, $zero
/* 6CE25C 8021A1EC 00000043 */  sra       $zero, $zero, 1
/* 6CE260 8021A1F0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE264 8021A1F4 8027D4C8 */  lb        $a3, -0x2b38($at)
/* 6CE268 8021A1F8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE26C 8021A1FC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE270 8021A200 00000000 */  nop       
/* 6CE274 8021A204 FFFFFFFA */  sd        $ra, -6($ra)
.L8021A208:
/* 6CE278 8021A208 00000043 */  sra       $zero, $zero, 1
/* 6CE27C 8021A20C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE280 8021A210 80218020 */  lb        $at, -0x7fe0($at)
/* 6CE284 8021A214 FFFFFFF1 */  sd        $ra, -0xf($ra)
/* 6CE288 8021A218 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CE28C 8021A21C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE290 8021A220 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CE294 8021A224 00000023 */  negu      $zero, $zero
/* 6CE298 8021A228 00000000 */  nop       
/* 6CE29C 8021A22C 00000002 */  srl       $zero, $zero, 0
/* 6CE2A0 8021A230 00000000 */  nop       
/* 6CE2A4 8021A234 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE2A8 8021A238 00000000 */  nop       
/* 6CE2AC 8021A23C 00000003 */  sra       $zero, $zero, 0
/* 6CE2B0 8021A240 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE2B4 8021A244 00000000 */  nop       
/* 6CE2B8 8021A248 00000043 */  sra       $zero, $zero, 1
/* 6CE2BC 8021A24C 00000003 */  sra       $zero, $zero, 0
/* 6CE2C0 8021A250 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6CE2C4 8021A254 00000050 */  .byte     0x00, 0x00, 0x00, 0x50
/* 6CE2C8 8021A258 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6CE2CC 8021A25C 00000027 */  not       $zero, $zero
.L8021A260:
/* 6CE2D0 8021A260 00000002 */  srl       $zero, $zero, 0
/* 6CE2D4 8021A264 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6CE2D8 8021A268 00000050 */  .byte     0x00, 0x00, 0x00, 0x50
/* 6CE2DC 8021A26C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE2E0 8021A270 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE2E4 8021A274 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6CE2E8 8021A278 00000003 */  sra       $zero, $zero, 0
/* 6CE2EC 8021A27C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE2F0 8021A280 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE2F4 8021A284 00000043 */  sra       $zero, $zero, 1
.L8021A288:
/* 6CE2F8 8021A288 00000004 */  sllv      $zero, $zero, $zero
/* 6CE2FC 8021A28C 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CE300 8021A290 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE304 8021A294 00000000 */  nop       
/* 6CE308 8021A298 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE30C 8021A29C 00000043 */  sra       $zero, $zero, 1
/* 6CE310 8021A2A0 00000003 */  sra       $zero, $zero, 0
/* 6CE314 8021A2A4 8026F230 */  lb        $a2, -0xdd0($at)
/* 6CE318 8021A2A8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE31C 8021A2AC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CE320 8021A2B0 00000046 */  rotrv     $zero, $zero, $zero
/* 6CE324 8021A2B4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE328 8021A2B8 8021A084 */  lb        $at, -0x5f7c($at)
/* 6CE32C 8021A2BC 0000000A */  movz      $zero, $zero, $zero
/* 6CE330 8021A2C0 00000002 */  srl       $zero, $zero, 0
/* 6CE334 8021A2C4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE338 8021A2C8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE33C 8021A2CC 00000008 */  jr        $zero
/* 6CE340 8021A2D0 00000001 */   movf     $zero, $zero, $fcc0
/* 6CE344 8021A2D4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE348 8021A2D8 00000004 */  sllv      $zero, $zero, $zero
/* 6CE34C 8021A2DC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE350 8021A2E0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE354 8021A2E4 00000013 */  mtlo      $zero
/* 6CE358 8021A2E8 00000000 */  nop       
/* 6CE35C 8021A2EC 00000010 */  mfhi      $zero
/* 6CE360 8021A2F0 00000002 */  srl       $zero, $zero, 0
/* 6CE364 8021A2F4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CE368 8021A2F8 0235D000 */  .byte     0x02, 0x35, 0xd0, 0x00
/* 6CE36C 8021A2FC 00000008 */  jr        $zero
/* 6CE370 8021A300 00000001 */   movf     $zero, $zero, $fcc0
/* 6CE374 8021A304 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE378 8021A308 00000004 */  sllv      $zero, $zero, $zero
/* 6CE37C 8021A30C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE380 8021A310 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE384 8021A314 00000013 */  mtlo      $zero
/* 6CE388 8021A318 00000000 */  nop       
/* 6CE38C 8021A31C 00000008 */  jr        $zero
/* 6CE390 8021A320 00000001 */   movf     $zero, $zero, $fcc0
/* 6CE394 8021A324 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE398 8021A328 00000006 */  srlv      $zero, $zero, $zero
/* 6CE39C 8021A32C 00000000 */  nop       
/* 6CE3A0 8021A330 00000043 */  sra       $zero, $zero, 1
/* 6CE3A4 8021A334 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE3A8 8021A338 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6CE3AC 8021A33C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE3B0 8021A340 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE3B4 8021A344 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CE3B8 8021A348 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CE3BC 8021A34C 00000027 */  not       $zero, $zero
.L8021A350:
/* 6CE3C0 8021A350 00000002 */  srl       $zero, $zero, 0
/* 6CE3C4 8021A354 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE3C8 8021A358 00000005 */  lsa       $zero, $zero, $zero, 1
.L8021A35C:
/* 6CE3CC 8021A35C 00000043 */  sra       $zero, $zero, 1
/* 6CE3D0 8021A360 00000003 */  sra       $zero, $zero, 0
/* 6CE3D4 8021A364 8026B6D0 */  lb        $a2, -0x4930($at)
/* 6CE3D8 8021A368 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE3DC 8021A36C F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 6CE3E0 8021A370 00000043 */  sra       $zero, $zero, 1
/* 6CE3E4 8021A374 00000004 */  sllv      $zero, $zero, $zero
/* 6CE3E8 8021A378 8027CB7C */  lb        $a3, -0x3484($at)
/* 6CE3EC 8021A37C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE3F0 8021A380 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE3F4 8021A384 80219C1C */  lb        $at, -0x63e4($at)
/* 6CE3F8 8021A388 00000043 */  sra       $zero, $zero, 1
/* 6CE3FC 8021A38C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE400 8021A390 8026A62C */  lb        $a2, -0x59d4($at)
/* 6CE404 8021A394 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE408 8021A398 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE40C 8021A39C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CE410 8021A3A0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CE414 8021A3A4 00000043 */  sra       $zero, $zero, 1
/* 6CE418 8021A3A8 00000003 */  sra       $zero, $zero, 0
/* 6CE41C 8021A3AC 8027A264 */  lb        $a3, -0x5d9c($at)
/* 6CE420 8021A3B0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE424 8021A3B4 00000000 */  nop       
/* 6CE428 8021A3B8 00000043 */  sra       $zero, $zero, 1
/* 6CE42C 8021A3BC 00000004 */  sllv      $zero, $zero, $zero
/* 6CE430 8021A3C0 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CE434 8021A3C4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE438 8021A3C8 00000000 */  nop       
/* 6CE43C 8021A3CC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE440 8021A3D0 00000014 */  dsllv     $zero, $zero, $zero
/* 6CE444 8021A3D4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE448 8021A3D8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE44C 8021A3DC 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CE450 8021A3E0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE454 8021A3E4 00000000 */  nop       
/* 6CE458 8021A3E8 00000043 */  sra       $zero, $zero, 1
/* 6CE45C 8021A3EC 00000004 */  sllv      $zero, $zero, $zero
/* 6CE460 8021A3F0 8027CB7C */  lb        $a3, -0x3484($at)
/* 6CE464 8021A3F4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE468 8021A3F8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE46C 8021A3FC 80219BD0 */  lb        $at, -0x6430($at)
/* 6CE470 8021A400 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CE474 8021A404 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE478 8021A408 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE47C 8021A40C 00000043 */  sra       $zero, $zero, 1
/* 6CE480 8021A410 00000004 */  sllv      $zero, $zero, $zero
/* 6CE484 8021A414 8027CB7C */  lb        $a3, -0x3484($at)
/* 6CE488 8021A418 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE48C 8021A41C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE490 8021A420 80219C68 */  lb        $at, -0x6398($at)
/* 6CE494 8021A424 00000023 */  negu      $zero, $zero
/* 6CE498 8021A428 00000000 */  nop       
/* 6CE49C 8021A42C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE4A0 8021A430 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE4A4 8021A434 00000014 */  dsllv     $zero, $zero, $zero
/* 6CE4A8 8021A438 00000003 */  sra       $zero, $zero, 0
/* 6CE4AC 8021A43C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE4B0 8021A440 00000002 */  srl       $zero, $zero, 0
/* 6CE4B4 8021A444 00000043 */  sra       $zero, $zero, 1
/* 6CE4B8 8021A448 00000004 */  sllv      $zero, $zero, $zero
/* 6CE4BC 8021A44C 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CE4C0 8021A450 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE4C4 8021A454 00000000 */  nop       
/* 6CE4C8 8021A458 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE4CC 8021A45C 00000043 */  sra       $zero, $zero, 1
/* 6CE4D0 8021A460 00000003 */  sra       $zero, $zero, 0
/* 6CE4D4 8021A464 8026F230 */  lb        $a2, -0xdd0($at)
/* 6CE4D8 8021A468 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE4DC 8021A46C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CE4E0 8021A470 00000046 */  rotrv     $zero, $zero, $zero
/* 6CE4E4 8021A474 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE4E8 8021A478 8021A084 */  lb        $at, -0x5f7c($at)
/* 6CE4EC 8021A47C 0000000A */  movz      $zero, $zero, $zero
/* 6CE4F0 8021A480 00000002 */  srl       $zero, $zero, 0
/* 6CE4F4 8021A484 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE4F8 8021A488 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE4FC 8021A48C 00000008 */  jr        $zero
/* 6CE500 8021A490 00000001 */   movf     $zero, $zero, $fcc0
/* 6CE504 8021A494 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE508 8021A498 00000004 */  sllv      $zero, $zero, $zero
/* 6CE50C 8021A49C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE510 8021A4A0 00000002 */  srl       $zero, $zero, 0
/* 6CE514 8021A4A4 00000013 */  mtlo      $zero
/* 6CE518 8021A4A8 00000000 */  nop       
/* 6CE51C 8021A4AC 00000010 */  mfhi      $zero
/* 6CE520 8021A4B0 00000002 */  srl       $zero, $zero, 0
/* 6CE524 8021A4B4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CE528 8021A4B8 0235D000 */  .byte     0x02, 0x35, 0xd0, 0x00
/* 6CE52C 8021A4BC 00000008 */  jr        $zero
/* 6CE530 8021A4C0 00000001 */   movf     $zero, $zero, $fcc0
/* 6CE534 8021A4C4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE538 8021A4C8 00000004 */  sllv      $zero, $zero, $zero
/* 6CE53C 8021A4CC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE540 8021A4D0 00000002 */  srl       $zero, $zero, 0
/* 6CE544 8021A4D4 00000013 */  mtlo      $zero
/* 6CE548 8021A4D8 00000000 */  nop       
/* 6CE54C 8021A4DC 00000008 */  jr        $zero
/* 6CE550 8021A4E0 00000001 */   movf     $zero, $zero, $fcc0
/* 6CE554 8021A4E4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE558 8021A4E8 00000006 */  srlv      $zero, $zero, $zero
/* 6CE55C 8021A4EC 00000000 */  nop       
/* 6CE560 8021A4F0 00000043 */  sra       $zero, $zero, 1
/* 6CE564 8021A4F4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE568 8021A4F8 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6CE56C 8021A4FC FFFFFF81 */  sd        $ra, -0x7f($ra)
.L8021A500:
/* 6CE570 8021A500 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE574 8021A504 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CE578 8021A508 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CE57C 8021A50C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6CE580 8021A510 00000002 */  srl       $zero, $zero, 0
/* 6CE584 8021A514 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE588 8021A518 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE58C 8021A51C 00000043 */  sra       $zero, $zero, 1
/* 6CE590 8021A520 00000003 */  sra       $zero, $zero, 0
/* 6CE594 8021A524 8026B6D0 */  lb        $a2, -0x4930($at)
/* 6CE598 8021A528 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE59C 8021A52C F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 6CE5A0 8021A530 00000043 */  sra       $zero, $zero, 1
/* 6CE5A4 8021A534 00000004 */  sllv      $zero, $zero, $zero
/* 6CE5A8 8021A538 8027CB7C */  lb        $a3, -0x3484($at)
/* 6CE5AC 8021A53C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE5B0 8021A540 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE5B4 8021A544 80219C1C */  lb        $at, -0x63e4($at)
/* 6CE5B8 8021A548 00000043 */  sra       $zero, $zero, 1
/* 6CE5BC 8021A54C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE5C0 8021A550 8026A62C */  lb        $a2, -0x59d4($at)
/* 6CE5C4 8021A554 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE5C8 8021A558 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE5CC 8021A55C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CE5D0 8021A560 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CE5D4 8021A564 00000043 */  sra       $zero, $zero, 1
/* 6CE5D8 8021A568 00000003 */  sra       $zero, $zero, 0
/* 6CE5DC 8021A56C 8027A264 */  lb        $a3, -0x5d9c($at)
/* 6CE5E0 8021A570 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE5E4 8021A574 00000000 */  nop       
/* 6CE5E8 8021A578 00000043 */  sra       $zero, $zero, 1
/* 6CE5EC 8021A57C 00000004 */  sllv      $zero, $zero, $zero
/* 6CE5F0 8021A580 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CE5F4 8021A584 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE5F8 8021A588 00000000 */  nop       
/* 6CE5FC 8021A58C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE600 8021A590 00000014 */  dsllv     $zero, $zero, $zero
/* 6CE604 8021A594 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE608 8021A598 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE60C 8021A59C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CE610 8021A5A0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE614 8021A5A4 00000000 */  nop       
/* 6CE618 8021A5A8 00000043 */  sra       $zero, $zero, 1
/* 6CE61C 8021A5AC 00000004 */  sllv      $zero, $zero, $zero
/* 6CE620 8021A5B0 8027CB7C */  lb        $a3, -0x3484($at)
/* 6CE624 8021A5B4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE628 8021A5B8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE62C 8021A5BC 80219BD0 */  lb        $at, -0x6430($at)
/* 6CE630 8021A5C0 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CE634 8021A5C4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE638 8021A5C8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE63C 8021A5CC 00000043 */  sra       $zero, $zero, 1
/* 6CE640 8021A5D0 00000004 */  sllv      $zero, $zero, $zero
/* 6CE644 8021A5D4 8027CB7C */  lb        $a3, -0x3484($at)
/* 6CE648 8021A5D8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE64C 8021A5DC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE650 8021A5E0 80219C68 */  lb        $at, -0x6398($at)
/* 6CE654 8021A5E4 00000023 */  negu      $zero, $zero
/* 6CE658 8021A5E8 00000000 */  nop       
/* 6CE65C 8021A5EC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CE660 8021A5F0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE664 8021A5F4 00000050 */  .byte     0x00, 0x00, 0x00, 0x50
/* 6CE668 8021A5F8 00000003 */  sra       $zero, $zero, 0
/* 6CE66C 8021A5FC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE670 8021A600 00000003 */  sra       $zero, $zero, 0
/* 6CE674 8021A604 00000043 */  sra       $zero, $zero, 1
/* 6CE678 8021A608 00000004 */  sllv      $zero, $zero, $zero
/* 6CE67C 8021A60C 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CE680 8021A610 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE684 8021A614 00000000 */  nop       
/* 6CE688 8021A618 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE68C 8021A61C 00000043 */  sra       $zero, $zero, 1
/* 6CE690 8021A620 00000003 */  sra       $zero, $zero, 0
/* 6CE694 8021A624 8026F230 */  lb        $a2, -0xdd0($at)
/* 6CE698 8021A628 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE69C 8021A62C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CE6A0 8021A630 00000046 */  rotrv     $zero, $zero, $zero
/* 6CE6A4 8021A634 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE6A8 8021A638 8021A084 */  lb        $at, -0x5f7c($at)
/* 6CE6AC 8021A63C 0000000A */  movz      $zero, $zero, $zero
/* 6CE6B0 8021A640 00000002 */  srl       $zero, $zero, 0
/* 6CE6B4 8021A644 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE6B8 8021A648 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE6BC 8021A64C 00000008 */  jr        $zero
/* 6CE6C0 8021A650 00000001 */   movf     $zero, $zero, $fcc0
/* 6CE6C4 8021A654 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE6C8 8021A658 00000004 */  sllv      $zero, $zero, $zero
/* 6CE6CC 8021A65C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE6D0 8021A660 00000003 */  sra       $zero, $zero, 0
/* 6CE6D4 8021A664 00000013 */  mtlo      $zero
/* 6CE6D8 8021A668 00000000 */  nop       
/* 6CE6DC 8021A66C 00000010 */  mfhi      $zero
/* 6CE6E0 8021A670 00000002 */  srl       $zero, $zero, 0
/* 6CE6E4 8021A674 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CE6E8 8021A678 0235D000 */  .byte     0x02, 0x35, 0xd0, 0x00
/* 6CE6EC 8021A67C 00000008 */  jr        $zero
/* 6CE6F0 8021A680 00000001 */   movf     $zero, $zero, $fcc0
/* 6CE6F4 8021A684 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE6F8 8021A688 00000004 */  sllv      $zero, $zero, $zero
/* 6CE6FC 8021A68C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE700 8021A690 00000003 */  sra       $zero, $zero, 0
/* 6CE704 8021A694 00000013 */  mtlo      $zero
/* 6CE708 8021A698 00000000 */  nop       
/* 6CE70C 8021A69C 00000008 */  jr        $zero
/* 6CE710 8021A6A0 00000001 */   movf     $zero, $zero, $fcc0
/* 6CE714 8021A6A4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE718 8021A6A8 00000006 */  srlv      $zero, $zero, $zero
/* 6CE71C 8021A6AC 00000000 */  nop       
/* 6CE720 8021A6B0 00000004 */  sllv      $zero, $zero, $zero
/* 6CE724 8021A6B4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE728 8021A6B8 00000000 */  nop       
/* 6CE72C 8021A6BC 00000002 */  srl       $zero, $zero, 0
/* 6CE730 8021A6C0 00000000 */  nop       
/* 6CE734 8021A6C4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE738 8021A6C8 00000000 */  nop       
/* 6CE73C 8021A6CC 00000009 */  jr        $zero
/* 6CE740 8021A6D0 00000010 */   mfhi     $zero
/* 6CE744 8021A6D4 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CE748 8021A6D8 0000001A */  div       $zero, $zero, $zero
/* 6CE74C 8021A6DC 0000001E */  ddiv      $zero, $zero, $zero
/* 6CE750 8021A6E0 00000020 */  add       $zero, $zero, $zero
/* 6CE754 8021A6E4 00000021 */  addu      $zero, $zero, $zero
/* 6CE758 8021A6E8 00000020 */  add       $zero, $zero, $zero
/* 6CE75C 8021A6EC 0000001E */  ddiv      $zero, $zero, $zero
/* 6CE760 8021A6F0 0000001A */  div       $zero, $zero, $zero
/* 6CE764 8021A6F4 00000016 */  dsrlv     $zero, $zero, $zero
.L8021A6F8:
/* 6CE768 8021A6F8 00000010 */  mfhi      $zero
/* 6CE76C 8021A6FC 00000009 */  jr        $zero
/* 6CE770 8021A700 00000000 */   nop      
/* 6CE774 8021A704 00000004 */  sllv      $zero, $zero, $zero
/* 6CE778 8021A708 00000006 */  srlv      $zero, $zero, $zero
/* 6CE77C 8021A70C 00000007 */  srav      $zero, $zero, $zero
/* 6CE780 8021A710 00000006 */  srlv      $zero, $zero, $zero
/* 6CE784 8021A714 00000004 */  sllv      $zero, $zero, $zero
/* 6CE788 8021A718 00000000 */  nop       
/* 6CE78C 8021A71C 00000002 */  srl       $zero, $zero, 0
/* 6CE790 8021A720 00000000 */  nop       
/* 6CE794 8021A724 00000043 */  sra       $zero, $zero, 1
/* 6CE798 8021A728 00000003 */  sra       $zero, $zero, 0
/* 6CE79C 8021A72C 8026F0EC */  lb        $a2, -0xf14($at)
/* 6CE7A0 8021A730 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE7A4 8021A734 00000000 */  nop       
/* 6CE7A8 8021A738 00000043 */  sra       $zero, $zero, 1
.L8021A73C:
/* 6CE7AC 8021A73C 00000003 */  sra       $zero, $zero, 0
/* 6CE7B0 8021A740 80278B4C */  lb        $a3, -0x74b4($at)
/* 6CE7B4 8021A744 FFFFFF81 */  sd        $ra, -0x7f($ra)
.L8021A748:
/* 6CE7B8 8021A748 00000000 */  nop       
/* 6CE7BC 8021A74C 00000043 */  sra       $zero, $zero, 1
/* 6CE7C0 8021A750 00000003 */  sra       $zero, $zero, 0
/* 6CE7C4 8021A754 8026B358 */  lb        $a2, -0x4ca8($at)
/* 6CE7C8 8021A758 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE7CC 8021A75C 00000000 */  nop       
/* 6CE7D0 8021A760 00000043 */  sra       $zero, $zero, 1
/* 6CE7D4 8021A764 00000003 */  sra       $zero, $zero, 0
/* 6CE7D8 8021A768 8027C4E0 */  lb        $a3, -0x3b20($at)
/* 6CE7DC 8021A76C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE7E0 8021A770 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE7E4 8021A774 00000014 */  dsllv     $zero, $zero, $zero
/* 6CE7E8 8021A778 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE7EC 8021A77C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE7F0 8021A780 0000001D */  dmultu    $zero, $zero
/* 6CE7F4 8021A784 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE7F8 8021A788 00000009 */  jr        $zero
/* 6CE7FC 8021A78C 0000001D */   dmultu   $zero, $zero
/* 6CE800 8021A790 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE804 8021A794 0000000A */  movz      $zero, $zero, $zero
.L8021A798:
/* 6CE808 8021A798 00000043 */  sra       $zero, $zero, 1
/* 6CE80C 8021A79C 00000004 */  sllv      $zero, $zero, $zero
/* 6CE810 8021A7A0 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CE814 8021A7A4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE818 8021A7A8 00000000 */  nop       
/* 6CE81C 8021A7AC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE820 8021A7B0 00000014 */  dsllv     $zero, $zero, $zero
/* 6CE824 8021A7B4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE828 8021A7B8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE82C 8021A7BC 0000001D */  dmultu    $zero, $zero
/* 6CE830 8021A7C0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE834 8021A7C4 00000000 */  nop       
/* 6CE838 8021A7C8 0000001D */  dmultu    $zero, $zero
/* 6CE83C 8021A7CC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE840 8021A7D0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE844 8021A7D4 00000025 */  or        $zero, $zero, $zero
/* 6CE848 8021A7D8 00000002 */  srl       $zero, $zero, 0
/* 6CE84C 8021A7DC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE850 8021A7E0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE854 8021A7E4 00000025 */  or        $zero, $zero, $zero
/* 6CE858 8021A7E8 00000002 */  srl       $zero, $zero, 0
/* 6CE85C 8021A7EC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CE860 8021A7F0 0059000B */  movn      $zero, $v0, $t9
/* 6CE864 8021A7F4 00000046 */  rotrv     $zero, $zero, $zero
/* 6CE868 8021A7F8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE86C 8021A7FC 80299044 */  lb        $t1, -0x6fbc($at)
/* 6CE870 8021A800 00000020 */  add       $zero, $zero, $zero
/* 6CE874 8021A804 00000000 */  nop       
/* 6CE878 8021A808 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CE87C 8021A80C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE880 8021A810 00000002 */  srl       $zero, $zero, 0
/* 6CE884 8021A814 00000025 */  or        $zero, $zero, $zero
/* 6CE888 8021A818 00000002 */  srl       $zero, $zero, 0
/* 6CE88C 8021A81C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE890 8021A820 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE894 8021A824 00000025 */  or        $zero, $zero, $zero
/* 6CE898 8021A828 00000002 */  srl       $zero, $zero, 0
/* 6CE89C 8021A82C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CE8A0 8021A830 00590006 */  srlv      $zero, $t9, $v0
/* 6CE8A4 8021A834 00000046 */  rotrv     $zero, $zero, $zero
/* 6CE8A8 8021A838 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE8AC 8021A83C 80299044 */  lb        $t1, -0x6fbc($at)
/* 6CE8B0 8021A840 00000023 */  negu      $zero, $zero
.L8021A844:
/* 6CE8B4 8021A844 00000000 */  nop       
/* 6CE8B8 8021A848 00000020 */  add       $zero, $zero, $zero
/* 6CE8BC 8021A84C 00000000 */  nop       
.L8021A850:
/* 6CE8C0 8021A850 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CE8C4 8021A854 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE8C8 8021A858 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6CE8CC 8021A85C 00000025 */  or        $zero, $zero, $zero
/* 6CE8D0 8021A860 00000002 */  srl       $zero, $zero, 0
/* 6CE8D4 8021A864 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE8D8 8021A868 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE8DC 8021A86C 00000025 */  or        $zero, $zero, $zero
/* 6CE8E0 8021A870 00000002 */  srl       $zero, $zero, 0
/* 6CE8E4 8021A874 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CE8E8 8021A878 0059000C */  syscall   0x16400
/* 6CE8EC 8021A87C 00000025 */  or        $zero, $zero, $zero
/* 6CE8F0 8021A880 00000002 */  srl       $zero, $zero, 0
/* 6CE8F4 8021A884 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CE8F8 8021A888 0059000D */  break     0x59
/* 6CE8FC 8021A88C 00000046 */   rotrv    $zero, $zero, $zero
/* 6CE900 8021A890 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE904 8021A894 8029A0D0 */  lb        $t1, -0x5f30($at)
/* 6CE908 8021A898 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CE90C 8021A89C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE910 8021A8A0 00000024 */  and       $zero, $zero, $zero
/* 6CE914 8021A8A4 00000025 */  or        $zero, $zero, $zero
/* 6CE918 8021A8A8 00000002 */  srl       $zero, $zero, 0
/* 6CE91C 8021A8AC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE920 8021A8B0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE924 8021A8B4 00000025 */  or        $zero, $zero, $zero
/* 6CE928 8021A8B8 00000002 */  srl       $zero, $zero, 0
/* 6CE92C 8021A8BC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CE930 8021A8C0 0059000C */  syscall   0x16400
/* 6CE934 8021A8C4 00000025 */  or        $zero, $zero, $zero
/* 6CE938 8021A8C8 00000002 */  srl       $zero, $zero, 0
/* 6CE93C 8021A8CC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CE940 8021A8D0 0059000D */  break     0x59
/* 6CE944 8021A8D4 00000046 */   rotrv    $zero, $zero, $zero
/* 6CE948 8021A8D8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE94C 8021A8DC 8029A0D0 */  lb        $t1, -0x5f30($at)
/* 6CE950 8021A8E0 00000025 */  or        $zero, $zero, $zero
/* 6CE954 8021A8E4 00000002 */  srl       $zero, $zero, 0
/* 6CE958 8021A8E8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE95C 8021A8EC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE960 8021A8F0 00000025 */  or        $zero, $zero, $zero
/* 6CE964 8021A8F4 00000002 */  srl       $zero, $zero, 0
/* 6CE968 8021A8F8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CE96C 8021A8FC 0059000D */  break     0x59
/* 6CE970 8021A900 00000046 */   rotrv    $zero, $zero, $zero
/* 6CE974 8021A904 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE978 8021A908 8029AEC0 */  lb        $t1, -0x5140($at)
/* 6CE97C 8021A90C 00000002 */  srl       $zero, $zero, 0
/* 6CE980 8021A910 00000000 */  nop       
/* 6CE984 8021A914 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CE988 8021A918 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE98C 8021A91C 0000000B */  movn      $zero, $zero, $zero
/* 6CE990 8021A920 00000043 */  sra       $zero, $zero, 1
/* 6CE994 8021A924 00000004 */  sllv      $zero, $zero, $zero
/* 6CE998 8021A928 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CE99C 8021A92C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CE9A0 8021A930 00000000 */  nop       
/* 6CE9A4 8021A934 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE9A8 8021A938 00000014 */  dsllv     $zero, $zero, $zero
/* 6CE9AC 8021A93C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE9B0 8021A940 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE9B4 8021A944 0000001D */  dmultu    $zero, $zero
/* 6CE9B8 8021A948 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE9BC 8021A94C 00000000 */  nop       
/* 6CE9C0 8021A950 0000001D */  dmultu    $zero, $zero
/* 6CE9C4 8021A954 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE9C8 8021A958 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE9CC 8021A95C 00000025 */  or        $zero, $zero, $zero
/* 6CE9D0 8021A960 00000002 */  srl       $zero, $zero, 0
/* 6CE9D4 8021A964 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CE9D8 8021A968 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE9DC 8021A96C 00000025 */  or        $zero, $zero, $zero
/* 6CE9E0 8021A970 00000002 */  srl       $zero, $zero, 0
/* 6CE9E4 8021A974 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CE9E8 8021A978 0059000B */  movn      $zero, $v0, $t9
/* 6CE9EC 8021A97C 00000046 */  rotrv     $zero, $zero, $zero
/* 6CE9F0 8021A980 00000001 */  movf      $zero, $zero, $fcc0
/* 6CE9F4 8021A984 8029B998 */  lb        $t1, -0x4668($at)
/* 6CE9F8 8021A988 00000020 */  add       $zero, $zero, $zero
.L8021A98C:
/* 6CE9FC 8021A98C 00000000 */  nop       
/* 6CEA00 8021A990 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CEA04 8021A994 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEA08 8021A998 00000002 */  srl       $zero, $zero, 0
/* 6CEA0C 8021A99C 00000025 */  or        $zero, $zero, $zero
/* 6CEA10 8021A9A0 00000002 */  srl       $zero, $zero, 0
/* 6CEA14 8021A9A4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CEA18 8021A9A8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEA1C 8021A9AC 00000025 */  or        $zero, $zero, $zero
/* 6CEA20 8021A9B0 00000002 */  srl       $zero, $zero, 0
/* 6CEA24 8021A9B4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CEA28 8021A9B8 00590006 */  srlv      $zero, $t9, $v0
/* 6CEA2C 8021A9BC 00000046 */  rotrv     $zero, $zero, $zero
/* 6CEA30 8021A9C0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEA34 8021A9C4 8029B998 */  lb        $t1, -0x4668($at)
/* 6CEA38 8021A9C8 00000023 */  negu      $zero, $zero
/* 6CEA3C 8021A9CC 00000000 */  nop       
/* 6CEA40 8021A9D0 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CEA44 8021A9D4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEA48 8021A9D8 00000021 */  addu      $zero, $zero, $zero
/* 6CEA4C 8021A9DC 00000043 */  sra       $zero, $zero, 1
/* 6CEA50 8021A9E0 00000004 */  sllv      $zero, $zero, $zero
/* 6CEA54 8021A9E4 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CEA58 8021A9E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEA5C 8021A9EC 00000000 */  nop       
/* 6CEA60 8021A9F0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CEA64 8021A9F4 00000014 */  dsllv     $zero, $zero, $zero
/* 6CEA68 8021A9F8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEA6C 8021A9FC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CEA70 8021AA00 0000001D */  dmultu    $zero, $zero
/* 6CEA74 8021AA04 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEA78 8021AA08 00000000 */  nop       
/* 6CEA7C 8021AA0C 0000001D */  dmultu    $zero, $zero
/* 6CEA80 8021AA10 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEA84 8021AA14 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEA88 8021AA18 00000025 */  or        $zero, $zero, $zero
/* 6CEA8C 8021AA1C 00000002 */  srl       $zero, $zero, 0
/* 6CEA90 8021AA20 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CEA94 8021AA24 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEA98 8021AA28 00000025 */  or        $zero, $zero, $zero
/* 6CEA9C 8021AA2C 00000002 */  srl       $zero, $zero, 0
/* 6CEAA0 8021AA30 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CEAA4 8021AA34 0059000B */  movn      $zero, $v0, $t9
/* 6CEAA8 8021AA38 00000046 */  rotrv     $zero, $zero, $zero
/* 6CEAAC 8021AA3C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEAB0 8021AA40 8029B998 */  lb        $t1, -0x4668($at)
/* 6CEAB4 8021AA44 00000025 */  or        $zero, $zero, $zero
/* 6CEAB8 8021AA48 00000002 */  srl       $zero, $zero, 0
/* 6CEABC 8021AA4C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CEAC0 8021AA50 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEAC4 8021AA54 00000025 */  or        $zero, $zero, $zero
/* 6CEAC8 8021AA58 00000002 */  srl       $zero, $zero, 0
/* 6CEACC 8021AA5C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CEAD0 8021AA60 0059000B */  movn      $zero, $v0, $t9
/* 6CEAD4 8021AA64 00000046 */  rotrv     $zero, $zero, $zero
/* 6CEAD8 8021AA68 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEADC 8021AA6C 8029AEC0 */  lb        $t1, -0x5140($at)
/* 6CEAE0 8021AA70 00000020 */  add       $zero, $zero, $zero
/* 6CEAE4 8021AA74 00000000 */  nop       
/* 6CEAE8 8021AA78 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CEAEC 8021AA7C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEAF0 8021AA80 00000002 */  srl       $zero, $zero, 0
/* 6CEAF4 8021AA84 00000025 */  or        $zero, $zero, $zero
/* 6CEAF8 8021AA88 00000002 */  srl       $zero, $zero, 0
/* 6CEAFC 8021AA8C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CEB00 8021AA90 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEB04 8021AA94 00000025 */  or        $zero, $zero, $zero
/* 6CEB08 8021AA98 00000002 */  srl       $zero, $zero, 0
/* 6CEB0C 8021AA9C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CEB10 8021AAA0 00590006 */  srlv      $zero, $t9, $v0
/* 6CEB14 8021AAA4 00000046 */  rotrv     $zero, $zero, $zero
/* 6CEB18 8021AAA8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEB1C 8021AAAC 8029B998 */  lb        $t1, -0x4668($at)
/* 6CEB20 8021AAB0 00000043 */  sra       $zero, $zero, 1
/* 6CEB24 8021AAB4 00000004 */  sllv      $zero, $zero, $zero
/* 6CEB28 8021AAB8 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6CEB2C 8021AABC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEB30 8021AAC0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEB34 8021AAC4 00590008 */  .byte     0x00, 0x59, 0x00, 0x08
/* 6CEB38 8021AAC8 00000008 */  jr        $zero
/* 6CEB3C 8021AACC 00000001 */   movf     $zero, $zero, $fcc0
/* 6CEB40 8021AAD0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CEB44 8021AAD4 00000025 */  or        $zero, $zero, $zero
/* 6CEB48 8021AAD8 00000002 */  srl       $zero, $zero, 0
/* 6CEB4C 8021AADC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CEB50 8021AAE0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEB54 8021AAE4 00000025 */  or        $zero, $zero, $zero
/* 6CEB58 8021AAE8 00000002 */  srl       $zero, $zero, 0
/* 6CEB5C 8021AAEC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CEB60 8021AAF0 0059000B */  movn      $zero, $v0, $t9
/* 6CEB64 8021AAF4 00000046 */  rotrv     $zero, $zero, $zero
/* 6CEB68 8021AAF8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEB6C 8021AAFC 8029AEC0 */  lb        $t1, -0x5140($at)
/* 6CEB70 8021AB00 00000023 */  negu      $zero, $zero
/* 6CEB74 8021AB04 00000000 */  nop       
/* 6CEB78 8021AB08 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CEB7C 8021AB0C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEB80 8021AB10 0000000D */  break     
/* 6CEB84 8021AB14 00000043 */   sra      $zero, $zero, 1
/* 6CEB88 8021AB18 00000004 */  sllv      $zero, $zero, $zero
/* 6CEB8C 8021AB1C 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6CEB90 8021AB20 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEB94 8021AB24 00000000 */  nop       
/* 6CEB98 8021AB28 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEB9C 8021AB2C 00000043 */  sra       $zero, $zero, 1
/* 6CEBA0 8021AB30 00000004 */  sllv      $zero, $zero, $zero
/* 6CEBA4 8021AB34 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6CEBA8 8021AB38 FFFFFF81 */  sd        $ra, -0x7f($ra)
.L8021AB3C:
/* 6CEBAC 8021AB3C 00000009 */  jr        $zero
/* 6CEBB0 8021AB40 00000001 */   movf     $zero, $zero, $fcc0
/* 6CEBB4 8021AB44 00000043 */  sra       $zero, $zero, 1
/* 6CEBB8 8021AB48 00000004 */  sllv      $zero, $zero, $zero
/* 6CEBBC 8021AB4C 8027CA74 */  lb        $a3, -0x358c($at)
/* 6CEBC0 8021AB50 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEBC4 8021AB54 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEBC8 8021AB58 80219D14 */  lb        $at, -0x62ec($at)
/* 6CEBCC 8021AB5C 00000043 */  sra       $zero, $zero, 1
/* 6CEBD0 8021AB60 00000004 */  sllv      $zero, $zero, $zero
/* 6CEBD4 8021AB64 8027CB7C */  lb        $a3, -0x3484($at)
/* 6CEBD8 8021AB68 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEBDC 8021AB6C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEBE0 8021AB70 80219C68 */  lb        $at, -0x6398($at)
/* 6CEBE4 8021AB74 00000043 */  sra       $zero, $zero, 1
/* 6CEBE8 8021AB78 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CEBEC 8021AB7C 8027D380 */  lb        $a3, -0x2c80($at)
.L8021AB80:
/* 6CEBF0 8021AB80 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEBF4 8021AB84 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEBF8 8021AB88 FFFFFFFB */  sd        $ra, -5($ra)
/* 6CEBFC 8021AB8C 0000000F */  sync      
/* 6CEC00 8021AB90 00000043 */  sra       $zero, $zero, 1
/* 6CEC04 8021AB94 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CEC08 8021AB98 8027D4C8 */  lb        $a3, -0x2b38($at)
/* 6CEC0C 8021AB9C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEC10 8021ABA0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEC14 8021ABA4 00000000 */  nop       
/* 6CEC18 8021ABA8 00000000 */  nop       
/* 6CEC1C 8021ABAC 00000043 */  sra       $zero, $zero, 1
/* 6CEC20 8021ABB0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CEC24 8021ABB4 8026D3C8 */  lb        $a2, -0x2c38($at)
/* 6CEC28 8021ABB8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEC2C 8021ABBC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEC30 8021ABC0 00000010 */  mfhi      $zero
.L8021ABC4:
/* 6CEC34 8021ABC4 00000000 */  nop       
/* 6CEC38 8021ABC8 00000043 */  sra       $zero, $zero, 1
/* 6CEC3C 8021ABCC 00000004 */  sllv      $zero, $zero, $zero
.L8021ABD0:
/* 6CEC40 8021ABD0 8026CE8C */  lb        $a2, -0x3174($at)
/* 6CEC44 8021ABD4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEC48 8021ABD8 00000400 */  sll       $zero, $zero, 0x10
/* 6CEC4C 8021ABDC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEC50 8021ABE0 00000043 */  sra       $zero, $zero, 1
/* 6CEC54 8021ABE4 00000004 */  sllv      $zero, $zero, $zero
/* 6CEC58 8021ABE8 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6CEC5C 8021ABEC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEC60 8021ABF0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEC64 8021ABF4 0059000B */  movn      $zero, $v0, $t9
/* 6CEC68 8021ABF8 00000043 */  sra       $zero, $zero, 1
/* 6CEC6C 8021ABFC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CEC70 8021AC00 8026C4AC */  lb        $a2, -0x3b54($at)
/* 6CEC74 8021AC04 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEC78 8021AC08 00000000 */  nop       
/* 6CEC7C 8021AC0C 0000000C */  syscall   
/* 6CEC80 8021AC10 00000000 */  nop       
/* 6CEC84 8021AC14 00000056 */  drotrv    $zero, $zero, $zero
/* 6CEC88 8021AC18 00000000 */  nop       
/* 6CEC8C 8021AC1C 00000008 */  jr        $zero
.L8021AC20:
/* 6CEC90 8021AC20 00000001 */   movf     $zero, $zero, $fcc0
/* 6CEC94 8021AC24 00000004 */  sllv      $zero, $zero, $zero
/* 6CEC98 8021AC28 00000043 */  sra       $zero, $zero, 1
/* 6CEC9C 8021AC2C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CECA0 8021AC30 8026C3AC */  lb        $a2, -0x3c54($at)
/* 6CECA4 8021AC34 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CECA8 8021AC38 00000000 */  nop       
/* 6CECAC 8021AC3C 00000000 */  nop       
/* 6CECB0 8021AC40 0000001E */  ddiv      $zero, $zero, $zero
/* 6CECB4 8021AC44 00000008 */  jr        $zero
/* 6CECB8 8021AC48 00000001 */   movf     $zero, $zero, $fcc0
/* 6CECBC 8021AC4C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CECC0 8021AC50 00000043 */  sra       $zero, $zero, 1
/* 6CECC4 8021AC54 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CECC8 8021AC58 8026C3AC */  lb        $a2, -0x3c54($at)
/* 6CECCC 8021AC5C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CECD0 8021AC60 00000000 */  nop       
/* 6CECD4 8021AC64 00000000 */  nop       
/* 6CECD8 8021AC68 00000000 */  nop       
/* 6CECDC 8021AC6C 00000008 */  jr        $zero
/* 6CECE0 8021AC70 00000001 */   movf     $zero, $zero, $fcc0
/* 6CECE4 8021AC74 00000001 */  movf      $zero, $zero, $fcc0
/* 6CECE8 8021AC78 00000043 */  sra       $zero, $zero, 1
/* 6CECEC 8021AC7C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CECF0 8021AC80 8026C3AC */  lb        $a2, -0x3c54($at)
/* 6CECF4 8021AC84 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CECF8 8021AC88 00000000 */  nop       
/* 6CECFC 8021AC8C 00000000 */  nop       
/* 6CED00 8021AC90 FFFFFFE2 */  sd        $ra, -0x1e($ra)
/* 6CED04 8021AC94 00000008 */  jr        $zero
/* 6CED08 8021AC98 00000001 */   movf     $zero, $zero, $fcc0
/* 6CED0C 8021AC9C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CED10 8021ACA0 00000043 */  sra       $zero, $zero, 1
/* 6CED14 8021ACA4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CED18 8021ACA8 8026C3AC */  lb        $a2, -0x3c54($at)
.L8021ACAC:
/* 6CED1C 8021ACAC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CED20 8021ACB0 00000000 */  nop       
/* 6CED24 8021ACB4 00000000 */  nop       
.L8021ACB8:
/* 6CED28 8021ACB8 FFFFFFC4 */  sd        $ra, -0x3c($ra)
/* 6CED2C 8021ACBC 00000008 */  jr        $zero
/* 6CED30 8021ACC0 00000001 */   movf     $zero, $zero, $fcc0
/* 6CED34 8021ACC4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CED38 8021ACC8 00000043 */  sra       $zero, $zero, 1
/* 6CED3C 8021ACCC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CED40 8021ACD0 8026C3AC */  lb        $a2, -0x3c54($at)
/* 6CED44 8021ACD4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CED48 8021ACD8 00000000 */  nop       
/* 6CED4C 8021ACDC 00000000 */  nop       
/* 6CED50 8021ACE0 FFFFFFB5 */  sd        $ra, -0x4b($ra)
/* 6CED54 8021ACE4 00000008 */  jr        $zero
/* 6CED58 8021ACE8 00000001 */   movf     $zero, $zero, $fcc0
/* 6CED5C 8021ACEC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CED60 8021ACF0 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6CED64 8021ACF4 00000000 */  nop       
/* 6CED68 8021ACF8 00000030 */  tge       $zero, $zero
/* 6CED6C 8021ACFC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CED70 8021AD00 8021A6CC */  lb        $at, -0x5934($at)
/* 6CED74 8021AD04 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CED78 8021AD08 00000001 */  movf      $zero, $zero, $fcc0
/* 6CED7C 8021AD0C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CED80 8021AD10 00000031 */  tgeu      $zero, $zero
/* 6CED84 8021AD14 00000001 */  movf      $zero, $zero, $fcc0
/* 6CED88 8021AD18 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CED8C 8021AD1C 00000043 */  sra       $zero, $zero, 1
/* 6CED90 8021AD20 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CED94 8021AD24 8026BA04 */  lb        $a2, -0x45fc($at)
/* 6CED98 8021AD28 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CED9C 8021AD2C 00000000 */  nop       
/* 6CEDA0 8021AD30 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CEDA4 8021AD34 00000000 */  nop       
/* 6CEDA8 8021AD38 00000008 */  jr        $zero
/* 6CEDAC 8021AD3C 00000001 */   movf     $zero, $zero, $fcc0
/* 6CEDB0 8021AD40 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEDB4 8021AD44 00000006 */  srlv      $zero, $zero, $zero
/* 6CEDB8 8021AD48 00000000 */  nop       
/* 6CEDBC 8021AD4C 00000043 */  sra       $zero, $zero, 1
/* 6CEDC0 8021AD50 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CEDC4 8021AD54 8026C4AC */  lb        $a2, -0x3b54($at)
/* 6CEDC8 8021AD58 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEDCC 8021AD5C 00000000 */  nop       
/* 6CEDD0 8021AD60 00000000 */  nop       
/* 6CEDD4 8021AD64 00000000 */  nop       
/* 6CEDD8 8021AD68 00000043 */  sra       $zero, $zero, 1
/* 6CEDDC 8021AD6C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CEDE0 8021AD70 8026C3AC */  lb        $a2, -0x3c54($at)
/* 6CEDE4 8021AD74 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEDE8 8021AD78 00000000 */  nop       
/* 6CEDEC 8021AD7C 00000000 */  nop       
/* 6CEDF0 8021AD80 00000000 */  nop       
/* 6CEDF4 8021AD84 00000043 */  sra       $zero, $zero, 1
/* 6CEDF8 8021AD88 00000004 */  sllv      $zero, $zero, $zero
/* 6CEDFC 8021AD8C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6CEE00 8021AD90 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEE04 8021AD94 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEE08 8021AD98 0059000F */  sync      
/* 6CEE0C 8021AD9C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CEE10 8021ADA0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEE14 8021ADA4 0000002F */  dsubu     $zero, $zero, $zero
/* 6CEE18 8021ADA8 00000025 */  or        $zero, $zero, $zero
/* 6CEE1C 8021ADAC 00000002 */  srl       $zero, $zero, 0
/* 6CEE20 8021ADB0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CEE24 8021ADB4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEE28 8021ADB8 00000025 */  or        $zero, $zero, $zero
/* 6CEE2C 8021ADBC 00000002 */  srl       $zero, $zero, 0
/* 6CEE30 8021ADC0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CEE34 8021ADC4 0059000B */  movn      $zero, $v0, $t9
/* 6CEE38 8021ADC8 00000046 */  rotrv     $zero, $zero, $zero
/* 6CEE3C 8021ADCC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEE40 8021ADD0 8029A6FC */  lb        $t1, -0x5904($at)
/* 6CEE44 8021ADD4 00000025 */  or        $zero, $zero, $zero
/* 6CEE48 8021ADD8 00000002 */  srl       $zero, $zero, 0
/* 6CEE4C 8021ADDC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CEE50 8021ADE0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEE54 8021ADE4 00000025 */  or        $zero, $zero, $zero
/* 6CEE58 8021ADE8 00000002 */  srl       $zero, $zero, 0
/* 6CEE5C 8021ADEC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CEE60 8021ADF0 0059000B */  movn      $zero, $v0, $t9
.L8021ADF4:
/* 6CEE64 8021ADF4 00000046 */  rotrv     $zero, $zero, $zero
/* 6CEE68 8021ADF8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEE6C 8021ADFC 8029BD70 */  lb        $t1, -0x4290($at)
/* 6CEE70 8021AE00 00000043 */  sra       $zero, $zero, 1
/* 6CEE74 8021AE04 00000006 */  srlv      $zero, $zero, $zero
/* 6CEE78 8021AE08 80278D08 */  lb        $a3, -0x72f8($at)
/* 6CEE7C 8021AE0C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEE80 8021AE10 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CEE84 8021AE14 00000000 */  nop       
/* 6CEE88 8021AE18 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEE8C 8021AE1C 00000000 */  nop       
/* 6CEE90 8021AE20 00000025 */  or        $zero, $zero, $zero
/* 6CEE94 8021AE24 00000002 */  srl       $zero, $zero, 0
/* 6CEE98 8021AE28 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CEE9C 8021AE2C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEEA0 8021AE30 00000025 */  or        $zero, $zero, $zero
/* 6CEEA4 8021AE34 00000002 */  srl       $zero, $zero, 0
/* 6CEEA8 8021AE38 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CEEAC 8021AE3C 00590004 */  sllv      $zero, $t9, $v0
/* 6CEEB0 8021AE40 00000046 */  rotrv     $zero, $zero, $zero
/* 6CEEB4 8021AE44 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEEB8 8021AE48 8029BEB8 */  lb        $t1, -0x4148($at)
/* 6CEEBC 8021AE4C 00000043 */  sra       $zero, $zero, 1
/* 6CEEC0 8021AE50 00000003 */  sra       $zero, $zero, 0
/* 6CEEC4 8021AE54 8026B55C */  lb        $a2, -0x4aa4($at)
/* 6CEEC8 8021AE58 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEECC 8021AE5C F24A80E7 */  scd       $t2, -0x7f19($s2)
/* 6CEED0 8021AE60 00000043 */  sra       $zero, $zero, 1
/* 6CEED4 8021AE64 00000006 */  srlv      $zero, $zero, $zero
/* 6CEED8 8021AE68 80278D08 */  lb        $a3, -0x72f8($at)
/* 6CEEDC 8021AE6C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEEE0 8021AE70 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CEEE4 8021AE74 00000000 */  nop       
/* 6CEEE8 8021AE78 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEEEC 8021AE7C 00000000 */  nop       
/* 6CEEF0 8021AE80 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CEEF4 8021AE84 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEEF8 8021AE88 00000026 */  xor       $zero, $zero, $zero
/* 6CEEFC 8021AE8C 00000025 */  or        $zero, $zero, $zero
/* 6CEF00 8021AE90 00000002 */  srl       $zero, $zero, 0
/* 6CEF04 8021AE94 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CEF08 8021AE98 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEF0C 8021AE9C 00000025 */  or        $zero, $zero, $zero
/* 6CEF10 8021AEA0 00000002 */  srl       $zero, $zero, 0
/* 6CEF14 8021AEA4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CEF18 8021AEA8 0059000B */  movn      $zero, $v0, $t9
/* 6CEF1C 8021AEAC 00000046 */  rotrv     $zero, $zero, $zero
/* 6CEF20 8021AEB0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEF24 8021AEB4 8029A6FC */  lb        $t1, -0x5904($at)
/* 6CEF28 8021AEB8 00000025 */  or        $zero, $zero, $zero
/* 6CEF2C 8021AEBC 00000002 */  srl       $zero, $zero, 0
/* 6CEF30 8021AEC0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CEF34 8021AEC4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEF38 8021AEC8 00000025 */  or        $zero, $zero, $zero
/* 6CEF3C 8021AECC 00000002 */  srl       $zero, $zero, 0
/* 6CEF40 8021AED0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CEF44 8021AED4 0059000B */  movn      $zero, $v0, $t9
/* 6CEF48 8021AED8 00000046 */  rotrv     $zero, $zero, $zero
/* 6CEF4C 8021AEDC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEF50 8021AEE0 8029AEC0 */  lb        $t1, -0x5140($at)
/* 6CEF54 8021AEE4 00000002 */  srl       $zero, $zero, 0
/* 6CEF58 8021AEE8 00000000 */  nop       
/* 6CEF5C 8021AEEC 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CEF60 8021AEF0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEF64 8021AEF4 00000013 */  mtlo      $zero
/* 6CEF68 8021AEF8 00000043 */  sra       $zero, $zero, 1
/* 6CEF6C 8021AEFC 00000004 */  sllv      $zero, $zero, $zero
/* 6CEF70 8021AF00 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CEF74 8021AF04 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEF78 8021AF08 00000000 */  nop       
/* 6CEF7C 8021AF0C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CEF80 8021AF10 0000000A */  movz      $zero, $zero, $zero
/* 6CEF84 8021AF14 00000002 */  srl       $zero, $zero, 0
/* 6CEF88 8021AF18 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CEF8C 8021AF1C 00000002 */  srl       $zero, $zero, 0
/* 6CEF90 8021AF20 00000043 */  sra       $zero, $zero, 1
/* 6CEF94 8021AF24 00000003 */  sra       $zero, $zero, 0
/* 6CEF98 8021AF28 8027CB08 */  lb        $a3, -0x34f8($at)
/* 6CEF9C 8021AF2C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEFA0 8021AF30 80219D34 */  lb        $at, -0x62cc($at)
/* 6CEFA4 8021AF34 00000043 */  sra       $zero, $zero, 1
/* 6CEFA8 8021AF38 00000004 */  sllv      $zero, $zero, $zero
.L8021AF3C:
/* 6CEFAC 8021AF3C 8027CA74 */  lb        $a3, -0x358c($at)
/* 6CEFB0 8021AF40 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEFB4 8021AF44 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEFB8 8021AF48 80219D00 */  lb        $at, -0x6300($at)
/* 6CEFBC 8021AF4C 00000043 */  sra       $zero, $zero, 1
/* 6CEFC0 8021AF50 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CEFC4 8021AF54 8026D3C8 */  lb        $a2, -0x2c38($at)
/* 6CEFC8 8021AF58 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEFCC 8021AF5C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEFD0 8021AF60 00001000 */  sll       $v0, $zero, 0
/* 6CEFD4 8021AF64 00000001 */  movf      $zero, $zero, $fcc0
/* 6CEFD8 8021AF68 00000043 */  sra       $zero, $zero, 1
/* 6CEFDC 8021AF6C 00000004 */  sllv      $zero, $zero, $zero
/* 6CEFE0 8021AF70 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6CEFE4 8021AF74 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CEFE8 8021AF78 00000000 */  nop       
/* 6CEFEC 8021AF7C 00000000 */  nop       
/* 6CEFF0 8021AF80 00000043 */  sra       $zero, $zero, 1
/* 6CEFF4 8021AF84 00000004 */  sllv      $zero, $zero, $zero
/* 6CEFF8 8021AF88 8027CB7C */  lb        $a3, -0x3484($at)
/* 6CEFFC 8021AF8C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF000 8021AF90 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF004 8021AF94 80219BD0 */  lb        $at, -0x6430($at)
/* 6CF008 8021AF98 00000043 */  sra       $zero, $zero, 1
/* 6CF00C 8021AF9C 00000003 */  sra       $zero, $zero, 0
/* 6CF010 8021AFA0 8026F230 */  lb        $a2, -0xdd0($at)
/* 6CF014 8021AFA4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF018 8021AFA8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6CF01C 8021AFAC 00000011 */  mthi      $zero
/* 6CF020 8021AFB0 00000002 */  srl       $zero, $zero, 0
/* 6CF024 8021AFB4 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6CF028 8021AFB8 18000000 */  blez      $zero, .L8021AFBC
.L8021AFBC:
/* 6CF02C 8021AFBC 00000043 */   sra      $zero, $zero, 1
/* 6CF030 8021AFC0 00000003 */  sra       $zero, $zero, 0
/* 6CF034 8021AFC4 8027DBA4 */  lb        $a3, -0x245c($at)
/* 6CF038 8021AFC8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF03C 8021AFCC 00000000 */  nop       
/* 6CF040 8021AFD0 00000013 */  mtlo      $zero
/* 6CF044 8021AFD4 00000000 */  nop       
/* 6CF048 8021AFD8 00000043 */  sra       $zero, $zero, 1
/* 6CF04C 8021AFDC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CF050 8021AFE0 8026D3C8 */  lb        $a2, -0x2c38($at)
/* 6CF054 8021AFE4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF058 8021AFE8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF05C 8021AFEC 00400000 */  .byte     0x00, 0x40, 0x00, 0x00
/* 6CF060 8021AFF0 00000000 */  nop       
/* 6CF064 8021AFF4 00000025 */  or        $zero, $zero, $zero
/* 6CF068 8021AFF8 00000002 */  srl       $zero, $zero, 0
/* 6CF06C 8021AFFC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF070 8021B000 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF074 8021B004 00000025 */  or        $zero, $zero, $zero
/* 6CF078 8021B008 00000002 */  srl       $zero, $zero, 0
/* 6CF07C 8021B00C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF080 8021B010 00590008 */  .byte     0x00, 0x59, 0x00, 0x08
/* 6CF084 8021B014 00000046 */  rotrv     $zero, $zero, $zero
/* 6CF088 8021B018 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF08C 8021B01C 8029AC70 */  lb        $t1, -0x5390($at)
/* 6CF090 8021B020 00000013 */  mtlo      $zero
.L8021B024:
/* 6CF094 8021B024 00000000 */  nop       
/* 6CF098 8021B028 0000001D */  dmultu    $zero, $zero
/* 6CF09C 8021B02C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF0A0 8021B030 00000017 */  dsrav     $zero, $zero, $zero
/* 6CF0A4 8021B034 0000001D */  dmultu    $zero, $zero
/* 6CF0A8 8021B038 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF0AC 8021B03C 00000019 */  multu     $zero, $zero
/* 6CF0B0 8021B040 00000043 */  sra       $zero, $zero, 1
/* 6CF0B4 8021B044 00000004 */  sllv      $zero, $zero, $zero
/* 6CF0B8 8021B048 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CF0BC 8021B04C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF0C0 8021B050 00000000 */  nop       
/* 6CF0C4 8021B054 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF0C8 8021B058 00000014 */  dsllv     $zero, $zero, $zero
/* 6CF0CC 8021B05C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF0D0 8021B060 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF0D4 8021B064 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF0D8 8021B068 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF0DC 8021B06C 00000000 */  nop       
/* 6CF0E0 8021B070 00000025 */  or        $zero, $zero, $zero
/* 6CF0E4 8021B074 00000002 */  srl       $zero, $zero, 0
/* 6CF0E8 8021B078 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF0EC 8021B07C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF0F0 8021B080 00000025 */  or        $zero, $zero, $zero
/* 6CF0F4 8021B084 00000002 */  srl       $zero, $zero, 0
/* 6CF0F8 8021B088 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF0FC 8021B08C 00590007 */  srav      $zero, $t9, $v0
/* 6CF100 8021B090 00000046 */  rotrv     $zero, $zero, $zero
/* 6CF104 8021B094 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF108 8021B098 8029AC70 */  lb        $t1, -0x5390($at)
/* 6CF10C 8021B09C 00000043 */  sra       $zero, $zero, 1
/* 6CF110 8021B0A0 00000003 */  sra       $zero, $zero, 0
/* 6CF114 8021B0A4 8026F230 */  lb        $a2, -0xdd0($at)
/* 6CF118 8021B0A8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF11C 8021B0AC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF120 8021B0B0 00000011 */  mthi      $zero
/* 6CF124 8021B0B4 00000002 */  srl       $zero, $zero, 0
/* 6CF128 8021B0B8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF12C 8021B0BC 0035D000 */  .byte     0x00, 0x35, 0xd0, 0x00
/* 6CF130 8021B0C0 00000043 */  sra       $zero, $zero, 1
/* 6CF134 8021B0C4 00000004 */  sllv      $zero, $zero, $zero
/* 6CF138 8021B0C8 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6CF13C 8021B0CC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF140 8021B0D0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF144 8021B0D4 00590008 */  .byte     0x00, 0x59, 0x00, 0x08
/* 6CF148 8021B0D8 00000008 */  jr        $zero
/* 6CF14C 8021B0DC 00000001 */   movf     $zero, $zero, $fcc0
/* 6CF150 8021B0E0 0000000A */  movz      $zero, $zero, $zero
/* 6CF154 8021B0E4 00000013 */  mtlo      $zero
/* 6CF158 8021B0E8 00000000 */  nop       
/* 6CF15C 8021B0EC 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF160 8021B0F0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF164 8021B0F4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF168 8021B0F8 00000025 */  or        $zero, $zero, $zero
/* 6CF16C 8021B0FC 00000002 */  srl       $zero, $zero, 0
/* 6CF170 8021B100 FE363C80 */  sd        $s6, 0x3c80($s1)
.L8021B104:
/* 6CF174 8021B104 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF178 8021B108 00000025 */  or        $zero, $zero, $zero
/* 6CF17C 8021B10C 00000002 */  srl       $zero, $zero, 0
/* 6CF180 8021B110 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF184 8021B114 0059000F */  sync      
/* 6CF188 8021B118 00000046 */  rotrv     $zero, $zero, $zero
/* 6CF18C 8021B11C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF190 8021B120 8029AC70 */  lb        $t1, -0x5390($at)
.L8021B124:
/* 6CF194 8021B124 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF198 8021B128 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF19C 8021B12C 00000002 */  srl       $zero, $zero, 0
/* 6CF1A0 8021B130 00000025 */  or        $zero, $zero, $zero
/* 6CF1A4 8021B134 00000002 */  srl       $zero, $zero, 0
/* 6CF1A8 8021B138 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF1AC 8021B13C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF1B0 8021B140 00000025 */  or        $zero, $zero, $zero
.L8021B144:
/* 6CF1B4 8021B144 00000002 */  srl       $zero, $zero, 0
/* 6CF1B8 8021B148 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF1BC 8021B14C 00590006 */  srlv      $zero, $t9, $v0
/* 6CF1C0 8021B150 00000046 */  rotrv     $zero, $zero, $zero
/* 6CF1C4 8021B154 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF1C8 8021B158 8029AC70 */  lb        $t1, -0x5390($at)
/* 6CF1CC 8021B15C 00000023 */  negu      $zero, $zero
/* 6CF1D0 8021B160 00000000 */  nop       
.L8021B164:
/* 6CF1D4 8021B164 00000020 */  add       $zero, $zero, $zero
/* 6CF1D8 8021B168 00000000 */  nop       
/* 6CF1DC 8021B16C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF1E0 8021B170 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF1E4 8021B174 0000001B */  divu      $zero, $zero, $zero
/* 6CF1E8 8021B178 00000008 */  jr        $zero
/* 6CF1EC 8021B17C 00000001 */   movf     $zero, $zero, $fcc0
/* 6CF1F0 8021B180 0000000A */  movz      $zero, $zero, $zero
/* 6CF1F4 8021B184 00000024 */  and       $zero, $zero, $zero
/* 6CF1F8 8021B188 00000002 */  srl       $zero, $zero, 0
/* 6CF1FC 8021B18C FBD3E280 */  bbit132   $fp, 0x13, .L80213B90
/* 6CF200 8021B190 00000000 */   nop      
/* 6CF204 8021B194 00000043 */  sra       $zero, $zero, 1
/* 6CF208 8021B198 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CF20C 8021B19C 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6CF210 8021B1A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF214 8021B1A4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF218 8021B1A8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF21C 8021B1AC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CF220 8021B1B0 00000043 */  sra       $zero, $zero, 1
/* 6CF224 8021B1B4 00000003 */  sra       $zero, $zero, 0
/* 6CF228 8021B1B8 8026F230 */  lb        $a2, -0xdd0($at)
/* 6CF22C 8021B1BC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF230 8021B1C0 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6CF234 8021B1C4 00000010 */  mfhi      $zero
/* 6CF238 8021B1C8 00000002 */  srl       $zero, $zero, 0
/* 6CF23C 8021B1CC FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6CF240 8021B1D0 00080000 */  sll       $zero, $t0, 0
/* 6CF244 8021B1D4 00000027 */  not       $zero, $zero
/* 6CF248 8021B1D8 00000002 */  srl       $zero, $zero, 0
/* 6CF24C 8021B1DC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF250 8021B1E0 00000010 */  mfhi      $zero
/* 6CF254 8021B1E4 00000024 */  and       $zero, $zero, $zero
/* 6CF258 8021B1E8 00000002 */  srl       $zero, $zero, 0
/* 6CF25C 8021B1EC FBD3E280 */  bbit132   $fp, 0x13, .L80213BF0
/* 6CF260 8021B1F0 00000001 */   movf     $zero, $zero, $fcc0
/* 6CF264 8021B1F4 00000013 */  mtlo      $zero
.L8021B1F8:
/* 6CF268 8021B1F8 00000000 */  nop       
/* 6CF26C 8021B1FC 00000010 */  mfhi      $zero
/* 6CF270 8021B200 00000002 */  srl       $zero, $zero, 0
/* 6CF274 8021B204 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6CF278 8021B208 00040000 */  sll       $zero, $a0, 0
/* 6CF27C 8021B20C 00000027 */  not       $zero, $zero
/* 6CF280 8021B210 00000002 */  srl       $zero, $zero, 0
/* 6CF284 8021B214 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF288 8021B218 FFFFFFF2 */  sd        $ra, -0xe($ra)
/* 6CF28C 8021B21C 00000027 */  not       $zero, $zero
/* 6CF290 8021B220 00000002 */  srl       $zero, $zero, 0
/* 6CF294 8021B224 FE363C81 */  sd        $s6, 0x3c81($s1)
.L8021B228:
/* 6CF298 8021B228 00000014 */  dsllv     $zero, $zero, $zero
/* 6CF29C 8021B22C 00000024 */  and       $zero, $zero, $zero
/* 6CF2A0 8021B230 00000002 */  srl       $zero, $zero, 0
/* 6CF2A4 8021B234 FBD3E280 */  bbit132   $fp, 0x13, .L80213C38
/* 6CF2A8 8021B238 00000001 */   movf     $zero, $zero, $fcc0
/* 6CF2AC 8021B23C 00000013 */  mtlo      $zero
/* 6CF2B0 8021B240 00000000 */  nop       
/* 6CF2B4 8021B244 00000010 */  mfhi      $zero
/* 6CF2B8 8021B248 00000002 */  srl       $zero, $zero, 0
/* 6CF2BC 8021B24C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6CF2C0 8021B250 00001000 */  sll       $v0, $zero, 0
/* 6CF2C4 8021B254 00000027 */  not       $zero, $zero
.L8021B258:
/* 6CF2C8 8021B258 00000002 */  srl       $zero, $zero, 0
/* 6CF2CC 8021B25C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF2D0 8021B260 FFFFFFF2 */  sd        $ra, -0xe($ra)
/* 6CF2D4 8021B264 00000027 */  not       $zero, $zero
/* 6CF2D8 8021B268 00000002 */  srl       $zero, $zero, 0
/* 6CF2DC 8021B26C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF2E0 8021B270 00000014 */  dsllv     $zero, $zero, $zero
/* 6CF2E4 8021B274 00000024 */  and       $zero, $zero, $zero
/* 6CF2E8 8021B278 00000002 */  srl       $zero, $zero, 0
/* 6CF2EC 8021B27C FBD3E280 */  bbit132   $fp, 0x13, .L80213C80
/* 6CF2F0 8021B280 00000001 */   movf     $zero, $zero, $fcc0
/* 6CF2F4 8021B284 00000013 */  mtlo      $zero
.L8021B288:
/* 6CF2F8 8021B288 00000000 */  nop       
/* 6CF2FC 8021B28C 00000043 */  sra       $zero, $zero, 1
/* 6CF300 8021B290 00000004 */  sllv      $zero, $zero, $zero
/* 6CF304 8021B294 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CF308 8021B298 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF30C 8021B29C 00000000 */  nop       
/* 6CF310 8021B2A0 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6CF314 8021B2A4 0000000A */  movz      $zero, $zero, $zero
/* 6CF318 8021B2A8 00000002 */  srl       $zero, $zero, 0
/* 6CF31C 8021B2AC FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6CF320 8021B2B0 00000002 */  srl       $zero, $zero, 0
/* 6CF324 8021B2B4 00000027 */  not       $zero, $zero
.L8021B2B8:
/* 6CF328 8021B2B8 00000002 */  srl       $zero, $zero, 0
/* 6CF32C 8021B2BC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF330 8021B2C0 00000017 */  dsrav     $zero, $zero, $zero
/* 6CF334 8021B2C4 00000024 */  and       $zero, $zero, $zero
/* 6CF338 8021B2C8 00000002 */  srl       $zero, $zero, 0
/* 6CF33C 8021B2CC FBD3E280 */  bbit132   $fp, 0x13, .L80213CD0
/* 6CF340 8021B2D0 00000001 */   movf     $zero, $zero, $fcc0
/* 6CF344 8021B2D4 00000013 */  mtlo      $zero
/* 6CF348 8021B2D8 00000000 */  nop       
/* 6CF34C 8021B2DC 0000000A */  movz      $zero, $zero, $zero
/* 6CF350 8021B2E0 00000002 */  srl       $zero, $zero, 0
/* 6CF354 8021B2E4 FBD3E280 */  bbit132   $fp, 0x13, .L80213CE8
.L8021B2E8:
/* 6CF358 8021B2E8 00000000 */   nop      
/* 6CF35C 8021B2EC 00000027 */  not       $zero, $zero
/* 6CF360 8021B2F0 00000002 */  srl       $zero, $zero, 0
/* 6CF364 8021B2F4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF368 8021B2F8 0000002A */  slt       $zero, $zero, $zero
/* 6CF36C 8021B2FC 00000013 */  mtlo      $zero
/* 6CF370 8021B300 00000000 */  nop       
/* 6CF374 8021B304 00000043 */  sra       $zero, $zero, 1
/* 6CF378 8021B308 0000000F */  sync      
/* 6CF37C 8021B30C 802D829C */  lb        $t5, -0x7d64($at)
/* 6CF380 8021B310 0000001A */  div       $zero, $zero, $zero
/* 6CF384 8021B314 00000000 */  nop       
/* 6CF388 8021B318 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF38C 8021B31C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF390 8021B320 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CF394 8021B324 00000014 */  dsllv     $zero, $zero, $zero
/* 6CF398 8021B328 00000000 */  nop       
/* 6CF39C 8021B32C 00000000 */  nop       
/* 6CF3A0 8021B330 00000000 */  nop       
/* 6CF3A4 8021B334 00000000 */  nop       
/* 6CF3A8 8021B338 00000000 */  nop       
/* 6CF3AC 8021B33C 00000000 */  nop       
/* 6CF3B0 8021B340 00000000 */  nop       
/* 6CF3B4 8021B344 00000000 */  nop       
/* 6CF3B8 8021B348 00000008 */  jr        $zero
/* 6CF3BC 8021B34C 00000001 */   movf     $zero, $zero, $fcc0
/* 6CF3C0 8021B350 00000014 */  dsllv     $zero, $zero, $zero
/* 6CF3C4 8021B354 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF3C8 8021B358 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF3CC 8021B35C 00000020 */  add       $zero, $zero, $zero
/* 6CF3D0 8021B360 00000043 */  sra       $zero, $zero, 1
/* 6CF3D4 8021B364 00000004 */  sllv      $zero, $zero, $zero
/* 6CF3D8 8021B368 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CF3DC 8021B36C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF3E0 8021B370 00000000 */  nop       
/* 6CF3E4 8021B374 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF3E8 8021B378 00000014 */  dsllv     $zero, $zero, $zero
/* 6CF3EC 8021B37C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF3F0 8021B380 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF3F4 8021B384 0000001D */  dmultu    $zero, $zero
/* 6CF3F8 8021B388 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF3FC 8021B38C 00000000 */  nop       
/* 6CF400 8021B390 0000001D */  dmultu    $zero, $zero
/* 6CF404 8021B394 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF408 8021B398 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF40C 8021B39C 00000025 */  or        $zero, $zero, $zero
/* 6CF410 8021B3A0 00000002 */  srl       $zero, $zero, 0
/* 6CF414 8021B3A4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF418 8021B3A8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF41C 8021B3AC 00000025 */  or        $zero, $zero, $zero
/* 6CF420 8021B3B0 00000002 */  srl       $zero, $zero, 0
/* 6CF424 8021B3B4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF428 8021B3B8 0059000B */  movn      $zero, $v0, $t9
/* 6CF42C 8021B3BC 00000046 */  rotrv     $zero, $zero, $zero
/* 6CF430 8021B3C0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF434 8021B3C4 80299044 */  lb        $t1, -0x6fbc($at)
/* 6CF438 8021B3C8 00000008 */  jr        $zero
/* 6CF43C 8021B3CC 00000001 */   movf     $zero, $zero, $fcc0
/* 6CF440 8021B3D0 0000000A */  movz      $zero, $zero, $zero
/* 6CF444 8021B3D4 00000025 */  or        $zero, $zero, $zero
/* 6CF448 8021B3D8 00000002 */  srl       $zero, $zero, 0
/* 6CF44C 8021B3DC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF450 8021B3E0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF454 8021B3E4 00000025 */  or        $zero, $zero, $zero
/* 6CF458 8021B3E8 00000002 */  srl       $zero, $zero, 0
/* 6CF45C 8021B3EC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF460 8021B3F0 0059000B */  movn      $zero, $v0, $t9
/* 6CF464 8021B3F4 00000046 */  rotrv     $zero, $zero, $zero
/* 6CF468 8021B3F8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF46C 8021B3FC 8029AEC0 */  lb        $t1, -0x5140($at)
/* 6CF470 8021B400 00000002 */  srl       $zero, $zero, 0
/* 6CF474 8021B404 00000000 */  nop       
/* 6CF478 8021B408 00000020 */  add       $zero, $zero, $zero
/* 6CF47C 8021B40C 00000000 */  nop       
/* 6CF480 8021B410 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF484 8021B414 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF488 8021B418 00000002 */  srl       $zero, $zero, 0
/* 6CF48C 8021B41C 00000025 */  or        $zero, $zero, $zero
/* 6CF490 8021B420 00000002 */  srl       $zero, $zero, 0
/* 6CF494 8021B424 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF498 8021B428 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF49C 8021B42C 00000025 */  or        $zero, $zero, $zero
/* 6CF4A0 8021B430 00000002 */  srl       $zero, $zero, 0
/* 6CF4A4 8021B434 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF4A8 8021B438 00590006 */  srlv      $zero, $t9, $v0
/* 6CF4AC 8021B43C 00000046 */  rotrv     $zero, $zero, $zero
/* 6CF4B0 8021B440 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF4B4 8021B444 80299044 */  lb        $t1, -0x6fbc($at)
/* 6CF4B8 8021B448 00000043 */  sra       $zero, $zero, 1
/* 6CF4BC 8021B44C 00000004 */  sllv      $zero, $zero, $zero
/* 6CF4C0 8021B450 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6CF4C4 8021B454 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF4C8 8021B458 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF4CC 8021B45C 00590008 */  .byte     0x00, 0x59, 0x00, 0x08
/* 6CF4D0 8021B460 00000008 */  jr        $zero
/* 6CF4D4 8021B464 00000001 */   movf     $zero, $zero, $fcc0
/* 6CF4D8 8021B468 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CF4DC 8021B46C 00000025 */  or        $zero, $zero, $zero
/* 6CF4E0 8021B470 00000002 */  srl       $zero, $zero, 0
/* 6CF4E4 8021B474 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF4E8 8021B478 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF4EC 8021B47C 00000025 */  or        $zero, $zero, $zero
/* 6CF4F0 8021B480 00000002 */  srl       $zero, $zero, 0
/* 6CF4F4 8021B484 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF4F8 8021B488 0059000B */  movn      $zero, $v0, $t9
/* 6CF4FC 8021B48C 00000046 */  rotrv     $zero, $zero, $zero
/* 6CF500 8021B490 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF504 8021B494 8029AEC0 */  lb        $t1, -0x5140($at)
/* 6CF508 8021B498 00000002 */  srl       $zero, $zero, 0
/* 6CF50C 8021B49C 00000000 */  nop       
/* 6CF510 8021B4A0 00000023 */  negu      $zero, $zero
/* 6CF514 8021B4A4 00000000 */  nop       
/* 6CF518 8021B4A8 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF51C 8021B4AC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF520 8021B4B0 00000031 */  tgeu      $zero, $zero
/* 6CF524 8021B4B4 00000043 */  sra       $zero, $zero, 1
/* 6CF528 8021B4B8 00000004 */  sllv      $zero, $zero, $zero
/* 6CF52C 8021B4BC 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CF530 8021B4C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF534 8021B4C4 00000000 */  nop       
/* 6CF538 8021B4C8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF53C 8021B4CC 00000014 */  dsllv     $zero, $zero, $zero
/* 6CF540 8021B4D0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF544 8021B4D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF548 8021B4D8 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF54C 8021B4DC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF550 8021B4E0 00000000 */  nop       
/* 6CF554 8021B4E4 00000025 */  or        $zero, $zero, $zero
/* 6CF558 8021B4E8 00000002 */  srl       $zero, $zero, 0
/* 6CF55C 8021B4EC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF560 8021B4F0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF564 8021B4F4 00000025 */  or        $zero, $zero, $zero
/* 6CF568 8021B4F8 00000002 */  srl       $zero, $zero, 0
/* 6CF56C 8021B4FC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF570 8021B500 00590001 */  movt      $zero, $v0, $fcc6
/* 6CF574 8021B504 00000046 */  rotrv     $zero, $zero, $zero
/* 6CF578 8021B508 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF57C 8021B50C 8029BFA0 */  lb        $t1, -0x4060($at)
/* 6CF580 8021B510 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF584 8021B514 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF588 8021B518 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF58C 8021B51C 00000025 */  or        $zero, $zero, $zero
/* 6CF590 8021B520 00000002 */  srl       $zero, $zero, 0
/* 6CF594 8021B524 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF598 8021B528 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF59C 8021B52C 00000025 */  or        $zero, $zero, $zero
/* 6CF5A0 8021B530 00000002 */  srl       $zero, $zero, 0
/* 6CF5A4 8021B534 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF5A8 8021B538 0059000F */  sync      
/* 6CF5AC 8021B53C 00000046 */  rotrv     $zero, $zero, $zero
/* 6CF5B0 8021B540 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF5B4 8021B544 8029AC70 */  lb        $t1, -0x5390($at)
/* 6CF5B8 8021B548 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF5BC 8021B54C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF5C0 8021B550 00000002 */  srl       $zero, $zero, 0
/* 6CF5C4 8021B554 00000025 */  or        $zero, $zero, $zero
/* 6CF5C8 8021B558 00000002 */  srl       $zero, $zero, 0
/* 6CF5CC 8021B55C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF5D0 8021B560 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF5D4 8021B564 00000025 */  or        $zero, $zero, $zero
/* 6CF5D8 8021B568 00000002 */  srl       $zero, $zero, 0
/* 6CF5DC 8021B56C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF5E0 8021B570 00590006 */  srlv      $zero, $t9, $v0
/* 6CF5E4 8021B574 00000046 */  rotrv     $zero, $zero, $zero
/* 6CF5E8 8021B578 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF5EC 8021B57C 8029BFA0 */  lb        $t1, -0x4060($at)
/* 6CF5F0 8021B580 00000023 */  negu      $zero, $zero
/* 6CF5F4 8021B584 00000000 */  nop       
/* 6CF5F8 8021B588 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF5FC 8021B58C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF600 8021B590 00000039 */  .byte     0x00, 0x00, 0x00, 0x39
/* 6CF604 8021B594 00000043 */  sra       $zero, $zero, 1
/* 6CF608 8021B598 00000004 */  sllv      $zero, $zero, $zero
/* 6CF60C 8021B59C 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CF610 8021B5A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF614 8021B5A4 00000000 */  nop       
/* 6CF618 8021B5A8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF61C 8021B5AC 00000014 */  dsllv     $zero, $zero, $zero
/* 6CF620 8021B5B0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF624 8021B5B4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF628 8021B5B8 0000001D */  dmultu    $zero, $zero
/* 6CF62C 8021B5BC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF630 8021B5C0 00000000 */  nop       
/* 6CF634 8021B5C4 0000001D */  dmultu    $zero, $zero
/* 6CF638 8021B5C8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF63C 8021B5CC 00000002 */  srl       $zero, $zero, 0
/* 6CF640 8021B5D0 00000025 */  or        $zero, $zero, $zero
/* 6CF644 8021B5D4 00000002 */  srl       $zero, $zero, 0
/* 6CF648 8021B5D8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF64C 8021B5DC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF650 8021B5E0 00000025 */  or        $zero, $zero, $zero
/* 6CF654 8021B5E4 00000002 */  srl       $zero, $zero, 0
/* 6CF658 8021B5E8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF65C 8021B5EC 00590004 */  sllv      $zero, $t9, $v0
/* 6CF660 8021B5F0 00000025 */  or        $zero, $zero, $zero
/* 6CF664 8021B5F4 00000002 */  srl       $zero, $zero, 0
/* 6CF668 8021B5F8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CF66C 8021B5FC 0059000B */  movn      $zero, $v0, $t9
/* 6CF670 8021B600 00000046 */  rotrv     $zero, $zero, $zero
/* 6CF674 8021B604 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF678 8021B608 8029B22C */  lb        $t1, -0x4dd4($at)
/* 6CF67C 8021B60C 00000002 */  srl       $zero, $zero, 0
/* 6CF680 8021B610 00000000 */  nop       
/* 6CF684 8021B614 00000020 */  add       $zero, $zero, $zero
/* 6CF688 8021B618 00000000 */  nop       
/* 6CF68C 8021B61C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF690 8021B620 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF694 8021B624 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF698 8021B628 00000025 */  or        $zero, $zero, $zero
/* 6CF69C 8021B62C 00000002 */  srl       $zero, $zero, 0
/* 6CF6A0 8021B630 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF6A4 8021B634 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF6A8 8021B638 00000025 */  or        $zero, $zero, $zero
/* 6CF6AC 8021B63C 00000002 */  srl       $zero, $zero, 0
/* 6CF6B0 8021B640 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF6B4 8021B644 0059000F */  sync      
/* 6CF6B8 8021B648 00000046 */  rotrv     $zero, $zero, $zero
/* 6CF6BC 8021B64C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF6C0 8021B650 8029AC70 */  lb        $t1, -0x5390($at)
/* 6CF6C4 8021B654 00000023 */  negu      $zero, $zero
/* 6CF6C8 8021B658 00000000 */  nop       
/* 6CF6CC 8021B65C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF6D0 8021B660 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF6D4 8021B664 0000003A */  dsrl      $zero, $zero, 0
/* 6CF6D8 8021B668 00000043 */  sra       $zero, $zero, 1
/* 6CF6DC 8021B66C 00000004 */  sllv      $zero, $zero, $zero
/* 6CF6E0 8021B670 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CF6E4 8021B674 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF6E8 8021B678 00000000 */  nop       
/* 6CF6EC 8021B67C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF6F0 8021B680 00000014 */  dsllv     $zero, $zero, $zero
/* 6CF6F4 8021B684 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF6F8 8021B688 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF6FC 8021B68C 00000016 */  dsrlv     $zero, $zero, $zero
.L8021B690:
/* 6CF700 8021B690 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF704 8021B694 00000000 */  nop       
/* 6CF708 8021B698 00000025 */  or        $zero, $zero, $zero
/* 6CF70C 8021B69C 00000002 */  srl       $zero, $zero, 0
/* 6CF710 8021B6A0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF714 8021B6A4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF718 8021B6A8 00000025 */  or        $zero, $zero, $zero
/* 6CF71C 8021B6AC 00000002 */  srl       $zero, $zero, 0
/* 6CF720 8021B6B0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF724 8021B6B4 00590016 */  dsrlv     $zero, $t9, $v0
/* 6CF728 8021B6B8 00000046 */  rotrv     $zero, $zero, $zero
/* 6CF72C 8021B6BC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF730 8021B6C0 8029C37C */  lb        $t1, -0x3c84($at)
.L8021B6C4:
/* 6CF734 8021B6C4 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF738 8021B6C8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF73C 8021B6CC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF740 8021B6D0 00000025 */  or        $zero, $zero, $zero
/* 6CF744 8021B6D4 00000002 */  srl       $zero, $zero, 0
/* 6CF748 8021B6D8 FE363C80 */  sd        $s6, 0x3c80($s1)
.L8021B6DC:
/* 6CF74C 8021B6DC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF750 8021B6E0 00000025 */  or        $zero, $zero, $zero
/* 6CF754 8021B6E4 00000002 */  srl       $zero, $zero, 0
/* 6CF758 8021B6E8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF75C 8021B6EC 0059000F */  sync      
/* 6CF760 8021B6F0 00000046 */  rotrv     $zero, $zero, $zero
/* 6CF764 8021B6F4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF768 8021B6F8 8029C37C */  lb        $t1, -0x3c84($at)
/* 6CF76C 8021B6FC 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF770 8021B700 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF774 8021B704 00000002 */  srl       $zero, $zero, 0
/* 6CF778 8021B708 00000025 */  or        $zero, $zero, $zero
/* 6CF77C 8021B70C 00000002 */  srl       $zero, $zero, 0
/* 6CF780 8021B710 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF784 8021B714 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF788 8021B718 00000025 */  or        $zero, $zero, $zero
/* 6CF78C 8021B71C 00000002 */  srl       $zero, $zero, 0
/* 6CF790 8021B720 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF794 8021B724 0059000F */  sync      
/* 6CF798 8021B728 00000046 */  rotrv     $zero, $zero, $zero
/* 6CF79C 8021B72C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF7A0 8021B730 8029C37C */  lb        $t1, -0x3c84($at)
/* 6CF7A4 8021B734 00000023 */  negu      $zero, $zero
/* 6CF7A8 8021B738 00000000 */  nop       
/* 6CF7AC 8021B73C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF7B0 8021B740 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF7B4 8021B744 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF7B8 8021B748 00000043 */  sra       $zero, $zero, 1
/* 6CF7BC 8021B74C 00000004 */  sllv      $zero, $zero, $zero
/* 6CF7C0 8021B750 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CF7C4 8021B754 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF7C8 8021B758 00000000 */  nop       
/* 6CF7CC 8021B75C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF7D0 8021B760 00000014 */  dsllv     $zero, $zero, $zero
/* 6CF7D4 8021B764 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF7D8 8021B768 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF7DC 8021B76C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF7E0 8021B770 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF7E4 8021B774 00000000 */  nop       
/* 6CF7E8 8021B778 00000025 */  or        $zero, $zero, $zero
/* 6CF7EC 8021B77C 00000002 */  srl       $zero, $zero, 0
/* 6CF7F0 8021B780 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF7F4 8021B784 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF7F8 8021B788 00000025 */  or        $zero, $zero, $zero
/* 6CF7FC 8021B78C 00000002 */  srl       $zero, $zero, 0
/* 6CF800 8021B790 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF804 8021B794 00590016 */  dsrlv     $zero, $t9, $v0
/* 6CF808 8021B798 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF80C 8021B79C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF810 8021B7A0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF814 8021B7A4 00000025 */  or        $zero, $zero, $zero
/* 6CF818 8021B7A8 00000002 */  srl       $zero, $zero, 0
/* 6CF81C 8021B7AC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF820 8021B7B0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF824 8021B7B4 00000025 */  or        $zero, $zero, $zero
/* 6CF828 8021B7B8 00000002 */  srl       $zero, $zero, 0
/* 6CF82C 8021B7BC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF830 8021B7C0 0059000F */  sync      
/* 6CF834 8021B7C4 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF838 8021B7C8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF83C 8021B7CC 00000002 */  srl       $zero, $zero, 0
/* 6CF840 8021B7D0 00000025 */  or        $zero, $zero, $zero
/* 6CF844 8021B7D4 00000002 */  srl       $zero, $zero, 0
/* 6CF848 8021B7D8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF84C 8021B7DC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF850 8021B7E0 00000025 */  or        $zero, $zero, $zero
/* 6CF854 8021B7E4 00000002 */  srl       $zero, $zero, 0
/* 6CF858 8021B7E8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF85C 8021B7EC 0059000F */  sync      
/* 6CF860 8021B7F0 00000023 */  negu      $zero, $zero
/* 6CF864 8021B7F4 00000000 */  nop       
/* 6CF868 8021B7F8 00000046 */  rotrv     $zero, $zero, $zero
/* 6CF86C 8021B7FC 00000001 */  movf      $zero, $zero, $fcc0
.L8021B800:
/* 6CF870 8021B800 8029C4A8 */  lb        $t1, -0x3b58($at)
/* 6CF874 8021B804 00000002 */  srl       $zero, $zero, 0
/* 6CF878 8021B808 00000000 */  nop       
/* 6CF87C 8021B80C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF880 8021B810 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF884 8021B814 0000001F */  ddivu     $zero, $zero, $zero
/* 6CF888 8021B818 00000043 */  sra       $zero, $zero, 1
/* 6CF88C 8021B81C 00000004 */  sllv      $zero, $zero, $zero
/* 6CF890 8021B820 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CF894 8021B824 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF898 8021B828 00000000 */  nop       
/* 6CF89C 8021B82C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF8A0 8021B830 00000014 */  dsllv     $zero, $zero, $zero
/* 6CF8A4 8021B834 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF8A8 8021B838 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF8AC 8021B83C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF8B0 8021B840 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF8B4 8021B844 00000000 */  nop       
/* 6CF8B8 8021B848 00000025 */  or        $zero, $zero, $zero
/* 6CF8BC 8021B84C 00000002 */  srl       $zero, $zero, 0
/* 6CF8C0 8021B850 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF8C4 8021B854 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF8C8 8021B858 00000025 */  or        $zero, $zero, $zero
/* 6CF8CC 8021B85C 00000002 */  srl       $zero, $zero, 0
/* 6CF8D0 8021B860 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF8D4 8021B864 00590001 */  movt      $zero, $v0, $fcc6
/* 6CF8D8 8021B868 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF8DC 8021B86C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF8E0 8021B870 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF8E4 8021B874 00000025 */  or        $zero, $zero, $zero
/* 6CF8E8 8021B878 00000002 */  srl       $zero, $zero, 0
/* 6CF8EC 8021B87C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF8F0 8021B880 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF8F4 8021B884 00000025 */  or        $zero, $zero, $zero
/* 6CF8F8 8021B888 00000002 */  srl       $zero, $zero, 0
/* 6CF8FC 8021B88C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF900 8021B890 0059000F */  sync      
/* 6CF904 8021B894 00000016 */  dsrlv     $zero, $zero, $zero
/* 6CF908 8021B898 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF90C 8021B89C 00000002 */  srl       $zero, $zero, 0
/* 6CF910 8021B8A0 00000025 */  or        $zero, $zero, $zero
/* 6CF914 8021B8A4 00000002 */  srl       $zero, $zero, 0
/* 6CF918 8021B8A8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF91C 8021B8AC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF920 8021B8B0 00000025 */  or        $zero, $zero, $zero
/* 6CF924 8021B8B4 00000002 */  srl       $zero, $zero, 0
/* 6CF928 8021B8B8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CF92C 8021B8BC 0059000F */  sync      
/* 6CF930 8021B8C0 00000023 */  negu      $zero, $zero
/* 6CF934 8021B8C4 00000000 */  nop       
/* 6CF938 8021B8C8 00000046 */  rotrv     $zero, $zero, $zero
/* 6CF93C 8021B8CC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF940 8021B8D0 8029AC70 */  lb        $t1, -0x5390($at)
/* 6CF944 8021B8D4 00000023 */  negu      $zero, $zero
/* 6CF948 8021B8D8 00000000 */  nop       
/* 6CF94C 8021B8DC 00000043 */  sra       $zero, $zero, 1
/* 6CF950 8021B8E0 00000003 */  sra       $zero, $zero, 0
/* 6CF954 8021B8E4 80278B4C */  lb        $a3, -0x74b4($at)
/* 6CF958 8021B8E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF95C 8021B8EC FFFFFFFF */  sd        $ra, -1($ra)
/* 6CF960 8021B8F0 00000043 */  sra       $zero, $zero, 1
/* 6CF964 8021B8F4 00000003 */  sra       $zero, $zero, 0
/* 6CF968 8021B8F8 8026F0EC */  lb        $a2, -0xf14($at)
/* 6CF96C 8021B8FC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF970 8021B900 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF974 8021B904 00000002 */  srl       $zero, $zero, 0
/* 6CF978 8021B908 00000000 */  nop       
/* 6CF97C 8021B90C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF980 8021B910 00000000 */  nop       
/* 6CF984 8021B914 00000043 */  sra       $zero, $zero, 1
/* 6CF988 8021B918 00000003 */  sra       $zero, $zero, 0
/* 6CF98C 8021B91C 8026F0EC */  lb        $a2, -0xf14($at)
/* 6CF990 8021B920 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF994 8021B924 00000000 */  nop       
/* 6CF998 8021B928 00000043 */  sra       $zero, $zero, 1
/* 6CF99C 8021B92C 00000003 */  sra       $zero, $zero, 0
/* 6CF9A0 8021B930 80278B4C */  lb        $a3, -0x74b4($at)
/* 6CF9A4 8021B934 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF9A8 8021B938 00000000 */  nop       
/* 6CF9AC 8021B93C 00000043 */  sra       $zero, $zero, 1
/* 6CF9B0 8021B940 00000003 */  sra       $zero, $zero, 0
/* 6CF9B4 8021B944 8027C548 */  lb        $a3, -0x3ab8($at)
/* 6CF9B8 8021B948 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF9BC 8021B94C 00000000 */  nop       
/* 6CF9C0 8021B950 00000043 */  sra       $zero, $zero, 1
/* 6CF9C4 8021B954 00000002 */  srl       $zero, $zero, 0
/* 6CF9C8 8021B958 80269E28 */  lb        $a2, -0x61d8($at)
/* 6CF9CC 8021B95C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF9D0 8021B960 0000000A */  movz      $zero, $zero, $zero
/* 6CF9D4 8021B964 00000002 */  srl       $zero, $zero, 0
/* 6CF9D8 8021B968 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CF9DC 8021B96C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF9E0 8021B970 00000043 */  sra       $zero, $zero, 1
/* 6CF9E4 8021B974 00000004 */  sllv      $zero, $zero, $zero
/* 6CF9E8 8021B978 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6CF9EC 8021B97C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CF9F0 8021B980 00000001 */  movf      $zero, $zero, $fcc0
/* 6CF9F4 8021B984 00590006 */  srlv      $zero, $t9, $v0
/* 6CF9F8 8021B988 00000012 */  mflo      $zero
/* 6CF9FC 8021B98C 00000000 */  nop       
/* 6CFA00 8021B990 00000043 */  sra       $zero, $zero, 1
/* 6CFA04 8021B994 00000004 */  sllv      $zero, $zero, $zero
/* 6CFA08 8021B998 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CFA0C 8021B99C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFA10 8021B9A0 00000000 */  nop       
/* 6CFA14 8021B9A4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CFA18 8021B9A8 0000000A */  movz      $zero, $zero, $zero
/* 6CFA1C 8021B9AC 00000002 */  srl       $zero, $zero, 0
/* 6CFA20 8021B9B0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CFA24 8021B9B4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFA28 8021B9B8 00000043 */  sra       $zero, $zero, 1
/* 6CFA2C 8021B9BC 00000004 */  sllv      $zero, $zero, $zero
/* 6CFA30 8021B9C0 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6CFA34 8021B9C4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFA38 8021B9C8 00000009 */  jr        $zero
/* 6CFA3C 8021B9CC FE363C80 */   sd       $s6, 0x3c80($s1)
/* 6CFA40 8021B9D0 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6CFA44 8021B9D4 00000002 */  srl       $zero, $zero, 0
/* 6CFA48 8021B9D8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CFA4C 8021B9DC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFA50 8021B9E0 0000000D */  break     
/* 6CFA54 8021B9E4 00000002 */   srl      $zero, $zero, 0
/* 6CFA58 8021B9E8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CFA5C 8021B9EC 00000000 */  nop       
/* 6CFA60 8021B9F0 00000043 */  sra       $zero, $zero, 1
/* 6CFA64 8021B9F4 00000004 */  sllv      $zero, $zero, $zero
/* 6CFA68 8021B9F8 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6CFA6C 8021B9FC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFA70 8021BA00 00000009 */  jr        $zero
/* 6CFA74 8021BA04 FE363C80 */   sd       $s6, 0x3c80($s1)
/* 6CFA78 8021BA08 00000043 */  sra       $zero, $zero, 1
/* 6CFA7C 8021BA0C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CFA80 8021BA10 8026EE88 */  lb        $a2, -0x1178($at)
/* 6CFA84 8021BA14 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFA88 8021BA18 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFA8C 8021BA1C 00000000 */  nop       
/* 6CFA90 8021BA20 00000002 */  srl       $zero, $zero, 0
/* 6CFA94 8021BA24 00000043 */  sra       $zero, $zero, 1
/* 6CFA98 8021BA28 00000004 */  sllv      $zero, $zero, $zero
/* 6CFA9C 8021BA2C 8026B2D0 */  lb        $a2, -0x4d30($at)
/* 6CFAA0 8021BA30 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFAA4 8021BA34 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFAA8 8021BA38 F24A8680 */  scd       $t2, -0x7980($s2)
/* 6CFAAC 8021BA3C 00000008 */  jr        $zero
/* 6CFAB0 8021BA40 00000001 */   movf     $zero, $zero, $fcc0
/* 6CFAB4 8021BA44 0000000F */  sync      
/* 6CFAB8 8021BA48 00000043 */  sra       $zero, $zero, 1
/* 6CFABC 8021BA4C 00000004 */  sllv      $zero, $zero, $zero
/* 6CFAC0 8021BA50 8026B2D0 */  lb        $a2, -0x4d30($at)
/* 6CFAC4 8021BA54 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFAC8 8021BA58 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFACC 8021BA5C F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 6CFAD0 8021BA60 00000043 */  sra       $zero, $zero, 1
/* 6CFAD4 8021BA64 00000004 */  sllv      $zero, $zero, $zero
/* 6CFAD8 8021BA68 8026EF4C */  lb        $a2, -0x10b4($at)
/* 6CFADC 8021BA6C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFAE0 8021BA70 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFAE4 8021BA74 00000000 */  nop       
/* 6CFAE8 8021BA78 00000012 */  mflo      $zero
/* 6CFAEC 8021BA7C 00000000 */  nop       
/* 6CFAF0 8021BA80 00000043 */  sra       $zero, $zero, 1
/* 6CFAF4 8021BA84 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CFAF8 8021BA88 8026EE88 */  lb        $a2, -0x1178($at)
/* 6CFAFC 8021BA8C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFB00 8021BA90 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFB04 8021BA94 00000000 */  nop       
/* 6CFB08 8021BA98 00000002 */  srl       $zero, $zero, 0
/* 6CFB0C 8021BA9C 00000043 */  sra       $zero, $zero, 1
/* 6CFB10 8021BAA0 00000004 */  sllv      $zero, $zero, $zero
/* 6CFB14 8021BAA4 8026B2D0 */  lb        $a2, -0x4d30($at)
/* 6CFB18 8021BAA8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFB1C 8021BAAC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFB20 8021BAB0 F24A8680 */  scd       $t2, -0x7980($s2)
/* 6CFB24 8021BAB4 00000008 */  jr        $zero
/* 6CFB28 8021BAB8 00000001 */   movf     $zero, $zero, $fcc0
/* 6CFB2C 8021BABC 0000000A */  movz      $zero, $zero, $zero
/* 6CFB30 8021BAC0 00000043 */  sra       $zero, $zero, 1
/* 6CFB34 8021BAC4 00000004 */  sllv      $zero, $zero, $zero
/* 6CFB38 8021BAC8 8026B2D0 */  lb        $a2, -0x4d30($at)
/* 6CFB3C 8021BACC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFB40 8021BAD0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFB44 8021BAD4 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 6CFB48 8021BAD8 00000043 */  sra       $zero, $zero, 1
/* 6CFB4C 8021BADC 00000004 */  sllv      $zero, $zero, $zero
/* 6CFB50 8021BAE0 8026EF4C */  lb        $a2, -0x10b4($at)
/* 6CFB54 8021BAE4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFB58 8021BAE8 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFB5C 8021BAEC 00000000 */  nop       
/* 6CFB60 8021BAF0 00000043 */  sra       $zero, $zero, 1
/* 6CFB64 8021BAF4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CFB68 8021BAF8 8026F740 */  lb        $a2, -0x8c0($at)
/* 6CFB6C 8021BAFC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFB70 8021BB00 00000002 */  srl       $zero, $zero, 0
/* 6CFB74 8021BB04 00000000 */  nop       
/* 6CFB78 8021BB08 00000000 */  nop       
/* 6CFB7C 8021BB0C 00000043 */  sra       $zero, $zero, 1
/* 6CFB80 8021BB10 00000003 */  sra       $zero, $zero, 0
/* 6CFB84 8021BB14 8025385C */  lb        $a1, 0x385c($at)
/* 6CFB88 8021BB18 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFB8C 8021BB1C 000003E2 */  .byte     0x00, 0x00, 0x03, 0xe2
/* 6CFB90 8021BB20 00000043 */  sra       $zero, $zero, 1
/* 6CFB94 8021BB24 00000004 */  sllv      $zero, $zero, $zero
/* 6CFB98 8021BB28 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6CFB9C 8021BB2C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFBA0 8021BB30 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFBA4 8021BB34 0059000F */  sync      
/* 6CFBA8 8021BB38 00000024 */  and       $zero, $zero, $zero
/* 6CFBAC 8021BB3C 00000002 */  srl       $zero, $zero, 0
/* 6CFBB0 8021BB40 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CFBB4 8021BB44 00000000 */  nop       
/* 6CFBB8 8021BB48 00000043 */  sra       $zero, $zero, 1
/* 6CFBBC 8021BB4C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CFBC0 8021BB50 8026C4AC */  lb        $a2, -0x3b54($at)
/* 6CFBC4 8021BB54 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFBC8 8021BB58 00000000 */  nop       
/* 6CFBCC 8021BB5C 0000000C */  syscall   
/* 6CFBD0 8021BB60 00000000 */  nop       
/* 6CFBD4 8021BB64 00000056 */  drotrv    $zero, $zero, $zero
/* 6CFBD8 8021BB68 00000000 */  nop       
/* 6CFBDC 8021BB6C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CFBE0 8021BB70 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFBE4 8021BB74 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CFBE8 8021BB78 00000027 */  not       $zero, $zero
/* 6CFBEC 8021BB7C 00000002 */  srl       $zero, $zero, 0
/* 6CFBF0 8021BB80 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CFBF4 8021BB84 0000000F */  sync      
/* 6CFBF8 8021BB88 00000043 */  sra       $zero, $zero, 1
/* 6CFBFC 8021BB8C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CFC00 8021BB90 8026C3AC */  lb        $a2, -0x3c54($at)
/* 6CFC04 8021BB94 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFC08 8021BB98 00000000 */  nop       
/* 6CFC0C 8021BB9C 00000000 */  nop       
/* 6CFC10 8021BBA0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CFC14 8021BBA4 00000008 */  jr        $zero
/* 6CFC18 8021BBA8 00000001 */   movf     $zero, $zero, $fcc0
/* 6CFC1C 8021BBAC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFC20 8021BBB0 00000006 */  srlv      $zero, $zero, $zero
/* 6CFC24 8021BBB4 00000000 */  nop       
/* 6CFC28 8021BBB8 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6CFC2C 8021BBBC 00000000 */  nop       
/* 6CFC30 8021BBC0 00000043 */  sra       $zero, $zero, 1
/* 6CFC34 8021BBC4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CFC38 8021BBC8 8026AAA8 */  lb        $a2, -0x5558($at)
.L8021BBCC:
/* 6CFC3C 8021BBCC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFC40 8021BBD0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CFC44 8021BBD4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CFC48 8021BBD8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CFC4C 8021BBDC 00000043 */  sra       $zero, $zero, 1
/* 6CFC50 8021BBE0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CFC54 8021BBE4 8026A510 */  lb        $a2, -0x5af0($at)
/* 6CFC58 8021BBE8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFC5C 8021BBEC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CFC60 8021BBF0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CFC64 8021BBF4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CFC68 8021BBF8 00000043 */  sra       $zero, $zero, 1
/* 6CFC6C 8021BBFC 00000003 */  sra       $zero, $zero, 0
/* 6CFC70 8021BC00 8026B55C */  lb        $a2, -0x4aa4($at)
/* 6CFC74 8021BC04 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFC78 8021BC08 F24A8680 */  scd       $t2, -0x7980($s2)
/* 6CFC7C 8021BC0C 00000043 */  sra       $zero, $zero, 1
/* 6CFC80 8021BC10 00000006 */  srlv      $zero, $zero, $zero
/* 6CFC84 8021BC14 80278D08 */  lb        $a3, -0x72f8($at)
/* 6CFC88 8021BC18 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFC8C 8021BC1C 00000008 */  jr        $zero
/* 6CFC90 8021BC20 00000000 */   nop      
.L8021BC24:
/* 6CFC94 8021BC24 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFC98 8021BC28 00000000 */  nop       
/* 6CFC9C 8021BC2C 00000043 */  sra       $zero, $zero, 1
/* 6CFCA0 8021BC30 00000003 */  sra       $zero, $zero, 0
/* 6CFCA4 8021BC34 8025385C */  lb        $a1, 0x385c($at)
/* 6CFCA8 8021BC38 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFCAC 8021BC3C 000020BA */  dsrl      $a0, $zero, 2
/* 6CFCB0 8021BC40 00000043 */  sra       $zero, $zero, 1
/* 6CFCB4 8021BC44 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CFCB8 8021BC48 8026C4AC */  lb        $a2, -0x3b54($at)
/* 6CFCBC 8021BC4C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFCC0 8021BC50 00000000 */  nop       
/* 6CFCC4 8021BC54 00000000 */  nop       
/* 6CFCC8 8021BC58 00000000 */  nop       
/* 6CFCCC 8021BC5C 00000043 */  sra       $zero, $zero, 1
/* 6CFCD0 8021BC60 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CFCD4 8021BC64 8026C3AC */  lb        $a2, -0x3c54($at)
/* 6CFCD8 8021BC68 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFCDC 8021BC6C 00000000 */  nop       
/* 6CFCE0 8021BC70 00000000 */  nop       
/* 6CFCE4 8021BC74 00000000 */  nop       
/* 6CFCE8 8021BC78 00000043 */  sra       $zero, $zero, 1
/* 6CFCEC 8021BC7C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CFCF0 8021BC80 8026BA04 */  lb        $a2, -0x45fc($at)
/* 6CFCF4 8021BC84 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFCF8 8021BC88 00000000 */  nop       
/* 6CFCFC 8021BC8C 00000000 */  nop       
/* 6CFD00 8021BC90 00000000 */  nop       
/* 6CFD04 8021BC94 00000043 */  sra       $zero, $zero, 1
/* 6CFD08 8021BC98 00000004 */  sllv      $zero, $zero, $zero
/* 6CFD0C 8021BC9C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6CFD10 8021BCA0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFD14 8021BCA4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFD18 8021BCA8 00590001 */  movt      $zero, $v0, $fcc6
/* 6CFD1C 8021BCAC 00000043 */  sra       $zero, $zero, 1
/* 6CFD20 8021BCB0 00000004 */  sllv      $zero, $zero, $zero
/* 6CFD24 8021BCB4 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6CFD28 8021BCB8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFD2C 8021BCBC 00000000 */  nop       
/* 6CFD30 8021BCC0 00000000 */  nop       
/* 6CFD34 8021BCC4 00000043 */  sra       $zero, $zero, 1
/* 6CFD38 8021BCC8 00000004 */  sllv      $zero, $zero, $zero
/* 6CFD3C 8021BCCC 8027CB7C */  lb        $a3, -0x3484($at)
/* 6CFD40 8021BCD0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFD44 8021BCD4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFD48 8021BCD8 80219BD0 */  lb        $at, -0x6430($at)
.L8021BCDC:
/* 6CFD4C 8021BCDC 00000043 */  sra       $zero, $zero, 1
/* 6CFD50 8021BCE0 00000004 */  sllv      $zero, $zero, $zero
/* 6CFD54 8021BCE4 8027CA74 */  lb        $a3, -0x358c($at)
/* 6CFD58 8021BCE8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFD5C 8021BCEC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFD60 8021BCF0 80219D00 */  lb        $at, -0x6300($at)
/* 6CFD64 8021BCF4 00000043 */  sra       $zero, $zero, 1
/* 6CFD68 8021BCF8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CFD6C 8021BCFC 8027D380 */  lb        $a3, -0x2c80($at)
/* 6CFD70 8021BD00 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFD74 8021BD04 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFD78 8021BD08 FFFFFFFC */  sd        $ra, -4($ra)
/* 6CFD7C 8021BD0C 00000020 */  add       $zero, $zero, $zero
/* 6CFD80 8021BD10 00000043 */  sra       $zero, $zero, 1
/* 6CFD84 8021BD14 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CFD88 8021BD18 8027D4C8 */  lb        $a3, -0x2b38($at)
/* 6CFD8C 8021BD1C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFD90 8021BD20 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFD94 8021BD24 FFFFFFFF */  sd        $ra, -1($ra)
/* 6CFD98 8021BD28 FFFFFFFC */  sd        $ra, -4($ra)
/* 6CFD9C 8021BD2C 00000043 */  sra       $zero, $zero, 1
/* 6CFDA0 8021BD30 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CFDA4 8021BD34 8026D3C8 */  lb        $a2, -0x2c38($at)
/* 6CFDA8 8021BD38 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFDAC 8021BD3C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFDB0 8021BD40 00000010 */  mfhi      $zero
/* 6CFDB4 8021BD44 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFDB8 8021BD48 00000043 */  sra       $zero, $zero, 1
/* 6CFDBC 8021BD4C 00000004 */  sllv      $zero, $zero, $zero
/* 6CFDC0 8021BD50 8026CE8C */  lb        $a2, -0x3174($at)
/* 6CFDC4 8021BD54 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFDC8 8021BD58 00000400 */  sll       $zero, $zero, 0x10
/* 6CFDCC 8021BD5C 00000000 */  nop       
/* 6CFDD0 8021BD60 00000013 */  mtlo      $zero
/* 6CFDD4 8021BD64 00000000 */  nop       
/* 6CFDD8 8021BD68 00000043 */  sra       $zero, $zero, 1
/* 6CFDDC 8021BD6C 00000003 */  sra       $zero, $zero, 0
/* 6CFDE0 8021BD70 80278B4C */  lb        $a3, -0x74b4($at)
/* 6CFDE4 8021BD74 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFDE8 8021BD78 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFDEC 8021BD7C 00000043 */  sra       $zero, $zero, 1
/* 6CFDF0 8021BD80 00000003 */  sra       $zero, $zero, 0
/* 6CFDF4 8021BD84 8026F0EC */  lb        $a2, -0xf14($at)
/* 6CFDF8 8021BD88 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFDFC 8021BD8C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFE00 8021BD90 00000002 */  srl       $zero, $zero, 0
/* 6CFE04 8021BD94 00000000 */  nop       
/* 6CFE08 8021BD98 00000013 */  mtlo      $zero
/* 6CFE0C 8021BD9C 00000000 */  nop       
/* 6CFE10 8021BDA0 00000043 */  sra       $zero, $zero, 1
/* 6CFE14 8021BDA4 00000002 */  srl       $zero, $zero, 0
/* 6CFE18 8021BDA8 8024E61C */  lb        $a0, -0x19e4($at)
/* 6CFE1C 8021BDAC 0000003F */  dsra32    $zero, $zero, 0
/* 6CFE20 8021BDB0 00000043 */  sra       $zero, $zero, 1
/* 6CFE24 8021BDB4 00000002 */  srl       $zero, $zero, 0
/* 6CFE28 8021BDB8 8024EB24 */  lb        $a0, -0x14dc($at)
/* 6CFE2C 8021BDBC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFE30 8021BDC0 00000043 */  sra       $zero, $zero, 1
/* 6CFE34 8021BDC4 00000004 */  sllv      $zero, $zero, $zero
/* 6CFE38 8021BDC8 8024ECF8 */  lb        $a0, -0x1308($at)
/* 6CFE3C 8021BDCC FFFFFFFF */  sd        $ra, -1($ra)
/* 6CFE40 8021BDD0 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFE44 8021BDD4 00000000 */  nop       
/* 6CFE48 8021BDD8 00000008 */  jr        $zero
/* 6CFE4C 8021BDDC 00000001 */   movf     $zero, $zero, $fcc0
/* 6CFE50 8021BDE0 0000000A */  movz      $zero, $zero, $zero
/* 6CFE54 8021BDE4 00000043 */  sra       $zero, $zero, 1
/* 6CFE58 8021BDE8 00000004 */  sllv      $zero, $zero, $zero
/* 6CFE5C 8021BDEC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6CFE60 8021BDF0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFE64 8021BDF4 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFE68 8021BDF8 00590007 */  srav      $zero, $t9, $v0
/* 6CFE6C 8021BDFC 00000008 */  jr        $zero
/* 6CFE70 8021BE00 00000001 */   movf     $zero, $zero, $fcc0
/* 6CFE74 8021BE04 0000000A */  movz      $zero, $zero, $zero
/* 6CFE78 8021BE08 00000056 */  drotrv    $zero, $zero, $zero
/* 6CFE7C 8021BE0C 00000000 */  nop       
/* 6CFE80 8021BE10 00000043 */  sra       $zero, $zero, 1
/* 6CFE84 8021BE14 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6CFE88 8021BE18 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6CFE8C 8021BE1C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFE90 8021BE20 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CFE94 8021BE24 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CFE98 8021BE28 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CFE9C 8021BE2C 00000027 */  not       $zero, $zero
/* 6CFEA0 8021BE30 00000002 */  srl       $zero, $zero, 0
.L8021BE34:
/* 6CFEA4 8021BE34 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CFEA8 8021BE38 00000004 */  sllv      $zero, $zero, $zero
/* 6CFEAC 8021BE3C 00000043 */  sra       $zero, $zero, 1
/* 6CFEB0 8021BE40 0000000F */  sync      
.L8021BE44:
/* 6CFEB4 8021BE44 802D829C */  lb        $t5, -0x7d64($at)
/* 6CFEB8 8021BE48 0000001D */  dmultu    $zero, $zero
/* 6CFEBC 8021BE4C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFEC0 8021BE50 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CFEC4 8021BE54 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CFEC8 8021BE58 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CFECC 8021BE5C 00000020 */  add       $zero, $zero, $zero
/* 6CFED0 8021BE60 00000004 */  sllv      $zero, $zero, $zero
/* 6CFED4 8021BE64 00000000 */  nop       
/* 6CFED8 8021BE68 0000000A */  movz      $zero, $zero, $zero
/* 6CFEDC 8021BE6C 00000000 */  nop       
/* 6CFEE0 8021BE70 00000000 */  nop       
/* 6CFEE4 8021BE74 00000000 */  nop       
/* 6CFEE8 8021BE78 00000000 */  nop       
/* 6CFEEC 8021BE7C 00000000 */  nop       
/* 6CFEF0 8021BE80 00000008 */  jr        $zero
/* 6CFEF4 8021BE84 00000001 */   movf     $zero, $zero, $fcc0
/* 6CFEF8 8021BE88 00000003 */  sra       $zero, $zero, 0
/* 6CFEFC 8021BE8C 00000043 */  sra       $zero, $zero, 1
/* 6CFF00 8021BE90 0000000F */  sync      
/* 6CFF04 8021BE94 802D829C */  lb        $t5, -0x7d64($at)
/* 6CFF08 8021BE98 0000001D */  dmultu    $zero, $zero
/* 6CFF0C 8021BE9C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFF10 8021BEA0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CFF14 8021BEA4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CFF18 8021BEA8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CFF1C 8021BEAC 00000020 */  add       $zero, $zero, $zero
/* 6CFF20 8021BEB0 00000004 */  sllv      $zero, $zero, $zero
/* 6CFF24 8021BEB4 00000000 */  nop       
/* 6CFF28 8021BEB8 0000000A */  movz      $zero, $zero, $zero
/* 6CFF2C 8021BEBC 00000000 */  nop       
/* 6CFF30 8021BEC0 00000000 */  nop       
/* 6CFF34 8021BEC4 00000000 */  nop       
/* 6CFF38 8021BEC8 00000000 */  nop       
/* 6CFF3C 8021BECC 00000000 */  nop       
/* 6CFF40 8021BED0 00000008 */  jr        $zero
/* 6CFF44 8021BED4 00000001 */   movf     $zero, $zero, $fcc0
/* 6CFF48 8021BED8 00000002 */  srl       $zero, $zero, 0
/* 6CFF4C 8021BEDC 00000043 */  sra       $zero, $zero, 1
/* 6CFF50 8021BEE0 0000000F */  sync      
/* 6CFF54 8021BEE4 802D829C */  lb        $t5, -0x7d64($at)
/* 6CFF58 8021BEE8 0000001D */  dmultu    $zero, $zero
/* 6CFF5C 8021BEEC 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFF60 8021BEF0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6CFF64 8021BEF4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6CFF68 8021BEF8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6CFF6C 8021BEFC 00000020 */  add       $zero, $zero, $zero
/* 6CFF70 8021BF00 00000004 */  sllv      $zero, $zero, $zero
/* 6CFF74 8021BF04 00000000 */  nop       
/* 6CFF78 8021BF08 0000000A */  movz      $zero, $zero, $zero
/* 6CFF7C 8021BF0C 00000000 */  nop       
/* 6CFF80 8021BF10 00000000 */  nop       
/* 6CFF84 8021BF14 00000000 */  nop       
/* 6CFF88 8021BF18 00000000 */  nop       
/* 6CFF8C 8021BF1C 00000000 */  nop       
/* 6CFF90 8021BF20 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6CFF94 8021BF24 00000000 */  nop       
/* 6CFF98 8021BF28 00000043 */  sra       $zero, $zero, 1
/* 6CFF9C 8021BF2C 00000003 */  sra       $zero, $zero, 0
/* 6CFFA0 8021BF30 8025385C */  lb        $a1, 0x385c($at)
/* 6CFFA4 8021BF34 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFFA8 8021BF38 00002021 */  addu      $a0, $zero, $zero
/* 6CFFAC 8021BF3C 00000043 */  sra       $zero, $zero, 1
/* 6CFFB0 8021BF40 00000004 */  sllv      $zero, $zero, $zero
/* 6CFFB4 8021BF44 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6CFFB8 8021BF48 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6CFFBC 8021BF4C 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFFC0 8021BF50 00590006 */  srlv      $zero, $t9, $v0
/* 6CFFC4 8021BF54 00000008 */  jr        $zero
/* 6CFFC8 8021BF58 00000001 */   movf     $zero, $zero, $fcc0
/* 6CFFCC 8021BF5C 0000000A */  movz      $zero, $zero, $zero
/* 6CFFD0 8021BF60 00000043 */  sra       $zero, $zero, 1
/* 6CFFD4 8021BF64 00000004 */  sllv      $zero, $zero, $zero
/* 6CFFD8 8021BF68 8024ECF8 */  lb        $a0, -0x1308($at)
/* 6CFFDC 8021BF6C FFFFFFFF */  sd        $ra, -1($ra)
/* 6CFFE0 8021BF70 00000001 */  movf      $zero, $zero, $fcc0
/* 6CFFE4 8021BF74 00000000 */  nop       
/* 6CFFE8 8021BF78 00000013 */  mtlo      $zero
/* 6CFFEC 8021BF7C 00000000 */  nop       
/* 6CFFF0 8021BF80 00000043 */  sra       $zero, $zero, 1
/* 6CFFF4 8021BF84 00000003 */  sra       $zero, $zero, 0
/* 6CFFF8 8021BF88 8025385C */  lb        $a1, 0x385c($at)
/* 6CFFFC 8021BF8C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0000 8021BF90 000020D3 */  .byte     0x00, 0x00, 0x20, 0xd3
/* 6D0004 8021BF94 00000043 */  sra       $zero, $zero, 1
/* 6D0008 8021BF98 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D000C 8021BF9C 8026F740 */  lb        $a2, -0x8c0($at)
/* 6D0010 8021BFA0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0014 8021BFA4 00000000 */  nop       
/* 6D0018 8021BFA8 00000000 */  nop       
/* 6D001C 8021BFAC 00000000 */  nop       
/* 6D0020 8021BFB0 00000043 */  sra       $zero, $zero, 1
/* 6D0024 8021BFB4 00000007 */  srav      $zero, $zero, $zero
/* 6D0028 8021BFB8 8027CFB8 */  lb        $a3, -0x3048($at)
/* 6D002C 8021BFBC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0030 8021BFC0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D0034 8021BFC4 00000000 */  nop       
/* 6D0038 8021BFC8 00000000 */  nop       
/* 6D003C 8021BFCC 00000004 */  sllv      $zero, $zero, $zero
/* 6D0040 8021BFD0 00000010 */  mfhi      $zero
/* 6D0044 8021BFD4 00000014 */  dsllv     $zero, $zero, $zero
/* 6D0048 8021BFD8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D004C 8021BFDC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D0050 8021BFE0 0000001D */  dmultu    $zero, $zero
/* 6D0054 8021BFE4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0058 8021BFE8 00000006 */  srlv      $zero, $zero, $zero
/* 6D005C 8021BFEC 0000001D */  dmultu    $zero, $zero
/* 6D0060 8021BFF0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0064 8021BFF4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0068 8021BFF8 00000024 */  and       $zero, $zero, $zero
/* 6D006C 8021BFFC 00000002 */  srl       $zero, $zero, 0
/* 6D0070 8021C000 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D0074 8021C004 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D0078 8021C008 00000043 */  sra       $zero, $zero, 1
/* 6D007C 8021C00C 00000002 */  srl       $zero, $zero, 0
/* 6D0080 8021C010 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 6D0084 8021C014 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0088 8021C018 00000043 */  sra       $zero, $zero, 1
/* 6D008C 8021C01C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0090 8021C020 8026A748 */  lb        $a2, -0x58b8($at)
/* 6D0094 8021C024 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0098 8021C028 FFFFFFD8 */  sd        $ra, -0x28($ra)
/* 6D009C 8021C02C 00000000 */  nop       
/* 6D00A0 8021C030 00000000 */  nop       
/* 6D00A4 8021C034 00000043 */  sra       $zero, $zero, 1
/* 6D00A8 8021C038 00000003 */  sra       $zero, $zero, 0
/* 6D00AC 8021C03C 8026B654 */  lb        $a2, -0x49ac($at)
/* 6D00B0 8021C040 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D00B4 8021C044 F24ABA80 */  scd       $t2, -0x4580($s2)
/* 6D00B8 8021C048 00000043 */  sra       $zero, $zero, 1
/* 6D00BC 8021C04C 00000004 */  sllv      $zero, $zero, $zero
/* 6D00C0 8021C050 80279E64 */  lb        $a3, -0x619c($at)
/* 6D00C4 8021C054 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D00C8 8021C058 00000000 */  nop       
/* 6D00CC 8021C05C 00000000 */  nop       
/* 6D00D0 8021C060 00000043 */  sra       $zero, $zero, 1
/* 6D00D4 8021C064 00000002 */  srl       $zero, $zero, 0
/* 6D00D8 8021C068 80269E28 */  lb        $a2, -0x61d8($at)
/* 6D00DC 8021C06C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D00E0 8021C070 0000000A */  movz      $zero, $zero, $zero
/* 6D00E4 8021C074 00000002 */  srl       $zero, $zero, 0
/* 6D00E8 8021C078 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D00EC 8021C07C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D00F0 8021C080 00000043 */  sra       $zero, $zero, 1
/* 6D00F4 8021C084 00000002 */  srl       $zero, $zero, 0
/* 6D00F8 8021C088 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D00FC 8021C08C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0100 8021C090 00000043 */  sra       $zero, $zero, 1
/* 6D0104 8021C094 00000002 */  srl       $zero, $zero, 0
/* 6D0108 8021C098 8024EC6C */  lb        $a0, -0x1394($at)
/* 6D010C 8021C09C 0000012C */  .byte     0x00, 0x00, 0x01, 0x2c
/* 6D0110 8021C0A0 00000043 */  sra       $zero, $zero, 1
/* 6D0114 8021C0A4 00000002 */  srl       $zero, $zero, 0
/* 6D0118 8021C0A8 8024EA58 */  lb        $a0, -0x15a8($at)
/* 6D011C 8021C0AC 00000014 */  dsllv     $zero, $zero, $zero
/* 6D0120 8021C0B0 00000043 */  sra       $zero, $zero, 1
/* 6D0124 8021C0B4 00000002 */  srl       $zero, $zero, 0
/* 6D0128 8021C0B8 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6D012C 8021C0BC 0000000A */  movz      $zero, $zero, $zero
/* 6D0130 8021C0C0 00000043 */  sra       $zero, $zero, 1
/* 6D0134 8021C0C4 00000004 */  sllv      $zero, $zero, $zero
/* 6D0138 8021C0C8 8024ECF8 */  lb        $a0, -0x1308($at)
/* 6D013C 8021C0CC FFFFFFFF */  sd        $ra, -1($ra)
/* 6D0140 8021C0D0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0144 8021C0D4 00000000 */  nop       
/* 6D0148 8021C0D8 00000013 */  mtlo      $zero
/* 6D014C 8021C0DC 00000000 */  nop       
/* 6D0150 8021C0E0 0000000A */  movz      $zero, $zero, $zero
/* 6D0154 8021C0E4 00000002 */  srl       $zero, $zero, 0
/* 6D0158 8021C0E8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D015C 8021C0EC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0160 8021C0F0 00000043 */  sra       $zero, $zero, 1
/* 6D0164 8021C0F4 00000007 */  srav      $zero, $zero, $zero
/* 6D0168 8021C0F8 8027CFB8 */  lb        $a3, -0x3048($at)
/* 6D016C 8021C0FC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0170 8021C100 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D0174 8021C104 80000000 */  lb        $zero, ($zero)
/* 6D0178 8021C108 00000000 */  nop       
/* 6D017C 8021C10C 00000000 */  nop       
/* 6D0180 8021C110 00000000 */  nop       
/* 6D0184 8021C114 00000013 */  mtlo      $zero
/* 6D0188 8021C118 00000000 */  nop       
/* 6D018C 8021C11C 00000043 */  sra       $zero, $zero, 1
/* 6D0190 8021C120 00000004 */  sllv      $zero, $zero, $zero
/* 6D0194 8021C124 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D0198 8021C128 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D019C 8021C12C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D01A0 8021C130 00590008 */  .byte     0x00, 0x59, 0x00, 0x08
/* 6D01A4 8021C134 00000008 */  jr        $zero
/* 6D01A8 8021C138 00000001 */   movf     $zero, $zero, $fcc0
/* 6D01AC 8021C13C 00000008 */  jr        $zero
/* 6D01B0 8021C140 00000043 */   sra      $zero, $zero, 1
/* 6D01B4 8021C144 00000002 */  srl       $zero, $zero, 0
/* 6D01B8 8021C148 8026F6EC */  lb        $a2, -0x914($at)
/* 6D01BC 8021C14C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D01C0 8021C150 00000043 */  sra       $zero, $zero, 1
/* 6D01C4 8021C154 00000003 */  sra       $zero, $zero, 0
/* 6D01C8 8021C158 8026B358 */  lb        $a2, -0x4ca8($at)
/* 6D01CC 8021C15C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D01D0 8021C160 000000B4 */  teq       $zero, $zero, 2
/* 6D01D4 8021C164 00000008 */  jr        $zero
/* 6D01D8 8021C168 00000001 */   movf     $zero, $zero, $fcc0
/* 6D01DC 8021C16C 00000004 */  sllv      $zero, $zero, $zero
/* 6D01E0 8021C170 00000043 */  sra       $zero, $zero, 1
/* 6D01E4 8021C174 00000004 */  sllv      $zero, $zero, $zero
/* 6D01E8 8021C178 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D01EC 8021C17C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D01F0 8021C180 00000001 */  movf      $zero, $zero, $fcc0
/* 6D01F4 8021C184 00590016 */  dsrlv     $zero, $t9, $v0
/* 6D01F8 8021C188 00000008 */  jr        $zero
/* 6D01FC 8021C18C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D0200 8021C190 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0204 8021C194 00000043 */  sra       $zero, $zero, 1
/* 6D0208 8021C198 00000004 */  sllv      $zero, $zero, $zero
/* 6D020C 8021C19C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D0210 8021C1A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0214 8021C1A4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0218 8021C1A8 00590016 */  dsrlv     $zero, $t9, $v0
/* 6D021C 8021C1AC 00000043 */  sra       $zero, $zero, 1
/* 6D0220 8021C1B0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0224 8021C1B4 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D0228 8021C1B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D022C 8021C1BC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D0230 8021C1C0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D0234 8021C1C4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D0238 8021C1C8 00000027 */  not       $zero, $zero
/* 6D023C 8021C1CC 00000002 */  srl       $zero, $zero, 0
/* 6D0240 8021C1D0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D0244 8021C1D4 00000014 */  dsllv     $zero, $zero, $zero
/* 6D0248 8021C1D8 00000043 */  sra       $zero, $zero, 1
/* 6D024C 8021C1DC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0250 8021C1E0 8026A510 */  lb        $a2, -0x5af0($at)
/* 6D0254 8021C1E4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0258 8021C1E8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D025C 8021C1EC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D0260 8021C1F0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D0264 8021C1F4 00000043 */  sra       $zero, $zero, 1
/* 6D0268 8021C1F8 00000003 */  sra       $zero, $zero, 0
/* 6D026C 8021C1FC 8026B55C */  lb        $a2, -0x4aa4($at)
/* 6D0270 8021C200 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0274 8021C204 F24A8280 */  scd       $t2, -0x7d80($s2)
/* 6D0278 8021C208 00000043 */  sra       $zero, $zero, 1
/* 6D027C 8021C20C 00000006 */  srlv      $zero, $zero, $zero
/* 6D0280 8021C210 80278D08 */  lb        $a3, -0x72f8($at)
/* 6D0284 8021C214 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0288 8021C218 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D028C 8021C21C 00000000 */  nop       
/* 6D0290 8021C220 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0294 8021C224 00000000 */  nop       
/* 6D0298 8021C228 00000043 */  sra       $zero, $zero, 1
/* 6D029C 8021C22C 00000004 */  sllv      $zero, $zero, $zero
/* 6D02A0 8021C230 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D02A4 8021C234 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D02A8 8021C238 00000001 */  movf      $zero, $zero, $fcc0
/* 6D02AC 8021C23C 00590016 */  dsrlv     $zero, $t9, $v0
/* 6D02B0 8021C240 00000008 */  jr        $zero
/* 6D02B4 8021C244 00000001 */   movf     $zero, $zero, $fcc0
/* 6D02B8 8021C248 00000006 */  srlv      $zero, $zero, $zero
/* 6D02BC 8021C24C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D02C0 8021C250 00000002 */  srl       $zero, $zero, 0
/* 6D02C4 8021C254 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D02C8 8021C258 00000014 */  dsllv     $zero, $zero, $zero
/* 6D02CC 8021C25C 00000043 */  sra       $zero, $zero, 1
/* 6D02D0 8021C260 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D02D4 8021C264 8026A510 */  lb        $a2, -0x5af0($at)
/* 6D02D8 8021C268 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D02DC 8021C26C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D02E0 8021C270 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D02E4 8021C274 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D02E8 8021C278 00000043 */  sra       $zero, $zero, 1
/* 6D02EC 8021C27C 00000006 */  srlv      $zero, $zero, $zero
/* 6D02F0 8021C280 80278D08 */  lb        $a3, -0x72f8($at)
/* 6D02F4 8021C284 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D02F8 8021C288 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D02FC 8021C28C 00000000 */  nop       
/* 6D0300 8021C290 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0304 8021C294 00000000 */  nop       
/* 6D0308 8021C298 00000043 */  sra       $zero, $zero, 1
/* 6D030C 8021C29C 00000002 */  srl       $zero, $zero, 0
/* 6D0310 8021C2A0 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D0314 8021C2A4 00000002 */  srl       $zero, $zero, 0
/* 6D0318 8021C2A8 00000043 */  sra       $zero, $zero, 1
/* 6D031C 8021C2AC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0320 8021C2B0 8027D7F0 */  lb        $a3, -0x2810($at)
/* 6D0324 8021C2B4 00000043 */  sra       $zero, $zero, 1
/* 6D0328 8021C2B8 00000003 */  sra       $zero, $zero, 0
/* 6D032C 8021C2BC 8026B358 */  lb        $a2, -0x4ca8($at)
/* 6D0330 8021C2C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0334 8021C2C4 000000B4 */  teq       $zero, $zero, 2
/* 6D0338 8021C2C8 00000043 */  sra       $zero, $zero, 1
/* 6D033C 8021C2CC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0340 8021C2D0 8026EE88 */  lb        $a2, -0x1178($at)
/* 6D0344 8021C2D4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0348 8021C2D8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D034C 8021C2DC 00000000 */  nop       
/* 6D0350 8021C2E0 00000002 */  srl       $zero, $zero, 0
/* 6D0354 8021C2E4 00000043 */  sra       $zero, $zero, 1
/* 6D0358 8021C2E8 00000004 */  sllv      $zero, $zero, $zero
/* 6D035C 8021C2EC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D0360 8021C2F0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0364 8021C2F4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0368 8021C2F8 00590016 */  dsrlv     $zero, $t9, $v0
/* 6D036C 8021C2FC 00000043 */  sra       $zero, $zero, 1
/* 6D0370 8021C300 00000002 */  srl       $zero, $zero, 0
/* 6D0374 8021C304 80269EC4 */  lb        $a2, -0x613c($at)
/* 6D0378 8021C308 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D037C 8021C30C 00000043 */  sra       $zero, $zero, 1
/* 6D0380 8021C310 00000003 */  sra       $zero, $zero, 0
/* 6D0384 8021C314 8026B654 */  lb        $a2, -0x49ac($at)
/* 6D0388 8021C318 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D038C 8021C31C F24A9A80 */  scd       $t2, -0x6580($s2)
/* 6D0390 8021C320 00000043 */  sra       $zero, $zero, 1
/* 6D0394 8021C324 00000004 */  sllv      $zero, $zero, $zero
/* 6D0398 8021C328 80279E64 */  lb        $a3, -0x619c($at)
/* 6D039C 8021C32C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D03A0 8021C330 00000000 */  nop       
/* 6D03A4 8021C334 00000000 */  nop       
/* 6D03A8 8021C338 00000043 */  sra       $zero, $zero, 1
/* 6D03AC 8021C33C 00000004 */  sllv      $zero, $zero, $zero
/* 6D03B0 8021C340 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D03B4 8021C344 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D03B8 8021C348 00000001 */  movf      $zero, $zero, $fcc0
/* 6D03BC 8021C34C 00590001 */  movt      $zero, $v0, $fcc6
/* 6D03C0 8021C350 00000043 */  sra       $zero, $zero, 1
/* 6D03C4 8021C354 00000004 */  sllv      $zero, $zero, $zero
/* 6D03C8 8021C358 8026EF4C */  lb        $a2, -0x10b4($at)
/* 6D03CC 8021C35C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D03D0 8021C360 00000001 */  movf      $zero, $zero, $fcc0
/* 6D03D4 8021C364 00000000 */  nop       
/* 6D03D8 8021C368 00000043 */  sra       $zero, $zero, 1
/* 6D03DC 8021C36C 00000004 */  sllv      $zero, $zero, $zero
/* 6D03E0 8021C370 8026B438 */  lb        $a2, -0x4bc8($at)
/* 6D03E4 8021C374 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D03E8 8021C378 00000001 */  movf      $zero, $zero, $fcc0
/* 6D03EC 8021C37C 00000000 */  nop       
/* 6D03F0 8021C380 00000043 */  sra       $zero, $zero, 1
/* 6D03F4 8021C384 00000003 */  sra       $zero, $zero, 0
/* 6D03F8 8021C388 8026B358 */  lb        $a2, -0x4ca8($at)
/* 6D03FC 8021C38C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0400 8021C390 00000000 */  nop       
/* 6D0404 8021C394 00000043 */  sra       $zero, $zero, 1
/* 6D0408 8021C398 00000003 */  sra       $zero, $zero, 0
/* 6D040C 8021C39C 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D0410 8021C3A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0414 8021C3A4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0418 8021C3A8 00000043 */  sra       $zero, $zero, 1
/* 6D041C 8021C3AC 00000003 */  sra       $zero, $zero, 0
/* 6D0420 8021C3B0 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D0424 8021C3B4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0428 8021C3B8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D042C 8021C3BC 00000002 */  srl       $zero, $zero, 0
/* 6D0430 8021C3C0 00000000 */  nop       
/* 6D0434 8021C3C4 00000020 */  add       $zero, $zero, $zero
/* 6D0438 8021C3C8 00000000 */  nop       
/* 6D043C 8021C3CC 00000023 */  negu      $zero, $zero
/* 6D0440 8021C3D0 00000000 */  nop       
/* 6D0444 8021C3D4 00000043 */  sra       $zero, $zero, 1
/* 6D0448 8021C3D8 00000002 */  srl       $zero, $zero, 0
/* 6D044C 8021C3DC 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 6D0450 8021C3E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0454 8021C3E4 00000043 */  sra       $zero, $zero, 1
/* 6D0458 8021C3E8 00000003 */  sra       $zero, $zero, 0
/* 6D045C 8021C3EC 8026B654 */  lb        $a2, -0x49ac($at)
/* 6D0460 8021C3F0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0464 8021C3F4 F24ABA80 */  scd       $t2, -0x4580($s2)
/* 6D0468 8021C3F8 00000043 */  sra       $zero, $zero, 1
/* 6D046C 8021C3FC 00000004 */  sllv      $zero, $zero, $zero
/* 6D0470 8021C400 80279E64 */  lb        $a3, -0x619c($at)
/* 6D0474 8021C404 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0478 8021C408 00000000 */  nop       
/* 6D047C 8021C40C 00000000 */  nop       
/* 6D0480 8021C410 00000043 */  sra       $zero, $zero, 1
/* 6D0484 8021C414 00000002 */  srl       $zero, $zero, 0
/* 6D0488 8021C418 8026F6EC */  lb        $a2, -0x914($at)
/* 6D048C 8021C41C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0490 8021C420 00000008 */  jr        $zero
.L8021C424:
/* 6D0494 8021C424 00000001 */   movf     $zero, $zero, $fcc0
/* 6D0498 8021C428 00000002 */  srl       $zero, $zero, 0
/* 6D049C 8021C42C 00000043 */  sra       $zero, $zero, 1
/* 6D04A0 8021C430 00000008 */  jr        $zero
/* 6D04A4 8021C434 8027CCB4 */   lb       $a3, -0x334c($at)
/* 6D04A8 8021C438 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D04AC 8021C43C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D04B0 8021C440 00000000 */  nop       
/* 6D04B4 8021C444 0000FFFF */  dsra32    $ra, $zero, 0x1f
/* 6D04B8 8021C448 00000000 */  nop       
/* 6D04BC 8021C44C 00000004 */  sllv      $zero, $zero, $zero
/* 6D04C0 8021C450 00000020 */  add       $zero, $zero, $zero
/* 6D04C4 8021C454 00000014 */  dsllv     $zero, $zero, $zero
/* 6D04C8 8021C458 00000001 */  movf      $zero, $zero, $fcc0
/* 6D04CC 8021C45C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D04D0 8021C460 0000001D */  dmultu    $zero, $zero
/* 6D04D4 8021C464 00000001 */  movf      $zero, $zero, $fcc0
/* 6D04D8 8021C468 00000000 */  nop       
/* 6D04DC 8021C46C 0000001D */  dmultu    $zero, $zero
/* 6D04E0 8021C470 00000001 */  movf      $zero, $zero, $fcc0
/* 6D04E4 8021C474 00000002 */  srl       $zero, $zero, 0
/* 6D04E8 8021C478 00000043 */  sra       $zero, $zero, 1
/* 6D04EC 8021C47C 00000002 */  srl       $zero, $zero, 0
/* 6D04F0 8021C480 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D04F4 8021C484 00000002 */  srl       $zero, $zero, 0
/* 6D04F8 8021C488 00000043 */  sra       $zero, $zero, 1
/* 6D04FC 8021C48C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0500 8021C490 8026A820 */  lb        $a2, -0x57e0($at)
/* 6D0504 8021C494 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0508 8021C498 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D050C 8021C49C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D0510 8021C4A0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D0514 8021C4A4 00000027 */  not       $zero, $zero
/* 6D0518 8021C4A8 00000002 */  srl       $zero, $zero, 0
/* 6D051C 8021C4AC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D0520 8021C4B0 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D0524 8021C4B4 00000024 */  and       $zero, $zero, $zero
/* 6D0528 8021C4B8 00000002 */  srl       $zero, $zero, 0
/* 6D052C 8021C4BC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D0530 8021C4C0 00000000 */  nop       
/* 6D0534 8021C4C4 00000043 */  sra       $zero, $zero, 1
/* 6D0538 8021C4C8 00000003 */  sra       $zero, $zero, 0
/* 6D053C 8021C4CC 8026B55C */  lb        $a2, -0x4aa4($at)
/* 6D0540 8021C4D0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0544 8021C4D4 F24A81B4 */  scd       $t2, -0x7e4c($s2)
/* 6D0548 8021C4D8 00000043 */  sra       $zero, $zero, 1
/* 6D054C 8021C4DC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0550 8021C4E0 8026A510 */  lb        $a2, -0x5af0($at)
/* 6D0554 8021C4E4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0558 8021C4E8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D055C 8021C4EC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D0560 8021C4F0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D0564 8021C4F4 00000043 */  sra       $zero, $zero, 1
/* 6D0568 8021C4F8 00000006 */  srlv      $zero, $zero, $zero
/* 6D056C 8021C4FC 80278D08 */  lb        $a3, -0x72f8($at)
/* 6D0570 8021C500 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0574 8021C504 0000000A */  movz      $zero, $zero, $zero
/* 6D0578 8021C508 00000000 */  nop       
/* 6D057C 8021C50C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0580 8021C510 00000000 */  nop       
/* 6D0584 8021C514 00000027 */  not       $zero, $zero
/* 6D0588 8021C518 00000002 */  srl       $zero, $zero, 0
/* 6D058C 8021C51C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D0590 8021C520 0000001E */  ddiv      $zero, $zero, $zero
/* 6D0594 8021C524 00000043 */  sra       $zero, $zero, 1
/* 6D0598 8021C528 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D059C 8021C52C 8026A510 */  lb        $a2, -0x5af0($at)
/* 6D05A0 8021C530 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D05A4 8021C534 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D05A8 8021C538 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D05AC 8021C53C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D05B0 8021C540 00000043 */  sra       $zero, $zero, 1
/* 6D05B4 8021C544 00000006 */  srlv      $zero, $zero, $zero
/* 6D05B8 8021C548 80278D08 */  lb        $a3, -0x72f8($at)
/* 6D05BC 8021C54C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D05C0 8021C550 00000008 */  jr        $zero
/* 6D05C4 8021C554 00000000 */   nop      
/* 6D05C8 8021C558 00000001 */  movf      $zero, $zero, $fcc0
/* 6D05CC 8021C55C 00000000 */  nop       
/* 6D05D0 8021C560 00000027 */  not       $zero, $zero
/* 6D05D4 8021C564 00000002 */  srl       $zero, $zero, 0
/* 6D05D8 8021C568 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D05DC 8021C56C 00000014 */  dsllv     $zero, $zero, $zero
/* 6D05E0 8021C570 00000043 */  sra       $zero, $zero, 1
/* 6D05E4 8021C574 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D05E8 8021C578 8026A510 */  lb        $a2, -0x5af0($at)
.L8021C57C:
/* 6D05EC 8021C57C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D05F0 8021C580 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D05F4 8021C584 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D05F8 8021C588 FE363C82 */  sd        $s6, 0x3c82($s1)
.L8021C58C:
/* 6D05FC 8021C58C 00000043 */  sra       $zero, $zero, 1
/* 6D0600 8021C590 00000006 */  srlv      $zero, $zero, $zero
/* 6D0604 8021C594 80278D08 */  lb        $a3, -0x72f8($at)
/* 6D0608 8021C598 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D060C 8021C59C 00000006 */  srlv      $zero, $zero, $zero
/* 6D0610 8021C5A0 00000000 */  nop       
/* 6D0614 8021C5A4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0618 8021C5A8 00000000 */  nop       
/* 6D061C 8021C5AC 00000043 */  sra       $zero, $zero, 1
/* 6D0620 8021C5B0 00000004 */  sllv      $zero, $zero, $zero
/* 6D0624 8021C5B4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D0628 8021C5B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D062C 8021C5BC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0630 8021C5C0 00590008 */  .byte     0x00, 0x59, 0x00, 0x08
/* 6D0634 8021C5C4 00000008 */  jr        $zero
/* 6D0638 8021C5C8 00000001 */   movf     $zero, $zero, $fcc0
/* 6D063C 8021C5CC 00000008 */  jr        $zero
/* 6D0640 8021C5D0 00000043 */   sra      $zero, $zero, 1
/* 6D0644 8021C5D4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0648 8021C5D8 8027D7F0 */  lb        $a3, -0x2810($at)
/* 6D064C 8021C5DC 00000025 */  or        $zero, $zero, $zero
/* 6D0650 8021C5E0 00000002 */  srl       $zero, $zero, 0
/* 6D0654 8021C5E4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D0658 8021C5E8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D065C 8021C5EC 00000025 */  or        $zero, $zero, $zero
/* 6D0660 8021C5F0 00000002 */  srl       $zero, $zero, 0
/* 6D0664 8021C5F4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D0668 8021C5F8 00590004 */  sllv      $zero, $t9, $v0
/* 6D066C 8021C5FC 00000046 */  rotrv     $zero, $zero, $zero
/* 6D0670 8021C600 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0674 8021C604 8029BEB8 */  lb        $t1, -0x4148($at)
/* 6D0678 8021C608 00000043 */  sra       $zero, $zero, 1
/* 6D067C 8021C60C 00000004 */  sllv      $zero, $zero, $zero
/* 6D0680 8021C610 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D0684 8021C614 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0688 8021C618 00000001 */  movf      $zero, $zero, $fcc0
/* 6D068C 8021C61C 00590001 */  movt      $zero, $v0, $fcc6
/* 6D0690 8021C620 00000020 */  add       $zero, $zero, $zero
/* 6D0694 8021C624 00000000 */  nop       
/* 6D0698 8021C628 00000023 */  negu      $zero, $zero
/* 6D069C 8021C62C 00000000 */  nop       
/* 6D06A0 8021C630 00000043 */  sra       $zero, $zero, 1
/* 6D06A4 8021C634 00000003 */  sra       $zero, $zero, 0
/* 6D06A8 8021C638 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D06AC 8021C63C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D06B0 8021C640 00000001 */  movf      $zero, $zero, $fcc0
/* 6D06B4 8021C644 00000043 */  sra       $zero, $zero, 1
/* 6D06B8 8021C648 00000003 */  sra       $zero, $zero, 0
/* 6D06BC 8021C64C 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D06C0 8021C650 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D06C4 8021C654 00000001 */  movf      $zero, $zero, $fcc0
/* 6D06C8 8021C658 00000002 */  srl       $zero, $zero, 0
/* 6D06CC 8021C65C 00000000 */  nop       
/* 6D06D0 8021C660 00000001 */  movf      $zero, $zero, $fcc0
/* 6D06D4 8021C664 00000000 */  nop       
/* 6D06D8 8021C668 00000043 */  sra       $zero, $zero, 1
/* 6D06DC 8021C66C 00000003 */  sra       $zero, $zero, 0
/* 6D06E0 8021C670 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D06E4 8021C674 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D06E8 8021C678 00000000 */  nop       
/* 6D06EC 8021C67C 00000043 */  sra       $zero, $zero, 1
/* 6D06F0 8021C680 00000003 */  sra       $zero, $zero, 0
/* 6D06F4 8021C684 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D06F8 8021C688 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D06FC 8021C68C 00000000 */  nop       
/* 6D0700 8021C690 00000043 */  sra       $zero, $zero, 1
/* 6D0704 8021C694 00000003 */  sra       $zero, $zero, 0
/* 6D0708 8021C698 8027C548 */  lb        $a3, -0x3ab8($at)
/* 6D070C 8021C69C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0710 8021C6A0 00000000 */  nop       
/* 6D0714 8021C6A4 00000043 */  sra       $zero, $zero, 1
/* 6D0718 8021C6A8 00000002 */  srl       $zero, $zero, 0
/* 6D071C 8021C6AC 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 6D0720 8021C6B0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0724 8021C6B4 00000043 */  sra       $zero, $zero, 1
/* 6D0728 8021C6B8 00000004 */  sllv      $zero, $zero, $zero
/* 6D072C 8021C6BC 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D0730 8021C6C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0734 8021C6C4 00000000 */  nop       
/* 6D0738 8021C6C8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D073C 8021C6CC 0000000A */  movz      $zero, $zero, $zero
/* 6D0740 8021C6D0 00000002 */  srl       $zero, $zero, 0
/* 6D0744 8021C6D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D0748 8021C6D8 00000000 */  nop       
/* 6D074C 8021C6DC 00000043 */  sra       $zero, $zero, 1
/* 6D0750 8021C6E0 00000002 */  srl       $zero, $zero, 0
/* 6D0754 8021C6E4 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D0758 8021C6E8 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D075C 8021C6EC 00000043 */  sra       $zero, $zero, 1
/* 6D0760 8021C6F0 00000002 */  srl       $zero, $zero, 0
/* 6D0764 8021C6F4 8024EB24 */  lb        $a0, -0x14dc($at)
/* 6D0768 8021C6F8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D076C 8021C6FC 00000043 */  sra       $zero, $zero, 1
/* 6D0770 8021C700 00000002 */  srl       $zero, $zero, 0
/* 6D0774 8021C704 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6D0778 8021C708 00000014 */  dsllv     $zero, $zero, $zero
/* 6D077C 8021C70C 00000043 */  sra       $zero, $zero, 1
/* 6D0780 8021C710 00000003 */  sra       $zero, $zero, 0
/* 6D0784 8021C714 8025385C */  lb        $a1, 0x385c($at)
/* 6D0788 8021C718 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D078C 8021C71C 000002D8 */  .byte     0x00, 0x00, 0x02, 0xd8
/* 6D0790 8021C720 00000043 */  sra       $zero, $zero, 1
/* 6D0794 8021C724 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0798 8021C728 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D079C 8021C72C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D07A0 8021C730 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D07A4 8021C734 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D07A8 8021C738 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D07AC 8021C73C 00000027 */  not       $zero, $zero
/* 6D07B0 8021C740 00000002 */  srl       $zero, $zero, 0
/* 6D07B4 8021C744 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D07B8 8021C748 0000000A */  movz      $zero, $zero, $zero
/* 6D07BC 8021C74C 00000043 */  sra       $zero, $zero, 1
/* 6D07C0 8021C750 0000000F */  sync      
/* 6D07C4 8021C754 802D829C */  lb        $t5, -0x7d64($at)
/* 6D07C8 8021C758 0000006B */  .byte     0x00, 0x00, 0x00, 0x6b
/* 6D07CC 8021C75C 00000006 */  srlv      $zero, $zero, $zero
/* 6D07D0 8021C760 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D07D4 8021C764 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D07D8 8021C768 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D07DC 8021C76C F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 6D07E0 8021C770 0000002D */  daddu     $zero, $zero, $zero
/* 6D07E4 8021C774 00000000 */  nop       
/* 6D07E8 8021C778 00000000 */  nop       
/* 6D07EC 8021C77C 00000000 */  nop       
/* 6D07F0 8021C780 00000000 */  nop       
/* 6D07F4 8021C784 00000000 */  nop       
/* 6D07F8 8021C788 00000000 */  nop       
/* 6D07FC 8021C78C 00000000 */  nop       
/* 6D0800 8021C790 00000043 */  sra       $zero, $zero, 1
/* 6D0804 8021C794 00000004 */  sllv      $zero, $zero, $zero
/* 6D0808 8021C798 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D080C 8021C79C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0810 8021C7A0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0814 8021C7A4 00590015 */  dlsa      $zero, $v0, $t9, 1
/* 6D0818 8021C7A8 00000008 */  jr        $zero
/* 6D081C 8021C7AC 00000001 */   movf     $zero, $zero, $fcc0
/* 6D0820 8021C7B0 0000001E */  ddiv      $zero, $zero, $zero
/* 6D0824 8021C7B4 00000043 */  sra       $zero, $zero, 1
/* 6D0828 8021C7B8 00000002 */  srl       $zero, $zero, 0
/* 6D082C 8021C7BC 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D0830 8021C7C0 00000002 */  srl       $zero, $zero, 0
/* 6D0834 8021C7C4 00000043 */  sra       $zero, $zero, 1
/* 6D0838 8021C7C8 00000002 */  srl       $zero, $zero, 0
/* 6D083C 8021C7CC 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6D0840 8021C7D0 00000014 */  dsllv     $zero, $zero, $zero
/* 6D0844 8021C7D4 00000056 */  drotrv    $zero, $zero, $zero
/* 6D0848 8021C7D8 00000000 */  nop       
/* 6D084C 8021C7DC 00000008 */  jr        $zero
/* 6D0850 8021C7E0 00000001 */   movf     $zero, $zero, $fcc0
/* 6D0854 8021C7E4 00000008 */  jr        $zero
/* 6D0858 8021C7E8 00000043 */   sra      $zero, $zero, 1
/* 6D085C 8021C7EC 00000004 */  sllv      $zero, $zero, $zero
/* 6D0860 8021C7F0 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D0864 8021C7F4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0868 8021C7F8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D086C 8021C7FC 00590007 */  srav      $zero, $t9, $v0
/* 6D0870 8021C800 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D0874 8021C804 00000000 */  nop       
/* 6D0878 8021C808 00000043 */  sra       $zero, $zero, 1
/* 6D087C 8021C80C 00000003 */  sra       $zero, $zero, 0
/* 6D0880 8021C810 8026B55C */  lb        $a2, -0x4aa4($at)
/* 6D0884 8021C814 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0888 8021C818 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 6D088C 8021C81C 00000043 */  sra       $zero, $zero, 1
/* 6D0890 8021C820 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0894 8021C824 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D0898 8021C828 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D089C 8021C82C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D08A0 8021C830 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D08A4 8021C834 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D08A8 8021C838 00000043 */  sra       $zero, $zero, 1
/* 6D08AC 8021C83C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D08B0 8021C840 8026A510 */  lb        $a2, -0x5af0($at)
/* 6D08B4 8021C844 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D08B8 8021C848 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D08BC 8021C84C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D08C0 8021C850 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D08C4 8021C854 00000043 */  sra       $zero, $zero, 1
/* 6D08C8 8021C858 00000006 */  srlv      $zero, $zero, $zero
/* 6D08CC 8021C85C 80278D08 */  lb        $a3, -0x72f8($at)
/* 6D08D0 8021C860 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D08D4 8021C864 00000010 */  mfhi      $zero
/* 6D08D8 8021C868 00000000 */  nop       
/* 6D08DC 8021C86C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D08E0 8021C870 00000000 */  nop       
/* 6D08E4 8021C874 00000043 */  sra       $zero, $zero, 1
/* 6D08E8 8021C878 00000003 */  sra       $zero, $zero, 0
/* 6D08EC 8021C87C 8025385C */  lb        $a1, 0x385c($at)
/* 6D08F0 8021C880 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D08F4 8021C884 000020BA */  dsrl      $a0, $zero, 2
/* 6D08F8 8021C888 00000043 */  sra       $zero, $zero, 1
/* 6D08FC 8021C88C 00000003 */  sra       $zero, $zero, 0
/* 6D0900 8021C890 802180EC */  lb        $at, -0x7f14($at)
/* 6D0904 8021C894 00000080 */  sll       $zero, $zero, 2
/* 6D0908 8021C898 0000000A */  movz      $zero, $zero, $zero
/* 6D090C 8021C89C 00000056 */  drotrv    $zero, $zero, $zero
/* 6D0910 8021C8A0 00000000 */  nop       
/* 6D0914 8021C8A4 00000043 */  sra       $zero, $zero, 1
/* 6D0918 8021C8A8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D091C 8021C8AC 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 6D0920 8021C8B0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0924 8021C8B4 00000000 */  nop       
/* 6D0928 8021C8B8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D092C 8021C8BC F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 6D0930 8021C8C0 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D0934 8021C8C4 00000000 */  nop       
/* 6D0938 8021C8C8 00000043 */  sra       $zero, $zero, 1
/* 6D093C 8021C8CC 00000004 */  sllv      $zero, $zero, $zero
/* 6D0940 8021C8D0 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D0944 8021C8D4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0948 8021C8D8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D094C 8021C8DC 00590006 */  srlv      $zero, $t9, $v0
/* 6D0950 8021C8E0 00000043 */  sra       $zero, $zero, 1
/* 6D0954 8021C8E4 00000003 */  sra       $zero, $zero, 0
/* 6D0958 8021C8E8 8027CB08 */  lb        $a3, -0x34f8($at)
/* 6D095C 8021C8EC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0960 8021C8F0 80219DE0 */  lb        $at, -0x6220($at)
/* 6D0964 8021C8F4 00000043 */  sra       $zero, $zero, 1
/* 6D0968 8021C8F8 00000004 */  sllv      $zero, $zero, $zero
/* 6D096C 8021C8FC 8027CA74 */  lb        $a3, -0x358c($at)
/* 6D0970 8021C900 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0974 8021C904 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0978 8021C908 80219D20 */  lb        $at, -0x62e0($at)
/* 6D097C 8021C90C 00000043 */  sra       $zero, $zero, 1
/* 6D0980 8021C910 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0984 8021C914 8026D3C8 */  lb        $a2, -0x2c38($at)
/* 6D0988 8021C918 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D098C 8021C91C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0990 8021C920 00001000 */  sll       $v0, $zero, 0
/* 6D0994 8021C924 00000000 */  nop       
/* 6D0998 8021C928 00000043 */  sra       $zero, $zero, 1
/* 6D099C 8021C92C 00000004 */  sllv      $zero, $zero, $zero
/* 6D09A0 8021C930 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D09A4 8021C934 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D09A8 8021C938 00000000 */  nop       
/* 6D09AC 8021C93C 00000002 */  srl       $zero, $zero, 0
/* 6D09B0 8021C940 00000043 */  sra       $zero, $zero, 1
/* 6D09B4 8021C944 00000004 */  sllv      $zero, $zero, $zero
/* 6D09B8 8021C948 8027CB7C */  lb        $a3, -0x3484($at)
/* 6D09BC 8021C94C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D09C0 8021C950 00000001 */  movf      $zero, $zero, $fcc0
/* 6D09C4 8021C954 80219CB4 */  lb        $at, -0x634c($at)
/* 6D09C8 8021C958 00000043 */  sra       $zero, $zero, 1
/* 6D09CC 8021C95C 00000003 */  sra       $zero, $zero, 0
/* 6D09D0 8021C960 8027DBA4 */  lb        $a3, -0x245c($at)
/* 6D09D4 8021C964 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D09D8 8021C968 00000001 */  movf      $zero, $zero, $fcc0
/* 6D09DC 8021C96C 00000043 */  sra       $zero, $zero, 1
/* 6D09E0 8021C970 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D09E4 8021C974 8026D3C8 */  lb        $a2, -0x2c38($at)
/* 6D09E8 8021C978 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D09EC 8021C97C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D09F0 8021C980 00400000 */  .byte     0x00, 0x40, 0x00, 0x00
/* 6D09F4 8021C984 00000001 */  movf      $zero, $zero, $fcc0
/* 6D09F8 8021C988 00000008 */  jr        $zero
/* 6D09FC 8021C98C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D0A00 8021C990 0000000A */  movz      $zero, $zero, $zero
/* 6D0A04 8021C994 00000043 */  sra       $zero, $zero, 1
/* 6D0A08 8021C998 00000003 */  sra       $zero, $zero, 0
/* 6D0A0C 8021C99C 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D0A10 8021C9A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0A14 8021C9A4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0A18 8021C9A8 00000043 */  sra       $zero, $zero, 1
/* 6D0A1C 8021C9AC 00000003 */  sra       $zero, $zero, 0
/* 6D0A20 8021C9B0 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D0A24 8021C9B4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0A28 8021C9B8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0A2C 8021C9BC 00000002 */  srl       $zero, $zero, 0
/* 6D0A30 8021C9C0 00000000 */  nop       
/* 6D0A34 8021C9C4 00000013 */  mtlo      $zero
/* 6D0A38 8021C9C8 00000000 */  nop       
/* 6D0A3C 8021C9CC 00000043 */  sra       $zero, $zero, 1
/* 6D0A40 8021C9D0 00000002 */  srl       $zero, $zero, 0
/* 6D0A44 8021C9D4 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D0A48 8021C9D8 0000003F */  dsra32    $zero, $zero, 0
/* 6D0A4C 8021C9DC 00000043 */  sra       $zero, $zero, 1
/* 6D0A50 8021C9E0 00000002 */  srl       $zero, $zero, 0
/* 6D0A54 8021C9E4 8024EB24 */  lb        $a0, -0x14dc($at)
/* 6D0A58 8021C9E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0A5C 8021C9EC 00000043 */  sra       $zero, $zero, 1
/* 6D0A60 8021C9F0 00000004 */  sllv      $zero, $zero, $zero
/* 6D0A64 8021C9F4 8024ECF8 */  lb        $a0, -0x1308($at)
/* 6D0A68 8021C9F8 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D0A6C 8021C9FC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0A70 8021CA00 00000000 */  nop       
/* 6D0A74 8021CA04 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0A78 8021CA08 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0A7C 8021CA0C 00000014 */  dsllv     $zero, $zero, $zero
/* 6D0A80 8021CA10 00000043 */  sra       $zero, $zero, 1
/* 6D0A84 8021CA14 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0A88 8021CA18 8026BA04 */  lb        $a2, -0x45fc($at)
/* 6D0A8C 8021CA1C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0A90 8021CA20 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0A94 8021CA24 00000000 */  nop       
/* 6D0A98 8021CA28 00000000 */  nop       
/* 6D0A9C 8021CA2C 00000008 */  jr        $zero
/* 6D0AA0 8021CA30 00000001 */   movf     $zero, $zero, $fcc0
/* 6D0AA4 8021CA34 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0AA8 8021CA38 00000043 */  sra       $zero, $zero, 1
/* 6D0AAC 8021CA3C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0AB0 8021CA40 8026BA04 */  lb        $a2, -0x45fc($at)
/* 6D0AB4 8021CA44 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0AB8 8021CA48 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D0ABC 8021CA4C 00000000 */  nop       
/* 6D0AC0 8021CA50 00000000 */  nop       
/* 6D0AC4 8021CA54 00000008 */  jr        $zero
/* 6D0AC8 8021CA58 00000001 */   movf     $zero, $zero, $fcc0
/* 6D0ACC 8021CA5C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0AD0 8021CA60 00000006 */  srlv      $zero, $zero, $zero
/* 6D0AD4 8021CA64 00000000 */  nop       
/* 6D0AD8 8021CA68 00000043 */  sra       $zero, $zero, 1
/* 6D0ADC 8021CA6C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0AE0 8021CA70 8026BA04 */  lb        $a2, -0x45fc($at)
/* 6D0AE4 8021CA74 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0AE8 8021CA78 00000000 */  nop       
/* 6D0AEC 8021CA7C 00000000 */  nop       
/* 6D0AF0 8021CA80 00000000 */  nop       
/* 6D0AF4 8021CA84 00000043 */  sra       $zero, $zero, 1
/* 6D0AF8 8021CA88 00000003 */  sra       $zero, $zero, 0
/* 6D0AFC 8021CA8C 8025385C */  lb        $a1, 0x385c($at)
/* 6D0B00 8021CA90 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0B04 8021CA94 0000037C */  dsll32    $zero, $zero, 0xd
/* 6D0B08 8021CA98 00000043 */  sra       $zero, $zero, 1
/* 6D0B0C 8021CA9C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0B10 8021CAA0 8026F740 */  lb        $a2, -0x8c0($at)
/* 6D0B14 8021CAA4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0B18 8021CAA8 00000000 */  nop       
/* 6D0B1C 8021CAAC 00000000 */  nop       
/* 6D0B20 8021CAB0 00000000 */  nop       
/* 6D0B24 8021CAB4 00000043 */  sra       $zero, $zero, 1
/* 6D0B28 8021CAB8 00000007 */  srav      $zero, $zero, $zero
/* 6D0B2C 8021CABC 8027CFB8 */  lb        $a3, -0x3048($at)
/* 6D0B30 8021CAC0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0B34 8021CAC4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D0B38 8021CAC8 00000000 */  nop       
/* 6D0B3C 8021CACC 00000000 */  nop       
/* 6D0B40 8021CAD0 00000004 */  sllv      $zero, $zero, $zero
/* 6D0B44 8021CAD4 00000010 */  mfhi      $zero
/* 6D0B48 8021CAD8 00000014 */  dsllv     $zero, $zero, $zero
/* 6D0B4C 8021CADC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0B50 8021CAE0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D0B54 8021CAE4 0000001D */  dmultu    $zero, $zero
/* 6D0B58 8021CAE8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0B5C 8021CAEC 00000006 */  srlv      $zero, $zero, $zero
/* 6D0B60 8021CAF0 0000001D */  dmultu    $zero, $zero
/* 6D0B64 8021CAF4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0B68 8021CAF8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0B6C 8021CAFC 00000024 */  and       $zero, $zero, $zero
/* 6D0B70 8021CB00 00000002 */  srl       $zero, $zero, 0
/* 6D0B74 8021CB04 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D0B78 8021CB08 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D0B7C 8021CB0C 00000056 */  drotrv    $zero, $zero, $zero
/* 6D0B80 8021CB10 00000000 */  nop       
/* 6D0B84 8021CB14 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0B88 8021CB18 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0B8C 8021CB1C 00000000 */  nop       
/* 6D0B90 8021CB20 00000043 */  sra       $zero, $zero, 1
/* 6D0B94 8021CB24 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0B98 8021CB28 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D0B9C 8021CB2C 00000000 */  nop       
/* 6D0BA0 8021CB30 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D0BA4 8021CB34 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D0BA8 8021CB38 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D0BAC 8021CB3C 00000027 */  not       $zero, $zero
/* 6D0BB0 8021CB40 00000002 */  srl       $zero, $zero, 0
/* 6D0BB4 8021CB44 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D0BB8 8021CB48 0000001E */  ddiv      $zero, $zero, $zero
/* 6D0BBC 8021CB4C 00000043 */  sra       $zero, $zero, 1
/* 6D0BC0 8021CB50 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0BC4 8021CB54 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D0BC8 8021CB58 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0BCC 8021CB5C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D0BD0 8021CB60 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D0BD4 8021CB64 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6D0BD8 8021CB68 0000000D */  break     
.L8021CB6C:
/* 6D0BDC 8021CB6C 00000002 */   srl      $zero, $zero, 0
/* 6D0BE0 8021CB70 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D0BE4 8021CB74 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D0BE8 8021CB78 00000007 */  srav      $zero, $zero, $zero
/* 6D0BEC 8021CB7C 00000000 */  nop       
/* 6D0BF0 8021CB80 00000013 */  mtlo      $zero
/* 6D0BF4 8021CB84 00000000 */  nop       
/* 6D0BF8 8021CB88 00000008 */  jr        $zero
/* 6D0BFC 8021CB8C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D0C00 8021CB90 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0C04 8021CB94 00000006 */  srlv      $zero, $zero, $zero
/* 6D0C08 8021CB98 00000000 */  nop       
/* 6D0C0C 8021CB9C 00000043 */  sra       $zero, $zero, 1
/* 6D0C10 8021CBA0 00000002 */  srl       $zero, $zero, 0
/* 6D0C14 8021CBA4 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D0C18 8021CBA8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0C1C 8021CBAC 0000000A */  movz      $zero, $zero, $zero
/* 6D0C20 8021CBB0 00000002 */  srl       $zero, $zero, 0
/* 6D0C24 8021CBB4 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D0C28 8021CBB8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0C2C 8021CBBC 00000043 */  sra       $zero, $zero, 1
/* 6D0C30 8021CBC0 00000007 */  srav      $zero, $zero, $zero
/* 6D0C34 8021CBC4 8027CFB8 */  lb        $a3, -0x3048($at)
/* 6D0C38 8021CBC8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0C3C 8021CBCC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D0C40 8021CBD0 80000000 */  lb        $zero, ($zero)
/* 6D0C44 8021CBD4 00000000 */  nop       
/* 6D0C48 8021CBD8 00000000 */  nop       
/* 6D0C4C 8021CBDC 00000000 */  nop       
/* 6D0C50 8021CBE0 00000013 */  mtlo      $zero
/* 6D0C54 8021CBE4 00000000 */  nop       
/* 6D0C58 8021CBE8 00000008 */  jr        $zero
/* 6D0C5C 8021CBEC 00000001 */   movf     $zero, $zero, $fcc0
/* 6D0C60 8021CBF0 0000000F */  sync      
/* 6D0C64 8021CBF4 00000043 */  sra       $zero, $zero, 1
/* 6D0C68 8021CBF8 00000002 */  srl       $zero, $zero, 0
/* 6D0C6C 8021CBFC 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D0C70 8021CC00 00000002 */  srl       $zero, $zero, 0
/* 6D0C74 8021CC04 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D0C78 8021CC08 00000000 */  nop       
/* 6D0C7C 8021CC0C 00000056 */  drotrv    $zero, $zero, $zero
/* 6D0C80 8021CC10 00000000 */  nop       
/* 6D0C84 8021CC14 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0C88 8021CC18 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0C8C 8021CC1C 0000001E */  ddiv      $zero, $zero, $zero
/* 6D0C90 8021CC20 00000043 */  sra       $zero, $zero, 1
/* 6D0C94 8021CC24 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0C98 8021CC28 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D0C9C 8021CC2C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0CA0 8021CC30 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D0CA4 8021CC34 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D0CA8 8021CC38 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D0CAC 8021CC3C 00000043 */  sra       $zero, $zero, 1
/* 6D0CB0 8021CC40 0000000F */  sync      
/* 6D0CB4 8021CC44 802D829C */  lb        $t5, -0x7d64($at)
/* 6D0CB8 8021CC48 00000007 */  srav      $zero, $zero, $zero
/* 6D0CBC 8021CC4C 00000002 */  srl       $zero, $zero, 0
/* 6D0CC0 8021CC50 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D0CC4 8021CC54 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D0CC8 8021CC58 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D0CCC 8021CC5C 00000000 */  nop       
/* 6D0CD0 8021CC60 00000000 */  nop       
/* 6D0CD4 8021CC64 00000000 */  nop       
/* 6D0CD8 8021CC68 00000000 */  nop       
/* 6D0CDC 8021CC6C 00000000 */  nop       
/* 6D0CE0 8021CC70 00000000 */  nop       
/* 6D0CE4 8021CC74 00000000 */  nop       
/* 6D0CE8 8021CC78 00000000 */  nop       
/* 6D0CEC 8021CC7C 00000000 */  nop       
/* 6D0CF0 8021CC80 00000008 */  jr        $zero
/* 6D0CF4 8021CC84 00000001 */   movf     $zero, $zero, $fcc0
/* 6D0CF8 8021CC88 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0CFC 8021CC8C 00000006 */  srlv      $zero, $zero, $zero
/* 6D0D00 8021CC90 00000000 */  nop       
/* 6D0D04 8021CC94 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D0D08 8021CC98 00000000 */  nop       
/* 6D0D0C 8021CC9C 00000043 */  sra       $zero, $zero, 1
/* 6D0D10 8021CCA0 00000002 */  srl       $zero, $zero, 0
/* 6D0D14 8021CCA4 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 6D0D18 8021CCA8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0D1C 8021CCAC 00000043 */  sra       $zero, $zero, 1
/* 6D0D20 8021CCB0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0D24 8021CCB4 8026A748 */  lb        $a2, -0x58b8($at)
/* 6D0D28 8021CCB8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0D2C 8021CCBC FFFFFF38 */  sd        $ra, -0xc8($ra)
/* 6D0D30 8021CCC0 00000000 */  nop       
.L8021CCC4:
/* 6D0D34 8021CCC4 00000000 */  nop       
/* 6D0D38 8021CCC8 00000043 */  sra       $zero, $zero, 1
/* 6D0D3C 8021CCCC 00000003 */  sra       $zero, $zero, 0
/* 6D0D40 8021CCD0 8026B654 */  lb        $a2, -0x49ac($at)
.L8021CCD4:
/* 6D0D44 8021CCD4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0D48 8021CCD8 F24ABA80 */  scd       $t2, -0x4580($s2)
/* 6D0D4C 8021CCDC 00000043 */  sra       $zero, $zero, 1
/* 6D0D50 8021CCE0 00000004 */  sllv      $zero, $zero, $zero
/* 6D0D54 8021CCE4 80279E64 */  lb        $a3, -0x619c($at)
/* 6D0D58 8021CCE8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0D5C 8021CCEC 00000000 */  nop       
/* 6D0D60 8021CCF0 00000000 */  nop       
/* 6D0D64 8021CCF4 00000008 */  jr        $zero
/* 6D0D68 8021CCF8 00000001 */   movf     $zero, $zero, $fcc0
/* 6D0D6C 8021CCFC 0000000F */  sync      
/* 6D0D70 8021CD00 00000043 */  sra       $zero, $zero, 1
/* 6D0D74 8021CD04 00000003 */  sra       $zero, $zero, 0
/* 6D0D78 8021CD08 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D0D7C 8021CD0C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0D80 8021CD10 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D0D84 8021CD14 00000011 */  mthi      $zero
/* 6D0D88 8021CD18 00000002 */  srl       $zero, $zero, 0
/* 6D0D8C 8021CD1C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D0D90 8021CD20 18000000 */  blez      $zero, .L8021CD24
.L8021CD24:
/* 6D0D94 8021CD24 00000043 */   sra      $zero, $zero, 1
/* 6D0D98 8021CD28 00000003 */  sra       $zero, $zero, 0
/* 6D0D9C 8021CD2C 8027DBA4 */  lb        $a3, -0x245c($at)
/* 6D0DA0 8021CD30 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0DA4 8021CD34 00000000 */  nop       
/* 6D0DA8 8021CD38 00000013 */  mtlo      $zero
/* 6D0DAC 8021CD3C 00000000 */  nop       
/* 6D0DB0 8021CD40 00000043 */  sra       $zero, $zero, 1
/* 6D0DB4 8021CD44 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0DB8 8021CD48 8026D3C8 */  lb        $a2, -0x2c38($at)
/* 6D0DBC 8021CD4C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0DC0 8021CD50 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0DC4 8021CD54 00400000 */  .byte     0x00, 0x40, 0x00, 0x00
/* 6D0DC8 8021CD58 00000000 */  nop       
/* 6D0DCC 8021CD5C 00000043 */  sra       $zero, $zero, 1
/* 6D0DD0 8021CD60 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0DD4 8021CD64 8027D7F0 */  lb        $a3, -0x2810($at)
/* 6D0DD8 8021CD68 00000043 */  sra       $zero, $zero, 1
/* 6D0DDC 8021CD6C 00000002 */  srl       $zero, $zero, 0
/* 6D0DE0 8021CD70 8026F6EC */  lb        $a2, -0x914($at)
/* 6D0DE4 8021CD74 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0DE8 8021CD78 00000043 */  sra       $zero, $zero, 1
/* 6D0DEC 8021CD7C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0DF0 8021CD80 8026AE40 */  lb        $a2, -0x51c0($at)
/* 6D0DF4 8021CD84 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0DF8 8021CD88 0000012C */  .byte     0x00, 0x00, 0x01, 0x2c
/* 6D0DFC 8021CD8C 00000000 */  nop       
/* 6D0E00 8021CD90 00000000 */  nop       
/* 6D0E04 8021CD94 00000043 */  sra       $zero, $zero, 1
/* 6D0E08 8021CD98 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0E0C 8021CD9C 8026EE88 */  lb        $a2, -0x1178($at)
/* 6D0E10 8021CDA0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0E14 8021CDA4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0E18 8021CDA8 00000000 */  nop       
/* 6D0E1C 8021CDAC 00000002 */  srl       $zero, $zero, 0
/* 6D0E20 8021CDB0 00000043 */  sra       $zero, $zero, 1
/* 6D0E24 8021CDB4 00000003 */  sra       $zero, $zero, 0
/* 6D0E28 8021CDB8 8026B654 */  lb        $a2, -0x49ac($at)
/* 6D0E2C 8021CDBC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0E30 8021CDC0 F24ABA80 */  scd       $t2, -0x4580($s2)
/* 6D0E34 8021CDC4 00000043 */  sra       $zero, $zero, 1
/* 6D0E38 8021CDC8 00000002 */  srl       $zero, $zero, 0
/* 6D0E3C 8021CDCC 80269EC4 */  lb        $a2, -0x613c($at)
/* 6D0E40 8021CDD0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0E44 8021CDD4 00000043 */  sra       $zero, $zero, 1
/* 6D0E48 8021CDD8 00000004 */  sllv      $zero, $zero, $zero
/* 6D0E4C 8021CDDC 80279E64 */  lb        $a3, -0x619c($at)
/* 6D0E50 8021CDE0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0E54 8021CDE4 00000000 */  nop       
/* 6D0E58 8021CDE8 00000000 */  nop       
/* 6D0E5C 8021CDEC 00000043 */  sra       $zero, $zero, 1
/* 6D0E60 8021CDF0 00000004 */  sllv      $zero, $zero, $zero
/* 6D0E64 8021CDF4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D0E68 8021CDF8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0E6C 8021CDFC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0E70 8021CE00 00590008 */  .byte     0x00, 0x59, 0x00, 0x08
/* 6D0E74 8021CE04 00000043 */  sra       $zero, $zero, 1
/* 6D0E78 8021CE08 00000004 */  sllv      $zero, $zero, $zero
/* 6D0E7C 8021CE0C 8026EF4C */  lb        $a2, -0x10b4($at)
/* 6D0E80 8021CE10 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0E84 8021CE14 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0E88 8021CE18 00000000 */  nop       
/* 6D0E8C 8021CE1C 00000043 */  sra       $zero, $zero, 1
/* 6D0E90 8021CE20 00000003 */  sra       $zero, $zero, 0
/* 6D0E94 8021CE24 8027CB08 */  lb        $a3, -0x34f8($at)
/* 6D0E98 8021CE28 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0E9C 8021CE2C 80219D34 */  lb        $at, -0x62cc($at)
/* 6D0EA0 8021CE30 00000043 */  sra       $zero, $zero, 1
/* 6D0EA4 8021CE34 00000004 */  sllv      $zero, $zero, $zero
/* 6D0EA8 8021CE38 8027CA74 */  lb        $a3, -0x358c($at)
/* 6D0EAC 8021CE3C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0EB0 8021CE40 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0EB4 8021CE44 80219D00 */  lb        $at, -0x6300($at)
/* 6D0EB8 8021CE48 00000043 */  sra       $zero, $zero, 1
/* 6D0EBC 8021CE4C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0EC0 8021CE50 8026D3C8 */  lb        $a2, -0x2c38($at)
/* 6D0EC4 8021CE54 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0EC8 8021CE58 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0ECC 8021CE5C 00001000 */  sll       $v0, $zero, 0
/* 6D0ED0 8021CE60 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0ED4 8021CE64 00000043 */  sra       $zero, $zero, 1
/* 6D0ED8 8021CE68 00000004 */  sllv      $zero, $zero, $zero
/* 6D0EDC 8021CE6C 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D0EE0 8021CE70 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0EE4 8021CE74 00000000 */  nop       
/* 6D0EE8 8021CE78 00000000 */  nop       
/* 6D0EEC 8021CE7C 00000043 */  sra       $zero, $zero, 1
/* 6D0EF0 8021CE80 00000004 */  sllv      $zero, $zero, $zero
/* 6D0EF4 8021CE84 8027CB7C */  lb        $a3, -0x3484($at)
/* 6D0EF8 8021CE88 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0EFC 8021CE8C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0F00 8021CE90 80219BD0 */  lb        $at, -0x6430($at)
/* 6D0F04 8021CE94 00000008 */  jr        $zero
/* 6D0F08 8021CE98 00000001 */   movf     $zero, $zero, $fcc0
/* 6D0F0C 8021CE9C 0000000A */  movz      $zero, $zero, $zero
/* 6D0F10 8021CEA0 00000043 */  sra       $zero, $zero, 1
/* 6D0F14 8021CEA4 00000003 */  sra       $zero, $zero, 0
/* 6D0F18 8021CEA8 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D0F1C 8021CEAC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0F20 8021CEB0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0F24 8021CEB4 00000043 */  sra       $zero, $zero, 1
/* 6D0F28 8021CEB8 00000003 */  sra       $zero, $zero, 0
/* 6D0F2C 8021CEBC 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D0F30 8021CEC0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0F34 8021CEC4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0F38 8021CEC8 00000002 */  srl       $zero, $zero, 0
/* 6D0F3C 8021CECC 00000000 */  nop       
/* 6D0F40 8021CED0 00000020 */  add       $zero, $zero, $zero
/* 6D0F44 8021CED4 00000000 */  nop       
/* 6D0F48 8021CED8 00000023 */  negu      $zero, $zero
/* 6D0F4C 8021CEDC 00000000 */  nop       
/* 6D0F50 8021CEE0 00000056 */  drotrv    $zero, $zero, $zero
/* 6D0F54 8021CEE4 00000000 */  nop       
/* 6D0F58 8021CEE8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0F5C 8021CEEC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0F60 8021CEF0 0000001E */  ddiv      $zero, $zero, $zero
/* 6D0F64 8021CEF4 00000043 */  sra       $zero, $zero, 1
/* 6D0F68 8021CEF8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D0F6C 8021CEFC 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D0F70 8021CF00 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0F74 8021CF04 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D0F78 8021CF08 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D0F7C 8021CF0C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D0F80 8021CF10 00000043 */  sra       $zero, $zero, 1
/* 6D0F84 8021CF14 0000000F */  sync      
/* 6D0F88 8021CF18 802D829C */  lb        $t5, -0x7d64($at)
/* 6D0F8C 8021CF1C 00000007 */  srav      $zero, $zero, $zero
/* 6D0F90 8021CF20 00000002 */  srl       $zero, $zero, 0
/* 6D0F94 8021CF24 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D0F98 8021CF28 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D0F9C 8021CF2C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D0FA0 8021CF30 00000000 */  nop       
/* 6D0FA4 8021CF34 00000000 */  nop       
/* 6D0FA8 8021CF38 00000000 */  nop       
/* 6D0FAC 8021CF3C 00000000 */  nop       
/* 6D0FB0 8021CF40 00000000 */  nop       
/* 6D0FB4 8021CF44 00000000 */  nop       
/* 6D0FB8 8021CF48 00000000 */  nop       
/* 6D0FBC 8021CF4C 00000000 */  nop       
/* 6D0FC0 8021CF50 00000000 */  nop       
/* 6D0FC4 8021CF54 00000008 */  jr        $zero
/* 6D0FC8 8021CF58 00000001 */   movf     $zero, $zero, $fcc0
/* 6D0FCC 8021CF5C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D0FD0 8021CF60 00000006 */  srlv      $zero, $zero, $zero
/* 6D0FD4 8021CF64 00000000 */  nop       
/* 6D0FD8 8021CF68 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D0FDC 8021CF6C 00000000 */  nop       
/* 6D0FE0 8021CF70 00000043 */  sra       $zero, $zero, 1
/* 6D0FE4 8021CF74 00000002 */  srl       $zero, $zero, 0
/* 6D0FE8 8021CF78 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 6D0FEC 8021CF7C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D0FF0 8021CF80 00000043 */  sra       $zero, $zero, 1
/* 6D0FF4 8021CF84 00000003 */  sra       $zero, $zero, 0
/* 6D0FF8 8021CF88 8026B654 */  lb        $a2, -0x49ac($at)
/* 6D0FFC 8021CF8C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1000 8021CF90 F24ABA80 */  scd       $t2, -0x4580($s2)
/* 6D1004 8021CF94 00000043 */  sra       $zero, $zero, 1
/* 6D1008 8021CF98 00000004 */  sllv      $zero, $zero, $zero
/* 6D100C 8021CF9C 80279E64 */  lb        $a3, -0x619c($at)
/* 6D1010 8021CFA0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1014 8021CFA4 00000000 */  nop       
/* 6D1018 8021CFA8 00000000 */  nop       
/* 6D101C 8021CFAC 00000008 */  jr        $zero
/* 6D1020 8021CFB0 00000001 */   movf     $zero, $zero, $fcc0
/* 6D1024 8021CFB4 00000002 */  srl       $zero, $zero, 0
/* 6D1028 8021CFB8 00000043 */  sra       $zero, $zero, 1
/* 6D102C 8021CFBC 00000008 */  jr        $zero
/* 6D1030 8021CFC0 8027CCB4 */   lb       $a3, -0x334c($at)
/* 6D1034 8021CFC4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1038 8021CFC8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D103C 8021CFCC 00000000 */  nop       
/* 6D1040 8021CFD0 0000FFFF */  dsra32    $ra, $zero, 0x1f
/* 6D1044 8021CFD4 00000000 */  nop       
/* 6D1048 8021CFD8 0000000A */  movz      $zero, $zero, $zero
/* 6D104C 8021CFDC 00000020 */  add       $zero, $zero, $zero
/* 6D1050 8021CFE0 00000014 */  dsllv     $zero, $zero, $zero
/* 6D1054 8021CFE4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1058 8021CFE8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D105C 8021CFEC 0000001D */  dmultu    $zero, $zero
/* 6D1060 8021CFF0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1064 8021CFF4 00000000 */  nop       
/* 6D1068 8021CFF8 0000001D */  dmultu    $zero, $zero
/* 6D106C 8021CFFC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1070 8021D000 00000002 */  srl       $zero, $zero, 0
/* 6D1074 8021D004 00000043 */  sra       $zero, $zero, 1
/* 6D1078 8021D008 00000002 */  srl       $zero, $zero, 0
/* 6D107C 8021D00C 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D1080 8021D010 00000002 */  srl       $zero, $zero, 0
/* 6D1084 8021D014 00000056 */  drotrv    $zero, $zero, $zero
/* 6D1088 8021D018 00000000 */  nop       
/* 6D108C 8021D01C 00000043 */  sra       $zero, $zero, 1
/* 6D1090 8021D020 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D1094 8021D024 8026C4AC */  lb        $a2, -0x3b54($at)
/* 6D1098 8021D028 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D109C 8021D02C 00000000 */  nop       
/* 6D10A0 8021D030 00000010 */  mfhi      $zero
/* 6D10A4 8021D034 00000000 */  nop       
/* 6D10A8 8021D038 00000024 */  and       $zero, $zero, $zero
/* 6D10AC 8021D03C 00000002 */  srl       $zero, $zero, 0
/* 6D10B0 8021D040 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D10B4 8021D044 00000000 */  nop       
/* 6D10B8 8021D048 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D10BC 8021D04C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D10C0 8021D050 0000003C */  dsll32    $zero, $zero, 0
/* 6D10C4 8021D054 00000027 */  not       $zero, $zero
/* 6D10C8 8021D058 00000002 */  srl       $zero, $zero, 0
/* 6D10CC 8021D05C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D10D0 8021D060 00000012 */  mflo      $zero
/* 6D10D4 8021D064 00000043 */  sra       $zero, $zero, 1
/* 6D10D8 8021D068 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D10DC 8021D06C 8026C3AC */  lb        $a2, -0x3c54($at)
/* 6D10E0 8021D070 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D10E4 8021D074 00000000 */  nop       
/* 6D10E8 8021D078 00000000 */  nop       
/* 6D10EC 8021D07C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D10F0 8021D080 00000008 */  jr        $zero
/* 6D10F4 8021D084 00000001 */   movf     $zero, $zero, $fcc0
/* 6D10F8 8021D088 00000001 */  movf      $zero, $zero, $fcc0
/* 6D10FC 8021D08C 00000006 */  srlv      $zero, $zero, $zero
/* 6D1100 8021D090 00000000 */  nop       
/* 6D1104 8021D094 00000043 */  sra       $zero, $zero, 1
/* 6D1108 8021D098 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D110C 8021D09C 8026C4AC */  lb        $a2, -0x3b54($at)
/* 6D1110 8021D0A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1114 8021D0A4 00000000 */  nop       
/* 6D1118 8021D0A8 00000000 */  nop       
/* 6D111C 8021D0AC 00000000 */  nop       
/* 6D1120 8021D0B0 00000043 */  sra       $zero, $zero, 1
/* 6D1124 8021D0B4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D1128 8021D0B8 8026C3AC */  lb        $a2, -0x3c54($at)
/* 6D112C 8021D0BC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1130 8021D0C0 00000000 */  nop       
/* 6D1134 8021D0C4 00000000 */  nop       
/* 6D1138 8021D0C8 00000000 */  nop       
/* 6D113C 8021D0CC 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D1140 8021D0D0 00000000 */  nop       
/* 6D1144 8021D0D4 00000043 */  sra       $zero, $zero, 1
/* 6D1148 8021D0D8 00000003 */  sra       $zero, $zero, 0
/* 6D114C 8021D0DC 8026B55C */  lb        $a2, -0x4aa4($at)
/* 6D1150 8021D0E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1154 8021D0E4 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 6D1158 8021D0E8 00000043 */  sra       $zero, $zero, 1
/* 6D115C 8021D0EC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D1160 8021D0F0 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D1164 8021D0F4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1168 8021D0F8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D116C 8021D0FC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D1170 8021D100 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D1174 8021D104 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D1178 8021D108 00000002 */  srl       $zero, $zero, 0
/* 6D117C 8021D10C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1180 8021D110 00000032 */  tlt       $zero, $zero
/* 6D1184 8021D114 00000043 */  sra       $zero, $zero, 1
/* 6D1188 8021D118 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D118C 8021D11C 8026A510 */  lb        $a2, -0x5af0($at)
/* 6D1190 8021D120 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1194 8021D124 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1198 8021D128 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D119C 8021D12C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D11A0 8021D130 00000043 */  sra       $zero, $zero, 1
/* 6D11A4 8021D134 00000006 */  srlv      $zero, $zero, $zero
/* 6D11A8 8021D138 80278D08 */  lb        $a3, -0x72f8($at)
/* 6D11AC 8021D13C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D11B0 8021D140 0000001E */  ddiv      $zero, $zero, $zero
/* 6D11B4 8021D144 00000000 */  nop       
/* 6D11B8 8021D148 00000001 */  movf      $zero, $zero, $fcc0
/* 6D11BC 8021D14C 00000000 */  nop       
/* 6D11C0 8021D150 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D11C4 8021D154 00000002 */  srl       $zero, $zero, 0
/* 6D11C8 8021D158 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D11CC 8021D15C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D11D0 8021D160 00000043 */  sra       $zero, $zero, 1
/* 6D11D4 8021D164 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D11D8 8021D168 8026A510 */  lb        $a2, -0x5af0($at)
/* 6D11DC 8021D16C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D11E0 8021D170 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D11E4 8021D174 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D11E8 8021D178 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D11EC 8021D17C 00000043 */  sra       $zero, $zero, 1
/* 6D11F0 8021D180 00000006 */  srlv      $zero, $zero, $zero
/* 6D11F4 8021D184 80278D08 */  lb        $a3, -0x72f8($at)
/* 6D11F8 8021D188 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D11FC 8021D18C 00000014 */  dsllv     $zero, $zero, $zero
/* 6D1200 8021D190 00000000 */  nop       
/* 6D1204 8021D194 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1208 8021D198 00000000 */  nop       
/* 6D120C 8021D19C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D1210 8021D1A0 00000002 */  srl       $zero, $zero, 0
/* 6D1214 8021D1A4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1218 8021D1A8 0000001E */  ddiv      $zero, $zero, $zero
/* 6D121C 8021D1AC 00000043 */  sra       $zero, $zero, 1
/* 6D1220 8021D1B0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D1224 8021D1B4 8026A510 */  lb        $a2, -0x5af0($at)
/* 6D1228 8021D1B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D122C 8021D1BC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1230 8021D1C0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D1234 8021D1C4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D1238 8021D1C8 00000043 */  sra       $zero, $zero, 1
/* 6D123C 8021D1CC 00000006 */  srlv      $zero, $zero, $zero
/* 6D1240 8021D1D0 80278D08 */  lb        $a3, -0x72f8($at)
/* 6D1244 8021D1D4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1248 8021D1D8 0000000A */  movz      $zero, $zero, $zero
/* 6D124C 8021D1DC 00000000 */  nop       
/* 6D1250 8021D1E0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1254 8021D1E4 00000000 */  nop       
/* 6D1258 8021D1E8 00000008 */  jr        $zero
/* 6D125C 8021D1EC 00000001 */   movf     $zero, $zero, $fcc0
/* 6D1260 8021D1F0 00000014 */  dsllv     $zero, $zero, $zero
/* 6D1264 8021D1F4 00000043 */  sra       $zero, $zero, 1
/* 6D1268 8021D1F8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D126C 8021D1FC 8027D7F0 */  lb        $a3, -0x2810($at)
/* 6D1270 8021D200 00000043 */  sra       $zero, $zero, 1
/* 6D1274 8021D204 00000003 */  sra       $zero, $zero, 0
/* 6D1278 8021D208 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D127C 8021D20C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1280 8021D210 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D1284 8021D214 00000011 */  mthi      $zero
/* 6D1288 8021D218 00000002 */  srl       $zero, $zero, 0
/* 6D128C 8021D21C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D1290 8021D220 18000000 */  blez      $zero, .L8021D224
.L8021D224:
/* 6D1294 8021D224 00000043 */   sra      $zero, $zero, 1
/* 6D1298 8021D228 00000003 */  sra       $zero, $zero, 0
/* 6D129C 8021D22C 8027DBA4 */  lb        $a3, -0x245c($at)
/* 6D12A0 8021D230 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D12A4 8021D234 00000000 */  nop       
/* 6D12A8 8021D238 00000013 */  mtlo      $zero
/* 6D12AC 8021D23C 00000000 */  nop       
/* 6D12B0 8021D240 00000043 */  sra       $zero, $zero, 1
/* 6D12B4 8021D244 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D12B8 8021D248 8026D3C8 */  lb        $a2, -0x2c38($at)
/* 6D12BC 8021D24C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D12C0 8021D250 00000001 */  movf      $zero, $zero, $fcc0
/* 6D12C4 8021D254 00400000 */  .byte     0x00, 0x40, 0x00, 0x00
/* 6D12C8 8021D258 00000000 */  nop       
/* 6D12CC 8021D25C 00000043 */  sra       $zero, $zero, 1
/* 6D12D0 8021D260 00000002 */  srl       $zero, $zero, 0
/* 6D12D4 8021D264 8026F6EC */  lb        $a2, -0x914($at)
/* 6D12D8 8021D268 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D12DC 8021D26C 00000043 */  sra       $zero, $zero, 1
/* 6D12E0 8021D270 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D12E4 8021D274 8026AE40 */  lb        $a2, -0x51c0($at)
/* 6D12E8 8021D278 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D12EC 8021D27C 0000012C */  .byte     0x00, 0x00, 0x01, 0x2c
/* 6D12F0 8021D280 00000000 */  nop       
/* 6D12F4 8021D284 00000000 */  nop       
/* 6D12F8 8021D288 00000025 */  or        $zero, $zero, $zero
/* 6D12FC 8021D28C 00000002 */  srl       $zero, $zero, 0
/* 6D1300 8021D290 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1304 8021D294 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1308 8021D298 00000025 */  or        $zero, $zero, $zero
/* 6D130C 8021D29C 00000002 */  srl       $zero, $zero, 0
/* 6D1310 8021D2A0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D1314 8021D2A4 00590004 */  sllv      $zero, $t9, $v0
/* 6D1318 8021D2A8 00000046 */  rotrv     $zero, $zero, $zero
/* 6D131C 8021D2AC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1320 8021D2B0 8029BEB8 */  lb        $t1, -0x4148($at)
/* 6D1324 8021D2B4 00000043 */  sra       $zero, $zero, 1
/* 6D1328 8021D2B8 00000004 */  sllv      $zero, $zero, $zero
/* 6D132C 8021D2BC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D1330 8021D2C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1334 8021D2C4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1338 8021D2C8 00590001 */  movt      $zero, $v0, $fcc6
/* 6D133C 8021D2CC 00000043 */  sra       $zero, $zero, 1
/* 6D1340 8021D2D0 00000003 */  sra       $zero, $zero, 0
/* 6D1344 8021D2D4 8027CB08 */  lb        $a3, -0x34f8($at)
/* 6D1348 8021D2D8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D134C 8021D2DC 80219D34 */  lb        $at, -0x62cc($at)
/* 6D1350 8021D2E0 00000043 */  sra       $zero, $zero, 1
/* 6D1354 8021D2E4 00000004 */  sllv      $zero, $zero, $zero
/* 6D1358 8021D2E8 8027CA74 */  lb        $a3, -0x358c($at)
/* 6D135C 8021D2EC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1360 8021D2F0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1364 8021D2F4 80219D00 */  lb        $at, -0x6300($at)
.L8021D2F8:
/* 6D1368 8021D2F8 00000043 */  sra       $zero, $zero, 1
/* 6D136C 8021D2FC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D1370 8021D300 8026D3C8 */  lb        $a2, -0x2c38($at)
/* 6D1374 8021D304 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1378 8021D308 00000001 */  movf      $zero, $zero, $fcc0
/* 6D137C 8021D30C 00001000 */  sll       $v0, $zero, 0
/* 6D1380 8021D310 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1384 8021D314 00000043 */  sra       $zero, $zero, 1
/* 6D1388 8021D318 00000004 */  sllv      $zero, $zero, $zero
/* 6D138C 8021D31C 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D1390 8021D320 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1394 8021D324 00000000 */  nop       
/* 6D1398 8021D328 00000000 */  nop       
/* 6D139C 8021D32C 00000043 */  sra       $zero, $zero, 1
/* 6D13A0 8021D330 00000004 */  sllv      $zero, $zero, $zero
/* 6D13A4 8021D334 8027CB7C */  lb        $a3, -0x3484($at)
/* 6D13A8 8021D338 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D13AC 8021D33C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D13B0 8021D340 80219BD0 */  lb        $at, -0x6430($at)
/* 6D13B4 8021D344 00000020 */  add       $zero, $zero, $zero
/* 6D13B8 8021D348 00000000 */  nop       
/* 6D13BC 8021D34C 00000023 */  negu      $zero, $zero
/* 6D13C0 8021D350 00000000 */  nop       
/* 6D13C4 8021D354 00000043 */  sra       $zero, $zero, 1
/* 6D13C8 8021D358 00000003 */  sra       $zero, $zero, 0
/* 6D13CC 8021D35C 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D13D0 8021D360 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D13D4 8021D364 00000001 */  movf      $zero, $zero, $fcc0
/* 6D13D8 8021D368 00000043 */  sra       $zero, $zero, 1
/* 6D13DC 8021D36C 00000003 */  sra       $zero, $zero, 0
/* 6D13E0 8021D370 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D13E4 8021D374 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D13E8 8021D378 00000001 */  movf      $zero, $zero, $fcc0
/* 6D13EC 8021D37C 00000002 */  srl       $zero, $zero, 0
/* 6D13F0 8021D380 00000000 */  nop       
/* 6D13F4 8021D384 00000001 */  movf      $zero, $zero, $fcc0
/* 6D13F8 8021D388 00000000 */  nop       
/* 6D13FC 8021D38C 00000043 */  sra       $zero, $zero, 1
/* 6D1400 8021D390 00000002 */  srl       $zero, $zero, 0
/* 6D1404 8021D394 8026E310 */  lb        $a2, -0x1cf0($at)
/* 6D1408 8021D398 00008002 */  srl       $s0, $zero, 0
/* 6D140C 8021D39C 00000043 */  sra       $zero, $zero, 1
/* 6D1410 8021D3A0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1414 8021D3A4 8026E354 */  lb        $a2, -0x1cac($at)
/* 6D1418 8021D3A8 00000003 */  sra       $zero, $zero, 0
/* 6D141C 8021D3AC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1420 8021D3B0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1424 8021D3B4 00000043 */  sra       $zero, $zero, 1
/* 6D1428 8021D3B8 00000003 */  sra       $zero, $zero, 0
/* 6D142C 8021D3BC 8026E8AC */  lb        $a2, -0x1754($at)
/* 6D1430 8021D3C0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1434 8021D3C4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D1438 8021D3C8 00000043 */  sra       $zero, $zero, 1
/* 6D143C 8021D3CC 00000003 */  sra       $zero, $zero, 0
/* 6D1440 8021D3D0 8027DA68 */  lb        $a3, -0x2598($at)
/* 6D1444 8021D3D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1448 8021D3D8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D144C 8021D3DC 00000014 */  dsllv     $zero, $zero, $zero
/* 6D1450 8021D3E0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1454 8021D3E4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D1458 8021D3E8 0000001D */  dmultu    $zero, $zero
/* 6D145C 8021D3EC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1460 8021D3F0 00000010 */  mfhi      $zero
/* 6D1464 8021D3F4 0000001D */  dmultu    $zero, $zero
/* 6D1468 8021D3F8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D146C 8021D3FC 00000049 */  .byte     0x00, 0x00, 0x00, 0x49
/* 6D1470 8021D400 00000024 */  and       $zero, $zero, $zero
/* 6D1474 8021D404 00000002 */  srl       $zero, $zero, 0
/* 6D1478 8021D408 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D147C 8021D40C FFFFFFFF */  sd        $ra, -1($ra)
/* 6D1480 8021D410 00000002 */  srl       $zero, $zero, 0
/* 6D1484 8021D414 00000000 */  nop       
/* 6D1488 8021D418 00000020 */  add       $zero, $zero, $zero
/* 6D148C 8021D41C 00000000 */  nop       
/* 6D1490 8021D420 00000023 */  negu      $zero, $zero
/* 6D1494 8021D424 00000000 */  nop       
/* 6D1498 8021D428 00000043 */  sra       $zero, $zero, 1
/* 6D149C 8021D42C 00000003 */  sra       $zero, $zero, 0
/* 6D14A0 8021D430 8026E414 */  lb        $a2, -0x1bec($at)
/* 6D14A4 8021D434 00000000 */  nop       
/* 6D14A8 8021D438 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D14AC 8021D43C 0000000B */  movn      $zero, $zero, $zero
/* 6D14B0 8021D440 00000002 */  srl       $zero, $zero, 0
/* 6D14B4 8021D444 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D14B8 8021D448 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D14BC 8021D44C 00000004 */  sllv      $zero, $zero, $zero
.L8021D450:
/* 6D14C0 8021D450 00000001 */  movf      $zero, $zero, $fcc0
/* 6D14C4 8021D454 00000001 */  movf      $zero, $zero, $fcc0
/* 6D14C8 8021D458 00000013 */  mtlo      $zero
/* 6D14CC 8021D45C 00000000 */  nop       
.L8021D460:
/* 6D14D0 8021D460 00000024 */  and       $zero, $zero, $zero
/* 6D14D4 8021D464 00000002 */  srl       $zero, $zero, 0
/* 6D14D8 8021D468 FBD3E281 */  bbit132   $fp, 0x13, .L80215E70
/* 6D14DC 8021D46C 00000000 */   nop      
/* 6D14E0 8021D470 00000024 */  and       $zero, $zero, $zero
/* 6D14E4 8021D474 00000002 */  srl       $zero, $zero, 0
/* 6D14E8 8021D478 FBD3E282 */  bbit132   $fp, 0x13, .L80215E84
/* 6D14EC 8021D47C 00000000 */   nop      
/* 6D14F0 8021D480 00000024 */  and       $zero, $zero, $zero
/* 6D14F4 8021D484 00000002 */  srl       $zero, $zero, 0
/* 6D14F8 8021D488 FBD3E283 */  bbit132   $fp, 0x13, .L80215E98
/* 6D14FC 8021D48C 00000000 */   nop      
/* 6D1500 8021D490 00000024 */  and       $zero, $zero, $zero
/* 6D1504 8021D494 00000002 */  srl       $zero, $zero, 0
/* 6D1508 8021D498 FBD3E284 */  bbit132   $fp, 0x13, .L80215EAC
/* 6D150C 8021D49C 00000000 */   nop      
/* 6D1510 8021D4A0 00000043 */  sra       $zero, $zero, 1
/* 6D1514 8021D4A4 00000002 */  srl       $zero, $zero, 0
/* 6D1518 8021D4A8 8026E310 */  lb        $a2, -0x1cf0($at)
/* 6D151C 8021D4AC 00008002 */  srl       $s0, $zero, 0
/* 6D1520 8021D4B0 00000043 */  sra       $zero, $zero, 1
/* 6D1524 8021D4B4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1528 8021D4B8 8026E354 */  lb        $a2, -0x1cac($at)
/* 6D152C 8021D4BC 00000003 */  sra       $zero, $zero, 0
/* 6D1530 8021D4C0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1534 8021D4C4 00000000 */  nop       
/* 6D1538 8021D4C8 00000043 */  sra       $zero, $zero, 1
/* 6D153C 8021D4CC 00000003 */  sra       $zero, $zero, 0
/* 6D1540 8021D4D0 8026E8AC */  lb        $a2, -0x1754($at)
/* 6D1544 8021D4D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1548 8021D4D8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D154C 8021D4DC 00000043 */  sra       $zero, $zero, 1
/* 6D1550 8021D4E0 00000003 */  sra       $zero, $zero, 0
/* 6D1554 8021D4E4 8026A0D4 */  lb        $a2, -0x5f2c($at)
/* 6D1558 8021D4E8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D155C 8021D4EC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D1560 8021D4F0 0000002B */  sltu      $zero, $zero, $zero
/* 6D1564 8021D4F4 00000002 */  srl       $zero, $zero, 0
/* 6D1568 8021D4F8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D156C 8021D4FC 00000004 */  sllv      $zero, $zero, $zero
/* 6D1570 8021D500 00000014 */  dsllv     $zero, $zero, $zero
/* 6D1574 8021D504 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1578 8021D508 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D157C 8021D50C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D1580 8021D510 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1584 8021D514 00000000 */  nop       
/* 6D1588 8021D518 00000024 */  and       $zero, $zero, $zero
/* 6D158C 8021D51C 00000002 */  srl       $zero, $zero, 0
/* 6D1590 8021D520 FBD3E281 */  bbit132   $fp, 0x13, .L80215F28
/* 6D1594 8021D524 00000001 */   movf     $zero, $zero, $fcc0
/* 6D1598 8021D528 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D159C 8021D52C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D15A0 8021D530 00000001 */  movf      $zero, $zero, $fcc0
/* 6D15A4 8021D534 00000024 */  and       $zero, $zero, $zero
/* 6D15A8 8021D538 00000002 */  srl       $zero, $zero, 0
/* 6D15AC 8021D53C FBD3E282 */  bbit132   $fp, 0x13, .L80215F48
/* 6D15B0 8021D540 00000001 */   movf     $zero, $zero, $fcc0
/* 6D15B4 8021D544 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D15B8 8021D548 00000001 */  movf      $zero, $zero, $fcc0
/* 6D15BC 8021D54C 00000002 */  srl       $zero, $zero, 0
/* 6D15C0 8021D550 00000024 */  and       $zero, $zero, $zero
/* 6D15C4 8021D554 00000002 */  srl       $zero, $zero, 0
/* 6D15C8 8021D558 FBD3E283 */  bbit132   $fp, 0x13, .L80215F68
/* 6D15CC 8021D55C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D15D0 8021D560 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D15D4 8021D564 00000001 */  movf      $zero, $zero, $fcc0
/* 6D15D8 8021D568 00000003 */  sra       $zero, $zero, 0
/* 6D15DC 8021D56C 00000024 */  and       $zero, $zero, $zero
/* 6D15E0 8021D570 00000002 */  srl       $zero, $zero, 0
/* 6D15E4 8021D574 FBD3E284 */  bbit132   $fp, 0x13, .L80215F88
/* 6D15E8 8021D578 00000001 */   movf     $zero, $zero, $fcc0
/* 6D15EC 8021D57C 00000023 */  negu      $zero, $zero
/* 6D15F0 8021D580 00000000 */  nop       
/* 6D15F4 8021D584 00000043 */  sra       $zero, $zero, 1
/* 6D15F8 8021D588 00000003 */  sra       $zero, $zero, 0
/* 6D15FC 8021D58C 8026E414 */  lb        $a2, -0x1bec($at)
/* 6D1600 8021D590 00000000 */  nop       
/* 6D1604 8021D594 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1608 8021D598 0000000B */  movn      $zero, $zero, $zero
/* 6D160C 8021D59C 00000002 */  srl       $zero, $zero, 0
/* 6D1610 8021D5A0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1614 8021D5A4 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D1618 8021D5A8 00000004 */  sllv      $zero, $zero, $zero
/* 6D161C 8021D5AC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1620 8021D5B0 00000000 */  nop       
/* 6D1624 8021D5B4 00000013 */  mtlo      $zero
/* 6D1628 8021D5B8 00000000 */  nop       
/* 6D162C 8021D5BC 0000000A */  movz      $zero, $zero, $zero
/* 6D1630 8021D5C0 00000002 */  srl       $zero, $zero, 0
/* 6D1634 8021D5C4 FBD3E281 */  bbit132   $fp, 0x13, .L80215FCC
/* 6D1638 8021D5C8 00000000 */   nop      
/* 6D163C 8021D5CC 00000024 */  and       $zero, $zero, $zero
/* 6D1640 8021D5D0 00000002 */  srl       $zero, $zero, 0
/* 6D1644 8021D5D4 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D1648 8021D5D8 00000000 */  nop       
/* 6D164C 8021D5DC 00000002 */  srl       $zero, $zero, 0
/* 6D1650 8021D5E0 00000000 */  nop       
/* 6D1654 8021D5E4 00000013 */  mtlo      $zero
/* 6D1658 8021D5E8 00000000 */  nop       
/* 6D165C 8021D5EC 0000000A */  movz      $zero, $zero, $zero
/* 6D1660 8021D5F0 00000002 */  srl       $zero, $zero, 0
/* 6D1664 8021D5F4 FBD3E282 */  bbit132   $fp, 0x13, .L80216000
/* 6D1668 8021D5F8 00000000 */   nop      
/* 6D166C 8021D5FC 00000024 */  and       $zero, $zero, $zero
/* 6D1670 8021D600 00000002 */  srl       $zero, $zero, 0
/* 6D1674 8021D604 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D1678 8021D608 00000001 */  movf      $zero, $zero, $fcc0
/* 6D167C 8021D60C 00000002 */  srl       $zero, $zero, 0
/* 6D1680 8021D610 00000000 */  nop       
/* 6D1684 8021D614 00000013 */  mtlo      $zero
/* 6D1688 8021D618 00000000 */  nop       
/* 6D168C 8021D61C 0000000A */  movz      $zero, $zero, $zero
/* 6D1690 8021D620 00000002 */  srl       $zero, $zero, 0
/* 6D1694 8021D624 FBD3E283 */  bbit132   $fp, 0x13, .L80216034
/* 6D1698 8021D628 00000000 */   nop      
/* 6D169C 8021D62C 00000024 */  and       $zero, $zero, $zero
/* 6D16A0 8021D630 00000002 */  srl       $zero, $zero, 0
/* 6D16A4 8021D634 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D16A8 8021D638 00000002 */  srl       $zero, $zero, 0
/* 6D16AC 8021D63C 00000002 */  srl       $zero, $zero, 0
/* 6D16B0 8021D640 00000000 */  nop       
/* 6D16B4 8021D644 00000013 */  mtlo      $zero
/* 6D16B8 8021D648 00000000 */  nop       
/* 6D16BC 8021D64C 0000000A */  movz      $zero, $zero, $zero
/* 6D16C0 8021D650 00000002 */  srl       $zero, $zero, 0
/* 6D16C4 8021D654 FBD3E284 */  bbit132   $fp, 0x13, .L80216068
/* 6D16C8 8021D658 00000000 */   nop      
/* 6D16CC 8021D65C 00000024 */  and       $zero, $zero, $zero
/* 6D16D0 8021D660 00000002 */  srl       $zero, $zero, 0
/* 6D16D4 8021D664 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D16D8 8021D668 00000003 */  sra       $zero, $zero, 0
/* 6D16DC 8021D66C 00000002 */  srl       $zero, $zero, 0
/* 6D16E0 8021D670 00000000 */  nop       
/* 6D16E4 8021D674 00000013 */  mtlo      $zero
/* 6D16E8 8021D678 00000000 */  nop       
/* 6D16EC 8021D67C 00000024 */  and       $zero, $zero, $zero
/* 6D16F0 8021D680 00000002 */  srl       $zero, $zero, 0
/* 6D16F4 8021D684 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D16F8 8021D688 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D16FC 8021D68C 00000002 */  srl       $zero, $zero, 0
/* 6D1700 8021D690 00000000 */  nop       
/* 6D1704 8021D694 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1708 8021D698 00000000 */  nop       
/* 6D170C 8021D69C 00000000 */  nop       
/* 6D1710 8021D6A0 FFFFFC18 */  sd        $ra, -0x3e8($ra)
/* 6D1714 8021D6A4 00000000 */  nop       
/* 6D1718 8021D6A8 80219EA0 */  lb        $at, -0x6160($at)
/* 6D171C 8021D6AC 8021D69C */  lb        $at, -0x2964($at)
/* 6D1720 8021D6B0 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6D1724 8021D6B4 00000000 */  nop       
/* 6D1728 8021D6B8 00000000 */  nop       
/* 6D172C 8021D6BC 00000000 */  nop       
/* 6D1730 8021D6C0 00000000 */  nop       
/* 6D1734 8021D6C4 00000043 */  sra       $zero, $zero, 1
/* 6D1738 8021D6C8 00000003 */  sra       $zero, $zero, 0
/* 6D173C 8021D6CC 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D1740 8021D6D0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1744 8021D6D4 00000000 */  nop       
/* 6D1748 8021D6D8 00000043 */  sra       $zero, $zero, 1
/* 6D174C 8021D6DC 00000003 */  sra       $zero, $zero, 0
/* 6D1750 8021D6E0 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D1754 8021D6E4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1758 8021D6E8 00000000 */  nop       
/* 6D175C 8021D6EC 00000043 */  sra       $zero, $zero, 1
/* 6D1760 8021D6F0 00000002 */  srl       $zero, $zero, 0
/* 6D1764 8021D6F4 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D1768 8021D6F8 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D176C 8021D6FC 00000043 */  sra       $zero, $zero, 1
/* 6D1770 8021D700 00000002 */  srl       $zero, $zero, 0
/* 6D1774 8021D704 8024EB24 */  lb        $a0, -0x14dc($at)
/* 6D1778 8021D708 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D177C 8021D70C 00000043 */  sra       $zero, $zero, 1
/* 6D1780 8021D710 00000002 */  srl       $zero, $zero, 0
/* 6D1784 8021D714 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6D1788 8021D718 00000014 */  dsllv     $zero, $zero, $zero
/* 6D178C 8021D71C 00000043 */  sra       $zero, $zero, 1
/* 6D1790 8021D720 00000003 */  sra       $zero, $zero, 0
/* 6D1794 8021D724 8025385C */  lb        $a1, 0x385c($at)
/* 6D1798 8021D728 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D179C 8021D72C 000002E5 */  .byte     0x00, 0x00, 0x02, 0xe5
/* 6D17A0 8021D730 00000043 */  sra       $zero, $zero, 1
/* 6D17A4 8021D734 00000004 */  sllv      $zero, $zero, $zero
/* 6D17A8 8021D738 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D17AC 8021D73C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D17B0 8021D740 00000001 */  movf      $zero, $zero, $fcc0
/* 6D17B4 8021D744 00590002 */  .byte     0x00, 0x59, 0x00, 0x02
/* 6D17B8 8021D748 00000008 */  jr        $zero
/* 6D17BC 8021D74C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D17C0 8021D750 00000014 */  dsllv     $zero, $zero, $zero
/* 6D17C4 8021D754 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D17C8 8021D758 00000001 */  movf      $zero, $zero, $fcc0
/* 6D17CC 8021D75C 00000002 */  srl       $zero, $zero, 0
/* 6D17D0 8021D760 00000043 */  sra       $zero, $zero, 1
/* 6D17D4 8021D764 00000004 */  sllv      $zero, $zero, $zero
/* 6D17D8 8021D768 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D17DC 8021D76C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D17E0 8021D770 00000001 */  movf      $zero, $zero, $fcc0
/* 6D17E4 8021D774 00590002 */  .byte     0x00, 0x59, 0x00, 0x02
/* 6D17E8 8021D778 00000008 */  jr        $zero
/* 6D17EC 8021D77C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D17F0 8021D780 00000008 */  jr        $zero
/* 6D17F4 8021D784 00000043 */   sra      $zero, $zero, 1
/* 6D17F8 8021D788 00000003 */  sra       $zero, $zero, 0
/* 6D17FC 8021D78C 8025385C */  lb        $a1, 0x385c($at)
/* 6D1800 8021D790 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1804 8021D794 000002E5 */  .byte     0x00, 0x00, 0x02, 0xe5
/* 6D1808 8021D798 00000043 */  sra       $zero, $zero, 1
/* 6D180C 8021D79C 00000003 */  sra       $zero, $zero, 0
/* 6D1810 8021D7A0 8026B358 */  lb        $a2, -0x4ca8($at)
/* 6D1814 8021D7A4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1818 8021D7A8 000000B4 */  teq       $zero, $zero, 2
/* 6D181C 8021D7AC 00000043 */  sra       $zero, $zero, 1
/* 6D1820 8021D7B0 00000004 */  sllv      $zero, $zero, $zero
/* 6D1824 8021D7B4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D1828 8021D7B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D182C 8021D7BC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1830 8021D7C0 00590009 */  .byte     0x00, 0x59, 0x00, 0x09
/* 6D1834 8021D7C4 00000008 */  jr        $zero
/* 6D1838 8021D7C8 00000001 */   movf     $zero, $zero, $fcc0
/* 6D183C 8021D7CC 00000008 */  jr        $zero
/* 6D1840 8021D7D0 00000043 */   sra      $zero, $zero, 1
/* 6D1844 8021D7D4 00000004 */  sllv      $zero, $zero, $zero
/* 6D1848 8021D7D8 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D184C 8021D7DC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1850 8021D7E0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1854 8021D7E4 00590002 */  .byte     0x00, 0x59, 0x00, 0x02
/* 6D1858 8021D7E8 00000008 */  jr        $zero
/* 6D185C 8021D7EC 00000001 */   movf     $zero, $zero, $fcc0
/* 6D1860 8021D7F0 00000008 */  jr        $zero
/* 6D1864 8021D7F4 00000043 */   sra      $zero, $zero, 1
/* 6D1868 8021D7F8 00000003 */  sra       $zero, $zero, 0
/* 6D186C 8021D7FC 8025385C */  lb        $a1, 0x385c($at)
/* 6D1870 8021D800 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1874 8021D804 000002E5 */  .byte     0x00, 0x00, 0x02, 0xe5
/* 6D1878 8021D808 00000043 */  sra       $zero, $zero, 1
/* 6D187C 8021D80C 00000003 */  sra       $zero, $zero, 0
/* 6D1880 8021D810 8026B358 */  lb        $a2, -0x4ca8($at)
/* 6D1884 8021D814 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1888 8021D818 00000000 */  nop       
/* 6D188C 8021D81C 00000043 */  sra       $zero, $zero, 1
/* 6D1890 8021D820 00000004 */  sllv      $zero, $zero, $zero
/* 6D1894 8021D824 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D1898 8021D828 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D189C 8021D82C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D18A0 8021D830 00590009 */  .byte     0x00, 0x59, 0x00, 0x09
/* 6D18A4 8021D834 00000008 */  jr        $zero
/* 6D18A8 8021D838 00000001 */   movf     $zero, $zero, $fcc0
/* 6D18AC 8021D83C 00000008 */  jr        $zero
/* 6D18B0 8021D840 00000006 */   srlv     $zero, $zero, $zero
/* 6D18B4 8021D844 00000000 */  nop       
/* 6D18B8 8021D848 00000043 */  sra       $zero, $zero, 1
/* 6D18BC 8021D84C 00000002 */  srl       $zero, $zero, 0
/* 6D18C0 8021D850 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D18C4 8021D854 00000002 */  srl       $zero, $zero, 0
/* 6D18C8 8021D858 00000043 */  sra       $zero, $zero, 1
/* 6D18CC 8021D85C 00000002 */  srl       $zero, $zero, 0
/* 6D18D0 8021D860 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6D18D4 8021D864 0000000F */  sync      
/* 6D18D8 8021D868 00000056 */  drotrv    $zero, $zero, $zero
/* 6D18DC 8021D86C 00000000 */  nop       
/* 6D18E0 8021D870 00000008 */  jr        $zero
/* 6D18E4 8021D874 00000001 */   movf     $zero, $zero, $fcc0
/* 6D18E8 8021D878 00000008 */  jr        $zero
/* 6D18EC 8021D87C 00000043 */   sra      $zero, $zero, 1
/* 6D18F0 8021D880 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D18F4 8021D884 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D18F8 8021D888 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D18FC 8021D88C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1900 8021D890 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D1904 8021D894 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D1908 8021D898 00000043 */  sra       $zero, $zero, 1
/* 6D190C 8021D89C 0000000F */  sync      
/* 6D1910 8021D8A0 802D829C */  lb        $t5, -0x7d64($at)
/* 6D1914 8021D8A4 00000011 */  mthi      $zero
/* 6D1918 8021D8A8 00000000 */  nop       
/* 6D191C 8021D8AC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1920 8021D8B0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D1924 8021D8B4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D1928 8021D8B8 0000001E */  ddiv      $zero, $zero, $zero
/* 6D192C 8021D8BC 00000000 */  nop       
/* 6D1930 8021D8C0 00000000 */  nop       
/* 6D1934 8021D8C4 00000000 */  nop       
/* 6D1938 8021D8C8 00000000 */  nop       
/* 6D193C 8021D8CC 00000000 */  nop       
/* 6D1940 8021D8D0 00000000 */  nop       
/* 6D1944 8021D8D4 00000000 */  nop       
/* 6D1948 8021D8D8 00000000 */  nop       
/* 6D194C 8021D8DC 00000043 */  sra       $zero, $zero, 1
/* 6D1950 8021D8E0 00000003 */  sra       $zero, $zero, 0
/* 6D1954 8021D8E4 8025385C */  lb        $a1, 0x385c($at)
/* 6D1958 8021D8E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D195C 8021D8EC 0000206D */  .byte     0x00, 0x00, 0x20, 0x6d
/* 6D1960 8021D8F0 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D1964 8021D8F4 00000000 */  nop       
/* 6D1968 8021D8F8 00000043 */  sra       $zero, $zero, 1
/* 6D196C 8021D8FC 00000004 */  sllv      $zero, $zero, $zero
/* 6D1970 8021D900 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D1974 8021D904 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1978 8021D908 00000001 */  movf      $zero, $zero, $fcc0
/* 6D197C 8021D90C 00590016 */  dsrlv     $zero, $t9, $v0
/* 6D1980 8021D910 00000043 */  sra       $zero, $zero, 1
/* 6D1984 8021D914 00000003 */  sra       $zero, $zero, 0
/* 6D1988 8021D918 8026B55C */  lb        $a2, -0x4aa4($at)
/* 6D198C 8021D91C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1990 8021D920 F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 6D1994 8021D924 00000043 */  sra       $zero, $zero, 1
/* 6D1998 8021D928 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D199C 8021D92C 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D19A0 8021D930 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D19A4 8021D934 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D19A8 8021D938 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D19AC 8021D93C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D19B0 8021D940 00000043 */  sra       $zero, $zero, 1
/* 6D19B4 8021D944 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D19B8 8021D948 8026A510 */  lb        $a2, -0x5af0($at)
/* 6D19BC 8021D94C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D19C0 8021D950 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D19C4 8021D954 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D19C8 8021D958 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D19CC 8021D95C 00000043 */  sra       $zero, $zero, 1
/* 6D19D0 8021D960 00000006 */  srlv      $zero, $zero, $zero
/* 6D19D4 8021D964 80278D08 */  lb        $a3, -0x72f8($at)
/* 6D19D8 8021D968 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D19DC 8021D96C 00000010 */  mfhi      $zero
/* 6D19E0 8021D970 00000000 */  nop       
/* 6D19E4 8021D974 00000001 */  movf      $zero, $zero, $fcc0
/* 6D19E8 8021D978 00000000 */  nop       
/* 6D19EC 8021D97C 00000043 */  sra       $zero, $zero, 1
/* 6D19F0 8021D980 00000003 */  sra       $zero, $zero, 0
/* 6D19F4 8021D984 8026DB64 */  lb        $a2, -0x249c($at)
/* 6D19F8 8021D988 8021D6A8 */  lb        $at, -0x2958($at)
/* 6D19FC 8021D98C 00000000 */  nop       
/* 6D1A00 8021D990 00000043 */  sra       $zero, $zero, 1
/* 6D1A04 8021D994 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D1A08 8021D998 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D1A0C 8021D99C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1A10 8021D9A0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D1A14 8021D9A4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D1A18 8021D9A8 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D1A1C 8021D9AC 00000027 */  not       $zero, $zero
/* 6D1A20 8021D9B0 00000002 */  srl       $zero, $zero, 0
/* 6D1A24 8021D9B4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D1A28 8021D9B8 000000C8 */  .byte     0x00, 0x00, 0x00, 0xc8
/* 6D1A2C 8021D9BC 00000043 */  sra       $zero, $zero, 1
/* 6D1A30 8021D9C0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D1A34 8021D9C4 8026AE40 */  lb        $a2, -0x51c0($at)
/* 6D1A38 8021D9C8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1A3C 8021D9CC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D1A40 8021D9D0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D1A44 8021D9D4 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D1A48 8021D9D8 00000043 */  sra       $zero, $zero, 1
/* 6D1A4C 8021D9DC 00000003 */  sra       $zero, $zero, 0
/* 6D1A50 8021D9E0 80269F94 */  lb        $a2, -0x606c($at)
/* 6D1A54 8021D9E4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1A58 8021D9E8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D1A5C 8021D9EC 00000043 */  sra       $zero, $zero, 1
/* 6D1A60 8021D9F0 00000003 */  sra       $zero, $zero, 0
/* 6D1A64 8021D9F4 8025385C */  lb        $a1, 0x385c($at)
/* 6D1A68 8021D9F8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1A6C 8021D9FC 000020D3 */  .byte     0x00, 0x00, 0x20, 0xd3
/* 6D1A70 8021DA00 00000043 */  sra       $zero, $zero, 1
/* 6D1A74 8021DA04 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D1A78 8021DA08 8026F740 */  lb        $a2, -0x8c0($at)
/* 6D1A7C 8021DA0C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1A80 8021DA10 00000000 */  nop       
/* 6D1A84 8021DA14 00000000 */  nop       
/* 6D1A88 8021DA18 00000000 */  nop       
/* 6D1A8C 8021DA1C 00000043 */  sra       $zero, $zero, 1
/* 6D1A90 8021DA20 00000004 */  sllv      $zero, $zero, $zero
/* 6D1A94 8021DA24 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D1A98 8021DA28 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1A9C 8021DA2C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1AA0 8021DA30 00590006 */  srlv      $zero, $t9, $v0
/* 6D1AA4 8021DA34 00000043 */  sra       $zero, $zero, 1
/* 6D1AA8 8021DA38 00000003 */  sra       $zero, $zero, 0
/* 6D1AAC 8021DA3C 8026B654 */  lb        $a2, -0x49ac($at)
/* 6D1AB0 8021DA40 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1AB4 8021DA44 F24A9280 */  scd       $t2, -0x6d80($s2)
/* 6D1AB8 8021DA48 00000043 */  sra       $zero, $zero, 1
/* 6D1ABC 8021DA4C 00000004 */  sllv      $zero, $zero, $zero
/* 6D1AC0 8021DA50 80279E64 */  lb        $a3, -0x619c($at)
/* 6D1AC4 8021DA54 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1AC8 8021DA58 00000000 */  nop       
/* 6D1ACC 8021DA5C 00000000 */  nop       
/* 6D1AD0 8021DA60 00000043 */  sra       $zero, $zero, 1
/* 6D1AD4 8021DA64 00000004 */  sllv      $zero, $zero, $zero
/* 6D1AD8 8021DA68 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D1ADC 8021DA6C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1AE0 8021DA70 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1AE4 8021DA74 00590008 */  .byte     0x00, 0x59, 0x00, 0x08
/* 6D1AE8 8021DA78 00000008 */  jr        $zero
/* 6D1AEC 8021DA7C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D1AF0 8021DA80 0000000A */  movz      $zero, $zero, $zero
/* 6D1AF4 8021DA84 00000043 */  sra       $zero, $zero, 1
/* 6D1AF8 8021DA88 00000004 */  sllv      $zero, $zero, $zero
/* 6D1AFC 8021DA8C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D1B00 8021DA90 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1B04 8021DA94 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1B08 8021DA98 00590001 */  movt      $zero, $v0, $fcc6
/* 6D1B0C 8021DA9C 00000043 */  sra       $zero, $zero, 1
/* 6D1B10 8021DAA0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D1B14 8021DAA4 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D1B18 8021DAA8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1B1C 8021DAAC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D1B20 8021DAB0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D1B24 8021DAB4 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D1B28 8021DAB8 00000043 */  sra       $zero, $zero, 1
/* 6D1B2C 8021DABC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D1B30 8021DAC0 8026A1EC */  lb        $a2, -0x5e14($at)
/* 6D1B34 8021DAC4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1B38 8021DAC8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D1B3C 8021DACC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D1B40 8021DAD0 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D1B44 8021DAD4 00000043 */  sra       $zero, $zero, 1
/* 6D1B48 8021DAD8 00000002 */  srl       $zero, $zero, 0
/* 6D1B4C 8021DADC 8026D664 */  lb        $a2, -0x299c($at)
/* 6D1B50 8021DAE0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1B54 8021DAE4 00000043 */  sra       $zero, $zero, 1
/* 6D1B58 8021DAE8 00000004 */  sllv      $zero, $zero, $zero
/* 6D1B5C 8021DAEC 8026BFB4 */  lb        $a2, -0x404c($at)
.L8021DAF0:
/* 6D1B60 8021DAF0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1B64 8021DAF4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1B68 8021DAF8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D1B6C 8021DAFC 00000014 */  dsllv     $zero, $zero, $zero
/* 6D1B70 8021DB00 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1B74 8021DB04 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D1B78 8021DB08 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D1B7C 8021DB0C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1B80 8021DB10 00000000 */  nop       
/* 6D1B84 8021DB14 00000043 */  sra       $zero, $zero, 1
/* 6D1B88 8021DB18 00000004 */  sllv      $zero, $zero, $zero
/* 6D1B8C 8021DB1C 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D1B90 8021DB20 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1B94 8021DB24 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1B98 8021DB28 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1B9C 8021DB2C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D1BA0 8021DB30 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1BA4 8021DB34 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1BA8 8021DB38 00000043 */  sra       $zero, $zero, 1
/* 6D1BAC 8021DB3C 00000004 */  sllv      $zero, $zero, $zero
/* 6D1BB0 8021DB40 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D1BB4 8021DB44 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1BB8 8021DB48 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1BBC 8021DB4C 00000002 */  srl       $zero, $zero, 0
/* 6D1BC0 8021DB50 00000023 */  negu      $zero, $zero
/* 6D1BC4 8021DB54 00000000 */  nop       
/* 6D1BC8 8021DB58 00000043 */  sra       $zero, $zero, 1
/* 6D1BCC 8021DB5C 00000004 */  sllv      $zero, $zero, $zero
.L8021DB60:
/* 6D1BD0 8021DB60 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D1BD4 8021DB64 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1BD8 8021DB68 00000002 */  srl       $zero, $zero, 0
/* 6D1BDC 8021DB6C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D1BE0 8021DB70 00000043 */  sra       $zero, $zero, 1
/* 6D1BE4 8021DB74 00000004 */  sllv      $zero, $zero, $zero
/* 6D1BE8 8021DB78 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D1BEC 8021DB7C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1BF0 8021DB80 00000002 */  srl       $zero, $zero, 0
/* 6D1BF4 8021DB84 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D1BF8 8021DB88 00000014 */  dsllv     $zero, $zero, $zero
/* 6D1BFC 8021DB8C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1C00 8021DB90 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D1C04 8021DB94 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D1C08 8021DB98 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1C0C 8021DB9C 00000000 */  nop       
/* 6D1C10 8021DBA0 00000043 */  sra       $zero, $zero, 1
/* 6D1C14 8021DBA4 00000003 */  sra       $zero, $zero, 0
/* 6D1C18 8021DBA8 8026F694 */  lb        $a2, -0x96c($at)
/* 6D1C1C 8021DBAC 00000004 */  sllv      $zero, $zero, $zero
/* 6D1C20 8021DBB0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1C24 8021DBB4 00000027 */  not       $zero, $zero
/* 6D1C28 8021DBB8 00000002 */  srl       $zero, $zero, 0
/* 6D1C2C 8021DBBC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1C30 8021DBC0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1C34 8021DBC4 00000043 */  sra       $zero, $zero, 1
.L8021DBC8:
/* 6D1C38 8021DBC8 00000003 */  sra       $zero, $zero, 0
/* 6D1C3C 8021DBCC 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D1C40 8021DBD0 00000004 */  sllv      $zero, $zero, $zero
/* 6D1C44 8021DBD4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1C48 8021DBD8 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D1C4C 8021DBDC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1C50 8021DBE0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1C54 8021DBE4 00000043 */  sra       $zero, $zero, 1
/* 6D1C58 8021DBE8 00000003 */  sra       $zero, $zero, 0
/* 6D1C5C 8021DBEC 8026F694 */  lb        $a2, -0x96c($at)
/* 6D1C60 8021DBF0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D1C64 8021DBF4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1C68 8021DBF8 00000027 */  not       $zero, $zero
/* 6D1C6C 8021DBFC 00000002 */  srl       $zero, $zero, 0
/* 6D1C70 8021DC00 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1C74 8021DC04 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1C78 8021DC08 00000043 */  sra       $zero, $zero, 1
/* 6D1C7C 8021DC0C 00000003 */  sra       $zero, $zero, 0
/* 6D1C80 8021DC10 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D1C84 8021DC14 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D1C88 8021DC18 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1C8C 8021DC1C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D1C90 8021DC20 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1C94 8021DC24 00000002 */  srl       $zero, $zero, 0
/* 6D1C98 8021DC28 00000043 */  sra       $zero, $zero, 1
/* 6D1C9C 8021DC2C 00000003 */  sra       $zero, $zero, 0
/* 6D1CA0 8021DC30 8026F694 */  lb        $a2, -0x96c($at)
/* 6D1CA4 8021DC34 00000006 */  srlv      $zero, $zero, $zero
/* 6D1CA8 8021DC38 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1CAC 8021DC3C 00000027 */  not       $zero, $zero
/* 6D1CB0 8021DC40 00000002 */  srl       $zero, $zero, 0
/* 6D1CB4 8021DC44 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1CB8 8021DC48 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1CBC 8021DC4C 00000043 */  sra       $zero, $zero, 1
/* 6D1CC0 8021DC50 00000003 */  sra       $zero, $zero, 0
/* 6D1CC4 8021DC54 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D1CC8 8021DC58 00000006 */  srlv      $zero, $zero, $zero
/* 6D1CCC 8021DC5C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1CD0 8021DC60 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D1CD4 8021DC64 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1CD8 8021DC68 00000003 */  sra       $zero, $zero, 0
/* 6D1CDC 8021DC6C 00000043 */  sra       $zero, $zero, 1
/* 6D1CE0 8021DC70 00000003 */  sra       $zero, $zero, 0
/* 6D1CE4 8021DC74 8026F694 */  lb        $a2, -0x96c($at)
/* 6D1CE8 8021DC78 00000007 */  srav      $zero, $zero, $zero
/* 6D1CEC 8021DC7C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1CF0 8021DC80 00000027 */  not       $zero, $zero
/* 6D1CF4 8021DC84 00000002 */  srl       $zero, $zero, 0
/* 6D1CF8 8021DC88 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1CFC 8021DC8C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1D00 8021DC90 00000043 */  sra       $zero, $zero, 1
/* 6D1D04 8021DC94 00000003 */  sra       $zero, $zero, 0
/* 6D1D08 8021DC98 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D1D0C 8021DC9C 00000007 */  srav      $zero, $zero, $zero
/* 6D1D10 8021DCA0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1D14 8021DCA4 00000023 */  negu      $zero, $zero
/* 6D1D18 8021DCA8 00000000 */  nop       
/* 6D1D1C 8021DCAC 00000043 */  sra       $zero, $zero, 1
/* 6D1D20 8021DCB0 00000003 */  sra       $zero, $zero, 0
/* 6D1D24 8021DCB4 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D1D28 8021DCB8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1D2C 8021DCBC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1D30 8021DCC0 00000043 */  sra       $zero, $zero, 1
/* 6D1D34 8021DCC4 00000003 */  sra       $zero, $zero, 0
/* 6D1D38 8021DCC8 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D1D3C 8021DCCC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1D40 8021DCD0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1D44 8021DCD4 00000002 */  srl       $zero, $zero, 0
/* 6D1D48 8021DCD8 00000000 */  nop       
/* 6D1D4C 8021DCDC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1D50 8021DCE0 00000000 */  nop       
/* 6D1D54 8021DCE4 00000024 */  and       $zero, $zero, $zero
.L8021DCE8:
/* 6D1D58 8021DCE8 00000002 */  srl       $zero, $zero, 0
/* 6D1D5C 8021DCEC FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D1D60 8021DCF0 00000000 */  nop       
/* 6D1D64 8021DCF4 00000043 */  sra       $zero, $zero, 1
/* 6D1D68 8021DCF8 00000002 */  srl       $zero, $zero, 0
/* 6D1D6C 8021DCFC 8026E310 */  lb        $a2, -0x1cf0($at)
/* 6D1D70 8021DD00 00008002 */  srl       $s0, $zero, 0
/* 6D1D74 8021DD04 00000043 */  sra       $zero, $zero, 1
/* 6D1D78 8021DD08 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1D7C 8021DD0C 8026E354 */  lb        $a2, -0x1cac($at)
/* 6D1D80 8021DD10 00000003 */  sra       $zero, $zero, 0
/* 6D1D84 8021DD14 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1D88 8021DD18 00000000 */  nop       
/* 6D1D8C 8021DD1C 00000043 */  sra       $zero, $zero, 1
/* 6D1D90 8021DD20 00000003 */  sra       $zero, $zero, 0
/* 6D1D94 8021DD24 8026E8AC */  lb        $a2, -0x1754($at)
/* 6D1D98 8021DD28 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1D9C 8021DD2C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D1DA0 8021DD30 00000043 */  sra       $zero, $zero, 1
/* 6D1DA4 8021DD34 00000003 */  sra       $zero, $zero, 0
/* 6D1DA8 8021DD38 8027DA68 */  lb        $a3, -0x2598($at)
/* 6D1DAC 8021DD3C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1DB0 8021DD40 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D1DB4 8021DD44 00000014 */  dsllv     $zero, $zero, $zero
/* 6D1DB8 8021DD48 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1DBC 8021DD4C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D1DC0 8021DD50 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D1DC4 8021DD54 00000001 */  movf      $zero, $zero, $fcc0
.L8021DD58:
/* 6D1DC8 8021DD58 0000004C */  syscall   1
/* 6D1DCC 8021DD5C 00000043 */  sra       $zero, $zero, 1
/* 6D1DD0 8021DD60 00000003 */  sra       $zero, $zero, 0
/* 6D1DD4 8021DD64 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D1DD8 8021DD68 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1DDC 8021DD6C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D1DE0 8021DD70 00000011 */  mthi      $zero
/* 6D1DE4 8021DD74 00000002 */  srl       $zero, $zero, 0
/* 6D1DE8 8021DD78 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D1DEC 8021DD7C 0035D000 */  .byte     0x00, 0x35, 0xd0, 0x00
/* 6D1DF0 8021DD80 00000043 */  sra       $zero, $zero, 1
/* 6D1DF4 8021DD84 00000004 */  sllv      $zero, $zero, $zero
/* 6D1DF8 8021DD88 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D1DFC 8021DD8C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1E00 8021DD90 00000000 */  nop       
/* 6D1E04 8021DD94 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D1E08 8021DD98 0000000A */  movz      $zero, $zero, $zero
/* 6D1E0C 8021DD9C 00000002 */  srl       $zero, $zero, 0
/* 6D1E10 8021DDA0 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D1E14 8021DDA4 00000000 */  nop       
/* 6D1E18 8021DDA8 00000043 */  sra       $zero, $zero, 1
/* 6D1E1C 8021DDAC 00000004 */  sllv      $zero, $zero, $zero
/* 6D1E20 8021DDB0 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D1E24 8021DDB4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1E28 8021DDB8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1E2C 8021DDBC FE363C83 */  sd        $s6, 0x3c83($s1)
.L8021DDC0:
/* 6D1E30 8021DDC0 00000014 */  dsllv     $zero, $zero, $zero
/* 6D1E34 8021DDC4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1E38 8021DDC8 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D1E3C 8021DDCC 0000001D */  dmultu    $zero, $zero
/* 6D1E40 8021DDD0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1E44 8021DDD4 00000000 */  nop       
/* 6D1E48 8021DDD8 0000001D */  dmultu    $zero, $zero
/* 6D1E4C 8021DDDC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1E50 8021DDE0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1E54 8021DDE4 00000043 */  sra       $zero, $zero, 1
/* 6D1E58 8021DDE8 00000004 */  sllv      $zero, $zero, $zero
/* 6D1E5C 8021DDEC 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D1E60 8021DDF0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D1E64 8021DDF4 00000002 */  srl       $zero, $zero, 0
/* 6D1E68 8021DDF8 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D1E6C 8021DDFC 00000014 */  dsllv     $zero, $zero, $zero
/* 6D1E70 8021DE00 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1E74 8021DE04 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D1E78 8021DE08 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D1E7C 8021DE0C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1E80 8021DE10 00000000 */  nop       
/* 6D1E84 8021DE14 00000043 */  sra       $zero, $zero, 1
/* 6D1E88 8021DE18 00000003 */  sra       $zero, $zero, 0
/* 6D1E8C 8021DE1C 8026F694 */  lb        $a2, -0x96c($at)
/* 6D1E90 8021DE20 00000004 */  sllv      $zero, $zero, $zero
/* 6D1E94 8021DE24 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D1E98 8021DE28 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D1E9C 8021DE2C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1EA0 8021DE30 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1EA4 8021DE34 00000043 */  sra       $zero, $zero, 1
/* 6D1EA8 8021DE38 00000003 */  sra       $zero, $zero, 0
/* 6D1EAC 8021DE3C 8026F694 */  lb        $a2, -0x96c($at)
/* 6D1EB0 8021DE40 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D1EB4 8021DE44 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D1EB8 8021DE48 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D1EBC 8021DE4C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1EC0 8021DE50 00000002 */  srl       $zero, $zero, 0
/* 6D1EC4 8021DE54 00000043 */  sra       $zero, $zero, 1
/* 6D1EC8 8021DE58 00000003 */  sra       $zero, $zero, 0
/* 6D1ECC 8021DE5C 8026F694 */  lb        $a2, -0x96c($at)
/* 6D1ED0 8021DE60 00000006 */  srlv      $zero, $zero, $zero
/* 6D1ED4 8021DE64 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D1ED8 8021DE68 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D1EDC 8021DE6C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1EE0 8021DE70 00000003 */  sra       $zero, $zero, 0
/* 6D1EE4 8021DE74 00000043 */  sra       $zero, $zero, 1
/* 6D1EE8 8021DE78 00000003 */  sra       $zero, $zero, 0
/* 6D1EEC 8021DE7C 8026F694 */  lb        $a2, -0x96c($at)
/* 6D1EF0 8021DE80 00000007 */  srav      $zero, $zero, $zero
/* 6D1EF4 8021DE84 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D1EF8 8021DE88 00000023 */  negu      $zero, $zero
/* 6D1EFC 8021DE8C 00000000 */  nop       
/* 6D1F00 8021DE90 0000000C */  syscall   
/* 6D1F04 8021DE94 00000002 */  srl       $zero, $zero, 0
/* 6D1F08 8021DE98 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D1F0C 8021DE9C 00000002 */  srl       $zero, $zero, 0
/* 6D1F10 8021DEA0 00000027 */  not       $zero, $zero
/* 6D1F14 8021DEA4 00000002 */  srl       $zero, $zero, 0
/* 6D1F18 8021DEA8 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D1F1C 8021DEAC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1F20 8021DEB0 00000013 */  mtlo      $zero
/* 6D1F24 8021DEB4 00000000 */  nop       
/* 6D1F28 8021DEB8 00000020 */  add       $zero, $zero, $zero
/* 6D1F2C 8021DEBC 00000000 */  nop       
/* 6D1F30 8021DEC0 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D1F34 8021DEC4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1F38 8021DEC8 00000002 */  srl       $zero, $zero, 0
/* 6D1F3C 8021DECC 00000023 */  negu      $zero, $zero
/* 6D1F40 8021DED0 00000000 */  nop       
/* 6D1F44 8021DED4 00000013 */  mtlo      $zero
/* 6D1F48 8021DED8 00000000 */  nop       
/* 6D1F4C 8021DEDC 00000013 */  mtlo      $zero
.L8021DEE0:
/* 6D1F50 8021DEE0 00000000 */  nop       
/* 6D1F54 8021DEE4 00000023 */  negu      $zero, $zero
/* 6D1F58 8021DEE8 00000000 */  nop       
/* 6D1F5C 8021DEEC 00000043 */  sra       $zero, $zero, 1
/* 6D1F60 8021DEF0 00000003 */  sra       $zero, $zero, 0
/* 6D1F64 8021DEF4 8026E414 */  lb        $a2, -0x1bec($at)
/* 6D1F68 8021DEF8 00000000 */  nop       
/* 6D1F6C 8021DEFC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1F70 8021DF00 0000000B */  movn      $zero, $zero, $zero
/* 6D1F74 8021DF04 00000002 */  srl       $zero, $zero, 0
/* 6D1F78 8021DF08 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1F7C 8021DF0C FFFFFFFF */  sd        $ra, -1($ra)
/* 6D1F80 8021DF10 00000004 */  sllv      $zero, $zero, $zero
/* 6D1F84 8021DF14 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1F88 8021DF18 00000000 */  nop       
/* 6D1F8C 8021DF1C 00000013 */  mtlo      $zero
/* 6D1F90 8021DF20 00000000 */  nop       
/* 6D1F94 8021DF24 00000002 */  srl       $zero, $zero, 0
/* 6D1F98 8021DF28 00000000 */  nop       
/* 6D1F9C 8021DF2C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1FA0 8021DF30 00000000 */  nop       
/* 6D1FA4 8021DF34 00000043 */  sra       $zero, $zero, 1
/* 6D1FA8 8021DF38 00000002 */  srl       $zero, $zero, 0
/* 6D1FAC 8021DF3C 80269E28 */  lb        $a2, -0x61d8($at)
/* 6D1FB0 8021DF40 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D1FB4 8021DF44 0000000A */  movz      $zero, $zero, $zero
/* 6D1FB8 8021DF48 00000002 */  srl       $zero, $zero, 0
/* 6D1FBC 8021DF4C FE363C80 */  sd        $s6, 0x3c80($s1)
.L8021DF50:
/* 6D1FC0 8021DF50 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1FC4 8021DF54 00000043 */  sra       $zero, $zero, 1
/* 6D1FC8 8021DF58 00000003 */  sra       $zero, $zero, 0
/* 6D1FCC 8021DF5C 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D1FD0 8021DF60 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1FD4 8021DF64 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1FD8 8021DF68 00000046 */  rotrv     $zero, $zero, $zero
/* 6D1FDC 8021DF6C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D1FE0 8021DF70 8021B914 */  lb        $at, -0x46ec($at)
/* 6D1FE4 8021DF74 00000002 */  srl       $zero, $zero, 0
/* 6D1FE8 8021DF78 00000000 */  nop       
/* 6D1FEC 8021DF7C 00000013 */  mtlo      $zero
/* 6D1FF0 8021DF80 00000000 */  nop       
/* 6D1FF4 8021DF84 00000043 */  sra       $zero, $zero, 1
/* 6D1FF8 8021DF88 00000004 */  sllv      $zero, $zero, $zero
/* 6D1FFC 8021DF8C 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D2000 8021DF90 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2004 8021DF94 00000000 */  nop       
/* 6D2008 8021DF98 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D200C 8021DF9C 00000014 */  dsllv     $zero, $zero, $zero
/* 6D2010 8021DFA0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2014 8021DFA4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2018 8021DFA8 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D201C 8021DFAC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2020 8021DFB0 00000000 */  nop       
/* 6D2024 8021DFB4 00000043 */  sra       $zero, $zero, 1
.L8021DFB8:
/* 6D2028 8021DFB8 00000003 */  sra       $zero, $zero, 0
/* 6D202C 8021DFBC 8026F694 */  lb        $a2, -0x96c($at)
/* 6D2030 8021DFC0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2034 8021DFC4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2038 8021DFC8 00000014 */  dsllv     $zero, $zero, $zero
/* 6D203C 8021DFCC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2040 8021DFD0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2044 8021DFD4 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D2048 8021DFD8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D204C 8021DFDC 00000000 */  nop       
/* 6D2050 8021DFE0 00000043 */  sra       $zero, $zero, 1
/* 6D2054 8021DFE4 00000004 */  sllv      $zero, $zero, $zero
/* 6D2058 8021DFE8 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D205C 8021DFEC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2060 8021DFF0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2064 8021DFF4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2068 8021DFF8 00000014 */  dsllv     $zero, $zero, $zero
/* 6D206C 8021DFFC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2070 8021E000 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2074 8021E004 0000001D */  dmultu    $zero, $zero
/* 6D2078 8021E008 00000001 */  movf      $zero, $zero, $fcc0
/* 6D207C 8021E00C 00000000 */  nop       
/* 6D2080 8021E010 0000001D */  dmultu    $zero, $zero
/* 6D2084 8021E014 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2088 8021E018 00000001 */  movf      $zero, $zero, $fcc0
/* 6D208C 8021E01C 00000043 */  sra       $zero, $zero, 1
/* 6D2090 8021E020 00000004 */  sllv      $zero, $zero, $zero
/* 6D2094 8021E024 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D2098 8021E028 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D209C 8021E02C 00000002 */  srl       $zero, $zero, 0
/* 6D20A0 8021E030 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D20A4 8021E034 00000014 */  dsllv     $zero, $zero, $zero
/* 6D20A8 8021E038 00000001 */  movf      $zero, $zero, $fcc0
/* 6D20AC 8021E03C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D20B0 8021E040 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D20B4 8021E044 00000001 */  movf      $zero, $zero, $fcc0
/* 6D20B8 8021E048 00000000 */  nop       
/* 6D20BC 8021E04C 00000043 */  sra       $zero, $zero, 1
/* 6D20C0 8021E050 00000003 */  sra       $zero, $zero, 0
/* 6D20C4 8021E054 8026F694 */  lb        $a2, -0x96c($at)
/* 6D20C8 8021E058 00000004 */  sllv      $zero, $zero, $zero
/* 6D20CC 8021E05C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D20D0 8021E060 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D20D4 8021E064 00000001 */  movf      $zero, $zero, $fcc0
/* 6D20D8 8021E068 00000001 */  movf      $zero, $zero, $fcc0
/* 6D20DC 8021E06C 00000043 */  sra       $zero, $zero, 1
/* 6D20E0 8021E070 00000003 */  sra       $zero, $zero, 0
/* 6D20E4 8021E074 8026F694 */  lb        $a2, -0x96c($at)
/* 6D20E8 8021E078 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D20EC 8021E07C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D20F0 8021E080 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D20F4 8021E084 00000001 */  movf      $zero, $zero, $fcc0
/* 6D20F8 8021E088 00000002 */  srl       $zero, $zero, 0
/* 6D20FC 8021E08C 00000043 */  sra       $zero, $zero, 1
/* 6D2100 8021E090 00000003 */  sra       $zero, $zero, 0
/* 6D2104 8021E094 8026F694 */  lb        $a2, -0x96c($at)
/* 6D2108 8021E098 00000006 */  srlv      $zero, $zero, $zero
/* 6D210C 8021E09C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D2110 8021E0A0 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D2114 8021E0A4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2118 8021E0A8 00000003 */  sra       $zero, $zero, 0
/* 6D211C 8021E0AC 00000043 */  sra       $zero, $zero, 1
/* 6D2120 8021E0B0 00000003 */  sra       $zero, $zero, 0
/* 6D2124 8021E0B4 8026F694 */  lb        $a2, -0x96c($at)
/* 6D2128 8021E0B8 00000007 */  srav      $zero, $zero, $zero
/* 6D212C 8021E0BC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D2130 8021E0C0 00000023 */  negu      $zero, $zero
/* 6D2134 8021E0C4 00000000 */  nop       
/* 6D2138 8021E0C8 0000000F */  sync      
/* 6D213C 8021E0CC 00000002 */  srl       $zero, $zero, 0
/* 6D2140 8021E0D0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D2144 8021E0D4 00000002 */  srl       $zero, $zero, 0
/* 6D2148 8021E0D8 00000043 */  sra       $zero, $zero, 1
/* 6D214C 8021E0DC 00000003 */  sra       $zero, $zero, 0
/* 6D2150 8021E0E0 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D2154 8021E0E4 000003E8 */  .byte     0x00, 0x00, 0x03, 0xe8
/* 6D2158 8021E0E8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D215C 8021E0EC 0000000C */  syscall   
/* 6D2160 8021E0F0 00000002 */  srl       $zero, $zero, 0
/* 6D2164 8021E0F4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2168 8021E0F8 0000012C */  .byte     0x00, 0x00, 0x01, 0x2c
/* 6D216C 8021E0FC 00000043 */  sra       $zero, $zero, 1
/* 6D2170 8021E100 00000003 */  sra       $zero, $zero, 0
/* 6D2174 8021E104 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D2178 8021E108 00000001 */  movf      $zero, $zero, $fcc0
/* 6D217C 8021E10C 00000002 */  srl       $zero, $zero, 0
/* 6D2180 8021E110 00000046 */  rotrv     $zero, $zero, $zero
/* 6D2184 8021E114 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2188 8021E118 8021C668 */  lb        $at, -0x3998($at)
/* 6D218C 8021E11C 00000012 */  mflo      $zero
/* 6D2190 8021E120 00000000 */  nop       
/* 6D2194 8021E124 00000043 */  sra       $zero, $zero, 1
/* 6D2198 8021E128 00000003 */  sra       $zero, $zero, 0
/* 6D219C 8021E12C 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D21A0 8021E130 00000001 */  movf      $zero, $zero, $fcc0
/* 6D21A4 8021E134 00000001 */  movf      $zero, $zero, $fcc0
/* 6D21A8 8021E138 00000046 */  rotrv     $zero, $zero, $zero
/* 6D21AC 8021E13C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D21B0 8021E140 8021B914 */  lb        $at, -0x46ec($at)
/* 6D21B4 8021E144 00000013 */  mtlo      $zero
/* 6D21B8 8021E148 00000000 */  nop       
/* 6D21BC 8021E14C 00000002 */  srl       $zero, $zero, 0
/* 6D21C0 8021E150 00000000 */  nop       
/* 6D21C4 8021E154 00000013 */  mtlo      $zero
/* 6D21C8 8021E158 00000000 */  nop       
/* 6D21CC 8021E15C 00000020 */  add       $zero, $zero, $zero
/* 6D21D0 8021E160 00000000 */  nop       
/* 6D21D4 8021E164 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D21D8 8021E168 00000001 */  movf      $zero, $zero, $fcc0
/* 6D21DC 8021E16C 00000002 */  srl       $zero, $zero, 0
/* 6D21E0 8021E170 00000043 */  sra       $zero, $zero, 1
/* 6D21E4 8021E174 00000003 */  sra       $zero, $zero, 0
/* 6D21E8 8021E178 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D21EC 8021E17C 000003E8 */  .byte     0x00, 0x00, 0x03, 0xe8
/* 6D21F0 8021E180 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D21F4 8021E184 0000000C */  syscall   
/* 6D21F8 8021E188 00000002 */  srl       $zero, $zero, 0
/* 6D21FC 8021E18C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2200 8021E190 0000012C */  .byte     0x00, 0x00, 0x01, 0x2c
/* 6D2204 8021E194 00000043 */  sra       $zero, $zero, 1
/* 6D2208 8021E198 00000003 */  sra       $zero, $zero, 0
/* 6D220C 8021E19C 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D2210 8021E1A0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2214 8021E1A4 00000002 */  srl       $zero, $zero, 0
/* 6D2218 8021E1A8 00000046 */  rotrv     $zero, $zero, $zero
/* 6D221C 8021E1AC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2220 8021E1B0 8021C668 */  lb        $at, -0x3998($at)
/* 6D2224 8021E1B4 00000012 */  mflo      $zero
/* 6D2228 8021E1B8 00000000 */  nop       
/* 6D222C 8021E1BC 00000043 */  sra       $zero, $zero, 1
/* 6D2230 8021E1C0 00000003 */  sra       $zero, $zero, 0
/* 6D2234 8021E1C4 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D2238 8021E1C8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D223C 8021E1CC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2240 8021E1D0 00000046 */  rotrv     $zero, $zero, $zero
/* 6D2244 8021E1D4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2248 8021E1D8 8021B914 */  lb        $at, -0x46ec($at)
/* 6D224C 8021E1DC 00000013 */  mtlo      $zero
/* 6D2250 8021E1E0 00000000 */  nop       
/* 6D2254 8021E1E4 00000002 */  srl       $zero, $zero, 0
/* 6D2258 8021E1E8 00000000 */  nop       
/* 6D225C 8021E1EC 00000023 */  negu      $zero, $zero
/* 6D2260 8021E1F0 00000000 */  nop       
/* 6D2264 8021E1F4 00000046 */  rotrv     $zero, $zero, $zero
/* 6D2268 8021E1F8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D226C 8021E1FC 8021D38C */  lb        $at, -0x2c74($at)
/* 6D2270 8021E200 0000000A */  movz      $zero, $zero, $zero
/* 6D2274 8021E204 00000002 */  srl       $zero, $zero, 0
/* 6D2278 8021E208 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D227C 8021E20C FFFFFFFF */  sd        $ra, -1($ra)
/* 6D2280 8021E210 00000043 */  sra       $zero, $zero, 1
/* 6D2284 8021E214 00000003 */  sra       $zero, $zero, 0
/* 6D2288 8021E218 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D228C 8021E21C 000003E8 */  .byte     0x00, 0x00, 0x03, 0xe8
/* 6D2290 8021E220 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2294 8021E224 0000000C */  syscall   
/* 6D2298 8021E228 00000002 */  srl       $zero, $zero, 0
/* 6D229C 8021E22C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D22A0 8021E230 0000012C */  .byte     0x00, 0x00, 0x01, 0x2c
/* 6D22A4 8021E234 00000043 */  sra       $zero, $zero, 1
/* 6D22A8 8021E238 00000003 */  sra       $zero, $zero, 0
/* 6D22AC 8021E23C 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D22B0 8021E240 00000001 */  movf      $zero, $zero, $fcc0
/* 6D22B4 8021E244 00000002 */  srl       $zero, $zero, 0
/* 6D22B8 8021E248 00000046 */  rotrv     $zero, $zero, $zero
/* 6D22BC 8021E24C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D22C0 8021E250 8021C668 */  lb        $at, -0x3998($at)
/* 6D22C4 8021E254 00000012 */  mflo      $zero
/* 6D22C8 8021E258 00000000 */  nop       
/* 6D22CC 8021E25C 00000043 */  sra       $zero, $zero, 1
/* 6D22D0 8021E260 00000003 */  sra       $zero, $zero, 0
/* 6D22D4 8021E264 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D22D8 8021E268 00000001 */  movf      $zero, $zero, $fcc0
/* 6D22DC 8021E26C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D22E0 8021E270 00000046 */  rotrv     $zero, $zero, $zero
/* 6D22E4 8021E274 00000001 */  movf      $zero, $zero, $fcc0
/* 6D22E8 8021E278 8021B914 */  lb        $at, -0x46ec($at)
/* 6D22EC 8021E27C 00000013 */  mtlo      $zero
/* 6D22F0 8021E280 00000000 */  nop       
/* 6D22F4 8021E284 00000002 */  srl       $zero, $zero, 0
/* 6D22F8 8021E288 00000000 */  nop       
/* 6D22FC 8021E28C 00000013 */  mtlo      $zero
/* 6D2300 8021E290 00000000 */  nop       
/* 6D2304 8021E294 00000046 */  rotrv     $zero, $zero, $zero
/* 6D2308 8021E298 00000001 */  movf      $zero, $zero, $fcc0
/* 6D230C 8021E29C 8021DCE4 */  lb        $at, -0x231c($at)
/* 6D2310 8021E2A0 00000014 */  dsllv     $zero, $zero, $zero
/* 6D2314 8021E2A4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2318 8021E2A8 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D231C 8021E2AC 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D2320 8021E2B0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2324 8021E2B4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2328 8021E2B8 00000043 */  sra       $zero, $zero, 1
/* 6D232C 8021E2BC 00000003 */  sra       $zero, $zero, 0
/* 6D2330 8021E2C0 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D2334 8021E2C4 000003E8 */  .byte     0x00, 0x00, 0x03, 0xe8
/* 6D2338 8021E2C8 FE363C80 */  sd        $s6, 0x3c80($s1)
.L8021E2CC:
/* 6D233C 8021E2CC 0000000C */  syscall   
/* 6D2340 8021E2D0 00000002 */  srl       $zero, $zero, 0
/* 6D2344 8021E2D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2348 8021E2D8 00000190 */  .byte     0x00, 0x00, 0x01, 0x90
/* 6D234C 8021E2DC 00000043 */  sra       $zero, $zero, 1
/* 6D2350 8021E2E0 00000003 */  sra       $zero, $zero, 0
/* 6D2354 8021E2E4 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D2358 8021E2E8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D235C 8021E2EC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2360 8021E2F0 00000046 */  rotrv     $zero, $zero, $zero
/* 6D2364 8021E2F4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2368 8021E2F8 8021D6C4 */  lb        $at, -0x293c($at)
/* 6D236C 8021E2FC 00000002 */  srl       $zero, $zero, 0
/* 6D2370 8021E300 00000000 */  nop       
/* 6D2374 8021E304 00000013 */  mtlo      $zero
/* 6D2378 8021E308 00000000 */  nop       
/* 6D237C 8021E30C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D2380 8021E310 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2384 8021E314 00000002 */  srl       $zero, $zero, 0
/* 6D2388 8021E318 00000043 */  sra       $zero, $zero, 1
/* 6D238C 8021E31C 00000003 */  sra       $zero, $zero, 0
/* 6D2390 8021E320 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D2394 8021E324 000003E8 */  .byte     0x00, 0x00, 0x03, 0xe8
/* 6D2398 8021E328 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D239C 8021E32C 0000000C */  syscall   
/* 6D23A0 8021E330 00000002 */  srl       $zero, $zero, 0
/* 6D23A4 8021E334 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D23A8 8021E338 000000C8 */  .byte     0x00, 0x00, 0x00, 0xc8
.L8021E33C:
/* 6D23AC 8021E33C 00000043 */  sra       $zero, $zero, 1
/* 6D23B0 8021E340 00000003 */  sra       $zero, $zero, 0
/* 6D23B4 8021E344 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D23B8 8021E348 00000001 */  movf      $zero, $zero, $fcc0
/* 6D23BC 8021E34C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D23C0 8021E350 00000046 */  rotrv     $zero, $zero, $zero
/* 6D23C4 8021E354 00000001 */  movf      $zero, $zero, $fcc0
/* 6D23C8 8021E358 8021D6C4 */  lb        $at, -0x293c($at)
/* 6D23CC 8021E35C 00000002 */  srl       $zero, $zero, 0
/* 6D23D0 8021E360 00000000 */  nop       
/* 6D23D4 8021E364 00000013 */  mtlo      $zero
/* 6D23D8 8021E368 00000000 */  nop       
/* 6D23DC 8021E36C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D23E0 8021E370 00000001 */  movf      $zero, $zero, $fcc0
/* 6D23E4 8021E374 00000003 */  sra       $zero, $zero, 0
/* 6D23E8 8021E378 00000043 */  sra       $zero, $zero, 1
/* 6D23EC 8021E37C 00000003 */  sra       $zero, $zero, 0
/* 6D23F0 8021E380 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D23F4 8021E384 000003E8 */  .byte     0x00, 0x00, 0x03, 0xe8
/* 6D23F8 8021E388 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D23FC 8021E38C 0000000C */  syscall   
/* 6D2400 8021E390 00000002 */  srl       $zero, $zero, 0
/* 6D2404 8021E394 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2408 8021E398 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6D240C 8021E39C 00000043 */  sra       $zero, $zero, 1
/* 6D2410 8021E3A0 00000003 */  sra       $zero, $zero, 0
.L8021E3A4:
/* 6D2414 8021E3A4 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D2418 8021E3A8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D241C 8021E3AC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2420 8021E3B0 00000046 */  rotrv     $zero, $zero, $zero
/* 6D2424 8021E3B4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2428 8021E3B8 8021D6C4 */  lb        $at, -0x293c($at)
/* 6D242C 8021E3BC 00000002 */  srl       $zero, $zero, 0
/* 6D2430 8021E3C0 00000000 */  nop       
/* 6D2434 8021E3C4 00000013 */  mtlo      $zero
/* 6D2438 8021E3C8 00000000 */  nop       
/* 6D243C 8021E3CC 00000023 */  negu      $zero, $zero
/* 6D2440 8021E3D0 00000000 */  nop       
/* 6D2444 8021E3D4 00000043 */  sra       $zero, $zero, 1
/* 6D2448 8021E3D8 00000003 */  sra       $zero, $zero, 0
/* 6D244C 8021E3DC 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D2450 8021E3E0 000003E8 */  .byte     0x00, 0x00, 0x03, 0xe8
/* 6D2454 8021E3E4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2458 8021E3E8 0000000C */  syscall   
/* 6D245C 8021E3EC 00000002 */  srl       $zero, $zero, 0
/* 6D2460 8021E3F0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2464 8021E3F4 0000012C */  .byte     0x00, 0x00, 0x01, 0x2c
/* 6D2468 8021E3F8 00000043 */  sra       $zero, $zero, 1
/* 6D246C 8021E3FC 00000003 */  sra       $zero, $zero, 0
/* 6D2470 8021E400 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D2474 8021E404 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2478 8021E408 00000002 */  srl       $zero, $zero, 0
/* 6D247C 8021E40C 00000046 */  rotrv     $zero, $zero, $zero
/* 6D2480 8021E410 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2484 8021E414 8021C668 */  lb        $at, -0x3998($at)
/* 6D2488 8021E418 00000012 */  mflo      $zero
/* 6D248C 8021E41C 00000000 */  nop       
/* 6D2490 8021E420 00000043 */  sra       $zero, $zero, 1
/* 6D2494 8021E424 00000003 */  sra       $zero, $zero, 0
/* 6D2498 8021E428 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D249C 8021E42C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D24A0 8021E430 00000001 */  movf      $zero, $zero, $fcc0
/* 6D24A4 8021E434 00000046 */  rotrv     $zero, $zero, $zero
/* 6D24A8 8021E438 00000001 */  movf      $zero, $zero, $fcc0
/* 6D24AC 8021E43C 8021B914 */  lb        $at, -0x46ec($at)
/* 6D24B0 8021E440 00000013 */  mtlo      $zero
/* 6D24B4 8021E444 00000000 */  nop       
/* 6D24B8 8021E448 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D24BC 8021E44C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D24C0 8021E450 00000001 */  movf      $zero, $zero, $fcc0
/* 6D24C4 8021E454 00000043 */  sra       $zero, $zero, 1
/* 6D24C8 8021E458 00000004 */  sllv      $zero, $zero, $zero
/* 6D24CC 8021E45C 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D24D0 8021E460 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D24D4 8021E464 00000001 */  movf      $zero, $zero, $fcc0
/* 6D24D8 8021E468 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D24DC 8021E46C 00000014 */  dsllv     $zero, $zero, $zero
/* 6D24E0 8021E470 00000001 */  movf      $zero, $zero, $fcc0
/* 6D24E4 8021E474 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D24E8 8021E478 0000001D */  dmultu    $zero, $zero
/* 6D24EC 8021E47C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D24F0 8021E480 00000000 */  nop       
/* 6D24F4 8021E484 0000001D */  dmultu    $zero, $zero
/* 6D24F8 8021E488 00000001 */  movf      $zero, $zero, $fcc0
/* 6D24FC 8021E48C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2500 8021E490 00000043 */  sra       $zero, $zero, 1
/* 6D2504 8021E494 00000004 */  sllv      $zero, $zero, $zero
/* 6D2508 8021E498 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D250C 8021E49C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2510 8021E4A0 00000002 */  srl       $zero, $zero, 0
/* 6D2514 8021E4A4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2518 8021E4A8 00000014 */  dsllv     $zero, $zero, $zero
/* 6D251C 8021E4AC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2520 8021E4B0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2524 8021E4B4 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D2528 8021E4B8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D252C 8021E4BC 00000000 */  nop       
/* 6D2530 8021E4C0 00000043 */  sra       $zero, $zero, 1
/* 6D2534 8021E4C4 00000003 */  sra       $zero, $zero, 0
/* 6D2538 8021E4C8 8026F694 */  lb        $a2, -0x96c($at)
/* 6D253C 8021E4CC 00000004 */  sllv      $zero, $zero, $zero
/* 6D2540 8021E4D0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D2544 8021E4D4 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D2548 8021E4D8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D254C 8021E4DC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2550 8021E4E0 00000043 */  sra       $zero, $zero, 1
/* 6D2554 8021E4E4 00000003 */  sra       $zero, $zero, 0
/* 6D2558 8021E4E8 8026F694 */  lb        $a2, -0x96c($at)
/* 6D255C 8021E4EC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D2560 8021E4F0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D2564 8021E4F4 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D2568 8021E4F8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D256C 8021E4FC 00000002 */  srl       $zero, $zero, 0
/* 6D2570 8021E500 00000043 */  sra       $zero, $zero, 1
/* 6D2574 8021E504 00000003 */  sra       $zero, $zero, 0
/* 6D2578 8021E508 8026F694 */  lb        $a2, -0x96c($at)
/* 6D257C 8021E50C 00000006 */  srlv      $zero, $zero, $zero
/* 6D2580 8021E510 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D2584 8021E514 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D2588 8021E518 00000001 */  movf      $zero, $zero, $fcc0
/* 6D258C 8021E51C 00000003 */  sra       $zero, $zero, 0
/* 6D2590 8021E520 00000043 */  sra       $zero, $zero, 1
/* 6D2594 8021E524 00000003 */  sra       $zero, $zero, 0
/* 6D2598 8021E528 8026F694 */  lb        $a2, -0x96c($at)
/* 6D259C 8021E52C 00000007 */  srav      $zero, $zero, $zero
/* 6D25A0 8021E530 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D25A4 8021E534 00000023 */  negu      $zero, $zero
/* 6D25A8 8021E538 00000000 */  nop       
/* 6D25AC 8021E53C 0000000F */  sync      
/* 6D25B0 8021E540 00000002 */  srl       $zero, $zero, 0
/* 6D25B4 8021E544 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D25B8 8021E548 00000002 */  srl       $zero, $zero, 0
/* 6D25BC 8021E54C 00000043 */  sra       $zero, $zero, 1
/* 6D25C0 8021E550 00000003 */  sra       $zero, $zero, 0
/* 6D25C4 8021E554 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D25C8 8021E558 000003E8 */  .byte     0x00, 0x00, 0x03, 0xe8
/* 6D25CC 8021E55C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D25D0 8021E560 0000000C */  syscall   
/* 6D25D4 8021E564 00000002 */  srl       $zero, $zero, 0
/* 6D25D8 8021E568 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D25DC 8021E56C 0000012C */  .byte     0x00, 0x00, 0x01, 0x2c
/* 6D25E0 8021E570 00000043 */  sra       $zero, $zero, 1
/* 6D25E4 8021E574 00000003 */  sra       $zero, $zero, 0
/* 6D25E8 8021E578 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D25EC 8021E57C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D25F0 8021E580 00000002 */  srl       $zero, $zero, 0
/* 6D25F4 8021E584 00000046 */  rotrv     $zero, $zero, $zero
/* 6D25F8 8021E588 00000001 */  movf      $zero, $zero, $fcc0
/* 6D25FC 8021E58C 8021C668 */  lb        $at, -0x3998($at)
/* 6D2600 8021E590 00000012 */  mflo      $zero
/* 6D2604 8021E594 00000000 */  nop       
/* 6D2608 8021E598 00000043 */  sra       $zero, $zero, 1
/* 6D260C 8021E59C 00000003 */  sra       $zero, $zero, 0
/* 6D2610 8021E5A0 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D2614 8021E5A4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2618 8021E5A8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D261C 8021E5AC 00000046 */  rotrv     $zero, $zero, $zero
/* 6D2620 8021E5B0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2624 8021E5B4 8021B914 */  lb        $at, -0x46ec($at)
/* 6D2628 8021E5B8 00000013 */  mtlo      $zero
/* 6D262C 8021E5BC 00000000 */  nop       
/* 6D2630 8021E5C0 00000002 */  srl       $zero, $zero, 0
/* 6D2634 8021E5C4 00000000 */  nop       
/* 6D2638 8021E5C8 00000013 */  mtlo      $zero
/* 6D263C 8021E5CC 00000000 */  nop       
/* 6D2640 8021E5D0 00000020 */  add       $zero, $zero, $zero
/* 6D2644 8021E5D4 00000000 */  nop       
/* 6D2648 8021E5D8 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D264C 8021E5DC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2650 8021E5E0 00000002 */  srl       $zero, $zero, 0
/* 6D2654 8021E5E4 00000046 */  rotrv     $zero, $zero, $zero
/* 6D2658 8021E5E8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D265C 8021E5EC 8021B914 */  lb        $at, -0x46ec($at)
/* 6D2660 8021E5F0 00000002 */  srl       $zero, $zero, 0
/* 6D2664 8021E5F4 00000000 */  nop       
/* 6D2668 8021E5F8 00000023 */  negu      $zero, $zero
/* 6D266C 8021E5FC 00000000 */  nop       
/* 6D2670 8021E600 00000046 */  rotrv     $zero, $zero, $zero
/* 6D2674 8021E604 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2678 8021E608 8021D38C */  lb        $at, -0x2c74($at)
/* 6D267C 8021E60C 0000000A */  movz      $zero, $zero, $zero
/* 6D2680 8021E610 00000002 */  srl       $zero, $zero, 0
/* 6D2684 8021E614 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D2688 8021E618 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D268C 8021E61C 00000046 */  rotrv     $zero, $zero, $zero
/* 6D2690 8021E620 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2694 8021E624 8021B914 */  lb        $at, -0x46ec($at)
/* 6D2698 8021E628 00000002 */  srl       $zero, $zero, 0
/* 6D269C 8021E62C 00000000 */  nop       
/* 6D26A0 8021E630 00000013 */  mtlo      $zero
/* 6D26A4 8021E634 00000000 */  nop       
/* 6D26A8 8021E638 00000046 */  rotrv     $zero, $zero, $zero
/* 6D26AC 8021E63C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D26B0 8021E640 8021DCE4 */  lb        $at, -0x231c($at)
/* 6D26B4 8021E644 00000014 */  dsllv     $zero, $zero, $zero
/* 6D26B8 8021E648 00000001 */  movf      $zero, $zero, $fcc0
/* 6D26BC 8021E64C FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D26C0 8021E650 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D26C4 8021E654 00000001 */  movf      $zero, $zero, $fcc0
/* 6D26C8 8021E658 00000001 */  movf      $zero, $zero, $fcc0
/* 6D26CC 8021E65C 00000043 */  sra       $zero, $zero, 1
/* 6D26D0 8021E660 00000003 */  sra       $zero, $zero, 0
/* 6D26D4 8021E664 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D26D8 8021E668 000003E8 */  .byte     0x00, 0x00, 0x03, 0xe8
/* 6D26DC 8021E66C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D26E0 8021E670 0000000C */  syscall   
/* 6D26E4 8021E674 00000002 */  srl       $zero, $zero, 0
/* 6D26E8 8021E678 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D26EC 8021E67C 00000190 */  .byte     0x00, 0x00, 0x01, 0x90
/* 6D26F0 8021E680 00000046 */  rotrv     $zero, $zero, $zero
/* 6D26F4 8021E684 00000001 */  movf      $zero, $zero, $fcc0
/* 6D26F8 8021E688 8021D6C4 */  lb        $at, -0x293c($at)
/* 6D26FC 8021E68C 00000002 */  srl       $zero, $zero, 0
/* 6D2700 8021E690 00000000 */  nop       
/* 6D2704 8021E694 00000013 */  mtlo      $zero
/* 6D2708 8021E698 00000000 */  nop       
/* 6D270C 8021E69C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D2710 8021E6A0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2714 8021E6A4 00000002 */  srl       $zero, $zero, 0
/* 6D2718 8021E6A8 00000043 */  sra       $zero, $zero, 1
/* 6D271C 8021E6AC 00000003 */  sra       $zero, $zero, 0
/* 6D2720 8021E6B0 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D2724 8021E6B4 000003E8 */  .byte     0x00, 0x00, 0x03, 0xe8
/* 6D2728 8021E6B8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D272C 8021E6BC 0000000C */  syscall   
/* 6D2730 8021E6C0 00000002 */  srl       $zero, $zero, 0
/* 6D2734 8021E6C4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2738 8021E6C8 000000C8 */  .byte     0x00, 0x00, 0x00, 0xc8
/* 6D273C 8021E6CC 00000046 */  rotrv     $zero, $zero, $zero
/* 6D2740 8021E6D0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2744 8021E6D4 8021D6C4 */  lb        $at, -0x293c($at)
/* 6D2748 8021E6D8 00000002 */  srl       $zero, $zero, 0
/* 6D274C 8021E6DC 00000000 */  nop       
/* 6D2750 8021E6E0 00000013 */  mtlo      $zero
/* 6D2754 8021E6E4 00000000 */  nop       
/* 6D2758 8021E6E8 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D275C 8021E6EC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2760 8021E6F0 00000003 */  sra       $zero, $zero, 0
/* 6D2764 8021E6F4 00000043 */  sra       $zero, $zero, 1
/* 6D2768 8021E6F8 00000003 */  sra       $zero, $zero, 0
/* 6D276C 8021E6FC 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D2770 8021E700 000003E8 */  .byte     0x00, 0x00, 0x03, 0xe8
/* 6D2774 8021E704 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2778 8021E708 0000000C */  syscall   
/* 6D277C 8021E70C 00000002 */  srl       $zero, $zero, 0
/* 6D2780 8021E710 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2784 8021E714 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6D2788 8021E718 00000046 */  rotrv     $zero, $zero, $zero
/* 6D278C 8021E71C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2790 8021E720 8021D6C4 */  lb        $at, -0x293c($at)
/* 6D2794 8021E724 00000002 */  srl       $zero, $zero, 0
/* 6D2798 8021E728 00000000 */  nop       
/* 6D279C 8021E72C 00000013 */  mtlo      $zero
/* 6D27A0 8021E730 00000000 */  nop       
/* 6D27A4 8021E734 00000023 */  negu      $zero, $zero
/* 6D27A8 8021E738 00000000 */  nop       
/* 6D27AC 8021E73C 00000046 */  rotrv     $zero, $zero, $zero
/* 6D27B0 8021E740 00000001 */  movf      $zero, $zero, $fcc0
/* 6D27B4 8021E744 8021B914 */  lb        $at, -0x46ec($at)
/* 6D27B8 8021E748 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D27BC 8021E74C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D27C0 8021E750 00000002 */  srl       $zero, $zero, 0
/* 6D27C4 8021E754 00000046 */  rotrv     $zero, $zero, $zero
/* 6D27C8 8021E758 00000001 */  movf      $zero, $zero, $fcc0
/* 6D27CC 8021E75C 8021C668 */  lb        $at, -0x3998($at)
/* 6D27D0 8021E760 00000023 */  negu      $zero, $zero
/* 6D27D4 8021E764 00000000 */  nop       
/* 6D27D8 8021E768 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D27DC 8021E76C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D27E0 8021E770 00000001 */  movf      $zero, $zero, $fcc0
/* 6D27E4 8021E774 00000043 */  sra       $zero, $zero, 1
/* 6D27E8 8021E778 00000003 */  sra       $zero, $zero, 0
/* 6D27EC 8021E77C 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D27F0 8021E780 00000001 */  movf      $zero, $zero, $fcc0
/* 6D27F4 8021E784 00000001 */  movf      $zero, $zero, $fcc0
/* 6D27F8 8021E788 00000046 */  rotrv     $zero, $zero, $zero
/* 6D27FC 8021E78C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2800 8021E790 8021B914 */  lb        $at, -0x46ec($at)
/* 6D2804 8021E794 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D2808 8021E798 00000001 */  movf      $zero, $zero, $fcc0
/* 6D280C 8021E79C 00000002 */  srl       $zero, $zero, 0
/* 6D2810 8021E7A0 00000046 */  rotrv     $zero, $zero, $zero
/* 6D2814 8021E7A4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2818 8021E7A8 8021C668 */  lb        $at, -0x3998($at)
/* 6D281C 8021E7AC 00000023 */  negu      $zero, $zero
/* 6D2820 8021E7B0 00000000 */  nop       
/* 6D2824 8021E7B4 00000002 */  srl       $zero, $zero, 0
/* 6D2828 8021E7B8 00000000 */  nop       
/* 6D282C 8021E7BC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2830 8021E7C0 00000000 */  nop       
/* 6D2834 8021E7C4 00000000 */  nop       
/* 6D2838 8021E7C8 00000000 */  nop       
/* 6D283C 8021E7CC 00000000 */  nop       
/* 6D2840 8021E7D0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2844 8021E7D4 00000000 */  nop       
/* 6D2848 8021E7D8 00000000 */  nop       
/* 6D284C 8021E7DC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2850 8021E7E0 00000000 */  nop       
/* 6D2854 8021E7E4 00000000 */  nop       
/* 6D2858 8021E7E8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D285C 8021E7EC 00000000 */  nop       
/* 6D2860 8021E7F0 00000002 */  srl       $zero, $zero, 0
/* 6D2864 8021E7F4 00000000 */  nop       
/* 6D2868 8021E7F8 00000006 */  srlv      $zero, $zero, $zero
/* 6D286C 8021E7FC 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D2870 8021E800 00000009 */  jr        $zero
/* 6D2874 8021E804 00000032 */   tlt      $zero, $zero
/* 6D2878 8021E808 00000007 */  srav      $zero, $zero, $zero
/* 6D287C 8021E80C 00000000 */  nop       
/* 6D2880 8021E810 00000004 */  sllv      $zero, $zero, $zero
/* 6D2884 8021E814 0000004B */  .byte     0x00, 0x00, 0x00, 0x4b
/* 6D2888 8021E818 00000003 */  sra       $zero, $zero, 0
/* 6D288C 8021E81C 00000000 */  nop       
/* 6D2890 8021E820 0000000B */  movn      $zero, $zero, $zero
/* 6D2894 8021E824 00000032 */  tlt       $zero, $zero
/* 6D2898 8021E828 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D289C 8021E82C 0000004B */  .byte     0x00, 0x00, 0x00, 0x4b
/* 6D28A0 8021E830 0000000A */  movz      $zero, $zero, $zero
/* 6D28A4 8021E834 0000003C */  dsll32    $zero, $zero, 0
/* 6D28A8 8021E838 00000008 */  jr        $zero
/* 6D28AC 8021E83C 00000050 */   .byte    0x00, 0x00, 0x00, 0x50
/* 6D28B0 8021E840 0000001F */  ddivu     $zero, $zero, $zero
/* 6D28B4 8021E844 00000000 */  nop       
/* 6D28B8 8021E848 00000020 */  add       $zero, $zero, $zero
/* 6D28BC 8021E84C FFFFFFFF */  sd        $ra, -1($ra)
/* 6D28C0 8021E850 00000025 */  or        $zero, $zero, $zero
/* 6D28C4 8021E854 00000000 */  nop       
/* 6D28C8 8021E858 00000022 */  neg       $zero, $zero
/* 6D28CC 8021E85C 00000000 */  nop       
/* 6D28D0 8021E860 00000024 */  and       $zero, $zero, $zero
/* 6D28D4 8021E864 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D28D8 8021E868 00000023 */  negu      $zero, $zero
/* 6D28DC 8021E86C 00000000 */  nop       
/* 6D28E0 8021E870 00000021 */  addu      $zero, $zero, $zero
/* 6D28E4 8021E874 00000000 */  nop       
/* 6D28E8 8021E878 00000026 */  xor       $zero, $zero, $zero
/* 6D28EC 8021E87C FFFFFFFF */  sd        $ra, -1($ra)
/* 6D28F0 8021E880 00000027 */  not       $zero, $zero
/* 6D28F4 8021E884 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D28F8 8021E888 00000029 */  .byte     0x00, 0x00, 0x00, 0x29
/* 6D28FC 8021E88C FFFFFFFE */  sd        $ra, -2($ra)
/* 6D2900 8021E890 00000000 */  nop       
/* 6D2904 8021E894 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2908 8021E898 00000000 */  nop       
/* 6D290C 8021E89C 00000002 */  srl       $zero, $zero, 0
/* 6D2910 8021E8A0 00000000 */  nop       
/* 6D2914 8021E8A4 00000006 */  srlv      $zero, $zero, $zero
/* 6D2918 8021E8A8 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D291C 8021E8AC 00000009 */  jr        $zero
/* 6D2920 8021E8B0 00000032 */   tlt      $zero, $zero
/* 6D2924 8021E8B4 00000007 */  srav      $zero, $zero, $zero
/* 6D2928 8021E8B8 00000000 */  nop       
/* 6D292C 8021E8BC 00000004 */  sllv      $zero, $zero, $zero
/* 6D2930 8021E8C0 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6D2934 8021E8C4 00000003 */  sra       $zero, $zero, 0
/* 6D2938 8021E8C8 00000000 */  nop       
/* 6D293C 8021E8CC 0000000B */  movn      $zero, $zero, $zero
/* 6D2940 8021E8D0 00000032 */  tlt       $zero, $zero
/* 6D2944 8021E8D4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D2948 8021E8D8 0000004B */  .byte     0x00, 0x00, 0x00, 0x4b
/* 6D294C 8021E8DC 0000000A */  movz      $zero, $zero, $zero
/* 6D2950 8021E8E0 0000003C */  dsll32    $zero, $zero, 0
/* 6D2954 8021E8E4 00000008 */  jr        $zero
/* 6D2958 8021E8E8 00000050 */   .byte    0x00, 0x00, 0x00, 0x50
/* 6D295C 8021E8EC 0000001F */  ddivu     $zero, $zero, $zero
/* 6D2960 8021E8F0 00000000 */  nop       
/* 6D2964 8021E8F4 00000020 */  add       $zero, $zero, $zero
/* 6D2968 8021E8F8 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D296C 8021E8FC 00000025 */  or        $zero, $zero, $zero
/* 6D2970 8021E900 00000000 */  nop       
/* 6D2974 8021E904 00000022 */  neg       $zero, $zero
/* 6D2978 8021E908 00000000 */  nop       
/* 6D297C 8021E90C 00000024 */  and       $zero, $zero, $zero
/* 6D2980 8021E910 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D2984 8021E914 00000023 */  negu      $zero, $zero
/* 6D2988 8021E918 00000000 */  nop       
/* 6D298C 8021E91C 00000021 */  addu      $zero, $zero, $zero
/* 6D2990 8021E920 00000000 */  nop       
/* 6D2994 8021E924 00000026 */  xor       $zero, $zero, $zero
/* 6D2998 8021E928 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D299C 8021E92C 00000027 */  not       $zero, $zero
/* 6D29A0 8021E930 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D29A4 8021E934 00000029 */  .byte     0x00, 0x00, 0x00, 0x29
/* 6D29A8 8021E938 FFFFFFFE */  sd        $ra, -2($ra)
/* 6D29AC 8021E93C 00000000 */  nop       
/* 6D29B0 8021E940 00800000 */  .byte     0x00, 0x80, 0x00, 0x00
/* 6D29B4 8021E944 01000000 */  .byte     0x01, 0x00, 0x00, 0x00
/* 6D29B8 8021E948 022300FF */  .byte     0x02, 0x23, 0x00, 0xff
/* 6D29BC 8021E94C 8021EA20 */  lb        $at, -0x15e0($at)
/* 6D29C0 8021E950 8021E7D0 */  lb        $at, -0x1830($at)
/* 6D29C4 8021E954 00000000 */  nop       
/* 6D29C8 8021E958 00000000 */  nop       
/* 6D29CC 8021E95C FBF40000 */  bbit132   $ra, 0x14, .L8021E960
.L8021E960:
/* 6D29D0 8021E960 00000000 */   nop      
/* 6D29D4 8021E964 00020001 */  .byte     0x00, 0x02, 0x00, 0x01
/* 6D29D8 8021E968 01000000 */  .byte     0x01, 0x00, 0x00, 0x00
/* 6D29DC 8021E96C 022300FF */  .byte     0x02, 0x23, 0x00, 0xff
/* 6D29E0 8021E970 8021EA20 */  lb        $at, -0x15e0($at)
/* 6D29E4 8021E974 8021E7DC */  lb        $at, -0x1824($at)
/* 6D29E8 8021E978 00000000 */  nop       
/* 6D29EC 8021E97C 00000000 */  nop       
/* 6D29F0 8021E980 FBF40000 */  bbit132   $ra, 0x14, .L8021E984
.L8021E984:
/* 6D29F4 8021E984 00000000 */   nop      
/* 6D29F8 8021E988 00800000 */  .byte     0x00, 0x80, 0x00, 0x00
/* 6D29FC 8021E98C 02000000 */  .byte     0x02, 0x00, 0x00, 0x00
/* 6D2A00 8021E990 F62300FF */  sdc1      $f3, 0xff($s1)
/* 6D2A04 8021E994 8021EA6C */  lb        $at, -0x1594($at)
/* 6D2A08 8021E998 8021E7DC */  lb        $at, -0x1824($at)
/* 6D2A0C 8021E99C 00800000 */  .byte     0x00, 0x80, 0x00, 0x00
/* 6D2A10 8021E9A0 00000000 */  nop       
/* 6D2A14 8021E9A4 00F80000 */  .byte     0x00, 0xf8, 0x00, 0x00
/* 6D2A18 8021E9A8 00000000 */  nop       
/* 6D2A1C 8021E9AC 00020001 */  .byte     0x00, 0x02, 0x00, 0x01
/* 6D2A20 8021E9B0 03000000 */  .byte     0x03, 0x00, 0x00, 0x00
/* 6D2A24 8021E9B4 000000FF */  dsra32    $zero, $zero, 3
/* 6D2A28 8021E9B8 8021EAB8 */  lb        $at, -0x1548($at)
/* 6D2A2C 8021E9BC 8021E7DC */  lb        $at, -0x1824($at)
/* 6D2A30 8021E9C0 00000000 */  nop       
/* 6D2A34 8021E9C4 00000000 */  nop       
/* 6D2A38 8021E9C8 00000000 */  nop       
/* 6D2A3C 8021E9CC 00000000 */  nop       
/* 6D2A40 8021E9D0 00000000 */  nop       
/* 6D2A44 8021E9D4 004D1A0B */  .byte     0x00, 0x4d, 0x1a, 0x0b
/* 6D2A48 8021E9D8 00010000 */  sll       $zero, $at, 0
/* 6D2A4C 8021E9DC 8021E940 */  lb        $at, -0x16c0($at)
/* 6D2A50 8021E9E0 8021F610 */  lb        $at, -0x9f0($at)
/* 6D2A54 8021E9E4 8021E7E8 */  lb        $at, -0x1818($at)
/* 6D2A58 8021E9E8 28504628 */  slti      $s0, $v0, 0x4628
/* 6D2A5C 8021E9EC 5F005002 */  bgtzl     $t8, .L802329F8
/* 6D2A60 8021E9F0 24280000 */   addiu    $t0, $at, 0
/* 6D2A64 8021E9F4 F6140A20 */  sdc1      $f20, 0xa20($s0)
/* 6D2A68 8021E9F8 00000200 */  sll       $zero, $zero, 8
/* 6D2A6C 8021E9FC 004E1A0B */  .byte     0x00, 0x4e, 0x1a, 0x0b
/* 6D2A70 8021EA00 00030000 */  sll       $zero, $v1, 0
/* 6D2A74 8021EA04 8021E964 */  lb        $at, -0x169c($at)
/* 6D2A78 8021EA08 8021F7D0 */  lb        $at, -0x830($at)
/* 6D2A7C 8021EA0C 8021E894 */  lb        $at, -0x176c($at)
/* 6D2A80 8021EA10 28554B28 */  slti      $s5, $v0, 0x4b28
/* 6D2A84 8021EA14 5F005002 */  bgtzl     $t8, .L80232A20
/* 6D2A88 8021EA18 30280000 */   andi     $t0, $at, 0
/* 6D2A8C 8021EA1C E7140122 */  swc1      $f20, 0x122($t8)
/* 6D2A90 8021EA20 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2A94 8021EA24 00560001 */  .byte     0x00, 0x56, 0x00, 0x01
/* 6D2A98 8021EA28 0000000C */  syscall   
/* 6D2A9C 8021EA2C 00560000 */  .byte     0x00, 0x56, 0x00, 0x00
/* 6D2AA0 8021EA30 00000006 */  srlv      $zero, $zero, $zero
/* 6D2AA4 8021EA34 00560008 */  .byte     0x00, 0x56, 0x00, 0x08
/* 6D2AA8 8021EA38 00000009 */  jr        $zero
/* 6D2AAC 8021EA3C 00560001 */   .byte    0x00, 0x56, 0x00, 0x01
/* 6D2AB0 8021EA40 00000008 */  jr        $zero
/* 6D2AB4 8021EA44 00560000 */   .byte    0x00, 0x56, 0x00, 0x00
/* 6D2AB8 8021EA48 0000000B */  movn      $zero, $zero, $zero
/* 6D2ABC 8021EA4C 00560001 */  .byte     0x00, 0x56, 0x00, 0x01
/* 6D2AC0 8021EA50 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D2AC4 8021EA54 00560000 */  .byte     0x00, 0x56, 0x00, 0x00
/* 6D2AC8 8021EA58 00000004 */  sllv      $zero, $zero, $zero
/* 6D2ACC 8021EA5C 00560007 */  srav      $zero, $s6, $v0
/* 6D2AD0 8021EA60 00000003 */  sra       $zero, $zero, 0
/* 6D2AD4 8021EA64 00560007 */  srav      $zero, $s6, $v0
/* 6D2AD8 8021EA68 00000000 */  nop       
/* 6D2ADC 8021EA6C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2AE0 8021EA70 00570001 */  .byte     0x00, 0x57, 0x00, 0x01
/* 6D2AE4 8021EA74 0000000C */  syscall   
/* 6D2AE8 8021EA78 00570000 */  .byte     0x00, 0x57, 0x00, 0x00
/* 6D2AEC 8021EA7C 00000006 */  srlv      $zero, $zero, $zero
/* 6D2AF0 8021EA80 00570008 */  .byte     0x00, 0x57, 0x00, 0x08
/* 6D2AF4 8021EA84 00000009 */  jr        $zero
/* 6D2AF8 8021EA88 00570001 */   .byte    0x00, 0x57, 0x00, 0x01
/* 6D2AFC 8021EA8C 00000008 */  jr        $zero
/* 6D2B00 8021EA90 00570000 */   .byte    0x00, 0x57, 0x00, 0x00
/* 6D2B04 8021EA94 0000000B */  movn      $zero, $zero, $zero
/* 6D2B08 8021EA98 00570001 */  .byte     0x00, 0x57, 0x00, 0x01
/* 6D2B0C 8021EA9C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D2B10 8021EAA0 00570000 */  .byte     0x00, 0x57, 0x00, 0x00
/* 6D2B14 8021EAA4 00000004 */  sllv      $zero, $zero, $zero
/* 6D2B18 8021EAA8 00570007 */  srav      $zero, $s7, $v0
/* 6D2B1C 8021EAAC 00000003 */  sra       $zero, $zero, 0
/* 6D2B20 8021EAB0 00570007 */  srav      $zero, $s7, $v0
/* 6D2B24 8021EAB4 00000000 */  nop       
/* 6D2B28 8021EAB8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2B2C 8021EABC 0057000A */  movz      $zero, $v0, $s7
/* 6D2B30 8021EAC0 00000000 */  nop       
/* 6D2B34 8021EAC4 00000024 */  and       $zero, $zero, $zero
/* 6D2B38 8021EAC8 00000002 */  srl       $zero, $zero, 0
/* 6D2B3C 8021EACC FE363C8F */  sd        $s6, 0x3c8f($s1)
/* 6D2B40 8021EAD0 00000000 */  nop       
/* 6D2B44 8021EAD4 00000003 */  sra       $zero, $zero, 0
/* 6D2B48 8021EAD8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2B4C 8021EADC 00000000 */  nop       
/* 6D2B50 8021EAE0 00000043 */  sra       $zero, $zero, 1
/* 6D2B54 8021EAE4 00000004 */  sllv      $zero, $zero, $zero
/* 6D2B58 8021EAE8 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D2B5C 8021EAEC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2B60 8021EAF0 00000009 */  jr        $zero
/* 6D2B64 8021EAF4 FE363C80 */   sd       $s6, 0x3c80($s1)
/* 6D2B68 8021EAF8 00000043 */  sra       $zero, $zero, 1
/* 6D2B6C 8021EAFC 00000003 */  sra       $zero, $zero, 0
/* 6D2B70 8021EB00 8026DE5C */  lb        $a2, -0x21a4($at)
/* 6D2B74 8021EB04 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2B78 8021EB08 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D2B7C 8021EB0C 0000000A */  movz      $zero, $zero, $zero
/* 6D2B80 8021EB10 00000002 */  srl       $zero, $zero, 0
/* 6D2B84 8021EB14 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D2B88 8021EB18 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2B8C 8021EB1C 00000043 */  sra       $zero, $zero, 1
/* 6D2B90 8021EB20 00000008 */  jr        $zero
/* 6D2B94 8021EB24 802182A8 */   lb       $at, -0x7d58($at)
/* 6D2B98 8021EB28 FE363C8F */  sd        $s6, 0x3c8f($s1)
/* 6D2B9C 8021EB2C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D2BA0 8021EB30 F24E7280 */  scd       $t6, 0x7280($s2)
/* 6D2BA4 8021EB34 F24C0A80 */  scd       $t4, 0xa80($s2)
/* 6D2BA8 8021EB38 00000014 */  dsllv     $zero, $zero, $zero
/* 6D2BAC 8021EB3C 00000000 */  nop       
/* 6D2BB0 8021EB40 00000000 */  nop       
/* 6D2BB4 8021EB44 00000027 */  not       $zero, $zero
/* 6D2BB8 8021EB48 00000002 */  srl       $zero, $zero, 0
/* 6D2BBC 8021EB4C FE363C8F */  sd        $s6, 0x3c8f($s1)
/* 6D2BC0 8021EB50 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2BC4 8021EB54 00000043 */  sra       $zero, $zero, 1
/* 6D2BC8 8021EB58 00000003 */  sra       $zero, $zero, 0
/* 6D2BCC 8021EB5C 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D2BD0 8021EB60 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2BD4 8021EB64 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D2BD8 8021EB68 00000010 */  mfhi      $zero
/* 6D2BDC 8021EB6C 00000002 */  srl       $zero, $zero, 0
/* 6D2BE0 8021EB70 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D2BE4 8021EB74 00000200 */  sll       $zero, $zero, 8
/* 6D2BE8 8021EB78 00000043 */  sra       $zero, $zero, 1
/* 6D2BEC 8021EB7C 00000004 */  sllv      $zero, $zero, $zero
/* 6D2BF0 8021EB80 8026F470 */  lb        $a2, -0xb90($at)
/* 6D2BF4 8021EB84 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2BF8 8021EB88 00000002 */  srl       $zero, $zero, 0
/* 6D2BFC 8021EB8C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D2C00 8021EB90 00000043 */  sra       $zero, $zero, 1
/* 6D2C04 8021EB94 00000004 */  sllv      $zero, $zero, $zero
/* 6D2C08 8021EB98 8026F470 */  lb        $a2, -0xb90($at)
/* 6D2C0C 8021EB9C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2C10 8021EBA0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2C14 8021EBA4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D2C18 8021EBA8 00000012 */  mflo      $zero
/* 6D2C1C 8021EBAC 00000000 */  nop       
/* 6D2C20 8021EBB0 00000043 */  sra       $zero, $zero, 1
/* 6D2C24 8021EBB4 00000004 */  sllv      $zero, $zero, $zero
/* 6D2C28 8021EBB8 8026F470 */  lb        $a2, -0xb90($at)
/* 6D2C2C 8021EBBC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2C30 8021EBC0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2C34 8021EBC4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D2C38 8021EBC8 00000043 */  sra       $zero, $zero, 1
/* 6D2C3C 8021EBCC 00000004 */  sllv      $zero, $zero, $zero
/* 6D2C40 8021EBD0 8026F470 */  lb        $a2, -0xb90($at)
/* 6D2C44 8021EBD4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2C48 8021EBD8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2C4C 8021EBDC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D2C50 8021EBE0 00000013 */  mtlo      $zero
/* 6D2C54 8021EBE4 00000000 */  nop       
/* 6D2C58 8021EBE8 00000012 */  mflo      $zero
/* 6D2C5C 8021EBEC 00000000 */  nop       
/* 6D2C60 8021EBF0 00000024 */  and       $zero, $zero, $zero
/* 6D2C64 8021EBF4 00000002 */  srl       $zero, $zero, 0
/* 6D2C68 8021EBF8 FE363C8F */  sd        $s6, 0x3c8f($s1)
/* 6D2C6C 8021EBFC 00000000 */  nop       
/* 6D2C70 8021EC00 00000043 */  sra       $zero, $zero, 1
/* 6D2C74 8021EC04 00000003 */  sra       $zero, $zero, 0
/* 6D2C78 8021EC08 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D2C7C 8021EC0C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2C80 8021EC10 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D2C84 8021EC14 00000010 */  mfhi      $zero
/* 6D2C88 8021EC18 00000002 */  srl       $zero, $zero, 0
/* 6D2C8C 8021EC1C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D2C90 8021EC20 00000200 */  sll       $zero, $zero, 8
/* 6D2C94 8021EC24 00000043 */  sra       $zero, $zero, 1
/* 6D2C98 8021EC28 00000004 */  sllv      $zero, $zero, $zero
/* 6D2C9C 8021EC2C 8026F470 */  lb        $a2, -0xb90($at)
/* 6D2CA0 8021EC30 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2CA4 8021EC34 00000002 */  srl       $zero, $zero, 0
/* 6D2CA8 8021EC38 000000FF */  dsra32    $zero, $zero, 3
/* 6D2CAC 8021EC3C 00000012 */  mflo      $zero
/* 6D2CB0 8021EC40 00000000 */  nop       
/* 6D2CB4 8021EC44 00000043 */  sra       $zero, $zero, 1
/* 6D2CB8 8021EC48 00000004 */  sllv      $zero, $zero, $zero
/* 6D2CBC 8021EC4C 8026F470 */  lb        $a2, -0xb90($at)
/* 6D2CC0 8021EC50 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2CC4 8021EC54 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2CC8 8021EC58 000000FF */  dsra32    $zero, $zero, 3
/* 6D2CCC 8021EC5C 00000013 */  mtlo      $zero
/* 6D2CD0 8021EC60 00000000 */  nop       
/* 6D2CD4 8021EC64 00000013 */  mtlo      $zero
/* 6D2CD8 8021EC68 00000000 */  nop       
/* 6D2CDC 8021EC6C 00000008 */  jr        $zero
/* 6D2CE0 8021EC70 00000001 */   movf     $zero, $zero, $fcc0
/* 6D2CE4 8021EC74 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2CE8 8021EC78 00000004 */  sllv      $zero, $zero, $zero
/* 6D2CEC 8021EC7C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2CF0 8021EC80 00000000 */  nop       
/* 6D2CF4 8021EC84 00000002 */  srl       $zero, $zero, 0
/* 6D2CF8 8021EC88 00000000 */  nop       
/* 6D2CFC 8021EC8C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2D00 8021EC90 00000000 */  nop       
/* 6D2D04 8021EC94 00000043 */  sra       $zero, $zero, 1
/* 6D2D08 8021EC98 00000002 */  srl       $zero, $zero, 0
/* 6D2D0C 8021EC9C 8026CD10 */  lb        $a2, -0x32f0($at)
/* 6D2D10 8021ECA0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2D14 8021ECA4 00000011 */  mthi      $zero
/* 6D2D18 8021ECA8 00000002 */  srl       $zero, $zero, 0
/* 6D2D1C 8021ECAC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2D20 8021ECB0 00080000 */  sll       $zero, $t0, 0
/* 6D2D24 8021ECB4 00000010 */  mfhi      $zero
/* 6D2D28 8021ECB8 00000002 */  srl       $zero, $zero, 0
/* 6D2D2C 8021ECBC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2D30 8021ECC0 00000240 */  sll       $zero, $zero, 9
/* 6D2D34 8021ECC4 00000043 */  sra       $zero, $zero, 1
/* 6D2D38 8021ECC8 00000004 */  sllv      $zero, $zero, $zero
/* 6D2D3C 8021ECCC 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D2D40 8021ECD0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2D44 8021ECD4 00000002 */  srl       $zero, $zero, 0
/* 6D2D48 8021ECD8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2D4C 8021ECDC 00000013 */  mtlo      $zero
/* 6D2D50 8021ECE0 00000000 */  nop       
/* 6D2D54 8021ECE4 00000012 */  mflo      $zero
/* 6D2D58 8021ECE8 00000000 */  nop       
/* 6D2D5C 8021ECEC 00000043 */  sra       $zero, $zero, 1
/* 6D2D60 8021ECF0 00000002 */  srl       $zero, $zero, 0
/* 6D2D64 8021ECF4 80218438 */  lb        $at, -0x7bc8($at)
/* 6D2D68 8021ECF8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2D6C 8021ECFC 00000014 */  dsllv     $zero, $zero, $zero
/* 6D2D70 8021ED00 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2D74 8021ED04 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2D78 8021ED08 0000001D */  dmultu    $zero, $zero
/* 6D2D7C 8021ED0C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2D80 8021ED10 00000083 */  sra       $zero, $zero, 2
/* 6D2D84 8021ED14 0000001D */  dmultu    $zero, $zero
/* 6D2D88 8021ED18 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2D8C 8021ED1C 00000084 */  .byte     0x00, 0x00, 0x00, 0x84
/* 6D2D90 8021ED20 0000001D */  dmultu    $zero, $zero
/* 6D2D94 8021ED24 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2D98 8021ED28 00000085 */  lsa       $zero, $zero, $zero, 3
/* 6D2D9C 8021ED2C 0000001D */  dmultu    $zero, $zero
/* 6D2DA0 8021ED30 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2DA4 8021ED34 00000088 */  .byte     0x00, 0x00, 0x00, 0x88
/* 6D2DA8 8021ED38 00000043 */  sra       $zero, $zero, 1
/* 6D2DAC 8021ED3C 00000002 */  srl       $zero, $zero, 0
/* 6D2DB0 8021ED40 8026CD10 */  lb        $a2, -0x32f0($at)
/* 6D2DB4 8021ED44 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2DB8 8021ED48 00000010 */  mfhi      $zero
/* 6D2DBC 8021ED4C 00000002 */  srl       $zero, $zero, 0
/* 6D2DC0 8021ED50 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2DC4 8021ED54 00000240 */  sll       $zero, $zero, 9
/* 6D2DC8 8021ED58 00000043 */  sra       $zero, $zero, 1
/* 6D2DCC 8021ED5C 00000004 */  sllv      $zero, $zero, $zero
/* 6D2DD0 8021ED60 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D2DD4 8021ED64 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2DD8 8021ED68 00000002 */  srl       $zero, $zero, 0
/* 6D2DDC 8021ED6C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2DE0 8021ED70 00000013 */  mtlo      $zero
/* 6D2DE4 8021ED74 00000000 */  nop       
/* 6D2DE8 8021ED78 00000020 */  add       $zero, $zero, $zero
/* 6D2DEC 8021ED7C 00000000 */  nop       
/* 6D2DF0 8021ED80 00000023 */  negu      $zero, $zero
/* 6D2DF4 8021ED84 00000000 */  nop       
/* 6D2DF8 8021ED88 00000013 */  mtlo      $zero
/* 6D2DFC 8021ED8C 00000000 */  nop       
/* 6D2E00 8021ED90 00000002 */  srl       $zero, $zero, 0
/* 6D2E04 8021ED94 00000000 */  nop       
/* 6D2E08 8021ED98 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2E0C 8021ED9C 00000000 */  nop       
/* 6D2E10 8021EDA0 00000043 */  sra       $zero, $zero, 1
/* 6D2E14 8021EDA4 00000004 */  sllv      $zero, $zero, $zero
/* 6D2E18 8021EDA8 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D2E1C 8021EDAC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2E20 8021EDB0 00000002 */  srl       $zero, $zero, 0
/* 6D2E24 8021EDB4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2E28 8021EDB8 0000000A */  movz      $zero, $zero, $zero
/* 6D2E2C 8021EDBC 00000002 */  srl       $zero, $zero, 0
/* 6D2E30 8021EDC0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2E34 8021EDC4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2E38 8021EDC8 00000043 */  sra       $zero, $zero, 1
/* 6D2E3C 8021EDCC 00000004 */  sllv      $zero, $zero, $zero
/* 6D2E40 8021EDD0 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D2E44 8021EDD4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2E48 8021EDD8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2E4C 8021EDDC 00560004 */  sllv      $zero, $s6, $v0
/* 6D2E50 8021EDE0 00000004 */  sllv      $zero, $zero, $zero
/* 6D2E54 8021EDE4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2E58 8021EDE8 00000000 */  nop       
/* 6D2E5C 8021EDEC 00000013 */  mtlo      $zero
/* 6D2E60 8021EDF0 00000000 */  nop       
/* 6D2E64 8021EDF4 00000043 */  sra       $zero, $zero, 1
/* 6D2E68 8021EDF8 00000002 */  srl       $zero, $zero, 0
/* 6D2E6C 8021EDFC 80269E54 */  lb        $a2, -0x61ac($at)
/* 6D2E70 8021EE00 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2E74 8021EE04 00000010 */  mfhi      $zero
/* 6D2E78 8021EE08 00000002 */  srl       $zero, $zero, 0
/* 6D2E7C 8021EE0C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2E80 8021EE10 00000400 */  sll       $zero, $zero, 0x10
/* 6D2E84 8021EE14 00000043 */  sra       $zero, $zero, 1
/* 6D2E88 8021EE18 00000004 */  sllv      $zero, $zero, $zero
/* 6D2E8C 8021EE1C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D2E90 8021EE20 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2E94 8021EE24 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2E98 8021EE28 00560004 */  sllv      $zero, $s6, $v0
/* 6D2E9C 8021EE2C 00000004 */  sllv      $zero, $zero, $zero
/* 6D2EA0 8021EE30 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2EA4 8021EE34 00000000 */  nop       
/* 6D2EA8 8021EE38 00000013 */  mtlo      $zero
/* 6D2EAC 8021EE3C 00000000 */  nop       
/* 6D2EB0 8021EE40 00000002 */  srl       $zero, $zero, 0
/* 6D2EB4 8021EE44 00000000 */  nop       
/* 6D2EB8 8021EE48 00000003 */  sra       $zero, $zero, 0
/* 6D2EBC 8021EE4C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2EC0 8021EE50 00000000 */  nop       
/* 6D2EC4 8021EE54 00000043 */  sra       $zero, $zero, 1
/* 6D2EC8 8021EE58 00000002 */  srl       $zero, $zero, 0
/* 6D2ECC 8021EE5C 8027D32C */  lb        $a3, -0x2cd4($at)
/* 6D2ED0 8021EE60 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2ED4 8021EE64 00000043 */  sra       $zero, $zero, 1
/* 6D2ED8 8021EE68 00000003 */  sra       $zero, $zero, 0
/* 6D2EDC 8021EE6C 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D2EE0 8021EE70 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2EE4 8021EE74 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2EE8 8021EE78 00000010 */  mfhi      $zero
/* 6D2EEC 8021EE7C 00000002 */  srl       $zero, $zero, 0
/* 6D2EF0 8021EE80 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2EF4 8021EE84 00080000 */  sll       $zero, $t0, 0
/* 6D2EF8 8021EE88 00000043 */  sra       $zero, $zero, 1
/* 6D2EFC 8021EE8C 00000006 */  srlv      $zero, $zero, $zero
/* 6D2F00 8021EE90 8026CB4C */  lb        $a2, -0x34b4($at)
/* 6D2F04 8021EE94 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2F08 8021EE98 00000003 */  sra       $zero, $zero, 0
/* 6D2F0C 8021EE9C F24A7C1A */  scd       $t2, 0x7c1a($s2)
/* 6D2F10 8021EEA0 F24A7C1A */  scd       $t2, 0x7c1a($s2)
/* 6D2F14 8021EEA4 F24A7C1A */  scd       $t2, 0x7c1a($s2)
/* 6D2F18 8021EEA8 00000013 */  mtlo      $zero
/* 6D2F1C 8021EEAC 00000000 */  nop       
/* 6D2F20 8021EEB0 00000043 */  sra       $zero, $zero, 1
/* 6D2F24 8021EEB4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D2F28 8021EEB8 8026D010 */  lb        $a2, -0x2ff0($at)
/* 6D2F2C 8021EEBC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2F30 8021EEC0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2F34 8021EEC4 00800000 */  .byte     0x00, 0x80, 0x00, 0x00
/* 6D2F38 8021EEC8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2F3C 8021EECC 00000043 */  sra       $zero, $zero, 1
/* 6D2F40 8021EED0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D2F44 8021EED4 8026D010 */  lb        $a2, -0x2ff0($at)
/* 6D2F48 8021EED8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2F4C 8021EEDC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2F50 8021EEE0 00020001 */  .byte     0x00, 0x02, 0x00, 0x01
/* 6D2F54 8021EEE4 00000000 */  nop       
/* 6D2F58 8021EEE8 00000043 */  sra       $zero, $zero, 1
/* 6D2F5C 8021EEEC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D2F60 8021EEF0 8026D010 */  lb        $a2, -0x2ff0($at)
/* 6D2F64 8021EEF4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2F68 8021EEF8 00000002 */  srl       $zero, $zero, 0
/* 6D2F6C 8021EEFC 00020001 */  .byte     0x00, 0x02, 0x00, 0x01
/* 6D2F70 8021EF00 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2F74 8021EF04 00000043 */  sra       $zero, $zero, 1
/* 6D2F78 8021EF08 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D2F7C 8021EF0C 8026D010 */  lb        $a2, -0x2ff0($at)
/* 6D2F80 8021EF10 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2F84 8021EF14 00000002 */  srl       $zero, $zero, 0
/* 6D2F88 8021EF18 00800000 */  .byte     0x00, 0x80, 0x00, 0x00
/* 6D2F8C 8021EF1C 00000000 */  nop       
/* 6D2F90 8021EF20 00000043 */  sra       $zero, $zero, 1
/* 6D2F94 8021EF24 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D2F98 8021EF28 8026D010 */  lb        $a2, -0x2ff0($at)
/* 6D2F9C 8021EF2C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2FA0 8021EF30 00000003 */  sra       $zero, $zero, 0
/* 6D2FA4 8021EF34 00100000 */  sll       $zero, $s0, 0
/* 6D2FA8 8021EF38 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2FAC 8021EF3C 00000043 */  sra       $zero, $zero, 1
/* 6D2FB0 8021EF40 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D2FB4 8021EF44 8026D010 */  lb        $a2, -0x2ff0($at)
/* 6D2FB8 8021EF48 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2FBC 8021EF4C 00000003 */  sra       $zero, $zero, 0
/* 6D2FC0 8021EF50 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2FC4 8021EF54 00000000 */  nop       
/* 6D2FC8 8021EF58 00000043 */  sra       $zero, $zero, 1
/* 6D2FCC 8021EF5C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D2FD0 8021EF60 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D2FD4 8021EF64 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D2FD8 8021EF68 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D2FDC 8021EF6C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D2FE0 8021EF70 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D2FE4 8021EF74 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D2FE8 8021EF78 00000002 */  srl       $zero, $zero, 0
/* 6D2FEC 8021EF7C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D2FF0 8021EF80 00000001 */  movf      $zero, $zero, $fcc0
/* 6D2FF4 8021EF84 00000043 */  sra       $zero, $zero, 1
/* 6D2FF8 8021EF88 00000006 */  srlv      $zero, $zero, $zero
/* 6D2FFC 8021EF8C 8026AF18 */  lb        $a2, -0x50e8($at)
/* 6D3000 8021EF90 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3004 8021EF94 00000003 */  sra       $zero, $zero, 0
/* 6D3008 8021EF98 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D300C 8021EF9C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D3010 8021EFA0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D3014 8021EFA4 00000043 */  sra       $zero, $zero, 1
/* 6D3018 8021EFA8 00000003 */  sra       $zero, $zero, 0
/* 6D301C 8021EFAC 8025385C */  lb        $a1, 0x385c($at)
/* 6D3020 8021EFB0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3024 8021EFB4 00000301 */  .byte     0x00, 0x00, 0x03, 0x01
/* 6D3028 8021EFB8 00000043 */  sra       $zero, $zero, 1
/* 6D302C 8021EFBC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D3030 8021EFC0 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D3034 8021EFC4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3038 8021EFC8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D303C 8021EFCC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D3040 8021EFD0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D3044 8021EFD4 00000024 */  and       $zero, $zero, $zero
/* 6D3048 8021EFD8 00000002 */  srl       $zero, $zero, 0
/* 6D304C 8021EFDC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D3050 8021EFE0 00000000 */  nop       
/* 6D3054 8021EFE4 00000043 */  sra       $zero, $zero, 1
/* 6D3058 8021EFE8 00000003 */  sra       $zero, $zero, 0
/* 6D305C 8021EFEC 8026B55C */  lb        $a2, -0x4aa4($at)
/* 6D3060 8021EFF0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3064 8021EFF4 F24A7DB4 */  scd       $t2, 0x7db4($s2)
/* 6D3068 8021EFF8 00000043 */  sra       $zero, $zero, 1
/* 6D306C 8021EFFC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D3070 8021F000 8026A510 */  lb        $a2, -0x5af0($at)
/* 6D3074 8021F004 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3078 8021F008 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D307C 8021F00C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D3080 8021F010 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D3084 8021F014 00000043 */  sra       $zero, $zero, 1
/* 6D3088 8021F018 00000006 */  srlv      $zero, $zero, $zero
/* 6D308C 8021F01C 80278D08 */  lb        $a3, -0x72f8($at)
/* 6D3090 8021F020 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3094 8021F024 0000000F */  sync      
/* 6D3098 8021F028 00000000 */  nop       
/* 6D309C 8021F02C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D30A0 8021F030 00000000 */  nop       
/* 6D30A4 8021F034 00000043 */  sra       $zero, $zero, 1
/* 6D30A8 8021F038 00000003 */  sra       $zero, $zero, 0
/* 6D30AC 8021F03C 80218530 */  lb        $at, -0x7ad0($at)
/* 6D30B0 8021F040 00000096 */  .byte     0x00, 0x00, 0x00, 0x96
/* 6D30B4 8021F044 0000000A */  movz      $zero, $zero, $zero
/* 6D30B8 8021F048 00000056 */  drotrv    $zero, $zero, $zero
/* 6D30BC 8021F04C 00000000 */  nop       
/* 6D30C0 8021F050 00000043 */  sra       $zero, $zero, 1
/* 6D30C4 8021F054 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D30C8 8021F058 802CB2A8 */  lb        $t4, -0x4d58($at)
/* 6D30CC 8021F05C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D30D0 8021F060 00000000 */  nop       
/* 6D30D4 8021F064 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D30D8 8021F068 F24A7D4D */  scd       $t2, 0x7d4d($s2)
/* 6D30DC 8021F06C 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D30E0 8021F070 00000000 */  nop       
/* 6D30E4 8021F074 00000043 */  sra       $zero, $zero, 1
/* 6D30E8 8021F078 00000003 */  sra       $zero, $zero, 0
/* 6D30EC 8021F07C 8027C4E0 */  lb        $a3, -0x3b20($at)
/* 6D30F0 8021F080 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D30F4 8021F084 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D30F8 8021F088 0000000A */  movz      $zero, $zero, $zero
/* 6D30FC 8021F08C 00000002 */  srl       $zero, $zero, 0
/* 6D3100 8021F090 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D3104 8021F094 0000000F */  sync      
/* 6D3108 8021F098 00000043 */  sra       $zero, $zero, 1
/* 6D310C 8021F09C 00000004 */  sllv      $zero, $zero, $zero
/* 6D3110 8021F0A0 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D3114 8021F0A4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3118 8021F0A8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D311C 8021F0AC 00560004 */  sllv      $zero, $s6, $v0
/* 6D3120 8021F0B0 00000043 */  sra       $zero, $zero, 1
/* 6D3124 8021F0B4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D3128 8021F0B8 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D312C 8021F0BC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3130 8021F0C0 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D3134 8021F0C4 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D3138 8021F0C8 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6D313C 8021F0CC 00000027 */  not       $zero, $zero
/* 6D3140 8021F0D0 00000002 */  srl       $zero, $zero, 0
/* 6D3144 8021F0D4 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D3148 8021F0D8 0000000A */  movz      $zero, $zero, $zero
/* 6D314C 8021F0DC 00000027 */  not       $zero, $zero
/* 6D3150 8021F0E0 00000002 */  srl       $zero, $zero, 0
/* 6D3154 8021F0E4 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6D3158 8021F0E8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D315C 8021F0EC 00000043 */  sra       $zero, $zero, 1
/* 6D3160 8021F0F0 0000000F */  sync      
/* 6D3164 8021F0F4 802D829C */  lb        $t5, -0x7d64($at)
/* 6D3168 8021F0F8 00000027 */  not       $zero, $zero
/* 6D316C 8021F0FC 00000000 */  nop       
/* 6D3170 8021F100 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D3174 8021F104 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D3178 8021F108 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6D317C 8021F10C F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 6D3180 8021F110 0000000A */  movz      $zero, $zero, $zero
/* 6D3184 8021F114 00000000 */  nop       
/* 6D3188 8021F118 00000000 */  nop       
/* 6D318C 8021F11C 00000000 */  nop       
/* 6D3190 8021F120 00000000 */  nop       
/* 6D3194 8021F124 00000000 */  nop       
/* 6D3198 8021F128 00000000 */  nop       
/* 6D319C 8021F12C 00000000 */  nop       
/* 6D31A0 8021F130 00000013 */  mtlo      $zero
/* 6D31A4 8021F134 00000000 */  nop       
/* 6D31A8 8021F138 00000043 */  sra       $zero, $zero, 1
/* 6D31AC 8021F13C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D31B0 8021F140 8026A510 */  lb        $a2, -0x5af0($at)
/* 6D31B4 8021F144 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D31B8 8021F148 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D31BC 8021F14C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D31C0 8021F150 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D31C4 8021F154 00000043 */  sra       $zero, $zero, 1
/* 6D31C8 8021F158 00000006 */  srlv      $zero, $zero, $zero
/* 6D31CC 8021F15C 80278D08 */  lb        $a3, -0x72f8($at)
/* 6D31D0 8021F160 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D31D4 8021F164 0000000A */  movz      $zero, $zero, $zero
/* 6D31D8 8021F168 00000000 */  nop       
/* 6D31DC 8021F16C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D31E0 8021F170 00000000 */  nop       
/* 6D31E4 8021F174 00000043 */  sra       $zero, $zero, 1
/* 6D31E8 8021F178 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D31EC 8021F17C 8026A510 */  lb        $a2, -0x5af0($at)
/* 6D31F0 8021F180 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D31F4 8021F184 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D31F8 8021F188 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D31FC 8021F18C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D3200 8021F190 00000043 */  sra       $zero, $zero, 1
/* 6D3204 8021F194 00000006 */  srlv      $zero, $zero, $zero
/* 6D3208 8021F198 80278D08 */  lb        $a3, -0x72f8($at)
/* 6D320C 8021F19C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3210 8021F1A0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D3214 8021F1A4 00000000 */  nop       
/* 6D3218 8021F1A8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D321C 8021F1AC 00000000 */  nop       
/* 6D3220 8021F1B0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D3224 8021F1B4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3228 8021F1B8 00000014 */  dsllv     $zero, $zero, $zero
/* 6D322C 8021F1BC 00000043 */  sra       $zero, $zero, 1
/* 6D3230 8021F1C0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D3234 8021F1C4 8026D010 */  lb        $a2, -0x2ff0($at)
/* 6D3238 8021F1C8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D323C 8021F1CC 00000003 */  sra       $zero, $zero, 0
/* 6D3240 8021F1D0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3244 8021F1D4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3248 8021F1D8 00000008 */  jr        $zero
/* 6D324C 8021F1DC 00000001 */   movf     $zero, $zero, $fcc0
/* 6D3250 8021F1E0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3254 8021F1E4 00000043 */  sra       $zero, $zero, 1
/* 6D3258 8021F1E8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D325C 8021F1EC 8026D010 */  lb        $a2, -0x2ff0($at)
/* 6D3260 8021F1F0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3264 8021F1F4 00000003 */  sra       $zero, $zero, 0
/* 6D3268 8021F1F8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D326C 8021F1FC 00000000 */  nop       
/* 6D3270 8021F200 00000008 */  jr        $zero
/* 6D3274 8021F204 00000001 */   movf     $zero, $zero, $fcc0
/* 6D3278 8021F208 00000001 */  movf      $zero, $zero, $fcc0
/* 6D327C 8021F20C 00000006 */  srlv      $zero, $zero, $zero
/* 6D3280 8021F210 00000000 */  nop       
/* 6D3284 8021F214 00000043 */  sra       $zero, $zero, 1
/* 6D3288 8021F218 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D328C 8021F21C 8026D010 */  lb        $a2, -0x2ff0($at)
/* 6D3290 8021F220 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3294 8021F224 00000003 */  sra       $zero, $zero, 0
/* 6D3298 8021F228 00000001 */  movf      $zero, $zero, $fcc0
/* 6D329C 8021F22C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D32A0 8021F230 00000043 */  sra       $zero, $zero, 1
/* 6D32A4 8021F234 00000004 */  sllv      $zero, $zero, $zero
/* 6D32A8 8021F238 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D32AC 8021F23C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D32B0 8021F240 00000001 */  movf      $zero, $zero, $fcc0
/* 6D32B4 8021F244 00560001 */  .byte     0x00, 0x56, 0x00, 0x01
/* 6D32B8 8021F248 00000043 */  sra       $zero, $zero, 1
/* 6D32BC 8021F24C 00000004 */  sllv      $zero, $zero, $zero
/* 6D32C0 8021F250 8026CE8C */  lb        $a2, -0x3174($at)
/* 6D32C4 8021F254 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D32C8 8021F258 00000200 */  sll       $zero, $zero, 8
/* 6D32CC 8021F25C 00000000 */  nop       
/* 6D32D0 8021F260 00000043 */  sra       $zero, $zero, 1
/* 6D32D4 8021F264 00000003 */  sra       $zero, $zero, 0
/* 6D32D8 8021F268 80278C20 */  lb        $a3, -0x73e0($at)
/* 6D32DC 8021F26C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D32E0 8021F270 8021FBE8 */  lb        $at, -0x418($at)
/* 6D32E4 8021F274 00000043 */  sra       $zero, $zero, 1
/* 6D32E8 8021F278 00000003 */  sra       $zero, $zero, 0
/* 6D32EC 8021F27C 8026FB20 */  lb        $a2, -0x4e0($at)
/* 6D32F0 8021F280 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D32F4 8021F284 0000004D */  break     0, 1
/* 6D32F8 8021F288 00000043 */   sra      $zero, $zero, 1
/* 6D32FC 8021F28C 00000003 */  sra       $zero, $zero, 0
/* 6D3300 8021F290 8027CB08 */  lb        $a3, -0x34f8($at)
/* 6D3304 8021F294 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3308 8021F298 8021E7E8 */  lb        $at, -0x1818($at)
/* 6D330C 8021F29C 00000043 */  sra       $zero, $zero, 1
/* 6D3310 8021F2A0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D3314 8021F2A4 80218464 */  lb        $at, -0x7b9c($at)
/* 6D3318 8021F2A8 FFFFFFF6 */  sd        $ra, -0xa($ra)
/* 6D331C 8021F2AC 00000014 */  dsllv     $zero, $zero, $zero
/* 6D3320 8021F2B0 0000000A */  movz      $zero, $zero, $zero
/* 6D3324 8021F2B4 00000020 */  add       $zero, $zero, $zero
/* 6D3328 8021F2B8 00000043 */  sra       $zero, $zero, 1
/* 6D332C 8021F2BC 00000004 */  sllv      $zero, $zero, $zero
/* 6D3330 8021F2C0 8026CE8C */  lb        $a2, -0x3174($at)
/* 6D3334 8021F2C4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3338 8021F2C8 00001000 */  sll       $v0, $zero, 0
/* 6D333C 8021F2CC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3340 8021F2D0 00000043 */  sra       $zero, $zero, 1
/* 6D3344 8021F2D4 00000002 */  srl       $zero, $zero, 0
/* 6D3348 8021F2D8 8026F6EC */  lb        $a2, -0x914($at)
/* 6D334C 8021F2DC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3350 8021F2E0 00000043 */  sra       $zero, $zero, 1
/* 6D3354 8021F2E4 00000003 */  sra       $zero, $zero, 0
/* 6D3358 8021F2E8 8026A05C */  lb        $a2, -0x5fa4($at)
/* 6D335C 8021F2EC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3360 8021F2F0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3364 8021F2F4 0000002B */  sltu      $zero, $zero, $zero
/* 6D3368 8021F2F8 00000002 */  srl       $zero, $zero, 0
/* 6D336C 8021F2FC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3370 8021F300 00000004 */  sllv      $zero, $zero, $zero
/* 6D3374 8021F304 00000043 */  sra       $zero, $zero, 1
/* 6D3378 8021F308 00000003 */  sra       $zero, $zero, 0
/* 6D337C 8021F30C 80269F94 */  lb        $a2, -0x606c($at)
/* 6D3380 8021F310 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3384 8021F314 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3388 8021F318 00000043 */  sra       $zero, $zero, 1
/* 6D338C 8021F31C 00000003 */  sra       $zero, $zero, 0
/* 6D3390 8021F320 8026B654 */  lb        $a2, -0x49ac($at)
/* 6D3394 8021F324 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3398 8021F328 F24A8A80 */  scd       $t2, -0x7580($s2)
/* 6D339C 8021F32C 00000043 */  sra       $zero, $zero, 1
/* 6D33A0 8021F330 00000004 */  sllv      $zero, $zero, $zero
/* 6D33A4 8021F334 80279E64 */  lb        $a3, -0x619c($at)
/* 6D33A8 8021F338 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D33AC 8021F33C 00000000 */  nop       
/* 6D33B0 8021F340 00000000 */  nop       
/* 6D33B4 8021F344 00000043 */  sra       $zero, $zero, 1
/* 6D33B8 8021F348 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D33BC 8021F34C 8026A820 */  lb        $a2, -0x57e0($at)
/* 6D33C0 8021F350 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D33C4 8021F354 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D33C8 8021F358 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D33CC 8021F35C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D33D0 8021F360 00000043 */  sra       $zero, $zero, 1
/* 6D33D4 8021F364 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D33D8 8021F368 8026A1EC */  lb        $a2, -0x5e14($at)
/* 6D33DC 8021F36C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D33E0 8021F370 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D33E4 8021F374 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D33E8 8021F378 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D33EC 8021F37C 00000043 */  sra       $zero, $zero, 1
/* 6D33F0 8021F380 00000002 */  srl       $zero, $zero, 0
/* 6D33F4 8021F384 8026D664 */  lb        $a2, -0x299c($at)
/* 6D33F8 8021F388 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D33FC 8021F38C 00000002 */  srl       $zero, $zero, 0
/* 6D3400 8021F390 00000000 */  nop       
/* 6D3404 8021F394 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3408 8021F398 00000000 */  nop       
/* 6D340C 8021F39C 00000043 */  sra       $zero, $zero, 1
/* 6D3410 8021F3A0 00000003 */  sra       $zero, $zero, 0
/* 6D3414 8021F3A4 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D3418 8021F3A8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D341C 8021F3AC 00000000 */  nop       
/* 6D3420 8021F3B0 00000043 */  sra       $zero, $zero, 1
/* 6D3424 8021F3B4 00000003 */  sra       $zero, $zero, 0
/* 6D3428 8021F3B8 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D342C 8021F3BC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3430 8021F3C0 00000000 */  nop       
/* 6D3434 8021F3C4 00000043 */  sra       $zero, $zero, 1
/* 6D3438 8021F3C8 00000002 */  srl       $zero, $zero, 0
/* 6D343C 8021F3CC 8027D32C */  lb        $a3, -0x2cd4($at)
/* 6D3440 8021F3D0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3444 8021F3D4 00000043 */  sra       $zero, $zero, 1
/* 6D3448 8021F3D8 00000003 */  sra       $zero, $zero, 0
/* 6D344C 8021F3DC 8027C4E0 */  lb        $a3, -0x3b20($at)
/* 6D3450 8021F3E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3454 8021F3E4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3458 8021F3E8 0000000B */  movn      $zero, $zero, $zero
/* 6D345C 8021F3EC 00000002 */  srl       $zero, $zero, 0
/* 6D3460 8021F3F0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3464 8021F3F4 00000039 */  .byte     0x00, 0x00, 0x00, 0x39
/* 6D3468 8021F3F8 00000043 */  sra       $zero, $zero, 1
/* 6D346C 8021F3FC 00000002 */  srl       $zero, $zero, 0
/* 6D3470 8021F400 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D3474 8021F404 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D3478 8021F408 00000043 */  sra       $zero, $zero, 1
/* 6D347C 8021F40C 00000002 */  srl       $zero, $zero, 0
/* 6D3480 8021F410 8024EB24 */  lb        $a0, -0x14dc($at)
/* 6D3484 8021F414 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3488 8021F418 00000043 */  sra       $zero, $zero, 1
/* 6D348C 8021F41C 00000002 */  srl       $zero, $zero, 0
/* 6D3490 8021F420 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6D3494 8021F424 0000000F */  sync      
/* 6D3498 8021F428 00000008 */  jr        $zero
/* 6D349C 8021F42C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D34A0 8021F430 0000000F */  sync      
/* 6D34A4 8021F434 00000043 */  sra       $zero, $zero, 1
/* 6D34A8 8021F438 00000002 */  srl       $zero, $zero, 0
/* 6D34AC 8021F43C 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D34B0 8021F440 00000001 */  movf      $zero, $zero, $fcc0
/* 6D34B4 8021F444 00000013 */  mtlo      $zero
/* 6D34B8 8021F448 00000000 */  nop       
/* 6D34BC 8021F44C 00000043 */  sra       $zero, $zero, 1
/* 6D34C0 8021F450 00000003 */  sra       $zero, $zero, 0
/* 6D34C4 8021F454 8026B654 */  lb        $a2, -0x49ac($at)
/* 6D34C8 8021F458 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D34CC 8021F45C F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 6D34D0 8021F460 00000043 */  sra       $zero, $zero, 1
/* 6D34D4 8021F464 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D34D8 8021F468 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D34DC 8021F46C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D34E0 8021F470 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D34E4 8021F474 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D34E8 8021F478 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D34EC 8021F47C 00000027 */  not       $zero, $zero
/* 6D34F0 8021F480 00000002 */  srl       $zero, $zero, 0
/* 6D34F4 8021F484 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D34F8 8021F488 00000014 */  dsllv     $zero, $zero, $zero
/* 6D34FC 8021F48C 00000043 */  sra       $zero, $zero, 1
/* 6D3500 8021F490 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D3504 8021F494 8026A510 */  lb        $a2, -0x5af0($at)
/* 6D3508 8021F498 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D350C 8021F49C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3510 8021F4A0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D3514 8021F4A4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D3518 8021F4A8 00000043 */  sra       $zero, $zero, 1
/* 6D351C 8021F4AC 00000004 */  sllv      $zero, $zero, $zero
/* 6D3520 8021F4B0 80279E64 */  lb        $a3, -0x619c($at)
/* 6D3524 8021F4B4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3528 8021F4B8 00000000 */  nop       
/* 6D352C 8021F4BC 00000000 */  nop       
/* 6D3530 8021F4C0 00000008 */  jr        $zero
/* 6D3534 8021F4C4 00000001 */   movf     $zero, $zero, $fcc0
/* 6D3538 8021F4C8 0000000A */  movz      $zero, $zero, $zero
/* 6D353C 8021F4CC 00000043 */  sra       $zero, $zero, 1
/* 6D3540 8021F4D0 00000003 */  sra       $zero, $zero, 0
/* 6D3544 8021F4D4 8026B358 */  lb        $a2, -0x4ca8($at)
/* 6D3548 8021F4D8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D354C 8021F4DC 000000B4 */  teq       $zero, $zero, 2
/* 6D3550 8021F4E0 00000043 */  sra       $zero, $zero, 1
/* 6D3554 8021F4E4 00000003 */  sra       $zero, $zero, 0
/* 6D3558 8021F4E8 8027D57C */  lb        $a3, -0x2a84($at)
/* 6D355C 8021F4EC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3560 8021F4F0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3564 8021F4F4 00000043 */  sra       $zero, $zero, 1
/* 6D3568 8021F4F8 00000003 */  sra       $zero, $zero, 0
/* 6D356C 8021F4FC 8026B654 */  lb        $a2, -0x49ac($at)
/* 6D3570 8021F500 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3574 8021F504 F24AA280 */  scd       $t2, -0x5d80($s2)
/* 6D3578 8021F508 00000043 */  sra       $zero, $zero, 1
/* 6D357C 8021F50C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D3580 8021F510 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D3584 8021F514 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3588 8021F518 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D358C 8021F51C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D3590 8021F520 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D3594 8021F524 00000027 */  not       $zero, $zero
/* 6D3598 8021F528 00000002 */  srl       $zero, $zero, 0
/* 6D359C 8021F52C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D35A0 8021F530 000000C8 */  .byte     0x00, 0x00, 0x00, 0xc8
/* 6D35A4 8021F534 00000043 */  sra       $zero, $zero, 1
/* 6D35A8 8021F538 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D35AC 8021F53C 8026A510 */  lb        $a2, -0x5af0($at)
/* 6D35B0 8021F540 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D35B4 8021F544 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D35B8 8021F548 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D35BC 8021F54C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D35C0 8021F550 00000043 */  sra       $zero, $zero, 1
/* 6D35C4 8021F554 00000004 */  sllv      $zero, $zero, $zero
/* 6D35C8 8021F558 80279E64 */  lb        $a3, -0x619c($at)
/* 6D35CC 8021F55C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D35D0 8021F560 00000000 */  nop       
/* 6D35D4 8021F564 00000000 */  nop       
/* 6D35D8 8021F568 00000043 */  sra       $zero, $zero, 1
/* 6D35DC 8021F56C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D35E0 8021F570 8027D7F0 */  lb        $a3, -0x2810($at)
/* 6D35E4 8021F574 00000043 */  sra       $zero, $zero, 1
/* 6D35E8 8021F578 00000002 */  srl       $zero, $zero, 0
/* 6D35EC 8021F57C 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D35F0 8021F580 00000002 */  srl       $zero, $zero, 0
/* 6D35F4 8021F584 00000046 */  rotrv     $zero, $zero, $zero
/* 6D35F8 8021F588 00000001 */  movf      $zero, $zero, $fcc0
/* 6D35FC 8021F58C 80298BF0 */  lb        $t1, -0x7410($at)
/* 6D3600 8021F590 00000043 */  sra       $zero, $zero, 1
/* 6D3604 8021F594 00000002 */  srl       $zero, $zero, 0
/* 6D3608 8021F598 8027D32C */  lb        $a3, -0x2cd4($at)
/* 6D360C 8021F59C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3610 8021F5A0 00000043 */  sra       $zero, $zero, 1
/* 6D3614 8021F5A4 00000002 */  srl       $zero, $zero, 0
/* 6D3618 8021F5A8 8027C7B0 */  lb        $a3, -0x3850($at)
/* 6D361C 8021F5AC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3620 8021F5B0 00000002 */  srl       $zero, $zero, 0
/* 6D3624 8021F5B4 00000000 */  nop       
/* 6D3628 8021F5B8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D362C 8021F5BC 00000000 */  nop       
/* 6D3630 8021F5C0 00000043 */  sra       $zero, $zero, 1
/* 6D3634 8021F5C4 00000004 */  sllv      $zero, $zero, $zero
/* 6D3638 8021F5C8 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D363C 8021F5CC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3640 8021F5D0 00000000 */  nop       
/* 6D3644 8021F5D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3648 8021F5D8 00000040 */  ssnop     
/* 6D364C 8021F5DC 00000002 */  srl       $zero, $zero, 0
/* 6D3650 8021F5E0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3654 8021F5E4 FFFFFFFE */  sd        $ra, -2($ra)
/* 6D3658 8021F5E8 00000043 */  sra       $zero, $zero, 1
/* 6D365C 8021F5EC 00000004 */  sllv      $zero, $zero, $zero
/* 6D3660 8021F5F0 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D3664 8021F5F4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3668 8021F5F8 00000000 */  nop       
/* 6D366C 8021F5FC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3670 8021F600 00000002 */  srl       $zero, $zero, 0
/* 6D3674 8021F604 00000000 */  nop       
/* 6D3678 8021F608 00000001 */  movf      $zero, $zero, $fcc0
/* 6D367C 8021F60C 00000000 */  nop       
/* 6D3680 8021F610 00000043 */  sra       $zero, $zero, 1
/* 6D3684 8021F614 00000003 */  sra       $zero, $zero, 0
/* 6D3688 8021F618 80278A94 */  lb        $a3, -0x756c($at)
/* 6D368C 8021F61C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3690 8021F620 8021EAC4 */  lb        $at, -0x153c($at)
/* 6D3694 8021F624 00000043 */  sra       $zero, $zero, 1
/* 6D3698 8021F628 00000003 */  sra       $zero, $zero, 0
/* 6D369C 8021F62C 80278930 */  lb        $a3, -0x76d0($at)
/* 6D36A0 8021F630 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D36A4 8021F634 80225034 */  lb        $v0, 0x5034($at)
/* 6D36A8 8021F638 00000043 */  sra       $zero, $zero, 1
/* 6D36AC 8021F63C 00000003 */  sra       $zero, $zero, 0
/* 6D36B0 8021F640 80278C20 */  lb        $a3, -0x73e0($at)
/* 6D36B4 8021F644 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D36B8 8021F648 8021FBE8 */  lb        $at, -0x418($at)
/* 6D36BC 8021F64C 00000043 */  sra       $zero, $zero, 1
/* 6D36C0 8021F650 00000003 */  sra       $zero, $zero, 0
/* 6D36C4 8021F654 80278C94 */  lb        $a3, -0x736c($at)
/* 6D36C8 8021F658 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D36CC 8021F65C 8021F5C0 */  lb        $at, -0xa40($at)
/* 6D36D0 8021F660 00000043 */  sra       $zero, $zero, 1
/* 6D36D4 8021F664 00000003 */  sra       $zero, $zero, 0
/* 6D36D8 8021F668 8026F694 */  lb        $a2, -0x96c($at)
/* 6D36DC 8021F66C 00000002 */  srl       $zero, $zero, 0
/* 6D36E0 8021F670 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D36E4 8021F674 0000000A */  movz      $zero, $zero, $zero
/* 6D36E8 8021F678 00000002 */  srl       $zero, $zero, 0
/* 6D36EC 8021F67C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D36F0 8021F680 00000000 */  nop       
/* 6D36F4 8021F684 00000043 */  sra       $zero, $zero, 1
/* 6D36F8 8021F688 00000003 */  sra       $zero, $zero, 0
/* 6D36FC 8021F68C 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D3700 8021F690 00000002 */  srl       $zero, $zero, 0
/* 6D3704 8021F694 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D3708 8021F698 00000013 */  mtlo      $zero
/* 6D370C 8021F69C 00000000 */  nop       
/* 6D3710 8021F6A0 00000043 */  sra       $zero, $zero, 1
/* 6D3714 8021F6A4 00000004 */  sllv      $zero, $zero, $zero
/* 6D3718 8021F6A8 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D371C 8021F6AC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3720 8021F6B0 00000000 */  nop       
/* 6D3724 8021F6B4 00000000 */  nop       
/* 6D3728 8021F6B8 00000043 */  sra       $zero, $zero, 1
/* 6D372C 8021F6BC 00000004 */  sllv      $zero, $zero, $zero
/* 6D3730 8021F6C0 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D3734 8021F6C4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3738 8021F6C8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D373C 8021F6CC 00000000 */  nop       
/* 6D3740 8021F6D0 00000043 */  sra       $zero, $zero, 1
/* 6D3744 8021F6D4 00000004 */  sllv      $zero, $zero, $zero
/* 6D3748 8021F6D8 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D374C 8021F6DC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3750 8021F6E0 00000002 */  srl       $zero, $zero, 0
/* 6D3754 8021F6E4 00000000 */  nop       
/* 6D3758 8021F6E8 00000043 */  sra       $zero, $zero, 1
/* 6D375C 8021F6EC 00000004 */  sllv      $zero, $zero, $zero
/* 6D3760 8021F6F0 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D3764 8021F6F4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3768 8021F6F8 00000003 */  sra       $zero, $zero, 0
/* 6D376C 8021F6FC 00000000 */  nop       
/* 6D3770 8021F700 00000043 */  sra       $zero, $zero, 1
/* 6D3774 8021F704 00000004 */  sllv      $zero, $zero, $zero
/* 6D3778 8021F708 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D377C 8021F70C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3780 8021F710 00000004 */  sllv      $zero, $zero, $zero
/* 6D3784 8021F714 00000000 */  nop       
/* 6D3788 8021F718 00000043 */  sra       $zero, $zero, 1
/* 6D378C 8021F71C 00000004 */  sllv      $zero, $zero, $zero
/* 6D3790 8021F720 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D3794 8021F724 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3798 8021F728 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D379C 8021F72C 00000000 */  nop       
/* 6D37A0 8021F730 00000043 */  sra       $zero, $zero, 1
/* 6D37A4 8021F734 00000004 */  sllv      $zero, $zero, $zero
/* 6D37A8 8021F738 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D37AC 8021F73C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D37B0 8021F740 00000006 */  srlv      $zero, $zero, $zero
/* 6D37B4 8021F744 00000000 */  nop       
/* 6D37B8 8021F748 00000043 */  sra       $zero, $zero, 1
/* 6D37BC 8021F74C 00000004 */  sllv      $zero, $zero, $zero
/* 6D37C0 8021F750 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D37C4 8021F754 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D37C8 8021F758 00000007 */  srav      $zero, $zero, $zero
/* 6D37CC 8021F75C 00000000 */  nop       
/* 6D37D0 8021F760 00000043 */  sra       $zero, $zero, 1
/* 6D37D4 8021F764 00000004 */  sllv      $zero, $zero, $zero
/* 6D37D8 8021F768 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D37DC 8021F76C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D37E0 8021F770 00000008 */  jr        $zero
/* 6D37E4 8021F774 00000000 */   nop      
/* 6D37E8 8021F778 00000043 */  sra       $zero, $zero, 1
/* 6D37EC 8021F77C 00000004 */  sllv      $zero, $zero, $zero
/* 6D37F0 8021F780 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D37F4 8021F784 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D37F8 8021F788 00000009 */  jr        $zero
/* 6D37FC 8021F78C FFFFFFFF */   sd       $ra, -1($ra)
/* 6D3800 8021F790 00000043 */  sra       $zero, $zero, 1
/* 6D3804 8021F794 00000004 */  sllv      $zero, $zero, $zero
/* 6D3808 8021F798 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D380C 8021F79C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3810 8021F7A0 0000000A */  movz      $zero, $zero, $zero
/* 6D3814 8021F7A4 00000000 */  nop       
/* 6D3818 8021F7A8 00000043 */  sra       $zero, $zero, 1
/* 6D381C 8021F7AC 00000004 */  sllv      $zero, $zero, $zero
/* 6D3820 8021F7B0 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D3824 8021F7B4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3828 8021F7B8 0000000B */  movn      $zero, $zero, $zero
/* 6D382C 8021F7BC FFFFFFFF */  sd        $ra, -1($ra)
/* 6D3830 8021F7C0 00000002 */  srl       $zero, $zero, 0
/* 6D3834 8021F7C4 00000000 */  nop       
/* 6D3838 8021F7C8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D383C 8021F7CC 00000000 */  nop       
/* 6D3840 8021F7D0 00000043 */  sra       $zero, $zero, 1
/* 6D3844 8021F7D4 00000003 */  sra       $zero, $zero, 0
/* 6D3848 8021F7D8 80278A94 */  lb        $a3, -0x756c($at)
/* 6D384C 8021F7DC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3850 8021F7E0 8021EAC4 */  lb        $at, -0x153c($at)
/* 6D3854 8021F7E4 00000043 */  sra       $zero, $zero, 1
/* 6D3858 8021F7E8 00000003 */  sra       $zero, $zero, 0
/* 6D385C 8021F7EC 80278930 */  lb        $a3, -0x76d0($at)
/* 6D3860 8021F7F0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3864 8021F7F4 80225034 */  lb        $v0, 0x5034($at)
/* 6D3868 8021F7F8 00000043 */  sra       $zero, $zero, 1
/* 6D386C 8021F7FC 00000003 */  sra       $zero, $zero, 0
/* 6D3870 8021F800 80278C20 */  lb        $a3, -0x73e0($at)
/* 6D3874 8021F804 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3878 8021F808 80220300 */  lb        $v0, 0x300($at)
/* 6D387C 8021F80C 00000043 */  sra       $zero, $zero, 1
/* 6D3880 8021F810 00000003 */  sra       $zero, $zero, 0
/* 6D3884 8021F814 8026F694 */  lb        $a2, -0x96c($at)
/* 6D3888 8021F818 00000002 */  srl       $zero, $zero, 0
/* 6D388C 8021F81C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3890 8021F820 0000000A */  movz      $zero, $zero, $zero
/* 6D3894 8021F824 00000002 */  srl       $zero, $zero, 0
/* 6D3898 8021F828 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D389C 8021F82C 00000000 */  nop       
/* 6D38A0 8021F830 00000043 */  sra       $zero, $zero, 1
/* 6D38A4 8021F834 00000003 */  sra       $zero, $zero, 0
/* 6D38A8 8021F838 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D38AC 8021F83C 00000002 */  srl       $zero, $zero, 0
/* 6D38B0 8021F840 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D38B4 8021F844 00000013 */  mtlo      $zero
/* 6D38B8 8021F848 00000000 */  nop       
/* 6D38BC 8021F84C 00000043 */  sra       $zero, $zero, 1
/* 6D38C0 8021F850 00000004 */  sllv      $zero, $zero, $zero
/* 6D38C4 8021F854 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D38C8 8021F858 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D38CC 8021F85C 00000000 */  nop       
/* 6D38D0 8021F860 00000000 */  nop       
/* 6D38D4 8021F864 00000043 */  sra       $zero, $zero, 1
/* 6D38D8 8021F868 00000004 */  sllv      $zero, $zero, $zero
/* 6D38DC 8021F86C 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D38E0 8021F870 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D38E4 8021F874 00000001 */  movf      $zero, $zero, $fcc0
/* 6D38E8 8021F878 00000000 */  nop       
/* 6D38EC 8021F87C 00000043 */  sra       $zero, $zero, 1
/* 6D38F0 8021F880 00000004 */  sllv      $zero, $zero, $zero
/* 6D38F4 8021F884 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D38F8 8021F888 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D38FC 8021F88C 00000002 */  srl       $zero, $zero, 0
/* 6D3900 8021F890 00000000 */  nop       
/* 6D3904 8021F894 00000043 */  sra       $zero, $zero, 1
/* 6D3908 8021F898 00000004 */  sllv      $zero, $zero, $zero
/* 6D390C 8021F89C 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D3910 8021F8A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3914 8021F8A4 00000003 */  sra       $zero, $zero, 0
/* 6D3918 8021F8A8 00000000 */  nop       
/* 6D391C 8021F8AC 00000043 */  sra       $zero, $zero, 1
/* 6D3920 8021F8B0 00000004 */  sllv      $zero, $zero, $zero
/* 6D3924 8021F8B4 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D3928 8021F8B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D392C 8021F8BC 00000004 */  sllv      $zero, $zero, $zero
/* 6D3930 8021F8C0 00000000 */  nop       
/* 6D3934 8021F8C4 00000043 */  sra       $zero, $zero, 1
/* 6D3938 8021F8C8 00000004 */  sllv      $zero, $zero, $zero
/* 6D393C 8021F8CC 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D3940 8021F8D0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3944 8021F8D4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D3948 8021F8D8 00000000 */  nop       
/* 6D394C 8021F8DC 00000043 */  sra       $zero, $zero, 1
/* 6D3950 8021F8E0 00000004 */  sllv      $zero, $zero, $zero
/* 6D3954 8021F8E4 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D3958 8021F8E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D395C 8021F8EC 00000006 */  srlv      $zero, $zero, $zero
/* 6D3960 8021F8F0 00000000 */  nop       
/* 6D3964 8021F8F4 00000043 */  sra       $zero, $zero, 1
/* 6D3968 8021F8F8 00000004 */  sllv      $zero, $zero, $zero
/* 6D396C 8021F8FC 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D3970 8021F900 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3974 8021F904 00000007 */  srav      $zero, $zero, $zero
/* 6D3978 8021F908 00000000 */  nop       
/* 6D397C 8021F90C 00000043 */  sra       $zero, $zero, 1
/* 6D3980 8021F910 00000004 */  sllv      $zero, $zero, $zero
/* 6D3984 8021F914 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D3988 8021F918 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D398C 8021F91C 00000008 */  jr        $zero
/* 6D3990 8021F920 00000000 */   nop      
/* 6D3994 8021F924 00000043 */  sra       $zero, $zero, 1
/* 6D3998 8021F928 00000004 */  sllv      $zero, $zero, $zero
/* 6D399C 8021F92C 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D39A0 8021F930 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D39A4 8021F934 00000009 */  jr        $zero
/* 6D39A8 8021F938 FFFFFFFF */   sd       $ra, -1($ra)
/* 6D39AC 8021F93C 00000043 */  sra       $zero, $zero, 1
/* 6D39B0 8021F940 00000004 */  sllv      $zero, $zero, $zero
/* 6D39B4 8021F944 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D39B8 8021F948 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D39BC 8021F94C 0000000A */  movz      $zero, $zero, $zero
/* 6D39C0 8021F950 00000000 */  nop       
/* 6D39C4 8021F954 00000043 */  sra       $zero, $zero, 1
/* 6D39C8 8021F958 00000004 */  sllv      $zero, $zero, $zero
/* 6D39CC 8021F95C 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D39D0 8021F960 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D39D4 8021F964 0000000B */  movn      $zero, $zero, $zero
/* 6D39D8 8021F968 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D39DC 8021F96C 00000002 */  srl       $zero, $zero, 0
/* 6D39E0 8021F970 00000000 */  nop       
/* 6D39E4 8021F974 00000001 */  movf      $zero, $zero, $fcc0
/* 6D39E8 8021F978 00000000 */  nop       
/* 6D39EC 8021F97C 00000043 */  sra       $zero, $zero, 1
/* 6D39F0 8021F980 00000004 */  sllv      $zero, $zero, $zero
/* 6D39F4 8021F984 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D39F8 8021F988 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D39FC 8021F98C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3A00 8021F990 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3A04 8021F994 0000000A */  movz      $zero, $zero, $zero
/* 6D3A08 8021F998 00000002 */  srl       $zero, $zero, 0
/* 6D3A0C 8021F99C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3A10 8021F9A0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3A14 8021F9A4 00000002 */  srl       $zero, $zero, 0
/* 6D3A18 8021F9A8 00000000 */  nop       
/* 6D3A1C 8021F9AC 00000013 */  mtlo      $zero
/* 6D3A20 8021F9B0 00000000 */  nop       
/* 6D3A24 8021F9B4 00000043 */  sra       $zero, $zero, 1
/* 6D3A28 8021F9B8 00000004 */  sllv      $zero, $zero, $zero
/* 6D3A2C 8021F9BC 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D3A30 8021F9C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3A34 8021F9C4 00000009 */  jr        $zero
/* 6D3A38 8021F9C8 FE363C80 */   sd       $s6, 0x3c80($s1)
/* 6D3A3C 8021F9CC 00000043 */  sra       $zero, $zero, 1
/* 6D3A40 8021F9D0 00000003 */  sra       $zero, $zero, 0
/* 6D3A44 8021F9D4 8026DE5C */  lb        $a2, -0x21a4($at)
/* 6D3A48 8021F9D8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3A4C 8021F9DC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D3A50 8021F9E0 0000000A */  movz      $zero, $zero, $zero
/* 6D3A54 8021F9E4 00000002 */  srl       $zero, $zero, 0
/* 6D3A58 8021F9E8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D3A5C 8021F9EC 00000000 */  nop       
/* 6D3A60 8021F9F0 00000002 */  srl       $zero, $zero, 0
/* 6D3A64 8021F9F4 00000000 */  nop       
/* 6D3A68 8021F9F8 00000013 */  mtlo      $zero
/* 6D3A6C 8021F9FC 00000000 */  nop       
/* 6D3A70 8021FA00 00000043 */  sra       $zero, $zero, 1
/* 6D3A74 8021FA04 00000004 */  sllv      $zero, $zero, $zero
/* 6D3A78 8021FA08 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D3A7C 8021FA0C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3A80 8021FA10 0000000A */  movz      $zero, $zero, $zero
/* 6D3A84 8021FA14 00000000 */  nop       
/* 6D3A88 8021FA18 00000043 */  sra       $zero, $zero, 1
/* 6D3A8C 8021FA1C 00000002 */  srl       $zero, $zero, 0
/* 6D3A90 8021FA20 80269E54 */  lb        $a2, -0x61ac($at)
/* 6D3A94 8021FA24 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D3A98 8021FA28 00000010 */  mfhi      $zero
/* 6D3A9C 8021FA2C 00000002 */  srl       $zero, $zero, 0
/* 6D3AA0 8021FA30 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D3AA4 8021FA34 20000000 */  addi      $zero, $zero, 0
/* 6D3AA8 8021FA38 00000003 */  sra       $zero, $zero, 0
/* 6D3AAC 8021FA3C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3AB0 8021FA40 00000000 */  nop       
/* 6D3AB4 8021FA44 00000043 */  sra       $zero, $zero, 1
/* 6D3AB8 8021FA48 00000002 */  srl       $zero, $zero, 0
/* 6D3ABC 8021FA4C 8026CD10 */  lb        $a2, -0x32f0($at)
/* 6D3AC0 8021FA50 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D3AC4 8021FA54 00000010 */  mfhi      $zero
/* 6D3AC8 8021FA58 00000002 */  srl       $zero, $zero, 0
/* 6D3ACC 8021FA5C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D3AD0 8021FA60 00000100 */  sll       $zero, $zero, 4
/* 6D3AD4 8021FA64 00000008 */  jr        $zero
/* 6D3AD8 8021FA68 00000001 */   movf     $zero, $zero, $fcc0
/* 6D3ADC 8021FA6C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3AE0 8021FA70 00000004 */  sllv      $zero, $zero, $zero
/* 6D3AE4 8021FA74 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3AE8 8021FA78 00000000 */  nop       
/* 6D3AEC 8021FA7C 00000013 */  mtlo      $zero
/* 6D3AF0 8021FA80 00000000 */  nop       
/* 6D3AF4 8021FA84 00000013 */  mtlo      $zero
/* 6D3AF8 8021FA88 00000000 */  nop       
/* 6D3AFC 8021FA8C 00000043 */  sra       $zero, $zero, 1
/* 6D3B00 8021FA90 00000004 */  sllv      $zero, $zero, $zero
/* 6D3B04 8021FA94 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D3B08 8021FA98 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3B0C 8021FA9C 00000009 */  jr        $zero
/* 6D3B10 8021FAA0 FE363C80 */   sd       $s6, 0x3c80($s1)
/* 6D3B14 8021FAA4 00000043 */  sra       $zero, $zero, 1
/* 6D3B18 8021FAA8 00000004 */  sllv      $zero, $zero, $zero
/* 6D3B1C 8021FAAC 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D3B20 8021FAB0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3B24 8021FAB4 00000009 */  jr        $zero
/* 6D3B28 8021FAB8 FFFFFFFF */   sd       $ra, -1($ra)
/* 6D3B2C 8021FABC 00000043 */  sra       $zero, $zero, 1
/* 6D3B30 8021FAC0 00000003 */  sra       $zero, $zero, 0
/* 6D3B34 8021FAC4 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D3B38 8021FAC8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3B3C 8021FACC FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D3B40 8021FAD0 00000010 */  mfhi      $zero
/* 6D3B44 8021FAD4 00000002 */  srl       $zero, $zero, 0
/* 6D3B48 8021FAD8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D3B4C 8021FADC 00000200 */  sll       $zero, $zero, 8
/* 6D3B50 8021FAE0 00000043 */  sra       $zero, $zero, 1
/* 6D3B54 8021FAE4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D3B58 8021FAE8 8026D3C8 */  lb        $a2, -0x2c38($at)
/* 6D3B5C 8021FAEC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3B60 8021FAF0 00000002 */  srl       $zero, $zero, 0
/* 6D3B64 8021FAF4 00400000 */  .byte     0x00, 0x40, 0x00, 0x00
/* 6D3B68 8021FAF8 00000000 */  nop       
/* 6D3B6C 8021FAFC 00000012 */  mflo      $zero
/* 6D3B70 8021FB00 00000000 */  nop       
/* 6D3B74 8021FB04 00000043 */  sra       $zero, $zero, 1
/* 6D3B78 8021FB08 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D3B7C 8021FB0C 8026D3C8 */  lb        $a2, -0x2c38($at)
/* 6D3B80 8021FB10 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3B84 8021FB14 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3B88 8021FB18 00400000 */  .byte     0x00, 0x40, 0x00, 0x00
/* 6D3B8C 8021FB1C 00000000 */  nop       
/* 6D3B90 8021FB20 00000013 */  mtlo      $zero
/* 6D3B94 8021FB24 00000000 */  nop       
/* 6D3B98 8021FB28 00000043 */  sra       $zero, $zero, 1
/* 6D3B9C 8021FB2C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D3BA0 8021FB30 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D3BA4 8021FB34 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3BA8 8021FB38 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D3BAC 8021FB3C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D3BB0 8021FB40 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D3BB4 8021FB44 00000043 */  sra       $zero, $zero, 1
/* 6D3BB8 8021FB48 00000002 */  srl       $zero, $zero, 0
/* 6D3BBC 8021FB4C 8027C7B0 */  lb        $a3, -0x3850($at)
/* 6D3BC0 8021FB50 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3BC4 8021FB54 00000056 */  drotrv    $zero, $zero, $zero
/* 6D3BC8 8021FB58 00000000 */  nop       
/* 6D3BCC 8021FB5C 00000027 */  not       $zero, $zero
/* 6D3BD0 8021FB60 00000002 */  srl       $zero, $zero, 0
/* 6D3BD4 8021FB64 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D3BD8 8021FB68 00000002 */  srl       $zero, $zero, 0
/* 6D3BDC 8021FB6C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D3BE0 8021FB70 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3BE4 8021FB74 00000002 */  srl       $zero, $zero, 0
/* 6D3BE8 8021FB78 00000043 */  sra       $zero, $zero, 1
/* 6D3BEC 8021FB7C 0000000F */  sync      
/* 6D3BF0 8021FB80 802D829C */  lb        $t5, -0x7d64($at)
/* 6D3BF4 8021FB84 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3BF8 8021FB88 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D3BFC 8021FB8C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D3C00 8021FB90 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D3C04 8021FB94 00000000 */  nop       
/* 6D3C08 8021FB98 00000000 */  nop       
/* 6D3C0C 8021FB9C 00000000 */  nop       
/* 6D3C10 8021FBA0 00000000 */  nop       
/* 6D3C14 8021FBA4 00000000 */  nop       
/* 6D3C18 8021FBA8 00000000 */  nop       
/* 6D3C1C 8021FBAC 00000000 */  nop       
/* 6D3C20 8021FBB0 00000000 */  nop       
/* 6D3C24 8021FBB4 00000000 */  nop       
/* 6D3C28 8021FBB8 00000000 */  nop       
/* 6D3C2C 8021FBBC 00000008 */  jr        $zero
/* 6D3C30 8021FBC0 00000001 */   movf     $zero, $zero, $fcc0
/* 6D3C34 8021FBC4 00000002 */  srl       $zero, $zero, 0
/* 6D3C38 8021FBC8 00000006 */  srlv      $zero, $zero, $zero
/* 6D3C3C 8021FBCC 00000000 */  nop       
/* 6D3C40 8021FBD0 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D3C44 8021FBD4 00000000 */  nop       
/* 6D3C48 8021FBD8 00000002 */  srl       $zero, $zero, 0
/* 6D3C4C 8021FBDC 00000000 */  nop       
/* 6D3C50 8021FBE0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3C54 8021FBE4 00000000 */  nop       
/* 6D3C58 8021FBE8 00000043 */  sra       $zero, $zero, 1
/* 6D3C5C 8021FBEC 00000003 */  sra       $zero, $zero, 0
/* 6D3C60 8021FBF0 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D3C64 8021FBF4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3C68 8021FBF8 00000000 */  nop       
/* 6D3C6C 8021FBFC 00000043 */  sra       $zero, $zero, 1
/* 6D3C70 8021FC00 00000003 */  sra       $zero, $zero, 0
/* 6D3C74 8021FC04 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D3C78 8021FC08 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3C7C 8021FC0C 00000000 */  nop       
/* 6D3C80 8021FC10 00000043 */  sra       $zero, $zero, 1
/* 6D3C84 8021FC14 00000004 */  sllv      $zero, $zero, $zero
/* 6D3C88 8021FC18 8026F470 */  lb        $a2, -0xb90($at)
/* 6D3C8C 8021FC1C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3C90 8021FC20 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3C94 8021FC24 000000FF */  dsra32    $zero, $zero, 3
/* 6D3C98 8021FC28 00000043 */  sra       $zero, $zero, 1
/* 6D3C9C 8021FC2C 00000003 */  sra       $zero, $zero, 0
/* 6D3CA0 8021FC30 8027C4E0 */  lb        $a3, -0x3b20($at)
/* 6D3CA4 8021FC34 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3CA8 8021FC38 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3CAC 8021FC3C 00000014 */  dsllv     $zero, $zero, $zero
/* 6D3CB0 8021FC40 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3CB4 8021FC44 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3CB8 8021FC48 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D3CBC 8021FC4C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3CC0 8021FC50 00000009 */  jr        $zero
/* 6D3CC4 8021FC54 00000043 */   sra      $zero, $zero, 1
/* 6D3CC8 8021FC58 00000004 */  sllv      $zero, $zero, $zero
/* 6D3CCC 8021FC5C 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D3CD0 8021FC60 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3CD4 8021FC64 00000000 */  nop       
/* 6D3CD8 8021FC68 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3CDC 8021FC6C 00000042 */  srl       $zero, $zero, 1
/* 6D3CE0 8021FC70 00000002 */  srl       $zero, $zero, 0
/* 6D3CE4 8021FC74 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3CE8 8021FC78 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3CEC 8021FC7C 00000043 */  sra       $zero, $zero, 1
/* 6D3CF0 8021FC80 00000004 */  sllv      $zero, $zero, $zero
/* 6D3CF4 8021FC84 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D3CF8 8021FC88 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3CFC 8021FC8C 00000000 */  nop       
/* 6D3D00 8021FC90 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3D04 8021FC94 00000025 */  or        $zero, $zero, $zero
/* 6D3D08 8021FC98 00000002 */  srl       $zero, $zero, 0
/* 6D3D0C 8021FC9C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3D10 8021FCA0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3D14 8021FCA4 00000025 */  or        $zero, $zero, $zero
/* 6D3D18 8021FCA8 00000002 */  srl       $zero, $zero, 0
/* 6D3D1C 8021FCAC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D3D20 8021FCB0 00560004 */  sllv      $zero, $s6, $v0
/* 6D3D24 8021FCB4 00000046 */  rotrv     $zero, $zero, $zero
/* 6D3D28 8021FCB8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3D2C 8021FCBC 80299044 */  lb        $t1, -0x6fbc($at)
/* 6D3D30 8021FCC0 0000001D */  dmultu    $zero, $zero
/* 6D3D34 8021FCC4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3D38 8021FCC8 0000000A */  movz      $zero, $zero, $zero
/* 6D3D3C 8021FCCC 0000001D */  dmultu    $zero, $zero
/* 6D3D40 8021FCD0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3D44 8021FCD4 0000003D */  .byte     0x00, 0x00, 0x00, 0x3d
/* 6D3D48 8021FCD8 00000025 */  or        $zero, $zero, $zero
/* 6D3D4C 8021FCDC 00000002 */  srl       $zero, $zero, 0
/* 6D3D50 8021FCE0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3D54 8021FCE4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3D58 8021FCE8 00000025 */  or        $zero, $zero, $zero
/* 6D3D5C 8021FCEC 00000002 */  srl       $zero, $zero, 0
/* 6D3D60 8021FCF0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D3D64 8021FCF4 00560004 */  sllv      $zero, $s6, $v0
/* 6D3D68 8021FCF8 00000046 */  rotrv     $zero, $zero, $zero
/* 6D3D6C 8021FCFC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3D70 8021FD00 80299044 */  lb        $t1, -0x6fbc($at)
/* 6D3D74 8021FD04 00000046 */  rotrv     $zero, $zero, $zero
/* 6D3D78 8021FD08 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3D7C 8021FD0C 8021F97C */  lb        $at, -0x684($at)
/* 6D3D80 8021FD10 00000020 */  add       $zero, $zero, $zero
/* 6D3D84 8021FD14 00000000 */  nop       
/* 6D3D88 8021FD18 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D3D8C 8021FD1C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3D90 8021FD20 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D3D94 8021FD24 00000025 */  or        $zero, $zero, $zero
/* 6D3D98 8021FD28 00000002 */  srl       $zero, $zero, 0
/* 6D3D9C 8021FD2C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3DA0 8021FD30 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3DA4 8021FD34 00000025 */  or        $zero, $zero, $zero
/* 6D3DA8 8021FD38 00000002 */  srl       $zero, $zero, 0
/* 6D3DAC 8021FD3C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D3DB0 8021FD40 00560005 */  lsa       $zero, $v0, $s6, 1
/* 6D3DB4 8021FD44 00000025 */  or        $zero, $zero, $zero
/* 6D3DB8 8021FD48 00000002 */  srl       $zero, $zero, 0
/* 6D3DBC 8021FD4C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D3DC0 8021FD50 00560006 */  srlv      $zero, $s6, $v0
/* 6D3DC4 8021FD54 00000046 */  rotrv     $zero, $zero, $zero
/* 6D3DC8 8021FD58 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3DCC 8021FD5C 8029A0D0 */  lb        $t1, -0x5f30($at)
/* 6D3DD0 8021FD60 00000046 */  rotrv     $zero, $zero, $zero
/* 6D3DD4 8021FD64 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3DD8 8021FD68 8021F97C */  lb        $at, -0x684($at)
/* 6D3DDC 8021FD6C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D3DE0 8021FD70 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3DE4 8021FD74 00000024 */  and       $zero, $zero, $zero
/* 6D3DE8 8021FD78 00000025 */  or        $zero, $zero, $zero
/* 6D3DEC 8021FD7C 00000002 */  srl       $zero, $zero, 0
/* 6D3DF0 8021FD80 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3DF4 8021FD84 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3DF8 8021FD88 00000025 */  or        $zero, $zero, $zero
/* 6D3DFC 8021FD8C 00000002 */  srl       $zero, $zero, 0
/* 6D3E00 8021FD90 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D3E04 8021FD94 00560005 */  lsa       $zero, $v0, $s6, 1
/* 6D3E08 8021FD98 00000025 */  or        $zero, $zero, $zero
/* 6D3E0C 8021FD9C 00000002 */  srl       $zero, $zero, 0
/* 6D3E10 8021FDA0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D3E14 8021FDA4 00560006 */  srlv      $zero, $s6, $v0
/* 6D3E18 8021FDA8 00000046 */  rotrv     $zero, $zero, $zero
/* 6D3E1C 8021FDAC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3E20 8021FDB0 8029A0D0 */  lb        $t1, -0x5f30($at)
/* 6D3E24 8021FDB4 00000046 */  rotrv     $zero, $zero, $zero
/* 6D3E28 8021FDB8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3E2C 8021FDBC 8021F97C */  lb        $at, -0x684($at)
/* 6D3E30 8021FDC0 00000025 */  or        $zero, $zero, $zero
/* 6D3E34 8021FDC4 00000002 */  srl       $zero, $zero, 0
/* 6D3E38 8021FDC8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3E3C 8021FDCC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3E40 8021FDD0 00000025 */  or        $zero, $zero, $zero
/* 6D3E44 8021FDD4 00000002 */  srl       $zero, $zero, 0
/* 6D3E48 8021FDD8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D3E4C 8021FDDC 00560006 */  srlv      $zero, $s6, $v0
/* 6D3E50 8021FDE0 00000046 */  rotrv     $zero, $zero, $zero
/* 6D3E54 8021FDE4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3E58 8021FDE8 8029AEC0 */  lb        $t1, -0x5140($at)
/* 6D3E5C 8021FDEC 00000002 */  srl       $zero, $zero, 0
/* 6D3E60 8021FDF0 00000000 */  nop       
/* 6D3E64 8021FDF4 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D3E68 8021FDF8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3E6C 8021FDFC 0000000B */  movn      $zero, $zero, $zero
/* 6D3E70 8021FE00 00000025 */  or        $zero, $zero, $zero
/* 6D3E74 8021FE04 00000002 */  srl       $zero, $zero, 0
/* 6D3E78 8021FE08 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3E7C 8021FE0C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3E80 8021FE10 00000025 */  or        $zero, $zero, $zero
/* 6D3E84 8021FE14 00000002 */  srl       $zero, $zero, 0
/* 6D3E88 8021FE18 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D3E8C 8021FE1C 00560004 */  sllv      $zero, $s6, $v0
/* 6D3E90 8021FE20 00000046 */  rotrv     $zero, $zero, $zero
/* 6D3E94 8021FE24 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3E98 8021FE28 8029B998 */  lb        $t1, -0x4668($at)
/* 6D3E9C 8021FE2C 00000046 */  rotrv     $zero, $zero, $zero
/* 6D3EA0 8021FE30 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3EA4 8021FE34 8021F97C */  lb        $at, -0x684($at)
/* 6D3EA8 8021FE38 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D3EAC 8021FE3C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3EB0 8021FE40 00000021 */  addu      $zero, $zero, $zero
/* 6D3EB4 8021FE44 00000025 */  or        $zero, $zero, $zero
/* 6D3EB8 8021FE48 00000002 */  srl       $zero, $zero, 0
/* 6D3EBC 8021FE4C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3EC0 8021FE50 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3EC4 8021FE54 00000025 */  or        $zero, $zero, $zero
/* 6D3EC8 8021FE58 00000002 */  srl       $zero, $zero, 0
/* 6D3ECC 8021FE5C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D3ED0 8021FE60 00560004 */  sllv      $zero, $s6, $v0
/* 6D3ED4 8021FE64 00000046 */  rotrv     $zero, $zero, $zero
/* 6D3ED8 8021FE68 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3EDC 8021FE6C 8029B998 */  lb        $t1, -0x4668($at)
/* 6D3EE0 8021FE70 00000046 */  rotrv     $zero, $zero, $zero
/* 6D3EE4 8021FE74 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3EE8 8021FE78 8021F97C */  lb        $at, -0x684($at)
/* 6D3EEC 8021FE7C 00000025 */  or        $zero, $zero, $zero
/* 6D3EF0 8021FE80 00000002 */  srl       $zero, $zero, 0
/* 6D3EF4 8021FE84 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3EF8 8021FE88 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3EFC 8021FE8C 00000025 */  or        $zero, $zero, $zero
/* 6D3F00 8021FE90 00000002 */  srl       $zero, $zero, 0
/* 6D3F04 8021FE94 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D3F08 8021FE98 00560004 */  sllv      $zero, $s6, $v0
/* 6D3F0C 8021FE9C 00000046 */  rotrv     $zero, $zero, $zero
/* 6D3F10 8021FEA0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3F14 8021FEA4 8029AEC0 */  lb        $t1, -0x5140($at)
/* 6D3F18 8021FEA8 00000002 */  srl       $zero, $zero, 0
/* 6D3F1C 8021FEAC 00000000 */  nop       
/* 6D3F20 8021FEB0 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D3F24 8021FEB4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3F28 8021FEB8 00000017 */  dsrav     $zero, $zero, $zero
/* 6D3F2C 8021FEBC 00000025 */  or        $zero, $zero, $zero
/* 6D3F30 8021FEC0 00000002 */  srl       $zero, $zero, 0
/* 6D3F34 8021FEC4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3F38 8021FEC8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3F3C 8021FECC 00000025 */  or        $zero, $zero, $zero
/* 6D3F40 8021FED0 00000002 */  srl       $zero, $zero, 0
/* 6D3F44 8021FED4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D3F48 8021FED8 00560001 */  .byte     0x00, 0x56, 0x00, 0x01
/* 6D3F4C 8021FEDC 00000046 */  rotrv     $zero, $zero, $zero
/* 6D3F50 8021FEE0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3F54 8021FEE4 8029AC70 */  lb        $t1, -0x5390($at)
/* 6D3F58 8021FEE8 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D3F5C 8021FEEC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3F60 8021FEF0 00000019 */  multu     $zero, $zero
/* 6D3F64 8021FEF4 00000025 */  or        $zero, $zero, $zero
/* 6D3F68 8021FEF8 00000002 */  srl       $zero, $zero, 0
/* 6D3F6C 8021FEFC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3F70 8021FF00 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3F74 8021FF04 00000025 */  or        $zero, $zero, $zero
/* 6D3F78 8021FF08 00000002 */  srl       $zero, $zero, 0
/* 6D3F7C 8021FF0C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D3F80 8021FF10 00560001 */  .byte     0x00, 0x56, 0x00, 0x01
/* 6D3F84 8021FF14 00000046 */  rotrv     $zero, $zero, $zero
/* 6D3F88 8021FF18 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3F8C 8021FF1C 8029AC70 */  lb        $t1, -0x5390($at)
/* 6D3F90 8021FF20 00000043 */  sra       $zero, $zero, 1
/* 6D3F94 8021FF24 00000004 */  sllv      $zero, $zero, $zero
/* 6D3F98 8021FF28 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D3F9C 8021FF2C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3FA0 8021FF30 00000000 */  nop       
/* 6D3FA4 8021FF34 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3FA8 8021FF38 00000010 */  mfhi      $zero
/* 6D3FAC 8021FF3C 00000002 */  srl       $zero, $zero, 0
/* 6D3FB0 8021FF40 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3FB4 8021FF44 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3FB8 8021FF48 00000046 */  rotrv     $zero, $zero, $zero
/* 6D3FBC 8021FF4C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D3FC0 8021FF50 8021F97C */  lb        $at, -0x684($at)
/* 6D3FC4 8021FF54 00000002 */  srl       $zero, $zero, 0
/* 6D3FC8 8021FF58 00000000 */  nop       
/* 6D3FCC 8021FF5C 00000013 */  mtlo      $zero
/* 6D3FD0 8021FF60 00000000 */  nop       
/* 6D3FD4 8021FF64 00000043 */  sra       $zero, $zero, 1
/* 6D3FD8 8021FF68 00000003 */  sra       $zero, $zero, 0
/* 6D3FDC 8021FF6C 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D3FE0 8021FF70 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D3FE4 8021FF74 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3FE8 8021FF78 0000000B */  movn      $zero, $zero, $zero
/* 6D3FEC 8021FF7C 00000002 */  srl       $zero, $zero, 0
/* 6D3FF0 8021FF80 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D3FF4 8021FF84 00000000 */  nop       
/* 6D3FF8 8021FF88 00000046 */  rotrv     $zero, $zero, $zero
/* 6D3FFC 8021FF8C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4000 8021FF90 8021F97C */  lb        $at, -0x684($at)
/* 6D4004 8021FF94 00000013 */  mtlo      $zero
/* 6D4008 8021FF98 00000000 */  nop       
/* 6D400C 8021FF9C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D4010 8021FFA0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4014 8021FFA4 00000020 */  add       $zero, $zero, $zero
/* 6D4018 8021FFA8 00000025 */  or        $zero, $zero, $zero
/* 6D401C 8021FFAC 00000002 */  srl       $zero, $zero, 0
/* 6D4020 8021FFB0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4024 8021FFB4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4028 8021FFB8 00000025 */  or        $zero, $zero, $zero
/* 6D402C 8021FFBC 00000002 */  srl       $zero, $zero, 0
/* 6D4030 8021FFC0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4034 8021FFC4 00560004 */  sllv      $zero, $s6, $v0
/* 6D4038 8021FFC8 00000046 */  rotrv     $zero, $zero, $zero
/* 6D403C 8021FFCC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4040 8021FFD0 80299044 */  lb        $t1, -0x6fbc($at)
/* 6D4044 8021FFD4 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4048 8021FFD8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D404C 8021FFDC 8021F97C */  lb        $at, -0x684($at)
/* 6D4050 8021FFE0 00000008 */  jr        $zero
/* 6D4054 8021FFE4 00000001 */   movf     $zero, $zero, $fcc0
/* 6D4058 8021FFE8 0000000A */  movz      $zero, $zero, $zero
/* 6D405C 8021FFEC 00000025 */  or        $zero, $zero, $zero
/* 6D4060 8021FFF0 00000002 */  srl       $zero, $zero, 0
/* 6D4064 8021FFF4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4068 8021FFF8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D406C 8021FFFC 00000025 */  or        $zero, $zero, $zero
/* 6D4070 80220000 00000002 */  srl       $zero, $zero, 0
/* 6D4074 80220004 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4078 80220008 00560004 */  sllv      $zero, $s6, $v0
/* 6D407C 8022000C 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4080 80220010 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4084 80220014 8029AEC0 */  lb        $t1, -0x5140($at)
/* 6D4088 80220018 00000002 */  srl       $zero, $zero, 0
/* 6D408C 8022001C 00000000 */  nop       
/* 6D4090 80220020 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D4094 80220024 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4098 80220028 00000031 */  tgeu      $zero, $zero
/* 6D409C 8022002C 00000025 */  or        $zero, $zero, $zero
/* 6D40A0 80220030 00000002 */  srl       $zero, $zero, 0
/* 6D40A4 80220034 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D40A8 80220038 00000001 */  movf      $zero, $zero, $fcc0
/* 6D40AC 8022003C 00000025 */  or        $zero, $zero, $zero
/* 6D40B0 80220040 00000002 */  srl       $zero, $zero, 0
/* 6D40B4 80220044 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D40B8 80220048 00560001 */  .byte     0x00, 0x56, 0x00, 0x01
/* 6D40BC 8022004C 00000046 */  rotrv     $zero, $zero, $zero
/* 6D40C0 80220050 00000001 */  movf      $zero, $zero, $fcc0
/* 6D40C4 80220054 8029BFA0 */  lb        $t1, -0x4060($at)
/* 6D40C8 80220058 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D40CC 8022005C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D40D0 80220060 00000039 */  .byte     0x00, 0x00, 0x00, 0x39
/* 6D40D4 80220064 00000046 */  rotrv     $zero, $zero, $zero
/* 6D40D8 80220068 00000001 */  movf      $zero, $zero, $fcc0
/* 6D40DC 8022006C 8021F97C */  lb        $at, -0x684($at)
/* 6D40E0 80220070 00000043 */  sra       $zero, $zero, 1
/* 6D40E4 80220074 00000004 */  sllv      $zero, $zero, $zero
/* 6D40E8 80220078 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D40EC 8022007C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D40F0 80220080 00000001 */  movf      $zero, $zero, $fcc0
/* 6D40F4 80220084 00560004 */  sllv      $zero, $s6, $v0
/* 6D40F8 80220088 00000043 */  sra       $zero, $zero, 1
/* 6D40FC 8022008C 00000003 */  sra       $zero, $zero, 0
/* 6D4100 80220090 8026B55C */  lb        $a2, -0x4aa4($at)
/* 6D4104 80220094 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4108 80220098 F24A8080 */  scd       $t2, -0x7f80($s2)
/* 6D410C 8022009C 00000043 */  sra       $zero, $zero, 1
/* 6D4110 802200A0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D4114 802200A4 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D4118 802200A8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D411C 802200AC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4120 802200B0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4124 802200B4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D4128 802200B8 00000043 */  sra       $zero, $zero, 1
/* 6D412C 802200BC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D4130 802200C0 8026A510 */  lb        $a2, -0x5af0($at)
/* 6D4134 802200C4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4138 802200C8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D413C 802200CC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4140 802200D0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D4144 802200D4 00000043 */  sra       $zero, $zero, 1
/* 6D4148 802200D8 00000006 */  srlv      $zero, $zero, $zero
/* 6D414C 802200DC 80278D08 */  lb        $a3, -0x72f8($at)
/* 6D4150 802200E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4154 802200E4 0000000F */  sync      
/* 6D4158 802200E8 00000000 */  nop       
/* 6D415C 802200EC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4160 802200F0 00000000 */  nop       
/* 6D4164 802200F4 00000008 */  jr        $zero
/* 6D4168 802200F8 00000001 */   movf     $zero, $zero, $fcc0
/* 6D416C 802200FC 0000000F */  sync      
/* 6D4170 80220100 00000043 */  sra       $zero, $zero, 1
/* 6D4174 80220104 00000004 */  sllv      $zero, $zero, $zero
/* 6D4178 80220108 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D417C 8022010C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4180 80220110 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4184 80220114 00560002 */  .byte     0x00, 0x56, 0x00, 0x02
/* 6D4188 80220118 00000046 */  rotrv     $zero, $zero, $zero
/* 6D418C 8022011C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4190 80220120 8021F39C */  lb        $at, -0xc64($at)
/* 6D4194 80220124 00000002 */  srl       $zero, $zero, 0
/* 6D4198 80220128 00000000 */  nop       
/* 6D419C 8022012C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D41A0 80220130 00000001 */  movf      $zero, $zero, $fcc0
/* 6D41A4 80220134 0000003A */  dsrl      $zero, $zero, 0
/* 6D41A8 80220138 00000025 */  or        $zero, $zero, $zero
/* 6D41AC 8022013C 00000002 */  srl       $zero, $zero, 0
/* 6D41B0 80220140 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D41B4 80220144 00000001 */  movf      $zero, $zero, $fcc0
/* 6D41B8 80220148 00000025 */  or        $zero, $zero, $zero
/* 6D41BC 8022014C 00000002 */  srl       $zero, $zero, 0
/* 6D41C0 80220150 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D41C4 80220154 00560002 */  .byte     0x00, 0x56, 0x00, 0x02
/* 6D41C8 80220158 00000046 */  rotrv     $zero, $zero, $zero
/* 6D41CC 8022015C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D41D0 80220160 8029C37C */  lb        $t1, -0x3c84($at)
/* 6D41D4 80220164 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D41D8 80220168 00000001 */  movf      $zero, $zero, $fcc0
/* 6D41DC 8022016C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D41E0 80220170 00000046 */  rotrv     $zero, $zero, $zero
/* 6D41E4 80220174 00000001 */  movf      $zero, $zero, $fcc0
/* 6D41E8 80220178 8021F97C */  lb        $at, -0x684($at)
/* 6D41EC 8022017C 00000043 */  sra       $zero, $zero, 1
/* 6D41F0 80220180 00000003 */  sra       $zero, $zero, 0
/* 6D41F4 80220184 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D41F8 80220188 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D41FC 8022018C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4200 80220190 00000011 */  mthi      $zero
/* 6D4204 80220194 00000002 */  srl       $zero, $zero, 0
/* 6D4208 80220198 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D420C 8022019C 0035D000 */  .byte     0x00, 0x35, 0xd0, 0x00
/* 6D4210 802201A0 00000010 */  mfhi      $zero
/* 6D4214 802201A4 00000002 */  srl       $zero, $zero, 0
/* 6D4218 802201A8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D421C 802201AC 00080000 */  sll       $zero, $t0, 0
/* 6D4220 802201B0 00000043 */  sra       $zero, $zero, 1
/* 6D4224 802201B4 00000006 */  srlv      $zero, $zero, $zero
/* 6D4228 802201B8 8026BC38 */  lb        $a2, -0x43c8($at)
/* 6D422C 802201BC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4230 802201C0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4234 802201C4 00000000 */  nop       
/* 6D4238 802201C8 00000002 */  srl       $zero, $zero, 0
/* 6D423C 802201CC 00000000 */  nop       
/* 6D4240 802201D0 00000012 */  mflo      $zero
/* 6D4244 802201D4 00000000 */  nop       
/* 6D4248 802201D8 00000043 */  sra       $zero, $zero, 1
/* 6D424C 802201DC 00000006 */  srlv      $zero, $zero, $zero
/* 6D4250 802201E0 8026BC38 */  lb        $a2, -0x43c8($at)
/* 6D4254 802201E4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4258 802201E8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D425C 802201EC FFFFFFFC */  sd        $ra, -4($ra)
/* 6D4260 802201F0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D4264 802201F4 00000000 */  nop       
/* 6D4268 802201F8 00000013 */  mtlo      $zero
/* 6D426C 802201FC 00000000 */  nop       
/* 6D4270 80220200 00000013 */  mtlo      $zero
/* 6D4274 80220204 00000000 */  nop       
/* 6D4278 80220208 00000025 */  or        $zero, $zero, $zero
/* 6D427C 8022020C 00000002 */  srl       $zero, $zero, 0
/* 6D4280 80220210 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4284 80220214 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4288 80220218 00000025 */  or        $zero, $zero, $zero
/* 6D428C 8022021C 00000002 */  srl       $zero, $zero, 0
/* 6D4290 80220220 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4294 80220224 00560004 */  sllv      $zero, $s6, $v0
/* 6D4298 80220228 00000046 */  rotrv     $zero, $zero, $zero
/* 6D429C 8022022C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D42A0 80220230 8029C4A8 */  lb        $t1, -0x3b58($at)
/* 6D42A4 80220234 00000002 */  srl       $zero, $zero, 0
/* 6D42A8 80220238 00000000 */  nop       
/* 6D42AC 8022023C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D42B0 80220240 00000001 */  movf      $zero, $zero, $fcc0
/* 6D42B4 80220244 0000001F */  ddivu     $zero, $zero, $zero
/* 6D42B8 80220248 00000025 */  or        $zero, $zero, $zero
/* 6D42BC 8022024C 00000002 */  srl       $zero, $zero, 0
/* 6D42C0 80220250 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D42C4 80220254 00000001 */  movf      $zero, $zero, $fcc0
/* 6D42C8 80220258 00000025 */  or        $zero, $zero, $zero
/* 6D42CC 8022025C 00000002 */  srl       $zero, $zero, 0
/* 6D42D0 80220260 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D42D4 80220264 00560001 */  .byte     0x00, 0x56, 0x00, 0x01
/* 6D42D8 80220268 00000046 */  rotrv     $zero, $zero, $zero
/* 6D42DC 8022026C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D42E0 80220270 8029AC70 */  lb        $t1, -0x5390($at)
/* 6D42E4 80220274 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D42E8 80220278 00000001 */  movf      $zero, $zero, $fcc0
/* 6D42EC 8022027C 00000013 */  mtlo      $zero
/* 6D42F0 80220280 00000025 */  or        $zero, $zero, $zero
/* 6D42F4 80220284 00000002 */  srl       $zero, $zero, 0
/* 6D42F8 80220288 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D42FC 8022028C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4300 80220290 00000025 */  or        $zero, $zero, $zero
/* 6D4304 80220294 00000002 */  srl       $zero, $zero, 0
/* 6D4308 80220298 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D430C 8022029C 00560004 */  sllv      $zero, $s6, $v0
/* 6D4310 802202A0 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4314 802202A4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4318 802202A8 80299044 */  lb        $t1, -0x6fbc($at)
/* 6D431C 802202AC 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4320 802202B0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4324 802202B4 8021F97C */  lb        $at, -0x684($at)
/* 6D4328 802202B8 0000001C */  dmult     $zero, $zero
/* 6D432C 802202BC 00000000 */  nop       
/* 6D4330 802202C0 00000023 */  negu      $zero, $zero
/* 6D4334 802202C4 00000000 */  nop       
/* 6D4338 802202C8 00000043 */  sra       $zero, $zero, 1
/* 6D433C 802202CC 00000003 */  sra       $zero, $zero, 0
/* 6D4340 802202D0 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D4344 802202D4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4348 802202D8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D434C 802202DC 00000043 */  sra       $zero, $zero, 1
/* 6D4350 802202E0 00000003 */  sra       $zero, $zero, 0
/* 6D4354 802202E4 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D4358 802202E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D435C 802202EC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4360 802202F0 00000002 */  srl       $zero, $zero, 0
/* 6D4364 802202F4 00000000 */  nop       
/* 6D4368 802202F8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D436C 802202FC 00000000 */  nop       
/* 6D4370 80220300 00000043 */  sra       $zero, $zero, 1
/* 6D4374 80220304 00000003 */  sra       $zero, $zero, 0
/* 6D4378 80220308 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D437C 8022030C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4380 80220310 00000000 */  nop       
/* 6D4384 80220314 00000043 */  sra       $zero, $zero, 1
/* 6D4388 80220318 00000003 */  sra       $zero, $zero, 0
/* 6D438C 8022031C 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D4390 80220320 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4394 80220324 00000000 */  nop       
/* 6D4398 80220328 00000043 */  sra       $zero, $zero, 1
/* 6D439C 8022032C 00000004 */  sllv      $zero, $zero, $zero
/* 6D43A0 80220330 8026F470 */  lb        $a2, -0xb90($at)
/* 6D43A4 80220334 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D43A8 80220338 00000002 */  srl       $zero, $zero, 0
/* 6D43AC 8022033C 000000FF */  dsra32    $zero, $zero, 3
/* 6D43B0 80220340 00000043 */  sra       $zero, $zero, 1
/* 6D43B4 80220344 00000003 */  sra       $zero, $zero, 0
/* 6D43B8 80220348 8027C4E0 */  lb        $a3, -0x3b20($at)
/* 6D43BC 8022034C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D43C0 80220350 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D43C4 80220354 00000014 */  dsllv     $zero, $zero, $zero
/* 6D43C8 80220358 00000001 */  movf      $zero, $zero, $fcc0
/* 6D43CC 8022035C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D43D0 80220360 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D43D4 80220364 00000001 */  movf      $zero, $zero, $fcc0
/* 6D43D8 80220368 00000009 */  jr        $zero
/* 6D43DC 8022036C 00000043 */   sra      $zero, $zero, 1
/* 6D43E0 80220370 00000004 */  sllv      $zero, $zero, $zero
/* 6D43E4 80220374 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D43E8 80220378 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D43EC 8022037C 00000000 */  nop       
/* 6D43F0 80220380 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D43F4 80220384 00000042 */  srl       $zero, $zero, 1
/* 6D43F8 80220388 00000002 */  srl       $zero, $zero, 0
/* 6D43FC 8022038C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4400 80220390 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4404 80220394 00000043 */  sra       $zero, $zero, 1
/* 6D4408 80220398 00000004 */  sllv      $zero, $zero, $zero
/* 6D440C 8022039C 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D4410 802203A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4414 802203A4 00000000 */  nop       
/* 6D4418 802203A8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D441C 802203AC 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4420 802203B0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4424 802203B4 8021EC94 */  lb        $at, -0x136c($at)
/* 6D4428 802203B8 00000025 */  or        $zero, $zero, $zero
/* 6D442C 802203BC 00000002 */  srl       $zero, $zero, 0
/* 6D4430 802203C0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4434 802203C4 00000002 */  srl       $zero, $zero, 0
/* 6D4438 802203C8 00000025 */  or        $zero, $zero, $zero
/* 6D443C 802203CC 00000002 */  srl       $zero, $zero, 0
/* 6D4440 802203D0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4444 802203D4 00570004 */  sllv      $zero, $s7, $v0
/* 6D4448 802203D8 00000046 */  rotrv     $zero, $zero, $zero
/* 6D444C 802203DC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4450 802203E0 80299044 */  lb        $t1, -0x6fbc($at)
/* 6D4454 802203E4 0000001D */  dmultu    $zero, $zero
/* 6D4458 802203E8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D445C 802203EC 0000000A */  movz      $zero, $zero, $zero
/* 6D4460 802203F0 0000001D */  dmultu    $zero, $zero
/* 6D4464 802203F4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4468 802203F8 0000000C */  syscall   
/* 6D446C 802203FC 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4470 80220400 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4474 80220404 8021EC94 */  lb        $at, -0x136c($at)
/* 6D4478 80220408 00000025 */  or        $zero, $zero, $zero
/* 6D447C 8022040C 00000002 */  srl       $zero, $zero, 0
/* 6D4480 80220410 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4484 80220414 00000002 */  srl       $zero, $zero, 0
/* 6D4488 80220418 00000025 */  or        $zero, $zero, $zero
/* 6D448C 8022041C 00000002 */  srl       $zero, $zero, 0
/* 6D4490 80220420 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4494 80220424 00570004 */  sllv      $zero, $s7, $v0
/* 6D4498 80220428 00000046 */  rotrv     $zero, $zero, $zero
/* 6D449C 8022042C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D44A0 80220430 80299044 */  lb        $t1, -0x6fbc($at)
/* 6D44A4 80220434 00000046 */  rotrv     $zero, $zero, $zero
/* 6D44A8 80220438 00000001 */  movf      $zero, $zero, $fcc0
/* 6D44AC 8022043C 8021F97C */  lb        $at, -0x684($at)
/* 6D44B0 80220440 00000046 */  rotrv     $zero, $zero, $zero
/* 6D44B4 80220444 00000001 */  movf      $zero, $zero, $fcc0
/* 6D44B8 80220448 8021EDA0 */  lb        $at, -0x1260($at)
/* 6D44BC 8022044C 00000020 */  add       $zero, $zero, $zero
/* 6D44C0 80220450 00000000 */  nop       
/* 6D44C4 80220454 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D44C8 80220458 00000001 */  movf      $zero, $zero, $fcc0
/* 6D44CC 8022045C 0000003D */  .byte     0x00, 0x00, 0x00, 0x3d
/* 6D44D0 80220460 00000025 */  or        $zero, $zero, $zero
/* 6D44D4 80220464 00000002 */  srl       $zero, $zero, 0
/* 6D44D8 80220468 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D44DC 8022046C 00000002 */  srl       $zero, $zero, 0
/* 6D44E0 80220470 00000025 */  or        $zero, $zero, $zero
/* 6D44E4 80220474 00000002 */  srl       $zero, $zero, 0
/* 6D44E8 80220478 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D44EC 8022047C 00570004 */  sllv      $zero, $s7, $v0
/* 6D44F0 80220480 00000046 */  rotrv     $zero, $zero, $zero
/* 6D44F4 80220484 00000001 */  movf      $zero, $zero, $fcc0
/* 6D44F8 80220488 80299044 */  lb        $t1, -0x6fbc($at)
/* 6D44FC 8022048C 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4500 80220490 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4504 80220494 8021F97C */  lb        $at, -0x684($at)
/* 6D4508 80220498 0000001D */  dmultu    $zero, $zero
/* 6D450C 8022049C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4510 802204A0 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D4514 802204A4 0000001D */  dmultu    $zero, $zero
/* 6D4518 802204A8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D451C 802204AC 0000000F */  sync      
/* 6D4520 802204B0 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4524 802204B4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4528 802204B8 8021EC94 */  lb        $at, -0x136c($at)
/* 6D452C 802204BC 00000025 */  or        $zero, $zero, $zero
/* 6D4530 802204C0 00000002 */  srl       $zero, $zero, 0
/* 6D4534 802204C4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4538 802204C8 00000002 */  srl       $zero, $zero, 0
/* 6D453C 802204CC 00000025 */  or        $zero, $zero, $zero
/* 6D4540 802204D0 00000002 */  srl       $zero, $zero, 0
/* 6D4544 802204D4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4548 802204D8 00570005 */  lsa       $zero, $v0, $s7, 1
/* 6D454C 802204DC 00000025 */  or        $zero, $zero, $zero
/* 6D4550 802204E0 00000002 */  srl       $zero, $zero, 0
/* 6D4554 802204E4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D4558 802204E8 00570006 */  srlv      $zero, $s7, $v0
/* 6D455C 802204EC 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4560 802204F0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4564 802204F4 8029A0D0 */  lb        $t1, -0x5f30($at)
/* 6D4568 802204F8 00000046 */  rotrv     $zero, $zero, $zero
/* 6D456C 802204FC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4570 80220500 8021F97C */  lb        $at, -0x684($at)
/* 6D4574 80220504 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4578 80220508 00000001 */  movf      $zero, $zero, $fcc0
/* 6D457C 8022050C 8021EDA0 */  lb        $at, -0x1260($at)
/* 6D4580 80220510 00000020 */  add       $zero, $zero, $zero
/* 6D4584 80220514 00000000 */  nop       
/* 6D4588 80220518 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D458C 8022051C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4590 80220520 00000024 */  and       $zero, $zero, $zero
/* 6D4594 80220524 00000025 */  or        $zero, $zero, $zero
/* 6D4598 80220528 00000002 */  srl       $zero, $zero, 0
/* 6D459C 8022052C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D45A0 80220530 00000002 */  srl       $zero, $zero, 0
/* 6D45A4 80220534 00000025 */  or        $zero, $zero, $zero
/* 6D45A8 80220538 00000002 */  srl       $zero, $zero, 0
/* 6D45AC 8022053C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D45B0 80220540 00570005 */  lsa       $zero, $v0, $s7, 1
/* 6D45B4 80220544 00000025 */  or        $zero, $zero, $zero
/* 6D45B8 80220548 00000002 */  srl       $zero, $zero, 0
/* 6D45BC 8022054C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D45C0 80220550 00570006 */  srlv      $zero, $s7, $v0
/* 6D45C4 80220554 00000046 */  rotrv     $zero, $zero, $zero
/* 6D45C8 80220558 00000001 */  movf      $zero, $zero, $fcc0
/* 6D45CC 8022055C 8029A0D0 */  lb        $t1, -0x5f30($at)
/* 6D45D0 80220560 00000046 */  rotrv     $zero, $zero, $zero
/* 6D45D4 80220564 00000001 */  movf      $zero, $zero, $fcc0
/* 6D45D8 80220568 8021F97C */  lb        $at, -0x684($at)
/* 6D45DC 8022056C 00000025 */  or        $zero, $zero, $zero
/* 6D45E0 80220570 00000002 */  srl       $zero, $zero, 0
/* 6D45E4 80220574 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D45E8 80220578 00000002 */  srl       $zero, $zero, 0
/* 6D45EC 8022057C 00000025 */  or        $zero, $zero, $zero
/* 6D45F0 80220580 00000002 */  srl       $zero, $zero, 0
/* 6D45F4 80220584 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D45F8 80220588 00570006 */  srlv      $zero, $s7, $v0
/* 6D45FC 8022058C 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4600 80220590 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4604 80220594 8029AEC0 */  lb        $t1, -0x5140($at)
/* 6D4608 80220598 00000002 */  srl       $zero, $zero, 0
/* 6D460C 8022059C 00000000 */  nop       
/* 6D4610 802205A0 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D4614 802205A4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4618 802205A8 0000000B */  movn      $zero, $zero, $zero
/* 6D461C 802205AC 00000025 */  or        $zero, $zero, $zero
/* 6D4620 802205B0 00000002 */  srl       $zero, $zero, 0
/* 6D4624 802205B4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4628 802205B8 00000002 */  srl       $zero, $zero, 0
/* 6D462C 802205BC 00000025 */  or        $zero, $zero, $zero
/* 6D4630 802205C0 00000002 */  srl       $zero, $zero, 0
/* 6D4634 802205C4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4638 802205C8 00570004 */  sllv      $zero, $s7, $v0
/* 6D463C 802205CC 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4640 802205D0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4644 802205D4 8029B998 */  lb        $t1, -0x4668($at)
/* 6D4648 802205D8 00000046 */  rotrv     $zero, $zero, $zero
/* 6D464C 802205DC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4650 802205E0 8021F97C */  lb        $at, -0x684($at)
/* 6D4654 802205E4 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D4658 802205E8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D465C 802205EC 00000021 */  addu      $zero, $zero, $zero
/* 6D4660 802205F0 00000025 */  or        $zero, $zero, $zero
/* 6D4664 802205F4 00000002 */  srl       $zero, $zero, 0
/* 6D4668 802205F8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D466C 802205FC 00000002 */  srl       $zero, $zero, 0
/* 6D4670 80220600 00000025 */  or        $zero, $zero, $zero
/* 6D4674 80220604 00000002 */  srl       $zero, $zero, 0
/* 6D4678 80220608 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D467C 8022060C 00570004 */  sllv      $zero, $s7, $v0
/* 6D4680 80220610 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4684 80220614 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4688 80220618 8029B998 */  lb        $t1, -0x4668($at)
/* 6D468C 8022061C 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4690 80220620 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4694 80220624 8021F97C */  lb        $at, -0x684($at)
/* 6D4698 80220628 00000025 */  or        $zero, $zero, $zero
/* 6D469C 8022062C 00000002 */  srl       $zero, $zero, 0
/* 6D46A0 80220630 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D46A4 80220634 00000002 */  srl       $zero, $zero, 0
/* 6D46A8 80220638 00000025 */  or        $zero, $zero, $zero
/* 6D46AC 8022063C 00000002 */  srl       $zero, $zero, 0
/* 6D46B0 80220640 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D46B4 80220644 00570004 */  sllv      $zero, $s7, $v0
/* 6D46B8 80220648 00000046 */  rotrv     $zero, $zero, $zero
/* 6D46BC 8022064C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D46C0 80220650 8029AEC0 */  lb        $t1, -0x5140($at)
/* 6D46C4 80220654 00000002 */  srl       $zero, $zero, 0
/* 6D46C8 80220658 00000000 */  nop       
/* 6D46CC 8022065C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D46D0 80220660 00000001 */  movf      $zero, $zero, $fcc0
/* 6D46D4 80220664 00000017 */  dsrav     $zero, $zero, $zero
/* 6D46D8 80220668 00000025 */  or        $zero, $zero, $zero
/* 6D46DC 8022066C 00000002 */  srl       $zero, $zero, 0
/* 6D46E0 80220670 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D46E4 80220674 00000002 */  srl       $zero, $zero, 0
/* 6D46E8 80220678 00000025 */  or        $zero, $zero, $zero
/* 6D46EC 8022067C 00000002 */  srl       $zero, $zero, 0
/* 6D46F0 80220680 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D46F4 80220684 00570001 */  .byte     0x00, 0x57, 0x00, 0x01
/* 6D46F8 80220688 00000046 */  rotrv     $zero, $zero, $zero
/* 6D46FC 8022068C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4700 80220690 8029AC70 */  lb        $t1, -0x5390($at)
/* 6D4704 80220694 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D4708 80220698 00000001 */  movf      $zero, $zero, $fcc0
/* 6D470C 8022069C 00000019 */  multu     $zero, $zero
/* 6D4710 802206A0 00000025 */  or        $zero, $zero, $zero
/* 6D4714 802206A4 00000002 */  srl       $zero, $zero, 0
/* 6D4718 802206A8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D471C 802206AC 00000002 */  srl       $zero, $zero, 0
/* 6D4720 802206B0 00000025 */  or        $zero, $zero, $zero
/* 6D4724 802206B4 00000002 */  srl       $zero, $zero, 0
/* 6D4728 802206B8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D472C 802206BC 00570001 */  .byte     0x00, 0x57, 0x00, 0x01
/* 6D4730 802206C0 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4734 802206C4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4738 802206C8 8029AC70 */  lb        $t1, -0x5390($at)
/* 6D473C 802206CC 00000043 */  sra       $zero, $zero, 1
/* 6D4740 802206D0 00000004 */  sllv      $zero, $zero, $zero
/* 6D4744 802206D4 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D4748 802206D8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D474C 802206DC 00000000 */  nop       
/* 6D4750 802206E0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4754 802206E4 00000010 */  mfhi      $zero
/* 6D4758 802206E8 00000002 */  srl       $zero, $zero, 0
/* 6D475C 802206EC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4760 802206F0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4764 802206F4 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4768 802206F8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D476C 802206FC 8021F97C */  lb        $at, -0x684($at)
/* 6D4770 80220700 00000002 */  srl       $zero, $zero, 0
/* 6D4774 80220704 00000000 */  nop       
/* 6D4778 80220708 00000013 */  mtlo      $zero
/* 6D477C 8022070C 00000000 */  nop       
/* 6D4780 80220710 00000043 */  sra       $zero, $zero, 1
/* 6D4784 80220714 00000003 */  sra       $zero, $zero, 0
/* 6D4788 80220718 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D478C 8022071C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4790 80220720 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4794 80220724 0000000B */  movn      $zero, $zero, $zero
/* 6D4798 80220728 00000002 */  srl       $zero, $zero, 0
/* 6D479C 8022072C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D47A0 80220730 00000000 */  nop       
/* 6D47A4 80220734 00000046 */  rotrv     $zero, $zero, $zero
/* 6D47A8 80220738 00000001 */  movf      $zero, $zero, $fcc0
/* 6D47AC 8022073C 8021F97C */  lb        $at, -0x684($at)
/* 6D47B0 80220740 00000013 */  mtlo      $zero
/* 6D47B4 80220744 00000000 */  nop       
/* 6D47B8 80220748 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D47BC 8022074C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D47C0 80220750 00000020 */  add       $zero, $zero, $zero
/* 6D47C4 80220754 00000025 */  or        $zero, $zero, $zero
/* 6D47C8 80220758 00000002 */  srl       $zero, $zero, 0
/* 6D47CC 8022075C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D47D0 80220760 00000002 */  srl       $zero, $zero, 0
/* 6D47D4 80220764 00000025 */  or        $zero, $zero, $zero
/* 6D47D8 80220768 00000002 */  srl       $zero, $zero, 0
/* 6D47DC 8022076C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D47E0 80220770 00570004 */  sllv      $zero, $s7, $v0
/* 6D47E4 80220774 00000046 */  rotrv     $zero, $zero, $zero
/* 6D47E8 80220778 00000001 */  movf      $zero, $zero, $fcc0
/* 6D47EC 8022077C 80299044 */  lb        $t1, -0x6fbc($at)
/* 6D47F0 80220780 00000046 */  rotrv     $zero, $zero, $zero
/* 6D47F4 80220784 00000001 */  movf      $zero, $zero, $fcc0
/* 6D47F8 80220788 8021F97C */  lb        $at, -0x684($at)
/* 6D47FC 8022078C 00000008 */  jr        $zero
/* 6D4800 80220790 00000001 */   movf     $zero, $zero, $fcc0
/* 6D4804 80220794 0000000A */  movz      $zero, $zero, $zero
/* 6D4808 80220798 00000025 */  or        $zero, $zero, $zero
/* 6D480C 8022079C 00000002 */  srl       $zero, $zero, 0
/* 6D4810 802207A0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4814 802207A4 00000002 */  srl       $zero, $zero, 0
/* 6D4818 802207A8 00000025 */  or        $zero, $zero, $zero
/* 6D481C 802207AC 00000002 */  srl       $zero, $zero, 0
/* 6D4820 802207B0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4824 802207B4 00570004 */  sllv      $zero, $s7, $v0
/* 6D4828 802207B8 00000046 */  rotrv     $zero, $zero, $zero
/* 6D482C 802207BC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4830 802207C0 8029AEC0 */  lb        $t1, -0x5140($at)
/* 6D4834 802207C4 00000002 */  srl       $zero, $zero, 0
/* 6D4838 802207C8 00000000 */  nop       
/* 6D483C 802207CC 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D4840 802207D0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4844 802207D4 00000038 */  dsll      $zero, $zero, 0
/* 6D4848 802207D8 00000043 */  sra       $zero, $zero, 1
/* 6D484C 802207DC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D4850 802207E0 8026AE40 */  lb        $a2, -0x51c0($at)
/* 6D4854 802207E4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4858 802207E8 00000014 */  dsllv     $zero, $zero, $zero
/* 6D485C 802207EC 00000000 */  nop       
/* 6D4860 802207F0 00000000 */  nop       
/* 6D4864 802207F4 00000043 */  sra       $zero, $zero, 1
/* 6D4868 802207F8 00000002 */  srl       $zero, $zero, 0
/* 6D486C 802207FC 8026D7A8 */  lb        $a2, -0x2858($at)
/* 6D4870 80220800 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4874 80220804 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D4878 80220808 00000001 */  movf      $zero, $zero, $fcc0
/* 6D487C 8022080C 00000035 */  .byte     0x00, 0x00, 0x00, 0x35
/* 6D4880 80220810 00000043 */  sra       $zero, $zero, 1
/* 6D4884 80220814 00000004 */  sllv      $zero, $zero, $zero
/* 6D4888 80220818 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D488C 8022081C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4890 80220820 00000002 */  srl       $zero, $zero, 0
/* 6D4894 80220824 00570001 */  .byte     0x00, 0x57, 0x00, 0x01
/* 6D4898 80220828 00000043 */  sra       $zero, $zero, 1
/* 6D489C 8022082C 00000002 */  srl       $zero, $zero, 0
/* 6D48A0 80220830 80269EC4 */  lb        $a2, -0x613c($at)
/* 6D48A4 80220834 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D48A8 80220838 00000043 */  sra       $zero, $zero, 1
/* 6D48AC 8022083C 00000003 */  sra       $zero, $zero, 0
/* 6D48B0 80220840 8026B654 */  lb        $a2, -0x49ac($at)
/* 6D48B4 80220844 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D48B8 80220848 F24A8A80 */  scd       $t2, -0x7580($s2)
/* 6D48BC 8022084C 00000043 */  sra       $zero, $zero, 1
/* 6D48C0 80220850 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D48C4 80220854 8027B624 */  lb        $a3, -0x49dc($at)
/* 6D48C8 80220858 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D48CC 8022085C 00000000 */  nop       
/* 6D48D0 80220860 00000001 */  movf      $zero, $zero, $fcc0
/* 6D48D4 80220864 00000000 */  nop       
/* 6D48D8 80220868 00000043 */  sra       $zero, $zero, 1
/* 6D48DC 8022086C 00000004 */  sllv      $zero, $zero, $zero
/* 6D48E0 80220870 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D48E4 80220874 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D48E8 80220878 00000002 */  srl       $zero, $zero, 0
/* 6D48EC 8022087C 00570001 */  .byte     0x00, 0x57, 0x00, 0x01
/* 6D48F0 80220880 00000043 */  sra       $zero, $zero, 1
/* 6D48F4 80220884 00000002 */  srl       $zero, $zero, 0
/* 6D48F8 80220888 8026D664 */  lb        $a2, -0x299c($at)
/* 6D48FC 8022088C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4900 80220890 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D4904 80220894 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4908 80220898 00000031 */  tgeu      $zero, $zero
/* 6D490C 8022089C 00000025 */  or        $zero, $zero, $zero
/* 6D4910 802208A0 00000002 */  srl       $zero, $zero, 0
/* 6D4914 802208A4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4918 802208A8 00000002 */  srl       $zero, $zero, 0
/* 6D491C 802208AC 00000025 */  or        $zero, $zero, $zero
/* 6D4920 802208B0 00000002 */  srl       $zero, $zero, 0
/* 6D4924 802208B4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4928 802208B8 00570001 */  .byte     0x00, 0x57, 0x00, 0x01
/* 6D492C 802208BC 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4930 802208C0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4934 802208C4 8029BFA0 */  lb        $t1, -0x4060($at)
/* 6D4938 802208C8 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D493C 802208CC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4940 802208D0 00000039 */  .byte     0x00, 0x00, 0x00, 0x39
/* 6D4944 802208D4 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4948 802208D8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D494C 802208DC 8021F97C */  lb        $at, -0x684($at)
/* 6D4950 802208E0 00000043 */  sra       $zero, $zero, 1
/* 6D4954 802208E4 00000004 */  sllv      $zero, $zero, $zero
/* 6D4958 802208E8 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D495C 802208EC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4960 802208F0 00000002 */  srl       $zero, $zero, 0
/* 6D4964 802208F4 00570004 */  sllv      $zero, $s7, $v0
/* 6D4968 802208F8 00000043 */  sra       $zero, $zero, 1
/* 6D496C 802208FC 00000003 */  sra       $zero, $zero, 0
/* 6D4970 80220900 8026B55C */  lb        $a2, -0x4aa4($at)
/* 6D4974 80220904 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4978 80220908 F24A8080 */  scd       $t2, -0x7f80($s2)
/* 6D497C 8022090C 00000043 */  sra       $zero, $zero, 1
/* 6D4980 80220910 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D4984 80220914 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D4988 80220918 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D498C 8022091C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4990 80220920 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4994 80220924 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D4998 80220928 00000043 */  sra       $zero, $zero, 1
/* 6D499C 8022092C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D49A0 80220930 8026A510 */  lb        $a2, -0x5af0($at)
/* 6D49A4 80220934 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D49A8 80220938 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D49AC 8022093C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D49B0 80220940 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D49B4 80220944 00000043 */  sra       $zero, $zero, 1
/* 6D49B8 80220948 00000006 */  srlv      $zero, $zero, $zero
/* 6D49BC 8022094C 80278D08 */  lb        $a3, -0x72f8($at)
/* 6D49C0 80220950 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D49C4 80220954 0000000F */  sync      
/* 6D49C8 80220958 00000000 */  nop       
/* 6D49CC 8022095C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D49D0 80220960 00000000 */  nop       
/* 6D49D4 80220964 00000008 */  jr        $zero
/* 6D49D8 80220968 00000001 */   movf     $zero, $zero, $fcc0
/* 6D49DC 8022096C 0000000F */  sync      
/* 6D49E0 80220970 00000043 */  sra       $zero, $zero, 1
/* 6D49E4 80220974 00000004 */  sllv      $zero, $zero, $zero
/* 6D49E8 80220978 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D49EC 8022097C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D49F0 80220980 00000002 */  srl       $zero, $zero, 0
/* 6D49F4 80220984 00570002 */  .byte     0x00, 0x57, 0x00, 0x02
/* 6D49F8 80220988 00000046 */  rotrv     $zero, $zero, $zero
/* 6D49FC 8022098C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4A00 80220990 8021F39C */  lb        $at, -0xc64($at)
/* 6D4A04 80220994 00000002 */  srl       $zero, $zero, 0
/* 6D4A08 80220998 00000000 */  nop       
/* 6D4A0C 8022099C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D4A10 802209A0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4A14 802209A4 0000003A */  dsrl      $zero, $zero, 0
/* 6D4A18 802209A8 00000025 */  or        $zero, $zero, $zero
/* 6D4A1C 802209AC 00000002 */  srl       $zero, $zero, 0
/* 6D4A20 802209B0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4A24 802209B4 00000002 */  srl       $zero, $zero, 0
/* 6D4A28 802209B8 00000025 */  or        $zero, $zero, $zero
/* 6D4A2C 802209BC 00000002 */  srl       $zero, $zero, 0
/* 6D4A30 802209C0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4A34 802209C4 00570002 */  .byte     0x00, 0x57, 0x00, 0x02
/* 6D4A38 802209C8 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4A3C 802209CC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4A40 802209D0 8029C37C */  lb        $t1, -0x3c84($at)
/* 6D4A44 802209D4 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D4A48 802209D8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4A4C 802209DC 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D4A50 802209E0 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4A54 802209E4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4A58 802209E8 8021F97C */  lb        $at, -0x684($at)
/* 6D4A5C 802209EC 00000043 */  sra       $zero, $zero, 1
/* 6D4A60 802209F0 00000003 */  sra       $zero, $zero, 0
/* 6D4A64 802209F4 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D4A68 802209F8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4A6C 802209FC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4A70 80220A00 00000011 */  mthi      $zero
/* 6D4A74 80220A04 00000002 */  srl       $zero, $zero, 0
/* 6D4A78 80220A08 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4A7C 80220A0C 0035D000 */  .byte     0x00, 0x35, 0xd0, 0x00
/* 6D4A80 80220A10 00000010 */  mfhi      $zero
/* 6D4A84 80220A14 00000002 */  srl       $zero, $zero, 0
/* 6D4A88 80220A18 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4A8C 80220A1C 00080000 */  sll       $zero, $t0, 0
/* 6D4A90 80220A20 00000043 */  sra       $zero, $zero, 1
/* 6D4A94 80220A24 00000006 */  srlv      $zero, $zero, $zero
/* 6D4A98 80220A28 8026BC38 */  lb        $a2, -0x43c8($at)
/* 6D4A9C 80220A2C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4AA0 80220A30 00000002 */  srl       $zero, $zero, 0
/* 6D4AA4 80220A34 FFFFFFFD */  sd        $ra, -3($ra)
/* 6D4AA8 80220A38 00000000 */  nop       
/* 6D4AAC 80220A3C 00000000 */  nop       
/* 6D4AB0 80220A40 00000012 */  mflo      $zero
/* 6D4AB4 80220A44 00000000 */  nop       
/* 6D4AB8 80220A48 00000043 */  sra       $zero, $zero, 1
/* 6D4ABC 80220A4C 00000006 */  srlv      $zero, $zero, $zero
/* 6D4AC0 80220A50 8026BC38 */  lb        $a2, -0x43c8($at)
/* 6D4AC4 80220A54 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4AC8 80220A58 00000002 */  srl       $zero, $zero, 0
/* 6D4ACC 80220A5C FFFFFFF1 */  sd        $ra, -0xf($ra)
/* 6D4AD0 80220A60 00000000 */  nop       
/* 6D4AD4 80220A64 00000000 */  nop       
/* 6D4AD8 80220A68 00000013 */  mtlo      $zero
/* 6D4ADC 80220A6C 00000000 */  nop       
/* 6D4AE0 80220A70 00000013 */  mtlo      $zero
/* 6D4AE4 80220A74 00000000 */  nop       
/* 6D4AE8 80220A78 00000025 */  or        $zero, $zero, $zero
/* 6D4AEC 80220A7C 00000002 */  srl       $zero, $zero, 0
/* 6D4AF0 80220A80 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4AF4 80220A84 00000002 */  srl       $zero, $zero, 0
/* 6D4AF8 80220A88 00000025 */  or        $zero, $zero, $zero
/* 6D4AFC 80220A8C 00000002 */  srl       $zero, $zero, 0
/* 6D4B00 80220A90 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4B04 80220A94 00570004 */  sllv      $zero, $s7, $v0
/* 6D4B08 80220A98 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4B0C 80220A9C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4B10 80220AA0 8029C4A8 */  lb        $t1, -0x3b58($at)
/* 6D4B14 80220AA4 00000002 */  srl       $zero, $zero, 0
/* 6D4B18 80220AA8 00000000 */  nop       
/* 6D4B1C 80220AAC 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D4B20 80220AB0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4B24 80220AB4 0000001F */  ddivu     $zero, $zero, $zero
/* 6D4B28 80220AB8 00000025 */  or        $zero, $zero, $zero
/* 6D4B2C 80220ABC 00000002 */  srl       $zero, $zero, 0
/* 6D4B30 80220AC0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4B34 80220AC4 00000002 */  srl       $zero, $zero, 0
/* 6D4B38 80220AC8 00000025 */  or        $zero, $zero, $zero
/* 6D4B3C 80220ACC 00000002 */  srl       $zero, $zero, 0
/* 6D4B40 80220AD0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4B44 80220AD4 00570001 */  .byte     0x00, 0x57, 0x00, 0x01
/* 6D4B48 80220AD8 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4B4C 80220ADC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4B50 80220AE0 8029AC70 */  lb        $t1, -0x5390($at)
/* 6D4B54 80220AE4 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D4B58 80220AE8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4B5C 80220AEC 00000013 */  mtlo      $zero
/* 6D4B60 80220AF0 00000025 */  or        $zero, $zero, $zero
/* 6D4B64 80220AF4 00000002 */  srl       $zero, $zero, 0
/* 6D4B68 80220AF8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4B6C 80220AFC 00000002 */  srl       $zero, $zero, 0
/* 6D4B70 80220B00 00000025 */  or        $zero, $zero, $zero
/* 6D4B74 80220B04 00000002 */  srl       $zero, $zero, 0
/* 6D4B78 80220B08 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4B7C 80220B0C 00570004 */  sllv      $zero, $s7, $v0
/* 6D4B80 80220B10 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4B84 80220B14 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4B88 80220B18 80299044 */  lb        $t1, -0x6fbc($at)
/* 6D4B8C 80220B1C 00000046 */  rotrv     $zero, $zero, $zero
/* 6D4B90 80220B20 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4B94 80220B24 8021F97C */  lb        $at, -0x684($at)
/* 6D4B98 80220B28 0000001C */  dmult     $zero, $zero
/* 6D4B9C 80220B2C 00000000 */  nop       
/* 6D4BA0 80220B30 00000023 */  negu      $zero, $zero
/* 6D4BA4 80220B34 00000000 */  nop       
/* 6D4BA8 80220B38 00000043 */  sra       $zero, $zero, 1
/* 6D4BAC 80220B3C 00000003 */  sra       $zero, $zero, 0
/* 6D4BB0 80220B40 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D4BB4 80220B44 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4BB8 80220B48 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4BBC 80220B4C 00000043 */  sra       $zero, $zero, 1
/* 6D4BC0 80220B50 00000003 */  sra       $zero, $zero, 0
/* 6D4BC4 80220B54 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D4BC8 80220B58 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4BCC 80220B5C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4BD0 80220B60 00000002 */  srl       $zero, $zero, 0
/* 6D4BD4 80220B64 00000000 */  nop       
/* 6D4BD8 80220B68 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4BDC 80220B6C 00000000 */  nop       
/* 6D4BE0 80220B70 00000043 */  sra       $zero, $zero, 1
/* 6D4BE4 80220B74 00000004 */  sllv      $zero, $zero, $zero
/* 6D4BE8 80220B78 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D4BEC 80220B7C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4BF0 80220B80 0000000A */  movz      $zero, $zero, $zero
/* 6D4BF4 80220B84 00000000 */  nop       
/* 6D4BF8 80220B88 00000043 */  sra       $zero, $zero, 1
/* 6D4BFC 80220B8C 00000004 */  sllv      $zero, $zero, $zero
/* 6D4C00 80220B90 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D4C04 80220B94 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4C08 80220B98 0000000B */  movn      $zero, $zero, $zero
/* 6D4C0C 80220B9C 00000000 */  nop       
/* 6D4C10 80220BA0 00000043 */  sra       $zero, $zero, 1
/* 6D4C14 80220BA4 00000004 */  sllv      $zero, $zero, $zero
/* 6D4C18 80220BA8 8026C0D4 */  lb        $a2, -0x3f2c($at)
/* 6D4C1C 80220BAC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4C20 80220BB0 00000004 */  sllv      $zero, $zero, $zero
/* 6D4C24 80220BB4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4C28 80220BB8 00000043 */  sra       $zero, $zero, 1
/* 6D4C2C 80220BBC 00000003 */  sra       $zero, $zero, 0
/* 6D4C30 80220BC0 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D4C34 80220BC4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4C38 80220BC8 00000000 */  nop       
/* 6D4C3C 80220BCC 00000043 */  sra       $zero, $zero, 1
/* 6D4C40 80220BD0 00000003 */  sra       $zero, $zero, 0
/* 6D4C44 80220BD4 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D4C48 80220BD8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4C4C 80220BDC 00000000 */  nop       
/* 6D4C50 80220BE0 00000043 */  sra       $zero, $zero, 1
/* 6D4C54 80220BE4 00000003 */  sra       $zero, $zero, 0
/* 6D4C58 80220BE8 8027C548 */  lb        $a3, -0x3ab8($at)
/* 6D4C5C 80220BEC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4C60 80220BF0 00000000 */  nop       
/* 6D4C64 80220BF4 00000043 */  sra       $zero, $zero, 1
/* 6D4C68 80220BF8 00000002 */  srl       $zero, $zero, 0
/* 6D4C6C 80220BFC 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D4C70 80220C00 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D4C74 80220C04 00000043 */  sra       $zero, $zero, 1
/* 6D4C78 80220C08 00000002 */  srl       $zero, $zero, 0
/* 6D4C7C 80220C0C 8024EB24 */  lb        $a0, -0x14dc($at)
/* 6D4C80 80220C10 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4C84 80220C14 00000043 */  sra       $zero, $zero, 1
/* 6D4C88 80220C18 00000002 */  srl       $zero, $zero, 0
/* 6D4C8C 80220C1C 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6D4C90 80220C20 0000000F */  sync      
/* 6D4C94 80220C24 00000008 */  jr        $zero
/* 6D4C98 80220C28 00000001 */   movf     $zero, $zero, $fcc0
/* 6D4C9C 80220C2C 0000000F */  sync      
/* 6D4CA0 80220C30 00000043 */  sra       $zero, $zero, 1
/* 6D4CA4 80220C34 00000003 */  sra       $zero, $zero, 0
/* 6D4CA8 80220C38 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D4CAC 80220C3C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4CB0 80220C40 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4CB4 80220C44 00000011 */  mthi      $zero
/* 6D4CB8 80220C48 00000002 */  srl       $zero, $zero, 0
/* 6D4CBC 80220C4C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4CC0 80220C50 00000200 */  sll       $zero, $zero, 8
/* 6D4CC4 80220C54 00000043 */  sra       $zero, $zero, 1
/* 6D4CC8 80220C58 00000004 */  sllv      $zero, $zero, $zero
/* 6D4CCC 80220C5C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D4CD0 80220C60 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4CD4 80220C64 00000001 */  movf      $zero, $zero, $fcc0
/* 6D4CD8 80220C68 00560002 */  .byte     0x00, 0x56, 0x00, 0x02
/* 6D4CDC 80220C6C 00000012 */  mflo      $zero
/* 6D4CE0 80220C70 00000000 */  nop       
/* 6D4CE4 80220C74 00000043 */  sra       $zero, $zero, 1
/* 6D4CE8 80220C78 00000004 */  sllv      $zero, $zero, $zero
/* 6D4CEC 80220C7C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D4CF0 80220C80 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4CF4 80220C84 00000002 */  srl       $zero, $zero, 0
/* 6D4CF8 80220C88 00570002 */  .byte     0x00, 0x57, 0x00, 0x02
/* 6D4CFC 80220C8C 00000013 */  mtlo      $zero
/* 6D4D00 80220C90 00000000 */  nop       
/* 6D4D04 80220C94 00000008 */  jr        $zero
/* 6D4D08 80220C98 00000001 */   movf     $zero, $zero, $fcc0
/* 6D4D0C 80220C9C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D4D10 80220CA0 00000043 */  sra       $zero, $zero, 1
/* 6D4D14 80220CA4 00000003 */  sra       $zero, $zero, 0
/* 6D4D18 80220CA8 8025385C */  lb        $a1, 0x385c($at)
/* 6D4D1C 80220CAC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4D20 80220CB0 000020D4 */  .byte     0x00, 0x00, 0x20, 0xd4
/* 6D4D24 80220CB4 00000043 */  sra       $zero, $zero, 1
/* 6D4D28 80220CB8 00000003 */  sra       $zero, $zero, 0
/* 6D4D2C 80220CBC 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D4D30 80220CC0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4D34 80220CC4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4D38 80220CC8 00000011 */  mthi      $zero
/* 6D4D3C 80220CCC 00000002 */  srl       $zero, $zero, 0
/* 6D4D40 80220CD0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4D44 80220CD4 00000200 */  sll       $zero, $zero, 8
/* 6D4D48 80220CD8 00000043 */  sra       $zero, $zero, 1
/* 6D4D4C 80220CDC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D4D50 80220CE0 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D4D54 80220CE4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4D58 80220CE8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4D5C 80220CEC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4D60 80220CF0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D4D64 80220CF4 00000043 */  sra       $zero, $zero, 1
/* 6D4D68 80220CF8 00000003 */  sra       $zero, $zero, 0
/* 6D4D6C 80220CFC 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D4D70 80220D00 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4D74 80220D04 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D4D78 80220D08 00000010 */  mfhi      $zero
/* 6D4D7C 80220D0C 00000002 */  srl       $zero, $zero, 0
/* 6D4D80 80220D10 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D4D84 80220D14 00080000 */  sll       $zero, $t0, 0
/* 6D4D88 80220D18 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D4D8C 80220D1C 00000002 */  srl       $zero, $zero, 0
/* 6D4D90 80220D20 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4D94 80220D24 00000006 */  srlv      $zero, $zero, $zero
/* 6D4D98 80220D28 00000027 */  not       $zero, $zero
/* 6D4D9C 80220D2C 00000002 */  srl       $zero, $zero, 0
/* 6D4DA0 80220D30 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4DA4 80220D34 0000000C */  syscall   
/* 6D4DA8 80220D38 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D4DAC 80220D3C 00000002 */  srl       $zero, $zero, 0
/* 6D4DB0 80220D40 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D4DB4 80220D44 00000002 */  srl       $zero, $zero, 0
/* 6D4DB8 80220D48 00000043 */  sra       $zero, $zero, 1
/* 6D4DBC 80220D4C 0000000F */  sync      
/* 6D4DC0 80220D50 802D829C */  lb        $t5, -0x7d64($at)
/* 6D4DC4 80220D54 00000033 */  tltu      $zero, $zero
/* 6D4DC8 80220D58 00000007 */  srav      $zero, $zero, $zero
/* 6D4DCC 80220D5C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4DD0 80220D60 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4DD4 80220D64 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D4DD8 80220D68 F24A7AFB */  scd       $t2, 0x7afb($s2)
/* 6D4DDC 80220D6C 0000001E */  ddiv      $zero, $zero, $zero
/* 6D4DE0 80220D70 00000000 */  nop       
/* 6D4DE4 80220D74 00000000 */  nop       
/* 6D4DE8 80220D78 00000000 */  nop       
/* 6D4DEC 80220D7C 00000000 */  nop       
/* 6D4DF0 80220D80 00000000 */  nop       
/* 6D4DF4 80220D84 00000000 */  nop       
/* 6D4DF8 80220D88 00000000 */  nop       
/* 6D4DFC 80220D8C 00000012 */  mflo      $zero
/* 6D4E00 80220D90 00000000 */  nop       
/* 6D4E04 80220D94 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D4E08 80220D98 00000002 */  srl       $zero, $zero, 0
/* 6D4E0C 80220D9C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4E10 80220DA0 00000010 */  mfhi      $zero
/* 6D4E14 80220DA4 00000027 */  not       $zero, $zero
/* 6D4E18 80220DA8 00000002 */  srl       $zero, $zero, 0
/* 6D4E1C 80220DAC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4E20 80220DB0 0000001F */  ddivu     $zero, $zero, $zero
/* 6D4E24 80220DB4 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D4E28 80220DB8 00000002 */  srl       $zero, $zero, 0
/* 6D4E2C 80220DBC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D4E30 80220DC0 00000002 */  srl       $zero, $zero, 0
/* 6D4E34 80220DC4 00000043 */  sra       $zero, $zero, 1
/* 6D4E38 80220DC8 0000000F */  sync      
/* 6D4E3C 80220DCC 802D829C */  lb        $t5, -0x7d64($at)
/* 6D4E40 80220DD0 00000033 */  tltu      $zero, $zero
/* 6D4E44 80220DD4 00000007 */  srav      $zero, $zero, $zero
/* 6D4E48 80220DD8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4E4C 80220DDC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4E50 80220DE0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D4E54 80220DE4 F24A7BB4 */  scd       $t2, 0x7bb4($s2)
/* 6D4E58 80220DE8 0000001E */  ddiv      $zero, $zero, $zero
/* 6D4E5C 80220DEC 00000000 */  nop       
/* 6D4E60 80220DF0 00000000 */  nop       
/* 6D4E64 80220DF4 00000000 */  nop       
/* 6D4E68 80220DF8 00000000 */  nop       
/* 6D4E6C 80220DFC 00000000 */  nop       
/* 6D4E70 80220E00 00000000 */  nop       
/* 6D4E74 80220E04 00000000 */  nop       
/* 6D4E78 80220E08 00000013 */  mtlo      $zero
/* 6D4E7C 80220E0C 00000000 */  nop       
/* 6D4E80 80220E10 00000012 */  mflo      $zero
/* 6D4E84 80220E14 00000000 */  nop       
/* 6D4E88 80220E18 00000043 */  sra       $zero, $zero, 1
/* 6D4E8C 80220E1C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D4E90 80220E20 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D4E94 80220E24 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4E98 80220E28 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4E9C 80220E2C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4EA0 80220E30 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D4EA4 80220E34 00000043 */  sra       $zero, $zero, 1
/* 6D4EA8 80220E38 00000003 */  sra       $zero, $zero, 0
/* 6D4EAC 80220E3C 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D4EB0 80220E40 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4EB4 80220E44 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D4EB8 80220E48 00000010 */  mfhi      $zero
/* 6D4EBC 80220E4C 00000002 */  srl       $zero, $zero, 0
/* 6D4EC0 80220E50 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D4EC4 80220E54 00080000 */  sll       $zero, $t0, 0
/* 6D4EC8 80220E58 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D4ECC 80220E5C 00000002 */  srl       $zero, $zero, 0
/* 6D4ED0 80220E60 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4ED4 80220E64 0000000C */  syscall   
/* 6D4ED8 80220E68 00000027 */  not       $zero, $zero
/* 6D4EDC 80220E6C 00000002 */  srl       $zero, $zero, 0
/* 6D4EE0 80220E70 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4EE4 80220E74 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D4EE8 80220E78 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D4EEC 80220E7C 00000002 */  srl       $zero, $zero, 0
/* 6D4EF0 80220E80 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D4EF4 80220E84 00000002 */  srl       $zero, $zero, 0
/* 6D4EF8 80220E88 00000043 */  sra       $zero, $zero, 1
/* 6D4EFC 80220E8C 0000000F */  sync      
/* 6D4F00 80220E90 802D829C */  lb        $t5, -0x7d64($at)
/* 6D4F04 80220E94 00000033 */  tltu      $zero, $zero
/* 6D4F08 80220E98 00000007 */  srav      $zero, $zero, $zero
/* 6D4F0C 80220E9C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4F10 80220EA0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4F14 80220EA4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D4F18 80220EA8 F24A7AFB */  scd       $t2, 0x7afb($s2)
/* 6D4F1C 80220EAC 0000001E */  ddiv      $zero, $zero, $zero
/* 6D4F20 80220EB0 00000000 */  nop       
/* 6D4F24 80220EB4 00000000 */  nop       
/* 6D4F28 80220EB8 00000000 */  nop       
/* 6D4F2C 80220EBC 00000000 */  nop       
/* 6D4F30 80220EC0 00000000 */  nop       
/* 6D4F34 80220EC4 00000000 */  nop       
/* 6D4F38 80220EC8 00000000 */  nop       
/* 6D4F3C 80220ECC 00000012 */  mflo      $zero
/* 6D4F40 80220ED0 00000000 */  nop       
/* 6D4F44 80220ED4 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D4F48 80220ED8 00000002 */  srl       $zero, $zero, 0
/* 6D4F4C 80220EDC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4F50 80220EE0 0000001E */  ddiv      $zero, $zero, $zero
/* 6D4F54 80220EE4 00000027 */  not       $zero, $zero
/* 6D4F58 80220EE8 00000002 */  srl       $zero, $zero, 0
/* 6D4F5C 80220EEC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4F60 80220EF0 00000024 */  and       $zero, $zero, $zero
/* 6D4F64 80220EF4 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D4F68 80220EF8 00000002 */  srl       $zero, $zero, 0
/* 6D4F6C 80220EFC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D4F70 80220F00 00000002 */  srl       $zero, $zero, 0
/* 6D4F74 80220F04 00000043 */  sra       $zero, $zero, 1
/* 6D4F78 80220F08 0000000F */  sync      
/* 6D4F7C 80220F0C 802D829C */  lb        $t5, -0x7d64($at)
/* 6D4F80 80220F10 00000033 */  tltu      $zero, $zero
/* 6D4F84 80220F14 00000007 */  srav      $zero, $zero, $zero
/* 6D4F88 80220F18 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4F8C 80220F1C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D4F90 80220F20 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D4F94 80220F24 F24A7BB4 */  scd       $t2, 0x7bb4($s2)
/* 6D4F98 80220F28 0000001E */  ddiv      $zero, $zero, $zero
/* 6D4F9C 80220F2C 00000000 */  nop       
/* 6D4FA0 80220F30 00000000 */  nop       
/* 6D4FA4 80220F34 00000000 */  nop       
/* 6D4FA8 80220F38 00000000 */  nop       
/* 6D4FAC 80220F3C 00000000 */  nop       
/* 6D4FB0 80220F40 00000000 */  nop       
/* 6D4FB4 80220F44 00000000 */  nop       
/* 6D4FB8 80220F48 00000013 */  mtlo      $zero
/* 6D4FBC 80220F4C 00000000 */  nop       
/* 6D4FC0 80220F50 00000013 */  mtlo      $zero
/* 6D4FC4 80220F54 00000000 */  nop       
/* 6D4FC8 80220F58 00000008 */  jr        $zero
/* 6D4FCC 80220F5C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D4FD0 80220F60 0000001E */  ddiv      $zero, $zero, $zero
/* 6D4FD4 80220F64 00000043 */  sra       $zero, $zero, 1
/* 6D4FD8 80220F68 00000003 */  sra       $zero, $zero, 0
/* 6D4FDC 80220F6C 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D4FE0 80220F70 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D4FE4 80220F74 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4FE8 80220F78 00000011 */  mthi      $zero
/* 6D4FEC 80220F7C 00000002 */  srl       $zero, $zero, 0
/* 6D4FF0 80220F80 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D4FF4 80220F84 00000200 */  sll       $zero, $zero, 8
/* 6D4FF8 80220F88 00000043 */  sra       $zero, $zero, 1
/* 6D4FFC 80220F8C 00000004 */  sllv      $zero, $zero, $zero
/* 6D5000 80220F90 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D5004 80220F94 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5008 80220F98 00000001 */  movf      $zero, $zero, $fcc0
/* 6D500C 80220F9C 00560001 */  .byte     0x00, 0x56, 0x00, 0x01
/* 6D5010 80220FA0 00000012 */  mflo      $zero
/* 6D5014 80220FA4 00000000 */  nop       
/* 6D5018 80220FA8 00000043 */  sra       $zero, $zero, 1
/* 6D501C 80220FAC 00000004 */  sllv      $zero, $zero, $zero
/* 6D5020 80220FB0 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D5024 80220FB4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5028 80220FB8 00000002 */  srl       $zero, $zero, 0
/* 6D502C 80220FBC 00570001 */  .byte     0x00, 0x57, 0x00, 0x01
/* 6D5030 80220FC0 00000013 */  mtlo      $zero
/* 6D5034 80220FC4 00000000 */  nop       
/* 6D5038 80220FC8 00000008 */  jr        $zero
/* 6D503C 80220FCC 00000001 */   movf     $zero, $zero, $fcc0
/* 6D5040 80220FD0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D5044 80220FD4 00000056 */  drotrv    $zero, $zero, $zero
/* 6D5048 80220FD8 00000000 */  nop       
/* 6D504C 80220FDC 00000008 */  jr        $zero
/* 6D5050 80220FE0 00000001 */   movf     $zero, $zero, $fcc0
/* 6D5054 80220FE4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D5058 80220FE8 00000043 */  sra       $zero, $zero, 1
/* 6D505C 80220FEC 00000003 */  sra       $zero, $zero, 0
/* 6D5060 80220FF0 8025385C */  lb        $a1, 0x385c($at)
/* 6D5064 80220FF4 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6D5068 80220FF8 0000206D */  .byte     0x00, 0x00, 0x20, 0x6d
/* 6D506C 80220FFC 00000043 */  sra       $zero, $zero, 1
/* 6D5070 80221000 00000003 */  sra       $zero, $zero, 0
/* 6D5074 80221004 8025385C */  lb        $a1, 0x385c($at)
/* 6D5078 80221008 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6D507C 8022100C 00000214 */  .byte     0x00, 0x00, 0x02, 0x14
/* 6D5080 80221010 00000008 */  jr        $zero
/* 6D5084 80221014 00000001 */   movf     $zero, $zero, $fcc0
/* 6D5088 80221018 0000001E */  ddiv      $zero, $zero, $zero
/* 6D508C 8022101C 00000043 */  sra       $zero, $zero, 1
/* 6D5090 80221020 00000003 */  sra       $zero, $zero, 0
/* 6D5094 80221024 8025385C */  lb        $a1, 0x385c($at)
/* 6D5098 80221028 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6D509C 8022102C 0000025C */  .byte     0x00, 0x00, 0x02, 0x5c
/* 6D50A0 80221030 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D50A4 80221034 00000000 */  nop       
/* 6D50A8 80221038 00000056 */  drotrv    $zero, $zero, $zero
/* 6D50AC 8022103C 00000000 */  nop       
/* 6D50B0 80221040 00000043 */  sra       $zero, $zero, 1
/* 6D50B4 80221044 00000002 */  srl       $zero, $zero, 0
/* 6D50B8 80221048 8026BF48 */  lb        $a2, -0x40b8($at)
/* 6D50BC 8022104C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D50C0 80221050 00000043 */  sra       $zero, $zero, 1
/* 6D50C4 80221054 00000004 */  sllv      $zero, $zero, $zero
/* 6D50C8 80221058 80270CA4 */  lb        $a3, 0xca4($at)
/* 6D50CC 8022105C FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6D50D0 80221060 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D50D4 80221064 00000000 */  nop       
/* 6D50D8 80221068 00000043 */  sra       $zero, $zero, 1
/* 6D50DC 8022106C 00000002 */  srl       $zero, $zero, 0
/* 6D50E0 80221070 8026BF48 */  lb        $a2, -0x40b8($at)
/* 6D50E4 80221074 00000000 */  nop       
/* 6D50E8 80221078 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D50EC 8022107C 00000000 */  nop       
/* 6D50F0 80221080 00000043 */  sra       $zero, $zero, 1
/* 6D50F4 80221084 00000001 */  movf      $zero, $zero, $fcc0
/* 6D50F8 80221088 8027114C */  lb        $a3, 0x114c($at)
/* 6D50FC 8022108C 00000043 */  sra       $zero, $zero, 1
/* 6D5100 80221090 00000002 */  srl       $zero, $zero, 0
/* 6D5104 80221094 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D5108 80221098 00000002 */  srl       $zero, $zero, 0
/* 6D510C 8022109C 00000043 */  sra       $zero, $zero, 1
/* 6D5110 802210A0 00000002 */  srl       $zero, $zero, 0
/* 6D5114 802210A4 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6D5118 802210A8 0000000A */  movz      $zero, $zero, $zero
/* 6D511C 802210AC 00000008 */  jr        $zero
/* 6D5120 802210B0 00000001 */   movf     $zero, $zero, $fcc0
/* 6D5124 802210B4 0000000A */  movz      $zero, $zero, $zero
/* 6D5128 802210B8 00000043 */  sra       $zero, $zero, 1
/* 6D512C 802210BC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D5130 802210C0 8027D7F0 */  lb        $a3, -0x2810($at)
/* 6D5134 802210C4 00000043 */  sra       $zero, $zero, 1
/* 6D5138 802210C8 00000003 */  sra       $zero, $zero, 0
/* 6D513C 802210CC 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D5140 802210D0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5144 802210D4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D5148 802210D8 00000043 */  sra       $zero, $zero, 1
/* 6D514C 802210DC 00000003 */  sra       $zero, $zero, 0
/* 6D5150 802210E0 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D5154 802210E4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5158 802210E8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D515C 802210EC 00000002 */  srl       $zero, $zero, 0
/* 6D5160 802210F0 00000000 */  nop       
/* 6D5164 802210F4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D5168 802210F8 00000000 */  nop       
/* 6D516C 802210FC 00000043 */  sra       $zero, $zero, 1
/* 6D5170 80221100 00000004 */  sllv      $zero, $zero, $zero
/* 6D5174 80221104 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D5178 80221108 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D517C 8022110C 0000000A */  movz      $zero, $zero, $zero
/* 6D5180 80221110 00000000 */  nop       
/* 6D5184 80221114 00000043 */  sra       $zero, $zero, 1
/* 6D5188 80221118 00000004 */  sllv      $zero, $zero, $zero
/* 6D518C 8022111C 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D5190 80221120 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5194 80221124 0000000B */  movn      $zero, $zero, $zero
/* 6D5198 80221128 00000001 */  movf      $zero, $zero, $fcc0
/* 6D519C 8022112C 00000043 */  sra       $zero, $zero, 1
/* 6D51A0 80221130 00000004 */  sllv      $zero, $zero, $zero
/* 6D51A4 80221134 8026C0D4 */  lb        $a2, -0x3f2c($at)
/* 6D51A8 80221138 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D51AC 8022113C 00000003 */  sra       $zero, $zero, 0
/* 6D51B0 80221140 00000001 */  movf      $zero, $zero, $fcc0
/* 6D51B4 80221144 00000043 */  sra       $zero, $zero, 1
/* 6D51B8 80221148 00000003 */  sra       $zero, $zero, 0
/* 6D51BC 8022114C 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D51C0 80221150 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D51C4 80221154 00000000 */  nop       
/* 6D51C8 80221158 00000043 */  sra       $zero, $zero, 1
/* 6D51CC 8022115C 00000003 */  sra       $zero, $zero, 0
/* 6D51D0 80221160 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D51D4 80221164 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D51D8 80221168 00000000 */  nop       
/* 6D51DC 8022116C 00000043 */  sra       $zero, $zero, 1
/* 6D51E0 80221170 00000003 */  sra       $zero, $zero, 0
/* 6D51E4 80221174 8027C548 */  lb        $a3, -0x3ab8($at)
/* 6D51E8 80221178 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D51EC 8022117C 00000000 */  nop       
/* 6D51F0 80221180 00000043 */  sra       $zero, $zero, 1
/* 6D51F4 80221184 00000002 */  srl       $zero, $zero, 0
/* 6D51F8 80221188 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D51FC 8022118C 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D5200 80221190 00000043 */  sra       $zero, $zero, 1
/* 6D5204 80221194 00000002 */  srl       $zero, $zero, 0
/* 6D5208 80221198 8024EB24 */  lb        $a0, -0x14dc($at)
/* 6D520C 8022119C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5210 802211A0 00000043 */  sra       $zero, $zero, 1
/* 6D5214 802211A4 00000002 */  srl       $zero, $zero, 0
/* 6D5218 802211A8 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6D521C 802211AC 0000000F */  sync      
/* 6D5220 802211B0 00000008 */  jr        $zero
/* 6D5224 802211B4 00000001 */   movf     $zero, $zero, $fcc0
/* 6D5228 802211B8 0000000F */  sync      
/* 6D522C 802211BC 00000043 */  sra       $zero, $zero, 1
/* 6D5230 802211C0 00000003 */  sra       $zero, $zero, 0
/* 6D5234 802211C4 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D5238 802211C8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D523C 802211CC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5240 802211D0 00000011 */  mthi      $zero
/* 6D5244 802211D4 00000002 */  srl       $zero, $zero, 0
/* 6D5248 802211D8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D524C 802211DC 00000200 */  sll       $zero, $zero, 8
/* 6D5250 802211E0 00000043 */  sra       $zero, $zero, 1
/* 6D5254 802211E4 00000004 */  sllv      $zero, $zero, $zero
/* 6D5258 802211E8 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D525C 802211EC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5260 802211F0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D5264 802211F4 00560002 */  .byte     0x00, 0x56, 0x00, 0x02
/* 6D5268 802211F8 00000012 */  mflo      $zero
/* 6D526C 802211FC 00000000 */  nop       
/* 6D5270 80221200 00000043 */  sra       $zero, $zero, 1
/* 6D5274 80221204 00000004 */  sllv      $zero, $zero, $zero
/* 6D5278 80221208 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D527C 8022120C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5280 80221210 00000002 */  srl       $zero, $zero, 0
/* 6D5284 80221214 00570002 */  .byte     0x00, 0x57, 0x00, 0x02
/* 6D5288 80221218 00000013 */  mtlo      $zero
/* 6D528C 8022121C 00000000 */  nop       
/* 6D5290 80221220 00000008 */  jr        $zero
/* 6D5294 80221224 00000001 */   movf     $zero, $zero, $fcc0
/* 6D5298 80221228 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D529C 8022122C 00000043 */  sra       $zero, $zero, 1
/* 6D52A0 80221230 00000003 */  sra       $zero, $zero, 0
/* 6D52A4 80221234 8025385C */  lb        $a1, 0x385c($at)
/* 6D52A8 80221238 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D52AC 8022123C 000020D4 */  .byte     0x00, 0x00, 0x20, 0xd4
/* 6D52B0 80221240 00000043 */  sra       $zero, $zero, 1
/* 6D52B4 80221244 00000003 */  sra       $zero, $zero, 0
/* 6D52B8 80221248 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D52BC 8022124C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D52C0 80221250 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D52C4 80221254 00000011 */  mthi      $zero
/* 6D52C8 80221258 00000002 */  srl       $zero, $zero, 0
/* 6D52CC 8022125C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D52D0 80221260 00000200 */  sll       $zero, $zero, 8
/* 6D52D4 80221264 00000043 */  sra       $zero, $zero, 1
/* 6D52D8 80221268 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D52DC 8022126C 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D52E0 80221270 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D52E4 80221274 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D52E8 80221278 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D52EC 8022127C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D52F0 80221280 00000043 */  sra       $zero, $zero, 1
/* 6D52F4 80221284 00000003 */  sra       $zero, $zero, 0
/* 6D52F8 80221288 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D52FC 8022128C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5300 80221290 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D5304 80221294 00000010 */  mfhi      $zero
/* 6D5308 80221298 00000002 */  srl       $zero, $zero, 0
/* 6D530C 8022129C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D5310 802212A0 00080000 */  sll       $zero, $t0, 0
/* 6D5314 802212A4 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D5318 802212A8 00000002 */  srl       $zero, $zero, 0
/* 6D531C 802212AC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5320 802212B0 00000006 */  srlv      $zero, $zero, $zero
/* 6D5324 802212B4 00000027 */  not       $zero, $zero
/* 6D5328 802212B8 00000002 */  srl       $zero, $zero, 0
/* 6D532C 802212BC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5330 802212C0 0000000C */  syscall   
/* 6D5334 802212C4 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D5338 802212C8 00000002 */  srl       $zero, $zero, 0
/* 6D533C 802212CC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D5340 802212D0 00000002 */  srl       $zero, $zero, 0
/* 6D5344 802212D4 00000043 */  sra       $zero, $zero, 1
/* 6D5348 802212D8 0000000F */  sync      
/* 6D534C 802212DC 802D829C */  lb        $t5, -0x7d64($at)
/* 6D5350 802212E0 00000033 */  tltu      $zero, $zero
/* 6D5354 802212E4 00000007 */  srav      $zero, $zero, $zero
/* 6D5358 802212E8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D535C 802212EC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5360 802212F0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D5364 802212F4 F24A7AFB */  scd       $t2, 0x7afb($s2)
/* 6D5368 802212F8 0000001E */  ddiv      $zero, $zero, $zero
/* 6D536C 802212FC 00000000 */  nop       
/* 6D5370 80221300 00000000 */  nop       
/* 6D5374 80221304 00000000 */  nop       
/* 6D5378 80221308 00000000 */  nop       
/* 6D537C 8022130C 00000000 */  nop       
/* 6D5380 80221310 00000000 */  nop       
/* 6D5384 80221314 00000000 */  nop       
/* 6D5388 80221318 00000012 */  mflo      $zero
/* 6D538C 8022131C 00000000 */  nop       
/* 6D5390 80221320 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D5394 80221324 00000002 */  srl       $zero, $zero, 0
/* 6D5398 80221328 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D539C 8022132C 00000010 */  mfhi      $zero
/* 6D53A0 80221330 00000027 */  not       $zero, $zero
/* 6D53A4 80221334 00000002 */  srl       $zero, $zero, 0
/* 6D53A8 80221338 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D53AC 8022133C 0000001F */  ddivu     $zero, $zero, $zero
/* 6D53B0 80221340 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D53B4 80221344 00000002 */  srl       $zero, $zero, 0
/* 6D53B8 80221348 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D53BC 8022134C 00000002 */  srl       $zero, $zero, 0
/* 6D53C0 80221350 00000043 */  sra       $zero, $zero, 1
/* 6D53C4 80221354 0000000F */  sync      
/* 6D53C8 80221358 802D829C */  lb        $t5, -0x7d64($at)
/* 6D53CC 8022135C 00000033 */  tltu      $zero, $zero
/* 6D53D0 80221360 00000007 */  srav      $zero, $zero, $zero
/* 6D53D4 80221364 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D53D8 80221368 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D53DC 8022136C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D53E0 80221370 F24A7BB4 */  scd       $t2, 0x7bb4($s2)
/* 6D53E4 80221374 0000001E */  ddiv      $zero, $zero, $zero
/* 6D53E8 80221378 00000000 */  nop       
/* 6D53EC 8022137C 00000000 */  nop       
/* 6D53F0 80221380 00000000 */  nop       
/* 6D53F4 80221384 00000000 */  nop       
/* 6D53F8 80221388 00000000 */  nop       
/* 6D53FC 8022138C 00000000 */  nop       
/* 6D5400 80221390 00000000 */  nop       
/* 6D5404 80221394 00000013 */  mtlo      $zero
/* 6D5408 80221398 00000000 */  nop       
/* 6D540C 8022139C 00000012 */  mflo      $zero
/* 6D5410 802213A0 00000000 */  nop       
/* 6D5414 802213A4 00000043 */  sra       $zero, $zero, 1
/* 6D5418 802213A8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D541C 802213AC 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D5420 802213B0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5424 802213B4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5428 802213B8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D542C 802213BC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D5430 802213C0 00000043 */  sra       $zero, $zero, 1
/* 6D5434 802213C4 00000003 */  sra       $zero, $zero, 0
/* 6D5438 802213C8 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D543C 802213CC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5440 802213D0 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D5444 802213D4 00000010 */  mfhi      $zero
/* 6D5448 802213D8 00000002 */  srl       $zero, $zero, 0
/* 6D544C 802213DC FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D5450 802213E0 00080000 */  sll       $zero, $t0, 0
/* 6D5454 802213E4 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D5458 802213E8 00000002 */  srl       $zero, $zero, 0
/* 6D545C 802213EC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5460 802213F0 0000000C */  syscall   
/* 6D5464 802213F4 00000027 */  not       $zero, $zero
/* 6D5468 802213F8 00000002 */  srl       $zero, $zero, 0
/* 6D546C 802213FC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5470 80221400 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D5474 80221404 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D5478 80221408 00000002 */  srl       $zero, $zero, 0
/* 6D547C 8022140C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D5480 80221410 00000002 */  srl       $zero, $zero, 0
/* 6D5484 80221414 00000043 */  sra       $zero, $zero, 1
/* 6D5488 80221418 0000000F */  sync      
/* 6D548C 8022141C 802D829C */  lb        $t5, -0x7d64($at)
/* 6D5490 80221420 00000033 */  tltu      $zero, $zero
/* 6D5494 80221424 00000007 */  srav      $zero, $zero, $zero
/* 6D5498 80221428 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D549C 8022142C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D54A0 80221430 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D54A4 80221434 F24A7AFB */  scd       $t2, 0x7afb($s2)
/* 6D54A8 80221438 0000001E */  ddiv      $zero, $zero, $zero
/* 6D54AC 8022143C 00000000 */  nop       
/* 6D54B0 80221440 00000000 */  nop       
/* 6D54B4 80221444 00000000 */  nop       
/* 6D54B8 80221448 00000000 */  nop       
/* 6D54BC 8022144C 00000000 */  nop       
/* 6D54C0 80221450 00000000 */  nop       
/* 6D54C4 80221454 00000000 */  nop       
/* 6D54C8 80221458 00000012 */  mflo      $zero
/* 6D54CC 8022145C 00000000 */  nop       
/* 6D54D0 80221460 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D54D4 80221464 00000002 */  srl       $zero, $zero, 0
/* 6D54D8 80221468 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D54DC 8022146C 0000001E */  ddiv      $zero, $zero, $zero
/* 6D54E0 80221470 00000027 */  not       $zero, $zero
/* 6D54E4 80221474 00000002 */  srl       $zero, $zero, 0
/* 6D54E8 80221478 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D54EC 8022147C 00000024 */  and       $zero, $zero, $zero
/* 6D54F0 80221480 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D54F4 80221484 00000002 */  srl       $zero, $zero, 0
/* 6D54F8 80221488 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D54FC 8022148C 00000002 */  srl       $zero, $zero, 0
/* 6D5500 80221490 00000043 */  sra       $zero, $zero, 1
/* 6D5504 80221494 0000000F */  sync      
/* 6D5508 80221498 802D829C */  lb        $t5, -0x7d64($at)
/* 6D550C 8022149C 00000033 */  tltu      $zero, $zero
/* 6D5510 802214A0 00000007 */  srav      $zero, $zero, $zero
/* 6D5514 802214A4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5518 802214A8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D551C 802214AC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D5520 802214B0 F24A7BB4 */  scd       $t2, 0x7bb4($s2)
/* 6D5524 802214B4 0000001E */  ddiv      $zero, $zero, $zero
/* 6D5528 802214B8 00000000 */  nop       
/* 6D552C 802214BC 00000000 */  nop       
/* 6D5530 802214C0 00000000 */  nop       
/* 6D5534 802214C4 00000000 */  nop       
/* 6D5538 802214C8 00000000 */  nop       
/* 6D553C 802214CC 00000000 */  nop       
/* 6D5540 802214D0 00000000 */  nop       
/* 6D5544 802214D4 00000013 */  mtlo      $zero
/* 6D5548 802214D8 00000000 */  nop       
/* 6D554C 802214DC 00000013 */  mtlo      $zero
/* 6D5550 802214E0 00000000 */  nop       
/* 6D5554 802214E4 00000008 */  jr        $zero
/* 6D5558 802214E8 00000001 */   movf     $zero, $zero, $fcc0
/* 6D555C 802214EC 0000001E */  ddiv      $zero, $zero, $zero
/* 6D5560 802214F0 00000043 */  sra       $zero, $zero, 1
/* 6D5564 802214F4 00000003 */  sra       $zero, $zero, 0
/* 6D5568 802214F8 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D556C 802214FC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5570 80221500 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5574 80221504 00000011 */  mthi      $zero
/* 6D5578 80221508 00000002 */  srl       $zero, $zero, 0
/* 6D557C 8022150C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5580 80221510 00000200 */  sll       $zero, $zero, 8
/* 6D5584 80221514 00000043 */  sra       $zero, $zero, 1
/* 6D5588 80221518 00000004 */  sllv      $zero, $zero, $zero
/* 6D558C 8022151C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D5590 80221520 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5594 80221524 00000001 */  movf      $zero, $zero, $fcc0
/* 6D5598 80221528 00560001 */  .byte     0x00, 0x56, 0x00, 0x01
/* 6D559C 8022152C 00000012 */  mflo      $zero
/* 6D55A0 80221530 00000000 */  nop       
/* 6D55A4 80221534 00000043 */  sra       $zero, $zero, 1
/* 6D55A8 80221538 00000004 */  sllv      $zero, $zero, $zero
/* 6D55AC 8022153C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D55B0 80221540 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D55B4 80221544 00000002 */  srl       $zero, $zero, 0
/* 6D55B8 80221548 00570001 */  .byte     0x00, 0x57, 0x00, 0x01
/* 6D55BC 8022154C 00000013 */  mtlo      $zero
/* 6D55C0 80221550 00000000 */  nop       
/* 6D55C4 80221554 00000008 */  jr        $zero
/* 6D55C8 80221558 00000001 */   movf     $zero, $zero, $fcc0
/* 6D55CC 8022155C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D55D0 80221560 00000043 */  sra       $zero, $zero, 1
/* 6D55D4 80221564 00000002 */  srl       $zero, $zero, 0
/* 6D55D8 80221568 8026E310 */  lb        $a2, -0x1cf0($at)
/* 6D55DC 8022156C 00008002 */  srl       $s0, $zero, 0
/* 6D55E0 80221570 00000043 */  sra       $zero, $zero, 1
/* 6D55E4 80221574 00000001 */  movf      $zero, $zero, $fcc0
/* 6D55E8 80221578 8026E354 */  lb        $a2, -0x1cac($at)
/* 6D55EC 8022157C 00000003 */  sra       $zero, $zero, 0
/* 6D55F0 80221580 00000001 */  movf      $zero, $zero, $fcc0
/* 6D55F4 80221584 00000000 */  nop       
/* 6D55F8 80221588 00000024 */  and       $zero, $zero, $zero
/* 6D55FC 8022158C 00000002 */  srl       $zero, $zero, 0
/* 6D5600 80221590 FBD3E280 */  bbit132   $fp, 0x13, .L80219F94
/* 6D5604 80221594 00000000 */   nop      
/* 6D5608 80221598 00000043 */  sra       $zero, $zero, 1
/* 6D560C 8022159C 00000003 */  sra       $zero, $zero, 0
/* 6D5610 802215A0 8026E8AC */  lb        $a2, -0x1754($at)
/* 6D5614 802215A4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5618 802215A8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D561C 802215AC 00000043 */  sra       $zero, $zero, 1
/* 6D5620 802215B0 00000003 */  sra       $zero, $zero, 0
/* 6D5624 802215B4 8027DA68 */  lb        $a3, -0x2598($at)
/* 6D5628 802215B8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D562C 802215BC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5630 802215C0 0000000A */  movz      $zero, $zero, $zero
/* 6D5634 802215C4 00000002 */  srl       $zero, $zero, 0
/* 6D5638 802215C8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D563C 802215CC 00000047 */  .byte     0x00, 0x00, 0x00, 0x47
/* 6D5640 802215D0 00000043 */  sra       $zero, $zero, 1
/* 6D5644 802215D4 00000004 */  sllv      $zero, $zero, $zero
/* 6D5648 802215D8 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D564C 802215DC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5650 802215E0 00000008 */  jr        $zero
/* 6D5654 802215E4 FE363C81 */   sd       $s6, 0x3c81($s1)
/* 6D5658 802215E8 0000000A */  movz      $zero, $zero, $zero
/* 6D565C 802215EC 00000002 */  srl       $zero, $zero, 0
/* 6D5660 802215F0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5664 802215F4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D5668 802215F8 00000024 */  and       $zero, $zero, $zero
/* 6D566C 802215FC 00000002 */  srl       $zero, $zero, 0
/* 6D5670 80221600 FBD3E280 */  bbit132   $fp, 0x13, .L8021A004
/* 6D5674 80221604 00000001 */   movf     $zero, $zero, $fcc0
/* 6D5678 80221608 00000013 */  mtlo      $zero
/* 6D567C 8022160C 00000000 */  nop       
/* 6D5680 80221610 00000013 */  mtlo      $zero
/* 6D5684 80221614 00000000 */  nop       
/* 6D5688 80221618 0000000A */  movz      $zero, $zero, $zero
/* 6D568C 8022161C 00000002 */  srl       $zero, $zero, 0
/* 6D5690 80221620 FBD3E280 */  bbit132   $fp, 0x13, .L8021A024
/* 6D5694 80221624 00000000 */   nop      
/* 6D5698 80221628 00000056 */  drotrv    $zero, $zero, $zero
/* 6D569C 8022162C 00000000 */  nop       
/* 6D56A0 80221630 00000008 */  jr        $zero
/* 6D56A4 80221634 00000001 */   movf     $zero, $zero, $fcc0
/* 6D56A8 80221638 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D56AC 8022163C 00000043 */  sra       $zero, $zero, 1
/* 6D56B0 80221640 00000003 */  sra       $zero, $zero, 0
/* 6D56B4 80221644 8025385C */  lb        $a1, 0x385c($at)
/* 6D56B8 80221648 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D56BC 8022164C 0000206D */  .byte     0x00, 0x00, 0x20, 0x6d
/* 6D56C0 80221650 00000043 */  sra       $zero, $zero, 1
/* 6D56C4 80221654 00000003 */  sra       $zero, $zero, 0
/* 6D56C8 80221658 8025385C */  lb        $a1, 0x385c($at)
/* 6D56CC 8022165C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D56D0 80221660 00000214 */  .byte     0x00, 0x00, 0x02, 0x14
/* 6D56D4 80221664 00000008 */  jr        $zero
/* 6D56D8 80221668 00000001 */   movf     $zero, $zero, $fcc0
/* 6D56DC 8022166C 0000001E */  ddiv      $zero, $zero, $zero
/* 6D56E0 80221670 00000043 */  sra       $zero, $zero, 1
/* 6D56E4 80221674 00000003 */  sra       $zero, $zero, 0
/* 6D56E8 80221678 8025385C */  lb        $a1, 0x385c($at)
/* 6D56EC 8022167C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D56F0 80221680 0000025C */  .byte     0x00, 0x00, 0x02, 0x5c
/* 6D56F4 80221684 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D56F8 80221688 00000000 */  nop       
/* 6D56FC 8022168C 00000056 */  drotrv    $zero, $zero, $zero
/* 6D5700 80221690 00000000 */  nop       
/* 6D5704 80221694 00000043 */  sra       $zero, $zero, 1
/* 6D5708 80221698 00000002 */  srl       $zero, $zero, 0
/* 6D570C 8022169C 8026BF48 */  lb        $a2, -0x40b8($at)
/* 6D5710 802216A0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D5714 802216A4 00000043 */  sra       $zero, $zero, 1
/* 6D5718 802216A8 00000004 */  sllv      $zero, $zero, $zero
/* 6D571C 802216AC 80270CA4 */  lb        $a3, 0xca4($at)
/* 6D5720 802216B0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5724 802216B4 00000003 */  sra       $zero, $zero, 0
/* 6D5728 802216B8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D572C 802216BC 00000043 */  sra       $zero, $zero, 1
/* 6D5730 802216C0 00000002 */  srl       $zero, $zero, 0
/* 6D5734 802216C4 8026BF48 */  lb        $a2, -0x40b8($at)
/* 6D5738 802216C8 00000000 */  nop       
/* 6D573C 802216CC 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D5740 802216D0 00000000 */  nop       
/* 6D5744 802216D4 00000013 */  mtlo      $zero
/* 6D5748 802216D8 00000000 */  nop       
/* 6D574C 802216DC 00000043 */  sra       $zero, $zero, 1
/* 6D5750 802216E0 00000003 */  sra       $zero, $zero, 0
/* 6D5754 802216E4 8026E414 */  lb        $a2, -0x1bec($at)
/* 6D5758 802216E8 00000000 */  nop       
/* 6D575C 802216EC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5760 802216F0 0000000B */  movn      $zero, $zero, $zero
/* 6D5764 802216F4 00000002 */  srl       $zero, $zero, 0
/* 6D5768 802216F8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D576C 802216FC FFFFFFFF */  sd        $ra, -1($ra)
/* 6D5770 80221700 00000004 */  sllv      $zero, $zero, $zero
/* 6D5774 80221704 00000001 */  movf      $zero, $zero, $fcc0
/* 6D5778 80221708 00000000 */  nop       
/* 6D577C 8022170C 00000013 */  mtlo      $zero
/* 6D5780 80221710 00000000 */  nop       
/* 6D5784 80221714 00000043 */  sra       $zero, $zero, 1
/* 6D5788 80221718 00000001 */  movf      $zero, $zero, $fcc0
/* 6D578C 8022171C 8027114C */  lb        $a3, 0x114c($at)
/* 6D5790 80221720 00000008 */  jr        $zero
/* 6D5794 80221724 00000001 */   movf     $zero, $zero, $fcc0
/* 6D5798 80221728 00000001 */  movf      $zero, $zero, $fcc0
/* 6D579C 8022172C 00000043 */  sra       $zero, $zero, 1
/* 6D57A0 80221730 00000002 */  srl       $zero, $zero, 0
/* 6D57A4 80221734 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D57A8 80221738 00000002 */  srl       $zero, $zero, 0
/* 6D57AC 8022173C 00000043 */  sra       $zero, $zero, 1
/* 6D57B0 80221740 00000002 */  srl       $zero, $zero, 0
/* 6D57B4 80221744 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6D57B8 80221748 0000000A */  movz      $zero, $zero, $zero
/* 6D57BC 8022174C 00000008 */  jr        $zero
/* 6D57C0 80221750 00000001 */   movf     $zero, $zero, $fcc0
/* 6D57C4 80221754 0000000A */  movz      $zero, $zero, $zero
/* 6D57C8 80221758 00000043 */  sra       $zero, $zero, 1
/* 6D57CC 8022175C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D57D0 80221760 8027D7F0 */  lb        $a3, -0x2810($at)
/* 6D57D4 80221764 00000043 */  sra       $zero, $zero, 1
/* 6D57D8 80221768 00000003 */  sra       $zero, $zero, 0
/* 6D57DC 8022176C 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D57E0 80221770 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D57E4 80221774 00000001 */  movf      $zero, $zero, $fcc0
/* 6D57E8 80221778 00000043 */  sra       $zero, $zero, 1
/* 6D57EC 8022177C 00000003 */  sra       $zero, $zero, 0
/* 6D57F0 80221780 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D57F4 80221784 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D57F8 80221788 00000001 */  movf      $zero, $zero, $fcc0
/* 6D57FC 8022178C 00000002 */  srl       $zero, $zero, 0
/* 6D5800 80221790 00000000 */  nop       
/* 6D5804 80221794 00000001 */  movf      $zero, $zero, $fcc0
/* 6D5808 80221798 00000000 */  nop       
/* 6D580C 8022179C 00000043 */  sra       $zero, $zero, 1
/* 6D5810 802217A0 00000004 */  sllv      $zero, $zero, $zero
/* 6D5814 802217A4 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D5818 802217A8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D581C 802217AC 0000000B */  movn      $zero, $zero, $zero
/* 6D5820 802217B0 00000002 */  srl       $zero, $zero, 0
/* 6D5824 802217B4 00000024 */  and       $zero, $zero, $zero
/* 6D5828 802217B8 00000002 */  srl       $zero, $zero, 0
/* 6D582C 802217BC FBD3E280 */  bbit132   $fp, 0x13, .L8021A1C0
/* 6D5830 802217C0 00000000 */   nop      
/* 6D5834 802217C4 00000024 */  and       $zero, $zero, $zero
/* 6D5838 802217C8 00000002 */  srl       $zero, $zero, 0
/* 6D583C 802217CC FBD3E281 */  bbit132   $fp, 0x13, .L8021A1D4
/* 6D5840 802217D0 00000000 */   nop      
/* 6D5844 802217D4 00000043 */  sra       $zero, $zero, 1
/* 6D5848 802217D8 00000004 */  sllv      $zero, $zero, $zero
/* 6D584C 802217DC 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D5850 802217E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5854 802217E4 0000000A */  movz      $zero, $zero, $zero
/* 6D5858 802217E8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D585C 802217EC 0000000A */  movz      $zero, $zero, $zero
/* 6D5860 802217F0 00000002 */  srl       $zero, $zero, 0
/* 6D5864 802217F4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5868 802217F8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D586C 802217FC 00000024 */  and       $zero, $zero, $zero
/* 6D5870 80221800 00000002 */  srl       $zero, $zero, 0
/* 6D5874 80221804 FBD3E280 */  bbit132   $fp, 0x13, .L8021A208
/* 6D5878 80221808 00000001 */   movf     $zero, $zero, $fcc0
/* 6D587C 8022180C 00000043 */  sra       $zero, $zero, 1
/* 6D5880 80221810 00000004 */  sllv      $zero, $zero, $zero
/* 6D5884 80221814 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D5888 80221818 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D588C 8022181C 00000009 */  jr        $zero
/* 6D5890 80221820 FE363C8A */   sd       $s6, 0x3c8a($s1)
/* 6D5894 80221824 00000013 */  mtlo      $zero
/* 6D5898 80221828 00000000 */  nop       
/* 6D589C 8022182C 00000043 */  sra       $zero, $zero, 1
/* 6D58A0 80221830 00000003 */  sra       $zero, $zero, 0
/* 6D58A4 80221834 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D58A8 80221838 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D58AC 8022183C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D58B0 80221840 00000010 */  mfhi      $zero
/* 6D58B4 80221844 00000002 */  srl       $zero, $zero, 0
/* 6D58B8 80221848 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D58BC 8022184C 00000200 */  sll       $zero, $zero, 8
/* 6D58C0 80221850 00000024 */  and       $zero, $zero, $zero
/* 6D58C4 80221854 00000002 */  srl       $zero, $zero, 0
/* 6D58C8 80221858 FBD3E281 */  bbit132   $fp, 0x13, .L8021A260
/* 6D58CC 8022185C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D58D0 80221860 00000013 */  mtlo      $zero
/* 6D58D4 80221864 00000000 */  nop       
/* 6D58D8 80221868 00000043 */  sra       $zero, $zero, 1
/* 6D58DC 8022186C 00000003 */  sra       $zero, $zero, 0
/* 6D58E0 80221870 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D58E4 80221874 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D58E8 80221878 00000000 */  nop       
/* 6D58EC 8022187C 0000000A */  movz      $zero, $zero, $zero
/* 6D58F0 80221880 00000002 */  srl       $zero, $zero, 0
/* 6D58F4 80221884 FBD3E280 */  bbit132   $fp, 0x13, .L8021A288
/* 6D58F8 80221888 00000001 */   movf     $zero, $zero, $fcc0
/* 6D58FC 8022188C 00000043 */  sra       $zero, $zero, 1
/* 6D5900 80221890 00000003 */  sra       $zero, $zero, 0
/* 6D5904 80221894 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D5908 80221898 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D590C 8022189C 00000000 */  nop       
/* 6D5910 802218A0 00000013 */  mtlo      $zero
/* 6D5914 802218A4 00000000 */  nop       
/* 6D5918 802218A8 00000043 */  sra       $zero, $zero, 1
/* 6D591C 802218AC 00000003 */  sra       $zero, $zero, 0
/* 6D5920 802218B0 8027C548 */  lb        $a3, -0x3ab8($at)
/* 6D5924 802218B4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5928 802218B8 00000000 */  nop       
/* 6D592C 802218BC 00000043 */  sra       $zero, $zero, 1
/* 6D5930 802218C0 00000002 */  srl       $zero, $zero, 0
/* 6D5934 802218C4 80269E28 */  lb        $a2, -0x61d8($at)
/* 6D5938 802218C8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D593C 802218CC 0000000A */  movz      $zero, $zero, $zero
/* 6D5940 802218D0 00000002 */  srl       $zero, $zero, 0
/* 6D5944 802218D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5948 802218D8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D594C 802218DC 00000043 */  sra       $zero, $zero, 1
/* 6D5950 802218E0 00000002 */  srl       $zero, $zero, 0
/* 6D5954 802218E4 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D5958 802218E8 00000002 */  srl       $zero, $zero, 0
/* 6D595C 802218EC 00000043 */  sra       $zero, $zero, 1
/* 6D5960 802218F0 00000002 */  srl       $zero, $zero, 0
/* 6D5964 802218F4 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6D5968 802218F8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D596C 802218FC 00000012 */  mflo      $zero
/* 6D5970 80221900 00000000 */  nop       
/* 6D5974 80221904 00000043 */  sra       $zero, $zero, 1
/* 6D5978 80221908 00000002 */  srl       $zero, $zero, 0
/* 6D597C 8022190C 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D5980 80221910 00000002 */  srl       $zero, $zero, 0
/* 6D5984 80221914 00000043 */  sra       $zero, $zero, 1
/* 6D5988 80221918 00000002 */  srl       $zero, $zero, 0
/* 6D598C 8022191C 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6D5990 80221920 0000000A */  movz      $zero, $zero, $zero
/* 6D5994 80221924 00000013 */  mtlo      $zero
/* 6D5998 80221928 00000000 */  nop       
/* 6D599C 8022192C 00000043 */  sra       $zero, $zero, 1
/* 6D59A0 80221930 00000003 */  sra       $zero, $zero, 0
/* 6D59A4 80221934 8025385C */  lb        $a1, 0x385c($at)
/* 6D59A8 80221938 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D59AC 8022193C 000020D4 */  .byte     0x00, 0x00, 0x20, 0xd4
/* 6D59B0 80221940 0000000A */  movz      $zero, $zero, $zero
/* 6D59B4 80221944 00000002 */  srl       $zero, $zero, 0
/* 6D59B8 80221948 FBD3E281 */  bbit132   $fp, 0x13, .L8021A350
/* 6D59BC 8022194C 00000000 */   nop      
/* 6D59C0 80221950 0000000A */  movz      $zero, $zero, $zero
/* 6D59C4 80221954 00000002 */  srl       $zero, $zero, 0
/* 6D59C8 80221958 FBD3E280 */  bbit132   $fp, 0x13, .L8021A35C
/* 6D59CC 8022195C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D59D0 80221960 00000043 */  sra       $zero, $zero, 1
/* 6D59D4 80221964 00000004 */  sllv      $zero, $zero, $zero
/* 6D59D8 80221968 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D59DC 8022196C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D59E0 80221970 00000001 */  movf      $zero, $zero, $fcc0
/* 6D59E4 80221974 00560002 */  .byte     0x00, 0x56, 0x00, 0x02
/* 6D59E8 80221978 00000043 */  sra       $zero, $zero, 1
/* 6D59EC 8022197C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D59F0 80221980 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D59F4 80221984 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D59F8 80221988 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D59FC 8022198C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5A00 80221990 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D5A04 80221994 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D5A08 80221998 00000002 */  srl       $zero, $zero, 0
/* 6D5A0C 8022199C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5A10 802219A0 00000011 */  mthi      $zero
/* 6D5A14 802219A4 00000027 */  not       $zero, $zero
/* 6D5A18 802219A8 00000002 */  srl       $zero, $zero, 0
/* 6D5A1C 802219AC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5A20 802219B0 00000021 */  addu      $zero, $zero, $zero
/* 6D5A24 802219B4 00000043 */  sra       $zero, $zero, 1
/* 6D5A28 802219B8 0000000F */  sync      
/* 6D5A2C 802219BC 802D829C */  lb        $t5, -0x7d64($at)
/* 6D5A30 802219C0 00000047 */  .byte     0x00, 0x00, 0x00, 0x47
/* 6D5A34 802219C4 00000000 */  nop       
/* 6D5A38 802219C8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5A3C 802219CC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5A40 802219D0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D5A44 802219D4 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 6D5A48 802219D8 0000001E */  ddiv      $zero, $zero, $zero
/* 6D5A4C 802219DC 00000000 */  nop       
/* 6D5A50 802219E0 00000000 */  nop       
/* 6D5A54 802219E4 00000000 */  nop       
/* 6D5A58 802219E8 00000000 */  nop       
/* 6D5A5C 802219EC 00000000 */  nop       
/* 6D5A60 802219F0 00000000 */  nop       
/* 6D5A64 802219F4 00000000 */  nop       
/* 6D5A68 802219F8 00000013 */  mtlo      $zero
/* 6D5A6C 802219FC 00000000 */  nop       
/* 6D5A70 80221A00 00000043 */  sra       $zero, $zero, 1
/* 6D5A74 80221A04 00000004 */  sllv      $zero, $zero, $zero
/* 6D5A78 80221A08 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D5A7C 80221A0C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5A80 80221A10 00000001 */  movf      $zero, $zero, $fcc0
/* 6D5A84 80221A14 00560002 */  .byte     0x00, 0x56, 0x00, 0x02
/* 6D5A88 80221A18 00000043 */  sra       $zero, $zero, 1
/* 6D5A8C 80221A1C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D5A90 80221A20 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D5A94 80221A24 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5A98 80221A28 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5A9C 80221A2C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5AA0 80221A30 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D5AA4 80221A34 00000043 */  sra       $zero, $zero, 1
/* 6D5AA8 80221A38 00000003 */  sra       $zero, $zero, 0
/* 6D5AAC 80221A3C 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D5AB0 80221A40 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5AB4 80221A44 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D5AB8 80221A48 00000010 */  mfhi      $zero
/* 6D5ABC 80221A4C 00000002 */  srl       $zero, $zero, 0
/* 6D5AC0 80221A50 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D5AC4 80221A54 00080000 */  sll       $zero, $t0, 0
/* 6D5AC8 80221A58 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D5ACC 80221A5C 00000002 */  srl       $zero, $zero, 0
/* 6D5AD0 80221A60 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5AD4 80221A64 00000006 */  srlv      $zero, $zero, $zero
/* 6D5AD8 80221A68 00000027 */  not       $zero, $zero
/* 6D5ADC 80221A6C 00000002 */  srl       $zero, $zero, 0
/* 6D5AE0 80221A70 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5AE4 80221A74 0000000D */  break     
/* 6D5AE8 80221A78 00000012 */   mflo     $zero
/* 6D5AEC 80221A7C 00000000 */  nop       
/* 6D5AF0 80221A80 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D5AF4 80221A84 00000002 */  srl       $zero, $zero, 0
/* 6D5AF8 80221A88 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5AFC 80221A8C 00000011 */  mthi      $zero
/* 6D5B00 80221A90 00000027 */  not       $zero, $zero
/* 6D5B04 80221A94 00000002 */  srl       $zero, $zero, 0
/* 6D5B08 80221A98 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5B0C 80221A9C 00000021 */  addu      $zero, $zero, $zero
/* 6D5B10 80221AA0 00000013 */  mtlo      $zero
/* 6D5B14 80221AA4 00000000 */  nop       
/* 6D5B18 80221AA8 00000043 */  sra       $zero, $zero, 1
/* 6D5B1C 80221AAC 0000000F */  sync      
/* 6D5B20 80221AB0 802D829C */  lb        $t5, -0x7d64($at)
/* 6D5B24 80221AB4 00000047 */  .byte     0x00, 0x00, 0x00, 0x47
/* 6D5B28 80221AB8 00000000 */  nop       
/* 6D5B2C 80221ABC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5B30 80221AC0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5B34 80221AC4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D5B38 80221AC8 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 6D5B3C 80221ACC 0000001E */  ddiv      $zero, $zero, $zero
/* 6D5B40 80221AD0 00000000 */  nop       
/* 6D5B44 80221AD4 00000000 */  nop       
/* 6D5B48 80221AD8 00000000 */  nop       
/* 6D5B4C 80221ADC 00000000 */  nop       
/* 6D5B50 80221AE0 00000000 */  nop       
/* 6D5B54 80221AE4 00000000 */  nop       
/* 6D5B58 80221AE8 00000000 */  nop       
/* 6D5B5C 80221AEC 00000012 */  mflo      $zero
/* 6D5B60 80221AF0 00000000 */  nop       
/* 6D5B64 80221AF4 0000000A */  movz      $zero, $zero, $zero
/* 6D5B68 80221AF8 00000002 */  srl       $zero, $zero, 0
/* 6D5B6C 80221AFC FBD3E280 */  bbit132   $fp, 0x13, .L8021A500
/* 6D5B70 80221B00 00000001 */   movf     $zero, $zero, $fcc0
/* 6D5B74 80221B04 00000043 */  sra       $zero, $zero, 1
/* 6D5B78 80221B08 00000004 */  sllv      $zero, $zero, $zero
/* 6D5B7C 80221B0C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D5B80 80221B10 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D5B84 80221B14 00000001 */  movf      $zero, $zero, $fcc0
/* 6D5B88 80221B18 00570002 */  .byte     0x00, 0x57, 0x00, 0x02
/* 6D5B8C 80221B1C 00000043 */  sra       $zero, $zero, 1
/* 6D5B90 80221B20 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D5B94 80221B24 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D5B98 80221B28 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D5B9C 80221B2C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5BA0 80221B30 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5BA4 80221B34 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D5BA8 80221B38 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D5BAC 80221B3C 00000002 */  srl       $zero, $zero, 0
/* 6D5BB0 80221B40 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5BB4 80221B44 0000001E */  ddiv      $zero, $zero, $zero
/* 6D5BB8 80221B48 00000027 */  not       $zero, $zero
/* 6D5BBC 80221B4C 00000002 */  srl       $zero, $zero, 0
/* 6D5BC0 80221B50 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5BC4 80221B54 00000024 */  and       $zero, $zero, $zero
/* 6D5BC8 80221B58 00000043 */  sra       $zero, $zero, 1
/* 6D5BCC 80221B5C 0000000F */  sync      
/* 6D5BD0 80221B60 802D829C */  lb        $t5, -0x7d64($at)
/* 6D5BD4 80221B64 00000047 */  .byte     0x00, 0x00, 0x00, 0x47
/* 6D5BD8 80221B68 00000000 */  nop       
/* 6D5BDC 80221B6C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5BE0 80221B70 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5BE4 80221B74 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D5BE8 80221B78 F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 6D5BEC 80221B7C 0000001E */  ddiv      $zero, $zero, $zero
/* 6D5BF0 80221B80 00000000 */  nop       
/* 6D5BF4 80221B84 00000000 */  nop       
/* 6D5BF8 80221B88 00000000 */  nop       
/* 6D5BFC 80221B8C 00000000 */  nop       
/* 6D5C00 80221B90 00000000 */  nop       
/* 6D5C04 80221B94 00000000 */  nop       
/* 6D5C08 80221B98 00000000 */  nop       
/* 6D5C0C 80221B9C 00000013 */  mtlo      $zero
/* 6D5C10 80221BA0 00000000 */  nop       
/* 6D5C14 80221BA4 00000043 */  sra       $zero, $zero, 1
/* 6D5C18 80221BA8 00000004 */  sllv      $zero, $zero, $zero
/* 6D5C1C 80221BAC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D5C20 80221BB0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5C24 80221BB4 00000002 */  srl       $zero, $zero, 0
/* 6D5C28 80221BB8 00570002 */  .byte     0x00, 0x57, 0x00, 0x02
/* 6D5C2C 80221BBC 00000043 */  sra       $zero, $zero, 1
/* 6D5C30 80221BC0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D5C34 80221BC4 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D5C38 80221BC8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5C3C 80221BCC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5C40 80221BD0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5C44 80221BD4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D5C48 80221BD8 00000043 */  sra       $zero, $zero, 1
/* 6D5C4C 80221BDC 00000003 */  sra       $zero, $zero, 0
/* 6D5C50 80221BE0 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D5C54 80221BE4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5C58 80221BE8 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D5C5C 80221BEC 00000010 */  mfhi      $zero
/* 6D5C60 80221BF0 00000002 */  srl       $zero, $zero, 0
/* 6D5C64 80221BF4 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D5C68 80221BF8 00080000 */  sll       $zero, $t0, 0
/* 6D5C6C 80221BFC 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D5C70 80221C00 00000002 */  srl       $zero, $zero, 0
/* 6D5C74 80221C04 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5C78 80221C08 0000000C */  syscall   
/* 6D5C7C 80221C0C 00000027 */  not       $zero, $zero
/* 6D5C80 80221C10 00000002 */  srl       $zero, $zero, 0
/* 6D5C84 80221C14 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5C88 80221C18 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D5C8C 80221C1C 00000012 */  mflo      $zero
/* 6D5C90 80221C20 00000000 */  nop       
/* 6D5C94 80221C24 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D5C98 80221C28 00000002 */  srl       $zero, $zero, 0
/* 6D5C9C 80221C2C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5CA0 80221C30 0000001E */  ddiv      $zero, $zero, $zero
/* 6D5CA4 80221C34 00000027 */  not       $zero, $zero
/* 6D5CA8 80221C38 00000002 */  srl       $zero, $zero, 0
/* 6D5CAC 80221C3C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5CB0 80221C40 00000024 */  and       $zero, $zero, $zero
/* 6D5CB4 80221C44 00000013 */  mtlo      $zero
/* 6D5CB8 80221C48 00000000 */  nop       
/* 6D5CBC 80221C4C 00000043 */  sra       $zero, $zero, 1
/* 6D5CC0 80221C50 0000000F */  sync      
/* 6D5CC4 80221C54 802D829C */  lb        $t5, -0x7d64($at)
/* 6D5CC8 80221C58 00000047 */  .byte     0x00, 0x00, 0x00, 0x47
/* 6D5CCC 80221C5C 00000000 */  nop       
/* 6D5CD0 80221C60 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5CD4 80221C64 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5CD8 80221C68 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D5CDC 80221C6C F24A7C80 */  scd       $t2, 0x7c80($s2)
/* 6D5CE0 80221C70 0000001E */  ddiv      $zero, $zero, $zero
/* 6D5CE4 80221C74 00000000 */  nop       
/* 6D5CE8 80221C78 00000000 */  nop       
/* 6D5CEC 80221C7C 00000000 */  nop       
/* 6D5CF0 80221C80 00000000 */  nop       
/* 6D5CF4 80221C84 00000000 */  nop       
/* 6D5CF8 80221C88 00000000 */  nop       
/* 6D5CFC 80221C8C 00000000 */  nop       
/* 6D5D00 80221C90 00000013 */  mtlo      $zero
/* 6D5D04 80221C94 00000000 */  nop       
/* 6D5D08 80221C98 00000008 */  jr        $zero
/* 6D5D0C 80221C9C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D5D10 80221CA0 0000001E */  ddiv      $zero, $zero, $zero
/* 6D5D14 80221CA4 00000043 */  sra       $zero, $zero, 1
/* 6D5D18 80221CA8 00000007 */  srav      $zero, $zero, $zero
/* 6D5D1C 80221CAC 8027CFB8 */  lb        $a3, -0x3048($at)
/* 6D5D20 80221CB0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5D24 80221CB4 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D5D28 80221CB8 00000000 */  nop       
/* 6D5D2C 80221CBC 00000000 */  nop       
/* 6D5D30 80221CC0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D5D34 80221CC4 00000010 */  mfhi      $zero
/* 6D5D38 80221CC8 00000014 */  dsllv     $zero, $zero, $zero
/* 6D5D3C 80221CCC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D5D40 80221CD0 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D5D44 80221CD4 0000001D */  dmultu    $zero, $zero
/* 6D5D48 80221CD8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D5D4C 80221CDC 00000006 */  srlv      $zero, $zero, $zero
/* 6D5D50 80221CE0 0000001D */  dmultu    $zero, $zero
/* 6D5D54 80221CE4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D5D58 80221CE8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D5D5C 80221CEC 0000000A */  movz      $zero, $zero, $zero
/* 6D5D60 80221CF0 00000002 */  srl       $zero, $zero, 0
/* 6D5D64 80221CF4 FBD3E280 */  bbit132   $fp, 0x13, .L8021A6F8
/* 6D5D68 80221CF8 00000001 */   movf     $zero, $zero, $fcc0
/* 6D5D6C 80221CFC 00000043 */  sra       $zero, $zero, 1
/* 6D5D70 80221D00 00000003 */  sra       $zero, $zero, 0
/* 6D5D74 80221D04 8025385C */  lb        $a1, 0x385c($at)
/* 6D5D78 80221D08 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D5D7C 80221D0C 000020D5 */  dlsa      $a0, $zero, $zero, 4
/* 6D5D80 80221D10 00000013 */  mtlo      $zero
/* 6D5D84 80221D14 00000000 */  nop       
/* 6D5D88 80221D18 00000043 */  sra       $zero, $zero, 1
/* 6D5D8C 80221D1C 00000003 */  sra       $zero, $zero, 0
/* 6D5D90 80221D20 8025385C */  lb        $a1, 0x385c($at)
/* 6D5D94 80221D24 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5D98 80221D28 000020D5 */  dlsa      $a0, $zero, $zero, 4
/* 6D5D9C 80221D2C 0000000A */  movz      $zero, $zero, $zero
/* 6D5DA0 80221D30 00000002 */  srl       $zero, $zero, 0
/* 6D5DA4 80221D34 FBD3E281 */  bbit132   $fp, 0x13, .L8021A73C
/* 6D5DA8 80221D38 00000000 */   nop      
/* 6D5DAC 80221D3C 0000000A */  movz      $zero, $zero, $zero
/* 6D5DB0 80221D40 00000002 */  srl       $zero, $zero, 0
/* 6D5DB4 80221D44 FBD3E280 */  bbit132   $fp, 0x13, .L8021A748
/* 6D5DB8 80221D48 00000001 */   movf     $zero, $zero, $fcc0
/* 6D5DBC 80221D4C 00000043 */  sra       $zero, $zero, 1
/* 6D5DC0 80221D50 00000004 */  sllv      $zero, $zero, $zero
/* 6D5DC4 80221D54 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D5DC8 80221D58 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D5DCC 80221D5C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D5DD0 80221D60 00560003 */  .byte     0x00, 0x56, 0x00, 0x03
/* 6D5DD4 80221D64 00000013 */  mtlo      $zero
/* 6D5DD8 80221D68 00000000 */  nop       
/* 6D5DDC 80221D6C 00000043 */  sra       $zero, $zero, 1
/* 6D5DE0 80221D70 00000004 */  sllv      $zero, $zero, $zero
/* 6D5DE4 80221D74 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D5DE8 80221D78 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5DEC 80221D7C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D5DF0 80221D80 00560003 */  .byte     0x00, 0x56, 0x00, 0x03
/* 6D5DF4 80221D84 00000012 */  mflo      $zero
/* 6D5DF8 80221D88 00000000 */  nop       
/* 6D5DFC 80221D8C 0000000A */  movz      $zero, $zero, $zero
/* 6D5E00 80221D90 00000002 */  srl       $zero, $zero, 0
/* 6D5E04 80221D94 FBD3E280 */  bbit132   $fp, 0x13, .L8021A798
/* 6D5E08 80221D98 00000001 */   movf     $zero, $zero, $fcc0
/* 6D5E0C 80221D9C 00000043 */  sra       $zero, $zero, 1
/* 6D5E10 80221DA0 00000004 */  sllv      $zero, $zero, $zero
/* 6D5E14 80221DA4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D5E18 80221DA8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D5E1C 80221DAC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D5E20 80221DB0 00570003 */  .byte     0x00, 0x57, 0x00, 0x03
/* 6D5E24 80221DB4 00000013 */  mtlo      $zero
/* 6D5E28 80221DB8 00000000 */  nop       
/* 6D5E2C 80221DBC 00000043 */  sra       $zero, $zero, 1
/* 6D5E30 80221DC0 00000004 */  sllv      $zero, $zero, $zero
/* 6D5E34 80221DC4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D5E38 80221DC8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5E3C 80221DCC 00000002 */  srl       $zero, $zero, 0
/* 6D5E40 80221DD0 00570003 */  .byte     0x00, 0x57, 0x00, 0x03
/* 6D5E44 80221DD4 00000013 */  mtlo      $zero
/* 6D5E48 80221DD8 00000000 */  nop       
/* 6D5E4C 80221DDC 00000008 */  jr        $zero
/* 6D5E50 80221DE0 00000001 */   movf     $zero, $zero, $fcc0
/* 6D5E54 80221DE4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D5E58 80221DE8 00000043 */  sra       $zero, $zero, 1
/* 6D5E5C 80221DEC 00000002 */  srl       $zero, $zero, 0
/* 6D5E60 80221DF0 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 6D5E64 80221DF4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5E68 80221DF8 00000043 */  sra       $zero, $zero, 1
/* 6D5E6C 80221DFC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D5E70 80221E00 8026A820 */  lb        $a2, -0x57e0($at)
/* 6D5E74 80221E04 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5E78 80221E08 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D5E7C 80221E0C FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6D5E80 80221E10 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 6D5E84 80221E14 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D5E88 80221E18 00000002 */  srl       $zero, $zero, 0
/* 6D5E8C 80221E1C FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D5E90 80221E20 00000032 */  tlt       $zero, $zero
/* 6D5E94 80221E24 00000024 */  and       $zero, $zero, $zero
/* 6D5E98 80221E28 00000002 */  srl       $zero, $zero, 0
/* 6D5E9C 80221E2C FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6D5EA0 80221E30 00000000 */  nop       
/* 6D5EA4 80221E34 0000000A */  movz      $zero, $zero, $zero
/* 6D5EA8 80221E38 00000002 */  srl       $zero, $zero, 0
/* 6D5EAC 80221E3C FBD3E281 */  bbit132   $fp, 0x13, .L8021A844
/* 6D5EB0 80221E40 00000000 */   nop      
/* 6D5EB4 80221E44 0000000A */  movz      $zero, $zero, $zero
/* 6D5EB8 80221E48 00000002 */  srl       $zero, $zero, 0
/* 6D5EBC 80221E4C FBD3E280 */  bbit132   $fp, 0x13, .L8021A850
/* 6D5EC0 80221E50 00000001 */   movf     $zero, $zero, $fcc0
/* 6D5EC4 80221E54 00000043 */  sra       $zero, $zero, 1
/* 6D5EC8 80221E58 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D5ECC 80221E5C 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D5ED0 80221E60 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D5ED4 80221E64 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5ED8 80221E68 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5EDC 80221E6C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D5EE0 80221E70 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D5EE4 80221E74 00000002 */  srl       $zero, $zero, 0
/* 6D5EE8 80221E78 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5EEC 80221E7C 00000014 */  dsllv     $zero, $zero, $zero
/* 6D5EF0 80221E80 00000027 */  not       $zero, $zero
/* 6D5EF4 80221E84 00000002 */  srl       $zero, $zero, 0
/* 6D5EF8 80221E88 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5EFC 80221E8C 00000014 */  dsllv     $zero, $zero, $zero
/* 6D5F00 80221E90 00000043 */  sra       $zero, $zero, 1
/* 6D5F04 80221E94 00000008 */  jr        $zero
/* 6D5F08 80221E98 80218150 */   lb       $at, -0x7eb0($at)
/* 6D5F0C 80221E9C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5F10 80221EA0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5F14 80221EA4 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 6D5F18 80221EA8 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D5F1C 80221EAC FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6D5F20 80221EB0 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 6D5F24 80221EB4 0000001E */  ddiv      $zero, $zero, $zero
/* 6D5F28 80221EB8 00000013 */  mtlo      $zero
/* 6D5F2C 80221EBC 00000000 */  nop       
/* 6D5F30 80221EC0 00000043 */  sra       $zero, $zero, 1
/* 6D5F34 80221EC4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D5F38 80221EC8 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D5F3C 80221ECC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5F40 80221ED0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5F44 80221ED4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5F48 80221ED8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D5F4C 80221EDC 00000043 */  sra       $zero, $zero, 1
/* 6D5F50 80221EE0 00000003 */  sra       $zero, $zero, 0
/* 6D5F54 80221EE4 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D5F58 80221EE8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D5F5C 80221EEC FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D5F60 80221EF0 00000010 */  mfhi      $zero
/* 6D5F64 80221EF4 00000002 */  srl       $zero, $zero, 0
/* 6D5F68 80221EF8 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D5F6C 80221EFC 00080000 */  sll       $zero, $t0, 0
/* 6D5F70 80221F00 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D5F74 80221F04 00000002 */  srl       $zero, $zero, 0
/* 6D5F78 80221F08 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5F7C 80221F0C 00000008 */  jr        $zero
/* 6D5F80 80221F10 00000027 */   not      $zero, $zero
/* 6D5F84 80221F14 00000002 */  srl       $zero, $zero, 0
/* 6D5F88 80221F18 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5F8C 80221F1C 00000008 */  jr        $zero
/* 6D5F90 80221F20 00000012 */   mflo     $zero
/* 6D5F94 80221F24 00000000 */  nop       
/* 6D5F98 80221F28 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D5F9C 80221F2C 00000002 */  srl       $zero, $zero, 0
/* 6D5FA0 80221F30 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5FA4 80221F34 00000014 */  dsllv     $zero, $zero, $zero
/* 6D5FA8 80221F38 00000027 */  not       $zero, $zero
/* 6D5FAC 80221F3C 00000002 */  srl       $zero, $zero, 0
/* 6D5FB0 80221F40 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5FB4 80221F44 00000014 */  dsllv     $zero, $zero, $zero
/* 6D5FB8 80221F48 00000013 */  mtlo      $zero
/* 6D5FBC 80221F4C 00000000 */  nop       
/* 6D5FC0 80221F50 00000043 */  sra       $zero, $zero, 1
/* 6D5FC4 80221F54 00000008 */  jr        $zero
/* 6D5FC8 80221F58 80218150 */   lb       $at, -0x7eb0($at)
/* 6D5FCC 80221F5C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D5FD0 80221F60 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D5FD4 80221F64 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 6D5FD8 80221F68 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D5FDC 80221F6C FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6D5FE0 80221F70 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 6D5FE4 80221F74 0000001E */  ddiv      $zero, $zero, $zero
/* 6D5FE8 80221F78 00000012 */  mflo      $zero
/* 6D5FEC 80221F7C 00000000 */  nop       
/* 6D5FF0 80221F80 0000000A */  movz      $zero, $zero, $zero
/* 6D5FF4 80221F84 00000002 */  srl       $zero, $zero, 0
/* 6D5FF8 80221F88 FBD3E280 */  bbit132   $fp, 0x13, .L8021A98C
/* 6D5FFC 80221F8C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D6000 80221F90 00000043 */  sra       $zero, $zero, 1
/* 6D6004 80221F94 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D6008 80221F98 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D600C 80221F9C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D6010 80221FA0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6014 80221FA4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6018 80221FA8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D601C 80221FAC 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D6020 80221FB0 00000002 */  srl       $zero, $zero, 0
/* 6D6024 80221FB4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6028 80221FB8 00000014 */  dsllv     $zero, $zero, $zero
/* 6D602C 80221FBC 00000027 */  not       $zero, $zero
/* 6D6030 80221FC0 00000002 */  srl       $zero, $zero, 0
/* 6D6034 80221FC4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6038 80221FC8 00000014 */  dsllv     $zero, $zero, $zero
/* 6D603C 80221FCC 00000043 */  sra       $zero, $zero, 1
/* 6D6040 80221FD0 00000008 */  jr        $zero
/* 6D6044 80221FD4 80218150 */   lb       $at, -0x7eb0($at)
/* 6D6048 80221FD8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D604C 80221FDC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6050 80221FE0 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 6D6054 80221FE4 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D6058 80221FE8 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6D605C 80221FEC FE363C86 */  sd        $s6, 0x3c86($s1)
/* 6D6060 80221FF0 0000001E */  ddiv      $zero, $zero, $zero
/* 6D6064 80221FF4 00000013 */  mtlo      $zero
/* 6D6068 80221FF8 00000000 */  nop       
/* 6D606C 80221FFC 00000043 */  sra       $zero, $zero, 1
/* 6D6070 80222000 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D6074 80222004 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D6078 80222008 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D607C 8022200C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6080 80222010 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6084 80222014 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D6088 80222018 00000043 */  sra       $zero, $zero, 1
/* 6D608C 8022201C 00000003 */  sra       $zero, $zero, 0
/* 6D6090 80222020 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D6094 80222024 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6098 80222028 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D609C 8022202C 00000010 */  mfhi      $zero
/* 6D60A0 80222030 00000002 */  srl       $zero, $zero, 0
/* 6D60A4 80222034 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D60A8 80222038 00080000 */  sll       $zero, $t0, 0
/* 6D60AC 8022203C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D60B0 80222040 00000002 */  srl       $zero, $zero, 0
/* 6D60B4 80222044 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D60B8 80222048 00000008 */  jr        $zero
/* 6D60BC 8022204C 00000027 */   not      $zero, $zero
/* 6D60C0 80222050 00000002 */  srl       $zero, $zero, 0
/* 6D60C4 80222054 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D60C8 80222058 00000008 */  jr        $zero
/* 6D60CC 8022205C 00000012 */   mflo     $zero
/* 6D60D0 80222060 00000000 */  nop       
/* 6D60D4 80222064 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D60D8 80222068 00000002 */  srl       $zero, $zero, 0
/* 6D60DC 8022206C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D60E0 80222070 00000014 */  dsllv     $zero, $zero, $zero
/* 6D60E4 80222074 00000027 */  not       $zero, $zero
/* 6D60E8 80222078 00000002 */  srl       $zero, $zero, 0
/* 6D60EC 8022207C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D60F0 80222080 00000014 */  dsllv     $zero, $zero, $zero
/* 6D60F4 80222084 00000013 */  mtlo      $zero
/* 6D60F8 80222088 00000000 */  nop       
/* 6D60FC 8022208C 00000043 */  sra       $zero, $zero, 1
/* 6D6100 80222090 00000008 */  jr        $zero
/* 6D6104 80222094 80218150 */   lb       $at, -0x7eb0($at)
/* 6D6108 80222098 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D610C 8022209C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6110 802220A0 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 6D6114 802220A4 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D6118 802220A8 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6D611C 802220AC FE363C86 */  sd        $s6, 0x3c86($s1)
/* 6D6120 802220B0 0000001E */  ddiv      $zero, $zero, $zero
/* 6D6124 802220B4 00000013 */  mtlo      $zero
/* 6D6128 802220B8 00000000 */  nop       
/* 6D612C 802220BC 00000008 */  jr        $zero
/* 6D6130 802220C0 00000001 */   movf     $zero, $zero, $fcc0
/* 6D6134 802220C4 00000032 */  tlt       $zero, $zero
/* 6D6138 802220C8 0000000A */  movz      $zero, $zero, $zero
/* 6D613C 802220CC 00000002 */  srl       $zero, $zero, 0
/* 6D6140 802220D0 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D6144 802220D4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D6148 802220D8 00000043 */  sra       $zero, $zero, 1
/* 6D614C 802220DC 00000007 */  srav      $zero, $zero, $zero
/* 6D6150 802220E0 8027CFB8 */  lb        $a3, -0x3048($at)
/* 6D6154 802220E4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6158 802220E8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D615C 802220EC 80000000 */  lb        $zero, ($zero)
/* 6D6160 802220F0 00000000 */  nop       
/* 6D6164 802220F4 00000000 */  nop       
/* 6D6168 802220F8 00000000 */  nop       
/* 6D616C 802220FC 00000013 */  mtlo      $zero
/* 6D6170 80222100 00000000 */  nop       
/* 6D6174 80222104 00000008 */  jr        $zero
/* 6D6178 80222108 00000001 */   movf     $zero, $zero, $fcc0
/* 6D617C 8022210C 0000000F */  sync      
/* 6D6180 80222110 00000043 */  sra       $zero, $zero, 1
/* 6D6184 80222114 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6188 80222118 8027D7F0 */  lb        $a3, -0x2810($at)
/* 6D618C 8022211C 00000043 */  sra       $zero, $zero, 1
/* 6D6190 80222120 00000003 */  sra       $zero, $zero, 0
/* 6D6194 80222124 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D6198 80222128 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D619C 8022212C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D61A0 80222130 0000000A */  movz      $zero, $zero, $zero
/* 6D61A4 80222134 00000002 */  srl       $zero, $zero, 0
/* 6D61A8 80222138 FBD3E280 */  bbit132   $fp, 0x13, .L8021AB3C
/* 6D61AC 8022213C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D61B0 80222140 00000043 */  sra       $zero, $zero, 1
/* 6D61B4 80222144 00000003 */  sra       $zero, $zero, 0
/* 6D61B8 80222148 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D61BC 8022214C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D61C0 80222150 00000001 */  movf      $zero, $zero, $fcc0
/* 6D61C4 80222154 00000013 */  mtlo      $zero
/* 6D61C8 80222158 00000000 */  nop       
/* 6D61CC 8022215C 00000002 */  srl       $zero, $zero, 0
/* 6D61D0 80222160 00000000 */  nop       
/* 6D61D4 80222164 00000020 */  add       $zero, $zero, $zero
/* 6D61D8 80222168 00000000 */  nop       
/* 6D61DC 8022216C 00000023 */  negu      $zero, $zero
/* 6D61E0 80222170 00000000 */  nop       
/* 6D61E4 80222174 0000000A */  movz      $zero, $zero, $zero
/* 6D61E8 80222178 00000002 */  srl       $zero, $zero, 0
/* 6D61EC 8022217C FBD3E280 */  bbit132   $fp, 0x13, .L8021AB80
/* 6D61F0 80222180 00000001 */   movf     $zero, $zero, $fcc0
/* 6D61F4 80222184 00000043 */  sra       $zero, $zero, 1
/* 6D61F8 80222188 00000003 */  sra       $zero, $zero, 0
/* 6D61FC 8022218C 8025385C */  lb        $a1, 0x385c($at)
/* 6D6200 80222190 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D6204 80222194 000020D5 */  dlsa      $a0, $zero, $zero, 4
/* 6D6208 80222198 00000013 */  mtlo      $zero
/* 6D620C 8022219C 00000000 */  nop       
/* 6D6210 802221A0 00000043 */  sra       $zero, $zero, 1
/* 6D6214 802221A4 00000003 */  sra       $zero, $zero, 0
/* 6D6218 802221A8 8025385C */  lb        $a1, 0x385c($at)
/* 6D621C 802221AC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6220 802221B0 000020D5 */  dlsa      $a0, $zero, $zero, 4
/* 6D6224 802221B4 0000000A */  movz      $zero, $zero, $zero
/* 6D6228 802221B8 00000002 */  srl       $zero, $zero, 0
/* 6D622C 802221BC FBD3E281 */  bbit132   $fp, 0x13, .L8021ABC4
/* 6D6230 802221C0 00000000 */   nop      
/* 6D6234 802221C4 0000000A */  movz      $zero, $zero, $zero
/* 6D6238 802221C8 00000002 */  srl       $zero, $zero, 0
/* 6D623C 802221CC FBD3E280 */  bbit132   $fp, 0x13, .L8021ABD0
/* 6D6240 802221D0 00000001 */   movf     $zero, $zero, $fcc0
/* 6D6244 802221D4 00000043 */  sra       $zero, $zero, 1
/* 6D6248 802221D8 00000004 */  sllv      $zero, $zero, $zero
/* 6D624C 802221DC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D6250 802221E0 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D6254 802221E4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6258 802221E8 00560003 */  .byte     0x00, 0x56, 0x00, 0x03
/* 6D625C 802221EC 00000013 */  mtlo      $zero
/* 6D6260 802221F0 00000000 */  nop       
/* 6D6264 802221F4 00000043 */  sra       $zero, $zero, 1
/* 6D6268 802221F8 00000004 */  sllv      $zero, $zero, $zero
/* 6D626C 802221FC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D6270 80222200 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6274 80222204 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6278 80222208 00560003 */  .byte     0x00, 0x56, 0x00, 0x03
/* 6D627C 8022220C 00000012 */  mflo      $zero
/* 6D6280 80222210 00000000 */  nop       
/* 6D6284 80222214 0000000A */  movz      $zero, $zero, $zero
/* 6D6288 80222218 00000002 */  srl       $zero, $zero, 0
/* 6D628C 8022221C FBD3E280 */  bbit132   $fp, 0x13, .L8021AC20
/* 6D6290 80222220 00000001 */   movf     $zero, $zero, $fcc0
/* 6D6294 80222224 00000043 */  sra       $zero, $zero, 1
/* 6D6298 80222228 00000004 */  sllv      $zero, $zero, $zero
/* 6D629C 8022222C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D62A0 80222230 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D62A4 80222234 00000001 */  movf      $zero, $zero, $fcc0
/* 6D62A8 80222238 00570003 */  .byte     0x00, 0x57, 0x00, 0x03
/* 6D62AC 8022223C 00000013 */  mtlo      $zero
/* 6D62B0 80222240 00000000 */  nop       
/* 6D62B4 80222244 00000043 */  sra       $zero, $zero, 1
/* 6D62B8 80222248 00000004 */  sllv      $zero, $zero, $zero
/* 6D62BC 8022224C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D62C0 80222250 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D62C4 80222254 00000002 */  srl       $zero, $zero, 0
/* 6D62C8 80222258 00570003 */  .byte     0x00, 0x57, 0x00, 0x03
/* 6D62CC 8022225C 00000013 */  mtlo      $zero
/* 6D62D0 80222260 00000000 */  nop       
/* 6D62D4 80222264 00000008 */  jr        $zero
/* 6D62D8 80222268 00000001 */   movf     $zero, $zero, $fcc0
/* 6D62DC 8022226C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D62E0 80222270 00000043 */  sra       $zero, $zero, 1
/* 6D62E4 80222274 00000002 */  srl       $zero, $zero, 0
/* 6D62E8 80222278 8026A3A8 */  lb        $a2, -0x5c58($at)
/* 6D62EC 8022227C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D62F0 80222280 00000043 */  sra       $zero, $zero, 1
/* 6D62F4 80222284 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D62F8 80222288 8026A820 */  lb        $a2, -0x57e0($at)
/* 6D62FC 8022228C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6300 80222290 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D6304 80222294 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6D6308 80222298 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 6D630C 8022229C 0000000A */  movz      $zero, $zero, $zero
/* 6D6310 802222A0 00000002 */  srl       $zero, $zero, 0
/* 6D6314 802222A4 FBD3E281 */  bbit132   $fp, 0x13, .L8021ACAC
/* 6D6318 802222A8 00000000 */   nop      
/* 6D631C 802222AC 0000000A */  movz      $zero, $zero, $zero
/* 6D6320 802222B0 00000002 */  srl       $zero, $zero, 0
/* 6D6324 802222B4 FBD3E280 */  bbit132   $fp, 0x13, .L8021ACB8
/* 6D6328 802222B8 00000001 */   movf     $zero, $zero, $fcc0
/* 6D632C 802222BC 00000043 */  sra       $zero, $zero, 1
/* 6D6330 802222C0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D6334 802222C4 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D6338 802222C8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D633C 802222CC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6340 802222D0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6344 802222D4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D6348 802222D8 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D634C 802222DC 00000002 */  srl       $zero, $zero, 0
/* 6D6350 802222E0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6354 802222E4 00000014 */  dsllv     $zero, $zero, $zero
/* 6D6358 802222E8 00000027 */  not       $zero, $zero
/* 6D635C 802222EC 00000002 */  srl       $zero, $zero, 0
/* 6D6360 802222F0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6364 802222F4 00000014 */  dsllv     $zero, $zero, $zero
/* 6D6368 802222F8 00000043 */  sra       $zero, $zero, 1
/* 6D636C 802222FC 00000008 */  jr        $zero
/* 6D6370 80222300 80218150 */   lb       $at, -0x7eb0($at)
/* 6D6374 80222304 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6378 80222308 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D637C 8022230C FE363C86 */  sd        $s6, 0x3c86($s1)
/* 6D6380 80222310 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D6384 80222314 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6D6388 80222318 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 6D638C 8022231C 00000014 */  dsllv     $zero, $zero, $zero
/* 6D6390 80222320 00000013 */  mtlo      $zero
/* 6D6394 80222324 00000000 */  nop       
/* 6D6398 80222328 00000043 */  sra       $zero, $zero, 1
/* 6D639C 8022232C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D63A0 80222330 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D63A4 80222334 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D63A8 80222338 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D63AC 8022233C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D63B0 80222340 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D63B4 80222344 00000043 */  sra       $zero, $zero, 1
/* 6D63B8 80222348 00000003 */  sra       $zero, $zero, 0
/* 6D63BC 8022234C 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D63C0 80222350 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D63C4 80222354 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D63C8 80222358 00000010 */  mfhi      $zero
/* 6D63CC 8022235C 00000002 */  srl       $zero, $zero, 0
/* 6D63D0 80222360 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D63D4 80222364 00080000 */  sll       $zero, $t0, 0
/* 6D63D8 80222368 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D63DC 8022236C 00000002 */  srl       $zero, $zero, 0
/* 6D63E0 80222370 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D63E4 80222374 00000008 */  jr        $zero
/* 6D63E8 80222378 00000027 */   not      $zero, $zero
/* 6D63EC 8022237C 00000002 */  srl       $zero, $zero, 0
/* 6D63F0 80222380 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D63F4 80222384 00000008 */  jr        $zero
/* 6D63F8 80222388 00000012 */   mflo     $zero
/* 6D63FC 8022238C 00000000 */  nop       
/* 6D6400 80222390 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D6404 80222394 00000002 */  srl       $zero, $zero, 0
/* 6D6408 80222398 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D640C 8022239C 00000014 */  dsllv     $zero, $zero, $zero
/* 6D6410 802223A0 00000027 */  not       $zero, $zero
/* 6D6414 802223A4 00000002 */  srl       $zero, $zero, 0
/* 6D6418 802223A8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D641C 802223AC 00000014 */  dsllv     $zero, $zero, $zero
/* 6D6420 802223B0 00000013 */  mtlo      $zero
/* 6D6424 802223B4 00000000 */  nop       
/* 6D6428 802223B8 00000043 */  sra       $zero, $zero, 1
/* 6D642C 802223BC 00000008 */  jr        $zero
/* 6D6430 802223C0 80218150 */   lb       $at, -0x7eb0($at)
/* 6D6434 802223C4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6438 802223C8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D643C 802223CC FE363C86 */  sd        $s6, 0x3c86($s1)
/* 6D6440 802223D0 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D6444 802223D4 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6D6448 802223D8 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 6D644C 802223DC 00000014 */  dsllv     $zero, $zero, $zero
/* 6D6450 802223E0 00000012 */  mflo      $zero
/* 6D6454 802223E4 00000000 */  nop       
/* 6D6458 802223E8 0000000A */  movz      $zero, $zero, $zero
/* 6D645C 802223EC 00000002 */  srl       $zero, $zero, 0
/* 6D6460 802223F0 FBD3E280 */  bbit132   $fp, 0x13, .L8021ADF4
/* 6D6464 802223F4 00000001 */   movf     $zero, $zero, $fcc0
/* 6D6468 802223F8 00000043 */  sra       $zero, $zero, 1
/* 6D646C 802223FC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D6470 80222400 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D6474 80222404 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D6478 80222408 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D647C 8022240C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6480 80222410 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D6484 80222414 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D6488 80222418 00000002 */  srl       $zero, $zero, 0
/* 6D648C 8022241C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6490 80222420 00000014 */  dsllv     $zero, $zero, $zero
/* 6D6494 80222424 00000027 */  not       $zero, $zero
/* 6D6498 80222428 00000002 */  srl       $zero, $zero, 0
/* 6D649C 8022242C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D64A0 80222430 00000014 */  dsllv     $zero, $zero, $zero
/* 6D64A4 80222434 00000043 */  sra       $zero, $zero, 1
/* 6D64A8 80222438 00000008 */  jr        $zero
/* 6D64AC 8022243C 80218150 */   lb       $at, -0x7eb0($at)
/* 6D64B0 80222440 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D64B4 80222444 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D64B8 80222448 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 6D64BC 8022244C FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D64C0 80222450 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6D64C4 80222454 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 6D64C8 80222458 00000014 */  dsllv     $zero, $zero, $zero
/* 6D64CC 8022245C 00000013 */  mtlo      $zero
/* 6D64D0 80222460 00000000 */  nop       
/* 6D64D4 80222464 00000043 */  sra       $zero, $zero, 1
/* 6D64D8 80222468 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D64DC 8022246C 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D64E0 80222470 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D64E4 80222474 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D64E8 80222478 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D64EC 8022247C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D64F0 80222480 00000043 */  sra       $zero, $zero, 1
/* 6D64F4 80222484 00000003 */  sra       $zero, $zero, 0
/* 6D64F8 80222488 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D64FC 8022248C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6500 80222490 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D6504 80222494 00000010 */  mfhi      $zero
/* 6D6508 80222498 00000002 */  srl       $zero, $zero, 0
/* 6D650C 8022249C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D6510 802224A0 00080000 */  sll       $zero, $t0, 0
/* 6D6514 802224A4 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D6518 802224A8 00000002 */  srl       $zero, $zero, 0
/* 6D651C 802224AC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6520 802224B0 00000008 */  jr        $zero
/* 6D6524 802224B4 00000027 */   not      $zero, $zero
/* 6D6528 802224B8 00000002 */  srl       $zero, $zero, 0
/* 6D652C 802224BC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6530 802224C0 00000008 */  jr        $zero
/* 6D6534 802224C4 00000012 */   mflo     $zero
/* 6D6538 802224C8 00000000 */  nop       
/* 6D653C 802224CC 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D6540 802224D0 00000002 */  srl       $zero, $zero, 0
/* 6D6544 802224D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6548 802224D8 00000014 */  dsllv     $zero, $zero, $zero
/* 6D654C 802224DC 00000027 */  not       $zero, $zero
/* 6D6550 802224E0 00000002 */  srl       $zero, $zero, 0
/* 6D6554 802224E4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6558 802224E8 00000014 */  dsllv     $zero, $zero, $zero
/* 6D655C 802224EC 00000013 */  mtlo      $zero
/* 6D6560 802224F0 00000000 */  nop       
/* 6D6564 802224F4 00000043 */  sra       $zero, $zero, 1
/* 6D6568 802224F8 00000008 */  jr        $zero
/* 6D656C 802224FC 80218150 */   lb       $at, -0x7eb0($at)
/* 6D6570 80222500 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6574 80222504 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6578 80222508 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 6D657C 8022250C FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D6580 80222510 FE363C85 */  sd        $s6, 0x3c85($s1)
/* 6D6584 80222514 FE363C86 */  sd        $s6, 0x3c86($s1)
/* 6D6588 80222518 00000014 */  dsllv     $zero, $zero, $zero
/* 6D658C 8022251C 00000013 */  mtlo      $zero
/* 6D6590 80222520 00000000 */  nop       
/* 6D6594 80222524 00000008 */  jr        $zero
/* 6D6598 80222528 00000001 */   movf     $zero, $zero, $fcc0
/* 6D659C 8022252C 00000012 */  mflo      $zero
/* 6D65A0 80222530 0000000A */  movz      $zero, $zero, $zero
/* 6D65A4 80222534 00000002 */  srl       $zero, $zero, 0
/* 6D65A8 80222538 FBD3E280 */  bbit132   $fp, 0x13, .L8021AF3C
/* 6D65AC 8022253C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D65B0 80222540 00000008 */  jr        $zero
/* 6D65B4 80222544 00000001 */   movf     $zero, $zero, $fcc0
/* 6D65B8 80222548 00000002 */  srl       $zero, $zero, 0
/* 6D65BC 8022254C 00000043 */  sra       $zero, $zero, 1
/* 6D65C0 80222550 00000008 */  jr        $zero
/* 6D65C4 80222554 8027CCB4 */   lb       $a3, -0x334c($at)
/* 6D65C8 80222558 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D65CC 8022255C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D65D0 80222560 10000010 */  b         .L802225A4
/* 6D65D4 80222564 00000000 */   nop      
/* 6D65D8 80222568 00000000 */  nop       
/* 6D65DC 8022256C 00000006 */  srlv      $zero, $zero, $zero
/* 6D65E0 80222570 00000020 */  add       $zero, $zero, $zero
/* 6D65E4 80222574 00000012 */  mflo      $zero
/* 6D65E8 80222578 00000000 */  nop       
/* 6D65EC 8022257C 00000008 */  jr        $zero
/* 6D65F0 80222580 00000001 */   movf     $zero, $zero, $fcc0
/* 6D65F4 80222584 00000002 */  srl       $zero, $zero, 0
/* 6D65F8 80222588 00000043 */  sra       $zero, $zero, 1
/* 6D65FC 8022258C 00000008 */  jr        $zero
/* 6D6600 80222590 8027CCB4 */   lb       $a3, -0x334c($at)
/* 6D6604 80222594 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6608 80222598 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D660C 8022259C 10000010 */  b         .L802225E0
/* 6D6610 802225A0 00000000 */   nop      
.L802225A4:
/* 6D6614 802225A4 00000000 */  nop       
/* 6D6618 802225A8 00000006 */  srlv      $zero, $zero, $zero
/* 6D661C 802225AC 00000020 */  add       $zero, $zero, $zero
/* 6D6620 802225B0 00000013 */  mtlo      $zero
/* 6D6624 802225B4 00000000 */  nop       
/* 6D6628 802225B8 00000014 */  dsllv     $zero, $zero, $zero
/* 6D662C 802225BC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6630 802225C0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6634 802225C4 0000001D */  dmultu    $zero, $zero
/* 6D6638 802225C8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D663C 802225CC 00000000 */  nop       
/* 6D6640 802225D0 0000001D */  dmultu    $zero, $zero
/* 6D6644 802225D4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6648 802225D8 00000002 */  srl       $zero, $zero, 0
/* 6D664C 802225DC 00000008 */  jr        $zero
.L802225E0:
/* 6D6650 802225E0 00000001 */   movf     $zero, $zero, $fcc0
/* 6D6654 802225E4 00000014 */  dsllv     $zero, $zero, $zero
/* 6D6658 802225E8 00000043 */  sra       $zero, $zero, 1
/* 6D665C 802225EC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6660 802225F0 8027D7F0 */  lb        $a3, -0x2810($at)
/* 6D6664 802225F4 00000020 */  add       $zero, $zero, $zero
/* 6D6668 802225F8 00000000 */  nop       
/* 6D666C 802225FC 00000023 */  negu      $zero, $zero
/* 6D6670 80222600 00000000 */  nop       
/* 6D6674 80222604 00000043 */  sra       $zero, $zero, 1
/* 6D6678 80222608 00000003 */  sra       $zero, $zero, 0
/* 6D667C 8022260C 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D6680 80222610 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6684 80222614 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6688 80222618 0000000A */  movz      $zero, $zero, $zero
/* 6D668C 8022261C 00000002 */  srl       $zero, $zero, 0
/* 6D6690 80222620 FBD3E280 */  bbit132   $fp, 0x13, .L8021B024
/* 6D6694 80222624 00000001 */   movf     $zero, $zero, $fcc0
/* 6D6698 80222628 00000043 */  sra       $zero, $zero, 1
/* 6D669C 8022262C 00000003 */  sra       $zero, $zero, 0
/* 6D66A0 80222630 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D66A4 80222634 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D66A8 80222638 00000001 */  movf      $zero, $zero, $fcc0
/* 6D66AC 8022263C 00000013 */  mtlo      $zero
/* 6D66B0 80222640 00000000 */  nop       
/* 6D66B4 80222644 00000002 */  srl       $zero, $zero, 0
/* 6D66B8 80222648 00000000 */  nop       
/* 6D66BC 8022264C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D66C0 80222650 00000000 */  nop       
/* 6D66C4 80222654 00000043 */  sra       $zero, $zero, 1
/* 6D66C8 80222658 00000002 */  srl       $zero, $zero, 0
/* 6D66CC 8022265C 8026E310 */  lb        $a2, -0x1cf0($at)
/* 6D66D0 80222660 00008002 */  srl       $s0, $zero, 0
/* 6D66D4 80222664 00000043 */  sra       $zero, $zero, 1
/* 6D66D8 80222668 00000001 */  movf      $zero, $zero, $fcc0
/* 6D66DC 8022266C 8026E354 */  lb        $a2, -0x1cac($at)
/* 6D66E0 80222670 00000003 */  sra       $zero, $zero, 0
/* 6D66E4 80222674 00000001 */  movf      $zero, $zero, $fcc0
/* 6D66E8 80222678 00000000 */  nop       
/* 6D66EC 8022267C 00000043 */  sra       $zero, $zero, 1
/* 6D66F0 80222680 00000003 */  sra       $zero, $zero, 0
/* 6D66F4 80222684 8026E8AC */  lb        $a2, -0x1754($at)
/* 6D66F8 80222688 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D66FC 8022268C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6700 80222690 00000043 */  sra       $zero, $zero, 1
/* 6D6704 80222694 00000003 */  sra       $zero, $zero, 0
/* 6D6708 80222698 8026A0D4 */  lb        $a2, -0x5f2c($at)
/* 6D670C 8022269C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6710 802226A0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6714 802226A4 0000002B */  sltu      $zero, $zero, $zero
/* 6D6718 802226A8 00000002 */  srl       $zero, $zero, 0
/* 6D671C 802226AC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6720 802226B0 00000004 */  sllv      $zero, $zero, $zero
/* 6D6724 802226B4 00000014 */  dsllv     $zero, $zero, $zero
/* 6D6728 802226B8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D672C 802226BC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6730 802226C0 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D6734 802226C4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6738 802226C8 00000000 */  nop       
/* 6D673C 802226CC 00000024 */  and       $zero, $zero, $zero
/* 6D6740 802226D0 00000002 */  srl       $zero, $zero, 0
/* 6D6744 802226D4 FBD3E28B */  bbit132   $fp, 0x13, .L8021B104
/* 6D6748 802226D8 00000001 */   movf     $zero, $zero, $fcc0
/* 6D674C 802226DC 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D6750 802226E0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6754 802226E4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6758 802226E8 00000024 */  and       $zero, $zero, $zero
/* 6D675C 802226EC 00000002 */  srl       $zero, $zero, 0
/* 6D6760 802226F0 FBD3E28C */  bbit132   $fp, 0x13, .L8021B124
/* 6D6764 802226F4 00000001 */   movf     $zero, $zero, $fcc0
/* 6D6768 802226F8 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D676C 802226FC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6770 80222700 00000002 */  srl       $zero, $zero, 0
/* 6D6774 80222704 00000024 */  and       $zero, $zero, $zero
/* 6D6778 80222708 00000002 */  srl       $zero, $zero, 0
/* 6D677C 8022270C FBD3E28D */  bbit132   $fp, 0x13, .L8021B144
/* 6D6780 80222710 00000001 */   movf     $zero, $zero, $fcc0
/* 6D6784 80222714 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D6788 80222718 00000001 */  movf      $zero, $zero, $fcc0
/* 6D678C 8022271C 00000003 */  sra       $zero, $zero, 0
/* 6D6790 80222720 00000024 */  and       $zero, $zero, $zero
/* 6D6794 80222724 00000002 */  srl       $zero, $zero, 0
/* 6D6798 80222728 FBD3E28E */  bbit132   $fp, 0x13, .L8021B164
/* 6D679C 8022272C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D67A0 80222730 00000023 */  negu      $zero, $zero
/* 6D67A4 80222734 00000000 */  nop       
/* 6D67A8 80222738 00000043 */  sra       $zero, $zero, 1
/* 6D67AC 8022273C 00000003 */  sra       $zero, $zero, 0
/* 6D67B0 80222740 8026E414 */  lb        $a2, -0x1bec($at)
/* 6D67B4 80222744 00000000 */  nop       
/* 6D67B8 80222748 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D67BC 8022274C 0000000B */  movn      $zero, $zero, $zero
/* 6D67C0 80222750 00000002 */  srl       $zero, $zero, 0
/* 6D67C4 80222754 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D67C8 80222758 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D67CC 8022275C 00000004 */  sllv      $zero, $zero, $zero
/* 6D67D0 80222760 00000001 */  movf      $zero, $zero, $fcc0
/* 6D67D4 80222764 00000000 */  nop       
/* 6D67D8 80222768 00000013 */  mtlo      $zero
/* 6D67DC 8022276C 00000000 */  nop       
/* 6D67E0 80222770 00000024 */  and       $zero, $zero, $zero
/* 6D67E4 80222774 00000002 */  srl       $zero, $zero, 0
/* 6D67E8 80222778 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D67EC 8022277C FFFFFFFF */  sd        $ra, -1($ra)
/* 6D67F0 80222780 00000043 */  sra       $zero, $zero, 1
/* 6D67F4 80222784 00000003 */  sra       $zero, $zero, 0
/* 6D67F8 80222788 8026A0D4 */  lb        $a2, -0x5f2c($at)
/* 6D67FC 8022278C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6800 80222790 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6804 80222794 0000002B */  sltu      $zero, $zero, $zero
/* 6D6808 80222798 00000002 */  srl       $zero, $zero, 0
/* 6D680C 8022279C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6810 802227A0 00000004 */  sllv      $zero, $zero, $zero
/* 6D6814 802227A4 00000014 */  dsllv     $zero, $zero, $zero
/* 6D6818 802227A8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D681C 802227AC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6820 802227B0 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D6824 802227B4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6828 802227B8 00000000 */  nop       
/* 6D682C 802227BC 0000000A */  movz      $zero, $zero, $zero
/* 6D6830 802227C0 00000002 */  srl       $zero, $zero, 0
/* 6D6834 802227C4 FBD3E28C */  bbit132   $fp, 0x13, .L8021B1F8
/* 6D6838 802227C8 00000000 */   nop      
/* 6D683C 802227CC 00000024 */  and       $zero, $zero, $zero
/* 6D6840 802227D0 00000002 */  srl       $zero, $zero, 0
/* 6D6844 802227D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6848 802227D8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D684C 802227DC 00000013 */  mtlo      $zero
/* 6D6850 802227E0 00000000 */  nop       
/* 6D6854 802227E4 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D6858 802227E8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D685C 802227EC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6860 802227F0 0000000A */  movz      $zero, $zero, $zero
/* 6D6864 802227F4 00000002 */  srl       $zero, $zero, 0
/* 6D6868 802227F8 FBD3E28B */  bbit132   $fp, 0x13, .L8021B228
/* 6D686C 802227FC 00000000 */   nop      
/* 6D6870 80222800 00000024 */  and       $zero, $zero, $zero
/* 6D6874 80222804 00000002 */  srl       $zero, $zero, 0
/* 6D6878 80222808 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D687C 8022280C 00000000 */  nop       
/* 6D6880 80222810 00000013 */  mtlo      $zero
/* 6D6884 80222814 00000000 */  nop       
/* 6D6888 80222818 0000000A */  movz      $zero, $zero, $zero
/* 6D688C 8022281C 00000002 */  srl       $zero, $zero, 0
/* 6D6890 80222820 FBD3E28D */  bbit132   $fp, 0x13, .L8021B258
/* 6D6894 80222824 00000000 */   nop      
/* 6D6898 80222828 00000024 */  and       $zero, $zero, $zero
/* 6D689C 8022282C 00000002 */  srl       $zero, $zero, 0
/* 6D68A0 80222830 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D68A4 80222834 00000002 */  srl       $zero, $zero, 0
/* 6D68A8 80222838 00000013 */  mtlo      $zero
/* 6D68AC 8022283C 00000000 */  nop       
/* 6D68B0 80222840 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D68B4 80222844 00000001 */  movf      $zero, $zero, $fcc0
/* 6D68B8 80222848 00000002 */  srl       $zero, $zero, 0
/* 6D68BC 8022284C 0000000A */  movz      $zero, $zero, $zero
/* 6D68C0 80222850 00000002 */  srl       $zero, $zero, 0
/* 6D68C4 80222854 FBD3E28C */  bbit132   $fp, 0x13, .L8021B288
/* 6D68C8 80222858 00000000 */   nop      
/* 6D68CC 8022285C 00000024 */  and       $zero, $zero, $zero
/* 6D68D0 80222860 00000002 */  srl       $zero, $zero, 0
/* 6D68D4 80222864 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D68D8 80222868 00000001 */  movf      $zero, $zero, $fcc0
/* 6D68DC 8022286C 00000013 */  mtlo      $zero
/* 6D68E0 80222870 00000000 */  nop       
/* 6D68E4 80222874 0000000A */  movz      $zero, $zero, $zero
/* 6D68E8 80222878 00000002 */  srl       $zero, $zero, 0
/* 6D68EC 8022287C FBD3E28E */  bbit132   $fp, 0x13, .L8021B2B8
/* 6D68F0 80222880 00000000 */   nop      
/* 6D68F4 80222884 00000024 */  and       $zero, $zero, $zero
/* 6D68F8 80222888 00000002 */  srl       $zero, $zero, 0
/* 6D68FC 8022288C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6900 80222890 00000003 */  sra       $zero, $zero, 0
/* 6D6904 80222894 00000013 */  mtlo      $zero
/* 6D6908 80222898 00000000 */  nop       
/* 6D690C 8022289C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D6910 802228A0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6914 802228A4 00000003 */  sra       $zero, $zero, 0
/* 6D6918 802228A8 0000000A */  movz      $zero, $zero, $zero
/* 6D691C 802228AC 00000002 */  srl       $zero, $zero, 0
/* 6D6920 802228B0 FBD3E28D */  bbit132   $fp, 0x13, .L8021B2E8
/* 6D6924 802228B4 00000000 */   nop      
/* 6D6928 802228B8 00000024 */  and       $zero, $zero, $zero
/* 6D692C 802228BC 00000002 */  srl       $zero, $zero, 0
/* 6D6930 802228C0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6934 802228C4 00000002 */  srl       $zero, $zero, 0
/* 6D6938 802228C8 00000013 */  mtlo      $zero
/* 6D693C 802228CC 00000000 */  nop       
/* 6D6940 802228D0 00000023 */  negu      $zero, $zero
/* 6D6944 802228D4 00000000 */  nop       
/* 6D6948 802228D8 0000000B */  movn      $zero, $zero, $zero
/* 6D694C 802228DC 00000002 */  srl       $zero, $zero, 0
/* 6D6950 802228E0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6954 802228E4 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D6958 802228E8 00000043 */  sra       $zero, $zero, 1
/* 6D695C 802228EC 00000003 */  sra       $zero, $zero, 0
/* 6D6960 802228F0 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D6964 802228F4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6968 802228F8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D696C 802228FC 00000010 */  mfhi      $zero
/* 6D6970 80222900 00000002 */  srl       $zero, $zero, 0
/* 6D6974 80222904 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6978 80222908 00000200 */  sll       $zero, $zero, 8
/* 6D697C 8022290C 00000027 */  not       $zero, $zero
/* 6D6980 80222910 00000002 */  srl       $zero, $zero, 0
/* 6D6984 80222914 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6988 80222918 00000004 */  sllv      $zero, $zero, $zero
/* 6D698C 8022291C 00000013 */  mtlo      $zero
/* 6D6990 80222920 00000000 */  nop       
/* 6D6994 80222924 00000013 */  mtlo      $zero
/* 6D6998 80222928 00000000 */  nop       
/* 6D699C 8022292C 00000002 */  srl       $zero, $zero, 0
/* 6D69A0 80222930 00000000 */  nop       
/* 6D69A4 80222934 00000001 */  movf      $zero, $zero, $fcc0
/* 6D69A8 80222938 00000000 */  nop       
/* 6D69AC 8022293C 00000002 */  srl       $zero, $zero, 0
/* 6D69B0 80222940 00000000 */  nop       
/* 6D69B4 80222944 00000001 */  movf      $zero, $zero, $fcc0
/* 6D69B8 80222948 00000000 */  nop       
/* 6D69BC 8022294C 00000043 */  sra       $zero, $zero, 1
/* 6D69C0 80222950 00000003 */  sra       $zero, $zero, 0
/* 6D69C4 80222954 80278C20 */  lb        $a3, -0x73e0($at)
/* 6D69C8 80222958 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D69CC 8022295C 8022293C */  lb        $v0, 0x293c($at)
/* 6D69D0 80222960 00000043 */  sra       $zero, $zero, 1
/* 6D69D4 80222964 00000004 */  sllv      $zero, $zero, $zero
/* 6D69D8 80222968 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D69DC 8022296C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D69E0 80222970 00000001 */  movf      $zero, $zero, $fcc0
/* 6D69E4 80222974 00000001 */  movf      $zero, $zero, $fcc0
/* 6D69E8 80222978 00000002 */  srl       $zero, $zero, 0
/* 6D69EC 8022297C 00000000 */  nop       
/* 6D69F0 80222980 00000001 */  movf      $zero, $zero, $fcc0
/* 6D69F4 80222984 00000000 */  nop       
/* 6D69F8 80222988 00000043 */  sra       $zero, $zero, 1
/* 6D69FC 8022298C 00000003 */  sra       $zero, $zero, 0
/* 6D6A00 80222990 80278C20 */  lb        $a3, -0x73e0($at)
/* 6D6A04 80222994 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6A08 80222998 8022293C */  lb        $v0, 0x293c($at)
/* 6D6A0C 8022299C 00000043 */  sra       $zero, $zero, 1
/* 6D6A10 802229A0 00000004 */  sllv      $zero, $zero, $zero
/* 6D6A14 802229A4 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D6A18 802229A8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6A1C 802229AC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6A20 802229B0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6A24 802229B4 00000002 */  srl       $zero, $zero, 0
/* 6D6A28 802229B8 00000000 */  nop       
/* 6D6A2C 802229BC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6A30 802229C0 00000000 */  nop       
/* 6D6A34 802229C4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6A38 802229C8 00000000 */  nop       
/* 6D6A3C 802229CC 00000000 */  nop       
/* 6D6A40 802229D0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6A44 802229D4 00000000 */  nop       
/* 6D6A48 802229D8 00000000 */  nop       
/* 6D6A4C 802229DC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6A50 802229E0 00000000 */  nop       
/* 6D6A54 802229E4 00000002 */  srl       $zero, $zero, 0
/* 6D6A58 802229E8 00000000 */  nop       
/* 6D6A5C 802229EC 00000006 */  srlv      $zero, $zero, $zero
/* 6D6A60 802229F0 00000000 */  nop       
/* 6D6A64 802229F4 00000009 */  jr        $zero
/* 6D6A68 802229F8 00000000 */   nop      
/* 6D6A6C 802229FC 00000007 */  srav      $zero, $zero, $zero
/* 6D6A70 80222A00 00000000 */  nop       
/* 6D6A74 80222A04 00000004 */  sllv      $zero, $zero, $zero
/* 6D6A78 80222A08 00000000 */  nop       
/* 6D6A7C 80222A0C 00000003 */  sra       $zero, $zero, 0
/* 6D6A80 80222A10 00000000 */  nop       
/* 6D6A84 80222A14 0000000B */  movn      $zero, $zero, $zero
/* 6D6A88 80222A18 00000000 */  nop       
/* 6D6A8C 80222A1C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D6A90 80222A20 00000000 */  nop       
/* 6D6A94 80222A24 0000000A */  movz      $zero, $zero, $zero
/* 6D6A98 80222A28 00000000 */  nop       
/* 6D6A9C 80222A2C 00000008 */  jr        $zero
/* 6D6AA0 80222A30 00000000 */   nop      
/* 6D6AA4 80222A34 0000001F */  ddivu     $zero, $zero, $zero
/* 6D6AA8 80222A38 00000000 */  nop       
/* 6D6AAC 80222A3C 00000020 */  add       $zero, $zero, $zero
/* 6D6AB0 80222A40 00000000 */  nop       
/* 6D6AB4 80222A44 00000025 */  or        $zero, $zero, $zero
/* 6D6AB8 80222A48 00000000 */  nop       
/* 6D6ABC 80222A4C 00000022 */  neg       $zero, $zero
/* 6D6AC0 80222A50 00000000 */  nop       
/* 6D6AC4 80222A54 00000024 */  and       $zero, $zero, $zero
/* 6D6AC8 80222A58 00000000 */  nop       
/* 6D6ACC 80222A5C 00000023 */  negu      $zero, $zero
/* 6D6AD0 80222A60 00000000 */  nop       
/* 6D6AD4 80222A64 00000021 */  addu      $zero, $zero, $zero
/* 6D6AD8 80222A68 00000000 */  nop       
/* 6D6ADC 80222A6C 00000026 */  xor       $zero, $zero, $zero
/* 6D6AE0 80222A70 00000000 */  nop       
/* 6D6AE4 80222A74 00000027 */  not       $zero, $zero
/* 6D6AE8 80222A78 00000000 */  nop       
/* 6D6AEC 80222A7C 00000029 */  .byte     0x00, 0x00, 0x00, 0x29
/* 6D6AF0 80222A80 00000000 */  nop       
/* 6D6AF4 80222A84 00000000 */  nop       
/* 6D6AF8 80222A88 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6AFC 80222A8C 00000000 */  nop       
/* 6D6B00 80222A90 00000002 */  srl       $zero, $zero, 0
/* 6D6B04 80222A94 00000000 */  nop       
/* 6D6B08 80222A98 00000006 */  srlv      $zero, $zero, $zero
/* 6D6B0C 80222A9C 00000000 */  nop       
/* 6D6B10 80222AA0 00000009 */  jr        $zero
/* 6D6B14 80222AA4 00000000 */   nop      
/* 6D6B18 80222AA8 00000007 */  srav      $zero, $zero, $zero
/* 6D6B1C 80222AAC 00000000 */  nop       
/* 6D6B20 80222AB0 00000004 */  sllv      $zero, $zero, $zero
/* 6D6B24 80222AB4 00000000 */  nop       
/* 6D6B28 80222AB8 00000003 */  sra       $zero, $zero, 0
/* 6D6B2C 80222ABC 00000000 */  nop       
/* 6D6B30 80222AC0 0000000B */  movn      $zero, $zero, $zero
/* 6D6B34 80222AC4 00000000 */  nop       
/* 6D6B38 80222AC8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D6B3C 80222ACC 00000000 */  nop       
/* 6D6B40 80222AD0 0000000A */  movz      $zero, $zero, $zero
/* 6D6B44 80222AD4 00000000 */  nop       
/* 6D6B48 80222AD8 00000008 */  jr        $zero
/* 6D6B4C 80222ADC 00000000 */   nop      
/* 6D6B50 80222AE0 0000001F */  ddivu     $zero, $zero, $zero
/* 6D6B54 80222AE4 00000000 */  nop       
/* 6D6B58 80222AE8 00000020 */  add       $zero, $zero, $zero
/* 6D6B5C 80222AEC 00000000 */  nop       
/* 6D6B60 80222AF0 00000025 */  or        $zero, $zero, $zero
/* 6D6B64 80222AF4 00000000 */  nop       
/* 6D6B68 80222AF8 00000022 */  neg       $zero, $zero
/* 6D6B6C 80222AFC 00000000 */  nop       
/* 6D6B70 80222B00 00000024 */  and       $zero, $zero, $zero
/* 6D6B74 80222B04 00000000 */  nop       
/* 6D6B78 80222B08 00000023 */  negu      $zero, $zero
/* 6D6B7C 80222B0C 00000000 */  nop       
/* 6D6B80 80222B10 00000021 */  addu      $zero, $zero, $zero
/* 6D6B84 80222B14 00000000 */  nop       
/* 6D6B88 80222B18 00000026 */  xor       $zero, $zero, $zero
/* 6D6B8C 80222B1C 00000000 */  nop       
/* 6D6B90 80222B20 00000027 */  not       $zero, $zero
/* 6D6B94 80222B24 00000000 */  nop       
/* 6D6B98 80222B28 00000029 */  .byte     0x00, 0x00, 0x00, 0x29
/* 6D6B9C 80222B2C 00000000 */  nop       
/* 6D6BA0 80222B30 00000000 */  nop       
/* 6D6BA4 80222B34 00800000 */  .byte     0x00, 0x80, 0x00, 0x00
/* 6D6BA8 80222B38 01000000 */  .byte     0x01, 0x00, 0x00, 0x00
/* 6D6BAC 80222B3C 022300FF */  .byte     0x02, 0x23, 0x00, 0xff
/* 6D6BB0 80222B40 8021EA20 */  lb        $at, -0x15e0($at)
/* 6D6BB4 80222B44 802229C4 */  lb        $v0, 0x29c4($at)
/* 6D6BB8 80222B48 00000020 */  add       $zero, $zero, $zero
/* 6D6BBC 80222B4C 00000000 */  nop       
/* 6D6BC0 80222B50 FBF40000 */  bbit132   $ra, 0x14, .L80222B54
.L80222B54:
/* 6D6BC4 80222B54 00000000 */   nop      
/* 6D6BC8 80222B58 00800000 */  .byte     0x00, 0x80, 0x00, 0x00
/* 6D6BCC 80222B5C 01000000 */  .byte     0x01, 0x00, 0x00, 0x00
/* 6D6BD0 80222B60 F62300FF */  sdc1      $f3, 0xff($s1)
/* 6D6BD4 80222B64 8021EA6C */  lb        $at, -0x1594($at)
/* 6D6BD8 80222B68 802229D0 */  lb        $v0, 0x29d0($at)
/* 6D6BDC 80222B6C 00000020 */  add       $zero, $zero, $zero
/* 6D6BE0 80222B70 00000000 */  nop       
/* 6D6BE4 80222B74 00F80000 */  .byte     0x00, 0xf8, 0x00, 0x00
/* 6D6BE8 80222B78 00000000 */  nop       
/* 6D6BEC 80222B7C 00200000 */  .byte     0x00, 0x20, 0x00, 0x00
/* 6D6BF0 80222B80 004F1A0B */  .byte     0x00, 0x4f, 0x1a, 0x0b
/* 6D6BF4 80222B84 00010000 */  sll       $zero, $at, 0
/* 6D6BF8 80222B88 80222B34 */  lb        $v0, 0x2b34($at)
/* 6D6BFC 80222B8C 8022294C */  lb        $v0, 0x294c($at)
/* 6D6C00 80222B90 802229DC */  lb        $v0, 0x29dc($at)
/* 6D6C04 80222B94 28000000 */  slti      $zero, $zero, 0
/* 6D6C08 80222B98 00004B00 */  sll       $t1, $zero, 0xc
/* 6D6C0C 80222B9C 24280000 */  addiu     $t0, $at, 0
/* 6D6C10 80222BA0 F6140A20 */  sdc1      $f20, 0xa20($s0)
/* 6D6C14 80222BA4 00200200 */  .byte     0x00, 0x20, 0x02, 0x00
/* 6D6C18 80222BA8 00501A0B */  .byte     0x00, 0x50, 0x1a, 0x0b
/* 6D6C1C 80222BAC 00010000 */  sll       $zero, $at, 0
/* 6D6C20 80222BB0 80222B58 */  lb        $v0, 0x2b58($at)
/* 6D6C24 80222BB4 80222988 */  lb        $v0, 0x2988($at)
/* 6D6C28 80222BB8 80222A88 */  lb        $v0, 0x2a88($at)
/* 6D6C2C 80222BBC 28000000 */  slti      $zero, $zero, 0
/* 6D6C30 80222BC0 00004B02 */  srl       $t1, $zero, 0xc
/* 6D6C34 80222BC4 30280000 */  andi      $t0, $at, 0
/* 6D6C38 80222BC8 E7140122 */  swc1      $f20, 0x122($t8)
/* 6D6C3C 80222BCC 00000000 */  nop       
/* 6D6C40 80222BD0 FFFFFC18 */  sd        $ra, -0x3e8($ra)
/* 6D6C44 80222BD4 00000000 */  nop       
/* 6D6C48 80222BD8 80222B7C */  lb        $v0, 0x2b7c($at)
/* 6D6C4C 80222BDC 80222BCC */  lb        $v0, 0x2bcc($at)
/* 6D6C50 80222BE0 00000000 */  nop       
/* 6D6C54 80222BE4 00000000 */  nop       
/* 6D6C58 80222BE8 00000000 */  nop       
/* 6D6C5C 80222BEC 00000000 */  nop       
/* 6D6C60 80222BF0 00000000 */  nop       
/* 6D6C64 80222BF4 80222BA4 */  lb        $v0, 0x2ba4($at)
/* 6D6C68 80222BF8 80222BCC */  lb        $v0, 0x2bcc($at)
/* 6D6C6C 80222BFC 00000000 */  nop       
/* 6D6C70 80222C00 00000000 */  nop       
/* 6D6C74 80222C04 00000000 */  nop       
/* 6D6C78 80222C08 00000000 */  nop       
/* 6D6C7C 80222C0C 00000000 */  nop       
/* 6D6C80 80222C10 00000043 */  sra       $zero, $zero, 1
/* 6D6C84 80222C14 00000004 */  sllv      $zero, $zero, $zero
/* 6D6C88 80222C18 8026A14C */  lb        $a2, -0x5eb4($at)
/* 6D6C8C 80222C1C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6C90 80222C20 00008002 */  srl       $s0, $zero, 0
/* 6D6C94 80222C24 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6C98 80222C28 0000000A */  movz      $zero, $zero, $zero
/* 6D6C9C 80222C2C 00000002 */  srl       $zero, $zero, 0
/* 6D6CA0 80222C30 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6CA4 80222C34 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6CA8 80222C38 00000046 */  rotrv     $zero, $zero, $zero
/* 6D6CAC 80222C3C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6CB0 80222C40 8021F39C */  lb        $at, -0xc64($at)
/* 6D6CB4 80222C44 00000002 */  srl       $zero, $zero, 0
/* 6D6CB8 80222C48 00000000 */  nop       
/* 6D6CBC 80222C4C 00000013 */  mtlo      $zero
/* 6D6CC0 80222C50 00000000 */  nop       
/* 6D6CC4 80222C54 00000043 */  sra       $zero, $zero, 1
/* 6D6CC8 80222C58 00000004 */  sllv      $zero, $zero, $zero
/* 6D6CCC 80222C5C 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D6CD0 80222C60 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6CD4 80222C64 0000000A */  movz      $zero, $zero, $zero
/* 6D6CD8 80222C68 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6CDC 80222C6C 00000043 */  sra       $zero, $zero, 1
/* 6D6CE0 80222C70 00000004 */  sllv      $zero, $zero, $zero
/* 6D6CE4 80222C74 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D6CE8 80222C78 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6CEC 80222C7C 0000000B */  movn      $zero, $zero, $zero
/* 6D6CF0 80222C80 00000003 */  sra       $zero, $zero, 0
/* 6D6CF4 80222C84 00000024 */  and       $zero, $zero, $zero
/* 6D6CF8 80222C88 00000002 */  srl       $zero, $zero, 0
/* 6D6CFC 80222C8C FBD3E280 */  bbit132   $fp, 0x13, .L8021B690
/* 6D6D00 80222C90 00000000 */   nop      
/* 6D6D04 80222C94 00000043 */  sra       $zero, $zero, 1
/* 6D6D08 80222C98 00000003 */  sra       $zero, $zero, 0
/* 6D6D0C 80222C9C 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D6D10 80222CA0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6D14 80222CA4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6D18 80222CA8 00000010 */  mfhi      $zero
/* 6D6D1C 80222CAC 00000002 */  srl       $zero, $zero, 0
/* 6D6D20 80222CB0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6D24 80222CB4 00000200 */  sll       $zero, $zero, 8
/* 6D6D28 80222CB8 00000024 */  and       $zero, $zero, $zero
/* 6D6D2C 80222CBC 00000002 */  srl       $zero, $zero, 0
/* 6D6D30 80222CC0 FBD3E280 */  bbit132   $fp, 0x13, .L8021B6C4
/* 6D6D34 80222CC4 00000001 */   movf     $zero, $zero, $fcc0
/* 6D6D38 80222CC8 00000013 */  mtlo      $zero
/* 6D6D3C 80222CCC 00000000 */  nop       
/* 6D6D40 80222CD0 0000000A */  movz      $zero, $zero, $zero
/* 6D6D44 80222CD4 00000002 */  srl       $zero, $zero, 0
/* 6D6D48 80222CD8 FBD3E280 */  bbit132   $fp, 0x13, .L8021B6DC
/* 6D6D4C 80222CDC 00000000 */   nop      
/* 6D6D50 80222CE0 00000043 */  sra       $zero, $zero, 1
/* 6D6D54 80222CE4 00000003 */  sra       $zero, $zero, 0
/* 6D6D58 80222CE8 8026DB64 */  lb        $a2, -0x249c($at)
/* 6D6D5C 80222CEC 80222BD8 */  lb        $v0, 0x2bd8($at)
/* 6D6D60 80222CF0 00000000 */  nop       
/* 6D6D64 80222CF4 00000012 */  mflo      $zero
/* 6D6D68 80222CF8 00000000 */  nop       
/* 6D6D6C 80222CFC 00000043 */  sra       $zero, $zero, 1
/* 6D6D70 80222D00 00000003 */  sra       $zero, $zero, 0
/* 6D6D74 80222D04 8026DB64 */  lb        $a2, -0x249c($at)
/* 6D6D78 80222D08 80222BF4 */  lb        $v0, 0x2bf4($at)
/* 6D6D7C 80222D0C 00000000 */  nop       
/* 6D6D80 80222D10 00000013 */  mtlo      $zero
/* 6D6D84 80222D14 00000000 */  nop       
/* 6D6D88 80222D18 00000043 */  sra       $zero, $zero, 1
/* 6D6D8C 80222D1C 00000004 */  sllv      $zero, $zero, $zero
/* 6D6D90 80222D20 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D6D94 80222D24 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6D98 80222D28 00000009 */  jr        $zero
/* 6D6D9C 80222D2C FE363C80 */   sd       $s6, 0x3c80($s1)
/* 6D6DA0 80222D30 00000024 */  and       $zero, $zero, $zero
/* 6D6DA4 80222D34 00000002 */  srl       $zero, $zero, 0
/* 6D6DA8 80222D38 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D6DAC 80222D3C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6DB0 80222D40 00000043 */  sra       $zero, $zero, 1
/* 6D6DB4 80222D44 00000003 */  sra       $zero, $zero, 0
/* 6D6DB8 80222D48 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D6DBC 80222D4C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6DC0 80222D50 00000000 */  nop       
/* 6D6DC4 80222D54 00000043 */  sra       $zero, $zero, 1
/* 6D6DC8 80222D58 00000003 */  sra       $zero, $zero, 0
/* 6D6DCC 80222D5C 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D6DD0 80222D60 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D6DD4 80222D64 00000000 */  nop       
/* 6D6DD8 80222D68 00000043 */  sra       $zero, $zero, 1
/* 6D6DDC 80222D6C 00000003 */  sra       $zero, $zero, 0
/* 6D6DE0 80222D70 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D6DE4 80222D74 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6DE8 80222D78 00000000 */  nop       
/* 6D6DEC 80222D7C 00000043 */  sra       $zero, $zero, 1
/* 6D6DF0 80222D80 00000003 */  sra       $zero, $zero, 0
/* 6D6DF4 80222D84 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D6DF8 80222D88 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D6DFC 80222D8C 00000000 */  nop       
/* 6D6E00 80222D90 00000043 */  sra       $zero, $zero, 1
/* 6D6E04 80222D94 00000003 */  sra       $zero, $zero, 0
/* 6D6E08 80222D98 8027C548 */  lb        $a3, -0x3ab8($at)
/* 6D6E0C 80222D9C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6E10 80222DA0 00000000 */  nop       
/* 6D6E14 80222DA4 00000043 */  sra       $zero, $zero, 1
/* 6D6E18 80222DA8 00000002 */  srl       $zero, $zero, 0
/* 6D6E1C 80222DAC 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D6E20 80222DB0 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D6E24 80222DB4 00000043 */  sra       $zero, $zero, 1
/* 6D6E28 80222DB8 00000002 */  srl       $zero, $zero, 0
/* 6D6E2C 80222DBC 8024EB24 */  lb        $a0, -0x14dc($at)
/* 6D6E30 80222DC0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6E34 80222DC4 00000043 */  sra       $zero, $zero, 1
/* 6D6E38 80222DC8 00000002 */  srl       $zero, $zero, 0
/* 6D6E3C 80222DCC 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6D6E40 80222DD0 00000019 */  multu     $zero, $zero
/* 6D6E44 80222DD4 00000008 */  jr        $zero
/* 6D6E48 80222DD8 00000001 */   movf     $zero, $zero, $fcc0
/* 6D6E4C 80222DDC 00000019 */  multu     $zero, $zero
/* 6D6E50 80222DE0 00000043 */  sra       $zero, $zero, 1
/* 6D6E54 80222DE4 00000003 */  sra       $zero, $zero, 0
/* 6D6E58 80222DE8 8025385C */  lb        $a1, 0x385c($at)
/* 6D6E5C 80222DEC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6E60 80222DF0 000020D6 */  .byte     0x00, 0x00, 0x20, 0xd6
/* 6D6E64 80222DF4 0000000A */  movz      $zero, $zero, $zero
/* 6D6E68 80222DF8 00000002 */  srl       $zero, $zero, 0
/* 6D6E6C 80222DFC FBD3E280 */  bbit132   $fp, 0x13, .L8021B800
/* 6D6E70 80222E00 00000000 */   nop      
/* 6D6E74 80222E04 00000043 */  sra       $zero, $zero, 1
/* 6D6E78 80222E08 00000004 */  sllv      $zero, $zero, $zero
/* 6D6E7C 80222E0C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D6E80 80222E10 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6E84 80222E14 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6E88 80222E18 00560002 */  .byte     0x00, 0x56, 0x00, 0x02
/* 6D6E8C 80222E1C 00000043 */  sra       $zero, $zero, 1
/* 6D6E90 80222E20 00000004 */  sllv      $zero, $zero, $zero
/* 6D6E94 80222E24 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D6E98 80222E28 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D6E9C 80222E2C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6EA0 80222E30 00560002 */  .byte     0x00, 0x56, 0x00, 0x02
/* 6D6EA4 80222E34 00000043 */  sra       $zero, $zero, 1
/* 6D6EA8 80222E38 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D6EAC 80222E3C 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D6EB0 80222E40 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6EB4 80222E44 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6EB8 80222E48 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6EBC 80222E4C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D6EC0 80222E50 00000027 */  not       $zero, $zero
/* 6D6EC4 80222E54 00000002 */  srl       $zero, $zero, 0
/* 6D6EC8 80222E58 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6ECC 80222E5C 00000017 */  dsrav     $zero, $zero, $zero
/* 6D6ED0 80222E60 00000012 */  mflo      $zero
/* 6D6ED4 80222E64 00000000 */  nop       
/* 6D6ED8 80222E68 00000043 */  sra       $zero, $zero, 1
/* 6D6EDC 80222E6C 00000004 */  sllv      $zero, $zero, $zero
/* 6D6EE0 80222E70 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D6EE4 80222E74 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6EE8 80222E78 00000002 */  srl       $zero, $zero, 0
/* 6D6EEC 80222E7C 00570002 */  .byte     0x00, 0x57, 0x00, 0x02
/* 6D6EF0 80222E80 00000043 */  sra       $zero, $zero, 1
/* 6D6EF4 80222E84 00000004 */  sllv      $zero, $zero, $zero
/* 6D6EF8 80222E88 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D6EFC 80222E8C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D6F00 80222E90 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6F04 80222E94 00570002 */  .byte     0x00, 0x57, 0x00, 0x02
/* 6D6F08 80222E98 00000043 */  sra       $zero, $zero, 1
/* 6D6F0C 80222E9C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D6F10 80222EA0 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D6F14 80222EA4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6F18 80222EA8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6F1C 80222EAC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6F20 80222EB0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D6F24 80222EB4 00000027 */  not       $zero, $zero
/* 6D6F28 80222EB8 00000002 */  srl       $zero, $zero, 0
/* 6D6F2C 80222EBC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6F30 80222EC0 00000017 */  dsrav     $zero, $zero, $zero
/* 6D6F34 80222EC4 00000013 */  mtlo      $zero
/* 6D6F38 80222EC8 00000000 */  nop       
/* 6D6F3C 80222ECC 00000043 */  sra       $zero, $zero, 1
/* 6D6F40 80222ED0 0000000F */  sync      
/* 6D6F44 80222ED4 802D829C */  lb        $t5, -0x7d64($at)
/* 6D6F48 80222ED8 0000006B */  .byte     0x00, 0x00, 0x00, 0x6b
/* 6D6F4C 80222EDC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6F50 80222EE0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6F54 80222EE4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6F58 80222EE8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D6F5C 80222EEC F24A7E80 */  scd       $t2, 0x7e80($s2)
/* 6D6F60 80222EF0 0000001E */  ddiv      $zero, $zero, $zero
/* 6D6F64 80222EF4 00000000 */  nop       
/* 6D6F68 80222EF8 00000000 */  nop       
/* 6D6F6C 80222EFC 00000000 */  nop       
/* 6D6F70 80222F00 00000000 */  nop       
/* 6D6F74 80222F04 00000000 */  nop       
/* 6D6F78 80222F08 00000000 */  nop       
/* 6D6F7C 80222F0C 00000000 */  nop       
/* 6D6F80 80222F10 00000008 */  jr        $zero
/* 6D6F84 80222F14 00000001 */   movf     $zero, $zero, $fcc0
/* 6D6F88 80222F18 0000000A */  movz      $zero, $zero, $zero
/* 6D6F8C 80222F1C 00000043 */  sra       $zero, $zero, 1
/* 6D6F90 80222F20 00000003 */  sra       $zero, $zero, 0
/* 6D6F94 80222F24 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D6F98 80222F28 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6F9C 80222F2C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6FA0 80222F30 00000043 */  sra       $zero, $zero, 1
/* 6D6FA4 80222F34 00000003 */  sra       $zero, $zero, 0
/* 6D6FA8 80222F38 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D6FAC 80222F3C FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D6FB0 80222F40 00000001 */  movf      $zero, $zero, $fcc0
/* 6D6FB4 80222F44 00000008 */  jr        $zero
/* 6D6FB8 80222F48 00000001 */   movf     $zero, $zero, $fcc0
/* 6D6FBC 80222F4C 0000001E */  ddiv      $zero, $zero, $zero
/* 6D6FC0 80222F50 00000043 */  sra       $zero, $zero, 1
/* 6D6FC4 80222F54 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D6FC8 80222F58 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D6FCC 80222F5C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D6FD0 80222F60 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D6FD4 80222F64 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D6FD8 80222F68 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D6FDC 80222F6C 00000027 */  not       $zero, $zero
/* 6D6FE0 80222F70 00000002 */  srl       $zero, $zero, 0
/* 6D6FE4 80222F74 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D6FE8 80222F78 FFFFFFFD */  sd        $ra, -3($ra)
/* 6D6FEC 80222F7C 00000043 */  sra       $zero, $zero, 1
/* 6D6FF0 80222F80 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D6FF4 80222F84 8026AE40 */  lb        $a2, -0x51c0($at)
/* 6D6FF8 80222F88 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D6FFC 80222F8C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7000 80222F90 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D7004 80222F94 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D7008 80222F98 00000024 */  and       $zero, $zero, $zero
/* 6D700C 80222F9C 00000002 */  srl       $zero, $zero, 0
/* 6D7010 80222FA0 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D7014 80222FA4 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D7018 80222FA8 00000008 */  jr        $zero
/* 6D701C 80222FAC 00000001 */   movf     $zero, $zero, $fcc0
/* 6D7020 80222FB0 0000000F */  sync      
/* 6D7024 80222FB4 00000043 */  sra       $zero, $zero, 1
/* 6D7028 80222FB8 00000002 */  srl       $zero, $zero, 0
/* 6D702C 80222FBC 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D7030 80222FC0 00000002 */  srl       $zero, $zero, 0
/* 6D7034 80222FC4 00000043 */  sra       $zero, $zero, 1
/* 6D7038 80222FC8 00000002 */  srl       $zero, $zero, 0
/* 6D703C 80222FCC 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6D7040 80222FD0 0000001E */  ddiv      $zero, $zero, $zero
/* 6D7044 80222FD4 00000043 */  sra       $zero, $zero, 1
/* 6D7048 80222FD8 00000003 */  sra       $zero, $zero, 0
/* 6D704C 80222FDC 8025385C */  lb        $a1, 0x385c($at)
/* 6D7050 80222FE0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7054 80222FE4 000020D7 */  .byte     0x00, 0x00, 0x20, 0xd7
/* 6D7058 80222FE8 00000043 */  sra       $zero, $zero, 1
/* 6D705C 80222FEC 00000003 */  sra       $zero, $zero, 0
/* 6D7060 80222FF0 8025385C */  lb        $a1, 0x385c($at)
/* 6D7064 80222FF4 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D7068 80222FF8 000020D7 */  .byte     0x00, 0x00, 0x20, 0xd7
/* 6D706C 80222FFC 00000043 */  sra       $zero, $zero, 1
/* 6D7070 80223000 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D7074 80223004 8026D010 */  lb        $a2, -0x2ff0($at)
/* 6D7078 80223008 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D707C 8022300C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7080 80223010 00800000 */  .byte     0x00, 0x80, 0x00, 0x00
/* 6D7084 80223014 00000000 */  nop       
/* 6D7088 80223018 00000043 */  sra       $zero, $zero, 1
/* 6D708C 8022301C 00000003 */  sra       $zero, $zero, 0
/* 6D7090 80223020 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D7094 80223024 000003E8 */  .byte     0x00, 0x00, 0x03, 0xe8
/* 6D7098 80223028 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D709C 8022302C 0000000C */  syscall   
/* 6D70A0 80223030 00000002 */  srl       $zero, $zero, 0
/* 6D70A4 80223034 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D70A8 80223038 000001F4 */  teq       $zero, $zero, 7
/* 6D70AC 8022303C 00000043 */  sra       $zero, $zero, 1
/* 6D70B0 80223040 00000003 */  sra       $zero, $zero, 0
/* 6D70B4 80223044 8026B654 */  lb        $a2, -0x49ac($at)
/* 6D70B8 80223048 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D70BC 8022304C F24A8280 */  scd       $t2, -0x7d80($s2)
/* 6D70C0 80223050 00000046 */  rotrv     $zero, $zero, $zero
/* 6D70C4 80223054 00000001 */  movf      $zero, $zero, $fcc0
/* 6D70C8 80223058 80222654 */  lb        $v0, 0x2654($at)
/* 6D70CC 8022305C 00000043 */  sra       $zero, $zero, 1
/* 6D70D0 80223060 00000003 */  sra       $zero, $zero, 0
/* 6D70D4 80223064 80269F94 */  lb        $a2, -0x606c($at)
/* 6D70D8 80223068 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D70DC 8022306C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D70E0 80223070 00000043 */  sra       $zero, $zero, 1
/* 6D70E4 80223074 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D70E8 80223078 8027B624 */  lb        $a3, -0x49dc($at)
/* 6D70EC 8022307C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D70F0 80223080 00000000 */  nop       
/* 6D70F4 80223084 00000000 */  nop       
/* 6D70F8 80223088 00000000 */  nop       
/* 6D70FC 8022308C 00000012 */  mflo      $zero
/* 6D7100 80223090 00000000 */  nop       
/* 6D7104 80223094 00000043 */  sra       $zero, $zero, 1
/* 6D7108 80223098 00000003 */  sra       $zero, $zero, 0
/* 6D710C 8022309C 8026B654 */  lb        $a2, -0x49ac($at)
/* 6D7110 802230A0 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D7114 802230A4 F24A8280 */  scd       $t2, -0x7d80($s2)
/* 6D7118 802230A8 00000046 */  rotrv     $zero, $zero, $zero
/* 6D711C 802230AC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7120 802230B0 80222654 */  lb        $v0, 0x2654($at)
/* 6D7124 802230B4 00000043 */  sra       $zero, $zero, 1
/* 6D7128 802230B8 00000003 */  sra       $zero, $zero, 0
/* 6D712C 802230BC 80269F94 */  lb        $a2, -0x606c($at)
/* 6D7130 802230C0 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D7134 802230C4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7138 802230C8 00000043 */  sra       $zero, $zero, 1
/* 6D713C 802230CC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D7140 802230D0 8027B624 */  lb        $a3, -0x49dc($at)
/* 6D7144 802230D4 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D7148 802230D8 00000000 */  nop       
/* 6D714C 802230DC 00000000 */  nop       
/* 6D7150 802230E0 00000000 */  nop       
/* 6D7154 802230E4 00000013 */  mtlo      $zero
/* 6D7158 802230E8 00000000 */  nop       
/* 6D715C 802230EC 00000043 */  sra       $zero, $zero, 1
/* 6D7160 802230F0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D7164 802230F4 8026D010 */  lb        $a2, -0x2ff0($at)
/* 6D7168 802230F8 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D716C 802230FC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7170 80223100 00800000 */  .byte     0x00, 0x80, 0x00, 0x00
/* 6D7174 80223104 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7178 80223108 00000043 */  sra       $zero, $zero, 1
/* 6D717C 8022310C 00000003 */  sra       $zero, $zero, 0
/* 6D7180 80223110 8027C6A0 */  lb        $a3, -0x3960($at)
/* 6D7184 80223114 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7188 80223118 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D718C 8022311C 00000043 */  sra       $zero, $zero, 1
/* 6D7190 80223120 00000003 */  sra       $zero, $zero, 0
/* 6D7194 80223124 8027C5C8 */  lb        $a3, -0x3a38($at)
/* 6D7198 80223128 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D719C 8022312C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D71A0 80223130 00000043 */  sra       $zero, $zero, 1
/* 6D71A4 80223134 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D71A8 80223138 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D71AC 8022313C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D71B0 80223140 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D71B4 80223144 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D71B8 80223148 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D71BC 8022314C 00000043 */  sra       $zero, $zero, 1
/* 6D71C0 80223150 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D71C4 80223154 8026A1EC */  lb        $a2, -0x5e14($at)
/* 6D71C8 80223158 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D71CC 8022315C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D71D0 80223160 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D71D4 80223164 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D71D8 80223168 00000043 */  sra       $zero, $zero, 1
/* 6D71DC 8022316C 00000002 */  srl       $zero, $zero, 0
/* 6D71E0 80223170 8026D664 */  lb        $a2, -0x299c($at)
/* 6D71E4 80223174 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D71E8 80223178 00000043 */  sra       $zero, $zero, 1
/* 6D71EC 8022317C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D71F0 80223180 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D71F4 80223184 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D71F8 80223188 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D71FC 8022318C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D7200 80223190 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D7204 80223194 00000043 */  sra       $zero, $zero, 1
/* 6D7208 80223198 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D720C 8022319C 8026A1EC */  lb        $a2, -0x5e14($at)
/* 6D7210 802231A0 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D7214 802231A4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7218 802231A8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D721C 802231AC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D7220 802231B0 00000043 */  sra       $zero, $zero, 1
/* 6D7224 802231B4 00000002 */  srl       $zero, $zero, 0
/* 6D7228 802231B8 8026D664 */  lb        $a2, -0x299c($at)
/* 6D722C 802231BC FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D7230 802231C0 0000000A */  movz      $zero, $zero, $zero
/* 6D7234 802231C4 00000002 */  srl       $zero, $zero, 0
/* 6D7238 802231C8 FBD3E280 */  bbit132   $fp, 0x13, .L8021BBCC
/* 6D723C 802231CC 00000000 */   nop      
/* 6D7240 802231D0 00000043 */  sra       $zero, $zero, 1
/* 6D7244 802231D4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D7248 802231D8 8026D3C8 */  lb        $a2, -0x2c38($at)
/* 6D724C 802231DC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7250 802231E0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7254 802231E4 00400000 */  .byte     0x00, 0x40, 0x00, 0x00
/* 6D7258 802231E8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D725C 802231EC 00000012 */  mflo      $zero
/* 6D7260 802231F0 00000000 */  nop       
/* 6D7264 802231F4 00000043 */  sra       $zero, $zero, 1
/* 6D7268 802231F8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D726C 802231FC 8026D3C8 */  lb        $a2, -0x2c38($at)
/* 6D7270 80223200 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7274 80223204 00000002 */  srl       $zero, $zero, 0
/* 6D7278 80223208 00400000 */  .byte     0x00, 0x40, 0x00, 0x00
/* 6D727C 8022320C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7280 80223210 00000013 */  mtlo      $zero
/* 6D7284 80223214 00000000 */  nop       
/* 6D7288 80223218 0000000A */  movz      $zero, $zero, $zero
/* 6D728C 8022321C 00000002 */  srl       $zero, $zero, 0
/* 6D7290 80223220 FBD3E280 */  bbit132   $fp, 0x13, .L8021BC24
/* 6D7294 80223224 00000000 */   nop      
/* 6D7298 80223228 00000043 */  sra       $zero, $zero, 1
/* 6D729C 8022322C 00000004 */  sllv      $zero, $zero, $zero
/* 6D72A0 80223230 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D72A4 80223234 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D72A8 80223238 00000001 */  movf      $zero, $zero, $fcc0
/* 6D72AC 8022323C 00560001 */  .byte     0x00, 0x56, 0x00, 0x01
/* 6D72B0 80223240 00000043 */  sra       $zero, $zero, 1
/* 6D72B4 80223244 00000004 */  sllv      $zero, $zero, $zero
/* 6D72B8 80223248 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D72BC 8022324C FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D72C0 80223250 00000001 */  movf      $zero, $zero, $fcc0
/* 6D72C4 80223254 00560001 */  .byte     0x00, 0x56, 0x00, 0x01
/* 6D72C8 80223258 00000012 */  mflo      $zero
/* 6D72CC 8022325C 00000000 */  nop       
/* 6D72D0 80223260 00000043 */  sra       $zero, $zero, 1
/* 6D72D4 80223264 00000004 */  sllv      $zero, $zero, $zero
/* 6D72D8 80223268 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D72DC 8022326C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D72E0 80223270 00000002 */  srl       $zero, $zero, 0
/* 6D72E4 80223274 00570001 */  .byte     0x00, 0x57, 0x00, 0x01
/* 6D72E8 80223278 00000043 */  sra       $zero, $zero, 1
/* 6D72EC 8022327C 00000004 */  sllv      $zero, $zero, $zero
/* 6D72F0 80223280 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D72F4 80223284 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D72F8 80223288 00000001 */  movf      $zero, $zero, $fcc0
/* 6D72FC 8022328C 00570001 */  .byte     0x00, 0x57, 0x00, 0x01
/* 6D7300 80223290 00000013 */  mtlo      $zero
/* 6D7304 80223294 00000000 */  nop       
/* 6D7308 80223298 00000043 */  sra       $zero, $zero, 1
/* 6D730C 8022329C 00000003 */  sra       $zero, $zero, 0
/* 6D7310 802232A0 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D7314 802232A4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7318 802232A8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D731C 802232AC 00000043 */  sra       $zero, $zero, 1
/* 6D7320 802232B0 00000003 */  sra       $zero, $zero, 0
/* 6D7324 802232B4 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D7328 802232B8 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D732C 802232BC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7330 802232C0 00000002 */  srl       $zero, $zero, 0
/* 6D7334 802232C4 00000000 */  nop       
/* 6D7338 802232C8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D733C 802232CC 00000000 */  nop       
/* 6D7340 802232D0 00000024 */  and       $zero, $zero, $zero
/* 6D7344 802232D4 00000002 */  srl       $zero, $zero, 0
/* 6D7348 802232D8 FBD3E280 */  bbit132   $fp, 0x13, .L8021BCDC
/* 6D734C 802232DC 00000000 */   nop      
/* 6D7350 802232E0 00000003 */  sra       $zero, $zero, 0
/* 6D7354 802232E4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7358 802232E8 0000000A */  movz      $zero, $zero, $zero
/* 6D735C 802232EC 00000043 */  sra       $zero, $zero, 1
/* 6D7360 802232F0 00000002 */  srl       $zero, $zero, 0
/* 6D7364 802232F4 8026E310 */  lb        $a2, -0x1cf0($at)
/* 6D7368 802232F8 00008002 */  srl       $s0, $zero, 0
/* 6D736C 802232FC 00000043 */  sra       $zero, $zero, 1
/* 6D7370 80223300 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7374 80223304 8026E354 */  lb        $a2, -0x1cac($at)
/* 6D7378 80223308 00000003 */  sra       $zero, $zero, 0
/* 6D737C 8022330C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7380 80223310 00000000 */  nop       
/* 6D7384 80223314 00000043 */  sra       $zero, $zero, 1
/* 6D7388 80223318 00000003 */  sra       $zero, $zero, 0
/* 6D738C 8022331C 8026E8AC */  lb        $a2, -0x1754($at)
/* 6D7390 80223320 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7394 80223324 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D7398 80223328 00000043 */  sra       $zero, $zero, 1
/* 6D739C 8022332C 00000003 */  sra       $zero, $zero, 0
/* 6D73A0 80223330 8026A0D4 */  lb        $a2, -0x5f2c($at)
/* 6D73A4 80223334 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D73A8 80223338 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D73AC 8022333C 00000043 */  sra       $zero, $zero, 1
/* 6D73B0 80223340 00000003 */  sra       $zero, $zero, 0
/* 6D73B4 80223344 8026F694 */  lb        $a2, -0x96c($at)
/* 6D73B8 80223348 00000002 */  srl       $zero, $zero, 0
/* 6D73BC 8022334C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D73C0 80223350 0000000D */  break     
/* 6D73C4 80223354 00000002 */   srl      $zero, $zero, 0
/* 6D73C8 80223358 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D73CC 8022335C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D73D0 80223360 00000043 */  sra       $zero, $zero, 1
/* 6D73D4 80223364 00000003 */  sra       $zero, $zero, 0
/* 6D73D8 80223368 80218588 */  lb        $at, -0x7a78($at)
/* 6D73DC 8022336C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D73E0 80223370 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D73E4 80223374 0000000A */  movz      $zero, $zero, $zero
/* 6D73E8 80223378 00000002 */  srl       $zero, $zero, 0
/* 6D73EC 8022337C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D73F0 80223380 00000000 */  nop       
/* 6D73F4 80223384 00000043 */  sra       $zero, $zero, 1
/* 6D73F8 80223388 00000003 */  sra       $zero, $zero, 0
/* 6D73FC 8022338C 8026FC04 */  lb        $a2, -0x3fc($at)
/* 6D7400 80223390 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7404 80223394 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D7408 80223398 0000000C */  syscall   
/* 6D740C 8022339C 00000002 */  srl       $zero, $zero, 0
/* 6D7410 802233A0 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D7414 802233A4 00000003 */  sra       $zero, $zero, 0
/* 6D7418 802233A8 00000024 */  and       $zero, $zero, $zero
/* 6D741C 802233AC 00000002 */  srl       $zero, $zero, 0
/* 6D7420 802233B0 FE363C88 */  sd        $s6, 0x3c88($s1)
/* 6D7424 802233B4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7428 802233B8 00000043 */  sra       $zero, $zero, 1
/* 6D742C 802233BC 00000003 */  sra       $zero, $zero, 0
/* 6D7430 802233C0 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D7434 802233C4 00000002 */  srl       $zero, $zero, 0
/* 6D7438 802233C8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D743C 802233CC 00000004 */  sllv      $zero, $zero, $zero
/* 6D7440 802233D0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7444 802233D4 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6D7448 802233D8 00000013 */  mtlo      $zero
/* 6D744C 802233DC 00000000 */  nop       
/* 6D7450 802233E0 00000013 */  mtlo      $zero
/* 6D7454 802233E4 00000000 */  nop       
/* 6D7458 802233E8 00000013 */  mtlo      $zero
/* 6D745C 802233EC 00000000 */  nop       
/* 6D7460 802233F0 00000043 */  sra       $zero, $zero, 1
/* 6D7464 802233F4 00000003 */  sra       $zero, $zero, 0
/* 6D7468 802233F8 8026E414 */  lb        $a2, -0x1bec($at)
/* 6D746C 802233FC 00000000 */  nop       
/* 6D7470 80223400 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7474 80223404 0000000B */  movn      $zero, $zero, $zero
/* 6D7478 80223408 00000002 */  srl       $zero, $zero, 0
/* 6D747C 8022340C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7480 80223410 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D7484 80223414 00000004 */  sllv      $zero, $zero, $zero
/* 6D7488 80223418 00000001 */  movf      $zero, $zero, $fcc0
/* 6D748C 8022341C 00000000 */  nop       
/* 6D7490 80223420 00000013 */  mtlo      $zero
/* 6D7494 80223424 00000000 */  nop       
/* 6D7498 80223428 0000000A */  movz      $zero, $zero, $zero
/* 6D749C 8022342C 00000002 */  srl       $zero, $zero, 0
/* 6D74A0 80223430 FBD3E280 */  bbit132   $fp, 0x13, .L8021BE34
/* 6D74A4 80223434 00000000 */   nop      
/* 6D74A8 80223438 00000024 */  and       $zero, $zero, $zero
/* 6D74AC 8022343C 00000002 */  srl       $zero, $zero, 0
/* 6D74B0 80223440 FBD3E280 */  bbit132   $fp, 0x13, .L8021BE44
/* 6D74B4 80223444 00000001 */   movf     $zero, $zero, $fcc0
/* 6D74B8 80223448 00000043 */  sra       $zero, $zero, 1
/* 6D74BC 8022344C 00000003 */  sra       $zero, $zero, 0
/* 6D74C0 80223450 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D74C4 80223454 00000002 */  srl       $zero, $zero, 0
/* 6D74C8 80223458 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D74CC 8022345C 00000004 */  sllv      $zero, $zero, $zero
/* 6D74D0 80223460 00000001 */  movf      $zero, $zero, $fcc0
/* 6D74D4 80223464 0000000A */  movz      $zero, $zero, $zero
/* 6D74D8 80223468 00000013 */  mtlo      $zero
/* 6D74DC 8022346C 00000000 */  nop       
/* 6D74E0 80223470 00000043 */  sra       $zero, $zero, 1
/* 6D74E4 80223474 00000004 */  sllv      $zero, $zero, $zero
/* 6D74E8 80223478 8026A14C */  lb        $a2, -0x5eb4($at)
/* 6D74EC 8022347C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D74F0 80223480 00008002 */  srl       $s0, $zero, 0
/* 6D74F4 80223484 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D74F8 80223488 0000000A */  movz      $zero, $zero, $zero
/* 6D74FC 8022348C 00000002 */  srl       $zero, $zero, 0
/* 6D7500 80223490 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7504 80223494 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7508 80223498 00000046 */  rotrv     $zero, $zero, $zero
/* 6D750C 8022349C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7510 802234A0 8021F39C */  lb        $at, -0xc64($at)
/* 6D7514 802234A4 00000002 */  srl       $zero, $zero, 0
/* 6D7518 802234A8 00000000 */  nop       
/* 6D751C 802234AC 00000013 */  mtlo      $zero
/* 6D7520 802234B0 00000000 */  nop       
/* 6D7524 802234B4 00000046 */  rotrv     $zero, $zero, $zero
/* 6D7528 802234B8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D752C 802234BC 8022179C */  lb        $v0, 0x179c($at)
/* 6D7530 802234C0 00000002 */  srl       $zero, $zero, 0
/* 6D7534 802234C4 00000000 */  nop       
/* 6D7538 802234C8 00000003 */  sra       $zero, $zero, 0
/* 6D753C 802234CC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7540 802234D0 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6D7544 802234D4 00000043 */  sra       $zero, $zero, 1
/* 6D7548 802234D8 00000004 */  sllv      $zero, $zero, $zero
/* 6D754C 802234DC 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D7550 802234E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7554 802234E4 0000000A */  movz      $zero, $zero, $zero
/* 6D7558 802234E8 00000000 */  nop       
/* 6D755C 802234EC 00000043 */  sra       $zero, $zero, 1
/* 6D7560 802234F0 00000004 */  sllv      $zero, $zero, $zero
/* 6D7564 802234F4 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D7568 802234F8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D756C 802234FC 0000000B */  movn      $zero, $zero, $zero
/* 6D7570 80223500 00000004 */  sllv      $zero, $zero, $zero
/* 6D7574 80223504 00000043 */  sra       $zero, $zero, 1
/* 6D7578 80223508 00000004 */  sllv      $zero, $zero, $zero
/* 6D757C 8022350C 8026C0D4 */  lb        $a2, -0x3f2c($at)
/* 6D7580 80223510 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7584 80223514 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D7588 80223518 00000001 */  movf      $zero, $zero, $fcc0
/* 6D758C 8022351C 00000043 */  sra       $zero, $zero, 1
/* 6D7590 80223520 00000003 */  sra       $zero, $zero, 0
/* 6D7594 80223524 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D7598 80223528 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D759C 8022352C 00000000 */  nop       
/* 6D75A0 80223530 00000043 */  sra       $zero, $zero, 1
/* 6D75A4 80223534 00000003 */  sra       $zero, $zero, 0
/* 6D75A8 80223538 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D75AC 8022353C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D75B0 80223540 00000000 */  nop       
/* 6D75B4 80223544 00000043 */  sra       $zero, $zero, 1
/* 6D75B8 80223548 00000003 */  sra       $zero, $zero, 0
/* 6D75BC 8022354C 8027C548 */  lb        $a3, -0x3ab8($at)
/* 6D75C0 80223550 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D75C4 80223554 00000000 */  nop       
/* 6D75C8 80223558 00000043 */  sra       $zero, $zero, 1
/* 6D75CC 8022355C 00000002 */  srl       $zero, $zero, 0
/* 6D75D0 80223560 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D75D4 80223564 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D75D8 80223568 00000043 */  sra       $zero, $zero, 1
/* 6D75DC 8022356C 00000002 */  srl       $zero, $zero, 0
/* 6D75E0 80223570 8024EB24 */  lb        $a0, -0x14dc($at)
/* 6D75E4 80223574 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D75E8 80223578 00000043 */  sra       $zero, $zero, 1
/* 6D75EC 8022357C 00000002 */  srl       $zero, $zero, 0
/* 6D75F0 80223580 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6D75F4 80223584 0000000F */  sync      
/* 6D75F8 80223588 00000008 */  jr        $zero
/* 6D75FC 8022358C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D7600 80223590 0000000F */  sync      
/* 6D7604 80223594 00000043 */  sra       $zero, $zero, 1
/* 6D7608 80223598 00000003 */  sra       $zero, $zero, 0
/* 6D760C 8022359C 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D7610 802235A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7614 802235A4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7618 802235A8 00000011 */  mthi      $zero
/* 6D761C 802235AC 00000002 */  srl       $zero, $zero, 0
/* 6D7620 802235B0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7624 802235B4 00000200 */  sll       $zero, $zero, 8
/* 6D7628 802235B8 00000043 */  sra       $zero, $zero, 1
/* 6D762C 802235BC 00000004 */  sllv      $zero, $zero, $zero
/* 6D7630 802235C0 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D7634 802235C4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7638 802235C8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D763C 802235CC 00560002 */  .byte     0x00, 0x56, 0x00, 0x02
/* 6D7640 802235D0 00000012 */  mflo      $zero
/* 6D7644 802235D4 00000000 */  nop       
/* 6D7648 802235D8 00000043 */  sra       $zero, $zero, 1
/* 6D764C 802235DC 00000004 */  sllv      $zero, $zero, $zero
/* 6D7650 802235E0 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D7654 802235E4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7658 802235E8 00000002 */  srl       $zero, $zero, 0
/* 6D765C 802235EC 00570002 */  .byte     0x00, 0x57, 0x00, 0x02
/* 6D7660 802235F0 00000013 */  mtlo      $zero
/* 6D7664 802235F4 00000000 */  nop       
/* 6D7668 802235F8 00000008 */  jr        $zero
/* 6D766C 802235FC 00000001 */   movf     $zero, $zero, $fcc0
/* 6D7670 80223600 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D7674 80223604 00000043 */  sra       $zero, $zero, 1
/* 6D7678 80223608 00000003 */  sra       $zero, $zero, 0
/* 6D767C 8022360C 8025385C */  lb        $a1, 0x385c($at)
/* 6D7680 80223610 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7684 80223614 000020D4 */  .byte     0x00, 0x00, 0x20, 0xd4
/* 6D7688 80223618 00000043 */  sra       $zero, $zero, 1
/* 6D768C 8022361C 00000003 */  sra       $zero, $zero, 0
/* 6D7690 80223620 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D7694 80223624 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7698 80223628 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D769C 8022362C 00000011 */  mthi      $zero
/* 6D76A0 80223630 00000002 */  srl       $zero, $zero, 0
/* 6D76A4 80223634 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D76A8 80223638 00000200 */  sll       $zero, $zero, 8
/* 6D76AC 8022363C 00000043 */  sra       $zero, $zero, 1
/* 6D76B0 80223640 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D76B4 80223644 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D76B8 80223648 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D76BC 8022364C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D76C0 80223650 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D76C4 80223654 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D76C8 80223658 00000043 */  sra       $zero, $zero, 1
/* 6D76CC 8022365C 00000003 */  sra       $zero, $zero, 0
/* 6D76D0 80223660 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D76D4 80223664 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D76D8 80223668 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D76DC 8022366C 00000010 */  mfhi      $zero
/* 6D76E0 80223670 00000002 */  srl       $zero, $zero, 0
/* 6D76E4 80223674 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D76E8 80223678 00080000 */  sll       $zero, $t0, 0
/* 6D76EC 8022367C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D76F0 80223680 00000002 */  srl       $zero, $zero, 0
/* 6D76F4 80223684 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D76F8 80223688 00000006 */  srlv      $zero, $zero, $zero
/* 6D76FC 8022368C 00000027 */  not       $zero, $zero
/* 6D7700 80223690 00000002 */  srl       $zero, $zero, 0
/* 6D7704 80223694 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D7708 80223698 0000000C */  syscall   
/* 6D770C 8022369C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D7710 802236A0 00000002 */  srl       $zero, $zero, 0
/* 6D7714 802236A4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D7718 802236A8 00000002 */  srl       $zero, $zero, 0
/* 6D771C 802236AC 00000043 */  sra       $zero, $zero, 1
/* 6D7720 802236B0 0000000F */  sync      
/* 6D7724 802236B4 802D829C */  lb        $t5, -0x7d64($at)
/* 6D7728 802236B8 00000033 */  tltu      $zero, $zero
/* 6D772C 802236BC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D7730 802236C0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7734 802236C4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D7738 802236C8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D773C 802236CC F24A7AFB */  scd       $t2, 0x7afb($s2)
/* 6D7740 802236D0 0000001E */  ddiv      $zero, $zero, $zero
/* 6D7744 802236D4 00000000 */  nop       
/* 6D7748 802236D8 00000000 */  nop       
/* 6D774C 802236DC 00000000 */  nop       
/* 6D7750 802236E0 00000000 */  nop       
/* 6D7754 802236E4 00000000 */  nop       
/* 6D7758 802236E8 00000000 */  nop       
/* 6D775C 802236EC 00000000 */  nop       
/* 6D7760 802236F0 00000012 */  mflo      $zero
/* 6D7764 802236F4 00000000 */  nop       
/* 6D7768 802236F8 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D776C 802236FC 00000002 */  srl       $zero, $zero, 0
/* 6D7770 80223700 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7774 80223704 00000010 */  mfhi      $zero
/* 6D7778 80223708 00000027 */  not       $zero, $zero
/* 6D777C 8022370C 00000002 */  srl       $zero, $zero, 0
/* 6D7780 80223710 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D7784 80223714 0000001F */  ddivu     $zero, $zero, $zero
/* 6D7788 80223718 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D778C 8022371C 00000002 */  srl       $zero, $zero, 0
/* 6D7790 80223720 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D7794 80223724 00000002 */  srl       $zero, $zero, 0
/* 6D7798 80223728 00000043 */  sra       $zero, $zero, 1
/* 6D779C 8022372C 0000000F */  sync      
/* 6D77A0 80223730 802D829C */  lb        $t5, -0x7d64($at)
/* 6D77A4 80223734 00000033 */  tltu      $zero, $zero
/* 6D77A8 80223738 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D77AC 8022373C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D77B0 80223740 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D77B4 80223744 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D77B8 80223748 F24A7BB4 */  scd       $t2, 0x7bb4($s2)
/* 6D77BC 8022374C 0000001E */  ddiv      $zero, $zero, $zero
/* 6D77C0 80223750 00000000 */  nop       
/* 6D77C4 80223754 00000000 */  nop       
/* 6D77C8 80223758 00000000 */  nop       
/* 6D77CC 8022375C 00000000 */  nop       
/* 6D77D0 80223760 00000000 */  nop       
/* 6D77D4 80223764 00000000 */  nop       
/* 6D77D8 80223768 00000000 */  nop       
/* 6D77DC 8022376C 00000013 */  mtlo      $zero
/* 6D77E0 80223770 00000000 */  nop       
/* 6D77E4 80223774 00000012 */  mflo      $zero
/* 6D77E8 80223778 00000000 */  nop       
/* 6D77EC 8022377C 00000043 */  sra       $zero, $zero, 1
/* 6D77F0 80223780 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D77F4 80223784 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D77F8 80223788 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D77FC 8022378C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7800 80223790 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D7804 80223794 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D7808 80223798 00000043 */  sra       $zero, $zero, 1
/* 6D780C 8022379C 00000003 */  sra       $zero, $zero, 0
/* 6D7810 802237A0 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D7814 802237A4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7818 802237A8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D781C 802237AC 00000010 */  mfhi      $zero
/* 6D7820 802237B0 00000002 */  srl       $zero, $zero, 0
/* 6D7824 802237B4 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D7828 802237B8 00080000 */  sll       $zero, $t0, 0
/* 6D782C 802237BC 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D7830 802237C0 00000002 */  srl       $zero, $zero, 0
/* 6D7834 802237C4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7838 802237C8 0000000C */  syscall   
/* 6D783C 802237CC 00000027 */  not       $zero, $zero
/* 6D7840 802237D0 00000002 */  srl       $zero, $zero, 0
/* 6D7844 802237D4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D7848 802237D8 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D784C 802237DC 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D7850 802237E0 00000002 */  srl       $zero, $zero, 0
/* 6D7854 802237E4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D7858 802237E8 00000002 */  srl       $zero, $zero, 0
/* 6D785C 802237EC 00000043 */  sra       $zero, $zero, 1
/* 6D7860 802237F0 0000000F */  sync      
/* 6D7864 802237F4 802D829C */  lb        $t5, -0x7d64($at)
/* 6D7868 802237F8 00000033 */  tltu      $zero, $zero
/* 6D786C 802237FC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D7870 80223800 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7874 80223804 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D7878 80223808 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D787C 8022380C F24A7AFB */  scd       $t2, 0x7afb($s2)
/* 6D7880 80223810 0000001E */  ddiv      $zero, $zero, $zero
/* 6D7884 80223814 00000000 */  nop       
/* 6D7888 80223818 00000000 */  nop       
/* 6D788C 8022381C 00000000 */  nop       
/* 6D7890 80223820 00000000 */  nop       
/* 6D7894 80223824 00000000 */  nop       
/* 6D7898 80223828 00000000 */  nop       
/* 6D789C 8022382C 00000000 */  nop       
/* 6D78A0 80223830 00000012 */  mflo      $zero
/* 6D78A4 80223834 00000000 */  nop       
/* 6D78A8 80223838 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D78AC 8022383C 00000002 */  srl       $zero, $zero, 0
/* 6D78B0 80223840 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D78B4 80223844 0000001E */  ddiv      $zero, $zero, $zero
/* 6D78B8 80223848 00000027 */  not       $zero, $zero
/* 6D78BC 8022384C 00000002 */  srl       $zero, $zero, 0
/* 6D78C0 80223850 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D78C4 80223854 00000024 */  and       $zero, $zero, $zero
/* 6D78C8 80223858 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D78CC 8022385C 00000002 */  srl       $zero, $zero, 0
/* 6D78D0 80223860 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D78D4 80223864 00000002 */  srl       $zero, $zero, 0
/* 6D78D8 80223868 00000043 */  sra       $zero, $zero, 1
/* 6D78DC 8022386C 0000000F */  sync      
/* 6D78E0 80223870 802D829C */  lb        $t5, -0x7d64($at)
/* 6D78E4 80223874 00000033 */  tltu      $zero, $zero
/* 6D78E8 80223878 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D78EC 8022387C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D78F0 80223880 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D78F4 80223884 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D78F8 80223888 F24A7BB4 */  scd       $t2, 0x7bb4($s2)
/* 6D78FC 8022388C 0000001E */  ddiv      $zero, $zero, $zero
/* 6D7900 80223890 00000000 */  nop       
/* 6D7904 80223894 00000000 */  nop       
/* 6D7908 80223898 00000000 */  nop       
/* 6D790C 8022389C 00000000 */  nop       
/* 6D7910 802238A0 00000000 */  nop       
/* 6D7914 802238A4 00000000 */  nop       
/* 6D7918 802238A8 00000000 */  nop       
/* 6D791C 802238AC 00000013 */  mtlo      $zero
/* 6D7920 802238B0 00000000 */  nop       
/* 6D7924 802238B4 00000013 */  mtlo      $zero
/* 6D7928 802238B8 00000000 */  nop       
/* 6D792C 802238BC 00000008 */  jr        $zero
/* 6D7930 802238C0 00000001 */   movf     $zero, $zero, $fcc0
/* 6D7934 802238C4 0000001E */  ddiv      $zero, $zero, $zero
/* 6D7938 802238C8 00000043 */  sra       $zero, $zero, 1
/* 6D793C 802238CC 00000003 */  sra       $zero, $zero, 0
/* 6D7940 802238D0 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D7944 802238D4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7948 802238D8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D794C 802238DC 00000011 */  mthi      $zero
/* 6D7950 802238E0 00000002 */  srl       $zero, $zero, 0
/* 6D7954 802238E4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7958 802238E8 00000200 */  sll       $zero, $zero, 8
/* 6D795C 802238EC 00000043 */  sra       $zero, $zero, 1
/* 6D7960 802238F0 00000004 */  sllv      $zero, $zero, $zero
/* 6D7964 802238F4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D7968 802238F8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D796C 802238FC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7970 80223900 00560001 */  .byte     0x00, 0x56, 0x00, 0x01
/* 6D7974 80223904 00000012 */  mflo      $zero
/* 6D7978 80223908 00000000 */  nop       
/* 6D797C 8022390C 00000043 */  sra       $zero, $zero, 1
/* 6D7980 80223910 00000004 */  sllv      $zero, $zero, $zero
/* 6D7984 80223914 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D7988 80223918 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D798C 8022391C 00000002 */  srl       $zero, $zero, 0
/* 6D7990 80223920 00570001 */  .byte     0x00, 0x57, 0x00, 0x01
/* 6D7994 80223924 00000013 */  mtlo      $zero
/* 6D7998 80223928 00000000 */  nop       
/* 6D799C 8022392C 00000008 */  jr        $zero
/* 6D79A0 80223930 00000001 */   movf     $zero, $zero, $fcc0
/* 6D79A4 80223934 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D79A8 80223938 00000056 */  drotrv    $zero, $zero, $zero
/* 6D79AC 8022393C 00000000 */  nop       
/* 6D79B0 80223940 00000008 */  jr        $zero
/* 6D79B4 80223944 00000001 */   movf     $zero, $zero, $fcc0
/* 6D79B8 80223948 0000000A */  movz      $zero, $zero, $zero
/* 6D79BC 8022394C 00000043 */  sra       $zero, $zero, 1
/* 6D79C0 80223950 00000003 */  sra       $zero, $zero, 0
/* 6D79C4 80223954 8025385C */  lb        $a1, 0x385c($at)
/* 6D79C8 80223958 FE363C88 */  sd        $s6, 0x3c88($s1)
/* 6D79CC 8022395C 000002DD */  .byte     0x00, 0x00, 0x02, 0xdd
/* 6D79D0 80223960 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D79D4 80223964 00000000 */  nop       
/* 6D79D8 80223968 00000056 */  drotrv    $zero, $zero, $zero
/* 6D79DC 8022396C 00000000 */  nop       
/* 6D79E0 80223970 00000043 */  sra       $zero, $zero, 1
/* 6D79E4 80223974 00000002 */  srl       $zero, $zero, 0
/* 6D79E8 80223978 8026BF48 */  lb        $a2, -0x40b8($at)
/* 6D79EC 8022397C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D79F0 80223980 00000043 */  sra       $zero, $zero, 1
/* 6D79F4 80223984 00000003 */  sra       $zero, $zero, 0
/* 6D79F8 80223988 8026FCD4 */  lb        $a2, -0x32c($at)
/* 6D79FC 8022398C FE363C88 */  sd        $s6, 0x3c88($s1)
/* 6D7A00 80223990 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7A04 80223994 00000043 */  sra       $zero, $zero, 1
/* 6D7A08 80223998 00000002 */  srl       $zero, $zero, 0
/* 6D7A0C 8022399C 8026BF48 */  lb        $a2, -0x40b8($at)
/* 6D7A10 802239A0 00000000 */  nop       
/* 6D7A14 802239A4 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D7A18 802239A8 00000000 */  nop       
/* 6D7A1C 802239AC 00000043 */  sra       $zero, $zero, 1
/* 6D7A20 802239B0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7A24 802239B4 8027114C */  lb        $a3, 0x114c($at)
/* 6D7A28 802239B8 00000043 */  sra       $zero, $zero, 1
/* 6D7A2C 802239BC 00000002 */  srl       $zero, $zero, 0
/* 6D7A30 802239C0 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D7A34 802239C4 00000002 */  srl       $zero, $zero, 0
/* 6D7A38 802239C8 00000008 */  jr        $zero
/* 6D7A3C 802239CC 00000001 */   movf     $zero, $zero, $fcc0
/* 6D7A40 802239D0 0000000A */  movz      $zero, $zero, $zero
/* 6D7A44 802239D4 00000043 */  sra       $zero, $zero, 1
/* 6D7A48 802239D8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7A4C 802239DC 8027D7F0 */  lb        $a3, -0x2810($at)
/* 6D7A50 802239E0 00000043 */  sra       $zero, $zero, 1
/* 6D7A54 802239E4 00000003 */  sra       $zero, $zero, 0
/* 6D7A58 802239E8 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D7A5C 802239EC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7A60 802239F0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7A64 802239F4 00000043 */  sra       $zero, $zero, 1
/* 6D7A68 802239F8 00000003 */  sra       $zero, $zero, 0
/* 6D7A6C 802239FC 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D7A70 80223A00 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7A74 80223A04 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7A78 80223A08 00000002 */  srl       $zero, $zero, 0
/* 6D7A7C 80223A0C 00000000 */  nop       
/* 6D7A80 80223A10 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7A84 80223A14 00000000 */  nop       
/* 6D7A88 80223A18 00000024 */  and       $zero, $zero, $zero
/* 6D7A8C 80223A1C 00000002 */  srl       $zero, $zero, 0
/* 6D7A90 80223A20 FBD3E280 */  bbit132   $fp, 0x13, .L8021C424
/* 6D7A94 80223A24 00000000 */   nop      
/* 6D7A98 80223A28 00000003 */  sra       $zero, $zero, 0
/* 6D7A9C 80223A2C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7AA0 80223A30 0000000A */  movz      $zero, $zero, $zero
/* 6D7AA4 80223A34 00000043 */  sra       $zero, $zero, 1
/* 6D7AA8 80223A38 00000002 */  srl       $zero, $zero, 0
/* 6D7AAC 80223A3C 8026E310 */  lb        $a2, -0x1cf0($at)
/* 6D7AB0 80223A40 00008002 */  srl       $s0, $zero, 0
/* 6D7AB4 80223A44 00000043 */  sra       $zero, $zero, 1
/* 6D7AB8 80223A48 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7ABC 80223A4C 8026E354 */  lb        $a2, -0x1cac($at)
/* 6D7AC0 80223A50 00000003 */  sra       $zero, $zero, 0
/* 6D7AC4 80223A54 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7AC8 80223A58 00000000 */  nop       
/* 6D7ACC 80223A5C 00000043 */  sra       $zero, $zero, 1
/* 6D7AD0 80223A60 00000003 */  sra       $zero, $zero, 0
/* 6D7AD4 80223A64 8026E8AC */  lb        $a2, -0x1754($at)
/* 6D7AD8 80223A68 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7ADC 80223A6C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D7AE0 80223A70 00000043 */  sra       $zero, $zero, 1
/* 6D7AE4 80223A74 00000003 */  sra       $zero, $zero, 0
/* 6D7AE8 80223A78 8026A0D4 */  lb        $a2, -0x5f2c($at)
/* 6D7AEC 80223A7C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7AF0 80223A80 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D7AF4 80223A84 00000043 */  sra       $zero, $zero, 1
/* 6D7AF8 80223A88 00000003 */  sra       $zero, $zero, 0
/* 6D7AFC 80223A8C 8026F694 */  lb        $a2, -0x96c($at)
/* 6D7B00 80223A90 00000002 */  srl       $zero, $zero, 0
/* 6D7B04 80223A94 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D7B08 80223A98 0000000D */  break     
/* 6D7B0C 80223A9C 00000002 */   srl      $zero, $zero, 0
/* 6D7B10 80223AA0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D7B14 80223AA4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D7B18 80223AA8 00000043 */  sra       $zero, $zero, 1
/* 6D7B1C 80223AAC 00000003 */  sra       $zero, $zero, 0
/* 6D7B20 80223AB0 80218588 */  lb        $at, -0x7a78($at)
/* 6D7B24 80223AB4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7B28 80223AB8 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D7B2C 80223ABC 0000000A */  movz      $zero, $zero, $zero
/* 6D7B30 80223AC0 00000002 */  srl       $zero, $zero, 0
/* 6D7B34 80223AC4 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D7B38 80223AC8 00000000 */  nop       
/* 6D7B3C 80223ACC 00000043 */  sra       $zero, $zero, 1
/* 6D7B40 80223AD0 00000003 */  sra       $zero, $zero, 0
/* 6D7B44 80223AD4 8026FC6C */  lb        $a2, -0x394($at)
/* 6D7B48 80223AD8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7B4C 80223ADC FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D7B50 80223AE0 0000000C */  syscall   
/* 6D7B54 80223AE4 00000002 */  srl       $zero, $zero, 0
/* 6D7B58 80223AE8 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D7B5C 80223AEC 00000003 */  sra       $zero, $zero, 0
/* 6D7B60 80223AF0 00000024 */  and       $zero, $zero, $zero
/* 6D7B64 80223AF4 00000002 */  srl       $zero, $zero, 0
/* 6D7B68 80223AF8 FE363C88 */  sd        $s6, 0x3c88($s1)
/* 6D7B6C 80223AFC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7B70 80223B00 00000043 */  sra       $zero, $zero, 1
/* 6D7B74 80223B04 00000003 */  sra       $zero, $zero, 0
/* 6D7B78 80223B08 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D7B7C 80223B0C 00000002 */  srl       $zero, $zero, 0
/* 6D7B80 80223B10 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D7B84 80223B14 00000004 */  sllv      $zero, $zero, $zero
/* 6D7B88 80223B18 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7B8C 80223B1C 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6D7B90 80223B20 00000013 */  mtlo      $zero
/* 6D7B94 80223B24 00000000 */  nop       
/* 6D7B98 80223B28 00000013 */  mtlo      $zero
/* 6D7B9C 80223B2C 00000000 */  nop       
/* 6D7BA0 80223B30 00000013 */  mtlo      $zero
/* 6D7BA4 80223B34 00000000 */  nop       
/* 6D7BA8 80223B38 00000043 */  sra       $zero, $zero, 1
/* 6D7BAC 80223B3C 00000003 */  sra       $zero, $zero, 0
/* 6D7BB0 80223B40 8026E414 */  lb        $a2, -0x1bec($at)
/* 6D7BB4 80223B44 00000000 */  nop       
/* 6D7BB8 80223B48 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7BBC 80223B4C 0000000B */  movn      $zero, $zero, $zero
/* 6D7BC0 80223B50 00000002 */  srl       $zero, $zero, 0
/* 6D7BC4 80223B54 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7BC8 80223B58 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D7BCC 80223B5C 00000004 */  sllv      $zero, $zero, $zero
/* 6D7BD0 80223B60 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7BD4 80223B64 00000000 */  nop       
/* 6D7BD8 80223B68 00000013 */  mtlo      $zero
/* 6D7BDC 80223B6C 00000000 */  nop       
/* 6D7BE0 80223B70 0000000A */  movz      $zero, $zero, $zero
/* 6D7BE4 80223B74 00000002 */  srl       $zero, $zero, 0
/* 6D7BE8 80223B78 FBD3E280 */  bbit132   $fp, 0x13, .L8021C57C
/* 6D7BEC 80223B7C 00000000 */   nop      
/* 6D7BF0 80223B80 00000024 */  and       $zero, $zero, $zero
/* 6D7BF4 80223B84 00000002 */  srl       $zero, $zero, 0
/* 6D7BF8 80223B88 FBD3E280 */  bbit132   $fp, 0x13, .L8021C58C
/* 6D7BFC 80223B8C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D7C00 80223B90 00000043 */  sra       $zero, $zero, 1
/* 6D7C04 80223B94 00000003 */  sra       $zero, $zero, 0
/* 6D7C08 80223B98 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D7C0C 80223B9C 00000002 */  srl       $zero, $zero, 0
/* 6D7C10 80223BA0 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D7C14 80223BA4 00000004 */  sllv      $zero, $zero, $zero
/* 6D7C18 80223BA8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7C1C 80223BAC 0000000A */  movz      $zero, $zero, $zero
/* 6D7C20 80223BB0 00000013 */  mtlo      $zero
/* 6D7C24 80223BB4 00000000 */  nop       
/* 6D7C28 80223BB8 00000043 */  sra       $zero, $zero, 1
/* 6D7C2C 80223BBC 00000004 */  sllv      $zero, $zero, $zero
/* 6D7C30 80223BC0 8026A14C */  lb        $a2, -0x5eb4($at)
/* 6D7C34 80223BC4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7C38 80223BC8 00008002 */  srl       $s0, $zero, 0
/* 6D7C3C 80223BCC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7C40 80223BD0 0000000A */  movz      $zero, $zero, $zero
/* 6D7C44 80223BD4 00000002 */  srl       $zero, $zero, 0
/* 6D7C48 80223BD8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7C4C 80223BDC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7C50 80223BE0 00000046 */  rotrv     $zero, $zero, $zero
/* 6D7C54 80223BE4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7C58 80223BE8 8021F39C */  lb        $at, -0xc64($at)
/* 6D7C5C 80223BEC 00000002 */  srl       $zero, $zero, 0
/* 6D7C60 80223BF0 00000000 */  nop       
/* 6D7C64 80223BF4 00000013 */  mtlo      $zero
/* 6D7C68 80223BF8 00000000 */  nop       
/* 6D7C6C 80223BFC 00000046 */  rotrv     $zero, $zero, $zero
/* 6D7C70 80223C00 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7C74 80223C04 8022179C */  lb        $v0, 0x179c($at)
/* 6D7C78 80223C08 00000002 */  srl       $zero, $zero, 0
/* 6D7C7C 80223C0C 00000000 */  nop       
/* 6D7C80 80223C10 00000003 */  sra       $zero, $zero, 0
/* 6D7C84 80223C14 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7C88 80223C18 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6D7C8C 80223C1C 00000043 */  sra       $zero, $zero, 1
/* 6D7C90 80223C20 00000004 */  sllv      $zero, $zero, $zero
/* 6D7C94 80223C24 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D7C98 80223C28 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7C9C 80223C2C 0000000A */  movz      $zero, $zero, $zero
/* 6D7CA0 80223C30 00000000 */  nop       
/* 6D7CA4 80223C34 00000043 */  sra       $zero, $zero, 1
/* 6D7CA8 80223C38 00000004 */  sllv      $zero, $zero, $zero
/* 6D7CAC 80223C3C 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D7CB0 80223C40 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7CB4 80223C44 0000000B */  movn      $zero, $zero, $zero
/* 6D7CB8 80223C48 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D7CBC 80223C4C 00000043 */  sra       $zero, $zero, 1
/* 6D7CC0 80223C50 00000004 */  sllv      $zero, $zero, $zero
/* 6D7CC4 80223C54 8026C0D4 */  lb        $a2, -0x3f2c($at)
/* 6D7CC8 80223C58 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7CCC 80223C5C 00000006 */  srlv      $zero, $zero, $zero
/* 6D7CD0 80223C60 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7CD4 80223C64 00000043 */  sra       $zero, $zero, 1
/* 6D7CD8 80223C68 00000003 */  sra       $zero, $zero, 0
/* 6D7CDC 80223C6C 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D7CE0 80223C70 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7CE4 80223C74 00000000 */  nop       
/* 6D7CE8 80223C78 00000043 */  sra       $zero, $zero, 1
/* 6D7CEC 80223C7C 00000003 */  sra       $zero, $zero, 0
/* 6D7CF0 80223C80 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D7CF4 80223C84 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7CF8 80223C88 00000000 */  nop       
/* 6D7CFC 80223C8C 00000043 */  sra       $zero, $zero, 1
/* 6D7D00 80223C90 00000003 */  sra       $zero, $zero, 0
/* 6D7D04 80223C94 8027C548 */  lb        $a3, -0x3ab8($at)
/* 6D7D08 80223C98 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7D0C 80223C9C 00000000 */  nop       
/* 6D7D10 80223CA0 00000043 */  sra       $zero, $zero, 1
/* 6D7D14 80223CA4 00000002 */  srl       $zero, $zero, 0
/* 6D7D18 80223CA8 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D7D1C 80223CAC 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D7D20 80223CB0 00000043 */  sra       $zero, $zero, 1
/* 6D7D24 80223CB4 00000002 */  srl       $zero, $zero, 0
/* 6D7D28 80223CB8 8024EB24 */  lb        $a0, -0x14dc($at)
/* 6D7D2C 80223CBC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7D30 80223CC0 00000043 */  sra       $zero, $zero, 1
/* 6D7D34 80223CC4 00000002 */  srl       $zero, $zero, 0
/* 6D7D38 80223CC8 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6D7D3C 80223CCC 0000000F */  sync      
/* 6D7D40 80223CD0 00000008 */  jr        $zero
/* 6D7D44 80223CD4 00000001 */   movf     $zero, $zero, $fcc0
/* 6D7D48 80223CD8 0000000F */  sync      
/* 6D7D4C 80223CDC 00000043 */  sra       $zero, $zero, 1
/* 6D7D50 80223CE0 00000003 */  sra       $zero, $zero, 0
/* 6D7D54 80223CE4 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D7D58 80223CE8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7D5C 80223CEC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7D60 80223CF0 00000011 */  mthi      $zero
/* 6D7D64 80223CF4 00000002 */  srl       $zero, $zero, 0
/* 6D7D68 80223CF8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7D6C 80223CFC 00000200 */  sll       $zero, $zero, 8
/* 6D7D70 80223D00 00000043 */  sra       $zero, $zero, 1
/* 6D7D74 80223D04 00000004 */  sllv      $zero, $zero, $zero
/* 6D7D78 80223D08 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D7D7C 80223D0C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7D80 80223D10 00000001 */  movf      $zero, $zero, $fcc0
/* 6D7D84 80223D14 00560002 */  .byte     0x00, 0x56, 0x00, 0x02
/* 6D7D88 80223D18 00000012 */  mflo      $zero
/* 6D7D8C 80223D1C 00000000 */  nop       
/* 6D7D90 80223D20 00000043 */  sra       $zero, $zero, 1
/* 6D7D94 80223D24 00000004 */  sllv      $zero, $zero, $zero
/* 6D7D98 80223D28 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D7D9C 80223D2C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7DA0 80223D30 00000002 */  srl       $zero, $zero, 0
/* 6D7DA4 80223D34 00570002 */  .byte     0x00, 0x57, 0x00, 0x02
/* 6D7DA8 80223D38 00000013 */  mtlo      $zero
/* 6D7DAC 80223D3C 00000000 */  nop       
/* 6D7DB0 80223D40 00000008 */  jr        $zero
/* 6D7DB4 80223D44 00000001 */   movf     $zero, $zero, $fcc0
/* 6D7DB8 80223D48 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D7DBC 80223D4C 00000043 */  sra       $zero, $zero, 1
/* 6D7DC0 80223D50 00000003 */  sra       $zero, $zero, 0
/* 6D7DC4 80223D54 8025385C */  lb        $a1, 0x385c($at)
/* 6D7DC8 80223D58 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7DCC 80223D5C 000020D4 */  .byte     0x00, 0x00, 0x20, 0xd4
/* 6D7DD0 80223D60 00000043 */  sra       $zero, $zero, 1
/* 6D7DD4 80223D64 00000003 */  sra       $zero, $zero, 0
/* 6D7DD8 80223D68 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D7DDC 80223D6C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7DE0 80223D70 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7DE4 80223D74 00000011 */  mthi      $zero
/* 6D7DE8 80223D78 00000002 */  srl       $zero, $zero, 0
/* 6D7DEC 80223D7C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7DF0 80223D80 00000200 */  sll       $zero, $zero, 8
/* 6D7DF4 80223D84 00000043 */  sra       $zero, $zero, 1
/* 6D7DF8 80223D88 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D7DFC 80223D8C 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D7E00 80223D90 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7E04 80223D94 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7E08 80223D98 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D7E0C 80223D9C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D7E10 80223DA0 00000043 */  sra       $zero, $zero, 1
/* 6D7E14 80223DA4 00000003 */  sra       $zero, $zero, 0
/* 6D7E18 80223DA8 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D7E1C 80223DAC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7E20 80223DB0 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D7E24 80223DB4 00000010 */  mfhi      $zero
/* 6D7E28 80223DB8 00000002 */  srl       $zero, $zero, 0
/* 6D7E2C 80223DBC FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D7E30 80223DC0 00080000 */  sll       $zero, $t0, 0
/* 6D7E34 80223DC4 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D7E38 80223DC8 00000002 */  srl       $zero, $zero, 0
/* 6D7E3C 80223DCC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7E40 80223DD0 00000006 */  srlv      $zero, $zero, $zero
/* 6D7E44 80223DD4 00000027 */  not       $zero, $zero
/* 6D7E48 80223DD8 00000002 */  srl       $zero, $zero, 0
/* 6D7E4C 80223DDC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D7E50 80223DE0 0000000C */  syscall   
/* 6D7E54 80223DE4 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D7E58 80223DE8 00000002 */  srl       $zero, $zero, 0
/* 6D7E5C 80223DEC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D7E60 80223DF0 00000002 */  srl       $zero, $zero, 0
/* 6D7E64 80223DF4 00000043 */  sra       $zero, $zero, 1
/* 6D7E68 80223DF8 0000000F */  sync      
/* 6D7E6C 80223DFC 802D829C */  lb        $t5, -0x7d64($at)
/* 6D7E70 80223E00 00000033 */  tltu      $zero, $zero
/* 6D7E74 80223E04 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D7E78 80223E08 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7E7C 80223E0C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D7E80 80223E10 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D7E84 80223E14 F24A7AFB */  scd       $t2, 0x7afb($s2)
/* 6D7E88 80223E18 0000001E */  ddiv      $zero, $zero, $zero
/* 6D7E8C 80223E1C 00000000 */  nop       
/* 6D7E90 80223E20 00000000 */  nop       
/* 6D7E94 80223E24 00000000 */  nop       
/* 6D7E98 80223E28 00000000 */  nop       
/* 6D7E9C 80223E2C 00000000 */  nop       
/* 6D7EA0 80223E30 00000000 */  nop       
/* 6D7EA4 80223E34 00000000 */  nop       
/* 6D7EA8 80223E38 00000012 */  mflo      $zero
/* 6D7EAC 80223E3C 00000000 */  nop       
/* 6D7EB0 80223E40 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D7EB4 80223E44 00000002 */  srl       $zero, $zero, 0
/* 6D7EB8 80223E48 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7EBC 80223E4C 00000010 */  mfhi      $zero
/* 6D7EC0 80223E50 00000027 */  not       $zero, $zero
/* 6D7EC4 80223E54 00000002 */  srl       $zero, $zero, 0
/* 6D7EC8 80223E58 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D7ECC 80223E5C 0000001F */  ddivu     $zero, $zero, $zero
/* 6D7ED0 80223E60 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D7ED4 80223E64 00000002 */  srl       $zero, $zero, 0
/* 6D7ED8 80223E68 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D7EDC 80223E6C 00000002 */  srl       $zero, $zero, 0
/* 6D7EE0 80223E70 00000043 */  sra       $zero, $zero, 1
/* 6D7EE4 80223E74 0000000F */  sync      
/* 6D7EE8 80223E78 802D829C */  lb        $t5, -0x7d64($at)
/* 6D7EEC 80223E7C 00000033 */  tltu      $zero, $zero
/* 6D7EF0 80223E80 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D7EF4 80223E84 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7EF8 80223E88 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D7EFC 80223E8C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D7F00 80223E90 F24A7BB4 */  scd       $t2, 0x7bb4($s2)
/* 6D7F04 80223E94 0000001E */  ddiv      $zero, $zero, $zero
/* 6D7F08 80223E98 00000000 */  nop       
/* 6D7F0C 80223E9C 00000000 */  nop       
/* 6D7F10 80223EA0 00000000 */  nop       
/* 6D7F14 80223EA4 00000000 */  nop       
/* 6D7F18 80223EA8 00000000 */  nop       
/* 6D7F1C 80223EAC 00000000 */  nop       
/* 6D7F20 80223EB0 00000000 */  nop       
/* 6D7F24 80223EB4 00000013 */  mtlo      $zero
/* 6D7F28 80223EB8 00000000 */  nop       
/* 6D7F2C 80223EBC 00000012 */  mflo      $zero
/* 6D7F30 80223EC0 00000000 */  nop       
/* 6D7F34 80223EC4 00000043 */  sra       $zero, $zero, 1
/* 6D7F38 80223EC8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D7F3C 80223ECC 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D7F40 80223ED0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7F44 80223ED4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7F48 80223ED8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D7F4C 80223EDC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D7F50 80223EE0 00000043 */  sra       $zero, $zero, 1
/* 6D7F54 80223EE4 00000003 */  sra       $zero, $zero, 0
/* 6D7F58 80223EE8 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D7F5C 80223EEC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D7F60 80223EF0 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D7F64 80223EF4 00000010 */  mfhi      $zero
/* 6D7F68 80223EF8 00000002 */  srl       $zero, $zero, 0
/* 6D7F6C 80223EFC FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D7F70 80223F00 00080000 */  sll       $zero, $t0, 0
/* 6D7F74 80223F04 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D7F78 80223F08 00000002 */  srl       $zero, $zero, 0
/* 6D7F7C 80223F0C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7F80 80223F10 0000000C */  syscall   
/* 6D7F84 80223F14 00000027 */  not       $zero, $zero
/* 6D7F88 80223F18 00000002 */  srl       $zero, $zero, 0
/* 6D7F8C 80223F1C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D7F90 80223F20 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D7F94 80223F24 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D7F98 80223F28 00000002 */  srl       $zero, $zero, 0
/* 6D7F9C 80223F2C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D7FA0 80223F30 00000002 */  srl       $zero, $zero, 0
/* 6D7FA4 80223F34 00000043 */  sra       $zero, $zero, 1
/* 6D7FA8 80223F38 0000000F */  sync      
/* 6D7FAC 80223F3C 802D829C */  lb        $t5, -0x7d64($at)
/* 6D7FB0 80223F40 00000033 */  tltu      $zero, $zero
/* 6D7FB4 80223F44 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D7FB8 80223F48 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7FBC 80223F4C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D7FC0 80223F50 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D7FC4 80223F54 F24A7AFB */  scd       $t2, 0x7afb($s2)
/* 6D7FC8 80223F58 0000001E */  ddiv      $zero, $zero, $zero
/* 6D7FCC 80223F5C 00000000 */  nop       
/* 6D7FD0 80223F60 00000000 */  nop       
/* 6D7FD4 80223F64 00000000 */  nop       
/* 6D7FD8 80223F68 00000000 */  nop       
/* 6D7FDC 80223F6C 00000000 */  nop       
/* 6D7FE0 80223F70 00000000 */  nop       
/* 6D7FE4 80223F74 00000000 */  nop       
/* 6D7FE8 80223F78 00000012 */  mflo      $zero
/* 6D7FEC 80223F7C 00000000 */  nop       
/* 6D7FF0 80223F80 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D7FF4 80223F84 00000002 */  srl       $zero, $zero, 0
/* 6D7FF8 80223F88 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D7FFC 80223F8C 0000001E */  ddiv      $zero, $zero, $zero
/* 6D8000 80223F90 00000027 */  not       $zero, $zero
/* 6D8004 80223F94 00000002 */  srl       $zero, $zero, 0
/* 6D8008 80223F98 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D800C 80223F9C 00000024 */  and       $zero, $zero, $zero
/* 6D8010 80223FA0 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D8014 80223FA4 00000002 */  srl       $zero, $zero, 0
/* 6D8018 80223FA8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D801C 80223FAC 00000002 */  srl       $zero, $zero, 0
/* 6D8020 80223FB0 00000043 */  sra       $zero, $zero, 1
/* 6D8024 80223FB4 0000000F */  sync      
/* 6D8028 80223FB8 802D829C */  lb        $t5, -0x7d64($at)
/* 6D802C 80223FBC 00000033 */  tltu      $zero, $zero
/* 6D8030 80223FC0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D8034 80223FC4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8038 80223FC8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D803C 80223FCC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D8040 80223FD0 F24A7BB4 */  scd       $t2, 0x7bb4($s2)
/* 6D8044 80223FD4 0000001E */  ddiv      $zero, $zero, $zero
/* 6D8048 80223FD8 00000000 */  nop       
/* 6D804C 80223FDC 00000000 */  nop       
/* 6D8050 80223FE0 00000000 */  nop       
/* 6D8054 80223FE4 00000000 */  nop       
/* 6D8058 80223FE8 00000000 */  nop       
/* 6D805C 80223FEC 00000000 */  nop       
/* 6D8060 80223FF0 00000000 */  nop       
/* 6D8064 80223FF4 00000013 */  mtlo      $zero
/* 6D8068 80223FF8 00000000 */  nop       
/* 6D806C 80223FFC 00000013 */  mtlo      $zero
/* 6D8070 80224000 00000000 */  nop       
/* 6D8074 80224004 00000008 */  jr        $zero
/* 6D8078 80224008 00000001 */   movf     $zero, $zero, $fcc0
/* 6D807C 8022400C 0000001E */  ddiv      $zero, $zero, $zero
/* 6D8080 80224010 00000043 */  sra       $zero, $zero, 1
/* 6D8084 80224014 00000003 */  sra       $zero, $zero, 0
/* 6D8088 80224018 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D808C 8022401C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8090 80224020 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8094 80224024 00000011 */  mthi      $zero
/* 6D8098 80224028 00000002 */  srl       $zero, $zero, 0
/* 6D809C 8022402C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D80A0 80224030 00000200 */  sll       $zero, $zero, 8
/* 6D80A4 80224034 00000043 */  sra       $zero, $zero, 1
/* 6D80A8 80224038 00000004 */  sllv      $zero, $zero, $zero
/* 6D80AC 8022403C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D80B0 80224040 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D80B4 80224044 00000001 */  movf      $zero, $zero, $fcc0
/* 6D80B8 80224048 00560001 */  .byte     0x00, 0x56, 0x00, 0x01
/* 6D80BC 8022404C 00000012 */  mflo      $zero
/* 6D80C0 80224050 00000000 */  nop       
/* 6D80C4 80224054 00000043 */  sra       $zero, $zero, 1
/* 6D80C8 80224058 00000004 */  sllv      $zero, $zero, $zero
/* 6D80CC 8022405C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D80D0 80224060 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D80D4 80224064 00000002 */  srl       $zero, $zero, 0
/* 6D80D8 80224068 00570001 */  .byte     0x00, 0x57, 0x00, 0x01
/* 6D80DC 8022406C 00000013 */  mtlo      $zero
/* 6D80E0 80224070 00000000 */  nop       
/* 6D80E4 80224074 00000008 */  jr        $zero
/* 6D80E8 80224078 00000001 */   movf     $zero, $zero, $fcc0
/* 6D80EC 8022407C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D80F0 80224080 00000056 */  drotrv    $zero, $zero, $zero
/* 6D80F4 80224084 00000000 */  nop       
/* 6D80F8 80224088 00000008 */  jr        $zero
/* 6D80FC 8022408C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D8100 80224090 0000000A */  movz      $zero, $zero, $zero
/* 6D8104 80224094 00000043 */  sra       $zero, $zero, 1
/* 6D8108 80224098 00000003 */  sra       $zero, $zero, 0
/* 6D810C 8022409C 8025385C */  lb        $a1, 0x385c($at)
/* 6D8110 802240A0 FE363C88 */  sd        $s6, 0x3c88($s1)
/* 6D8114 802240A4 000002DD */  .byte     0x00, 0x00, 0x02, 0xdd
/* 6D8118 802240A8 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D811C 802240AC 00000000 */  nop       
/* 6D8120 802240B0 00000056 */  drotrv    $zero, $zero, $zero
/* 6D8124 802240B4 00000000 */  nop       
/* 6D8128 802240B8 00000043 */  sra       $zero, $zero, 1
/* 6D812C 802240BC 00000002 */  srl       $zero, $zero, 0
/* 6D8130 802240C0 8026BF48 */  lb        $a2, -0x40b8($at)
/* 6D8134 802240C4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8138 802240C8 00000043 */  sra       $zero, $zero, 1
/* 6D813C 802240CC 00000003 */  sra       $zero, $zero, 0
/* 6D8140 802240D0 80270174 */  lb        $a3, 0x174($at)
/* 6D8144 802240D4 FE363C88 */  sd        $s6, 0x3c88($s1)
/* 6D8148 802240D8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D814C 802240DC 00000043 */  sra       $zero, $zero, 1
/* 6D8150 802240E0 00000002 */  srl       $zero, $zero, 0
/* 6D8154 802240E4 8026BF48 */  lb        $a2, -0x40b8($at)
/* 6D8158 802240E8 00000000 */  nop       
/* 6D815C 802240EC 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D8160 802240F0 00000000 */  nop       
/* 6D8164 802240F4 00000043 */  sra       $zero, $zero, 1
/* 6D8168 802240F8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D816C 802240FC 8027114C */  lb        $a3, 0x114c($at)
/* 6D8170 80224100 00000043 */  sra       $zero, $zero, 1
/* 6D8174 80224104 00000002 */  srl       $zero, $zero, 0
/* 6D8178 80224108 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D817C 8022410C 00000002 */  srl       $zero, $zero, 0
/* 6D8180 80224110 00000008 */  jr        $zero
/* 6D8184 80224114 00000001 */   movf     $zero, $zero, $fcc0
/* 6D8188 80224118 0000000A */  movz      $zero, $zero, $zero
/* 6D818C 8022411C 00000043 */  sra       $zero, $zero, 1
/* 6D8190 80224120 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8194 80224124 8027D7F0 */  lb        $a3, -0x2810($at)
/* 6D8198 80224128 00000043 */  sra       $zero, $zero, 1
/* 6D819C 8022412C 00000003 */  sra       $zero, $zero, 0
/* 6D81A0 80224130 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D81A4 80224134 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D81A8 80224138 00000001 */  movf      $zero, $zero, $fcc0
/* 6D81AC 8022413C 00000043 */  sra       $zero, $zero, 1
/* 6D81B0 80224140 00000003 */  sra       $zero, $zero, 0
/* 6D81B4 80224144 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D81B8 80224148 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D81BC 8022414C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D81C0 80224150 00000002 */  srl       $zero, $zero, 0
/* 6D81C4 80224154 00000000 */  nop       
/* 6D81C8 80224158 00000001 */  movf      $zero, $zero, $fcc0
/* 6D81CC 8022415C 00000000 */  nop       
/* 6D81D0 80224160 00000024 */  and       $zero, $zero, $zero
/* 6D81D4 80224164 00000002 */  srl       $zero, $zero, 0
/* 6D81D8 80224168 FBD3E280 */  bbit132   $fp, 0x13, .L8021CB6C
/* 6D81DC 8022416C 00000000 */   nop      
/* 6D81E0 80224170 00000003 */  sra       $zero, $zero, 0
/* 6D81E4 80224174 00000001 */  movf      $zero, $zero, $fcc0
/* 6D81E8 80224178 0000000A */  movz      $zero, $zero, $zero
/* 6D81EC 8022417C 00000043 */  sra       $zero, $zero, 1
/* 6D81F0 80224180 00000002 */  srl       $zero, $zero, 0
/* 6D81F4 80224184 8026E310 */  lb        $a2, -0x1cf0($at)
/* 6D81F8 80224188 00008002 */  srl       $s0, $zero, 0
/* 6D81FC 8022418C 00000043 */  sra       $zero, $zero, 1
/* 6D8200 80224190 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8204 80224194 8026E354 */  lb        $a2, -0x1cac($at)
/* 6D8208 80224198 00000003 */  sra       $zero, $zero, 0
/* 6D820C 8022419C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8210 802241A0 00000000 */  nop       
/* 6D8214 802241A4 00000043 */  sra       $zero, $zero, 1
/* 6D8218 802241A8 00000003 */  sra       $zero, $zero, 0
/* 6D821C 802241AC 8026E8AC */  lb        $a2, -0x1754($at)
/* 6D8220 802241B0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8224 802241B4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D8228 802241B8 00000043 */  sra       $zero, $zero, 1
/* 6D822C 802241BC 00000003 */  sra       $zero, $zero, 0
/* 6D8230 802241C0 8026A0D4 */  lb        $a2, -0x5f2c($at)
/* 6D8234 802241C4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8238 802241C8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D823C 802241CC 00000043 */  sra       $zero, $zero, 1
/* 6D8240 802241D0 00000003 */  sra       $zero, $zero, 0
/* 6D8244 802241D4 8026F694 */  lb        $a2, -0x96c($at)
/* 6D8248 802241D8 00000002 */  srl       $zero, $zero, 0
/* 6D824C 802241DC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D8250 802241E0 0000000D */  break     
/* 6D8254 802241E4 00000002 */   srl      $zero, $zero, 0
/* 6D8258 802241E8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D825C 802241EC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D8260 802241F0 00000043 */  sra       $zero, $zero, 1
/* 6D8264 802241F4 00000003 */  sra       $zero, $zero, 0
/* 6D8268 802241F8 80218588 */  lb        $at, -0x7a78($at)
/* 6D826C 802241FC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8270 80224200 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D8274 80224204 0000000A */  movz      $zero, $zero, $zero
/* 6D8278 80224208 00000002 */  srl       $zero, $zero, 0
/* 6D827C 8022420C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D8280 80224210 00000000 */  nop       
/* 6D8284 80224214 00000043 */  sra       $zero, $zero, 1
/* 6D8288 80224218 00000003 */  sra       $zero, $zero, 0
/* 6D828C 8022421C 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D8290 80224220 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8294 80224224 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D8298 80224228 00000011 */  mthi      $zero
/* 6D829C 8022422C 00000002 */  srl       $zero, $zero, 0
/* 6D82A0 80224230 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D82A4 80224234 04002000 */  bltz      $zero, .L8022C238
/* 6D82A8 80224238 00000024 */   and      $zero, $zero, $zero
/* 6D82AC 8022423C 00000002 */  srl       $zero, $zero, 0
/* 6D82B0 80224240 FE363C88 */  sd        $s6, 0x3c88($s1)
/* 6D82B4 80224244 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D82B8 80224248 00000043 */  sra       $zero, $zero, 1
/* 6D82BC 8022424C 00000003 */  sra       $zero, $zero, 0
/* 6D82C0 80224250 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D82C4 80224254 00000002 */  srl       $zero, $zero, 0
/* 6D82C8 80224258 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D82CC 8022425C 00000004 */  sllv      $zero, $zero, $zero
/* 6D82D0 80224260 00000001 */  movf      $zero, $zero, $fcc0
/* 6D82D4 80224264 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6D82D8 80224268 00000013 */  mtlo      $zero
/* 6D82DC 8022426C 00000000 */  nop       
/* 6D82E0 80224270 00000013 */  mtlo      $zero
/* 6D82E4 80224274 00000000 */  nop       
/* 6D82E8 80224278 00000013 */  mtlo      $zero
/* 6D82EC 8022427C 00000000 */  nop       
/* 6D82F0 80224280 00000043 */  sra       $zero, $zero, 1
/* 6D82F4 80224284 00000003 */  sra       $zero, $zero, 0
/* 6D82F8 80224288 8026E414 */  lb        $a2, -0x1bec($at)
/* 6D82FC 8022428C 00000000 */  nop       
/* 6D8300 80224290 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8304 80224294 0000000B */  movn      $zero, $zero, $zero
/* 6D8308 80224298 00000002 */  srl       $zero, $zero, 0
/* 6D830C 8022429C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8310 802242A0 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D8314 802242A4 00000004 */  sllv      $zero, $zero, $zero
/* 6D8318 802242A8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D831C 802242AC 00000000 */  nop       
/* 6D8320 802242B0 00000013 */  mtlo      $zero
/* 6D8324 802242B4 00000000 */  nop       
/* 6D8328 802242B8 0000000A */  movz      $zero, $zero, $zero
/* 6D832C 802242BC 00000002 */  srl       $zero, $zero, 0
/* 6D8330 802242C0 FBD3E280 */  bbit132   $fp, 0x13, .L8021CCC4
/* 6D8334 802242C4 00000000 */   nop      
/* 6D8338 802242C8 00000024 */  and       $zero, $zero, $zero
/* 6D833C 802242CC 00000002 */  srl       $zero, $zero, 0
/* 6D8340 802242D0 FBD3E280 */  bbit132   $fp, 0x13, .L8021CCD4
/* 6D8344 802242D4 00000001 */   movf     $zero, $zero, $fcc0
/* 6D8348 802242D8 00000043 */  sra       $zero, $zero, 1
/* 6D834C 802242DC 00000003 */  sra       $zero, $zero, 0
/* 6D8350 802242E0 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D8354 802242E4 00000002 */  srl       $zero, $zero, 0
/* 6D8358 802242E8 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D835C 802242EC 00000004 */  sllv      $zero, $zero, $zero
/* 6D8360 802242F0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8364 802242F4 0000000A */  movz      $zero, $zero, $zero
/* 6D8368 802242F8 00000013 */  mtlo      $zero
/* 6D836C 802242FC 00000000 */  nop       
/* 6D8370 80224300 00000043 */  sra       $zero, $zero, 1
/* 6D8374 80224304 00000004 */  sllv      $zero, $zero, $zero
/* 6D8378 80224308 8026A14C */  lb        $a2, -0x5eb4($at)
/* 6D837C 8022430C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8380 80224310 00008002 */  srl       $s0, $zero, 0
/* 6D8384 80224314 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8388 80224318 0000000A */  movz      $zero, $zero, $zero
/* 6D838C 8022431C 00000002 */  srl       $zero, $zero, 0
/* 6D8390 80224320 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8394 80224324 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8398 80224328 00000046 */  rotrv     $zero, $zero, $zero
/* 6D839C 8022432C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D83A0 80224330 8021F39C */  lb        $at, -0xc64($at)
/* 6D83A4 80224334 00000002 */  srl       $zero, $zero, 0
/* 6D83A8 80224338 00000000 */  nop       
/* 6D83AC 8022433C 00000013 */  mtlo      $zero
/* 6D83B0 80224340 00000000 */  nop       
/* 6D83B4 80224344 00000046 */  rotrv     $zero, $zero, $zero
/* 6D83B8 80224348 00000001 */  movf      $zero, $zero, $fcc0
/* 6D83BC 8022434C 8022179C */  lb        $v0, 0x179c($at)
/* 6D83C0 80224350 00000002 */  srl       $zero, $zero, 0
/* 6D83C4 80224354 00000000 */  nop       
/* 6D83C8 80224358 00000003 */  sra       $zero, $zero, 0
/* 6D83CC 8022435C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D83D0 80224360 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6D83D4 80224364 00000043 */  sra       $zero, $zero, 1
/* 6D83D8 80224368 00000004 */  sllv      $zero, $zero, $zero
/* 6D83DC 8022436C 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D83E0 80224370 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D83E4 80224374 0000000A */  movz      $zero, $zero, $zero
/* 6D83E8 80224378 00000000 */  nop       
/* 6D83EC 8022437C 00000043 */  sra       $zero, $zero, 1
/* 6D83F0 80224380 00000004 */  sllv      $zero, $zero, $zero
/* 6D83F4 80224384 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D83F8 80224388 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D83FC 8022438C 0000000B */  movn      $zero, $zero, $zero
/* 6D8400 80224390 00000006 */  srlv      $zero, $zero, $zero
/* 6D8404 80224394 00000043 */  sra       $zero, $zero, 1
/* 6D8408 80224398 00000004 */  sllv      $zero, $zero, $zero
/* 6D840C 8022439C 8026C0D4 */  lb        $a2, -0x3f2c($at)
/* 6D8410 802243A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8414 802243A4 00000007 */  srav      $zero, $zero, $zero
/* 6D8418 802243A8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D841C 802243AC 00000043 */  sra       $zero, $zero, 1
/* 6D8420 802243B0 00000003 */  sra       $zero, $zero, 0
/* 6D8424 802243B4 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D8428 802243B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D842C 802243BC 00000000 */  nop       
/* 6D8430 802243C0 00000043 */  sra       $zero, $zero, 1
/* 6D8434 802243C4 00000003 */  sra       $zero, $zero, 0
/* 6D8438 802243C8 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D843C 802243CC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8440 802243D0 00000000 */  nop       
/* 6D8444 802243D4 00000043 */  sra       $zero, $zero, 1
/* 6D8448 802243D8 00000003 */  sra       $zero, $zero, 0
/* 6D844C 802243DC 8027C548 */  lb        $a3, -0x3ab8($at)
/* 6D8450 802243E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8454 802243E4 00000000 */  nop       
/* 6D8458 802243E8 00000043 */  sra       $zero, $zero, 1
/* 6D845C 802243EC 00000002 */  srl       $zero, $zero, 0
/* 6D8460 802243F0 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D8464 802243F4 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D8468 802243F8 00000043 */  sra       $zero, $zero, 1
/* 6D846C 802243FC 00000002 */  srl       $zero, $zero, 0
/* 6D8470 80224400 8024EB24 */  lb        $a0, -0x14dc($at)
/* 6D8474 80224404 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8478 80224408 00000043 */  sra       $zero, $zero, 1
/* 6D847C 8022440C 00000002 */  srl       $zero, $zero, 0
/* 6D8480 80224410 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6D8484 80224414 0000000F */  sync      
/* 6D8488 80224418 00000008 */  jr        $zero
/* 6D848C 8022441C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D8490 80224420 0000000F */  sync      
/* 6D8494 80224424 00000043 */  sra       $zero, $zero, 1
/* 6D8498 80224428 00000003 */  sra       $zero, $zero, 0
/* 6D849C 8022442C 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D84A0 80224430 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D84A4 80224434 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D84A8 80224438 00000011 */  mthi      $zero
/* 6D84AC 8022443C 00000002 */  srl       $zero, $zero, 0
/* 6D84B0 80224440 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D84B4 80224444 00000200 */  sll       $zero, $zero, 8
/* 6D84B8 80224448 00000043 */  sra       $zero, $zero, 1
/* 6D84BC 8022444C 00000004 */  sllv      $zero, $zero, $zero
/* 6D84C0 80224450 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D84C4 80224454 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D84C8 80224458 00000001 */  movf      $zero, $zero, $fcc0
/* 6D84CC 8022445C 00560002 */  .byte     0x00, 0x56, 0x00, 0x02
/* 6D84D0 80224460 00000012 */  mflo      $zero
/* 6D84D4 80224464 00000000 */  nop       
/* 6D84D8 80224468 00000043 */  sra       $zero, $zero, 1
/* 6D84DC 8022446C 00000004 */  sllv      $zero, $zero, $zero
/* 6D84E0 80224470 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D84E4 80224474 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D84E8 80224478 00000002 */  srl       $zero, $zero, 0
/* 6D84EC 8022447C 00570002 */  .byte     0x00, 0x57, 0x00, 0x02
/* 6D84F0 80224480 00000013 */  mtlo      $zero
/* 6D84F4 80224484 00000000 */  nop       
/* 6D84F8 80224488 00000008 */  jr        $zero
/* 6D84FC 8022448C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D8500 80224490 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D8504 80224494 00000043 */  sra       $zero, $zero, 1
/* 6D8508 80224498 00000003 */  sra       $zero, $zero, 0
/* 6D850C 8022449C 8025385C */  lb        $a1, 0x385c($at)
/* 6D8510 802244A0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8514 802244A4 000002F0 */  tge       $zero, $zero, 0xb
/* 6D8518 802244A8 00000043 */  sra       $zero, $zero, 1
/* 6D851C 802244AC 00000003 */  sra       $zero, $zero, 0
/* 6D8520 802244B0 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D8524 802244B4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8528 802244B8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D852C 802244BC 00000011 */  mthi      $zero
/* 6D8530 802244C0 00000002 */  srl       $zero, $zero, 0
/* 6D8534 802244C4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8538 802244C8 00000200 */  sll       $zero, $zero, 8
/* 6D853C 802244CC 00000043 */  sra       $zero, $zero, 1
/* 6D8540 802244D0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D8544 802244D4 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D8548 802244D8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D854C 802244DC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8550 802244E0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D8554 802244E4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D8558 802244E8 00000043 */  sra       $zero, $zero, 1
/* 6D855C 802244EC 00000003 */  sra       $zero, $zero, 0
/* 6D8560 802244F0 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D8564 802244F4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8568 802244F8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D856C 802244FC 00000010 */  mfhi      $zero
/* 6D8570 80224500 00000002 */  srl       $zero, $zero, 0
/* 6D8574 80224504 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D8578 80224508 00080000 */  sll       $zero, $t0, 0
/* 6D857C 8022450C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D8580 80224510 00000002 */  srl       $zero, $zero, 0
/* 6D8584 80224514 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8588 80224518 00000006 */  srlv      $zero, $zero, $zero
/* 6D858C 8022451C 00000027 */  not       $zero, $zero
/* 6D8590 80224520 00000002 */  srl       $zero, $zero, 0
/* 6D8594 80224524 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D8598 80224528 0000000C */  syscall   
/* 6D859C 8022452C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D85A0 80224530 00000002 */  srl       $zero, $zero, 0
/* 6D85A4 80224534 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D85A8 80224538 00000002 */  srl       $zero, $zero, 0
/* 6D85AC 8022453C 00000043 */  sra       $zero, $zero, 1
/* 6D85B0 80224540 0000000F */  sync      
/* 6D85B4 80224544 802D829C */  lb        $t5, -0x7d64($at)
/* 6D85B8 80224548 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D85BC 8022454C 00000000 */  nop       
/* 6D85C0 80224550 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D85C4 80224554 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D85C8 80224558 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D85CC 8022455C F24A7AFB */  scd       $t2, 0x7afb($s2)
/* 6D85D0 80224560 0000001E */  ddiv      $zero, $zero, $zero
/* 6D85D4 80224564 00000000 */  nop       
/* 6D85D8 80224568 00000000 */  nop       
/* 6D85DC 8022456C 00000000 */  nop       
/* 6D85E0 80224570 00000000 */  nop       
/* 6D85E4 80224574 00000000 */  nop       
/* 6D85E8 80224578 00000000 */  nop       
/* 6D85EC 8022457C 00000000 */  nop       
/* 6D85F0 80224580 00000012 */  mflo      $zero
/* 6D85F4 80224584 00000000 */  nop       
/* 6D85F8 80224588 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D85FC 8022458C 00000002 */  srl       $zero, $zero, 0
/* 6D8600 80224590 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8604 80224594 00000010 */  mfhi      $zero
/* 6D8608 80224598 00000027 */  not       $zero, $zero
/* 6D860C 8022459C 00000002 */  srl       $zero, $zero, 0
/* 6D8610 802245A0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D8614 802245A4 0000001F */  ddivu     $zero, $zero, $zero
/* 6D8618 802245A8 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D861C 802245AC 00000002 */  srl       $zero, $zero, 0
/* 6D8620 802245B0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D8624 802245B4 00000002 */  srl       $zero, $zero, 0
/* 6D8628 802245B8 00000043 */  sra       $zero, $zero, 1
/* 6D862C 802245BC 0000000F */  sync      
/* 6D8630 802245C0 802D829C */  lb        $t5, -0x7d64($at)
/* 6D8634 802245C4 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D8638 802245C8 00000000 */  nop       
/* 6D863C 802245CC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8640 802245D0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D8644 802245D4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D8648 802245D8 F24A7BB4 */  scd       $t2, 0x7bb4($s2)
/* 6D864C 802245DC 0000001E */  ddiv      $zero, $zero, $zero
/* 6D8650 802245E0 00000000 */  nop       
/* 6D8654 802245E4 00000000 */  nop       
/* 6D8658 802245E8 00000000 */  nop       
/* 6D865C 802245EC 00000000 */  nop       
/* 6D8660 802245F0 00000000 */  nop       
/* 6D8664 802245F4 00000000 */  nop       
/* 6D8668 802245F8 00000000 */  nop       
/* 6D866C 802245FC 00000013 */  mtlo      $zero
/* 6D8670 80224600 00000000 */  nop       
/* 6D8674 80224604 00000012 */  mflo      $zero
/* 6D8678 80224608 00000000 */  nop       
/* 6D867C 8022460C 00000043 */  sra       $zero, $zero, 1
/* 6D8680 80224610 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D8684 80224614 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D8688 80224618 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D868C 8022461C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8690 80224620 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D8694 80224624 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D8698 80224628 00000043 */  sra       $zero, $zero, 1
/* 6D869C 8022462C 00000003 */  sra       $zero, $zero, 0
/* 6D86A0 80224630 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D86A4 80224634 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D86A8 80224638 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D86AC 8022463C 00000010 */  mfhi      $zero
/* 6D86B0 80224640 00000002 */  srl       $zero, $zero, 0
/* 6D86B4 80224644 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D86B8 80224648 00080000 */  sll       $zero, $t0, 0
/* 6D86BC 8022464C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D86C0 80224650 00000002 */  srl       $zero, $zero, 0
/* 6D86C4 80224654 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D86C8 80224658 0000000C */  syscall   
/* 6D86CC 8022465C 00000027 */  not       $zero, $zero
/* 6D86D0 80224660 00000002 */  srl       $zero, $zero, 0
/* 6D86D4 80224664 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D86D8 80224668 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D86DC 8022466C 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D86E0 80224670 00000002 */  srl       $zero, $zero, 0
/* 6D86E4 80224674 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D86E8 80224678 00000002 */  srl       $zero, $zero, 0
/* 6D86EC 8022467C 00000043 */  sra       $zero, $zero, 1
/* 6D86F0 80224680 0000000F */  sync      
/* 6D86F4 80224684 802D829C */  lb        $t5, -0x7d64($at)
/* 6D86F8 80224688 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D86FC 8022468C 00000000 */  nop       
/* 6D8700 80224690 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8704 80224694 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D8708 80224698 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D870C 8022469C F24A7AFB */  scd       $t2, 0x7afb($s2)
/* 6D8710 802246A0 0000001E */  ddiv      $zero, $zero, $zero
/* 6D8714 802246A4 00000000 */  nop       
/* 6D8718 802246A8 00000000 */  nop       
/* 6D871C 802246AC 00000000 */  nop       
/* 6D8720 802246B0 00000000 */  nop       
/* 6D8724 802246B4 00000000 */  nop       
/* 6D8728 802246B8 00000000 */  nop       
/* 6D872C 802246BC 00000000 */  nop       
/* 6D8730 802246C0 00000012 */  mflo      $zero
/* 6D8734 802246C4 00000000 */  nop       
/* 6D8738 802246C8 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D873C 802246CC 00000002 */  srl       $zero, $zero, 0
/* 6D8740 802246D0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8744 802246D4 0000001E */  ddiv      $zero, $zero, $zero
/* 6D8748 802246D8 00000027 */  not       $zero, $zero
/* 6D874C 802246DC 00000002 */  srl       $zero, $zero, 0
/* 6D8750 802246E0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D8754 802246E4 00000024 */  and       $zero, $zero, $zero
/* 6D8758 802246E8 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D875C 802246EC 00000002 */  srl       $zero, $zero, 0
/* 6D8760 802246F0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D8764 802246F4 00000002 */  srl       $zero, $zero, 0
/* 6D8768 802246F8 00000043 */  sra       $zero, $zero, 1
/* 6D876C 802246FC 0000000F */  sync      
/* 6D8770 80224700 802D829C */  lb        $t5, -0x7d64($at)
/* 6D8774 80224704 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D8778 80224708 00000000 */  nop       
/* 6D877C 8022470C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8780 80224710 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D8784 80224714 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D8788 80224718 F24A7BB4 */  scd       $t2, 0x7bb4($s2)
/* 6D878C 8022471C 0000001E */  ddiv      $zero, $zero, $zero
/* 6D8790 80224720 00000000 */  nop       
/* 6D8794 80224724 00000000 */  nop       
/* 6D8798 80224728 00000000 */  nop       
/* 6D879C 8022472C 00000000 */  nop       
/* 6D87A0 80224730 00000000 */  nop       
/* 6D87A4 80224734 00000000 */  nop       
/* 6D87A8 80224738 00000000 */  nop       
/* 6D87AC 8022473C 00000013 */  mtlo      $zero
/* 6D87B0 80224740 00000000 */  nop       
/* 6D87B4 80224744 00000013 */  mtlo      $zero
/* 6D87B8 80224748 00000000 */  nop       
/* 6D87BC 8022474C 00000008 */  jr        $zero
/* 6D87C0 80224750 00000001 */   movf     $zero, $zero, $fcc0
/* 6D87C4 80224754 0000001E */  ddiv      $zero, $zero, $zero
/* 6D87C8 80224758 00000043 */  sra       $zero, $zero, 1
/* 6D87CC 8022475C 00000003 */  sra       $zero, $zero, 0
/* 6D87D0 80224760 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D87D4 80224764 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D87D8 80224768 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D87DC 8022476C 00000011 */  mthi      $zero
/* 6D87E0 80224770 00000002 */  srl       $zero, $zero, 0
/* 6D87E4 80224774 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D87E8 80224778 00000200 */  sll       $zero, $zero, 8
/* 6D87EC 8022477C 00000043 */  sra       $zero, $zero, 1
/* 6D87F0 80224780 00000004 */  sllv      $zero, $zero, $zero
/* 6D87F4 80224784 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D87F8 80224788 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D87FC 8022478C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8800 80224790 00560001 */  .byte     0x00, 0x56, 0x00, 0x01
/* 6D8804 80224794 00000012 */  mflo      $zero
/* 6D8808 80224798 00000000 */  nop       
/* 6D880C 8022479C 00000043 */  sra       $zero, $zero, 1
/* 6D8810 802247A0 00000004 */  sllv      $zero, $zero, $zero
/* 6D8814 802247A4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D8818 802247A8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D881C 802247AC 00000002 */  srl       $zero, $zero, 0
/* 6D8820 802247B0 00570001 */  .byte     0x00, 0x57, 0x00, 0x01
/* 6D8824 802247B4 00000013 */  mtlo      $zero
/* 6D8828 802247B8 00000000 */  nop       
/* 6D882C 802247BC 00000008 */  jr        $zero
/* 6D8830 802247C0 00000001 */   movf     $zero, $zero, $fcc0
/* 6D8834 802247C4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D8838 802247C8 00000056 */  drotrv    $zero, $zero, $zero
/* 6D883C 802247CC 00000000 */  nop       
/* 6D8840 802247D0 00000008 */  jr        $zero
/* 6D8844 802247D4 00000001 */   movf     $zero, $zero, $fcc0
/* 6D8848 802247D8 0000000A */  movz      $zero, $zero, $zero
/* 6D884C 802247DC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D8850 802247E0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8854 802247E4 00000004 */  sllv      $zero, $zero, $zero
/* 6D8858 802247E8 00000043 */  sra       $zero, $zero, 1
/* 6D885C 802247EC 00000003 */  sra       $zero, $zero, 0
/* 6D8860 802247F0 8025385C */  lb        $a1, 0x385c($at)
/* 6D8864 802247F4 FE363C88 */  sd        $s6, 0x3c88($s1)
/* 6D8868 802247F8 000003D2 */  .byte     0x00, 0x00, 0x03, 0xd2
/* 6D886C 802247FC 00000043 */  sra       $zero, $zero, 1
/* 6D8870 80224800 00000003 */  sra       $zero, $zero, 0
/* 6D8874 80224804 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D8878 80224808 00000003 */  sra       $zero, $zero, 0
/* 6D887C 8022480C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8880 80224810 00000027 */  not       $zero, $zero
/* 6D8884 80224814 00000002 */  srl       $zero, $zero, 0
/* 6D8888 80224818 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D888C 8022481C 00000003 */  sra       $zero, $zero, 0
/* 6D8890 80224820 00000008 */  jr        $zero
/* 6D8894 80224824 00000001 */   movf     $zero, $zero, $fcc0
/* 6D8898 80224828 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D889C 8022482C 00000006 */  srlv      $zero, $zero, $zero
/* 6D88A0 80224830 00000000 */  nop       
/* 6D88A4 80224834 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D88A8 80224838 00000000 */  nop       
/* 6D88AC 8022483C 00000056 */  drotrv    $zero, $zero, $zero
/* 6D88B0 80224840 00000000 */  nop       
/* 6D88B4 80224844 00000043 */  sra       $zero, $zero, 1
/* 6D88B8 80224848 00000002 */  srl       $zero, $zero, 0
/* 6D88BC 8022484C 8026BF48 */  lb        $a2, -0x40b8($at)
/* 6D88C0 80224850 00000001 */  movf      $zero, $zero, $fcc0
/* 6D88C4 80224854 00000043 */  sra       $zero, $zero, 1
/* 6D88C8 80224858 00000003 */  sra       $zero, $zero, 0
/* 6D88CC 8022485C 8027095C */  lb        $a3, 0x95c($at)
/* 6D88D0 80224860 FE363C88 */  sd        $s6, 0x3c88($s1)
/* 6D88D4 80224864 00000003 */  sra       $zero, $zero, 0
/* 6D88D8 80224868 00000043 */  sra       $zero, $zero, 1
/* 6D88DC 8022486C 00000002 */  srl       $zero, $zero, 0
/* 6D88E0 80224870 8026BF48 */  lb        $a2, -0x40b8($at)
/* 6D88E4 80224874 00000000 */  nop       
/* 6D88E8 80224878 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D88EC 8022487C 00000000 */  nop       
/* 6D88F0 80224880 00000043 */  sra       $zero, $zero, 1
/* 6D88F4 80224884 00000001 */  movf      $zero, $zero, $fcc0
/* 6D88F8 80224888 8027114C */  lb        $a3, 0x114c($at)
/* 6D88FC 8022488C 00000043 */  sra       $zero, $zero, 1
/* 6D8900 80224890 00000002 */  srl       $zero, $zero, 0
/* 6D8904 80224894 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D8908 80224898 00000002 */  srl       $zero, $zero, 0
/* 6D890C 8022489C 00000008 */  jr        $zero
/* 6D8910 802248A0 00000001 */   movf     $zero, $zero, $fcc0
/* 6D8914 802248A4 0000000A */  movz      $zero, $zero, $zero
/* 6D8918 802248A8 00000043 */  sra       $zero, $zero, 1
/* 6D891C 802248AC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8920 802248B0 8027D7F0 */  lb        $a3, -0x2810($at)
/* 6D8924 802248B4 00000043 */  sra       $zero, $zero, 1
/* 6D8928 802248B8 00000003 */  sra       $zero, $zero, 0
/* 6D892C 802248BC 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D8930 802248C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8934 802248C4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8938 802248C8 00000043 */  sra       $zero, $zero, 1
/* 6D893C 802248CC 00000003 */  sra       $zero, $zero, 0
/* 6D8940 802248D0 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D8944 802248D4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8948 802248D8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D894C 802248DC 00000002 */  srl       $zero, $zero, 0
/* 6D8950 802248E0 00000000 */  nop       
/* 6D8954 802248E4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8958 802248E8 00000000 */  nop       
/* 6D895C 802248EC 00000024 */  and       $zero, $zero, $zero
/* 6D8960 802248F0 00000002 */  srl       $zero, $zero, 0
/* 6D8964 802248F4 FBD3E280 */  bbit132   $fp, 0x13, .L8021D2F8
/* 6D8968 802248F8 00000000 */   nop      
/* 6D896C 802248FC 00000003 */  sra       $zero, $zero, 0
/* 6D8970 80224900 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8974 80224904 0000000A */  movz      $zero, $zero, $zero
/* 6D8978 80224908 00000043 */  sra       $zero, $zero, 1
/* 6D897C 8022490C 00000002 */  srl       $zero, $zero, 0
/* 6D8980 80224910 8026E310 */  lb        $a2, -0x1cf0($at)
/* 6D8984 80224914 00008002 */  srl       $s0, $zero, 0
/* 6D8988 80224918 00000043 */  sra       $zero, $zero, 1
/* 6D898C 8022491C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8990 80224920 8026E354 */  lb        $a2, -0x1cac($at)
/* 6D8994 80224924 00000003 */  sra       $zero, $zero, 0
/* 6D8998 80224928 00000001 */  movf      $zero, $zero, $fcc0
/* 6D899C 8022492C 00000000 */  nop       
/* 6D89A0 80224930 00000043 */  sra       $zero, $zero, 1
/* 6D89A4 80224934 00000003 */  sra       $zero, $zero, 0
/* 6D89A8 80224938 8026E8AC */  lb        $a2, -0x1754($at)
/* 6D89AC 8022493C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D89B0 80224940 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D89B4 80224944 00000043 */  sra       $zero, $zero, 1
/* 6D89B8 80224948 00000003 */  sra       $zero, $zero, 0
/* 6D89BC 8022494C 8026A0D4 */  lb        $a2, -0x5f2c($at)
/* 6D89C0 80224950 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D89C4 80224954 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D89C8 80224958 00000043 */  sra       $zero, $zero, 1
/* 6D89CC 8022495C 00000003 */  sra       $zero, $zero, 0
/* 6D89D0 80224960 8026F694 */  lb        $a2, -0x96c($at)
/* 6D89D4 80224964 00000002 */  srl       $zero, $zero, 0
/* 6D89D8 80224968 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D89DC 8022496C 0000000D */  break     
/* 6D89E0 80224970 00000002 */   srl      $zero, $zero, 0
/* 6D89E4 80224974 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D89E8 80224978 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D89EC 8022497C 00000043 */  sra       $zero, $zero, 1
/* 6D89F0 80224980 00000003 */  sra       $zero, $zero, 0
/* 6D89F4 80224984 80218588 */  lb        $at, -0x7a78($at)
/* 6D89F8 80224988 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D89FC 8022498C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D8A00 80224990 0000000A */  movz      $zero, $zero, $zero
/* 6D8A04 80224994 00000002 */  srl       $zero, $zero, 0
/* 6D8A08 80224998 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D8A0C 8022499C 00000000 */  nop       
/* 6D8A10 802249A0 00000043 */  sra       $zero, $zero, 1
/* 6D8A14 802249A4 00000003 */  sra       $zero, $zero, 0
/* 6D8A18 802249A8 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D8A1C 802249AC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8A20 802249B0 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D8A24 802249B4 00000011 */  mthi      $zero
/* 6D8A28 802249B8 00000002 */  srl       $zero, $zero, 0
/* 6D8A2C 802249BC FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D8A30 802249C0 04002000 */  bltz      $zero, .L8022C9C4
/* 6D8A34 802249C4 00000024 */   and      $zero, $zero, $zero
/* 6D8A38 802249C8 00000002 */  srl       $zero, $zero, 0
/* 6D8A3C 802249CC FE363C88 */  sd        $s6, 0x3c88($s1)
/* 6D8A40 802249D0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8A44 802249D4 00000043 */  sra       $zero, $zero, 1
/* 6D8A48 802249D8 00000003 */  sra       $zero, $zero, 0
/* 6D8A4C 802249DC 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D8A50 802249E0 00000002 */  srl       $zero, $zero, 0
/* 6D8A54 802249E4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D8A58 802249E8 00000004 */  sllv      $zero, $zero, $zero
/* 6D8A5C 802249EC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8A60 802249F0 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6D8A64 802249F4 00000013 */  mtlo      $zero
/* 6D8A68 802249F8 00000000 */  nop       
/* 6D8A6C 802249FC 00000013 */  mtlo      $zero
/* 6D8A70 80224A00 00000000 */  nop       
/* 6D8A74 80224A04 00000013 */  mtlo      $zero
/* 6D8A78 80224A08 00000000 */  nop       
/* 6D8A7C 80224A0C 00000043 */  sra       $zero, $zero, 1
/* 6D8A80 80224A10 00000003 */  sra       $zero, $zero, 0
/* 6D8A84 80224A14 8026E414 */  lb        $a2, -0x1bec($at)
/* 6D8A88 80224A18 00000000 */  nop       
/* 6D8A8C 80224A1C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8A90 80224A20 0000000B */  movn      $zero, $zero, $zero
/* 6D8A94 80224A24 00000002 */  srl       $zero, $zero, 0
/* 6D8A98 80224A28 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8A9C 80224A2C FFFFFFFF */  sd        $ra, -1($ra)
/* 6D8AA0 80224A30 00000004 */  sllv      $zero, $zero, $zero
/* 6D8AA4 80224A34 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8AA8 80224A38 00000000 */  nop       
/* 6D8AAC 80224A3C 00000013 */  mtlo      $zero
/* 6D8AB0 80224A40 00000000 */  nop       
/* 6D8AB4 80224A44 0000000A */  movz      $zero, $zero, $zero
/* 6D8AB8 80224A48 00000002 */  srl       $zero, $zero, 0
/* 6D8ABC 80224A4C FBD3E280 */  bbit132   $fp, 0x13, .L8021D450
/* 6D8AC0 80224A50 00000000 */   nop      
/* 6D8AC4 80224A54 00000024 */  and       $zero, $zero, $zero
/* 6D8AC8 80224A58 00000002 */  srl       $zero, $zero, 0
/* 6D8ACC 80224A5C FBD3E280 */  bbit132   $fp, 0x13, .L8021D460
/* 6D8AD0 80224A60 00000001 */   movf     $zero, $zero, $fcc0
/* 6D8AD4 80224A64 00000043 */  sra       $zero, $zero, 1
/* 6D8AD8 80224A68 00000003 */  sra       $zero, $zero, 0
/* 6D8ADC 80224A6C 8026F638 */  lb        $a2, -0x9c8($at)
/* 6D8AE0 80224A70 00000002 */  srl       $zero, $zero, 0
/* 6D8AE4 80224A74 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D8AE8 80224A78 00000004 */  sllv      $zero, $zero, $zero
/* 6D8AEC 80224A7C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8AF0 80224A80 0000000A */  movz      $zero, $zero, $zero
/* 6D8AF4 80224A84 00000013 */  mtlo      $zero
/* 6D8AF8 80224A88 00000000 */  nop       
/* 6D8AFC 80224A8C 00000043 */  sra       $zero, $zero, 1
/* 6D8B00 80224A90 00000004 */  sllv      $zero, $zero, $zero
/* 6D8B04 80224A94 8026A14C */  lb        $a2, -0x5eb4($at)
/* 6D8B08 80224A98 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8B0C 80224A9C 00008002 */  srl       $s0, $zero, 0
/* 6D8B10 80224AA0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8B14 80224AA4 0000000A */  movz      $zero, $zero, $zero
/* 6D8B18 80224AA8 00000002 */  srl       $zero, $zero, 0
/* 6D8B1C 80224AAC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8B20 80224AB0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8B24 80224AB4 00000046 */  rotrv     $zero, $zero, $zero
/* 6D8B28 80224AB8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8B2C 80224ABC 8021F39C */  lb        $at, -0xc64($at)
/* 6D8B30 80224AC0 00000002 */  srl       $zero, $zero, 0
/* 6D8B34 80224AC4 00000000 */  nop       
/* 6D8B38 80224AC8 00000013 */  mtlo      $zero
/* 6D8B3C 80224ACC 00000000 */  nop       
/* 6D8B40 80224AD0 00000046 */  rotrv     $zero, $zero, $zero
/* 6D8B44 80224AD4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8B48 80224AD8 8022179C */  lb        $v0, 0x179c($at)
/* 6D8B4C 80224ADC 00000002 */  srl       $zero, $zero, 0
/* 6D8B50 80224AE0 00000000 */  nop       
/* 6D8B54 80224AE4 00000003 */  sra       $zero, $zero, 0
/* 6D8B58 80224AE8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8B5C 80224AEC 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6D8B60 80224AF0 00000043 */  sra       $zero, $zero, 1
/* 6D8B64 80224AF4 00000004 */  sllv      $zero, $zero, $zero
/* 6D8B68 80224AF8 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D8B6C 80224AFC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8B70 80224B00 0000000A */  movz      $zero, $zero, $zero
/* 6D8B74 80224B04 00000000 */  nop       
/* 6D8B78 80224B08 00000043 */  sra       $zero, $zero, 1
/* 6D8B7C 80224B0C 00000004 */  sllv      $zero, $zero, $zero
/* 6D8B80 80224B10 8026C044 */  lb        $a2, -0x3fbc($at)
/* 6D8B84 80224B14 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8B88 80224B18 0000000B */  movn      $zero, $zero, $zero
/* 6D8B8C 80224B1C 00000007 */  srav      $zero, $zero, $zero
/* 6D8B90 80224B20 00000043 */  sra       $zero, $zero, 1
/* 6D8B94 80224B24 00000004 */  sllv      $zero, $zero, $zero
/* 6D8B98 80224B28 8026C0D4 */  lb        $a2, -0x3f2c($at)
/* 6D8B9C 80224B2C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8BA0 80224B30 00000008 */  jr        $zero
/* 6D8BA4 80224B34 00000001 */   movf     $zero, $zero, $fcc0
/* 6D8BA8 80224B38 00000043 */  sra       $zero, $zero, 1
/* 6D8BAC 80224B3C 00000003 */  sra       $zero, $zero, 0
/* 6D8BB0 80224B40 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D8BB4 80224B44 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8BB8 80224B48 00000000 */  nop       
/* 6D8BBC 80224B4C 00000043 */  sra       $zero, $zero, 1
/* 6D8BC0 80224B50 00000003 */  sra       $zero, $zero, 0
/* 6D8BC4 80224B54 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D8BC8 80224B58 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8BCC 80224B5C 00000000 */  nop       
/* 6D8BD0 80224B60 00000043 */  sra       $zero, $zero, 1
/* 6D8BD4 80224B64 00000003 */  sra       $zero, $zero, 0
/* 6D8BD8 80224B68 8027C548 */  lb        $a3, -0x3ab8($at)
/* 6D8BDC 80224B6C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8BE0 80224B70 00000000 */  nop       
/* 6D8BE4 80224B74 00000043 */  sra       $zero, $zero, 1
/* 6D8BE8 80224B78 00000002 */  srl       $zero, $zero, 0
/* 6D8BEC 80224B7C 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D8BF0 80224B80 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D8BF4 80224B84 00000043 */  sra       $zero, $zero, 1
/* 6D8BF8 80224B88 00000002 */  srl       $zero, $zero, 0
/* 6D8BFC 80224B8C 8024EB24 */  lb        $a0, -0x14dc($at)
/* 6D8C00 80224B90 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8C04 80224B94 00000043 */  sra       $zero, $zero, 1
/* 6D8C08 80224B98 00000002 */  srl       $zero, $zero, 0
/* 6D8C0C 80224B9C 8024EC08 */  lb        $a0, -0x13f8($at)
/* 6D8C10 80224BA0 0000000F */  sync      
/* 6D8C14 80224BA4 00000008 */  jr        $zero
/* 6D8C18 80224BA8 00000001 */   movf     $zero, $zero, $fcc0
/* 6D8C1C 80224BAC 0000000F */  sync      
/* 6D8C20 80224BB0 00000043 */  sra       $zero, $zero, 1
/* 6D8C24 80224BB4 00000003 */  sra       $zero, $zero, 0
/* 6D8C28 80224BB8 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D8C2C 80224BBC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8C30 80224BC0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8C34 80224BC4 00000011 */  mthi      $zero
/* 6D8C38 80224BC8 00000002 */  srl       $zero, $zero, 0
/* 6D8C3C 80224BCC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8C40 80224BD0 00000200 */  sll       $zero, $zero, 8
/* 6D8C44 80224BD4 00000043 */  sra       $zero, $zero, 1
/* 6D8C48 80224BD8 00000004 */  sllv      $zero, $zero, $zero
/* 6D8C4C 80224BDC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D8C50 80224BE0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8C54 80224BE4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8C58 80224BE8 00560002 */  .byte     0x00, 0x56, 0x00, 0x02
/* 6D8C5C 80224BEC 00000012 */  mflo      $zero
/* 6D8C60 80224BF0 00000000 */  nop       
/* 6D8C64 80224BF4 00000043 */  sra       $zero, $zero, 1
/* 6D8C68 80224BF8 00000004 */  sllv      $zero, $zero, $zero
/* 6D8C6C 80224BFC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D8C70 80224C00 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8C74 80224C04 00000002 */  srl       $zero, $zero, 0
/* 6D8C78 80224C08 00570002 */  .byte     0x00, 0x57, 0x00, 0x02
/* 6D8C7C 80224C0C 00000013 */  mtlo      $zero
/* 6D8C80 80224C10 00000000 */  nop       
/* 6D8C84 80224C14 00000008 */  jr        $zero
/* 6D8C88 80224C18 00000001 */   movf     $zero, $zero, $fcc0
/* 6D8C8C 80224C1C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D8C90 80224C20 00000043 */  sra       $zero, $zero, 1
/* 6D8C94 80224C24 00000003 */  sra       $zero, $zero, 0
/* 6D8C98 80224C28 8025385C */  lb        $a1, 0x385c($at)
/* 6D8C9C 80224C2C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8CA0 80224C30 000020D4 */  .byte     0x00, 0x00, 0x20, 0xd4
/* 6D8CA4 80224C34 00000043 */  sra       $zero, $zero, 1
/* 6D8CA8 80224C38 00000003 */  sra       $zero, $zero, 0
/* 6D8CAC 80224C3C 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D8CB0 80224C40 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8CB4 80224C44 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8CB8 80224C48 00000011 */  mthi      $zero
/* 6D8CBC 80224C4C 00000002 */  srl       $zero, $zero, 0
/* 6D8CC0 80224C50 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8CC4 80224C54 00000200 */  sll       $zero, $zero, 8
/* 6D8CC8 80224C58 00000043 */  sra       $zero, $zero, 1
/* 6D8CCC 80224C5C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D8CD0 80224C60 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D8CD4 80224C64 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8CD8 80224C68 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8CDC 80224C6C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D8CE0 80224C70 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D8CE4 80224C74 00000043 */  sra       $zero, $zero, 1
/* 6D8CE8 80224C78 00000003 */  sra       $zero, $zero, 0
/* 6D8CEC 80224C7C 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D8CF0 80224C80 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8CF4 80224C84 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D8CF8 80224C88 00000010 */  mfhi      $zero
/* 6D8CFC 80224C8C 00000002 */  srl       $zero, $zero, 0
/* 6D8D00 80224C90 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D8D04 80224C94 00080000 */  sll       $zero, $t0, 0
/* 6D8D08 80224C98 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D8D0C 80224C9C 00000002 */  srl       $zero, $zero, 0
/* 6D8D10 80224CA0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8D14 80224CA4 00000006 */  srlv      $zero, $zero, $zero
/* 6D8D18 80224CA8 00000027 */  not       $zero, $zero
/* 6D8D1C 80224CAC 00000002 */  srl       $zero, $zero, 0
/* 6D8D20 80224CB0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D8D24 80224CB4 0000000C */  syscall   
/* 6D8D28 80224CB8 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D8D2C 80224CBC 00000002 */  srl       $zero, $zero, 0
/* 6D8D30 80224CC0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D8D34 80224CC4 00000002 */  srl       $zero, $zero, 0
/* 6D8D38 80224CC8 00000043 */  sra       $zero, $zero, 1
/* 6D8D3C 80224CCC 0000000F */  sync      
/* 6D8D40 80224CD0 802D829C */  lb        $t5, -0x7d64($at)
/* 6D8D44 80224CD4 00000033 */  tltu      $zero, $zero
/* 6D8D48 80224CD8 00000006 */  srlv      $zero, $zero, $zero
/* 6D8D4C 80224CDC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8D50 80224CE0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D8D54 80224CE4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D8D58 80224CE8 F24A7AFB */  scd       $t2, 0x7afb($s2)
/* 6D8D5C 80224CEC 0000001E */  ddiv      $zero, $zero, $zero
/* 6D8D60 80224CF0 00000000 */  nop       
/* 6D8D64 80224CF4 00000000 */  nop       
/* 6D8D68 80224CF8 00000000 */  nop       
/* 6D8D6C 80224CFC 00000000 */  nop       
/* 6D8D70 80224D00 00000000 */  nop       
/* 6D8D74 80224D04 00000000 */  nop       
/* 6D8D78 80224D08 00000000 */  nop       
/* 6D8D7C 80224D0C 00000012 */  mflo      $zero
/* 6D8D80 80224D10 00000000 */  nop       
/* 6D8D84 80224D14 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D8D88 80224D18 00000002 */  srl       $zero, $zero, 0
/* 6D8D8C 80224D1C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8D90 80224D20 00000010 */  mfhi      $zero
/* 6D8D94 80224D24 00000027 */  not       $zero, $zero
/* 6D8D98 80224D28 00000002 */  srl       $zero, $zero, 0
/* 6D8D9C 80224D2C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D8DA0 80224D30 0000001F */  ddivu     $zero, $zero, $zero
/* 6D8DA4 80224D34 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D8DA8 80224D38 00000002 */  srl       $zero, $zero, 0
/* 6D8DAC 80224D3C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D8DB0 80224D40 00000002 */  srl       $zero, $zero, 0
/* 6D8DB4 80224D44 00000043 */  sra       $zero, $zero, 1
/* 6D8DB8 80224D48 0000000F */  sync      
/* 6D8DBC 80224D4C 802D829C */  lb        $t5, -0x7d64($at)
/* 6D8DC0 80224D50 00000033 */  tltu      $zero, $zero
/* 6D8DC4 80224D54 00000006 */  srlv      $zero, $zero, $zero
/* 6D8DC8 80224D58 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8DCC 80224D5C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D8DD0 80224D60 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D8DD4 80224D64 F24A7BB4 */  scd       $t2, 0x7bb4($s2)
/* 6D8DD8 80224D68 0000001E */  ddiv      $zero, $zero, $zero
/* 6D8DDC 80224D6C 00000000 */  nop       
/* 6D8DE0 80224D70 00000000 */  nop       
/* 6D8DE4 80224D74 00000000 */  nop       
/* 6D8DE8 80224D78 00000000 */  nop       
/* 6D8DEC 80224D7C 00000000 */  nop       
/* 6D8DF0 80224D80 00000000 */  nop       
/* 6D8DF4 80224D84 00000000 */  nop       
/* 6D8DF8 80224D88 00000013 */  mtlo      $zero
/* 6D8DFC 80224D8C 00000000 */  nop       
/* 6D8E00 80224D90 00000012 */  mflo      $zero
/* 6D8E04 80224D94 00000000 */  nop       
/* 6D8E08 80224D98 00000043 */  sra       $zero, $zero, 1
/* 6D8E0C 80224D9C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D8E10 80224DA0 8026AAA8 */  lb        $a2, -0x5558($at)
/* 6D8E14 80224DA4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8E18 80224DA8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8E1C 80224DAC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D8E20 80224DB0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D8E24 80224DB4 00000043 */  sra       $zero, $zero, 1
/* 6D8E28 80224DB8 00000003 */  sra       $zero, $zero, 0
/* 6D8E2C 80224DBC 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D8E30 80224DC0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8E34 80224DC4 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D8E38 80224DC8 00000010 */  mfhi      $zero
/* 6D8E3C 80224DCC 00000002 */  srl       $zero, $zero, 0
/* 6D8E40 80224DD0 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D8E44 80224DD4 00080000 */  sll       $zero, $t0, 0
/* 6D8E48 80224DD8 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D8E4C 80224DDC 00000002 */  srl       $zero, $zero, 0
/* 6D8E50 80224DE0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8E54 80224DE4 0000000C */  syscall   
/* 6D8E58 80224DE8 00000027 */  not       $zero, $zero
/* 6D8E5C 80224DEC 00000002 */  srl       $zero, $zero, 0
/* 6D8E60 80224DF0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D8E64 80224DF4 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D8E68 80224DF8 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D8E6C 80224DFC 00000002 */  srl       $zero, $zero, 0
/* 6D8E70 80224E00 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D8E74 80224E04 00000002 */  srl       $zero, $zero, 0
/* 6D8E78 80224E08 00000043 */  sra       $zero, $zero, 1
/* 6D8E7C 80224E0C 0000000F */  sync      
/* 6D8E80 80224E10 802D829C */  lb        $t5, -0x7d64($at)
/* 6D8E84 80224E14 00000033 */  tltu      $zero, $zero
/* 6D8E88 80224E18 00000006 */  srlv      $zero, $zero, $zero
/* 6D8E8C 80224E1C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8E90 80224E20 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D8E94 80224E24 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D8E98 80224E28 F24A7AFB */  scd       $t2, 0x7afb($s2)
/* 6D8E9C 80224E2C 0000001E */  ddiv      $zero, $zero, $zero
/* 6D8EA0 80224E30 00000000 */  nop       
/* 6D8EA4 80224E34 00000000 */  nop       
/* 6D8EA8 80224E38 00000000 */  nop       
/* 6D8EAC 80224E3C 00000000 */  nop       
/* 6D8EB0 80224E40 00000000 */  nop       
/* 6D8EB4 80224E44 00000000 */  nop       
/* 6D8EB8 80224E48 00000000 */  nop       
/* 6D8EBC 80224E4C 00000012 */  mflo      $zero
/* 6D8EC0 80224E50 00000000 */  nop       
/* 6D8EC4 80224E54 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D8EC8 80224E58 00000002 */  srl       $zero, $zero, 0
/* 6D8ECC 80224E5C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8ED0 80224E60 0000001E */  ddiv      $zero, $zero, $zero
/* 6D8ED4 80224E64 00000027 */  not       $zero, $zero
/* 6D8ED8 80224E68 00000002 */  srl       $zero, $zero, 0
/* 6D8EDC 80224E6C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D8EE0 80224E70 00000024 */  and       $zero, $zero, $zero
/* 6D8EE4 80224E74 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D8EE8 80224E78 00000002 */  srl       $zero, $zero, 0
/* 6D8EEC 80224E7C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D8EF0 80224E80 00000002 */  srl       $zero, $zero, 0
/* 6D8EF4 80224E84 00000043 */  sra       $zero, $zero, 1
/* 6D8EF8 80224E88 0000000F */  sync      
/* 6D8EFC 80224E8C 802D829C */  lb        $t5, -0x7d64($at)
/* 6D8F00 80224E90 00000033 */  tltu      $zero, $zero
/* 6D8F04 80224E94 00000006 */  srlv      $zero, $zero, $zero
/* 6D8F08 80224E98 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8F0C 80224E9C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D8F10 80224EA0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D8F14 80224EA4 F24A7BB4 */  scd       $t2, 0x7bb4($s2)
/* 6D8F18 80224EA8 0000001E */  ddiv      $zero, $zero, $zero
/* 6D8F1C 80224EAC 00000000 */  nop       
/* 6D8F20 80224EB0 00000000 */  nop       
/* 6D8F24 80224EB4 00000000 */  nop       
/* 6D8F28 80224EB8 00000000 */  nop       
/* 6D8F2C 80224EBC 00000000 */  nop       
/* 6D8F30 80224EC0 00000000 */  nop       
/* 6D8F34 80224EC4 00000000 */  nop       
/* 6D8F38 80224EC8 00000013 */  mtlo      $zero
/* 6D8F3C 80224ECC 00000000 */  nop       
/* 6D8F40 80224ED0 00000013 */  mtlo      $zero
/* 6D8F44 80224ED4 00000000 */  nop       
/* 6D8F48 80224ED8 00000008 */  jr        $zero
/* 6D8F4C 80224EDC 00000001 */   movf     $zero, $zero, $fcc0
/* 6D8F50 80224EE0 0000001E */  ddiv      $zero, $zero, $zero
/* 6D8F54 80224EE4 00000043 */  sra       $zero, $zero, 1
/* 6D8F58 80224EE8 00000003 */  sra       $zero, $zero, 0
/* 6D8F5C 80224EEC 8026CF20 */  lb        $a2, -0x30e0($at)
/* 6D8F60 80224EF0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8F64 80224EF4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8F68 80224EF8 00000011 */  mthi      $zero
/* 6D8F6C 80224EFC 00000002 */  srl       $zero, $zero, 0
/* 6D8F70 80224F00 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D8F74 80224F04 00000200 */  sll       $zero, $zero, 8
/* 6D8F78 80224F08 00000043 */  sra       $zero, $zero, 1
/* 6D8F7C 80224F0C 00000004 */  sllv      $zero, $zero, $zero
/* 6D8F80 80224F10 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D8F84 80224F14 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8F88 80224F18 00000001 */  movf      $zero, $zero, $fcc0
/* 6D8F8C 80224F1C 00560001 */  .byte     0x00, 0x56, 0x00, 0x01
/* 6D8F90 80224F20 00000012 */  mflo      $zero
/* 6D8F94 80224F24 00000000 */  nop       
/* 6D8F98 80224F28 00000043 */  sra       $zero, $zero, 1
/* 6D8F9C 80224F2C 00000004 */  sllv      $zero, $zero, $zero
/* 6D8FA0 80224F30 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 6D8FA4 80224F34 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D8FA8 80224F38 00000002 */  srl       $zero, $zero, 0
/* 6D8FAC 80224F3C 00570001 */  .byte     0x00, 0x57, 0x00, 0x01
/* 6D8FB0 80224F40 00000013 */  mtlo      $zero
/* 6D8FB4 80224F44 00000000 */  nop       
/* 6D8FB8 80224F48 00000008 */  jr        $zero
/* 6D8FBC 80224F4C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D8FC0 80224F50 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D8FC4 80224F54 00000056 */  drotrv    $zero, $zero, $zero
/* 6D8FC8 80224F58 00000000 */  nop       
/* 6D8FCC 80224F5C 00000008 */  jr        $zero
/* 6D8FD0 80224F60 00000001 */   movf     $zero, $zero, $fcc0
/* 6D8FD4 80224F64 0000000A */  movz      $zero, $zero, $zero
/* 6D8FD8 80224F68 00000043 */  sra       $zero, $zero, 1
/* 6D8FDC 80224F6C 00000003 */  sra       $zero, $zero, 0
/* 6D8FE0 80224F70 8025385C */  lb        $a1, 0x385c($at)
/* 6D8FE4 80224F74 FE363C88 */  sd        $s6, 0x3c88($s1)
/* 6D8FE8 80224F78 000002DB */  .byte     0x00, 0x00, 0x02, 0xdb
/* 6D8FEC 80224F7C 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D8FF0 80224F80 00000000 */  nop       
/* 6D8FF4 80224F84 00000056 */  drotrv    $zero, $zero, $zero
/* 6D8FF8 80224F88 00000000 */  nop       
/* 6D8FFC 80224F8C 00000043 */  sra       $zero, $zero, 1
/* 6D9000 80224F90 00000002 */  srl       $zero, $zero, 0
/* 6D9004 80224F94 8026BF48 */  lb        $a2, -0x40b8($at)
/* 6D9008 80224F98 00000001 */  movf      $zero, $zero, $fcc0
/* 6D900C 80224F9C 00000043 */  sra       $zero, $zero, 1
/* 6D9010 80224FA0 00000003 */  sra       $zero, $zero, 0
/* 6D9014 80224FA4 80270614 */  lb        $a3, 0x614($at)
/* 6D9018 80224FA8 FE363C88 */  sd        $s6, 0x3c88($s1)
/* 6D901C 80224FAC 00000002 */  srl       $zero, $zero, 0
/* 6D9020 80224FB0 00000043 */  sra       $zero, $zero, 1
/* 6D9024 80224FB4 00000002 */  srl       $zero, $zero, 0
/* 6D9028 80224FB8 8026BF48 */  lb        $a2, -0x40b8($at)
/* 6D902C 80224FBC 00000000 */  nop       
/* 6D9030 80224FC0 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6D9034 80224FC4 00000000 */  nop       
/* 6D9038 80224FC8 00000043 */  sra       $zero, $zero, 1
/* 6D903C 80224FCC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9040 80224FD0 8027114C */  lb        $a3, 0x114c($at)
/* 6D9044 80224FD4 00000043 */  sra       $zero, $zero, 1
/* 6D9048 80224FD8 00000002 */  srl       $zero, $zero, 0
/* 6D904C 80224FDC 8024E61C */  lb        $a0, -0x19e4($at)
/* 6D9050 80224FE0 00000002 */  srl       $zero, $zero, 0
/* 6D9054 80224FE4 00000008 */  jr        $zero
/* 6D9058 80224FE8 00000001 */   movf     $zero, $zero, $fcc0
/* 6D905C 80224FEC 0000000A */  movz      $zero, $zero, $zero
/* 6D9060 80224FF0 00000043 */  sra       $zero, $zero, 1
/* 6D9064 80224FF4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9068 80224FF8 8027D7F0 */  lb        $a3, -0x2810($at)
/* 6D906C 80224FFC 00000043 */  sra       $zero, $zero, 1
/* 6D9070 80225000 00000003 */  sra       $zero, $zero, 0
/* 6D9074 80225004 80278B4C */  lb        $a3, -0x74b4($at)
/* 6D9078 80225008 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D907C 8022500C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9080 80225010 00000043 */  sra       $zero, $zero, 1
/* 6D9084 80225014 00000003 */  sra       $zero, $zero, 0
/* 6D9088 80225018 8026F0EC */  lb        $a2, -0xf14($at)
/* 6D908C 8022501C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D9090 80225020 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9094 80225024 00000002 */  srl       $zero, $zero, 0
/* 6D9098 80225028 00000000 */  nop       
/* 6D909C 8022502C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D90A0 80225030 00000000 */  nop       
/* 6D90A4 80225034 00000043 */  sra       $zero, $zero, 1
/* 6D90A8 80225038 00000002 */  srl       $zero, $zero, 0
/* 6D90AC 8022503C 80269E28 */  lb        $a2, -0x61d8($at)
/* 6D90B0 80225040 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D90B4 80225044 0000000A */  movz      $zero, $zero, $zero
/* 6D90B8 80225048 00000002 */  srl       $zero, $zero, 0
/* 6D90BC 8022504C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D90C0 80225050 00000001 */  movf      $zero, $zero, $fcc0
/* 6D90C4 80225054 00000046 */  rotrv     $zero, $zero, $zero
/* 6D90C8 80225058 00000001 */  movf      $zero, $zero, $fcc0
/* 6D90CC 8022505C 8022179C */  lb        $v0, 0x179c($at)
/* 6D90D0 80225060 00000002 */  srl       $zero, $zero, 0
/* 6D90D4 80225064 00000000 */  nop       
/* 6D90D8 80225068 00000013 */  mtlo      $zero
/* 6D90DC 8022506C 00000000 */  nop       
/* 6D90E0 80225070 00000043 */  sra       $zero, $zero, 1
/* 6D90E4 80225074 00000004 */  sllv      $zero, $zero, $zero
/* 6D90E8 80225078 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D90EC 8022507C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D90F0 80225080 0000000A */  movz      $zero, $zero, $zero
/* 6D90F4 80225084 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D90F8 80225088 0000000A */  movz      $zero, $zero, $zero
/* 6D90FC 8022508C 00000002 */  srl       $zero, $zero, 0
/* 6D9100 80225090 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9104 80225094 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9108 80225098 00000004 */  sllv      $zero, $zero, $zero
/* 6D910C 8022509C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9110 802250A0 00000014 */  dsllv     $zero, $zero, $zero
/* 6D9114 802250A4 00000013 */  mtlo      $zero
/* 6D9118 802250A8 00000000 */  nop       
/* 6D911C 802250AC 00000024 */  and       $zero, $zero, $zero
/* 6D9120 802250B0 00000002 */  srl       $zero, $zero, 0
/* 6D9124 802250B4 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D9128 802250B8 00000000 */  nop       
/* 6D912C 802250BC 00000043 */  sra       $zero, $zero, 1
/* 6D9130 802250C0 00000002 */  srl       $zero, $zero, 0
/* 6D9134 802250C4 8026E310 */  lb        $a2, -0x1cf0($at)
/* 6D9138 802250C8 00008002 */  srl       $s0, $zero, 0
/* 6D913C 802250CC 00000043 */  sra       $zero, $zero, 1
/* 6D9140 802250D0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9144 802250D4 8026E354 */  lb        $a2, -0x1cac($at)
/* 6D9148 802250D8 00000003 */  sra       $zero, $zero, 0
/* 6D914C 802250DC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9150 802250E0 00000000 */  nop       
/* 6D9154 802250E4 00000024 */  and       $zero, $zero, $zero
/* 6D9158 802250E8 00000002 */  srl       $zero, $zero, 0
/* 6D915C 802250EC FBD3E280 */  bbit132   $fp, 0x13, .L8021DAF0
/* 6D9160 802250F0 00000000 */   nop      
/* 6D9164 802250F4 00000043 */  sra       $zero, $zero, 1
/* 6D9168 802250F8 00000003 */  sra       $zero, $zero, 0
/* 6D916C 802250FC 8026E8AC */  lb        $a2, -0x1754($at)
/* 6D9170 80225100 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9174 80225104 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D9178 80225108 00000043 */  sra       $zero, $zero, 1
/* 6D917C 8022510C 00000003 */  sra       $zero, $zero, 0
/* 6D9180 80225110 8027DA68 */  lb        $a3, -0x2598($at)
/* 6D9184 80225114 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9188 80225118 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D918C 8022511C 0000000A */  movz      $zero, $zero, $zero
/* 6D9190 80225120 00000002 */  srl       $zero, $zero, 0
/* 6D9194 80225124 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D9198 80225128 00000047 */  .byte     0x00, 0x00, 0x00, 0x47
/* 6D919C 8022512C 00000043 */  sra       $zero, $zero, 1
/* 6D91A0 80225130 00000004 */  sllv      $zero, $zero, $zero
/* 6D91A4 80225134 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D91A8 80225138 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D91AC 8022513C 00000008 */  jr        $zero
/* 6D91B0 80225140 FE363C81 */   sd       $s6, 0x3c81($s1)
/* 6D91B4 80225144 0000000A */  movz      $zero, $zero, $zero
/* 6D91B8 80225148 00000002 */  srl       $zero, $zero, 0
/* 6D91BC 8022514C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D91C0 80225150 00000001 */  movf      $zero, $zero, $fcc0
/* 6D91C4 80225154 00000024 */  and       $zero, $zero, $zero
/* 6D91C8 80225158 00000002 */  srl       $zero, $zero, 0
/* 6D91CC 8022515C FBD3E280 */  bbit132   $fp, 0x13, .L8021DB60
/* 6D91D0 80225160 00000001 */   movf     $zero, $zero, $fcc0
/* 6D91D4 80225164 00000013 */  mtlo      $zero
/* 6D91D8 80225168 00000000 */  nop       
/* 6D91DC 8022516C 00000013 */  mtlo      $zero
/* 6D91E0 80225170 00000000 */  nop       
/* 6D91E4 80225174 00000043 */  sra       $zero, $zero, 1
/* 6D91E8 80225178 00000003 */  sra       $zero, $zero, 0
/* 6D91EC 8022517C 8027C6A0 */  lb        $a3, -0x3960($at)
/* 6D91F0 80225180 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D91F4 80225184 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D91F8 80225188 00000043 */  sra       $zero, $zero, 1
/* 6D91FC 8022518C 00000003 */  sra       $zero, $zero, 0
/* 6D9200 80225190 8027C748 */  lb        $a3, -0x38b8($at)
/* 6D9204 80225194 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9208 80225198 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D920C 8022519C 0000002E */  dsub      $zero, $zero, $zero
/* 6D9210 802251A0 00000002 */  srl       $zero, $zero, 0
/* 6D9214 802251A4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D9218 802251A8 F24C0A80 */  scd       $t4, 0xa80($s2)
/* 6D921C 802251AC 0000002F */  dsubu     $zero, $zero, $zero
/* 6D9220 802251B0 00000002 */  srl       $zero, $zero, 0
/* 6D9224 802251B4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D9228 802251B8 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D922C 802251BC 0000000A */  movz      $zero, $zero, $zero
/* 6D9230 802251C0 00000002 */  srl       $zero, $zero, 0
/* 6D9234 802251C4 FBD3E280 */  bbit132   $fp, 0x13, .L8021DBC8
/* 6D9238 802251C8 00000000 */   nop      
/* 6D923C 802251CC 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D9240 802251D0 00000002 */  srl       $zero, $zero, 0
/* 6D9244 802251D4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D9248 802251D8 00000019 */  multu     $zero, $zero
/* 6D924C 802251DC 00000043 */  sra       $zero, $zero, 1
/* 6D9250 802251E0 00000003 */  sra       $zero, $zero, 0
/* 6D9254 802251E4 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D9258 802251E8 00000063 */  .byte     0x00, 0x00, 0x00, 0x63
/* 6D925C 802251EC FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D9260 802251F0 00000027 */  not       $zero, $zero
/* 6D9264 802251F4 00000002 */  srl       $zero, $zero, 0
/* 6D9268 802251F8 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D926C 802251FC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9270 80225200 0000000C */  syscall   
/* 6D9274 80225204 00000002 */  srl       $zero, $zero, 0
/* 6D9278 80225208 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D927C 8022520C 0000004B */  .byte     0x00, 0x00, 0x00, 0x4b
/* 6D9280 80225210 00000027 */  not       $zero, $zero
/* 6D9284 80225214 00000002 */  srl       $zero, $zero, 0
/* 6D9288 80225218 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D928C 8022521C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9290 80225220 00000024 */  and       $zero, $zero, $zero
/* 6D9294 80225224 00000002 */  srl       $zero, $zero, 0
/* 6D9298 80225228 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6D929C 8022522C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D92A0 80225230 00000013 */  mtlo      $zero
/* 6D92A4 80225234 00000000 */  nop       
/* 6D92A8 80225238 00000013 */  mtlo      $zero
/* 6D92AC 8022523C 00000000 */  nop       
/* 6D92B0 80225240 00000013 */  mtlo      $zero
/* 6D92B4 80225244 00000000 */  nop       
/* 6D92B8 80225248 00000043 */  sra       $zero, $zero, 1
/* 6D92BC 8022524C 00000003 */  sra       $zero, $zero, 0
/* 6D92C0 80225250 8026E414 */  lb        $a2, -0x1bec($at)
/* 6D92C4 80225254 00000000 */  nop       
/* 6D92C8 80225258 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D92CC 8022525C 0000000B */  movn      $zero, $zero, $zero
/* 6D92D0 80225260 00000002 */  srl       $zero, $zero, 0
/* 6D92D4 80225264 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D92D8 80225268 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D92DC 8022526C 00000004 */  sllv      $zero, $zero, $zero
/* 6D92E0 80225270 00000001 */  movf      $zero, $zero, $fcc0
/* 6D92E4 80225274 00000000 */  nop       
/* 6D92E8 80225278 00000013 */  mtlo      $zero
/* 6D92EC 8022527C 00000000 */  nop       
/* 6D92F0 80225280 0000000D */  break     
/* 6D92F4 80225284 00000002 */   srl      $zero, $zero, 0
/* 6D92F8 80225288 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D92FC 8022528C 00000000 */  nop       
/* 6D9300 80225290 00000004 */  sllv      $zero, $zero, $zero
/* 6D9304 80225294 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9308 80225298 0000000A */  movz      $zero, $zero, $zero
/* 6D930C 8022529C 00000013 */  mtlo      $zero
/* 6D9310 802252A0 00000000 */  nop       
/* 6D9314 802252A4 00000024 */  and       $zero, $zero, $zero
/* 6D9318 802252A8 00000002 */  srl       $zero, $zero, 0
/* 6D931C 802252AC FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D9320 802252B0 00000000 */  nop       
/* 6D9324 802252B4 00000043 */  sra       $zero, $zero, 1
/* 6D9328 802252B8 00000002 */  srl       $zero, $zero, 0
/* 6D932C 802252BC 8026E310 */  lb        $a2, -0x1cf0($at)
/* 6D9330 802252C0 00008002 */  srl       $s0, $zero, 0
/* 6D9334 802252C4 00000043 */  sra       $zero, $zero, 1
/* 6D9338 802252C8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D933C 802252CC 8026E354 */  lb        $a2, -0x1cac($at)
/* 6D9340 802252D0 00000003 */  sra       $zero, $zero, 0
/* 6D9344 802252D4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9348 802252D8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D934C 802252DC 00000024 */  and       $zero, $zero, $zero
/* 6D9350 802252E0 00000002 */  srl       $zero, $zero, 0
/* 6D9354 802252E4 FBD3E280 */  bbit132   $fp, 0x13, .L8021DCE8
/* 6D9358 802252E8 00000000 */   nop      
/* 6D935C 802252EC 00000043 */  sra       $zero, $zero, 1
/* 6D9360 802252F0 00000003 */  sra       $zero, $zero, 0
/* 6D9364 802252F4 8026E8AC */  lb        $a2, -0x1754($at)
/* 6D9368 802252F8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D936C 802252FC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D9370 80225300 00000043 */  sra       $zero, $zero, 1
/* 6D9374 80225304 00000003 */  sra       $zero, $zero, 0
/* 6D9378 80225308 8027DA68 */  lb        $a3, -0x2598($at)
/* 6D937C 8022530C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9380 80225310 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D9384 80225314 0000000A */  movz      $zero, $zero, $zero
/* 6D9388 80225318 00000002 */  srl       $zero, $zero, 0
/* 6D938C 8022531C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D9390 80225320 00000047 */  .byte     0x00, 0x00, 0x00, 0x47
/* 6D9394 80225324 00000043 */  sra       $zero, $zero, 1
/* 6D9398 80225328 00000004 */  sllv      $zero, $zero, $zero
/* 6D939C 8022532C 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D93A0 80225330 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D93A4 80225334 00000008 */  jr        $zero
/* 6D93A8 80225338 FE363C81 */   sd       $s6, 0x3c81($s1)
/* 6D93AC 8022533C 0000000A */  movz      $zero, $zero, $zero
/* 6D93B0 80225340 00000002 */  srl       $zero, $zero, 0
/* 6D93B4 80225344 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D93B8 80225348 00000001 */  movf      $zero, $zero, $fcc0
/* 6D93BC 8022534C 00000024 */  and       $zero, $zero, $zero
/* 6D93C0 80225350 00000002 */  srl       $zero, $zero, 0
/* 6D93C4 80225354 FBD3E280 */  bbit132   $fp, 0x13, .L8021DD58
/* 6D93C8 80225358 00000001 */   movf     $zero, $zero, $fcc0
/* 6D93CC 8022535C 00000013 */  mtlo      $zero
/* 6D93D0 80225360 00000000 */  nop       
/* 6D93D4 80225364 00000013 */  mtlo      $zero
/* 6D93D8 80225368 00000000 */  nop       
/* 6D93DC 8022536C 00000043 */  sra       $zero, $zero, 1
/* 6D93E0 80225370 00000003 */  sra       $zero, $zero, 0
/* 6D93E4 80225374 8027C6A0 */  lb        $a3, -0x3960($at)
/* 6D93E8 80225378 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D93EC 8022537C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D93F0 80225380 00000043 */  sra       $zero, $zero, 1
/* 6D93F4 80225384 00000003 */  sra       $zero, $zero, 0
/* 6D93F8 80225388 8027C748 */  lb        $a3, -0x38b8($at)
/* 6D93FC 8022538C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9400 80225390 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D9404 80225394 0000002E */  dsub      $zero, $zero, $zero
/* 6D9408 80225398 00000002 */  srl       $zero, $zero, 0
/* 6D940C 8022539C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D9410 802253A0 F24C0A80 */  scd       $t4, 0xa80($s2)
/* 6D9414 802253A4 0000002F */  dsubu     $zero, $zero, $zero
/* 6D9418 802253A8 00000002 */  srl       $zero, $zero, 0
/* 6D941C 802253AC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D9420 802253B0 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D9424 802253B4 0000000A */  movz      $zero, $zero, $zero
/* 6D9428 802253B8 00000002 */  srl       $zero, $zero, 0
/* 6D942C 802253BC FBD3E280 */  bbit132   $fp, 0x13, .L8021DDC0
/* 6D9430 802253C0 00000000 */   nop      
/* 6D9434 802253C4 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D9438 802253C8 00000002 */  srl       $zero, $zero, 0
/* 6D943C 802253CC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D9440 802253D0 00000014 */  dsllv     $zero, $zero, $zero
/* 6D9444 802253D4 00000043 */  sra       $zero, $zero, 1
/* 6D9448 802253D8 00000003 */  sra       $zero, $zero, 0
/* 6D944C 802253DC 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D9450 802253E0 00000063 */  .byte     0x00, 0x00, 0x00, 0x63
/* 6D9454 802253E4 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D9458 802253E8 00000027 */  not       $zero, $zero
/* 6D945C 802253EC 00000002 */  srl       $zero, $zero, 0
/* 6D9460 802253F0 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D9464 802253F4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9468 802253F8 0000000C */  syscall   
/* 6D946C 802253FC 00000002 */  srl       $zero, $zero, 0
/* 6D9470 80225400 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D9474 80225404 00000050 */  .byte     0x00, 0x00, 0x00, 0x50
/* 6D9478 80225408 00000027 */  not       $zero, $zero
/* 6D947C 8022540C 00000002 */  srl       $zero, $zero, 0
/* 6D9480 80225410 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D9484 80225414 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9488 80225418 00000024 */  and       $zero, $zero, $zero
/* 6D948C 8022541C 00000002 */  srl       $zero, $zero, 0
/* 6D9490 80225420 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6D9494 80225424 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9498 80225428 00000013 */  mtlo      $zero
/* 6D949C 8022542C 00000000 */  nop       
/* 6D94A0 80225430 00000013 */  mtlo      $zero
/* 6D94A4 80225434 00000000 */  nop       
/* 6D94A8 80225438 00000013 */  mtlo      $zero
/* 6D94AC 8022543C 00000000 */  nop       
/* 6D94B0 80225440 00000043 */  sra       $zero, $zero, 1
/* 6D94B4 80225444 00000003 */  sra       $zero, $zero, 0
/* 6D94B8 80225448 8026E414 */  lb        $a2, -0x1bec($at)
/* 6D94BC 8022544C 00000000 */  nop       
/* 6D94C0 80225450 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D94C4 80225454 0000000B */  movn      $zero, $zero, $zero
/* 6D94C8 80225458 00000002 */  srl       $zero, $zero, 0
/* 6D94CC 8022545C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D94D0 80225460 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D94D4 80225464 00000004 */  sllv      $zero, $zero, $zero
/* 6D94D8 80225468 00000001 */  movf      $zero, $zero, $fcc0
/* 6D94DC 8022546C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D94E0 80225470 00000013 */  mtlo      $zero
/* 6D94E4 80225474 00000000 */  nop       
/* 6D94E8 80225478 0000000D */  break     
/* 6D94EC 8022547C 00000002 */   srl      $zero, $zero, 0
/* 6D94F0 80225480 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D94F4 80225484 00000000 */  nop       
/* 6D94F8 80225488 00000004 */  sllv      $zero, $zero, $zero
/* 6D94FC 8022548C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9500 80225490 0000000A */  movz      $zero, $zero, $zero
/* 6D9504 80225494 00000013 */  mtlo      $zero
/* 6D9508 80225498 00000000 */  nop       
/* 6D950C 8022549C 00000024 */  and       $zero, $zero, $zero
/* 6D9510 802254A0 00000002 */  srl       $zero, $zero, 0
/* 6D9514 802254A4 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D9518 802254A8 00000000 */  nop       
/* 6D951C 802254AC 00000043 */  sra       $zero, $zero, 1
/* 6D9520 802254B0 00000002 */  srl       $zero, $zero, 0
/* 6D9524 802254B4 8026E310 */  lb        $a2, -0x1cf0($at)
/* 6D9528 802254B8 00008002 */  srl       $s0, $zero, 0
/* 6D952C 802254BC 00000043 */  sra       $zero, $zero, 1
/* 6D9530 802254C0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9534 802254C4 8026E354 */  lb        $a2, -0x1cac($at)
/* 6D9538 802254C8 00000003 */  sra       $zero, $zero, 0
/* 6D953C 802254CC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9540 802254D0 00000002 */  srl       $zero, $zero, 0
/* 6D9544 802254D4 00000024 */  and       $zero, $zero, $zero
/* 6D9548 802254D8 00000002 */  srl       $zero, $zero, 0
/* 6D954C 802254DC FBD3E280 */  bbit132   $fp, 0x13, .L8021DEE0
/* 6D9550 802254E0 00000000 */   nop      
/* 6D9554 802254E4 00000043 */  sra       $zero, $zero, 1
/* 6D9558 802254E8 00000003 */  sra       $zero, $zero, 0
/* 6D955C 802254EC 8026E8AC */  lb        $a2, -0x1754($at)
/* 6D9560 802254F0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9564 802254F4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D9568 802254F8 00000043 */  sra       $zero, $zero, 1
/* 6D956C 802254FC 00000003 */  sra       $zero, $zero, 0
/* 6D9570 80225500 8027DA68 */  lb        $a3, -0x2598($at)
/* 6D9574 80225504 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9578 80225508 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D957C 8022550C 0000000A */  movz      $zero, $zero, $zero
/* 6D9580 80225510 00000002 */  srl       $zero, $zero, 0
/* 6D9584 80225514 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D9588 80225518 00000047 */  .byte     0x00, 0x00, 0x00, 0x47
/* 6D958C 8022551C 00000043 */  sra       $zero, $zero, 1
/* 6D9590 80225520 00000004 */  sllv      $zero, $zero, $zero
/* 6D9594 80225524 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D9598 80225528 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D959C 8022552C 00000008 */  jr        $zero
/* 6D95A0 80225530 FE363C81 */   sd       $s6, 0x3c81($s1)
/* 6D95A4 80225534 0000000A */  movz      $zero, $zero, $zero
/* 6D95A8 80225538 00000002 */  srl       $zero, $zero, 0
/* 6D95AC 8022553C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D95B0 80225540 00000001 */  movf      $zero, $zero, $fcc0
/* 6D95B4 80225544 00000024 */  and       $zero, $zero, $zero
/* 6D95B8 80225548 00000002 */  srl       $zero, $zero, 0
/* 6D95BC 8022554C FBD3E280 */  bbit132   $fp, 0x13, .L8021DF50
/* 6D95C0 80225550 00000001 */   movf     $zero, $zero, $fcc0
/* 6D95C4 80225554 00000013 */  mtlo      $zero
/* 6D95C8 80225558 00000000 */  nop       
/* 6D95CC 8022555C 00000013 */  mtlo      $zero
/* 6D95D0 80225560 00000000 */  nop       
/* 6D95D4 80225564 00000043 */  sra       $zero, $zero, 1
/* 6D95D8 80225568 00000003 */  sra       $zero, $zero, 0
/* 6D95DC 8022556C 8027C6A0 */  lb        $a3, -0x3960($at)
/* 6D95E0 80225570 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D95E4 80225574 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D95E8 80225578 00000043 */  sra       $zero, $zero, 1
/* 6D95EC 8022557C 00000003 */  sra       $zero, $zero, 0
/* 6D95F0 80225580 8027C748 */  lb        $a3, -0x38b8($at)
/* 6D95F4 80225584 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D95F8 80225588 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D95FC 8022558C 0000002E */  dsub      $zero, $zero, $zero
/* 6D9600 80225590 00000002 */  srl       $zero, $zero, 0
/* 6D9604 80225594 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D9608 80225598 F24C0A80 */  scd       $t4, 0xa80($s2)
/* 6D960C 8022559C 0000002F */  dsubu     $zero, $zero, $zero
/* 6D9610 802255A0 00000002 */  srl       $zero, $zero, 0
/* 6D9614 802255A4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D9618 802255A8 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D961C 802255AC 0000000A */  movz      $zero, $zero, $zero
/* 6D9620 802255B0 00000002 */  srl       $zero, $zero, 0
/* 6D9624 802255B4 FBD3E280 */  bbit132   $fp, 0x13, .L8021DFB8
/* 6D9628 802255B8 00000000 */   nop      
/* 6D962C 802255BC 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D9630 802255C0 00000002 */  srl       $zero, $zero, 0
/* 6D9634 802255C4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D9638 802255C8 0000000F */  sync      
/* 6D963C 802255CC 00000043 */  sra       $zero, $zero, 1
/* 6D9640 802255D0 00000003 */  sra       $zero, $zero, 0
/* 6D9644 802255D4 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D9648 802255D8 00000063 */  .byte     0x00, 0x00, 0x00, 0x63
/* 6D964C 802255DC FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D9650 802255E0 00000027 */  not       $zero, $zero
/* 6D9654 802255E4 00000002 */  srl       $zero, $zero, 0
/* 6D9658 802255E8 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D965C 802255EC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9660 802255F0 0000000C */  syscall   
/* 6D9664 802255F4 00000002 */  srl       $zero, $zero, 0
/* 6D9668 802255F8 FE363C84 */  sd        $s6, 0x3c84($s1)
/* 6D966C 802255FC 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6D9670 80225600 00000027 */  not       $zero, $zero
/* 6D9674 80225604 00000002 */  srl       $zero, $zero, 0
/* 6D9678 80225608 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D967C 8022560C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9680 80225610 00000024 */  and       $zero, $zero, $zero
/* 6D9684 80225614 00000002 */  srl       $zero, $zero, 0
/* 6D9688 80225618 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6D968C 8022561C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9690 80225620 00000013 */  mtlo      $zero
/* 6D9694 80225624 00000000 */  nop       
/* 6D9698 80225628 00000013 */  mtlo      $zero
/* 6D969C 8022562C 00000000 */  nop       
/* 6D96A0 80225630 00000013 */  mtlo      $zero
/* 6D96A4 80225634 00000000 */  nop       
/* 6D96A8 80225638 00000043 */  sra       $zero, $zero, 1
/* 6D96AC 8022563C 00000003 */  sra       $zero, $zero, 0
/* 6D96B0 80225640 8026E414 */  lb        $a2, -0x1bec($at)
/* 6D96B4 80225644 00000000 */  nop       
/* 6D96B8 80225648 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D96BC 8022564C 0000000B */  movn      $zero, $zero, $zero
/* 6D96C0 80225650 00000002 */  srl       $zero, $zero, 0
/* 6D96C4 80225654 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D96C8 80225658 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D96CC 8022565C 00000004 */  sllv      $zero, $zero, $zero
/* 6D96D0 80225660 00000001 */  movf      $zero, $zero, $fcc0
/* 6D96D4 80225664 00000002 */  srl       $zero, $zero, 0
/* 6D96D8 80225668 00000013 */  mtlo      $zero
/* 6D96DC 8022566C 00000000 */  nop       
/* 6D96E0 80225670 0000000D */  break     
/* 6D96E4 80225674 00000002 */   srl      $zero, $zero, 0
/* 6D96E8 80225678 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D96EC 8022567C 00000000 */  nop       
/* 6D96F0 80225680 00000004 */  sllv      $zero, $zero, $zero
/* 6D96F4 80225684 00000001 */  movf      $zero, $zero, $fcc0
/* 6D96F8 80225688 0000000A */  movz      $zero, $zero, $zero
/* 6D96FC 8022568C 00000013 */  mtlo      $zero
/* 6D9700 80225690 00000000 */  nop       
/* 6D9704 80225694 00000004 */  sllv      $zero, $zero, $zero
/* 6D9708 80225698 00000001 */  movf      $zero, $zero, $fcc0
/* 6D970C 8022569C 00000014 */  dsllv     $zero, $zero, $zero
/* 6D9710 802256A0 00000003 */  sra       $zero, $zero, 0
/* 6D9714 802256A4 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9718 802256A8 0000000A */  movz      $zero, $zero, $zero
/* 6D971C 802256AC 00000043 */  sra       $zero, $zero, 1
/* 6D9720 802256B0 00000004 */  sllv      $zero, $zero, $zero
/* 6D9724 802256B4 8026A14C */  lb        $a2, -0x5eb4($at)
/* 6D9728 802256B8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D972C 802256BC 00008002 */  srl       $s0, $zero, 0
/* 6D9730 802256C0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9734 802256C4 0000000A */  movz      $zero, $zero, $zero
/* 6D9738 802256C8 00000002 */  srl       $zero, $zero, 0
/* 6D973C 802256CC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9740 802256D0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9744 802256D4 00000046 */  rotrv     $zero, $zero, $zero
/* 6D9748 802256D8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D974C 802256DC 8021F39C */  lb        $at, -0xc64($at)
/* 6D9750 802256E0 00000002 */  srl       $zero, $zero, 0
/* 6D9754 802256E4 00000000 */  nop       
/* 6D9758 802256E8 00000013 */  mtlo      $zero
/* 6D975C 802256EC 00000000 */  nop       
/* 6D9760 802256F0 0000000A */  movz      $zero, $zero, $zero
/* 6D9764 802256F4 00000002 */  srl       $zero, $zero, 0
/* 6D9768 802256F8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D976C 802256FC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9770 80225700 00000043 */  sra       $zero, $zero, 1
/* 6D9774 80225704 00000004 */  sllv      $zero, $zero, $zero
/* 6D9778 80225708 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D977C 8022570C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D9780 80225710 00000004 */  sllv      $zero, $zero, $zero
/* 6D9784 80225714 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9788 80225718 0000000C */  syscall   
/* 6D978C 8022571C 00000002 */  srl       $zero, $zero, 0
/* 6D9790 80225720 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9794 80225724 00000002 */  srl       $zero, $zero, 0
/* 6D9798 80225728 00000043 */  sra       $zero, $zero, 1
/* 6D979C 8022572C 00000003 */  sra       $zero, $zero, 0
/* 6D97A0 80225730 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D97A4 80225734 000003E8 */  .byte     0x00, 0x00, 0x03, 0xe8
/* 6D97A8 80225738 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D97AC 8022573C 0000000C */  syscall   
/* 6D97B0 80225740 00000002 */  srl       $zero, $zero, 0
/* 6D97B4 80225744 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D97B8 80225748 000001F4 */  teq       $zero, $zero, 7
/* 6D97BC 8022574C 00000046 */  rotrv     $zero, $zero, $zero
/* 6D97C0 80225750 00000001 */  movf      $zero, $zero, $fcc0
/* 6D97C4 80225754 80220B70 */  lb        $v0, 0xb70($at)
/* 6D97C8 80225758 00000002 */  srl       $zero, $zero, 0
/* 6D97CC 8022575C 00000000 */  nop       
/* 6D97D0 80225760 00000013 */  mtlo      $zero
/* 6D97D4 80225764 00000000 */  nop       
/* 6D97D8 80225768 00000012 */  mflo      $zero
/* 6D97DC 8022576C 00000000 */  nop       
/* 6D97E0 80225770 00000043 */  sra       $zero, $zero, 1
/* 6D97E4 80225774 00000004 */  sllv      $zero, $zero, $zero
/* 6D97E8 80225778 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D97EC 8022577C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D97F0 80225780 00000003 */  sra       $zero, $zero, 0
/* 6D97F4 80225784 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D97F8 80225788 0000000C */  syscall   
/* 6D97FC 8022578C 00000002 */  srl       $zero, $zero, 0
/* 6D9800 80225790 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9804 80225794 00000002 */  srl       $zero, $zero, 0
/* 6D9808 80225798 00000043 */  sra       $zero, $zero, 1
/* 6D980C 8022579C 00000003 */  sra       $zero, $zero, 0
/* 6D9810 802257A0 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D9814 802257A4 000003E8 */  .byte     0x00, 0x00, 0x03, 0xe8
/* 6D9818 802257A8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D981C 802257AC 0000000C */  syscall   
/* 6D9820 802257B0 00000002 */  srl       $zero, $zero, 0
/* 6D9824 802257B4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9828 802257B8 000001F4 */  teq       $zero, $zero, 7
/* 6D982C 802257BC 00000046 */  rotrv     $zero, $zero, $zero
/* 6D9830 802257C0 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9834 802257C4 802210FC */  lb        $v0, 0x10fc($at)
/* 6D9838 802257C8 00000002 */  srl       $zero, $zero, 0
/* 6D983C 802257CC 00000000 */  nop       
/* 6D9840 802257D0 00000013 */  mtlo      $zero
/* 6D9844 802257D4 00000000 */  nop       
/* 6D9848 802257D8 00000013 */  mtlo      $zero
/* 6D984C 802257DC 00000000 */  nop       
/* 6D9850 802257E0 00000013 */  mtlo      $zero
/* 6D9854 802257E4 00000000 */  nop       
/* 6D9858 802257E8 00000012 */  mflo      $zero
/* 6D985C 802257EC 00000000 */  nop       
/* 6D9860 802257F0 00000043 */  sra       $zero, $zero, 1
/* 6D9864 802257F4 00000004 */  sllv      $zero, $zero, $zero
/* 6D9868 802257F8 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D986C 802257FC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D9870 80225800 00000003 */  sra       $zero, $zero, 0
/* 6D9874 80225804 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9878 80225808 0000000C */  syscall   
/* 6D987C 8022580C 00000002 */  srl       $zero, $zero, 0
/* 6D9880 80225810 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9884 80225814 00000002 */  srl       $zero, $zero, 0
/* 6D9888 80225818 00000043 */  sra       $zero, $zero, 1
/* 6D988C 8022581C 00000003 */  sra       $zero, $zero, 0
/* 6D9890 80225820 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D9894 80225824 000003E8 */  .byte     0x00, 0x00, 0x03, 0xe8
/* 6D9898 80225828 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D989C 8022582C 0000000C */  syscall   
/* 6D98A0 80225830 00000002 */  srl       $zero, $zero, 0
/* 6D98A4 80225834 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D98A8 80225838 000001F4 */  teq       $zero, $zero, 7
/* 6D98AC 8022583C 00000046 */  rotrv     $zero, $zero, $zero
/* 6D98B0 80225840 00000001 */  movf      $zero, $zero, $fcc0
/* 6D98B4 80225844 802210FC */  lb        $v0, 0x10fc($at)
/* 6D98B8 80225848 00000002 */  srl       $zero, $zero, 0
/* 6D98BC 8022584C 00000000 */  nop       
/* 6D98C0 80225850 00000013 */  mtlo      $zero
/* 6D98C4 80225854 00000000 */  nop       
/* 6D98C8 80225858 00000012 */  mflo      $zero
/* 6D98CC 8022585C 00000000 */  nop       
/* 6D98D0 80225860 00000043 */  sra       $zero, $zero, 1
/* 6D98D4 80225864 00000004 */  sllv      $zero, $zero, $zero
/* 6D98D8 80225868 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D98DC 8022586C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D98E0 80225870 00000004 */  sllv      $zero, $zero, $zero
/* 6D98E4 80225874 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D98E8 80225878 0000000C */  syscall   
/* 6D98EC 8022587C 00000002 */  srl       $zero, $zero, 0
/* 6D98F0 80225880 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D98F4 80225884 00000002 */  srl       $zero, $zero, 0
/* 6D98F8 80225888 00000026 */  xor       $zero, $zero, $zero
/* 6D98FC 8022588C 00000002 */  srl       $zero, $zero, 0
/* 6D9900 80225890 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D9904 80225894 F24C0A80 */  scd       $t4, 0xa80($s2)
/* 6D9908 80225898 00000043 */  sra       $zero, $zero, 1
/* 6D990C 8022589C 00000002 */  srl       $zero, $zero, 0
/* 6D9910 802258A0 8026E310 */  lb        $a2, -0x1cf0($at)
/* 6D9914 802258A4 00008002 */  srl       $s0, $zero, 0
/* 6D9918 802258A8 00000043 */  sra       $zero, $zero, 1
/* 6D991C 802258AC 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9920 802258B0 8026E354 */  lb        $a2, -0x1cac($at)
/* 6D9924 802258B4 00000003 */  sra       $zero, $zero, 0
/* 6D9928 802258B8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D992C 802258BC 0000000B */  movn      $zero, $zero, $zero
/* 6D9930 802258C0 00000024 */  and       $zero, $zero, $zero
/* 6D9934 802258C4 00000002 */  srl       $zero, $zero, 0
/* 6D9938 802258C8 FBD3E280 */  bbit132   $fp, 0x13, .L8021E2CC
/* 6D993C 802258CC 00000000 */   nop      
/* 6D9940 802258D0 00000043 */  sra       $zero, $zero, 1
/* 6D9944 802258D4 00000003 */  sra       $zero, $zero, 0
/* 6D9948 802258D8 8026E8AC */  lb        $a2, -0x1754($at)
/* 6D994C 802258DC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9950 802258E0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D9954 802258E4 00000043 */  sra       $zero, $zero, 1
/* 6D9958 802258E8 00000003 */  sra       $zero, $zero, 0
/* 6D995C 802258EC 8027DA68 */  lb        $a3, -0x2598($at)
/* 6D9960 802258F0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9964 802258F4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D9968 802258F8 0000000A */  movz      $zero, $zero, $zero
/* 6D996C 802258FC 00000002 */  srl       $zero, $zero, 0
/* 6D9970 80225900 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D9974 80225904 00000047 */  .byte     0x00, 0x00, 0x00, 0x47
/* 6D9978 80225908 00000043 */  sra       $zero, $zero, 1
/* 6D997C 8022590C 00000004 */  sllv      $zero, $zero, $zero
/* 6D9980 80225910 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D9984 80225914 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9988 80225918 00000008 */  jr        $zero
/* 6D998C 8022591C FE363C81 */   sd       $s6, 0x3c81($s1)
/* 6D9990 80225920 0000000A */  movz      $zero, $zero, $zero
/* 6D9994 80225924 00000002 */  srl       $zero, $zero, 0
/* 6D9998 80225928 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D999C 8022592C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D99A0 80225930 00000024 */  and       $zero, $zero, $zero
/* 6D99A4 80225934 00000002 */  srl       $zero, $zero, 0
/* 6D99A8 80225938 FBD3E280 */  bbit132   $fp, 0x13, .L8021E33C
/* 6D99AC 8022593C 00000001 */   movf     $zero, $zero, $fcc0
/* 6D99B0 80225940 00000013 */  mtlo      $zero
/* 6D99B4 80225944 00000000 */  nop       
/* 6D99B8 80225948 00000013 */  mtlo      $zero
/* 6D99BC 8022594C 00000000 */  nop       
/* 6D99C0 80225950 00000043 */  sra       $zero, $zero, 1
/* 6D99C4 80225954 00000003 */  sra       $zero, $zero, 0
/* 6D99C8 80225958 8027C6A0 */  lb        $a3, -0x3960($at)
/* 6D99CC 8022595C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D99D0 80225960 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D99D4 80225964 00000043 */  sra       $zero, $zero, 1
/* 6D99D8 80225968 00000003 */  sra       $zero, $zero, 0
/* 6D99DC 8022596C 8027C748 */  lb        $a3, -0x38b8($at)
/* 6D99E0 80225970 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D99E4 80225974 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D99E8 80225978 0000002E */  dsub      $zero, $zero, $zero
/* 6D99EC 8022597C 00000002 */  srl       $zero, $zero, 0
/* 6D99F0 80225980 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D99F4 80225984 F24C0A80 */  scd       $t4, 0xa80($s2)
/* 6D99F8 80225988 0000002F */  dsubu     $zero, $zero, $zero
/* 6D99FC 8022598C 00000002 */  srl       $zero, $zero, 0
/* 6D9A00 80225990 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D9A04 80225994 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6D9A08 80225998 0000000A */  movz      $zero, $zero, $zero
/* 6D9A0C 8022599C 00000002 */  srl       $zero, $zero, 0
/* 6D9A10 802259A0 FBD3E280 */  bbit132   $fp, 0x13, .L8021E3A4
/* 6D9A14 802259A4 00000000 */   nop      
/* 6D9A18 802259A8 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D9A1C 802259AC 00000002 */  srl       $zero, $zero, 0
/* 6D9A20 802259B0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D9A24 802259B4 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D9A28 802259B8 00000026 */  xor       $zero, $zero, $zero
/* 6D9A2C 802259BC 00000002 */  srl       $zero, $zero, 0
/* 6D9A30 802259C0 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D9A34 802259C4 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6D9A38 802259C8 00000024 */  and       $zero, $zero, $zero
/* 6D9A3C 802259CC 00000002 */  srl       $zero, $zero, 0
/* 6D9A40 802259D0 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6D9A44 802259D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9A48 802259D8 00000013 */  mtlo      $zero
/* 6D9A4C 802259DC 00000000 */  nop       
/* 6D9A50 802259E0 00000013 */  mtlo      $zero
/* 6D9A54 802259E4 00000000 */  nop       
/* 6D9A58 802259E8 00000043 */  sra       $zero, $zero, 1
/* 6D9A5C 802259EC 00000003 */  sra       $zero, $zero, 0
/* 6D9A60 802259F0 8026E414 */  lb        $a2, -0x1bec($at)
/* 6D9A64 802259F4 00000000 */  nop       
/* 6D9A68 802259F8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9A6C 802259FC 0000000B */  movn      $zero, $zero, $zero
/* 6D9A70 80225A00 00000002 */  srl       $zero, $zero, 0
/* 6D9A74 80225A04 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9A78 80225A08 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D9A7C 80225A0C 00000004 */  sllv      $zero, $zero, $zero
/* 6D9A80 80225A10 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9A84 80225A14 0000000B */  movn      $zero, $zero, $zero
/* 6D9A88 80225A18 00000013 */  mtlo      $zero
/* 6D9A8C 80225A1C 00000000 */  nop       
/* 6D9A90 80225A20 00000043 */  sra       $zero, $zero, 1
/* 6D9A94 80225A24 00000003 */  sra       $zero, $zero, 0
/* 6D9A98 80225A28 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D9A9C 80225A2C 000003E8 */  .byte     0x00, 0x00, 0x03, 0xe8
/* 6D9AA0 80225A30 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9AA4 80225A34 0000000C */  syscall   
/* 6D9AA8 80225A38 00000002 */  srl       $zero, $zero, 0
/* 6D9AAC 80225A3C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9AB0 80225A40 000001F4 */  teq       $zero, $zero, 7
/* 6D9AB4 80225A44 00000046 */  rotrv     $zero, $zero, $zero
/* 6D9AB8 80225A48 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9ABC 80225A4C 80220B70 */  lb        $v0, 0xb70($at)
/* 6D9AC0 80225A50 00000002 */  srl       $zero, $zero, 0
/* 6D9AC4 80225A54 00000000 */  nop       
/* 6D9AC8 80225A58 00000013 */  mtlo      $zero
/* 6D9ACC 80225A5C 00000000 */  nop       
/* 6D9AD0 80225A60 00000013 */  mtlo      $zero
/* 6D9AD4 80225A64 00000000 */  nop       
/* 6D9AD8 80225A68 00000013 */  mtlo      $zero
/* 6D9ADC 80225A6C 00000000 */  nop       
/* 6D9AE0 80225A70 00000013 */  mtlo      $zero
/* 6D9AE4 80225A74 00000000 */  nop       
/* 6D9AE8 80225A78 00000003 */  sra       $zero, $zero, 0
/* 6D9AEC 80225A7C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9AF0 80225A80 00000014 */  dsllv     $zero, $zero, $zero
/* 6D9AF4 80225A84 00000024 */  and       $zero, $zero, $zero
/* 6D9AF8 80225A88 00000002 */  srl       $zero, $zero, 0
/* 6D9AFC 80225A8C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D9B00 80225A90 0000000A */  movz      $zero, $zero, $zero
/* 6D9B04 80225A94 00000024 */  and       $zero, $zero, $zero
/* 6D9B08 80225A98 00000002 */  srl       $zero, $zero, 0
/* 6D9B0C 80225A9C FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6D9B10 80225AA0 0000000A */  movz      $zero, $zero, $zero
/* 6D9B14 80225AA4 00000024 */  and       $zero, $zero, $zero
/* 6D9B18 80225AA8 00000002 */  srl       $zero, $zero, 0
/* 6D9B1C 80225AAC FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 6D9B20 80225AB0 0000000A */  movz      $zero, $zero, $zero
/* 6D9B24 80225AB4 00000024 */  and       $zero, $zero, $zero
/* 6D9B28 80225AB8 00000002 */  srl       $zero, $zero, 0
/* 6D9B2C 80225ABC FE363C8D */  sd        $s6, 0x3c8d($s1)
/* 6D9B30 80225AC0 0000000A */  movz      $zero, $zero, $zero
/* 6D9B34 80225AC4 00000024 */  and       $zero, $zero, $zero
/* 6D9B38 80225AC8 00000002 */  srl       $zero, $zero, 0
/* 6D9B3C 80225ACC FE363C8E */  sd        $s6, 0x3c8e($s1)
/* 6D9B40 80225AD0 0000000A */  movz      $zero, $zero, $zero
/* 6D9B44 80225AD4 00000024 */  and       $zero, $zero, $zero
/* 6D9B48 80225AD8 00000002 */  srl       $zero, $zero, 0
/* 6D9B4C 80225ADC FE363C8F */  sd        $s6, 0x3c8f($s1)
/* 6D9B50 80225AE0 0000000A */  movz      $zero, $zero, $zero
/* 6D9B54 80225AE4 00000043 */  sra       $zero, $zero, 1
/* 6D9B58 80225AE8 00000004 */  sllv      $zero, $zero, $zero
/* 6D9B5C 80225AEC 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D9B60 80225AF0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D9B64 80225AF4 0000000A */  movz      $zero, $zero, $zero
/* 6D9B68 80225AF8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9B6C 80225AFC 0000000A */  movz      $zero, $zero, $zero
/* 6D9B70 80225B00 00000002 */  srl       $zero, $zero, 0
/* 6D9B74 80225B04 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9B78 80225B08 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9B7C 80225B0C 00000024 */  and       $zero, $zero, $zero
/* 6D9B80 80225B10 00000002 */  srl       $zero, $zero, 0
/* 6D9B84 80225B14 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D9B88 80225B18 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6D9B8C 80225B1C 00000024 */  and       $zero, $zero, $zero
/* 6D9B90 80225B20 00000002 */  srl       $zero, $zero, 0
/* 6D9B94 80225B24 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6D9B98 80225B28 00000000 */  nop       
/* 6D9B9C 80225B2C 00000024 */  and       $zero, $zero, $zero
/* 6D9BA0 80225B30 00000002 */  srl       $zero, $zero, 0
/* 6D9BA4 80225B34 FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 6D9BA8 80225B38 00000000 */  nop       
/* 6D9BAC 80225B3C 00000024 */  and       $zero, $zero, $zero
/* 6D9BB0 80225B40 00000002 */  srl       $zero, $zero, 0
/* 6D9BB4 80225B44 FE363C8D */  sd        $s6, 0x3c8d($s1)
/* 6D9BB8 80225B48 00000000 */  nop       
/* 6D9BBC 80225B4C 00000024 */  and       $zero, $zero, $zero
/* 6D9BC0 80225B50 00000002 */  srl       $zero, $zero, 0
/* 6D9BC4 80225B54 FE363C8E */  sd        $s6, 0x3c8e($s1)
/* 6D9BC8 80225B58 00000000 */  nop       
/* 6D9BCC 80225B5C 00000024 */  and       $zero, $zero, $zero
/* 6D9BD0 80225B60 00000002 */  srl       $zero, $zero, 0
/* 6D9BD4 80225B64 FE363C8F */  sd        $s6, 0x3c8f($s1)
/* 6D9BD8 80225B68 00000000 */  nop       
/* 6D9BDC 80225B6C 00000004 */  sllv      $zero, $zero, $zero
/* 6D9BE0 80225B70 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9BE4 80225B74 0000007B */  dsra      $zero, $zero, 1
/* 6D9BE8 80225B78 00000012 */  mflo      $zero
/* 6D9BEC 80225B7C 00000000 */  nop       
/* 6D9BF0 80225B80 00000046 */  rotrv     $zero, $zero, $zero
/* 6D9BF4 80225B84 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9BF8 80225B88 80222654 */  lb        $v0, 0x2654($at)
/* 6D9BFC 80225B8C 0000000A */  movz      $zero, $zero, $zero
/* 6D9C00 80225B90 00000002 */  srl       $zero, $zero, 0
/* 6D9C04 80225B94 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9C08 80225B98 FFFFFFFF */  sd        $ra, -1($ra)
/* 6D9C0C 80225B9C 00000024 */  and       $zero, $zero, $zero
/* 6D9C10 80225BA0 00000002 */  srl       $zero, $zero, 0
/* 6D9C14 80225BA4 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6D9C18 80225BA8 00000000 */  nop       
/* 6D9C1C 80225BAC 00000013 */  mtlo      $zero
/* 6D9C20 80225BB0 00000000 */  nop       
/* 6D9C24 80225BB4 00000013 */  mtlo      $zero
/* 6D9C28 80225BB8 00000000 */  nop       
/* 6D9C2C 80225BBC 00000043 */  sra       $zero, $zero, 1
/* 6D9C30 80225BC0 00000003 */  sra       $zero, $zero, 0
/* 6D9C34 80225BC4 8026F230 */  lb        $a2, -0xdd0($at)
/* 6D9C38 80225BC8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D9C3C 80225BCC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9C40 80225BD0 0000000B */  movn      $zero, $zero, $zero
/* 6D9C44 80225BD4 00000002 */  srl       $zero, $zero, 0
/* 6D9C48 80225BD8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9C4C 80225BDC 00000000 */  nop       
/* 6D9C50 80225BE0 00000024 */  and       $zero, $zero, $zero
/* 6D9C54 80225BE4 00000002 */  srl       $zero, $zero, 0
/* 6D9C58 80225BE8 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6D9C5C 80225BEC 00000000 */  nop       
/* 6D9C60 80225BF0 00000013 */  mtlo      $zero
/* 6D9C64 80225BF4 00000000 */  nop       
/* 6D9C68 80225BF8 00000043 */  sra       $zero, $zero, 1
/* 6D9C6C 80225BFC 00000004 */  sllv      $zero, $zero, $zero
/* 6D9C70 80225C00 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D9C74 80225C04 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D9C78 80225C08 0000000B */  movn      $zero, $zero, $zero
/* 6D9C7C 80225C0C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9C80 80225C10 00000014 */  dsllv     $zero, $zero, $zero
/* 6D9C84 80225C14 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9C88 80225C18 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9C8C 80225C1C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D9C90 80225C20 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9C94 80225C24 00000004 */  sllv      $zero, $zero, $zero
/* 6D9C98 80225C28 00000043 */  sra       $zero, $zero, 1
/* 6D9C9C 80225C2C 00000004 */  sllv      $zero, $zero, $zero
/* 6D9CA0 80225C30 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D9CA4 80225C34 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D9CA8 80225C38 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D9CAC 80225C3C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D9CB0 80225C40 0000000C */  syscall   
/* 6D9CB4 80225C44 00000002 */  srl       $zero, $zero, 0
/* 6D9CB8 80225C48 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D9CBC 80225C4C 00000003 */  sra       $zero, $zero, 0
/* 6D9CC0 80225C50 00000043 */  sra       $zero, $zero, 1
/* 6D9CC4 80225C54 00000003 */  sra       $zero, $zero, 0
/* 6D9CC8 80225C58 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D9CCC 80225C5C 00000063 */  .byte     0x00, 0x00, 0x00, 0x63
/* 6D9CD0 80225C60 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9CD4 80225C64 00000027 */  not       $zero, $zero
/* 6D9CD8 80225C68 00000002 */  srl       $zero, $zero, 0
/* 6D9CDC 80225C6C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9CE0 80225C70 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9CE4 80225C74 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D9CE8 80225C78 00000002 */  srl       $zero, $zero, 0
/* 6D9CEC 80225C7C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9CF0 80225C80 00000032 */  tlt       $zero, $zero
/* 6D9CF4 80225C84 00000024 */  and       $zero, $zero, $zero
/* 6D9CF8 80225C88 00000002 */  srl       $zero, $zero, 0
/* 6D9CFC 80225C8C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D9D00 80225C90 00000000 */  nop       
/* 6D9D04 80225C94 00000024 */  and       $zero, $zero, $zero
/* 6D9D08 80225C98 00000002 */  srl       $zero, $zero, 0
/* 6D9D0C 80225C9C FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6D9D10 80225CA0 00000000 */  nop       
/* 6D9D14 80225CA4 00000024 */  and       $zero, $zero, $zero
/* 6D9D18 80225CA8 00000002 */  srl       $zero, $zero, 0
/* 6D9D1C 80225CAC FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 6D9D20 80225CB0 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6D9D24 80225CB4 00000024 */  and       $zero, $zero, $zero
/* 6D9D28 80225CB8 00000002 */  srl       $zero, $zero, 0
/* 6D9D2C 80225CBC FE363C8D */  sd        $s6, 0x3c8d($s1)
/* 6D9D30 80225CC0 00000000 */  nop       
/* 6D9D34 80225CC4 00000024 */  and       $zero, $zero, $zero
/* 6D9D38 80225CC8 00000002 */  srl       $zero, $zero, 0
/* 6D9D3C 80225CCC FE363C8E */  sd        $s6, 0x3c8e($s1)
/* 6D9D40 80225CD0 00000000 */  nop       
/* 6D9D44 80225CD4 00000024 */  and       $zero, $zero, $zero
/* 6D9D48 80225CD8 00000002 */  srl       $zero, $zero, 0
/* 6D9D4C 80225CDC FE363C8F */  sd        $s6, 0x3c8f($s1)
/* 6D9D50 80225CE0 00000000 */  nop       
/* 6D9D54 80225CE4 00000013 */  mtlo      $zero
/* 6D9D58 80225CE8 00000000 */  nop       
/* 6D9D5C 80225CEC 00000013 */  mtlo      $zero
/* 6D9D60 80225CF0 00000000 */  nop       
/* 6D9D64 80225CF4 00000016 */  dsrlv     $zero, $zero, $zero
/* 6D9D68 80225CF8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9D6C 80225CFC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D9D70 80225D00 00000043 */  sra       $zero, $zero, 1
/* 6D9D74 80225D04 00000004 */  sllv      $zero, $zero, $zero
/* 6D9D78 80225D08 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D9D7C 80225D0C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D9D80 80225D10 00000006 */  srlv      $zero, $zero, $zero
/* 6D9D84 80225D14 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D9D88 80225D18 0000000C */  syscall   
/* 6D9D8C 80225D1C 00000002 */  srl       $zero, $zero, 0
/* 6D9D90 80225D20 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6D9D94 80225D24 00000003 */  sra       $zero, $zero, 0
/* 6D9D98 80225D28 00000043 */  sra       $zero, $zero, 1
/* 6D9D9C 80225D2C 00000003 */  sra       $zero, $zero, 0
/* 6D9DA0 80225D30 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D9DA4 80225D34 00000063 */  .byte     0x00, 0x00, 0x00, 0x63
/* 6D9DA8 80225D38 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9DAC 80225D3C 00000027 */  not       $zero, $zero
/* 6D9DB0 80225D40 00000002 */  srl       $zero, $zero, 0
/* 6D9DB4 80225D44 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9DB8 80225D48 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9DBC 80225D4C 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D9DC0 80225D50 00000002 */  srl       $zero, $zero, 0
/* 6D9DC4 80225D54 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9DC8 80225D58 00000032 */  tlt       $zero, $zero
/* 6D9DCC 80225D5C 00000024 */  and       $zero, $zero, $zero
/* 6D9DD0 80225D60 00000002 */  srl       $zero, $zero, 0
/* 6D9DD4 80225D64 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D9DD8 80225D68 00000000 */  nop       
/* 6D9DDC 80225D6C 00000024 */  and       $zero, $zero, $zero
/* 6D9DE0 80225D70 00000002 */  srl       $zero, $zero, 0
/* 6D9DE4 80225D74 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6D9DE8 80225D78 00000000 */  nop       
/* 6D9DEC 80225D7C 00000024 */  and       $zero, $zero, $zero
/* 6D9DF0 80225D80 00000002 */  srl       $zero, $zero, 0
/* 6D9DF4 80225D84 FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 6D9DF8 80225D88 00000000 */  nop       
/* 6D9DFC 80225D8C 00000024 */  and       $zero, $zero, $zero
/* 6D9E00 80225D90 00000002 */  srl       $zero, $zero, 0
/* 6D9E04 80225D94 FE363C8D */  sd        $s6, 0x3c8d($s1)
/* 6D9E08 80225D98 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6D9E0C 80225D9C 00000024 */  and       $zero, $zero, $zero
/* 6D9E10 80225DA0 00000002 */  srl       $zero, $zero, 0
/* 6D9E14 80225DA4 FE363C8E */  sd        $s6, 0x3c8e($s1)
/* 6D9E18 80225DA8 00000000 */  nop       
/* 6D9E1C 80225DAC 00000024 */  and       $zero, $zero, $zero
/* 6D9E20 80225DB0 00000002 */  srl       $zero, $zero, 0
/* 6D9E24 80225DB4 FE363C8F */  sd        $s6, 0x3c8f($s1)
/* 6D9E28 80225DB8 00000000 */  nop       
/* 6D9E2C 80225DBC 00000013 */  mtlo      $zero
/* 6D9E30 80225DC0 00000000 */  nop       
/* 6D9E34 80225DC4 00000013 */  mtlo      $zero
/* 6D9E38 80225DC8 00000000 */  nop       
/* 6D9E3C 80225DCC 00000023 */  negu      $zero, $zero
/* 6D9E40 80225DD0 00000000 */  nop       
/* 6D9E44 80225DD4 00000043 */  sra       $zero, $zero, 1
/* 6D9E48 80225DD8 00000004 */  sllv      $zero, $zero, $zero
/* 6D9E4C 80225DDC 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D9E50 80225DE0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D9E54 80225DE4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6D9E58 80225DE8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9E5C 80225DEC 0000000F */  sync      
/* 6D9E60 80225DF0 00000002 */  srl       $zero, $zero, 0
/* 6D9E64 80225DF4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9E68 80225DF8 00000003 */  sra       $zero, $zero, 0
/* 6D9E6C 80225DFC 00000024 */  and       $zero, $zero, $zero
/* 6D9E70 80225E00 00000002 */  srl       $zero, $zero, 0
/* 6D9E74 80225E04 FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 6D9E78 80225E08 00000000 */  nop       
/* 6D9E7C 80225E0C 00000013 */  mtlo      $zero
/* 6D9E80 80225E10 00000000 */  nop       
/* 6D9E84 80225E14 00000043 */  sra       $zero, $zero, 1
/* 6D9E88 80225E18 00000004 */  sllv      $zero, $zero, $zero
/* 6D9E8C 80225E1C 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D9E90 80225E20 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D9E94 80225E24 00000006 */  srlv      $zero, $zero, $zero
/* 6D9E98 80225E28 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9E9C 80225E2C 0000000F */  sync      
/* 6D9EA0 80225E30 00000002 */  srl       $zero, $zero, 0
/* 6D9EA4 80225E34 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9EA8 80225E38 00000003 */  sra       $zero, $zero, 0
/* 6D9EAC 80225E3C 00000024 */  and       $zero, $zero, $zero
/* 6D9EB0 80225E40 00000002 */  srl       $zero, $zero, 0
/* 6D9EB4 80225E44 FE363C8D */  sd        $s6, 0x3c8d($s1)
/* 6D9EB8 80225E48 00000000 */  nop       
/* 6D9EBC 80225E4C 00000013 */  mtlo      $zero
/* 6D9EC0 80225E50 00000000 */  nop       
/* 6D9EC4 80225E54 00000043 */  sra       $zero, $zero, 1
/* 6D9EC8 80225E58 00000004 */  sllv      $zero, $zero, $zero
/* 6D9ECC 80225E5C 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D9ED0 80225E60 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D9ED4 80225E64 00000007 */  srav      $zero, $zero, $zero
/* 6D9ED8 80225E68 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9EDC 80225E6C 0000000F */  sync      
/* 6D9EE0 80225E70 00000002 */  srl       $zero, $zero, 0
/* 6D9EE4 80225E74 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9EE8 80225E78 00000003 */  sra       $zero, $zero, 0
/* 6D9EEC 80225E7C 00000024 */  and       $zero, $zero, $zero
/* 6D9EF0 80225E80 00000002 */  srl       $zero, $zero, 0
/* 6D9EF4 80225E84 FE363C8E */  sd        $s6, 0x3c8e($s1)
/* 6D9EF8 80225E88 00000000 */  nop       
/* 6D9EFC 80225E8C 00000013 */  mtlo      $zero
/* 6D9F00 80225E90 00000000 */  nop       
/* 6D9F04 80225E94 00000043 */  sra       $zero, $zero, 1
/* 6D9F08 80225E98 00000004 */  sllv      $zero, $zero, $zero
/* 6D9F0C 80225E9C 8026BFB4 */  lb        $a2, -0x404c($at)
/* 6D9F10 80225EA0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 6D9F14 80225EA4 00000008 */  jr        $zero
/* 6D9F18 80225EA8 FE363C80 */   sd       $s6, 0x3c80($s1)
/* 6D9F1C 80225EAC 0000000F */  sync      
/* 6D9F20 80225EB0 00000002 */  srl       $zero, $zero, 0
/* 6D9F24 80225EB4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9F28 80225EB8 00000003 */  sra       $zero, $zero, 0
/* 6D9F2C 80225EBC 00000024 */  and       $zero, $zero, $zero
/* 6D9F30 80225EC0 00000002 */  srl       $zero, $zero, 0
/* 6D9F34 80225EC4 FE363C8F */  sd        $s6, 0x3c8f($s1)
/* 6D9F38 80225EC8 00000000 */  nop       
/* 6D9F3C 80225ECC 00000013 */  mtlo      $zero
/* 6D9F40 80225ED0 00000000 */  nop       
/* 6D9F44 80225ED4 00000003 */  sra       $zero, $zero, 0
/* 6D9F48 80225ED8 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9F4C 80225EDC 0000007B */  dsra      $zero, $zero, 1
/* 6D9F50 80225EE0 00000024 */  and       $zero, $zero, $zero
/* 6D9F54 80225EE4 00000002 */  srl       $zero, $zero, 0
/* 6D9F58 80225EE8 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D9F5C 80225EEC 00000000 */  nop       
/* 6D9F60 80225EF0 00000027 */  not       $zero, $zero
/* 6D9F64 80225EF4 00000002 */  srl       $zero, $zero, 0
/* 6D9F68 80225EF8 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D9F6C 80225EFC FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6D9F70 80225F00 00000027 */  not       $zero, $zero
/* 6D9F74 80225F04 00000002 */  srl       $zero, $zero, 0
/* 6D9F78 80225F08 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D9F7C 80225F0C FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6D9F80 80225F10 00000027 */  not       $zero, $zero
/* 6D9F84 80225F14 00000002 */  srl       $zero, $zero, 0
/* 6D9F88 80225F18 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D9F8C 80225F1C FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 6D9F90 80225F20 00000027 */  not       $zero, $zero
/* 6D9F94 80225F24 00000002 */  srl       $zero, $zero, 0
/* 6D9F98 80225F28 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D9F9C 80225F2C FE363C8D */  sd        $s6, 0x3c8d($s1)
/* 6D9FA0 80225F30 00000027 */  not       $zero, $zero
/* 6D9FA4 80225F34 00000002 */  srl       $zero, $zero, 0
/* 6D9FA8 80225F38 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D9FAC 80225F3C FE363C8E */  sd        $s6, 0x3c8e($s1)
/* 6D9FB0 80225F40 00000027 */  not       $zero, $zero
/* 6D9FB4 80225F44 00000002 */  srl       $zero, $zero, 0
/* 6D9FB8 80225F48 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D9FBC 80225F4C FE363C8F */  sd        $s6, 0x3c8f($s1)
/* 6D9FC0 80225F50 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 6D9FC4 80225F54 00000002 */  srl       $zero, $zero, 0
/* 6D9FC8 80225F58 FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D9FCC 80225F5C 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9FD0 80225F60 00000043 */  sra       $zero, $zero, 1
/* 6D9FD4 80225F64 00000003 */  sra       $zero, $zero, 0
/* 6D9FD8 80225F68 802D46B0 */  lb        $t5, 0x46b0($at)
/* 6D9FDC 80225F6C FE363C89 */  sd        $s6, 0x3c89($s1)
/* 6D9FE0 80225F70 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9FE4 80225F74 00000027 */  not       $zero, $zero
/* 6D9FE8 80225F78 00000002 */  srl       $zero, $zero, 0
/* 6D9FEC 80225F7C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6D9FF0 80225F80 00000001 */  movf      $zero, $zero, $fcc0
/* 6D9FF4 80225F84 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6D9FF8 80225F88 00000002 */  srl       $zero, $zero, 0
/* 6D9FFC 80225F8C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA000 80225F90 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA004 80225F94 00000046 */  rotrv     $zero, $zero, $zero
/* 6DA008 80225F98 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA00C 80225F9C 8022179C */  lb        $v0, 0x179c($at)
/* 6DA010 80225FA0 00000002 */  srl       $zero, $zero, 0
/* 6DA014 80225FA4 00000000 */  nop       
/* 6DA018 80225FA8 00000013 */  mtlo      $zero
/* 6DA01C 80225FAC 00000000 */  nop       
/* 6DA020 80225FB0 00000027 */  not       $zero, $zero
/* 6DA024 80225FB4 00000002 */  srl       $zero, $zero, 0
/* 6DA028 80225FB8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA02C 80225FBC FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6DA030 80225FC0 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6DA034 80225FC4 00000002 */  srl       $zero, $zero, 0
/* 6DA038 80225FC8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA03C 80225FCC FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA040 80225FD0 00000046 */  rotrv     $zero, $zero, $zero
/* 6DA044 80225FD4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA048 80225FD8 80222C10 */  lb        $v0, 0x2c10($at)
/* 6DA04C 80225FDC 00000002 */  srl       $zero, $zero, 0
/* 6DA050 80225FE0 00000000 */  nop       
/* 6DA054 80225FE4 00000013 */  mtlo      $zero
/* 6DA058 80225FE8 00000000 */  nop       
/* 6DA05C 80225FEC 00000027 */  not       $zero, $zero
/* 6DA060 80225FF0 00000002 */  srl       $zero, $zero, 0
/* 6DA064 80225FF4 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA068 80225FF8 FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 6DA06C 80225FFC 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6DA070 80226000 00000002 */  srl       $zero, $zero, 0
/* 6DA074 80226004 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA078 80226008 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA07C 8022600C 00000046 */  rotrv     $zero, $zero, $zero
/* 6DA080 80226010 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA084 80226014 802232D0 */  lb        $v0, 0x32d0($at)
/* 6DA088 80226018 00000002 */  srl       $zero, $zero, 0
/* 6DA08C 8022601C 00000000 */  nop       
/* 6DA090 80226020 00000013 */  mtlo      $zero
/* 6DA094 80226024 00000000 */  nop       
/* 6DA098 80226028 00000027 */  not       $zero, $zero
/* 6DA09C 8022602C 00000002 */  srl       $zero, $zero, 0
/* 6DA0A0 80226030 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA0A4 80226034 FE363C8D */  sd        $s6, 0x3c8d($s1)
/* 6DA0A8 80226038 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6DA0AC 8022603C 00000002 */  srl       $zero, $zero, 0
/* 6DA0B0 80226040 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA0B4 80226044 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA0B8 80226048 00000046 */  rotrv     $zero, $zero, $zero
/* 6DA0BC 8022604C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA0C0 80226050 80223A18 */  lb        $v0, 0x3a18($at)
/* 6DA0C4 80226054 00000002 */  srl       $zero, $zero, 0
/* 6DA0C8 80226058 00000000 */  nop       
/* 6DA0CC 8022605C 00000013 */  mtlo      $zero
/* 6DA0D0 80226060 00000000 */  nop       
/* 6DA0D4 80226064 00000027 */  not       $zero, $zero
/* 6DA0D8 80226068 00000002 */  srl       $zero, $zero, 0
/* 6DA0DC 8022606C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA0E0 80226070 FE363C8E */  sd        $s6, 0x3c8e($s1)
/* 6DA0E4 80226074 0000000E */  .byte     0x00, 0x00, 0x00, 0x0e
/* 6DA0E8 80226078 00000002 */  srl       $zero, $zero, 0
/* 6DA0EC 8022607C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA0F0 80226080 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA0F4 80226084 00000046 */  rotrv     $zero, $zero, $zero
/* 6DA0F8 80226088 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA0FC 8022608C 80224160 */  lb        $v0, 0x4160($at)
/* 6DA100 80226090 00000002 */  srl       $zero, $zero, 0
/* 6DA104 80226094 00000000 */  nop       
/* 6DA108 80226098 00000013 */  mtlo      $zero
/* 6DA10C 8022609C 00000000 */  nop       
/* 6DA110 802260A0 00000046 */  rotrv     $zero, $zero, $zero
/* 6DA114 802260A4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA118 802260A8 802248EC */  lb        $v0, 0x48ec($at)
/* 6DA11C 802260AC 00000002 */  srl       $zero, $zero, 0
/* 6DA120 802260B0 00000000 */  nop       
/* 6DA124 802260B4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA128 802260B8 00000000 */  nop       
/* 6DA12C 802260BC 00000000 */  nop       
/* 6DA130 802260C0 00000024 */  and       $zero, $zero, $zero
/* 6DA134 802260C4 00000002 */  srl       $zero, $zero, 0
/* 6DA138 802260C8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA13C 802260CC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA140 802260D0 00000043 */  sra       $zero, $zero, 1
/* 6DA144 802260D4 00000003 */  sra       $zero, $zero, 0
/* 6DA148 802260D8 802C9000 */  lb        $t4, -0x7000($at)
/* 6DA14C 802260DC FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA150 802260E0 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA154 802260E4 00000024 */  and       $zero, $zero, $zero
/* 6DA158 802260E8 00000002 */  srl       $zero, $zero, 0
/* 6DA15C 802260EC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA160 802260F0 00000000 */  nop       
/* 6DA164 802260F4 00000024 */  and       $zero, $zero, $zero
/* 6DA168 802260F8 00000002 */  srl       $zero, $zero, 0
/* 6DA16C 802260FC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA170 80226100 00000000 */  nop       
/* 6DA174 80226104 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA178 80226108 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA17C 8022610C 00000000 */  nop       
/* 6DA180 80226110 00000043 */  sra       $zero, $zero, 1
/* 6DA184 80226114 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA188 80226118 802C9364 */  lb        $t4, -0x6c9c($at)
/* 6DA18C 8022611C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA190 80226120 00000000 */  nop       
/* 6DA194 80226124 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA198 80226128 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA19C 8022612C 00000027 */  not       $zero, $zero
/* 6DA1A0 80226130 00000002 */  srl       $zero, $zero, 0
/* 6DA1A4 80226134 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA1A8 80226138 00008000 */  sll       $s0, $zero, 0
/* 6DA1AC 8022613C 00000027 */  not       $zero, $zero
/* 6DA1B0 80226140 00000002 */  srl       $zero, $zero, 0
/* 6DA1B4 80226144 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA1B8 80226148 00000000 */  nop       
/* 6DA1BC 8022614C 00000008 */  jr        $zero
/* 6DA1C0 80226150 00000001 */   movf     $zero, $zero, $fcc0
/* 6DA1C4 80226154 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA1C8 80226158 00000006 */  srlv      $zero, $zero, $zero
/* 6DA1CC 8022615C 00000000 */  nop       
/* 6DA1D0 80226160 00000002 */  srl       $zero, $zero, 0
/* 6DA1D4 80226164 00000000 */  nop       
/* 6DA1D8 80226168 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA1DC 8022616C 00000000 */  nop       
/* 6DA1E0 80226170 00000043 */  sra       $zero, $zero, 1
/* 6DA1E4 80226174 00000002 */  srl       $zero, $zero, 0
/* 6DA1E8 80226178 802D9700 */  lb        $t5, -0x6900($at)
/* 6DA1EC 8022617C FFFFFFFF */  sd        $ra, -1($ra)
/* 6DA1F0 80226180 00000043 */  sra       $zero, $zero, 1
/* 6DA1F4 80226184 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA1F8 80226188 802CAD98 */  lb        $t4, -0x5268($at)
/* 6DA1FC 8022618C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA200 80226190 00000000 */  nop       
/* 6DA204 80226194 00000000 */  nop       
/* 6DA208 80226198 00000000 */  nop       
/* 6DA20C 8022619C 00000043 */  sra       $zero, $zero, 1
/* 6DA210 802261A0 00000003 */  sra       $zero, $zero, 0
/* 6DA214 802261A4 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DA218 802261A8 00000024 */  and       $zero, $zero, $zero
/* 6DA21C 802261AC 00000000 */  nop       
/* 6DA220 802261B0 00000056 */  drotrv    $zero, $zero, $zero
/* 6DA224 802261B4 00000000 */  nop       
/* 6DA228 802261B8 00000024 */  and       $zero, $zero, $zero
/* 6DA22C 802261BC 00000002 */  srl       $zero, $zero, 0
/* 6DA230 802261C0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA234 802261C4 00000025 */  or        $zero, $zero, $zero
/* 6DA238 802261C8 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DA23C 802261CC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA240 802261D0 802260C0 */  lb        $v0, 0x60c0($at)
/* 6DA244 802261D4 00000008 */  jr        $zero
/* 6DA248 802261D8 00000001 */   movf     $zero, $zero, $fcc0
/* 6DA24C 802261DC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA250 802261E0 00000024 */  and       $zero, $zero, $zero
/* 6DA254 802261E4 00000002 */  srl       $zero, $zero, 0
/* 6DA258 802261E8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA25C 802261EC 00000027 */  not       $zero, $zero
/* 6DA260 802261F0 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DA264 802261F4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA268 802261F8 802260C0 */  lb        $v0, 0x60c0($at)
/* 6DA26C 802261FC 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 6DA270 80226200 00000000 */  nop       
/* 6DA274 80226204 00000002 */  srl       $zero, $zero, 0
/* 6DA278 80226208 00000000 */  nop       
/* 6DA27C 8022620C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA280 80226210 00000000 */  nop       
/* 6DA284 80226214 00000002 */  srl       $zero, $zero, 0
/* 6DA288 80226218 00000000 */  nop       
/* 6DA28C 8022621C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA290 80226220 00000000 */  nop       
/* 6DA294 80226224 00000018 */  mult      $zero, $zero
/* 6DA298 80226228 00000017 */  dsrav     $zero, $zero, $zero
/* 6DA29C 8022622C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6DA2A0 80226230 00000000 */  nop       
/* 6DA2A4 80226234 80227A20 */  lb        $v0, 0x7a20($at)
/* 6DA2A8 80226238 80227A10 */  lb        $v0, 0x7a10($at)
/* 6DA2AC 8022623C 80227A00 */  lb        $v0, 0x7a00($at)
/* 6DA2B0 80226240 80226170 */  lb        $v0, 0x6170($at)
/* 6DA2B4 80226244 80226214 */  lb        $v0, 0x6214($at)
/* 6DA2B8 80226248 00000000 */  nop       
/* 6DA2BC 8022624C 80226224 */  lb        $v0, 0x6224($at)
/* 6DA2C0 80226250 00000000 */  nop       
/* 6DA2C4 80226254 00000000 */  nop       
/* 6DA2C8 80226258 00000000 */  nop       
/* 6DA2CC 8022625C 00000000 */  nop       
/* 6DA2D0 80226260 00000024 */  and       $zero, $zero, $zero
/* 6DA2D4 80226264 00000002 */  srl       $zero, $zero, 0
/* 6DA2D8 80226268 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA2DC 8022626C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA2E0 80226270 00000043 */  sra       $zero, $zero, 1
/* 6DA2E4 80226274 00000003 */  sra       $zero, $zero, 0
/* 6DA2E8 80226278 802C9000 */  lb        $t4, -0x7000($at)
/* 6DA2EC 8022627C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA2F0 80226280 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA2F4 80226284 00000024 */  and       $zero, $zero, $zero
/* 6DA2F8 80226288 00000002 */  srl       $zero, $zero, 0
/* 6DA2FC 8022628C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA300 80226290 00000000 */  nop       
/* 6DA304 80226294 00000024 */  and       $zero, $zero, $zero
/* 6DA308 80226298 00000002 */  srl       $zero, $zero, 0
/* 6DA30C 8022629C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA310 802262A0 00000000 */  nop       
/* 6DA314 802262A4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA318 802262A8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA31C 802262AC 00000000 */  nop       
/* 6DA320 802262B0 00000043 */  sra       $zero, $zero, 1
/* 6DA324 802262B4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA328 802262B8 802C9364 */  lb        $t4, -0x6c9c($at)
/* 6DA32C 802262BC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA330 802262C0 00000000 */  nop       
/* 6DA334 802262C4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA338 802262C8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA33C 802262CC 00000027 */  not       $zero, $zero
/* 6DA340 802262D0 00000002 */  srl       $zero, $zero, 0
/* 6DA344 802262D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA348 802262D8 00008000 */  sll       $s0, $zero, 0
/* 6DA34C 802262DC 00000027 */  not       $zero, $zero
/* 6DA350 802262E0 00000002 */  srl       $zero, $zero, 0
/* 6DA354 802262E4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA358 802262E8 00000000 */  nop       
/* 6DA35C 802262EC 00000008 */  jr        $zero
/* 6DA360 802262F0 00000001 */   movf     $zero, $zero, $fcc0
/* 6DA364 802262F4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA368 802262F8 00000006 */  srlv      $zero, $zero, $zero
/* 6DA36C 802262FC 00000000 */  nop       
/* 6DA370 80226300 00000002 */  srl       $zero, $zero, 0
/* 6DA374 80226304 00000000 */  nop       
/* 6DA378 80226308 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA37C 8022630C 00000000 */  nop       
/* 6DA380 80226310 00000043 */  sra       $zero, $zero, 1
/* 6DA384 80226314 00000002 */  srl       $zero, $zero, 0
/* 6DA388 80226318 802D9700 */  lb        $t5, -0x6900($at)
/* 6DA38C 8022631C FFFFFFFF */  sd        $ra, -1($ra)
/* 6DA390 80226320 00000043 */  sra       $zero, $zero, 1
/* 6DA394 80226324 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA398 80226328 802CAD98 */  lb        $t4, -0x5268($at)
/* 6DA39C 8022632C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA3A0 80226330 00000000 */  nop       
/* 6DA3A4 80226334 00000000 */  nop       
/* 6DA3A8 80226338 00000000 */  nop       
/* 6DA3AC 8022633C 00000043 */  sra       $zero, $zero, 1
/* 6DA3B0 80226340 00000003 */  sra       $zero, $zero, 0
/* 6DA3B4 80226344 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DA3B8 80226348 00000019 */  multu     $zero, $zero
/* 6DA3BC 8022634C 00000000 */  nop       
/* 6DA3C0 80226350 00000024 */  and       $zero, $zero, $zero
/* 6DA3C4 80226354 00000002 */  srl       $zero, $zero, 0
/* 6DA3C8 80226358 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA3CC 8022635C 00000025 */  or        $zero, $zero, $zero
/* 6DA3D0 80226360 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DA3D4 80226364 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA3D8 80226368 80226260 */  lb        $v0, 0x6260($at)
/* 6DA3DC 8022636C 00000024 */  and       $zero, $zero, $zero
/* 6DA3E0 80226370 00000002 */  srl       $zero, $zero, 0
/* 6DA3E4 80226374 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA3E8 80226378 00000027 */  not       $zero, $zero
/* 6DA3EC 8022637C 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DA3F0 80226380 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA3F4 80226384 80226260 */  lb        $v0, 0x6260($at)
/* 6DA3F8 80226388 00000002 */  srl       $zero, $zero, 0
/* 6DA3FC 8022638C 00000000 */  nop       
/* 6DA400 80226390 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA404 80226394 00000000 */  nop       
/* 6DA408 80226398 00000002 */  srl       $zero, $zero, 0
/* 6DA40C 8022639C 00000000 */  nop       
/* 6DA410 802263A0 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA414 802263A4 00000000 */  nop       
/* 6DA418 802263A8 00000018 */  mult      $zero, $zero
/* 6DA41C 802263AC 00000017 */  dsrav     $zero, $zero, $zero
/* 6DA420 802263B0 00000016 */  dsrlv     $zero, $zero, $zero
/* 6DA424 802263B4 00000000 */  nop       
/* 6DA428 802263B8 80227A48 */  lb        $v0, 0x7a48($at)
/* 6DA42C 802263BC 80227A38 */  lb        $v0, 0x7a38($at)
/* 6DA430 802263C0 80227A28 */  lb        $v0, 0x7a28($at)
/* 6DA434 802263C4 80226310 */  lb        $v0, 0x6310($at)
/* 6DA438 802263C8 80226398 */  lb        $v0, 0x6398($at)
/* 6DA43C 802263CC 00000000 */  nop       
/* 6DA440 802263D0 802263A8 */  lb        $v0, 0x63a8($at)
/* 6DA444 802263D4 00000000 */  nop       
/* 6DA448 802263D8 00000000 */  nop       
/* 6DA44C 802263DC 00000000 */  nop       
/* 6DA450 802263E0 00000024 */  and       $zero, $zero, $zero
/* 6DA454 802263E4 00000002 */  srl       $zero, $zero, 0
/* 6DA458 802263E8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA45C 802263EC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA460 802263F0 00000024 */  and       $zero, $zero, $zero
/* 6DA464 802263F4 00000002 */  srl       $zero, $zero, 0
/* 6DA468 802263F8 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6DA46C 802263FC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DA470 80226400 00000024 */  and       $zero, $zero, $zero
/* 6DA474 80226404 00000002 */  srl       $zero, $zero, 0
/* 6DA478 80226408 FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 6DA47C 8022640C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DA480 80226410 00000043 */  sra       $zero, $zero, 1
/* 6DA484 80226414 00000003 */  sra       $zero, $zero, 0
/* 6DA488 80226418 802C9000 */  lb        $t4, -0x7000($at)
/* 6DA48C 8022641C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA490 80226420 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA494 80226424 00000024 */  and       $zero, $zero, $zero
/* 6DA498 80226428 00000002 */  srl       $zero, $zero, 0
/* 6DA49C 8022642C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA4A0 80226430 00000000 */  nop       
/* 6DA4A4 80226434 00000024 */  and       $zero, $zero, $zero
/* 6DA4A8 80226438 00000002 */  srl       $zero, $zero, 0
/* 6DA4AC 8022643C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA4B0 80226440 00000000 */  nop       
/* 6DA4B4 80226444 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA4B8 80226448 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA4BC 8022644C 00000000 */  nop       
/* 6DA4C0 80226450 00000043 */  sra       $zero, $zero, 1
/* 6DA4C4 80226454 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA4C8 80226458 802C9364 */  lb        $t4, -0x6c9c($at)
/* 6DA4CC 8022645C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA4D0 80226460 00000000 */  nop       
/* 6DA4D4 80226464 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA4D8 80226468 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA4DC 8022646C 00000027 */  not       $zero, $zero
/* 6DA4E0 80226470 00000002 */  srl       $zero, $zero, 0
/* 6DA4E4 80226474 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA4E8 80226478 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6DA4EC 8022647C 00000027 */  not       $zero, $zero
/* 6DA4F0 80226480 00000002 */  srl       $zero, $zero, 0
/* 6DA4F4 80226484 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA4F8 80226488 FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 6DA4FC 8022648C 00000008 */  jr        $zero
/* 6DA500 80226490 00000001 */   movf     $zero, $zero, $fcc0
/* 6DA504 80226494 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA508 80226498 00000006 */  srlv      $zero, $zero, $zero
/* 6DA50C 8022649C 00000000 */  nop       
/* 6DA510 802264A0 00000002 */  srl       $zero, $zero, 0
/* 6DA514 802264A4 00000000 */  nop       
/* 6DA518 802264A8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA51C 802264AC 00000000 */  nop       
/* 6DA520 802264B0 00000024 */  and       $zero, $zero, $zero
/* 6DA524 802264B4 00000002 */  srl       $zero, $zero, 0
/* 6DA528 802264B8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA52C 802264BC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA530 802264C0 00000024 */  and       $zero, $zero, $zero
/* 6DA534 802264C4 00000002 */  srl       $zero, $zero, 0
/* 6DA538 802264C8 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6DA53C 802264CC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DA540 802264D0 00000024 */  and       $zero, $zero, $zero
/* 6DA544 802264D4 00000002 */  srl       $zero, $zero, 0
/* 6DA548 802264D8 FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 6DA54C 802264DC FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DA550 802264E0 00000043 */  sra       $zero, $zero, 1
/* 6DA554 802264E4 00000003 */  sra       $zero, $zero, 0
/* 6DA558 802264E8 802C9000 */  lb        $t4, -0x7000($at)
/* 6DA55C 802264EC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA560 802264F0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA564 802264F4 00000024 */  and       $zero, $zero, $zero
/* 6DA568 802264F8 00000002 */  srl       $zero, $zero, 0
/* 6DA56C 802264FC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA570 80226500 00000000 */  nop       
/* 6DA574 80226504 00000024 */  and       $zero, $zero, $zero
/* 6DA578 80226508 00000002 */  srl       $zero, $zero, 0
/* 6DA57C 8022650C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA580 80226510 00000000 */  nop       
/* 6DA584 80226514 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA588 80226518 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA58C 8022651C 00000000 */  nop       
/* 6DA590 80226520 00000043 */  sra       $zero, $zero, 1
/* 6DA594 80226524 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA598 80226528 802C9364 */  lb        $t4, -0x6c9c($at)
/* 6DA59C 8022652C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA5A0 80226530 00000000 */  nop       
/* 6DA5A4 80226534 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA5A8 80226538 00000000 */  nop       
/* 6DA5AC 8022653C 00000043 */  sra       $zero, $zero, 1
/* 6DA5B0 80226540 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA5B4 80226544 802C9364 */  lb        $t4, -0x6c9c($at)
/* 6DA5B8 80226548 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA5BC 8022654C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA5C0 80226550 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA5C4 80226554 00000000 */  nop       
/* 6DA5C8 80226558 00000027 */  not       $zero, $zero
/* 6DA5CC 8022655C 00000002 */  srl       $zero, $zero, 0
/* 6DA5D0 80226560 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA5D4 80226564 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6DA5D8 80226568 00000027 */  not       $zero, $zero
/* 6DA5DC 8022656C 00000002 */  srl       $zero, $zero, 0
/* 6DA5E0 80226570 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA5E4 80226574 FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 6DA5E8 80226578 00000008 */  jr        $zero
/* 6DA5EC 8022657C 00000001 */   movf     $zero, $zero, $fcc0
/* 6DA5F0 80226580 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA5F4 80226584 00000006 */  srlv      $zero, $zero, $zero
/* 6DA5F8 80226588 00000000 */  nop       
/* 6DA5FC 8022658C 00000002 */  srl       $zero, $zero, 0
/* 6DA600 80226590 00000000 */  nop       
/* 6DA604 80226594 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA608 80226598 00000000 */  nop       
/* 6DA60C 8022659C 00000024 */  and       $zero, $zero, $zero
/* 6DA610 802265A0 00000002 */  srl       $zero, $zero, 0
/* 6DA614 802265A4 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA618 802265A8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA61C 802265AC 00000024 */  and       $zero, $zero, $zero
/* 6DA620 802265B0 00000002 */  srl       $zero, $zero, 0
/* 6DA624 802265B4 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6DA628 802265B8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DA62C 802265BC 00000024 */  and       $zero, $zero, $zero
/* 6DA630 802265C0 00000002 */  srl       $zero, $zero, 0
/* 6DA634 802265C4 FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 6DA638 802265C8 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DA63C 802265CC 00000043 */  sra       $zero, $zero, 1
/* 6DA640 802265D0 00000003 */  sra       $zero, $zero, 0
/* 6DA644 802265D4 802C9000 */  lb        $t4, -0x7000($at)
/* 6DA648 802265D8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA64C 802265DC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA650 802265E0 00000024 */  and       $zero, $zero, $zero
/* 6DA654 802265E4 00000002 */  srl       $zero, $zero, 0
/* 6DA658 802265E8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA65C 802265EC 00000000 */  nop       
/* 6DA660 802265F0 00000024 */  and       $zero, $zero, $zero
/* 6DA664 802265F4 00000002 */  srl       $zero, $zero, 0
/* 6DA668 802265F8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA66C 802265FC 00000000 */  nop       
/* 6DA670 80226600 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA674 80226604 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA678 80226608 00000000 */  nop       
/* 6DA67C 8022660C 00000043 */  sra       $zero, $zero, 1
/* 6DA680 80226610 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA684 80226614 802C9364 */  lb        $t4, -0x6c9c($at)
/* 6DA688 80226618 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA68C 8022661C 00000000 */  nop       
/* 6DA690 80226620 00000000 */  nop       
/* 6DA694 80226624 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA698 80226628 00000043 */  sra       $zero, $zero, 1
/* 6DA69C 8022662C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA6A0 80226630 802C9364 */  lb        $t4, -0x6c9c($at)
/* 6DA6A4 80226634 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA6A8 80226638 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA6AC 8022663C 00000000 */  nop       
/* 6DA6B0 80226640 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA6B4 80226644 00000027 */  not       $zero, $zero
/* 6DA6B8 80226648 00000002 */  srl       $zero, $zero, 0
/* 6DA6BC 8022664C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA6C0 80226650 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6DA6C4 80226654 00000027 */  not       $zero, $zero
/* 6DA6C8 80226658 00000002 */  srl       $zero, $zero, 0
/* 6DA6CC 8022665C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA6D0 80226660 FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 6DA6D4 80226664 00000008 */  jr        $zero
/* 6DA6D8 80226668 00000001 */   movf     $zero, $zero, $fcc0
/* 6DA6DC 8022666C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA6E0 80226670 00000006 */  srlv      $zero, $zero, $zero
/* 6DA6E4 80226674 00000000 */  nop       
/* 6DA6E8 80226678 00000002 */  srl       $zero, $zero, 0
/* 6DA6EC 8022667C 00000000 */  nop       
/* 6DA6F0 80226680 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA6F4 80226684 00000000 */  nop       
/* 6DA6F8 80226688 00000043 */  sra       $zero, $zero, 1
/* 6DA6FC 8022668C 00000002 */  srl       $zero, $zero, 0
/* 6DA700 80226690 802D9700 */  lb        $t5, -0x6900($at)
/* 6DA704 80226694 FFFFFFFF */  sd        $ra, -1($ra)
/* 6DA708 80226698 00000043 */  sra       $zero, $zero, 1
/* 6DA70C 8022669C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA710 802266A0 802CAD98 */  lb        $t4, -0x5268($at)
/* 6DA714 802266A4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA718 802266A8 00000000 */  nop       
/* 6DA71C 802266AC 00000000 */  nop       
/* 6DA720 802266B0 00000000 */  nop       
/* 6DA724 802266B4 00000024 */  and       $zero, $zero, $zero
/* 6DA728 802266B8 00000002 */  srl       $zero, $zero, 0
/* 6DA72C 802266BC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA730 802266C0 00000010 */  mfhi      $zero
/* 6DA734 802266C4 00000024 */  and       $zero, $zero, $zero
/* 6DA738 802266C8 00000002 */  srl       $zero, $zero, 0
/* 6DA73C 802266CC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA740 802266D0 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA744 802266D4 00000024 */  and       $zero, $zero, $zero
/* 6DA748 802266D8 00000002 */  srl       $zero, $zero, 0
/* 6DA74C 802266DC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DA750 802266E0 FFFFFE70 */  sd        $ra, -0x190($ra)
/* 6DA754 802266E4 00000024 */  and       $zero, $zero, $zero
/* 6DA758 802266E8 00000002 */  srl       $zero, $zero, 0
/* 6DA75C 802266EC FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DA760 802266F0 FFFFFCE0 */  sd        $ra, -0x320($ra)
/* 6DA764 802266F4 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DA768 802266F8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA76C 802266FC 802264B0 */  lb        $v0, 0x64b0($at)
/* 6DA770 80226700 00000024 */  and       $zero, $zero, $zero
/* 6DA774 80226704 00000002 */  srl       $zero, $zero, 0
/* 6DA778 80226708 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA77C 8022670C 00000013 */  mtlo      $zero
/* 6DA780 80226710 00000024 */  and       $zero, $zero, $zero
/* 6DA784 80226714 00000002 */  srl       $zero, $zero, 0
/* 6DA788 80226718 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA78C 8022671C 00000003 */  sra       $zero, $zero, 0
/* 6DA790 80226720 00000024 */  and       $zero, $zero, $zero
/* 6DA794 80226724 00000002 */  srl       $zero, $zero, 0
/* 6DA798 80226728 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DA79C 8022672C FFFFFE70 */  sd        $ra, -0x190($ra)
/* 6DA7A0 80226730 00000024 */  and       $zero, $zero, $zero
/* 6DA7A4 80226734 00000002 */  srl       $zero, $zero, 0
/* 6DA7A8 80226738 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DA7AC 8022673C FFFFFCE0 */  sd        $ra, -0x320($ra)
/* 6DA7B0 80226740 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DA7B4 80226744 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA7B8 80226748 802264B0 */  lb        $v0, 0x64b0($at)
/* 6DA7BC 8022674C 00000024 */  and       $zero, $zero, $zero
/* 6DA7C0 80226750 00000002 */  srl       $zero, $zero, 0
/* 6DA7C4 80226754 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA7C8 80226758 00000011 */  mthi      $zero
/* 6DA7CC 8022675C 00000024 */  and       $zero, $zero, $zero
/* 6DA7D0 80226760 00000002 */  srl       $zero, $zero, 0
/* 6DA7D4 80226764 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA7D8 80226768 00000000 */  nop       
/* 6DA7DC 8022676C 00000024 */  and       $zero, $zero, $zero
/* 6DA7E0 80226770 00000002 */  srl       $zero, $zero, 0
/* 6DA7E4 80226774 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DA7E8 80226778 FFFFFE70 */  sd        $ra, -0x190($ra)
/* 6DA7EC 8022677C 00000024 */  and       $zero, $zero, $zero
/* 6DA7F0 80226780 00000002 */  srl       $zero, $zero, 0
/* 6DA7F4 80226784 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DA7F8 80226788 FFFFFCE0 */  sd        $ra, -0x320($ra)
/* 6DA7FC 8022678C 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DA800 80226790 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA804 80226794 8022659C */  lb        $v0, 0x659c($at)
/* 6DA808 80226798 00000024 */  and       $zero, $zero, $zero
/* 6DA80C 8022679C 00000002 */  srl       $zero, $zero, 0
/* 6DA810 802267A0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA814 802267A4 00000012 */  mflo      $zero
/* 6DA818 802267A8 00000024 */  and       $zero, $zero, $zero
/* 6DA81C 802267AC 00000002 */  srl       $zero, $zero, 0
/* 6DA820 802267B0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA824 802267B4 00000002 */  srl       $zero, $zero, 0
/* 6DA828 802267B8 00000024 */  and       $zero, $zero, $zero
/* 6DA82C 802267BC 00000002 */  srl       $zero, $zero, 0
/* 6DA830 802267C0 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DA834 802267C4 FFFFFE70 */  sd        $ra, -0x190($ra)
/* 6DA838 802267C8 00000024 */  and       $zero, $zero, $zero
/* 6DA83C 802267CC 00000002 */  srl       $zero, $zero, 0
/* 6DA840 802267D0 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DA844 802267D4 FFFFFCE0 */  sd        $ra, -0x320($ra)
/* 6DA848 802267D8 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DA84C 802267DC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA850 802267E0 8022659C */  lb        $v0, 0x659c($at)
/* 6DA854 802267E4 00000002 */  srl       $zero, $zero, 0
/* 6DA858 802267E8 00000000 */  nop       
/* 6DA85C 802267EC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA860 802267F0 00000000 */  nop       
/* 6DA864 802267F4 00000002 */  srl       $zero, $zero, 0
/* 6DA868 802267F8 00000000 */  nop       
/* 6DA86C 802267FC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA870 80226800 00000000 */  nop       
/* 6DA874 80226804 0000000D */  break     
/* 6DA878 80226808 00000000 */   nop      
/* 6DA87C 8022680C 80227A70 */  lb        $v0, 0x7a70($at)
/* 6DA880 80226810 80227A60 */  lb        $v0, 0x7a60($at)
/* 6DA884 80226814 80227A50 */  lb        $v0, 0x7a50($at)
/* 6DA888 80226818 80226688 */  lb        $v0, 0x6688($at)
/* 6DA88C 8022681C 802267F4 */  lb        $v0, 0x67f4($at)
/* 6DA890 80226820 00000000 */  nop       
/* 6DA894 80226824 80226804 */  lb        $v0, 0x6804($at)
/* 6DA898 80226828 00000000 */  nop       
/* 6DA89C 8022682C 00000000 */  nop       
/* 6DA8A0 80226830 00000000 */  nop       
/* 6DA8A4 80226834 00000000 */  nop       
/* 6DA8A8 80226838 00000000 */  nop       
/* 6DA8AC 8022683C 00000000 */  nop       
/* 6DA8B0 80226840 00000043 */  sra       $zero, $zero, 1
/* 6DA8B4 80226844 00000002 */  srl       $zero, $zero, 0
/* 6DA8B8 80226848 802D9700 */  lb        $t5, -0x6900($at)
/* 6DA8BC 8022684C FFFFFFFF */  sd        $ra, -1($ra)
/* 6DA8C0 80226850 00000043 */  sra       $zero, $zero, 1
/* 6DA8C4 80226854 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA8C8 80226858 802CAD98 */  lb        $t4, -0x5268($at)
/* 6DA8CC 8022685C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA8D0 80226860 00000000 */  nop       
/* 6DA8D4 80226864 00000000 */  nop       
/* 6DA8D8 80226868 00000000 */  nop       
/* 6DA8DC 8022686C 00000043 */  sra       $zero, $zero, 1
/* 6DA8E0 80226870 00000002 */  srl       $zero, $zero, 0
/* 6DA8E4 80226874 80253734 */  lb        $a1, 0x3734($at)
/* 6DA8E8 80226878 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA8EC 8022687C 00000002 */  srl       $zero, $zero, 0
/* 6DA8F0 80226880 00000000 */  nop       
/* 6DA8F4 80226884 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA8F8 80226888 00000000 */  nop       
/* 6DA8FC 8022688C 00000002 */  srl       $zero, $zero, 0
/* 6DA900 80226890 00000000 */  nop       
/* 6DA904 80226894 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA908 80226898 00000000 */  nop       
/* 6DA90C 8022689C 00000019 */  multu     $zero, $zero
/* 6DA910 802268A0 00000000 */  nop       
/* 6DA914 802268A4 80227A98 */  lb        $v0, 0x7a98($at)
/* 6DA918 802268A8 80227A88 */  lb        $v0, 0x7a88($at)
/* 6DA91C 802268AC 80227A78 */  lb        $v0, 0x7a78($at)
/* 6DA920 802268B0 80226840 */  lb        $v0, 0x6840($at)
/* 6DA924 802268B4 8022688C */  lb        $v0, 0x688c($at)
/* 6DA928 802268B8 00000000 */  nop       
/* 6DA92C 802268BC 8022689C */  lb        $v0, 0x689c($at)
/* 6DA930 802268C0 00000000 */  nop       
/* 6DA934 802268C4 00000000 */  nop       
/* 6DA938 802268C8 00000000 */  nop       
/* 6DA93C 802268CC 00000000 */  nop       
/* 6DA940 802268D0 00000024 */  and       $zero, $zero, $zero
/* 6DA944 802268D4 00000002 */  srl       $zero, $zero, 0
/* 6DA948 802268D8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA94C 802268DC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA950 802268E0 00000043 */  sra       $zero, $zero, 1
/* 6DA954 802268E4 00000003 */  sra       $zero, $zero, 0
/* 6DA958 802268E8 802C9000 */  lb        $t4, -0x7000($at)
/* 6DA95C 802268EC FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DA960 802268F0 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA964 802268F4 00000024 */  and       $zero, $zero, $zero
/* 6DA968 802268F8 00000002 */  srl       $zero, $zero, 0
/* 6DA96C 802268FC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA970 80226900 00000000 */  nop       
/* 6DA974 80226904 00000024 */  and       $zero, $zero, $zero
/* 6DA978 80226908 00000002 */  srl       $zero, $zero, 0
/* 6DA97C 8022690C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA980 80226910 00000000 */  nop       
/* 6DA984 80226914 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA988 80226918 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA98C 8022691C 00000000 */  nop       
/* 6DA990 80226920 00000043 */  sra       $zero, $zero, 1
/* 6DA994 80226924 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA998 80226928 802C9364 */  lb        $t4, -0x6c9c($at)
/* 6DA99C 8022692C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA9A0 80226930 00000000 */  nop       
/* 6DA9A4 80226934 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA9A8 80226938 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA9AC 8022693C 00000027 */  not       $zero, $zero
/* 6DA9B0 80226940 00000002 */  srl       $zero, $zero, 0
/* 6DA9B4 80226944 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DA9B8 80226948 00008000 */  sll       $s0, $zero, 0
/* 6DA9BC 8022694C 00000027 */  not       $zero, $zero
/* 6DA9C0 80226950 00000002 */  srl       $zero, $zero, 0
/* 6DA9C4 80226954 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DA9C8 80226958 00000000 */  nop       
/* 6DA9CC 8022695C 00000008 */  jr        $zero
/* 6DA9D0 80226960 00000001 */   movf     $zero, $zero, $fcc0
/* 6DA9D4 80226964 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DA9D8 80226968 00000006 */  srlv      $zero, $zero, $zero
/* 6DA9DC 8022696C 00000000 */  nop       
/* 6DA9E0 80226970 00000002 */  srl       $zero, $zero, 0
/* 6DA9E4 80226974 00000000 */  nop       
/* 6DA9E8 80226978 00000001 */  movf      $zero, $zero, $fcc0
/* 6DA9EC 8022697C 00000000 */  nop       
/* 6DA9F0 80226980 00000043 */  sra       $zero, $zero, 1
/* 6DA9F4 80226984 00000002 */  srl       $zero, $zero, 0
/* 6DA9F8 80226988 802D9700 */  lb        $t5, -0x6900($at)
/* 6DA9FC 8022698C FFFFFFFF */  sd        $ra, -1($ra)
/* 6DAA00 80226990 00000043 */  sra       $zero, $zero, 1
/* 6DAA04 80226994 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DAA08 80226998 802CAD98 */  lb        $t4, -0x5268($at)
/* 6DAA0C 8022699C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAA10 802269A0 00000000 */  nop       
/* 6DAA14 802269A4 00000000 */  nop       
/* 6DAA18 802269A8 00000000 */  nop       
/* 6DAA1C 802269AC 00000043 */  sra       $zero, $zero, 1
/* 6DAA20 802269B0 00000003 */  sra       $zero, $zero, 0
/* 6DAA24 802269B4 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DAA28 802269B8 0000000F */  sync      
/* 6DAA2C 802269BC 00000000 */  nop       
/* 6DAA30 802269C0 00000043 */  sra       $zero, $zero, 1
/* 6DAA34 802269C4 00000003 */  sra       $zero, $zero, 0
/* 6DAA38 802269C8 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DAA3C 802269CC 00000011 */  mthi      $zero
/* 6DAA40 802269D0 00000000 */  nop       
/* 6DAA44 802269D4 00000043 */  sra       $zero, $zero, 1
/* 6DAA48 802269D8 00000003 */  sra       $zero, $zero, 0
/* 6DAA4C 802269DC 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DAA50 802269E0 00000010 */  mfhi      $zero
/* 6DAA54 802269E4 00000000 */  nop       
/* 6DAA58 802269E8 00000043 */  sra       $zero, $zero, 1
/* 6DAA5C 802269EC 00000003 */  sra       $zero, $zero, 0
/* 6DAA60 802269F0 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DAA64 802269F4 0000001A */  div       $zero, $zero, $zero
/* 6DAA68 802269F8 00000000 */  nop       
/* 6DAA6C 802269FC 00000043 */  sra       $zero, $zero, 1
/* 6DAA70 80226A00 00000003 */  sra       $zero, $zero, 0
/* 6DAA74 80226A04 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DAA78 80226A08 00000012 */  mflo      $zero
/* 6DAA7C 80226A0C 00000000 */  nop       
/* 6DAA80 80226A10 00000043 */  sra       $zero, $zero, 1
/* 6DAA84 80226A14 00000003 */  sra       $zero, $zero, 0
/* 6DAA88 80226A18 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DAA8C 80226A1C 00000014 */  dsllv     $zero, $zero, $zero
/* 6DAA90 80226A20 00000000 */  nop       
/* 6DAA94 80226A24 00000043 */  sra       $zero, $zero, 1
/* 6DAA98 80226A28 00000003 */  sra       $zero, $zero, 0
/* 6DAA9C 80226A2C 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DAAA0 80226A30 00000016 */  dsrlv     $zero, $zero, $zero
/* 6DAAA4 80226A34 00000000 */  nop       
/* 6DAAA8 80226A38 00000043 */  sra       $zero, $zero, 1
/* 6DAAAC 80226A3C 00000003 */  sra       $zero, $zero, 0
/* 6DAAB0 80226A40 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DAAB4 80226A44 00000018 */  mult      $zero, $zero
/* 6DAAB8 80226A48 00000000 */  nop       
/* 6DAABC 80226A4C 00000024 */  and       $zero, $zero, $zero
/* 6DAAC0 80226A50 00000002 */  srl       $zero, $zero, 0
/* 6DAAC4 80226A54 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DAAC8 80226A58 00000020 */  add       $zero, $zero, $zero
/* 6DAACC 80226A5C 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DAAD0 80226A60 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAAD4 80226A64 802268D0 */  lb        $v0, 0x68d0($at)
/* 6DAAD8 80226A68 00000024 */  and       $zero, $zero, $zero
/* 6DAADC 80226A6C 00000002 */  srl       $zero, $zero, 0
/* 6DAAE0 80226A70 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DAAE4 80226A74 00000022 */  neg       $zero, $zero
/* 6DAAE8 80226A78 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DAAEC 80226A7C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAAF0 80226A80 802268D0 */  lb        $v0, 0x68d0($at)
/* 6DAAF4 80226A84 00000024 */  and       $zero, $zero, $zero
/* 6DAAF8 80226A88 00000002 */  srl       $zero, $zero, 0
/* 6DAAFC 80226A8C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DAB00 80226A90 00000024 */  and       $zero, $zero, $zero
/* 6DAB04 80226A94 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DAB08 80226A98 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAB0C 80226A9C 802268D0 */  lb        $v0, 0x68d0($at)
/* 6DAB10 80226AA0 00000002 */  srl       $zero, $zero, 0
/* 6DAB14 80226AA4 00000000 */  nop       
/* 6DAB18 80226AA8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAB1C 80226AAC 00000000 */  nop       
/* 6DAB20 80226AB0 00000002 */  srl       $zero, $zero, 0
/* 6DAB24 80226AB4 00000000 */  nop       
/* 6DAB28 80226AB8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAB2C 80226ABC 00000000 */  nop       
/* 6DAB30 80226AC0 80227AC0 */  lb        $v0, 0x7ac0($at)
/* 6DAB34 80226AC4 80227AB0 */  lb        $v0, 0x7ab0($at)
/* 6DAB38 80226AC8 80227AA0 */  lb        $v0, 0x7aa0($at)
/* 6DAB3C 80226ACC 80226980 */  lb        $v0, 0x6980($at)
/* 6DAB40 80226AD0 80226AB0 */  lb        $v0, 0x6ab0($at)
/* 6DAB44 80226AD4 00000000 */  nop       
/* 6DAB48 80226AD8 00000000 */  nop       
/* 6DAB4C 80226ADC 00000000 */  nop       
/* 6DAB50 80226AE0 00000000 */  nop       
/* 6DAB54 80226AE4 00000000 */  nop       
/* 6DAB58 80226AE8 00000000 */  nop       
/* 6DAB5C 80226AEC 00000000 */  nop       
/* 6DAB60 80226AF0 00000024 */  and       $zero, $zero, $zero
/* 6DAB64 80226AF4 00000002 */  srl       $zero, $zero, 0
/* 6DAB68 80226AF8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DAB6C 80226AFC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DAB70 80226B00 00000043 */  sra       $zero, $zero, 1
/* 6DAB74 80226B04 00000003 */  sra       $zero, $zero, 0
/* 6DAB78 80226B08 802C9000 */  lb        $t4, -0x7000($at)
/* 6DAB7C 80226B0C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DAB80 80226B10 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAB84 80226B14 00000024 */  and       $zero, $zero, $zero
/* 6DAB88 80226B18 00000002 */  srl       $zero, $zero, 0
/* 6DAB8C 80226B1C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DAB90 80226B20 00000000 */  nop       
/* 6DAB94 80226B24 00000024 */  and       $zero, $zero, $zero
/* 6DAB98 80226B28 00000002 */  srl       $zero, $zero, 0
/* 6DAB9C 80226B2C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DABA0 80226B30 00000000 */  nop       
/* 6DABA4 80226B34 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DABA8 80226B38 00000001 */  movf      $zero, $zero, $fcc0
/* 6DABAC 80226B3C 00000000 */  nop       
/* 6DABB0 80226B40 00000043 */  sra       $zero, $zero, 1
/* 6DABB4 80226B44 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DABB8 80226B48 802C9364 */  lb        $t4, -0x6c9c($at)
/* 6DABBC 80226B4C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DABC0 80226B50 00000000 */  nop       
/* 6DABC4 80226B54 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DABC8 80226B58 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DABCC 80226B5C 00000027 */  not       $zero, $zero
/* 6DABD0 80226B60 00000002 */  srl       $zero, $zero, 0
/* 6DABD4 80226B64 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DABD8 80226B68 00008000 */  sll       $s0, $zero, 0
/* 6DABDC 80226B6C 00000027 */  not       $zero, $zero
/* 6DABE0 80226B70 00000002 */  srl       $zero, $zero, 0
/* 6DABE4 80226B74 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DABE8 80226B78 00000000 */  nop       
/* 6DABEC 80226B7C 00000008 */  jr        $zero
/* 6DABF0 80226B80 00000001 */   movf     $zero, $zero, $fcc0
/* 6DABF4 80226B84 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DABF8 80226B88 00000006 */  srlv      $zero, $zero, $zero
/* 6DABFC 80226B8C 00000000 */  nop       
/* 6DAC00 80226B90 00000002 */  srl       $zero, $zero, 0
/* 6DAC04 80226B94 00000000 */  nop       
/* 6DAC08 80226B98 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAC0C 80226B9C 00000000 */  nop       
/* 6DAC10 80226BA0 00000043 */  sra       $zero, $zero, 1
/* 6DAC14 80226BA4 00000002 */  srl       $zero, $zero, 0
/* 6DAC18 80226BA8 802D9700 */  lb        $t5, -0x6900($at)
/* 6DAC1C 80226BAC FFFFFFFF */  sd        $ra, -1($ra)
/* 6DAC20 80226BB0 00000043 */  sra       $zero, $zero, 1
/* 6DAC24 80226BB4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DAC28 80226BB8 802CAD98 */  lb        $t4, -0x5268($at)
/* 6DAC2C 80226BBC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAC30 80226BC0 00000000 */  nop       
/* 6DAC34 80226BC4 00000000 */  nop       
/* 6DAC38 80226BC8 00000000 */  nop       
/* 6DAC3C 80226BCC 00000043 */  sra       $zero, $zero, 1
/* 6DAC40 80226BD0 00000003 */  sra       $zero, $zero, 0
/* 6DAC44 80226BD4 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DAC48 80226BD8 0000000D */  break     
/* 6DAC4C 80226BDC 00000000 */   nop      
/* 6DAC50 80226BE0 00000043 */  sra       $zero, $zero, 1
/* 6DAC54 80226BE4 00000003 */  sra       $zero, $zero, 0
/* 6DAC58 80226BE8 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DAC5C 80226BEC 00000011 */  mthi      $zero
/* 6DAC60 80226BF0 00000000 */  nop       
/* 6DAC64 80226BF4 00000043 */  sra       $zero, $zero, 1
/* 6DAC68 80226BF8 00000003 */  sra       $zero, $zero, 0
/* 6DAC6C 80226BFC 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DAC70 80226C00 00000010 */  mfhi      $zero
/* 6DAC74 80226C04 00000000 */  nop       
/* 6DAC78 80226C08 00000043 */  sra       $zero, $zero, 1
/* 6DAC7C 80226C0C 00000003 */  sra       $zero, $zero, 0
/* 6DAC80 80226C10 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DAC84 80226C14 00000012 */  mflo      $zero
/* 6DAC88 80226C18 00000000 */  nop       
/* 6DAC8C 80226C1C 00000043 */  sra       $zero, $zero, 1
/* 6DAC90 80226C20 00000003 */  sra       $zero, $zero, 0
/* 6DAC94 80226C24 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DAC98 80226C28 00000014 */  dsllv     $zero, $zero, $zero
/* 6DAC9C 80226C2C 00000000 */  nop       
/* 6DACA0 80226C30 00000043 */  sra       $zero, $zero, 1
/* 6DACA4 80226C34 00000003 */  sra       $zero, $zero, 0
/* 6DACA8 80226C38 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DACAC 80226C3C 00000016 */  dsrlv     $zero, $zero, $zero
/* 6DACB0 80226C40 00000000 */  nop       
/* 6DACB4 80226C44 00000043 */  sra       $zero, $zero, 1
/* 6DACB8 80226C48 00000003 */  sra       $zero, $zero, 0
/* 6DACBC 80226C4C 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DACC0 80226C50 00000018 */  mult      $zero, $zero
/* 6DACC4 80226C54 00000000 */  nop       
/* 6DACC8 80226C58 00000024 */  and       $zero, $zero, $zero
/* 6DACCC 80226C5C 00000002 */  srl       $zero, $zero, 0
/* 6DACD0 80226C60 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DACD4 80226C64 00000020 */  add       $zero, $zero, $zero
/* 6DACD8 80226C68 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DACDC 80226C6C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DACE0 80226C70 80226AF0 */  lb        $v0, 0x6af0($at)
/* 6DACE4 80226C74 00000024 */  and       $zero, $zero, $zero
/* 6DACE8 80226C78 00000002 */  srl       $zero, $zero, 0
/* 6DACEC 80226C7C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DACF0 80226C80 00000022 */  neg       $zero, $zero
/* 6DACF4 80226C84 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DACF8 80226C88 00000001 */  movf      $zero, $zero, $fcc0
/* 6DACFC 80226C8C 80226AF0 */  lb        $v0, 0x6af0($at)
/* 6DAD00 80226C90 00000024 */  and       $zero, $zero, $zero
/* 6DAD04 80226C94 00000002 */  srl       $zero, $zero, 0
/* 6DAD08 80226C98 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DAD0C 80226C9C 00000024 */  and       $zero, $zero, $zero
/* 6DAD10 80226CA0 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DAD14 80226CA4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAD18 80226CA8 80226AF0 */  lb        $v0, 0x6af0($at)
/* 6DAD1C 80226CAC 00000002 */  srl       $zero, $zero, 0
/* 6DAD20 80226CB0 00000000 */  nop       
/* 6DAD24 80226CB4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAD28 80226CB8 00000000 */  nop       
/* 6DAD2C 80226CBC 00000002 */  srl       $zero, $zero, 0
/* 6DAD30 80226CC0 00000000 */  nop       
/* 6DAD34 80226CC4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAD38 80226CC8 00000000 */  nop       
/* 6DAD3C 80226CCC 80227AE8 */  lb        $v0, 0x7ae8($at)
/* 6DAD40 80226CD0 80227AD8 */  lb        $v0, 0x7ad8($at)
/* 6DAD44 80226CD4 80227AC8 */  lb        $v0, 0x7ac8($at)
/* 6DAD48 80226CD8 80226BA0 */  lb        $v0, 0x6ba0($at)
/* 6DAD4C 80226CDC 80226CBC */  lb        $v0, 0x6cbc($at)
/* 6DAD50 80226CE0 00000000 */  nop       
/* 6DAD54 80226CE4 00000000 */  nop       
/* 6DAD58 80226CE8 00000000 */  nop       
/* 6DAD5C 80226CEC 00000000 */  nop       
/* 6DAD60 80226CF0 00000000 */  nop       
/* 6DAD64 80226CF4 00000000 */  nop       
/* 6DAD68 80226CF8 00000000 */  nop       
/* 6DAD6C 80226CFC 00000000 */  nop       
/* 6DAD70 80226D00 00000024 */  and       $zero, $zero, $zero
/* 6DAD74 80226D04 00000002 */  srl       $zero, $zero, 0
/* 6DAD78 80226D08 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DAD7C 80226D0C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DAD80 80226D10 00000043 */  sra       $zero, $zero, 1
/* 6DAD84 80226D14 00000003 */  sra       $zero, $zero, 0
/* 6DAD88 80226D18 802C9000 */  lb        $t4, -0x7000($at)
/* 6DAD8C 80226D1C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DAD90 80226D20 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAD94 80226D24 00000024 */  and       $zero, $zero, $zero
/* 6DAD98 80226D28 00000002 */  srl       $zero, $zero, 0
/* 6DAD9C 80226D2C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DADA0 80226D30 00000000 */  nop       
/* 6DADA4 80226D34 00000024 */  and       $zero, $zero, $zero
/* 6DADA8 80226D38 00000002 */  srl       $zero, $zero, 0
/* 6DADAC 80226D3C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DADB0 80226D40 00000000 */  nop       
/* 6DADB4 80226D44 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DADB8 80226D48 00000001 */  movf      $zero, $zero, $fcc0
/* 6DADBC 80226D4C 00000000 */  nop       
/* 6DADC0 80226D50 00000043 */  sra       $zero, $zero, 1
/* 6DADC4 80226D54 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DADC8 80226D58 802C9364 */  lb        $t4, -0x6c9c($at)
/* 6DADCC 80226D5C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DADD0 80226D60 00000000 */  nop       
/* 6DADD4 80226D64 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DADD8 80226D68 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DADDC 80226D6C 00000027 */  not       $zero, $zero
/* 6DADE0 80226D70 00000002 */  srl       $zero, $zero, 0
/* 6DADE4 80226D74 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DADE8 80226D78 00008000 */  sll       $s0, $zero, 0
/* 6DADEC 80226D7C 00000027 */  not       $zero, $zero
/* 6DADF0 80226D80 00000002 */  srl       $zero, $zero, 0
/* 6DADF4 80226D84 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DADF8 80226D88 00000000 */  nop       
/* 6DADFC 80226D8C 00000008 */  jr        $zero
/* 6DAE00 80226D90 00000001 */   movf     $zero, $zero, $fcc0
/* 6DAE04 80226D94 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DAE08 80226D98 00000006 */  srlv      $zero, $zero, $zero
/* 6DAE0C 80226D9C 00000000 */  nop       
/* 6DAE10 80226DA0 00000002 */  srl       $zero, $zero, 0
/* 6DAE14 80226DA4 00000000 */  nop       
/* 6DAE18 80226DA8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAE1C 80226DAC 00000000 */  nop       
/* 6DAE20 80226DB0 00000043 */  sra       $zero, $zero, 1
/* 6DAE24 80226DB4 00000002 */  srl       $zero, $zero, 0
/* 6DAE28 80226DB8 802D9700 */  lb        $t5, -0x6900($at)
/* 6DAE2C 80226DBC FFFFFFFF */  sd        $ra, -1($ra)
/* 6DAE30 80226DC0 00000043 */  sra       $zero, $zero, 1
/* 6DAE34 80226DC4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DAE38 80226DC8 802CAD98 */  lb        $t4, -0x5268($at)
/* 6DAE3C 80226DCC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAE40 80226DD0 00000000 */  nop       
/* 6DAE44 80226DD4 00000000 */  nop       
/* 6DAE48 80226DD8 00000000 */  nop       
/* 6DAE4C 80226DDC 00000043 */  sra       $zero, $zero, 1
/* 6DAE50 80226DE0 00000003 */  sra       $zero, $zero, 0
/* 6DAE54 80226DE4 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DAE58 80226DE8 0000001E */  ddiv      $zero, $zero, $zero
/* 6DAE5C 80226DEC 00000000 */  nop       
/* 6DAE60 80226DF0 00000043 */  sra       $zero, $zero, 1
/* 6DAE64 80226DF4 00000003 */  sra       $zero, $zero, 0
/* 6DAE68 80226DF8 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DAE6C 80226DFC 00000027 */  not       $zero, $zero
/* 6DAE70 80226E00 00000000 */  nop       
/* 6DAE74 80226E04 00000043 */  sra       $zero, $zero, 1
/* 6DAE78 80226E08 00000003 */  sra       $zero, $zero, 0
/* 6DAE7C 80226E0C 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DAE80 80226E10 00000026 */  xor       $zero, $zero, $zero
/* 6DAE84 80226E14 00000000 */  nop       
/* 6DAE88 80226E18 00000043 */  sra       $zero, $zero, 1
/* 6DAE8C 80226E1C 00000003 */  sra       $zero, $zero, 0
/* 6DAE90 80226E20 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DAE94 80226E24 00000024 */  and       $zero, $zero, $zero
/* 6DAE98 80226E28 00000000 */  nop       
/* 6DAE9C 80226E2C 00000043 */  sra       $zero, $zero, 1
/* 6DAEA0 80226E30 00000003 */  sra       $zero, $zero, 0
/* 6DAEA4 80226E34 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DAEA8 80226E38 00000022 */  neg       $zero, $zero
/* 6DAEAC 80226E3C 00000000 */  nop       
/* 6DAEB0 80226E40 00000043 */  sra       $zero, $zero, 1
/* 6DAEB4 80226E44 00000003 */  sra       $zero, $zero, 0
/* 6DAEB8 80226E48 802C9308 */  lb        $t4, -0x6cf8($at)
/* 6DAEBC 80226E4C 00000020 */  add       $zero, $zero, $zero
/* 6DAEC0 80226E50 00000000 */  nop       
/* 6DAEC4 80226E54 00000024 */  and       $zero, $zero, $zero
/* 6DAEC8 80226E58 00000002 */  srl       $zero, $zero, 0
/* 6DAECC 80226E5C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DAED0 80226E60 00000012 */  mflo      $zero
/* 6DAED4 80226E64 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DAED8 80226E68 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAEDC 80226E6C 80226D00 */  lb        $v0, 0x6d00($at)
/* 6DAEE0 80226E70 00000024 */  and       $zero, $zero, $zero
/* 6DAEE4 80226E74 00000002 */  srl       $zero, $zero, 0
/* 6DAEE8 80226E78 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DAEEC 80226E7C 00000014 */  dsllv     $zero, $zero, $zero
/* 6DAEF0 80226E80 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DAEF4 80226E84 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAEF8 80226E88 80226D00 */  lb        $v0, 0x6d00($at)
/* 6DAEFC 80226E8C 00000024 */  and       $zero, $zero, $zero
/* 6DAF00 80226E90 00000002 */  srl       $zero, $zero, 0
/* 6DAF04 80226E94 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DAF08 80226E98 00000016 */  dsrlv     $zero, $zero, $zero
/* 6DAF0C 80226E9C 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DAF10 80226EA0 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAF14 80226EA4 80226D00 */  lb        $v0, 0x6d00($at)
/* 6DAF18 80226EA8 00000024 */  and       $zero, $zero, $zero
/* 6DAF1C 80226EAC 00000002 */  srl       $zero, $zero, 0
/* 6DAF20 80226EB0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DAF24 80226EB4 00000018 */  mult      $zero, $zero
/* 6DAF28 80226EB8 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DAF2C 80226EBC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAF30 80226EC0 80226D00 */  lb        $v0, 0x6d00($at)
/* 6DAF34 80226EC4 00000002 */  srl       $zero, $zero, 0
/* 6DAF38 80226EC8 00000000 */  nop       
/* 6DAF3C 80226ECC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAF40 80226ED0 00000000 */  nop       
/* 6DAF44 80226ED4 00000002 */  srl       $zero, $zero, 0
/* 6DAF48 80226ED8 00000000 */  nop       
/* 6DAF4C 80226EDC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAF50 80226EE0 00000000 */  nop       
/* 6DAF54 80226EE4 80227B10 */  lb        $v0, 0x7b10($at)
/* 6DAF58 80226EE8 80227B00 */  lb        $v0, 0x7b00($at)
/* 6DAF5C 80226EEC 80227AF0 */  lb        $v0, 0x7af0($at)
/* 6DAF60 80226EF0 80226DB0 */  lb        $v0, 0x6db0($at)
/* 6DAF64 80226EF4 80226ED4 */  lb        $v0, 0x6ed4($at)
/* 6DAF68 80226EF8 00000000 */  nop       
/* 6DAF6C 80226EFC 00000000 */  nop       
/* 6DAF70 80226F00 00000000 */  nop       
/* 6DAF74 80226F04 00000000 */  nop       
/* 6DAF78 80226F08 00000000 */  nop       
/* 6DAF7C 80226F0C 00000000 */  nop       
/* 6DAF80 80226F10 00000043 */  sra       $zero, $zero, 1
/* 6DAF84 80226F14 00000002 */  srl       $zero, $zero, 0
/* 6DAF88 80226F18 802D9700 */  lb        $t5, -0x6900($at)
/* 6DAF8C 80226F1C FFFFFFFF */  sd        $ra, -1($ra)
/* 6DAF90 80226F20 00000043 */  sra       $zero, $zero, 1
/* 6DAF94 80226F24 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DAF98 80226F28 802CAD98 */  lb        $t4, -0x5268($at)
/* 6DAF9C 80226F2C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAFA0 80226F30 00000000 */  nop       
/* 6DAFA4 80226F34 00000000 */  nop       
/* 6DAFA8 80226F38 00000000 */  nop       
/* 6DAFAC 80226F3C 00000002 */  srl       $zero, $zero, 0
/* 6DAFB0 80226F40 00000000 */  nop       
/* 6DAFB4 80226F44 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAFB8 80226F48 00000000 */  nop       
/* 6DAFBC 80226F4C 00000002 */  srl       $zero, $zero, 0
/* 6DAFC0 80226F50 00000000 */  nop       
/* 6DAFC4 80226F54 00000001 */  movf      $zero, $zero, $fcc0
/* 6DAFC8 80226F58 00000000 */  nop       
/* 6DAFCC 80226F5C 00000010 */  mfhi      $zero
/* 6DAFD0 80226F60 00000000 */  nop       
/* 6DAFD4 80226F64 80227B38 */  lb        $v0, 0x7b38($at)
/* 6DAFD8 80226F68 80227B28 */  lb        $v0, 0x7b28($at)
/* 6DAFDC 80226F6C 80227B18 */  lb        $v0, 0x7b18($at)
/* 6DAFE0 80226F70 80226F10 */  lb        $v0, 0x6f10($at)
/* 6DAFE4 80226F74 80226F4C */  lb        $v0, 0x6f4c($at)
/* 6DAFE8 80226F78 00000000 */  nop       
/* 6DAFEC 80226F7C 80226F5C */  lb        $v0, 0x6f5c($at)
/* 6DAFF0 80226F80 00000000 */  nop       
/* 6DAFF4 80226F84 00000000 */  nop       
/* 6DAFF8 80226F88 00000000 */  nop       
/* 6DAFFC 80226F8C 00000000 */  nop       
/* 6DB000 80226F90 00000024 */  and       $zero, $zero, $zero
/* 6DB004 80226F94 00000002 */  srl       $zero, $zero, 0
/* 6DB008 80226F98 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DB00C 80226F9C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB010 80226FA0 00000024 */  and       $zero, $zero, $zero
/* 6DB014 80226FA4 00000002 */  srl       $zero, $zero, 0
/* 6DB018 80226FA8 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6DB01C 80226FAC FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DB020 80226FB0 00000024 */  and       $zero, $zero, $zero
/* 6DB024 80226FB4 00000002 */  srl       $zero, $zero, 0
/* 6DB028 80226FB8 FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 6DB02C 80226FBC FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DB030 80226FC0 00000043 */  sra       $zero, $zero, 1
/* 6DB034 80226FC4 00000003 */  sra       $zero, $zero, 0
/* 6DB038 80226FC8 802C9000 */  lb        $t4, -0x7000($at)
/* 6DB03C 80226FCC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB040 80226FD0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB044 80226FD4 00000024 */  and       $zero, $zero, $zero
/* 6DB048 80226FD8 00000002 */  srl       $zero, $zero, 0
/* 6DB04C 80226FDC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB050 80226FE0 00000000 */  nop       
/* 6DB054 80226FE4 00000024 */  and       $zero, $zero, $zero
/* 6DB058 80226FE8 00000002 */  srl       $zero, $zero, 0
/* 6DB05C 80226FEC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB060 80226FF0 00000000 */  nop       
/* 6DB064 80226FF4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DB068 80226FF8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB06C 80226FFC 00000000 */  nop       
/* 6DB070 80227000 00000043 */  sra       $zero, $zero, 1
/* 6DB074 80227004 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DB078 80227008 802C9364 */  lb        $t4, -0x6c9c($at)
/* 6DB07C 8022700C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DB080 80227010 00000000 */  nop       
/* 6DB084 80227014 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB088 80227018 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB08C 8022701C 00000027 */  not       $zero, $zero
/* 6DB090 80227020 00000002 */  srl       $zero, $zero, 0
/* 6DB094 80227024 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB098 80227028 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6DB09C 8022702C 00000027 */  not       $zero, $zero
/* 6DB0A0 80227030 00000002 */  srl       $zero, $zero, 0
/* 6DB0A4 80227034 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB0A8 80227038 FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 6DB0AC 8022703C 00000008 */  jr        $zero
/* 6DB0B0 80227040 00000001 */   movf     $zero, $zero, $fcc0
/* 6DB0B4 80227044 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB0B8 80227048 00000006 */  srlv      $zero, $zero, $zero
/* 6DB0BC 8022704C 00000000 */  nop       
/* 6DB0C0 80227050 00000002 */  srl       $zero, $zero, 0
/* 6DB0C4 80227054 00000000 */  nop       
/* 6DB0C8 80227058 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB0CC 8022705C 00000000 */  nop       
/* 6DB0D0 80227060 00000024 */  and       $zero, $zero, $zero
/* 6DB0D4 80227064 00000002 */  srl       $zero, $zero, 0
/* 6DB0D8 80227068 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DB0DC 8022706C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB0E0 80227070 00000024 */  and       $zero, $zero, $zero
/* 6DB0E4 80227074 00000002 */  srl       $zero, $zero, 0
/* 6DB0E8 80227078 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6DB0EC 8022707C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DB0F0 80227080 00000024 */  and       $zero, $zero, $zero
/* 6DB0F4 80227084 00000002 */  srl       $zero, $zero, 0
/* 6DB0F8 80227088 FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 6DB0FC 8022708C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DB100 80227090 00000043 */  sra       $zero, $zero, 1
/* 6DB104 80227094 00000003 */  sra       $zero, $zero, 0
/* 6DB108 80227098 802C9000 */  lb        $t4, -0x7000($at)
/* 6DB10C 8022709C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB110 802270A0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB114 802270A4 00000024 */  and       $zero, $zero, $zero
/* 6DB118 802270A8 00000002 */  srl       $zero, $zero, 0
/* 6DB11C 802270AC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB120 802270B0 00000000 */  nop       
/* 6DB124 802270B4 00000024 */  and       $zero, $zero, $zero
/* 6DB128 802270B8 00000002 */  srl       $zero, $zero, 0
/* 6DB12C 802270BC FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB130 802270C0 00000000 */  nop       
/* 6DB134 802270C4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DB138 802270C8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB13C 802270CC 00000000 */  nop       
/* 6DB140 802270D0 00000043 */  sra       $zero, $zero, 1
/* 6DB144 802270D4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DB148 802270D8 802C9364 */  lb        $t4, -0x6c9c($at)
/* 6DB14C 802270DC FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DB150 802270E0 00000000 */  nop       
/* 6DB154 802270E4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB158 802270E8 00000000 */  nop       
/* 6DB15C 802270EC 00000043 */  sra       $zero, $zero, 1
/* 6DB160 802270F0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DB164 802270F4 802C9364 */  lb        $t4, -0x6c9c($at)
/* 6DB168 802270F8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DB16C 802270FC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB170 80227100 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB174 80227104 00000000 */  nop       
/* 6DB178 80227108 00000027 */  not       $zero, $zero
/* 6DB17C 8022710C 00000002 */  srl       $zero, $zero, 0
/* 6DB180 80227110 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB184 80227114 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6DB188 80227118 00000027 */  not       $zero, $zero
/* 6DB18C 8022711C 00000002 */  srl       $zero, $zero, 0
/* 6DB190 80227120 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB194 80227124 FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 6DB198 80227128 00000008 */  jr        $zero
/* 6DB19C 8022712C 00000001 */   movf     $zero, $zero, $fcc0
/* 6DB1A0 80227130 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB1A4 80227134 00000006 */  srlv      $zero, $zero, $zero
/* 6DB1A8 80227138 00000000 */  nop       
/* 6DB1AC 8022713C 00000002 */  srl       $zero, $zero, 0
/* 6DB1B0 80227140 00000000 */  nop       
/* 6DB1B4 80227144 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB1B8 80227148 00000000 */  nop       
/* 6DB1BC 8022714C 00000024 */  and       $zero, $zero, $zero
/* 6DB1C0 80227150 00000002 */  srl       $zero, $zero, 0
/* 6DB1C4 80227154 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DB1C8 80227158 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB1CC 8022715C 00000024 */  and       $zero, $zero, $zero
/* 6DB1D0 80227160 00000002 */  srl       $zero, $zero, 0
/* 6DB1D4 80227164 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6DB1D8 80227168 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DB1DC 8022716C 00000024 */  and       $zero, $zero, $zero
/* 6DB1E0 80227170 00000002 */  srl       $zero, $zero, 0
/* 6DB1E4 80227174 FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 6DB1E8 80227178 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DB1EC 8022717C 00000043 */  sra       $zero, $zero, 1
/* 6DB1F0 80227180 00000003 */  sra       $zero, $zero, 0
/* 6DB1F4 80227184 802C9000 */  lb        $t4, -0x7000($at)
/* 6DB1F8 80227188 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB1FC 8022718C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB200 80227190 00000024 */  and       $zero, $zero, $zero
/* 6DB204 80227194 00000002 */  srl       $zero, $zero, 0
/* 6DB208 80227198 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB20C 8022719C 00000000 */  nop       
/* 6DB210 802271A0 00000024 */  and       $zero, $zero, $zero
/* 6DB214 802271A4 00000002 */  srl       $zero, $zero, 0
/* 6DB218 802271A8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB21C 802271AC 00000000 */  nop       
/* 6DB220 802271B0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DB224 802271B4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB228 802271B8 00000000 */  nop       
/* 6DB22C 802271BC 00000043 */  sra       $zero, $zero, 1
/* 6DB230 802271C0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DB234 802271C4 802C9364 */  lb        $t4, -0x6c9c($at)
/* 6DB238 802271C8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DB23C 802271CC 00000000 */  nop       
/* 6DB240 802271D0 00000000 */  nop       
/* 6DB244 802271D4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB248 802271D8 00000043 */  sra       $zero, $zero, 1
/* 6DB24C 802271DC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DB250 802271E0 802C9364 */  lb        $t4, -0x6c9c($at)
/* 6DB254 802271E4 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DB258 802271E8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB25C 802271EC 00000000 */  nop       
/* 6DB260 802271F0 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB264 802271F4 00000027 */  not       $zero, $zero
/* 6DB268 802271F8 00000002 */  srl       $zero, $zero, 0
/* 6DB26C 802271FC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB270 80227200 FE363C8B */  sd        $s6, 0x3c8b($s1)
/* 6DB274 80227204 00000027 */  not       $zero, $zero
/* 6DB278 80227208 00000002 */  srl       $zero, $zero, 0
/* 6DB27C 8022720C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB280 80227210 FE363C8C */  sd        $s6, 0x3c8c($s1)
/* 6DB284 80227214 00000008 */  jr        $zero
/* 6DB288 80227218 00000001 */   movf     $zero, $zero, $fcc0
/* 6DB28C 8022721C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB290 80227220 00000006 */  srlv      $zero, $zero, $zero
/* 6DB294 80227224 00000000 */  nop       
/* 6DB298 80227228 00000002 */  srl       $zero, $zero, 0
/* 6DB29C 8022722C 00000000 */  nop       
/* 6DB2A0 80227230 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB2A4 80227234 00000000 */  nop       
/* 6DB2A8 80227238 00000043 */  sra       $zero, $zero, 1
/* 6DB2AC 8022723C 00000002 */  srl       $zero, $zero, 0
/* 6DB2B0 80227240 802D9700 */  lb        $t5, -0x6900($at)
/* 6DB2B4 80227244 FFFFFFFF */  sd        $ra, -1($ra)
/* 6DB2B8 80227248 00000043 */  sra       $zero, $zero, 1
/* 6DB2BC 8022724C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DB2C0 80227250 802CAD98 */  lb        $t4, -0x5268($at)
/* 6DB2C4 80227254 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB2C8 80227258 00000000 */  nop       
/* 6DB2CC 8022725C 00000000 */  nop       
/* 6DB2D0 80227260 00000000 */  nop       
/* 6DB2D4 80227264 00000024 */  and       $zero, $zero, $zero
/* 6DB2D8 80227268 00000002 */  srl       $zero, $zero, 0
/* 6DB2DC 8022726C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB2E0 80227270 00000010 */  mfhi      $zero
/* 6DB2E4 80227274 00000024 */  and       $zero, $zero, $zero
/* 6DB2E8 80227278 00000002 */  srl       $zero, $zero, 0
/* 6DB2EC 8022727C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB2F0 80227280 00000000 */  nop       
/* 6DB2F4 80227284 00000024 */  and       $zero, $zero, $zero
/* 6DB2F8 80227288 00000002 */  srl       $zero, $zero, 0
/* 6DB2FC 8022728C FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DB300 80227290 FFFFFF38 */  sd        $ra, -0xc8($ra)
/* 6DB304 80227294 00000024 */  and       $zero, $zero, $zero
/* 6DB308 80227298 00000002 */  srl       $zero, $zero, 0
/* 6DB30C 8022729C FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DB310 802272A0 00000000 */  nop       
/* 6DB314 802272A4 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DB318 802272A8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB31C 802272AC 80226F90 */  lb        $v0, 0x6f90($at)
/* 6DB320 802272B0 00000024 */  and       $zero, $zero, $zero
/* 6DB324 802272B4 00000002 */  srl       $zero, $zero, 0
/* 6DB328 802272B8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB32C 802272BC 00000011 */  mthi      $zero
/* 6DB330 802272C0 00000024 */  and       $zero, $zero, $zero
/* 6DB334 802272C4 00000002 */  srl       $zero, $zero, 0
/* 6DB338 802272C8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB33C 802272CC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB340 802272D0 00000024 */  and       $zero, $zero, $zero
/* 6DB344 802272D4 00000002 */  srl       $zero, $zero, 0
/* 6DB348 802272D8 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DB34C 802272DC FFFFFF88 */  sd        $ra, -0x78($ra)
/* 6DB350 802272E0 00000024 */  and       $zero, $zero, $zero
/* 6DB354 802272E4 00000002 */  srl       $zero, $zero, 0
/* 6DB358 802272E8 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DB35C 802272EC 00000000 */  nop       
/* 6DB360 802272F0 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DB364 802272F4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB368 802272F8 80226F90 */  lb        $v0, 0x6f90($at)
/* 6DB36C 802272FC 00000024 */  and       $zero, $zero, $zero
/* 6DB370 80227300 00000002 */  srl       $zero, $zero, 0
/* 6DB374 80227304 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB378 80227308 00000000 */  nop       
/* 6DB37C 8022730C 00000024 */  and       $zero, $zero, $zero
/* 6DB380 80227310 00000002 */  srl       $zero, $zero, 0
/* 6DB384 80227314 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB388 80227318 00000002 */  srl       $zero, $zero, 0
/* 6DB38C 8022731C 00000024 */  and       $zero, $zero, $zero
/* 6DB390 80227320 00000002 */  srl       $zero, $zero, 0
/* 6DB394 80227324 FE363C82 */  sd        $s6, 0x3c82($s1)
/* 6DB398 80227328 FFFFFF9C */  sd        $ra, -0x64($ra)
/* 6DB39C 8022732C 00000024 */  and       $zero, $zero, $zero
/* 6DB3A0 80227330 00000002 */  srl       $zero, $zero, 0
/* 6DB3A4 80227334 FE363C83 */  sd        $s6, 0x3c83($s1)
/* 6DB3A8 80227338 00000000 */  nop       
/* 6DB3AC 8022733C 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 6DB3B0 80227340 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB3B4 80227344 80226F90 */  lb        $v0, 0x6f90($at)
/* 6DB3B8 80227348 00000002 */  srl       $zero, $zero, 0
/* 6DB3BC 8022734C 00000000 */  nop       
/* 6DB3C0 80227350 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB3C4 80227354 00000000 */  nop       
/* 6DB3C8 80227358 00000002 */  srl       $zero, $zero, 0
/* 6DB3CC 8022735C 00000000 */  nop       
/* 6DB3D0 80227360 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB3D4 80227364 00000000 */  nop       
/* 6DB3D8 80227368 00000011 */  mthi      $zero
/* 6DB3DC 8022736C 00000000 */  nop       
/* 6DB3E0 80227370 80227B60 */  lb        $v0, 0x7b60($at)
/* 6DB3E4 80227374 80227B50 */  lb        $v0, 0x7b50($at)
/* 6DB3E8 80227378 80227B40 */  lb        $v0, 0x7b40($at)
/* 6DB3EC 8022737C 80227238 */  lb        $v0, 0x7238($at)
/* 6DB3F0 80227380 80227358 */  lb        $v0, 0x7358($at)
/* 6DB3F4 80227384 00000000 */  nop       
/* 6DB3F8 80227388 80227368 */  lb        $v0, 0x7368($at)
/* 6DB3FC 8022738C 00000000 */  nop       
/* 6DB400 80227390 00000000 */  nop       
/* 6DB404 80227394 00000000 */  nop       
/* 6DB408 80227398 00000000 */  nop       
/* 6DB40C 8022739C 00000000 */  nop       
/* 6DB410 802273A0 00000043 */  sra       $zero, $zero, 1
/* 6DB414 802273A4 00000002 */  srl       $zero, $zero, 0
/* 6DB418 802273A8 802D9700 */  lb        $t5, -0x6900($at)
/* 6DB41C 802273AC FFFFFFFF */  sd        $ra, -1($ra)
/* 6DB420 802273B0 00000043 */  sra       $zero, $zero, 1
/* 6DB424 802273B4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DB428 802273B8 802CAD98 */  lb        $t4, -0x5268($at)
/* 6DB42C 802273BC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB430 802273C0 00000000 */  nop       
/* 6DB434 802273C4 00000000 */  nop       
/* 6DB438 802273C8 00000000 */  nop       
/* 6DB43C 802273CC 00000002 */  srl       $zero, $zero, 0
/* 6DB440 802273D0 00000000 */  nop       
/* 6DB444 802273D4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB448 802273D8 00000000 */  nop       
/* 6DB44C 802273DC 00000002 */  srl       $zero, $zero, 0
/* 6DB450 802273E0 00000000 */  nop       
/* 6DB454 802273E4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB458 802273E8 00000000 */  nop       
/* 6DB45C 802273EC 00000016 */  dsrlv     $zero, $zero, $zero
/* 6DB460 802273F0 00000000 */  nop       
/* 6DB464 802273F4 80227B88 */  lb        $v0, 0x7b88($at)
/* 6DB468 802273F8 80227B78 */  lb        $v0, 0x7b78($at)
/* 6DB46C 802273FC 80227B68 */  lb        $v0, 0x7b68($at)
/* 6DB470 80227400 802273A0 */  lb        $v0, 0x73a0($at)
/* 6DB474 80227404 802273DC */  lb        $v0, 0x73dc($at)
/* 6DB478 80227408 00000000 */  nop       
/* 6DB47C 8022740C 802273EC */  lb        $v0, 0x73ec($at)
/* 6DB480 80227410 00000000 */  nop       
/* 6DB484 80227414 00000000 */  nop       
/* 6DB488 80227418 00000000 */  nop       
/* 6DB48C 8022741C 00000000 */  nop       
/* 6DB490 80227420 00000043 */  sra       $zero, $zero, 1
/* 6DB494 80227424 00000002 */  srl       $zero, $zero, 0
/* 6DB498 80227428 802D9700 */  lb        $t5, -0x6900($at)
/* 6DB49C 8022742C FFFFFFFF */  sd        $ra, -1($ra)
/* 6DB4A0 80227430 00000043 */  sra       $zero, $zero, 1
/* 6DB4A4 80227434 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DB4A8 80227438 802CAD98 */  lb        $t4, -0x5268($at)
/* 6DB4AC 8022743C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB4B0 80227440 00000000 */  nop       
/* 6DB4B4 80227444 00000000 */  nop       
/* 6DB4B8 80227448 00000000 */  nop       
/* 6DB4BC 8022744C 00000002 */  srl       $zero, $zero, 0
/* 6DB4C0 80227450 00000000 */  nop       
/* 6DB4C4 80227454 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB4C8 80227458 00000000 */  nop       
/* 6DB4CC 8022745C 00000002 */  srl       $zero, $zero, 0
/* 6DB4D0 80227460 00000000 */  nop       
/* 6DB4D4 80227464 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB4D8 80227468 00000000 */  nop       
/* 6DB4DC 8022746C 0000000C */  syscall   
/* 6DB4E0 80227470 00000000 */  nop       
/* 6DB4E4 80227474 80227BB0 */  lb        $v0, 0x7bb0($at)
/* 6DB4E8 80227478 80227BA0 */  lb        $v0, 0x7ba0($at)
/* 6DB4EC 8022747C 80227B90 */  lb        $v0, 0x7b90($at)
/* 6DB4F0 80227480 80227420 */  lb        $v0, 0x7420($at)
/* 6DB4F4 80227484 8022745C */  lb        $v0, 0x745c($at)
/* 6DB4F8 80227488 00000000 */  nop       
/* 6DB4FC 8022748C 8022746C */  lb        $v0, 0x746c($at)
/* 6DB500 80227490 00000000 */  nop       
/* 6DB504 80227494 00000000 */  nop       
/* 6DB508 80227498 00000000 */  nop       
/* 6DB50C 8022749C 00000000 */  nop       
/* 6DB510 802274A0 00000043 */  sra       $zero, $zero, 1
/* 6DB514 802274A4 00000002 */  srl       $zero, $zero, 0
/* 6DB518 802274A8 802D9700 */  lb        $t5, -0x6900($at)
/* 6DB51C 802274AC FFFFFFFF */  sd        $ra, -1($ra)
/* 6DB520 802274B0 00000043 */  sra       $zero, $zero, 1
/* 6DB524 802274B4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DB528 802274B8 802CAD98 */  lb        $t4, -0x5268($at)
/* 6DB52C 802274BC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB530 802274C0 00000000 */  nop       
/* 6DB534 802274C4 00000000 */  nop       
/* 6DB538 802274C8 00000000 */  nop       
/* 6DB53C 802274CC 00000002 */  srl       $zero, $zero, 0
/* 6DB540 802274D0 00000000 */  nop       
/* 6DB544 802274D4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB548 802274D8 00000000 */  nop       
/* 6DB54C 802274DC 00000002 */  srl       $zero, $zero, 0
/* 6DB550 802274E0 00000000 */  nop       
/* 6DB554 802274E4 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB558 802274E8 00000000 */  nop       
/* 6DB55C 802274EC 0000000A */  movz      $zero, $zero, $zero
/* 6DB560 802274F0 00000000 */  nop       
/* 6DB564 802274F4 80227BD8 */  lb        $v0, 0x7bd8($at)
/* 6DB568 802274F8 80227BC8 */  lb        $v0, 0x7bc8($at)
/* 6DB56C 802274FC 80227BB8 */  lb        $v0, 0x7bb8($at)
/* 6DB570 80227500 802274A0 */  lb        $v0, 0x74a0($at)
/* 6DB574 80227504 802274DC */  lb        $v0, 0x74dc($at)
/* 6DB578 80227508 00000000 */  nop       
/* 6DB57C 8022750C 802274EC */  lb        $v0, 0x74ec($at)
/* 6DB580 80227510 00000000 */  nop       
/* 6DB584 80227514 00000000 */  nop       
/* 6DB588 80227518 00000000 */  nop       
/* 6DB58C 8022751C 00000000 */  nop       
/* 6DB590 80227520 00000024 */  and       $zero, $zero, $zero
/* 6DB594 80227524 00000002 */  srl       $zero, $zero, 0
/* 6DB598 80227528 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DB59C 8022752C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB5A0 80227530 00000043 */  sra       $zero, $zero, 1
/* 6DB5A4 80227534 00000003 */  sra       $zero, $zero, 0
/* 6DB5A8 80227538 802C9000 */  lb        $t4, -0x7000($at)
/* 6DB5AC 8022753C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DB5B0 80227540 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB5B4 80227544 00000024 */  and       $zero, $zero, $zero
/* 6DB5B8 80227548 00000002 */  srl       $zero, $zero, 0
/* 6DB5BC 8022754C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB5C0 80227550 00000000 */  nop       
/* 6DB5C4 80227554 00000024 */  and       $zero, $zero, $zero
/* 6DB5C8 80227558 00000002 */  srl       $zero, $zero, 0
/* 6DB5CC 8022755C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB5D0 80227560 00000000 */  nop       
/* 6DB5D4 80227564 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DB5D8 80227568 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB5DC 8022756C 00000000 */  nop       
/* 6DB5E0 80227570 00000043 */  sra       $zero, $zero, 1
/* 6DB5E4 80227574 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DB5E8 80227578 802C9364 */  lb        $t4, -0x6c9c($at)
/* 6DB5EC 8022757C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB5F0 80227580 00000000 */  nop       
/* 6DB5F4 80227584 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB5F8 80227588 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB5FC 8022758C 00000027 */  not       $zero, $zero
/* 6DB600 80227590 00000002 */  srl       $zero, $zero, 0
/* 6DB604 80227594 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB608 80227598 00008000 */  sll       $s0, $zero, 0
/* 6DB60C 8022759C 00000027 */  not       $zero, $zero
/* 6DB610 802275A0 00000002 */  srl       $zero, $zero, 0
/* 6DB614 802275A4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB618 802275A8 00000000 */  nop       
/* 6DB61C 802275AC 00000008 */  jr        $zero
/* 6DB620 802275B0 00000001 */   movf     $zero, $zero, $fcc0
/* 6DB624 802275B4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DB628 802275B8 00000006 */  srlv      $zero, $zero, $zero
/* 6DB62C 802275BC 00000000 */  nop       
/* 6DB630 802275C0 00000002 */  srl       $zero, $zero, 0
/* 6DB634 802275C4 00000000 */  nop       
/* 6DB638 802275C8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB63C 802275CC 00000000 */  nop       
/* 6DB640 802275D0 00000043 */  sra       $zero, $zero, 1
/* 6DB644 802275D4 00000002 */  srl       $zero, $zero, 0
/* 6DB648 802275D8 802D9700 */  lb        $t5, -0x6900($at)
/* 6DB64C 802275DC FFFFFFFF */  sd        $ra, -1($ra)
/* 6DB650 802275E0 00000043 */  sra       $zero, $zero, 1
/* 6DB654 802275E4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DB658 802275E8 802CAD98 */  lb        $t4, -0x5268($at)
/* 6DB65C 802275EC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB660 802275F0 00000000 */  nop       
/* 6DB664 802275F4 00000000 */  nop       
/* 6DB668 802275F8 00000000 */  nop       
/* 6DB66C 802275FC 00000002 */  srl       $zero, $zero, 0
/* 6DB670 80227600 00000000 */  nop       
/* 6DB674 80227604 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB678 80227608 00000000 */  nop       
/* 6DB67C 8022760C 00000002 */  srl       $zero, $zero, 0
/* 6DB680 80227610 00000000 */  nop       
/* 6DB684 80227614 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB688 80227618 00000000 */  nop       
/* 6DB68C 8022761C 80227C00 */  lb        $v0, 0x7c00($at)
/* 6DB690 80227620 80227BF0 */  lb        $v0, 0x7bf0($at)
/* 6DB694 80227624 80227BE0 */  lb        $v0, 0x7be0($at)
/* 6DB698 80227628 802275D0 */  lb        $v0, 0x75d0($at)
/* 6DB69C 8022762C 8022760C */  lb        $v0, 0x760c($at)
/* 6DB6A0 80227630 00000000 */  nop       
/* 6DB6A4 80227634 00000000 */  nop       
/* 6DB6A8 80227638 00000000 */  nop       
/* 6DB6AC 8022763C 00000000 */  nop       
/* 6DB6B0 80227640 00000000 */  nop       
/* 6DB6B4 80227644 00000000 */  nop       
/* 6DB6B8 80227648 00000000 */  nop       
/* 6DB6BC 8022764C 00000000 */  nop       
/* 6DB6C0 80227650 00000024 */  and       $zero, $zero, $zero
/* 6DB6C4 80227654 00000002 */  srl       $zero, $zero, 0
/* 6DB6C8 80227658 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DB6CC 8022765C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB6D0 80227660 00000043 */  sra       $zero, $zero, 1
/* 6DB6D4 80227664 00000003 */  sra       $zero, $zero, 0
/* 6DB6D8 80227668 802C9000 */  lb        $t4, -0x7000($at)
/* 6DB6DC 8022766C FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 6DB6E0 80227670 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB6E4 80227674 00000024 */  and       $zero, $zero, $zero
/* 6DB6E8 80227678 00000002 */  srl       $zero, $zero, 0
/* 6DB6EC 8022767C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB6F0 80227680 00000000 */  nop       
/* 6DB6F4 80227684 00000024 */  and       $zero, $zero, $zero
/* 6DB6F8 80227688 00000002 */  srl       $zero, $zero, 0
/* 6DB6FC 8022768C FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB700 80227690 00000000 */  nop       
/* 6DB704 80227694 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DB708 80227698 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB70C 8022769C 00000000 */  nop       
/* 6DB710 802276A0 00000043 */  sra       $zero, $zero, 1
/* 6DB714 802276A4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DB718 802276A8 802C9364 */  lb        $t4, -0x6c9c($at)
/* 6DB71C 802276AC 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB720 802276B0 00000000 */  nop       
/* 6DB724 802276B4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB728 802276B8 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB72C 802276BC 00000027 */  not       $zero, $zero
/* 6DB730 802276C0 00000002 */  srl       $zero, $zero, 0
/* 6DB734 802276C4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 6DB738 802276C8 00008000 */  sll       $s0, $zero, 0
/* 6DB73C 802276CC 00000027 */  not       $zero, $zero
/* 6DB740 802276D0 00000002 */  srl       $zero, $zero, 0
/* 6DB744 802276D4 FE363C81 */  sd        $s6, 0x3c81($s1)
/* 6DB748 802276D8 00000000 */  nop       
/* 6DB74C 802276DC 00000008 */  jr        $zero
/* 6DB750 802276E0 00000001 */   movf     $zero, $zero, $fcc0
/* 6DB754 802276E4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DB758 802276E8 00000006 */  srlv      $zero, $zero, $zero
/* 6DB75C 802276EC 00000000 */  nop       
/* 6DB760 802276F0 00000002 */  srl       $zero, $zero, 0
/* 6DB764 802276F4 00000000 */  nop       
/* 6DB768 802276F8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB76C 802276FC 00000000 */  nop       
/* 6DB770 80227700 00000043 */  sra       $zero, $zero, 1
/* 6DB774 80227704 00000002 */  srl       $zero, $zero, 0
/* 6DB778 80227708 802D9700 */  lb        $t5, -0x6900($at)
/* 6DB77C 8022770C FFFFFFFF */  sd        $ra, -1($ra)
/* 6DB780 80227710 00000043 */  sra       $zero, $zero, 1
/* 6DB784 80227714 00000005 */  lsa       $zero, $zero, $zero, 1
/* 6DB788 80227718 802CAD98 */  lb        $t4, -0x5268($at)
/* 6DB78C 8022771C 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB790 80227720 00000000 */  nop       
/* 6DB794 80227724 00000000 */  nop       
/* 6DB798 80227728 00000000 */  nop       
/* 6DB79C 8022772C 00000002 */  srl       $zero, $zero, 0
/* 6DB7A0 80227730 00000000 */  nop       
/* 6DB7A4 80227734 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB7A8 80227738 00000000 */  nop       
/* 6DB7AC 8022773C 00000002 */  srl       $zero, $zero, 0
/* 6DB7B0 80227740 00000000 */  nop       
/* 6DB7B4 80227744 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB7B8 80227748 00000000 */  nop       
/* 6DB7BC 8022774C 80227C28 */  lb        $v0, 0x7c28($at)
/* 6DB7C0 80227750 80227C18 */  lb        $v0, 0x7c18($at)
/* 6DB7C4 80227754 80227C08 */  lb        $v0, 0x7c08($at)
/* 6DB7C8 80227758 80227700 */  lb        $v0, 0x7700($at)
/* 6DB7CC 8022775C 8022773C */  lb        $v0, 0x773c($at)
/* 6DB7D0 80227760 00000000 */  nop       
/* 6DB7D4 80227764 00000000 */  nop       
/* 6DB7D8 80227768 00000000 */  nop       
/* 6DB7DC 8022776C 00000000 */  nop       
/* 6DB7E0 80227770 00000000 */  nop       
/* 6DB7E4 80227774 00000000 */  nop       
/* 6DB7E8 80227778 00000000 */  nop       
/* 6DB7EC 8022777C 00000000 */  nop       
/* 6DB7F0 80227780 80218EEC */  lb        $at, -0x7114($at)
/* 6DB7F4 80227784 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB7F8 80227788 0000000A */  movz      $zero, $zero, $zero
/* 6DB7FC 8022778C 00000000 */  nop       
/* 6DB800 80227790 00000000 */  nop       
/* 6DB804 80227794 00000000 */  nop       
/* 6DB808 80227798 00000000 */  nop       
/* 6DB80C 8022779C 80218EEC */  lb        $at, -0x7114($at)
/* 6DB810 802277A0 00000002 */  srl       $zero, $zero, 0
/* 6DB814 802277A4 00000009 */  jr        $zero
/* 6DB818 802277A8 00000000 */   nop      
/* 6DB81C 802277AC 00000000 */  nop       
/* 6DB820 802277B0 00000000 */  nop       
/* 6DB824 802277B4 00000000 */  nop       
/* 6DB828 802277B8 80218EEC */  lb        $at, -0x7114($at)
/* 6DB82C 802277BC 00000000 */  nop       
/* 6DB830 802277C0 0000000A */  movz      $zero, $zero, $zero
/* 6DB834 802277C4 00000000 */  nop       
/* 6DB838 802277C8 00000000 */  nop       
/* 6DB83C 802277CC 00000000 */  nop       
/* 6DB840 802277D0 00000000 */  nop       
/* 6DB844 802277D4 80218EEC */  lb        $at, -0x7114($at)
/* 6DB848 802277D8 00000001 */  movf      $zero, $zero, $fcc0
/* 6DB84C 802277DC 00000009 */  jr        $zero
/* 6DB850 802277E0 00000000 */   nop      
/* 6DB854 802277E4 00000000 */  nop       
/* 6DB858 802277E8 00000000 */  nop       
/* 6DB85C 802277EC 00000000 */  nop       
/* 6DB860 802277F0 80218EEC */  lb        $at, -0x7114($at)
/* 6DB864 802277F4 00000002 */  srl       $zero, $zero, 0
/* 6DB868 802277F8 00000008 */  jr        $zero
/* 6DB86C 802277FC 00000000 */   nop      
/* 6DB870 80227800 00000000 */  nop       
/* 6DB874 80227804 00000000 */  nop       
/* 6DB878 80227808 00000000 */  nop       
/* 6DB87C 8022780C 00000046 */  rotrv     $zero, $zero, $zero
/* 6DB880 80227810 00000000 */  nop       
/* 6DB884 80227814 FFFFFFEC */  sd        $ra, -0x14($ra)
/* 6DB888 80227818 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 6DB88C 8022781C 00000000 */  nop       
/* 6DB890 80227820 00000000 */  nop       
/* 6DB894 80227824 8021872C */  lb        $at, -0x78d4($at)
/* 6DB898 80227828 8022780C */  lb        $v0, 0x780c($at)
/* 6DB89C 8022782C 0000000A */  movz      $zero, $zero, $zero
/* 6DB8A0 80227830 00000000 */  nop       
/* 6DB8A4 80227834 00000000 */  nop       
/* 6DB8A8 80227838 00000000 */  nop       
/* 6DB8AC 8022783C 00000000 */  nop       
/* 6DB8B0 80227840 8021872C */  lb        $at, -0x78d4($at)
/* 6DB8B4 80227844 80227818 */  lb        $v0, 0x7818($at)
/* 6DB8B8 80227848 00000009 */  jr        $zero
/* 6DB8BC 8022784C 00000000 */   nop      
/* 6DB8C0 80227850 00000000 */  nop       
/* 6DB8C4 80227854 00000000 */  nop       
/* 6DB8C8 80227858 00000000 */  nop       
/* 6DB8CC 8022785C 00000082 */  srl       $zero, $zero, 2
/* 6DB8D0 80227860 00000000 */  nop       
/* 6DB8D4 80227864 00000019 */  multu     $zero, $zero
/* 6DB8D8 80227868 8021872C */  lb        $at, -0x78d4($at)
/* 6DB8DC 8022786C 8022780C */  lb        $v0, 0x780c($at)
/* 6DB8E0 80227870 0000000A */  movz      $zero, $zero, $zero
/* 6DB8E4 80227874 00000000 */  nop       
/* 6DB8E8 80227878 00000000 */  nop       
/* 6DB8EC 8022787C 00000000 */  nop       
/* 6DB8F0 80227880 00000000 */  nop       
/* 6DB8F4 80227884 8021872C */  lb        $at, -0x78d4($at)
/* 6DB8F8 80227888 80227818 */  lb        $v0, 0x7818($at)
/* 6DB8FC 8022788C 00000009 */  jr        $zero
/* 6DB900 80227890 00000000 */   nop      
/* 6DB904 80227894 00000000 */  nop       
/* 6DB908 80227898 00000000 */  nop       
/* 6DB90C 8022789C 00000000 */  nop       
/* 6DB910 802278A0 80219EA0 */  lb        $at, -0x6160($at)
/* 6DB914 802278A4 8022785C */  lb        $v0, 0x785c($at)
/* 6DB918 802278A8 00000008 */  jr        $zero
/* 6DB91C 802278AC 00000000 */   nop      
/* 6DB920 802278B0 00000000 */  nop       
/* 6DB924 802278B4 00000000 */  nop       
/* 6DB928 802278B8 00000000 */  nop       
/* 6DB92C 802278BC 8021872C */  lb        $at, -0x78d4($at)
/* 6DB930 802278C0 8022780C */  lb        $v0, 0x780c($at)
/* 6DB934 802278C4 0000000A */  movz      $zero, $zero, $zero
/* 6DB938 802278C8 00000000 */  nop       
/* 6DB93C 802278CC 00000000 */  nop       
/* 6DB940 802278D0 00000000 */  nop       
/* 6DB944 802278D4 00000000 */  nop       
/* 6DB948 802278D8 8021872C */  lb        $at, -0x78d4($at)
/* 6DB94C 802278DC 80227818 */  lb        $v0, 0x7818($at)
/* 6DB950 802278E0 00000009 */  jr        $zero
/* 6DB954 802278E4 00000000 */   nop      
/* 6DB958 802278E8 00000000 */  nop       
/* 6DB95C 802278EC 00000000 */  nop       
/* 6DB960 802278F0 00000000 */  nop       
/* 6DB964 802278F4 8021E9D0 */  lb        $at, -0x1630($at)
/* 6DB968 802278F8 8022785C */  lb        $v0, 0x785c($at)
/* 6DB96C 802278FC 00000008 */  jr        $zero
/* 6DB970 80227900 00000000 */   nop      
/* 6DB974 80227904 00000000 */  nop       
/* 6DB978 80227908 00000000 */  nop       
/* 6DB97C 8022790C 00000000 */  nop       
/* 6DB980 80227910 80227CA8 */  lb        $v0, 0x7ca8($at)
/* 6DB984 80227914 00000002 */  srl       $zero, $zero, 0
/* 6DB988 80227918 80227780 */  lb        $v0, 0x7780($at)
/* 6DB98C 8022791C 80226234 */  lb        $v0, 0x6234($at)
/* 6DB990 80227920 00000000 */  nop       
/* 6DB994 80227924 80227C94 */  lb        $v0, 0x7c94($at)
/* 6DB998 80227928 00000003 */  sra       $zero, $zero, 0
/* 6DB99C 8022792C 802277B8 */  lb        $v0, 0x77b8($at)
/* 6DB9A0 80227930 80226234 */  lb        $v0, 0x6234($at)
/* 6DB9A4 80227934 00000000 */  nop       
/* 6DB9A8 80227938 80227C78 */  lb        $v0, 0x7c78($at)
/* 6DB9AC 8022793C 00000002 */  srl       $zero, $zero, 0
/* 6DB9B0 80227940 80227824 */  lb        $v0, 0x7824($at)
/* 6DB9B4 80227944 80226234 */  lb        $v0, 0x6234($at)
/* 6DB9B8 80227948 00000000 */  nop       
/* 6DB9BC 8022794C 80227C54 */  lb        $v0, 0x7c54($at)
/* 6DB9C0 80227950 00000003 */  sra       $zero, $zero, 0
/* 6DB9C4 80227954 80227868 */  lb        $v0, 0x7868($at)
/* 6DB9C8 80227958 80226234 */  lb        $v0, 0x6234($at)
/* 6DB9CC 8022795C 00000000 */  nop       
/* 6DB9D0 80227960 80227C30 */  lb        $v0, 0x7c30($at)
/* 6DB9D4 80227964 00000003 */  sra       $zero, $zero, 0
/* 6DB9D8 80227968 802278BC */  lb        $v0, 0x78bc($at)
/* 6DB9DC 8022796C 80226234 */  lb        $v0, 0x6234($at)
/* 6DB9E0 80227970 00000000 */  nop       
/* 6DB9E4 80227974 00000000 */  nop       
/* 6DB9E8 80227978 00000000 */  nop       
/* 6DB9EC 8022797C 00000000 */  nop       
/* 6DB9F0 80227980 00000000 */  nop       
/* 6DB9F4 80227984 00000000 */  nop       
/* 6DB9F8 80227988 80227D24 */  lb        $v0, 0x7d24($at)
/* 6DB9FC 8022798C 80226234 */  lb        $v0, 0x6234($at)
/* 6DBA00 80227990 80227D1C */  lb        $v0, 0x7d1c($at)
/* 6DBA04 80227994 802263B8 */  lb        $v0, 0x63b8($at)
/* 6DBA08 80227998 80227D14 */  lb        $v0, 0x7d14($at)
/* 6DBA0C 8022799C 8022680C */  lb        $v0, 0x680c($at)
/* 6DBA10 802279A0 80227D0C */  lb        $v0, 0x7d0c($at)
/* 6DBA14 802279A4 80226AC0 */  lb        $v0, 0x6ac0($at)
/* 6DBA18 802279A8 80227D04 */  lb        $v0, 0x7d04($at)
/* 6DBA1C 802279AC 80226AC0 */  lb        $v0, 0x6ac0($at)
/* 6DBA20 802279B0 80227CFC */  lb        $v0, 0x7cfc($at)
/* 6DBA24 802279B4 80226CCC */  lb        $v0, 0x6ccc($at)
/* 6DBA28 802279B8 80227CF4 */  lb        $v0, 0x7cf4($at)
/* 6DBA2C 802279BC 80226EE4 */  lb        $v0, 0x6ee4($at)
/* 6DBA30 802279C0 80227CEC */  lb        $v0, 0x7cec($at)
/* 6DBA34 802279C4 80226F64 */  lb        $v0, 0x6f64($at)
/* 6DBA38 802279C8 80227CE4 */  lb        $v0, 0x7ce4($at)
/* 6DBA3C 802279CC 80227370 */  lb        $v0, 0x7370($at)
/* 6DBA40 802279D0 80227CDC */  lb        $v0, 0x7cdc($at)
/* 6DBA44 802279D4 802273F4 */  lb        $v0, 0x73f4($at)
/* 6DBA48 802279D8 80227CD4 */  lb        $v0, 0x7cd4($at)
/* 6DBA4C 802279DC 80227474 */  lb        $v0, 0x7474($at)
/* 6DBA50 802279E0 80227CCC */  lb        $v0, 0x7ccc($at)
/* 6DBA54 802279E4 802274F4 */  lb        $v0, 0x74f4($at)
/* 6DBA58 802279E8 80227CC4 */  lb        $v0, 0x7cc4($at)
/* 6DBA5C 802279EC 8022761C */  lb        $v0, 0x761c($at)
/* 6DBA60 802279F0 80227CBC */  lb        $v0, 0x7cbc($at)
/* 6DBA64 802279F4 8022774C */  lb        $v0, 0x774c($at)
/* 6DBA68 802279F8 00000000 */  nop       
/* 6DBA6C 802279FC 00000000 */  nop       
/* 6DBA70 80227A00 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBA74 80227A04 62743031 */  daddi     $s4, $s3, 0x3031
/* 6DBA78 80227A08 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 6DBA7C 80227A0C 00000000 */  nop       
/* 6DBA80 80227A10 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBA84 80227A14 62743031 */  daddi     $s4, $s3, 0x3031
/* 6DBA88 80227A18 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 6DBA8C 80227A1C 70650000 */  madd      $v1, $a1
/* 6DBA90 80227A20 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBA94 80227A24 74657800 */  jalx      0x8195e000
/* 6DBA98 80227A28 6B70615F */   ldl      $s0, 0x615f($k1)
/* 6DBA9C 80227A2C 62743031 */  daddi     $s4, $s3, 0x3031
/* 6DBAA0 80227A30 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 6DBAA4 80227A34 00000000 */  nop       
/* 6DBAA8 80227A38 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBAAC 80227A3C 62743031 */  daddi     $s4, $s3, 0x3031
/* 6DBAB0 80227A40 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 6DBAB4 80227A44 70650000 */  madd      $v1, $a1
/* 6DBAB8 80227A48 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBABC 80227A4C 74657800 */  jalx      0x8195e000
/* 6DBAC0 80227A50 6B70615F */   ldl      $s0, 0x615f($k1)
/* 6DBAC4 80227A54 62743032 */  daddi     $s4, $s3, 0x3032
/* 6DBAC8 80227A58 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 6DBACC 80227A5C 00000000 */  nop       
/* 6DBAD0 80227A60 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBAD4 80227A64 62743032 */  daddi     $s4, $s3, 0x3032
/* 6DBAD8 80227A68 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 6DBADC 80227A6C 70650000 */  madd      $v1, $a1
/* 6DBAE0 80227A70 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBAE4 80227A74 74657800 */  jalx      0x8195e000
/* 6DBAE8 80227A78 6B70615F */   ldl      $s0, 0x615f($k1)
/* 6DBAEC 80227A7C 62743033 */  daddi     $s4, $s3, 0x3033
/* 6DBAF0 80227A80 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 6DBAF4 80227A84 00000000 */  nop       
/* 6DBAF8 80227A88 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBAFC 80227A8C 62743033 */  daddi     $s4, $s3, 0x3033
/* 6DBB00 80227A90 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 6DBB04 80227A94 70650000 */  madd      $v1, $a1
/* 6DBB08 80227A98 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBB0C 80227A9C 74657800 */  jalx      0x8195e000
/* 6DBB10 80227AA0 6B70615F */   ldl      $s0, 0x615f($k1)
/* 6DBB14 80227AA4 62743034 */  daddi     $s4, $s3, 0x3034
/* 6DBB18 80227AA8 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 6DBB1C 80227AAC 00000000 */  nop       
/* 6DBB20 80227AB0 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBB24 80227AB4 62743034 */  daddi     $s4, $s3, 0x3034
/* 6DBB28 80227AB8 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 6DBB2C 80227ABC 70650000 */  madd      $v1, $a1
/* 6DBB30 80227AC0 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBB34 80227AC4 74657800 */  jalx      0x8195e000
/* 6DBB38 80227AC8 6B70615F */   ldl      $s0, 0x615f($k1)
/* 6DBB3C 80227ACC 62743034 */  daddi     $s4, $s3, 0x3034
/* 6DBB40 80227AD0 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 6DBB44 80227AD4 00000000 */  nop       
/* 6DBB48 80227AD8 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBB4C 80227ADC 62743034 */  daddi     $s4, $s3, 0x3034
/* 6DBB50 80227AE0 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 6DBB54 80227AE4 70650000 */  madd      $v1, $a1
/* 6DBB58 80227AE8 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBB5C 80227AEC 74657800 */  jalx      0x8195e000
/* 6DBB60 80227AF0 6B70615F */   ldl      $s0, 0x615f($k1)
/* 6DBB64 80227AF4 62743034 */  daddi     $s4, $s3, 0x3034
/* 6DBB68 80227AF8 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 6DBB6C 80227AFC 00000000 */  nop       
/* 6DBB70 80227B00 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBB74 80227B04 62743034 */  daddi     $s4, $s3, 0x3034
/* 6DBB78 80227B08 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 6DBB7C 80227B0C 70650000 */  madd      $v1, $a1
/* 6DBB80 80227B10 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBB84 80227B14 74657800 */  jalx      0x8195e000
/* 6DBB88 80227B18 6B70615F */   ldl      $s0, 0x615f($k1)
/* 6DBB8C 80227B1C 62743035 */  daddi     $s4, $s3, 0x3035
/* 6DBB90 80227B20 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 6DBB94 80227B24 00000000 */  nop       
/* 6DBB98 80227B28 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBB9C 80227B2C 62743035 */  daddi     $s4, $s3, 0x3035
/* 6DBBA0 80227B30 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 6DBBA4 80227B34 70650000 */  madd      $v1, $a1
/* 6DBBA8 80227B38 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBBAC 80227B3C 74657800 */  jalx      0x8195e000
/* 6DBBB0 80227B40 6B70615F */   ldl      $s0, 0x615f($k1)
/* 6DBBB4 80227B44 62743037 */  daddi     $s4, $s3, 0x3037
/* 6DBBB8 80227B48 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 6DBBBC 80227B4C 00000000 */  nop       
/* 6DBBC0 80227B50 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBBC4 80227B54 62743037 */  daddi     $s4, $s3, 0x3037
/* 6DBBC8 80227B58 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 6DBBCC 80227B5C 70650000 */  madd      $v1, $a1
/* 6DBBD0 80227B60 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBBD4 80227B64 74657800 */  jalx      0x8195e000
/* 6DBBD8 80227B68 6B70615F */   ldl      $s0, 0x615f($k1)
/* 6DBBDC 80227B6C 62743038 */  daddi     $s4, $s3, 0x3038
/* 6DBBE0 80227B70 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 6DBBE4 80227B74 00000000 */  nop       
/* 6DBBE8 80227B78 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBBEC 80227B7C 62743038 */  daddi     $s4, $s3, 0x3038
/* 6DBBF0 80227B80 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 6DBBF4 80227B84 70650000 */  madd      $v1, $a1
/* 6DBBF8 80227B88 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBBFC 80227B8C 74657800 */  jalx      0x8195e000
/* 6DBC00 80227B90 6B70615F */   ldl      $s0, 0x615f($k1)
/* 6DBC04 80227B94 62743039 */  daddi     $s4, $s3, 0x3039
/* 6DBC08 80227B98 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 6DBC0C 80227B9C 00000000 */  nop       
/* 6DBC10 80227BA0 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBC14 80227BA4 62743039 */  daddi     $s4, $s3, 0x3039
/* 6DBC18 80227BA8 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 6DBC1C 80227BAC 70650000 */  madd      $v1, $a1
/* 6DBC20 80227BB0 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBC24 80227BB4 74657800 */  jalx      0x8195e000
/* 6DBC28 80227BB8 6B70615F */   ldl      $s0, 0x615f($k1)
/* 6DBC2C 80227BBC 62743131 */  daddi     $s4, $s3, 0x3131
/* 6DBC30 80227BC0 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 6DBC34 80227BC4 00000000 */  nop       
/* 6DBC38 80227BC8 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBC3C 80227BCC 62743131 */  daddi     $s4, $s3, 0x3131
/* 6DBC40 80227BD0 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 6DBC44 80227BD4 70650000 */  madd      $v1, $a1
/* 6DBC48 80227BD8 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBC4C 80227BDC 74657800 */  jalx      0x8195e000
/* 6DBC50 80227BE0 6B70615F */   ldl      $s0, 0x615f($k1)
/* 6DBC54 80227BE4 62743133 */  daddi     $s4, $s3, 0x3133
/* 6DBC58 80227BE8 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 6DBC5C 80227BEC 00000000 */  nop       
/* 6DBC60 80227BF0 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBC64 80227BF4 62743133 */  daddi     $s4, $s3, 0x3133
/* 6DBC68 80227BF8 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 6DBC6C 80227BFC 70650000 */  madd      $v1, $a1
/* 6DBC70 80227C00 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBC74 80227C04 74657800 */  jalx      0x8195e000
/* 6DBC78 80227C08 6B70615F */   ldl      $s0, 0x615f($k1)
/* 6DBC7C 80227C0C 62743134 */  daddi     $s4, $s3, 0x3134
/* 6DBC80 80227C10 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 6DBC84 80227C14 00000000 */  nop       
/* 6DBC88 80227C18 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBC8C 80227C1C 62743134 */  daddi     $s4, $s3, 0x3134
/* 6DBC90 80227C20 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 6DBC94 80227C24 70650000 */  madd      $v1, $a1
/* 6DBC98 80227C28 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBC9C 80227C2C 74657800 */  jalx      0x8195e000
/* 6DBCA0 80227C30 8358815B */   lb       $t8, -0x7ea5($k0)
/* 6DBCA4 80227C34 8370815B */  lb        $s0, -0x7ea5($k1)
/* 6DBCA8 80227C38 834C8389 */  lb        $t4, -0x7c77($k0)
/* 6DBCAC 80227C3C 815B82BD */  lb        $k1, -0x7d43($t2)
/* 6DBCB0 80227C40 82A282D9 */  lb        $v0, -0x7d27($s5)
/* 6DBCB4 80227C44 82A47882 */  lb        $a0, 0x7882($s5)
/* 6DBCB8 80227C48 512C834A */  beql      $t1, $t4, .L80208974
/* 6DBCBC 80227C4C 83818362 */   lb       $at, -0x7c9e($gp)
/* 6DBCC0 80227C50 834E0000 */  lb        $t6, ($k0)
/* 6DBCC4 80227C54 8358815B */  lb        $t8, -0x7ea5($k0)
/* 6DBCC8 80227C58 8370815B */  lb        $s0, -0x7ea5($k1)
/* 6DBCCC 80227C5C 834C8389 */  lb        $t4, -0x7c77($k0)
/* 6DBCD0 80227C60 815B82BD */  lb        $k1, -0x7d43($t2)
/* 6DBCD4 80227C64 82A282D9 */  lb        $v0, -0x7d27($s5)
/* 6DBCD8 80227C68 82A47882 */  lb        $a0, 0x7882($s5)
/* 6DBCDC 80227C6C 512C8367 */  beql      $t1, $t4, .L80208A0C
/* 6DBCE0 80227C70 8351836D */   lb       $s1, -0x7c93($k0)
/* 6DBCE4 80227C74 83520000 */  lb        $s2, ($k0)
/* 6DBCE8 80227C78 8358815B */  lb        $t8, -0x7ea5($k0)
/* 6DBCEC 80227C7C 8370815B */  lb        $s0, -0x7ea5($k1)
/* 6DBCF0 80227C80 834C8389 */  lb        $t4, -0x7c77($k0)
/* 6DBCF4 80227C84 815B82BD */  lb        $k1, -0x7d43($t2)
/* 6DBCF8 80227C88 82A282D9 */  lb        $v0, -0x7d27($s5)
/* 6DBCFC 80227C8C 82A47882 */  lb        $a0, 0x7882($s5)
/* 6DBD00 80227C90 51000000 */  beql      $t0, $zero, .L80227C94
.L80227C94:
/* 6DBD04 80227C94 8358815B */   lb       $t8, -0x7ea5($k0)
/* 6DBD08 80227C98 8370815B */  lb        $s0, -0x7ea5($k1)
/* 6DBD0C 80227C9C 834C8389 */  lb        $t4, -0x7c77($k0)
/* 6DBD10 80227CA0 815B7882 */  lb        $k1, 0x7882($t2)
/* 6DBD14 80227CA4 52000000 */  beql      $s0, $zero, .L80227CA8
.L80227CA8:
/* 6DBD18 80227CA8 8358815B */   lb       $t8, -0x7ea5($k0)
/* 6DBD1C 80227CAC 8370815B */  lb        $s0, -0x7ea5($k1)
/* 6DBD20 80227CB0 834C8389 */  lb        $t4, -0x7c77($k0)
/* 6DBD24 80227CB4 815B7882 */  lb        $k1, 0x7882($t2)
/* 6DBD28 80227CB8 51000000 */  beql      $t0, $zero, .L80227CBC
.L80227CBC:
/* 6DBD2C 80227CBC 6B70615F */   ldl      $s0, 0x615f($k1)
/* 6DBD30 80227CC0 31340000 */  andi      $s4, $t1, 0
/* 6DBD34 80227CC4 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBD38 80227CC8 31330000 */  andi      $s3, $t1, 0
/* 6DBD3C 80227CCC 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBD40 80227CD0 31310000 */  andi      $s1, $t1, 0
/* 6DBD44 80227CD4 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBD48 80227CD8 30390000 */  andi      $t9, $at, 0
/* 6DBD4C 80227CDC 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBD50 80227CE0 30380000 */  andi      $t8, $at, 0
/* 6DBD54 80227CE4 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBD58 80227CE8 30370000 */  andi      $s7, $at, 0
/* 6DBD5C 80227CEC 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBD60 80227CF0 30350000 */  andi      $s5, $at, 0
/* 6DBD64 80227CF4 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBD68 80227CF8 30346300 */  andi      $s4, $at, 0x6300
/* 6DBD6C 80227CFC 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBD70 80227D00 30346200 */  andi      $s4, $at, 0x6200
/* 6DBD74 80227D04 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBD78 80227D08 30340000 */  andi      $s4, $at, 0
/* 6DBD7C 80227D0C 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBD80 80227D10 30330000 */  andi      $s3, $at, 0
/* 6DBD84 80227D14 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBD88 80227D18 30320000 */  andi      $s2, $at, 0
/* 6DBD8C 80227D1C 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBD90 80227D20 30316200 */  andi      $s1, $at, 0x6200
/* 6DBD94 80227D24 6B70615F */  ldl       $s0, 0x615f($k1)
/* 6DBD98 80227D28 30310000 */  andi      $s1, $at, 0
/* 6DBD9C 80227D2C 00000000 */  nop       
