.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403CC_ADB26C
/* ADB26C 802403CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ADB270 802403D0 AFBF0010 */  sw        $ra, 0x10($sp)
/* ADB274 802403D4 8C82000C */  lw        $v0, 0xc($a0)
/* ADB278 802403D8 0C0B1EAF */  jal       get_variable
/* ADB27C 802403DC 8C450000 */   lw       $a1, ($v0)
/* ADB280 802403E0 8FBF0010 */  lw        $ra, 0x10($sp)
/* ADB284 802403E4 3C018024 */  lui       $at, %hi(D_80241D38)
/* ADB288 802403E8 AC221D38 */  sw        $v0, %lo(D_80241D38)($at)
/* ADB28C 802403EC 24020002 */  addiu     $v0, $zero, 2
/* ADB290 802403F0 03E00008 */  jr        $ra
/* ADB294 802403F4 27BD0018 */   addiu    $sp, $sp, 0x18
