.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243C40_9DAC60
/* 9DAC60 80243C40 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9DAC64 80243C44 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9DAC68 80243C48 8C82000C */  lw        $v0, 0xc($a0)
/* 9DAC6C 80243C4C 0C0B1EAF */  jal       evt_get_variable
/* 9DAC70 80243C50 8C450000 */   lw       $a1, ($v0)
/* 9DAC74 80243C54 3C018025 */  lui       $at, %hi(D_80252404_9E9424)
/* 9DAC78 80243C58 AC222404 */  sw        $v0, %lo(D_80252404_9E9424)($at)
/* 9DAC7C 80243C5C 24020002 */  addiu     $v0, $zero, 2
/* 9DAC80 80243C60 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9DAC84 80243C64 24030001 */  addiu     $v1, $zero, 1
/* 9DAC88 80243C68 3C018025 */  lui       $at, %hi(D_80252400_9E9420)
/* 9DAC8C 80243C6C AC232400 */  sw        $v1, %lo(D_80252400_9E9420)($at)
/* 9DAC90 80243C70 03E00008 */  jr        $ra
/* 9DAC94 80243C74 27BD0018 */   addiu    $sp, $sp, 0x18
