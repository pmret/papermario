.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B1C_BAAC5C
/* BAAC5C 80240B1C 27BDFF90 */  addiu     $sp, $sp, -0x70
/* BAAC60 80240B20 AFB40050 */  sw        $s4, 0x50($sp)
/* BAAC64 80240B24 0080A02D */  daddu     $s4, $a0, $zero
/* BAAC68 80240B28 AFBF0060 */  sw        $ra, 0x60($sp)
/* BAAC6C 80240B2C AFB7005C */  sw        $s7, 0x5c($sp)
/* BAAC70 80240B30 AFB60058 */  sw        $s6, 0x58($sp)
/* BAAC74 80240B34 AFB50054 */  sw        $s5, 0x54($sp)
/* BAAC78 80240B38 AFB3004C */  sw        $s3, 0x4c($sp)
/* BAAC7C 80240B3C AFB20048 */  sw        $s2, 0x48($sp)
/* BAAC80 80240B40 AFB10044 */  sw        $s1, 0x44($sp)
/* BAAC84 80240B44 AFB00040 */  sw        $s0, 0x40($sp)
/* BAAC88 80240B48 F7B40068 */  sdc1      $f20, 0x68($sp)
/* BAAC8C 80240B4C 8E950148 */  lw        $s5, 0x148($s4)
/* BAAC90 80240B50 00A0B02D */  daddu     $s6, $a1, $zero
/* BAAC94 80240B54 86A40008 */  lh        $a0, 8($s5)
/* BAAC98 80240B58 0C00EABB */  jal       get_npc_unsafe
/* BAAC9C 80240B5C 00C0B82D */   daddu    $s7, $a2, $zero
/* BAACA0 80240B60 0040982D */  daddu     $s3, $v0, $zero
/* BAACA4 80240B64 C6600018 */  lwc1      $f0, 0x18($s3)
/* BAACA8 80240B68 44801000 */  mtc1      $zero, $f2
/* BAACAC 80240B6C 44801800 */  mtc1      $zero, $f3
/* BAACB0 80240B70 46000021 */  cvt.d.s   $f0, $f0
/* BAACB4 80240B74 4620103C */  c.lt.d    $f2, $f0
/* BAACB8 80240B78 00000000 */  nop
/* BAACBC 80240B7C 45000021 */  bc1f      .L80240C04
/* BAACC0 80240B80 27A50028 */   addiu    $a1, $sp, 0x28
/* BAACC4 80240B84 C6600038 */  lwc1      $f0, 0x38($s3)
/* BAACC8 80240B88 C662003C */  lwc1      $f2, 0x3c($s3)
/* BAACCC 80240B8C C6640040 */  lwc1      $f4, 0x40($s3)
/* BAACD0 80240B90 C6660018 */  lwc1      $f6, 0x18($s3)
/* BAACD4 80240B94 E7A00028 */  swc1      $f0, 0x28($sp)
/* BAACD8 80240B98 E7A2002C */  swc1      $f2, 0x2c($sp)
/* BAACDC 80240B9C E7A40030 */  swc1      $f4, 0x30($sp)
/* BAACE0 80240BA0 E7A60010 */  swc1      $f6, 0x10($sp)
/* BAACE4 80240BA4 C660000C */  lwc1      $f0, 0xc($s3)
/* BAACE8 80240BA8 E7A00014 */  swc1      $f0, 0x14($sp)
/* BAACEC 80240BAC 866200A8 */  lh        $v0, 0xa8($s3)
/* BAACF0 80240BB0 44820000 */  mtc1      $v0, $f0
/* BAACF4 80240BB4 00000000 */  nop
/* BAACF8 80240BB8 46800020 */  cvt.s.w   $f0, $f0
/* BAACFC 80240BBC E7A00018 */  swc1      $f0, 0x18($sp)
/* BAAD00 80240BC0 866200A6 */  lh        $v0, 0xa6($s3)
/* BAAD04 80240BC4 27A6002C */  addiu     $a2, $sp, 0x2c
/* BAAD08 80240BC8 44820000 */  mtc1      $v0, $f0
/* BAAD0C 80240BCC 00000000 */  nop
/* BAAD10 80240BD0 46800020 */  cvt.s.w   $f0, $f0
/* BAAD14 80240BD4 E7A0001C */  swc1      $f0, 0x1c($sp)
/* BAAD18 80240BD8 8E640080 */  lw        $a0, 0x80($s3)
/* BAAD1C 80240BDC 0C037711 */  jal       npc_test_move_simple_with_slipping
/* BAAD20 80240BE0 27A70030 */   addiu    $a3, $sp, 0x30
/* BAAD24 80240BE4 10400003 */  beqz      $v0, .L80240BF4
/* BAAD28 80240BE8 00000000 */   nop
/* BAAD2C 80240BEC 08090301 */  j         .L80240C04
/* BAAD30 80240BF0 AE600018 */   sw       $zero, 0x18($s3)
.L80240BF4:
/* BAAD34 80240BF4 8E650018 */  lw        $a1, 0x18($s3)
/* BAAD38 80240BF8 8E66000C */  lw        $a2, 0xc($s3)
/* BAAD3C 80240BFC 0C00EA95 */  jal       npc_move_heading
/* BAAD40 80240C00 0260202D */   daddu    $a0, $s3, $zero
.L80240C04:
/* BAAD44 80240C04 C660001C */  lwc1      $f0, 0x1c($s3)
/* BAAD48 80240C08 44801000 */  mtc1      $zero, $f2
/* BAAD4C 80240C0C 44801800 */  mtc1      $zero, $f3
/* BAAD50 80240C10 46000021 */  cvt.d.s   $f0, $f0
/* BAAD54 80240C14 4622003C */  c.lt.d    $f0, $f2
/* BAAD58 80240C18 00000000 */  nop
/* BAAD5C 80240C1C 4500006C */  bc1f      .L80240DD0
/* BAAD60 80240C20 27B00028 */   addiu    $s0, $sp, 0x28
/* BAAD64 80240C24 0200282D */  daddu     $a1, $s0, $zero
/* BAAD68 80240C28 27A60034 */  addiu     $a2, $sp, 0x34
/* BAAD6C 80240C2C 27B20038 */  addiu     $s2, $sp, 0x38
/* BAAD70 80240C30 C6600038 */  lwc1      $f0, 0x38($s3)
/* BAAD74 80240C34 3C0142C8 */  lui       $at, 0x42c8
/* BAAD78 80240C38 44811000 */  mtc1      $at, $f2
/* BAAD7C 80240C3C C6640040 */  lwc1      $f4, 0x40($s3)
/* BAAD80 80240C40 3C01447A */  lui       $at, 0x447a
/* BAAD84 80240C44 44813000 */  mtc1      $at, $f6
/* BAAD88 80240C48 27B10030 */  addiu     $s1, $sp, 0x30
/* BAAD8C 80240C4C E7A00028 */  swc1      $f0, 0x28($sp)
/* BAAD90 80240C50 E7A20034 */  swc1      $f2, 0x34($sp)
/* BAAD94 80240C54 E7A40030 */  swc1      $f4, 0x30($sp)
/* BAAD98 80240C58 E7A60038 */  swc1      $f6, 0x38($sp)
/* BAAD9C 80240C5C AFB20010 */  sw        $s2, 0x10($sp)
/* BAADA0 80240C60 8E640080 */  lw        $a0, 0x80($s3)
/* BAADA4 80240C64 0C0372DF */  jal       npc_raycast_down_sides
/* BAADA8 80240C68 0220382D */   daddu    $a3, $s1, $zero
/* BAADAC 80240C6C 0200282D */  daddu     $a1, $s0, $zero
/* BAADB0 80240C70 27A6002C */  addiu     $a2, $sp, 0x2c
/* BAADB4 80240C74 C662003C */  lwc1      $f2, 0x3c($s3)
/* BAADB8 80240C78 C6660038 */  lwc1      $f6, 0x38($s3)
/* BAADBC 80240C7C 3C01402A */  lui       $at, 0x402a
/* BAADC0 80240C80 4481A800 */  mtc1      $at, $f21
/* BAADC4 80240C84 4480A000 */  mtc1      $zero, $f20
/* BAADC8 80240C88 460010A1 */  cvt.d.s   $f2, $f2
/* BAADCC 80240C8C 46341080 */  add.d     $f2, $f2, $f20
/* BAADD0 80240C90 C660001C */  lwc1      $f0, 0x1c($s3)
/* BAADD4 80240C94 C6640040 */  lwc1      $f4, 0x40($s3)
/* BAADD8 80240C98 46000005 */  abs.s     $f0, $f0
/* BAADDC 80240C9C E7A40030 */  swc1      $f4, 0x30($sp)
/* BAADE0 80240CA0 3C014030 */  lui       $at, 0x4030
/* BAADE4 80240CA4 44812800 */  mtc1      $at, $f5
/* BAADE8 80240CA8 44802000 */  mtc1      $zero, $f4
/* BAADEC 80240CAC 46000021 */  cvt.d.s   $f0, $f0
/* BAADF0 80240CB0 E7A60028 */  swc1      $f6, 0x28($sp)
/* BAADF4 80240CB4 46240000 */  add.d     $f0, $f0, $f4
/* BAADF8 80240CB8 462010A0 */  cvt.s.d   $f2, $f2
/* BAADFC 80240CBC E7A2002C */  swc1      $f2, 0x2c($sp)
/* BAAE00 80240CC0 46200020 */  cvt.s.d   $f0, $f0
/* BAAE04 80240CC4 E7A00038 */  swc1      $f0, 0x38($sp)
/* BAAE08 80240CC8 AFB20010 */  sw        $s2, 0x10($sp)
/* BAAE0C 80240CCC 8E640080 */  lw        $a0, 0x80($s3)
/* BAAE10 80240CD0 0C0372DF */  jal       npc_raycast_down_sides
/* BAAE14 80240CD4 0220382D */   daddu    $a3, $s1, $zero
/* BAAE18 80240CD8 1040003D */  beqz      $v0, .L80240DD0
/* BAAE1C 80240CDC 00000000 */   nop
/* BAAE20 80240CE0 C660001C */  lwc1      $f0, 0x1c($s3)
/* BAAE24 80240CE4 C7A20038 */  lwc1      $f2, 0x38($sp)
/* BAAE28 80240CE8 46000005 */  abs.s     $f0, $f0
/* BAAE2C 80240CEC 46000021 */  cvt.d.s   $f0, $f0
/* BAAE30 80240CF0 46340000 */  add.d     $f0, $f0, $f20
/* BAAE34 80240CF4 460010A1 */  cvt.d.s   $f2, $f2
/* BAAE38 80240CF8 4620103E */  c.le.d    $f2, $f0
/* BAAE3C 80240CFC 00000000 */  nop
/* BAAE40 80240D00 45000033 */  bc1f      .L80240DD0
/* BAAE44 80240D04 2403F7FF */   addiu    $v1, $zero, -0x801
/* BAAE48 80240D08 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* BAAE4C 80240D0C 8E620000 */  lw        $v0, ($s3)
/* BAAE50 80240D10 AE60001C */  sw        $zero, 0x1c($s3)
/* BAAE54 80240D14 00431024 */  and       $v0, $v0, $v1
/* BAAE58 80240D18 E660003C */  swc1      $f0, 0x3c($s3)
/* BAAE5C 80240D1C AE620000 */  sw        $v0, ($s3)
/* BAAE60 80240D20 AFA00010 */  sw        $zero, 0x10($sp)
/* BAAE64 80240D24 AFA00014 */  sw        $zero, 0x14($sp)
/* BAAE68 80240D28 8E650038 */  lw        $a1, 0x38($s3)
/* BAAE6C 80240D2C 8E66003C */  lw        $a2, 0x3c($s3)
/* BAAE70 80240D30 8E670040 */  lw        $a3, 0x40($s3)
/* BAAE74 80240D34 0C01BECC */  jal       fx_walk
/* BAAE78 80240D38 24040002 */   addiu    $a0, $zero, 2
/* BAAE7C 80240D3C 02E0202D */  daddu     $a0, $s7, $zero
/* BAAE80 80240D40 2402000C */  addiu     $v0, $zero, 0xc
/* BAAE84 80240D44 AE820070 */  sw        $v0, 0x70($s4)
/* BAAE88 80240D48 24020001 */  addiu     $v0, $zero, 1
/* BAAE8C 80240D4C AFA20010 */  sw        $v0, 0x10($sp)
/* BAAE90 80240D50 8EC60024 */  lw        $a2, 0x24($s6)
/* BAAE94 80240D54 8EC70028 */  lw        $a3, 0x28($s6)
/* BAAE98 80240D58 0C01242D */  jal       func_800490B4
/* BAAE9C 80240D5C 02A0282D */   daddu    $a1, $s5, $zero
/* BAAEA0 80240D60 14400022 */  bnez      $v0, .L80240DEC
/* BAAEA4 80240D64 24040002 */   addiu    $a0, $zero, 2
/* BAAEA8 80240D68 0260282D */  daddu     $a1, $s3, $zero
/* BAAEAC 80240D6C 0000302D */  daddu     $a2, $zero, $zero
/* BAAEB0 80240D70 866300A8 */  lh        $v1, 0xa8($s3)
/* BAAEB4 80240D74 3C013F80 */  lui       $at, 0x3f80
/* BAAEB8 80240D78 44810000 */  mtc1      $at, $f0
/* BAAEBC 80240D7C 3C014000 */  lui       $at, 0x4000
/* BAAEC0 80240D80 44811000 */  mtc1      $at, $f2
/* BAAEC4 80240D84 3C01C1A0 */  lui       $at, 0xc1a0
/* BAAEC8 80240D88 44812000 */  mtc1      $at, $f4
/* BAAECC 80240D8C 2402000F */  addiu     $v0, $zero, 0xf
/* BAAED0 80240D90 AFA2001C */  sw        $v0, 0x1c($sp)
/* BAAED4 80240D94 44834000 */  mtc1      $v1, $f8
/* BAAED8 80240D98 00000000 */  nop
/* BAAEDC 80240D9C 46804220 */  cvt.s.w   $f8, $f8
/* BAAEE0 80240DA0 44074000 */  mfc1      $a3, $f8
/* BAAEE4 80240DA4 27A2003C */  addiu     $v0, $sp, 0x3c
/* BAAEE8 80240DA8 AFA20020 */  sw        $v0, 0x20($sp)
/* BAAEEC 80240DAC E7A00010 */  swc1      $f0, 0x10($sp)
/* BAAEF0 80240DB0 E7A20014 */  swc1      $f2, 0x14($sp)
/* BAAEF4 80240DB4 0C01BFA4 */  jal       fx_emote
/* BAAEF8 80240DB8 E7A40018 */   swc1     $f4, 0x18($sp)
/* BAAEFC 80240DBC 24020019 */  addiu     $v0, $zero, 0x19
/* BAAF00 80240DC0 A662008E */  sh        $v0, 0x8e($s3)
/* BAAF04 80240DC4 2402000E */  addiu     $v0, $zero, 0xe
/* BAAF08 80240DC8 0809037B */  j         .L80240DEC
/* BAAF0C 80240DCC AE820070 */   sw       $v0, 0x70($s4)
.L80240DD0:
/* BAAF10 80240DD0 C664003C */  lwc1      $f4, 0x3c($s3)
/* BAAF14 80240DD4 C660001C */  lwc1      $f0, 0x1c($s3)
/* BAAF18 80240DD8 46002100 */  add.s     $f4, $f4, $f0
/* BAAF1C 80240DDC C6620014 */  lwc1      $f2, 0x14($s3)
/* BAAF20 80240DE0 46020001 */  sub.s     $f0, $f0, $f2
/* BAAF24 80240DE4 E664003C */  swc1      $f4, 0x3c($s3)
/* BAAF28 80240DE8 E660001C */  swc1      $f0, 0x1c($s3)
.L80240DEC:
/* BAAF2C 80240DEC 8FBF0060 */  lw        $ra, 0x60($sp)
/* BAAF30 80240DF0 8FB7005C */  lw        $s7, 0x5c($sp)
/* BAAF34 80240DF4 8FB60058 */  lw        $s6, 0x58($sp)
/* BAAF38 80240DF8 8FB50054 */  lw        $s5, 0x54($sp)
/* BAAF3C 80240DFC 8FB40050 */  lw        $s4, 0x50($sp)
/* BAAF40 80240E00 8FB3004C */  lw        $s3, 0x4c($sp)
/* BAAF44 80240E04 8FB20048 */  lw        $s2, 0x48($sp)
/* BAAF48 80240E08 8FB10044 */  lw        $s1, 0x44($sp)
/* BAAF4C 80240E0C 8FB00040 */  lw        $s0, 0x40($sp)
/* BAAF50 80240E10 D7B40068 */  ldc1      $f20, 0x68($sp)
/* BAAF54 80240E14 03E00008 */  jr        $ra
/* BAAF58 80240E18 27BD0070 */   addiu    $sp, $sp, 0x70
