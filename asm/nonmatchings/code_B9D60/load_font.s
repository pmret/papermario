.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel load_font
/* B9E34 80123734 3C028015 */  lui       $v0, %hi(D_80155C98)
/* B9E38 80123738 84425C98 */  lh        $v0, %lo(D_80155C98)($v0)
/* B9E3C 8012373C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B9E40 80123740 10820022 */  beq       $a0, $v0, .L801237CC
/* B9E44 80123744 AFBF0010 */   sw       $ra, 0x10($sp)
/* B9E48 80123748 1480000B */  bnez      $a0, .L80123778
/* B9E4C 8012374C 24020001 */   addiu    $v0, $zero, 1
/* B9E50 80123750 3C040000 */  lui       $a0, 0
/* B9E54 80123754 24840000 */  addiu     $a0, $a0, 0
/* B9E58 80123758 3C06802F */  lui       $a2, %hi(D_802EE8D0)
/* B9E5C 8012375C 24C6E8D0 */  addiu     $a2, $a2, %lo(D_802EE8D0)
/* B9E60 80123760 0C048DC2 */  jal       load_font_data
/* B9E64 80123764 24055100 */   addiu    $a1, $zero, 0x5100
/* B9E68 80123768 3C040000 */  lui       $a0, 0
/* B9E6C 8012376C 24845300 */  addiu     $a0, $a0, 0x5300
/* B9E70 80123770 08048DEF */  j         .L801237BC
/* B9E74 80123774 24050500 */   addiu    $a1, $zero, 0x500
.L80123778:
/* B9E78 80123778 14820014 */  bne       $a0, $v0, .L801237CC
/* B9E7C 8012377C 00000000 */   nop
/* B9E80 80123780 3C040000 */  lui       $a0, 0
/* B9E84 80123784 24845800 */  addiu     $a0, $a0, 0x5800
/* B9E88 80123788 3C06802F */  lui       $a2, %hi(D_802ED970)
/* B9E8C 8012378C 24C6D970 */  addiu     $a2, $a2, %lo(D_802ED970)
/* B9E90 80123790 0C048DC2 */  jal       load_font_data
/* B9E94 80123794 24050F60 */   addiu    $a1, $zero, 0xf60
/* B9E98 80123798 3C040000 */  lui       $a0, 0
/* B9E9C 8012379C 24846760 */  addiu     $a0, $a0, 0x6760
/* B9EA0 801237A0 3C06802F */  lui       $a2, %hi(D_802F39D0)
/* B9EA4 801237A4 24C639D0 */  addiu     $a2, $a2, %lo(D_802F39D0)
/* B9EA8 801237A8 0C048DC2 */  jal       load_font_data
/* B9EAC 801237AC 24050B88 */   addiu    $a1, $zero, 0xb88
/* B9EB0 801237B0 3C040000 */  lui       $a0, 0
/* B9EB4 801237B4 248472E8 */  addiu     $a0, $a0, 0x72e8
/* B9EB8 801237B8 24050080 */  addiu     $a1, $zero, 0x80
.L801237BC:
/* B9EBC 801237BC 3C06802F */  lui       $a2, %hi(D_802F4560)
/* B9EC0 801237C0 24C64560 */  addiu     $a2, $a2, %lo(D_802F4560)
/* B9EC4 801237C4 0C048DC2 */  jal       load_font_data
/* B9EC8 801237C8 00000000 */   nop
.L801237CC:
/* B9ECC 801237CC 8FBF0010 */  lw        $ra, 0x10($sp)
/* B9ED0 801237D0 03E00008 */  jr        $ra
/* B9ED4 801237D4 27BD0018 */   addiu    $sp, $sp, 0x18
