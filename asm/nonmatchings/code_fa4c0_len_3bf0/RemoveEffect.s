.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel RemoveEffect
/* 0FC494 802D7AE4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FC498 802D7AE8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FC49C 802D7AEC 8C82000C */  lw    $v0, 0xc($a0)
/* 0FC4A0 802D7AF0 0C0B1EAF */  jal   get_variable
/* 0FC4A4 802D7AF4 8C450000 */   lw    $a1, ($v0)
/* 0FC4A8 802D7AF8 0C016914 */  jal   remove_effect
/* 0FC4AC 802D7AFC 0040202D */   daddu $a0, $v0, $zero
/* 0FC4B0 802D7B00 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FC4B4 802D7B04 24020002 */  addiu $v0, $zero, 2
/* 0FC4B8 802D7B08 03E00008 */  jr    $ra
/* 0FC4BC 802D7B0C 27BD0018 */   addiu $sp, $sp, 0x18

glabel func_802D7B10
/* 0FC4C0 802D7B10 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FC4C4 802D7B14 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FC4C8 802D7B18 8C82000C */  lw    $v0, 0xc($a0)
/* 0FC4CC 802D7B1C 0C0B1EAF */  jal   get_variable
/* 0FC4D0 802D7B20 8C450000 */   lw    $a1, ($v0)
/* 0FC4D4 802D7B24 0040202D */  daddu $a0, $v0, $zero
/* 0FC4D8 802D7B28 8C830000 */  lw    $v1, ($a0)
/* 0FC4DC 802D7B2C 34630010 */  ori   $v1, $v1, 0x10
/* 0FC4E0 802D7B30 AC830000 */  sw    $v1, ($a0)
/* 0FC4E4 802D7B34 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FC4E8 802D7B38 24020002 */  addiu $v0, $zero, 2
/* 0FC4EC 802D7B3C 03E00008 */  jr    $ra
/* 0FC4F0 802D7B40 27BD0018 */   addiu $sp, $sp, 0x18

glabel func_802D7B44
/* 0FC4F4 802D7B44 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FC4F8 802D7B48 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FC4FC 802D7B4C 8C82000C */  lw    $v0, 0xc($a0)
/* 0FC500 802D7B50 0C0B1EAF */  jal   get_variable
/* 0FC504 802D7B54 8C450000 */   lw    $a1, ($v0)
/* 0FC508 802D7B58 8C44000C */  lw    $a0, 0xc($v0)
/* 0FC50C 802D7B5C 2403000A */  addiu $v1, $zero, 0xa
/* 0FC510 802D7B60 AC830014 */  sw    $v1, 0x14($a0)
/* 0FC514 802D7B64 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FC518 802D7B68 24020002 */  addiu $v0, $zero, 2
/* 0FC51C 802D7B6C 03E00008 */  jr    $ra
/* 0FC520 802D7B70 27BD0018 */   addiu $sp, $sp, 0x18

glabel func_802D7B74
/* 0FC524 802D7B74 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FC528 802D7B78 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FC52C 802D7B7C 8C82000C */  lw    $v0, 0xc($a0)
/* 0FC530 802D7B80 0C0B1EAF */  jal   get_variable
/* 0FC534 802D7B84 8C450000 */   lw    $a1, ($v0)
/* 0FC538 802D7B88 8C44000C */  lw    $a0, 0xc($v0)
/* 0FC53C 802D7B8C 24030005 */  addiu $v1, $zero, 5
/* 0FC540 802D7B90 AC830030 */  sw    $v1, 0x30($a0)
/* 0FC544 802D7B94 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FC548 802D7B98 24020002 */  addiu $v0, $zero, 2
/* 0FC54C 802D7B9C 03E00008 */  jr    $ra
/* 0FC550 802D7BA0 27BD0018 */   addiu $sp, $sp, 0x18

