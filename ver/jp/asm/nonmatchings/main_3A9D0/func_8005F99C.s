.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005F99C
/* 3AD9C 8005F99C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3ADA0 8005F9A0 3C048009 */  lui       $a0, %hi(D_80093CD0)
/* 3ADA4 8005F9A4 24843CD0 */  addiu     $a0, $a0, %lo(D_80093CD0)
/* 3ADA8 8005F9A8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3ADAC 8005F9AC 0C018118 */  jal       func_80060460
/* 3ADB0 8005F9B0 00000000 */   nop
/* 3ADB4 8005F9B4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3ADB8 8005F9B8 03E00008 */  jr        $ra
/* 3ADBC 8005F9BC 27BD0018 */   addiu    $sp, $sp, 0x18
