.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406EC_B070EC
/* B070EC 802406EC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B070F0 802406F0 AFB3001C */  sw        $s3, 0x1c($sp)
/* B070F4 802406F4 0080982D */  daddu     $s3, $a0, $zero
/* B070F8 802406F8 AFBF0020 */  sw        $ra, 0x20($sp)
/* B070FC 802406FC AFB20018 */  sw        $s2, 0x18($sp)
/* B07100 80240700 AFB10014 */  sw        $s1, 0x14($sp)
/* B07104 80240704 AFB00010 */  sw        $s0, 0x10($sp)
/* B07108 80240708 8E70000C */  lw        $s0, 0xc($s3)
/* B0710C 8024070C 8E050000 */  lw        $a1, ($s0)
/* B07110 80240710 0C0B1EAF */  jal       get_variable
/* B07114 80240714 26100004 */   addiu    $s0, $s0, 4
/* B07118 80240718 0260202D */  daddu     $a0, $s3, $zero
/* B0711C 8024071C 8E050000 */  lw        $a1, ($s0)
/* B07120 80240720 0C0B1EAF */  jal       get_variable
/* B07124 80240724 0040902D */   daddu    $s2, $v0, $zero
/* B07128 80240728 2404003C */  addiu     $a0, $zero, 0x3c
/* B0712C 8024072C 0C00AB39 */  jal       heap_malloc
/* B07130 80240730 0040882D */   daddu    $s1, $v0, $zero
/* B07134 80240734 0040802D */  daddu     $s0, $v0, $zero
/* B07138 80240738 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* B0713C 8024073C 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* B07140 80240740 AE120008 */  sw        $s2, 8($s0)
/* B07144 80240744 AE11000C */  sw        $s1, 0xc($s0)
/* B07148 80240748 846200B0 */  lh        $v0, 0xb0($v1)
/* B0714C 8024074C 44820000 */  mtc1      $v0, $f0
/* B07150 80240750 00000000 */  nop       
/* B07154 80240754 46800020 */  cvt.s.w   $f0, $f0
/* B07158 80240758 E6000034 */  swc1      $f0, 0x34($s0)
/* B0715C 8024075C 846200B2 */  lh        $v0, 0xb2($v1)
/* B07160 80240760 44820000 */  mtc1      $v0, $f0
/* B07164 80240764 00000000 */  nop       
/* B07168 80240768 46800020 */  cvt.s.w   $f0, $f0
/* B0716C 8024076C E6000038 */  swc1      $f0, 0x38($s0)
/* B07170 80240770 C4600028 */  lwc1      $f0, 0x28($v1)
/* B07174 80240774 E6000010 */  swc1      $f0, 0x10($s0)
/* B07178 80240778 C460002C */  lwc1      $f0, 0x2c($v1)
/* B0717C 8024077C E6000014 */  swc1      $f0, 0x14($s0)
/* B07180 80240780 C4620030 */  lwc1      $f2, 0x30($v1)
/* B07184 80240784 3C013F36 */  lui       $at, 0x3f36
/* B07188 80240788 3421DB6E */  ori       $at, $at, 0xdb6e
/* B0718C 8024078C 44810000 */  mtc1      $at, $f0
/* B07190 80240790 24040001 */  addiu     $a0, $zero, 1
/* B07194 80240794 AE00001C */  sw        $zero, 0x1c($s0)
/* B07198 80240798 AE000020 */  sw        $zero, 0x20($s0)
/* B0719C 8024079C AE000024 */  sw        $zero, 0x24($s0)
/* B071A0 802407A0 E6000028 */  swc1      $f0, 0x28($s0)
/* B071A4 802407A4 E600002C */  swc1      $f0, 0x2c($s0)
/* B071A8 802407A8 E6000030 */  swc1      $f0, 0x30($s0)
/* B071AC 802407AC 0C04E9C1 */  jal       func_8013A704
/* B071B0 802407B0 E6020018 */   swc1     $f2, 0x18($s0)
/* B071B4 802407B4 0000202D */  daddu     $a0, $zero, $zero
/* B071B8 802407B8 3C058024 */  lui       $a1, %hi(func_80240310_B06D10)
/* B071BC 802407BC 24A50310 */  addiu     $a1, $a1, %lo(func_80240310_B06D10)
/* B071C0 802407C0 0C048C56 */  jal       bind_dynamic_entity_3
/* B071C4 802407C4 AE020000 */   sw       $v0, ($s0)
/* B071C8 802407C8 0260202D */  daddu     $a0, $s3, $zero
/* B071CC 802407CC 3C05FD05 */  lui       $a1, 0xfd05
/* B071D0 802407D0 34A50F8A */  ori       $a1, $a1, 0xf8a
/* B071D4 802407D4 0200302D */  daddu     $a2, $s0, $zero
/* B071D8 802407D8 0C0B2026 */  jal       set_variable
/* B071DC 802407DC AE020004 */   sw       $v0, 4($s0)
/* B071E0 802407E0 8FBF0020 */  lw        $ra, 0x20($sp)
/* B071E4 802407E4 8FB3001C */  lw        $s3, 0x1c($sp)
/* B071E8 802407E8 8FB20018 */  lw        $s2, 0x18($sp)
/* B071EC 802407EC 8FB10014 */  lw        $s1, 0x14($sp)
/* B071F0 802407F0 8FB00010 */  lw        $s0, 0x10($sp)
/* B071F4 802407F4 24020002 */  addiu     $v0, $zero, 2
/* B071F8 802407F8 03E00008 */  jr        $ra
/* B071FC 802407FC 27BD0028 */   addiu    $sp, $sp, 0x28
