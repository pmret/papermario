.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005F0B0
/* 3A4B0 8005F0B0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3A4B4 8005F0B4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3A4B8 8005F0B8 3C01800A */  lui       $at, %hi(D_8009A5D8)
/* 3A4BC 8005F0BC AC20A5D8 */  sw        $zero, %lo(D_8009A5D8)($at)
/* 3A4C0 8005F0C0 0C019CD4 */  jal       func_80067350
/* 3A4C4 8005F0C4 24040001 */   addiu    $a0, $zero, 1
/* 3A4C8 8005F0C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3A4CC 8005F0CC 03E00008 */  jr        $ra
/* 3A4D0 8005F0D0 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3A4D4 8005F0D4 00000000 */  nop
/* 3A4D8 8005F0D8 00000000 */  nop
/* 3A4DC 8005F0DC 00000000 */  nop
