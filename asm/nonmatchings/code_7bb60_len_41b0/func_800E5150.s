.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E5150
/* 7E600 800E5150 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7E604 800E5154 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7E608 800E5158 0C03945D */  jal       func_800E5174
/* 7E60C 800E515C 00000000 */   nop      
/* 7E610 800E5160 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7E614 800E5164 3C018016 */  lui       $at, 0x8016
/* 7E618 800E5168 A422A55A */  sh        $v0, -0x5aa6($at)
/* 7E61C 800E516C 03E00008 */  jr        $ra
/* 7E620 800E5170 27BD0018 */   addiu    $sp, $sp, 0x18
