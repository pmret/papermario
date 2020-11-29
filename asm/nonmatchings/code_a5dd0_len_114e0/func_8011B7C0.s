.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011B7C0
/* B1EC0 8011B7C0 3084FFFF */  andi      $a0, $a0, 0xffff
/* B1EC4 8011B7C4 3C0A800A */  lui       $t2, %hi(D_8009A5F4)
/* B1EC8 8011B7C8 8D4AA5F4 */  lw        $t2, %lo(D_8009A5F4)($t2)
/* B1ECC 8011B7CC 00041080 */  sll       $v0, $a0, 2
/* B1ED0 8011B7D0 004A3821 */  addu      $a3, $v0, $t2
/* B1ED4 8011B7D4 90E30000 */  lbu       $v1, ($a3)
/* B1ED8 8011B7D8 286200FF */  slti      $v0, $v1, 0xff
/* B1EDC 8011B7DC 10400004 */  beqz      $v0, .L8011B7F0
/* B1EE0 8011B7E0 2408FFFF */   addiu    $t0, $zero, -1
/* B1EE4 8011B7E4 0060402D */  daddu     $t0, $v1, $zero
/* B1EE8 8011B7E8 08046E10 */  j         .L8011B840
/* B1EEC 8011B7EC 0100482D */   daddu    $t1, $t0, $zero
.L8011B7F0:
/* B1EF0 8011B7F0 2484FFFF */  addiu     $a0, $a0, -1
/* B1EF4 8011B7F4 90EB0001 */  lbu       $t3, 1($a3)
/* B1EF8 8011B7F8 04800011 */  bltz      $a0, .L8011B840
/* B1EFC 8011B7FC 00041080 */   sll      $v0, $a0, 2
/* B1F00 8011B800 240CFFFF */  addiu     $t4, $zero, -1
/* B1F04 8011B804 004A3821 */  addu      $a3, $v0, $t2
.L8011B808:
/* B1F08 8011B808 90E20001 */  lbu       $v0, 1($a3)
/* B1F0C 8011B80C 0162102A */  slt       $v0, $t3, $v0
/* B1F10 8011B810 1040000C */  beqz      $v0, .L8011B844
/* B1F14 8011B814 28C20002 */   slti     $v0, $a2, 2
/* B1F18 8011B818 90E30000 */  lbu       $v1, ($a3)
/* B1F1C 8011B81C 286200FF */  slti      $v0, $v1, 0xff
/* B1F20 8011B820 50400005 */  beql      $v0, $zero, .L8011B838
/* B1F24 8011B824 2484FFFF */   addiu    $a0, $a0, -1
/* B1F28 8011B828 510C0001 */  beql      $t0, $t4, .L8011B830
/* B1F2C 8011B82C 0060402D */   daddu    $t0, $v1, $zero
.L8011B830:
/* B1F30 8011B830 0060482D */  daddu     $t1, $v1, $zero
/* B1F34 8011B834 2484FFFF */  addiu     $a0, $a0, -1
.L8011B838:
/* B1F38 8011B838 0481FFF3 */  bgez      $a0, .L8011B808
/* B1F3C 8011B83C 24E7FFFC */   addiu    $a3, $a3, -4
.L8011B840:
/* B1F40 8011B840 28C20002 */  slti      $v0, $a2, 2
.L8011B844:
/* B1F44 8011B844 10400016 */  beqz      $v0, .L8011B8A0
/* B1F48 8011B848 0120202D */   daddu    $a0, $t1, $zero
/* B1F4C 8011B84C 0104102A */  slt       $v0, $t0, $a0
/* B1F50 8011B850 14400011 */  bnez      $v0, .L8011B898
/* B1F54 8011B854 00054827 */   nor      $t1, $zero, $a1
/* B1F58 8011B858 3C038015 */  lui       $v1, %hi(gCurrentModelListPtr)
/* B1F5C 8011B85C 8C6312CC */  lw        $v1, %lo(gCurrentModelListPtr)($v1)
/* B1F60 8011B860 00041080 */  sll       $v0, $a0, 2
/* B1F64 8011B864 00433821 */  addu      $a3, $v0, $v1
.L8011B868:
/* B1F68 8011B868 10C00004 */  beqz      $a2, .L8011B87C
/* B1F6C 8011B86C 8CE30000 */   lw       $v1, ($a3)
/* B1F70 8011B870 94620000 */  lhu       $v0, ($v1)
/* B1F74 8011B874 08046E21 */  j         .L8011B884
/* B1F78 8011B878 00491024 */   and      $v0, $v0, $t1
.L8011B87C:
/* B1F7C 8011B87C 94620000 */  lhu       $v0, ($v1)
/* B1F80 8011B880 00451025 */  or        $v0, $v0, $a1
.L8011B884:
/* B1F84 8011B884 A4620000 */  sh        $v0, ($v1)
/* B1F88 8011B888 24840001 */  addiu     $a0, $a0, 1
/* B1F8C 8011B88C 0104102A */  slt       $v0, $t0, $a0
/* B1F90 8011B890 1040FFF5 */  beqz      $v0, .L8011B868
/* B1F94 8011B894 24E70004 */   addiu    $a3, $a3, 4
.L8011B898:
/* B1F98 8011B898 03E00008 */  jr        $ra
/* B1F9C 8011B89C 00000000 */   nop      
.L8011B8A0:
/* B1FA0 8011B8A0 19200011 */  blez      $t1, .L8011B8E8
/* B1FA4 8011B8A4 0000202D */   daddu    $a0, $zero, $zero
/* B1FA8 8011B8A8 240B0003 */  addiu     $t3, $zero, 3
/* B1FAC 8011B8AC 00055027 */  nor       $t2, $zero, $a1
/* B1FB0 8011B8B0 3C078015 */  lui       $a3, %hi(gCurrentModelListPtr)
/* B1FB4 8011B8B4 8CE712CC */  lw        $a3, %lo(gCurrentModelListPtr)($a3)
.L8011B8B8:
/* B1FB8 8011B8B8 14CB0004 */  bne       $a2, $t3, .L8011B8CC
/* B1FBC 8011B8BC 8CE30000 */   lw       $v1, ($a3)
/* B1FC0 8011B8C0 94620000 */  lhu       $v0, ($v1)
/* B1FC4 8011B8C4 08046E35 */  j         .L8011B8D4
/* B1FC8 8011B8C8 004A1024 */   and      $v0, $v0, $t2
.L8011B8CC:
/* B1FCC 8011B8CC 94620000 */  lhu       $v0, ($v1)
/* B1FD0 8011B8D0 00451025 */  or        $v0, $v0, $a1
.L8011B8D4:
/* B1FD4 8011B8D4 A4620000 */  sh        $v0, ($v1)
/* B1FD8 8011B8D8 24840001 */  addiu     $a0, $a0, 1
/* B1FDC 8011B8DC 0089102A */  slt       $v0, $a0, $t1
/* B1FE0 8011B8E0 1440FFF5 */  bnez      $v0, .L8011B8B8
/* B1FE4 8011B8E4 24E70004 */   addiu    $a3, $a3, 4
.L8011B8E8:
/* B1FE8 8011B8E8 25040001 */  addiu     $a0, $t0, 1
/* B1FEC 8011B8EC 28820100 */  slti      $v0, $a0, 0x100
/* B1FF0 8011B8F0 1040FFE9 */  beqz      $v0, .L8011B898
/* B1FF4 8011B8F4 24090003 */   addiu    $t1, $zero, 3
/* B1FF8 8011B8F8 00054027 */  nor       $t0, $zero, $a1
/* B1FFC 8011B8FC 3C038015 */  lui       $v1, %hi(gCurrentModelListPtr)
/* B2000 8011B900 8C6312CC */  lw        $v1, %lo(gCurrentModelListPtr)($v1)
/* B2004 8011B904 00041080 */  sll       $v0, $a0, 2
/* B2008 8011B908 00433821 */  addu      $a3, $v0, $v1
.L8011B90C:
/* B200C 8011B90C 8CE30000 */  lw        $v1, ($a3)
/* B2010 8011B910 5060000A */  beql      $v1, $zero, .L8011B93C
/* B2014 8011B914 24840001 */   addiu    $a0, $a0, 1
/* B2018 8011B918 14C90004 */  bne       $a2, $t1, .L8011B92C
/* B201C 8011B91C 00000000 */   nop      
/* B2020 8011B920 94620000 */  lhu       $v0, ($v1)
/* B2024 8011B924 08046E4D */  j         .L8011B934
/* B2028 8011B928 00481024 */   and      $v0, $v0, $t0
.L8011B92C:
/* B202C 8011B92C 94620000 */  lhu       $v0, ($v1)
/* B2030 8011B930 00451025 */  or        $v0, $v0, $a1
.L8011B934:
/* B2034 8011B934 A4620000 */  sh        $v0, ($v1)
/* B2038 8011B938 24840001 */  addiu     $a0, $a0, 1
.L8011B93C:
/* B203C 8011B93C 28820100 */  slti      $v0, $a0, 0x100
/* B2040 8011B940 1440FFF2 */  bnez      $v0, .L8011B90C
/* B2044 8011B944 24E70004 */   addiu    $a3, $a3, 4
/* B2048 8011B948 03E00008 */  jr        $ra
/* B204C 8011B94C 00000000 */   nop      
