.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005F5AC
/* 3A9AC 8005F5AC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3A9B0 8005F5B0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3A9B4 8005F5B4 8C82000C */  lw        $v0, 0xc($a0)
/* 3A9B8 8005F5B8 0C01A510 */  jal       func_80069440
/* 3A9BC 8005F5BC 8C440000 */   lw       $a0, ($v0)
/* 3A9C0 8005F5C0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3A9C4 8005F5C4 03E00008 */  jr        $ra
/* 3A9C8 8005F5C8 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3A9CC 8005F5CC 00000000 */  nop
