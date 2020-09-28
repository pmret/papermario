.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_801125E8
/* A8CE8 801125E8 27BDFF70 */  addiu     $sp, $sp, -0x90
/* A8CEC 801125EC AFBE0078 */  sw        $fp, 0x78($sp)
/* A8CF0 801125F0 8FBE00A0 */  lw        $fp, 0xa0($sp)
/* A8CF4 801125F4 AFB60070 */  sw        $s6, 0x70($sp)
/* A8CF8 801125F8 8FB600A4 */  lw        $s6, 0xa4($sp)
/* A8CFC 801125FC 3C0146FF */  lui       $at, 0x46ff
/* A8D00 80112600 3421FE00 */  ori       $at, $at, 0xfe00
/* A8D04 80112604 44810000 */  mtc1      $at, $f0
/* A8D08 80112608 AFB5006C */  sw        $s5, 0x6c($sp)
/* A8D0C 8011260C 0080A82D */  daddu     $s5, $a0, $zero
/* A8D10 80112610 AFB30064 */  sw        $s3, 0x64($sp)
/* A8D14 80112614 00A0982D */  daddu     $s3, $a1, $zero
/* A8D18 80112618 AFB40068 */  sw        $s4, 0x68($sp)
/* A8D1C 8011261C 00C0A02D */  daddu     $s4, $a2, $zero
/* A8D20 80112620 AFB70074 */  sw        $s7, 0x74($sp)
/* A8D24 80112624 00E0B82D */  daddu     $s7, $a3, $zero
/* A8D28 80112628 AFB1005C */  sw        $s1, 0x5c($sp)
/* A8D2C 8011262C 2411FFFF */  addiu     $s1, $zero, -1
/* A8D30 80112630 F7B40080 */  sdc1      $f20, 0x80($sp)
/* A8D34 80112634 4480A000 */  mtc1      $zero, $f20
/* A8D38 80112638 3C01BF80 */  lui       $at, 0xbf80
/* A8D3C 8011263C 44811000 */  mtc1      $at, $f2
/* A8D40 80112640 27A20038 */  addiu     $v0, $sp, 0x38
/* A8D44 80112644 AFBF007C */  sw        $ra, 0x7c($sp)
/* A8D48 80112648 AFB20060 */  sw        $s2, 0x60($sp)
/* A8D4C 8011264C AFB00058 */  sw        $s0, 0x58($sp)
/* A8D50 80112650 F7B60088 */  sdc1      $f22, 0x88($sp)
/* A8D54 80112654 E7A00044 */  swc1      $f0, 0x44($sp)
/* A8D58 80112658 E6C00000 */  swc1      $f0, ($s6)
/* A8D5C 8011265C AFA20018 */  sw        $v0, 0x18($sp)
/* A8D60 80112660 27A2003C */  addiu     $v0, $sp, 0x3c
/* A8D64 80112664 AFA2001C */  sw        $v0, 0x1c($sp)
/* A8D68 80112668 27A20040 */  addiu     $v0, $sp, 0x40
/* A8D6C 8011266C AFA20020 */  sw        $v0, 0x20($sp)
/* A8D70 80112670 27A20044 */  addiu     $v0, $sp, 0x44
/* A8D74 80112674 AFA20024 */  sw        $v0, 0x24($sp)
/* A8D78 80112678 27A20048 */  addiu     $v0, $sp, 0x48
/* A8D7C 8011267C AFA20028 */  sw        $v0, 0x28($sp)
/* A8D80 80112680 27A2004C */  addiu     $v0, $sp, 0x4c
/* A8D84 80112684 AFA2002C */  sw        $v0, 0x2c($sp)
/* A8D88 80112688 27A20050 */  addiu     $v0, $sp, 0x50
/* A8D8C 8011268C E7A20010 */  swc1      $f2, 0x10($sp)
/* A8D90 80112690 E7B40014 */  swc1      $f20, 0x14($sp)
/* A8D94 80112694 AFA20030 */  sw        $v0, 0x30($sp)
/* A8D98 80112698 C6AC0000 */  lwc1      $f12, ($s5)
/* A8D9C 8011269C C66E0000 */  lwc1      $f14, ($s3)
/* A8DA0 801126A0 8E860000 */  lw        $a2, ($s4)
/* A8DA4 801126A4 4407A000 */  mfc1      $a3, $f20
/* A8DA8 801126A8 0C017512 */  jal       test_ray_entities
/* A8DAC 801126AC 0000902D */   daddu    $s2, $zero, $zero
/* A8DB0 801126B0 0040802D */  daddu     $s0, $v0, $zero
/* A8DB4 801126B4 06000019 */  bltz      $s0, .L8011271C
/* A8DB8 801126B8 00000000 */   nop      
/* A8DBC 801126BC 0C0441A9 */  jal       get_entity_type
/* A8DC0 801126C0 0200202D */   daddu    $a0, $s0, $zero
/* A8DC4 801126C4 2403000C */  addiu     $v1, $zero, 0xc
/* A8DC8 801126C8 54430014 */  bnel      $v0, $v1, .L8011271C
/* A8DCC 801126CC 36114000 */   ori      $s1, $s0, 0x4000
/* A8DD0 801126D0 C7A00048 */  lwc1      $f0, 0x48($sp)
/* A8DD4 801126D4 46140032 */  c.eq.s    $f0, $f20
/* A8DD8 801126D8 00000000 */  nop       
/* A8DDC 801126DC 4500000F */  bc1f      .L8011271C
/* A8DE0 801126E0 00000000 */   nop      
/* A8DE4 801126E4 C7A00050 */  lwc1      $f0, 0x50($sp)
/* A8DE8 801126E8 46140032 */  c.eq.s    $f0, $f20
/* A8DEC 801126EC 00000000 */  nop       
/* A8DF0 801126F0 4500000A */  bc1f      .L8011271C
/* A8DF4 801126F4 00000000 */   nop      
/* A8DF8 801126F8 C7A0004C */  lwc1      $f0, 0x4c($sp)
/* A8DFC 801126FC 3C013FF0 */  lui       $at, 0x3ff0
/* A8E00 80112700 44811800 */  mtc1      $at, $f3
/* A8E04 80112704 44801000 */  mtc1      $zero, $f2
/* A8E08 80112708 46000021 */  cvt.d.s   $f0, $f0
/* A8E0C 8011270C 46220032 */  c.eq.d    $f0, $f2
/* A8E10 80112710 00000000 */  nop       
/* A8E14 80112714 45030001 */  bc1tl     .L8011271C
/* A8E18 80112718 36114000 */   ori      $s1, $s0, 0x4000
.L8011271C:
/* A8E1C 8011271C 3C01BF80 */  lui       $at, 0xbf80
/* A8E20 80112720 44810000 */  mtc1      $at, $f0
/* A8E24 80112724 27A20038 */  addiu     $v0, $sp, 0x38
/* A8E28 80112728 AFA2001C */  sw        $v0, 0x1c($sp)
/* A8E2C 8011272C 27A2003C */  addiu     $v0, $sp, 0x3c
/* A8E30 80112730 AFA20020 */  sw        $v0, 0x20($sp)
/* A8E34 80112734 27A20040 */  addiu     $v0, $sp, 0x40
/* A8E38 80112738 AFA20024 */  sw        $v0, 0x24($sp)
/* A8E3C 8011273C 27A20044 */  addiu     $v0, $sp, 0x44
/* A8E40 80112740 AFA20028 */  sw        $v0, 0x28($sp)
/* A8E44 80112744 27A20048 */  addiu     $v0, $sp, 0x48
/* A8E48 80112748 AFA2002C */  sw        $v0, 0x2c($sp)
/* A8E4C 8011274C 27A2004C */  addiu     $v0, $sp, 0x4c
/* A8E50 80112750 AFA20030 */  sw        $v0, 0x30($sp)
/* A8E54 80112754 27A20050 */  addiu     $v0, $sp, 0x50
/* A8E58 80112758 AFA00010 */  sw        $zero, 0x10($sp)
/* A8E5C 8011275C AFA00018 */  sw        $zero, 0x18($sp)
/* A8E60 80112760 AFA20034 */  sw        $v0, 0x34($sp)
/* A8E64 80112764 E7A00014 */  swc1      $f0, 0x14($sp)
/* A8E68 80112768 8E660000 */  lw        $a2, ($s3)
/* A8E6C 8011276C 8E870000 */  lw        $a3, ($s4)
/* A8E70 80112770 8EA50000 */  lw        $a1, ($s5)
/* A8E74 80112774 0C017334 */  jal       test_ray_colliders
/* A8E78 80112778 3C040001 */   lui      $a0, 1
/* A8E7C 8011277C 04430001 */  bgezl     $v0, .L80112784
/* A8E80 80112780 0040882D */   daddu    $s1, $v0, $zero
.L80112784:
/* A8E84 80112784 06220025 */  bltzl     $s1, .L8011281C
/* A8E88 80112788 AEE00000 */   sw       $zero, ($s7)
/* A8E8C 8011278C C7A00044 */  lwc1      $f0, 0x44($sp)
/* A8E90 80112790 3C0142C8 */  lui       $at, 0x42c8
/* A8E94 80112794 4481A000 */  mtc1      $at, $f20
/* A8E98 80112798 E6C00000 */  swc1      $f0, ($s6)
/* A8E9C 8011279C C7A0003C */  lwc1      $f0, 0x3c($sp)
/* A8EA0 801127A0 E6600000 */  swc1      $f0, ($s3)
/* A8EA4 801127A4 C7A00050 */  lwc1      $f0, 0x50($sp)
/* A8EA8 801127A8 46140002 */  mul.s     $f0, $f0, $f20
/* A8EAC 801127AC 00000000 */  nop       
/* A8EB0 801127B0 44060000 */  mfc1      $a2, $f0
/* A8EB4 801127B4 C7A0004C */  lwc1      $f0, 0x4c($sp)
/* A8EB8 801127B8 46140002 */  mul.s     $f0, $f0, $f20
/* A8EBC 801127BC 00000000 */  nop       
/* A8EC0 801127C0 4480B000 */  mtc1      $zero, $f22
/* A8EC4 801127C4 00000000 */  nop       
/* A8EC8 801127C8 4600B306 */  mov.s     $f12, $f22
/* A8ECC 801127CC 44070000 */  mfc1      $a3, $f0
/* A8ED0 801127D0 0C00A720 */  jal       atan2
/* A8ED4 801127D4 4600B386 */   mov.s    $f14, $f22
/* A8ED8 801127D8 46000007 */  neg.s     $f0, $f0
/* A8EDC 801127DC E6E00000 */  swc1      $f0, ($s7)
/* A8EE0 801127E0 C7A00048 */  lwc1      $f0, 0x48($sp)
/* A8EE4 801127E4 46140002 */  mul.s     $f0, $f0, $f20
/* A8EE8 801127E8 00000000 */  nop       
/* A8EEC 801127EC 44060000 */  mfc1      $a2, $f0
/* A8EF0 801127F0 C7A0004C */  lwc1      $f0, 0x4c($sp)
/* A8EF4 801127F4 46140002 */  mul.s     $f0, $f0, $f20
/* A8EF8 801127F8 00000000 */  nop       
/* A8EFC 801127FC 24120001 */  addiu     $s2, $zero, 1
/* A8F00 80112800 4600B306 */  mov.s     $f12, $f22
/* A8F04 80112804 44070000 */  mfc1      $a3, $f0
/* A8F08 80112808 0C00A720 */  jal       atan2
/* A8F0C 8011280C 46006386 */   mov.s    $f14, $f12
/* A8F10 80112810 46000007 */  neg.s     $f0, $f0
/* A8F14 80112814 08044A08 */  j         .L80112820
/* A8F18 80112818 E7C00000 */   swc1     $f0, ($fp)
.L8011281C:
/* A8F1C 8011281C AFC00000 */  sw        $zero, ($fp)
.L80112820:
/* A8F20 80112820 0240102D */  daddu     $v0, $s2, $zero
/* A8F24 80112824 8FBF007C */  lw        $ra, 0x7c($sp)
/* A8F28 80112828 8FBE0078 */  lw        $fp, 0x78($sp)
/* A8F2C 8011282C 8FB70074 */  lw        $s7, 0x74($sp)
/* A8F30 80112830 8FB60070 */  lw        $s6, 0x70($sp)
/* A8F34 80112834 8FB5006C */  lw        $s5, 0x6c($sp)
/* A8F38 80112838 8FB40068 */  lw        $s4, 0x68($sp)
/* A8F3C 8011283C 8FB30064 */  lw        $s3, 0x64($sp)
/* A8F40 80112840 8FB20060 */  lw        $s2, 0x60($sp)
/* A8F44 80112844 8FB1005C */  lw        $s1, 0x5c($sp)
/* A8F48 80112848 8FB00058 */  lw        $s0, 0x58($sp)
/* A8F4C 8011284C D7B60088 */  ldc1      $f22, 0x88($sp)
/* A8F50 80112850 D7B40080 */  ldc1      $f20, 0x80($sp)
/* A8F54 80112854 03E00008 */  jr        $ra
/* A8F58 80112858 27BD0090 */   addiu    $sp, $sp, 0x90
