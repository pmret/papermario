.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80244840_AF1C50
.double 0.3, 2.8165885703910132e+209

.section .text

glabel func_80240B0C_AEDF1C
/* AEDF1C 80240B0C 27BDFF88 */  addiu     $sp, $sp, -0x78
/* AEDF20 80240B10 AFB7004C */  sw        $s7, 0x4c($sp)
/* AEDF24 80240B14 0080B82D */  daddu     $s7, $a0, $zero
/* AEDF28 80240B18 AFBF0054 */  sw        $ra, 0x54($sp)
/* AEDF2C 80240B1C AFBE0050 */  sw        $fp, 0x50($sp)
/* AEDF30 80240B20 AFB60048 */  sw        $s6, 0x48($sp)
/* AEDF34 80240B24 AFB50044 */  sw        $s5, 0x44($sp)
/* AEDF38 80240B28 AFB40040 */  sw        $s4, 0x40($sp)
/* AEDF3C 80240B2C AFB3003C */  sw        $s3, 0x3c($sp)
/* AEDF40 80240B30 AFB20038 */  sw        $s2, 0x38($sp)
/* AEDF44 80240B34 AFB10034 */  sw        $s1, 0x34($sp)
/* AEDF48 80240B38 AFB00030 */  sw        $s0, 0x30($sp)
/* AEDF4C 80240B3C F7BA0070 */  sdc1      $f26, 0x70($sp)
/* AEDF50 80240B40 F7B80068 */  sdc1      $f24, 0x68($sp)
/* AEDF54 80240B44 F7B60060 */  sdc1      $f22, 0x60($sp)
/* AEDF58 80240B48 F7B40058 */  sdc1      $f20, 0x58($sp)
/* AEDF5C 80240B4C 8EE20148 */  lw        $v0, 0x148($s7)
/* AEDF60 80240B50 0C00EABB */  jal       get_npc_unsafe
/* AEDF64 80240B54 84440008 */   lh       $a0, 8($v0)
/* AEDF68 80240B58 27B50020 */  addiu     $s5, $sp, 0x20
/* AEDF6C 80240B5C 02A0202D */  daddu     $a0, $s5, $zero
/* AEDF70 80240B60 0040882D */  daddu     $s1, $v0, $zero
/* AEDF74 80240B64 27B40024 */  addiu     $s4, $sp, 0x24
/* AEDF78 80240B68 8EE3000C */  lw        $v1, 0xc($s7)
/* AEDF7C 80240B6C 3C0641F0 */  lui       $a2, 0x41f0
/* AEDF80 80240B70 8E27000C */  lw        $a3, 0xc($s1)
/* AEDF84 80240B74 C6200038 */  lwc1      $f0, 0x38($s1)
/* AEDF88 80240B78 C6220040 */  lwc1      $f2, 0x40($s1)
/* AEDF8C 80240B7C 8C7E0000 */  lw        $fp, ($v1)
/* AEDF90 80240B80 24630004 */  addiu     $v1, $v1, 4
/* AEDF94 80240B84 C4740000 */  lwc1      $f20, ($v1)
/* AEDF98 80240B88 4680A520 */  cvt.s.w   $f20, $f20
/* AEDF9C 80240B8C 24630004 */  addiu     $v1, $v1, 4
/* AEDFA0 80240B90 C4760000 */  lwc1      $f22, ($v1)
/* AEDFA4 80240B94 4680B5A0 */  cvt.s.w   $f22, $f22
/* AEDFA8 80240B98 24630004 */  addiu     $v1, $v1, 4
/* AEDFAC 80240B9C C4780000 */  lwc1      $f24, ($v1)
/* AEDFB0 80240BA0 4680C620 */  cvt.s.w   $f24, $f24
/* AEDFB4 80240BA4 24630004 */  addiu     $v1, $v1, 4
/* AEDFB8 80240BA8 C47A0000 */  lwc1      $f26, ($v1)
/* AEDFBC 80240BAC 4680D6A0 */  cvt.s.w   $f26, $f26
/* AEDFC0 80240BB0 24630004 */  addiu     $v1, $v1, 4
/* AEDFC4 80240BB4 8C760000 */  lw        $s6, ($v1)
/* AEDFC8 80240BB8 8C700004 */  lw        $s0, 4($v1)
/* AEDFCC 80240BBC 0280282D */  daddu     $a1, $s4, $zero
/* AEDFD0 80240BC0 E7A00020 */  swc1      $f0, 0x20($sp)
/* AEDFD4 80240BC4 0C00A7E7 */  jal       add_vec2D_polar
/* AEDFD8 80240BC8 E7A20024 */   swc1     $f2, 0x24($sp)
/* AEDFDC 80240BCC 3C038015 */  lui       $v1, %hi(D_80151328)
/* AEDFE0 80240BD0 8C631328 */  lw        $v1, %lo(D_80151328)($v1)
/* AEDFE4 80240BD4 C7A00020 */  lwc1      $f0, 0x20($sp)
/* AEDFE8 80240BD8 3C0141A0 */  lui       $at, 0x41a0
/* AEDFEC 80240BDC 44811000 */  mtc1      $at, $f2
/* AEDFF0 80240BE0 00101040 */  sll       $v0, $s0, 1
/* AEDFF4 80240BE4 00501021 */  addu      $v0, $v0, $s0
/* AEDFF8 80240BE8 000210C0 */  sll       $v0, $v0, 3
/* AEDFFC 80240BEC 24420004 */  addiu     $v0, $v0, 4
/* AEE000 80240BF0 00621821 */  addu      $v1, $v1, $v0
/* AEE004 80240BF4 E4600004 */  swc1      $f0, 4($v1)
/* AEE008 80240BF8 C620003C */  lwc1      $f0, 0x3c($s1)
/* AEE00C 80240BFC 4406A000 */  mfc1      $a2, $f20
/* AEE010 80240C00 46020000 */  add.s     $f0, $f0, $f2
/* AEE014 80240C04 C7A20024 */  lwc1      $f2, 0x24($sp)
/* AEE018 80240C08 02A0202D */  daddu     $a0, $s5, $zero
/* AEE01C 80240C0C E462000C */  swc1      $f2, 0xc($v1)
/* AEE020 80240C10 E4600008 */  swc1      $f0, 8($v1)
/* AEE024 80240C14 8E27000C */  lw        $a3, 0xc($s1)
/* AEE028 80240C18 C6200038 */  lwc1      $f0, 0x38($s1)
/* AEE02C 80240C1C C6220040 */  lwc1      $f2, 0x40($s1)
/* AEE030 80240C20 0280282D */  daddu     $a1, $s4, $zero
/* AEE034 80240C24 E7A00020 */  swc1      $f0, 0x20($sp)
/* AEE038 80240C28 0C00A7E7 */  jal       add_vec2D_polar
/* AEE03C 80240C2C E7A20024 */   swc1     $f2, 0x24($sp)
/* AEE040 80240C30 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* AEE044 80240C34 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* AEE048 80240C38 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* AEE04C 80240C3C C7AE0024 */  lwc1      $f14, 0x24($sp)
/* AEE050 80240C40 8E460028 */  lw        $a2, 0x28($s2)
/* AEE054 80240C44 8E470030 */  lw        $a3, 0x30($s2)
/* AEE058 80240C48 0C00A7B5 */  jal       dist2D
/* AEE05C 80240C4C 0000802D */   daddu    $s0, $zero, $zero
/* AEE060 80240C50 4616003E */  c.le.s    $f0, $f22
/* AEE064 80240C54 00000000 */  nop
/* AEE068 80240C58 45000002 */  bc1f      .L80240C64
/* AEE06C 80240C5C 0240982D */   daddu    $s3, $s2, $zero
/* AEE070 80240C60 24100001 */  addiu     $s0, $zero, 1
.L80240C64:
/* AEE074 80240C64 4600B021 */  cvt.d.s   $f0, $f22
/* AEE078 80240C68 46200000 */  add.d     $f0, $f0, $f0
/* AEE07C 80240C6C 3C014059 */  lui       $at, 0x4059
/* AEE080 80240C70 44811800 */  mtc1      $at, $f3
/* AEE084 80240C74 44801000 */  mtc1      $zero, $f2
/* AEE088 80240C78 3C018024 */  lui       $at, %hi(D_80244840_AF1C50)
/* AEE08C 80240C7C D4244840 */  ldc1      $f4, %lo(D_80244840_AF1C50)($at)
/* AEE090 80240C80 46220003 */  div.d     $f0, $f0, $f2
/* AEE094 80240C84 46240000 */  add.d     $f0, $f0, $f4
/* AEE098 80240C88 C7A20020 */  lwc1      $f2, 0x20($sp)
/* AEE09C 80240C8C C7A40024 */  lwc1      $f4, 0x24($sp)
/* AEE0A0 80240C90 44051000 */  mfc1      $a1, $f2
/* AEE0A4 80240C94 44072000 */  mfc1      $a3, $f4
/* AEE0A8 80240C98 46200020 */  cvt.s.d   $f0, $f0
/* AEE0AC 80240C9C E7A00010 */  swc1      $f0, 0x10($sp)
/* AEE0B0 80240CA0 8E26003C */  lw        $a2, 0x3c($s1)
/* AEE0B4 80240CA4 0C090298 */  jal       func_80240A60_AEDE70
/* AEE0B8 80240CA8 02C0202D */   daddu    $a0, $s6, $zero
/* AEE0BC 80240CAC 02A0202D */  daddu     $a0, $s5, $zero
/* AEE0C0 80240CB0 4406C000 */  mfc1      $a2, $f24
/* AEE0C4 80240CB4 8E27000C */  lw        $a3, 0xc($s1)
/* AEE0C8 80240CB8 C6200038 */  lwc1      $f0, 0x38($s1)
/* AEE0CC 80240CBC C6220040 */  lwc1      $f2, 0x40($s1)
/* AEE0D0 80240CC0 0280282D */  daddu     $a1, $s4, $zero
/* AEE0D4 80240CC4 E7A00020 */  swc1      $f0, 0x20($sp)
/* AEE0D8 80240CC8 0C00A7E7 */  jal       add_vec2D_polar
/* AEE0DC 80240CCC E7A20024 */   swc1     $f2, 0x24($sp)
/* AEE0E0 80240CD0 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* AEE0E4 80240CD4 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* AEE0E8 80240CD8 8E460028 */  lw        $a2, 0x28($s2)
/* AEE0EC 80240CDC 0C00A7B5 */  jal       dist2D
/* AEE0F0 80240CE0 8E470030 */   lw       $a3, 0x30($s2)
/* AEE0F4 80240CE4 461A003E */  c.le.s    $f0, $f26
/* AEE0F8 80240CE8 00000000 */  nop
/* AEE0FC 80240CEC 45030001 */  bc1tl     .L80240CF4
/* AEE100 80240CF0 36100010 */   ori      $s0, $s0, 0x10
.L80240CF4:
/* AEE104 80240CF4 32020001 */  andi      $v0, $s0, 1
/* AEE108 80240CF8 10400026 */  beqz      $v0, .L80240D94
/* AEE10C 80240CFC 02E0202D */   daddu    $a0, $s7, $zero
/* AEE110 80240D00 C62C0038 */  lwc1      $f12, 0x38($s1)
/* AEE114 80240D04 C62E0040 */  lwc1      $f14, 0x40($s1)
/* AEE118 80240D08 8E660028 */  lw        $a2, 0x28($s3)
/* AEE11C 80240D0C 8E670030 */  lw        $a3, 0x30($s3)
/* AEE120 80240D10 C622003C */  lwc1      $f2, 0x3c($s1)
/* AEE124 80240D14 46006006 */  mov.s     $f0, $f12
/* AEE128 80240D18 46007106 */  mov.s     $f4, $f14
/* AEE12C 80240D1C E7A00020 */  swc1      $f0, 0x20($sp)
/* AEE130 80240D20 E7A20028 */  swc1      $f2, 0x28($sp)
/* AEE134 80240D24 0C00A7B5 */  jal       dist2D
/* AEE138 80240D28 E7A40024 */   swc1     $f4, 0x24($sp)
/* AEE13C 80240D2C C62C0038 */  lwc1      $f12, 0x38($s1)
/* AEE140 80240D30 C62E0040 */  lwc1      $f14, 0x40($s1)
/* AEE144 80240D34 8E660028 */  lw        $a2, 0x28($s3)
/* AEE148 80240D38 8E670030 */  lw        $a3, 0x30($s3)
/* AEE14C 80240D3C 0C00A720 */  jal       atan2
/* AEE150 80240D40 46000506 */   mov.s    $f20, $f0
/* AEE154 80240D44 0000202D */  daddu     $a0, $zero, $zero
/* AEE158 80240D48 02A0282D */  daddu     $a1, $s5, $zero
/* AEE15C 80240D4C E7B40010 */  swc1      $f20, 0x10($sp)
/* AEE160 80240D50 E7A00014 */  swc1      $f0, 0x14($sp)
/* AEE164 80240D54 862200A6 */  lh        $v0, 0xa6($s1)
/* AEE168 80240D58 27A60028 */  addiu     $a2, $sp, 0x28
/* AEE16C 80240D5C 44820000 */  mtc1      $v0, $f0
/* AEE170 80240D60 00000000 */  nop
/* AEE174 80240D64 46800020 */  cvt.s.w   $f0, $f0
/* AEE178 80240D68 E7A00018 */  swc1      $f0, 0x18($sp)
/* AEE17C 80240D6C 862200A8 */  lh        $v0, 0xa8($s1)
/* AEE180 80240D70 0280382D */  daddu     $a3, $s4, $zero
/* AEE184 80240D74 44820000 */  mtc1      $v0, $f0
/* AEE188 80240D78 00000000 */  nop
/* AEE18C 80240D7C 46800020 */  cvt.s.w   $f0, $f0
/* AEE190 80240D80 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* AEE194 80240D84 E7A0001C */   swc1     $f0, 0x1c($sp)
/* AEE198 80240D88 54400001 */  bnel      $v0, $zero, .L80240D90
/* AEE19C 80240D8C 0000802D */   daddu    $s0, $zero, $zero
.L80240D90:
/* AEE1A0 80240D90 02E0202D */  daddu     $a0, $s7, $zero
.L80240D94:
/* AEE1A4 80240D94 03C0282D */  daddu     $a1, $fp, $zero
/* AEE1A8 80240D98 0C0B2026 */  jal       evt_set_variable
/* AEE1AC 80240D9C 0200302D */   daddu    $a2, $s0, $zero
/* AEE1B0 80240DA0 8FBF0054 */  lw        $ra, 0x54($sp)
/* AEE1B4 80240DA4 8FBE0050 */  lw        $fp, 0x50($sp)
/* AEE1B8 80240DA8 8FB7004C */  lw        $s7, 0x4c($sp)
/* AEE1BC 80240DAC 8FB60048 */  lw        $s6, 0x48($sp)
/* AEE1C0 80240DB0 8FB50044 */  lw        $s5, 0x44($sp)
/* AEE1C4 80240DB4 8FB40040 */  lw        $s4, 0x40($sp)
/* AEE1C8 80240DB8 8FB3003C */  lw        $s3, 0x3c($sp)
/* AEE1CC 80240DBC 8FB20038 */  lw        $s2, 0x38($sp)
/* AEE1D0 80240DC0 8FB10034 */  lw        $s1, 0x34($sp)
/* AEE1D4 80240DC4 8FB00030 */  lw        $s0, 0x30($sp)
/* AEE1D8 80240DC8 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* AEE1DC 80240DCC D7B80068 */  ldc1      $f24, 0x68($sp)
/* AEE1E0 80240DD0 D7B60060 */  ldc1      $f22, 0x60($sp)
/* AEE1E4 80240DD4 D7B40058 */  ldc1      $f20, 0x58($sp)
/* AEE1E8 80240DD8 24020002 */  addiu     $v0, $zero, 2
/* AEE1EC 80240DDC 03E00008 */  jr        $ra
/* AEE1F0 80240DE0 27BD0078 */   addiu    $sp, $sp, 0x78
