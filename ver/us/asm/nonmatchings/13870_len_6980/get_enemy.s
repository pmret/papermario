.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_enemy
/* 1A0E8 8003ECE8 3C03800B */  lui       $v1, %hi(gCurrentEncounter)
/* 1A0EC 8003ECEC 24630F10 */  addiu     $v1, $v1, %lo(gCurrentEncounter)
/* 1A0F0 8003ECF0 8062001C */  lb        $v0, 0x1c($v1)
/* 1A0F4 8003ECF4 18400018 */  blez      $v0, .L8003ED58
/* 1A0F8 8003ECF8 0000382D */   daddu    $a3, $zero, $zero
/* 1A0FC 8003ECFC 0040502D */  daddu     $t2, $v0, $zero
/* 1A100 8003ED00 0060482D */  daddu     $t1, $v1, $zero
.L8003ED04:
/* 1A104 8003ED04 8D220028 */  lw        $v0, 0x28($t1)
/* 1A108 8003ED08 50400010 */  beql      $v0, $zero, .L8003ED4C
/* 1A10C 8003ED0C 24E70001 */   addiu    $a3, $a3, 1
/* 1A110 8003ED10 8C430000 */  lw        $v1, ($v0)
/* 1A114 8003ED14 1860000C */  blez      $v1, .L8003ED48
/* 1A118 8003ED18 0000302D */   daddu    $a2, $zero, $zero
/* 1A11C 8003ED1C 0060402D */  daddu     $t0, $v1, $zero
/* 1A120 8003ED20 0040282D */  daddu     $a1, $v0, $zero
.L8003ED24:
/* 1A124 8003ED24 8CA30004 */  lw        $v1, 4($a1)
/* 1A128 8003ED28 10600004 */  beqz      $v1, .L8003ED3C
/* 1A12C 8003ED2C 24C60001 */   addiu    $a2, $a2, 1
/* 1A130 8003ED30 84620008 */  lh        $v0, 8($v1)
/* 1A134 8003ED34 1044000A */  beq       $v0, $a0, .L8003ED60
/* 1A138 8003ED38 00000000 */   nop
.L8003ED3C:
/* 1A13C 8003ED3C 00C8102A */  slt       $v0, $a2, $t0
/* 1A140 8003ED40 1440FFF8 */  bnez      $v0, .L8003ED24
/* 1A144 8003ED44 24A50004 */   addiu    $a1, $a1, 4
.L8003ED48:
/* 1A148 8003ED48 24E70001 */  addiu     $a3, $a3, 1
.L8003ED4C:
/* 1A14C 8003ED4C 00EA102A */  slt       $v0, $a3, $t2
/* 1A150 8003ED50 1440FFEC */  bnez      $v0, .L8003ED04
/* 1A154 8003ED54 25290004 */   addiu    $t1, $t1, 4
.L8003ED58:
/* 1A158 8003ED58 0800FB56 */  j         .L8003ED58
/* 1A15C 8003ED5C 00000000 */   nop
.L8003ED60:
/* 1A160 8003ED60 03E00008 */  jr        $ra
/* 1A164 8003ED64 0060102D */   daddu    $v0, $v1, $zero
