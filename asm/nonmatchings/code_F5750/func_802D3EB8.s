.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D3EB8
/* F8868 802D3EB8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F886C 802D3EBC AFB00010 */  sw        $s0, 0x10($sp)
/* F8870 802D3EC0 0080802D */  daddu     $s0, $a0, $zero
/* F8874 802D3EC4 AFBF0014 */  sw        $ra, 0x14($sp)
/* F8878 802D3EC8 8E03000C */  lw        $v1, 0xc($s0)
/* F887C 802D3ECC 54A00001 */  bnel      $a1, $zero, .L802D3ED4
/* F8880 802D3ED0 AE000070 */   sw       $zero, 0x70($s0)
.L802D3ED4:
/* F8884 802D3ED4 8E020070 */  lw        $v0, 0x70($s0)
/* F8888 802D3ED8 14400007 */  bnez      $v0, .L802D3EF8
/* F888C 802D3EDC 00000000 */   nop      
/* F8890 802D3EE0 8C650000 */  lw        $a1, ($v1)
/* F8894 802D3EE4 0C0B1EAF */  jal       get_variable
/* F8898 802D3EE8 0200202D */   daddu    $a0, $s0, $zero
/* F889C 802D3EEC AE020074 */  sw        $v0, 0x74($s0)
/* F88A0 802D3EF0 24020001 */  addiu     $v0, $zero, 1
/* F88A4 802D3EF4 AE020070 */  sw        $v0, 0x70($s0)
.L802D3EF8:
/* F88A8 802D3EF8 8E020074 */  lw        $v0, 0x74($s0)
/* F88AC 802D3EFC 3C03802E */  lui       $v1, 0x802e
/* F88B0 802D3F00 8C63B7C0 */  lw        $v1, -0x4840($v1)
/* F88B4 802D3F04 00021080 */  sll       $v0, $v0, 2
/* F88B8 802D3F08 00431021 */  addu      $v0, $v0, $v1
/* F88BC 802D3F0C 8C500000 */  lw        $s0, ($v0)
/* F88C0 802D3F10 C6040008 */  lwc1      $f4, 8($s0)
/* F88C4 802D3F14 C6000044 */  lwc1      $f0, 0x44($s0)
/* F88C8 802D3F18 C6020040 */  lwc1      $f2, 0x40($s0)
/* F88CC 802D3F1C 46002100 */  add.s     $f4, $f4, $f0
/* F88D0 802D3F20 8E05003C */  lw        $a1, 0x3c($s0)
/* F88D4 802D3F24 8E060038 */  lw        $a2, 0x38($s0)
/* F88D8 802D3F28 46020001 */  sub.s     $f0, $f0, $f2
/* F88DC 802D3F2C 0200202D */  daddu     $a0, $s0, $zero
/* F88E0 802D3F30 E6040008 */  swc1      $f4, 8($s0)
/* F88E4 802D3F34 0C0B4BCD */  jal       func_802D2F34
/* F88E8 802D3F38 E6000044 */   swc1     $f0, 0x44($s0)
/* F88EC 802D3F3C C6000008 */  lwc1      $f0, 8($s0)
/* F88F0 802D3F40 44801000 */  mtc1      $zero, $f2
/* F88F4 802D3F44 00000000 */  nop       
/* F88F8 802D3F48 4602003C */  c.lt.s    $f0, $f2
/* F88FC 802D3F4C 00000000 */  nop       
/* F8900 802D3F50 45030003 */  bc1tl     .L802D3F60
/* F8904 802D3F54 E6020008 */   swc1     $f2, 8($s0)
/* F8908 802D3F58 080B4FD9 */  j         .L802D3F64
/* F890C 802D3F5C 0000102D */   daddu    $v0, $zero, $zero
.L802D3F60:
/* F8910 802D3F60 24020001 */  addiu     $v0, $zero, 1
.L802D3F64:
/* F8914 802D3F64 8FBF0014 */  lw        $ra, 0x14($sp)
/* F8918 802D3F68 8FB00010 */  lw        $s0, 0x10($sp)
/* F891C 802D3F6C 03E00008 */  jr        $ra
/* F8920 802D3F70 27BD0018 */   addiu    $sp, $sp, 0x18
