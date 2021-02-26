.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80028808
/* 3C08 80028808 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3C0C 8002880C AFBF0010 */  sw        $ra, 0x10($sp)
/* 3C10 80028810 0C00A1F0 */  jal       func_800287C0
/* 3C14 80028814 00000000 */   nop
/* 3C18 80028818 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3C1C 8002881C 3C01800A */  lui       $at, %hi(D_8009A680)
/* 3C20 80028820 A420A680 */  sh        $zero, %lo(D_8009A680)($at)
/* 3C24 80028824 3C01800A */  lui       $at, %hi(D_8009A682)
/* 3C28 80028828 A420A682 */  sh        $zero, %lo(D_8009A682)($at)
/* 3C2C 8002882C 3C01800A */  lui       $at, %hi(D_8009A684)
/* 3C30 80028830 A420A684 */  sh        $zero, %lo(D_8009A684)($at)
/* 3C34 80028834 3C01800A */  lui       $at, %hi(D_8009A686)
/* 3C38 80028838 A420A686 */  sh        $zero, %lo(D_8009A686)($at)
/* 3C3C 8002883C 03E00008 */  jr        $ra
/* 3C40 80028840 27BD0018 */   addiu    $sp, $sp, 0x18
