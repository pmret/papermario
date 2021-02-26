.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055CF4
/* 310F4 80055CF4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 310F8 80055CF8 30A200FF */  andi      $v0, $a1, 0xff
/* 310FC 80055CFC 3C055700 */  lui       $a1, 0x5700
/* 31100 80055D00 AFBF0010 */  sw        $ra, 0x10($sp)
/* 31104 80055D04 0C0140DE */  jal       func_80050378
/* 31108 80055D08 00452825 */   or       $a1, $v0, $a1
/* 3110C 80055D0C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 31110 80055D10 03E00008 */  jr        $ra
/* 31114 80055D14 27BD0018 */   addiu    $sp, $sp, 0x18
