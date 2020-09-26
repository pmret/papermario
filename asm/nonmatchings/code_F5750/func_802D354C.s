.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D354C
/* F7EFC 802D354C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* F7F00 802D3550 AFB20018 */  sw        $s2, 0x18($sp)
/* F7F04 802D3554 0080902D */  daddu     $s2, $a0, $zero
/* F7F08 802D3558 AFBF0020 */  sw        $ra, 0x20($sp)
/* F7F0C 802D355C AFB3001C */  sw        $s3, 0x1c($sp)
/* F7F10 802D3560 AFB10014 */  sw        $s1, 0x14($sp)
/* F7F14 802D3564 AFB00010 */  sw        $s0, 0x10($sp)
/* F7F18 802D3568 8E42000C */  lw        $v0, 0xc($s2)
/* F7F1C 802D356C 8C450004 */  lw        $a1, 4($v0)
/* F7F20 802D3570 8C530000 */  lw        $s3, ($v0)
/* F7F24 802D3574 0C0B1EAF */  jal       get_variable
/* F7F28 802D3578 0000882D */   daddu    $s1, $zero, $zero
/* F7F2C 802D357C 0040202D */  daddu     $a0, $v0, $zero
/* F7F30 802D3580 3C03802E */  lui       $v1, 0x802e
/* F7F34 802D3584 8C63B7C0 */  lw        $v1, -0x4840($v1)
.L802D3588:
/* F7F38 802D3588 8C700000 */  lw        $s0, ($v1)
/* F7F3C 802D358C 8E020000 */  lw        $v0, ($s0)
/* F7F40 802D3590 04400006 */  bltz      $v0, .L802D35AC
/* F7F44 802D3594 2A220040 */   slti     $v0, $s1, 0x40
/* F7F48 802D3598 26310001 */  addiu     $s1, $s1, 1
/* F7F4C 802D359C 2A220040 */  slti      $v0, $s1, 0x40
/* F7F50 802D35A0 1440FFF9 */  bnez      $v0, .L802D3588
/* F7F54 802D35A4 24630004 */   addiu    $v1, $v1, 4
/* F7F58 802D35A8 2A220040 */  slti      $v0, $s1, 0x40
.L802D35AC:
/* F7F5C 802D35AC 10400016 */  beqz      $v0, .L802D3608
/* F7F60 802D35B0 24020002 */   addiu    $v0, $zero, 2
/* F7F64 802D35B4 0C048379 */  jal       func_80120DE4
/* F7F68 802D35B8 00000000 */   nop      
/* F7F6C 802D35BC 3C013F80 */  lui       $at, 0x3f80
/* F7F70 802D35C0 44810000 */  mtc1      $at, $f0
/* F7F74 802D35C4 AE020000 */  sw        $v0, ($s0)
/* F7F78 802D35C8 0040202D */  daddu     $a0, $v0, $zero
/* F7F7C 802D35CC AE000004 */  sw        $zero, 4($s0)
/* F7F80 802D35D0 AE000008 */  sw        $zero, 8($s0)
/* F7F84 802D35D4 AE00000C */  sw        $zero, 0xc($s0)
/* F7F88 802D35D8 AE000010 */  sw        $zero, 0x10($s0)
/* F7F8C 802D35DC AE000014 */  sw        $zero, 0x14($s0)
/* F7F90 802D35E0 AE000018 */  sw        $zero, 0x18($s0)
/* F7F94 802D35E4 E600001C */  swc1      $f0, 0x1c($s0)
/* F7F98 802D35E8 E6000020 */  swc1      $f0, 0x20($s0)
/* F7F9C 802D35EC 0C0483C1 */  jal       func_80120F04
/* F7FA0 802D35F0 E6000024 */   swc1     $f0, 0x24($s0)
/* F7FA4 802D35F4 0240202D */  daddu     $a0, $s2, $zero
/* F7FA8 802D35F8 0260282D */  daddu     $a1, $s3, $zero
/* F7FAC 802D35FC 0C0B2026 */  jal       set_variable
/* F7FB0 802D3600 0220302D */   daddu    $a2, $s1, $zero
/* F7FB4 802D3604 24020002 */  addiu     $v0, $zero, 2
.L802D3608:
/* F7FB8 802D3608 8FBF0020 */  lw        $ra, 0x20($sp)
/* F7FBC 802D360C 8FB3001C */  lw        $s3, 0x1c($sp)
/* F7FC0 802D3610 8FB20018 */  lw        $s2, 0x18($sp)
/* F7FC4 802D3614 8FB10014 */  lw        $s1, 0x14($sp)
/* F7FC8 802D3618 8FB00010 */  lw        $s0, 0x10($sp)
/* F7FCC 802D361C 03E00008 */  jr        $ra
/* F7FD0 802D3620 27BD0028 */   addiu    $sp, $sp, 0x28
