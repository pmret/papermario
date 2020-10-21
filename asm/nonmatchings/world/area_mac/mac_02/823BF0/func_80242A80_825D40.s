.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A80_825D40
/* 825D40 80242A80 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 825D44 80242A84 AFBF0010 */  sw        $ra, 0x10($sp)
/* 825D48 80242A88 10A00003 */  beqz      $a1, .L80242A98
/* 825D4C 80242A8C 8C86000C */   lw       $a2, 0xc($a0)
/* 825D50 80242A90 3C018025 */  lui       $at, 0x8025
/* 825D54 80242A94 AC208778 */  sw        $zero, -0x7888($at)
.L80242A98:
/* 825D58 80242A98 3C038025 */  lui       $v1, 0x8025
/* 825D5C 80242A9C 24638778 */  addiu     $v1, $v1, -0x7888
/* 825D60 80242AA0 8C620000 */  lw        $v0, ($v1)
/* 825D64 80242AA4 54400003 */  bnel      $v0, $zero, .L80242AB4
/* 825D68 80242AA8 AC600000 */   sw       $zero, ($v1)
/* 825D6C 80242AAC 08090AB2 */  j         .L80242AC8
/* 825D70 80242AB0 0000102D */   daddu    $v0, $zero, $zero
.L80242AB4:
/* 825D74 80242AB4 8CC50000 */  lw        $a1, ($a2)
/* 825D78 80242AB8 3C068025 */  lui       $a2, 0x8025
/* 825D7C 80242ABC 0C0B2026 */  jal       set_variable
/* 825D80 80242AC0 8CC6877C */   lw       $a2, -0x7884($a2)
/* 825D84 80242AC4 24020002 */  addiu     $v0, $zero, 2
.L80242AC8:
/* 825D88 80242AC8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 825D8C 80242ACC 03E00008 */  jr        $ra
/* 825D90 80242AD0 27BD0018 */   addiu    $sp, $sp, 0x18
