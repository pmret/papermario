.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80243CE0_B06560
.double 0.3, 2.8165885703910132e+209

.section .text

glabel func_8024039C_B02C1C
/* B02C1C 8024039C 27BDFF88 */  addiu     $sp, $sp, -0x78
/* B02C20 802403A0 AFB7004C */  sw        $s7, 0x4c($sp)
/* B02C24 802403A4 0080B82D */  daddu     $s7, $a0, $zero
/* B02C28 802403A8 AFBF0054 */  sw        $ra, 0x54($sp)
/* B02C2C 802403AC AFBE0050 */  sw        $fp, 0x50($sp)
/* B02C30 802403B0 AFB60048 */  sw        $s6, 0x48($sp)
/* B02C34 802403B4 AFB50044 */  sw        $s5, 0x44($sp)
/* B02C38 802403B8 AFB40040 */  sw        $s4, 0x40($sp)
/* B02C3C 802403BC AFB3003C */  sw        $s3, 0x3c($sp)
/* B02C40 802403C0 AFB20038 */  sw        $s2, 0x38($sp)
/* B02C44 802403C4 AFB10034 */  sw        $s1, 0x34($sp)
/* B02C48 802403C8 AFB00030 */  sw        $s0, 0x30($sp)
/* B02C4C 802403CC F7BA0070 */  sdc1      $f26, 0x70($sp)
/* B02C50 802403D0 F7B80068 */  sdc1      $f24, 0x68($sp)
/* B02C54 802403D4 F7B60060 */  sdc1      $f22, 0x60($sp)
/* B02C58 802403D8 F7B40058 */  sdc1      $f20, 0x58($sp)
/* B02C5C 802403DC 8EE20148 */  lw        $v0, 0x148($s7)
/* B02C60 802403E0 0C00EABB */  jal       get_npc_unsafe
/* B02C64 802403E4 84440008 */   lh       $a0, 8($v0)
/* B02C68 802403E8 27B50020 */  addiu     $s5, $sp, 0x20
/* B02C6C 802403EC 02A0202D */  daddu     $a0, $s5, $zero
/* B02C70 802403F0 0040882D */  daddu     $s1, $v0, $zero
/* B02C74 802403F4 27B40024 */  addiu     $s4, $sp, 0x24
/* B02C78 802403F8 8EE3000C */  lw        $v1, 0xc($s7)
/* B02C7C 802403FC 3C0641F0 */  lui       $a2, 0x41f0
/* B02C80 80240400 8E27000C */  lw        $a3, 0xc($s1)
/* B02C84 80240404 C6200038 */  lwc1      $f0, 0x38($s1)
/* B02C88 80240408 C6220040 */  lwc1      $f2, 0x40($s1)
/* B02C8C 8024040C 8C7E0000 */  lw        $fp, ($v1)
/* B02C90 80240410 24630004 */  addiu     $v1, $v1, 4
/* B02C94 80240414 C4740000 */  lwc1      $f20, ($v1)
/* B02C98 80240418 4680A520 */  cvt.s.w   $f20, $f20
/* B02C9C 8024041C 24630004 */  addiu     $v1, $v1, 4
/* B02CA0 80240420 C4760000 */  lwc1      $f22, ($v1)
/* B02CA4 80240424 4680B5A0 */  cvt.s.w   $f22, $f22
/* B02CA8 80240428 24630004 */  addiu     $v1, $v1, 4
/* B02CAC 8024042C C4780000 */  lwc1      $f24, ($v1)
/* B02CB0 80240430 4680C620 */  cvt.s.w   $f24, $f24
/* B02CB4 80240434 24630004 */  addiu     $v1, $v1, 4
/* B02CB8 80240438 C47A0000 */  lwc1      $f26, ($v1)
/* B02CBC 8024043C 4680D6A0 */  cvt.s.w   $f26, $f26
/* B02CC0 80240440 24630004 */  addiu     $v1, $v1, 4
/* B02CC4 80240444 8C760000 */  lw        $s6, ($v1)
/* B02CC8 80240448 8C700004 */  lw        $s0, 4($v1)
/* B02CCC 8024044C 0280282D */  daddu     $a1, $s4, $zero
/* B02CD0 80240450 E7A00020 */  swc1      $f0, 0x20($sp)
/* B02CD4 80240454 0C00A7E7 */  jal       add_vec2D_polar
/* B02CD8 80240458 E7A20024 */   swc1     $f2, 0x24($sp)
/* B02CDC 8024045C 3C038015 */  lui       $v1, %hi(D_80151328)
/* B02CE0 80240460 8C631328 */  lw        $v1, %lo(D_80151328)($v1)
/* B02CE4 80240464 C7A00020 */  lwc1      $f0, 0x20($sp)
/* B02CE8 80240468 3C0141A0 */  lui       $at, 0x41a0
/* B02CEC 8024046C 44811000 */  mtc1      $at, $f2
/* B02CF0 80240470 00101040 */  sll       $v0, $s0, 1
/* B02CF4 80240474 00501021 */  addu      $v0, $v0, $s0
/* B02CF8 80240478 000210C0 */  sll       $v0, $v0, 3
/* B02CFC 8024047C 24420004 */  addiu     $v0, $v0, 4
/* B02D00 80240480 00621821 */  addu      $v1, $v1, $v0
/* B02D04 80240484 E4600004 */  swc1      $f0, 4($v1)
/* B02D08 80240488 C620003C */  lwc1      $f0, 0x3c($s1)
/* B02D0C 8024048C 4406A000 */  mfc1      $a2, $f20
/* B02D10 80240490 46020000 */  add.s     $f0, $f0, $f2
/* B02D14 80240494 C7A20024 */  lwc1      $f2, 0x24($sp)
/* B02D18 80240498 02A0202D */  daddu     $a0, $s5, $zero
/* B02D1C 8024049C E462000C */  swc1      $f2, 0xc($v1)
/* B02D20 802404A0 E4600008 */  swc1      $f0, 8($v1)
/* B02D24 802404A4 8E27000C */  lw        $a3, 0xc($s1)
/* B02D28 802404A8 C6200038 */  lwc1      $f0, 0x38($s1)
/* B02D2C 802404AC C6220040 */  lwc1      $f2, 0x40($s1)
/* B02D30 802404B0 0280282D */  daddu     $a1, $s4, $zero
/* B02D34 802404B4 E7A00020 */  swc1      $f0, 0x20($sp)
/* B02D38 802404B8 0C00A7E7 */  jal       add_vec2D_polar
/* B02D3C 802404BC E7A20024 */   swc1     $f2, 0x24($sp)
/* B02D40 802404C0 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* B02D44 802404C4 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* B02D48 802404C8 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* B02D4C 802404CC C7AE0024 */  lwc1      $f14, 0x24($sp)
/* B02D50 802404D0 8E460028 */  lw        $a2, 0x28($s2)
/* B02D54 802404D4 8E470030 */  lw        $a3, 0x30($s2)
/* B02D58 802404D8 0C00A7B5 */  jal       dist2D
/* B02D5C 802404DC 0000802D */   daddu    $s0, $zero, $zero
/* B02D60 802404E0 4616003E */  c.le.s    $f0, $f22
/* B02D64 802404E4 00000000 */  nop
/* B02D68 802404E8 45000002 */  bc1f      .L802404F4
/* B02D6C 802404EC 0240982D */   daddu    $s3, $s2, $zero
/* B02D70 802404F0 24100001 */  addiu     $s0, $zero, 1
.L802404F4:
/* B02D74 802404F4 4600B021 */  cvt.d.s   $f0, $f22
/* B02D78 802404F8 46200000 */  add.d     $f0, $f0, $f0
/* B02D7C 802404FC 3C014059 */  lui       $at, 0x4059
/* B02D80 80240500 44811800 */  mtc1      $at, $f3
/* B02D84 80240504 44801000 */  mtc1      $zero, $f2
/* B02D88 80240508 3C018024 */  lui       $at, %hi(D_80243CE0_B06560)
/* B02D8C 8024050C D4243CE0 */  ldc1      $f4, %lo(D_80243CE0_B06560)($at)
/* B02D90 80240510 46220003 */  div.d     $f0, $f0, $f2
/* B02D94 80240514 46240000 */  add.d     $f0, $f0, $f4
/* B02D98 80240518 C7A20020 */  lwc1      $f2, 0x20($sp)
/* B02D9C 8024051C C7A40024 */  lwc1      $f4, 0x24($sp)
/* B02DA0 80240520 44051000 */  mfc1      $a1, $f2
/* B02DA4 80240524 44072000 */  mfc1      $a3, $f4
/* B02DA8 80240528 46200020 */  cvt.s.d   $f0, $f0
/* B02DAC 8024052C E7A00010 */  swc1      $f0, 0x10($sp)
/* B02DB0 80240530 8E26003C */  lw        $a2, 0x3c($s1)
/* B02DB4 80240534 0C0900BC */  jal       func_802402F0_B02B70
/* B02DB8 80240538 02C0202D */   daddu    $a0, $s6, $zero
/* B02DBC 8024053C 02A0202D */  daddu     $a0, $s5, $zero
/* B02DC0 80240540 4406C000 */  mfc1      $a2, $f24
/* B02DC4 80240544 8E27000C */  lw        $a3, 0xc($s1)
/* B02DC8 80240548 C6200038 */  lwc1      $f0, 0x38($s1)
/* B02DCC 8024054C C6220040 */  lwc1      $f2, 0x40($s1)
/* B02DD0 80240550 0280282D */  daddu     $a1, $s4, $zero
/* B02DD4 80240554 E7A00020 */  swc1      $f0, 0x20($sp)
/* B02DD8 80240558 0C00A7E7 */  jal       add_vec2D_polar
/* B02DDC 8024055C E7A20024 */   swc1     $f2, 0x24($sp)
/* B02DE0 80240560 C7AC0020 */  lwc1      $f12, 0x20($sp)
/* B02DE4 80240564 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* B02DE8 80240568 8E460028 */  lw        $a2, 0x28($s2)
/* B02DEC 8024056C 0C00A7B5 */  jal       dist2D
/* B02DF0 80240570 8E470030 */   lw       $a3, 0x30($s2)
/* B02DF4 80240574 461A003E */  c.le.s    $f0, $f26
/* B02DF8 80240578 00000000 */  nop
/* B02DFC 8024057C 45030001 */  bc1tl     .L80240584
/* B02E00 80240580 36100010 */   ori      $s0, $s0, 0x10
.L80240584:
/* B02E04 80240584 32020001 */  andi      $v0, $s0, 1
/* B02E08 80240588 10400026 */  beqz      $v0, .L80240624
/* B02E0C 8024058C 02E0202D */   daddu    $a0, $s7, $zero
/* B02E10 80240590 C62C0038 */  lwc1      $f12, 0x38($s1)
/* B02E14 80240594 C62E0040 */  lwc1      $f14, 0x40($s1)
/* B02E18 80240598 8E660028 */  lw        $a2, 0x28($s3)
/* B02E1C 8024059C 8E670030 */  lw        $a3, 0x30($s3)
/* B02E20 802405A0 C622003C */  lwc1      $f2, 0x3c($s1)
/* B02E24 802405A4 46006006 */  mov.s     $f0, $f12
/* B02E28 802405A8 46007106 */  mov.s     $f4, $f14
/* B02E2C 802405AC E7A00020 */  swc1      $f0, 0x20($sp)
/* B02E30 802405B0 E7A20028 */  swc1      $f2, 0x28($sp)
/* B02E34 802405B4 0C00A7B5 */  jal       dist2D
/* B02E38 802405B8 E7A40024 */   swc1     $f4, 0x24($sp)
/* B02E3C 802405BC C62C0038 */  lwc1      $f12, 0x38($s1)
/* B02E40 802405C0 C62E0040 */  lwc1      $f14, 0x40($s1)
/* B02E44 802405C4 8E660028 */  lw        $a2, 0x28($s3)
/* B02E48 802405C8 8E670030 */  lw        $a3, 0x30($s3)
/* B02E4C 802405CC 0C00A720 */  jal       atan2
/* B02E50 802405D0 46000506 */   mov.s    $f20, $f0
/* B02E54 802405D4 0000202D */  daddu     $a0, $zero, $zero
/* B02E58 802405D8 02A0282D */  daddu     $a1, $s5, $zero
/* B02E5C 802405DC E7B40010 */  swc1      $f20, 0x10($sp)
/* B02E60 802405E0 E7A00014 */  swc1      $f0, 0x14($sp)
/* B02E64 802405E4 862200A6 */  lh        $v0, 0xa6($s1)
/* B02E68 802405E8 27A60028 */  addiu     $a2, $sp, 0x28
/* B02E6C 802405EC 44820000 */  mtc1      $v0, $f0
/* B02E70 802405F0 00000000 */  nop
/* B02E74 802405F4 46800020 */  cvt.s.w   $f0, $f0
/* B02E78 802405F8 E7A00018 */  swc1      $f0, 0x18($sp)
/* B02E7C 802405FC 862200A8 */  lh        $v0, 0xa8($s1)
/* B02E80 80240600 0280382D */  daddu     $a3, $s4, $zero
/* B02E84 80240604 44820000 */  mtc1      $v0, $f0
/* B02E88 80240608 00000000 */  nop
/* B02E8C 8024060C 46800020 */  cvt.s.w   $f0, $f0
/* B02E90 80240610 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* B02E94 80240614 E7A0001C */   swc1     $f0, 0x1c($sp)
/* B02E98 80240618 54400001 */  bnel      $v0, $zero, .L80240620
/* B02E9C 8024061C 0000802D */   daddu    $s0, $zero, $zero
.L80240620:
/* B02EA0 80240620 02E0202D */  daddu     $a0, $s7, $zero
.L80240624:
/* B02EA4 80240624 03C0282D */  daddu     $a1, $fp, $zero
/* B02EA8 80240628 0C0B2026 */  jal       set_variable
/* B02EAC 8024062C 0200302D */   daddu    $a2, $s0, $zero
/* B02EB0 80240630 8FBF0054 */  lw        $ra, 0x54($sp)
/* B02EB4 80240634 8FBE0050 */  lw        $fp, 0x50($sp)
/* B02EB8 80240638 8FB7004C */  lw        $s7, 0x4c($sp)
/* B02EBC 8024063C 8FB60048 */  lw        $s6, 0x48($sp)
/* B02EC0 80240640 8FB50044 */  lw        $s5, 0x44($sp)
/* B02EC4 80240644 8FB40040 */  lw        $s4, 0x40($sp)
/* B02EC8 80240648 8FB3003C */  lw        $s3, 0x3c($sp)
/* B02ECC 8024064C 8FB20038 */  lw        $s2, 0x38($sp)
/* B02ED0 80240650 8FB10034 */  lw        $s1, 0x34($sp)
/* B02ED4 80240654 8FB00030 */  lw        $s0, 0x30($sp)
/* B02ED8 80240658 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* B02EDC 8024065C D7B80068 */  ldc1      $f24, 0x68($sp)
/* B02EE0 80240660 D7B60060 */  ldc1      $f22, 0x60($sp)
/* B02EE4 80240664 D7B40058 */  ldc1      $f20, 0x58($sp)
/* B02EE8 80240668 24020002 */  addiu     $v0, $zero, 2
/* B02EEC 8024066C 03E00008 */  jr        $ra
/* B02EF0 80240670 27BD0078 */   addiu    $sp, $sp, 0x78
