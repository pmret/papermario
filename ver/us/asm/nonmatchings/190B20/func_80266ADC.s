.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80266ADC
/* 1953BC 80266ADC 2402FFFF */  addiu     $v0, $zero, -1
/* 1953C0 80266AE0 A0820206 */  sb        $v0, 0x206($a0)
/* 1953C4 80266AE4 8C820000 */  lw        $v0, ($a0)
/* 1953C8 80266AE8 3C030008 */  lui       $v1, 8
/* 1953CC 80266AEC 00431025 */  or        $v0, $v0, $v1
/* 1953D0 80266AF0 03E00008 */  jr        $ra
/* 1953D4 80266AF4 AC820000 */   sw       $v0, ($a0)
