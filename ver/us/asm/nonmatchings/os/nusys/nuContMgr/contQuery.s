.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel contQuery
/* 3BC70 80060870 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3BC74 80060874 AFB00010 */  sw        $s0, 0x10($sp)
/* 3BC78 80060878 3C10800E */  lui       $s0, %hi(nuSiMesgQ)
/* 3BC7C 8006087C 2610AC78 */  addiu     $s0, $s0, %lo(nuSiMesgQ)
/* 3BC80 80060880 AFBF0014 */  sw        $ra, 0x14($sp)
/* 3BC84 80060884 0C018640 */  jal       osContStartQuery
/* 3BC88 80060888 0200202D */   daddu    $a0, $s0, $zero
/* 3BC8C 8006088C 14400008 */  bnez      $v0, .L800608B0
/* 3BC90 80060890 0200202D */   daddu    $a0, $s0, $zero
/* 3BC94 80060894 0000282D */  daddu     $a1, $zero, $zero
/* 3BC98 80060898 0C0195BC */  jal       osRecvMesg
/* 3BC9C 8006089C 24060001 */   addiu    $a2, $zero, 1
/* 3BCA0 800608A0 3C04800B */  lui       $a0, %hi(nuContStatus)
/* 3BCA4 800608A4 0C018660 */  jal       osContGetQuery
/* 3BCA8 800608A8 24841B7C */   addiu    $a0, $a0, %lo(nuContStatus)
/* 3BCAC 800608AC 0000102D */  daddu     $v0, $zero, $zero
.L800608B0:
/* 3BCB0 800608B0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3BCB4 800608B4 8FB00010 */  lw        $s0, 0x10($sp)
/* 3BCB8 800608B8 03E00008 */  jr        $ra
/* 3BCBC 800608BC 27BD0018 */   addiu    $sp, $sp, 0x18