glabel func_802D7BA4
/* 0FC554 802D7BA4 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0FC558 802D7BA8 AFB00018 */  sw    $s0, 0x18($sp)
/* 0FC55C 802D7BAC 0080802D */  daddu $s0, $a0, $zero
/* 0FC560 802D7BB0 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0FC564 802D7BB4 AFB60030 */  sw    $s6, 0x30($sp)
/* 0FC568 802D7BB8 AFB5002C */  sw    $s5, 0x2c($sp)
/* 0FC56C 802D7BBC AFB40028 */  sw    $s4, 0x28($sp)
/* 0FC570 802D7BC0 AFB30024 */  sw    $s3, 0x24($sp)
/* 0FC574 802D7BC4 AFB20020 */  sw    $s2, 0x20($sp)
/* 0FC578 802D7BC8 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0FC57C 802D7BCC 8E130088 */  lw    $s3, 0x88($s0)
/* 0FC580 802D7BD0 8E14008C */  lw    $s4, 0x8c($s0)
/* 0FC584 802D7BD4 8E150090 */  lw    $s5, 0x90($s0)
/* 0FC588 802D7BD8 8E160094 */  lw    $s6, 0x94($s0)
/* 0FC58C 802D7BDC 8E120098 */  lw    $s2, 0x98($s0)
/* 0FC590 802D7BE0 8E11009C */  lw    $s1, 0x9c($s0)
/* 0FC594 802D7BE4 10A00012 */  beqz  $a1, .L802D7C30
/* 0FC598 802D7BE8 27A50010 */   addiu $a1, $sp, 0x10
/* 0FC59C 802D7BEC 24040001 */  addiu $a0, $zero, 1
/* 0FC5A0 802D7BF0 27A60014 */  addiu $a2, $sp, 0x14
/* 0FC5A4 802D7BF4 0C04DF70 */  jal   func_80137DC0
/* 0FC5A8 802D7BF8 AE110070 */   sw    $s1, 0x70($s0)
/* 0FC5AC 802D7BFC 24040001 */  addiu $a0, $zero, 1
/* 0FC5B0 802D7C00 0000282D */  daddu $a1, $zero, $zero
/* 0FC5B4 802D7C04 0260302D */  daddu $a2, $s3, $zero
/* 0FC5B8 802D7C08 C7A00014 */  lwc1  $f0, 0x14($sp)
/* 0FC5BC 802D7C0C 4600008D */  trunc.w.s $f2, $f0
/* 0FC5C0 802D7C10 E6020074 */  swc1  $f2, 0x74($s0)
/* 0FC5C4 802D7C14 0C04DF93 */  jal   func_80137E4C
/* 0FC5C8 802D7C18 0280382D */   daddu $a3, $s4, $zero
/* 0FC5CC 802D7C1C 24040001 */  addiu $a0, $zero, 1
/* 0FC5D0 802D7C20 0080282D */  daddu $a1, $a0, $zero
/* 0FC5D4 802D7C24 02A0302D */  daddu $a2, $s5, $zero
/* 0FC5D8 802D7C28 0C04DF93 */  jal   func_80137E4C
/* 0FC5DC 802D7C2C 02C0382D */   daddu $a3, $s6, $zero
.L802D7C30:
/* 0FC5E0 802D7C30 24040001 */  addiu $a0, $zero, 1
/* 0FC5E4 802D7C34 27A50010 */  addiu $a1, $sp, 0x10
/* 0FC5E8 802D7C38 0C04DF70 */  jal   func_80137DC0
/* 0FC5EC 802D7C3C 27A60014 */   addiu $a2, $sp, 0x14
/* 0FC5F0 802D7C40 8E020074 */  lw    $v0, 0x74($s0)
/* 0FC5F4 802D7C44 8E030070 */  lw    $v1, 0x70($s0)
/* 0FC5F8 802D7C48 00521023 */  subu  $v0, $v0, $s2
/* 0FC5FC 802D7C4C 00430018 */  mult  $v0, $v1
/* 0FC600 802D7C50 00001812 */  mflo  $v1
/* 0FC604 802D7C54 00000000 */  nop   
/* 0FC608 802D7C58 16200002 */  bnez  $s1, .L802D7C64
/* 0FC60C 802D7C5C 0071001A */   div   $zero, $v1, $s1
/* 0FC610 802D7C60 0007000D */  break 7
.L802D7C64:
/* 0FC614 802D7C64 2401FFFF */  addiu $at, $zero, -1
/* 0FC618 802D7C68 16210004 */  bne   $s1, $at, .L802D7C7C
/* 0FC61C 802D7C6C 3C018000 */   lui   $at, 0x8000
/* 0FC620 802D7C70 14610002 */  bne   $v1, $at, .L802D7C7C
/* 0FC624 802D7C74 00000000 */   nop   
/* 0FC628 802D7C78 0006000D */  break 6
.L802D7C7C:
/* 0FC62C 802D7C7C 00001012 */  mflo  $v0
/* 0FC630 802D7C80 00521021 */  addu  $v0, $v0, $s2
/* 0FC634 802D7C84 44821000 */  mtc1  $v0, $f2
/* 0FC638 802D7C88 00000000 */  nop   
/* 0FC63C 802D7C8C 468010A0 */  cvt.s.w $f2, $f2
/* 0FC640 802D7C90 44051000 */  mfc1  $a1, $f2
/* 0FC644 802D7C94 0C04DF69 */  jal   func_80137DA4
/* 0FC648 802D7C98 2404000C */   addiu $a0, $zero, 0xc
/* 0FC64C 802D7C9C 8E020070 */  lw    $v0, 0x70($s0)
/* 0FC650 802D7CA0 2442FFFF */  addiu $v0, $v0, -1
/* 0FC654 802D7CA4 04400003 */  bltz  $v0, .L802D7CB4
/* 0FC658 802D7CA8 AE020070 */   sw    $v0, 0x70($s0)
/* 0FC65C 802D7CAC 080B5F34 */  j     .L802D7CD0
/* 0FC660 802D7CB0 0000102D */   daddu $v0, $zero, $zero

