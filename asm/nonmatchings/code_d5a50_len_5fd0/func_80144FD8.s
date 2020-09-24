.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80144FD8
/* DB6D8 80144FD8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DB6DC 80144FDC 2402F7FF */  addiu     $v0, $zero, -0x801
/* DB6E0 80144FE0 00821024 */  and       $v0, $a0, $v0
/* DB6E4 80144FE4 00021080 */  sll       $v0, $v0, 2
/* DB6E8 80144FE8 3C038015 */  lui       $v1, 0x8015
/* DB6EC 80144FEC 8C637960 */  lw        $v1, 0x7960($v1)
/* DB6F0 80144FF0 AFBF0014 */  sw        $ra, 0x14($sp)
/* DB6F4 80144FF4 AFB00010 */  sw        $s0, 0x10($sp)
/* DB6F8 80144FF8 00431021 */  addu      $v0, $v0, $v1
/* DB6FC 80144FFC 8C500000 */  lw        $s0, ($v0)
/* DB700 80145000 0C00AB0A */  jal       general_heap_malloc
/* DB704 80145004 240400F0 */   addiu    $a0, $zero, 0xf0
/* DB708 80145008 0040202D */  daddu     $a0, $v0, $zero
/* DB70C 8014500C 14800003 */  bnez      $a0, .L8014501C
/* DB710 80145010 AE04001C */   sw       $a0, 0x1c($s0)
.L80145014:
/* DB714 80145014 08051405 */  j         .L80145014
/* DB718 80145018 00000000 */   nop      
.L8014501C:
/* DB71C 8014501C 3C020003 */  lui       $v0, 3
/* DB720 80145020 8E030000 */  lw        $v1, ($s0)
/* DB724 80145024 3C013F80 */  lui       $at, 0x3f80
/* DB728 80145028 44810000 */  mtc1      $at, $f0
/* DB72C 8014502C 00621825 */  or        $v1, $v1, $v0
/* DB730 80145030 AE030000 */  sw        $v1, ($s0)
/* DB734 80145034 AC800000 */  sw        $zero, ($a0)
/* DB738 80145038 AC800004 */  sw        $zero, 4($a0)
/* DB73C 8014503C AC800008 */  sw        $zero, 8($a0)
/* DB740 80145040 AC80000C */  sw        $zero, 0xc($a0)
/* DB744 80145044 AC800010 */  sw        $zero, 0x10($a0)
/* DB748 80145048 AC800014 */  sw        $zero, 0x14($a0)
/* DB74C 8014504C AC800018 */  sw        $zero, 0x18($a0)
/* DB750 80145050 E480001C */  swc1      $f0, 0x1c($a0)
/* DB754 80145054 E4800020 */  swc1      $f0, 0x20($a0)
/* DB758 80145058 0C0504FE */  jal       func_801413F8
/* DB75C 8014505C E4800024 */   swc1     $f0, 0x24($a0)
/* DB760 80145060 8FBF0014 */  lw        $ra, 0x14($sp)
/* DB764 80145064 8FB00010 */  lw        $s0, 0x10($sp)
/* DB768 80145068 03E00008 */  jr        $ra
/* DB76C 8014506C 27BD0018 */   addiu    $sp, $sp, 0x18
