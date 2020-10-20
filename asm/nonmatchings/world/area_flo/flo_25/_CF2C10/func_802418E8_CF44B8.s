.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418E8_CF44B8
/* CF44B8 802418E8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CF44BC 802418EC AFB10014 */  sw        $s1, 0x14($sp)
/* CF44C0 802418F0 0080882D */  daddu     $s1, $a0, $zero
/* CF44C4 802418F4 AFBF0018 */  sw        $ra, 0x18($sp)
/* CF44C8 802418F8 AFB00010 */  sw        $s0, 0x10($sp)
/* CF44CC 802418FC 8E300148 */  lw        $s0, 0x148($s1)
/* CF44D0 80241900 0C00EABB */  jal       get_npc_unsafe
/* CF44D4 80241904 86040008 */   lh       $a0, 8($s0)
/* CF44D8 80241908 0040182D */  daddu     $v1, $v0, $zero
/* CF44DC 8024190C 9462008E */  lhu       $v0, 0x8e($v1)
/* CF44E0 80241910 2442FFFF */  addiu     $v0, $v0, -1
/* CF44E4 80241914 A462008E */  sh        $v0, 0x8e($v1)
/* CF44E8 80241918 00021400 */  sll       $v0, $v0, 0x10
/* CF44EC 8024191C 1C400004 */  bgtz      $v0, .L80241930
/* CF44F0 80241920 00000000 */   nop      
/* CF44F4 80241924 AE000074 */  sw        $zero, 0x74($s0)
/* CF44F8 80241928 A460008E */  sh        $zero, 0x8e($v1)
/* CF44FC 8024192C AE200070 */  sw        $zero, 0x70($s1)
.L80241930:
/* CF4500 80241930 8FBF0018 */  lw        $ra, 0x18($sp)
/* CF4504 80241934 8FB10014 */  lw        $s1, 0x14($sp)
/* CF4508 80241938 8FB00010 */  lw        $s0, 0x10($sp)
/* CF450C 8024193C 03E00008 */  jr        $ra
/* CF4510 80241940 27BD0020 */   addiu    $sp, $sp, 0x20
