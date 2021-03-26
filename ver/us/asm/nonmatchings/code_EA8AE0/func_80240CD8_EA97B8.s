.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CD8_EA97B8
/* EA97B8 80240CD8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EA97BC 80240CDC AFB10014 */  sw        $s1, 0x14($sp)
/* EA97C0 80240CE0 0080882D */  daddu     $s1, $a0, $zero
/* EA97C4 80240CE4 AFBF0020 */  sw        $ra, 0x20($sp)
/* EA97C8 80240CE8 AFB3001C */  sw        $s3, 0x1c($sp)
/* EA97CC 80240CEC AFB20018 */  sw        $s2, 0x18($sp)
/* EA97D0 80240CF0 AFB00010 */  sw        $s0, 0x10($sp)
/* EA97D4 80240CF4 8E30000C */  lw        $s0, 0xc($s1)
/* EA97D8 80240CF8 8E050000 */  lw        $a1, ($s0)
/* EA97DC 80240CFC 0C0B53A3 */  jal       dead_get_variable
/* EA97E0 80240D00 26100004 */   addiu    $s0, $s0, 4
/* EA97E4 80240D04 8E050000 */  lw        $a1, ($s0)
/* EA97E8 80240D08 26100004 */  addiu     $s0, $s0, 4
/* EA97EC 80240D0C 0220202D */  daddu     $a0, $s1, $zero
/* EA97F0 80240D10 0C0B53A3 */  jal       dead_get_variable
/* EA97F4 80240D14 0040982D */   daddu    $s3, $v0, $zero
/* EA97F8 80240D18 8E050000 */  lw        $a1, ($s0)
/* EA97FC 80240D1C 26100004 */  addiu     $s0, $s0, 4
/* EA9800 80240D20 0220202D */  daddu     $a0, $s1, $zero
/* EA9804 80240D24 0C0B53A3 */  jal       dead_get_variable
/* EA9808 80240D28 0040902D */   daddu    $s2, $v0, $zero
/* EA980C 80240D2C 8E050000 */  lw        $a1, ($s0)
/* EA9810 80240D30 26100004 */  addiu     $s0, $s0, 4
/* EA9814 80240D34 0C0B53A3 */  jal       dead_get_variable
/* EA9818 80240D38 0220202D */   daddu    $a0, $s1, $zero
/* EA981C 80240D3C 8E050000 */  lw        $a1, ($s0)
/* EA9820 80240D40 0C0B53A3 */  jal       dead_get_variable
/* EA9824 80240D44 0220202D */   daddu    $a0, $s1, $zero
/* EA9828 80240D48 0000202D */  daddu     $a0, $zero, $zero
/* EA982C 80240D4C 3C05FD05 */  lui       $a1, 0xfd05
/* EA9830 80240D50 34A50F80 */  ori       $a1, $a1, 0xf80
/* EA9834 80240D54 0C0B53A3 */  jal       dead_get_variable
/* EA9838 80240D58 0040802D */   daddu    $s0, $v0, $zero
/* EA983C 80240D5C 00131900 */  sll       $v1, $s3, 4
/* EA9840 80240D60 00731823 */  subu      $v1, $v1, $s3
/* EA9844 80240D64 00031940 */  sll       $v1, $v1, 5
/* EA9848 80240D68 00431821 */  addu      $v1, $v0, $v1
/* EA984C 80240D6C 24020002 */  addiu     $v0, $zero, 2
/* EA9850 80240D70 00529004 */  sllv      $s2, $s2, $v0
/* EA9854 80240D74 00721821 */  addu      $v1, $v1, $s2
/* EA9858 80240D78 44900000 */  mtc1      $s0, $f0
/* EA985C 80240D7C 00000000 */  nop
/* EA9860 80240D80 46800020 */  cvt.s.w   $f0, $f0
/* EA9864 80240D84 E460006C */  swc1      $f0, 0x6c($v1)
/* EA9868 80240D88 8FBF0020 */  lw        $ra, 0x20($sp)
/* EA986C 80240D8C 8FB3001C */  lw        $s3, 0x1c($sp)
/* EA9870 80240D90 8FB20018 */  lw        $s2, 0x18($sp)
/* EA9874 80240D94 8FB10014 */  lw        $s1, 0x14($sp)
/* EA9878 80240D98 8FB00010 */  lw        $s0, 0x10($sp)
/* EA987C 80240D9C 03E00008 */  jr        $ra
/* EA9880 80240DA0 27BD0028 */   addiu    $sp, $sp, 0x28
