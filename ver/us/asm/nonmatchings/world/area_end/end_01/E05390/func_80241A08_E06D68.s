.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A08_E06D68
/* E06D68 80241A08 27BDFF90 */  addiu     $sp, $sp, -0x70
/* E06D6C 80241A0C AFB00048 */  sw        $s0, 0x48($sp)
/* E06D70 80241A10 00A0802D */  daddu     $s0, $a1, $zero
/* E06D74 80241A14 AFBF0050 */  sw        $ra, 0x50($sp)
/* E06D78 80241A18 AFB1004C */  sw        $s1, 0x4c($sp)
/* E06D7C 80241A1C F7B80068 */  sdc1      $f24, 0x68($sp)
/* E06D80 80241A20 F7B60060 */  sdc1      $f22, 0x60($sp)
/* E06D84 80241A24 F7B40058 */  sdc1      $f20, 0x58($sp)
/* E06D88 80241A28 8C820050 */  lw        $v0, 0x50($a0)
/* E06D8C 80241A2C 2404000B */  addiu     $a0, $zero, 0xb
/* E06D90 80241A30 0000302D */  daddu     $a2, $zero, $zero
/* E06D94 80241A34 C6140010 */  lwc1      $f20, 0x10($s0)
/* E06D98 80241A38 4680A520 */  cvt.s.w   $f20, $f20
/* E06D9C 80241A3C 3C05437F */  lui       $a1, 0x437f
/* E06DA0 80241A40 C6160014 */  lwc1      $f22, 0x14($s0)
/* E06DA4 80241A44 4680B5A0 */  cvt.s.w   $f22, $f22
/* E06DA8 80241A48 AFA20010 */  sw        $v0, 0x10($sp)
/* E06DAC 80241A4C 8E070018 */  lw        $a3, 0x18($s0)
/* E06DB0 80241A50 0C00A8ED */  jal       update_lerp
/* E06DB4 80241A54 27B10038 */   addiu    $s1, $sp, 0x38
/* E06DB8 80241A58 AFB10010 */  sw        $s1, 0x10($sp)
/* E06DBC 80241A5C 8E040004 */  lw        $a0, 4($s0)
/* E06DC0 80241A60 8E050008 */  lw        $a1, 8($s0)
/* E06DC4 80241A64 8E060000 */  lw        $a2, ($s0)
/* E06DC8 80241A68 8E07000C */  lw        $a3, 0xc($s0)
/* E06DCC 80241A6C 0C04BA38 */  jal       msg_get_glyph
/* E06DD0 80241A70 46000606 */   mov.s    $f24, $f0
/* E06DD4 80241A74 4600A08D */  trunc.w.s $f2, $f20
/* E06DD8 80241A78 44021000 */  mfc1      $v0, $f2
/* E06DDC 80241A7C 93A50040 */  lbu       $a1, 0x40($sp)
/* E06DE0 80241A80 93A60041 */  lbu       $a2, 0x41($sp)
/* E06DE4 80241A84 00021400 */  sll       $v0, $v0, 0x10
/* E06DE8 80241A88 AFA00010 */  sw        $zero, 0x10($sp)
/* E06DEC 80241A8C 8FA3003C */  lw        $v1, 0x3c($sp)
/* E06DF0 80241A90 00021403 */  sra       $v0, $v0, 0x10
/* E06DF4 80241A94 AFA20018 */  sw        $v0, 0x18($sp)
/* E06DF8 80241A98 4600B08D */  trunc.w.s $f2, $f22
/* E06DFC 80241A9C 44021000 */  mfc1      $v0, $f2
/* E06E00 80241AA0 00000000 */  nop
/* E06E04 80241AA4 00021400 */  sll       $v0, $v0, 0x10
/* E06E08 80241AA8 3C014F00 */  lui       $at, 0x4f00
/* E06E0C 80241AAC 44810000 */  mtc1      $at, $f0
/* E06E10 80241AB0 00021403 */  sra       $v0, $v0, 0x10
/* E06E14 80241AB4 AFA2001C */  sw        $v0, 0x1c($sp)
/* E06E18 80241AB8 2402000A */  addiu     $v0, $zero, 0xa
/* E06E1C 80241ABC AFA20020 */  sw        $v0, 0x20($sp)
/* E06E20 80241AC0 24020014 */  addiu     $v0, $zero, 0x14
/* E06E24 80241AC4 AFA20024 */  sw        $v0, 0x24($sp)
/* E06E28 80241AC8 2402012C */  addiu     $v0, $zero, 0x12c
/* E06E2C 80241ACC AFA20028 */  sw        $v0, 0x28($sp)
/* E06E30 80241AD0 240200C8 */  addiu     $v0, $zero, 0xc8
/* E06E34 80241AD4 AFA2002C */  sw        $v0, 0x2c($sp)
/* E06E38 80241AD8 4618003E */  c.le.s    $f0, $f24
/* E06E3C 80241ADC 00000000 */  nop
/* E06E40 80241AE0 45010005 */  bc1t      .L80241AF8
/* E06E44 80241AE4 AFA30014 */   sw       $v1, 0x14($sp)
/* E06E48 80241AE8 4600C08D */  trunc.w.s $f2, $f24
/* E06E4C 80241AEC 44031000 */  mfc1      $v1, $f2
/* E06E50 80241AF0 080906C5 */  j         .L80241B14
/* E06E54 80241AF4 306200FF */   andi     $v0, $v1, 0xff
.L80241AF8:
/* E06E58 80241AF8 4600C001 */  sub.s     $f0, $f24, $f0
/* E06E5C 80241AFC 3C028000 */  lui       $v0, 0x8000
/* E06E60 80241B00 4600008D */  trunc.w.s $f2, $f0
/* E06E64 80241B04 44031000 */  mfc1      $v1, $f2
/* E06E68 80241B08 00000000 */  nop
/* E06E6C 80241B0C 00621825 */  or        $v1, $v1, $v0
/* E06E70 80241B10 306200FF */  andi      $v0, $v1, 0xff
.L80241B14:
/* E06E74 80241B14 AFA20030 */  sw        $v0, 0x30($sp)
/* E06E78 80241B18 8E240000 */  lw        $a0, ($s1)
/* E06E7C 80241B1C 0C04BA68 */  jal       draw_ci_image_with_clipping
/* E06E80 80241B20 24070002 */   addiu    $a3, $zero, 2
/* E06E84 80241B24 8FBF0050 */  lw        $ra, 0x50($sp)
/* E06E88 80241B28 8FB1004C */  lw        $s1, 0x4c($sp)
/* E06E8C 80241B2C 8FB00048 */  lw        $s0, 0x48($sp)
/* E06E90 80241B30 D7B80068 */  ldc1      $f24, 0x68($sp)
/* E06E94 80241B34 D7B60060 */  ldc1      $f22, 0x60($sp)
/* E06E98 80241B38 D7B40058 */  ldc1      $f20, 0x58($sp)
/* E06E9C 80241B3C 03E00008 */  jr        $ra
/* E06EA0 80241B40 27BD0070 */   addiu    $sp, $sp, 0x70
