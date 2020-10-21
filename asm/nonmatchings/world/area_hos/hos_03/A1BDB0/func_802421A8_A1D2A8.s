.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802421A8_A1D2A8
/* A1D2A8 802421A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A1D2AC 802421AC AFBF0010 */  sw        $ra, 0x10($sp)
/* A1D2B0 802421B0 0C03A625 */  jal       func_800E9894
/* A1D2B4 802421B4 00000000 */   nop      
/* A1D2B8 802421B8 8FBF0010 */  lw        $ra, 0x10($sp)
/* A1D2BC 802421BC 24020002 */  addiu     $v0, $zero, 2
/* A1D2C0 802421C0 03E00008 */  jr        $ra
/* A1D2C4 802421C4 27BD0018 */   addiu    $sp, $sp, 0x18
