.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802C95A0
/* 0EDF50 802C95A0 27BDFE70 */  addiu $sp, $sp, -0x190
/* 0EDF54 802C95A4 AFB40188 */  sw    $s4, 0x188($sp)
/* 0EDF58 802C95A8 0080A02D */  daddu $s4, $a0, $zero
/* 0EDF5C 802C95AC AFB30184 */  sw    $s3, 0x184($sp)
/* 0EDF60 802C95B0 00A0982D */  daddu $s3, $a1, $zero
/* 0EDF64 802C95B4 AFBF018C */  sw    $ra, 0x18c($sp)
/* 0EDF68 802C95B8 AFB20180 */  sw    $s2, 0x180($sp)
/* 0EDF6C 802C95BC AFB1017C */  sw    $s1, 0x17c($sp)
/* 0EDF70 802C95C0 AFB00178 */  sw    $s0, 0x178($sp)
/* 0EDF74 802C95C4 8E62000C */  lw    $v0, 0xc($s3)
/* 0EDF78 802C95C8 2411FFFF */  addiu $s1, $zero, -1
/* 0EDF7C 802C95CC 8C450000 */  lw    $a1, ($v0)
/* 0EDF80 802C95D0 0C0B1EAF */  jal   get_variable
/* 0EDF84 802C95D4 0260202D */   daddu $a0, $s3, $zero
/* 0EDF88 802C95D8 0040282D */  daddu $a1, $v0, $zero
/* 0EDF8C 802C95DC 3C06800A */  lui   $a2, 0x800a
/* 0EDF90 802C95E0 8CC6A5F4 */  lw    $a2, -0x5a0c($a2)
/* 0EDF94 802C95E4 00051080 */  sll   $v0, $a1, 2
/* 0EDF98 802C95E8 00462021 */  addu  $a0, $v0, $a2
/* 0EDF9C 802C95EC 90830000 */  lbu   $v1, ($a0)
/* 0EDFA0 802C95F0 286200FF */  slti  $v0, $v1, 0xff
/* 0EDFA4 802C95F4 10400004 */  beqz  $v0, .L802C9608
/* 0EDFA8 802C95F8 0220902D */   daddu $s2, $s1, $zero
/* 0EDFAC 802C95FC 0060902D */  daddu $s2, $v1, $zero
/* 0EDFB0 802C9600 080B2597 */  j     .L802C965C
/* 0EDFB4 802C9604 0240882D */   daddu $s1, $s2, $zero

.L802C9608:
/* 0EDFB8 802C9608 24B0FFFF */  addiu $s0, $a1, -1
/* 0EDFBC 802C960C 90850001 */  lbu   $a1, 1($a0)
/* 0EDFC0 802C9610 06000013 */  bltz  $s0, .L802C9660
/* 0EDFC4 802C9614 27A20010 */   addiu $v0, $sp, 0x10
/* 0EDFC8 802C9618 2407FFFF */  addiu $a3, $zero, -1
/* 0EDFCC 802C961C 00101080 */  sll   $v0, $s0, 2
/* 0EDFD0 802C9620 00462021 */  addu  $a0, $v0, $a2
.L802C9624:
/* 0EDFD4 802C9624 90820001 */  lbu   $v0, 1($a0)
/* 0EDFD8 802C9628 00A2102A */  slt   $v0, $a1, $v0
/* 0EDFDC 802C962C 1040000C */  beqz  $v0, .L802C9660
/* 0EDFE0 802C9630 27A20010 */   addiu $v0, $sp, 0x10
/* 0EDFE4 802C9634 90830000 */  lbu   $v1, ($a0)
/* 0EDFE8 802C9638 286200FF */  slti  $v0, $v1, 0xff
/* 0EDFEC 802C963C 50400005 */  beql  $v0, $zero, .L802C9654
/* 0EDFF0 802C9640 2610FFFF */   addiu $s0, $s0, -1
/* 0EDFF4 802C9644 52470001 */  beql  $s2, $a3, .L802C964C
/* 0EDFF8 802C9648 0060902D */   daddu $s2, $v1, $zero
.L802C964C:
/* 0EDFFC 802C964C 0060882D */  daddu $s1, $v1, $zero
/* 0EE000 802C9650 2610FFFF */  addiu $s0, $s0, -1
.L802C9654:
/* 0EE004 802C9654 0601FFF3 */  bgez  $s0, .L802C9624
/* 0EE008 802C9658 2484FFFC */   addiu $a0, $a0, -4
.L802C965C:
/* 0EE00C 802C965C 27A20010 */  addiu $v0, $sp, 0x10
.L802C9660:
/* 0EE010 802C9660 0260202D */  daddu $a0, $s3, $zero
/* 0EE014 802C9664 24830160 */  addiu $v1, $a0, 0x160
.L802C9668:
/* 0EE018 802C9668 8C880000 */  lw    $t0, ($a0)
/* 0EE01C 802C966C 8C890004 */  lw    $t1, 4($a0)
/* 0EE020 802C9670 8C8A0008 */  lw    $t2, 8($a0)
/* 0EE024 802C9674 8C8B000C */  lw    $t3, 0xc($a0)
/* 0EE028 802C9678 AC480000 */  sw    $t0, ($v0)
/* 0EE02C 802C967C AC490004 */  sw    $t1, 4($v0)
/* 0EE030 802C9680 AC4A0008 */  sw    $t2, 8($v0)
/* 0EE034 802C9684 AC4B000C */  sw    $t3, 0xc($v0)
/* 0EE038 802C9688 24840010 */  addiu $a0, $a0, 0x10
/* 0EE03C 802C968C 1483FFF6 */  bne   $a0, $v1, .L802C9668
/* 0EE040 802C9690 24420010 */   addiu $v0, $v0, 0x10
/* 0EE044 802C9694 0220802D */  daddu $s0, $s1, $zero
/* 0EE048 802C9698 8C880000 */  lw    $t0, ($a0)
/* 0EE04C 802C969C 8C890004 */  lw    $t1, 4($a0)
/* 0EE050 802C96A0 AC480000 */  sw    $t0, ($v0)
/* 0EE054 802C96A4 AC490004 */  sw    $t1, 4($v0)
/* 0EE058 802C96A8 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0EE05C 802C96AC 0250102A */  slt   $v0, $s2, $s0
/* 0EE060 802C96B0 8E330000 */  lw    $s3, ($s1)
/* 0EE064 802C96B4 54400011 */  bnel  $v0, $zero, .L802C96FC
/* 0EE068 802C96B8 AE330000 */   sw    $s3, ($s1)
/* 0EE06C 802C96BC 27A40010 */  addiu $a0, $sp, 0x10
.L802C96C0:
/* 0EE070 802C96C0 3C038015 */  lui   $v1, 0x8015
/* 0EE074 802C96C4 8C6312CC */  lw    $v1, 0x12cc($v1)
/* 0EE078 802C96C8 00101080 */  sll   $v0, $s0, 2
/* 0EE07C 802C96CC 00431021 */  addu  $v0, $v0, $v1
/* 0EE080 802C96D0 8C420000 */  lw    $v0, ($v0)
/* 0EE084 802C96D4 24050001 */  addiu $a1, $zero, 1
/* 0EE088 802C96D8 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0EE08C 802C96DC 94420002 */  lhu   $v0, 2($v0)
/* 0EE090 802C96E0 02058021 */  addu  $s0, $s0, $a1
/* 0EE094 802C96E4 0280F809 */  jalr  $s4
/* 0EE098 802C96E8 AE220000 */  sw    $v0, ($s1)
/* 0EE09C 802C96EC 0250102A */  slt   $v0, $s2, $s0
/* 0EE0A0 802C96F0 1040FFF3 */  beqz  $v0, .L802C96C0
/* 0EE0A4 802C96F4 27A40010 */   addiu $a0, $sp, 0x10
/* 0EE0A8 802C96F8 AE330000 */  sw    $s3, ($s1)
.L802C96FC:
/* 0EE0AC 802C96FC 8FBF018C */  lw    $ra, 0x18c($sp)
/* 0EE0B0 802C9700 8FB40188 */  lw    $s4, 0x188($sp)
/* 0EE0B4 802C9704 8FB30184 */  lw    $s3, 0x184($sp)
/* 0EE0B8 802C9708 8FB20180 */  lw    $s2, 0x180($sp)
/* 0EE0BC 802C970C 8FB1017C */  lw    $s1, 0x17c($sp)
/* 0EE0C0 802C9710 8FB00178 */  lw    $s0, 0x178($sp)
/* 0EE0C4 802C9714 03E00008 */  jr    $ra
/* 0EE0C8 802C9718 27BD0190 */   addiu $sp, $sp, 0x190

