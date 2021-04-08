.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80060890
/* 3BC90 80060890 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3BC94 80060894 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3BC98 80060898 0C018244 */  jal       func_80060910
/* 3BC9C 8006089C 24040001 */   addiu    $a0, $zero, 1
/* 3BCA0 800608A0 24030001 */  addiu     $v1, $zero, 1
/* 3BCA4 800608A4 3C01800A */  lui       $at, %hi(D_8009A5C0)
/* 3BCA8 800608A8 AC23A5C0 */  sw        $v1, %lo(D_8009A5C0)($at)
/* 3BCAC 800608AC 0C018244 */  jal       func_80060910
/* 3BCB0 800608B0 0040202D */   daddu    $a0, $v0, $zero
/* 3BCB4 800608B4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3BCB8 800608B8 03E00008 */  jr        $ra
/* 3BCBC 800608BC 27BD0018 */   addiu    $sp, $sp, 0x18
