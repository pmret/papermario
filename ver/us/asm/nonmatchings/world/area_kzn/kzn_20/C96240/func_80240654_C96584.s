.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240654_C96584
/* C96584 80240654 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C96588 80240658 AFBF0010 */  sw        $ra, 0x10($sp)
/* C9658C 8024065C 10A00003 */  beqz      $a1, .L8024066C
/* C96590 80240660 8C86000C */   lw       $a2, 0xc($a0)
/* C96594 80240664 3C018024 */  lui       $at, %hi(D_802417E4_C97714)
/* C96598 80240668 AC2017E4 */  sw        $zero, %lo(D_802417E4_C97714)($at)
.L8024066C:
/* C9659C 8024066C 3C038024 */  lui       $v1, %hi(D_802417E4_C97714)
/* C965A0 80240670 246317E4 */  addiu     $v1, $v1, %lo(D_802417E4_C97714)
/* C965A4 80240674 8C620000 */  lw        $v0, ($v1)
/* C965A8 80240678 54400003 */  bnel      $v0, $zero, .L80240688
/* C965AC 8024067C AC600000 */   sw       $zero, ($v1)
/* C965B0 80240680 080901A7 */  j         .L8024069C
/* C965B4 80240684 0000102D */   daddu    $v0, $zero, $zero
.L80240688:
/* C965B8 80240688 8CC50000 */  lw        $a1, ($a2)
/* C965BC 8024068C 3C068024 */  lui       $a2, %hi(D_802417E8_C97718)
/* C965C0 80240690 0C0B2026 */  jal       set_variable
/* C965C4 80240694 8CC617E8 */   lw       $a2, %lo(D_802417E8_C97718)($a2)
/* C965C8 80240698 24020002 */  addiu     $v0, $zero, 2
.L8024069C:
/* C965CC 8024069C 8FBF0010 */  lw        $ra, 0x10($sp)
/* C965D0 802406A0 03E00008 */  jr        $ra
/* C965D4 802406A4 27BD0018 */   addiu    $sp, $sp, 0x18
