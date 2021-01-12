.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E6C24
/* 1084A4 802E6C24 27BDFF40 */  addiu     $sp, $sp, -0xc0
/* 1084A8 802E6C28 AFB300A4 */  sw        $s3, 0xa4($sp)
/* 1084AC 802E6C2C 0080982D */  daddu     $s3, $a0, $zero
/* 1084B0 802E6C30 AFB400A8 */  sw        $s4, 0xa8($sp)
/* 1084B4 802E6C34 3C148016 */  lui       $s4, %hi(D_8015A578)
/* 1084B8 802E6C38 2694A578 */  addiu     $s4, $s4, %lo(D_8015A578)
/* 1084BC 802E6C3C 0280202D */  daddu     $a0, $s4, $zero
/* 1084C0 802E6C40 AFBF00AC */  sw        $ra, 0xac($sp)
/* 1084C4 802E6C44 AFB200A0 */  sw        $s2, 0xa0($sp)
/* 1084C8 802E6C48 AFB1009C */  sw        $s1, 0x9c($sp)
/* 1084CC 802E6C4C AFB00098 */  sw        $s0, 0x98($sp)
/* 1084D0 802E6C50 F7B600B8 */  sdc1      $f22, 0xb8($sp)
/* 1084D4 802E6C54 F7B400B0 */  sdc1      $f20, 0xb0($sp)
/* 1084D8 802E6C58 8E720040 */  lw        $s2, 0x40($s3)
/* 1084DC 802E6C5C 0C00A580 */  jal       mem_clear
/* 1084E0 802E6C60 24050010 */   addiu    $a1, $zero, 0x10
/* 1084E4 802E6C64 3C02802E */  lui       $v0, %hi(func_802E61B0)
/* 1084E8 802E6C68 244261B0 */  addiu     $v0, $v0, %lo(func_802E61B0)
/* 1084EC 802E6C6C AE62003C */  sw        $v0, 0x3c($s3)
/* 1084F0 802E6C70 3402FFFF */  ori       $v0, $zero, 0xffff
/* 1084F4 802E6C74 A6420006 */  sh        $v0, 6($s2)
/* 1084F8 802E6C78 C660004C */  lwc1      $f0, 0x4c($s3)
/* 1084FC 802E6C7C 3C038016 */  lui       $v1, %hi(D_8015C7D0)
/* 108500 802E6C80 2463C7D0 */  addiu     $v1, $v1, %lo(D_8015C7D0)
/* 108504 802E6C84 E6400024 */  swc1      $f0, 0x24($s2)
/* 108508 802E6C88 94620002 */  lhu       $v0, 2($v1)
/* 10850C 802E6C8C A6420074 */  sh        $v0, 0x74($s2)
/* 108510 802E6C90 8C630004 */  lw        $v1, 4($v1)
/* 108514 802E6C94 24020001 */  addiu     $v0, $zero, 1
/* 108518 802E6C98 A2420003 */  sb        $v0, 3($s2)
/* 10851C 802E6C9C 2402FFFF */  addiu     $v0, $zero, -1
/* 108520 802E6CA0 AE420014 */  sw        $v0, 0x14($s2)
/* 108524 802E6CA4 14600003 */  bnez      $v1, .L802E6CB4
/* 108528 802E6CA8 AE430010 */   sw       $v1, 0x10($s2)
/* 10852C 802E6CAC 2402015C */  addiu     $v0, $zero, 0x15c
/* 108530 802E6CB0 AE420010 */  sw        $v0, 0x10($s2)
.L802E6CB4:
/* 108534 802E6CB4 26510034 */  addiu     $s1, $s2, 0x34
/* 108538 802E6CB8 0C019D28 */  jal       guMtxIdentF
/* 10853C 802E6CBC 0220202D */   daddu    $a0, $s1, $zero
/* 108540 802E6CC0 8E650048 */  lw        $a1, 0x48($s3)
/* 108544 802E6CC4 8E66004C */  lw        $a2, 0x4c($s3)
/* 108548 802E6CC8 8E670050 */  lw        $a3, 0x50($s3)
/* 10854C 802E6CCC 4480A000 */  mtc1      $zero, $f20
/* 108550 802E6CD0 0C019E40 */  jal       guTranslateF
/* 108554 802E6CD4 27A40018 */   addiu    $a0, $sp, 0x18
/* 108558 802E6CD8 27B00058 */  addiu     $s0, $sp, 0x58
/* 10855C 802E6CDC E7B40010 */  swc1      $f20, 0x10($sp)
/* 108560 802E6CE0 8E650064 */  lw        $a1, 0x64($s3)
/* 108564 802E6CE4 3C013F80 */  lui       $at, 0x3f80
/* 108568 802E6CE8 4481B000 */  mtc1      $at, $f22
/* 10856C 802E6CEC 4406A000 */  mfc1      $a2, $f20
/* 108570 802E6CF0 4407B000 */  mfc1      $a3, $f22
/* 108574 802E6CF4 0C019EC8 */  jal       guRotateF
/* 108578 802E6CF8 0200202D */   daddu    $a0, $s0, $zero
/* 10857C 802E6CFC 0200202D */  daddu     $a0, $s0, $zero
/* 108580 802E6D00 27A50018 */  addiu     $a1, $sp, 0x18
/* 108584 802E6D04 0C019D80 */  jal       guMtxCatF
/* 108588 802E6D08 00A0302D */   daddu    $a2, $a1, $zero
/* 10858C 802E6D0C E7B40010 */  swc1      $f20, 0x10($sp)
/* 108590 802E6D10 8E650060 */  lw        $a1, 0x60($s3)
/* 108594 802E6D14 4406B000 */  mfc1      $a2, $f22
/* 108598 802E6D18 4407A000 */  mfc1      $a3, $f20
/* 10859C 802E6D1C 0C019EC8 */  jal       guRotateF
/* 1085A0 802E6D20 0200202D */   daddu    $a0, $s0, $zero
/* 1085A4 802E6D24 0200202D */  daddu     $a0, $s0, $zero
/* 1085A8 802E6D28 27A50018 */  addiu     $a1, $sp, 0x18
/* 1085AC 802E6D2C 0C019D80 */  jal       guMtxCatF
/* 1085B0 802E6D30 00A0302D */   daddu    $a2, $a1, $zero
/* 1085B4 802E6D34 4406A000 */  mfc1      $a2, $f20
/* 1085B8 802E6D38 0200202D */  daddu     $a0, $s0, $zero
/* 1085BC 802E6D3C E7B60010 */  swc1      $f22, 0x10($sp)
/* 1085C0 802E6D40 8E650068 */  lw        $a1, 0x68($s3)
/* 1085C4 802E6D44 0C019EC8 */  jal       guRotateF
/* 1085C8 802E6D48 00C0382D */   daddu    $a3, $a2, $zero
/* 1085CC 802E6D4C 0200202D */  daddu     $a0, $s0, $zero
/* 1085D0 802E6D50 27A50018 */  addiu     $a1, $sp, 0x18
/* 1085D4 802E6D54 0C019D80 */  jal       guMtxCatF
/* 1085D8 802E6D58 00A0302D */   daddu    $a2, $a1, $zero
/* 1085DC 802E6D5C 8E650054 */  lw        $a1, 0x54($s3)
/* 1085E0 802E6D60 8E660058 */  lw        $a2, 0x58($s3)
/* 1085E4 802E6D64 8E67005C */  lw        $a3, 0x5c($s3)
/* 1085E8 802E6D68 0C019DF0 */  jal       guScaleF
/* 1085EC 802E6D6C 0200202D */   daddu    $a0, $s0, $zero
/* 1085F0 802E6D70 0200202D */  daddu     $a0, $s0, $zero
/* 1085F4 802E6D74 27A50018 */  addiu     $a1, $sp, 0x18
/* 1085F8 802E6D78 0C019D80 */  jal       guMtxCatF
/* 1085FC 802E6D7C 0220302D */   daddu    $a2, $s1, $zero
/* 108600 802E6D80 92820001 */  lbu       $v0, 1($s4)
/* 108604 802E6D84 30420001 */  andi      $v0, $v0, 1
/* 108608 802E6D88 10400009 */  beqz      $v0, .L802E6DB0
/* 10860C 802E6D8C 00000000 */   nop
/* 108610 802E6D90 3C100A00 */  lui       $s0, 0xa00
/* 108614 802E6D94 261001B0 */  addiu     $s0, $s0, 0x1b0
/* 108618 802E6D98 3C05802F */  lui       $a1, %hi(D_802EAAE0)
/* 10861C 802E6D9C 24A5AAE0 */  addiu     $a1, $a1, %lo(D_802EAAE0)
/* 108620 802E6DA0 0C0442F3 */  jal       func_80110BCC
/* 108624 802E6DA4 0260202D */   daddu    $a0, $s3, $zero
/* 108628 802E6DA8 080B9B6F */  j         .L802E6DBC
/* 10862C 802E6DAC 3202FFFF */   andi     $v0, $s0, 0xffff
.L802E6DB0:
/* 108630 802E6DB0 3C100A00 */  lui       $s0, 0xa00
/* 108634 802E6DB4 26100180 */  addiu     $s0, $s0, 0x180
/* 108638 802E6DB8 3202FFFF */  andi      $v0, $s0, 0xffff
.L802E6DBC:
/* 10863C 802E6DBC 8E650044 */  lw        $a1, 0x44($s3)
/* 108640 802E6DC0 96440074 */  lhu       $a0, 0x74($s2)
/* 108644 802E6DC4 00A22821 */  addu      $a1, $a1, $v0
/* 108648 802E6DC8 AE450078 */  sw        $a1, 0x78($s2)
/* 10864C 802E6DCC 8E670044 */  lw        $a3, 0x44($s3)
/* 108650 802E6DD0 0C0470CB */  jal       func_8011C32C
/* 108654 802E6DD4 26460034 */   addiu    $a2, $s2, 0x34
/* 108658 802E6DD8 3C038016 */  lui       $v1, %hi(D_8015A578)
/* 10865C 802E6DDC 2463A578 */  addiu     $v1, $v1, %lo(D_8015A578)
/* 108660 802E6DE0 90620001 */  lbu       $v0, 1($v1)
/* 108664 802E6DE4 24420001 */  addiu     $v0, $v0, 1
/* 108668 802E6DE8 A0620001 */  sb        $v0, 1($v1)
/* 10866C 802E6DEC 8FBF00AC */  lw        $ra, 0xac($sp)
/* 108670 802E6DF0 8FB400A8 */  lw        $s4, 0xa8($sp)
/* 108674 802E6DF4 8FB300A4 */  lw        $s3, 0xa4($sp)
/* 108678 802E6DF8 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 10867C 802E6DFC 8FB1009C */  lw        $s1, 0x9c($sp)
/* 108680 802E6E00 8FB00098 */  lw        $s0, 0x98($sp)
/* 108684 802E6E04 D7B600B8 */  ldc1      $f22, 0xb8($sp)
/* 108688 802E6E08 D7B400B0 */  ldc1      $f20, 0xb0($sp)
/* 10868C 802E6E0C 03E00008 */  jr        $ra
/* 108690 802E6E10 27BD00C0 */   addiu    $sp, $sp, 0xc0
/* 108694 802E6E14 00000000 */  nop
/* 108698 802E6E18 00000000 */  nop
/* 10869C 802E6E1C 00000000 */  nop
