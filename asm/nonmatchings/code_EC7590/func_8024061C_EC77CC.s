.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024061C_EC77CC
/* EC77CC 8024061C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EC77D0 80240620 AFB00010 */  sw        $s0, 0x10($sp)
/* EC77D4 80240624 3C108024 */  lui       $s0, %hi(D_80241BB0)
/* EC77D8 80240628 26101BB0 */  addiu     $s0, $s0, %lo(D_80241BB0)
/* EC77DC 8024062C AFBF0018 */  sw        $ra, 0x18($sp)
/* EC77E0 80240630 AFB10014 */  sw        $s1, 0x14($sp)
/* EC77E4 80240634 8E020000 */  lw        $v0, ($s0)
/* EC77E8 80240638 14400010 */  bnez      $v0, .L8024067C
/* EC77EC 8024063C 0080882D */   daddu    $s1, $a0, $zero
/* EC77F0 80240640 0C00AFF5 */  jal       func_8002BFD4
/* EC77F4 80240644 24040040 */   addiu    $a0, $zero, 0x40
/* EC77F8 80240648 AE020000 */  sw        $v0, ($s0)
/* EC77FC 8024064C 0000182D */  daddu     $v1, $zero, $zero
/* EC7800 80240650 0040282D */  daddu     $a1, $v0, $zero
/* EC7804 80240654 0220202D */  daddu     $a0, $s1, $zero
.L80240658:
/* EC7808 80240658 8C820084 */  lw        $v0, 0x84($a0)
/* EC780C 8024065C 24840004 */  addiu     $a0, $a0, 4
/* EC7810 80240660 24630001 */  addiu     $v1, $v1, 1
/* EC7814 80240664 ACA20000 */  sw        $v0, ($a1)
/* EC7818 80240668 28620010 */  slti      $v0, $v1, 0x10
/* EC781C 8024066C 1440FFFA */  bnez      $v0, .L80240658
/* EC7820 80240670 24A50004 */   addiu    $a1, $a1, 4
/* EC7824 80240674 080901AE */  j         .L802406B8
/* EC7828 80240678 00000000 */   nop      
.L8024067C:
/* EC782C 8024067C 0000182D */  daddu     $v1, $zero, $zero
/* EC7830 80240680 0040282D */  daddu     $a1, $v0, $zero
/* EC7834 80240684 0220202D */  daddu     $a0, $s1, $zero
.L80240688:
/* EC7838 80240688 8CA20000 */  lw        $v0, ($a1)
/* EC783C 8024068C 24A50004 */  addiu     $a1, $a1, 4
/* EC7840 80240690 24630001 */  addiu     $v1, $v1, 1
/* EC7844 80240694 AC820084 */  sw        $v0, 0x84($a0)
/* EC7848 80240698 28620010 */  slti      $v0, $v1, 0x10
/* EC784C 8024069C 1440FFFA */  bnez      $v0, .L80240688
/* EC7850 802406A0 24840004 */   addiu    $a0, $a0, 4
/* EC7854 802406A4 3C108024 */  lui       $s0, %hi(D_80241BB0)
/* EC7858 802406A8 26101BB0 */  addiu     $s0, $s0, %lo(D_80241BB0)
/* EC785C 802406AC 0C00B007 */  jal       func_8002C01C
/* EC7860 802406B0 8E040000 */   lw       $a0, ($s0)
/* EC7864 802406B4 AE000000 */  sw        $zero, ($s0)
.L802406B8:
/* EC7868 802406B8 8FBF0018 */  lw        $ra, 0x18($sp)
/* EC786C 802406BC 8FB10014 */  lw        $s1, 0x14($sp)
/* EC7870 802406C0 8FB00010 */  lw        $s0, 0x10($sp)
/* EC7874 802406C4 24020002 */  addiu     $v0, $zero, 2
/* EC7878 802406C8 03E00008 */  jr        $ra
/* EC787C 802406CC 27BD0020 */   addiu    $sp, $sp, 0x20
