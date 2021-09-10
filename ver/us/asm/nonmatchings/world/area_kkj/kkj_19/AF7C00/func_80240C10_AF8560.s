.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C10_AF8560
/* AF8560 80240C10 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AF8564 80240C14 AFBF0010 */  sw        $ra, 0x10($sp)
/* AF8568 80240C18 8C82000C */  lw        $v0, 0xc($a0)
/* AF856C 80240C1C 0C0B1EAF */  jal       evt_get_variable
/* AF8570 80240C20 8C450000 */   lw       $a1, ($v0)
/* AF8574 80240C24 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* AF8578 80240C28 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* AF857C 80240C2C 0040182D */  daddu     $v1, $v0, $zero
/* AF8580 80240C30 3C018011 */  lui       $at, %hi(gPlayerStatus+0xC4)
/* AF8584 80240C34 A023F08C */  sb        $v1, %lo(gPlayerStatus+0xC4)($at)
/* AF8588 80240C38 A0830080 */  sb        $v1, 0x80($a0)
/* AF858C 80240C3C 8FBF0010 */  lw        $ra, 0x10($sp)
/* AF8590 80240C40 24020002 */  addiu     $v0, $zero, 2
/* AF8594 80240C44 03E00008 */  jr        $ra
/* AF8598 80240C48 27BD0018 */   addiu    $sp, $sp, 0x18
