.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_801385D4
/* 0CECD4 801385D4 3C038015 */  lui   $v1, 0x8015
/* 0CECD8 801385D8 8C63C6F0 */  lw    $v1, -0x3910($v1)
/* 0CECDC 801385DC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0CECE0 801385E0 AFB20018 */  sw    $s2, 0x18($sp)
/* 0CECE4 801385E4 0080902D */  daddu $s2, $a0, $zero
/* 0CECE8 801385E8 AFB10014 */  sw    $s1, 0x14($sp)
/* 0CECEC 801385EC 0000882D */  daddu $s1, $zero, $zero
/* 0CECF0 801385F0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0CECF4 801385F4 24100014 */  addiu $s0, $zero, 0x14
/* 0CECF8 801385F8 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0CECFC 801385FC 0220982D */  daddu $s3, $s1, $zero
/* 0CED00 80138600 2C620011 */  sltiu $v0, $v1, 0x11
/* 0CED04 80138604 10400030 */  beqz  $v0, .L801386C8
/* 0CED08 80138608 AFBF0020 */   sw    $ra, 0x20($sp)
/* 0CED0C 8013860C 00031080 */  sll   $v0, $v1, 2
/* 0CED10 80138610 3C018015 */  lui   $at, 0x8015
/* 0CED14 80138614 00220821 */  addu  $at, $at, $v0
/* 0CED18 80138618 8C220F38 */  lw    $v0, 0xf38($at)
/* 0CED1C 8013861C 00400008 */  jr    $v0
/* 0CED20 80138620 00000000 */   nop   
/* 0CED24 80138624 0000202D */  daddu $a0, $zero, $zero
/* 0CED28 80138628 240500D0 */  addiu $a1, $zero, 0xd0
/* 0CED2C 8013862C 00A0302D */  daddu $a2, $a1, $zero
/* 0CED30 80138630 0C04DF84 */  jal   func_80137E10
/* 0CED34 80138634 00A0382D */   daddu $a3, $a1, $zero
/* 0CED38 80138638 0804E1B2 */  j     .L801386C8
/* 0CED3C 8013863C 24100032 */   addiu $s0, $zero, 0x32

/* 0CED40 80138640 24110001 */  addiu $s1, $zero, 1
/* 0CED44 80138644 0804E1B2 */  j     .L801386C8
/* 0CED48 80138648 24100032 */   addiu $s0, $zero, 0x32

/* 0CED4C 8013864C 24110001 */  addiu $s1, $zero, 1
/* 0CED50 80138650 0804E1B2 */  j     .L801386C8
/* 0CED54 80138654 24100007 */   addiu $s0, $zero, 7

/* 0CED58 80138658 0804E1B2 */  j     .L801386C8
/* 0CED5C 8013865C 24110001 */   addiu $s1, $zero, 1

/* 0CED60 80138660 0804E1B2 */  j     .L801386C8
/* 0CED64 80138664 24110004 */   addiu $s1, $zero, 4

/* 0CED68 80138668 24110005 */  addiu $s1, $zero, 5
/* 0CED6C 8013866C 0804E1B2 */  j     .L801386C8
/* 0CED70 80138670 24100007 */   addiu $s0, $zero, 7

/* 0CED74 80138674 24110004 */  addiu $s1, $zero, 4
/* 0CED78 80138678 0804E1B2 */  j     .L801386C8
/* 0CED7C 8013867C 24100007 */   addiu $s0, $zero, 7

/* 0CED80 80138680 0000202D */  daddu $a0, $zero, $zero
/* 0CED84 80138684 0080282D */  daddu $a1, $a0, $zero
/* 0CED88 80138688 2406000F */  addiu $a2, $zero, 0xf
/* 0CED8C 8013868C 0C04DF93 */  jal   func_80137E4C
/* 0CED90 80138690 2407001C */   addiu $a3, $zero, 0x1c
/* 0CED94 80138694 0000202D */  daddu $a0, $zero, $zero
/* 0CED98 80138698 24050001 */  addiu $a1, $zero, 1
/* 0CED9C 8013869C 24060131 */  addiu $a2, $zero, 0x131
/* 0CEDA0 801386A0 0C04DF93 */  jal   func_80137E4C
/* 0CEDA4 801386A4 2407009C */   addiu $a3, $zero, 0x9c
/* 0CEDA8 801386A8 86420000 */  lh    $v0, ($s2)
/* 0CEDAC 801386AC 2404000C */  addiu $a0, $zero, 0xc
/* 0CEDB0 801386B0 44820000 */  mtc1  $v0, $f0
/* 0CEDB4 801386B4 00000000 */  nop   
/* 0CEDB8 801386B8 46800020 */  cvt.s.w $f0, $f0
/* 0CEDBC 801386BC 44050000 */  mfc1  $a1, $f0
/* 0CEDC0 801386C0 0C04DF62 */  jal   func_80137D88
/* 0CEDC4 801386C4 24100002 */   addiu $s0, $zero, 2
.L801386C8:
/* 0CEDC8 801386C8 3C038015 */  lui   $v1, 0x8015
/* 0CEDCC 801386CC 8C63C6F0 */  lw    $v1, -0x3910($v1)
/* 0CEDD0 801386D0 24020010 */  addiu $v0, $zero, 0x10
/* 0CEDD4 801386D4 10620008 */  beq   $v1, $v0, .L801386F8
/* 0CEDD8 801386D8 00000000 */   nop   
/* 0CEDDC 801386DC 86420000 */  lh    $v0, ($s2)
/* 0CEDE0 801386E0 44820000 */  mtc1  $v0, $f0
/* 0CEDE4 801386E4 00000000 */  nop   
/* 0CEDE8 801386E8 46800020 */  cvt.s.w $f0, $f0
/* 0CEDEC 801386EC 44050000 */  mfc1  $a1, $f0
/* 0CEDF0 801386F0 0C04DF62 */  jal   func_80137D88
/* 0CEDF4 801386F4 0220202D */   daddu $a0, $s1, $zero
.L801386F8:
/* 0CEDF8 801386F8 86420000 */  lh    $v0, ($s2)
/* 0CEDFC 801386FC 96430000 */  lhu   $v1, ($s2)
/* 0CEE00 80138700 50400001 */  beql  $v0, $zero, .L80138708
/* 0CEE04 80138704 24130001 */   addiu $s3, $zero, 1
.L80138708:
/* 0CEE08 80138708 00701023 */  subu  $v0, $v1, $s0
/* 0CEE0C 8013870C A6420000 */  sh    $v0, ($s2)
/* 0CEE10 80138710 00021400 */  sll   $v0, $v0, 0x10
/* 0CEE14 80138714 04420001 */  bltzl $v0, .L8013871C
/* 0CEE18 80138718 A6400000 */   sh    $zero, ($s2)
.L8013871C:
/* 0CEE1C 8013871C 0260102D */  daddu $v0, $s3, $zero
/* 0CEE20 80138720 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0CEE24 80138724 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0CEE28 80138728 8FB20018 */  lw    $s2, 0x18($sp)
/* 0CEE2C 8013872C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0CEE30 80138730 8FB00010 */  lw    $s0, 0x10($sp)
/* 0CEE34 80138734 03E00008 */  jr    $ra
/* 0CEE38 80138738 27BD0028 */   addiu $sp, $sp, 0x28

/* 0CEE3C 8013873C 00000000 */  nop   
