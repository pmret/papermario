.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418A4_A3AD84
/* A3AD84 802418A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A3AD88 802418A8 AFBF0010 */  sw        $ra, 0x10($sp)
/* A3AD8C 802418AC 8C82000C */  lw        $v0, 0xc($a0)
/* A3AD90 802418B0 0C0B1EAF */  jal       get_variable
/* A3AD94 802418B4 8C450000 */   lw       $a1, ($v0)
/* A3AD98 802418B8 3C058011 */  lui       $a1, %hi(gPlayerData)
/* A3AD9C 802418BC 24A5F290 */  addiu     $a1, $a1, %lo(gPlayerData)
/* A3ADA0 802418C0 3C048024 */  lui       $a0, %hi(D_802447D0)
/* A3ADA4 802418C4 00822021 */  addu      $a0, $a0, $v0
/* A3ADA8 802418C8 908447D0 */  lbu       $a0, %lo(D_802447D0)($a0)
/* A3ADAC 802418CC 94A3000C */  lhu       $v1, 0xc($a1)
/* A3ADB0 802418D0 00641821 */  addu      $v1, $v1, $a0
/* A3ADB4 802418D4 A4A3000C */  sh        $v1, 0xc($a1)
/* A3ADB8 802418D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* A3ADBC 802418DC 24020002 */  addiu     $v0, $zero, 2
/* A3ADC0 802418E0 03E00008 */  jr        $ra
/* A3ADC4 802418E4 27BD0018 */   addiu    $sp, $sp, 0x18
