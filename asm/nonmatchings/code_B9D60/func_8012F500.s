.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8012F500
/* C5C00 8012F500 27BDFF88 */  addiu     $sp, $sp, -0x78
/* C5C04 8012F504 C7A800A4 */  lwc1      $f8, 0xa4($sp)
/* C5C08 8012F508 3C018015 */  lui       $at, %hi(D_80150A40)
/* C5C0C 8012F50C D4220A40 */  ldc1      $f2, %lo(D_80150A40)($at)
/* C5C10 8012F510 8FA2008C */  lw        $v0, 0x8c($sp)
/* C5C14 8012F514 AFA40078 */  sw        $a0, 0x78($sp)
/* C5C18 8012F518 8FA40090 */  lw        $a0, 0x90($sp)
/* C5C1C 8012F51C C7AA00A8 */  lwc1      $f10, 0xa8($sp)
/* C5C20 8012F520 AFB5005C */  sw        $s5, 0x5c($sp)
/* C5C24 8012F524 93B5008B */  lbu       $s5, 0x8b($sp)
/* C5C28 8012F528 97A30096 */  lhu       $v1, 0x96($sp)
/* C5C2C 8012F52C 97A8009A */  lhu       $t0, 0x9a($sp)
/* C5C30 8012F530 A3A70027 */  sb        $a3, 0x27($sp)
/* C5C34 8012F534 97A700A2 */  lhu       $a3, 0xa2($sp)
/* C5C38 8012F538 AFB30054 */  sw        $s3, 0x54($sp)
/* C5C3C 8012F53C 00A0982D */  daddu     $s3, $a1, $zero
/* C5C40 8012F540 AFBE0068 */  sw        $fp, 0x68($sp)
/* C5C44 8012F544 AFB70064 */  sw        $s7, 0x64($sp)
/* C5C48 8012F548 AFB60060 */  sw        $s6, 0x60($sp)
/* C5C4C 8012F54C AFB40058 */  sw        $s4, 0x58($sp)
/* C5C50 8012F550 AFB20050 */  sw        $s2, 0x50($sp)
/* C5C54 8012F554 AFB1004C */  sw        $s1, 0x4c($sp)
/* C5C58 8012F558 AFB00048 */  sw        $s0, 0x48($sp)
/* C5C5C 8012F55C F7B40070 */  sdc1      $f20, 0x70($sp)
/* C5C60 8012F560 AFA60080 */  sw        $a2, 0x80($sp)
/* C5C64 8012F564 46004021 */  cvt.d.s   $f0, $f8
/* C5C68 8012F568 A3B50028 */  sb        $s5, 0x28($sp)
/* C5C6C 8012F56C 97B5009E */  lhu       $s5, 0x9e($sp)
/* C5C70 8012F570 4622003C */  c.lt.d    $f0, $f2
/* C5C74 8012F574 00000000 */  nop       
/* C5C78 8012F578 45010046 */  bc1t      .L8012F694
/* C5C7C 8012F57C A7B50036 */   sh       $s5, 0x36($sp)
/* C5C80 8012F580 460051A1 */  cvt.d.s   $f6, $f10
/* C5C84 8012F584 4622303C */  c.lt.d    $f6, $f2
/* C5C88 8012F588 00000000 */  nop       
/* C5C8C 8012F58C 45030214 */  bc1tl     .L8012FDE0
/* C5C90 8012F590 0000102D */   daddu    $v0, $zero, $zero
/* C5C94 8012F594 00021400 */  sll       $v0, $v0, 0x10
/* C5C98 8012F598 00022C03 */  sra       $a1, $v0, 0x10
/* C5C9C 8012F59C 97B50036 */  lhu       $s5, 0x36($sp)
/* C5CA0 8012F5A0 3066FFFF */  andi      $a2, $v1, 0xffff
/* C5CA4 8012F5A4 02A61021 */  addu      $v0, $s5, $a2
/* C5CA8 8012F5A8 00A2102A */  slt       $v0, $a1, $v0
/* C5CAC 8012F5AC 10400039 */  beqz      $v0, .L8012F694
/* C5CB0 8012F5B0 00041400 */   sll      $v0, $a0, 0x10
/* C5CB4 8012F5B4 00022403 */  sra       $a0, $v0, 0x10
/* C5CB8 8012F5B8 3103FFFF */  andi      $v1, $t0, 0xffff
/* C5CBC 8012F5BC 00E33821 */  addu      $a3, $a3, $v1
/* C5CC0 8012F5C0 0087102A */  slt       $v0, $a0, $a3
/* C5CC4 8012F5C4 10400206 */  beqz      $v0, .L8012FDE0
/* C5CC8 8012F5C8 0000102D */   daddu    $v0, $zero, $zero
/* C5CCC 8012F5CC 44931000 */  mtc1      $s3, $f2
/* C5CD0 8012F5D0 00000000 */  nop       
/* C5CD4 8012F5D4 468010A1 */  cvt.d.w   $f2, $f2
/* C5CD8 8012F5D8 44852000 */  mtc1      $a1, $f4
/* C5CDC 8012F5DC 00000000 */  nop       
/* C5CE0 8012F5E0 46802120 */  cvt.s.w   $f4, $f4
/* C5CE4 8012F5E4 06630007 */  bgezl     $s3, .L8012F604
/* C5CE8 8012F5E8 46201020 */   cvt.s.d  $f0, $f2
/* C5CEC 8012F5EC 3C0141F0 */  lui       $at, 0x41f0
/* C5CF0 8012F5F0 44810800 */  mtc1      $at, $f1
/* C5CF4 8012F5F4 44800000 */  mtc1      $zero, $f0
/* C5CF8 8012F5F8 00000000 */  nop       
/* C5CFC 8012F5FC 46201080 */  add.d     $f2, $f2, $f0
/* C5D00 8012F600 46201020 */  cvt.s.d   $f0, $f2
.L8012F604:
/* C5D04 8012F604 46080002 */  mul.s     $f0, $f0, $f8
/* C5D08 8012F608 00000000 */  nop       
/* C5D0C 8012F60C 46002000 */  add.s     $f0, $f4, $f0
/* C5D10 8012F610 4600050D */  trunc.w.s $f20, $f0
/* C5D14 8012F614 4402A000 */  mfc1      $v0, $f20
/* C5D18 8012F618 00000000 */  nop       
/* C5D1C 8012F61C 00021400 */  sll       $v0, $v0, 0x10
/* C5D20 8012F620 00021403 */  sra       $v0, $v0, 0x10
/* C5D24 8012F624 00C2102A */  slt       $v0, $a2, $v0
/* C5D28 8012F628 104001ED */  beqz      $v0, .L8012FDE0
/* C5D2C 8012F62C 0000102D */   daddu    $v0, $zero, $zero
/* C5D30 8012F630 C7A20080 */  lwc1      $f2, 0x80($sp)
/* C5D34 8012F634 468010A1 */  cvt.d.w   $f2, $f2
/* C5D38 8012F638 8FB50080 */  lw        $s5, 0x80($sp)
/* C5D3C 8012F63C 44842000 */  mtc1      $a0, $f4
/* C5D40 8012F640 00000000 */  nop       
/* C5D44 8012F644 46802120 */  cvt.s.w   $f4, $f4
/* C5D48 8012F648 06A30007 */  bgezl     $s5, .L8012F668
/* C5D4C 8012F64C 46201020 */   cvt.s.d  $f0, $f2
/* C5D50 8012F650 3C0141F0 */  lui       $at, 0x41f0
/* C5D54 8012F654 44810800 */  mtc1      $at, $f1
/* C5D58 8012F658 44800000 */  mtc1      $zero, $f0
/* C5D5C 8012F65C 00000000 */  nop       
/* C5D60 8012F660 46201080 */  add.d     $f2, $f2, $f0
/* C5D64 8012F664 46201020 */  cvt.s.d   $f0, $f2
.L8012F668:
/* C5D68 8012F668 460A0002 */  mul.s     $f0, $f0, $f10
/* C5D6C 8012F66C 00000000 */  nop       
/* C5D70 8012F670 46002000 */  add.s     $f0, $f4, $f0
/* C5D74 8012F674 4600050D */  trunc.w.s $f20, $f0
/* C5D78 8012F678 4402A000 */  mfc1      $v0, $f20
/* C5D7C 8012F67C 00000000 */  nop       
/* C5D80 8012F680 00021400 */  sll       $v0, $v0, 0x10
/* C5D84 8012F684 00021403 */  sra       $v0, $v0, 0x10
/* C5D88 8012F688 0062102A */  slt       $v0, $v1, $v0
/* C5D8C 8012F68C 14400003 */  bnez      $v0, .L8012F69C
/* C5D90 8012F690 0000C82D */   daddu    $t9, $zero, $zero
.L8012F694:
/* C5D94 8012F694 0804BF78 */  j         .L8012FDE0
/* C5D98 8012F698 0000102D */   daddu    $v0, $zero, $zero
.L8012F69C:
/* C5D9C 8012F69C 0060702D */  daddu     $t6, $v1, $zero
/* C5DA0 8012F6A0 0080B82D */  daddu     $s7, $a0, $zero
/* C5DA4 8012F6A4 02EE1023 */  subu      $v0, $s7, $t6
/* C5DA8 8012F6A8 04420001 */  bltzl     $v0, .L8012F6B0
/* C5DAC 8012F6AC 00021023 */   negu     $v0, $v0
.L8012F6B0:
/* C5DB0 8012F6B0 3C014040 */  lui       $at, 0x4040
/* C5DB4 8012F6B4 44812800 */  mtc1      $at, $f5
/* C5DB8 8012F6B8 44802000 */  mtc1      $zero, $f4
/* C5DBC 8012F6BC 00E0A02D */  daddu     $s4, $a3, $zero
/* C5DC0 8012F6C0 46243102 */  mul.d     $f4, $f6, $f4
/* C5DC4 8012F6C4 00000000 */  nop       
/* C5DC8 8012F6C8 00A0802D */  daddu     $s0, $a1, $zero
/* C5DCC 8012F6CC 3C014200 */  lui       $at, 0x4200
/* C5DD0 8012F6D0 44817000 */  mtc1      $at, $f14
/* C5DD4 8012F6D4 3C013F80 */  lui       $at, 0x3f80
/* C5DD8 8012F6D8 44811000 */  mtc1      $at, $f2
/* C5DDC 8012F6DC 3C014050 */  lui       $at, 0x4050
/* C5DE0 8012F6E0 44819800 */  mtc1      $at, $f19
/* C5DE4 8012F6E4 44809000 */  mtc1      $zero, $f18
/* C5DE8 8012F6E8 3C018015 */  lui       $at, %hi(D_80150A48)
/* C5DEC 8012F6EC D42C0A48 */  ldc1      $f12, %lo(D_80150A48)($at)
/* C5DF0 8012F6F0 3C014480 */  lui       $at, 0x4480
/* C5DF4 8012F6F4 44813000 */  mtc1      $at, $f6
/* C5DF8 8012F6F8 46081003 */  div.s     $f0, $f2, $f8
/* C5DFC 8012F6FC 46060002 */  mul.s     $f0, $f0, $f6
/* C5E00 8012F700 00000000 */  nop       
/* C5E04 8012F704 3C014280 */  lui       $at, 0x4280
/* C5E08 8012F708 44818000 */  mtc1      $at, $f16
/* C5E0C 8012F70C 00C0502D */  daddu     $t2, $a2, $zero
/* C5E10 8012F710 AFA2003C */  sw        $v0, 0x3c($sp)
/* C5E14 8012F714 460A1083 */  div.s     $f2, $f2, $f10
/* C5E18 8012F718 46061082 */  mul.s     $f2, $f2, $f6
/* C5E1C 8012F71C 00000000 */  nop       
/* C5E20 8012F720 AFA00004 */  sw        $zero, 4($sp)
/* C5E24 8012F724 AFB70014 */  sw        $s7, 0x14($sp)
/* C5E28 8012F728 4600050D */  trunc.w.s $f20, $f0
/* C5E2C 8012F72C E7B40038 */  swc1      $f20, 0x38($sp)
/* C5E30 8012F730 3C013FE0 */  lui       $at, 0x3fe0
/* C5E34 8012F734 44810800 */  mtc1      $at, $f1
/* C5E38 8012F738 44800000 */  mtc1      $zero, $f0
/* C5E3C 8012F73C 4600150D */  trunc.w.s $f20, $f2
/* C5E40 8012F740 441EA000 */  mfc1      $fp, $f20
/* C5E44 8012F744 46202100 */  add.d     $f4, $f4, $f0
.L8012F748:
/* C5E48 8012F748 C7A00014 */  lwc1      $f0, 0x14($sp)
/* C5E4C 8012F74C 46800021 */  cvt.d.w   $f0, $f0
/* C5E50 8012F750 8FA20004 */  lw        $v0, 4($sp)
/* C5E54 8012F754 46240000 */  add.d     $f0, $f0, $f4
/* C5E58 8012F758 2442001F */  addiu     $v0, $v0, 0x1f
/* C5E5C 8012F75C AFA2000C */  sw        $v0, 0xc($sp)
/* C5E60 8012F760 4620050D */  trunc.w.d $f20, $f0
/* C5E64 8012F764 4402A000 */  mfc1      $v0, $f20
/* C5E68 8012F768 00000000 */  nop       
/* C5E6C 8012F76C AFA2001C */  sw        $v0, 0x1c($sp)
/* C5E70 8012F770 01C2102A */  slt       $v0, $t6, $v0
/* C5E74 8012F774 14400014 */  bnez      $v0, .L8012F7C8
/* C5E78 8012F778 0000902D */   daddu    $s2, $zero, $zero
/* C5E7C 8012F77C 460E5082 */  mul.s     $f2, $f10, $f14
/* C5E80 8012F780 00000000 */  nop       
.L8012F784:
/* C5E84 8012F784 8FA40004 */  lw        $a0, 4($sp)
/* C5E88 8012F788 8FA2001C */  lw        $v0, 0x1c($sp)
/* C5E8C 8012F78C 24830020 */  addiu     $v1, $a0, 0x20
/* C5E90 8012F790 44820000 */  mtc1      $v0, $f0
/* C5E94 8012F794 00000000 */  nop       
/* C5E98 8012F798 46800020 */  cvt.s.w   $f0, $f0
/* C5E9C 8012F79C 46020000 */  add.s     $f0, $f0, $f2
/* C5EA0 8012F7A0 AFA30004 */  sw        $v1, 4($sp)
/* C5EA4 8012F7A4 AFA20014 */  sw        $v0, 0x14($sp)
/* C5EA8 8012F7A8 4600050D */  trunc.w.s $f20, $f0
/* C5EAC 8012F7AC 4402A000 */  mfc1      $v0, $f20
/* C5EB0 8012F7B0 00000000 */  nop       
/* C5EB4 8012F7B4 AFA2001C */  sw        $v0, 0x1c($sp)
/* C5EB8 8012F7B8 004E102A */  slt       $v0, $v0, $t6
/* C5EBC 8012F7BC 1440FFF1 */  bnez      $v0, .L8012F784
/* C5EC0 8012F7C0 2482003F */   addiu    $v0, $a0, 0x3f
/* C5EC4 8012F7C4 AFA2000C */  sw        $v0, 0xc($sp)
.L8012F7C8:
/* C5EC8 8012F7C8 8FA20014 */  lw        $v0, 0x14($sp)
/* C5ECC 8012F7CC 004E102A */  slt       $v0, $v0, $t6
/* C5ED0 8012F7D0 10400009 */  beqz      $v0, .L8012F7F8
/* C5ED4 8012F7D4 00000000 */   nop      
/* C5ED8 8012F7D8 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* C5EDC 8012F7DC 46800020 */  cvt.s.w   $f0, $f0
/* C5EE0 8012F7E0 460A0003 */  div.s     $f0, $f0, $f10
/* C5EE4 8012F7E4 460E0002 */  mul.s     $f0, $f0, $f14
/* C5EE8 8012F7E8 00000000 */  nop       
/* C5EEC 8012F7EC AFAE0014 */  sw        $t6, 0x14($sp)
/* C5EF0 8012F7F0 4600050D */  trunc.w.s $f20, $f0
/* C5EF4 8012F7F4 4412A000 */  mfc1      $s2, $f20
.L8012F7F8:
/* C5EF8 8012F7F8 8FA2000C */  lw        $v0, 0xc($sp)
/* C5EFC 8012F7FC 8FB50080 */  lw        $s5, 0x80($sp)
/* C5F00 8012F800 24420001 */  addiu     $v0, $v0, 1
/* C5F04 8012F804 0055102B */  sltu      $v0, $v0, $s5
/* C5F08 8012F808 14400014 */  bnez      $v0, .L8012F85C
/* C5F0C 8012F80C 26A3FFFF */   addiu    $v1, $s5, -1
/* C5F10 8012F810 44830000 */  mtc1      $v1, $f0
/* C5F14 8012F814 00000000 */  nop       
/* C5F18 8012F818 46800020 */  cvt.s.w   $f0, $f0
/* C5F1C 8012F81C 460A0002 */  mul.s     $f0, $f0, $f10
/* C5F20 8012F820 00000000 */  nop       
/* C5F24 8012F824 4600050D */  trunc.w.s $f20, $f0
/* C5F28 8012F828 4402A000 */  mfc1      $v0, $f20
/* C5F2C 8012F82C 00000000 */  nop       
/* C5F30 8012F830 00021400 */  sll       $v0, $v0, 0x10
/* C5F34 8012F834 00021403 */  sra       $v0, $v0, 0x10
/* C5F38 8012F838 02E21021 */  addu      $v0, $s7, $v0
/* C5F3C 8012F83C 44820000 */  mtc1      $v0, $f0
/* C5F40 8012F840 00000000 */  nop       
/* C5F44 8012F844 46800020 */  cvt.s.w   $f0, $f0
/* C5F48 8012F848 460A0000 */  add.s     $f0, $f0, $f10
/* C5F4C 8012F84C AFA3000C */  sw        $v1, 0xc($sp)
/* C5F50 8012F850 24190001 */  addiu     $t9, $zero, 1
/* C5F54 8012F854 4600050D */  trunc.w.s $f20, $f0
/* C5F58 8012F858 E7B4001C */  swc1      $f20, 0x1c($sp)
.L8012F85C:
/* C5F5C 8012F85C 8FA2001C */  lw        $v0, 0x1c($sp)
/* C5F60 8012F860 0282102A */  slt       $v0, $s4, $v0
/* C5F64 8012F864 10400004 */  beqz      $v0, .L8012F878
/* C5F68 8012F868 332200FF */   andi     $v0, $t9, 0xff
/* C5F6C 8012F86C 14400002 */  bnez      $v0, .L8012F878
/* C5F70 8012F870 AFB4001C */   sw       $s4, 0x1c($sp)
/* C5F74 8012F874 24190001 */  addiu     $t9, $zero, 1
.L8012F878:
/* C5F78 8012F878 0000582D */  daddu     $t3, $zero, $zero
/* C5F7C 8012F87C 020A1023 */  subu      $v0, $s0, $t2
/* C5F80 8012F880 04410002 */  bgez      $v0, .L8012F88C
/* C5F84 8012F884 0040B02D */   daddu    $s6, $v0, $zero
/* C5F88 8012F888 0016B023 */  negu      $s6, $s6
.L8012F88C:
/* C5F8C 8012F88C 3C08800A */  lui       $t0, %hi(gMasterGfxPos)
/* C5F90 8012F890 2508A66C */  addiu     $t0, $t0, %lo(gMasterGfxPos)
/* C5F94 8012F894 46004021 */  cvt.d.s   $f0, $f8
/* C5F98 8012F898 266CFFFF */  addiu     $t4, $s3, -1
/* C5F9C 8012F89C 3C11F510 */  lui       $s1, 0xf510
/* C5FA0 8012F8A0 97A20036 */  lhu       $v0, 0x36($sp)
/* C5FA4 8012F8A4 93AF0028 */  lbu       $t7, 0x28($sp)
/* C5FA8 8012F8A8 93B50027 */  lbu       $s5, 0x27($sp)
/* C5FAC 8012F8AC 46320002 */  mul.d     $f0, $f0, $f18
/* C5FB0 8012F8B0 00000000 */  nop       
/* C5FB4 8012F8B4 AFA00000 */  sw        $zero, ($sp)
/* C5FB8 8012F8B8 AFB00010 */  sw        $s0, 0x10($sp)
/* C5FBC 8012F8BC 0142C021 */  addu      $t8, $t2, $v0
/* C5FC0 8012F8C0 32A20007 */  andi      $v0, $s5, 7
/* C5FC4 8012F8C4 00024D40 */  sll       $t1, $v0, 0x15
/* C5FC8 8012F8C8 31950FFF */  andi      $s5, $t4, 0xfff
/* C5FCC 8012F8CC AFB50040 */  sw        $s5, 0x40($sp)
/* C5FD0 8012F8D0 462C0180 */  add.d     $f6, $f0, $f12
.L8012F8D4:
/* C5FD4 8012F8D4 C7A00010 */  lwc1      $f0, 0x10($sp)
/* C5FD8 8012F8D8 46800021 */  cvt.d.w   $f0, $f0
/* C5FDC 8012F8DC 8FA20000 */  lw        $v0, ($sp)
/* C5FE0 8012F8E0 46260000 */  add.d     $f0, $f0, $f6
/* C5FE4 8012F8E4 2442003F */  addiu     $v0, $v0, 0x3f
/* C5FE8 8012F8E8 AFA20008 */  sw        $v0, 8($sp)
/* C5FEC 8012F8EC 4620050D */  trunc.w.d $f20, $f0
/* C5FF0 8012F8F0 4402A000 */  mfc1      $v0, $f20
/* C5FF4 8012F8F4 00000000 */  nop       
/* C5FF8 8012F8F8 AFA20018 */  sw        $v0, 0x18($sp)
/* C5FFC 8012F8FC 0142102A */  slt       $v0, $t2, $v0
/* C6000 8012F900 14400014 */  bnez      $v0, .L8012F954
/* C6004 8012F904 0000682D */   daddu    $t5, $zero, $zero
/* C6008 8012F908 46104082 */  mul.s     $f2, $f8, $f16
/* C600C 8012F90C 00000000 */  nop       
.L8012F910:
/* C6010 8012F910 8FA40000 */  lw        $a0, ($sp)
/* C6014 8012F914 8FA30018 */  lw        $v1, 0x18($sp)
/* C6018 8012F918 24820040 */  addiu     $v0, $a0, 0x40
/* C601C 8012F91C 44830000 */  mtc1      $v1, $f0
/* C6020 8012F920 00000000 */  nop       
/* C6024 8012F924 46800020 */  cvt.s.w   $f0, $f0
/* C6028 8012F928 46020000 */  add.s     $f0, $f0, $f2
/* C602C 8012F92C AFA20000 */  sw        $v0, ($sp)
/* C6030 8012F930 AFA30010 */  sw        $v1, 0x10($sp)
/* C6034 8012F934 4600050D */  trunc.w.s $f20, $f0
/* C6038 8012F938 4402A000 */  mfc1      $v0, $f20
/* C603C 8012F93C 00000000 */  nop       
/* C6040 8012F940 AFA20018 */  sw        $v0, 0x18($sp)
/* C6044 8012F944 004A102A */  slt       $v0, $v0, $t2
/* C6048 8012F948 1440FFF1 */  bnez      $v0, .L8012F910
/* C604C 8012F94C 2482007F */   addiu    $v0, $a0, 0x7f
/* C6050 8012F950 AFA20008 */  sw        $v0, 8($sp)
.L8012F954:
/* C6054 8012F954 8FA20010 */  lw        $v0, 0x10($sp)
/* C6058 8012F958 004A102A */  slt       $v0, $v0, $t2
/* C605C 8012F95C 1040000A */  beqz      $v0, .L8012F988
/* C6060 8012F960 00000000 */   nop      
/* C6064 8012F964 44960000 */  mtc1      $s6, $f0
/* C6068 8012F968 00000000 */  nop       
/* C606C 8012F96C 46800020 */  cvt.s.w   $f0, $f0
/* C6070 8012F970 46080003 */  div.s     $f0, $f0, $f8
/* C6074 8012F974 460E0002 */  mul.s     $f0, $f0, $f14
/* C6078 8012F978 00000000 */  nop       
/* C607C 8012F97C AFAA0010 */  sw        $t2, 0x10($sp)
/* C6080 8012F980 4600050D */  trunc.w.s $f20, $f0
/* C6084 8012F984 440DA000 */  mfc1      $t5, $f20
.L8012F988:
/* C6088 8012F988 8FA20008 */  lw        $v0, 8($sp)
/* C608C 8012F98C 24420001 */  addiu     $v0, $v0, 1
/* C6090 8012F990 0053102B */  sltu      $v0, $v0, $s3
/* C6094 8012F994 14400016 */  bnez      $v0, .L8012F9F0
/* C6098 8012F998 00000000 */   nop      
/* C609C 8012F99C 448C0000 */  mtc1      $t4, $f0
/* C60A0 8012F9A0 00000000 */  nop       
/* C60A4 8012F9A4 46800020 */  cvt.s.w   $f0, $f0
/* C60A8 8012F9A8 46080002 */  mul.s     $f0, $f0, $f8
/* C60AC 8012F9AC 00000000 */  nop       
/* C60B0 8012F9B0 4600050D */  trunc.w.s $f20, $f0
/* C60B4 8012F9B4 4402A000 */  mfc1      $v0, $f20
/* C60B8 8012F9B8 00000000 */  nop       
/* C60BC 8012F9BC 00021400 */  sll       $v0, $v0, 0x10
/* C60C0 8012F9C0 00021403 */  sra       $v0, $v0, 0x10
/* C60C4 8012F9C4 02021021 */  addu      $v0, $s0, $v0
/* C60C8 8012F9C8 44820000 */  mtc1      $v0, $f0
/* C60CC 8012F9CC 00000000 */  nop       
/* C60D0 8012F9D0 46800020 */  cvt.s.w   $f0, $f0
/* C60D4 8012F9D4 46080000 */  add.s     $f0, $f0, $f8
/* C60D8 8012F9D8 46000021 */  cvt.d.s   $f0, $f0
/* C60DC 8012F9DC 462C0000 */  add.d     $f0, $f0, $f12
/* C60E0 8012F9E0 AFAC0008 */  sw        $t4, 8($sp)
/* C60E4 8012F9E4 240B0001 */  addiu     $t3, $zero, 1
/* C60E8 8012F9E8 4620050D */  trunc.w.d $f20, $f0
/* C60EC 8012F9EC E7B40018 */  swc1      $f20, 0x18($sp)
.L8012F9F0:
/* C60F0 8012F9F0 8FA20018 */  lw        $v0, 0x18($sp)
/* C60F4 8012F9F4 0302102A */  slt       $v0, $t8, $v0
/* C60F8 8012F9F8 10400003 */  beqz      $v0, .L8012FA08
/* C60FC 8012F9FC 24020002 */   addiu    $v0, $zero, 2
/* C6100 8012FA00 AFB80018 */  sw        $t8, 0x18($sp)
/* C6104 8012FA04 240B0001 */  addiu     $t3, $zero, 1
.L8012FA08:
/* C6108 8012FA08 15E2004F */  bne       $t7, $v0, .L8012FB48
/* C610C 8012FA0C 3C060701 */   lui      $a2, 0x701
/* C6110 8012FA10 34C64060 */  ori       $a2, $a2, 0x4060
/* C6114 8012FA14 8D050000 */  lw        $a1, ($t0)
/* C6118 8012FA18 3C070001 */  lui       $a3, 1
/* C611C 8012FA1C 00A0182D */  daddu     $v1, $a1, $zero
/* C6120 8012FA20 24A50008 */  addiu     $a1, $a1, 8
/* C6124 8012FA24 AD050000 */  sw        $a1, ($t0)
/* C6128 8012FA28 8FB50040 */  lw        $s5, 0x40($sp)
/* C612C 8012FA2C 3C02FD10 */  lui       $v0, 0xfd10
/* C6130 8012FA30 02A21025 */  or        $v0, $s5, $v0
/* C6134 8012FA34 01221025 */  or        $v0, $t1, $v0
/* C6138 8012FA38 AC620000 */  sw        $v0, ($v1)
/* C613C 8012FA3C 8FB50078 */  lw        $s5, 0x78($sp)
/* C6140 8012FA40 34E74060 */  ori       $a3, $a3, 0x4060
/* C6144 8012FA44 AC750004 */  sw        $s5, 4($v1)
/* C6148 8012FA48 8FA20008 */  lw        $v0, 8($sp)
/* C614C 8012FA4C 8FA40000 */  lw        $a0, ($sp)
/* C6150 8012FA50 24A30008 */  addiu     $v1, $a1, 8
/* C6154 8012FA54 AD030000 */  sw        $v1, ($t0)
/* C6158 8012FA58 24A30010 */  addiu     $v1, $a1, 0x10
/* C615C 8012FA5C ACA60004 */  sw        $a2, 4($a1)
/* C6160 8012FA60 AD030000 */  sw        $v1, ($t0)
/* C6164 8012FA64 3C03E600 */  lui       $v1, 0xe600
/* C6168 8012FA68 ACA30008 */  sw        $v1, 8($a1)
/* C616C 8012FA6C 3C03F400 */  lui       $v1, 0xf400
/* C6170 8012FA70 ACA0000C */  sw        $zero, 0xc($a1)
/* C6174 8012FA74 00441023 */  subu      $v0, $v0, $a0
/* C6178 8012FA78 00021040 */  sll       $v0, $v0, 1
/* C617C 8012FA7C 24420009 */  addiu     $v0, $v0, 9
/* C6180 8012FA80 000210C3 */  sra       $v0, $v0, 3
/* C6184 8012FA84 304201FF */  andi      $v0, $v0, 0x1ff
/* C6188 8012FA88 00021240 */  sll       $v0, $v0, 9
/* C618C 8012FA8C 00511025 */  or        $v0, $v0, $s1
/* C6190 8012FA90 01221025 */  or        $v0, $t1, $v0
/* C6194 8012FA94 ACA20000 */  sw        $v0, ($a1)
/* C6198 8012FA98 8FA40000 */  lw        $a0, ($sp)
/* C619C 8012FA9C 24A20018 */  addiu     $v0, $a1, 0x18
/* C61A0 8012FAA0 AD020000 */  sw        $v0, ($t0)
/* C61A4 8012FAA4 8FA20004 */  lw        $v0, 4($sp)
/* C61A8 8012FAA8 00042080 */  sll       $a0, $a0, 2
/* C61AC 8012FAAC 30840FFF */  andi      $a0, $a0, 0xfff
/* C61B0 8012FAB0 00042300 */  sll       $a0, $a0, 0xc
/* C61B4 8012FAB4 00021080 */  sll       $v0, $v0, 2
/* C61B8 8012FAB8 30420FFF */  andi      $v0, $v0, 0xfff
/* C61BC 8012FABC 00431025 */  or        $v0, $v0, $v1
/* C61C0 8012FAC0 00822025 */  or        $a0, $a0, $v0
/* C61C4 8012FAC4 ACA40010 */  sw        $a0, 0x10($a1)
/* C61C8 8012FAC8 8FA30008 */  lw        $v1, 8($sp)
/* C61CC 8012FACC 8FA4000C */  lw        $a0, 0xc($sp)
/* C61D0 8012FAD0 3C02E700 */  lui       $v0, 0xe700
/* C61D4 8012FAD4 ACA20018 */  sw        $v0, 0x18($a1)
/* C61D8 8012FAD8 3C020700 */  lui       $v0, 0x700
/* C61DC 8012FADC ACA0001C */  sw        $zero, 0x1c($a1)
/* C61E0 8012FAE0 00031880 */  sll       $v1, $v1, 2
/* C61E4 8012FAE4 30630FFF */  andi      $v1, $v1, 0xfff
/* C61E8 8012FAE8 00031B00 */  sll       $v1, $v1, 0xc
/* C61EC 8012FAEC 00042080 */  sll       $a0, $a0, 2
/* C61F0 8012FAF0 30840FFF */  andi      $a0, $a0, 0xfff
/* C61F4 8012FAF4 00822025 */  or        $a0, $a0, $v0
/* C61F8 8012FAF8 00641825 */  or        $v1, $v1, $a0
/* C61FC 8012FAFC ACA30014 */  sw        $v1, 0x14($a1)
/* C6200 8012FB00 8FA20008 */  lw        $v0, 8($sp)
/* C6204 8012FB04 8FA40000 */  lw        $a0, ($sp)
/* C6208 8012FB08 24A30020 */  addiu     $v1, $a1, 0x20
/* C620C 8012FB0C AD030000 */  sw        $v1, ($t0)
/* C6210 8012FB10 3C03F200 */  lui       $v1, 0xf200
/* C6214 8012FB14 ACA70024 */  sw        $a3, 0x24($a1)
/* C6218 8012FB18 00441023 */  subu      $v0, $v0, $a0
/* C621C 8012FB1C 00021040 */  sll       $v0, $v0, 1
/* C6220 8012FB20 24420009 */  addiu     $v0, $v0, 9
/* C6224 8012FB24 000210C3 */  sra       $v0, $v0, 3
/* C6228 8012FB28 304201FF */  andi      $v0, $v0, 0x1ff
/* C622C 8012FB2C 00021240 */  sll       $v0, $v0, 9
/* C6230 8012FB30 00511025 */  or        $v0, $v0, $s1
/* C6234 8012FB34 01221025 */  or        $v0, $t1, $v0
/* C6238 8012FB38 ACA20020 */  sw        $v0, 0x20($a1)
/* C623C 8012FB3C 8FA40000 */  lw        $a0, ($sp)
/* C6240 8012FB40 0804BF28 */  j         .L8012FCA0
/* C6244 8012FB44 24A20028 */   addiu    $v0, $a1, 0x28
.L8012FB48:
/* C6248 8012FB48 15E0006B */  bnez      $t7, .L8012FCF8
/* C624C 8012FB4C 316700FF */   andi     $a3, $t3, 0xff
/* C6250 8012FB50 3C060701 */  lui       $a2, 0x701
/* C6254 8012FB54 34C64060 */  ori       $a2, $a2, 0x4060
/* C6258 8012FB58 3C070001 */  lui       $a3, 1
/* C625C 8012FB5C 00131042 */  srl       $v0, $s3, 1
/* C6260 8012FB60 2442FFFF */  addiu     $v0, $v0, -1
/* C6264 8012FB64 30420FFF */  andi      $v0, $v0, 0xfff
/* C6268 8012FB68 3C03FD08 */  lui       $v1, 0xfd08
/* C626C 8012FB6C 00431025 */  or        $v0, $v0, $v1
/* C6270 8012FB70 8D050000 */  lw        $a1, ($t0)
/* C6274 8012FB74 01221025 */  or        $v0, $t1, $v0
/* C6278 8012FB78 00A0202D */  daddu     $a0, $a1, $zero
/* C627C 8012FB7C 24A50008 */  addiu     $a1, $a1, 8
/* C6280 8012FB80 AD050000 */  sw        $a1, ($t0)
/* C6284 8012FB84 AC820000 */  sw        $v0, ($a0)
/* C6288 8012FB88 8FB50078 */  lw        $s5, 0x78($sp)
/* C628C 8012FB8C 34E74060 */  ori       $a3, $a3, 0x4060
/* C6290 8012FB90 AC950004 */  sw        $s5, 4($a0)
/* C6294 8012FB94 8FA20008 */  lw        $v0, 8($sp)
/* C6298 8012FB98 8FA40000 */  lw        $a0, ($sp)
/* C629C 8012FB9C 24A30008 */  addiu     $v1, $a1, 8
/* C62A0 8012FBA0 AD030000 */  sw        $v1, ($t0)
/* C62A4 8012FBA4 24A30010 */  addiu     $v1, $a1, 0x10
/* C62A8 8012FBA8 ACA60004 */  sw        $a2, 4($a1)
/* C62AC 8012FBAC AD030000 */  sw        $v1, ($t0)
/* C62B0 8012FBB0 3C03E600 */  lui       $v1, 0xe600
/* C62B4 8012FBB4 ACA30008 */  sw        $v1, 8($a1)
/* C62B8 8012FBB8 3C03F508 */  lui       $v1, 0xf508
/* C62BC 8012FBBC ACA0000C */  sw        $zero, 0xc($a1)
/* C62C0 8012FBC0 00441023 */  subu      $v0, $v0, $a0
/* C62C4 8012FBC4 24420001 */  addiu     $v0, $v0, 1
/* C62C8 8012FBC8 00021043 */  sra       $v0, $v0, 1
/* C62CC 8012FBCC 24420007 */  addiu     $v0, $v0, 7
/* C62D0 8012FBD0 000210C3 */  sra       $v0, $v0, 3
/* C62D4 8012FBD4 304201FF */  andi      $v0, $v0, 0x1ff
/* C62D8 8012FBD8 00021240 */  sll       $v0, $v0, 9
/* C62DC 8012FBDC 00431025 */  or        $v0, $v0, $v1
/* C62E0 8012FBE0 01221025 */  or        $v0, $t1, $v0
/* C62E4 8012FBE4 ACA20000 */  sw        $v0, ($a1)
/* C62E8 8012FBE8 24A20018 */  addiu     $v0, $a1, 0x18
/* C62EC 8012FBEC 8FA40000 */  lw        $a0, ($sp)
/* C62F0 8012FBF0 3C03F400 */  lui       $v1, 0xf400
/* C62F4 8012FBF4 AD020000 */  sw        $v0, ($t0)
/* C62F8 8012FBF8 8FA20004 */  lw        $v0, 4($sp)
/* C62FC 8012FBFC 00042040 */  sll       $a0, $a0, 1
/* C6300 8012FC00 30840FFF */  andi      $a0, $a0, 0xfff
/* C6304 8012FC04 00042300 */  sll       $a0, $a0, 0xc
/* C6308 8012FC08 00021080 */  sll       $v0, $v0, 2
/* C630C 8012FC0C 30420FFF */  andi      $v0, $v0, 0xfff
/* C6310 8012FC10 00431025 */  or        $v0, $v0, $v1
/* C6314 8012FC14 00822025 */  or        $a0, $a0, $v0
/* C6318 8012FC18 ACA40010 */  sw        $a0, 0x10($a1)
/* C631C 8012FC1C 8FA30008 */  lw        $v1, 8($sp)
/* C6320 8012FC20 8FA4000C */  lw        $a0, 0xc($sp)
/* C6324 8012FC24 3C02E700 */  lui       $v0, 0xe700
/* C6328 8012FC28 ACA20018 */  sw        $v0, 0x18($a1)
/* C632C 8012FC2C 3C020700 */  lui       $v0, 0x700
/* C6330 8012FC30 ACA0001C */  sw        $zero, 0x1c($a1)
/* C6334 8012FC34 00031840 */  sll       $v1, $v1, 1
/* C6338 8012FC38 30630FFF */  andi      $v1, $v1, 0xfff
/* C633C 8012FC3C 00031B00 */  sll       $v1, $v1, 0xc
/* C6340 8012FC40 00042080 */  sll       $a0, $a0, 2
/* C6344 8012FC44 30840FFF */  andi      $a0, $a0, 0xfff
/* C6348 8012FC48 00822025 */  or        $a0, $a0, $v0
/* C634C 8012FC4C 00641825 */  or        $v1, $v1, $a0
/* C6350 8012FC50 ACA30014 */  sw        $v1, 0x14($a1)
/* C6354 8012FC54 8FA20008 */  lw        $v0, 8($sp)
/* C6358 8012FC58 8FA40000 */  lw        $a0, ($sp)
/* C635C 8012FC5C 24A30020 */  addiu     $v1, $a1, 0x20
/* C6360 8012FC60 AD030000 */  sw        $v1, ($t0)
/* C6364 8012FC64 3C03F500 */  lui       $v1, 0xf500
/* C6368 8012FC68 ACA70024 */  sw        $a3, 0x24($a1)
/* C636C 8012FC6C 00441023 */  subu      $v0, $v0, $a0
/* C6370 8012FC70 24420001 */  addiu     $v0, $v0, 1
/* C6374 8012FC74 00021043 */  sra       $v0, $v0, 1
/* C6378 8012FC78 24420007 */  addiu     $v0, $v0, 7
/* C637C 8012FC7C 000210C3 */  sra       $v0, $v0, 3
/* C6380 8012FC80 304201FF */  andi      $v0, $v0, 0x1ff
/* C6384 8012FC84 00021240 */  sll       $v0, $v0, 9
/* C6388 8012FC88 00431025 */  or        $v0, $v0, $v1
/* C638C 8012FC8C 01221025 */  or        $v0, $t1, $v0
/* C6390 8012FC90 ACA20020 */  sw        $v0, 0x20($a1)
/* C6394 8012FC94 24A20028 */  addiu     $v0, $a1, 0x28
/* C6398 8012FC98 8FA40000 */  lw        $a0, ($sp)
/* C639C 8012FC9C 3C03F200 */  lui       $v1, 0xf200
.L8012FCA0:
/* C63A0 8012FCA0 AD020000 */  sw        $v0, ($t0)
/* C63A4 8012FCA4 8FA20004 */  lw        $v0, 4($sp)
/* C63A8 8012FCA8 00042080 */  sll       $a0, $a0, 2
/* C63AC 8012FCAC 30840FFF */  andi      $a0, $a0, 0xfff
/* C63B0 8012FCB0 00042300 */  sll       $a0, $a0, 0xc
/* C63B4 8012FCB4 00021080 */  sll       $v0, $v0, 2
/* C63B8 8012FCB8 30420FFF */  andi      $v0, $v0, 0xfff
/* C63BC 8012FCBC 00431025 */  or        $v0, $v0, $v1
/* C63C0 8012FCC0 00822025 */  or        $a0, $a0, $v0
/* C63C4 8012FCC4 ACA40028 */  sw        $a0, 0x28($a1)
/* C63C8 8012FCC8 8FA30008 */  lw        $v1, 8($sp)
/* C63CC 8012FCCC 24A20030 */  addiu     $v0, $a1, 0x30
/* C63D0 8012FCD0 AD020000 */  sw        $v0, ($t0)
/* C63D4 8012FCD4 8FA2000C */  lw        $v0, 0xc($sp)
/* C63D8 8012FCD8 00031880 */  sll       $v1, $v1, 2
/* C63DC 8012FCDC 30630FFF */  andi      $v1, $v1, 0xfff
/* C63E0 8012FCE0 00031B00 */  sll       $v1, $v1, 0xc
/* C63E4 8012FCE4 00021080 */  sll       $v0, $v0, 2
/* C63E8 8012FCE8 30420FFF */  andi      $v0, $v0, 0xfff
/* C63EC 8012FCEC 00621825 */  or        $v1, $v1, $v0
/* C63F0 8012FCF0 ACA3002C */  sw        $v1, 0x2c($a1)
/* C63F4 8012FCF4 316700FF */  andi      $a3, $t3, 0xff
.L8012FCF8:
/* C63F8 8012FCF8 8D050000 */  lw        $a1, ($t0)
/* C63FC 8012FCFC 3C04E400 */  lui       $a0, 0xe400
/* C6400 8012FD00 00A0302D */  daddu     $a2, $a1, $zero
/* C6404 8012FD04 24A50008 */  addiu     $a1, $a1, 8
/* C6408 8012FD08 AD050000 */  sw        $a1, ($t0)
/* C640C 8012FD0C 8FA30018 */  lw        $v1, 0x18($sp)
/* C6410 8012FD10 8FA2001C */  lw        $v0, 0x1c($sp)
/* C6414 8012FD14 00671823 */  subu      $v1, $v1, $a3
/* C6418 8012FD18 00031880 */  sll       $v1, $v1, 2
/* C641C 8012FD1C 30630FFF */  andi      $v1, $v1, 0xfff
/* C6420 8012FD20 00031B00 */  sll       $v1, $v1, 0xc
/* C6424 8012FD24 00021080 */  sll       $v0, $v0, 2
/* C6428 8012FD28 30420FFF */  andi      $v0, $v0, 0xfff
/* C642C 8012FD2C 00441025 */  or        $v0, $v0, $a0
/* C6430 8012FD30 00621825 */  or        $v1, $v1, $v0
/* C6434 8012FD34 24A20008 */  addiu     $v0, $a1, 8
/* C6438 8012FD38 ACC30000 */  sw        $v1, ($a2)
/* C643C 8012FD3C AD020000 */  sw        $v0, ($t0)
/* C6440 8012FD40 8FA30010 */  lw        $v1, 0x10($sp)
/* C6444 8012FD44 24A20010 */  addiu     $v0, $a1, 0x10
/* C6448 8012FD48 AD020000 */  sw        $v0, ($t0)
/* C644C 8012FD4C 8FA20014 */  lw        $v0, 0x14($sp)
/* C6450 8012FD50 00031880 */  sll       $v1, $v1, 2
/* C6454 8012FD54 30630FFF */  andi      $v1, $v1, 0xfff
/* C6458 8012FD58 00031B00 */  sll       $v1, $v1, 0xc
/* C645C 8012FD5C 00021080 */  sll       $v0, $v0, 2
/* C6460 8012FD60 30420FFF */  andi      $v0, $v0, 0xfff
/* C6464 8012FD64 00621825 */  or        $v1, $v1, $v0
/* C6468 8012FD68 3C02E100 */  lui       $v0, 0xe100
/* C646C 8012FD6C ACC30004 */  sw        $v1, 4($a2)
/* C6470 8012FD70 ACA20000 */  sw        $v0, ($a1)
/* C6474 8012FD74 000D1400 */  sll       $v0, $t5, 0x10
/* C6478 8012FD78 3243FFFF */  andi      $v1, $s2, 0xffff
/* C647C 8012FD7C 00431025 */  or        $v0, $v0, $v1
/* C6480 8012FD80 ACA20004 */  sw        $v0, 4($a1)
/* C6484 8012FD84 3C02F100 */  lui       $v0, 0xf100
/* C6488 8012FD88 ACA20008 */  sw        $v0, 8($a1)
/* C648C 8012FD8C 8FB50038 */  lw        $s5, 0x38($sp)
/* C6490 8012FD90 33C3FFFF */  andi      $v1, $fp, 0xffff
/* C6494 8012FD94 00151400 */  sll       $v0, $s5, 0x10
/* C6498 8012FD98 00431025 */  or        $v0, $v0, $v1
/* C649C 8012FD9C 14E00007 */  bnez      $a3, .L8012FDBC
/* C64A0 8012FDA0 ACA2000C */   sw       $v0, 0xc($a1)
/* C64A4 8012FDA4 8FA20000 */  lw        $v0, ($sp)
/* C64A8 8012FDA8 8FA30018 */  lw        $v1, 0x18($sp)
/* C64AC 8012FDAC 24420040 */  addiu     $v0, $v0, 0x40
/* C64B0 8012FDB0 AFA20000 */  sw        $v0, ($sp)
/* C64B4 8012FDB4 0804BE35 */  j         .L8012F8D4
/* C64B8 8012FDB8 AFA30010 */   sw       $v1, 0x10($sp)
.L8012FDBC:
/* C64BC 8012FDBC 332200FF */  andi      $v0, $t9, 0xff
/* C64C0 8012FDC0 14400007 */  bnez      $v0, .L8012FDE0
/* C64C4 8012FDC4 24020001 */   addiu    $v0, $zero, 1
/* C64C8 8012FDC8 8FA20004 */  lw        $v0, 4($sp)
/* C64CC 8012FDCC 8FA3001C */  lw        $v1, 0x1c($sp)
/* C64D0 8012FDD0 24420020 */  addiu     $v0, $v0, 0x20
/* C64D4 8012FDD4 AFA20004 */  sw        $v0, 4($sp)
/* C64D8 8012FDD8 0804BDD2 */  j         .L8012F748
/* C64DC 8012FDDC AFA30014 */   sw       $v1, 0x14($sp)
.L8012FDE0:
/* C64E0 8012FDE0 8FBE0068 */  lw        $fp, 0x68($sp)
/* C64E4 8012FDE4 8FB70064 */  lw        $s7, 0x64($sp)
/* C64E8 8012FDE8 8FB60060 */  lw        $s6, 0x60($sp)
/* C64EC 8012FDEC 8FB5005C */  lw        $s5, 0x5c($sp)
/* C64F0 8012FDF0 8FB40058 */  lw        $s4, 0x58($sp)
/* C64F4 8012FDF4 8FB30054 */  lw        $s3, 0x54($sp)
/* C64F8 8012FDF8 8FB20050 */  lw        $s2, 0x50($sp)
/* C64FC 8012FDFC 8FB1004C */  lw        $s1, 0x4c($sp)
/* C6500 8012FE00 8FB00048 */  lw        $s0, 0x48($sp)
/* C6504 8012FE04 D7B40070 */  ldc1      $f20, 0x70($sp)
/* C6508 8012FE08 03E00008 */  jr        $ra
/* C650C 8012FE0C 27BD0078 */   addiu    $sp, $sp, 0x78
