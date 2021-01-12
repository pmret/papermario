.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BEC_B28C1C
/* B28C1C 80240BEC 27BDFF90 */  addiu     $sp, $sp, -0x70
/* B28C20 80240BF0 AFB40050 */  sw        $s4, 0x50($sp)
/* B28C24 80240BF4 0080A02D */  daddu     $s4, $a0, $zero
/* B28C28 80240BF8 AFBF0060 */  sw        $ra, 0x60($sp)
/* B28C2C 80240BFC AFB7005C */  sw        $s7, 0x5c($sp)
/* B28C30 80240C00 AFB60058 */  sw        $s6, 0x58($sp)
/* B28C34 80240C04 AFB50054 */  sw        $s5, 0x54($sp)
/* B28C38 80240C08 AFB3004C */  sw        $s3, 0x4c($sp)
/* B28C3C 80240C0C AFB20048 */  sw        $s2, 0x48($sp)
/* B28C40 80240C10 AFB10044 */  sw        $s1, 0x44($sp)
/* B28C44 80240C14 AFB00040 */  sw        $s0, 0x40($sp)
/* B28C48 80240C18 F7B40068 */  sdc1      $f20, 0x68($sp)
/* B28C4C 80240C1C 8E950148 */  lw        $s5, 0x148($s4)
/* B28C50 80240C20 00A0B02D */  daddu     $s6, $a1, $zero
/* B28C54 80240C24 86A40008 */  lh        $a0, 8($s5)
/* B28C58 80240C28 0C00EABB */  jal       get_npc_unsafe
/* B28C5C 80240C2C 00C0B82D */   daddu    $s7, $a2, $zero
/* B28C60 80240C30 0040982D */  daddu     $s3, $v0, $zero
/* B28C64 80240C34 C6600018 */  lwc1      $f0, 0x18($s3)
/* B28C68 80240C38 44801000 */  mtc1      $zero, $f2
/* B28C6C 80240C3C 44801800 */  mtc1      $zero, $f3
/* B28C70 80240C40 46000021 */  cvt.d.s   $f0, $f0
/* B28C74 80240C44 4620103C */  c.lt.d    $f2, $f0
/* B28C78 80240C48 00000000 */  nop
/* B28C7C 80240C4C 45000021 */  bc1f      .L80240CD4
/* B28C80 80240C50 27A50028 */   addiu    $a1, $sp, 0x28
/* B28C84 80240C54 C6600038 */  lwc1      $f0, 0x38($s3)
/* B28C88 80240C58 C662003C */  lwc1      $f2, 0x3c($s3)
/* B28C8C 80240C5C C6640040 */  lwc1      $f4, 0x40($s3)
/* B28C90 80240C60 C6660018 */  lwc1      $f6, 0x18($s3)
/* B28C94 80240C64 E7A00028 */  swc1      $f0, 0x28($sp)
/* B28C98 80240C68 E7A2002C */  swc1      $f2, 0x2c($sp)
/* B28C9C 80240C6C E7A40030 */  swc1      $f4, 0x30($sp)
/* B28CA0 80240C70 E7A60010 */  swc1      $f6, 0x10($sp)
/* B28CA4 80240C74 C660000C */  lwc1      $f0, 0xc($s3)
/* B28CA8 80240C78 E7A00014 */  swc1      $f0, 0x14($sp)
/* B28CAC 80240C7C 866200A8 */  lh        $v0, 0xa8($s3)
/* B28CB0 80240C80 44820000 */  mtc1      $v0, $f0
/* B28CB4 80240C84 00000000 */  nop
/* B28CB8 80240C88 46800020 */  cvt.s.w   $f0, $f0
/* B28CBC 80240C8C E7A00018 */  swc1      $f0, 0x18($sp)
/* B28CC0 80240C90 866200A6 */  lh        $v0, 0xa6($s3)
/* B28CC4 80240C94 27A6002C */  addiu     $a2, $sp, 0x2c
/* B28CC8 80240C98 44820000 */  mtc1      $v0, $f0
/* B28CCC 80240C9C 00000000 */  nop
/* B28CD0 80240CA0 46800020 */  cvt.s.w   $f0, $f0
/* B28CD4 80240CA4 E7A0001C */  swc1      $f0, 0x1c($sp)
/* B28CD8 80240CA8 8E640080 */  lw        $a0, 0x80($s3)
/* B28CDC 80240CAC 0C037711 */  jal       func_800DDC44
/* B28CE0 80240CB0 27A70030 */   addiu    $a3, $sp, 0x30
/* B28CE4 80240CB4 10400003 */  beqz      $v0, .L80240CC4
/* B28CE8 80240CB8 00000000 */   nop
/* B28CEC 80240CBC 08090335 */  j         .L80240CD4
/* B28CF0 80240CC0 AE600018 */   sw       $zero, 0x18($s3)
.L80240CC4:
/* B28CF4 80240CC4 8E650018 */  lw        $a1, 0x18($s3)
/* B28CF8 80240CC8 8E66000C */  lw        $a2, 0xc($s3)
/* B28CFC 80240CCC 0C00EA95 */  jal       npc_move_heading
/* B28D00 80240CD0 0260202D */   daddu    $a0, $s3, $zero
.L80240CD4:
/* B28D04 80240CD4 C660001C */  lwc1      $f0, 0x1c($s3)
/* B28D08 80240CD8 44801000 */  mtc1      $zero, $f2
/* B28D0C 80240CDC 44801800 */  mtc1      $zero, $f3
/* B28D10 80240CE0 46000021 */  cvt.d.s   $f0, $f0
/* B28D14 80240CE4 4622003C */  c.lt.d    $f0, $f2
/* B28D18 80240CE8 00000000 */  nop
/* B28D1C 80240CEC 4500006C */  bc1f      .L80240EA0
/* B28D20 80240CF0 27B00028 */   addiu    $s0, $sp, 0x28
/* B28D24 80240CF4 0200282D */  daddu     $a1, $s0, $zero
/* B28D28 80240CF8 27A60034 */  addiu     $a2, $sp, 0x34
/* B28D2C 80240CFC 27B20038 */  addiu     $s2, $sp, 0x38
/* B28D30 80240D00 C6600038 */  lwc1      $f0, 0x38($s3)
/* B28D34 80240D04 3C0142C8 */  lui       $at, 0x42c8
/* B28D38 80240D08 44811000 */  mtc1      $at, $f2
/* B28D3C 80240D0C C6640040 */  lwc1      $f4, 0x40($s3)
/* B28D40 80240D10 3C01447A */  lui       $at, 0x447a
/* B28D44 80240D14 44813000 */  mtc1      $at, $f6
/* B28D48 80240D18 27B10030 */  addiu     $s1, $sp, 0x30
/* B28D4C 80240D1C E7A00028 */  swc1      $f0, 0x28($sp)
/* B28D50 80240D20 E7A20034 */  swc1      $f2, 0x34($sp)
/* B28D54 80240D24 E7A40030 */  swc1      $f4, 0x30($sp)
/* B28D58 80240D28 E7A60038 */  swc1      $f6, 0x38($sp)
/* B28D5C 80240D2C AFB20010 */  sw        $s2, 0x10($sp)
/* B28D60 80240D30 8E640080 */  lw        $a0, 0x80($s3)
/* B28D64 80240D34 0C0372DF */  jal       func_800DCB7C
/* B28D68 80240D38 0220382D */   daddu    $a3, $s1, $zero
/* B28D6C 80240D3C 0200282D */  daddu     $a1, $s0, $zero
/* B28D70 80240D40 27A6002C */  addiu     $a2, $sp, 0x2c
/* B28D74 80240D44 C662003C */  lwc1      $f2, 0x3c($s3)
/* B28D78 80240D48 C6660038 */  lwc1      $f6, 0x38($s3)
/* B28D7C 80240D4C 3C01402A */  lui       $at, 0x402a
/* B28D80 80240D50 4481A800 */  mtc1      $at, $f21
/* B28D84 80240D54 4480A000 */  mtc1      $zero, $f20
/* B28D88 80240D58 460010A1 */  cvt.d.s   $f2, $f2
/* B28D8C 80240D5C 46341080 */  add.d     $f2, $f2, $f20
/* B28D90 80240D60 C660001C */  lwc1      $f0, 0x1c($s3)
/* B28D94 80240D64 C6640040 */  lwc1      $f4, 0x40($s3)
/* B28D98 80240D68 46000005 */  abs.s     $f0, $f0
/* B28D9C 80240D6C E7A40030 */  swc1      $f4, 0x30($sp)
/* B28DA0 80240D70 3C014030 */  lui       $at, 0x4030
/* B28DA4 80240D74 44812800 */  mtc1      $at, $f5
/* B28DA8 80240D78 44802000 */  mtc1      $zero, $f4
/* B28DAC 80240D7C 46000021 */  cvt.d.s   $f0, $f0
/* B28DB0 80240D80 E7A60028 */  swc1      $f6, 0x28($sp)
/* B28DB4 80240D84 46240000 */  add.d     $f0, $f0, $f4
/* B28DB8 80240D88 462010A0 */  cvt.s.d   $f2, $f2
/* B28DBC 80240D8C E7A2002C */  swc1      $f2, 0x2c($sp)
/* B28DC0 80240D90 46200020 */  cvt.s.d   $f0, $f0
/* B28DC4 80240D94 E7A00038 */  swc1      $f0, 0x38($sp)
/* B28DC8 80240D98 AFB20010 */  sw        $s2, 0x10($sp)
/* B28DCC 80240D9C 8E640080 */  lw        $a0, 0x80($s3)
/* B28DD0 80240DA0 0C0372DF */  jal       func_800DCB7C
/* B28DD4 80240DA4 0220382D */   daddu    $a3, $s1, $zero
/* B28DD8 80240DA8 1040003D */  beqz      $v0, .L80240EA0
/* B28DDC 80240DAC 00000000 */   nop
/* B28DE0 80240DB0 C660001C */  lwc1      $f0, 0x1c($s3)
/* B28DE4 80240DB4 C7A20038 */  lwc1      $f2, 0x38($sp)
/* B28DE8 80240DB8 46000005 */  abs.s     $f0, $f0
/* B28DEC 80240DBC 46000021 */  cvt.d.s   $f0, $f0
/* B28DF0 80240DC0 46340000 */  add.d     $f0, $f0, $f20
/* B28DF4 80240DC4 460010A1 */  cvt.d.s   $f2, $f2
/* B28DF8 80240DC8 4620103E */  c.le.d    $f2, $f0
/* B28DFC 80240DCC 00000000 */  nop
/* B28E00 80240DD0 45000033 */  bc1f      .L80240EA0
/* B28E04 80240DD4 2403F7FF */   addiu    $v1, $zero, -0x801
/* B28E08 80240DD8 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* B28E0C 80240DDC 8E620000 */  lw        $v0, ($s3)
/* B28E10 80240DE0 AE60001C */  sw        $zero, 0x1c($s3)
/* B28E14 80240DE4 00431024 */  and       $v0, $v0, $v1
/* B28E18 80240DE8 E660003C */  swc1      $f0, 0x3c($s3)
/* B28E1C 80240DEC AE620000 */  sw        $v0, ($s3)
/* B28E20 80240DF0 AFA00010 */  sw        $zero, 0x10($sp)
/* B28E24 80240DF4 AFA00014 */  sw        $zero, 0x14($sp)
/* B28E28 80240DF8 8E650038 */  lw        $a1, 0x38($s3)
/* B28E2C 80240DFC 8E66003C */  lw        $a2, 0x3c($s3)
/* B28E30 80240E00 8E670040 */  lw        $a3, 0x40($s3)
/* B28E34 80240E04 0C01BECC */  jal       fx_walk_normal
/* B28E38 80240E08 24040002 */   addiu    $a0, $zero, 2
/* B28E3C 80240E0C 02E0202D */  daddu     $a0, $s7, $zero
/* B28E40 80240E10 2402000C */  addiu     $v0, $zero, 0xc
/* B28E44 80240E14 AE820070 */  sw        $v0, 0x70($s4)
/* B28E48 80240E18 24020001 */  addiu     $v0, $zero, 1
/* B28E4C 80240E1C AFA20010 */  sw        $v0, 0x10($sp)
/* B28E50 80240E20 8EC60024 */  lw        $a2, 0x24($s6)
/* B28E54 80240E24 8EC70028 */  lw        $a3, 0x28($s6)
/* B28E58 80240E28 0C01242D */  jal       func_800490B4
/* B28E5C 80240E2C 02A0282D */   daddu    $a1, $s5, $zero
/* B28E60 80240E30 14400022 */  bnez      $v0, .L80240EBC
/* B28E64 80240E34 24040002 */   addiu    $a0, $zero, 2
/* B28E68 80240E38 0260282D */  daddu     $a1, $s3, $zero
/* B28E6C 80240E3C 0000302D */  daddu     $a2, $zero, $zero
/* B28E70 80240E40 866300A8 */  lh        $v1, 0xa8($s3)
/* B28E74 80240E44 3C013F80 */  lui       $at, 0x3f80
/* B28E78 80240E48 44810000 */  mtc1      $at, $f0
/* B28E7C 80240E4C 3C014000 */  lui       $at, 0x4000
/* B28E80 80240E50 44811000 */  mtc1      $at, $f2
/* B28E84 80240E54 3C01C1A0 */  lui       $at, 0xc1a0
/* B28E88 80240E58 44812000 */  mtc1      $at, $f4
/* B28E8C 80240E5C 2402000F */  addiu     $v0, $zero, 0xf
/* B28E90 80240E60 AFA2001C */  sw        $v0, 0x1c($sp)
/* B28E94 80240E64 44834000 */  mtc1      $v1, $f8
/* B28E98 80240E68 00000000 */  nop
/* B28E9C 80240E6C 46804220 */  cvt.s.w   $f8, $f8
/* B28EA0 80240E70 44074000 */  mfc1      $a3, $f8
/* B28EA4 80240E74 27A2003C */  addiu     $v0, $sp, 0x3c
/* B28EA8 80240E78 AFA20020 */  sw        $v0, 0x20($sp)
/* B28EAC 80240E7C E7A00010 */  swc1      $f0, 0x10($sp)
/* B28EB0 80240E80 E7A20014 */  swc1      $f2, 0x14($sp)
/* B28EB4 80240E84 0C01BFA4 */  jal       fx_emote
/* B28EB8 80240E88 E7A40018 */   swc1     $f4, 0x18($sp)
/* B28EBC 80240E8C 24020019 */  addiu     $v0, $zero, 0x19
/* B28EC0 80240E90 A662008E */  sh        $v0, 0x8e($s3)
/* B28EC4 80240E94 2402000E */  addiu     $v0, $zero, 0xe
/* B28EC8 80240E98 080903AF */  j         .L80240EBC
/* B28ECC 80240E9C AE820070 */   sw       $v0, 0x70($s4)
.L80240EA0:
/* B28ED0 80240EA0 C664003C */  lwc1      $f4, 0x3c($s3)
/* B28ED4 80240EA4 C660001C */  lwc1      $f0, 0x1c($s3)
/* B28ED8 80240EA8 46002100 */  add.s     $f4, $f4, $f0
/* B28EDC 80240EAC C6620014 */  lwc1      $f2, 0x14($s3)
/* B28EE0 80240EB0 46020001 */  sub.s     $f0, $f0, $f2
/* B28EE4 80240EB4 E664003C */  swc1      $f4, 0x3c($s3)
/* B28EE8 80240EB8 E660001C */  swc1      $f0, 0x1c($s3)
.L80240EBC:
/* B28EEC 80240EBC 8FBF0060 */  lw        $ra, 0x60($sp)
/* B28EF0 80240EC0 8FB7005C */  lw        $s7, 0x5c($sp)
/* B28EF4 80240EC4 8FB60058 */  lw        $s6, 0x58($sp)
/* B28EF8 80240EC8 8FB50054 */  lw        $s5, 0x54($sp)
/* B28EFC 80240ECC 8FB40050 */  lw        $s4, 0x50($sp)
/* B28F00 80240ED0 8FB3004C */  lw        $s3, 0x4c($sp)
/* B28F04 80240ED4 8FB20048 */  lw        $s2, 0x48($sp)
/* B28F08 80240ED8 8FB10044 */  lw        $s1, 0x44($sp)
/* B28F0C 80240EDC 8FB00040 */  lw        $s0, 0x40($sp)
/* B28F10 80240EE0 D7B40068 */  ldc1      $f20, 0x68($sp)
/* B28F14 80240EE4 03E00008 */  jr        $ra
/* B28F18 80240EE8 27BD0070 */   addiu    $sp, $sp, 0x70
