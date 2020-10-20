.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C74
/* 8657B4 80240C74 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 8657B8 80240C78 AFB10034 */  sw        $s1, 0x34($sp)
/* 8657BC 80240C7C 0080882D */  daddu     $s1, $a0, $zero
/* 8657C0 80240C80 AFBF003C */  sw        $ra, 0x3c($sp)
/* 8657C4 80240C84 AFB20038 */  sw        $s2, 0x38($sp)
/* 8657C8 80240C88 AFB00030 */  sw        $s0, 0x30($sp)
/* 8657CC 80240C8C F7BE0068 */  sdc1      $f30, 0x68($sp)
/* 8657D0 80240C90 F7BC0060 */  sdc1      $f28, 0x60($sp)
/* 8657D4 80240C94 F7BA0058 */  sdc1      $f26, 0x58($sp)
/* 8657D8 80240C98 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 8657DC 80240C9C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 8657E0 80240CA0 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 8657E4 80240CA4 8E30000C */  lw        $s0, 0xc($s1)
/* 8657E8 80240CA8 8E050000 */  lw        $a1, ($s0)
/* 8657EC 80240CAC 0C0B1EAF */  jal       get_variable
/* 8657F0 80240CB0 26100004 */   addiu    $s0, $s0, 4
/* 8657F4 80240CB4 8E050000 */  lw        $a1, ($s0)
/* 8657F8 80240CB8 26100004 */  addiu     $s0, $s0, 4
/* 8657FC 80240CBC 0220202D */  daddu     $a0, $s1, $zero
/* 865800 80240CC0 0C0B210B */  jal       get_float_variable
/* 865804 80240CC4 0040902D */   daddu    $s2, $v0, $zero
/* 865808 80240CC8 8E050000 */  lw        $a1, ($s0)
/* 86580C 80240CCC 26100004 */  addiu     $s0, $s0, 4
/* 865810 80240CD0 0220202D */  daddu     $a0, $s1, $zero
/* 865814 80240CD4 0C0B210B */  jal       get_float_variable
/* 865818 80240CD8 46000706 */   mov.s    $f28, $f0
/* 86581C 80240CDC 8E050000 */  lw        $a1, ($s0)
/* 865820 80240CE0 26100004 */  addiu     $s0, $s0, 4
/* 865824 80240CE4 0220202D */  daddu     $a0, $s1, $zero
/* 865828 80240CE8 0C0B210B */  jal       get_float_variable
/* 86582C 80240CEC 46000786 */   mov.s    $f30, $f0
/* 865830 80240CF0 8E050000 */  lw        $a1, ($s0)
/* 865834 80240CF4 26100004 */  addiu     $s0, $s0, 4
/* 865838 80240CF8 0220202D */  daddu     $a0, $s1, $zero
/* 86583C 80240CFC 0C0B210B */  jal       get_float_variable
/* 865840 80240D00 46000686 */   mov.s    $f26, $f0
/* 865844 80240D04 8E050000 */  lw        $a1, ($s0)
/* 865848 80240D08 26100004 */  addiu     $s0, $s0, 4
/* 86584C 80240D0C 0220202D */  daddu     $a0, $s1, $zero
/* 865850 80240D10 0C0B210B */  jal       get_float_variable
/* 865854 80240D14 46000606 */   mov.s    $f24, $f0
/* 865858 80240D18 8E050000 */  lw        $a1, ($s0)
/* 86585C 80240D1C 26100004 */  addiu     $s0, $s0, 4
/* 865860 80240D20 0220202D */  daddu     $a0, $s1, $zero
/* 865864 80240D24 0C0B210B */  jal       get_float_variable
/* 865868 80240D28 46000586 */   mov.s    $f22, $f0
/* 86586C 80240D2C 0220202D */  daddu     $a0, $s1, $zero
/* 865870 80240D30 8E050000 */  lw        $a1, ($s0)
/* 865874 80240D34 0C0B1EAF */  jal       get_variable
/* 865878 80240D38 46000506 */   mov.s    $f20, $f0
/* 86587C 80240D3C 4405E000 */  mfc1      $a1, $f28
/* 865880 80240D40 4406F000 */  mfc1      $a2, $f30
/* 865884 80240D44 4407D000 */  mfc1      $a3, $f26
/* 865888 80240D48 0240202D */  daddu     $a0, $s2, $zero
/* 86588C 80240D4C AFA2001C */  sw        $v0, 0x1c($sp)
/* 865890 80240D50 27A20028 */  addiu     $v0, $sp, 0x28
/* 865894 80240D54 E7B80010 */  swc1      $f24, 0x10($sp)
/* 865898 80240D58 E7B60014 */  swc1      $f22, 0x14($sp)
/* 86589C 80240D5C E7B40018 */  swc1      $f20, 0x18($sp)
/* 8658A0 80240D60 0C01C3DC */  jal       func_80070F70
/* 8658A4 80240D64 AFA20020 */   sw       $v0, 0x20($sp)
/* 8658A8 80240D68 8FA30028 */  lw        $v1, 0x28($sp)
/* 8658AC 80240D6C AE230084 */  sw        $v1, 0x84($s1)
/* 8658B0 80240D70 8FBF003C */  lw        $ra, 0x3c($sp)
/* 8658B4 80240D74 8FB20038 */  lw        $s2, 0x38($sp)
/* 8658B8 80240D78 8FB10034 */  lw        $s1, 0x34($sp)
/* 8658BC 80240D7C 8FB00030 */  lw        $s0, 0x30($sp)
/* 8658C0 80240D80 D7BE0068 */  ldc1      $f30, 0x68($sp)
/* 8658C4 80240D84 D7BC0060 */  ldc1      $f28, 0x60($sp)
/* 8658C8 80240D88 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* 8658CC 80240D8C D7B80050 */  ldc1      $f24, 0x50($sp)
/* 8658D0 80240D90 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 8658D4 80240D94 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 8658D8 80240D98 24020002 */  addiu     $v0, $zero, 2
/* 8658DC 80240D9C 03E00008 */  jr        $ra
/* 8658E0 80240DA0 27BD0070 */   addiu    $sp, $sp, 0x70
