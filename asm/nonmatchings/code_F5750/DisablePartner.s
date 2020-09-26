.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel DisablePartner
/* F68E8 802D1F38 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F68EC 802D1F3C AFBF0010 */  sw        $ra, 0x10($sp)
/* F68F0 802D1F40 8C82000C */  lw        $v0, 0xc($a0)
/* F68F4 802D1F44 0C0B1EAF */  jal       get_variable
/* F68F8 802D1F48 8C450000 */   lw       $a1, ($v0)
/* F68FC 802D1F4C 2443FFFF */  addiu     $v1, $v0, -1
/* F6900 802D1F50 000318C0 */  sll       $v1, $v1, 3
/* F6904 802D1F54 3C018011 */  lui       $at, 0x8011
/* F6908 802D1F58 00230821 */  addu      $at, $at, $v1
/* F690C 802D1F5C A020F2A4 */  sb        $zero, -0xd5c($at)
/* F6910 802D1F60 8FBF0010 */  lw        $ra, 0x10($sp)
/* F6914 802D1F64 24020002 */  addiu     $v0, $zero, 2
/* F6918 802D1F68 03E00008 */  jr        $ra
/* F691C 802D1F6C 27BD0018 */   addiu    $sp, $sp, 0x18
