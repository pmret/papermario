.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802428E0_C88390
/* C88390 802428E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C88394 802428E4 AFBF0010 */  sw        $ra, 0x10($sp)
/* C88398 802428E8 10A00003 */  beqz      $a1, .L802428F8
/* C8839C 802428EC 8C86000C */   lw       $a2, 0xc($a0)
/* C883A0 802428F0 3C018024 */  lui       $at, 0x8024
/* C883A4 802428F4 AC2040D8 */  sw        $zero, 0x40d8($at)
.L802428F8:
/* C883A8 802428F8 3C038024 */  lui       $v1, 0x8024
/* C883AC 802428FC 246340D8 */  addiu     $v1, $v1, 0x40d8
/* C883B0 80242900 8C620000 */  lw        $v0, ($v1)
/* C883B4 80242904 54400003 */  bnel      $v0, $zero, .L80242914
/* C883B8 80242908 AC600000 */   sw       $zero, ($v1)
/* C883BC 8024290C 08090A4A */  j         .L80242928
/* C883C0 80242910 0000102D */   daddu    $v0, $zero, $zero
.L80242914:
/* C883C4 80242914 8CC50000 */  lw        $a1, ($a2)
/* C883C8 80242918 3C068024 */  lui       $a2, 0x8024
/* C883CC 8024291C 0C0B2026 */  jal       set_variable
/* C883D0 80242920 8CC640DC */   lw       $a2, 0x40dc($a2)
/* C883D4 80242924 24020002 */  addiu     $v0, $zero, 2
.L80242928:
/* C883D8 80242928 8FBF0010 */  lw        $ra, 0x10($sp)
/* C883DC 8024292C 03E00008 */  jr        $ra
/* C883E0 80242930 27BD0018 */   addiu    $sp, $sp, 0x18
