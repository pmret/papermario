.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80268798
/* 197078 80268798 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19707C 8026879C 3C01802A */  lui       $at, %hi(D_8029FBC0)
/* 197080 802687A0 AC27FBC0 */  sw        $a3, %lo(D_8029FBC0)($at)
/* 197084 802687A4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 197088 802687A8 0C09A0A1 */  jal       func_80268284
/* 19708C 802687AC 0000382D */   daddu    $a3, $zero, $zero
/* 197090 802687B0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 197094 802687B4 03E00008 */  jr        $ra
/* 197098 802687B8 27BD0018 */   addiu    $sp, $sp, 0x18