/* 0EE0CC 802C971C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EE0D0 802C9720 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0EE0D4 802C9724 8C82000C */  lw    $v0, 0xc($a0)
/* 0EE0D8 802C9728 0C0B1EAF */  jal   get_variable
/* 0EE0DC 802C972C 8C450000 */   lw    $a1, ($v0)
/* 0EE0E0 802C9730 0C046CDF */  jal   func_8011B37C
/* 0EE0E4 802C9734 3044FFFF */   andi  $a0, $v0, 0xffff
/* 0EE0E8 802C9738 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0EE0EC 802C973C 24020002 */  addiu $v0, $zero, 2
/* 0EE0F0 802C9740 03E00008 */  jr    $ra
/* 0EE0F4 802C9744 27BD0018 */   addiu $sp, $sp, 0x18

/* 0EE0F8 802C9748 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EE0FC 802C974C AFB00010 */  sw    $s0, 0x10($sp)
/* 0EE100 802C9750 0080802D */  daddu $s0, $a0, $zero
/* 0EE104 802C9754 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EE108 802C9758 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EE10C 802C975C 8E11000C */  lw    $s1, 0xc($s0)
/* 0EE110 802C9760 8E250000 */  lw    $a1, ($s1)
/* 0EE114 802C9764 0C0B1EAF */  jal   get_variable
/* 0EE118 802C9768 26310004 */   addiu $s1, $s1, 4
/* 0EE11C 802C976C 0200202D */  daddu $a0, $s0, $zero
/* 0EE120 802C9770 8E250000 */  lw    $a1, ($s1)
/* 0EE124 802C9774 0C0B1EAF */  jal   get_variable
/* 0EE128 802C9778 0040802D */   daddu $s0, $v0, $zero
/* 0EE12C 802C977C 10400005 */  beqz  $v0, .L802C9794
/* 0EE130 802C9780 00000000 */   nop   
/* 0EE134 802C9784 0C046D74 */  jal   func_8011B5D0
/* 0EE138 802C9788 3204FFFF */   andi  $a0, $s0, 0xffff
/* 0EE13C 802C978C 080B25E7 */  j     .L802C979C
/* 0EE140 802C9790 00000000 */   nop   

.L802C9794:
/* 0EE144 802C9794 0C046D98 */  jal   func_8011B660
/* 0EE148 802C9798 3204FFFF */   andi  $a0, $s0, 0xffff
.L802C979C:
/* 0EE14C 802C979C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EE150 802C97A0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EE154 802C97A4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EE158 802C97A8 24020002 */  addiu $v0, $zero, 2
/* 0EE15C 802C97AC 03E00008 */  jr    $ra
/* 0EE160 802C97B0 27BD0020 */   addiu $sp, $sp, 0x20

