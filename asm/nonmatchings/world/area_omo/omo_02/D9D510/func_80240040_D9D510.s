.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_D9D510
/* D9D510 80240040 27BDFF30 */  addiu     $sp, $sp, -0xd0
/* D9D514 80240044 AFB600B0 */  sw        $s6, 0xb0($sp)
/* D9D518 80240048 AFBF00B4 */  sw        $ra, 0xb4($sp)
/* D9D51C 8024004C AFB500AC */  sw        $s5, 0xac($sp)
/* D9D520 80240050 AFB400A8 */  sw        $s4, 0xa8($sp)
/* D9D524 80240054 AFB300A4 */  sw        $s3, 0xa4($sp)
/* D9D528 80240058 AFB200A0 */  sw        $s2, 0xa0($sp)
/* D9D52C 8024005C AFB1009C */  sw        $s1, 0x9c($sp)
/* D9D530 80240060 AFB00098 */  sw        $s0, 0x98($sp)
/* D9D534 80240064 F7B800C8 */  sdc1      $f24, 0xc8($sp)
/* D9D538 80240068 F7B600C0 */  sdc1      $f22, 0xc0($sp)
/* D9D53C 8024006C F7B400B8 */  sdc1      $f20, 0xb8($sp)
/* D9D540 80240070 10A0001E */  beqz      $a1, .L802400EC
/* D9D544 80240074 0080B02D */   daddu    $s6, $a0, $zero
/* D9D548 80240078 0C00AB39 */  jal       heap_malloc
/* D9D54C 8024007C 24040030 */   addiu    $a0, $zero, 0x30
/* D9D550 80240080 0040982D */  daddu     $s3, $v0, $zero
/* D9D554 80240084 0000A02D */  daddu     $s4, $zero, $zero
/* D9D558 80240088 26700008 */  addiu     $s0, $s3, 8
/* D9D55C 8024008C 3C014060 */  lui       $at, 0x4060
/* D9D560 80240090 4481A000 */  mtc1      $at, $f20
/* D9D564 80240094 3C128024 */  lui       $s2, 0x8024
/* D9D568 80240098 265234F8 */  addiu     $s2, $s2, 0x34f8
/* D9D56C 8024009C AED30070 */  sw        $s3, 0x70($s6)
.L802400A0:
/* D9D570 802400A0 8E440000 */  lw        $a0, ($s2)
/* D9D574 802400A4 26520004 */  addiu     $s2, $s2, 4
/* D9D578 802400A8 0C046C04 */  jal       get_model_list_index_from_tree_index
/* D9D57C 802400AC AE04000C */   sw       $a0, 0xc($s0)
/* D9D580 802400B0 0C046B4C */  jal       get_model_from_list_index
/* D9D584 802400B4 0040202D */   daddu    $a0, $v0, $zero
/* D9D588 802400B8 0040882D */  daddu     $s1, $v0, $zero
/* D9D58C 802400BC 26940001 */  addiu     $s4, $s4, 1
/* D9D590 802400C0 C6200098 */  lwc1      $f0, 0x98($s1)
/* D9D594 802400C4 2E820002 */  sltiu     $v0, $s4, 2
/* D9D598 802400C8 E6600000 */  swc1      $f0, ($s3)
/* D9D59C 802400CC C62000A0 */  lwc1      $f0, 0xa0($s1)
/* D9D5A0 802400D0 26730018 */  addiu     $s3, $s3, 0x18
/* D9D5A4 802400D4 E6140004 */  swc1      $f20, 4($s0)
/* D9D5A8 802400D8 AE000008 */  sw        $zero, 8($s0)
/* D9D5AC 802400DC AE000000 */  sw        $zero, ($s0)
/* D9D5B0 802400E0 E600FFFC */  swc1      $f0, -4($s0)
/* D9D5B4 802400E4 1440FFEE */  bnez      $v0, .L802400A0
/* D9D5B8 802400E8 26100018 */   addiu    $s0, $s0, 0x18
.L802400EC:
/* D9D5BC 802400EC 0000A02D */  daddu     $s4, $zero, $zero
/* D9D5C0 802400F0 27B50058 */  addiu     $s5, $sp, 0x58
/* D9D5C4 802400F4 8ED30070 */  lw        $s3, 0x70($s6)
/* D9D5C8 802400F8 4480B000 */  mtc1      $zero, $f22
/* D9D5CC 802400FC 26720004 */  addiu     $s2, $s3, 4
.L80240100:
/* D9D5D0 80240100 C64C000C */  lwc1      $f12, 0xc($s2)
/* D9D5D4 80240104 C6400008 */  lwc1      $f0, 8($s2)
/* D9D5D8 80240108 46006300 */  add.s     $f12, $f12, $f0
/* D9D5DC 8024010C 0C00A6C9 */  jal       clamp_angle
/* D9D5E0 80240110 E64C000C */   swc1     $f12, 0xc($s2)
/* D9D5E4 80240114 3C014048 */  lui       $at, 0x4048
/* D9D5E8 80240118 3421F5C3 */  ori       $at, $at, 0xf5c3
/* D9D5EC 8024011C 44816000 */  mtc1      $at, $f12
/* D9D5F0 80240120 00000000 */  nop       
/* D9D5F4 80240124 460C0302 */  mul.s     $f12, $f0, $f12
/* D9D5F8 80240128 00000000 */  nop       
/* D9D5FC 8024012C 3C014334 */  lui       $at, 0x4334
/* D9D600 80240130 44811000 */  mtc1      $at, $f2
/* D9D604 80240134 E640000C */  swc1      $f0, 0xc($s2)
/* D9D608 80240138 0C00A85B */  jal       sin_rad
/* D9D60C 8024013C 46026303 */   div.s    $f12, $f12, $f2
/* D9D610 80240140 3C0141A0 */  lui       $at, 0x41a0
/* D9D614 80240144 44811000 */  mtc1      $at, $f2
/* D9D618 80240148 00000000 */  nop       
/* D9D61C 8024014C 46020502 */  mul.s     $f20, $f0, $f2
/* D9D620 80240150 00000000 */  nop       
/* D9D624 80240154 4614A082 */  mul.s     $f2, $f20, $f20
/* D9D628 80240158 00000000 */  nop       
/* D9D62C 8024015C 3C0142B4 */  lui       $at, 0x42b4
/* D9D630 80240160 44810000 */  mtc1      $at, $f0
/* D9D634 80240164 1680001C */  bnez      $s4, .L802401D8
/* D9D638 80240168 46001603 */   div.s    $f24, $f2, $f0
/* D9D63C 8024016C C6400004 */  lwc1      $f0, 4($s2)
/* D9D640 80240170 4600B03E */  c.le.s    $f22, $f0
/* D9D644 80240174 00000000 */  nop       
/* D9D648 80240178 45000005 */  bc1f      .L80240190
/* D9D64C 8024017C 00000000 */   nop      
/* D9D650 80240180 4616A03C */  c.lt.s    $f20, $f22
/* D9D654 80240184 00000000 */  nop       
/* D9D658 80240188 4501000A */  bc1t      .L802401B4
/* D9D65C 8024018C 240401D6 */   addiu    $a0, $zero, 0x1d6
.L80240190:
/* D9D660 80240190 4616003C */  c.lt.s    $f0, $f22
/* D9D664 80240194 00000000 */  nop       
/* D9D668 80240198 4502000F */  bc1fl     .L802401D8
/* D9D66C 8024019C E6540004 */   swc1     $f20, 4($s2)
/* D9D670 802401A0 4614B03E */  c.le.s    $f22, $f20
/* D9D674 802401A4 00000000 */  nop       
/* D9D678 802401A8 4502000B */  bc1fl     .L802401D8
/* D9D67C 802401AC E6540004 */   swc1     $f20, 4($s2)
/* D9D680 802401B0 240401D6 */  addiu     $a0, $zero, 0x1d6
.L802401B4:
/* D9D684 802401B4 0000282D */  daddu     $a1, $zero, $zero
/* D9D688 802401B8 3C06C430 */  lui       $a2, 0xc430
/* D9D68C 802401BC 34C68000 */  ori       $a2, $a2, 0x8000
/* D9D690 802401C0 3C0142CC */  lui       $at, 0x42cc
/* D9D694 802401C4 44810000 */  mtc1      $at, $f0
/* D9D698 802401C8 0000382D */  daddu     $a3, $zero, $zero
/* D9D69C 802401CC 0C052757 */  jal       play_sound_at_position
/* D9D6A0 802401D0 E7A00010 */   swc1     $f0, 0x10($sp)
/* D9D6A4 802401D4 E6540004 */  swc1      $f20, 4($s2)
.L802401D8:
/* D9D6A8 802401D8 8E440010 */  lw        $a0, 0x10($s2)
/* D9D6AC 802401DC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* D9D6B0 802401E0 26940001 */   addiu    $s4, $s4, 1
/* D9D6B4 802401E4 0C046B4C */  jal       get_model_from_list_index
/* D9D6B8 802401E8 0040202D */   daddu    $a0, $v0, $zero
/* D9D6BC 802401EC 0040882D */  daddu     $s1, $v0, $zero
/* D9D6C0 802401F0 96220000 */  lhu       $v0, ($s1)
/* D9D6C4 802401F4 4406B000 */  mfc1      $a2, $f22
/* D9D6C8 802401F8 34421400 */  ori       $v0, $v0, 0x1400
/* D9D6CC 802401FC A6220000 */  sh        $v0, ($s1)
/* D9D6D0 80240200 C6600000 */  lwc1      $f0, ($s3)
/* D9D6D4 80240204 C6420000 */  lwc1      $f2, ($s2)
/* D9D6D8 80240208 46000007 */  neg.s     $f0, $f0
/* D9D6DC 8024020C 46001087 */  neg.s     $f2, $f2
/* D9D6E0 80240210 44050000 */  mfc1      $a1, $f0
/* D9D6E4 80240214 44071000 */  mfc1      $a3, $f2
/* D9D6E8 80240218 0C019E40 */  jal       guTranslateF
/* D9D6EC 8024021C 27A40018 */   addiu    $a0, $sp, 0x18
/* D9D6F0 80240220 4405A000 */  mfc1      $a1, $f20
/* D9D6F4 80240224 4406B000 */  mfc1      $a2, $f22
/* D9D6F8 80240228 4407B000 */  mfc1      $a3, $f22
/* D9D6FC 8024022C 3C013F80 */  lui       $at, 0x3f80
/* D9D700 80240230 44810000 */  mtc1      $at, $f0
/* D9D704 80240234 02A0202D */  daddu     $a0, $s5, $zero
/* D9D708 80240238 0C019EC8 */  jal       guRotateF
/* D9D70C 8024023C E7A00010 */   swc1     $f0, 0x10($sp)
/* D9D710 80240240 27A40018 */  addiu     $a0, $sp, 0x18
/* D9D714 80240244 02A0282D */  daddu     $a1, $s5, $zero
/* D9D718 80240248 26300058 */  addiu     $s0, $s1, 0x58
/* D9D71C 8024024C 0C019D80 */  jal       guMtxCatF
/* D9D720 80240250 0200302D */   daddu    $a2, $s0, $zero
/* D9D724 80240254 27A40018 */  addiu     $a0, $sp, 0x18
/* D9D728 80240258 8E470000 */  lw        $a3, ($s2)
/* D9D72C 8024025C 26520018 */  addiu     $s2, $s2, 0x18
/* D9D730 80240260 8E650000 */  lw        $a1, ($s3)
/* D9D734 80240264 4406C000 */  mfc1      $a2, $f24
/* D9D738 80240268 0C019E40 */  jal       guTranslateF
/* D9D73C 8024026C 26730018 */   addiu    $s3, $s3, 0x18
/* D9D740 80240270 0200202D */  daddu     $a0, $s0, $zero
/* D9D744 80240274 27A50018 */  addiu     $a1, $sp, 0x18
/* D9D748 80240278 0C019D80 */  jal       guMtxCatF
/* D9D74C 8024027C 0080302D */   daddu    $a2, $a0, $zero
/* D9D750 80240280 2E820002 */  sltiu     $v0, $s4, 2
/* D9D754 80240284 1440FF9E */  bnez      $v0, .L80240100
/* D9D758 80240288 0000102D */   daddu    $v0, $zero, $zero
/* D9D75C 8024028C 8FBF00B4 */  lw        $ra, 0xb4($sp)
/* D9D760 80240290 8FB600B0 */  lw        $s6, 0xb0($sp)
/* D9D764 80240294 8FB500AC */  lw        $s5, 0xac($sp)
/* D9D768 80240298 8FB400A8 */  lw        $s4, 0xa8($sp)
/* D9D76C 8024029C 8FB300A4 */  lw        $s3, 0xa4($sp)
/* D9D770 802402A0 8FB200A0 */  lw        $s2, 0xa0($sp)
/* D9D774 802402A4 8FB1009C */  lw        $s1, 0x9c($sp)
/* D9D778 802402A8 8FB00098 */  lw        $s0, 0x98($sp)
/* D9D77C 802402AC D7B800C8 */  ldc1      $f24, 0xc8($sp)
/* D9D780 802402B0 D7B600C0 */  ldc1      $f22, 0xc0($sp)
/* D9D784 802402B4 D7B400B8 */  ldc1      $f20, 0xb8($sp)
/* D9D788 802402B8 03E00008 */  jr        $ra
/* D9D78C 802402BC 27BD00D0 */   addiu    $sp, $sp, 0xd0
