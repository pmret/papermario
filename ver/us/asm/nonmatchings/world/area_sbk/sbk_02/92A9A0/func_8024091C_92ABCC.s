.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024091C_92ABCC
/* 92ABCC 8024091C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 92ABD0 80240920 AFBF0010 */  sw        $ra, 0x10($sp)
/* 92ABD4 80240924 10A00003 */  beqz      $a1, .L80240934
/* 92ABD8 80240928 8C86000C */   lw       $a2, 0xc($a0)
/* 92ABDC 8024092C 3C018024 */  lui       $at, %hi(D_8024404C_92E2FC)
/* 92ABE0 80240930 AC20404C */  sw        $zero, %lo(D_8024404C_92E2FC)($at)
.L80240934:
/* 92ABE4 80240934 3C038024 */  lui       $v1, %hi(D_8024404C_92E2FC)
/* 92ABE8 80240938 2463404C */  addiu     $v1, $v1, %lo(D_8024404C_92E2FC)
/* 92ABEC 8024093C 8C620000 */  lw        $v0, ($v1)
/* 92ABF0 80240940 54400003 */  bnel      $v0, $zero, .L80240950
/* 92ABF4 80240944 AC600000 */   sw       $zero, ($v1)
/* 92ABF8 80240948 08090259 */  j         .L80240964
/* 92ABFC 8024094C 0000102D */   daddu    $v0, $zero, $zero
.L80240950:
/* 92AC00 80240950 8CC50000 */  lw        $a1, ($a2)
/* 92AC04 80240954 3C068024 */  lui       $a2, %hi(D_80244050_92E300)
/* 92AC08 80240958 0C0B2026 */  jal       evt_set_variable
/* 92AC0C 8024095C 8CC64050 */   lw       $a2, %lo(D_80244050_92E300)($a2)
/* 92AC10 80240960 24020002 */  addiu     $v0, $zero, 2
.L80240964:
/* 92AC14 80240964 8FBF0010 */  lw        $ra, 0x10($sp)
/* 92AC18 80240968 03E00008 */  jr        $ra
/* 92AC1C 8024096C 27BD0018 */   addiu    $sp, $sp, 0x18
