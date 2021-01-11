.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuContDataUnLock
/* 3BCF0 800608F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3BCF4 800608F4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3BCF8 800608F8 0C018250 */  jal       osSetIntMask
/* 3BCFC 800608FC 24040001 */   addiu    $a0, $zero, 1
/* 3BD00 80060900 3C01800A */  lui       $at, %hi(D_8009A5E0)
/* 3BD04 80060904 AC20A5E0 */  sw        $zero, %lo(D_8009A5E0)($at)
/* 3BD08 80060908 0C018250 */  jal       osSetIntMask
/* 3BD0C 8006090C 0040202D */   daddu    $a0, $v0, $zero
/* 3BD10 80060910 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3BD14 80060914 03E00008 */  jr        $ra
/* 3BD18 80060918 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3BD1C 8006091C 00000000 */  nop
