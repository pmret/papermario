.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD100_31B120
/* 31B120 802BD100 3C038011 */  lui       $v1, %hi(D_8010C978)
/* 31B124 802BD104 8C63C978 */  lw        $v1, %lo(D_8010C978)($v1)
/* 31B128 802BD108 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31B12C 802BD10C AFBF0010 */  sw        $ra, 0x10($sp)
/* 31B130 802BD110 04600009 */  bltz      $v1, .L802BD138
/* 31B134 802BD114 0000102D */   daddu    $v0, $zero, $zero
/* 31B138 802BD118 30624000 */  andi      $v0, $v1, 0x4000
/* 31B13C 802BD11C 10400005 */  beqz      $v0, .L802BD134
/* 31B140 802BD120 2404BFFF */   addiu    $a0, $zero, -0x4001
/* 31B144 802BD124 0C044277 */  jal       func_801109DC
/* 31B148 802BD128 00642024 */   and      $a0, $v1, $a0
/* 31B14C 802BD12C 080AF44E */  j         .L802BD138
/* 31B150 802BD130 00000000 */   nop      
.L802BD134:
/* 31B154 802BD134 0000102D */  daddu     $v0, $zero, $zero
.L802BD138:
/* 31B158 802BD138 8FBF0010 */  lw        $ra, 0x10($sp)
/* 31B15C 802BD13C 03E00008 */  jr        $ra
/* 31B160 802BD140 27BD0018 */   addiu    $sp, $sp, 0x18
