.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411AC_D4E1EC
/* D4E1EC 802411AC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D4E1F0 802411B0 AFBF0010 */  sw        $ra, 0x10($sp)
/* D4E1F4 802411B4 10A00003 */  beqz      $a1, .L802411C4
/* D4E1F8 802411B8 8C86000C */   lw       $a2, 0xc($a0)
/* D4E1FC 802411BC 3C018024 */  lui       $at, %hi(func_80241F94_95D194)
/* D4E200 802411C0 AC201F94 */  sw        $zero, %lo(func_80241F94_95D194)($at)
.L802411C4:
/* D4E204 802411C4 3C038024 */  lui       $v1, %hi(func_80241F94_95D194)
/* D4E208 802411C8 24631F94 */  addiu     $v1, $v1, %lo(func_80241F94_95D194)
/* D4E20C 802411CC 8C620000 */  lw        $v0, ($v1)
/* D4E210 802411D0 54400003 */  bnel      $v0, $zero, .L802411E0
/* D4E214 802411D4 AC600000 */   sw       $zero, ($v1)
/* D4E218 802411D8 0809047D */  j         .L802411F4
/* D4E21C 802411DC 0000102D */   daddu    $v0, $zero, $zero
.L802411E0:
/* D4E220 802411E0 8CC50000 */  lw        $a1, ($a2)
/* D4E224 802411E4 3C068024 */  lui       $a2, %hi(func_80241F98_D21E28)
/* D4E228 802411E8 0C0B2026 */  jal       set_variable
/* D4E22C 802411EC 8CC61F98 */   lw       $a2, %lo(func_80241F98_D21E28)($a2)
/* D4E230 802411F0 24020002 */  addiu     $v0, $zero, 2
.L802411F4:
/* D4E234 802411F4 8FBF0010 */  lw        $ra, 0x10($sp)
/* D4E238 802411F8 03E00008 */  jr        $ra
/* D4E23C 802411FC 27BD0018 */   addiu    $sp, $sp, 0x18
