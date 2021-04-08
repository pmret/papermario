.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004B724
/* 26B24 8004B724 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 26B28 8004B728 AFB40028 */  sw        $s4, 0x28($sp)
/* 26B2C 8004B72C 0080A02D */  daddu     $s4, $a0, $zero
/* 26B30 8004B730 AFB70034 */  sw        $s7, 0x34($sp)
/* 26B34 8004B734 00A0B82D */  daddu     $s7, $a1, $zero
/* 26B38 8004B738 AFBF003C */  sw        $ra, 0x3c($sp)
/* 26B3C 8004B73C AFBE0038 */  sw        $fp, 0x38($sp)
/* 26B40 8004B740 AFB60030 */  sw        $s6, 0x30($sp)
/* 26B44 8004B744 AFB5002C */  sw        $s5, 0x2c($sp)
/* 26B48 8004B748 AFB30024 */  sw        $s3, 0x24($sp)
/* 26B4C 8004B74C AFB20020 */  sw        $s2, 0x20($sp)
/* 26B50 8004B750 AFB1001C */  sw        $s1, 0x1c($sp)
/* 26B54 8004B754 AFB00018 */  sw        $s0, 0x18($sp)
/* 26B58 8004B758 96E20000 */  lhu       $v0, ($s7)
/* 26B5C 8004B75C 0000402D */  daddu     $t0, $zero, $zero
/* 26B60 8004B760 2445FFFF */  addiu     $a1, $v0, -1
/* 26B64 8004B764 304923FF */  andi      $t1, $v0, 0x23ff
/* 26B68 8004B768 0040182D */  daddu     $v1, $v0, $zero
/* 26B6C 8004B76C 30422000 */  andi      $v0, $v0, 0x2000
/* 26B70 8004B770 10400020 */  beqz      $v0, .L8004B7F4
/* 26B74 8004B774 30A400FF */   andi     $a0, $a1, 0xff
/* 26B78 8004B778 30A401FF */  andi      $a0, $a1, 0x1ff
/* 26B7C 8004B77C 2C820140 */  sltiu     $v0, $a0, 0x140
/* 26B80 8004B780 10400178 */  beqz      $v0, .L8004BD64
/* 26B84 8004B784 00041880 */   sll      $v1, $a0, 2
/* 26B88 8004B788 8E82002C */  lw        $v0, 0x2c($s4)
/* 26B8C 8004B78C 00439021 */  addu      $s2, $v0, $v1
/* 26B90 8004B790 96420000 */  lhu       $v0, ($s2)
/* 26B94 8004B794 10400173 */  beqz      $v0, .L8004BD64
/* 26B98 8004B798 24100007 */   addiu    $s0, $zero, 7
/* 26B9C 8004B79C 3124FFFF */  andi      $a0, $t1, 0xffff
/* 26BA0 8004B7A0 24030620 */  addiu     $v1, $zero, 0x620
.L8004B7A4:
/* 26BA4 8004B7A4 02833821 */  addu      $a3, $s4, $v1
/* 26BA8 8004B7A8 94E20096 */  lhu       $v0, 0x96($a3)
/* 26BAC 8004B7AC 1044000F */  beq       $v0, $a0, .L8004B7EC
/* 26BB0 8004B7B0 2610FFFF */   addiu    $s0, $s0, -1
/* 26BB4 8004B7B4 0601FFFB */  bgez      $s0, .L8004B7A4
/* 26BB8 8004B7B8 2463FF54 */   addiu    $v1, $v1, -0xac
.L8004B7BC:
/* 26BBC 8004B7BC 55000038 */  bnel      $t0, $zero, .L8004B8A0
/* 26BC0 8004B7C0 0280202D */   daddu    $a0, $s4, $zero
/* 26BC4 8004B7C4 24100007 */  addiu     $s0, $zero, 7
/* 26BC8 8004B7C8 24030620 */  addiu     $v1, $zero, 0x620
.L8004B7CC:
/* 26BCC 8004B7CC 02833821 */  addu      $a3, $s4, $v1
/* 26BD0 8004B7D0 8CE20000 */  lw        $v0, ($a3)
/* 26BD4 8004B7D4 10400010 */  beqz      $v0, .L8004B818
/* 26BD8 8004B7D8 2610FFFF */   addiu    $s0, $s0, -1
/* 26BDC 8004B7DC 0601FFFB */  bgez      $s0, .L8004B7CC
/* 26BE0 8004B7E0 2463FF54 */   addiu    $v1, $v1, -0xac
/* 26BE4 8004B7E4 08012E26 */  j         .L8004B898
/* 26BE8 8004B7E8 00000000 */   nop
.L8004B7EC:
/* 26BEC 8004B7EC 08012DEF */  j         .L8004B7BC
/* 26BF0 8004B7F0 24080001 */   addiu    $t0, $zero, 1
.L8004B7F4:
/* 26BF4 8004B7F4 2C8200C0 */  sltiu     $v0, $a0, 0xc0
/* 26BF8 8004B7F8 14400031 */  bnez      $v0, .L8004B8C0
/* 26BFC 8004B7FC 00000000 */   nop
/* 26C00 8004B800 10C00007 */  beqz      $a2, .L8004B820
/* 26C04 8004B804 00C0902D */   daddu    $s2, $a2, $zero
/* 26C08 8004B808 08012E11 */  j         .L8004B844
/* 26C0C 8004B80C 00000000 */   nop
.L8004B810:
/* 26C10 8004B810 08012E1C */  j         .L8004B870
/* 26C14 8004B814 24080001 */   addiu    $t0, $zero, 1
.L8004B818:
/* 26C18 8004B818 08012E26 */  j         .L8004B898
/* 26C1C 8004B81C 24080001 */   addiu    $t0, $zero, 1
.L8004B820:
/* 26C20 8004B820 2522FFFF */  addiu     $v0, $t1, -1
/* 26C24 8004B824 00021203 */  sra       $v0, $v0, 8
/* 26C28 8004B828 24420004 */  addiu     $v0, $v0, 4
/* 26C2C 8004B82C 00021080 */  sll       $v0, $v0, 2
/* 26C30 8004B830 02821021 */  addu      $v0, $s4, $v0
/* 26C34 8004B834 2483FF40 */  addiu     $v1, $a0, -0xc0
/* 26C38 8004B838 8C42000C */  lw        $v0, 0xc($v0)
/* 26C3C 8004B83C 00031880 */  sll       $v1, $v1, 2
/* 26C40 8004B840 00439021 */  addu      $s2, $v0, $v1
.L8004B844:
/* 26C44 8004B844 96420000 */  lhu       $v0, ($s2)
/* 26C48 8004B848 10400146 */  beqz      $v0, .L8004BD64
/* 26C4C 8004B84C 24100007 */   addiu    $s0, $zero, 7
/* 26C50 8004B850 3124FFFF */  andi      $a0, $t1, 0xffff
/* 26C54 8004B854 24030620 */  addiu     $v1, $zero, 0x620
.L8004B858:
/* 26C58 8004B858 02833821 */  addu      $a3, $s4, $v1
/* 26C5C 8004B85C 94E20096 */  lhu       $v0, 0x96($a3)
/* 26C60 8004B860 1044FFEB */  beq       $v0, $a0, .L8004B810
/* 26C64 8004B864 2610FFFF */   addiu    $s0, $s0, -1
/* 26C68 8004B868 0601FFFB */  bgez      $s0, .L8004B858
/* 26C6C 8004B86C 2463FF54 */   addiu    $v1, $v1, -0xac
.L8004B870:
/* 26C70 8004B870 5500000B */  bnel      $t0, $zero, .L8004B8A0
/* 26C74 8004B874 0280202D */   daddu    $a0, $s4, $zero
/* 26C78 8004B878 24100007 */  addiu     $s0, $zero, 7
/* 26C7C 8004B87C 24030620 */  addiu     $v1, $zero, 0x620
.L8004B880:
/* 26C80 8004B880 02833821 */  addu      $a3, $s4, $v1
/* 26C84 8004B884 8CE20000 */  lw        $v0, ($a3)
/* 26C88 8004B888 1040FFE3 */  beqz      $v0, .L8004B818
/* 26C8C 8004B88C 2610FFFF */   addiu    $s0, $s0, -1
/* 26C90 8004B890 0601FFFB */  bgez      $s0, .L8004B880
/* 26C94 8004B894 2463FF54 */   addiu    $v1, $v1, -0xac
.L8004B898:
/* 26C98 8004B898 11000132 */  beqz      $t0, .L8004BD64
/* 26C9C 8004B89C 0280202D */   daddu    $a0, $s4, $zero
.L8004B8A0:
/* 26CA0 8004B8A0 00E0282D */  daddu     $a1, $a3, $zero
/* 26CA4 8004B8A4 0240302D */  daddu     $a2, $s2, $zero
/* 26CA8 8004B8A8 02E0382D */  daddu     $a3, $s7, $zero
/* 26CAC 8004B8AC AFA00010 */  sw        $zero, 0x10($sp)
/* 26CB0 8004B8B0 0C012F65 */  jal       func_8004BD94
/* 26CB4 8004B8B4 AFA00014 */   sw       $zero, 0x14($sp)
/* 26CB8 8004B8B8 08012F59 */  j         .L8004BD64
/* 26CBC 8004B8BC 00000000 */   nop
.L8004B8C0:
/* 26CC0 8004B8C0 10C00005 */  beqz      $a2, .L8004B8D8
/* 26CC4 8004B8C4 00C0902D */   daddu    $s2, $a2, $zero
/* 26CC8 8004B8C8 08012E3C */  j         .L8004B8F0
/* 26CCC 8004B8CC 00000000 */   nop
.L8004B8D0:
/* 26CD0 8004B8D0 08012E54 */  j         .L8004B950
/* 26CD4 8004B8D4 24080001 */   addiu    $t0, $zero, 1
.L8004B8D8:
/* 26CD8 8004B8D8 00031182 */  srl       $v0, $v1, 6
/* 26CDC 8004B8DC 3042000C */  andi      $v0, $v0, 0xc
/* 26CE0 8004B8E0 02821021 */  addu      $v0, $s4, $v0
/* 26CE4 8004B8E4 8C43000C */  lw        $v1, 0xc($v0)
/* 26CE8 8004B8E8 00041080 */  sll       $v0, $a0, 2
/* 26CEC 8004B8EC 00629021 */  addu      $s2, $v1, $v0
.L8004B8F0:
/* 26CF0 8004B8F0 96420000 */  lhu       $v0, ($s2)
/* 26CF4 8004B8F4 1040011B */  beqz      $v0, .L8004BD64
/* 26CF8 8004B8F8 00000000 */   nop
/* 26CFC 8004B8FC 96440002 */  lhu       $a0, 2($s2)
/* 26D00 8004B900 30820300 */  andi      $v0, $a0, 0x300
/* 26D04 8004B904 0002AA02 */  srl       $s5, $v0, 8
/* 26D08 8004B908 30820060 */  andi      $v0, $a0, 0x60
/* 26D0C 8004B90C 00028142 */  srl       $s0, $v0, 5
/* 26D10 8004B910 30820080 */  andi      $v0, $a0, 0x80
/* 26D14 8004B914 1600007F */  bnez      $s0, .L8004BB14
/* 26D18 8004B918 000299C2 */   srl      $s3, $v0, 7
/* 26D1C 8004B91C 96E20002 */  lhu       $v0, 2($s7)
/* 26D20 8004B920 1040000B */  beqz      $v0, .L8004B950
/* 26D24 8004B924 00000000 */   nop
/* 26D28 8004B928 0000802D */  daddu     $s0, $zero, $zero
/* 26D2C 8004B92C 0040282D */  daddu     $a1, $v0, $zero
/* 26D30 8004B930 2403016C */  addiu     $v1, $zero, 0x16c
.L8004B934:
/* 26D34 8004B934 02833821 */  addu      $a3, $s4, $v1
/* 26D38 8004B938 94E20096 */  lhu       $v0, 0x96($a3)
/* 26D3C 8004B93C 1045FFE4 */  beq       $v0, $a1, .L8004B8D0
/* 26D40 8004B940 26100001 */   addiu    $s0, $s0, 1
/* 26D44 8004B944 2A020008 */  slti      $v0, $s0, 8
/* 26D48 8004B948 1440FFFA */  bnez      $v0, .L8004B934
/* 26D4C 8004B94C 246300AC */   addiu    $v1, $v1, 0xac
.L8004B950:
/* 26D50 8004B950 1660001C */  bnez      $s3, .L8004B9C4
/* 26D54 8004B954 00000000 */   nop
/* 26D58 8004B958 55000064 */  bnel      $t0, $zero, .L8004BAEC
/* 26D5C 8004B95C 0280202D */   daddu    $a0, $s4, $zero
/* 26D60 8004B960 30900007 */  andi      $s0, $a0, 7
/* 26D64 8004B964 00101040 */  sll       $v0, $s0, 1
/* 26D68 8004B968 00501021 */  addu      $v0, $v0, $s0
/* 26D6C 8004B96C 00021080 */  sll       $v0, $v0, 2
/* 26D70 8004B970 00501023 */  subu      $v0, $v0, $s0
/* 26D74 8004B974 00021080 */  sll       $v0, $v0, 2
/* 26D78 8004B978 00501023 */  subu      $v0, $v0, $s0
/* 26D7C 8004B97C 00021080 */  sll       $v0, $v0, 2
/* 26D80 8004B980 2442016C */  addiu     $v0, $v0, 0x16c
/* 26D84 8004B984 02823821 */  addu      $a3, $s4, $v0
/* 26D88 8004B988 8CE20000 */  lw        $v0, ($a3)
/* 26D8C 8004B98C 10400057 */  beqz      $v0, .L8004BAEC
/* 26D90 8004B990 0280202D */   daddu    $a0, $s4, $zero
/* 26D94 8004B994 90E20098 */  lbu       $v0, 0x98($a3)
/* 26D98 8004B998 02A2102B */  sltu      $v0, $s5, $v0
/* 26D9C 8004B99C 10400054 */  beqz      $v0, .L8004BAF0
/* 26DA0 8004B9A0 00E0282D */   daddu    $a1, $a3, $zero
/* 26DA4 8004B9A4 08012F59 */  j         .L8004BD64
/* 26DA8 8004B9A8 00000000 */   nop
.L8004B9AC:
/* 26DAC 8004B9AC 08012E84 */  j         .L8004BA10
/* 26DB0 8004B9B0 24080001 */   addiu    $t0, $zero, 1
.L8004B9B4:
/* 26DB4 8004B9B4 08012E96 */  j         .L8004BA58
/* 26DB8 8004B9B8 24080001 */   addiu    $t0, $zero, 1
.L8004B9BC:
/* 26DBC 8004B9BC 08012EA9 */  j         .L8004BAA4
/* 26DC0 8004B9C0 24080001 */   addiu    $t0, $zero, 1
.L8004B9C4:
/* 26DC4 8004B9C4 55000049 */  bnel      $t0, $zero, .L8004BAEC
/* 26DC8 8004B9C8 0280202D */   daddu    $a0, $s4, $zero
/* 26DCC 8004B9CC 30900007 */  andi      $s0, $a0, 7
/* 26DD0 8004B9D0 0600000F */  bltz      $s0, .L8004BA10
/* 26DD4 8004B9D4 00101040 */   sll      $v0, $s0, 1
/* 26DD8 8004B9D8 3125FFFF */  andi      $a1, $t1, 0xffff
/* 26DDC 8004B9DC 00501021 */  addu      $v0, $v0, $s0
/* 26DE0 8004B9E0 00021080 */  sll       $v0, $v0, 2
/* 26DE4 8004B9E4 00501023 */  subu      $v0, $v0, $s0
/* 26DE8 8004B9E8 00021080 */  sll       $v0, $v0, 2
/* 26DEC 8004B9EC 00501023 */  subu      $v0, $v0, $s0
/* 26DF0 8004B9F0 00021080 */  sll       $v0, $v0, 2
/* 26DF4 8004B9F4 2443016C */  addiu     $v1, $v0, 0x16c
.L8004B9F8:
/* 26DF8 8004B9F8 02833821 */  addu      $a3, $s4, $v1
/* 26DFC 8004B9FC 94E20096 */  lhu       $v0, 0x96($a3)
/* 26E00 8004BA00 1045FFEA */  beq       $v0, $a1, .L8004B9AC
/* 26E04 8004BA04 2610FFFF */   addiu    $s0, $s0, -1
/* 26E08 8004BA08 0601FFFB */  bgez      $s0, .L8004B9F8
/* 26E0C 8004BA0C 2463FF54 */   addiu    $v1, $v1, -0xac
.L8004BA10:
/* 26E10 8004BA10 55000036 */  bnel      $t0, $zero, .L8004BAEC
/* 26E14 8004BA14 0280202D */   daddu    $a0, $s4, $zero
/* 26E18 8004BA18 30900007 */  andi      $s0, $a0, 7
/* 26E1C 8004BA1C 0600000E */  bltz      $s0, .L8004BA58
/* 26E20 8004BA20 00101040 */   sll      $v0, $s0, 1
/* 26E24 8004BA24 00501021 */  addu      $v0, $v0, $s0
/* 26E28 8004BA28 00021080 */  sll       $v0, $v0, 2
/* 26E2C 8004BA2C 00501023 */  subu      $v0, $v0, $s0
/* 26E30 8004BA30 00021080 */  sll       $v0, $v0, 2
/* 26E34 8004BA34 00501023 */  subu      $v0, $v0, $s0
/* 26E38 8004BA38 00021080 */  sll       $v0, $v0, 2
/* 26E3C 8004BA3C 2443016C */  addiu     $v1, $v0, 0x16c
.L8004BA40:
/* 26E40 8004BA40 02833821 */  addu      $a3, $s4, $v1
/* 26E44 8004BA44 8CE20000 */  lw        $v0, ($a3)
/* 26E48 8004BA48 1040FFDA */  beqz      $v0, .L8004B9B4
/* 26E4C 8004BA4C 2610FFFF */   addiu    $s0, $s0, -1
/* 26E50 8004BA50 0601FFFB */  bgez      $s0, .L8004BA40
/* 26E54 8004BA54 2463FF54 */   addiu    $v1, $v1, -0xac
.L8004BA58:
/* 26E58 8004BA58 55000024 */  bnel      $t0, $zero, .L8004BAEC
/* 26E5C 8004BA5C 0280202D */   daddu    $a0, $s4, $zero
/* 26E60 8004BA60 30900007 */  andi      $s0, $a0, 7
/* 26E64 8004BA64 0600000F */  bltz      $s0, .L8004BAA4
/* 26E68 8004BA68 00101040 */   sll      $v0, $s0, 1
/* 26E6C 8004BA6C 00501021 */  addu      $v0, $v0, $s0
/* 26E70 8004BA70 00021080 */  sll       $v0, $v0, 2
/* 26E74 8004BA74 00501023 */  subu      $v0, $v0, $s0
/* 26E78 8004BA78 00021080 */  sll       $v0, $v0, 2
/* 26E7C 8004BA7C 00501023 */  subu      $v0, $v0, $s0
/* 26E80 8004BA80 00021080 */  sll       $v0, $v0, 2
/* 26E84 8004BA84 2443016C */  addiu     $v1, $v0, 0x16c
.L8004BA88:
/* 26E88 8004BA88 02833821 */  addu      $a3, $s4, $v1
/* 26E8C 8004BA8C 90E20098 */  lbu       $v0, 0x98($a3)
/* 26E90 8004BA90 0055102B */  sltu      $v0, $v0, $s5
/* 26E94 8004BA94 1440FFC9 */  bnez      $v0, .L8004B9BC
/* 26E98 8004BA98 2610FFFF */   addiu    $s0, $s0, -1
/* 26E9C 8004BA9C 0601FFFA */  bgez      $s0, .L8004BA88
/* 26EA0 8004BAA0 2463FF54 */   addiu    $v1, $v1, -0xac
.L8004BAA4:
/* 26EA4 8004BAA4 55000011 */  bnel      $t0, $zero, .L8004BAEC
/* 26EA8 8004BAA8 0280202D */   daddu    $a0, $s4, $zero
/* 26EAC 8004BAAC 30900007 */  andi      $s0, $a0, 7
/* 26EB0 8004BAB0 00101040 */  sll       $v0, $s0, 1
/* 26EB4 8004BAB4 00501021 */  addu      $v0, $v0, $s0
/* 26EB8 8004BAB8 00021080 */  sll       $v0, $v0, 2
/* 26EBC 8004BABC 00501023 */  subu      $v0, $v0, $s0
/* 26EC0 8004BAC0 00021080 */  sll       $v0, $v0, 2
/* 26EC4 8004BAC4 00501023 */  subu      $v0, $v0, $s0
/* 26EC8 8004BAC8 00021080 */  sll       $v0, $v0, 2
/* 26ECC 8004BACC 2442016C */  addiu     $v0, $v0, 0x16c
/* 26ED0 8004BAD0 02823821 */  addu      $a3, $s4, $v0
/* 26ED4 8004BAD4 90E20098 */  lbu       $v0, 0x98($a3)
/* 26ED8 8004BAD8 02A2102B */  sltu      $v0, $s5, $v0
/* 26EDC 8004BADC 50400001 */  beql      $v0, $zero, .L8004BAE4
/* 26EE0 8004BAE0 24080001 */   addiu    $t0, $zero, 1
.L8004BAE4:
/* 26EE4 8004BAE4 1100009F */  beqz      $t0, .L8004BD64
/* 26EE8 8004BAE8 0280202D */   daddu    $a0, $s4, $zero
.L8004BAEC:
/* 26EEC 8004BAEC 00E0282D */  daddu     $a1, $a3, $zero
.L8004BAF0:
/* 26EF0 8004BAF0 96420000 */  lhu       $v0, ($s2)
/* 26EF4 8004BAF4 8C860008 */  lw        $a2, 8($a0)
/* 26EF8 8004BAF8 02E0382D */  daddu     $a3, $s7, $zero
/* 26EFC 8004BAFC AFB50010 */  sw        $s5, 0x10($sp)
/* 26F00 8004BB00 AFA00014 */  sw        $zero, 0x14($sp)
/* 26F04 8004BB04 0C012F65 */  jal       func_8004BD94
/* 26F08 8004BB08 00463021 */   addu     $a2, $v0, $a2
/* 26F0C 8004BB0C 08012F59 */  j         .L8004BD64
/* 26F10 8004BB10 00000000 */   nop
.L8004BB14:
/* 26F14 8004BB14 96420000 */  lhu       $v0, ($s2)
/* 26F18 8004BB18 8E830008 */  lw        $v1, 8($s4)
/* 26F1C 8004BB1C 00439021 */  addu      $s2, $v0, $v1
/* 26F20 8004BB20 30821800 */  andi      $v0, $a0, 0x1800
/* 26F24 8004BB24 0002B2C2 */  srl       $s6, $v0, 0xb
/* 26F28 8004BB28 12C00005 */  beqz      $s6, .L8004BB40
/* 26F2C 8004BB2C 0280202D */   daddu    $a0, $s4, $zero
/* 26F30 8004BB30 0C012FEC */  jal       func_8004BFB0
/* 26F34 8004BB34 02C0282D */   daddu    $a1, $s6, $zero
/* 26F38 8004BB38 08012ED4 */  j         .L8004BB50
/* 26F3C 8004BB3C 2603FFFF */   addiu    $v1, $s0, -1
.L8004BB40:
/* 26F40 8004BB40 96E50000 */  lhu       $a1, ($s7)
/* 26F44 8004BB44 0C012FD5 */  jal       func_8004BF54
/* 26F48 8004BB48 0280202D */   daddu    $a0, $s4, $zero
/* 26F4C 8004BB4C 2603FFFF */  addiu     $v1, $s0, -1
.L8004BB50:
/* 26F50 8004BB50 24020002 */  addiu     $v0, $zero, 2
/* 26F54 8004BB54 1260005D */  beqz      $s3, .L8004BCCC
/* 26F58 8004BB58 00628804 */   sllv     $s1, $v0, $v1
/* 26F5C 8004BB5C 24100007 */  addiu     $s0, $zero, 7
/* 26F60 8004BB60 3C1E8008 */  lui       $fp, %hi(D_80078434)
/* 26F64 8004BB64 27DE8434 */  addiu     $fp, $fp, %lo(D_80078434)
/* 26F68 8004BB68 24130620 */  addiu     $s3, $zero, 0x620
.L8004BB6C:
/* 26F6C 8004BB6C 96420000 */  lhu       $v0, ($s2)
/* 26F70 8004BB70 10400010 */  beqz      $v0, .L8004BBB4
/* 26F74 8004BB74 02933821 */   addu     $a3, $s4, $s3
/* 26F78 8004BB78 8CE20000 */  lw        $v0, ($a3)
/* 26F7C 8004BB7C 545E0011 */  bnel      $v0, $fp, .L8004BBC4
/* 26F80 8004BB80 2610FFFF */   addiu    $s0, $s0, -1
/* 26F84 8004BB84 0280202D */  daddu     $a0, $s4, $zero
/* 26F88 8004BB88 00E0282D */  daddu     $a1, $a3, $zero
/* 26F8C 8004BB8C 02E0382D */  daddu     $a3, $s7, $zero
/* 26F90 8004BB90 96420000 */  lhu       $v0, ($s2)
/* 26F94 8004BB94 8E860008 */  lw        $a2, 8($s4)
/* 26F98 8004BB98 2631FFFF */  addiu     $s1, $s1, -1
/* 26F9C 8004BB9C AFB50010 */  sw        $s5, 0x10($sp)
/* 26FA0 8004BBA0 AFB60014 */  sw        $s6, 0x14($sp)
/* 26FA4 8004BBA4 0C012F65 */  jal       func_8004BD94
/* 26FA8 8004BBA8 00463021 */   addu     $a2, $v0, $a2
/* 26FAC 8004BBAC 08012EEE */  j         .L8004BBB8
/* 26FB0 8004BBB0 00000000 */   nop
.L8004BBB4:
/* 26FB4 8004BBB4 2631FFFF */  addiu     $s1, $s1, -1
.L8004BBB8:
/* 26FB8 8004BBB8 1A200004 */  blez      $s1, .L8004BBCC
/* 26FBC 8004BBBC 2610FFFF */   addiu    $s0, $s0, -1
/* 26FC0 8004BBC0 26520004 */  addiu     $s2, $s2, 4
.L8004BBC4:
/* 26FC4 8004BBC4 0601FFE9 */  bgez      $s0, .L8004BB6C
/* 26FC8 8004BBC8 2673FF54 */   addiu    $s3, $s3, -0xac
.L8004BBCC:
/* 26FCC 8004BBCC 12200065 */  beqz      $s1, .L8004BD64
/* 26FD0 8004BBD0 24100007 */   addiu    $s0, $zero, 7
/* 26FD4 8004BBD4 24130620 */  addiu     $s3, $zero, 0x620
.L8004BBD8:
/* 26FD8 8004BBD8 96420000 */  lhu       $v0, ($s2)
/* 26FDC 8004BBDC 10400013 */  beqz      $v0, .L8004BC2C
/* 26FE0 8004BBE0 02933821 */   addu     $a3, $s4, $s3
/* 26FE4 8004BBE4 8CE20000 */  lw        $v0, ($a3)
/* 26FE8 8004BBE8 5440000E */  bnel      $v0, $zero, .L8004BC24
/* 26FEC 8004BBEC 2673FF54 */   addiu    $s3, $s3, -0xac
/* 26FF0 8004BBF0 0280202D */  daddu     $a0, $s4, $zero
/* 26FF4 8004BBF4 00E0282D */  daddu     $a1, $a3, $zero
/* 26FF8 8004BBF8 02E0382D */  daddu     $a3, $s7, $zero
/* 26FFC 8004BBFC 96420000 */  lhu       $v0, ($s2)
/* 27000 8004BC00 8E860008 */  lw        $a2, 8($s4)
/* 27004 8004BC04 2631FFFF */  addiu     $s1, $s1, -1
/* 27008 8004BC08 AFB50010 */  sw        $s5, 0x10($sp)
/* 2700C 8004BC0C AFB60014 */  sw        $s6, 0x14($sp)
/* 27010 8004BC10 0C012F65 */  jal       func_8004BD94
/* 27014 8004BC14 00463021 */   addu     $a2, $v0, $a2
/* 27018 8004BC18 1A20000A */  blez      $s1, .L8004BC44
/* 2701C 8004BC1C 2673FF54 */   addiu    $s3, $s3, -0xac
/* 27020 8004BC20 26520004 */  addiu     $s2, $s2, 4
.L8004BC24:
/* 27024 8004BC24 08012F0F */  j         .L8004BC3C
/* 27028 8004BC28 2610FFFF */   addiu    $s0, $s0, -1
.L8004BC2C:
/* 2702C 8004BC2C 2631FFFF */  addiu     $s1, $s1, -1
/* 27030 8004BC30 1A200004 */  blez      $s1, .L8004BC44
/* 27034 8004BC34 00000000 */   nop
/* 27038 8004BC38 26520004 */  addiu     $s2, $s2, 4
.L8004BC3C:
/* 2703C 8004BC3C 0601FFE6 */  bgez      $s0, .L8004BBD8
/* 27040 8004BC40 00000000 */   nop
.L8004BC44:
/* 27044 8004BC44 12200047 */  beqz      $s1, .L8004BD64
/* 27048 8004BC48 24100007 */   addiu    $s0, $zero, 7
/* 2704C 8004BC4C 24130620 */  addiu     $s3, $zero, 0x620
.L8004BC50:
/* 27050 8004BC50 96420000 */  lhu       $v0, ($s2)
/* 27054 8004BC54 10400015 */  beqz      $v0, .L8004BCAC
/* 27058 8004BC58 02933821 */   addu     $a3, $s4, $s3
/* 2705C 8004BC5C 90E20099 */  lbu       $v0, 0x99($a3)
/* 27060 8004BC60 0056102B */  sltu      $v0, $v0, $s6
/* 27064 8004BC64 50400015 */  beql      $v0, $zero, .L8004BCBC
/* 27068 8004BC68 2610FFFF */   addiu    $s0, $s0, -1
/* 2706C 8004BC6C 90E20098 */  lbu       $v0, 0x98($a3)
/* 27070 8004BC70 02A2102B */  sltu      $v0, $s5, $v0
/* 27074 8004BC74 54400011 */  bnel      $v0, $zero, .L8004BCBC
/* 27078 8004BC78 2610FFFF */   addiu    $s0, $s0, -1
/* 2707C 8004BC7C 0280202D */  daddu     $a0, $s4, $zero
/* 27080 8004BC80 00E0282D */  daddu     $a1, $a3, $zero
/* 27084 8004BC84 02E0382D */  daddu     $a3, $s7, $zero
/* 27088 8004BC88 96420000 */  lhu       $v0, ($s2)
/* 2708C 8004BC8C 8E860008 */  lw        $a2, 8($s4)
/* 27090 8004BC90 2631FFFF */  addiu     $s1, $s1, -1
/* 27094 8004BC94 AFB50010 */  sw        $s5, 0x10($sp)
/* 27098 8004BC98 AFB60014 */  sw        $s6, 0x14($sp)
/* 2709C 8004BC9C 0C012F65 */  jal       func_8004BD94
/* 270A0 8004BCA0 00463021 */   addu     $a2, $v0, $a2
/* 270A4 8004BCA4 08012F2C */  j         .L8004BCB0
/* 270A8 8004BCA8 00000000 */   nop
.L8004BCAC:
/* 270AC 8004BCAC 2631FFFF */  addiu     $s1, $s1, -1
.L8004BCB0:
/* 270B0 8004BCB0 1A20002C */  blez      $s1, .L8004BD64
/* 270B4 8004BCB4 26520004 */   addiu    $s2, $s2, 4
/* 270B8 8004BCB8 2610FFFF */  addiu     $s0, $s0, -1
.L8004BCBC:
/* 270BC 8004BCBC 0601FFE4 */  bgez      $s0, .L8004BC50
/* 270C0 8004BCC0 2673FF54 */   addiu    $s3, $s3, -0xac
/* 270C4 8004BCC4 08012F59 */  j         .L8004BD64
/* 270C8 8004BCC8 00000000 */   nop
.L8004BCCC:
/* 270CC 8004BCCC 1A200025 */  blez      $s1, .L8004BD64
/* 270D0 8004BCD0 0000982D */   daddu    $s3, $zero, $zero
.L8004BCD4:
/* 270D4 8004BCD4 96420000 */  lhu       $v0, ($s2)
/* 270D8 8004BCD8 5040001F */  beql      $v0, $zero, .L8004BD58
/* 270DC 8004BCDC 26730001 */   addiu    $s3, $s3, 1
/* 270E0 8004BCE0 96440002 */  lhu       $a0, 2($s2)
/* 270E4 8004BCE4 30900007 */  andi      $s0, $a0, 7
/* 270E8 8004BCE8 00101040 */  sll       $v0, $s0, 1
/* 270EC 8004BCEC 00501021 */  addu      $v0, $v0, $s0
/* 270F0 8004BCF0 00021080 */  sll       $v0, $v0, 2
/* 270F4 8004BCF4 00501023 */  subu      $v0, $v0, $s0
/* 270F8 8004BCF8 00021080 */  sll       $v0, $v0, 2
/* 270FC 8004BCFC 00501023 */  subu      $v0, $v0, $s0
/* 27100 8004BD00 00021080 */  sll       $v0, $v0, 2
/* 27104 8004BD04 2442016C */  addiu     $v0, $v0, 0x16c
/* 27108 8004BD08 02823821 */  addu      $a3, $s4, $v0
/* 2710C 8004BD0C 30820300 */  andi      $v0, $a0, 0x300
/* 27110 8004BD10 8CE30000 */  lw        $v1, ($a3)
/* 27114 8004BD14 10600005 */  beqz      $v1, .L8004BD2C
/* 27118 8004BD18 0002AA02 */   srl      $s5, $v0, 8
/* 2711C 8004BD1C 90E20098 */  lbu       $v0, 0x98($a3)
/* 27120 8004BD20 02A2102B */  sltu      $v0, $s5, $v0
/* 27124 8004BD24 5440000B */  bnel      $v0, $zero, .L8004BD54
/* 27128 8004BD28 26520004 */   addiu    $s2, $s2, 4
.L8004BD2C:
/* 2712C 8004BD2C 0280202D */  daddu     $a0, $s4, $zero
/* 27130 8004BD30 00E0282D */  daddu     $a1, $a3, $zero
/* 27134 8004BD34 96420000 */  lhu       $v0, ($s2)
/* 27138 8004BD38 8E860008 */  lw        $a2, 8($s4)
/* 2713C 8004BD3C 02E0382D */  daddu     $a3, $s7, $zero
/* 27140 8004BD40 AFB50010 */  sw        $s5, 0x10($sp)
/* 27144 8004BD44 AFB60014 */  sw        $s6, 0x14($sp)
/* 27148 8004BD48 0C012F65 */  jal       func_8004BD94
/* 2714C 8004BD4C 00463021 */   addu     $a2, $v0, $a2
/* 27150 8004BD50 26520004 */  addiu     $s2, $s2, 4
.L8004BD54:
/* 27154 8004BD54 26730001 */  addiu     $s3, $s3, 1
.L8004BD58:
/* 27158 8004BD58 0271102A */  slt       $v0, $s3, $s1
/* 2715C 8004BD5C 1440FFDD */  bnez      $v0, .L8004BCD4
/* 27160 8004BD60 00000000 */   nop
.L8004BD64:
/* 27164 8004BD64 8FBF003C */  lw        $ra, 0x3c($sp)
/* 27168 8004BD68 8FBE0038 */  lw        $fp, 0x38($sp)
/* 2716C 8004BD6C 8FB70034 */  lw        $s7, 0x34($sp)
/* 27170 8004BD70 8FB60030 */  lw        $s6, 0x30($sp)
/* 27174 8004BD74 8FB5002C */  lw        $s5, 0x2c($sp)
/* 27178 8004BD78 8FB40028 */  lw        $s4, 0x28($sp)
/* 2717C 8004BD7C 8FB30024 */  lw        $s3, 0x24($sp)
/* 27180 8004BD80 8FB20020 */  lw        $s2, 0x20($sp)
/* 27184 8004BD84 8FB1001C */  lw        $s1, 0x1c($sp)
/* 27188 8004BD88 8FB00018 */  lw        $s0, 0x18($sp)
/* 2718C 8004BD8C 03E00008 */  jr        $ra
/* 27190 8004BD90 27BD0040 */   addiu    $sp, $sp, 0x40