.L802D7CB4:
/* 0FC664 802D7CB4 44921000 */  mtc1  $s2, $f2
/* 0FC668 802D7CB8 00000000 */  nop   
/* 0FC66C 802D7CBC 468010A0 */  cvt.s.w $f2, $f2
/* 0FC670 802D7CC0 44051000 */  mfc1  $a1, $f2
/* 0FC674 802D7CC4 0C04DF69 */  jal   func_80137DA4
/* 0FC678 802D7CC8 2404000C */   addiu $a0, $zero, 0xc
/* 0FC67C 802D7CCC 24020002 */  addiu $v0, $zero, 2
.L802D7CD0:
/* 0FC680 802D7CD0 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0FC684 802D7CD4 8FB60030 */  lw    $s6, 0x30($sp)
/* 0FC688 802D7CD8 8FB5002C */  lw    $s5, 0x2c($sp)
/* 0FC68C 802D7CDC 8FB40028 */  lw    $s4, 0x28($sp)
/* 0FC690 802D7CE0 8FB30024 */  lw    $s3, 0x24($sp)
/* 0FC694 802D7CE4 8FB20020 */  lw    $s2, 0x20($sp)
/* 0FC698 802D7CE8 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0FC69C 802D7CEC 8FB00018 */  lw    $s0, 0x18($sp)
/* 0FC6A0 802D7CF0 03E00008 */  jr    $ra
/* 0FC6A4 802D7CF4 27BD0038 */   addiu $sp, $sp, 0x38

