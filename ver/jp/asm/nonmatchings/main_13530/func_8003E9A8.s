.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003E9A8
/* 19DA8 8003E9A8 3C03800B */  lui       $v1, %hi(D_800B0EF0)
/* 19DAC 8003E9AC 24630EF0 */  addiu     $v1, $v1, %lo(D_800B0EF0)
/* 19DB0 8003E9B0 8062001C */  lb        $v0, 0x1c($v1)
/* 19DB4 8003E9B4 18400018 */  blez      $v0, .L8003EA18
/* 19DB8 8003E9B8 0000382D */   daddu    $a3, $zero, $zero
/* 19DBC 8003E9BC 0040502D */  daddu     $t2, $v0, $zero
/* 19DC0 8003E9C0 0060482D */  daddu     $t1, $v1, $zero
.L8003E9C4:
/* 19DC4 8003E9C4 8D220028 */  lw        $v0, 0x28($t1)
/* 19DC8 8003E9C8 50400010 */  beql      $v0, $zero, .L8003EA0C
/* 19DCC 8003E9CC 24E70001 */   addiu    $a3, $a3, 1
/* 19DD0 8003E9D0 8C430000 */  lw        $v1, ($v0)
/* 19DD4 8003E9D4 1860000C */  blez      $v1, .L8003EA08
/* 19DD8 8003E9D8 0000302D */   daddu    $a2, $zero, $zero
/* 19DDC 8003E9DC 0060402D */  daddu     $t0, $v1, $zero
/* 19DE0 8003E9E0 0040282D */  daddu     $a1, $v0, $zero
.L8003E9E4:
/* 19DE4 8003E9E4 8CA30004 */  lw        $v1, 4($a1)
/* 19DE8 8003E9E8 10600004 */  beqz      $v1, .L8003E9FC
/* 19DEC 8003E9EC 24C60001 */   addiu    $a2, $a2, 1
/* 19DF0 8003E9F0 84620008 */  lh        $v0, 8($v1)
/* 19DF4 8003E9F4 1044000A */  beq       $v0, $a0, .L8003EA20
/* 19DF8 8003E9F8 00000000 */   nop
.L8003E9FC:
/* 19DFC 8003E9FC 00C8102A */  slt       $v0, $a2, $t0
/* 19E00 8003EA00 1440FFF8 */  bnez      $v0, .L8003E9E4
/* 19E04 8003EA04 24A50004 */   addiu    $a1, $a1, 4
.L8003EA08:
/* 19E08 8003EA08 24E70001 */  addiu     $a3, $a3, 1
.L8003EA0C:
/* 19E0C 8003EA0C 00EA102A */  slt       $v0, $a3, $t2
/* 19E10 8003EA10 1440FFEC */  bnez      $v0, .L8003E9C4
/* 19E14 8003EA14 25290004 */   addiu    $t1, $t1, 4
.L8003EA18:
/* 19E18 8003EA18 0800FA86 */  j         .L8003EA18
/* 19E1C 8003EA1C 00000000 */   nop
.L8003EA20:
/* 19E20 8003EA20 03E00008 */  jr        $ra
/* 19E24 8003EA24 0060102D */   daddu    $v0, $v1, $zero
