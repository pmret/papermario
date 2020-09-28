.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002B608
/* 6A08 8002B608 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6A0C 8002B60C 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 6A10 8002B610 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 6A14 8002B614 2402000A */  addiu     $v0, $zero, 0xa
/* 6A18 8002B618 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6A1C 8002B61C 0C00AD8C */  jal       fio_serialize_state
/* 6A20 8002B620 A462008E */   sh       $v0, 0x8e($v1)
/* 6A24 8002B624 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6A28 8002B628 03E00008 */  jr        $ra
/* 6A2C 8002B62C 27BD0018 */   addiu    $sp, $sp, 0x18
