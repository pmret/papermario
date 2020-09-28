.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel collision_check_above
/* 77C94 800DE7E4 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 77C98 800DE7E8 F7B40048 */  sdc1      $f20, 0x48($sp)
/* 77C9C 800DE7EC C7B40084 */  lwc1      $f20, 0x84($sp)
/* 77CA0 800DE7F0 3C0140C9 */  lui       $at, 0x40c9
/* 77CA4 800DE7F4 34210FD0 */  ori       $at, $at, 0xfd0
/* 77CA8 800DE7F8 44810000 */  mtc1      $at, $f0
/* 77CAC 800DE7FC AFB60038 */  sw        $s6, 0x38($sp)
/* 77CB0 800DE800 00A0B02D */  daddu     $s6, $a1, $zero
/* 77CB4 800DE804 AFB7003C */  sw        $s7, 0x3c($sp)
/* 77CB8 800DE808 00C0B82D */  daddu     $s7, $a2, $zero
/* 77CBC 800DE80C AFBE0040 */  sw        $fp, 0x40($sp)
/* 77CC0 800DE810 00E0F02D */  daddu     $fp, $a3, $zero
/* 77CC4 800DE814 AFB40030 */  sw        $s4, 0x30($sp)
/* 77CC8 800DE818 2414FFFF */  addiu     $s4, $zero, -1
/* 77CCC 800DE81C AFBF0044 */  sw        $ra, 0x44($sp)
/* 77CD0 800DE820 AFB50034 */  sw        $s5, 0x34($sp)
/* 77CD4 800DE824 AFB3002C */  sw        $s3, 0x2c($sp)
/* 77CD8 800DE828 AFB20028 */  sw        $s2, 0x28($sp)
/* 77CDC 800DE82C AFB10024 */  sw        $s1, 0x24($sp)
/* 77CE0 800DE830 AFB00020 */  sw        $s0, 0x20($sp)
/* 77CE4 800DE834 F7BC0068 */  sdc1      $f28, 0x68($sp)
/* 77CE8 800DE838 F7BA0060 */  sdc1      $f26, 0x60($sp)
/* 77CEC 800DE83C F7B80058 */  sdc1      $f24, 0x58($sp)
/* 77CF0 800DE840 F7B60050 */  sdc1      $f22, 0x50($sp)
/* 77CF4 800DE844 848200B2 */  lh        $v0, 0xb2($a0)
/* 77CF8 800DE848 4600A502 */  mul.s     $f20, $f20, $f0
/* 77CFC 800DE84C 00000000 */  nop       
/* 77D00 800DE850 3C013E99 */  lui       $at, 0x3e99
/* 77D04 800DE854 3421999A */  ori       $at, $at, 0x999a
/* 77D08 800DE858 44811000 */  mtc1      $at, $f2
/* 77D0C 800DE85C 8FB50080 */  lw        $s5, 0x80($sp)
/* 77D10 800DE860 4482B000 */  mtc1      $v0, $f22
/* 77D14 800DE864 00000000 */  nop       
/* 77D18 800DE868 4680B5A0 */  cvt.s.w   $f22, $f22
/* 77D1C 800DE86C 3C0143B4 */  lui       $at, 0x43b4
/* 77D20 800DE870 44810000 */  mtc1      $at, $f0
/* 77D24 800DE874 4602B582 */  mul.s     $f22, $f22, $f2
/* 77D28 800DE878 00000000 */  nop       
/* 77D2C 800DE87C 4600A503 */  div.s     $f20, $f20, $f0
/* 77D30 800DE880 0C00A85B */  jal       sin_rad
/* 77D34 800DE884 4600A306 */   mov.s    $f12, $f20
/* 77D38 800DE888 4600B702 */  mul.s     $f28, $f22, $f0
/* 77D3C 800DE88C 00000000 */  nop       
/* 77D40 800DE890 0C00A874 */  jal       cos_rad
/* 77D44 800DE894 4600A306 */   mov.s    $f12, $f20
/* 77D48 800DE898 27B30010 */  addiu     $s3, $sp, 0x10
/* 77D4C 800DE89C 0260202D */  daddu     $a0, $s3, $zero
/* 77D50 800DE8A0 27B20014 */  addiu     $s2, $sp, 0x14
/* 77D54 800DE8A4 0240282D */  daddu     $a1, $s2, $zero
/* 77D58 800DE8A8 27B10018 */  addiu     $s1, $sp, 0x18
/* 77D5C 800DE8AC 0220302D */  daddu     $a2, $s1, $zero
/* 77D60 800DE8B0 27B0001C */  addiu     $s0, $sp, 0x1c
/* 77D64 800DE8B4 4600B587 */  neg.s     $f22, $f22
/* 77D68 800DE8B8 4600B682 */  mul.s     $f26, $f22, $f0
/* 77D6C 800DE8BC 00000000 */  nop       
/* 77D70 800DE8C0 C6D60000 */  lwc1      $f22, ($s6)
/* 77D74 800DE8C4 C6F80000 */  lwc1      $f24, ($s7)
/* 77D78 800DE8C8 C7D40000 */  lwc1      $f20, ($fp)
/* 77D7C 800DE8CC C6A00000 */  lwc1      $f0, ($s5)
/* 77D80 800DE8D0 461CB080 */  add.s     $f2, $f22, $f28
/* 77D84 800DE8D4 0200382D */  daddu     $a3, $s0, $zero
/* 77D88 800DE8D8 E7A0001C */  swc1      $f0, 0x1c($sp)
/* 77D8C 800DE8DC 461AA000 */  add.s     $f0, $f20, $f26
/* 77D90 800DE8E0 E7B80014 */  swc1      $f24, 0x14($sp)
/* 77D94 800DE8E4 E7A20010 */  swc1      $f2, 0x10($sp)
/* 77D98 800DE8E8 0C037A82 */  jal       trace_above_player
/* 77D9C 800DE8EC E7A00018 */   swc1     $f0, 0x18($sp)
/* 77DA0 800DE8F0 04410022 */  bgez      $v0, .L800DE97C
/* 77DA4 800DE8F4 0260202D */   daddu    $a0, $s3, $zero
/* 77DA8 800DE8F8 0240282D */  daddu     $a1, $s2, $zero
/* 77DAC 800DE8FC 461CB081 */  sub.s     $f2, $f22, $f28
/* 77DB0 800DE900 0220302D */  daddu     $a2, $s1, $zero
/* 77DB4 800DE904 0200382D */  daddu     $a3, $s0, $zero
/* 77DB8 800DE908 461AA001 */  sub.s     $f0, $f20, $f26
/* 77DBC 800DE90C E7B80014 */  swc1      $f24, 0x14($sp)
/* 77DC0 800DE910 E7A20010 */  swc1      $f2, 0x10($sp)
/* 77DC4 800DE914 0C037A82 */  jal       trace_above_player
/* 77DC8 800DE918 E7A00018 */   swc1     $f0, 0x18($sp)
/* 77DCC 800DE91C 04410017 */  bgez      $v0, .L800DE97C
/* 77DD0 800DE920 0260202D */   daddu    $a0, $s3, $zero
/* 77DD4 800DE924 0240282D */  daddu     $a1, $s2, $zero
/* 77DD8 800DE928 461AB080 */  add.s     $f2, $f22, $f26
/* 77DDC 800DE92C 0220302D */  daddu     $a2, $s1, $zero
/* 77DE0 800DE930 0200382D */  daddu     $a3, $s0, $zero
/* 77DE4 800DE934 461CA000 */  add.s     $f0, $f20, $f28
/* 77DE8 800DE938 E7B80014 */  swc1      $f24, 0x14($sp)
/* 77DEC 800DE93C E7A20010 */  swc1      $f2, 0x10($sp)
/* 77DF0 800DE940 0C037A82 */  jal       trace_above_player
/* 77DF4 800DE944 E7A00018 */   swc1     $f0, 0x18($sp)
/* 77DF8 800DE948 0441000C */  bgez      $v0, .L800DE97C
/* 77DFC 800DE94C 0260202D */   daddu    $a0, $s3, $zero
/* 77E00 800DE950 0240282D */  daddu     $a1, $s2, $zero
/* 77E04 800DE954 461AB081 */  sub.s     $f2, $f22, $f26
/* 77E08 800DE958 0220302D */  daddu     $a2, $s1, $zero
/* 77E0C 800DE95C 0200382D */  daddu     $a3, $s0, $zero
/* 77E10 800DE960 461CA001 */  sub.s     $f0, $f20, $f28
/* 77E14 800DE964 E7B80014 */  swc1      $f24, 0x14($sp)
/* 77E18 800DE968 E7A20010 */  swc1      $f2, 0x10($sp)
/* 77E1C 800DE96C 0C037A82 */  jal       trace_above_player
/* 77E20 800DE970 E7A00018 */   swc1     $f0, 0x18($sp)
/* 77E24 800DE974 0440000A */  bltz      $v0, .L800DE9A0
/* 77E28 800DE978 00000000 */   nop      
.L800DE97C:
/* 77E2C 800DE97C C7A00010 */  lwc1      $f0, 0x10($sp)
/* 77E30 800DE980 E6C00000 */  swc1      $f0, ($s6)
/* 77E34 800DE984 C7A00014 */  lwc1      $f0, 0x14($sp)
/* 77E38 800DE988 E6E00000 */  swc1      $f0, ($s7)
/* 77E3C 800DE98C C7A00018 */  lwc1      $f0, 0x18($sp)
/* 77E40 800DE990 E7C00000 */  swc1      $f0, ($fp)
/* 77E44 800DE994 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 77E48 800DE998 0040A02D */  daddu     $s4, $v0, $zero
/* 77E4C 800DE99C E6A00000 */  swc1      $f0, ($s5)
.L800DE9A0:
/* 77E50 800DE9A0 06810008 */  bgez      $s4, .L800DE9C4
/* 77E54 800DE9A4 0280102D */   daddu    $v0, $s4, $zero
/* 77E58 800DE9A8 C7A00010 */  lwc1      $f0, 0x10($sp)
/* 77E5C 800DE9AC E6C00000 */  swc1      $f0, ($s6)
/* 77E60 800DE9B0 C7A00014 */  lwc1      $f0, 0x14($sp)
/* 77E64 800DE9B4 E6E00000 */  swc1      $f0, ($s7)
/* 77E68 800DE9B8 C7A00018 */  lwc1      $f0, 0x18($sp)
/* 77E6C 800DE9BC E7C00000 */  swc1      $f0, ($fp)
/* 77E70 800DE9C0 AEA00000 */  sw        $zero, ($s5)
.L800DE9C4:
/* 77E74 800DE9C4 8FBF0044 */  lw        $ra, 0x44($sp)
/* 77E78 800DE9C8 8FBE0040 */  lw        $fp, 0x40($sp)
/* 77E7C 800DE9CC 8FB7003C */  lw        $s7, 0x3c($sp)
/* 77E80 800DE9D0 8FB60038 */  lw        $s6, 0x38($sp)
/* 77E84 800DE9D4 8FB50034 */  lw        $s5, 0x34($sp)
/* 77E88 800DE9D8 8FB40030 */  lw        $s4, 0x30($sp)
/* 77E8C 800DE9DC 8FB3002C */  lw        $s3, 0x2c($sp)
/* 77E90 800DE9E0 8FB20028 */  lw        $s2, 0x28($sp)
/* 77E94 800DE9E4 8FB10024 */  lw        $s1, 0x24($sp)
/* 77E98 800DE9E8 8FB00020 */  lw        $s0, 0x20($sp)
/* 77E9C 800DE9EC D7BC0068 */  ldc1      $f28, 0x68($sp)
/* 77EA0 800DE9F0 D7BA0060 */  ldc1      $f26, 0x60($sp)
/* 77EA4 800DE9F4 D7B80058 */  ldc1      $f24, 0x58($sp)
/* 77EA8 800DE9F8 D7B60050 */  ldc1      $f22, 0x50($sp)
/* 77EAC 800DE9FC D7B40048 */  ldc1      $f20, 0x48($sp)
/* 77EB0 800DEA00 03E00008 */  jr        $ra
/* 77EB4 800DEA04 27BD0070 */   addiu    $sp, $sp, 0x70
