.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel update_npc_blur
/* 0161F8 8003ADF8 8C850020 */  lw    $a1, 0x20($a0)
/* 0161FC 8003ADFC 80A30001 */  lb    $v1, 1($a1)
/* 016200 8003AE00 C4800038 */  lwc1  $f0, 0x38($a0)
/* 016204 8003AE04 00031080 */  sll   $v0, $v1, 2
/* 016208 8003AE08 00A21021 */  addu  $v0, $a1, $v0
/* 01620C 8003AE0C E4400004 */  swc1  $f0, 4($v0)
/* 016210 8003AE10 C480003C */  lwc1  $f0, 0x3c($a0)
/* 016214 8003AE14 E4400054 */  swc1  $f0, 0x54($v0)
/* 016218 8003AE18 C4800040 */  lwc1  $f0, 0x40($a0)
/* 01621C 8003AE1C 24630001 */  addiu $v1, $v1, 1
/* 016220 8003AE20 E44000A4 */  swc1  $f0, 0xa4($v0)
/* 016224 8003AE24 28620014 */  slti  $v0, $v1, 0x14
/* 016228 8003AE28 50400001 */  beql  $v0, $zero, .L8003AE30
/* 01622C 8003AE2C 0000182D */   daddu $v1, $zero, $zero
.L8003AE30:
/* 016230 8003AE30 03E00008 */  jr    $ra
/* 016234 8003AE34 A0A30001 */   sb    $v1, 1($a1)

