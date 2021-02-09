.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B38_CAF878
/* CAF878 80240B38 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CAF87C 80240B3C AFB10014 */  sw        $s1, 0x14($sp)
/* CAF880 80240B40 0080882D */  daddu     $s1, $a0, $zero
/* CAF884 80240B44 AFB20018 */  sw        $s2, 0x18($sp)
/* CAF888 80240B48 AFBF001C */  sw        $ra, 0x1c($sp)
/* CAF88C 80240B4C AFB00010 */  sw        $s0, 0x10($sp)
/* CAF890 80240B50 8E30000C */  lw        $s0, 0xc($s1)
/* CAF894 80240B54 10A00010 */  beqz      $a1, .L80240B98
/* CAF898 80240B58 0000902D */   daddu    $s2, $zero, $zero
/* CAF89C 80240B5C 8E050000 */  lw        $a1, ($s0)
/* CAF8A0 80240B60 0C0B1EAF */  jal       get_variable
/* CAF8A4 80240B64 26100004 */   addiu    $s0, $s0, 4
/* CAF8A8 80240B68 AE220084 */  sw        $v0, 0x84($s1)
/* CAF8AC 80240B6C 8E050000 */  lw        $a1, ($s0)
/* CAF8B0 80240B70 0C0B1EAF */  jal       get_variable
/* CAF8B4 80240B74 0220202D */   daddu    $a0, $s1, $zero
/* CAF8B8 80240B78 0240202D */  daddu     $a0, $s2, $zero
/* CAF8BC 80240B7C 240500D0 */  addiu     $a1, $zero, 0xd0
/* CAF8C0 80240B80 00A0302D */  daddu     $a2, $a1, $zero
/* CAF8C4 80240B84 00A0382D */  daddu     $a3, $a1, $zero
/* CAF8C8 80240B88 AE220088 */  sw        $v0, 0x88($s1)
/* CAF8CC 80240B8C AE200070 */  sw        $zero, 0x70($s1)
/* CAF8D0 80240B90 0C04DF84 */  jal       set_transition_stencil_color
/* CAF8D4 80240B94 AE200074 */   sw       $zero, 0x74($s1)
.L80240B98:
/* CAF8D8 80240B98 8E230070 */  lw        $v1, 0x70($s1)
/* CAF8DC 80240B9C 24040001 */  addiu     $a0, $zero, 1
/* CAF8E0 80240BA0 10640019 */  beq       $v1, $a0, .L80240C08
/* CAF8E4 80240BA4 28620002 */   slti     $v0, $v1, 2
/* CAF8E8 80240BA8 10400005 */  beqz      $v0, .L80240BC0
/* CAF8EC 80240BAC 24020002 */   addiu    $v0, $zero, 2
/* CAF8F0 80240BB0 10600007 */  beqz      $v1, .L80240BD0
/* CAF8F4 80240BB4 240500FF */   addiu    $a1, $zero, 0xff
/* CAF8F8 80240BB8 08090312 */  j         .L80240C48
/* CAF8FC 80240BBC 00000000 */   nop
.L80240BC0:
/* CAF900 80240BC0 10620019 */  beq       $v1, $v0, .L80240C28
/* CAF904 80240BC4 00000000 */   nop
/* CAF908 80240BC8 08090312 */  j         .L80240C48
/* CAF90C 80240BCC 00000000 */   nop
.L80240BD0:
/* CAF910 80240BD0 8E220074 */  lw        $v0, 0x74($s1)
/* CAF914 80240BD4 14450004 */  bne       $v0, $a1, .L80240BE8
/* CAF918 80240BD8 00000000 */   nop
/* CAF91C 80240BDC AE240070 */  sw        $a0, 0x70($s1)
/* CAF920 80240BE0 AE200078 */  sw        $zero, 0x78($s1)
/* CAF924 80240BE4 8E220074 */  lw        $v0, 0x74($s1)
.L80240BE8:
/* CAF928 80240BE8 8E230084 */  lw        $v1, 0x84($s1)
/* CAF92C 80240BEC 00431021 */  addu      $v0, $v0, $v1
/* CAF930 80240BF0 AE220074 */  sw        $v0, 0x74($s1)
/* CAF934 80240BF4 28420100 */  slti      $v0, $v0, 0x100
/* CAF938 80240BF8 50400013 */  beql      $v0, $zero, .L80240C48
/* CAF93C 80240BFC AE250074 */   sw       $a1, 0x74($s1)
/* CAF940 80240C00 08090312 */  j         .L80240C48
/* CAF944 80240C04 00000000 */   nop
.L80240C08:
/* CAF948 80240C08 8E220078 */  lw        $v0, 0x78($s1)
/* CAF94C 80240C0C 24420001 */  addiu     $v0, $v0, 1
/* CAF950 80240C10 AE220078 */  sw        $v0, 0x78($s1)
/* CAF954 80240C14 28420002 */  slti      $v0, $v0, 2
/* CAF958 80240C18 1440000B */  bnez      $v0, .L80240C48
/* CAF95C 80240C1C 24020002 */   addiu    $v0, $zero, 2
/* CAF960 80240C20 08090312 */  j         .L80240C48
/* CAF964 80240C24 AE220070 */   sw       $v0, 0x70($s1)
.L80240C28:
/* CAF968 80240C28 8E230074 */  lw        $v1, 0x74($s1)
/* CAF96C 80240C2C 50600001 */  beql      $v1, $zero, .L80240C34
/* CAF970 80240C30 24120001 */   addiu    $s2, $zero, 1
.L80240C34:
/* CAF974 80240C34 8E220088 */  lw        $v0, 0x88($s1)
/* CAF978 80240C38 00621023 */  subu      $v0, $v1, $v0
/* CAF97C 80240C3C 04410002 */  bgez      $v0, .L80240C48
/* CAF980 80240C40 AE220074 */   sw       $v0, 0x74($s1)
/* CAF984 80240C44 AE200074 */  sw        $zero, 0x74($s1)
.L80240C48:
/* CAF988 80240C48 C6200074 */  lwc1      $f0, 0x74($s1)
/* CAF98C 80240C4C 46800020 */  cvt.s.w   $f0, $f0
/* CAF990 80240C50 44050000 */  mfc1      $a1, $f0
/* CAF994 80240C54 0C04DF62 */  jal       set_transition_stencil_zoom_0
/* CAF998 80240C58 24040001 */   addiu    $a0, $zero, 1
/* CAF99C 80240C5C 0240102D */  daddu     $v0, $s2, $zero
/* CAF9A0 80240C60 8FBF001C */  lw        $ra, 0x1c($sp)
/* CAF9A4 80240C64 8FB20018 */  lw        $s2, 0x18($sp)
/* CAF9A8 80240C68 8FB10014 */  lw        $s1, 0x14($sp)
/* CAF9AC 80240C6C 8FB00010 */  lw        $s0, 0x10($sp)
/* CAF9B0 80240C70 03E00008 */  jr        $ra
/* CAF9B4 80240C74 27BD0020 */   addiu    $sp, $sp, 0x20
