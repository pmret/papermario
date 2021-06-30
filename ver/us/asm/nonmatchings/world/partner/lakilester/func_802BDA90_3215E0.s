.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BDA90_3215E0
/* 3215E0 802BDA90 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 3215E4 802BDA94 AFB00030 */  sw        $s0, 0x30($sp)
/* 3215E8 802BDA98 0080802D */  daddu     $s0, $a0, $zero
/* 3215EC 802BDA9C AFBF0034 */  sw        $ra, 0x34($sp)
/* 3215F0 802BDAA0 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3215F4 802BDAA4 C60C000C */  lwc1      $f12, 0xc($s0)
/* 3215F8 802BDAA8 860200A6 */  lh        $v0, 0xa6($s0)
/* 3215FC 802BDAAC 3C013F4C */  lui       $at, 0x3f4c
/* 321600 802BDAB0 3421CCCD */  ori       $at, $at, 0xcccd
/* 321604 802BDAB4 44811000 */  mtc1      $at, $f2
/* 321608 802BDAB8 44820000 */  mtc1      $v0, $f0
/* 32160C 802BDABC 00000000 */  nop
/* 321610 802BDAC0 46800020 */  cvt.s.w   $f0, $f0
/* 321614 802BDAC4 46020502 */  mul.s     $f20, $f0, $f2
/* 321618 802BDAC8 0C00A6C9 */  jal       clamp_angle
/* 32161C 802BDACC 00000000 */   nop
/* 321620 802BDAD0 C6020038 */  lwc1      $f2, 0x38($s0)
/* 321624 802BDAD4 C6040064 */  lwc1      $f4, 0x64($s0)
/* 321628 802BDAD8 C6060040 */  lwc1      $f6, 0x40($s0)
/* 32162C 802BDADC 27A50020 */  addiu     $a1, $sp, 0x20
/* 321630 802BDAE0 E7A20020 */  swc1      $f2, 0x20($sp)
/* 321634 802BDAE4 E7A40024 */  swc1      $f4, 0x24($sp)
/* 321638 802BDAE8 E7A60028 */  swc1      $f6, 0x28($sp)
/* 32163C 802BDAEC AFA00010 */  sw        $zero, 0x10($sp)
/* 321640 802BDAF0 E7A00014 */  swc1      $f0, 0x14($sp)
/* 321644 802BDAF4 860200A8 */  lh        $v0, 0xa8($s0)
/* 321648 802BDAF8 27A60024 */  addiu     $a2, $sp, 0x24
/* 32164C 802BDAFC 44820000 */  mtc1      $v0, $f0
/* 321650 802BDB00 00000000 */  nop
/* 321654 802BDB04 46800020 */  cvt.s.w   $f0, $f0
/* 321658 802BDB08 E7A00018 */  swc1      $f0, 0x18($sp)
/* 32165C 802BDB0C E7B4001C */  swc1      $f20, 0x1c($sp)
/* 321660 802BDB10 8E040080 */  lw        $a0, 0x80($s0)
/* 321664 802BDB14 0C037765 */  jal       npc_test_move_complex_with_slipping
/* 321668 802BDB18 27A70028 */   addiu    $a3, $sp, 0x28
/* 32166C 802BDB1C 1040000C */  beqz      $v0, .L802BDB50
/* 321670 802BDB20 24039FFF */   addiu    $v1, $zero, -0x6001
/* 321674 802BDB24 8E020000 */  lw        $v0, ($s0)
/* 321678 802BDB28 3C038011 */  lui       $v1, %hi(D_8010C97A)
/* 32167C 802BDB2C 9463C97A */  lhu       $v1, %lo(D_8010C97A)($v1)
/* 321680 802BDB30 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 321684 802BDB34 C7A20028 */  lwc1      $f2, 0x28($sp)
/* 321688 802BDB38 34426000 */  ori       $v0, $v0, 0x6000
/* 32168C 802BDB3C AE020000 */  sw        $v0, ($s0)
/* 321690 802BDB40 A6030086 */  sh        $v1, 0x86($s0)
/* 321694 802BDB44 E6000038 */  swc1      $f0, 0x38($s0)
/* 321698 802BDB48 080AF6D7 */  j         .L802BDB5C
/* 32169C 802BDB4C E6020040 */   swc1     $f2, 0x40($s0)
.L802BDB50:
/* 3216A0 802BDB50 8E020000 */  lw        $v0, ($s0)
/* 3216A4 802BDB54 00431024 */  and       $v0, $v0, $v1
/* 3216A8 802BDB58 AE020000 */  sw        $v0, ($s0)
.L802BDB5C:
/* 3216AC 802BDB5C C600000C */  lwc1      $f0, 0xc($s0)
/* 3216B0 802BDB60 3C014234 */  lui       $at, 0x4234
/* 3216B4 802BDB64 44816000 */  mtc1      $at, $f12
/* 3216B8 802BDB68 0C00A6C9 */  jal       clamp_angle
/* 3216BC 802BDB6C 460C0300 */   add.s    $f12, $f0, $f12
/* 3216C0 802BDB70 C6020038 */  lwc1      $f2, 0x38($s0)
/* 3216C4 802BDB74 C6040064 */  lwc1      $f4, 0x64($s0)
/* 3216C8 802BDB78 C6060040 */  lwc1      $f6, 0x40($s0)
/* 3216CC 802BDB7C 27A50020 */  addiu     $a1, $sp, 0x20
/* 3216D0 802BDB80 E7A20020 */  swc1      $f2, 0x20($sp)
/* 3216D4 802BDB84 E7A40024 */  swc1      $f4, 0x24($sp)
/* 3216D8 802BDB88 E7A60028 */  swc1      $f6, 0x28($sp)
/* 3216DC 802BDB8C AFA00010 */  sw        $zero, 0x10($sp)
/* 3216E0 802BDB90 E7A00014 */  swc1      $f0, 0x14($sp)
/* 3216E4 802BDB94 860200A8 */  lh        $v0, 0xa8($s0)
/* 3216E8 802BDB98 27A60024 */  addiu     $a2, $sp, 0x24
/* 3216EC 802BDB9C E7B4001C */  swc1      $f20, 0x1c($sp)
/* 3216F0 802BDBA0 44820000 */  mtc1      $v0, $f0
/* 3216F4 802BDBA4 00000000 */  nop
/* 3216F8 802BDBA8 46800020 */  cvt.s.w   $f0, $f0
/* 3216FC 802BDBAC E7A00018 */  swc1      $f0, 0x18($sp)
/* 321700 802BDBB0 8E040080 */  lw        $a0, 0x80($s0)
/* 321704 802BDBB4 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* 321708 802BDBB8 27A70028 */   addiu    $a3, $sp, 0x28
/* 32170C 802BDBBC 10400008 */  beqz      $v0, .L802BDBE0
/* 321710 802BDBC0 2403DFFF */   addiu    $v1, $zero, -0x2001
/* 321714 802BDBC4 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 321718 802BDBC8 8E020000 */  lw        $v0, ($s0)
/* 32171C 802BDBCC C7A20028 */  lwc1      $f2, 0x28($sp)
/* 321720 802BDBD0 34422000 */  ori       $v0, $v0, 0x2000
/* 321724 802BDBD4 E6000038 */  swc1      $f0, 0x38($s0)
/* 321728 802BDBD8 080AF6FA */  j         .L802BDBE8
/* 32172C 802BDBDC E6020040 */   swc1     $f2, 0x40($s0)
.L802BDBE0:
/* 321730 802BDBE0 8E020000 */  lw        $v0, ($s0)
/* 321734 802BDBE4 00431024 */  and       $v0, $v0, $v1
.L802BDBE8:
/* 321738 802BDBE8 AE020000 */  sw        $v0, ($s0)
/* 32173C 802BDBEC C600000C */  lwc1      $f0, 0xc($s0)
/* 321740 802BDBF0 3C014234 */  lui       $at, 0x4234
/* 321744 802BDBF4 44816000 */  mtc1      $at, $f12
/* 321748 802BDBF8 0C00A6C9 */  jal       clamp_angle
/* 32174C 802BDBFC 460C0301 */   sub.s    $f12, $f0, $f12
/* 321750 802BDC00 C6020038 */  lwc1      $f2, 0x38($s0)
/* 321754 802BDC04 C6040064 */  lwc1      $f4, 0x64($s0)
/* 321758 802BDC08 C6060040 */  lwc1      $f6, 0x40($s0)
/* 32175C 802BDC0C 27A50020 */  addiu     $a1, $sp, 0x20
/* 321760 802BDC10 E7A20020 */  swc1      $f2, 0x20($sp)
/* 321764 802BDC14 E7A40024 */  swc1      $f4, 0x24($sp)
/* 321768 802BDC18 E7A60028 */  swc1      $f6, 0x28($sp)
/* 32176C 802BDC1C AFA00010 */  sw        $zero, 0x10($sp)
/* 321770 802BDC20 E7A00014 */  swc1      $f0, 0x14($sp)
/* 321774 802BDC24 860200A8 */  lh        $v0, 0xa8($s0)
/* 321778 802BDC28 27A60024 */  addiu     $a2, $sp, 0x24
/* 32177C 802BDC2C E7B4001C */  swc1      $f20, 0x1c($sp)
/* 321780 802BDC30 44820000 */  mtc1      $v0, $f0
/* 321784 802BDC34 00000000 */  nop
/* 321788 802BDC38 46800020 */  cvt.s.w   $f0, $f0
/* 32178C 802BDC3C E7A00018 */  swc1      $f0, 0x18($sp)
/* 321790 802BDC40 8E040080 */  lw        $a0, 0x80($s0)
/* 321794 802BDC44 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* 321798 802BDC48 27A70028 */   addiu    $a3, $sp, 0x28
/* 32179C 802BDC4C 10400008 */  beqz      $v0, .L802BDC70
/* 3217A0 802BDC50 2403DFFF */   addiu    $v1, $zero, -0x2001
/* 3217A4 802BDC54 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 3217A8 802BDC58 8E020000 */  lw        $v0, ($s0)
/* 3217AC 802BDC5C C7A20028 */  lwc1      $f2, 0x28($sp)
/* 3217B0 802BDC60 34422000 */  ori       $v0, $v0, 0x2000
/* 3217B4 802BDC64 E6000038 */  swc1      $f0, 0x38($s0)
/* 3217B8 802BDC68 080AF71E */  j         .L802BDC78
/* 3217BC 802BDC6C E6020040 */   swc1     $f2, 0x40($s0)
.L802BDC70:
/* 3217C0 802BDC70 8E020000 */  lw        $v0, ($s0)
/* 3217C4 802BDC74 00431024 */  and       $v0, $v0, $v1
.L802BDC78:
/* 3217C8 802BDC78 AE020000 */  sw        $v0, ($s0)
/* 3217CC 802BDC7C C60C000C */  lwc1      $f12, 0xc($s0)
/* 3217D0 802BDC80 3C014234 */  lui       $at, 0x4234
/* 3217D4 802BDC84 44810000 */  mtc1      $at, $f0
/* 3217D8 802BDC88 00000000 */  nop
/* 3217DC 802BDC8C 46006300 */  add.s     $f12, $f12, $f0
/* 3217E0 802BDC90 3C014334 */  lui       $at, 0x4334
/* 3217E4 802BDC94 44810000 */  mtc1      $at, $f0
/* 3217E8 802BDC98 0C00A6C9 */  jal       clamp_angle
/* 3217EC 802BDC9C 46006300 */   add.s    $f12, $f12, $f0
/* 3217F0 802BDCA0 C6020038 */  lwc1      $f2, 0x38($s0)
/* 3217F4 802BDCA4 C6040064 */  lwc1      $f4, 0x64($s0)
/* 3217F8 802BDCA8 C6060040 */  lwc1      $f6, 0x40($s0)
/* 3217FC 802BDCAC 27A50020 */  addiu     $a1, $sp, 0x20
/* 321800 802BDCB0 E7A20020 */  swc1      $f2, 0x20($sp)
/* 321804 802BDCB4 E7A40024 */  swc1      $f4, 0x24($sp)
/* 321808 802BDCB8 E7A60028 */  swc1      $f6, 0x28($sp)
/* 32180C 802BDCBC AFA00010 */  sw        $zero, 0x10($sp)
/* 321810 802BDCC0 E7A00014 */  swc1      $f0, 0x14($sp)
/* 321814 802BDCC4 860200A8 */  lh        $v0, 0xa8($s0)
/* 321818 802BDCC8 27A60024 */  addiu     $a2, $sp, 0x24
/* 32181C 802BDCCC E7B4001C */  swc1      $f20, 0x1c($sp)
/* 321820 802BDCD0 44820000 */  mtc1      $v0, $f0
/* 321824 802BDCD4 00000000 */  nop
/* 321828 802BDCD8 46800020 */  cvt.s.w   $f0, $f0
/* 32182C 802BDCDC E7A00018 */  swc1      $f0, 0x18($sp)
/* 321830 802BDCE0 8E040080 */  lw        $a0, 0x80($s0)
/* 321834 802BDCE4 0C037711 */  jal       npc_test_move_simple_with_slipping
/* 321838 802BDCE8 27A70028 */   addiu    $a3, $sp, 0x28
/* 32183C 802BDCEC 10400009 */  beqz      $v0, .L802BDD14
/* 321840 802BDCF0 2403DFFF */   addiu    $v1, $zero, -0x2001
/* 321844 802BDCF4 8E020000 */  lw        $v0, ($s0)
/* 321848 802BDCF8 C7A00020 */  lwc1      $f0, 0x20($sp)
/* 32184C 802BDCFC C7A20028 */  lwc1      $f2, 0x28($sp)
/* 321850 802BDD00 34422000 */  ori       $v0, $v0, 0x2000
/* 321854 802BDD04 AE020000 */  sw        $v0, ($s0)
/* 321858 802BDD08 E6000038 */  swc1      $f0, 0x38($s0)
/* 32185C 802BDD0C 080AF748 */  j         .L802BDD20
/* 321860 802BDD10 E6020040 */   swc1     $f2, 0x40($s0)
.L802BDD14:
/* 321864 802BDD14 8E020000 */  lw        $v0, ($s0)
/* 321868 802BDD18 00431024 */  and       $v0, $v0, $v1
/* 32186C 802BDD1C AE020000 */  sw        $v0, ($s0)
.L802BDD20:
/* 321870 802BDD20 C60C000C */  lwc1      $f12, 0xc($s0)
/* 321874 802BDD24 3C014234 */  lui       $at, 0x4234
/* 321878 802BDD28 44810000 */  mtc1      $at, $f0
/* 32187C 802BDD2C 00000000 */  nop
/* 321880 802BDD30 46006301 */  sub.s     $f12, $f12, $f0
/* 321884 802BDD34 3C014334 */  lui       $at, 0x4334
/* 321888 802BDD38 44810000 */  mtc1      $at, $f0
/* 32188C 802BDD3C 0C00A6C9 */  jal       clamp_angle
/* 321890 802BDD40 46006300 */   add.s    $f12, $f12, $f0
/* 321894 802BDD44 C6020038 */  lwc1      $f2, 0x38($s0)
/* 321898 802BDD48 C6040064 */  lwc1      $f4, 0x64($s0)
/* 32189C 802BDD4C C6060040 */  lwc1      $f6, 0x40($s0)
/* 3218A0 802BDD50 27A50020 */  addiu     $a1, $sp, 0x20
/* 3218A4 802BDD54 E7A20020 */  swc1      $f2, 0x20($sp)
/* 3218A8 802BDD58 E7A40024 */  swc1      $f4, 0x24($sp)
/* 3218AC 802BDD5C E7A60028 */  swc1      $f6, 0x28($sp)
/* 3218B0 802BDD60 AFA00010 */  sw        $zero, 0x10($sp)
/* 3218B4 802BDD64 E7A00014 */  swc1      $f0, 0x14($sp)
/* 3218B8 802BDD68 860200A8 */  lh        $v0, 0xa8($s0)
/* 3218BC 802BDD6C 27A60024 */  addiu     $a2, $sp, 0x24
/* 3218C0 802BDD70 E7B4001C */  swc1      $f20, 0x1c($sp)
/* 3218C4 802BDD74 44820000 */  mtc1      $v0, $f0
/* 3218C8 802BDD78 00000000 */  nop
/* 3218CC 802BDD7C 46800020 */  cvt.s.w   $f0, $f0
/* 3218D0 802BDD80 E7A00018 */  swc1      $f0, 0x18($sp)
/* 3218D4 802BDD84 8E040080 */  lw        $a0, 0x80($s0)
/* 3218D8 802BDD88 0C037711 */  jal       npc_test_move_simple_with_slipping
/* 3218DC 802BDD8C 27A70028 */   addiu    $a3, $sp, 0x28
/* 3218E0 802BDD90 10400009 */  beqz      $v0, .L802BDDB8
/* 3218E4 802BDD94 2403DFFF */   addiu    $v1, $zero, -0x2001
/* 3218E8 802BDD98 8E020000 */  lw        $v0, ($s0)
/* 3218EC 802BDD9C C7A00020 */  lwc1      $f0, 0x20($sp)
/* 3218F0 802BDDA0 C7A20028 */  lwc1      $f2, 0x28($sp)
/* 3218F4 802BDDA4 34422000 */  ori       $v0, $v0, 0x2000
/* 3218F8 802BDDA8 AE020000 */  sw        $v0, ($s0)
/* 3218FC 802BDDAC E6000038 */  swc1      $f0, 0x38($s0)
/* 321900 802BDDB0 080AF771 */  j         .L802BDDC4
/* 321904 802BDDB4 E6020040 */   swc1     $f2, 0x40($s0)
.L802BDDB8:
/* 321908 802BDDB8 8E020000 */  lw        $v0, ($s0)
/* 32190C 802BDDBC 00431024 */  and       $v0, $v0, $v1
/* 321910 802BDDC0 AE020000 */  sw        $v0, ($s0)
.L802BDDC4:
/* 321914 802BDDC4 8FBF0034 */  lw        $ra, 0x34($sp)
/* 321918 802BDDC8 8FB00030 */  lw        $s0, 0x30($sp)
/* 32191C 802BDDCC D7B40038 */  ldc1      $f20, 0x38($sp)
/* 321920 802BDDD0 03E00008 */  jr        $ra
/* 321924 802BDDD4 27BD0040 */   addiu    $sp, $sp, 0x40
