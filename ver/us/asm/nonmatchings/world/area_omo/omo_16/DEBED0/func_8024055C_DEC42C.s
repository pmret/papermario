.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024055C_DEC42C
/* DEC42C 8024055C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DEC430 80240560 AFB00010 */  sw        $s0, 0x10($sp)
/* DEC434 80240564 0080802D */  daddu     $s0, $a0, $zero
/* DEC438 80240568 3C05FD05 */  lui       $a1, 0xfd05
/* DEC43C 8024056C AFBF0014 */  sw        $ra, 0x14($sp)
/* DEC440 80240570 0C0B210B */  jal       evt_get_float_variable
/* DEC444 80240574 34A50F8B */   ori      $a1, $a1, 0xf8b
/* DEC448 80240578 46000106 */  mov.s     $f4, $f0
/* DEC44C 8024057C 3C0144FA */  lui       $at, 0x44fa
/* DEC450 80240580 44811000 */  mtc1      $at, $f2
/* DEC454 80240584 46002005 */  abs.s     $f0, $f4
/* DEC458 80240588 4602003C */  c.lt.s    $f0, $f2
/* DEC45C 8024058C 00000000 */  nop
/* DEC460 80240590 4500000D */  bc1f      .L802405C8
/* DEC464 80240594 AE000084 */   sw       $zero, 0x84($s0)
/* DEC468 80240598 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* DEC46C 8024059C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* DEC470 802405A0 8C420010 */  lw        $v0, 0x10($v0)
/* DEC474 802405A4 30428000 */  andi      $v0, $v0, 0x8000
/* DEC478 802405A8 10400007 */  beqz      $v0, .L802405C8
/* DEC47C 802405AC 24020001 */   addiu    $v0, $zero, 1
/* DEC480 802405B0 AE020084 */  sw        $v0, 0x84($s0)
/* DEC484 802405B4 3C0144FA */  lui       $at, 0x44fa
/* DEC488 802405B8 44811000 */  mtc1      $at, $f2
/* DEC48C 802405BC 46002005 */  abs.s     $f0, $f4
/* DEC490 802405C0 4602003C */  c.lt.s    $f0, $f2
/* DEC494 802405C4 00000000 */  nop
.L802405C8:
/* DEC498 802405C8 45000008 */  bc1f      .L802405EC
/* DEC49C 802405CC 00000000 */   nop
/* DEC4A0 802405D0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* DEC4A4 802405D4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* DEC4A8 802405D8 8C420010 */  lw        $v0, 0x10($v0)
/* DEC4AC 802405DC 30424000 */  andi      $v0, $v0, 0x4000
/* DEC4B0 802405E0 10400002 */  beqz      $v0, .L802405EC
/* DEC4B4 802405E4 24020001 */   addiu    $v0, $zero, 1
/* DEC4B8 802405E8 AE020084 */  sw        $v0, 0x84($s0)
.L802405EC:
/* DEC4BC 802405EC 8FBF0014 */  lw        $ra, 0x14($sp)
/* DEC4C0 802405F0 8FB00010 */  lw        $s0, 0x10($sp)
/* DEC4C4 802405F4 24020002 */  addiu     $v0, $zero, 2
/* DEC4C8 802405F8 03E00008 */  jr        $ra
/* DEC4CC 802405FC 27BD0018 */   addiu    $sp, $sp, 0x18
