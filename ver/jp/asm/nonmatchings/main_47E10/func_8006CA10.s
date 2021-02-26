.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006CA10
/* 47E10 8006CA10 40085000 */  mfc0      $t0, $10
/* 47E14 8006CA14 2409001F */  addiu     $t1, $zero, 0x1f
/* 47E18 8006CA18 40890000 */  mtc0      $t1, $0
/* 47E1C 8006CA1C 40802800 */  mtc0      $zero, $5
/* 47E20 8006CA20 240A0017 */  addiu     $t2, $zero, 0x17
/* 47E24 8006CA24 3C09C000 */  lui       $t1, 0xc000
/* 47E28 8006CA28 40895000 */  mtc0      $t1, $10
/* 47E2C 8006CA2C 3C098000 */  lui       $t1, 0x8000
/* 47E30 8006CA30 00095982 */  srl       $t3, $t1, 6
/* 47E34 8006CA34 016A5825 */  or        $t3, $t3, $t2
/* 47E38 8006CA38 408B1000 */  mtc0      $t3, $2
/* 47E3C 8006CA3C 24090001 */  addiu     $t1, $zero, 1
/* 47E40 8006CA40 40891800 */  mtc0      $t1, $3
/* 47E44 8006CA44 00000000 */  nop
/* 47E48 8006CA48 42000002 */  tlbwi
/* 47E4C 8006CA4C 00000000 */  nop
/* 47E50 8006CA50 00000000 */  nop
/* 47E54 8006CA54 00000000 */  nop
/* 47E58 8006CA58 00000000 */  nop
/* 47E5C 8006CA5C 40885000 */  mtc0      $t0, $10
/* 47E60 8006CA60 03E00008 */  jr        $ra
/* 47E64 8006CA64 00000000 */   nop
/* 47E68 8006CA68 00000000 */  nop
/* 47E6C 8006CA6C 00000000 */  nop
