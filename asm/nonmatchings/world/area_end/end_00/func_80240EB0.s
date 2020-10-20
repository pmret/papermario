.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EB0
/* DF78B0 80240EB0 27BDFF90 */  addiu     $sp, $sp, -0x70
/* DF78B4 80240EB4 AFB00048 */  sw        $s0, 0x48($sp)
/* DF78B8 80240EB8 00A0802D */  daddu     $s0, $a1, $zero
/* DF78BC 80240EBC AFBF0050 */  sw        $ra, 0x50($sp)
/* DF78C0 80240EC0 AFB1004C */  sw        $s1, 0x4c($sp)
/* DF78C4 80240EC4 F7B80068 */  sdc1      $f24, 0x68($sp)
/* DF78C8 80240EC8 F7B60060 */  sdc1      $f22, 0x60($sp)
/* DF78CC 80240ECC F7B40058 */  sdc1      $f20, 0x58($sp)
/* DF78D0 80240ED0 8C82001C */  lw        $v0, 0x1c($a0)
/* DF78D4 80240ED4 0000202D */  daddu     $a0, $zero, $zero
/* DF78D8 80240ED8 0000282D */  daddu     $a1, $zero, $zero
/* DF78DC 80240EDC C6140010 */  lwc1      $f20, 0x10($s0)
/* DF78E0 80240EE0 4680A520 */  cvt.s.w   $f20, $f20
/* DF78E4 80240EE4 3C06437F */  lui       $a2, 0x437f
/* DF78E8 80240EE8 C6160014 */  lwc1      $f22, 0x14($s0)
/* DF78EC 80240EEC 4680B5A0 */  cvt.s.w   $f22, $f22
/* DF78F0 80240EF0 AFA20010 */  sw        $v0, 0x10($sp)
/* DF78F4 80240EF4 8E070018 */  lw        $a3, 0x18($s0)
/* DF78F8 80240EF8 0C00A8ED */  jal       update_lerp
/* DF78FC 80240EFC 27B10038 */   addiu    $s1, $sp, 0x38
/* DF7900 80240F00 AFB10010 */  sw        $s1, 0x10($sp)
/* DF7904 80240F04 8E040004 */  lw        $a0, 4($s0)
/* DF7908 80240F08 8E050008 */  lw        $a1, 8($s0)
/* DF790C 80240F0C 8E060000 */  lw        $a2, ($s0)
/* DF7910 80240F10 8E07000C */  lw        $a3, 0xc($s0)
/* DF7914 80240F14 0C04BA38 */  jal       func_8012E8E0
/* DF7918 80240F18 46000606 */   mov.s    $f24, $f0
/* DF791C 80240F1C 4600A08D */  trunc.w.s $f2, $f20
/* DF7920 80240F20 44021000 */  mfc1      $v0, $f2
/* DF7924 80240F24 93A50040 */  lbu       $a1, 0x40($sp)
/* DF7928 80240F28 93A60041 */  lbu       $a2, 0x41($sp)
/* DF792C 80240F2C 00021400 */  sll       $v0, $v0, 0x10
/* DF7930 80240F30 AFA00010 */  sw        $zero, 0x10($sp)
/* DF7934 80240F34 8FA3003C */  lw        $v1, 0x3c($sp)
/* DF7938 80240F38 00021403 */  sra       $v0, $v0, 0x10
/* DF793C 80240F3C AFA20018 */  sw        $v0, 0x18($sp)
/* DF7940 80240F40 4600B08D */  trunc.w.s $f2, $f22
/* DF7944 80240F44 44021000 */  mfc1      $v0, $f2
/* DF7948 80240F48 00000000 */  nop       
/* DF794C 80240F4C 00021400 */  sll       $v0, $v0, 0x10
/* DF7950 80240F50 3C014F00 */  lui       $at, 0x4f00
/* DF7954 80240F54 44810000 */  mtc1      $at, $f0
/* DF7958 80240F58 00021403 */  sra       $v0, $v0, 0x10
/* DF795C 80240F5C AFA2001C */  sw        $v0, 0x1c($sp)
/* DF7960 80240F60 2402000A */  addiu     $v0, $zero, 0xa
/* DF7964 80240F64 AFA20020 */  sw        $v0, 0x20($sp)
/* DF7968 80240F68 24020014 */  addiu     $v0, $zero, 0x14
/* DF796C 80240F6C AFA20024 */  sw        $v0, 0x24($sp)
/* DF7970 80240F70 2402012C */  addiu     $v0, $zero, 0x12c
/* DF7974 80240F74 AFA20028 */  sw        $v0, 0x28($sp)
/* DF7978 80240F78 240200C8 */  addiu     $v0, $zero, 0xc8
/* DF797C 80240F7C AFA2002C */  sw        $v0, 0x2c($sp)
/* DF7980 80240F80 4618003E */  c.le.s    $f0, $f24
/* DF7984 80240F84 00000000 */  nop       
/* DF7988 80240F88 45010005 */  bc1t      .L80240FA0
/* DF798C 80240F8C AFA30014 */   sw       $v1, 0x14($sp)
/* DF7990 80240F90 4600C08D */  trunc.w.s $f2, $f24
/* DF7994 80240F94 44031000 */  mfc1      $v1, $f2
/* DF7998 80240F98 080903EF */  j         .L80240FBC
/* DF799C 80240F9C 306200FF */   andi     $v0, $v1, 0xff
.L80240FA0:
/* DF79A0 80240FA0 4600C001 */  sub.s     $f0, $f24, $f0
/* DF79A4 80240FA4 3C028000 */  lui       $v0, 0x8000
/* DF79A8 80240FA8 4600008D */  trunc.w.s $f2, $f0
/* DF79AC 80240FAC 44031000 */  mfc1      $v1, $f2
/* DF79B0 80240FB0 00000000 */  nop       
/* DF79B4 80240FB4 00621825 */  or        $v1, $v1, $v0
/* DF79B8 80240FB8 306200FF */  andi      $v0, $v1, 0xff
.L80240FBC:
/* DF79BC 80240FBC AFA20030 */  sw        $v0, 0x30($sp)
/* DF79C0 80240FC0 8E240000 */  lw        $a0, ($s1)
/* DF79C4 80240FC4 0C04BA68 */  jal       func_8012E9A0
/* DF79C8 80240FC8 24070002 */   addiu    $a3, $zero, 2
/* DF79CC 80240FCC 8FBF0050 */  lw        $ra, 0x50($sp)
/* DF79D0 80240FD0 8FB1004C */  lw        $s1, 0x4c($sp)
/* DF79D4 80240FD4 8FB00048 */  lw        $s0, 0x48($sp)
/* DF79D8 80240FD8 D7B80068 */  ldc1      $f24, 0x68($sp)
/* DF79DC 80240FDC D7B60060 */  ldc1      $f22, 0x60($sp)
/* DF79E0 80240FE0 D7B40058 */  ldc1      $f20, 0x58($sp)
/* DF79E4 80240FE4 03E00008 */  jr        $ra
/* DF79E8 80240FE8 27BD0070 */   addiu    $sp, $sp, 0x70