glabel func_802D7CF8
/* 0FC6A8 802D7CF8 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0FC6AC 802D7CFC AFB10014 */  sw    $s1, 0x14($sp)
/* 0FC6B0 802D7D00 0080882D */  daddu $s1, $a0, $zero
/* 0FC6B4 802D7D04 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0FC6B8 802D7D08 AFB60028 */  sw    $s6, 0x28($sp)
/* 0FC6BC 802D7D0C AFB50024 */  sw    $s5, 0x24($sp)
/* 0FC6C0 802D7D10 AFB40020 */  sw    $s4, 0x20($sp)
/* 0FC6C4 802D7D14 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0FC6C8 802D7D18 AFB20018 */  sw    $s2, 0x18($sp)
/* 0FC6CC 802D7D1C AFB00010 */  sw    $s0, 0x10($sp)
/* 0FC6D0 802D7D20 8E30000C */  lw    $s0, 0xc($s1)
/* 0FC6D4 802D7D24 8E050000 */  lw    $a1, ($s0)
/* 0FC6D8 802D7D28 0C0B1EAF */  jal   get_variable
/* 0FC6DC 802D7D2C 26100004 */   addiu $s0, $s0, 4
/* 0FC6E0 802D7D30 8E050000 */  lw    $a1, ($s0)
/* 0FC6E4 802D7D34 26100004 */  addiu $s0, $s0, 4
/* 0FC6E8 802D7D38 0220202D */  daddu $a0, $s1, $zero
/* 0FC6EC 802D7D3C 0C0B1EAF */  jal   get_variable
/* 0FC6F0 802D7D40 0040B02D */   daddu $s6, $v0, $zero
/* 0FC6F4 802D7D44 8E050000 */  lw    $a1, ($s0)
/* 0FC6F8 802D7D48 26100004 */  addiu $s0, $s0, 4
/* 0FC6FC 802D7D4C 0220202D */  daddu $a0, $s1, $zero
/* 0FC700 802D7D50 0C0B1EAF */  jal   get_variable
/* 0FC704 802D7D54 0040A82D */   daddu $s5, $v0, $zero
/* 0FC708 802D7D58 8E050000 */  lw    $a1, ($s0)
/* 0FC70C 802D7D5C 26100004 */  addiu $s0, $s0, 4
/* 0FC710 802D7D60 0220202D */  daddu $a0, $s1, $zero
/* 0FC714 802D7D64 0C0B1EAF */  jal   get_variable
/* 0FC718 802D7D68 0040A02D */   daddu $s4, $v0, $zero
/* 0FC71C 802D7D6C 8E050000 */  lw    $a1, ($s0)
/* 0FC720 802D7D70 26100004 */  addiu $s0, $s0, 4
/* 0FC724 802D7D74 0220202D */  daddu $a0, $s1, $zero
/* 0FC728 802D7D78 0C0B1EAF */  jal   get_variable
/* 0FC72C 802D7D7C 0040982D */   daddu $s3, $v0, $zero
/* 0FC730 802D7D80 8E050000 */  lw    $a1, ($s0)
/* 0FC734 802D7D84 26100004 */  addiu $s0, $s0, 4
/* 0FC738 802D7D88 0220202D */  daddu $a0, $s1, $zero
/* 0FC73C 802D7D8C 0C0B1EAF */  jal   get_variable
/* 0FC740 802D7D90 0040902D */   daddu $s2, $v0, $zero
/* 0FC744 802D7D94 0220202D */  daddu $a0, $s1, $zero
/* 0FC748 802D7D98 8E050000 */  lw    $a1, ($s0)
/* 0FC74C 802D7D9C 0C0B1EAF */  jal   get_variable
/* 0FC750 802D7DA0 0040882D */   daddu $s1, $v0, $zero
/* 0FC754 802D7DA4 3C04802E */  lui   $a0, 0x802e
/* 0FC758 802D7DA8 24849D50 */  addiu $a0, $a0, -0x62b0
/* 0FC75C 802D7DAC 24050001 */  addiu $a1, $zero, 1
/* 0FC760 802D7DB0 0040802D */  daddu $s0, $v0, $zero
/* 0FC764 802D7DB4 0C0B0CF8 */  jal   start_script
/* 0FC768 802D7DB8 0000302D */   daddu $a2, $zero, $zero
/* 0FC76C 802D7DBC 0040182D */  daddu $v1, $v0, $zero
/* 0FC770 802D7DC0 AC760084 */  sw    $s6, 0x84($v1)
/* 0FC774 802D7DC4 AC750088 */  sw    $s5, 0x88($v1)
/* 0FC778 802D7DC8 AC74008C */  sw    $s4, 0x8c($v1)
/* 0FC77C 802D7DCC AC730090 */  sw    $s3, 0x90($v1)
/* 0FC780 802D7DD0 AC720094 */  sw    $s2, 0x94($v1)
/* 0FC784 802D7DD4 AC710098 */  sw    $s1, 0x98($v1)
/* 0FC788 802D7DD8 AC70009C */  sw    $s0, 0x9c($v1)
/* 0FC78C 802D7DDC 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0FC790 802D7DE0 8FB60028 */  lw    $s6, 0x28($sp)
/* 0FC794 802D7DE4 8FB50024 */  lw    $s5, 0x24($sp)
/* 0FC798 802D7DE8 8FB40020 */  lw    $s4, 0x20($sp)
/* 0FC79C 802D7DEC 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0FC7A0 802D7DF0 8FB20018 */  lw    $s2, 0x18($sp)
/* 0FC7A4 802D7DF4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FC7A8 802D7DF8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FC7AC 802D7DFC 24020002 */  addiu $v0, $zero, 2
/* 0FC7B0 802D7E00 03E00008 */  jr    $ra
/* 0FC7B4 802D7E04 27BD0030 */   addiu $sp, $sp, 0x30

