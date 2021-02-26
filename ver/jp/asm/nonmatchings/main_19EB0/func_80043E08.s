.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80043E08
/* 1F208 80043E08 3C02800A */  lui       $v0, %hi(D_8009A5E0)
/* 1F20C 80043E0C 8C42A5E0 */  lw        $v0, %lo(D_8009A5E0)($v0)
/* 1F210 80043E10 3C03800B */  lui       $v1, %hi(D_800B0EF5)
/* 1F214 80043E14 80630EF5 */  lb        $v1, %lo(D_800B0EF5)($v1)
/* 1F218 80043E18 38420003 */  xori      $v0, $v0, 3
/* 1F21C 80043E1C 2C440001 */  sltiu     $a0, $v0, 1
/* 1F220 80043E20 24020005 */  addiu     $v0, $zero, 5
/* 1F224 80043E24 50620001 */  beql      $v1, $v0, .L80043E2C
/* 1F228 80043E28 24040001 */   addiu    $a0, $zero, 1
.L80043E2C:
/* 1F22C 80043E2C 03E00008 */  jr        $ra
/* 1F230 80043E30 0080102D */   daddu    $v0, $a0, $zero
/* 1F234 80043E34 00000000 */  nop
/* 1F238 80043E38 00000000 */  nop
/* 1F23C 80043E3C 00000000 */  nop
