.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413E0_91F950
/* 91F950 802413E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 91F954 802413E4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 91F958 802413E8 10A00003 */  beqz      $a1, .L802413F8
/* 91F95C 802413EC 8C86000C */   lw       $a2, 0xc($a0)
/* 91F960 802413F0 3C018024 */  lui       $at, %hi(D_8024626C_9247DC)
/* 91F964 802413F4 AC20626C */  sw        $zero, %lo(D_8024626C_9247DC)($at)
.L802413F8:
/* 91F968 802413F8 3C038024 */  lui       $v1, %hi(D_8024626C_9247DC)
/* 91F96C 802413FC 2463626C */  addiu     $v1, $v1, %lo(D_8024626C_9247DC)
/* 91F970 80241400 8C620000 */  lw        $v0, ($v1)
/* 91F974 80241404 54400003 */  bnel      $v0, $zero, .L80241414
/* 91F978 80241408 AC600000 */   sw       $zero, ($v1)
/* 91F97C 8024140C 0809050A */  j         .L80241428
/* 91F980 80241410 0000102D */   daddu    $v0, $zero, $zero
.L80241414:
/* 91F984 80241414 8CC50000 */  lw        $a1, ($a2)
/* 91F988 80241418 3C068024 */  lui       $a2, %hi(D_80246270_9247E0)
/* 91F98C 8024141C 0C0B2026 */  jal       set_variable
/* 91F990 80241420 8CC66270 */   lw       $a2, %lo(D_80246270_9247E0)($a2)
/* 91F994 80241424 24020002 */  addiu     $v0, $zero, 2
.L80241428:
/* 91F998 80241428 8FBF0010 */  lw        $ra, 0x10($sp)
/* 91F99C 8024142C 03E00008 */  jr        $ra
/* 91F9A0 80241430 27BD0018 */   addiu    $sp, $sp, 0x18
