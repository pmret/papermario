.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel render_frame
/* 8B3C 8002D73C 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 8B40 8002D740 AFBF0054 */  sw        $ra, 0x54($sp)
/* 8B44 8002D744 AFBE0050 */  sw        $fp, 0x50($sp)
/* 8B48 8002D748 AFB7004C */  sw        $s7, 0x4c($sp)
/* 8B4C 8002D74C AFB60048 */  sw        $s6, 0x48($sp)
/* 8B50 8002D750 AFB50044 */  sw        $s5, 0x44($sp)
/* 8B54 8002D754 AFB40040 */  sw        $s4, 0x40($sp)
/* 8B58 8002D758 AFB3003C */  sw        $s3, 0x3c($sp)
/* 8B5C 8002D75C AFB20038 */  sw        $s2, 0x38($sp)
/* 8B60 8002D760 AFB10034 */  sw        $s1, 0x34($sp)
/* 8B64 8002D764 AFB00030 */  sw        $s0, 0x30($sp)
/* 8B68 8002D768 F7B80068 */  sdc1      $f24, 0x68($sp)
/* 8B6C 8002D76C F7B60060 */  sdc1      $f22, 0x60($sp)
/* 8B70 8002D770 F7B40058 */  sdc1      $f20, 0x58($sp)
/* 8B74 8002D774 14800005 */  bnez      $a0, .L8002D78C
/* 8B78 8002D778 AFA40070 */   sw       $a0, 0x70($sp)
/* 8B7C 8002D77C 3C01800A */  lui       $at, 0x800a
/* 8B80 8002D780 A420A634 */  sh        $zero, -0x59cc($at)
/* 8B84 8002D784 0C0459A6 */  jal       func_80116698
/* 8B88 8002D788 00000000 */   nop      
.L8002D78C:
/* 8B8C 8002D78C 8FAB0070 */  lw        $t3, 0x70($sp)
/* 8B90 8002D790 11600003 */  beqz      $t3, .L8002D7A0
/* 8B94 8002D794 AFA00020 */   sw       $zero, 0x20($sp)
/* 8B98 8002D798 240B0003 */  addiu     $t3, $zero, 3
/* 8B9C 8002D79C AFAB0020 */  sw        $t3, 0x20($sp)
.L8002D7A0:
/* 8BA0 8002D7A0 8FAB0070 */  lw        $t3, 0x70($sp)
/* 8BA4 8002D7A4 24020001 */  addiu     $v0, $zero, 1
/* 8BA8 8002D7A8 004B5823 */  subu      $t3, $v0, $t3
/* 8BAC 8002D7AC 24020004 */  addiu     $v0, $zero, 4
/* 8BB0 8002D7B0 004B1023 */  subu      $v0, $v0, $t3
/* 8BB4 8002D7B4 AFAB0070 */  sw        $t3, 0x70($sp)
/* 8BB8 8002D7B8 8FAB0020 */  lw        $t3, 0x20($sp)
/* 8BBC 8002D7BC 0162102A */  slt       $v0, $t3, $v0
/* 8BC0 8002D7C0 104001BD */  beqz      $v0, .L8002DEB8
/* 8BC4 8002D7C4 000B1880 */   sll      $v1, $t3, 2
/* 8BC8 8002D7C8 3C17800A */  lui       $s7, 0x800a
/* 8BCC 8002D7CC 26F7A66C */  addiu     $s7, $s7, -0x5994
/* 8BD0 8002D7D0 3C02800B */  lui       $v0, 0x800b
/* 8BD4 8002D7D4 24421D80 */  addiu     $v0, $v0, 0x1d80
/* 8BD8 8002D7D8 006B1821 */  addu      $v1, $v1, $t3
/* 8BDC 8002D7DC 00031880 */  sll       $v1, $v1, 2
/* 8BE0 8002D7E0 006B1823 */  subu      $v1, $v1, $t3
/* 8BE4 8002D7E4 000320C0 */  sll       $a0, $v1, 3
/* 8BE8 8002D7E8 00641821 */  addu      $v1, $v1, $a0
/* 8BEC 8002D7EC 000318C0 */  sll       $v1, $v1, 3
/* 8BF0 8002D7F0 0062B021 */  addu      $s6, $v1, $v0
/* 8BF4 8002D7F4 3C014080 */  lui       $at, 0x4080
/* 8BF8 8002D7F8 4481B000 */  mtc1      $at, $f22
/* 8BFC 8002D7FC 4480A000 */  mtc1      $zero, $f20
/* 8C00 8002D800 3C013F80 */  lui       $at, 0x3f80
/* 8C04 8002D804 4481C000 */  mtc1      $at, $f24
.L8002D808:
/* 8C08 8002D808 96C20000 */  lhu       $v0, ($s6)
/* 8C0C 8002D80C 104001A0 */  beqz      $v0, .L8002DE90
/* 8C10 8002D810 30420082 */   andi     $v0, $v0, 0x82
/* 8C14 8002D814 1440019E */  bnez      $v0, .L8002DE90
/* 8C18 8002D818 00000000 */   nop      
/* 8C1C 8002D81C 8EC201FC */  lw        $v0, 0x1fc($s6)
/* 8C20 8002D820 97AB0022 */  lhu       $t3, 0x22($sp)
/* 8C24 8002D824 3C01800A */  lui       $at, 0x800a
/* 8C28 8002D828 A42BA634 */  sh        $t3, -0x59cc($at)
/* 8C2C 8002D82C 50400005 */  beql      $v0, $zero, .L8002D844
/* 8C30 8002D830 3C02DC08 */   lui      $v0, 0xdc08
/* 8C34 8002D834 0040F809 */  jalr      $v0
/* 8C38 8002D838 02C0202D */   daddu    $a0, $s6, $zero
/* 8C3C 8002D83C 0800B713 */  j         .L8002DC4C
/* 8C40 8002D840 3C0A0001 */   lui      $t2, 1
.L8002D844:
/* 8C44 8002D844 34420008 */  ori       $v0, $v0, 8
/* 8C48 8002D848 3C04D9C0 */  lui       $a0, 0xd9c0
/* 8C4C 8002D84C 3484F9FB */  ori       $a0, $a0, 0xf9fb
/* 8C50 8002D850 3C05E300 */  lui       $a1, 0xe300
/* 8C54 8002D854 34A50A01 */  ori       $a1, $a1, 0xa01
/* 8C58 8002D858 3C06E300 */  lui       $a2, 0xe300
/* 8C5C 8002D85C 8EF50000 */  lw        $s5, ($s7)
/* 8C60 8002D860 34C60800 */  ori       $a2, $a2, 0x800
/* 8C64 8002D864 02A0182D */  daddu     $v1, $s5, $zero
/* 8C68 8002D868 26B50008 */  addiu     $s5, $s5, 8
/* 8C6C 8002D86C AC620000 */  sw        $v0, ($v1)
/* 8C70 8002D870 26C200A0 */  addiu     $v0, $s6, 0xa0
/* 8C74 8002D874 AC620004 */  sw        $v0, 4($v1)
/* 8C78 8002D878 3C02D700 */  lui       $v0, 0xd700
/* 8C7C 8002D87C AEA40000 */  sw        $a0, ($s5)
/* 8C80 8002D880 AEA00004 */  sw        $zero, 4($s5)
/* 8C84 8002D884 AEA20008 */  sw        $v0, 8($s5)
/* 8C88 8002D888 AEA0000C */  sw        $zero, 0xc($s5)
/* 8C8C 8002D88C AEA50010 */  sw        $a1, 0x10($s5)
/* 8C90 8002D890 AEA00014 */  sw        $zero, 0x14($s5)
/* 8C94 8002D894 AEA60018 */  sw        $a2, 0x18($s5)
/* 8C98 8002D898 AEA0001C */  sw        $zero, 0x1c($s5)
/* 8C9C 8002D89C 86D8000E */  lh        $t8, 0xe($s6)
/* 8CA0 8002D8A0 86D90010 */  lh        $t9, 0x10($s6)
/* 8CA4 8002D8A4 26A20008 */  addiu     $v0, $s5, 8
/* 8CA8 8002D8A8 AEF50000 */  sw        $s5, ($s7)
/* 8CAC 8002D8AC AEE20000 */  sw        $v0, ($s7)
/* 8CB0 8002D8B0 26A20010 */  addiu     $v0, $s5, 0x10
/* 8CB4 8002D8B4 AEE20000 */  sw        $v0, ($s7)
/* 8CB8 8002D8B8 26A20018 */  addiu     $v0, $s5, 0x18
/* 8CBC 8002D8BC AEE20000 */  sw        $v0, ($s7)
/* 8CC0 8002D8C0 26A20020 */  addiu     $v0, $s5, 0x20
/* 8CC4 8002D8C4 AEE20000 */  sw        $v0, ($s7)
/* 8CC8 8002D8C8 86C2000A */  lh        $v0, 0xa($s6)
/* 8CCC 8002D8CC 86C3000C */  lh        $v1, 0xc($s6)
/* 8CD0 8002D8D0 0302F021 */  addu      $fp, $t8, $v0
/* 8CD4 8002D8D4 07010002 */  bgez      $t8, .L8002D8E0
/* 8CD8 8002D8D8 0323A021 */   addu     $s4, $t9, $v1
/* 8CDC 8002D8DC 0000C02D */  daddu     $t8, $zero, $zero
.L8002D8E0:
/* 8CE0 8002D8E0 07220001 */  bltzl     $t9, .L8002D8E8
/* 8CE4 8002D8E4 0000C82D */   daddu    $t9, $zero, $zero
.L8002D8E8:
/* 8CE8 8002D8E8 5BC00001 */  blezl     $fp, .L8002D8F0
/* 8CEC 8002D8EC 241E0001 */   addiu    $fp, $zero, 1
.L8002D8F0:
/* 8CF0 8002D8F0 5A800001 */  blezl     $s4, .L8002D8F8
/* 8CF4 8002D8F4 24140001 */   addiu    $s4, $zero, 1
.L8002D8F8:
/* 8CF8 8002D8F8 2B020140 */  slti      $v0, $t8, 0x140
/* 8CFC 8002D8FC 50400001 */  beql      $v0, $zero, .L8002D904
/* 8D00 8002D900 2418013F */   addiu    $t8, $zero, 0x13f
.L8002D904:
/* 8D04 8002D904 2B2200F0 */  slti      $v0, $t9, 0xf0
/* 8D08 8002D908 50400001 */  beql      $v0, $zero, .L8002D910
/* 8D0C 8002D90C 241900EF */   addiu    $t9, $zero, 0xef
.L8002D910:
/* 8D10 8002D910 2BC20141 */  slti      $v0, $fp, 0x141
/* 8D14 8002D914 50400001 */  beql      $v0, $zero, .L8002D91C
/* 8D18 8002D918 241E0140 */   addiu    $fp, $zero, 0x140
.L8002D91C:
/* 8D1C 8002D91C 2A8200F1 */  slti      $v0, $s4, 0xf1
/* 8D20 8002D920 50400001 */  beql      $v0, $zero, .L8002D928
/* 8D24 8002D924 241400F0 */   addiu    $s4, $zero, 0xf0
.L8002D928:
/* 8D28 8002D928 3C03E300 */  lui       $v1, 0xe300
/* 8D2C 8002D92C 34630F00 */  ori       $v1, $v1, 0xf00
/* 8D30 8002D930 3C04E300 */  lui       $a0, 0xe300
/* 8D34 8002D934 34841001 */  ori       $a0, $a0, 0x1001
/* 8D38 8002D938 3C05E300 */  lui       $a1, 0xe300
/* 8D3C 8002D93C 34A50D01 */  ori       $a1, $a1, 0xd01
/* 8D40 8002D940 3C06E300 */  lui       $a2, 0xe300
/* 8D44 8002D944 34C60C00 */  ori       $a2, $a2, 0xc00
/* 8D48 8002D948 3C07E300 */  lui       $a3, 0xe300
/* 8D4C 8002D94C 34E71201 */  ori       $a3, $a3, 0x1201
/* 8D50 8002D950 3C08E300 */  lui       $t0, 0xe300
/* 8D54 8002D954 35081402 */  ori       $t0, $t0, 0x1402
/* 8D58 8002D958 3C0AFCFF */  lui       $t2, 0xfcff
/* 8D5C 8002D95C 354AFFFF */  ori       $t2, $t2, 0xffff
/* 8D60 8002D960 3C09FFFE */  lui       $t1, 0xfffe
/* 8D64 8002D964 3529793C */  ori       $t1, $t1, 0x793c
/* 8D68 8002D968 3C0BE300 */  lui       $t3, 0xe300
/* 8D6C 8002D96C 356B1700 */  ori       $t3, $t3, 0x1700
/* 8D70 8002D970 3C0CE200 */  lui       $t4, 0xe200
/* 8D74 8002D974 358C1E01 */  ori       $t4, $t4, 0x1e01
/* 8D78 8002D978 3C0DE200 */  lui       $t5, 0xe200
/* 8D7C 8002D97C 35AD001C */  ori       $t5, $t5, 0x1c
/* 8D80 8002D980 3C0E0F0A */  lui       $t6, 0xf0a
/* 8D84 8002D984 35CE4000 */  ori       $t6, $t6, 0x4000
/* 8D88 8002D988 3C0FE300 */  lui       $t7, 0xe300
/* 8D8C 8002D98C 35EF1801 */  ori       $t7, $t7, 0x1801
/* 8D90 8002D990 3C10DB04 */  lui       $s0, 0xdb04
/* 8D94 8002D994 36100004 */  ori       $s0, $s0, 4
/* 8D98 8002D998 3C11DB04 */  lui       $s1, 0xdb04
/* 8D9C 8002D99C 3631000C */  ori       $s1, $s1, 0xc
/* 8DA0 8002D9A0 3C12DB04 */  lui       $s2, 0xdb04
/* 8DA4 8002D9A4 36520014 */  ori       $s2, $s2, 0x14
/* 8DA8 8002D9A8 3C13DB04 */  lui       $s3, 0xdb04
/* 8DAC 8002D9AC 3673001C */  ori       $s3, $s3, 0x1c
/* 8DB0 8002D9B0 AFAB0028 */  sw        $t3, 0x28($sp)
/* 8DB4 8002D9B4 3C0BFF10 */  lui       $t3, 0xff10
/* 8DB8 8002D9B8 26A20028 */  addiu     $v0, $s5, 0x28
/* 8DBC 8002D9BC AFAB0024 */  sw        $t3, 0x24($sp)
/* 8DC0 8002D9C0 AEE20000 */  sw        $v0, ($s7)
/* 8DC4 8002D9C4 26A20030 */  addiu     $v0, $s5, 0x30
/* 8DC8 8002D9C8 AEE20000 */  sw        $v0, ($s7)
/* 8DCC 8002D9CC 26A20038 */  addiu     $v0, $s5, 0x38
/* 8DD0 8002D9D0 AEA30028 */  sw        $v1, 0x28($s5)
/* 8DD4 8002D9D4 AEA0002C */  sw        $zero, 0x2c($s5)
/* 8DD8 8002D9D8 AEE20000 */  sw        $v0, ($s7)
/* 8DDC 8002D9DC 26A20040 */  addiu     $v0, $s5, 0x40
/* 8DE0 8002D9E0 AEA40030 */  sw        $a0, 0x30($s5)
/* 8DE4 8002D9E4 AEA00034 */  sw        $zero, 0x34($s5)
/* 8DE8 8002D9E8 AEE20000 */  sw        $v0, ($s7)
/* 8DEC 8002D9EC 26A20048 */  addiu     $v0, $s5, 0x48
/* 8DF0 8002D9F0 AEA50038 */  sw        $a1, 0x38($s5)
/* 8DF4 8002D9F4 AEA0003C */  sw        $zero, 0x3c($s5)
/* 8DF8 8002D9F8 AEE20000 */  sw        $v0, ($s7)
/* 8DFC 8002D9FC 3C020008 */  lui       $v0, 8
/* 8E00 8002DA00 AEA20044 */  sw        $v0, 0x44($s5)
/* 8E04 8002DA04 26A20050 */  addiu     $v0, $s5, 0x50
/* 8E08 8002DA08 AEA60040 */  sw        $a2, 0x40($s5)
/* 8E0C 8002DA0C AEE20000 */  sw        $v0, ($s7)
/* 8E10 8002DA10 24022000 */  addiu     $v0, $zero, 0x2000
/* 8E14 8002DA14 AEA2004C */  sw        $v0, 0x4c($s5)
/* 8E18 8002DA18 26A20058 */  addiu     $v0, $s5, 0x58
/* 8E1C 8002DA1C AEA70048 */  sw        $a3, 0x48($s5)
/* 8E20 8002DA20 AEE20000 */  sw        $v0, ($s7)
/* 8E24 8002DA24 24020C00 */  addiu     $v0, $zero, 0xc00
/* 8E28 8002DA28 AEA20054 */  sw        $v0, 0x54($s5)
/* 8E2C 8002DA2C 26A20060 */  addiu     $v0, $s5, 0x60
/* 8E30 8002DA30 AEA80050 */  sw        $t0, 0x50($s5)
/* 8E34 8002DA34 AEE20000 */  sw        $v0, ($s7)
/* 8E38 8002DA38 26A20068 */  addiu     $v0, $s5, 0x68
/* 8E3C 8002DA3C 44981000 */  mtc1      $t8, $f2
/* 8E40 8002DA40 00000000 */  nop       
/* 8E44 8002DA44 468010A0 */  cvt.s.w   $f2, $f2
/* 8E48 8002DA48 46161082 */  mul.s     $f2, $f2, $f22
/* 8E4C 8002DA4C 00000000 */  nop       
/* 8E50 8002DA50 AEAA0058 */  sw        $t2, 0x58($s5)
/* 8E54 8002DA54 AEA9005C */  sw        $t1, 0x5c($s5)
/* 8E58 8002DA58 AEE20000 */  sw        $v0, ($s7)
/* 8E5C 8002DA5C 26A20070 */  addiu     $v0, $s5, 0x70
/* 8E60 8002DA60 44990000 */  mtc1      $t9, $f0
/* 8E64 8002DA64 00000000 */  nop       
/* 8E68 8002DA68 46800020 */  cvt.s.w   $f0, $f0
/* 8E6C 8002DA6C 8FAB0028 */  lw        $t3, 0x28($sp)
/* 8E70 8002DA70 46160002 */  mul.s     $f0, $f0, $f22
/* 8E74 8002DA74 00000000 */  nop       
/* 8E78 8002DA78 AEAB0060 */  sw        $t3, 0x60($s5)
/* 8E7C 8002DA7C AEA00064 */  sw        $zero, 0x64($s5)
/* 8E80 8002DA80 AEE20000 */  sw        $v0, ($s7)
/* 8E84 8002DA84 26A20078 */  addiu     $v0, $s5, 0x78
/* 8E88 8002DA88 AEAC0068 */  sw        $t4, 0x68($s5)
/* 8E8C 8002DA8C AEA0006C */  sw        $zero, 0x6c($s5)
/* 8E90 8002DA90 AEE20000 */  sw        $v0, ($s7)
/* 8E94 8002DA94 3C02ED00 */  lui       $v0, 0xed00
/* 8E98 8002DA98 AEAD0070 */  sw        $t5, 0x70($s5)
/* 8E9C 8002DA9C AEAE0074 */  sw        $t6, 0x74($s5)
/* 8EA0 8002DAA0 4600110D */  trunc.w.s $f4, $f2
/* 8EA4 8002DAA4 44042000 */  mfc1      $a0, $f4
/* 8EA8 8002DAA8 00000000 */  nop       
/* 8EAC 8002DAAC 30840FFF */  andi      $a0, $a0, 0xfff
/* 8EB0 8002DAB0 00042300 */  sll       $a0, $a0, 0xc
/* 8EB4 8002DAB4 4600010D */  trunc.w.s $f4, $f0
/* 8EB8 8002DAB8 44032000 */  mfc1      $v1, $f4
/* 8EBC 8002DABC 449E1000 */  mtc1      $fp, $f2
/* 8EC0 8002DAC0 00000000 */  nop       
/* 8EC4 8002DAC4 468010A0 */  cvt.s.w   $f2, $f2
/* 8EC8 8002DAC8 46161082 */  mul.s     $f2, $f2, $f22
/* 8ECC 8002DACC 00000000 */  nop       
/* 8ED0 8002DAD0 30630FFF */  andi      $v1, $v1, 0xfff
/* 8ED4 8002DAD4 00621825 */  or        $v1, $v1, $v0
/* 8ED8 8002DAD8 00832025 */  or        $a0, $a0, $v1
/* 8EDC 8002DADC 44940000 */  mtc1      $s4, $f0
/* 8EE0 8002DAE0 00000000 */  nop       
/* 8EE4 8002DAE4 46800020 */  cvt.s.w   $f0, $f0
/* 8EE8 8002DAE8 46160002 */  mul.s     $f0, $f0, $f22
/* 8EEC 8002DAEC 00000000 */  nop       
/* 8EF0 8002DAF0 AEA40020 */  sw        $a0, 0x20($s5)
/* 8EF4 8002DAF4 4600110D */  trunc.w.s $f4, $f2
/* 8EF8 8002DAF8 44032000 */  mfc1      $v1, $f4
/* 8EFC 8002DAFC 00000000 */  nop       
/* 8F00 8002DB00 30630FFF */  andi      $v1, $v1, 0xfff
/* 8F04 8002DB04 00031B00 */  sll       $v1, $v1, 0xc
/* 8F08 8002DB08 4600010D */  trunc.w.s $f4, $f0
/* 8F0C 8002DB0C 44022000 */  mfc1      $v0, $f4
/* 8F10 8002DB10 00000000 */  nop       
/* 8F14 8002DB14 30420FFF */  andi      $v0, $v0, 0xfff
/* 8F18 8002DB18 00621825 */  or        $v1, $v1, $v0
/* 8F1C 8002DB1C 26A20080 */  addiu     $v0, $s5, 0x80
/* 8F20 8002DB20 AEA30024 */  sw        $v1, 0x24($s5)
/* 8F24 8002DB24 AEE20000 */  sw        $v0, ($s7)
/* 8F28 8002DB28 240200C0 */  addiu     $v0, $zero, 0xc0
/* 8F2C 8002DB2C 8FAB0024 */  lw        $t3, 0x24($sp)
/* 8F30 8002DB30 3C04800A */  lui       $a0, 0x800a
/* 8F34 8002DB34 8C84A64C */  lw        $a0, -0x59b4($a0)
/* 8F38 8002DB38 356B013F */  ori       $t3, $t3, 0x13f
/* 8F3C 8002DB3C AFAB0024 */  sw        $t3, 0x24($sp)
/* 8F40 8002DB40 AEA2007C */  sw        $v0, 0x7c($s5)
/* 8F44 8002DB44 26A20088 */  addiu     $v0, $s5, 0x88
/* 8F48 8002DB48 240B0002 */  addiu     $t3, $zero, 2
/* 8F4C 8002DB4C AEAF0078 */  sw        $t7, 0x78($s5)
/* 8F50 8002DB50 AEE20000 */  sw        $v0, ($s7)
/* 8F54 8002DB54 26A20090 */  addiu     $v0, $s5, 0x90
/* 8F58 8002DB58 AEB00080 */  sw        $s0, 0x80($s5)
/* 8F5C 8002DB5C AEAB0084 */  sw        $t3, 0x84($s5)
/* 8F60 8002DB60 AEE20000 */  sw        $v0, ($s7)
/* 8F64 8002DB64 26A20098 */  addiu     $v0, $s5, 0x98
/* 8F68 8002DB68 AEAB008C */  sw        $t3, 0x8c($s5)
/* 8F6C 8002DB6C 340BFFFE */  ori       $t3, $zero, 0xfffe
/* 8F70 8002DB70 AEB10088 */  sw        $s1, 0x88($s5)
/* 8F74 8002DB74 AEE20000 */  sw        $v0, ($s7)
/* 8F78 8002DB78 26A200A0 */  addiu     $v0, $s5, 0xa0
/* 8F7C 8002DB7C AEB20090 */  sw        $s2, 0x90($s5)
/* 8F80 8002DB80 AEAB0094 */  sw        $t3, 0x94($s5)
/* 8F84 8002DB84 AEE20000 */  sw        $v0, ($s7)
/* 8F88 8002DB88 26A200A8 */  addiu     $v0, $s5, 0xa8
/* 8F8C 8002DB8C AEB30098 */  sw        $s3, 0x98($s5)
/* 8F90 8002DB90 AEAB009C */  sw        $t3, 0x9c($s5)
/* 8F94 8002DB94 AEE20000 */  sw        $v0, ($s7)
/* 8F98 8002DB98 8FAB0024 */  lw        $t3, 0x24($sp)
/* 8F9C 8002DB9C 0C0187A4 */  jal       osVirtualToPhysical
/* 8FA0 8002DBA0 AEAB00A0 */   sw       $t3, 0xa0($s5)
/* 8FA4 8002DBA4 8EE40000 */  lw        $a0, ($s7)
/* 8FA8 8002DBA8 AEA200A4 */  sw        $v0, 0xa4($s5)
/* 8FAC 8002DBAC 0080102D */  daddu     $v0, $a0, $zero
/* 8FB0 8002DBB0 3C0BE700 */  lui       $t3, 0xe700
/* 8FB4 8002DBB4 AC4B0000 */  sw        $t3, ($v0)
/* 8FB8 8002DBB8 AC400004 */  sw        $zero, 4($v0)
/* 8FBC 8002DBBC 96C20000 */  lhu       $v0, ($s6)
/* 8FC0 8002DBC0 24840008 */  addiu     $a0, $a0, 8
/* 8FC4 8002DBC4 30420010 */  andi      $v0, $v0, 0x10
/* 8FC8 8002DBC8 14400007 */  bnez      $v0, .L8002DBE8
/* 8FCC 8002DBCC AEE40000 */   sw       $a0, ($s7)
/* 8FD0 8002DBD0 3C02DB0E */  lui       $v0, 0xdb0e
/* 8FD4 8002DBD4 AC820000 */  sw        $v0, ($a0)
/* 8FD8 8002DBD8 96C30038 */  lhu       $v1, 0x38($s6)
/* 8FDC 8002DBDC 24820008 */  addiu     $v0, $a0, 8
/* 8FE0 8002DBE0 AEE20000 */  sw        $v0, ($s7)
/* 8FE4 8002DBE4 AC830004 */  sw        $v1, 4($a0)
.L8002DBE8:
/* 8FE8 8002DBE8 26C400D4 */  addiu     $a0, $s6, 0xd4
/* 8FEC 8002DBEC 3C05800A */  lui       $a1, 0x800a
/* 8FF0 8002DBF0 84A5A634 */  lh        $a1, -0x59cc($a1)
/* 8FF4 8002DBF4 3C02800A */  lui       $v0, 0x800a
/* 8FF8 8002DBF8 8C42A674 */  lw        $v0, -0x598c($v0)
/* 8FFC 8002DBFC 00052980 */  sll       $a1, $a1, 6
/* 9000 8002DC00 24A50030 */  addiu     $a1, $a1, 0x30
/* 9004 8002DC04 0C019D40 */  jal       guMtxF2L
/* 9008 8002DC08 00452821 */   addu     $a1, $v0, $a1
/* 900C 8002DC0C 3C05DA38 */  lui       $a1, 0xda38
/* 9010 8002DC10 34A50007 */  ori       $a1, $a1, 7
/* 9014 8002DC14 8EE20000 */  lw        $v0, ($s7)
/* 9018 8002DC18 3C03800A */  lui       $v1, 0x800a
/* 901C 8002DC1C 8463A634 */  lh        $v1, -0x59cc($v1)
/* 9020 8002DC20 0040202D */  daddu     $a0, $v0, $zero
/* 9024 8002DC24 24420008 */  addiu     $v0, $v0, 8
/* 9028 8002DC28 00031980 */  sll       $v1, $v1, 6
/* 902C 8002DC2C AEE20000 */  sw        $v0, ($s7)
/* 9030 8002DC30 3C02800A */  lui       $v0, 0x800a
/* 9034 8002DC34 8C42A674 */  lw        $v0, -0x598c($v0)
/* 9038 8002DC38 24630030 */  addiu     $v1, $v1, 0x30
/* 903C 8002DC3C AC850000 */  sw        $a1, ($a0)
/* 9040 8002DC40 00431021 */  addu      $v0, $v0, $v1
/* 9044 8002DC44 AC820004 */  sw        $v0, 4($a0)
/* 9048 8002DC48 3C0A0001 */  lui       $t2, 1
.L8002DC4C:
/* 904C 8002DC4C 354A1630 */  ori       $t2, $t2, 0x1630
/* 9050 8002DC50 3C098007 */  lui       $t1, 0x8007
/* 9054 8002DC54 252941F0 */  addiu     $t1, $t1, 0x41f0
/* 9058 8002DC58 4406A000 */  mfc1      $a2, $f20
/* 905C 8002DC5C 95280000 */  lhu       $t0, ($t1)
/* 9060 8002DC60 4407C000 */  mfc1      $a3, $f24
/* 9064 8002DC64 3C03800A */  lui       $v1, 0x800a
/* 9068 8002DC68 8C63A674 */  lw        $v1, -0x598c($v1)
/* 906C 8002DC6C C6C00084 */  lwc1      $f0, 0x84($s6)
/* 9070 8002DC70 3104FFFF */  andi      $a0, $t0, 0xffff
/* 9074 8002DC74 00042180 */  sll       $a0, $a0, 6
/* 9078 8002DC78 008A2021 */  addu      $a0, $a0, $t2
/* 907C 8002DC7C 00642021 */  addu      $a0, $v1, $a0
/* 9080 8002DC80 3102FFFF */  andi      $v0, $t0, 0xffff
/* 9084 8002DC84 00021180 */  sll       $v0, $v0, 6
/* 9088 8002DC88 004A1021 */  addu      $v0, $v0, $t2
/* 908C 8002DC8C 00621821 */  addu      $v1, $v1, $v0
/* 9090 8002DC90 46000007 */  neg.s     $f0, $f0
/* 9094 8002DC94 44050000 */  mfc1      $a1, $f0
/* 9098 8002DC98 25080001 */  addiu     $t0, $t0, 1
/* 909C 8002DC9C AEC30204 */  sw        $v1, 0x204($s6)
/* 90A0 8002DCA0 A5280000 */  sh        $t0, ($t1)
/* 90A4 8002DCA4 0C019F20 */  jal       guRotate
/* 90A8 8002DCA8 E7B40010 */   swc1     $f20, 0x10($sp)
/* 90AC 8002DCAC 3C048007 */  lui       $a0, 0x8007
/* 90B0 8002DCB0 8C84419C */  lw        $a0, 0x419c($a0)
/* 90B4 8002DCB4 90820082 */  lbu       $v0, 0x82($a0)
/* 90B8 8002DCB8 96C300A8 */  lhu       $v1, 0xa8($s6)
/* 90BC 8002DCBC 00021600 */  sll       $v0, $v0, 0x18
/* 90C0 8002DCC0 00021603 */  sra       $v0, $v0, 0x18
/* 90C4 8002DCC4 00621821 */  addu      $v1, $v1, $v0
/* 90C8 8002DCC8 A6C300B8 */  sh        $v1, 0xb8($s6)
/* 90CC 8002DCCC 90830083 */  lbu       $v1, 0x83($a0)
/* 90D0 8002DCD0 96C200AA */  lhu       $v0, 0xaa($s6)
/* 90D4 8002DCD4 96C40000 */  lhu       $a0, ($s6)
/* 90D8 8002DCD8 00031E00 */  sll       $v1, $v1, 0x18
/* 90DC 8002DCDC 00031E03 */  sra       $v1, $v1, 0x18
/* 90E0 8002DCE0 00431021 */  addu      $v0, $v0, $v1
/* 90E4 8002DCE4 A6C200BA */  sh        $v0, 0xba($s6)
/* 90E8 8002DCE8 30820010 */  andi      $v0, $a0, 0x10
/* 90EC 8002DCEC 14400048 */  bnez      $v0, .L8002DE10
/* 90F0 8002DCF0 24020003 */   addiu    $v0, $zero, 3
/* 90F4 8002DCF4 3C03800A */  lui       $v1, 0x800a
/* 90F8 8002DCF8 8463A634 */  lh        $v1, -0x59cc($v1)
/* 90FC 8002DCFC 10620019 */  beq       $v1, $v0, .L8002DD64
/* 9100 8002DD00 30820200 */   andi     $v0, $a0, 0x200
/* 9104 8002DD04 14400003 */  bnez      $v0, .L8002DD14
/* 9108 8002DD08 00000000 */   nop      
/* 910C 8002DD0C 0C043FAD */  jal       render_entities
/* 9110 8002DD10 00000000 */   nop      
.L8002DD14:
/* 9114 8002DD14 96C20000 */  lhu       $v0, ($s6)
/* 9118 8002DD18 30420400 */  andi      $v0, $v0, 0x400
/* 911C 8002DD1C 14400003 */  bnez      $v0, .L8002DD2C
/* 9120 8002DD20 00000000 */   nop      
/* 9124 8002DD24 0C045AE4 */  jal       render_models
/* 9128 8002DD28 00000000 */   nop      
.L8002DD2C:
/* 912C 8002DD2C 0C03844E */  jal       render_player
/* 9130 8002DD30 00000000 */   nop      
/* 9134 8002DD34 0C00E9FC */  jal       render_npcs
/* 9138 8002DD38 00000000 */   nop      
/* 913C 8002DD3C 0C048D1C */  jal       render_dynamic_entities
/* 9140 8002DD40 00000000 */   nop      
/* 9144 8002DD44 0C0167BD */  jal       render_effects
/* 9148 8002DD48 00000000 */   nop      
/* 914C 8002DD4C 0C04766E */  jal       func_8011D9B8
/* 9150 8002DD50 00000000 */   nop      
/* 9154 8002DD54 0C050DAD */  jal       render_menu_icons
/* 9158 8002DD58 00000000 */   nop      
/* 915C 8002DD5C 0800B788 */  j         .L8002DE20
/* 9160 8002DD60 00000000 */   nop      
.L8002DD64:
/* 9164 8002DD64 26D000D4 */  addiu     $s0, $s6, 0xd4
/* 9168 8002DD68 4405A000 */  mfc1      $a1, $f20
/* 916C 8002DD6C 3C0643A0 */  lui       $a2, 0x43a0
/* 9170 8002DD70 3C07C370 */  lui       $a3, 0xc370
/* 9174 8002DD74 3C01C47A */  lui       $at, 0xc47a
/* 9178 8002DD78 44810000 */  mtc1      $at, $f0
/* 917C 8002DD7C 3C01447A */  lui       $at, 0x447a
/* 9180 8002DD80 44811000 */  mtc1      $at, $f2
/* 9184 8002DD84 0200202D */  daddu     $a0, $s0, $zero
/* 9188 8002DD88 E7B40010 */  swc1      $f20, 0x10($sp)
/* 918C 8002DD8C E7B8001C */  swc1      $f24, 0x1c($sp)
/* 9190 8002DD90 E7A00014 */  swc1      $f0, 0x14($sp)
/* 9194 8002DD94 0C018E44 */  jal       guOrthoF
/* 9198 8002DD98 E7A20018 */   swc1     $f2, 0x18($sp)
/* 919C 8002DD9C 0200202D */  daddu     $a0, $s0, $zero
/* 91A0 8002DDA0 3C05800A */  lui       $a1, 0x800a
/* 91A4 8002DDA4 84A5A634 */  lh        $a1, -0x59cc($a1)
/* 91A8 8002DDA8 3C02800A */  lui       $v0, 0x800a
/* 91AC 8002DDAC 8C42A674 */  lw        $v0, -0x598c($v0)
/* 91B0 8002DDB0 00052980 */  sll       $a1, $a1, 6
/* 91B4 8002DDB4 24A50030 */  addiu     $a1, $a1, 0x30
/* 91B8 8002DDB8 0C019D40 */  jal       guMtxF2L
/* 91BC 8002DDBC 00452821 */   addu     $a1, $v0, $a1
/* 91C0 8002DDC0 3C05DA38 */  lui       $a1, 0xda38
/* 91C4 8002DDC4 34A50007 */  ori       $a1, $a1, 7
/* 91C8 8002DDC8 8EE20000 */  lw        $v0, ($s7)
/* 91CC 8002DDCC 3C03800A */  lui       $v1, 0x800a
/* 91D0 8002DDD0 8463A634 */  lh        $v1, -0x59cc($v1)
/* 91D4 8002DDD4 0040202D */  daddu     $a0, $v0, $zero
/* 91D8 8002DDD8 24420008 */  addiu     $v0, $v0, 8
/* 91DC 8002DDDC 00031980 */  sll       $v1, $v1, 6
/* 91E0 8002DDE0 AEE20000 */  sw        $v0, ($s7)
/* 91E4 8002DDE4 3C02800A */  lui       $v0, 0x800a
/* 91E8 8002DDE8 8C42A674 */  lw        $v0, -0x598c($v0)
/* 91EC 8002DDEC 24630030 */  addiu     $v1, $v1, 0x30
/* 91F0 8002DDF0 AC850000 */  sw        $a1, ($a0)
/* 91F4 8002DDF4 00431021 */  addu      $v0, $v0, $v1
/* 91F8 8002DDF8 0C050DAD */  jal       render_menu_icons
/* 91FC 8002DDFC AC820004 */   sw       $v0, 4($a0)
/* 9200 8002DE00 0C04CB95 */  jal       render_item_entities
/* 9204 8002DE04 00000000 */   nop      
/* 9208 8002DE08 0800B788 */  j         .L8002DE20
/* 920C 8002DE0C 00000000 */   nop      
.L8002DE10:
/* 9210 8002DE10 0C048D1C */  jal       render_dynamic_entities
/* 9214 8002DE14 00000000 */   nop      
/* 9218 8002DE18 0C04766E */  jal       func_8011D9B8
/* 921C 8002DE1C 00000000 */   nop      
.L8002DE20:
/* 9220 8002DE20 8EC20200 */  lw        $v0, 0x200($s6)
/* 9224 8002DE24 10400004 */  beqz      $v0, .L8002DE38
/* 9228 8002DE28 3C03FF10 */   lui      $v1, 0xff10
/* 922C 8002DE2C 0040F809 */  jalr      $v0
/* 9230 8002DE30 02C0202D */   daddu    $a0, $s6, $zero
/* 9234 8002DE34 3C03FF10 */  lui       $v1, 0xff10
.L8002DE38:
/* 9238 8002DE38 3463013F */  ori       $v1, $v1, 0x13f
/* 923C 8002DE3C 8EF00000 */  lw        $s0, ($s7)
/* 9240 8002DE40 3C04800A */  lui       $a0, 0x800a
/* 9244 8002DE44 8C84A64C */  lw        $a0, -0x59b4($a0)
/* 9248 8002DE48 0200102D */  daddu     $v0, $s0, $zero
/* 924C 8002DE4C 26100008 */  addiu     $s0, $s0, 8
/* 9250 8002DE50 3C0BE700 */  lui       $t3, 0xe700
/* 9254 8002DE54 AEF00000 */  sw        $s0, ($s7)
/* 9258 8002DE58 AC4B0000 */  sw        $t3, ($v0)
/* 925C 8002DE5C AC400004 */  sw        $zero, 4($v0)
/* 9260 8002DE60 26020008 */  addiu     $v0, $s0, 8
/* 9264 8002DE64 AEE20000 */  sw        $v0, ($s7)
/* 9268 8002DE68 0C0187A4 */  jal       osVirtualToPhysical
/* 926C 8002DE6C AE030000 */   sw       $v1, ($s0)
/* 9270 8002DE70 8EE30000 */  lw        $v1, ($s7)
/* 9274 8002DE74 AE020004 */  sw        $v0, 4($s0)
/* 9278 8002DE78 0060102D */  daddu     $v0, $v1, $zero
/* 927C 8002DE7C 24630008 */  addiu     $v1, $v1, 8
/* 9280 8002DE80 3C0BE700 */  lui       $t3, 0xe700
/* 9284 8002DE84 AEE30000 */  sw        $v1, ($s7)
/* 9288 8002DE88 AC4B0000 */  sw        $t3, ($v0)
/* 928C 8002DE8C AC400004 */  sw        $zero, 4($v0)
.L8002DE90:
/* 9290 8002DE90 8FAB0020 */  lw        $t3, 0x20($sp)
/* 9294 8002DE94 256B0001 */  addiu     $t3, $t3, 1
/* 9298 8002DE98 AFAB0020 */  sw        $t3, 0x20($sp)
/* 929C 8002DE9C 8FAB0070 */  lw        $t3, 0x70($sp)
/* 92A0 8002DEA0 24020004 */  addiu     $v0, $zero, 4
/* 92A4 8002DEA4 004B1023 */  subu      $v0, $v0, $t3
/* 92A8 8002DEA8 8FAB0020 */  lw        $t3, 0x20($sp)
/* 92AC 8002DEAC 0162102A */  slt       $v0, $t3, $v0
/* 92B0 8002DEB0 1440FE55 */  bnez      $v0, .L8002D808
/* 92B4 8002DEB4 26D60558 */   addiu    $s6, $s6, 0x558
.L8002DEB8:
/* 92B8 8002DEB8 8FBF0054 */  lw        $ra, 0x54($sp)
/* 92BC 8002DEBC 8FBE0050 */  lw        $fp, 0x50($sp)
/* 92C0 8002DEC0 8FB7004C */  lw        $s7, 0x4c($sp)
/* 92C4 8002DEC4 8FB60048 */  lw        $s6, 0x48($sp)
/* 92C8 8002DEC8 8FB50044 */  lw        $s5, 0x44($sp)
/* 92CC 8002DECC 8FB40040 */  lw        $s4, 0x40($sp)
/* 92D0 8002DED0 8FB3003C */  lw        $s3, 0x3c($sp)
/* 92D4 8002DED4 8FB20038 */  lw        $s2, 0x38($sp)
/* 92D8 8002DED8 8FB10034 */  lw        $s1, 0x34($sp)
/* 92DC 8002DEDC 8FB00030 */  lw        $s0, 0x30($sp)
/* 92E0 8002DEE0 D7B80068 */  ldc1      $f24, 0x68($sp)
/* 92E4 8002DEE4 D7B60060 */  ldc1      $f22, 0x60($sp)
/* 92E8 8002DEE8 D7B40058 */  ldc1      $f20, 0x58($sp)
/* 92EC 8002DEEC 03E00008 */  jr        $ra
/* 92F0 8002DEF0 27BD0070 */   addiu    $sp, $sp, 0x70
