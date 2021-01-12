.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003D788
/* 18B88 8003D788 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 18B8C 8003D78C AFB00030 */  sw        $s0, 0x30($sp)
/* 18B90 8003D790 0080802D */  daddu     $s0, $a0, $zero
/* 18B94 8003D794 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 18B98 8003D798 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 18B9C 8003D79C AFBF0038 */  sw        $ra, 0x38($sp)
/* 18BA0 8003D7A0 AFB10034 */  sw        $s1, 0x34($sp)
/* 18BA4 8003D7A4 84620086 */  lh        $v0, 0x86($v1)
/* 18BA8 8003D7A8 24110005 */  addiu     $s1, $zero, 5
/* 18BAC 8003D7AC 14510004 */  bne       $v0, $s1, .L8003D7C0
/* 18BB0 8003D7B0 0000302D */   daddu    $a2, $zero, $zero
/* 18BB4 8003D7B4 8462008C */  lh        $v0, 0x8c($v1)
/* 18BB8 8003D7B8 38420002 */  xori      $v0, $v0, 2
/* 18BBC 8003D7BC 2C460001 */  sltiu     $a2, $v0, 1
.L8003D7C0:
/* 18BC0 8003D7C0 24020002 */  addiu     $v0, $zero, 2
/* 18BC4 8003D7C4 14A20026 */  bne       $a1, $v0, .L8003D860
/* 18BC8 8003D7C8 00000000 */   nop
/* 18BCC 8003D7CC C602003C */  lwc1      $f2, 0x3c($s0)
/* 18BD0 8003D7D0 44800000 */  mtc1      $zero, $f0
/* 18BD4 8003D7D4 C6040040 */  lwc1      $f4, 0x40($s0)
/* 18BD8 8003D7D8 46001080 */  add.s     $f2, $f2, $f0
/* 18BDC 8003D7DC C6000038 */  lwc1      $f0, 0x38($s0)
/* 18BE0 8003D7E0 14C00011 */  bnez      $a2, .L8003D828
/* 18BE4 8003D7E4 24040003 */   addiu    $a0, $zero, 3
/* 18BE8 8003D7E8 3C108007 */  lui       $s0, %hi(D_80077C10)
/* 18BEC 8003D7EC 26107C10 */  addiu     $s0, $s0, %lo(D_80077C10)
/* 18BF0 8003D7F0 44050000 */  mfc1      $a1, $f0
/* 18BF4 8003D7F4 44061000 */  mfc1      $a2, $f2
/* 18BF8 8003D7F8 44072000 */  mfc1      $a3, $f4
/* 18BFC 8003D7FC C6000000 */  lwc1      $f0, ($s0)
/* 18C00 8003D800 0000202D */  daddu     $a0, $zero, $zero
/* 18C04 8003D804 0C01BEB4 */  jal       fx_walk_large
/* 18C08 8003D808 E7A00010 */   swc1     $f0, 0x10($sp)
/* 18C0C 8003D80C C6000000 */  lwc1      $f0, ($s0)
/* 18C10 8003D810 3C01420C */  lui       $at, 0x420c
/* 18C14 8003D814 44816000 */  mtc1      $at, $f12
/* 18C18 8003D818 0C00A6C9 */  jal       clamp_angle
/* 18C1C 8003D81C 460C0300 */   add.s    $f12, $f0, $f12
/* 18C20 8003D820 0800F689 */  j         .L8003DA24
/* 18C24 8003D824 E6000000 */   swc1     $f0, ($s0)
.L8003D828:
/* 18C28 8003D828 44050000 */  mfc1      $a1, $f0
/* 18C2C 8003D82C 44061000 */  mfc1      $a2, $f2
/* 18C30 8003D830 44072000 */  mfc1      $a3, $f4
/* 18C34 8003D834 3C014150 */  lui       $at, 0x4150
/* 18C38 8003D838 44810000 */  mtc1      $at, $f0
/* 18C3C 8003D83C 3C014120 */  lui       $at, 0x4120
/* 18C40 8003D840 44811000 */  mtc1      $at, $f2
/* 18C44 8003D844 3C013F80 */  lui       $at, 0x3f80
/* 18C48 8003D848 44812000 */  mtc1      $at, $f4
/* 18C4C 8003D84C 2402001E */  addiu     $v0, $zero, 0x1e
/* 18C50 8003D850 AFB1001C */  sw        $s1, 0x1c($sp)
/* 18C54 8003D854 AFA20020 */  sw        $v0, 0x20($sp)
/* 18C58 8003D858 0800F686 */  j         .L8003DA18
/* 18C5C 8003D85C E7A00010 */   swc1     $f0, 0x10($sp)
.L8003D860:
/* 18C60 8003D860 10A00070 */  beqz      $a1, .L8003DA24
/* 18C64 8003D864 00000000 */   nop
/* 18C68 8003D868 3C048007 */  lui       $a0, %hi(D_80077C14)
/* 18C6C 8003D86C 24847C14 */  addiu     $a0, $a0, %lo(D_80077C14)
/* 18C70 8003D870 94820000 */  lhu       $v0, ($a0)
/* 18C74 8003D874 24430001 */  addiu     $v1, $v0, 1
/* 18C78 8003D878 00021400 */  sll       $v0, $v0, 0x10
/* 18C7C 8003D87C 00021403 */  sra       $v0, $v0, 0x10
/* 18C80 8003D880 28420004 */  slti      $v0, $v0, 4
/* 18C84 8003D884 14400067 */  bnez      $v0, .L8003DA24
/* 18C88 8003D888 A4830000 */   sh       $v1, ($a0)
/* 18C8C 8003D88C 14C00034 */  bnez      $a2, .L8003D960
/* 18C90 8003D890 A4800000 */   sh       $zero, ($a0)
/* 18C94 8003D894 C60C000C */  lwc1      $f12, 0xc($s0)
/* 18C98 8003D898 0C00A6C9 */  jal       clamp_angle
/* 18C9C 8003D89C 46006307 */   neg.s    $f12, $f12
/* 18CA0 8003D8A0 3C0140C9 */  lui       $at, 0x40c9
/* 18CA4 8003D8A4 34210FD0 */  ori       $at, $at, 0xfd0
/* 18CA8 8003D8A8 44811000 */  mtc1      $at, $f2
/* 18CAC 8003D8AC 00000000 */  nop
/* 18CB0 8003D8B0 46020002 */  mul.s     $f0, $f0, $f2
/* 18CB4 8003D8B4 00000000 */  nop
/* 18CB8 8003D8B8 27A50028 */  addiu     $a1, $sp, 0x28
/* 18CBC 8003D8BC 3C0143B4 */  lui       $at, 0x43b4
/* 18CC0 8003D8C0 44816000 */  mtc1      $at, $f12
/* 18CC4 8003D8C4 27A6002C */  addiu     $a2, $sp, 0x2c
/* 18CC8 8003D8C8 0C00A82D */  jal       sin_cos_rad
/* 18CCC 8003D8CC 460C0303 */   div.s    $f12, $f0, $f12
/* 18CD0 8003D8D0 860200A6 */  lh        $v0, 0xa6($s0)
/* 18CD4 8003D8D4 C7AA0028 */  lwc1      $f10, 0x28($sp)
/* 18CD8 8003D8D8 44821000 */  mtc1      $v0, $f2
/* 18CDC 8003D8DC 00000000 */  nop
/* 18CE0 8003D8E0 468010A0 */  cvt.s.w   $f2, $f2
/* 18CE4 8003D8E4 460A1182 */  mul.s     $f6, $f2, $f10
/* 18CE8 8003D8E8 00000000 */  nop
/* 18CEC 8003D8EC C7A8002C */  lwc1      $f8, 0x2c($sp)
/* 18CF0 8003D8F0 46081082 */  mul.s     $f2, $f2, $f8
/* 18CF4 8003D8F4 00000000 */  nop
/* 18CF8 8003D8F8 3C013E4C */  lui       $at, 0x3e4c
/* 18CFC 8003D8FC 3421CCCD */  ori       $at, $at, 0xcccd
/* 18D00 8003D900 44810000 */  mtc1      $at, $f0
/* 18D04 8003D904 00000000 */  nop
/* 18D08 8003D908 46003182 */  mul.s     $f6, $f6, $f0
/* 18D0C 8003D90C 00000000 */  nop
/* 18D10 8003D910 46001082 */  mul.s     $f2, $f2, $f0
/* 18D14 8003D914 00000000 */  nop
/* 18D18 8003D918 C604003C */  lwc1      $f4, 0x3c($s0)
/* 18D1C 8003D91C 3C013FC0 */  lui       $at, 0x3fc0
/* 18D20 8003D920 44810000 */  mtc1      $at, $f0
/* 18D24 8003D924 00000000 */  nop
/* 18D28 8003D928 46002100 */  add.s     $f4, $f4, $f0
/* 18D2C 8003D92C C6000038 */  lwc1      $f0, 0x38($s0)
/* 18D30 8003D930 46060000 */  add.s     $f0, $f0, $f6
/* 18D34 8003D934 44050000 */  mfc1      $a1, $f0
/* 18D38 8003D938 C6000040 */  lwc1      $f0, 0x40($s0)
/* 18D3C 8003D93C 46020000 */  add.s     $f0, $f0, $f2
/* 18D40 8003D940 44062000 */  mfc1      $a2, $f4
/* 18D44 8003D944 44070000 */  mfc1      $a3, $f0
/* 18D48 8003D948 0000202D */  daddu     $a0, $zero, $zero
/* 18D4C 8003D94C E7AA0010 */  swc1      $f10, 0x10($sp)
/* 18D50 8003D950 0C01BECC */  jal       fx_walk_normal
/* 18D54 8003D954 E7A80014 */   swc1     $f8, 0x14($sp)
/* 18D58 8003D958 0800F689 */  j         .L8003DA24
/* 18D5C 8003D95C 00000000 */   nop
.L8003D960:
/* 18D60 8003D960 0C00A6C9 */  jal       clamp_angle
/* 18D64 8003D964 C60C000C */   lwc1     $f12, 0xc($s0)
/* 18D68 8003D968 3C0140C9 */  lui       $at, 0x40c9
/* 18D6C 8003D96C 34210FD0 */  ori       $at, $at, 0xfd0
/* 18D70 8003D970 44811000 */  mtc1      $at, $f2
/* 18D74 8003D974 00000000 */  nop
/* 18D78 8003D978 46020002 */  mul.s     $f0, $f0, $f2
/* 18D7C 8003D97C 00000000 */  nop
/* 18D80 8003D980 27A50028 */  addiu     $a1, $sp, 0x28
/* 18D84 8003D984 3C0143B4 */  lui       $at, 0x43b4
/* 18D88 8003D988 44816000 */  mtc1      $at, $f12
/* 18D8C 8003D98C 27A6002C */  addiu     $a2, $sp, 0x2c
/* 18D90 8003D990 0C00A82D */  jal       sin_cos_rad
/* 18D94 8003D994 460C0303 */   div.s    $f12, $f0, $f12
/* 18D98 8003D998 C602003C */  lwc1      $f2, 0x3c($s0)
/* 18D9C 8003D99C 3C013FC0 */  lui       $at, 0x3fc0
/* 18DA0 8003D9A0 44810000 */  mtc1      $at, $f0
/* 18DA4 8003D9A4 860200A6 */  lh        $v0, 0xa6($s0)
/* 18DA8 8003D9A8 46001080 */  add.s     $f2, $f2, $f0
/* 18DAC 8003D9AC C7A40028 */  lwc1      $f4, 0x28($sp)
/* 18DB0 8003D9B0 44820000 */  mtc1      $v0, $f0
/* 18DB4 8003D9B4 00000000 */  nop
/* 18DB8 8003D9B8 46800020 */  cvt.s.w   $f0, $f0
/* 18DBC 8003D9BC 46040102 */  mul.s     $f4, $f0, $f4
/* 18DC0 8003D9C0 00000000 */  nop
/* 18DC4 8003D9C4 44061000 */  mfc1      $a2, $f2
/* 18DC8 8003D9C8 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* 18DCC 8003D9CC 46020002 */  mul.s     $f0, $f0, $f2
/* 18DD0 8003D9D0 00000000 */  nop
/* 18DD4 8003D9D4 24040003 */  addiu     $a0, $zero, 3
/* 18DD8 8003D9D8 C6060038 */  lwc1      $f6, 0x38($s0)
/* 18DDC 8003D9DC C6080040 */  lwc1      $f8, 0x40($s0)
/* 18DE0 8003D9E0 3C0140A0 */  lui       $at, 0x40a0
/* 18DE4 8003D9E4 44811000 */  mtc1      $at, $f2
/* 18DE8 8003D9E8 46043180 */  add.s     $f6, $f6, $f4
/* 18DEC 8003D9EC E7A20010 */  swc1      $f2, 0x10($sp)
/* 18DF0 8003D9F0 3C014120 */  lui       $at, 0x4120
/* 18DF4 8003D9F4 44811000 */  mtc1      $at, $f2
/* 18DF8 8003D9F8 46004200 */  add.s     $f8, $f8, $f0
/* 18DFC 8003D9FC 3C013F80 */  lui       $at, 0x3f80
/* 18E00 8003DA00 44812000 */  mtc1      $at, $f4
/* 18E04 8003DA04 44053000 */  mfc1      $a1, $f6
/* 18E08 8003DA08 44074000 */  mfc1      $a3, $f8
/* 18E0C 8003DA0C 2402001E */  addiu     $v0, $zero, 0x1e
/* 18E10 8003DA10 AFB1001C */  sw        $s1, 0x1c($sp)
/* 18E14 8003DA14 AFA20020 */  sw        $v0, 0x20($sp)
.L8003DA18:
/* 18E18 8003DA18 E7A20014 */  swc1      $f2, 0x14($sp)
/* 18E1C 8003DA1C 0C01C8D4 */  jal       func_80072350
/* 18E20 8003DA20 E7A40018 */   swc1     $f4, 0x18($sp)
.L8003DA24:
/* 18E24 8003DA24 8FBF0038 */  lw        $ra, 0x38($sp)
/* 18E28 8003DA28 8FB10034 */  lw        $s1, 0x34($sp)
/* 18E2C 8003DA2C 8FB00030 */  lw        $s0, 0x30($sp)
/* 18E30 8003DA30 03E00008 */  jr        $ra
/* 18E34 8003DA34 27BD0040 */   addiu    $sp, $sp, 0x40
