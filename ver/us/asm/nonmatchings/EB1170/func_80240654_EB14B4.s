.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240654_EB14B4
/* EB14B4 80240654 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EB14B8 80240658 AFBF0010 */  sw        $ra, 0x10($sp)
/* EB14BC 8024065C 10A00003 */  beqz      $a1, .L8024066C
/* EB14C0 80240660 8C86000C */   lw       $a2, 0xc($a0)
/* EB14C4 80240664 3C018024 */  lui       $at, %hi(D_802417E4_EB2644)
/* EB14C8 80240668 AC2017E4 */  sw        $zero, %lo(D_802417E4_EB2644)($at)
.L8024066C:
/* EB14CC 8024066C 3C038024 */  lui       $v1, %hi(D_802417E4_EB2644)
/* EB14D0 80240670 246317E4 */  addiu     $v1, $v1, %lo(D_802417E4_EB2644)
/* EB14D4 80240674 8C620000 */  lw        $v0, ($v1)
/* EB14D8 80240678 54400003 */  bnel      $v0, $zero, .L80240688
/* EB14DC 8024067C AC600000 */   sw       $zero, ($v1)
/* EB14E0 80240680 080901A7 */  j         .L8024069C
/* EB14E4 80240684 0000102D */   daddu    $v0, $zero, $zero
.L80240688:
/* EB14E8 80240688 8CC50000 */  lw        $a1, ($a2)
/* EB14EC 8024068C 3C068024 */  lui       $a2, %hi(D_802417E8_EB2648)
/* EB14F0 80240690 0C0B551A */  jal       dead_evt_set_variable
/* EB14F4 80240694 8CC617E8 */   lw       $a2, %lo(D_802417E8_EB2648)($a2)
/* EB14F8 80240698 24020002 */  addiu     $v0, $zero, 2
.L8024069C:
/* EB14FC 8024069C 8FBF0010 */  lw        $ra, 0x10($sp)
/* EB1500 802406A0 03E00008 */  jr        $ra
/* EB1504 802406A4 27BD0018 */   addiu    $sp, $sp, 0x18
