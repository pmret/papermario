.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A3C_D7F79C
/* D7F79C 80240A3C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D7F7A0 80240A40 AFB00010 */  sw        $s0, 0x10($sp)
/* D7F7A4 80240A44 0080802D */  daddu     $s0, $a0, $zero
/* D7F7A8 80240A48 AFBF0014 */  sw        $ra, 0x14($sp)
/* D7F7AC 80240A4C 8E02000C */  lw        $v0, 0xc($s0)
/* D7F7B0 80240A50 0C0B1EAF */  jal       get_variable
/* D7F7B4 80240A54 8C450000 */   lw       $a1, ($v0)
/* D7F7B8 80240A58 0200202D */  daddu     $a0, $s0, $zero
/* D7F7BC 80240A5C 3C05FD05 */  lui       $a1, 0xfd05
/* D7F7C0 80240A60 34A50F80 */  ori       $a1, $a1, 0xf80
/* D7F7C4 80240A64 0C0B1EAF */  jal       get_variable
/* D7F7C8 80240A68 0040802D */   daddu    $s0, $v0, $zero
/* D7F7CC 80240A6C 0040302D */  daddu     $a2, $v0, $zero
/* D7F7D0 80240A70 00101040 */  sll       $v0, $s0, 1
/* D7F7D4 80240A74 00501021 */  addu      $v0, $v0, $s0
/* D7F7D8 80240A78 000210C0 */  sll       $v0, $v0, 3
/* D7F7DC 80240A7C 00C22821 */  addu      $a1, $a2, $v0
/* D7F7E0 80240A80 84A30002 */  lh        $v1, 2($a1)
/* D7F7E4 80240A84 84A40000 */  lh        $a0, ($a1)
/* D7F7E8 80240A88 000310C0 */  sll       $v0, $v1, 3
/* D7F7EC 80240A8C 00431021 */  addu      $v0, $v0, $v1
/* D7F7F0 80240A90 00441021 */  addu      $v0, $v0, $a0
/* D7F7F4 80240A94 00021040 */  sll       $v0, $v0, 1
/* D7F7F8 80240A98 00C21021 */  addu      $v0, $a2, $v0
/* D7F7FC 80240A9C 24030014 */  addiu     $v1, $zero, 0x14
/* D7F800 80240AA0 A4430048 */  sh        $v1, 0x48($v0)
/* D7F804 80240AA4 C4A00014 */  lwc1      $f0, 0x14($a1)
/* D7F808 80240AA8 2402005A */  addiu     $v0, $zero, 0x5a
/* D7F80C 80240AAC 4600008D */  trunc.w.s $f2, $f0
/* D7F810 80240AB0 44031000 */  mfc1      $v1, $f2
/* D7F814 80240AB4 00000000 */  nop       
/* D7F818 80240AB8 10620012 */  beq       $v1, $v0, .L80240B04
/* D7F81C 80240ABC 00000000 */   nop      
/* D7F820 80240AC0 2862005B */  slti      $v0, $v1, 0x5b
/* D7F824 80240AC4 10400005 */  beqz      $v0, .L80240ADC
/* D7F828 80240AC8 240200B4 */   addiu    $v0, $zero, 0xb4
/* D7F82C 80240ACC 10600009 */  beqz      $v1, .L80240AF4
/* D7F830 80240AD0 00000000 */   nop      
/* D7F834 80240AD4 080902CB */  j         .L80240B2C
/* D7F838 80240AD8 00000000 */   nop      
.L80240ADC:
/* D7F83C 80240ADC 1062000C */  beq       $v1, $v0, .L80240B10
/* D7F840 80240AE0 2402010E */   addiu    $v0, $zero, 0x10e
/* D7F844 80240AE4 1062000E */  beq       $v1, $v0, .L80240B20
/* D7F848 80240AE8 00000000 */   nop      
/* D7F84C 80240AEC 080902CB */  j         .L80240B2C
/* D7F850 80240AF0 00000000 */   nop      
.L80240AF4:
/* D7F854 80240AF4 94A20002 */  lhu       $v0, 2($a1)
/* D7F858 80240AF8 2442FFFF */  addiu     $v0, $v0, -1
/* D7F85C 80240AFC 080902CB */  j         .L80240B2C
/* D7F860 80240B00 A4A20002 */   sh       $v0, 2($a1)
.L80240B04:
/* D7F864 80240B04 94A20000 */  lhu       $v0, ($a1)
/* D7F868 80240B08 080902CA */  j         .L80240B28
/* D7F86C 80240B0C 24420001 */   addiu    $v0, $v0, 1
.L80240B10:
/* D7F870 80240B10 94A20002 */  lhu       $v0, 2($a1)
/* D7F874 80240B14 24420001 */  addiu     $v0, $v0, 1
/* D7F878 80240B18 080902CB */  j         .L80240B2C
/* D7F87C 80240B1C A4A20002 */   sh       $v0, 2($a1)
.L80240B20:
/* D7F880 80240B20 94A20000 */  lhu       $v0, ($a1)
/* D7F884 80240B24 2442FFFF */  addiu     $v0, $v0, -1
.L80240B28:
/* D7F888 80240B28 A4A20000 */  sh        $v0, ($a1)
.L80240B2C:
/* D7F88C 80240B2C 84A30002 */  lh        $v1, 2($a1)
/* D7F890 80240B30 84A40000 */  lh        $a0, ($a1)
/* D7F894 80240B34 000310C0 */  sll       $v0, $v1, 3
/* D7F898 80240B38 00431021 */  addu      $v0, $v0, $v1
/* D7F89C 80240B3C 00441021 */  addu      $v0, $v0, $a0
/* D7F8A0 80240B40 00021040 */  sll       $v0, $v0, 1
/* D7F8A4 80240B44 00C21021 */  addu      $v0, $a2, $v0
/* D7F8A8 80240B48 2403FFFF */  addiu     $v1, $zero, -1
/* D7F8AC 80240B4C A4430048 */  sh        $v1, 0x48($v0)
/* D7F8B0 80240B50 84A40000 */  lh        $a0, ($a1)
/* D7F8B4 80240B54 00041840 */  sll       $v1, $a0, 1
/* D7F8B8 80240B58 00641821 */  addu      $v1, $v1, $a0
/* D7F8BC 80240B5C 000318C0 */  sll       $v1, $v1, 3
/* D7F8C0 80240B60 00641821 */  addu      $v1, $v1, $a0
/* D7F8C4 80240B64 00031840 */  sll       $v1, $v1, 1
/* D7F8C8 80240B68 24630032 */  addiu     $v1, $v1, 0x32
/* D7F8CC 80240B6C 84A40002 */  lh        $a0, 2($a1)
/* D7F8D0 80240B70 44830000 */  mtc1      $v1, $f0
/* D7F8D4 80240B74 00000000 */  nop       
/* D7F8D8 80240B78 46800020 */  cvt.s.w   $f0, $f0
/* D7F8DC 80240B7C E4A0000C */  swc1      $f0, 0xc($a1)
/* D7F8E0 80240B80 00041840 */  sll       $v1, $a0, 1
/* D7F8E4 80240B84 00641821 */  addu      $v1, $v1, $a0
/* D7F8E8 80240B88 000318C0 */  sll       $v1, $v1, 3
/* D7F8EC 80240B8C 00641821 */  addu      $v1, $v1, $a0
/* D7F8F0 80240B90 00031840 */  sll       $v1, $v1, 1
/* D7F8F4 80240B94 2463004B */  addiu     $v1, $v1, 0x4b
/* D7F8F8 80240B98 44830000 */  mtc1      $v1, $f0
/* D7F8FC 80240B9C 00000000 */  nop       
/* D7F900 80240BA0 46800020 */  cvt.s.w   $f0, $f0
/* D7F904 80240BA4 E4A00010 */  swc1      $f0, 0x10($a1)
/* D7F908 80240BA8 8FBF0014 */  lw        $ra, 0x14($sp)
/* D7F90C 80240BAC 8FB00010 */  lw        $s0, 0x10($sp)
/* D7F910 80240BB0 24020002 */  addiu     $v0, $zero, 2
/* D7F914 80240BB4 03E00008 */  jr        $ra
/* D7F918 80240BB8 27BD0018 */   addiu    $sp, $sp, 0x18
