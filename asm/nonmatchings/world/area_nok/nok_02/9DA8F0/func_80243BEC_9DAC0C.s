.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243BEC_9DAC0C
/* 9DAC0C 80243BEC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9DAC10 80243BF0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9DAC14 80243BF4 10A00003 */  beqz      $a1, .L80243C04
/* 9DAC18 80243BF8 8C86000C */   lw       $a2, 0xc($a0)
/* 9DAC1C 80243BFC 3C018025 */  lui       $at, %hi(D_80252400)
/* 9DAC20 80243C00 AC202400 */  sw        $zero, %lo(D_80252400)($at)
.L80243C04:
/* 9DAC24 80243C04 3C038025 */  lui       $v1, %hi(D_80252400)
/* 9DAC28 80243C08 24632400 */  addiu     $v1, $v1, %lo(D_80252400)
/* 9DAC2C 80243C0C 8C620000 */  lw        $v0, ($v1)
/* 9DAC30 80243C10 54400003 */  bnel      $v0, $zero, .L80243C20
/* 9DAC34 80243C14 AC600000 */   sw       $zero, ($v1)
/* 9DAC38 80243C18 08090F0D */  j         .L80243C34
/* 9DAC3C 80243C1C 0000102D */   daddu    $v0, $zero, $zero
.L80243C20:
/* 9DAC40 80243C20 8CC50000 */  lw        $a1, ($a2)
/* 9DAC44 80243C24 3C068025 */  lui       $a2, %hi(D_80252404)
/* 9DAC48 80243C28 0C0B2026 */  jal       set_variable
/* 9DAC4C 80243C2C 8CC62404 */   lw       $a2, %lo(D_80252404)($a2)
/* 9DAC50 80243C30 24020002 */  addiu     $v0, $zero, 2
.L80243C34:
/* 9DAC54 80243C34 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9DAC58 80243C38 03E00008 */  jr        $ra
/* 9DAC5C 80243C3C 27BD0018 */   addiu    $sp, $sp, 0x18
