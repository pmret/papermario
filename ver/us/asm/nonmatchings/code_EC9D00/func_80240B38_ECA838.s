.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B38_ECA838
/* ECA838 80240B38 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* ECA83C 80240B3C AFB10014 */  sw        $s1, 0x14($sp)
/* ECA840 80240B40 0080882D */  daddu     $s1, $a0, $zero
/* ECA844 80240B44 AFB20018 */  sw        $s2, 0x18($sp)
/* ECA848 80240B48 AFBF001C */  sw        $ra, 0x1c($sp)
/* ECA84C 80240B4C AFB00010 */  sw        $s0, 0x10($sp)
/* ECA850 80240B50 8E30000C */  lw        $s0, 0xc($s1)
/* ECA854 80240B54 10A00010 */  beqz      $a1, .L80240B98
/* ECA858 80240B58 0000902D */   daddu    $s2, $zero, $zero
/* ECA85C 80240B5C 8E050000 */  lw        $a1, ($s0)
/* ECA860 80240B60 0C0B53A3 */  jal       dead_get_variable
/* ECA864 80240B64 26100004 */   addiu    $s0, $s0, 4
/* ECA868 80240B68 AE220084 */  sw        $v0, 0x84($s1)
/* ECA86C 80240B6C 8E050000 */  lw        $a1, ($s0)
/* ECA870 80240B70 0C0B53A3 */  jal       dead_get_variable
/* ECA874 80240B74 0220202D */   daddu    $a0, $s1, $zero
/* ECA878 80240B78 0240202D */  daddu     $a0, $s2, $zero
/* ECA87C 80240B7C 240500D0 */  addiu     $a1, $zero, 0xd0
/* ECA880 80240B80 00A0302D */  daddu     $a2, $a1, $zero
/* ECA884 80240B84 00A0382D */  daddu     $a3, $a1, $zero
/* ECA888 80240B88 AE220088 */  sw        $v0, 0x88($s1)
/* ECA88C 80240B8C AE200070 */  sw        $zero, 0x70($s1)
/* ECA890 80240B90 0C051080 */  jal       func_80144200
/* ECA894 80240B94 AE200074 */   sw       $zero, 0x74($s1)
.L80240B98:
/* ECA898 80240B98 8E230070 */  lw        $v1, 0x70($s1)
/* ECA89C 80240B9C 24040001 */  addiu     $a0, $zero, 1
/* ECA8A0 80240BA0 10640019 */  beq       $v1, $a0, .L80240C08
/* ECA8A4 80240BA4 28620002 */   slti     $v0, $v1, 2
/* ECA8A8 80240BA8 10400005 */  beqz      $v0, .L80240BC0
/* ECA8AC 80240BAC 24020002 */   addiu    $v0, $zero, 2
/* ECA8B0 80240BB0 10600007 */  beqz      $v1, .L80240BD0
/* ECA8B4 80240BB4 240500FF */   addiu    $a1, $zero, 0xff
/* ECA8B8 80240BB8 08090312 */  j         .L80240C48
/* ECA8BC 80240BBC 00000000 */   nop
.L80240BC0:
/* ECA8C0 80240BC0 10620019 */  beq       $v1, $v0, .L80240C28
/* ECA8C4 80240BC4 00000000 */   nop
/* ECA8C8 80240BC8 08090312 */  j         .L80240C48
/* ECA8CC 80240BCC 00000000 */   nop
.L80240BD0:
/* ECA8D0 80240BD0 8E220074 */  lw        $v0, 0x74($s1)
/* ECA8D4 80240BD4 14450004 */  bne       $v0, $a1, .L80240BE8
/* ECA8D8 80240BD8 00000000 */   nop
/* ECA8DC 80240BDC AE240070 */  sw        $a0, 0x70($s1)
/* ECA8E0 80240BE0 AE200078 */  sw        $zero, 0x78($s1)
/* ECA8E4 80240BE4 8E220074 */  lw        $v0, 0x74($s1)
.L80240BE8:
/* ECA8E8 80240BE8 8E230084 */  lw        $v1, 0x84($s1)
/* ECA8EC 80240BEC 00431021 */  addu      $v0, $v0, $v1
/* ECA8F0 80240BF0 AE220074 */  sw        $v0, 0x74($s1)
/* ECA8F4 80240BF4 28420100 */  slti      $v0, $v0, 0x100
/* ECA8F8 80240BF8 50400013 */  beql      $v0, $zero, .L80240C48
/* ECA8FC 80240BFC AE250074 */   sw       $a1, 0x74($s1)
/* ECA900 80240C00 08090312 */  j         .L80240C48
/* ECA904 80240C04 00000000 */   nop
.L80240C08:
/* ECA908 80240C08 8E220078 */  lw        $v0, 0x78($s1)
/* ECA90C 80240C0C 24420001 */  addiu     $v0, $v0, 1
/* ECA910 80240C10 AE220078 */  sw        $v0, 0x78($s1)
/* ECA914 80240C14 28420002 */  slti      $v0, $v0, 2
/* ECA918 80240C18 1440000B */  bnez      $v0, .L80240C48
/* ECA91C 80240C1C 24020002 */   addiu    $v0, $zero, 2
/* ECA920 80240C20 08090312 */  j         .L80240C48
/* ECA924 80240C24 AE220070 */   sw       $v0, 0x70($s1)
.L80240C28:
/* ECA928 80240C28 8E230074 */  lw        $v1, 0x74($s1)
/* ECA92C 80240C2C 50600001 */  beql      $v1, $zero, .L80240C34
/* ECA930 80240C30 24120001 */   addiu    $s2, $zero, 1
.L80240C34:
/* ECA934 80240C34 8E220088 */  lw        $v0, 0x88($s1)
/* ECA938 80240C38 00621023 */  subu      $v0, $v1, $v0
/* ECA93C 80240C3C 04410002 */  bgez      $v0, .L80240C48
/* ECA940 80240C40 AE220074 */   sw       $v0, 0x74($s1)
/* ECA944 80240C44 AE200074 */  sw        $zero, 0x74($s1)
.L80240C48:
/* ECA948 80240C48 C6200074 */  lwc1      $f0, 0x74($s1)
/* ECA94C 80240C4C 46800020 */  cvt.s.w   $f0, $f0
/* ECA950 80240C50 44050000 */  mfc1      $a1, $f0
/* ECA954 80240C54 0C05105E */  jal       func_80144178
/* ECA958 80240C58 24040001 */   addiu    $a0, $zero, 1
/* ECA95C 80240C5C 0240102D */  daddu     $v0, $s2, $zero
/* ECA960 80240C60 8FBF001C */  lw        $ra, 0x1c($sp)
/* ECA964 80240C64 8FB20018 */  lw        $s2, 0x18($sp)
/* ECA968 80240C68 8FB10014 */  lw        $s1, 0x14($sp)
/* ECA96C 80240C6C 8FB00010 */  lw        $s0, 0x10($sp)
/* ECA970 80240C70 03E00008 */  jr        $ra
/* ECA974 80240C74 27BD0020 */   addiu    $sp, $sp, 0x20
