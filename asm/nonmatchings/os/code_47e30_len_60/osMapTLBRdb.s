.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osMapTLBRdb
/* 47E30 8006CA30 40085000 */  mfc0      $t0, $10
/* 47E34 8006CA34 2409001F */  addiu     $t1, $zero, 0x1f
/* 47E38 8006CA38 40890000 */  mtc0      $t1, $0
/* 47E3C 8006CA3C 40802800 */  mtc0      $zero, $5
/* 47E40 8006CA40 240A0017 */  addiu     $t2, $zero, 0x17
/* 47E44 8006CA44 3C09C000 */  lui       $t1, 0xc000
/* 47E48 8006CA48 40895000 */  mtc0      $t1, $10
/* 47E4C 8006CA4C 3C098000 */  lui       $t1, 0x8000
/* 47E50 8006CA50 00095982 */  srl       $t3, $t1, 6
/* 47E54 8006CA54 016A5825 */  or        $t3, $t3, $t2
/* 47E58 8006CA58 408B1000 */  mtc0      $t3, $2
/* 47E5C 8006CA5C 24090001 */  addiu     $t1, $zero, 1
/* 47E60 8006CA60 40891800 */  mtc0      $t1, $3
/* 47E64 8006CA64 00000000 */  nop
/* 47E68 8006CA68 42000002 */  tlbwi
/* 47E6C 8006CA6C 00000000 */  nop
/* 47E70 8006CA70 00000000 */  nop
/* 47E74 8006CA74 00000000 */  nop
/* 47E78 8006CA78 00000000 */  nop
/* 47E7C 8006CA7C 40885000 */  mtc0      $t0, $10
/* 47E80 8006CA80 03E00008 */  jr        $ra
/* 47E84 8006CA84 00000000 */   nop
/* 47E88 8006CA88 00000000 */  nop
/* 47E8C 8006CA8C 00000000 */  nop
