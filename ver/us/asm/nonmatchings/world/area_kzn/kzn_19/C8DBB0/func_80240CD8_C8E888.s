.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CD8_C8E888
/* C8E888 80240CD8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C8E88C 80240CDC AFB10014 */  sw        $s1, 0x14($sp)
/* C8E890 80240CE0 0080882D */  daddu     $s1, $a0, $zero
/* C8E894 80240CE4 AFBF0020 */  sw        $ra, 0x20($sp)
/* C8E898 80240CE8 AFB3001C */  sw        $s3, 0x1c($sp)
/* C8E89C 80240CEC AFB20018 */  sw        $s2, 0x18($sp)
/* C8E8A0 80240CF0 AFB00010 */  sw        $s0, 0x10($sp)
/* C8E8A4 80240CF4 8E30000C */  lw        $s0, 0xc($s1)
/* C8E8A8 80240CF8 8E050000 */  lw        $a1, ($s0)
/* C8E8AC 80240CFC 0C0B1EAF */  jal       evt_get_variable
/* C8E8B0 80240D00 26100004 */   addiu    $s0, $s0, 4
/* C8E8B4 80240D04 8E050000 */  lw        $a1, ($s0)
/* C8E8B8 80240D08 26100004 */  addiu     $s0, $s0, 4
/* C8E8BC 80240D0C 0220202D */  daddu     $a0, $s1, $zero
/* C8E8C0 80240D10 0C0B1EAF */  jal       evt_get_variable
/* C8E8C4 80240D14 0040982D */   daddu    $s3, $v0, $zero
/* C8E8C8 80240D18 8E050000 */  lw        $a1, ($s0)
/* C8E8CC 80240D1C 26100004 */  addiu     $s0, $s0, 4
/* C8E8D0 80240D20 0220202D */  daddu     $a0, $s1, $zero
/* C8E8D4 80240D24 0C0B1EAF */  jal       evt_get_variable
/* C8E8D8 80240D28 0040902D */   daddu    $s2, $v0, $zero
/* C8E8DC 80240D2C 8E050000 */  lw        $a1, ($s0)
/* C8E8E0 80240D30 26100004 */  addiu     $s0, $s0, 4
/* C8E8E4 80240D34 0C0B1EAF */  jal       evt_get_variable
/* C8E8E8 80240D38 0220202D */   daddu    $a0, $s1, $zero
/* C8E8EC 80240D3C 8E050000 */  lw        $a1, ($s0)
/* C8E8F0 80240D40 0C0B1EAF */  jal       evt_get_variable
/* C8E8F4 80240D44 0220202D */   daddu    $a0, $s1, $zero
/* C8E8F8 80240D48 0000202D */  daddu     $a0, $zero, $zero
/* C8E8FC 80240D4C 3C05FD05 */  lui       $a1, 0xfd05
/* C8E900 80240D50 34A50F80 */  ori       $a1, $a1, 0xf80
/* C8E904 80240D54 0C0B1EAF */  jal       evt_get_variable
/* C8E908 80240D58 0040802D */   daddu    $s0, $v0, $zero
/* C8E90C 80240D5C 00131900 */  sll       $v1, $s3, 4
/* C8E910 80240D60 00731823 */  subu      $v1, $v1, $s3
/* C8E914 80240D64 00031940 */  sll       $v1, $v1, 5
/* C8E918 80240D68 00431821 */  addu      $v1, $v0, $v1
/* C8E91C 80240D6C 24020002 */  addiu     $v0, $zero, 2
/* C8E920 80240D70 00529004 */  sllv      $s2, $s2, $v0
/* C8E924 80240D74 00721821 */  addu      $v1, $v1, $s2
/* C8E928 80240D78 44900000 */  mtc1      $s0, $f0
/* C8E92C 80240D7C 00000000 */  nop
/* C8E930 80240D80 46800020 */  cvt.s.w   $f0, $f0
/* C8E934 80240D84 E460006C */  swc1      $f0, 0x6c($v1)
/* C8E938 80240D88 8FBF0020 */  lw        $ra, 0x20($sp)
/* C8E93C 80240D8C 8FB3001C */  lw        $s3, 0x1c($sp)
/* C8E940 80240D90 8FB20018 */  lw        $s2, 0x18($sp)
/* C8E944 80240D94 8FB10014 */  lw        $s1, 0x14($sp)
/* C8E948 80240D98 8FB00010 */  lw        $s0, 0x10($sp)
/* C8E94C 80240D9C 03E00008 */  jr        $ra
/* C8E950 80240DA0 27BD0028 */   addiu    $sp, $sp, 0x28
