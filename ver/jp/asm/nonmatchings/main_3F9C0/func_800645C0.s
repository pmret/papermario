.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800645C0
/* 3F9C0 800645C0 3084FFFF */  andi      $a0, $a0, 0xffff
/* 3F9C4 800645C4 00042102 */  srl       $a0, $a0, 4
/* 3F9C8 800645C8 30820400 */  andi      $v0, $a0, 0x400
/* 3F9CC 800645CC 10400004 */  beqz      $v0, .L800645E0
/* 3F9D0 800645D0 00802821 */   addu     $a1, $a0, $zero
/* 3F9D4 800645D4 00041027 */  nor       $v0, $zero, $a0
/* 3F9D8 800645D8 08019179 */  j         .L800645E4
/* 3F9DC 800645DC 304203FF */   andi     $v0, $v0, 0x3ff
.L800645E0:
/* 3F9E0 800645E0 308203FF */  andi      $v0, $a0, 0x3ff
.L800645E4:
/* 3F9E4 800645E4 00021040 */  sll       $v0, $v0, 1
/* 3F9E8 800645E8 3C038009 */  lui       $v1, %hi(D_80093DC0)
/* 3F9EC 800645EC 00621821 */  addu      $v1, $v1, $v0
/* 3F9F0 800645F0 94633DC0 */  lhu       $v1, %lo(D_80093DC0)($v1)
/* 3F9F4 800645F4 30A20800 */  andi      $v0, $a1, 0x800
/* 3F9F8 800645F8 14400003 */  bnez      $v0, .L80064608
/* 3F9FC 800645FC 00031023 */   negu     $v0, $v1
/* 3FA00 80064600 08019183 */  j         .L8006460C
/* 3FA04 80064604 00031400 */   sll      $v0, $v1, 0x10
.L80064608:
/* 3FA08 80064608 00021400 */  sll       $v0, $v0, 0x10
.L8006460C:
/* 3FA0C 8006460C 03E00008 */  jr        $ra
/* 3FA10 80064610 00021403 */   sra      $v0, $v0, 0x10
/* 3FA14 80064614 00000000 */  nop
/* 3FA18 80064618 00000000 */  nop
/* 3FA1C 8006461C 00000000 */  nop
