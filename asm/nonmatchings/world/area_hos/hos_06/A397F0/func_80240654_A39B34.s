.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240654_A39B34
/* A39B34 80240654 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A39B38 80240658 AFBF0010 */  sw        $ra, 0x10($sp)
/* A39B3C 8024065C 10A00003 */  beqz      $a1, .L8024066C
/* A39B40 80240660 8C86000C */   lw       $a2, 0xc($a0)
/* A39B44 80240664 3C018024 */  lui       $at, %hi(D_80242C6C)
/* A39B48 80240668 AC202C6C */  sw        $zero, %lo(D_80242C6C)($at)
.L8024066C:
/* A39B4C 8024066C 3C038024 */  lui       $v1, %hi(D_80242C6C)
/* A39B50 80240670 24632C6C */  addiu     $v1, $v1, %lo(D_80242C6C)
/* A39B54 80240674 8C620000 */  lw        $v0, ($v1)
/* A39B58 80240678 54400003 */  bnel      $v0, $zero, .L80240688
/* A39B5C 8024067C AC600000 */   sw       $zero, ($v1)
/* A39B60 80240680 080901A7 */  j         .L8024069C
/* A39B64 80240684 0000102D */   daddu    $v0, $zero, $zero
.L80240688:
/* A39B68 80240688 8CC50000 */  lw        $a1, ($a2)
/* A39B6C 8024068C 3C068024 */  lui       $a2, %hi(D_80242C70)
/* A39B70 80240690 0C0B2026 */  jal       set_variable
/* A39B74 80240694 8CC62C70 */   lw       $a2, %lo(D_80242C70)($a2)
/* A39B78 80240698 24020002 */  addiu     $v0, $zero, 2
.L8024069C:
/* A39B7C 8024069C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A39B80 802406A0 03E00008 */  jr        $ra
/* A39B84 802406A4 27BD0018 */   addiu    $sp, $sp, 0x18
