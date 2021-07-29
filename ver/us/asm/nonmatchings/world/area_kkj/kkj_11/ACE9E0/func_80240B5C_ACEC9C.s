.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80245F40_AD4080
.double 0.3, 2.8165885703910132e+209

.section .text

glabel func_80240B5C_ACEC9C
/* ACEC9C 80240B5C 27BDFF88 */  addiu     $sp, $sp, -0x78
/* ACECA0 80240B60 AFB7004C */  sw        $s7, 0x4c($sp)
/* ACECA4 80240B64 0080B82D */  daddu     $s7, $a0, $zero
/* ACECA8 80240B68 AFBF0054 */  sw        $ra, 0x54($sp)
/* ACECAC 80240B6C AFBE0050 */  sw        $fp, 0x50($sp)
/* ACECB0 80240B70 AFB60048 */  sw        $s6, 0x48($sp)
/* ACECB4 80240B74 AFB50044 */  sw        $s5, 0x44($sp)
/* ACECB8 80240B78 AFB40040 */  sw        $s4, 0x40($sp)
/* ACECBC 80240B7C AFB3003C */  sw        $s3, 0x3c($sp)
/* ACECC0 80240B80 AFB20038 */  sw        $s2, 0x38($sp)
/* ACECC4 80240B84 AFB10034 */  sw        $s1, 0x34($sp)
/* ACECC8 80240B88 AFB00030 */  sw        $s0, 0x30($sp)
/* ACECCC 80240B8C F7BA0070 */  sdc1      $f26, 0x70($sp)
/* ACECD0 80240B90 F7B80068 */  sdc1      $f24, 0x68($sp)
/* ACECD4 80240B94 F7B60060 */  sdc1      $f22, 0x60($sp)
/* ACECD8 80240B98 F7B40058 */  sdc1      $f20, 0x58($sp)
/* ACECDC 80240B9C 8EE20148 */  lw        $v0, 0x148($s7)
/* ACECE0 80240BA0 0C00EABB */  jal       get_npc_unsafe
/* ACECE4 80240BA4 84440008 */   lh       $a0, 8($v0)
/* ACECE8 80240BA8 27B50020 */  addiu     $s5, $sp, 0x20
/* ACECEC 80240BAC 02A0202D */  daddu     $a0, $s5, $zero
/* ACECF0 80240BB0 0040882D */  daddu     $s1, $v0, $zero
/* ACECF4 80240BB4 27B40024 */  addiu     $s4, $sp, 0x24
/* ACECF8 80240BB8 8EE3000C */  lw        $v1, 0xc($s7)
/* ACECFC 80240BBC 3C0641F0 */  lui       $a2, 0x41f0
/* ACED00 80240BC0 8E27000C */  lw        $a3, 0xc($s1)
/* ACED04 80240BC4 C6200038 */  lwc1      $f0, 0x38($s1)
/* ACED08 80240BC8 C6220040 */  lwc1      $f2, 0x40($s1)
/* ACED0C 80240BCC 8C7E0000 */  lw        $fp, ($v1)
/* ACED10 80240BD0 24630004 */  addiu     $v1, $v1, 4
/* ACED14 80240BD4 C4740000 */  lwc1      $f20, ($v1)
/* ACED18 80240BD8 4680A520 */  cvt.s.w   $f20, $f20
/* ACED1C 80240BDC 24630004 */  addiu     $v1, $v1, 4
/* ACED20 80240BE0 C4760000 */  lwc1      $f22, ($v1)
/* ACED24 80240BE4 4680B5A0 */  cvt.s.w   $f22, $f22
/* ACED28 80240BE8 24630004 */  addiu     $v1, $v1, 4
/* ACED2C 80240BEC C4780000 */  lwc1      $f24, ($v1)
/* ACED30 80240BF0 4680C620 */  cvt.s.w   $f24, $f24
/* ACED34 80240BF4 24630004 */  addiu     $v1, $v1, 4
/* ACED38 80240BF8 C47A0000 */  lwc1      $f26, ($v1)
/* ACED3C 80240BFC 4680D6A0 */  cvt.s.w   $f26, $f26
/* ACED40 80240C00 24630004 */  addiu     $v1, $v1, 4
/* ACED44 80240C04 8C760000 */  lw        $s6, ($v1)
/* ACED48 80240C08 8C700004 */  lw        $s0, 4($v1)
/* ACED4C 80240C0C 0280282D */  daddu     $a1, $s4, $zero
/* ACED50 80240C10 E7A00020 */  swc1      $f0, 0x20($sp)
/* ACED54 80240C14 0C00A7E7 */  jal       add_vec2D_polar
/* ACED58 80240C18 E7A20024 */   swc1     $f2, 0x24($sp)
/* ACED5C 80240C1C 3C038015 */  lui       $v1, %hi(D_80151328)
/* ACED60 80240C20 8C631328 */  lw        $v1, %lo(D_80151328)($v1)
/* ACED64 80240C24 C7A00020 */  lwc1      $f0, 0x20($sp)
/* ACED68 80240C28 3C0141A0 */  lui       $at, 0x41a0
/* ACED6C 80240C2C 44811000 */  mtc1      $at, $f2
/* ACED70 80240C30 00101040 */  sll       $v0, $s0, 1
/* ACED74 80240C34 00501021 */  addu      $v0, $v0, $s0
/* ACED78 80240C38 000210C0 */  sll       $v0, $v0, 3
/* ACED7C 80240C3C 24420004 */  addiu     $v0, $v0, 4
/* ACED80 80240C40 00621821 */  addu      $v1, $v1, $v0
/* ACED84 80240C44 E4600004 */  swc1      $f0, 4($v1)
/* ACED88 80240C48 C620003C */  lwc1      $f0, 0x3c($s1)
/* ACED8C 80240C4C 4406A000 */  mfc1      $a2, $f20
/* ACED90 80240C50 46020000 */  add.s     $f0, $f0, $f2
/* ACED94 80240C54 C7A20024 */  lwc1      $f2, 0x24($sp)
/* ACED98 80240C58 02A0202D */  daddu     $a0, $s5, $zero
/* ACED9C 80240C5C E462000C */  swc1      $f2, 0xc($v1)
/* ACEDA0 80240C60 E4600008 */  swc1      $f0, 8($v1)
/* ACEDA4 80240C64 8E27000C */  lw        $a3, 0xc($s1)
/* ACEDA8 80240C68 C6200038 */  lwc1      $f0, 0x38($s1)
/* ACEDAC 80240C6C C6220040 */  lwc1      $f2, 0x40($s1)
/* ACEDB0 80240C70 0280282D */  daddu     $a1, $s4, $zero
/* ACEDB4 80240C74 E7A00020 */  swc1      $f0, 0x20($sp)
/* ACEDB8 80240C78 0C00A7E7 */  jal       add_vec2D_polar
/* ACEDBC 80240C7C E7A20024 */   swc1     $f2, 0x24($sp)
/* ACEDC0 80240C80 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* ACEDC4 80240C84 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* ACEDC8 80240C88 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* ACEDCC 80240C8C C7AE0024 */  lwc1      $f14, 0x24($sp)
/* ACEDD0 80240C90 8E460028 */  lw        $a2, 0x28($s2)
/* ACEDD4 80240C94 8E470030 */  lw        $a3, 0x30($s2)
/* ACEDD8 80240C98 0C00A7B5 */  jal       dist2D
/* ACEDDC 80240C9C 0000802D */   daddu    $s0, $zero, $zero
/* ACEDE0 80240CA0 4616003E */  c.le.s    $f0, $f22
/* ACEDE4 80240CA4 00000000 */  nop
/* ACEDE8 80240CA8 45000002 */  bc1f      .L80240CB4
/* ACEDEC 80240CAC 0240982D */   daddu    $s3, $s2, $zero
/* ACEDF0 80240CB0 24100001 */  addiu     $s0, $zero, 1
.L80240CB4:
/* ACEDF4 80240CB4 4600B021 */  cvt.d.s   $f0, $f22
/* ACEDF8 80240CB8 46200000 */  add.d     $f0, $f0, $f0
/* ACEDFC 80240CBC 3C014059 */  lui       $at, 0x4059
/* ACEE00 80240CC0 44811800 */  mtc1      $at, $f3
/* ACEE04 80240CC4 44801000 */  mtc1      $zero, $f2
/* ACEE08 80240CC8 3C018024 */  lui       $at, %hi(D_80245F40_AD4080)
/* ACEE0C 80240CCC D4245F40 */  ldc1      $f4, %lo(D_80245F40_AD4080)($at)
/* ACEE10 80240CD0 46220003 */  div.d     $f0, $f0, $f2
/* ACEE14 80240CD4 46240000 */  add.d     $f0, $f0, $f4
/* ACEE18 80240CD8 C7A20020 */  lwc1      $f2, 0x20($sp)
/* ACEE1C 80240CDC C7A40024 */  lwc1      $f4, 0x24($sp)
/* ACEE20 80240CE0 44051000 */  mfc1      $a1, $f2
/* ACEE24 80240CE4 44072000 */  mfc1      $a3, $f4
/* ACEE28 80240CE8 46200020 */  cvt.s.d   $f0, $f0
/* ACEE2C 80240CEC E7A00010 */  swc1      $f0, 0x10($sp)
/* ACEE30 80240CF0 8E26003C */  lw        $a2, 0x3c($s1)
/* ACEE34 80240CF4 0C0902AC */  jal       func_80240AB0_ACEBF0
/* ACEE38 80240CF8 02C0202D */   daddu    $a0, $s6, $zero
/* ACEE3C 80240CFC 02A0202D */  daddu     $a0, $s5, $zero
/* ACEE40 80240D00 4406C000 */  mfc1      $a2, $f24
/* ACEE44 80240D04 8E27000C */  lw        $a3, 0xc($s1)
/* ACEE48 80240D08 C6200038 */  lwc1      $f0, 0x38($s1)
/* ACEE4C 80240D0C C6220040 */  lwc1      $f2, 0x40($s1)
/* ACEE50 80240D10 0280282D */  daddu     $a1, $s4, $zero
/* ACEE54 80240D14 E7A00020 */  swc1      $f0, 0x20($sp)
/* ACEE58 80240D18 0C00A7E7 */  jal       add_vec2D_polar
/* ACEE5C 80240D1C E7A20024 */   swc1     $f2, 0x24($sp)
/* ACEE60 80240D20 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* ACEE64 80240D24 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* ACEE68 80240D28 8E460028 */  lw        $a2, 0x28($s2)
/* ACEE6C 80240D2C 0C00A7B5 */  jal       dist2D
/* ACEE70 80240D30 8E470030 */   lw       $a3, 0x30($s2)
/* ACEE74 80240D34 461A003E */  c.le.s    $f0, $f26
/* ACEE78 80240D38 00000000 */  nop
/* ACEE7C 80240D3C 45030001 */  bc1tl     .L80240D44
/* ACEE80 80240D40 36100010 */   ori      $s0, $s0, 0x10
.L80240D44:
/* ACEE84 80240D44 32020001 */  andi      $v0, $s0, 1
/* ACEE88 80240D48 10400026 */  beqz      $v0, .L80240DE4
/* ACEE8C 80240D4C 02E0202D */   daddu    $a0, $s7, $zero
/* ACEE90 80240D50 C62C0038 */  lwc1      $f12, 0x38($s1)
/* ACEE94 80240D54 C62E0040 */  lwc1      $f14, 0x40($s1)
/* ACEE98 80240D58 8E660028 */  lw        $a2, 0x28($s3)
/* ACEE9C 80240D5C 8E670030 */  lw        $a3, 0x30($s3)
/* ACEEA0 80240D60 C622003C */  lwc1      $f2, 0x3c($s1)
/* ACEEA4 80240D64 46006006 */  mov.s     $f0, $f12
/* ACEEA8 80240D68 46007106 */  mov.s     $f4, $f14
/* ACEEAC 80240D6C E7A00020 */  swc1      $f0, 0x20($sp)
/* ACEEB0 80240D70 E7A20028 */  swc1      $f2, 0x28($sp)
/* ACEEB4 80240D74 0C00A7B5 */  jal       dist2D
/* ACEEB8 80240D78 E7A40024 */   swc1     $f4, 0x24($sp)
/* ACEEBC 80240D7C C62C0038 */  lwc1      $f12, 0x38($s1)
/* ACEEC0 80240D80 C62E0040 */  lwc1      $f14, 0x40($s1)
/* ACEEC4 80240D84 8E660028 */  lw        $a2, 0x28($s3)
/* ACEEC8 80240D88 8E670030 */  lw        $a3, 0x30($s3)
/* ACEECC 80240D8C 0C00A720 */  jal       atan2
/* ACEED0 80240D90 46000506 */   mov.s    $f20, $f0
/* ACEED4 80240D94 0000202D */  daddu     $a0, $zero, $zero
/* ACEED8 80240D98 02A0282D */  daddu     $a1, $s5, $zero
/* ACEEDC 80240D9C E7B40010 */  swc1      $f20, 0x10($sp)
/* ACEEE0 80240DA0 E7A00014 */  swc1      $f0, 0x14($sp)
/* ACEEE4 80240DA4 862200A6 */  lh        $v0, 0xa6($s1)
/* ACEEE8 80240DA8 27A60028 */  addiu     $a2, $sp, 0x28
/* ACEEEC 80240DAC 44820000 */  mtc1      $v0, $f0
/* ACEEF0 80240DB0 00000000 */  nop
/* ACEEF4 80240DB4 46800020 */  cvt.s.w   $f0, $f0
/* ACEEF8 80240DB8 E7A00018 */  swc1      $f0, 0x18($sp)
/* ACEEFC 80240DBC 862200A8 */  lh        $v0, 0xa8($s1)
/* ACEF00 80240DC0 0280382D */  daddu     $a3, $s4, $zero
/* ACEF04 80240DC4 44820000 */  mtc1      $v0, $f0
/* ACEF08 80240DC8 00000000 */  nop
/* ACEF0C 80240DCC 46800020 */  cvt.s.w   $f0, $f0
/* ACEF10 80240DD0 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* ACEF14 80240DD4 E7A0001C */   swc1     $f0, 0x1c($sp)
/* ACEF18 80240DD8 54400001 */  bnel      $v0, $zero, .L80240DE0
/* ACEF1C 80240DDC 0000802D */   daddu    $s0, $zero, $zero
.L80240DE0:
/* ACEF20 80240DE0 02E0202D */  daddu     $a0, $s7, $zero
.L80240DE4:
/* ACEF24 80240DE4 03C0282D */  daddu     $a1, $fp, $zero
/* ACEF28 80240DE8 0C0B2026 */  jal       set_variable
/* ACEF2C 80240DEC 0200302D */   daddu    $a2, $s0, $zero
/* ACEF30 80240DF0 8FBF0054 */  lw        $ra, 0x54($sp)
/* ACEF34 80240DF4 8FBE0050 */  lw        $fp, 0x50($sp)
/* ACEF38 80240DF8 8FB7004C */  lw        $s7, 0x4c($sp)
/* ACEF3C 80240DFC 8FB60048 */  lw        $s6, 0x48($sp)
/* ACEF40 80240E00 8FB50044 */  lw        $s5, 0x44($sp)
/* ACEF44 80240E04 8FB40040 */  lw        $s4, 0x40($sp)
/* ACEF48 80240E08 8FB3003C */  lw        $s3, 0x3c($sp)
/* ACEF4C 80240E0C 8FB20038 */  lw        $s2, 0x38($sp)
/* ACEF50 80240E10 8FB10034 */  lw        $s1, 0x34($sp)
/* ACEF54 80240E14 8FB00030 */  lw        $s0, 0x30($sp)
/* ACEF58 80240E18 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* ACEF5C 80240E1C D7B80068 */  ldc1      $f24, 0x68($sp)
/* ACEF60 80240E20 D7B60060 */  ldc1      $f22, 0x60($sp)
/* ACEF64 80240E24 D7B40058 */  ldc1      $f20, 0x58($sp)
/* ACEF68 80240E28 24020002 */  addiu     $v0, $zero, 2
/* ACEF6C 80240E2C 03E00008 */  jr        $ra
/* ACEF70 80240E30 27BD0078 */   addiu    $sp, $sp, 0x78
