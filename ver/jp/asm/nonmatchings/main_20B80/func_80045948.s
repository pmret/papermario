.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045948
/* 20D48 80045948 0000202D */  daddu     $a0, $zero, $zero
/* 20D4C 8004594C 24050001 */  addiu     $a1, $zero, 1
/* 20D50 80045950 3C03800A */  lui       $v1, %hi(D_8009E9D0)
/* 20D54 80045954 2463E9D0 */  addiu     $v1, $v1, %lo(D_8009E9D0)
.L80045958:
/* 20D58 80045958 84620010 */  lh        $v0, 0x10($v1)
/* 20D5C 8004595C 14400004 */  bnez      $v0, .L80045970
/* 20D60 80045960 24840001 */   addiu    $a0, $a0, 1
/* 20D64 80045964 A4650010 */  sh        $a1, 0x10($v1)
/* 20D68 80045968 03E00008 */  jr        $ra
/* 20D6C 8004596C 0060102D */   daddu    $v0, $v1, $zero
.L80045970:
/* 20D70 80045970 28820020 */  slti      $v0, $a0, 0x20
/* 20D74 80045974 1440FFF8 */  bnez      $v0, .L80045958
/* 20D78 80045978 2463001C */   addiu    $v1, $v1, 0x1c
/* 20D7C 8004597C 03E00008 */  jr        $ra
/* 20D80 80045980 0000102D */   daddu    $v0, $zero, $zero
