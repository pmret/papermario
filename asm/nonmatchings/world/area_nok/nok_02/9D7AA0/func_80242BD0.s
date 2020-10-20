.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242BD0
/* 9D9BF0 80242BD0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9D9BF4 80242BD4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9D9BF8 80242BD8 10A00003 */  beqz      $a1, .L80242BE8
/* 9D9BFC 80242BDC 8C86000C */   lw       $a2, 0xc($a0)
/* 9D9C00 80242BE0 3C018025 */  lui       $at, 0x8025
/* 9D9C04 80242BE4 AC2096F0 */  sw        $zero, -0x6910($at)
.L80242BE8:
/* 9D9C08 80242BE8 3C038025 */  lui       $v1, 0x8025
/* 9D9C0C 80242BEC 246396F0 */  addiu     $v1, $v1, -0x6910
/* 9D9C10 80242BF0 8C620000 */  lw        $v0, ($v1)
/* 9D9C14 80242BF4 54400003 */  bnel      $v0, $zero, .L80242C04
/* 9D9C18 80242BF8 AC600000 */   sw       $zero, ($v1)
/* 9D9C1C 80242BFC 08090B06 */  j         .L80242C18
/* 9D9C20 80242C00 0000102D */   daddu    $v0, $zero, $zero
.L80242C04:
/* 9D9C24 80242C04 8CC50000 */  lw        $a1, ($a2)
/* 9D9C28 80242C08 3C068025 */  lui       $a2, 0x8025
/* 9D9C2C 80242C0C 0C0B2026 */  jal       set_variable
/* 9D9C30 80242C10 8CC696F4 */   lw       $a2, -0x690c($a2)
/* 9D9C34 80242C14 24020002 */  addiu     $v0, $zero, 2
.L80242C18:
/* 9D9C38 80242C18 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9D9C3C 80242C1C 03E00008 */  jr        $ra
/* 9D9C40 80242C20 27BD0018 */   addiu    $sp, $sp, 0x18
