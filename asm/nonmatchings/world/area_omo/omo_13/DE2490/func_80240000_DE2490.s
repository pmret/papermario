.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_DE2490
/* DE2490 80240000 27BDFF30 */  addiu     $sp, $sp, -0xd0
/* DE2494 80240004 AFB600B0 */  sw        $s6, 0xb0($sp)
/* DE2498 80240008 AFBF00B4 */  sw        $ra, 0xb4($sp)
/* DE249C 8024000C AFB500AC */  sw        $s5, 0xac($sp)
/* DE24A0 80240010 AFB400A8 */  sw        $s4, 0xa8($sp)
/* DE24A4 80240014 AFB300A4 */  sw        $s3, 0xa4($sp)
/* DE24A8 80240018 AFB200A0 */  sw        $s2, 0xa0($sp)
/* DE24AC 8024001C AFB1009C */  sw        $s1, 0x9c($sp)
/* DE24B0 80240020 AFB00098 */  sw        $s0, 0x98($sp)
/* DE24B4 80240024 F7B800C8 */  sdc1      $f24, 0xc8($sp)
/* DE24B8 80240028 F7B600C0 */  sdc1      $f22, 0xc0($sp)
/* DE24BC 8024002C F7B400B8 */  sdc1      $f20, 0xb8($sp)
/* DE24C0 80240030 10A0001D */  beqz      $a1, .L802400A8
/* DE24C4 80240034 0080B02D */   daddu    $s6, $a0, $zero
/* DE24C8 80240038 0C00AB39 */  jal       heap_malloc
/* DE24CC 8024003C 24040018 */   addiu    $a0, $zero, 0x18
/* DE24D0 80240040 0040982D */  daddu     $s3, $v0, $zero
/* DE24D4 80240044 0000A02D */  daddu     $s4, $zero, $zero
/* DE24D8 80240048 26700008 */  addiu     $s0, $s3, 8
/* DE24DC 8024004C 3C014060 */  lui       $at, 0x4060
/* DE24E0 80240050 4481A000 */  mtc1      $at, $f20
/* DE24E4 80240054 3C128024 */  lui       $s2, %hi(func_80241A78_BA61F8)
/* DE24E8 80240058 26521A78 */  addiu     $s2, $s2, %lo(func_80241A78_BA61F8)
/* DE24EC 8024005C AED30070 */  sw        $s3, 0x70($s6)
.L80240060:
/* DE24F0 80240060 8E440000 */  lw        $a0, ($s2)
/* DE24F4 80240064 26520004 */  addiu     $s2, $s2, 4
/* DE24F8 80240068 0C046C04 */  jal       get_model_list_index_from_tree_index
/* DE24FC 8024006C AE04000C */   sw       $a0, 0xc($s0)
/* DE2500 80240070 0C046B4C */  jal       get_model_from_list_index
/* DE2504 80240074 0040202D */   daddu    $a0, $v0, $zero
/* DE2508 80240078 0040882D */  daddu     $s1, $v0, $zero
/* DE250C 8024007C C6200098 */  lwc1      $f0, 0x98($s1)
/* DE2510 80240080 26940001 */  addiu     $s4, $s4, 1
/* DE2514 80240084 E6600000 */  swc1      $f0, ($s3)
/* DE2518 80240088 C62000A0 */  lwc1      $f0, 0xa0($s1)
/* DE251C 8024008C 26730018 */  addiu     $s3, $s3, 0x18
/* DE2520 80240090 E6140004 */  swc1      $f20, 4($s0)
/* DE2524 80240094 AE000008 */  sw        $zero, 8($s0)
/* DE2528 80240098 AE000000 */  sw        $zero, ($s0)
/* DE252C 8024009C E600FFFC */  swc1      $f0, -4($s0)
/* DE2530 802400A0 1280FFEF */  beqz      $s4, .L80240060
/* DE2534 802400A4 26100018 */   addiu    $s0, $s0, 0x18
.L802400A8:
/* DE2538 802400A8 0000A02D */  daddu     $s4, $zero, $zero
/* DE253C 802400AC 27B50058 */  addiu     $s5, $sp, 0x58
/* DE2540 802400B0 8ED30070 */  lw        $s3, 0x70($s6)
/* DE2544 802400B4 4480B000 */  mtc1      $zero, $f22
/* DE2548 802400B8 26720004 */  addiu     $s2, $s3, 4
.L802400BC:
/* DE254C 802400BC C64C000C */  lwc1      $f12, 0xc($s2)
/* DE2550 802400C0 C6400008 */  lwc1      $f0, 8($s2)
/* DE2554 802400C4 46006300 */  add.s     $f12, $f12, $f0
/* DE2558 802400C8 0C00A6C9 */  jal       clamp_angle
/* DE255C 802400CC E64C000C */   swc1     $f12, 0xc($s2)
/* DE2560 802400D0 3C014048 */  lui       $at, 0x4048
/* DE2564 802400D4 3421F5C3 */  ori       $at, $at, 0xf5c3
/* DE2568 802400D8 44816000 */  mtc1      $at, $f12
/* DE256C 802400DC 00000000 */  nop
/* DE2570 802400E0 460C0302 */  mul.s     $f12, $f0, $f12
/* DE2574 802400E4 00000000 */  nop
/* DE2578 802400E8 3C014334 */  lui       $at, 0x4334
/* DE257C 802400EC 44811000 */  mtc1      $at, $f2
/* DE2580 802400F0 E640000C */  swc1      $f0, 0xc($s2)
/* DE2584 802400F4 0C00A85B */  jal       sin_rad
/* DE2588 802400F8 46026303 */   div.s    $f12, $f12, $f2
/* DE258C 802400FC 3C0141A0 */  lui       $at, 0x41a0
/* DE2590 80240100 44811000 */  mtc1      $at, $f2
/* DE2594 80240104 00000000 */  nop
/* DE2598 80240108 46020502 */  mul.s     $f20, $f0, $f2
/* DE259C 8024010C 00000000 */  nop
/* DE25A0 80240110 4614A082 */  mul.s     $f2, $f20, $f20
/* DE25A4 80240114 00000000 */  nop
/* DE25A8 80240118 3C0142B4 */  lui       $at, 0x42b4
/* DE25AC 8024011C 44810000 */  mtc1      $at, $f0
/* DE25B0 80240120 1680001B */  bnez      $s4, .L80240190
/* DE25B4 80240124 46001603 */   div.s    $f24, $f2, $f0
/* DE25B8 80240128 C6400004 */  lwc1      $f0, 4($s2)
/* DE25BC 8024012C 4600B03E */  c.le.s    $f22, $f0
/* DE25C0 80240130 00000000 */  nop
/* DE25C4 80240134 45000005 */  bc1f      .L8024014C
/* DE25C8 80240138 00000000 */   nop
/* DE25CC 8024013C 4616A03C */  c.lt.s    $f20, $f22
/* DE25D0 80240140 00000000 */  nop
/* DE25D4 80240144 4501000A */  bc1t      .L80240170
/* DE25D8 80240148 240401D6 */   addiu    $a0, $zero, 0x1d6
.L8024014C:
/* DE25DC 8024014C 4616003C */  c.lt.s    $f0, $f22
/* DE25E0 80240150 00000000 */  nop
/* DE25E4 80240154 4502000E */  bc1fl     .L80240190
/* DE25E8 80240158 E6540004 */   swc1     $f20, 4($s2)
/* DE25EC 8024015C 4614B03E */  c.le.s    $f22, $f20
/* DE25F0 80240160 00000000 */  nop
/* DE25F4 80240164 4502000A */  bc1fl     .L80240190
/* DE25F8 80240168 E6540004 */   swc1     $f20, 4($s2)
/* DE25FC 8024016C 240401D6 */  addiu     $a0, $zero, 0x1d6
.L80240170:
/* DE2600 80240170 0000282D */  daddu     $a1, $zero, $zero
/* DE2604 80240174 3C06C3A0 */  lui       $a2, 0xc3a0
/* DE2608 80240178 3C0142BE */  lui       $at, 0x42be
/* DE260C 8024017C 44810000 */  mtc1      $at, $f0
/* DE2610 80240180 0000382D */  daddu     $a3, $zero, $zero
/* DE2614 80240184 0C052757 */  jal       play_sound_at_position
/* DE2618 80240188 E7A00010 */   swc1     $f0, 0x10($sp)
/* DE261C 8024018C E6540004 */  swc1      $f20, 4($s2)
.L80240190:
/* DE2620 80240190 8E440010 */  lw        $a0, 0x10($s2)
/* DE2624 80240194 0C046C04 */  jal       get_model_list_index_from_tree_index
/* DE2628 80240198 26940001 */   addiu    $s4, $s4, 1
/* DE262C 8024019C 0C046B4C */  jal       get_model_from_list_index
/* DE2630 802401A0 0040202D */   daddu    $a0, $v0, $zero
/* DE2634 802401A4 0040882D */  daddu     $s1, $v0, $zero
/* DE2638 802401A8 96220000 */  lhu       $v0, ($s1)
/* DE263C 802401AC 4406B000 */  mfc1      $a2, $f22
/* DE2640 802401B0 34421400 */  ori       $v0, $v0, 0x1400
/* DE2644 802401B4 A6220000 */  sh        $v0, ($s1)
/* DE2648 802401B8 C6600000 */  lwc1      $f0, ($s3)
/* DE264C 802401BC C6420000 */  lwc1      $f2, ($s2)
/* DE2650 802401C0 46000007 */  neg.s     $f0, $f0
/* DE2654 802401C4 46001087 */  neg.s     $f2, $f2
/* DE2658 802401C8 44050000 */  mfc1      $a1, $f0
/* DE265C 802401CC 44071000 */  mfc1      $a3, $f2
/* DE2660 802401D0 0C019E40 */  jal       guTranslateF
/* DE2664 802401D4 27A40018 */   addiu    $a0, $sp, 0x18
/* DE2668 802401D8 4405A000 */  mfc1      $a1, $f20
/* DE266C 802401DC 4406B000 */  mfc1      $a2, $f22
/* DE2670 802401E0 4407B000 */  mfc1      $a3, $f22
/* DE2674 802401E4 3C013F80 */  lui       $at, 0x3f80
/* DE2678 802401E8 44810000 */  mtc1      $at, $f0
/* DE267C 802401EC 02A0202D */  daddu     $a0, $s5, $zero
/* DE2680 802401F0 0C019EC8 */  jal       guRotateF
/* DE2684 802401F4 E7A00010 */   swc1     $f0, 0x10($sp)
/* DE2688 802401F8 27A40018 */  addiu     $a0, $sp, 0x18
/* DE268C 802401FC 02A0282D */  daddu     $a1, $s5, $zero
/* DE2690 80240200 26300058 */  addiu     $s0, $s1, 0x58
/* DE2694 80240204 0C019D80 */  jal       guMtxCatF
/* DE2698 80240208 0200302D */   daddu    $a2, $s0, $zero
/* DE269C 8024020C 27A40018 */  addiu     $a0, $sp, 0x18
/* DE26A0 80240210 8E470000 */  lw        $a3, ($s2)
/* DE26A4 80240214 26520018 */  addiu     $s2, $s2, 0x18
/* DE26A8 80240218 8E650000 */  lw        $a1, ($s3)
/* DE26AC 8024021C 4406C000 */  mfc1      $a2, $f24
/* DE26B0 80240220 0C019E40 */  jal       guTranslateF
/* DE26B4 80240224 26730018 */   addiu    $s3, $s3, 0x18
/* DE26B8 80240228 0200202D */  daddu     $a0, $s0, $zero
/* DE26BC 8024022C 27A50018 */  addiu     $a1, $sp, 0x18
/* DE26C0 80240230 0C019D80 */  jal       guMtxCatF
/* DE26C4 80240234 0080302D */   daddu    $a2, $a0, $zero
/* DE26C8 80240238 1280FFA0 */  beqz      $s4, .L802400BC
/* DE26CC 8024023C 0000102D */   daddu    $v0, $zero, $zero
/* DE26D0 80240240 8FBF00B4 */  lw        $ra, 0xb4($sp)
/* DE26D4 80240244 8FB600B0 */  lw        $s6, 0xb0($sp)
/* DE26D8 80240248 8FB500AC */  lw        $s5, 0xac($sp)
/* DE26DC 8024024C 8FB400A8 */  lw        $s4, 0xa8($sp)
/* DE26E0 80240250 8FB300A4 */  lw        $s3, 0xa4($sp)
/* DE26E4 80240254 8FB200A0 */  lw        $s2, 0xa0($sp)
/* DE26E8 80240258 8FB1009C */  lw        $s1, 0x9c($sp)
/* DE26EC 8024025C 8FB00098 */  lw        $s0, 0x98($sp)
/* DE26F0 80240260 D7B800C8 */  ldc1      $f24, 0xc8($sp)
/* DE26F4 80240264 D7B600C0 */  ldc1      $f22, 0xc0($sp)
/* DE26F8 80240268 D7B400B8 */  ldc1      $f20, 0xb8($sp)
/* DE26FC 8024026C 03E00008 */  jr        $ra
/* DE2700 80240270 27BD00D0 */   addiu    $sp, $sp, 0xd0
/* DE2704 80240274 00000000 */  nop
/* DE2708 80240278 00000000 */  nop
/* DE270C 8024027C 00000000 */  nop