glabel func_802D7E08
/* 0FC7B8 802D7E08 27BDFFA0 */  addiu $sp, $sp, -0x60
/* 0FC7BC 802D7E0C AFB10024 */  sw    $s1, 0x24($sp)
/* 0FC7C0 802D7E10 0080882D */  daddu $s1, $a0, $zero
/* 0FC7C4 802D7E14 AFBF0034 */  sw    $ra, 0x34($sp)
/* 0FC7C8 802D7E18 AFB40030 */  sw    $s4, 0x30($sp)
/* 0FC7CC 802D7E1C AFB3002C */  sw    $s3, 0x2c($sp)
/* 0FC7D0 802D7E20 AFB20028 */  sw    $s2, 0x28($sp)
/* 0FC7D4 802D7E24 AFB00020 */  sw    $s0, 0x20($sp)
/* 0FC7D8 802D7E28 F7BC0058 */  sdc1  $f28, 0x58($sp)
/* 0FC7DC 802D7E2C F7BA0050 */  sdc1  $f26, 0x50($sp)
/* 0FC7E0 802D7E30 F7B80048 */  sdc1  $f24, 0x48($sp)
/* 0FC7E4 802D7E34 F7B60040 */  sdc1  $f22, 0x40($sp)
/* 0FC7E8 802D7E38 F7B40038 */  sdc1  $f20, 0x38($sp)
/* 0FC7EC 802D7E3C 8E30000C */  lw    $s0, 0xc($s1)
/* 0FC7F0 802D7E40 8E050000 */  lw    $a1, ($s0)
/* 0FC7F4 802D7E44 0C0B1EAF */  jal   get_variable
/* 0FC7F8 802D7E48 26100004 */   addiu $s0, $s0, 4
/* 0FC7FC 802D7E4C 8E050000 */  lw    $a1, ($s0)
/* 0FC800 802D7E50 26100004 */  addiu $s0, $s0, 4
/* 0FC804 802D7E54 0220202D */  daddu $a0, $s1, $zero
/* 0FC808 802D7E58 0C0B1EAF */  jal   get_variable
/* 0FC80C 802D7E5C 0040982D */   daddu $s3, $v0, $zero
/* 0FC810 802D7E60 8E050000 */  lw    $a1, ($s0)
/* 0FC814 802D7E64 26100004 */  addiu $s0, $s0, 4
/* 0FC818 802D7E68 0220202D */  daddu $a0, $s1, $zero
/* 0FC81C 802D7E6C 0C0B210B */  jal   get_float_variable
/* 0FC820 802D7E70 0040A02D */   daddu $s4, $v0, $zero
/* 0FC824 802D7E74 8E050000 */  lw    $a1, ($s0)
/* 0FC828 802D7E78 26100004 */  addiu $s0, $s0, 4
/* 0FC82C 802D7E7C 0220202D */  daddu $a0, $s1, $zero
/* 0FC830 802D7E80 0C0B1EAF */  jal   get_variable
/* 0FC834 802D7E84 46000706 */   mov.s $f28, $f0
/* 0FC838 802D7E88 8E050000 */  lw    $a1, ($s0)
/* 0FC83C 802D7E8C 26100004 */  addiu $s0, $s0, 4
/* 0FC840 802D7E90 0220202D */  daddu $a0, $s1, $zero
/* 0FC844 802D7E94 0C0B210B */  jal   get_float_variable
/* 0FC848 802D7E98 0040902D */   daddu $s2, $v0, $zero
/* 0FC84C 802D7E9C 8E050000 */  lw    $a1, ($s0)
/* 0FC850 802D7EA0 26100004 */  addiu $s0, $s0, 4
/* 0FC854 802D7EA4 0220202D */  daddu $a0, $s1, $zero
/* 0FC858 802D7EA8 0C0B210B */  jal   get_float_variable
/* 0FC85C 802D7EAC 46000686 */   mov.s $f26, $f0
/* 0FC860 802D7EB0 8E050000 */  lw    $a1, ($s0)
/* 0FC864 802D7EB4 26100004 */  addiu $s0, $s0, 4
/* 0FC868 802D7EB8 0220202D */  daddu $a0, $s1, $zero
/* 0FC86C 802D7EBC 0C0B210B */  jal   get_float_variable
/* 0FC870 802D7EC0 46000606 */   mov.s $f24, $f0
/* 0FC874 802D7EC4 8E050000 */  lw    $a1, ($s0)
/* 0FC878 802D7EC8 26100004 */  addiu $s0, $s0, 4
/* 0FC87C 802D7ECC 0220202D */  daddu $a0, $s1, $zero
/* 0FC880 802D7ED0 0C0B210B */  jal   get_float_variable
/* 0FC884 802D7ED4 46000586 */   mov.s $f22, $f0
/* 0FC888 802D7ED8 0220202D */  daddu $a0, $s1, $zero
/* 0FC88C 802D7EDC 8E050000 */  lw    $a1, ($s0)
/* 0FC890 802D7EE0 0C0B1EAF */  jal   get_variable
/* 0FC894 802D7EE4 46000506 */   mov.s $f20, $f0
/* 0FC898 802D7EE8 12400006 */  beqz  $s2, .L802D7F04
/* 0FC89C 802D7EEC 0040802D */   daddu $s0, $v0, $zero
/* 0FC8A0 802D7EF0 24020001 */  addiu $v0, $zero, 1
/* 0FC8A4 802D7EF4 12420014 */  beq   $s2, $v0, .L802D7F48
/* 0FC8A8 802D7EF8 4600D206 */   mov.s $f8, $f26
/* 0FC8AC 802D7EFC 080B5FF2 */  j     .L802D7FC8
/* 0FC8B0 802D7F00 4600C006 */   mov.s $f0, $f24

