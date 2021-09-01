.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218620_5CECB0
/* 5CECB0 80218620 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 5CECB4 80218624 AFB20018 */  sw        $s2, 0x18($sp)
/* 5CECB8 80218628 0080902D */  daddu     $s2, $a0, $zero
/* 5CECBC 8021862C AFBF001C */  sw        $ra, 0x1c($sp)
/* 5CECC0 80218630 AFB10014 */  sw        $s1, 0x14($sp)
/* 5CECC4 80218634 AFB00010 */  sw        $s0, 0x10($sp)
/* 5CECC8 80218638 8E50000C */  lw        $s0, 0xc($s2)
/* 5CECCC 8021863C 8E050000 */  lw        $a1, ($s0)
/* 5CECD0 80218640 0C0B1EAF */  jal       evt_get_variable
/* 5CECD4 80218644 26100004 */   addiu    $s0, $s0, 4
/* 5CECD8 80218648 8E050000 */  lw        $a1, ($s0)
/* 5CECDC 8021864C 26100004 */  addiu     $s0, $s0, 4
/* 5CECE0 80218650 0240202D */  daddu     $a0, $s2, $zero
/* 5CECE4 80218654 3C038023 */  lui       $v1, %hi(D_80235E00)
/* 5CECE8 80218658 24635E00 */  addiu     $v1, $v1, %lo(D_80235E00)
/* 5CECEC 8021865C 000288C0 */  sll       $s1, $v0, 3
/* 5CECF0 80218660 02228821 */  addu      $s1, $s1, $v0
/* 5CECF4 80218664 00118880 */  sll       $s1, $s1, 2
/* 5CECF8 80218668 0C0B1EAF */  jal       evt_get_variable
/* 5CECFC 8021866C 02238821 */   addu     $s1, $s1, $v1
/* 5CED00 80218670 44820000 */  mtc1      $v0, $f0
/* 5CED04 80218674 00000000 */  nop
/* 5CED08 80218678 46800020 */  cvt.s.w   $f0, $f0
/* 5CED0C 8021867C E6200000 */  swc1      $f0, ($s1)
/* 5CED10 80218680 8E050000 */  lw        $a1, ($s0)
/* 5CED14 80218684 26100004 */  addiu     $s0, $s0, 4
/* 5CED18 80218688 0C0B1EAF */  jal       evt_get_variable
/* 5CED1C 8021868C 0240202D */   daddu    $a0, $s2, $zero
/* 5CED20 80218690 44820000 */  mtc1      $v0, $f0
/* 5CED24 80218694 00000000 */  nop
/* 5CED28 80218698 46800020 */  cvt.s.w   $f0, $f0
/* 5CED2C 8021869C E6200004 */  swc1      $f0, 4($s1)
/* 5CED30 802186A0 8E050000 */  lw        $a1, ($s0)
/* 5CED34 802186A4 26100004 */  addiu     $s0, $s0, 4
/* 5CED38 802186A8 0C0B1EAF */  jal       evt_get_variable
/* 5CED3C 802186AC 0240202D */   daddu    $a0, $s2, $zero
/* 5CED40 802186B0 24040014 */  addiu     $a0, $zero, 0x14
/* 5CED44 802186B4 44820000 */  mtc1      $v0, $f0
/* 5CED48 802186B8 00000000 */  nop
/* 5CED4C 802186BC 46800020 */  cvt.s.w   $f0, $f0
/* 5CED50 802186C0 0C00A67F */  jal       rand_int
/* 5CED54 802186C4 E6200008 */   swc1     $f0, 8($s1)
/* 5CED58 802186C8 24040028 */  addiu     $a0, $zero, 0x28
/* 5CED5C 802186CC 00021023 */  negu      $v0, $v0
/* 5CED60 802186D0 44820000 */  mtc1      $v0, $f0
/* 5CED64 802186D4 00000000 */  nop
/* 5CED68 802186D8 46800020 */  cvt.s.w   $f0, $f0
/* 5CED6C 802186DC 0C00A67F */  jal       rand_int
/* 5CED70 802186E0 E620000C */   swc1     $f0, 0xc($s1)
/* 5CED74 802186E4 2442003C */  addiu     $v0, $v0, 0x3c
/* 5CED78 802186E8 44820000 */  mtc1      $v0, $f0
/* 5CED7C 802186EC 00000000 */  nop
/* 5CED80 802186F0 46800020 */  cvt.s.w   $f0, $f0
/* 5CED84 802186F4 E6200010 */  swc1      $f0, 0x10($s1)
/* 5CED88 802186F8 AE200014 */  sw        $zero, 0x14($s1)
/* 5CED8C 802186FC 8E050000 */  lw        $a1, ($s0)
/* 5CED90 80218700 26100004 */  addiu     $s0, $s0, 4
/* 5CED94 80218704 0C0B1EAF */  jal       evt_get_variable
/* 5CED98 80218708 0240202D */   daddu    $a0, $s2, $zero
/* 5CED9C 8021870C 44820000 */  mtc1      $v0, $f0
/* 5CEDA0 80218710 00000000 */  nop
/* 5CEDA4 80218714 46800020 */  cvt.s.w   $f0, $f0
/* 5CEDA8 80218718 E6200018 */  swc1      $f0, 0x18($s1)
/* 5CEDAC 8021871C 8E050000 */  lw        $a1, ($s0)
/* 5CEDB0 80218720 26100004 */  addiu     $s0, $s0, 4
/* 5CEDB4 80218724 0C0B1EAF */  jal       evt_get_variable
/* 5CEDB8 80218728 0240202D */   daddu    $a0, $s2, $zero
/* 5CEDBC 8021872C 44820000 */  mtc1      $v0, $f0
/* 5CEDC0 80218730 00000000 */  nop
/* 5CEDC4 80218734 46800020 */  cvt.s.w   $f0, $f0
/* 5CEDC8 80218738 E620001C */  swc1      $f0, 0x1c($s1)
/* 5CEDCC 8021873C 8E050000 */  lw        $a1, ($s0)
/* 5CEDD0 80218740 0C0B1EAF */  jal       evt_get_variable
/* 5CEDD4 80218744 0240202D */   daddu    $a0, $s2, $zero
/* 5CEDD8 80218748 44820000 */  mtc1      $v0, $f0
/* 5CEDDC 8021874C 00000000 */  nop
/* 5CEDE0 80218750 46800020 */  cvt.s.w   $f0, $f0
/* 5CEDE4 80218754 E6200020 */  swc1      $f0, 0x20($s1)
/* 5CEDE8 80218758 8FBF001C */  lw        $ra, 0x1c($sp)
/* 5CEDEC 8021875C 8FB20018 */  lw        $s2, 0x18($sp)
/* 5CEDF0 80218760 8FB10014 */  lw        $s1, 0x14($sp)
/* 5CEDF4 80218764 8FB00010 */  lw        $s0, 0x10($sp)
/* 5CEDF8 80218768 24020002 */  addiu     $v0, $zero, 2
/* 5CEDFC 8021876C 03E00008 */  jr        $ra
/* 5CEE00 80218770 27BD0020 */   addiu    $sp, $sp, 0x20
