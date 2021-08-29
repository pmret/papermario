.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405FC_9C2F0C
/* 9C2F0C 802405FC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9C2F10 80240600 AFB20020 */  sw        $s2, 0x20($sp)
/* 9C2F14 80240604 0080902D */  daddu     $s2, $a0, $zero
/* 9C2F18 80240608 AFBF0024 */  sw        $ra, 0x24($sp)
/* 9C2F1C 8024060C AFB1001C */  sw        $s1, 0x1c($sp)
/* 9C2F20 80240610 AFB00018 */  sw        $s0, 0x18($sp)
/* 9C2F24 80240614 10A00035 */  beqz      $a1, .L802406EC
/* 9C2F28 80240618 8E51000C */   lw       $s1, 0xc($s2)
/* 9C2F2C 8024061C 0C00AB39 */  jal       heap_malloc
/* 9C2F30 80240620 24040058 */   addiu    $a0, $zero, 0x58
/* 9C2F34 80240624 0040802D */  daddu     $s0, $v0, $zero
/* 9C2F38 80240628 AE500084 */  sw        $s0, 0x84($s2)
/* 9C2F3C 8024062C 8E250000 */  lw        $a1, ($s1)
/* 9C2F40 80240630 26310004 */  addiu     $s1, $s1, 4
/* 9C2F44 80240634 0C0B1EAF */  jal       get_variable
/* 9C2F48 80240638 0240202D */   daddu    $a0, $s2, $zero
/* 9C2F4C 8024063C AE020038 */  sw        $v0, 0x38($s0)
/* 9C2F50 80240640 8E250000 */  lw        $a1, ($s1)
/* 9C2F54 80240644 26310004 */  addiu     $s1, $s1, 4
/* 9C2F58 80240648 0C0B210B */  jal       evt_get_float_variable
/* 9C2F5C 8024064C 0240202D */   daddu    $a0, $s2, $zero
/* 9C2F60 80240650 E6000018 */  swc1      $f0, 0x18($s0)
/* 9C2F64 80240654 8E250000 */  lw        $a1, ($s1)
/* 9C2F68 80240658 26310004 */  addiu     $s1, $s1, 4
/* 9C2F6C 8024065C 0C0B210B */  jal       evt_get_float_variable
/* 9C2F70 80240660 0240202D */   daddu    $a0, $s2, $zero
/* 9C2F74 80240664 E6000024 */  swc1      $f0, 0x24($s0)
/* 9C2F78 80240668 8E250000 */  lw        $a1, ($s1)
/* 9C2F7C 8024066C 26310004 */  addiu     $s1, $s1, 4
/* 9C2F80 80240670 0C0B210B */  jal       evt_get_float_variable
/* 9C2F84 80240674 0240202D */   daddu    $a0, $s2, $zero
/* 9C2F88 80240678 E6000020 */  swc1      $f0, 0x20($s0)
/* 9C2F8C 8024067C 8E250000 */  lw        $a1, ($s1)
/* 9C2F90 80240680 0C0B210B */  jal       evt_get_float_variable
/* 9C2F94 80240684 0240202D */   daddu    $a0, $s2, $zero
/* 9C2F98 80240688 3C013F80 */  lui       $at, 0x3f80
/* 9C2F9C 8024068C 44811000 */  mtc1      $at, $f2
/* 9C2FA0 80240690 E6000028 */  swc1      $f0, 0x28($s0)
/* 9C2FA4 80240694 AFA00014 */  sw        $zero, 0x14($sp)
/* 9C2FA8 80240698 E7A20010 */  swc1      $f2, 0x10($sp)
/* 9C2FAC 8024069C 8E050018 */  lw        $a1, 0x18($s0)
/* 9C2FB0 802406A0 8E060024 */  lw        $a2, 0x24($s0)
/* 9C2FB4 802406A4 8E070020 */  lw        $a3, 0x20($s0)
/* 9C2FB8 802406A8 0C01C9AC */  jal       playFX_7B
/* 9C2FBC 802406AC 24040001 */   addiu    $a0, $zero, 1
/* 9C2FC0 802406B0 AE020054 */  sw        $v0, 0x54($s0)
/* 9C2FC4 802406B4 8C43000C */  lw        $v1, 0xc($v0)
/* 9C2FC8 802406B8 9202003B */  lbu       $v0, 0x3b($s0)
/* 9C2FCC 802406BC A0620034 */  sb        $v0, 0x34($v1)
/* 9C2FD0 802406C0 8E020054 */  lw        $v0, 0x54($s0)
/* 9C2FD4 802406C4 8C42000C */  lw        $v0, 0xc($v0)
/* 9C2FD8 802406C8 AC400020 */  sw        $zero, 0x20($v0)
/* 9C2FDC 802406CC 8E050018 */  lw        $a1, 0x18($s0)
/* 9C2FE0 802406D0 8E060028 */  lw        $a2, 0x28($s0)
/* 9C2FE4 802406D4 8E070020 */  lw        $a3, 0x20($s0)
/* 9C2FE8 802406D8 0C044898 */  jal       create_shadow_type
/* 9C2FEC 802406DC 0000202D */   daddu    $a0, $zero, $zero
/* 9C2FF0 802406E0 AE020040 */  sw        $v0, 0x40($s0)
/* 9C2FF4 802406E4 2402010E */  addiu     $v0, $zero, 0x10e
/* 9C2FF8 802406E8 A602004C */  sh        $v0, 0x4c($s0)
.L802406EC:
/* 9C2FFC 802406EC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 9C3000 802406F0 8FB20020 */  lw        $s2, 0x20($sp)
/* 9C3004 802406F4 8FB1001C */  lw        $s1, 0x1c($sp)
/* 9C3008 802406F8 8FB00018 */  lw        $s0, 0x18($sp)
/* 9C300C 802406FC 24020002 */  addiu     $v0, $zero, 2
/* 9C3010 80240700 03E00008 */  jr        $ra
/* 9C3014 80240704 27BD0028 */   addiu    $sp, $sp, 0x28
