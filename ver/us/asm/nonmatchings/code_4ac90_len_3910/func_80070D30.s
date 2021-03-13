.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80070D30
/* 4C130 80070D30 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 4C134 80070D34 AFA40010 */  sw        $a0, 0x10($sp)
/* 4C138 80070D38 AFA50014 */  sw        $a1, 0x14($sp)
/* 4C13C 80070D3C AFA60018 */  sw        $a2, 0x18($sp)
/* 4C140 80070D40 AFA7001C */  sw        $a3, 0x1c($sp)
/* 4C144 80070D44 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 4C148 80070D48 E7AE0024 */  swc1      $f14, 0x24($sp)
/* 4C14C 80070D4C E7B00028 */  swc1      $f16, 0x28($sp)
/* 4C150 80070D50 AFBF002C */  sw        $ra, 0x2c($sp)
/* 4C154 80070D54 0C016959 */  jal       load_effect
/* 4C158 80070D58 24040037 */   addiu    $a0, $zero, 0x37
/* 4C15C 80070D5C 8FA40010 */  lw        $a0, 0x10($sp)
/* 4C160 80070D60 8FA50014 */  lw        $a1, 0x14($sp)
/* 4C164 80070D64 8FA60018 */  lw        $a2, 0x18($sp)
/* 4C168 80070D68 8FA7001C */  lw        $a3, 0x1c($sp)
/* 4C16C 80070D6C C7AC0020 */  lwc1      $f12, 0x20($sp)
/* 4C170 80070D70 C7AE0024 */  lwc1      $f14, 0x24($sp)
/* 4C174 80070D74 C7B00028 */  lwc1      $f16, 0x28($sp)
/* 4C178 80070D78 8FBF002C */  lw        $ra, 0x2c($sp)
/* 4C17C 80070D7C 27BD0030 */  addiu     $sp, $sp, 0x30
/* 4C180 80070D80 3C018008 */  lui       $at, %hi(gEffectTable+0x528)
/* 4C184 80070D84 8C21F738 */  lw        $at, %lo(gEffectTable+0x528)($at)
/* 4C188 80070D88 00200008 */  jr        $at
/* 4C18C 80070D8C 00000000 */   nop
