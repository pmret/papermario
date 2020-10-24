.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243548_96C708
/* 96C708 80243548 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 96C70C 8024354C AFB10014 */  sw        $s1, 0x14($sp)
/* 96C710 80243550 0080882D */  daddu     $s1, $a0, $zero
/* 96C714 80243554 AFBF0018 */  sw        $ra, 0x18($sp)
/* 96C718 80243558 AFB00010 */  sw        $s0, 0x10($sp)
/* 96C71C 8024355C 8E30000C */  lw        $s0, 0xc($s1)
/* 96C720 80243560 8E050000 */  lw        $a1, ($s0)
/* 96C724 80243564 0C0B1EAF */  jal       get_variable
/* 96C728 80243568 26100004 */   addiu    $s0, $s0, 4
/* 96C72C 8024356C 0220202D */  daddu     $a0, $s1, $zero
/* 96C730 80243570 8E050000 */  lw        $a1, ($s0)
/* 96C734 80243574 0C0B1EAF */  jal       get_variable
/* 96C738 80243578 0040802D */   daddu    $s0, $v0, $zero
/* 96C73C 8024357C 44820000 */  mtc1      $v0, $f0
/* 96C740 80243580 00000000 */  nop       
/* 96C744 80243584 46800020 */  cvt.s.w   $f0, $f0
/* 96C748 80243588 24020002 */  addiu     $v0, $zero, 2
/* 96C74C 8024358C 00501804 */  sllv      $v1, $s0, $v0
/* 96C750 80243590 00701821 */  addu      $v1, $v1, $s0
/* 96C754 80243594 00431804 */  sllv      $v1, $v1, $v0
/* 96C758 80243598 00701823 */  subu      $v1, $v1, $s0
/* 96C75C 8024359C 000320C0 */  sll       $a0, $v1, 3
/* 96C760 802435A0 00641821 */  addu      $v1, $v1, $a0
/* 96C764 802435A4 000318C0 */  sll       $v1, $v1, 3
/* 96C768 802435A8 3C01800B */  lui       $at, 0x800b
/* 96C76C 802435AC 00230821 */  addu      $at, $at, $v1
/* 96C770 802435B0 E4201D98 */  swc1      $f0, 0x1d98($at)
/* 96C774 802435B4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 96C778 802435B8 8FB10014 */  lw        $s1, 0x14($sp)
/* 96C77C 802435BC 8FB00010 */  lw        $s0, 0x10($sp)
/* 96C780 802435C0 03E00008 */  jr        $ra
/* 96C784 802435C4 27BD0020 */   addiu    $sp, $sp, 0x20
