.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240500_AF2160
/* AF2160 80240500 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AF2164 80240504 0000282D */  daddu     $a1, $zero, $zero
/* AF2168 80240508 00A0302D */  daddu     $a2, $a1, $zero
/* AF216C 8024050C 3C038024 */  lui       $v1, %hi(D_8024092C)
/* AF2170 80240510 2463092C */  addiu     $v1, $v1, %lo(D_8024092C)
/* AF2174 80240514 AFBF0010 */  sw        $ra, 0x10($sp)
/* AF2178 80240518 8C840084 */  lw        $a0, 0x84($a0)
.L8024051C:
/* AF217C 8024051C 8C620000 */  lw        $v0, ($v1)
/* AF2180 80240520 54820003 */  bnel      $a0, $v0, .L80240530
/* AF2184 80240524 24C60001 */   addiu    $a2, $a2, 1
/* AF2188 80240528 0809014F */  j         .L8024053C
/* AF218C 8024052C 24050001 */   addiu    $a1, $zero, 1
.L80240530:
/* AF2190 80240530 28C20005 */  slti      $v0, $a2, 5
/* AF2194 80240534 1440FFF9 */  bnez      $v0, .L8024051C
/* AF2198 80240538 24630004 */   addiu    $v1, $v1, 4
.L8024053C:
/* AF219C 8024053C 10A00006 */  beqz      $a1, .L80240558
/* AF21A0 80240540 3C05F840 */   lui      $a1, 0xf840
/* AF21A4 80240544 34A55D6E */  ori       $a1, $a1, 0x5d6e
/* AF21A8 80240548 0000202D */  daddu     $a0, $zero, $zero
/* AF21AC 8024054C 00C52821 */  addu      $a1, $a2, $a1
/* AF21B0 80240550 0C0B2026 */  jal       set_variable
/* AF21B4 80240554 24060001 */   addiu    $a2, $zero, 1
.L80240558:
/* AF21B8 80240558 8FBF0010 */  lw        $ra, 0x10($sp)
/* AF21BC 8024055C 24020002 */  addiu     $v0, $zero, 2
/* AF21C0 80240560 03E00008 */  jr        $ra
/* AF21C4 80240564 27BD0018 */   addiu    $sp, $sp, 0x18
