.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240260_B1B7D0
/* B1B7D0 80240260 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B1B7D4 80240264 AFB00010 */  sw        $s0, 0x10($sp)
/* B1B7D8 80240268 0080802D */  daddu     $s0, $a0, $zero
/* B1B7DC 8024026C 3C058024 */  lui       $a1, %hi(func_8024029C_B1B80C)
/* B1B7E0 80240270 24A5029C */  addiu     $a1, $a1, %lo(func_8024029C_B1B80C)
/* B1B7E4 80240274 AFBF0014 */  sw        $ra, 0x14($sp)
/* B1B7E8 80240278 0C048C8F */  jal       bind_dynamic_entity_7
/* B1B7EC 8024027C 0000202D */   daddu    $a0, $zero, $zero
/* B1B7F0 80240280 8E03013C */  lw        $v1, 0x13c($s0)
/* B1B7F4 80240284 AC620000 */  sw        $v0, ($v1)
/* B1B7F8 80240288 8FBF0014 */  lw        $ra, 0x14($sp)
/* B1B7FC 8024028C 8FB00010 */  lw        $s0, 0x10($sp)
/* B1B800 80240290 24020002 */  addiu     $v0, $zero, 2
/* B1B804 80240294 03E00008 */  jr        $ra
/* B1B808 80240298 27BD0018 */   addiu    $sp, $sp, 0x18
