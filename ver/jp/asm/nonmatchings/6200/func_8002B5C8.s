.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002B5C8
/* 69C8 8002B5C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 69CC 8002B5CC 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 69D0 8002B5D0 8C63417C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 69D4 8002B5D4 2402000A */  addiu     $v0, $zero, 0xa
/* 69D8 8002B5D8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 69DC 8002B5DC 0C00AD7C */  jal       func_8002B5F0
/* 69E0 8002B5E0 A462008E */   sh       $v0, 0x8e($v1)
/* 69E4 8002B5E4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 69E8 8002B5E8 03E00008 */  jr        $ra
/* 69EC 8002B5EC 27BD0018 */   addiu    $sp, $sp, 0x18
