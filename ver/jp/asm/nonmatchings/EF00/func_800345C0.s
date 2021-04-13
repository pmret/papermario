.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800345C0
/* F9C0 800345C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F9C4 800345C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* F9C8 800345C8 3C01800A */  lui       $at, %hi(D_8009E731)
/* F9CC 800345CC A020E731 */  sb        $zero, %lo(D_8009E731)($at)
/* F9D0 800345D0 3C01800A */  lui       $at, %hi(D_8009E732)
/* F9D4 800345D4 A420E732 */  sh        $zero, %lo(D_8009E732)($at)
/* F9D8 800345D8 0C038056 */  jal       func_800E0158
/* F9DC 800345DC 00000000 */   nop
/* F9E0 800345E0 0C009C15 */  jal       func_80027054
/* F9E4 800345E4 24040003 */   addiu    $a0, $zero, 3
/* F9E8 800345E8 0C0533DD */  jal       func_8014CF74
/* F9EC 800345EC 24040002 */   addiu    $a0, $zero, 2
/* F9F0 800345F0 8FBF0010 */  lw        $ra, 0x10($sp)
/* F9F4 800345F4 03E00008 */  jr        $ra
/* F9F8 800345F8 27BD0018 */   addiu    $sp, $sp, 0x18
