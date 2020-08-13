.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802A47E0
/* 419570 802A47E0 3C02802B */  lui   $v0, 0x802b
/* 419574 802A47E4 8C42D66C */  lw    $v0, -0x2994($v0)
/* 419578 802A47E8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 41957C 802A47EC AFB00010 */  sw    $s0, 0x10($sp)
/* 419580 802A47F0 0000802D */  daddu $s0, $zero, $zero
/* 419584 802A47F4 AFBF0018 */  sw    $ra, 0x18($sp)
/* 419588 802A47F8 1840000F */  blez  $v0, .L802A4838
/* 41958C 802A47FC AFB10014 */   sw    $s1, 0x14($sp)
/* 419590 802A4800 3C11802B */  lui   $s1, 0x802b
/* 419594 802A4804 2631D628 */  addiu $s1, $s1, -0x29d8
/* 419598 802A4808 240500FF */  addiu $a1, $zero, 0xff
.L802A480C:
/* 41959C 802A480C 00A0302D */  daddu $a2, $a1, $zero
/* 4195A0 802A4810 00A0382D */  daddu $a3, $a1, $zero
/* 4195A4 802A4814 8E240000 */  lw    $a0, ($s1)
/* 4195A8 802A4818 0C0513BF */  jal   func_80144EFC
/* 4195AC 802A481C 26310004 */   addiu $s1, $s1, 4
/* 4195B0 802A4820 3C02802B */  lui   $v0, 0x802b
/* 4195B4 802A4824 8C42D66C */  lw    $v0, -0x2994($v0)
/* 4195B8 802A4828 26100001 */  addiu $s0, $s0, 1
/* 4195BC 802A482C 0202102A */  slt   $v0, $s0, $v0
/* 4195C0 802A4830 5440FFF6 */  bnezl $v0, .L802A480C
/* 4195C4 802A4834 240500FF */   addiu $a1, $zero, 0xff
.L802A4838:
/* 4195C8 802A4838 240500FF */  addiu $a1, $zero, 0xff
/* 4195CC 802A483C 00A0302D */  daddu $a2, $a1, $zero
/* 4195D0 802A4840 3C10802B */  lui   $s0, 0x802b
/* 4195D4 802A4844 2610D618 */  addiu $s0, $s0, -0x29e8
/* 4195D8 802A4848 8E040000 */  lw    $a0, ($s0)
/* 4195DC 802A484C 0C0513BF */  jal   func_80144EFC
/* 4195E0 802A4850 00A0382D */   daddu $a3, $a1, $zero
/* 4195E4 802A4854 240500FF */  addiu $a1, $zero, 0xff
/* 4195E8 802A4858 00A0302D */  daddu $a2, $a1, $zero
/* 4195EC 802A485C 3C04802B */  lui   $a0, 0x802b
/* 4195F0 802A4860 8C84D61C */  lw    $a0, -0x29e4($a0)
/* 4195F4 802A4864 0C0513BF */  jal   func_80144EFC
/* 4195F8 802A4868 00A0382D */   daddu $a3, $a1, $zero
/* 4195FC 802A486C 240500FF */  addiu $a1, $zero, 0xff
/* 419600 802A4870 00A0302D */  daddu $a2, $a1, $zero
/* 419604 802A4874 3C04802B */  lui   $a0, 0x802b
/* 419608 802A4878 8C84D620 */  lw    $a0, -0x29e0($a0)
/* 41960C 802A487C 0C0513BF */  jal   func_80144EFC
/* 419610 802A4880 00A0382D */   daddu $a3, $a1, $zero
/* 419614 802A4884 8E040000 */  lw    $a0, ($s0)
/* 419618 802A4888 3C058010 */  lui   $a1, 0x8010
/* 41961C 802A488C 24A54A28 */  addiu $a1, $a1, 0x4a28
/* 419620 802A4890 0C0511FF */  jal   set_menu_icon_script
/* 419624 802A4894 00000000 */   nop   
/* 419628 802A4898 24040006 */  addiu $a0, $zero, 6
/* 41962C 802A489C 0C051F9F */  jal   func_80147E7C
/* 419630 802A48A0 24050005 */   addiu $a1, $zero, 5
/* 419634 802A48A4 24040007 */  addiu $a0, $zero, 7
/* 419638 802A48A8 0C051F9F */  jal   func_80147E7C
/* 41963C 802A48AC 24050005 */   addiu $a1, $zero, 5
/* 419640 802A48B0 24040008 */  addiu $a0, $zero, 8
/* 419644 802A48B4 0C051F9F */  jal   func_80147E7C
/* 419648 802A48B8 24050001 */   addiu $a1, $zero, 1
/* 41964C 802A48BC 2402000A */  addiu $v0, $zero, 0xa
/* 419650 802A48C0 8FBF0018 */  lw    $ra, 0x18($sp)
/* 419654 802A48C4 8FB10014 */  lw    $s1, 0x14($sp)
/* 419658 802A48C8 8FB00010 */  lw    $s0, 0x10($sp)
/* 41965C 802A48CC 24030001 */  addiu $v1, $zero, 1
/* 419660 802A48D0 3C01802B */  lui   $at, 0x802b
/* 419664 802A48D4 A022D614 */  sb    $v0, -0x29ec($at)
/* 419668 802A48D8 240200FF */  addiu $v0, $zero, 0xff
/* 41966C 802A48DC 3C01802B */  lui   $at, 0x802b
/* 419670 802A48E0 A023D60B */  sb    $v1, -0x29f5($at)
/* 419674 802A48E4 3C01802B */  lui   $at, 0x802b
/* 419678 802A48E8 AC22D624 */  sw    $v0, -0x29dc($at)
/* 41967C 802A48EC 3C01802B */  lui   $at, 0x802b
/* 419680 802A48F0 A023D604 */  sb    $v1, -0x29fc($at)
/* 419684 802A48F4 03E00008 */  jr    $ra
/* 419688 802A48F8 27BD0020 */   addiu $sp, $sp, 0x20

