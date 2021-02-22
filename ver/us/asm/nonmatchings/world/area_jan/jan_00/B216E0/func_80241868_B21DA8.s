.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241868_B21DA8
/* B21DA8 80241868 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* B21DAC 8024186C AFB10014 */  sw        $s1, 0x14($sp)
/* B21DB0 80241870 0080882D */  daddu     $s1, $a0, $zero
/* B21DB4 80241874 AFBF0018 */  sw        $ra, 0x18($sp)
/* B21DB8 80241878 AFB00010 */  sw        $s0, 0x10($sp)
/* B21DBC 8024187C F7B80030 */  sdc1      $f24, 0x30($sp)
/* B21DC0 80241880 F7B60028 */  sdc1      $f22, 0x28($sp)
/* B21DC4 80241884 F7B40020 */  sdc1      $f20, 0x20($sp)
/* B21DC8 80241888 0C00EAD2 */  jal       get_npc_safe
/* B21DCC 8024188C 0000202D */   daddu    $a0, $zero, $zero
/* B21DD0 80241890 0040802D */  daddu     $s0, $v0, $zero
/* B21DD4 80241894 C614000C */  lwc1      $f20, 0xc($s0)
/* B21DD8 80241898 3C01432A */  lui       $at, 0x432a
/* B21DDC 8024189C 4481C000 */  mtc1      $at, $f24
/* B21DE0 802418A0 4600A507 */  neg.s     $f20, $f20
/* B21DE4 802418A4 0C00A8BB */  jal       sin_deg
/* B21DE8 802418A8 4600A306 */   mov.s    $f12, $f20
/* B21DEC 802418AC 46180002 */  mul.s     $f0, $f0, $f24
/* B21DF0 802418B0 00000000 */  nop
/* B21DF4 802418B4 C6160038 */  lwc1      $f22, 0x38($s0)
/* B21DF8 802418B8 3C0141F0 */  lui       $at, 0x41f0
/* B21DFC 802418BC 44811000 */  mtc1      $at, $f2
/* B21E00 802418C0 00000000 */  nop
/* B21E04 802418C4 4602B580 */  add.s     $f22, $f22, $f2
/* B21E08 802418C8 4600A306 */  mov.s     $f12, $f20
/* B21E0C 802418CC 0C00A8D4 */  jal       cos_deg
/* B21E10 802418D0 4600B580 */   add.s    $f22, $f22, $f0
/* B21E14 802418D4 0220202D */  daddu     $a0, $s1, $zero
/* B21E18 802418D8 46180002 */  mul.s     $f0, $f0, $f24
/* B21E1C 802418DC 00000000 */  nop
/* B21E20 802418E0 3C05FE36 */  lui       $a1, 0xfe36
/* B21E24 802418E4 34A53C80 */  ori       $a1, $a1, 0x3c80
/* B21E28 802418E8 C6180040 */  lwc1      $f24, 0x40($s0)
/* B21E2C 802418EC C614003C */  lwc1      $f20, 0x3c($s0)
/* B21E30 802418F0 4600C600 */  add.s     $f24, $f24, $f0
/* B21E34 802418F4 3C014248 */  lui       $at, 0x4248
/* B21E38 802418F8 44810000 */  mtc1      $at, $f0
/* B21E3C 802418FC 4406B000 */  mfc1      $a2, $f22
/* B21E40 80241900 0C0B2190 */  jal       set_float_variable
/* B21E44 80241904 4600A500 */   add.s    $f20, $f20, $f0
/* B21E48 80241908 0220202D */  daddu     $a0, $s1, $zero
/* B21E4C 8024190C 3C05FE36 */  lui       $a1, 0xfe36
/* B21E50 80241910 4406A000 */  mfc1      $a2, $f20
/* B21E54 80241914 0C0B2190 */  jal       set_float_variable
/* B21E58 80241918 34A53C81 */   ori      $a1, $a1, 0x3c81
/* B21E5C 8024191C 0220202D */  daddu     $a0, $s1, $zero
/* B21E60 80241920 3C05FE36 */  lui       $a1, 0xfe36
/* B21E64 80241924 4406C000 */  mfc1      $a2, $f24
/* B21E68 80241928 0C0B2190 */  jal       set_float_variable
/* B21E6C 8024192C 34A53C82 */   ori      $a1, $a1, 0x3c82
/* B21E70 80241930 8FBF0018 */  lw        $ra, 0x18($sp)
/* B21E74 80241934 8FB10014 */  lw        $s1, 0x14($sp)
/* B21E78 80241938 8FB00010 */  lw        $s0, 0x10($sp)
/* B21E7C 8024193C D7B80030 */  ldc1      $f24, 0x30($sp)
/* B21E80 80241940 D7B60028 */  ldc1      $f22, 0x28($sp)
/* B21E84 80241944 D7B40020 */  ldc1      $f20, 0x20($sp)
/* B21E88 80241948 24020002 */  addiu     $v0, $zero, 2
/* B21E8C 8024194C 03E00008 */  jr        $ra
/* B21E90 80241950 27BD0038 */   addiu    $sp, $sp, 0x38
/* B21E94 80241954 00000000 */  nop
/* B21E98 80241958 00000000 */  nop
/* B21E9C 8024195C 00000000 */  nop