.L802D7F04:
/* 0FC8B4 802D7F04 3C055555 */  lui   $a1, 0x5555
/* 0FC8B8 802D7F08 3C048011 */  lui   $a0, 0x8011
/* 0FC8BC 802D7F0C 2484EFC8 */  addiu $a0, $a0, -0x1038
/* 0FC8C0 802D7F10 948200B0 */  lhu   $v0, 0xb0($a0)
/* 0FC8C4 802D7F14 34A55556 */  ori   $a1, $a1, 0x5556
/* 0FC8C8 802D7F18 00021400 */  sll   $v0, $v0, 0x10
/* 0FC8CC 802D7F1C 00021C03 */  sra   $v1, $v0, 0x10
/* 0FC8D0 802D7F20 00650018 */  mult  $v1, $a1
/* 0FC8D4 802D7F24 C4880028 */  lwc1  $f8, 0x28($a0)
/* 0FC8D8 802D7F28 C4860030 */  lwc1  $f6, 0x30($a0)
/* 0FC8DC 802D7F2C C482002C */  lwc1  $f2, 0x2c($a0)
/* 0FC8E0 802D7F30 00031840 */  sll   $v1, $v1, 1
/* 0FC8E4 802D7F34 00004010 */  mfhi  $t0
/* 0FC8E8 802D7F38 000217C3 */  sra   $v0, $v0, 0x1f
/* 0FC8EC 802D7F3C 01021023 */  subu  $v0, $t0, $v0
/* 0FC8F0 802D7F40 080B5FE5 */  j     .L802D7F94
/* 0FC8F4 802D7F44 00650018 */   mult  $v1, $a1

