.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406C4_E12E24
/* E12E24 802406C4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E12E28 802406C8 AFB1001C */  sw        $s1, 0x1c($sp)
/* E12E2C 802406CC 0080882D */  daddu     $s1, $a0, $zero
/* E12E30 802406D0 0000202D */  daddu     $a0, $zero, $zero
/* E12E34 802406D4 AFBF0020 */  sw        $ra, 0x20($sp)
/* E12E38 802406D8 0C00FB3A */  jal       get_enemy
/* E12E3C 802406DC AFB00018 */   sw       $s0, 0x18($sp)
/* E12E40 802406E0 8E23000C */  lw        $v1, 0xc($s1)
/* E12E44 802406E4 8C650000 */  lw        $a1, ($v1)
/* E12E48 802406E8 8C500080 */  lw        $s0, 0x80($v0)
/* E12E4C 802406EC 0C0B1EAF */  jal       get_variable
/* E12E50 802406F0 0220202D */   daddu    $a0, $s1, $zero
/* E12E54 802406F4 00021840 */  sll       $v1, $v0, 1
/* E12E58 802406F8 00621821 */  addu      $v1, $v1, $v0
/* E12E5C 802406FC 000318C0 */  sll       $v1, $v1, 3
/* E12E60 80240700 00621823 */  subu      $v1, $v1, $v0
/* E12E64 80240704 00031880 */  sll       $v1, $v1, 2
/* E12E68 80240708 02038021 */  addu      $s0, $s0, $v1
/* E12E6C 8024070C 8E020090 */  lw        $v0, 0x90($s0)
/* E12E70 80240710 AFA20010 */  sw        $v0, 0x10($sp)
/* E12E74 80240714 8E0500A0 */  lw        $a1, 0xa0($s0)
/* E12E78 80240718 8E0600AC */  lw        $a2, 0xac($s0)
/* E12E7C 8024071C 8E07008C */  lw        $a3, 0x8c($s0)
/* E12E80 80240720 0C00A8ED */  jal       update_lerp
/* E12E84 80240724 24040004 */   addiu    $a0, $zero, 4
/* E12E88 80240728 8E020090 */  lw        $v0, 0x90($s0)
/* E12E8C 8024072C E6000094 */  swc1      $f0, 0x94($s0)
/* E12E90 80240730 AFA20010 */  sw        $v0, 0x10($sp)
/* E12E94 80240734 8E0500A4 */  lw        $a1, 0xa4($s0)
/* E12E98 80240738 8E0600B0 */  lw        $a2, 0xb0($s0)
/* E12E9C 8024073C 8E07008C */  lw        $a3, 0x8c($s0)
/* E12EA0 80240740 0C00A8ED */  jal       update_lerp
/* E12EA4 80240744 24040004 */   addiu    $a0, $zero, 4
/* E12EA8 80240748 8E020090 */  lw        $v0, 0x90($s0)
/* E12EAC 8024074C E6000098 */  swc1      $f0, 0x98($s0)
/* E12EB0 80240750 AFA20010 */  sw        $v0, 0x10($sp)
/* E12EB4 80240754 8E0500A8 */  lw        $a1, 0xa8($s0)
/* E12EB8 80240758 8E0600B4 */  lw        $a2, 0xb4($s0)
/* E12EBC 8024075C 8E07008C */  lw        $a3, 0x8c($s0)
/* E12EC0 80240760 0C00A8ED */  jal       update_lerp
/* E12EC4 80240764 24040004 */   addiu    $a0, $zero, 4
/* E12EC8 80240768 8E020090 */  lw        $v0, 0x90($s0)
/* E12ECC 8024076C E600009C */  swc1      $f0, 0x9c($s0)
/* E12ED0 80240770 AFA20010 */  sw        $v0, 0x10($sp)
/* E12ED4 80240774 8E0500C8 */  lw        $a1, 0xc8($s0)
/* E12ED8 80240778 8E0600CC */  lw        $a2, 0xcc($s0)
/* E12EDC 8024077C 8E07008C */  lw        $a3, 0x8c($s0)
/* E12EE0 80240780 0C00A8ED */  jal       update_lerp
/* E12EE4 80240784 0000202D */   daddu    $a0, $zero, $zero
/* E12EE8 80240788 8E02008C */  lw        $v0, 0x8c($s0)
/* E12EEC 8024078C 8E030090 */  lw        $v1, 0x90($s0)
/* E12EF0 80240790 E60000C4 */  swc1      $f0, 0xc4($s0)
/* E12EF4 80240794 24420001 */  addiu     $v0, $v0, 1
/* E12EF8 80240798 AE02008C */  sw        $v0, 0x8c($s0)
/* E12EFC 8024079C 0043102A */  slt       $v0, $v0, $v1
/* E12F00 802407A0 14400005 */  bnez      $v0, .L802407B8
/* E12F04 802407A4 0220202D */   daddu    $a0, $s1, $zero
/* E12F08 802407A8 3C05FE36 */  lui       $a1, 0xfe36
/* E12F0C 802407AC 34A53C83 */  ori       $a1, $a1, 0x3c83
/* E12F10 802407B0 080901F1 */  j         .L802407C4
/* E12F14 802407B4 24060001 */   addiu    $a2, $zero, 1
.L802407B8:
/* E12F18 802407B8 3C05FE36 */  lui       $a1, 0xfe36
/* E12F1C 802407BC 34A53C83 */  ori       $a1, $a1, 0x3c83
/* E12F20 802407C0 0000302D */  daddu     $a2, $zero, $zero
.L802407C4:
/* E12F24 802407C4 0C0B2026 */  jal       set_variable
/* E12F28 802407C8 00000000 */   nop      
/* E12F2C 802407CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* E12F30 802407D0 8FB1001C */  lw        $s1, 0x1c($sp)
/* E12F34 802407D4 8FB00018 */  lw        $s0, 0x18($sp)
/* E12F38 802407D8 24020002 */  addiu     $v0, $zero, 2
/* E12F3C 802407DC 03E00008 */  jr        $ra
/* E12F40 802407E0 27BD0028 */   addiu    $sp, $sp, 0x28
