.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411A0_D59A30
/* D59A30 802411A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D59A34 802411A4 AFBF0010 */  sw        $ra, 0x10($sp)
/* D59A38 802411A8 8C82000C */  lw        $v0, 0xc($a0)
/* D59A3C 802411AC 0C0B1EAF */  jal       evt_get_variable
/* D59A40 802411B0 8C450000 */   lw       $a1, ($v0)
/* D59A44 802411B4 3C018024 */  lui       $at, %hi(D_80241D9C_D5A62C)
/* D59A48 802411B8 AC221D9C */  sw        $v0, %lo(D_80241D9C_D5A62C)($at)
/* D59A4C 802411BC 24020002 */  addiu     $v0, $zero, 2
/* D59A50 802411C0 8FBF0010 */  lw        $ra, 0x10($sp)
/* D59A54 802411C4 24030001 */  addiu     $v1, $zero, 1
/* D59A58 802411C8 3C018024 */  lui       $at, %hi(D_80241D98_D5A628)
/* D59A5C 802411CC AC231D98 */  sw        $v1, %lo(D_80241D98_D5A628)($at)
/* D59A60 802411D0 03E00008 */  jr        $ra
/* D59A64 802411D4 27BD0018 */   addiu    $sp, $sp, 0x18