.L802D7F48:
/* 0FC8F8 802D7F48 0220202D */  daddu $a0, $s1, $zero
/* 0FC8FC 802D7F4C 0C0B36B0 */  jal   func_802CDAC0
/* 0FC900 802D7F50 0260282D */   daddu $a1, $s3, $zero
/* 0FC904 802D7F54 0040282D */  daddu $a1, $v0, $zero
/* 0FC908 802D7F58 10A00025 */  beqz  $a1, .L802D7FF0
/* 0FC90C 802D7F5C 3C045555 */   lui   $a0, 0x5555
/* 0FC910 802D7F60 94A200A8 */  lhu   $v0, 0xa8($a1)
/* 0FC914 802D7F64 34845556 */  ori   $a0, $a0, 0x5556
/* 0FC918 802D7F68 00021400 */  sll   $v0, $v0, 0x10
/* 0FC91C 802D7F6C 00021C03 */  sra   $v1, $v0, 0x10
/* 0FC920 802D7F70 00640018 */  mult  $v1, $a0
/* 0FC924 802D7F74 C4A80038 */  lwc1  $f8, 0x38($a1)
/* 0FC928 802D7F78 C4A60040 */  lwc1  $f6, 0x40($a1)
/* 0FC92C 802D7F7C C4A2003C */  lwc1  $f2, 0x3c($a1)
/* 0FC930 802D7F80 00031840 */  sll   $v1, $v1, 1
/* 0FC934 802D7F84 00004010 */  mfhi  $t0
/* 0FC938 802D7F88 000217C3 */  sra   $v0, $v0, 0x1f
/* 0FC93C 802D7F8C 01021023 */  subu  $v0, $t0, $v0
/* 0FC940 802D7F90 00640018 */  mult  $v1, $a0
.L802D7F94:
/* 0FC944 802D7F94 00021400 */  sll   $v0, $v0, 0x10
/* 0FC948 802D7F98 00021403 */  sra   $v0, $v0, 0x10
/* 0FC94C 802D7F9C 44822000 */  mtc1  $v0, $f4
/* 0FC950 802D7FA0 00000000 */  nop   
/* 0FC954 802D7FA4 46802120 */  cvt.s.w $f4, $f4
/* 0FC958 802D7FA8 00031FC3 */  sra   $v1, $v1, 0x1f
/* 0FC95C 802D7FAC 00004010 */  mfhi  $t0
/* 0FC960 802D7FB0 01031823 */  subu  $v1, $t0, $v1
/* 0FC964 802D7FB4 44830000 */  mtc1  $v1, $f0
/* 0FC968 802D7FB8 00000000 */  nop   
/* 0FC96C 802D7FBC 46800020 */  cvt.s.w $f0, $f0
/* 0FC970 802D7FC0 080B5FF4 */  j     .L802D7FD0
/* 0FC974 802D7FC4 46001000 */   add.s $f0, $f2, $f0

.L802D7FC8:
/* 0FC978 802D7FC8 4600B186 */  mov.s $f6, $f22
/* 0FC97C 802D7FCC 4600A106 */  mov.s $f4, $f20
.L802D7FD0:
/* 0FC980 802D7FD0 44054000 */  mfc1  $a1, $f8
/* 0FC984 802D7FD4 44060000 */  mfc1  $a2, $f0
/* 0FC988 802D7FD8 44073000 */  mfc1  $a3, $f6
/* 0FC98C 802D7FDC 0280202D */  daddu $a0, $s4, $zero
/* 0FC990 802D7FE0 E7A40010 */  swc1  $f4, 0x10($sp)
/* 0FC994 802D7FE4 E7BC0014 */  swc1  $f28, 0x14($sp)
/* 0FC998 802D7FE8 0C01C1E4 */  jal   fx_sweat
/* 0FC99C 802D7FEC AFB00018 */   sw    $s0, 0x18($sp)
.L802D7FF0:
/* 0FC9A0 802D7FF0 24020002 */  addiu $v0, $zero, 2
/* 0FC9A4 802D7FF4 8FBF0034 */  lw    $ra, 0x34($sp)
/* 0FC9A8 802D7FF8 8FB40030 */  lw    $s4, 0x30($sp)
/* 0FC9AC 802D7FFC 8FB3002C */  lw    $s3, 0x2c($sp)
/* 0FC9B0 802D8000 8FB20028 */  lw    $s2, 0x28($sp)
/* 0FC9B4 802D8004 8FB10024 */  lw    $s1, 0x24($sp)
/* 0FC9B8 802D8008 8FB00020 */  lw    $s0, 0x20($sp)
/* 0FC9BC 802D800C D7BC0058 */  ldc1  $f28, 0x58($sp)
/* 0FC9C0 802D8010 D7BA0050 */  ldc1  $f26, 0x50($sp)
/* 0FC9C4 802D8014 D7B80048 */  ldc1  $f24, 0x48($sp)
/* 0FC9C8 802D8018 D7B60040 */  ldc1  $f22, 0x40($sp)
/* 0FC9CC 802D801C D7B40038 */  ldc1  $f20, 0x38($sp)
/* 0FC9D0 802D8020 03E00008 */  jr    $ra
/* 0FC9D4 802D8024 27BD0060 */   addiu $sp, $sp, 0x60

