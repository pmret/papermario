.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056228
/* 31628 80056228 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3162C 8005622C 3C04800A */  lui       $a0, 0x800a
/* 31630 80056230 8C84A640 */  lw        $a0, -0x59c0($a0)
/* 31634 80056234 AFBF0010 */  sw        $ra, 0x10($sp)
/* 31638 80056238 0C012E95 */  jal       func_8004BA54
/* 3163C 8005623C 24050001 */   addiu    $a1, $zero, 1
/* 31640 80056240 8FBF0010 */  lw        $ra, 0x10($sp)
/* 31644 80056244 03E00008 */  jr        $ra
/* 31648 80056248 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3164C 8005624C 00000000 */  nop       
