.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80280AC4
/* 7E1944 80280AC4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 7E1948 80280AC8 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 7E194C 80280ACC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7E1950 80280AD0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 7E1954 80280AD4 AFB20018 */  sw        $s2, 0x18($sp)
/* 7E1958 80280AD8 AFB10014 */  sw        $s1, 0x14($sp)
/* 7E195C 80280ADC AFB00010 */  sw        $s0, 0x10($sp)
/* 7E1960 80280AE0 8C420144 */  lw        $v0, 0x144($v0)
/* 7E1964 80280AE4 0080902D */  daddu     $s2, $a0, $zero
/* 7E1968 80280AE8 84500354 */  lh        $s0, 0x354($v0)
/* 7E196C 80280AEC 16000003 */  bnez      $s0, .L80280AFC
/* 7E1970 80280AF0 24510028 */   addiu    $s1, $v0, 0x28
/* 7E1974 80280AF4 080A02CB */  j         .L80280B2C
/* 7E1978 80280AF8 0000102D */   daddu    $v0, $zero, $zero
.L80280AFC:
/* 7E197C 80280AFC 0C03C4EC */  jal       func_800F13B0
/* 7E1980 80280B00 00000000 */   nop      
/* 7E1984 80280B04 240200FF */  addiu     $v0, $zero, 0xff
/* 7E1988 80280B08 16020003 */  bne       $s0, $v0, .L80280B18
/* 7E198C 80280B0C 2602FFFF */   addiu    $v0, $s0, -1
/* 7E1990 80280B10 080A02C9 */  j         .L80280B24
/* 7E1994 80280B14 2402FFFF */   addiu    $v0, $zero, -1
.L80280B18:
/* 7E1998 80280B18 00021080 */  sll       $v0, $v0, 2
/* 7E199C 80280B1C 02221021 */  addu      $v0, $s1, $v0
/* 7E19A0 80280B20 8C420108 */  lw        $v0, 0x108($v0)
.L80280B24:
/* 7E19A4 80280B24 AE420000 */  sw        $v0, ($s2)
/* 7E19A8 80280B28 24020001 */  addiu     $v0, $zero, 1
.L80280B2C:
/* 7E19AC 80280B2C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 7E19B0 80280B30 8FB20018 */  lw        $s2, 0x18($sp)
/* 7E19B4 80280B34 8FB10014 */  lw        $s1, 0x14($sp)
/* 7E19B8 80280B38 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E19BC 80280B3C 03E00008 */  jr        $ra
/* 7E19C0 80280B40 27BD0020 */   addiu    $sp, $sp, 0x20
