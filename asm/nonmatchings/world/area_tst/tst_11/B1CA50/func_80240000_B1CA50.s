.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_B1CA50
/* B1CA50 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B1CA54 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* B1CA58 80240008 0080802D */  daddu     $s0, $a0, $zero
/* B1CA5C 8024000C 3C058024 */  lui       $a1, %hi(D_8024003C)
/* B1CA60 80240010 24A5003C */  addiu     $a1, $a1, %lo(D_8024003C)
/* B1CA64 80240014 AFBF0014 */  sw        $ra, 0x14($sp)
/* B1CA68 80240018 0C048C8F */  jal       bind_dynamic_entity_7
/* B1CA6C 8024001C 0000202D */   daddu    $a0, $zero, $zero
/* B1CA70 80240020 8E03013C */  lw        $v1, 0x13c($s0)
/* B1CA74 80240024 AC620000 */  sw        $v0, ($v1)
/* B1CA78 80240028 8FBF0014 */  lw        $ra, 0x14($sp)
/* B1CA7C 8024002C 8FB00010 */  lw        $s0, 0x10($sp)
/* B1CA80 80240030 24020002 */  addiu     $v0, $zero, 2
/* B1CA84 80240034 03E00008 */  jr        $ra
/* B1CA88 80240038 27BD0018 */   addiu    $sp, $sp, 0x18
