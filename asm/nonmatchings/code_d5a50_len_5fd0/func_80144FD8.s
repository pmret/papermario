.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80144FD8
/* 0DB6D8 80144FD8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0DB6DC 80144FDC 2402F7FF */  addiu $v0, $zero, -0x801
/* 0DB6E0 80144FE0 00821024 */  and   $v0, $a0, $v0
/* 0DB6E4 80144FE4 00021080 */  sll   $v0, $v0, 2
/* 0DB6E8 80144FE8 3C038015 */  lui   $v1, 0x8015
/* 0DB6EC 80144FEC 8C637960 */  lw    $v1, 0x7960($v1)
/* 0DB6F0 80144FF0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0DB6F4 80144FF4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0DB6F8 80144FF8 00431021 */  addu  $v0, $v0, $v1
/* 0DB6FC 80144FFC 8C500000 */  lw    $s0, ($v0)
/* 0DB700 80145000 0C00AB0A */  jal   general_heap_malloc
/* 0DB704 80145004 240400F0 */   addiu $a0, $zero, 0xf0
/* 0DB708 80145008 0040202D */  daddu $a0, $v0, $zero
/* 0DB70C 8014500C 14800003 */  bnez  $a0, .L8014501C
/* 0DB710 80145010 AE04001C */   sw    $a0, 0x1c($s0)
.L80145014:
/* 0DB714 80145014 08051405 */  j     .L80145014
/* 0DB718 80145018 00000000 */   nop   

.L8014501C:
/* 0DB71C 8014501C 3C020003 */  lui   $v0, 3
/* 0DB720 80145020 8E030000 */  lw    $v1, ($s0)
/* 0DB724 80145024 3C013F80 */  lui   $at, 0x3f80
/* 0DB728 80145028 44810000 */  mtc1  $at, $f0
/* 0DB72C 8014502C 00621825 */  or    $v1, $v1, $v0
/* 0DB730 80145030 AE030000 */  sw    $v1, ($s0)
/* 0DB734 80145034 AC800000 */  sw    $zero, ($a0)
/* 0DB738 80145038 AC800004 */  sw    $zero, 4($a0)
/* 0DB73C 8014503C AC800008 */  sw    $zero, 8($a0)
/* 0DB740 80145040 AC80000C */  sw    $zero, 0xc($a0)
/* 0DB744 80145044 AC800010 */  sw    $zero, 0x10($a0)
/* 0DB748 80145048 AC800014 */  sw    $zero, 0x14($a0)
/* 0DB74C 8014504C AC800018 */  sw    $zero, 0x18($a0)
/* 0DB750 80145050 E480001C */  swc1  $f0, 0x1c($a0)
/* 0DB754 80145054 E4800020 */  swc1  $f0, 0x20($a0)
/* 0DB758 80145058 0C0504FE */  jal   func_801413F8
/* 0DB75C 8014505C E4800024 */   swc1  $f0, 0x24($a0)
/* 0DB760 80145060 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0DB764 80145064 8FB00010 */  lw    $s0, 0x10($sp)
/* 0DB768 80145068 03E00008 */  jr    $ra
/* 0DB76C 8014506C 27BD0018 */   addiu $sp, $sp, 0x18

/* 0DB770 80145070 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0DB774 80145074 2402F7FF */  addiu $v0, $zero, -0x801
/* 0DB778 80145078 00821024 */  and   $v0, $a0, $v0
/* 0DB77C 8014507C 00021080 */  sll   $v0, $v0, 2
/* 0DB780 80145080 3C038015 */  lui   $v1, 0x8015
/* 0DB784 80145084 8C637960 */  lw    $v1, 0x7960($v1)
/* 0DB788 80145088 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0DB78C 8014508C AFB00010 */  sw    $s0, 0x10($sp)
/* 0DB790 80145090 00431021 */  addu  $v0, $v0, $v1
/* 0DB794 80145094 8C500000 */  lw    $s0, ($v0)
/* 0DB798 80145098 0C00AB0A */  jal   general_heap_malloc
/* 0DB79C 8014509C 240400F0 */   addiu $a0, $zero, 0xf0
/* 0DB7A0 801450A0 0040202D */  daddu $a0, $v0, $zero
/* 0DB7A4 801450A4 14800003 */  bnez  $a0, .L801450B4
/* 0DB7A8 801450A8 AE04001C */   sw    $a0, 0x1c($s0)
.L801450AC:
/* 0DB7AC 801450AC 0805142B */  j     .L801450AC
/* 0DB7B0 801450B0 00000000 */   nop   

.L801450B4:
/* 0DB7B4 801450B4 3C024003 */  lui   $v0, 0x4003
/* 0DB7B8 801450B8 8E030000 */  lw    $v1, ($s0)
/* 0DB7BC 801450BC 3C013F80 */  lui   $at, 0x3f80
/* 0DB7C0 801450C0 44810000 */  mtc1  $at, $f0
/* 0DB7C4 801450C4 00621825 */  or    $v1, $v1, $v0
/* 0DB7C8 801450C8 AE030000 */  sw    $v1, ($s0)
/* 0DB7CC 801450CC AC800000 */  sw    $zero, ($a0)
/* 0DB7D0 801450D0 AC800004 */  sw    $zero, 4($a0)
/* 0DB7D4 801450D4 AC800008 */  sw    $zero, 8($a0)
/* 0DB7D8 801450D8 AC80000C */  sw    $zero, 0xc($a0)
/* 0DB7DC 801450DC AC800010 */  sw    $zero, 0x10($a0)
/* 0DB7E0 801450E0 AC800014 */  sw    $zero, 0x14($a0)
/* 0DB7E4 801450E4 AC800018 */  sw    $zero, 0x18($a0)
/* 0DB7E8 801450E8 E480001C */  swc1  $f0, 0x1c($a0)
/* 0DB7EC 801450EC E4800020 */  swc1  $f0, 0x20($a0)
/* 0DB7F0 801450F0 0C0504FE */  jal   func_801413F8
/* 0DB7F4 801450F4 E4800024 */   swc1  $f0, 0x24($a0)
/* 0DB7F8 801450F8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0DB7FC 801450FC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0DB800 80145100 03E00008 */  jr    $ra
/* 0DB804 80145104 27BD0018 */   addiu $sp, $sp, 0x18

