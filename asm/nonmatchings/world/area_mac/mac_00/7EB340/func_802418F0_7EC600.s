.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418F0_7EC600
/* 7EC600 802418F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7EC604 802418F4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7EC608 802418F8 10A00003 */  beqz      $a1, .L80241908
/* 7EC60C 802418FC 8C86000C */   lw       $a2, 0xc($a0)
/* 7EC610 80241900 3C018025 */  lui       $at, %hi(D_802483E8)
/* 7EC614 80241904 AC2083E8 */  sw        $zero, %lo(D_802483E8)($at)
.L80241908:
/* 7EC618 80241908 3C038025 */  lui       $v1, %hi(D_802483E8)
/* 7EC61C 8024190C 246383E8 */  addiu     $v1, $v1, %lo(D_802483E8)
/* 7EC620 80241910 8C620000 */  lw        $v0, ($v1)
/* 7EC624 80241914 54400003 */  bnel      $v0, $zero, .L80241924
/* 7EC628 80241918 AC600000 */   sw       $zero, ($v1)
/* 7EC62C 8024191C 0809064E */  j         .L80241938
/* 7EC630 80241920 0000102D */   daddu    $v0, $zero, $zero
.L80241924:
/* 7EC634 80241924 8CC50000 */  lw        $a1, ($a2)
/* 7EC638 80241928 3C068025 */  lui       $a2, %hi(D_802483EC)
/* 7EC63C 8024192C 0C0B2026 */  jal       set_variable
/* 7EC640 80241930 8CC683EC */   lw       $a2, %lo(D_802483EC)($a2)
/* 7EC644 80241934 24020002 */  addiu     $v0, $zero, 2
.L80241938:
/* 7EC648 80241938 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7EC64C 8024193C 03E00008 */  jr        $ra
/* 7EC650 80241940 27BD0018 */   addiu    $sp, $sp, 0x18
